/*******************(C)  COPYRIGHT 2018 KENNETH L ANDERSON *********************
* 
*      ARDUINO ELECTRICAL RESISTANCE/CONDUCTANCE MONITORING SKETCH 
*      
* File Name          : adc_for_plant_tissue.ino
* Author             : KENNETH L ANDERSON
* Version            : v.Free
* Date               : 26-April-2018
* Description        : To replicate Cleve Backster's findings that he named "Primary Perception".  Basically, this sketch turns an Arduino MCU and optional (recommended) ADS1115 into a nicely functional poor man's polygraph.
* Boards tested on   : Uno using both ADS1115 and inboard analog inputs.  
*                    : TTGO XI using ADS1115.  
*                    : Sadly, TTGO XI 12-bit analog inputs are unsuitable due to their irremoveable pullup conductance.  
*                    : Many other configurations should work fine.  
*                    : The ATTINY85 is not suitable at all due to not having hardware serial
* 
* Known limitations  : No ability to accept user input from keyboard during run time
*                    : Only tested with a single plant hooked up, hence a single analog input pin in use - and it must be the first available analog input pin
*                    : No ability to control exactly where the times 10 line is plotted
*                    : Re-compile is needed for any changes to configuration
*                    : Analog input pins being used MUST be the first available analog inputs
*                    : These limitations will be addressed in future not-for-free versions
*                    
********************************************************************************
* THE PRESENT PRODUCT WHICH IS ONLY FOR USE BY SOFTWARE- AND HARDWARE-COMPETENT USERS
* IS INTENDED TO OFFER VARIOUS CAPABILITIES.  BECAUSE ABSOLUTELY NO CONSIDERATION 
* IS EXPECTED IN RETURN, NO CONTRACT, WHETHER OFFERING SUITABILITY, RELIABILITY, 
* FUNCTIONALITY, SAFETY, OR OTHER, EXISTS.  BY USING THIS PRODUCT YOU EXPRESSLY AND
* TOTALLY ACCEPT FULL LIABILITY FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES 
* WITH RESPECT TO ANY CLAIMS ARISING FROM SOFTWARE AND/OR HARDWARE DERIVATIONS OF PRODUCT.
* I MAKE ABSOLUTELY NO CLAIM OF MY OWN COMPETENCE, LICENSURE, CERTIFICATION, EXPERIENCE,
* OR PROFESSIONAL STANDING OTHER THAN BEING AN ELECTRONICS TECHNICIAN BY FORMAL 
* DEGREE AND UNITED STATES FCC RADIOTELEPHONE OPERATORS LICENSE, AND 
* A SOFTWARE DEVELOPER BY LIMITED PRACTICAL EXPERIENCE, AND BEING FORMALLY
* DEGREED WITH BACHELOR OF GENERAL STUDIES MAJORED IN GENERAL SCIENCES
********************************************************************************
*
* TODO:  Arrange for run-time keyboard input to eliminate need to re-compile when changes are made or plotting adjustments are desired
*        Use an LM334 to prevent power supply noise from plotting (i.e., convert from resistance to conductance)
*        Use digital potentiometer (x9c104 or x9c503) for more automated balancing of the two serial resistances
* 
*  These planned enhancements will be reserved for NOT-FOR-FREE sketch versions in the future
* 
*********************************************************************************************************************/
#define VERSION "v.Free"
#define NUM_ANALOG_INPUTS_TO_PLOT 1 //The number of consecutive analog pins to plot, beginning with PIN_A0
#define NUM_ADS1X15_INPUTS_TO_PLOT 0 //The number of consecutive ADS1X15 pins to plot, beginning with A0
#if ( NUM_ANALOG_INPUTS_TO_PLOT > 0 )
    #ifndef NUM_ANALOG_INPUTS
Sorry, but you will have to manually define the variable NUM_ANALOG_INPUTS somewhere above this line and re-compile...
    #endif
#else
    #if ( NUM_ADS1X15_INPUTS_TO_PLOT == 0 )
You'll need to manually define at least one of the variables NUM_ANALOG_INPUTS_TO_PLOT or NUM_ADS1X15_INPUTS_TO_PLOT where they appear in the lines above and re-compile...
If you only have the Arduino without an ADS1X15, then define NUM_ANALOG_INPUTS_TO_PLOT.  Otherwise, define NUM_ADS1X15_INPUTS_TO_PLOT and/or both of them.
    #endif
#endif

#define MULTIPLICATION_FACTOR 15 //To aid in viewing

