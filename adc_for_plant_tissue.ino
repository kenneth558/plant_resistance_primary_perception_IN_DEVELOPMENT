// Before using this sketch, you must set the following appropriately for your configuration and preferences !!!
#define NUM_ANALOG_INPUTS_TO_PLOT 0 //The number of consecutive analog pins to plot, beginning with PIN_A0
#define NUM_ADDON_ADC_INPUTS_TO_PLOT 1 //The number of consecutive ADS1X15 pins to plot, beginning with A0 and, if double-ended, A1
// TODO: If both the above are zeroes, use of HX711 is assumed.....?  Or would a separate definition work better or be more usefully flexible
#define 24BIT_ADDON_ADC_TYPE "ADS3"  // Proposing that this covers ADS1231; could make this "ADS4" (ADS1242), "AD9" (AD779x), "AD8" (AD7780) or "MAX" (MAX112x0...) or "LTC" (LTC2400) but code not included in v.FREE
#define MULTIPLICATION_FACTOR 20 //To aid in viewing
#define HighestBitResFromAddonADC 11 // all ADC values will get scaled to the single-ended aspect of this,  15 is ADS1115 single-ended, 16 for double-ended when two LM334s are used.  change to 11 for ADS1015 single-ended or 12 with two LM334s, (future: change to 24 for HX711--NO b/c there is the ADS1231 at 24 bits)
// Note to myself that Adafruit ADS1015 library uses two's complement representation of negative values
#define SAMPLE_TIMES 9 //To better average out artifacts we over-sample and average.  This value can be tweaked by you to ensure neutralization of power line noise or harmonics of power supplies, etc.....
#define MOST_PROBLEMATIC_INTERFERENCE_FREQ 60 // This is here just in case you think that you might have some interference on a known frequency.
#define DELAY_TIME_BETWEEN_SAMPLES_MS ( 1000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ / SAMPLE_TIMES ) //COARSE ADJUST
#define DELAY_TIME_BETWEEN_SAMPLES_US ( ( ( 1000000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ ) - ( DELAY_TIME_BETWEEN_SAMPLES_MS * SAMPLE_TIMES * 1000 ) ) / SAMPLE_TIMES ) //FINE ADJUST.  THIS GETS ADDED TO COARSE ADJUST, PRECISION = TRUNCATED PRAGMATICALLY TO uSec TO ACKNOWLEDGE SOME OVERHEAD FOR LOOPING SUPPORT CODE   // End of this part of code update

#define FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES 14 //Some boards don't have good definitions and constants for the analog pins :-(
#define REPOSITION_RATIO_OF_MAGNIFIED_VIEW_WHEN_LIMITS_GET_EXCEEDED (.6) //BETWEEN 0 AND 1 indicating how much of the display region to skip when magnified view trace has to get repositioned because trace would be outside region bounds

