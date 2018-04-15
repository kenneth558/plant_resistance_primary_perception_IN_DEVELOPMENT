//============================================
// ADC demo for Larduino w/ LGT8F328D
// Using new added internal 2.56V reference
//============================================
#include <math.h>
long int value;//TheWeMos has 12-bit ADC resolution 
const uint8_t ADC_RES_BIT = 12;
const uint8_t SAMPLE_TIMES = 5;
#define PIN_A0 14
#define PIN_A1 15
#define PIN_A2 16
#define PIN_A3 17
#define PIN_A4 18
#define PIN_A5 19

void setup() 
{
    analogReference( DEFAULT );
    
    Serial.begin( 19200 );
    analogReadResolution( ADC_RES_BIT );
}

void loop() 
{
    value = analogRead( PIN_A0 );
    for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
    {
      value += analogRead( PIN_A0 );
    }
    value = value / SAMPLE_TIMES;
    Serial.print( value );
    if( value < 1000 ) Serial.print( " " );
    if( value < 100 ) Serial.print( " " );
    if( value < 10 ) Serial.print( " " );
    Serial.print( " at " );
    Serial.print( ADC_RES_BIT );
    Serial.println( " bits" );
    delay( 500 );
}