//#define DEBUG
#include <math.h>

#if ( NUM_ADS1X15_INPUTS_TO_PLOT > 0 )
        #include "SPI.h"
/*
*
*  SDA, SCL Wemos XI/TTGO XI are terribly mislabeled in slkscreen on the board!  Use A4 for SDA, and A5 is SCL.
*/
    #include <Adafruit_ADS1015.h>//for systems using ADS1115/ADS1015
    Adafruit_ADS1115 ads;  //For when ADS1115 is being used
    //Adafruit_ADS1015 ads;  //For when ADS1015 is being used
#endif
#define UpperLimitADS1X15Input 32767 //This value for ADS1115
// #define UpperLimitADS1X15Input 2047 //This value for ADS1015

//#define UpperLimitAnalogInput 4095 //This value for Arduinos that have 12-bit analog inputs
#define UpperLimitAnalogInput 1023 //This value for Arduinos that have 10-bit analog inputs

const uint8_t SAMPLE_TIMES = 30; //To better average out artifacts we over-sample and average.  This value can be tweaked by you to ensure neutralization of power line noise or harmonics of power supplies, etc.....

/*
 * 
 * The following pin defines are for the WeMos XI/TTGO XI board only
 * Change per your board layout
 * 
 */

uint8_t *A_PIN_ARRAY;
unsigned long magnify_adjustment[ NUM_ADS1X15_INPUTS_TO_PLOT + NUM_ANALOG_INPUTS_TO_PLOT ];

void setup() 
{
#if ( NUM_ADS1X15_INPUTS_TO_PLOT > 0 )
    analogReference( DEFAULT );
#endif    
//#ifdef __LGT8FX8E__
    Serial.begin( 19200 );//This speed is what works best with WeMos XI/TTGO XI board.
//#else
//    Serial.begin( 57600 );//Is there any reason for this higher speed?  I don't think so, but feel free to put this code back into action if you want to.
//#endif
//#ifndef ARDUINO_AVR_DIGISPARKPRO
//    analogReadResolution( ADC_RES_BIT );
//#endif
#if ( NUM_ANALOG_INPUTS_TO_PLOT > 0 )
    A_PIN_ARRAY = (uint8_t *)malloc( NUM_ANALOG_INPUTS );

//Herafter is the pattern.  If you have more analog pins, add them according to the pattern.
#ifdef NUM_ANALOG_INPUTS
#ifdef PIN_A0
    for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
    {
        if( i == 0 )
            *( A_PIN_ARRAY + i ) = PIN_A0;
#ifdef PIN_A1
        else if( i == 1 )
            *( A_PIN_ARRAY + i ) = PIN_A1;
#ifdef PIN_A2
        else if( i == 2 )
            *( A_PIN_ARRAY + i ) = PIN_A2;
#ifdef PIN_A3
        else if( i == 3 )
            *( A_PIN_ARRAY + i ) = PIN_A3;
#ifdef PIN_A4
        else if( i == 4 )
            *( A_PIN_ARRAY + i ) = PIN_A4;
#ifdef PIN_A5
        else if( i == 5 )
            *( A_PIN_ARRAY + i ) = PIN_A5;
#ifdef PIN_A6
        else if( i == 6 )
            *( A_PIN_ARRAY + i ) = PIN_A6;
#ifdef PIN_A7
        else if( i == 7 )
            *( A_PIN_ARRAY + i ) = PIN_A7;
#ifdef PIN_A8
        else if( i == 8 )
            *( A_PIN_ARRAY + i ) = PIN_A8;
#ifdef PIN_A9
        else if( i == 9 )
            *( A_PIN_ARRAY + i ) = PIN_A9;
#ifdef PIN_A10
        else if( i == 10 )
            *( A_PIN_ARRAY + i ) = PIN_A10;
#ifdef PIN_A11
        else if( i == 11 )
            *( A_PIN_ARRAY + i ) = PIN_A11;
#ifdef PIN_A12
        else if( i == 12 )
            *( A_PIN_ARRAY + i ) = PIN_A12;
#ifdef PIN_A13
        else if( i == 13 )
            *( A_PIN_ARRAY + i ) = PIN_A13;
#ifdef PIN_A14
        else if( i == 14 )
            *( A_PIN_ARRAY + i ) = PIN_A14;
#ifdef PIN_A15
        else if( i == 15 )
            *( A_PIN_ARRAY + i ) = PIN_A15;
#ifdef PIN_A16
        else if( i == 16 )
            *( A_PIN_ARRAY + i ) = PIN_A16;
#ifdef PIN_A17
        else if( i == 17 )
            *( A_PIN_ARRAY + i ) = PIN_A17;
#ifdef PIN_A18
        else if( i == 18 )
            *( A_PIN_ARRAY + i ) = PIN_A18;
#ifdef PIN_A19
        else if( i == 19 )
            *( A_PIN_ARRAY + i ) = PIN_A19;
#ifdef PIN_A20
        else if( i == 20 )
            *( A_PIN_ARRAY + i ) = PIN_A20;
#ifdef PIN_A21
        else if( i == 21 )
            *( A_PIN_ARRAY + i ) = PIN_A21;
#ifdef PIN_A22
        else if( i == 22 )
            *( A_PIN_ARRAY + i ) = PIN_A22;
#endif //end of PIN_A22 check
#endif //end of PIN_A21 check
#endif //end of PIN_A20 check
#endif //end of PIN_A19 check
#endif //end of PIN_A18 check
#endif //end of PIN_A17 check
#endif //end of PIN_A16 check
#endif //end of PIN_A15 check
#endif //end of PIN_A14 check
#endif //end of PIN_A13 check
#endif //end of PIN_A12 check
#endif //end of PIN_A11 check
#endif //end of PIN_A10 check
#endif //end of PIN_A9 check
#endif //end of PIN_A8 check
#endif //end of PIN_A7 check
#endif //end of PIN_A6 check
#endif //end of PIN_A5 check
#endif //end of PIN_A4 check
#endif //end of PIN_A3 check
#endif //end of PIN_A2 check
#endif //end of PIN_A1 check
    }
#endif //end of PIN_A0 check
#else
    #define NUM_ANALOG_INPUTS 255
#endif
#endif
#if ( NUM_ADS1X15_INPUTS_TO_PLOT > 0 )
//   ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
   ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV  //This allows a simple power rail excitation supply to voltage divider
//   ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
//   ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
//   ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
//   ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
    ads.begin();
#endif
#ifdef __LGT8FX8E__
    delay( 8000 );  // Needed by this board for serial to work
#endif
    for( uint8_t i = 0; i < NUM_ADS1X15_INPUTS_TO_PLOT + NUM_ANALOG_INPUTS_TO_PLOT; i++ )
        magnify_adjustment[ i ] = 0;
#ifdef DEBUG
        Serial.println( F( " end of setup" ) );
#endif
}