//#define DEBUG true //Don't forget that DEBUG is not formatted for Serial plotter, but might work anyway if you'd never print numbers only any DEBUG print line
#define AnalogInputBitsOfBoard 10 //Most Arduino boards are 10-bit resolution, but some can be 12 bits.  For known 12 bit boards (SAM, SAMD and TTGO XI architectures), this gets re-defined below, so generally this can be left as 10 even for those boards
#define SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING 9 //8 works only usually
/*******************(C)  COPYRIGHT 2018 KENNETH L ANDERSON *********************
* 
*      ARDUINO ELECTRICAL RESISTANCE/CONDUCTANCE MONITORING SKETCH 
*      
* File Name          : adc_for_plant_tissue.ino
* Author             : KENNETH L ANDERSON
* Version            : v.Free
* Date               : 29-May-2018.  Versions you may have downloaded dated prior to 30 April should be replaced with 30 April 2018 or one more recent.  Revisions more recent than 30 April 2018 do not affect you if your 30 April sketch compiles and plots any inboard analog input pins.  No changes have been made to ADS1X15 operation nor 10-bit operation since 30 April 2018
* Description        : To replicate Cleve Backster's findings that he named "Primary Perception".  Basically, this sketch turns an Arduino MCU and optional (recommended) ADS1115 into a nicely functional poor man's polygraph in order to learn/demonstrate telempathic horticulture.
* Boards tested on   : Uno using both ADS1115 and inboard analog inputs.  
*                    : TTGO XI using ADS1115.  
*                    : Many other configurations should work fine.  
*                    : Sadly, TTGO XI 12-bit analog inputs are unsuitable due to their irremoveable pullup conductance.  
*                    : The ATTINY85 is not suitable at all due to not having hardware serial
* 
* Known limitations  : No ability to accept user input from keyboard during run time
*                    : Re-compile is needed for any changes to configuration
*                    : Analog input pins being used MUST be the first available analog inputs
*                    : Only a single add-on ADS ADC device and only 1 or 2 differential channels on it is accommodated 
*                    : Some of these limitations will be addressed in future not-for-free versions
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
*        Use dual tightly thermally coupled LM334s to prevent power supply noise from plotting (i.e., convert from resistance to conductance)  5 VOLT DEVICES ONLY.   A toroid-based noise suppression coil might be needed.  The 2nd LM334 excites a fixed resistor circuit parallel to the plant circuit and connected to a second analog input for software temperature compensation.
*        Use digital potentiometer (MCP41XXX or MCP42XXX) for more automated balancing of the two serial resistances.  The charge pump noise generated by the x9c series rules it out.
*        Accommodate 24-bit amps like HX711 and ADS1231
* 
*  These planned enhancements will be reserved for NOT-FOR-FREE sketch versions in the future
*  
*  Changelog:  30 April 2018 :  Final inboard 10 bit operation and ADS1X15 operation has been achieved.  Future work on free version will be for 12 bit boards only
*              04 May   2018 :  Some 12 bit tweaking so that TTGO/WeMos XI, SAM and SAMD architectures compile with inboard analog inputs to computed at 12 bit even though AnalogInputBitsOfBoard is set at default.
*              18 May   2018 :  Anti-aliasing code
*              29 May   2018 :  Differential use of ADS1x15 to allow LM334 temperature comp to negative inputs so LM334 can be used on positive inputs
*              NEXT          :  Accommodate HX711 and ADS1231
*              NEXT          :  Made able to use MCP41XXX or MCP42XXX with LM334
*              NEXT          :  Software temperature compensation using a 2nd LM334 tightly theramlly coupled to 1ts LM334 feeding a fixed resistor circuit in parallel with the plant circuit and connected to a 2nd analog input.  Table of offsets from midpoint or one end of pot settings.
*               
*********************************************************************************************************************/
#define VERSION "v.Free"  // Since this never gets used anywhere, it doesn't compile in so no memory is wasted

#include <math.h>
#if ( NUM_ADDON_ADC_INPUTS_TO_PLOT > 0 )
    #include "SPI.h"
/*
*
*  SDA, SCL Wemos XI/TTGO XI are terribly mislabeled in slkscreen on the board!  Use A4 for SDA, and A5 is SCL.
*/
    #define HALFHighestBitResFromAddonADC ( HighestBitResFromAddonADC / 2 )
    #if ( ( HALFHighestBitResFromAddonADC * 2 ) == HighestBitResFromAddonADC )
        #define DIFFERENTIAL 
    #endif
    #include <Adafruit_ADS1015.h>//for systems using ADS1115/ADS1015
    #if ( HighestBitResFromAddonADC == 15 ) || ( HighestBitResFromAddonADC == 16 )
        Adafruit_ADS1115 ads;  //For when ADS1115 is being used
    #else
        #if ( HighestBitResFromAddonADC == 11 ) || ( HighestBitResFromAddonADC == 12 )
            Adafruit_ADS1015 ads;  //For when ADS1015 is being used
        #else
            #error “This add-on ADC resolution is not supported in this sketch version."
        #endif
    #endif
#endif
#if ( NUM_ANALOG_INPUTS_TO_PLOT > 0 )
    #ifndef NUM_ANALOG_INPUTS
Sorry, but you will have to manually define the variable NUM_ANALOG_INPUTS somewhere above this line and re-compile...
    #endif
#else
    #if ( NUM_ADDON_ADC_INPUTS_TO_PLOT == 0 )
