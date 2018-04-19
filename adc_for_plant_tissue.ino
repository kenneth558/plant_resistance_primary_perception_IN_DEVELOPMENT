//============================================
// ADC demo for Larduino w/ LGT8F328D
// Using new added internal 2.56V reference
//============================================

#define NUM_ANALOG_INPUTS_TO_PLOT 0 //The number of consecutive analog pins to plot, beginning with PIN_A0
#define NUM_ADS1115_INPUTS_TO_PLOT 1

#define UpperLimitAnalogInput 4095
#define LowerLimitAnalogInput 0
#define UpperLimitADS1115Input 65535
#define LowerLimitADS1115Input 0

#include <math.h>
#include <Adafruit_ADS1015.h>//for systems using ADS1115/ADS1015
Adafruit_ADS1115 ads;

const uint8_t ADC_RES_BIT = 12;
const uint8_t SAMPLE_TIMES = 5;

/*
 * 
 * The following pin defines are for the WeMos XI/TTGO XI board only
 * Change per your board layout
 * 
 */
#ifndef PIN_A0
    #define PIN_A0 14
    #define PIN_A1 15
    #define PIN_A2 16
    #define PIN_A3 17
    #define PIN_A4 18
    #define PIN_A5 19
#endif

uint8_t *A_PIN_ARRAY;

void setup() 
{
    analogReference( DEFAULT );
    
    Serial.begin( 19200 );
//#ifndef ARDUINO_AVR_DIGISPARKPRO
//    analogReadResolution( ADC_RES_BIT );
//#endif
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
ads.begin();
}

void loop() 
{
  int16_t adc0, adc1, adc2, adc3;
  unsigned long value;


    if( NUM_ANALOG_INPUTS == 255 )
    {
        bool beenhere = false;
        if( !beenhere ) 
        {
            beenhere = true;
            Serial.println( F( "Sorry, but you will have to manually define the variable NUM_ANALOG_INPUTS and re-compile..." ) );
        }
    }
    else
    {
        for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
        {
            value = analogRead( *( A_PIN_ARRAY + i ) );
            for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
            {
              value += analogRead( *( A_PIN_ARRAY + i ) );
            }
            value = (uint16_t)( value / SAMPLE_TIMES );
/* */
        Serial.print( UpperLimitAnalogInput ); //constant max X
        Serial.print(" ");
/* */
            Serial.print( value );
            Serial.print( " " );
/* */
        Serial.print( LowerLimitAnalogInput );// constant min X
        Serial.print(" ");
/* */
        }
    }
/*
    adc0 = ads.readADC_SingleEnded(0);
    adc1 = ads.readADC_SingleEnded(1);
    adc2 = ads.readADC_SingleEnded(2);
    adc3 = ads.readADC_SingleEnded(3);
*/
    for( uint8_t i = 0; i < NUM_ADS1115_INPUTS_TO_PLOT; i++ )
    {
        value = ads.readADC_SingleEnded( i );
        for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
        {
          value += ads.readADC_SingleEnded( i );
        }
        value = (uint16_t)( value / SAMPLE_TIMES );
/* */
        Serial.print( UpperLimitADS1115Input / 2 ); //constant max X
        Serial.print(" ");
/* */
        Serial.print( value );
        Serial.print(" ");
/* */
        Serial.print( LowerLimitADS1115Input );// constant min X
        Serial.print(" ");
/* */
    }
    Serial.println();
    delay( 100 );
}