unsigned long value, valueTemp;

void loop() 
{    
    Serial.print( ( ( unsigned long )UpperLimitADS1X15Input * ( unsigned long )NUM_ADS1X15_INPUTS_TO_PLOT ) + ( ( unsigned long )UpperLimitAnalogInput * ( unsigned long )NUM_ANALOG_INPUTS_TO_PLOT ) );
    Serial.print(" ");
    Serial.println( 0 ); //This is color two
    for( uint16_t plotter_loops = 0; plotter_loops < 500 / 3; plotter_loops++ ) 
    {
#if ( NUM_ANALOG_INPUTS_TO_PLOT > 0 )
        for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
        {
            value = analogRead( *( A_PIN_ARRAY + i ) );
            for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
                  value += analogRead( *( A_PIN_ARRAY + i ) );

            if( i == 0 )
            {
                Serial.print( 0 ); //This is color one
                Serial.print(" ");
                Serial.print( 0 ); //This is color two
                Serial.print(" ");
            }

            value = ( uint16_t )( value / SAMPLE_TIMES );
            Serial.print( value + ( ( unsigned long )UpperLimitAnalogInput * ( unsigned long )( NUM_ANALOG_INPUTS_TO_PLOT - ( i + 1 ) ) ) + ( ( unsigned long )UpperLimitADS1X15Input * ( unsigned long )NUM_ADS1X15_INPUTS_TO_PLOT ) ); //This is color three
            Serial.print( " " );

            //Next lines plot a magnified version.  First, magnify_adjustment is determined
            //Ensure ( value * MULTIPLICATION_FACTOR ) - magnify_adjustment is greater than 0. 0 was decided on b/c the plotter graph upper limit will be greater than the analog input upper limit making the activity appear in the lower part
            while( !( ( signed long )( ( value * MULTIPLICATION_FACTOR ) - magnify_adjustment[ i ] ) >= 0 ) ) magnify_adjustment[ i ] -= ( UpperLimitAnalogInput / 100 );

            //If ( signed long )( ( value * MULTIPLICATION_FACTOR ) - magnify_adjustment ) is too high, bring it down by increasing magnify_adjustment
            while( !( ( unsigned long )( ( value * MULTIPLICATION_FACTOR ) - magnify_adjustment[ i ] ) <= UpperLimitAnalogInput / 2 ) ) magnify_adjustment[ i ] += ( UpperLimitAnalogInput / 100 );

            //Plot it now
            Serial.print( ( unsigned long )( ( value * MULTIPLICATION_FACTOR ) - magnify_adjustment[ i ] ) + ( ( unsigned long )UpperLimitAnalogInput * ( unsigned long )( NUM_ANALOG_INPUTS_TO_PLOT - i ) ) + ( ( unsigned long )UpperLimitADS1X15Input * ( unsigned long )NUM_ADS1X15_INPUTS_TO_PLOT ) ); //This is color four or five
            Serial.print( " " );
        }
#endif

#if ( NUM_ADS1X15_INPUTS_TO_PLOT > 0 )
        for( uint8_t i = 0; i < NUM_ADS1X15_INPUTS_TO_PLOT; i++ )
        {
#ifdef DEBUG
        Serial.println( F( "Line286" ) );
#endif
            value = ads.readADC_SingleEnded( i );
            while( value > UpperLimitADS1X15Input ) value = ads.readADC_SingleEnded( i );
#ifdef DEBUG
        Serial.println( F( "Line295" ) );
#endif
            for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
            {
                valueTemp = ads.readADC_SingleEnded( i );
                while( valueTemp > UpperLimitADS1X15Input ) valueTemp = ads.readADC_SingleEnded( i );
                value += valueTemp;
            }
#ifdef DEBUG
        Serial.println( F( "Line304" ) );
#endif
            value = (uint16_t)( value / SAMPLE_TIMES );
#ifdef DEBUG
        Serial.println( F( "Line308" ) );
#endif

#if ( NUM_ANALOG_INPUTS_TO_PLOT == 0 )
            if( i == 0 )
            {
                Serial.print( 0 ); //This is color one
                Serial.print(" ");
                Serial.print( 0 ); //This is color two
                Serial.print(" ");
            }
#endif
            Serial.print( value + ( ( unsigned long )UpperLimitADS1X15Input * ( unsigned long )( NUM_ADS1X15_INPUTS_TO_PLOT - ( i + 1 ) ) ) ); //This is color three and odds above

            //Next lines plot a magnified version.  First, magnify_adjustment is determined
            Serial.print(" ");

            //If ( signed long )( ( value * MULTIPLICATION_FACTOR ) - magnify_adjustment ) is too high, bring it down by increasing magnify_adjustment
            while( !( ( signed long )( ( value * MULTIPLICATION_FACTOR ) - magnify_adjustment[ i + NUM_ANALOG_INPUTS_TO_PLOT ] ) <= UpperLimitADS1X15Input / 2 ) ) magnify_adjustment[ i + NUM_ANALOG_INPUTS_TO_PLOT ] += ( UpperLimitADS1X15Input / 100 );

            //Ensure ( value * MULTIPLICATION_FACTOR ) - magnify_adjustment is greater than 0. 0 was decided on b/c the plotter graph upper limit will be greater than the analog input upper limit making the activity appear in the lower part
            while( !( ( signed long )( ( value * MULTIPLICATION_FACTOR ) - magnify_adjustment[ i + NUM_ANALOG_INPUTS_TO_PLOT ] ) >= 0 ) ) magnify_adjustment[ i + NUM_ANALOG_INPUTS_TO_PLOT ] -= ( UpperLimitADS1X15Input / 100 );

            //Plot it now
            Serial.print( ( signed long )( ( value * MULTIPLICATION_FACTOR ) - magnify_adjustment[ i + NUM_ANALOG_INPUTS_TO_PLOT ] ) + ( ( unsigned long )UpperLimitADS1X15Input * ( unsigned long )( NUM_ADS1X15_INPUTS_TO_PLOT - ( i + 1 ) ) ) ); //This is color four
            Serial.print(" ");
        }
#endif
        Serial.println();
#if ( 12 * ( NUM_ANALOG_INPUTS_TO_PLOT + NUM_ADS1X15_INPUTS_TO_PLOT ) < 110  )
    #define DELAY_TIME ( 110 - ( 12 * ( NUM_ANALOG_INPUTS_TO_PLOT + NUM_ADS1X15_INPUTS_TO_PLOT ) ) )
        delay( DELAY_TIME );
#endif
    }
}