You'll need to manually define at least one of the variables NUM_ANALOG_INPUTS_TO_PLOT or NUM_ADDON_ADC_INPUTS_TO_PLOT where they appear in the lines above and re-compile...
If you only have the Arduino without an ADS1X15, then define NUM_ANALOG_INPUTS_TO_PLOT.  Otherwise, define NUM_ADDON_ADC_INPUTS_TO_PLOT and/or both of them.
    #endif
#endif

/*
 * 
 * The following pin defines are for the WeMos XI/TTGO XI board only
 * Change per your board layout
 * 
 */

uint8_t *A_PIN_ARRAY;
struct magnify_adjustment_and_display_zero
{
    uint32_t magnify_adjustment;
    uint32_t zero_of_this_plotline;
    uint32_t high_limit_of_this_plotline;
} typedef magnify_adjustment_and_display_zero;

magnify_adjustment_and_display_zero screen_offsets[ NUM_ADDON_ADC_INPUTS_TO_PLOT + NUM_ANALOG_INPUTS_TO_PLOT ];
bool graphline = false;
uint32_t value, valueTemp;
//#ifdef DIFFERENTIAL
//    #define PlotterMaxScale ( ( ( uint32_t )pow( 2, HighestBitResFromAddonADC - 1 ) ) * ( uint32_t )( NUM_ADDON_ADC_INPUTS_TO_PLOT + NUM_ANALOG_INPUTS_TO_PLOT ) )
//#else
    #define PlotterMaxScale ( ( ( uint32_t )pow( 2, HighestBitResFromAddonADC ) ) * ( uint32_t )( NUM_ADDON_ADC_INPUTS_TO_PLOT + NUM_ANALOG_INPUTS_TO_PLOT ) )
//#endif
#define HundredthPlotterMaxScale ( PlotterMaxScale / 100 );


void setup() 
{
    #if ( NUM_ADDON_ADC_INPUTS_TO_PLOT > 0 ) 
        #if !( ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD )
            analogReference( DEFAULT ); //This is the voltage level of max bit value on analog input
        #else
            analogReference( AR_DEFAULT ); //
        #endif
    #endif    
    //#ifdef __LGT8FX8E__
        Serial.begin( 19200 );//This speed is what works best with WeMos XI/TTGO XI board.
    //#else
    //    Serial.begin( 57600 );//Is there any reason for this higher speed?  I don't think so, but feel free to put this code back into action if you want to.
    //#endif
    //#ifndef ARDUINO_AVR_DIGISPARKPRO
    //    analogReadResolution( ADC_RES_BIT );
    //#endif
    #if ( NUM_ADDON_ADC_INPUTS_TO_PLOT > 0 )
    //   ads.setGain( GAIN_TWOTHIRDS );  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
       ads.setGain( GAIN_ONE );        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV  //This allows a simple power rail excitation supply to voltage divider
    //   ads.setGain( GAIN_TWO );        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
    //   ads.setGain( GAIN_FOUR );       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
    //   ads.setGain( GAIN_EIGHT );      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
    //   ads.setGain( GAIN_SIXTEEN );    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
        ads.begin();
    #endif
    
    #ifdef __LGT8FX8E__
        delay( SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING * 1000 );  // Needed by this board for serial to work
    //    analogReadResolution( 12 );  //not necessary
    #endif
    #if ( ARDUINO_ARCH_XI || ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD ) //These are the boards known to have 12 bit analog inputs
        #ifdef AnalogInputBitsOfBoard
            #undef AnalogInputBitsOfBoard
        #endif
        #define AnalogInputBitsOfBoard 12  //These boards have 12 bit
    #endif
    
    #define BitsToShiftInboardADCValues ( HighestBitResFromAddonADC - AnalogInputBitsOfBoard )
    
    for( uint8_t i = 0; i < NUM_ADDON_ADC_INPUTS_TO_PLOT + NUM_ANALOG_INPUTS_TO_PLOT; i++ )
    {
        screen_offsets[ i ].magnify_adjustment = 0;
//where i > NUM_ANALOG_INPUTS_TO_PLOT results in 
        screen_offsets[ i ].high_limit_of_this_plotline = ( uint32_t )pow( 2, HighestBitResFromAddonADC ) * ( i > NUM_ANALOG_INPUTS_TO_PLOT ? ( ( uint32_t )( NUM_ADDON_ADC_INPUTS_TO_PLOT - i ) ) : ( ( uint32_t )( NUM_ANALOG_INPUTS_TO_PLOT - i ) + ( uint32_t )NUM_ADDON_ADC_INPUTS_TO_PLOT ) );
        screen_offsets[ i ].zero_of_this_plotline = ( uint32_t )pow( 2, HighestBitResFromAddonADC ) * ( i > NUM_ANALOG_INPUTS_TO_PLOT ? ( ( uint32_t )( NUM_ADDON_ADC_INPUTS_TO_PLOT - ( i + 1 ) ) ) : ( uint32_t )( NUM_ANALOG_INPUTS_TO_PLOT - ( i + 1 ) ) + ( uint32_t )NUM_ADDON_ADC_INPUTS_TO_PLOT );
    }
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT + NUM_ADDON_ADC_INPUTS_TO_PLOT; i++ )
    {
        Serial.print( 0 );
        Serial.print( F( " " ) );
        Serial.print( 0 );
        Serial.print( F( " " ) );
    }
//    Serial.println( F( "0" ) );
    Serial.println( PlotterMaxScale );
    #if ( NUM_ANALOG_INPUTS_TO_PLOT > 0 )
        uint8_t *A_PIN_ARRAY = (uint8_t *)malloc( NUM_ANALOG_INPUTS );
    
        //Herafter is the pattern.  If you have more analog pins, add them according to the pattern.
        #ifdef NUM_ANALOG_INPUTS
        #ifdef PIN_A0
            for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
            {
                if( i == 0 )
                    A_PIN_ARRAY[ i ] = PIN_A0;
                #ifdef DEBUG  //This is to demonstrate the purpose of DEBUG
                    Serial.println( A_PIN_ARRAY[ i ] );
                #endif
                #ifdef A1
                    else if( i == 1 )
                        A_PIN_ARRAY[ i ] = PIN_A1;
                    #ifdef A2
                    else if( i == 2 )
                        A_PIN_ARRAY[ i ] = PIN_A2;
                        #ifdef PIN_A3
                    else if( i == 3 )
                        A_PIN_ARRAY[ i ] = PIN_3;
                            #ifdef PIN_A4
                    else if( i == 4 )
                        A_PIN_ARRAY[ i ] = PIN_A4;
                                #ifdef PIN_A5
                    else if( i == 5 )
                        A_PIN_ARRAY[ i ] = PIN_A5;
                                    #ifdef PIN_A6
                    else if( i == 6 )
                        A_PIN_ARRAY[ i ] = PIN_A6;
                                        #ifdef PIN_A7
                    else if( i == 7 )
                        A_PIN_ARRAY[ i ] = PIN_A7;
                                            #ifdef PIN_A8
                    else if( i == 8 )
                        A_PIN_ARRAY[ i ] = PIN_A8;
                                                #ifdef PIN_A9
                    else if( i == 9 )
                        A_PIN_ARRAY[ i ] = PIN_A9;
                                                    #ifdef PIN_A10
                    else if( i == 10 )
                        A_PIN_ARRAY[ i ] = PIN_A10;
                                                        #ifdef PIN_A11
                    else if( i == 11 )
                        A_PIN_ARRAY[ i ] = PIN_A11;
                                                            #ifdef PIN_A12
                    else if( i == 12 )
                        A_PIN_ARRAY[ i ] = PIN_A12;
                                                                #ifdef PIN_A13
                    else if( i == 13 )
                        A_PIN_ARRAY[ i ] = PIN_A13;
                                                                    #ifdef PIN_A14
                    else if( i == 14 )
                        A_PIN_ARRAY[ i ] = PIN_A14;
                                                                        #ifdef PIN_A15
                    else if( i == 15 )
                        A_PIN_ARRAY[ i ] = PIN_A15;
                                                                            #ifdef PIN_A16
                    else if( i == 16 )
                        A_PIN_ARRAY[ i ] = PIN_A16;
                                                                                #ifdef PIN_A17
                    else if( i == 17 )
                        A_PIN_ARRAY[ i ] = PIN_A17;
                                                                                    #ifdef PIN_A18
                    else if( i == 18 )
                        A_PIN_ARRAY[ i ] = PIN_A18;
                                                                                        #ifdef PIN_A19
                    else if( i == 19 )
                        A_PIN_ARRAY[ i ] = PIN_A19;
                                                                                            #ifdef PIN_A20
                    else if( i == 20 )
                        A_PIN_ARRAY[ i ] = PIN_A20;
                                                                                                #ifdef PIN_A21
                    else if( i == 21 )
                        A_PIN_ARRAY[ i ] = PIN_A21;
                                                                                                    #ifdef PIN_A22
                    else if( i == 22 )
                        A_PIN_ARRAY[ i ] = PIN_A22;
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
            #else
            //Some boards don't have good definitions and constants for the analog pins :-(
                #ifdef DEBUG
                        Serial.println( F( "Creating analog pin definitions" ) );
                #endif
                for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
                    A_PIN_ARRAY[ i ] = i + FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES;
            #endif //end of PIN_A0 check
        #endif
    #endif
    #ifdef DEBUG
            for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
                Serial.println( A_PIN_ARRAY[ i ] );
                Serial.print( F( "PlotterMaxScale = " ) );
                Serial.println( PlotterMaxScale );
        #ifdef DIFFERENTIAL
            Serial.print( F( "( uint32_t )pow( 2, HighestBitResFromAddonADC - 1 ) = " ) );Serial.println( ( uint32_t )pow( 2, HighestBitResFromAddonADC - 1 ) );
        #else
            Serial.print( F( "( uint32_t )pow( 2, HighestBitResFromAddonADC ) = " ) );Serial.println( ( uint32_t )pow( 2, HighestBitResFromAddonADC ) );
        #endif
                Serial.println( F( "End of setup" ) );
    #endif
}

void plot_the_normal_and_magnified_signals( uint8_t channel )
{
    value = value / SAMPLE_TIMES;
    Serial.print( value + screen_offsets[ channel ].zero_of_this_plotline ); //This is color one
    
    //Next lines plot a magnified version.  First, magnify_adjustment is determined
    Serial.print( F( " " ) );

//The following preprocessor directive is NOT TESTED 29 May 2018:  Submit a better formula if you determine it.
    #if ( ( HighestBitResFromAddonADC > 23 ) && ( MULTIPLICATION_FACTOR > 255 ) ) || ( ( HighestBitResFromAddonADC > 14 ) && ( MULTIPLICATION_FACTOR > 1000 ) ) || ( ( HighestBitResFromAddonADC > 10 ) && ( MULTIPLICATION_FACTOR > 2000 ) ) || ( ( HighestBitResFromAddonADC < 11 ) && ( MULTIPLICATION_FACTOR > 5000 ) )
        Serial.print( 0 ); //This is color two or four when magnification is too large 4294967296 is max
    #else
        value *= MULTIPLICATION_FACTOR; //This needs to promote to float if normal cast produces overflow but I don't know how to do it without making it float always which is not native and thus too inefficient
    
        if( screen_offsets[ channel ].magnify_adjustment + screen_offsets[ channel ].zero_of_this_plotline > value )
            screen_offsets[ channel ].magnify_adjustment = value - screen_offsets[ channel ].zero_of_this_plotline - ( ( screen_offsets[ channel ].high_limit_of_this_plotline - screen_offsets[ channel ].zero_of_this_plotline ) * REPOSITION_RATIO_OF_MAGNIFIED_VIEW_WHEN_LIMITS_GET_EXCEEDED ) ;
    
        if( screen_offsets[ channel ].magnify_adjustment + screen_offsets[ channel ].high_limit_of_this_plotline < value )
            screen_offsets[ channel ].magnify_adjustment = value - screen_offsets[ channel ].high_limit_of_this_plotline + ( ( screen_offsets[ channel ].high_limit_of_this_plotline - screen_offsets[ channel ].zero_of_this_plotline ) * REPOSITION_RATIO_OF_MAGNIFIED_VIEW_WHEN_LIMITS_GET_EXCEEDED ) ;
            
            //Plot it now
        Serial.print( value - screen_offsets[ channel ].magnify_adjustment ); //This is color two or four
    #endif
    Serial.print( F( " " ) );
}

void loop() 
{    
    for( uint16_t plotter_loops = 0; plotter_loops < 500 / 3; plotter_loops++ ) 
    {
        #if ( NUM_ANALOG_INPUTS_TO_PLOT > 0 ) //plot the inboard analogs first and above
            for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
            {
                value = analogRead( 14 ) << BitsToShiftInboardADCValues;
//                value = analogRead( *( A_PIN_ARRAY + i ) ) << BitsToShiftInboardADCValues;
    
                for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
                {
                    #if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
                                    delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
                    #endif
                    #if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
                                    delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
                    #endif
                    value += ( analogRead( 14 ) << BitsToShiftInboardADCValues );
//                    value += ( analogRead( *( A_PIN_ARRAY + i ) ) << BitsToShiftInboardADCValues );
                }
                plot_the_normal_and_magnified_signals( i );
            }
        #endif

        #if ( NUM_ADDON_ADC_INPUTS_TO_PLOT > 0 )
            for( uint8_t i = 0; i < NUM_ADDON_ADC_INPUTS_TO_PLOT; i++ )
            {
                #if ( HighestBitResFromAddonADC == 11 ) || ( HighestBitResFromAddonADC == 15 )
                    value = ads.readADC_SingleEnded( i );
                    while( value > pow( 2, HighestBitResFromAddonADC ) )
                    {
                        value = ads.readADC_SingleEnded( i );
                    }
                #else
                    #ifdef DIFFERENTIAL
                        value = ( ( ( i == 1 ) ? ( ads.readADC_Differential_2_3() ) : ( ads.readADC_Differential_0_1() ) ) + pow( 2, HighestBitResFromAddonADC - 1 ) );
                        #ifdef DEBUG
                            Serial.print( F( "Read direct differential value " ) );
                            Serial.println( ads.readADC_Differential_0_1() );
                            Serial.print( F( "Read adjusted differential value " ) );
                            Serial.println( value );
                        #endif
                    #endif
                #endif
                #if ( defined SAMPLE_TIMES ) && ( SAMPLE_TIMES > 0 )
                    for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
                    {
                        #if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
                            delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
                        #endif
                        #if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
                            delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
                        #endif
                        #if ( HighestBitResFromAddonADC == 11 ) || ( HighestBitResFromAddonADC == 15 )
                            valueTemp = ads.readADC_SingleEnded( i );
                            while( valueTemp > pow( 2, HighestBitResFromAddonADC ) ) valueTemp = ads.readADC_SingleEnded( i );
                        #else
                            #ifdef DIFFERENTIAL
                                valueTemp = ( ( ( i == 1 ) ? ( ads.readADC_Differential_2_3() ) : ( ads.readADC_Differential_0_1() ) ) + pow( 2, HighestBitResFromAddonADC - 1 ) );
                                #ifdef DEBUG
                                    Serial.print( F( "Read adjusted differential valueTemp " ) );
                                    Serial.println( valueTemp );
                                #endif
                            #endif
                        #endif
                        value += valueTemp;
                    }
                #endif
                plot_the_normal_and_magnified_signals( i + NUM_ANALOG_INPUTS_TO_PLOT );
            }
        #endif
        if( graphline ) valueTemp = 0;
        else valueTemp = PlotterMaxScale;
        Serial.println( valueTemp );
        #if ( 12 * ( NUM_ANALOG_INPUTS_TO_PLOT + NUM_ADDON_ADC_INPUTS_TO_PLOT ) < 110  )
            #define DELAY_TIME ( 110 - ( 12 * ( NUM_ANALOG_INPUTS_TO_PLOT + NUM_ADDON_ADC_INPUTS_TO_PLOT ) ) )
            delay( DELAY_TIME );
        #endif
    }
    graphline = !graphline;
}
