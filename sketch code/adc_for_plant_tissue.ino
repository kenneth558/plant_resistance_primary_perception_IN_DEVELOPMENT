//        Before compiling this sketch, you must set or confirm the following appropriately for your configuration and preferences !!!
#define USING_LM334_WITH_DIGIPOT_BANKS 1                                                       //Number of digipot Wheatstones you have, but this sketch revision level not tested beyond 1.  Remove if using Wheatstone bridge with only standard resistors.  make this the number of bridges with upper resistive elements being LM334s controllable with the MCP4162-104 pots
#define NUM_OF_INBOARDS_PLOTTED 2                                                              //The number of consecutive analog pins to plot, beginning with PIN_A0
#define NUM_OF_OUTBOARDS_PLOTTED 1                                                             //The number of consecutive "highest-sensitivity ADC" pins to plot, beginning with A0 and, if double-ended, A1.  ADDON ADC ONLY - DOES _NOT_ INCLUDE INBOARD ANALOG INPUT PINS
#define MAGNIFICATION_FACTOR 14                                                                //Activates the plotting of magnified traces in all ADC linespaces; upper limit somewhere less than 4,294,967,295. Note: you can disable displaying magnified traces altogether by not defined this macro at all. Proper use of SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS will also disable magnified traces of the first two analog inputs
#define HIGHEST_SENSI_ADDON_ADC_TYPE HX711                                                     //Proposing that "ADS1231" covers ADS1231; could make this "ADS1232" (ADS1232), "ADS1242" (ADS1242), "AD779x" (AD779x), "AD7780" (AD7780), "HX711" (HX711), "MAX112x0" (MAX112x0...) or "LTC2400" (LTC2400) but code not included in v.FREE; ONLY ONE TYPE ALLOWED
#define HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC 24                                        //All ADC values will get scaled to the single-ended aspect of this,  15 is ADS1115 single-ended, 16 for double-ended when two LM334s are used.  change to 11 for ADS1015 single-ended or 12 with two LM334s, (future: change to 24 for HX711--NO b/c there is the ADS1231 at 24 bits)
#define SAMPLE_TIMES 2                                                                         //To better average out artifacts we over-sample and average.  This value can be tweaked by you to ensure neutralization of power line noise or harmonics of power supplies, etc.....
#define MOST_PROBLEMATIC_INTERFERENCE_FREQ 60                                                  //This is here just in case you think that you might have some interference on a known frequency.
#define DELAY_TIME_BETWEEN_SAMPLES_MS ( 1000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ / SAMPLE_TIMES ) //COARSE ADJUST
#define DELAY_TIME_BETWEEN_SAMPLES_US ( ( ( 1000000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ ) - ( DELAY_TIME_BETWEEN_SAMPLES_MS * SAMPLE_TIMES * 1000 ) ) / SAMPLE_TIMES ) //FINE ADJUST.  THIS GETS ADDED TO COARSE ADJUST, PRECISION = TRUNCATED PRAGMATICALLY TO uSec TO ACKNOWLEDGE SOME OVERHEAD FOR LOOPING SUPPORT CODE   // End of this part of code update
#define FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES 14 //Some boards don't have good definitions and constants for the analog pins :-(
#define PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED 99 //BETWEEN 0 AND 100 indicating how much of the display region in percent to skip when magnified view trace has to get repositioned because trace would be outside region bounds; NO BOUNDS CHECKING IS PROVIDED!!!
#define ANALOG_INPUT_BITS_OF_BOARD 10                                                          //Most Arduino boards are 10-bit resolution, but some can be 12 bits.  For known 12 bit boards (SAM, SAMD and TTGO XI architectures), this gets re-defined below, so generally this can be left as 10 even for those boards
#define SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING 9                     //8 works only usually
#define HIGHEST_SENSI_PGA_GAIN_FACTOR 128                                                      //For HX711 a gain of 128 gets applied to channel A. Available to you for your own use PGA=Programmable Gain Amplifier: many ADCs will correlate a gain of one with full-scale being rail-to-rail, while a gain of anything higher correlates to full-scale being in the mV range (most sensitive and most noise-susceptible).
#define MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS 70                                                //Sets a maximum speed limit, but actual speed may be further limited by other factors
#define SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS 1 //If defined allows the rail-to-rail inboard Analog Inputs to be used to adjust digipots, but mainly causes first inboard Analog Inputs to be paired (superimposed in pairs sharing plot-line spaces) so even manual pots can be adjusted easily.
#define AUTO_BRIDGE_BALANCING  //increases setup time and during which the plot timing line stays high, then spikes low and high to indicate balancing complete //Turns on auto-balancing in setup(), significant time elapse for this to complete!
//#define DEBUG                                                                                  //Don't forget that DEBUG is not formatted for Serial plotter, but might work anyway if you'd never print numbers only any DEBUG print line
//#define POT_TEST_WOBBLE_POSITIVE 0                                                             //For testing - wobbles digipot settings on bank index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the signal leg
//#define POT_TEST_WOBBLE_NEGATIVE 0                                                             //For testing - wobbles digipot settings on bank index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the reference leg
//#define LEAVE_POT_VALUES_ALONE_DURING_SETUP                                                    //First run should leave this undefined to load digi pots with some values
//#define BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE 1                                      //Though the name suggests otherwise, this offset will be applied to all signal lines, not just the first one, until further development (I couldn't make this into an array).  Inboard Analog Inputs of 10 bits will make much change with little values, 12 bit inboard allows more flexibility here
#ifdef BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE
    #define ADDITIONAL_LSB_DIGIPOT_SETTING_BIAS_TO_SIGNAL_TRACE 1                                //To maintain consistent effect with the above, associated macro, this gets applied inverted. This is in lieu of setting by reading the ADCs and zeroing them.
#endif
#ifdef __LGT8FX8E__
    #define BAUD_TO_SERIAL 19200  //This speed is what works best with WeMos XI/TTGO XI board.  Experiment as desired.
#else
    #define BAUD_TO_SERIAL 115200 //YOU MAY SET THIS TO THE MAXIMUM VALUE THAT YOUR CONFIGURATION WILL FUNCTION WITH (UNLESS YOU'RE USING THE WeMos XI/TTGO XI, OF COURSE)
#endif
#define LSB_DIGIPOT_RESISTANCE_STEP_PER_MSB_RESISTANCE_STEP 10                                    //Example: If the LSB digipot is 200 ohms/step and the MSB digipot is 2000 ohms/step, this value will be 10
//#define POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR 3                       //NOT the digital number //Can use a spare analog input as magnification attenuator by connecting wiper of a pot (100K or greater, please) that voltage-divides 0-5 vdc.
//#define USING_DUAL_74LV138_DECODERS_FOR_DIGIPOT_CS_LINES
//!!! NOTE !!! 270+ lines below this are also macros entitled similar to BANK_X_LEG_X_DIGITAL_POT_X.  Those macros must also be set to correspond to the pins driving the CS lines of digipots

//No need to change macros below:
#define CONVERT_TWOS_COMP_TO_SINGLE_ENDED( value_read_from_the_differential_ADC, mask, xorvalue ) ((value_read_from_the_differential_ADC & mask)^xorvalue)
//OTHER MACROS (DEFINES OR RE-DEFINES) ELSEWHERE: VERSION, NUM_OF_INBOARDS_PLOTTED, NUM_OF_OUTBOARDS_PLOTTED, DIGIPOT_0_B0L0_STARTVALUE - DIGIPOT_2_B0L1_STARTVALUE, HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC, DIFFERENTIAL, PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, PLOTTER_MAX_SCALE, HUNDREDTHPLOTTER_MAX_SCALE, SAMPLE_TIMES, SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE, COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG, HEIGHT_OF_A_PLOT_LINESPACE

//FUTURE #define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 2                           //sets how soon run-time auto-balancing kicks in when trace goes off scale
//FUTURE #define TEST_STEP_UP_DOWN COMMONMODE                                                                  //Available: SINGLESIDE COMMONMODE
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DIGIPOT_CS_LINES 
    #warning These_ 7 pin numbers get specified normally, but be sure you specify the _digital_pot_CS_pins_ with the MSB set to decode them; i.e., make those pin numbers>= 128, but not these
    #define FIRST_STAGE_3_TO_8_DECODER_A0_PIN 5
    #define FIRST_STAGE_3_TO_8_DECODER_A1_PIN 6
    #define FIRST_STAGE_3_TO_8_DECODER_A2_PIN 7
    #define SECOND_STAGE_3_TO_8_DECODER_A0_PIN 8
    #define SECOND_STAGE_3_TO_8_DECODER_A1_PIN 9
    #define SECOND_STAGE_3_TO_8_DECODER_A2_PIN 10
    #define BOTH_STAGES_3_TO_8_DECODER_ENABLE_PIN 11
#endif
/*******************(C)  COPYRIGHT 2018 KENNETH L ANDERSON *********************
* 
*      ARDUINO ELECTRICAL RESISTANCE/CONDUCTANCE MONITORING SKETCH 
*      
* File Name          : adc_for_plant_tissue.ino
* Author             : KENNETH L ANDERSON
* Version            : v.Free
* Date               : 11-Sep-2018
* Description        : To replicate Cleve Backster's findings that he attributed to a phenomenon he called "Primary Perception".  Basically, this sketch turns an Arduino MCU and optional (recommended) ADS1115 into a nicely functional poor man's polygraph in order to learn/demonstrate telempathic gardening.
* Boards tested on   : Uno using both ADS1115 and inboard analog inputs.  
*                    : TTGO XI using ADS1115.  
*                    : Many other configurations should work fine.  
*                    : The ATTINY85 is not suitable at all due to not having hardware serial
* 
* Known limitations  : No ability to accept user input from keyboard during run time due to Arduino plotter limitation
*                    : Re-compile is needed for any changes to configuration
*                    : Analog input pins being used MUST be the first available analog inputs
*                    : Only a single add-on ADS ADC device and only 1 or 2 differential channels on it is tested
*                    : Conventional add-on high-sensitivity ADCs limit their common mode differential input range to a few millivolts with active or passive clamping
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
* TODO:  Arrange for run-time keyboard input to eliminate need to re-compile when changes are made or plotting adjustments are desired.  Will require non-Arduino IDE plotter
*        Use dual tightly thermally coupled LM334s to prevent power supply noise from plotting (i.e., convert from resistance to conductance)  5 VOLT DEVICES ONLY.   A toroid-based noise suppression coil might be needed.  The 2nd LM334 excites a fixed resistor circuit parallel to the plant circuit and connected to a second analog input for software temperature compensation.
*        Use digital potentiometer (MCP41XXX or MCP42XXX) for more automated balancing of the two serial resistances.  The charge pump noise generated by the x9c series rules it out.
*        Accommodate more 24-bit amps like ADS1231
* 
*  These planned enhancements will be reserved for NOT-FOR-FREE sketch versions in the future
*  
*  Changelog:  30 April 2018 :  Final inboard 10 bit operation and ADS1X15 operation has been achieved.  Future work on free version will be for 12 bit boards only
*              04 May   2018 :  Some 12 bit tweaking so that TTGO/WeMos XI, SAM and SAMD architectures compile with inboard analog inputs to computed at 12 bit even though ANALOG_INPUT_BITS_OF_BOARD is set at default.
*              18 May   2018 :  Anti-aliasing code
*              29 May   2018 :  Differential use of ADS1x15 to allow LM334 temperature comp to negative inputs so LM334 can be used on positive inputs
*              32 May   2018 :  Added skeleton preprocessor defines for user to compatibly code their own support for a few 24-bit ADCs
*              05 June  2018 :  HX711 accommodated, you'll just have to balance the bridge manually
*              08 June  2018 :  Bugfix for inboard analog inputs above the first one - they didn't print before this fix
*              17 June  2018 :  Corrected pointer reinitialize of AnalogPinArray that disabled internal Analog Input pins.  Added "while ( !Serial );" for Leonardo's native USB; starting to add framework for programmable potentiometers, changed defines to allow for a separate full-scale, lower res ADC and a high res ADC for normal viewing, etc,
*              18 June  2018 :  Bug fixes relative to displaying multiple traces while one or more are from inboard analog pins
*              13 July  2018 :  Modified plotter timing trace to notch horizontally at range min and max for signal traces when it crosses up and down.  Incorporated digi pot adjustings in debug mode. Enabled bypass of digi pot set in setup()
*              14 July  2018 :  Improved horizontal timing trace notching - made it shorter and consistent between levels
*              15 July  2018 :  Allow unique digipot initializing value for each pot.  Discovered HX711 input Z is way too low for use without buffers.  Regrouping....
*              16 July  2018 :  Removed disparaging comments toward TTGO XI/Wemo XI because we will make the plunge to employ the AD8244 buffer as standard, resulting in those boards being eligible as any other board
*              20 July  2018 :  Improved plotting with INBOARDINPARALLELWITHHIGHESTSENSI and improved 24-bit plot values
*              26 July  2018 :  Corrected conversion from twos complement differential readings to proper single ended plotting
*              27 July  2018 :  Discovered HX711's common-mode level sweet spot for max sensitivity, made COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG with default of half-scale
*              28 July  2018 :  If using digipots with LM334s, sketch can now auto-balance during setup and target the most sensitive common-mode voltage of a selected outboard ADC...LATER REVISIONS BROKE AUTO_BRIDGE_BALANCING
*              29 July  2018 :  With INBOARDINPARALLELWITHHIGHESTSENSI && AUTO_BRIDGE_BALANCING defined, plotspace now excludes the two inboard Analog Input traces, making maximum linespace available for the other more interesting traces
*              30 July  2018 :  Now able continuously to run-time auto-balance at least with a single HX711 LATER REVISIONS BROKE AUTO_BRIDGE_BALANCING
*              31 July  2018 :  I've noticed one sketch bug in the printing of the magnified traces in that they don't stay within bounds any more. Older sketch versions never had that problem. I'm not sure where it began, but it seems to be a memory management problem from my inital troubleshooting rather than any type of algorithm weakness. I'll work on that when I'm able... 
*              01 Aug   2018 :  Working on vertical positioning of the magnified traces
*              23 Aug   2018 :  Fixed magnified traces in all respects; added functionality to display digipot calibration effects during calibration in setup(); started adding code to handle multiple digipot banks that utilize dual 74VHC138/74LV138s.  Still no AUTO_BRIDGE_BALANCING
*              23 Aug   2018 :  Magnification factor adjustable downward via a potentiometer if defined POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR with the digital number of an inboard analog input pin.
*              23 Aug   2018 :  added USING_DUAL_74LV138_DECODERS_FOR_DIGIPOT_CS_LINES with possibly enough code (just needs testing). Allowed for any ratio of LSB pot step to MSB step with LSB_DIGIPOT_RESISTANCE_STEP_PER_MSB_RESISTANCE_STEP
*              11 Sep   2018 :  Back with new style of arrays useage to make bug-free coding more possible.
*              NEXT          :  Auto adjust only works in setup, not tested beyond that, quite sure it doesn't work yet during run time
*              NEXT          :  Runtime auto-adjust testing: Test proposed code for LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER
*              NEXT          :  Try putting some alpha chars into output for future expansion beyond Arduino
*              NEXT          :  EEPROM storage of things like ADC sweet spot, initial digipot settings, etc
*              NEXT          :  Accommodate ADS1232 &/or ADS1231
*               
*********************************************************************************************************************/
#define VERSION "v.Free"  // Since this never gets used anywhere, it doesn't compile in so no memory is wasted
#include <math.h>
//global variables are declared static to prevent them from being seen by any later user-added compilation units that would try, presumeably inadvertently, through the use of the "extern" cast
#define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ( 1 << ( ANALOG_INPUT_BITS_OF_BOARD - 1 ) ) // Needed if HIGHEST_SENSI_ADDON_ADC_TYPE has a sweet spot of max sensitivity, unlike true op-amp.  (HX711 == 306; normal op-amp, which has none == Vcc/2 == 512)
//Next, force all macros to be coherent with each other
#ifndef NUM_OF_OUTBOARDS_PLOTTED
    #define NUM_OF_OUTBOARDS_PLOTTED 0
#elif ( 1 > NUM_OF_OUTBOARDS_PLOTTED + 0 ) //Evaluates to 1>+0 if the macro was defined as a blank.  Only way I know of to check for blank macros when we need a number in them
    #undef NUM_OF_OUTBOARDS_PLOTTED
    #define NUM_OF_OUTBOARDS_PLOTTED 0
#endif
#ifndef NUM_OF_INBOARDS_PLOTTED  
    #define NUM_OF_INBOARDS_PLOTTED 0 //This is used for some lightly thought out formulas in any case, so it must be defined until formulas are re-written to handle null values, but that might not be desirable as it results in more confusing formulas
#elif ( 1 > NUM_OF_INBOARDS_PLOTTED + 0 )
    #undef NUM_OF_INBOARDS_PLOTTED
    #define NUM_OF_INBOARDS_PLOTTED 0
#endif
#ifdef MAGNIFICATION_FACTOR
    #if ( MAGNIFICATION_FACTOR == 0 ) //This value not allowed, assume it to mean 1
        #undef MAGNIFICATION_FACTOR
        #define MAGNIFICATION_FACTOR 1
    #endif
#endif
#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 ) //Since so many of the ADC libraries already use OO classes, we'll set that as a pattern - instantiate prior to executing any code
    #define HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC / 2 )
    #if ( ( HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC * 2 ) == HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC )
        #define DIFFERENTIAL 
    #endif
    #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC < 17 ) && ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
        #include <Adafruit_ADS1015.h>//for systems using ADS1115/ADS1015  Data addressable I2C, shares bidirectional, open-collector data and clk only with other I2C slaves on same bus, must use the core-defined SDA/SCL pins except ESP8266 and ATtiny85 or see https://www.arduino.cc/en/reference/wire or see the Adafruit_ADS1X15-master README.md
/*  
*  With Adafruit_ADS1015.h, SDA, SCL Wemos XI/TTGO XI use A4 for SDA, and A5 is SCL.
*/
        #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 15 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 16 )
            Adafruit_ADS1115 ads;  //For when ADS1115 is being used Data addressable I2C and shares bidirectional, open-collector data and clk only with other I2C slaves on same bus, must use the core-defined SDA/SCL pins except ESP8266 and ATtiny85 or see https://www.arduino.cc/en/reference/wire or see the Adafruit_ADS1X15-master README.md
        #else
            #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 12 )
                Adafruit_ADS1015 ads;  //For when ADS1015 is being used Data addressable I2C and bidirectional, open-collector data and clk only with other I2C slaves on same bus, must use the core-defined SDA/SCL pins except ESP8266 and ATtiny85 or see https://www.arduino.cc/en/reference/wire or see the Adafruit_ADS1X15-master README.md
            #else
                #error “This add-on ADC resolution is not supported in this sketch version."
            #endif
        #endif
    #else
        #define PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC 2 //Must always be dedicated in cases where it doesn't go hi-Z (as in HX711).  This won't work if an ADS1x15 or any other I2C device is also used on this pin
        #define PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC 3 //Must always be dedicated in cases where it doesn't go hi-Z (as in HX711).  This won't work if an ADS1x15 or any other I2C device is also used on this pin
/*
 * If ever would use an ADS1x15 along with this ADC, then see error msg below
        #ifdef ARDUINO_AVR_LEONARDO
            #if ( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC == 2 ) || ( PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC == 3 ) || ( PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC == 2 ) || ( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC == 3 )
                #error "The pins being used for clock and data of the ADC conflict with the I2C pins used by ADS1x15.  See https://www.arduino.cc/en/reference/wire and the Adafruit_ADS1X15-master README.md.  Remove this warning once you are satisfied one way or another"
            #endif
        #endif
*/
        #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == HX711 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 24 )  //The HX711 does NOT communicate over open-collector I2C; pick your own pins for comming with it other than SS, CLK, MOSI, and MISO of SPI.  The digital interface to the HX711 is a proprietary SPI-like interface using CLK to select and Data is always lo-z (can't share either)
            #include <HX711.h>  //From https://github.com/bogde/HX711  This ADC has no CS pin so the library must use software SPI with dedicated CLK pin.  Not data selectable as would be in I2C, nor CS selectable - must be on dedicated CLK & Data lines
            HX711 hx711( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC ); // This library allows us to set the pins and gain here or later in a .begin().   
            #undef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
            #define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG 306                // If HIGHEST_SENSI_ADDON_ADC_TYPE has a sweet spot of max sensitivity, unlike true op-amp.  (HX711 == 305, ranging from 1.49 to 1.507 vdc depending which scale is used to read it).  This will also be discovered and stored in EEPROM in a future revision
        #else
            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1232 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 24 )
            #else
                #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1242 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 24 ) //Which 24-bit ADC is single-ended?  ADS1242 It is 23 bits hopefully
                #else
                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == AD7780 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 24 )
                    #else
                        #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == AD779x ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 24 )
                        #else
                            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == MAX112x0 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 24 )
                            #else
                                #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == LTC2400 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 24 )
                                #else
                                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1231 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 24 )
                                    #else
                                        #error “This add-on ADC resolution is not supported in this sketch version."
                                    #endif
                                #endif
                            #endif
                        #endif
                    #endif
                #endif
            #endif
        #endif
    #endif
#else
    #ifdef HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC
        #undef HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC
    #endif
    #define HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC ANALOG_INPUT_BITS_OF_BOARD
    #ifdef HIGHEST_SENSI_ADDON_ADC_TYPE
        #undef HIGHEST_SENSI_ADDON_ADC_TYPE
    #endif
    #ifdef HIGHEST_SENSI_PGA_GAIN_FACTOR
        #undef HIGHEST_SENSI_PGA_GAIN_FACTOR
    #endif
#endif
#ifndef LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER
    #define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 65536
#endif
#ifndef BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE
    #define BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE 0
#endif
#if ( NUM_OF_INBOARDS_PLOTTED > 0 )
    #ifndef NUM_ANALOG_INPUTS
#error You will have to manually define the define variable NUM_ANALOG_INPUTS somewhere above this line and re-compile...
    #endif
#else
    #if ( NUM_OF_OUTBOARDS_PLOTTED == 0 )
You'll need to manually define at least one of the variables NUM_OF_INBOARDS_PLOTTED or NUM_OF_OUTBOARDS_PLOTTED where they appear in the lines above and re-compile...
If you only have the Arduino without an ADS1X15, then define NUM_OF_INBOARDS_PLOTTED.  Otherwise, define NUM_OF_OUTBOARDS_PLOTTED and/or both of them.
    #endif
#endif

#if defined MAGNIFICATION_FACTOR && ( ( PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED > 100 ) || ( PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED < 0 ) )
    #error The macro PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED is out of bounds
#endif

// NOT ALL OF THE FOLLOWING INDEX_OF_INBOARDS_NOT_PLOTTED MACROS WILL BE CORRECT.  ADJUST AS NEEDED DURING DEVELOPMENT
//#error Examine carefully the following calculations:
//The following redefines likely obsolete a number of macro checks in the body of sketch but I haven't gone through to clean them up
#ifdef USING_LM334_WITH_DIGIPOT_BANKS
    #if ( 1 > USING_LM334_WITH_DIGIPOT_BANKS + 0 ) //This traps both a null and all negatives - they are invalid and get changed to a 1 value, not a 0 value
        #undef USING_LM334_WITH_DIGIPOT_BANKS
        #define USING_LM334_WITH_DIGIPOT_BANKS 1  //Make sure it contains an integer
        #warning You are specifying USING_LM334_WITH_DIGIPOT_BANKS with no number: Assuming 1 for the number of input pairs that the first analog pins form to read analog signals
    #elif ( USING_LM334_WITH_DIGIPOT_BANKS == 0 )
        #undef USING_LM334_WITH_DIGIPOT_BANKS     //Zero value means same as undefined so undef it to minimize variations
    #endif
#endif
#if ( NUM_OF_INBOARDS_PLOTTED < 2 ) && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
    #undef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
#endif
#ifdef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
    #if ( 1 > SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS + 0 ) //This traps both a null and all negatives - they are invalid
        #undef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
        #define SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS 1
        #warning You are specifying SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS with no number: Assuming just a single bridge exists
    #elif ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS == 0 )
        #undef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS //Zero value means same as undefined so undef it to minimize variations
    #endif
#endif

#ifndef USING_LM334_WITH_DIGIPOT_BANKS
    #undef POT_TEST_WOBBLE_POSITIVE
    #undef POT_TEST_WOBBLE_NEGATIVE
    #undef TEST_STEP_UP_DOWN
    #undef AUTO_BRIDGE_BALANCING
#else
/*
 Using a Microchip MCP4162 digital potentiometer 
    [http://bit.ly/iwDmnd]
    http://tronixstuff.com/tutorials > chapter 34 | CC by-sa-nc | John Boxall

    SS – digital 10 to CS of a single digital pot, not abstracted by library call, so can be any pin as determined within main function unidirectional NOT PIN 10 ON LEONARDO - IS FOUND ON LED_BUILTIN_RX (PIN 17) ONLY
    MOSI – digital 11 to inputs of all digital pots unidirectional NOT PIN 11 ON LEONARDO - IS FOUND ON 1CSP ONLY.  REQ'D IN ALL CASES.
    MISO – digital 12 to outputs of all digital pots unidirectional NOT PIN 12 ON EXCEPT LEONARDO - IS FOUND ON 1CSP ONLY.  OPTIONAL IN SOME CASES.
    SCK – digital 13 to CLK of all digital pots unidirectional NOT PIN 13 ON LEONARDO - IS FOUND ON 1CSP ONLY
    Clock speed of MCP4162 is 10 MHz max, well capable to use default Arduino speed of 4 MHz.
    EEPROM and nonvolatile settings are only available with >8.5 Vdc to <12.5Vdc applied to CS pins of MCP4162, which we don't have.
    Therefore, we have no need to read data back from digipots b/c we're storing their settings in sketch variables.

*/
    #include "SPI.h" //This is the hardware implementatino of SPI with CS pin selectable devices, not addressable via data and unidirectional data in and data out pins.  The software implementation uses shiftIn() instead and is slower but flexible which pins get used and can be used adjunctive for cases where a chip has no CS pin.  Adafruit_ADS1015 uses the shiftIn() method, so those pins are user's choice.  Not data addressable as would be in I2C

    #ifdef POT_TEST_WOBBLE_POSITIVE
        #if ( 1 > POT_TEST_WOBBLE_POSITIVE + 0 )
            #undef POT_TEST_WOBBLE_POSITIVE
            #define POT_TEST_WOBBLE_POSITIVE 0 //make sure it contains a bank index, default is bank 0
        #endif
    #endif
    #ifdef POT_TEST_WOBBLE_NEGATIVE
        #if ( 1 > POT_TEST_WOBBLE_NEGATIVE + 0 )
            #undef POT_TEST_WOBBLE_NEGATIVE
            #define POT_TEST_WOBBLE_NEGATIVE 0 //make sure it contains a bank index, default is bank 0
        #endif
    #endif
    #define NUM_OF_DIGIPOTS_PER_BANK 6
    #define NUM_OF_DIGIPOTS ( NUM_OF_DIGIPOTS_PER_BANK * USING_LM334_WITH_DIGIPOT_BANKS )
    static uint8_t DigipotPins[ NUM_OF_DIGIPOTS ];
    static uint16_t DigipotValues[ NUM_OF_DIGIPOTS ];
    #define MAXPOTVALUE 257

//    #if ( USING_LM334_WITH_DIGIPOT_BANKS > 0 ) Just b/c this conforms to the pattern
//When using one or two 3:8 decoders, note that these pins numbers must be greater than 127
    #define BANK_0_LEG_0_DIGITAL_POT_0 5  // first digital pot's CS line connected to here. coarse adjust A positive leg
    #define BANK_0_LEG_0_DIGITAL_POT_1 6  // second digital pot's CS line connected to here.  coarse adjust B positive leg
    #define BANK_0_LEG_0_DIGITAL_POT_2 7  // third digital pot's CS line connected to here.  fine adjust positive leg
    #define BANK_0_LEG_1_DIGITAL_POT_0 8  // fourth digital pot's CS line connected to here.  coarse adjust A negative leg
    #define BANK_0_LEG_1_DIGITAL_POT_1 9  // fifth digital pot's CS line connected to here.  coarse adjust B negative leg
    #define BANK_0_LEG_1_DIGITAL_POT_2 10 // sixth digital pot's CS line connected to here.  fine adjust negative leg

    #define DIGIPOT_0_B0L0_STARTVALUE 57 //(MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
    #define DIGIPOT_1_B0L0_STARTVALUE 57 //(MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
    #define DIGIPOT_2_B0L0_STARTVALUE 40 //(MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
    #define DIGIPOT_0_B0L1_STARTVALUE 57 //(MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
    #define DIGIPOT_1_B0L1_STARTVALUE 57 //(MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
    #define DIGIPOT_2_B0L1_STARTVALUE 14 //(MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
    #if ( USING_LM334_WITH_DIGIPOT_BANKS > 1 ) //none of this below works, yet.  It is in process of development...
        #define BANK_1_LEG_0_DIGITAL_POT_0 5  // first digital pot's CS line connected to here. coarse adjust A positive leg
        #define BANK_1_LEG_0_DIGITAL_POT_1 6  // second digital pot's CS line connected to here.  coarse adjust B positive leg
        #define BANK_1_LEG_0_DIGITAL_POT_2 7  // third digital pot's CS line connected to here.  fine adjust positive leg
        #define BANK_1_LEG_1_DIGITAL_POT_0 8  // fourth digital pot's CS line connected to here.  coarse adjust A negative leg
        #define BANK_1_LEG_1_DIGITAL_POT_1 9  // fifth digital pot's CS line connected to here.  coarse adjust B negative leg
        #define BANK_1_LEG_1_DIGITAL_POT_2 10 // sixth digital pot's CS line connected to here.  fine adjust negative leg
        #define DIGIPOT_0_B1L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #define DIGIPOT_1_B1L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #define DIGIPOT_2_B1L0_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #define DIGIPOT_0_B1L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #define DIGIPOT_1_B1L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #define DIGIPOT_2_B1L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #if ( USING_LM334_WITH_DIGIPOT_BANKS > 2 )
            #define BANK_2_LEG_0_DIGITAL_POT_0 5  // first digital pot's CS line connected to here. coarse adjust A positive leg
            #define BANK_2_LEG_0_DIGITAL_POT_1 6  // second digital pot's CS line connected to here.  coarse adjust B positive leg
            #define BANK_2_LEG_0_DIGITAL_POT_2 7  // third digital pot's CS line connected to here.  fine adjust positive leg
            #define BANK_2_LEG_1_DIGITAL_POT_0 8  // fourth digital pot's CS line connected to here.  coarse adjust A negative leg
            #define BANK_2_LEG_1_DIGITAL_POT_1 9  // fifth digital pot's CS line connected to here.  coarse adjust B negative leg
            #define BANK_2_LEG_1_DIGITAL_POT_2 10 // sixth digital pot's CS line connected to here.  fine adjust negative leg
            #define DIGIPOT_0_B2L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
            #define DIGIPOT_1_B2L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
            #define DIGIPOT_2_B2L0_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
            #define DIGIPOT_0_B2L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
            #define DIGIPOT_1_B2L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
            #define DIGIPOT_2_B2L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
            #if ( USING_LM334_WITH_DIGIPOT_BANKS > 3 )
                #define BANK_3_LEG_0_DIGITAL_POT_0 5  // first digital pot's CS line connected to here. coarse adjust A positive leg
                #define BANK_3_LEG_0_DIGITAL_POT_1 6  // second digital pot's CS line connected to here.  coarse adjust B positive leg
                #define BANK_3_LEG_0_DIGITAL_POT_2 7  // third digital pot's CS line connected to here.  fine adjust positive leg
                #define BANK_3_LEG_1_DIGITAL_POT_0 8  // fourth digital pot's CS line connected to here.  coarse adjust A negative leg
                #define BANK_3_LEG_1_DIGITAL_POT_1 9  // fifth digital pot's CS line connected to here.  coarse adjust B negative leg
                #define BANK_3_LEG_1_DIGITAL_POT_2 10 // sixth digital pot's CS line connected to here.  fine adjust negative leg
                #define DIGIPOT_0_B3L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                #define DIGIPOT_1_B3L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                #define DIGIPOT_2_B3L0_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                #define DIGIPOT_0_B3L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                #define DIGIPOT_1_B3L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                #define DIGIPOT_2_B3L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                #if ( USING_LM334_WITH_DIGIPOT_BANKS > 4 )
                    #define BANK_4_LEG_0_DIGITAL_POT_0 5  // first digital pot's CS line connected to here. coarse adjust A positive leg
                    #define BANK_4_LEG_0_DIGITAL_POT_1 6  // second digital pot's CS line connected to here.  coarse adjust B positive leg
                    #define BANK_4_LEG_0_DIGITAL_POT_2 7  // third digital pot's CS line connected to here.  fine adjust positive leg
                    #define BANK_4_LEG_1_DIGITAL_POT_0 8  // fourth digital pot's CS line connected to here.  coarse adjust A negative leg
                    #define BANK_4_LEG_1_DIGITAL_POT_1 9  // fifth digital pot's CS line connected to here.  coarse adjust B negative leg
                    #define BANK_4_LEG_1_DIGITAL_POT_2 10 // sixth digital pot's CS line connected to here.  fine adjust negative leg
                    #define DIGIPOT_0_B4L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                    #define DIGIPOT_1_B4L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                    #define DIGIPOT_2_B4L0_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                    #define DIGIPOT_0_B4L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                    #define DIGIPOT_1_B4L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                    #define DIGIPOT_2_B4L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                    #if ( USING_LM334_WITH_DIGIPOT_BANKS > 5 )
                        #define BANK_5_LEG_0_DIGITAL_POT_0 5  // first digital pot's CS line connected to here. coarse adjust A positive leg
                        #define BANK_5_LEG_0_DIGITAL_POT_1 6  // second digital pot's CS line connected to here.  coarse adjust B positive leg
                        #define BANK_5_LEG_0_DIGITAL_POT_2 7  // third digital pot's CS line connected to here.  fine adjust positive leg
                        #define BANK_5_LEG_1_DIGITAL_POT_0 8  // fourth digital pot's CS line connected to here.  coarse adjust A negative leg
                        #define BANK_5_LEG_1_DIGITAL_POT_1 9  // fifth digital pot's CS line connected to here.  coarse adjust B negative leg
                        #define BANK_5_LEG_1_DIGITAL_POT_2 10 // sixth digital pot's CS line connected to here.  fine adjust negative leg
                        #define DIGIPOT_0_B5L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                        #define DIGIPOT_1_B5L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                        #define DIGIPOT_2_B5L0_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                        #define DIGIPOT_0_B5L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                        #define DIGIPOT_1_B5L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                        #define DIGIPOT_2_B5L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                        #if ( USING_LM334_WITH_DIGIPOT_BANKS > 6 )
                            #define BANK_6_LEG_0_DIGITAL_POT_0 5  // first digital pot's CS line connected to here. coarse adjust A positive leg
                            #define BANK_6_LEG_0_DIGITAL_POT_1 6  // second digital pot's CS line connected to here.  coarse adjust B positive leg
                            #define BANK_6_LEG_0_DIGITAL_POT_2 7  // third digital pot's CS line connected to here.  fine adjust positive leg
                            #define BANK_6_LEG_1_DIGITAL_POT_0 8  // fourth digital pot's CS line connected to here.  coarse adjust A negative leg
                            #define BANK_6_LEG_1_DIGITAL_POT_1 9  // fifth digital pot's CS line connected to here.  coarse adjust B negative leg
                            #define BANK_6_LEG_1_DIGITAL_POT_2 10 // sixth digital pot's CS line connected to here.  fine adjust negative leg
                            #define DIGIPOT_0_B6L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                            #define DIGIPOT_1_B6L0_STARTVALUE (MAXPOTVALUE / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                            #define DIGIPOT_2_B6L0_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                            #define DIGIPOT_0_B6L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                            #define DIGIPOT_1_B6L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                            #define DIGIPOT_2_B6L1_STARTVALUE (MAXPOTVALUE / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                        #endif
                    #endif
                #endif
            #endif
        #endif
    #endif
    #if defined ARDUINO_AVR_LEONARDO \
    && ( BANK_0_LEG_0_DIGITAL_POT_0 == 2 || BANK_0_LEG_0_DIGITAL_POT_0 == 3 \
    || BANK_0_LEG_0_DIGITAL_POT_1 == 2 || BANK_0_LEG_0_DIGITAL_POT_1 == 3 \
    || BANK_0_LEG_0_DIGITAL_POT_2 == 2 || BANK_0_LEG_0_DIGITAL_POT_2 == 3 \
    || BANK_0_LEG_1_DIGITAL_POT_0 == 2 || BANK_0_LEG_1_DIGITAL_POT_0 == 3 \
    || BANK_0_LEG_1_DIGITAL_POT_1 == 2 || BANK_0_LEG_1_DIGITAL_POT_1 == 3 \
    || BANK_0_LEG_1_DIGITAL_POT_2 == 2 || BANK_0_LEG_1_DIGITAL_POT_2 == 3 \
    )
//        #if ( USING_LM334_WITH_DIGIPOT_BANKS > 1 )
//            #if ( USING_LM334_WITH_DIGIPOT_BANKS > 2 )
//                #if ( USING_LM334_WITH_DIGIPOT_BANKS > 3 )
//                    #if ( USING_LM334_WITH_DIGIPOT_BANKS > 4 )
//                        #if ( USING_LM334_WITH_DIGIPOT_BANKS > 5 )
//                            #if ( USING_LM334_WITH_DIGIPOT_BANKS > 6 )
//                            #endif
//                        #endif
//                    #endif
//                #endif
//            #endif
//        #endif //Expand this if sketch expands
//    )//This style of compiler preprocessor nested definition doesn't really work.  It is here to show the desired concept
    
        #error "The pins being used for clock and data of the ADC conflict with the I2C pins used by ADS1x15.  See https://www.arduino.cc/en/reference/wire and the Adafruit_ADS1X15-master README.md.  Remove this warning once you are satisfied one way or another"
    #endif
/* EEPROM and nonvolatile settings are only available with >8.5, <12.5 Vdc applied to CS pins of MCP4162, which we don't have with mere Arduino: */
    #define FINETUNE true
#endif

#if ( ARDUINO_ARCH_XI || ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD ) //These are the boards known to have 12 bit analog inputs
    #ifdef ANALOG_INPUT_BITS_OF_BOARD
        #undef ANALOG_INPUT_BITS_OF_BOARD
    #endif
    #define ANALOG_INPUT_BITS_OF_BOARD 12  //These boards have 12 bit
#endif

#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
    #define SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC - ANALOG_INPUT_BITS_OF_BOARD )
#else
    #define SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE 0
#endif

/*
DEFINING INDEX_OF_INBOARDS_NOT_SUPERIMPOSED:
*/

#if defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS \
    && ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS > 0 )

    #if ( ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * 2 ) < NUM_OF_INBOARDS_PLOTTED ) //use the smaller of the two possibilities
        #define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * 2 )
    #else
        #define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED NUM_OF_INBOARDS_PLOTTED
    #endif

#else
    #define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED 0

#endif

/*
DEFINING INDEX_OF_INBOARDS_NOT_PLOTTED:
*/

#define INDEX_OF_INBOARDS_NOT_PLOTTED NUM_OF_INBOARDS_PLOTTED

/*
DEFINING INDEX_OF_OUTBOARDS:
*/

#if defined USING_LM334_WITH_DIGIPOT_BANKS \
    && ( ( USING_LM334_WITH_DIGIPOT_BANKS * 2 ) > NUM_OF_INBOARDS_PLOTTED )
    #define INDEX_OF_OUTBOARDS ( USING_LM334_WITH_DIGIPOT_BANKS * 2 )
#else
    #define INDEX_OF_OUTBOARDS NUM_OF_INBOARDS_PLOTTED
#endif

struct previous_readings_only_of_inboards_and_outboards
{
    uint32_t CurrentUnmagnifiedReading;
    uint32_t PreviousUnmagnifiedReading;
    uint8_t IndexInLinespaceParametersArray;
} typedef previous_readings_only;

//To retrieve bridgeleg readings for non-plotting use, you must downconvert them with >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE (shift rights).
previous_readings_only MasterReadingsArray[ INDEX_OF_OUTBOARDS + NUM_OF_OUTBOARDS_PLOTTED ];

struct linespace_bounds_and_magnify_trace_offsets
{
    uint32_t ZeroOfThisPlotLinespace;
    uint32_t HighLimitOfThisPlotLinespace;
    uint32_t LastSignalPinPlotPoint;
    uint32_t LastReferencePinPlotPointOrLastMagnifiedPlotPoint;
#ifdef MAGNIFICATION_FACTOR
    uint32_t MagnifyAdjustment;
#endif
} typedef linespace_bounds_and_magnify_trace_offsets;

/*
DEFINING NUMBER_OF_LINESPACES:
*/

#define NUMBER_OF_LINESPACES ( NUM_OF_INBOARDS_PLOTTED + NUM_OF_OUTBOARDS_PLOTTED - ( INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) ) //Each superimposed pair reduces total linespaces by one from total of plotted
linespace_bounds_and_magnify_trace_offsets LinespaceParameters[ NUMBER_OF_LINESPACES ]; // INDEX_OF_INBOARDS_NOT_SUPERIMPOSED, being the start index for the not superimposed part of the array is also actually the number of superimposed inboards

static bool graphline = false;
static uint32_t ThisReadingTemp;
static long MillisStart;
#ifdef DEBUG
    static char szFull[ ] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#endif
#define HEIGHT_OF_A_PLOT_LINESPACE ( ( uint32_t )pow( 2, HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC ) ) //casting as uint32_t allows calculations properly
#define PLOTTER_MAX_SCALE ( ( uint32_t )( HEIGHT_OF_A_PLOT_LINESPACE * NUMBER_OF_LINESPACES ) )
#define HALF_HEIGHT_OF_A_PLOT_LINESPACE ( ( uint32_t )( HEIGHT_OF_A_PLOT_LINESPACE / 2 ) )

//#if not defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS || ( NUM_OF_OUTBOARDS_PLOTTED == 0 ) || ( NUM_OF_INBOARDS_PLOTTED != 2 )
//    #define PLOTTER_MAX_SCALE ( HEIGHT_OF_A_PLOT_LINESPACE * ( ( uint32_t )( NUM_OF_OUTBOARDS_PLOTTED + NUM_OF_INBOARDS_PLOTTED ) ) )
//#else
//    #define PLOTTER_MAX_SCALE ( HEIGHT_OF_A_PLOT_LINESPACE * ( ( uint32_t )( NUM_OF_OUTBOARDS_PLOTTED + NUM_OF_INBOARDS_PLOTTED - 1 ) ) )
//#endif
#define HundredthPLOTTER_MAX_SCALE ( PLOTTER_MAX_SCALE / 100 );
#ifndef SAMPLE_TIMES
    #define SAMPLE_TIMES 1
#elif ( 1 > SAMPLE_TIMES + 0 )
    #undef SAMPLE_TIMES
    #define SAMPLE_TIMES 1
#endif
/*  development notes to self:
Is SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS (1, 2, 3, etc. ) ever needed?

AUTO_BRIDGE_BALANCING means both initial setup & ongoing adjustment: initial adjustment means setting pots to EEPROM settings or defines settings and for 
sweet spot ADCs it fines tunes during setup and re-stores that in EEPROM

defined AUTO_BRIDGE_BALANCING should only be allowed to be the case 
    with NUM_OF_OUTBOARDS_PLOTTED > 0
    and USING_LM334_WITH_DIGIPOT_BANKS (?inboard pairs 1, 2, 3, etc. or ADDONs n... ) //Besides being used for auto-balancing, these could be used just to allow a wider range of plant tissue conductance.
    and SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS (but is this moot?).  The alternative 
    to this condition in isolation from bridge balancing is just adjusting to plant resistance instead of 

Bridge balancing should not be needed with those ADCs that need a sweet spot to work.  That sweet spot could be hard wired or manual pot adjusted and only 
bridge LEG adjusting should get done????
With those ADCs, the digipots should be able to be put in serial and assigned to
Except that the tempco of the LM334 will then all be on only one leg, thus not able to be balanced out to cancel out, so never mind....
Possibilities:
AUTO...BALANCING is invalid w/o ...POTS and ...PARALLELed > 0
not USING_LM334_WITH_DIGIPOT_BANKS - invalidates AUTO...BALANCING
                                  - if inputs are ...PARALLELed > 0 and ...ADDONs exist and INBOARDS > 0, it is for manual pot manipulations while viewing 
                                    traces
                                                             
So: - define ...PARALLELed = 0 if it is undefined
    - undefine USING...POTS if USING...POTS == 0 or if ...INBOARD == 0 and not AUTO...BALANCING and #defined LEAVE_POT_VALUES_ALONE_DURING_SETUP and #not defined DEBUG, the digipots may be useful in debug then re-compile but why would they need to be
    - undefine AUTO...BALANCING if not USING...POTS, or if not ...ADDONs, or if ...PARALLELed == 0
    - define ...PARALLELed = 0 if ...ADDONs == 0, or if not AUTO...BALANCING and ...INBOARD == 0 while USING...POTS
    
 */
#ifdef USING_LM334_WITH_DIGIPOT_BANKS
    void setPotValue( uint8_t DigitalPotPin, uint16_t value )
    {
        if( DigitalPotPin < 128 ) //Pins numbered below 128 are normal digital inboard pins
        {
            for( uint8_t index = 0; index < NUM_OF_DIGIPOTS_PER_BANK * USING_LM334_WITH_DIGIPOT_BANKS; index++ )
            {
                if( DigitalPotPin == DigipotPins[ index ] )
                {
                    DigipotValues[ index ] = value < MAXPOTVALUE ? value : MAXPOTVALUE;
                    value = DigipotValues[ index ];
                    break;
                }
            }
        }
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DIGIPOT_CS_LINES
        else
        {//Pins numbered above 127 are outboard pins provided through the dual 74LV138 decoding circuitry
         //The two 74LV138 each have three enable pins but we only use one.  It would require 7 pins to address the two devices simultaneously.  Use 'em since we have them...it'll save a part for latch
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A0_PIN, DigitalPotPin & B1 );  //These address bits are always necessary
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A1_PIN, DigitalPotPin & B10 ); //These address bits are always necessary
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A2_PIN, DigitalPotPin & B100 ); //These address bits are always necessary
            digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A0_PIN, DigitalPotPin & B1000 ); //This decoder might not be present
            digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A1_PIN, DigitalPotPin & B10000 ); //This decoder might not be present
            digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A2_PIN, DigitalPotPin & B100000 );  //This decoder might not be present
            DigitalPotPin = BOTH_STAGES_3_TO_8_DECODER_ENABLE_PIN;
        }
#endif
        digitalWrite( DigitalPotPin, LOW );
        SPI.transfer( ( value & 0x100 ) ? 1 : 0 );
        SPI.transfer( value & 0xff ); // send value (0~255)
        digitalWrite( DigitalPotPin, HIGH );
    }
    
    void offsetPotValue( uint8_t DigitalPotPin, int16_t offsetvalue )
    {
    #ifdef DEBUG
//        offsetvalue += 40;  //A magnifier for troubleshooting
        while ( !Serial );
        Serial.print( F( "Digi pot on pin " ) );
    #endif
        for( uint8_t index = 0; index < NUM_OF_DIGIPOTS_PER_BANK * USING_LM334_WITH_DIGIPOT_BANKS; index++ )
        {
            if( DigitalPotPin == DigipotPins[ index ] )
            {
                if( offsetvalue < 0 ) offsetvalue = max( offsetvalue, 0 - DigipotValues[ index ] ); else if( offsetvalue > 0 ) offsetvalue = min( offsetvalue, MAXPOTVALUE - DigipotValues[ index ] ); DigipotValues[ index ] += offsetvalue; offsetvalue = DigipotValues[ index ]; 
                break;
            }
        }
        #ifdef DEBUG
            while ( !Serial );
            Serial.print( DigitalPotPin );
            Serial.print( F( " getting " ) );
            Serial.print( offsetvalue );
        #endif
      digitalWrite( DigitalPotPin, LOW );
      SPI.transfer( ( offsetvalue & 0x100 /*This restricts data to step numbers only.  Maybe you'd want to open it up for other type data...*/) ? 1 : 0 );
      SPI.transfer( offsetvalue & 0xff ); // send value (0~255)
      digitalWrite( DigitalPotPin, HIGH );
    #ifdef DEBUG
        while ( !Serial );
        Serial.print( F( ". Digi pot on pin " ) );
        Serial.print( DigitalPotPin );
        Serial.print( F( " got a " ) );
        Serial.println( offsetvalue );
    #endif
    }

    bool adjustValuesForThisLeg( uint8_t MSBpotPin, uint16_t* MSBpotValue, uint8_t MIDpotPin, uint16_t* MIDpotValue, uint8_t LSBpotPin, uint16_t* LSBpotValue, bool PosOrNeg = true ) //default direction will be positive
    { // This effectively increments or decrements LSB digipot setting just once
        #ifdef DEBUG
            while ( !Serial );
            Serial.print( F( "adjustValuesForThisLeg called on " ) );
            Serial.print( MSBpotPin );
            Serial.print( F( " going " ) );
            Serial.println( PosOrNeg ? "up": "down");
        #endif
        //if going up and TotalValueCoarse is already MAXPOTVALUE * 2, add one to value_fine if it is less than MAXPOTVALUE, else return false; save new value; return true
        //if going up still and either coarse value is MAXPOTVALUE, only increment the other value, save new, return true;
        //if going up and neither coarse value is MAXPOTVALUE, increment MID with a switch statement, save new
        uint16_t TotalValueCoarse = *MSBpotValue;
        TotalValueCoarse += *MIDpotValue;  //We abstract it this way to force MSB and MID digi pot values to conform as namesaked
        //Next lines just force significant digit compliance inside digi pots
        *MSBpotValue = ( TotalValueCoarse > MAXPOTVALUE ? TotalValueCoarse - MAXPOTVALUE : 0 );
        *MIDpotValue = ( TotalValueCoarse > MAXPOTVALUE ? MAXPOTVALUE : TotalValueCoarse );
        *LSBpotValue = min( MAXPOTVALUE, *LSBpotValue );
        
        setPotValue( MSBpotPin, *MSBpotValue );
        setPotValue( MIDpotPin, *MIDpotValue );
        setPotValue( LSBpotPin, *LSBpotValue );

        if( PosOrNeg ) //Positive direction == true
        {
            if( TotalValueCoarse >= MAXPOTVALUE * 2 )
            {
                *MSBpotValue = *MIDpotValue = MAXPOTVALUE;
                setPotValue( MSBpotPin, *MSBpotValue ); //This shouldn't do anything if the pot values conform to MSB and MID already
                setPotValue( MIDpotPin, *MIDpotValue ); //This shouldn't do anything if the pot values conform to MSB and MID already
                setPotValue( LSBpotPin, ++( *LSBpotValue ) > MAXPOTVALUE ? MAXPOTVALUE : *LSBpotValue );
                if( *LSBpotValue > MAXPOTVALUE ) { *LSBpotValue = MAXPOTVALUE; return false; }
                return true;
            }
            if( *LSBpotValue + 1 > ( LSB_DIGIPOT_RESISTANCE_STEP_PER_MSB_RESISTANCE_STEP - 1 ) ) //This catches *LSBpotValue having or about to have a value higher than 9 when it shouldn't.  So we cycle it down
            {
                do 
                {
                    *LSBpotValue = ( uint16_t )( ( int16_t )*LSBpotValue - LSB_DIGIPOT_RESISTANCE_STEP_PER_MSB_RESISTANCE_STEP ); //Yes, this can cause an unsigned to underflow to -1
                } while( ( ++TotalValueCoarse < MAXPOTVALUE * 2 ) && *LSBpotValue + 1 > ( LSB_DIGIPOT_RESISTANCE_STEP_PER_MSB_RESISTANCE_STEP - 1 ) );

                *MSBpotValue = ( TotalValueCoarse > MAXPOTVALUE ?  TotalValueCoarse - MAXPOTVALUE : 0 );
                *MIDpotValue = ( TotalValueCoarse > MAXPOTVALUE ? MAXPOTVALUE : TotalValueCoarse );
                setPotValue( MSBpotPin, *MSBpotValue );
                setPotValue( MIDpotPin, *MIDpotValue );
            }
            setPotValue( LSBpotPin, ++( *LSBpotValue ) );
            return true;
        }

//Being told to decrement
        if( TotalValueCoarse == 0 && *LSBpotValue == 0 ) return false;
        if( ( int16_t )*LSBpotValue == 0 ) //This catches *LSBpotValue having or about to have a value lower than 0.  So we cycle it up
        {
            *LSBpotValue = LSB_DIGIPOT_RESISTANCE_STEP_PER_MSB_RESISTANCE_STEP;
            *MSBpotValue = ( --TotalValueCoarse > MAXPOTVALUE ? TotalValueCoarse - MAXPOTVALUE : 0 );
            *MIDpotValue = ( TotalValueCoarse > MAXPOTVALUE ? MAXPOTVALUE : TotalValueCoarse );
            setPotValue( MSBpotPin, *MSBpotValue );
            setPotValue( MIDpotPin, *MIDpotValue );
        }
        setPotValue( LSBpotPin, --( *LSBpotValue ) );
        return true;
    }

    bool AdjustBridgeOutputPositive( uint8_t bank )
    {
        // If all are maxed out positive, return false
        if( ( DigipotValues[ 0 + bank * NUM_OF_DIGIPOTS_PER_BANK ]  + DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] >= ( 514 + MAXPOTVALUE ) ) && \
            ( DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] == 0 ) ) return false;
//Target leg to adjust is the one that brings the negative leg closet to its midpoint: determine how far away from midpoint the negative leg is:
        if( ( ( ( DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) * MAXPOTVALUE ) + ( DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) ) > 66177 /*This is half of total resistance in terms of digi pot units*/ )
        {
            if( adjustValuesForThisLeg( DigipotPins[ 3 ], DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 4 ], DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 5 ], DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false ) ) return true;
            else return adjustValuesForThisLeg( DigipotPins[ 0 ], DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 ], DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 2 ], DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
        }
        else if( adjustValuesForThisLeg( DigipotPins[ 0 ], DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 ], DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 2 ], DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false ) ) return true;
        return adjustValuesForThisLeg( DigipotPins[ 3 ], DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 4 ], DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 5 ], DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
    }
    
    bool AdjustBridgeOutputNegative( uint8_t bank )
    { //Determine which leg is closest to Vcc/2 and tweak that first.  If all pots are maxed (positive leg to negative and negative leg to positive) return false
        if( ( DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] == 0 ) && \
            ( DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] >= MAXPOTVALUE * 2 ) && ( DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > 256 ) ) return false;
//Target leg to adjust is the one that brings the negative leg closet to its midpoint: determine how far away from midpoint the negative leg is:
        if( ( ( ( DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) * MAXPOTVALUE ) + ( DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) ) < 66177 /*This is half of total resistance in terms of digi pot units*/ )
        {
            if( adjustValuesForThisLeg( DigipotPins[ 3 ], DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 4 ], DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 5 ], DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) ) return true;
            else return adjustValuesForThisLeg( DigipotPins[ 0 ], DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 ], DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 2 ], DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
        }
        else if( adjustValuesForThisLeg( DigipotPins[ 0 ], DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 ], DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 2 ], DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) ) return true;
        return adjustValuesForThisLeg( DigipotPins[ 3 ], DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 4 ], DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 5 ], DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
    }
#endif

void ReplotLastValuesForAllTraces( bool actuals = false )                  //If we don't execute the following construct, the signal traces will lag behind the graphline
{
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Entering ReplotLastValuesForAllTraces" ) );
#endif
    while( !Serial ) ; 
    Serial.print( F( " " ) );
//#error The following lines are where I'm at now. Consider when inboards aren't plotted but handling digipot banks
//Skip printing of indices of inboards beyond what NUM_OF_INBOARDS_PLOTTED specifies, skip index to first outboard
//#error 
/*

#if ( NUM_OF_INBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings LinespaceParametersInboard[ NUM_OF_INBOARDS_PLOTTED ];
#endif
#if defined USING_LM334_WITH_DIGIPOT_BANKS && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < USING_LM334_WITH_DIGIPOT_BANKS * 2 )
    previous_readings_only DigipotLeg[ ( USING_LM334_WITH_DIGIPOT_BANKS * 2 ) - NUM_OF_INBOARDS_PLOTTED ];
#endif
#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings LinespaceParametersOutboard[ NUM_OF_OUTBOARDS_PLOTTED ];
#endif

 */
//#ifndef MAGNIFICATION_FACTOR
//    for( ; IndexOfLinespaceParameters < max( NUM_OF_INBOARDS_PLOTTED, ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * 2 ) ) + NUM_OF_OUTBOARDS_PLOTTED; IndexOfLinespaceParameters++ )
    for( uint8_t LinespaceParametersIndex = 0; LinespaceParametersIndex < NUMBER_OF_LINESPACES; LinespaceParametersIndex++ )    
    {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.print( F( "LinespaceParametersIndex = " ) );
    Serial.print( LinespaceParametersIndex );
    Serial.print( F( ", LastSignalPinPlotPoint = " ) );
    Serial.print( LinespaceParameters[ LinespaceParametersIndex ].LastSignalPinPlotPoint );
    Serial.print( F( ", ZeroOfThisPlotLinespace = " ) );
    Serial.print( LinespaceParameters[ LinespaceParametersIndex ].ZeroOfThisPlotLinespace );
    Serial.print( F( ", INDEX_OF_INBOARDS_NOT_SUPERIMPOSED = " ) );
    Serial.println( INDEX_OF_INBOARDS_NOT_SUPERIMPOSED );
#endif
        Serial.print( actuals ? LinespaceParameters[ LinespaceParametersIndex ].LastSignalPinPlotPoint + LinespaceParameters[ LinespaceParametersIndex ].ZeroOfThisPlotLinespace: 0 ); //I think this looks better than the line above
        Serial.print( F( " " ) );
// INDEX_OF_INBOARDS_NOT_SUPERIMPOSED actually equals the number of InboardSuperimposed that exist
        if( LinespaceParametersIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.print( F( ", LastReferencePinPlotPointOrLastMagnifiedPlotPoint = " ) );
    Serial.println( LinespaceParameters[ LinespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
#endif
            Serial.print( actuals ? LinespaceParameters[ LinespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + LinespaceParameters[ LinespaceParametersIndex ].ZeroOfThisPlotLinespace : 0 ); //I think this looks better than the line above
            Serial.print( F( " " ) );
            continue;
        }
        else //skip the following if the above was true
        {
            ;
#ifdef MAGNIFICATION_FACTOR
        Serial.print( actuals ? LinespaceParameters[ LinespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + LinespaceParameters[ LinespaceParametersIndex ].ZeroOfThisPlotLinespace : 0 ); //I think this looks better than the line above
        Serial.print( F( " " ) );
#endif
        }
    }
    Serial.println();
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Leaving ReplotLastValuesForAllTraces" ) );
#endif
}
//

void PlotTimingLineGoingUp( bool TracesAlreadyInitializedToValidReadings = true )
{ //doesn't work in loop() when there is more than one linespace: it runs one too many indices?
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Entering PlotTimingLineGoingUp" ) );
#endif
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    for( uint8_t LinespaceParametersIndex = NUMBER_OF_LINESPACES - 1; LinespaceParametersIndex != 255; LinespaceParametersIndex-- )
    {
/*
        if( LinespaceParametersIndex > 1 ) //plot only double instances until the last one
        {
            Serial.println(); //temporary for debugging
            Serial.print( LinespaceParameters[ LinespaceParametersIndex - 1 ].HighLimitOfThisPlotLinespace );
            Serial.print( F( " " ) );//?
            #ifdef DEBUG
                while( !Serial ) ;
                Serial.println();
                Serial.println( F( "Line 815" ) );
            #endif
            if( TracesAlreadyInitializedToValidReadings ) 
                ReplotLastValuesForAllTraces( TracesAlreadyInitializedToValidReadings );
            else
                Serial.println();
            #ifdef DEBUG
                while( !Serial ) ; 
                Serial.println();
                Serial.println( F( "Line 820" ) );
            #endif
        }
*/
            Serial.print( LinespaceParameters[ LinespaceParametersIndex ].ZeroOfThisPlotLinespace );
            ReplotLastValuesForAllTraces( true );
            Serial.print( LinespaceParameters[ LinespaceParametersIndex ].HighLimitOfThisPlotLinespace );
            ReplotLastValuesForAllTraces( true );
//        Serial.print( LinespaceParameters[ LinespaceParametersIndex - 1 ].HighLimitOfThisPlotLinespace );
//        Serial.print( F( " " ) );//?
        #ifdef DEBUG
            while( !Serial ) ; 
                Serial.println();
            Serial.print( F( "Line 826 LinespaceParametersIndex - 1 =" ) );
            Serial.println( LinespaceParametersIndex - 1 );
        #endif
//        if( TracesAlreadyInitializedToValidReadings ) ReplotLastValuesForAllTraces( TracesAlreadyInitializedToValidReadings );
//        else Serial.println();
        #ifdef DEBUG
            while( !Serial ) ; 
                Serial.println();
            Serial.print( F( "Line 832, LinespaceParametersIndex - 1 =" ) );
            Serial.println( LinespaceParametersIndex - 1 );
        #endif
    }
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Leaving PlotTimingLineGoingUp" ) );
#endif
}

static uint8_t *AnalogPinArray;
uint16_t BestOfFour( uint8_t AnalogPinArrayIndex = 0 )
{ //remove from consideration the max and min, then return avg of remaining two  //Re-suse some variables not otherwise in use right now
    uint16_t value = analogRead( *( AnalogPinArray + AnalogPinArrayIndex ) );
    delay( 2 );
    uint16_t value1 = analogRead( *( AnalogPinArray + AnalogPinArrayIndex ) );
    delay( 2 );
    uint16_t value2 = analogRead( *( AnalogPinArray + AnalogPinArrayIndex ) );
    delay( 2 );
    uint16_t val4 = analogRead( *( AnalogPinArray + AnalogPinArrayIndex ) );
    return ( uint16_t )( ( ( long )( value + value1 + value2 + val4 ) ) - ( max( max( max( value, value1 ), value2 ), val4 ) + min( min( min( value, value1 ), value2 ), val4 ) ) ) / 2;
}

uint16_t BestGuessAnalogInputreading( uint8_t AnalogPinArrayIndex, bool finetune = false, uint8_t bank = 0 )
{
    uint16_t value, value1;
    unsigned long runningtotal = 0;
    uint8_t times = 0;
    do
    {
        value = BestOfFour( AnalogPinArrayIndex + ( bank * 2 ) );
        value1 = BestOfFour( AnalogPinArrayIndex + ( bank * 2 ) );
        if( finetune )
        {
            times++;
            runningtotal += value;
            runningtotal += value1;
        }
    }while( value != value1 );
    if( !finetune ) return value;
    return value; 
        //The following wish isn't a good method
//        return ( uint16_t )( runningtotal / ( unsigned long ) times );
}

#if defined USING_LM334_WITH_DIGIPOT_BANKS
static uint8_t SetDigipotsStep = 0;

bool SetDigipotsReferenceLeg( bool JustPerformOneStep = false, uint8_t bank = 0 ) //All this does is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
{
    static uint8_t stepsize;
#ifdef DEBUG
    while ( !Serial && ( millis() - MillisStart < 8000 ) );
    Serial.print( F( "Setting up digipots: bridge leg 0 = " ) );
    Serial.print( analogRead( *( AnalogPinArray + 0 + bank ) ) ); //This array was not initialized for a digipot array but should have been.  Is currently only defined for displaying pins
    Serial.print( F( ", bridge leg 1 = " ) );
    Serial.print( analogRead( *( AnalogPinArray + 1 + bank ) ) );
    Serial.print( F( ", SetDigipotsStep = " ) );
    Serial.print( SetDigipotsStep );
    Serial.print( F( ", stepsize = " ) );
    Serial.println( stepsize );
#endif
if( SetDigipotsStep != 0 )
{
    if( SetDigipotsStep == 1 ) goto SetDigipotsStep1;
    if( SetDigipotsStep == 2 ) goto SetDigipotsStep2;
    if( SetDigipotsStep == 3 ) goto SetDigipotsStep3;
    if( SetDigipotsStep == 4 ) goto SetDigipotsStep4;
    if( SetDigipotsStep == 5 ) goto SetDigipotsStep5;
    if( SetDigipotsStep == 6 ) goto SetDigipotsStep6;
    if( SetDigipotsStep == 7 ) goto SetDigipotsStep7;
    if( SetDigipotsStep == 8 ) goto SetDigipotsStep8;
    if( SetDigipotsStep == 9 ) goto SetDigipotsStep9;
//    if( SetDigipotsStep == 10 ) goto SetDigipotsStep10;
}

/*Next is where the Wheatstone bridge reference leg output (that connects to negative input of highest sensi ADC) is set to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG voltage level*/
    stepsize = 10;
    static uint16_t startpoint1;
    static uint16_t startpoint2;

    while( ( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        {
            startpoint1 = DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            if( DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 )
            {
                setPotValue( DigipotPins[ 3 + ( bank * 2 ) ], DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
                if( JustPerformOneStep )
                {
                    SetDigipotsStep = 1;
                    return false;
                }
SetDigipotsStep1:;
            }
            if( DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 )
            {
                setPotValue( DigipotPins[ 4 + ( bank * 2 ) ], DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
                if( JustPerformOneStep )
                {
                    SetDigipotsStep = 2;
                    return false;
                }
SetDigipotsStep2:;
            }
        }
        setPotValue( DigipotPins[ 3 + ( bank * 2 ) ], startpoint1 );
        setPotValue( DigipotPins[ 4 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
    }
    while( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
    {
        adjustValuesForThisLeg( DigipotPins[ 3 + ( bank * 2 ) ], &DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 4 + ( bank * 2 ) ], &DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 5 + ( bank * 2 ) ], &DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
        if( JustPerformOneStep )
        {
            SetDigipotsStep = 3;
            return false;
        }
SetDigipotsStep3:;
    }
    stepsize = 10;

    while( ( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) && ( stepsize > 0 ) )
    {//FIXME this loop can never be false when the startpoints get restored?
        while( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        {
            startpoint1 = DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            if( DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 )
            {
                setPotValue( DigipotPins[ 3 + ( bank * 2 ) ], DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
                if( JustPerformOneStep )
                {
                    SetDigipotsStep = 4;
                    return false;
                }
SetDigipotsStep4:;
            }
            if( DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 )
            {
                setPotValue( DigipotPins[ 4 + ( bank * 2 ) ], DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
                if( JustPerformOneStep )
                {
                    SetDigipotsStep = 5;
                    return false;
                }
SetDigipotsStep5:; //This bottoms out as far as setting digipots
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "Line 897, BestGuessAnalogInputreading( 1 + ( bank * 2 ) )= " ) );
    Serial.print( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) );
    Serial.print( F( ", DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ]= " ) );
    Serial.print( DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ); //These setting values increase without end FIXME
    Serial.print( F( ", DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] = " ) );
    Serial.print( DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
    Serial.print( F( ", DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] = " ) );
    Serial.print( DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
    Serial.print( F( ", stepsize=" ) );
    Serial.println( stepsize );
#endif
            }
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "Line 903, stepsize=" ) );
    Serial.println( stepsize );
#endif
        }
        setPotValue( DigipotPins[ 3 + ( bank * 2 ) ], startpoint1 );
        setPotValue( DigipotPins[ 4 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "new stepsize = " ) );
    Serial.println( stepsize );
#endif
    }
    while( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
    {
        adjustValuesForThisLeg( DigipotPins[ 3 + ( bank * 2 ) ], &DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 4 + ( bank * 2 ) ], &DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 5 + ( bank * 2 ) ], &DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
        if( JustPerformOneStep )
        {
            SetDigipotsStep = 6;
            return false;
        }
SetDigipotsStep6:;
    }
//Converge by two consecutive readings
    do
    {//This leg is the  reference, so we need to take a little extra time: avg out more samples
        if( BestGuessAnalogInputreading( 1 + ( bank * 2 ), FINETUNE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        {
            adjustValuesForThisLeg( DigipotPins[ 3 + ( bank * 2 ) ], &DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 4 + ( bank * 2 ) ], &DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 5 + ( bank * 2 ) ], &DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
        }
        else if( BestGuessAnalogInputreading( 1 + ( bank * 2 ), FINETUNE ) /*read it again*/ < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        {
            adjustValuesForThisLeg( DigipotPins[ 3 + ( bank * 2 ) ], &DigipotValues[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 4 + ( bank * 2 ) ], &DigipotValues[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 5 + ( bank * 2 ) ], &DigipotValues[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
        }
        if( JustPerformOneStep )
        {
            SetDigipotsStep = 7;
            return false;
        }
SetDigipotsStep7:
        if( BestGuessAnalogInputreading( 1 + ( bank * 2 ), FINETUNE ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) continue;
        if( JustPerformOneStep )
        {
            SetDigipotsStep = 8;
            return false;
        }
SetDigipotsStep8:;
    }while( BestGuessAnalogInputreading( 1 + ( bank * 2 ), FINETUNE ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );

/* This notion is for if a single reference bank leg of the first digipot bank suffices for the reference legs of all ADDON digipot banks to minimize parts count of multiple digipot bank systems.  Is not being pursued at this time....
    static uint8_t channel;
    for( channel = 0; channel < NUM_OF_OUTBOARDS_PLOTTED; channel++ )
    {
        SetBridgeLegSignalInput( channel );
        if( JustPerformOneStep )
        {
            SetDigipotsStep = 10;
            return false;
        }
*/
SetDigipotsStep9:;
/*    }*/
    SetDigipotsStep = 0;
    return true;
}
void ReadAndPlotFromAllADCsInAndOutboard( bool );

bool MatchBridgeLegSignalToReference( uint8_t bank )
{//BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE
    uint16_t stepsize = 10;    
    uint16_t startpoint1;
    uint16_t startpoint2;
    while( ( BestGuessAnalogInputreading( bank * 2 ) < BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * 2 ) < BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
        {
            startpoint1 = DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            if( DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 ) setPotValue( DigipotPins[ 0 + ( bank * 2 ) ], DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
            if( DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 ) setPotValue( DigipotPins[ 1 + ( bank * 2 ) ], DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
            BestGuessAnalogInputreading( bank * 2 );
        }
        setPotValue( DigipotPins[ 0 + ( bank * 2 ) ], startpoint1 );
        setPotValue( DigipotPins[ 1 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
    }
//Converge on BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) in smaller steps
    while( BestGuessAnalogInputreading( bank * 2 ) < BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
    {
        adjustValuesForThisLeg( DigipotPins[ 0 + ( bank * 2 ) ], &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 + ( bank * 2 ) ], &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 2 + ( bank * 2 ) ], &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
    }
    stepsize = 10;
    while( ( BestGuessAnalogInputreading( bank * 2 ) > BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * 2 ) > BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
        {
            startpoint1 = DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            setPotValue( DigipotPins[ 0 + ( bank * 2 ) ], DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
            setPotValue( DigipotPins[ 1 + ( bank * 2 ) ], DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
            BestGuessAnalogInputreading( bank * 2 );
        }
        setPotValue( DigipotPins[ 0 + ( bank * 2 ) ], startpoint1 );
        setPotValue( DigipotPins[ 1 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
    }

//Converge on BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) in smaller steps
    while( BestGuessAnalogInputreading( bank * 2 ) > BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
    {
        adjustValuesForThisLeg( DigipotPins[ 0 + ( bank * 2 ) ], &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 + ( bank * 2 ) ], &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 2 + ( bank * 2 ) ], &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
    }
//Converge by one or two consecutive readings
    do
    {
        if( BestGuessAnalogInputreading( bank * 2 ) > BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
        {
            adjustValuesForThisLeg( DigipotPins[ 0 + ( bank * 2 ) ], &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 + ( bank * 2 ) ], &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 2 + ( bank * 2 ) ], &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
        }
        else if( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ < BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
        {
            adjustValuesForThisLeg( DigipotPins[ 0 + ( bank * 2 ) ], &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 + ( bank * 2 ) ], &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 2 + ( bank * 2 ) ], &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
        }
        if( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ != BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE ) continue;
        
    }while( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ != BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE );

// Lastly, apply negative ADDITIONAL_LSB_DIGIPOT_SETTING_BIAS_TO_SIGNAL_TRACE to signal leg LSB digipot
#if defined ADDITIONAL_LSB_DIGIPOT_SETTING_BIAS_TO_SIGNAL_TRACE
    #if ( 1 < ADDITIONAL_LSB_DIGIPOT_SETTING_BIAS_TO_SIGNAL_TRACE + 1 )
        for( uint8_t AdjustClicks = 0; AdjustClicks < abs( ADDITIONAL_LSB_DIGIPOT_SETTING_BIAS_TO_SIGNAL_TRACE ); AdjustClicks++ )
            adjustValuesForThisLeg( DigipotPins[ 0 + ( bank * 2 ) ], &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 + ( bank * 2 ) ], &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 2 + ( bank * 2 ) ], &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], ADDITIONAL_LSB_DIGIPOT_SETTING_BIAS_TO_SIGNAL_TRACE > 0 ? false : true  );
    #endif
#endif
//If ADDON ADC affiliated with this bank reads above zero on avg, lower the signal leg and vice versa
    //refresh the readings
//    ReadAndPlotFromAllADCsInAndOutboard( true ); // I would think the operator would appreciate seeing something like this during calibration
/*    Fine tune into perfect balance:

//    bool adjustValuesForThisLeg( uint8_t MSBpotPin, uint16_t* MSBpotValue, uint8_t MIDpotPin, uint16_t* MIDpotValue, uint8_t LSBpotPin, uint16_t* LSBpotValue, bool PosOrNeg = true ) //default direction will be positive
    //see what ADDON ADC affiliated with this bank reads avg
#ifdef MAGNIFICATION_FACTOR
    while( LastPlotPoints[ bank * 2 ] < 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#else
    while( LastPlotPoints[ bank ] < 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#endif
    {//reading is too high, lower the leg
        if( adjustValuesForThisLeg( *( AnalogPinArray + 0 + ( bank * 2 ) ), &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], *( AnalogPinArray + 1 + ( bank * 2 ) ), &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], *( AnalogPinArray + 2 + ( bank * 2 ) ), &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false ) == false ) break;
        ReadAndPlotFromAllADCsInAndOutboard( true ); // I would think the operator would appreciate seeing something like this during calibration
    }
#ifdef MAGNIFICATION_FACTOR
     while( LastPlotPoints[ bank * 2 ] > 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#else
    while( LastPlotPoints[ bank ] > 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#endif
    {//reading is too low, raise the leg
        if( adjustValuesForThisLeg( *( AnalogPinArray + 0 + ( bank * 2 ) ), &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], *( AnalogPinArray + 1 + ( bank * 2 ) ), &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], *( AnalogPinArray + 2 + ( bank * 2 ) ), &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true ) == false ) break;
        ReadAndPlotFromAllADCsInAndOutboard( true ); // I would think the operator would appreciate seeing something like this during calibration
    }
*/
    return true;
    return false;
}

void SetBridgeLegSignalInput( uint8_t bank )
{//BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE
    uint16_t stepsize = 10;    
    uint16_t startpoint1;
    uint16_t startpoint2;
    while( ( BestGuessAnalogInputreading( bank * 2 ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * 2 ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
        {
            startpoint1 = DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            if( DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 ) setPotValue( DigipotPins[ 0 + ( bank * 2 ) ], DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
            if( DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 ) setPotValue( DigipotPins[ 1 + ( bank * 2 ) ], DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
            BestGuessAnalogInputreading( bank * 2 );
        }
        setPotValue( DigipotPins[ 0 + ( bank * 2 ) ], startpoint1 );
        setPotValue( DigipotPins[ 1 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
    }
//Converge on COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG in smaller steps
    while( BestGuessAnalogInputreading( bank * 2 ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
    {
        adjustValuesForThisLeg( DigipotPins[ 0 + ( bank * 2 ) ], &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 + ( bank * 2 ) ], &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 2 + ( bank * 2 ) ], &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
    }
    stepsize = 10;
    while( ( BestGuessAnalogInputreading( bank * 2 ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * 2 ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
        {
            startpoint1 = DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            setPotValue( DigipotPins[ 0 + ( bank * 2 ) ], DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
            setPotValue( DigipotPins[ 1 + ( bank * 2 ) ], DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
            BestGuessAnalogInputreading( bank * 2 );
        }
        setPotValue( DigipotPins[ 0 + ( bank * 2 ) ], startpoint1 );
        setPotValue( DigipotPins[ 1 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
    }

//Converge on COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG in smaller steps
    while( BestGuessAnalogInputreading( bank * 2 ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
    {
        adjustValuesForThisLeg( DigipotPins[ 0 + ( bank * 2 ) ], &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 + ( bank * 2 ) ], &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 2 + ( bank * 2 ) ], &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
    }
//Converge by one or two consecutive readings
    do
    {
        if( BestGuessAnalogInputreading( bank * 2 ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
        {
            adjustValuesForThisLeg( DigipotPins[ 0 + ( bank * 2 ) ], &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 + ( bank * 2 ) ], &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 2 + ( bank * 2 ) ], &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
        }
        else if( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE )
        {
            adjustValuesForThisLeg( DigipotPins[ 0 + ( bank * 2 ) ], &DigipotValues[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], DigipotPins[ 1 + ( bank * 2 ) ], &DigipotValues[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  DigipotPins[ 2 + ( bank * 2 ) ], &DigipotValues[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
        }
        if( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE ) continue;
        
    }while( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE );
}
#endif

static uint32_t TracespaceToSkipWhenRepositioning, NegativeTracespaceToSkipWhenRepositioning;
/*
#if ( NUM_OF_INBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings LinespaceParametersInboard[ NUM_OF_INBOARDS_PLOTTED ];
#endif
#if defined USING_LM334_WITH_DIGIPOT_BANKS && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < USING_LM334_WITH_DIGIPOT_BANKS * 2 )
    previous_readings_only DigipotLeg[ ( USING_LM334_WITH_DIGIPOT_BANKS * 2 ) - NUM_OF_INBOARDS_PLOTTED ];
#endif
#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings LinespaceParametersOutboard[ NUM_OF_OUTBOARDS_PLOTTED ];
#endif

How are LastSignalPinPlotPoint and PreviousUnmagnifiedReading differently used?

LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastSignalPinPlotPoint = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;

*/
#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 ) && defined AUTO_BRIDGE_BALANCING
int PlotTheNormalAndMagnifiedSignals( uint8_t MasterReadingsArrayIndex )
#else
void PlotTheNormalAndMagnifiedSignals( uint8_t MasterReadingsArrayIndex ) //Two indices per every non-magnified trace ifdef MAGNIFICATION_FACTOR, otherwise one per 
#endif
{
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "Line 1319 MasterReadingsArrayIndex = " ) );
    Serial.println( MasterReadingsArrayIndex );
#endif
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    if( ( MasterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) && !( MasterReadingsArrayIndex % 2 ) ) //This is the case for those ADCs that have just had their current readings refreshed immediately prior to teh execution of this function, so use the stored readings.  Note also that the standard linespace is designed large enough to always accommodate plotting the full unmagnified reading
    {//this case and the case of MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS but not including the case of MasterReadingsArrayIndex < NUM_OF_INBOARDS_PLOTTED needs to return some values
        LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastSignalPinPlotPoint = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading + LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one of pair
    #ifdef DEBUG
        Serial.println();
        Serial.println( F( "Line 1289 signal" ) );
    #endif
    #ifdef MAGNIFICATION_FACTOR
        Serial.print( F( " " ) );
        goto AFTER_THE_MAGNIFIED_PLOTTED;
    #endif
    }
    else if( MasterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) //This is still the case for those ADCs that have just had their current readings refreshed immediately prior to teh execution of this function, so use the stored readings.  Note also that the standard linespace is designed large enough to always accommodate plotting the full unmagnified reading
    {
        LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading + LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color two of pair
    #ifdef DEBUG
        Serial.println();
        Serial.println( F( "Line 1298 reference" ) );
    #endif
    #ifdef MAGNIFICATION_FACTOR
        Serial.print( F( " " ) );
        goto AFTER_THE_MAGNIFIED_PLOTTED;
    #endif
    }
/*
    else if( MasterReadingsArrayIndex < NUM_OF_INBOARDS_PLOTTED )
    {
        LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastSignalPinPlotPoint = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading + LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one
        #ifdef DEBUG
            Serial.println();
            Serial.println( F( "Line 1277 " ) );
        #endif
    }
*/
    else //non-superimposed inboards and all outboards
    {
        LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastSignalPinPlotPoint = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading + LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one
        #ifdef DEBUG
            Serial.println();
            Serial.println( F( "Line 1285 " ) );
        #endif
    }
    #ifdef DEBUG
        Serial.print( F( "Line 1368 MasterReadingsArrayIndex = " ) );
        Serial.print( MasterReadingsArrayIndex );
        Serial.print( F( ", CurrentUnmagnifiedReading = " ) );
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading );
        Serial.print( F( ", IndexInLinespaceParametersArray = " ) );
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray );
        Serial.print( F( ", ZeroOfThisPlotLinespace = " ) );
        Serial.println( LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].ZeroOfThisPlotLinespace );
    #endif
    Serial.print( F( " " ) );
#ifdef MAGNIFICATION_FACTOR
    uint32_t ThisPlotPoint;
/*
SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS will be one for every pair to superimpose on each other
NUM_OF_INBOARDS_PLOTTED are paired times SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS, then singled
NUM_OF_OUTBOARDS_PLOTTED is taken at face value
*/
    #if defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS 
        if( MasterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) goto AFTER_THE_MAGNIFIED_PLOTTED;//if this is one of the two parallel traces, skip the magnified view
    #endif

    //Next lines plot a magnified version.  First, MagnifyAdjustment is determined
//Next we multiply the difference between PreviousUnmagnifiedReading and this one, and see if it would take the trace out of bounds
//Derive the next plot point for the case of current CurrentUnmagnifiedReading being less than or equal to the last UnmagnifiedReading
    if( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading > MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading ) //new plot point is higher than previous
    {
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
        ThisPlotPoint = LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + ( ( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading - MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#else
        ThisPlotPoint = LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + ( ( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading - MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#endif
        if( ThisPlotPoint > HEIGHT_OF_A_PLOT_LINESPACE ) //new plot point is higher than upper limit
            ThisPlotPoint = TracespaceToSkipWhenRepositioning;
    }
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
    else if( ( MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading - MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR ) > LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint )
#else
    else if( ( MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading - MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * MAGNIFICATION_FACTOR > LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint )
#endif
        ThisPlotPoint = NegativeTracespaceToSkipWhenRepositioning;
    else
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
        ThisPlotPoint = LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint  - ( ( MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading - MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#else
        ThisPlotPoint = LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint - ( ( MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading - MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#endif
    LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = ThisPlotPoint;
    Serial.print( LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].ZeroOfThisPlotLinespace + LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
    Serial.print( F( " " ) );
#ifdef DEBUG
            Serial.println();
            Serial.println( F( "Line 1356 " ) );
        Serial.println();
#endif
/* Previous algorithm that I think worked fine:

    if( ThisReading > LinespaceParameters[ channel ].PreviousUnmagnifiedReading ) //new reading is higher than previous
    {
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
        ThisPlotPoint = LastPlotPoints[ ( channel * 2 ) + 1 ] + ( ( ThisReading - LinespaceParameters[ channel ].PreviousUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#else
        ThisPlotPoint = LastPlotPoints[ ( channel * 2 ) + 1 ] + ( ( ThisReading - LinespaceParameters[ channel ].PreviousUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#endif
        if( ThisPlotPoint > HEIGHT_OF_A_PLOT_LINESPACE ) //new plot point is higher than upper limit
            ThisPlotPoint = TracespaceToSkipWhenRepositioning;
    }
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
    else if( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR ) > LastPlotPoints[ ( channel * 2 ) + 1 ] )
#else
    else if( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * MAGNIFICATION_FACTOR > LastPlotPoints[ ( channel * 2 ) + 1 ] )
#endif
        ThisPlotPoint = NegativeTracespaceToSkipWhenRepositioning;
    else
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
        ThisPlotPoint = LastPlotPoints[ ( channel * 2 ) + 1 ] - ( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#else
        ThisPlotPoint = LastPlotPoints[ ( channel * 2 ) + 1 ] - ( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#endif
    Serial.print( LinespaceParameters[ channel ].ZeroOfThisPlotLinespace + ThisPlotPoint ); 
    Serial.print( F( " " ) );
    LastPlotPoints[ ( channel * 2 ) + 1 ] = ThisPlotPoint;


*/
AFTER_THE_MAGNIFIED_PLOTTED:
#endif
MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;
#ifdef DEBUG
        Serial.println();
#endif
}
/* Something left over from previous revision
#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 ) && defined AUTO_BRIDGE_BALANCING
    #ifdef MAGNIFICATION_FACTOR
    if( MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS ) return BestGuessAnalogInputreading( 1 + ( channel * 2 ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE - BestGuessAnalogInputreading( ( channel - 2 ) * 2 ) );
    #else
    if( MasterReadingsArrayIndex >= NUM_OF_INBOARDS_PLOTTED ) return BestGuessAnalogInputreading( 1 + channel ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE - BestGuessAnalogInputreading( ( channel - 2 ) * 2 );
    #endif
//BestGuessAnalogInputreading index argument is a bank...which doesn't exist except with the outboard ADCs
#endif
return;//only saving the reading, don't plot.  These are just LM334 non-plotted banks
*/
#if defined ( POT_TEST_WOBBLE_POSITIVE ) || defined ( POT_TEST_WOBBLE_NEGATIVE )
static bool potwobbledirection = true;
static uint8_t wobbleloops = 0;
void wobble( void )
{ //Adjust active code to amount of wobble you need at the moment
#ifdef POT_TEST_WOBBLE_POSITIVE
//        offsetPotValue( DigipotPins[ 0 + ( POT_TEST_WOBBLE_POSITIVE * 2 ) ], potwobbledirection ? 1 : -1 );
//        offsetPotValue( DigipotPins[ 1 + ( POT_TEST_WOBBLE_POSITIVE * 2 ) ], potwobbledirection ? 1 : -1 );
        offsetPotValue( DigipotPins[ 2 + ( POT_TEST_WOBBLE_POSITIVE * 2 ) ], potwobbledirection ? 1 : -1 );
#endif
#ifdef POT_TEST_WOBBLE_NEGATIVE
//        offsetPotValue( DigipotPins[ 3 + ( POT_TEST_WOBBLE_NEGATIVE * 2 ) ], potwobbledirection ? -1 : 1 );
//        offsetPotValue( DigipotPins[ 4 + ( POT_TEST_WOBBLE_NEGATIVE * 2 ) ], potwobbledirection ? -1 : 1 );
        offsetPotValue( DigipotPins[ 5 + ( POT_TEST_WOBBLE_NEGATIVE * 2 ) ], potwobbledirection ? -1 : 1 );
#endif
    potwobbledirection = !potwobbledirection;
}
#endif

#ifdef AUTO_BRIDGE_BALANCING
    static uint16_t CounterForTraceOutOfRangeTooLong[ NUM_OF_OUTBOARDS_PLOTTED ]; //This is to prevent infinite loop with AUTO_BRIDGE_BALANCING
#endif

void ReadAndPlotFromAllADCsInAndOutboard( bool DuringSetup = false )
{
    for( uint8_t InboardPinIndex = 0; InboardPinIndex < INDEX_OF_OUTBOARDS; InboardPinIndex++ )
    {
        #ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
//                    Serial.print( F( "AnalogPinArray = " ) );
//                    Serial.println( (unsigned long)AnalogPinArray );
            Serial.print( F( "Reading pin " ) );
            Serial.print( *( AnalogPinArray + InboardPinIndex ) );
            Serial.print( F( ", level appearing as " ) );
            Serial.print( analogRead( *( AnalogPinArray + InboardPinIndex ) ) );
            if( InboardPinIndex == 0 )
            {
                Serial.print( F( ", SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE " ) );
                Serial.println( SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
            }
            else Serial.println();
        #endif
        MasterReadingsArray[ InboardPinIndex ].CurrentUnmagnifiedReading = analogRead( *( AnalogPinArray + InboardPinIndex ) );
        #ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
            Serial.print( F( "Value was " ) );
            Serial.print( MasterReadingsArray[ InboardPinIndex ].CurrentUnmagnifiedReading );;
        #endif

        for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
        {
            #if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
                            delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
            #endif
            #if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
                            delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
            #endif
            MasterReadingsArray[ InboardPinIndex ].CurrentUnmagnifiedReading += analogRead( *( AnalogPinArray + InboardPinIndex ) );
        }
        #ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
            Serial.print( F( ".  Done reading pin " ) );
            Serial.print( *( AnalogPinArray + InboardPinIndex ) );
            Serial.print( F( ", " ) );
            Serial.print( SAMPLE_TIMES );
            Serial.print( F( " times, total CurrentUnmagnifiedReading now " ) );
            Serial.print( MasterReadingsArray[ InboardPinIndex ].CurrentUnmagnifiedReading );
            Serial.print( F( " which should average to " ) );
            Serial.print( MasterReadingsArray[ InboardPinIndex ].CurrentUnmagnifiedReading / SAMPLE_TIMES );
            Serial.println( F( ", now plotting one inboard analog input with magnified version offset for proper positioning:" ) );
        #endif
        MasterReadingsArray[ InboardPinIndex ].CurrentUnmagnifiedReading /= SAMPLE_TIMES;
        MasterReadingsArray[ InboardPinIndex ].CurrentUnmagnifiedReading <<= SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
    }

#if ( NUM_OF_INBOARDS_PLOTTED > 0 ) //plot the inboard analogs first and above from readings in MasterReadingsArray
    for( uint8_t InboardPinIndex = 0; InboardPinIndex < NUM_OF_INBOARDS_PLOTTED; InboardPinIndex++ )
    {
        PlotTheNormalAndMagnifiedSignals( InboardPinIndex ); //not permissible to plot the paired/superimposed traces except with odds below INDEX_OF_INBOARDS_NOT_SUPERIMPOSED
        #ifdef DEBUG
            Serial.println();
        #endif
    }
#endif

#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
    for( uint8_t whichOutboardADCindex = 0; whichOutboardADCindex < NUM_OF_OUTBOARDS_PLOTTED; whichOutboardADCindex++ )
    {
        #ifdef USING_LM334_WITH_DIGIPOT_BANKS 
Start_of_addon_ADC_acquisition:
            bool OverscaleIsUnfixable = false;
            while( true ) //comes back to here if CurrentUnmagnifiedReading overscales
            {
        #endif
        #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 15 )
            MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = ads.readADC_SingleEnded( whichOutboardADCindex );
            while( MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ] > HEIGHT_OF_A_PLOT_LINESPACE ) //TODO: verify the need for this check
            {
                MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = ads.readADC_SingleEnded( whichOutboardADCindex );
            }
        #else
            #ifdef DIFFERENTIAL
                #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC < 17 )
                    MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = CONVERT_TWOS_COMP_TO_SINGLE_ENDED( ( whichOutboardADCindex == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), ( uint32_t )(  - 1 ), HEIGHT_OF_A_PLOT_LINESPACE >> 1 );  // Convert to single-ended style
                #else
                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == HX711 )
//                                hx711.power_up();
                        MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = CONVERT_TWOS_COMP_TO_SINGLE_ENDED( hx711.read(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x800000*/ );
//                                CurrentUnmagnifiedReading = 0xFFFFFF;//= hx711.read_average( 9 );
                        
//                                hx711.power_down();
                    #else
                        #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1232 )
                        #else
                            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1242 )
                            #else
                                #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == AD7780 )
                                #else
                                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == AD779x )
                                    #else
                                        #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == MAX112x0 )
                                        #else
                                            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == LTC2400 )
                                            #else
                                                #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1231 )
                                                #else
                                                #endif
                                            #endif
                                        #endif
                                    #endif
                                #endif
                            #endif
                        #endif
                    #endif
                #endif
            #else //then figure it is Single-ended
            #endif
        #endif
        #ifdef USING_LM334_WITH_DIGIPOT_BANKS 
                break;
            }
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
                #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC == 15 )
                    ThisReadingTemp = ads.readADC_SingleEnded( whichOutboardADCindex );
                    while( ThisReadingTemp > HEIGHT_OF_A_PLOT_LINESPACE ) ThisReadingTemp = ads.readADC_SingleEnded( whichOutboardADCindex );
                #else
                    #ifdef DIFFERENTIAL
                        #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC < 17 )
                            ThisReadingTemp = CONVERT_TWOS_COMP_TO_SINGLE_ENDED( ( whichOutboardADCindex == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x8000*/ );
                        #else
                            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == HX711 )
                                #ifdef DEBUG
                                    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
//                                            Serial.println( F( "Reading differential ThisReadingTemp" ) );
                                #endif
//                                            hx711.power_up();
                                    ThisReadingTemp = CONVERT_TWOS_COMP_TO_SINGLE_ENDED( hx711.read(), HEIGHT_OF_A_PLOT_LINESPACE - 1/*mask of significant bits 24 or 32, etc*/, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x800000 which bit is sign bit*/ );
//                                            ThisReadingTemp = 0xFFFFFF; //hx711.read_average( 9 );
                                    
//                                            hx711.power_down();
                            #else
                                #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1232 )
                                #else
                                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1242 )
                                    #else
                                        #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == AD7780 )
                                        #else
                                            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == AD779x )
                                            #else
                                                #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == MAX211x0 )
                                                #else
                                                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == LTC2400 )
                                                    #else
                                                        #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1231 )
                                                        #else
                                                        #endif
                                                    #endif
                                                #endif
                                            #endif
                                        #endif
                                    #endif
                                #endif
                            #endif
                        #endif
                        #ifdef DEBUG
                            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
//                                    Serial.print( F( "Read adjusted differential ThisReadingTemp " ) );
//                                    Serial.println( ThisReadingTemp );
                        #endif
                    #endif
                #endif
                MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading += ThisReadingTemp;
        }
        #endif
        MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading /= SAMPLE_TIMES;
        MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading =(  MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading < HEIGHT_OF_A_PLOT_LINESPACE  ) ? MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading : HEIGHT_OF_A_PLOT_LINESPACE;
#ifdef DEBUG
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        Serial.print( F( "Line 1687 INDEX_OF_OUTBOARDS = " ) );
        Serial.print( INDEX_OF_OUTBOARDS );
        Serial.print( F( ", whichOutboardADCindex = " ) );
        Serial.println( whichOutboardADCindex );
        Serial.print( F( ", INDEX_OF_OUTBOARDS + whichOutboardADCindex = " ) );
        Serial.println( INDEX_OF_OUTBOARDS + whichOutboardADCindex );
#endif
        PlotTheNormalAndMagnifiedSignals( INDEX_OF_OUTBOARDS + whichOutboardADCindex );
    }
#endif
}

void setup() 
{
Serial.begin( BAUD_TO_SERIAL );//This speed is what works best with WeMos XI/TTGO XI board.
#ifdef USING_LM334_WITH_DIGIPOT_BANKS   //This is important to put this first so LM334 get some resistance
    #if ( USING_LM334_WITH_DIGIPOT_BANKS == 1 )
    pinMode( SS, OUTPUT );
    digitalWrite( SS, HIGH ); //Not needed by slave devices but rather by this board to make it configure itself to be master
//
    DigipotValues[ 0 ] = DIGIPOT_0_B0L0_STARTVALUE;  // Storing a copy of the digi pot values in sketch makes it possible to eliminate the MISO pin connection to the data out pins of all digi pots, besides the digi pots data out may not conform strictly to SPI since the MCP41X1 version has one bidirectional data pin
    DigipotValues[ 1 ] = DIGIPOT_1_B0L0_STARTVALUE;
    DigipotValues[ 2 ] = DIGIPOT_2_B0L0_STARTVALUE;
    DigipotValues[ 3 ] = DIGIPOT_0_B0L1_STARTVALUE;
    DigipotValues[ 4 ] = DIGIPOT_1_B0L1_STARTVALUE;
    DigipotValues[ 5 ] = DIGIPOT_2_B0L1_STARTVALUE;

    DigipotPins[ 0 ] = BANK_0_LEG_0_DIGITAL_POT_0;
    DigipotPins[ 1 ] = BANK_0_LEG_0_DIGITAL_POT_1;
    DigipotPins[ 2 ] = BANK_0_LEG_0_DIGITAL_POT_2;
    DigipotPins[ 3 ] = BANK_0_LEG_1_DIGITAL_POT_0;
    DigipotPins[ 4 ] = BANK_0_LEG_1_DIGITAL_POT_1;
    DigipotPins[ 5 ] = BANK_0_LEG_1_DIGITAL_POT_2;
        
    for( uint8_t index = 0; index < USING_LM334_WITH_DIGIPOT_BANKS; index++ )
    {
        pinMode( DigipotPins[ 0 + index ], OUTPUT );
        pinMode( DigipotPins[ 1 + index ], OUTPUT );
        pinMode( DigipotPins[ 2 + index ], OUTPUT );
        pinMode( DigipotPins[ 3 + index ], OUTPUT );
        pinMode( DigipotPins[ 4 + index ], OUTPUT );
        pinMode( DigipotPins[ 5 + index ], OUTPUT );
        digitalWrite( DigipotPins[ 0 + index ], HIGH );
        digitalWrite( DigipotPins[ 1 + index ], HIGH );
        digitalWrite( DigipotPins[ 2 + index ], HIGH );
        digitalWrite( DigipotPins[ 3 + index ], HIGH );
        digitalWrite( DigipotPins[ 4 + index ], HIGH );
        digitalWrite( DigipotPins[ 5 + index ], HIGH );
        SPI.begin();
        SPI.setBitOrder( MSBFIRST );
    #ifndef LEAVE_POT_VALUES_ALONE_DURING_SETUP //This causes digipot stored settings not to match digipots, but at least they stay put to what they were last set to
        setPotValue( DigipotPins[ 0 + index ], DigipotValues[ 0 + index ] );
        setPotValue( DigipotPins[ 1 + index ], DigipotValues[ 1 + index ] );
        setPotValue( DigipotPins[ 2 + index ], DigipotValues[ 2 + index ] );
        setPotValue( DigipotPins[ 3 + index ], DigipotValues[ 3 + index ] );
        setPotValue( DigipotPins[ 4 + index ], DigipotValues[ 4 + index ] );
        setPotValue( DigipotPins[ 5 + index ], DigipotValues[ 5 + index ] );
    #endif
        #ifdef DEBUG
            while ( !Serial && ( millis() - MillisStart < 8000 ) );
            Serial.println( F( "Digi pots set up" ) );
        #endif
    }
    #else
        #error This sketch is not entirely able to handle multiple digipot banks at this revision level
    #endif
#endif
    #if ( NUM_OF_OUTBOARDS_PLOTTED > 0 ) 
        #if !( ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD )
            analogReference( DEFAULT ); //This is the voltage level of max bit value on analog input
        #else
            analogReference( AR_DEFAULT ); //
        #endif
    #endif    
    #ifdef DEBUG
        MillisStart = millis();
        while ( !Serial && ( millis() - MillisStart < 8000 ) );
        Serial.print( F( "Starting setup with SDA & SCL & SCK & A4 & A5 & INDEX_OF_OUTBOARDS = " ) );
        Serial.print( SDA );
        Serial.print( F( " & " ) );
        Serial.print( SCL );
        Serial.print( F( " & " ) );
        Serial.print( SCK );
        Serial.print( F( " & " ) );
        Serial.print( A4 );
        Serial.print( F( " & " ) );
        Serial.print( A5 );
        Serial.print( F( " & " ) );
        Serial.println( INDEX_OF_OUTBOARDS );
#ifdef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
        Serial.print( F( "SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS " ) );
        Serial.println( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS );
#else
        Serial.println( F( "SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS not defined" ) );
#endif
        Serial.print( F( "NUM_OF_OUTBOARDS_PLOTTED " ) );
        Serial.println( NUM_OF_OUTBOARDS_PLOTTED );
#ifdef USING_LM334_WITH_DIGIPOT_BANKS
        Serial.print( F( "USING_LM334_WITH_DIGIPOT_BANKS " ) );
        Serial.println( USING_LM334_WITH_DIGIPOT_BANKS );
#else
        Serial.println( F( "USING_LM334_WITH_DIGIPOT_BANKS not defined" ) );
#endif
#ifdef AUTO_BRIDGE_BALANCING
        Serial.println( F( "AUTO_BRIDGE_BALANCING defined" ) );
#else
        Serial.println( F( "AUTO_BRIDGE_BALANCING not defined" ) );
#endif
        Serial.print( F( "INDEX_OF_INBOARDS_NOT_SUPERIMPOSED " ) );
        Serial.println( INDEX_OF_INBOARDS_NOT_SUPERIMPOSED );
        Serial.print( F( "INDEX_OF_INBOARDS_NOT_PLOTTED " ) );
        Serial.println( INDEX_OF_INBOARDS_NOT_PLOTTED );
        Serial.print( F( "INDEX_OF_OUTBOARDS " ) );
        Serial.println( INDEX_OF_OUTBOARDS );
        Serial.print( F( "NUMBER_OF_LINESPACES " ) );
        Serial.println( NUMBER_OF_LINESPACES );
    #endif
    //#ifndef ARDUINO_AVR_DIGISPARKPRO
    //    analogReadResolution( ADC_RES_BIT );
    //#endif
    #if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
        #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_ADDON_ADC < 17 )
        //   ads.setGain( GAIN_TWOTHIRDS );  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)  //The extra ones are here for reference 
           ads.setGain( GAIN_ONE );        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV  //This allows a simple power rail excitation supply to voltage divider
        //   ads.setGain( GAIN_TWO );        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
        //   ads.setGain( GAIN_FOUR );       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
        //   ads.setGain( GAIN_EIGHT );      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
        //   ads.setGain( GAIN_SIXTEEN );    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
            ads.begin();
        #else
            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == HX711 )
            /*
                #ifdef USING_LM334_WITH_DIGIPOT_BANKS
                    #define MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT NUM_OF_OUTBOARDS_PLOTTED
                    #ifdef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
                        #define RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT NUM_OF_INBOARDS_PLOTTED
                    #endif
                #else
                    #define MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT 0
                    #define ( NUM_OF_OUTBOARDS_PLOTTED + RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT NUM_OF_INBOARDS_PLOTTED )
                #endif
                */
                #ifdef DEBUG
                    MillisStart = millis();
                    while ( !Serial && ( millis() - MillisStart < 8000 ) );
//                    Serial.print( F( "MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT " ) );
//                    Serial.println( MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT );
//                    Serial.print( F( "RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT " ) );
//                    Serial.println( RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT );
                    Serial.print( F( "Initializing HX711..." ) );
                #endif
/*
 * With the library being used, the .begin() method is not needed if the HX711 was declared earlier prior to setup().  The reason I'm doing it superfluously here is simply to suggest some measure of future consistency across all ADCs since other ADC libraries may not allow one or the other...
 */
                hx711.begin( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, HIGHEST_SENSI_PGA_GAIN_FACTOR );  // if the third parameter is ommited the default gain value 128 & channel A is used by the library
                #ifdef DEBUG
                    MillisStart = millis();
                    while ( !Serial && ( millis() - MillisStart < 8000 ) ); //We limit the time to wait for serial ready
                    Serial.println( F( "done initializing HX711." ) );
                #endif
            #else
                #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1232 )
                #else
                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1242 )
                    #else
                        #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == AD7780 )
                        #else
                            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == AD779x )
                            #else
                                #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == MAX112x0 )
                                #else
                                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == LTC2400 )
                                    #else
                                        #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1231 )
                                        #else
                                        #endif
                                    #endif
                                #endif
                            #endif
                        #endif
                    #endif
                #endif
            #endif
        #endif
    #endif
    
    #ifdef __LGT8FX8E__
    //    analogReadResolution( 12 );  //I believe this is not necessary
        delay( SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING * 1000 );  // Needed by this board for serial to work
    #endif
#ifdef MAGNIFICATION_FACTOR
    TracespaceToSkipWhenRepositioning = ( HEIGHT_OF_A_PLOT_LINESPACE * PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) / 100;
    NegativeTracespaceToSkipWhenRepositioning = HEIGHT_OF_A_PLOT_LINESPACE - ( HEIGHT_OF_A_PLOT_LINESPACE * PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) / 100;
#endif
//    if( NUM_OF_OUTBOARDS_PLOTTED + NUM_OF_INBOARDS_PLOTTED > 1 ) LinespaceParameters[ 0 ].ZeroOfThisPlotLinespace = PLOTTER_MAX_SCALE - HEIGHT_OF_A_PLOT_LINESPACE;

#ifdef DEBUG
        while( !Serial );
        Serial.println( F( "The following numbers count up to the highest index of linespaces to be displayed:" ) );
#endif
// INDEX_OF_INBOARDS_NOT_SUPERIMPOSED actually equals the number of InboardSuperimposed exist
    for( uint8_t LinespacesIndex = 0; LinespacesIndex < NUMBER_OF_LINESPACES; LinespacesIndex++ )
    {
        uint8_t MasterReadingsArrayIndex;
        if( LinespacesIndex == 0 ) MasterReadingsArrayIndex = 0;
        if( ( MasterReadingsArrayIndex == INDEX_OF_INBOARDS_NOT_PLOTTED ) && ( MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS ) )
//        {
            MasterReadingsArrayIndex = INDEX_OF_OUTBOARDS; //whatever members are not plotted get skipped
//            LinespacesIndex--; //ensure this linepsace doesn't get skipped
//            continue;
//        }
#ifdef DEBUG
        while( !Serial );
        Serial.print( F( ", Line 1852 LinespacesIndex = " ) );
        Serial.print( LinespacesIndex );
        Serial.print( F( ", Line 1854 MasterReadingsArrayIndex = " ) );
        Serial.print( MasterReadingsArrayIndex );
        Serial.print( F( " " ) );
#endif
        LinespaceParameters[ LinespacesIndex ].HighLimitOfThisPlotLinespace = ( NUMBER_OF_LINESPACES - LinespacesIndex ) * HEIGHT_OF_A_PLOT_LINESPACE;
        LinespaceParameters[ LinespacesIndex ].ZeroOfThisPlotLinespace = LinespaceParameters[ LinespacesIndex ].HighLimitOfThisPlotLinespace - HEIGHT_OF_A_PLOT_LINESPACE;
        LinespaceParameters[ LinespacesIndex ].LastSignalPinPlotPoint = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
        LinespaceParameters[ LinespacesIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
        MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
        MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
        MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray = LinespacesIndex;
//                  Note that INDEX_OF_INBOARDS_NOT_SUPERIMPOSED is an index for MasterReadingsArray and actually is equal to the number of InboardSuperimposed that exist
        if( LinespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) //The two arrays correlate 1:2 until INDEX_OF_INBOARDS_NOT_SUPERIMPOSED
        {
            MasterReadingsArray[ MasterReadingsArrayIndex + 1 ].PreviousUnmagnifiedReading = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
            MasterReadingsArray[ MasterReadingsArrayIndex + 1 ].CurrentUnmagnifiedReading = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
            MasterReadingsArray[ MasterReadingsArrayIndex + 1 ].IndexInLinespaceParametersArray = LinespacesIndex;
        }
#ifdef MAGNIFICATION_FACTOR
        else
            LinespaceParameters[ LinespacesIndex ].MagnifyAdjustment = 0;
#endif
#ifdef DEBUG
        while( !Serial );
//        Serial.println();
        Serial.print( F( "LinespaceParameters[ " ) );
        Serial.print( LinespacesIndex );
        Serial.print( F( " ].HighLimitOfThisPlotLinespace == " ) );
        Serial.print( LinespaceParameters[ LinespacesIndex ].HighLimitOfThisPlotLinespace );
        Serial.print( F( ", ZeroOfThisPlotLinespace == " ) );
        Serial.print( LinespaceParameters[ LinespacesIndex ].ZeroOfThisPlotLinespace );
        Serial.print( F( ", LastReferencePinPlotPointOrLastMagnifiedPlotPoint == " ) );
        Serial.print( LinespaceParameters[ LinespacesIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
        Serial.print( F( ", PreviousUnmagnifiedReading == " ) );
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading );
        Serial.print( F( ", CurrentUnmagnifiedReading == " ) );
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading );
        Serial.print( F( ", IndexInLinespaceParametersArray == " ) );
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray );
        if( LinespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 )
        {
            Serial.print( F( ", + 1 PreviousUnmagnifiedReading == " ) );
            Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex + 1 ].PreviousUnmagnifiedReading );
            Serial.print( F( ", + 1 CurrentUnmagnifiedReading == " ) );
            Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex + 1 ].CurrentUnmagnifiedReading );
            Serial.print( F( ", + 1 IndexInLinespaceParametersArray == " ) );
            Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex + 1 ].IndexInLinespaceParametersArray );
        }
        Serial.println();
#endif
        MasterReadingsArrayIndex++;
        if( LinespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) MasterReadingsArrayIndex++; //skip the one we had to take care of in this linepsace iteration
    }
//    Serial.println();

    PlotTimingLineGoingUp( false ); //The false makes all traces originate at global zero.  It seems to look better that way

//Next the pin translation table is allocated then filled
    #if defined USING_LM334_WITH_DIGIPOT_BANKS /* && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS */ && ( NUM_OF_INBOARDS_PLOTTED < USING_LM334_WITH_DIGIPOT_BANKS * 2 )
        AnalogPinArray = ( uint8_t * )malloc( 2 * USING_LM334_WITH_DIGIPOT_BANKS );
    #elif ( NUM_OF_INBOARDS_PLOTTED > 0 )
        AnalogPinArray = ( uint8_t * )malloc( NUM_OF_INBOARDS_PLOTTED );
    #endif
        #if ( NUM_OF_INBOARDS_PLOTTED > 0 ) || ( defined USING_LM334_WITH_DIGIPOT_BANKS /*&& defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && defined AUTO_BRIDGE_BALANCING && not defined LEAVE_POT_VALUES_ALONE_DURING_SETUP*/ )
        //Hereafter is the pattern.  If you have more analog pins, add them according to the pattern.
        #ifdef NUM_ANALOG_INPUTS
        #ifdef PIN_A0
            #if defined USING_LM334_WITH_DIGIPOT_BANKS /*&& defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS */ && ( NUM_OF_INBOARDS_PLOTTED < USING_LM334_WITH_DIGIPOT_BANKS * 2 )
            for( uint8_t i = 0; i < ( USING_LM334_WITH_DIGIPOT_BANKS * 2 ); i++ )
            #else
            for( uint8_t i = 0; i < NUM_OF_INBOARDS_PLOTTED; i++ )
            #endif
            {
                if( i == 0 )
                    *(AnalogPinArray + i) = PIN_A0;
                #ifdef PIN_A1
                    else if( i == 1 )
                        *(AnalogPinArray + i) = PIN_A1;
                    #ifdef PIN_A2
                    else if( i == 2 )
                        *(AnalogPinArray + i) = PIN_A2;
                        #ifdef PIN_A3
                    else if( i == 3 )
                        *(AnalogPinArray + i) = PIN_A3;
                            #ifdef PIN_A4
                    else if( i == 4 )
                        *(AnalogPinArray + i) = PIN_A4;
                                #ifdef PIN_A5
                    else if( i == 5 )
                        *(AnalogPinArray + i) = PIN_A5;
                                    #ifdef PIN_A6
                    else if( i == 6 )
                        *(AnalogPinArray + i) = PIN_A6;
                                        #ifdef PIN_A7
                    else if( i == 7 )
                        *(AnalogPinArray + i) = PIN_A7;
                                            #ifdef PIN_A8
                    else if( i == 8 )
                        *(AnalogPinArray + i) = PIN_A8;
                                                #ifdef PIN_A9
                    else if( i == 9 )
                        *(AnalogPinArray + i) = PIN_A9;
                                                    #ifdef PIN_A10
                    else if( i == 10 )
                        *(AnalogPinArray + i) = PIN_A10;
                                                        #ifdef PIN_A11
                    else if( i == 11 )
                        *(AnalogPinArray + i) = PIN_A11;
                                                            #ifdef PIN_A12
                    else if( i == 12 )
                        *(AnalogPinArray + i) = PIN_A12;
                                                                #ifdef PIN_A13
                    else if( i == 13 )
                        *(AnalogPinArray + i) = PIN_A13;
                                                                    #ifdef PIN_A14
                    else if( i == 14 )
                        *(AnalogPinArray + i) = PIN_A14;
                                                                        #ifdef PIN_A15
                    else if( i == 15 )
                        *(AnalogPinArray + i) = PIN_A15;
                                                                            #ifdef PIN_A16
                    else if( i == 16 )
                        *(AnalogPinArray + i) = PIN_A16;
                                                                                #ifdef PIN_A17
                    else if( i == 17 )
                        *(AnalogPinArray + i) = PIN_A17;
                                                                                    #ifdef PIN_A18
                    else if( i == 18 )
                        *(AnalogPinArray + i) = PIN_A18;
                                                                                        #ifdef PIN_A19
                    else if( i == 19 )
                        *(AnalogPinArray + i) = PIN_A19;
                                                                                            #ifdef PIN_A20
                    else if( i == 20 )
                        *(AnalogPinArray + i) = PIN_A20;
                                                                                                #ifdef PIN_A21
                    else if( i == 21 )
                        *(AnalogPinArray + i) = PIN_A21;
                                                                                                    #ifdef PIN_A22
                    else if( i == 22 )
                        *(AnalogPinArray + i) = PIN_A22;
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
            //Some boards don't have good definitions and constants for the analog pins, TTGO XI, for example :-(
                #ifdef DEBUG
                    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
                    Serial.println( F( "Creating analog pin definitions" ) );
                #endif
            #if defined USING_LM334_WITH_DIGIPOT_BANKS && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < USING_LM334_WITH_DIGIPOT_BANKS * 2 )
                for( uint8_t i = 0; i < ( USING_LM334_WITH_DIGIPOT_BANKS * 2 ); i++ )
            #else
                for( uint8_t i = 0; i < NUM_OF_INBOARDS_PLOTTED; i++ )
            #endif
                    *(AnalogPinArray + i) = i + FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES;
            #endif //end of PIN_A0 check
        #endif
    #endif
    #ifdef DEBUG
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        #ifndef __LGT8FX8E__
            Serial.print( F( "Operator convenience delay so operator can prepare as needed..." ) );
            delay( 5000 );
            Serial.println( F( "done delaying for operator convenience." ) );
        #endif
        Serial.println( F( "Some running parameters:" ) );
        Serial.print( F( "AnalogPinArray = " ) );
        Serial.println( (unsigned long)AnalogPinArray );
        #if defined USING_LM334_WITH_DIGIPOT_BANKS && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < USING_LM334_WITH_DIGIPOT_BANKS * 2 )
            for( uint8_t i = 0; i < ( USING_LM334_WITH_DIGIPOT_BANKS * 2 ); i++ )
        #else
            for( uint8_t i = 0; i < NUM_OF_INBOARDS_PLOTTED; i++ )
        #endif
            Serial.println( *( AnalogPinArray + i ) );
        Serial.print( F( "PLOTTER_MAX_SCALE = " ) );
        Serial.print( PLOTTER_MAX_SCALE );
        Serial.print( F( " and ( uint32_t )( NUM_OF_OUTBOARDS_PLOTTED + NUM_OF_INBOARDS_PLOTTED ) = " ) );
        Serial.println( ( uint32_t )( NUM_OF_OUTBOARDS_PLOTTED + NUM_OF_INBOARDS_PLOTTED ) );
        
        //add other prints here to your liking
        
        Serial.print( F( "End of " ) );
    #endif //end of DEBUG
    #ifdef AUTO_BRIDGE_BALANCING
        for( uint8_t index = 0; index < NUM_OF_OUTBOARDS_PLOTTED; index++ )
            CounterForTraceOutOfRangeTooLong[ index ] = 0;
    #endif
//#error this area below is where I'm at in development
    #if defined AUTO_BRIDGE_BALANCING && not defined LEAVE_POT_VALUES_ALONE_DURING_SETUP
        #ifdef DEBUG
            Serial.println( F( "initial setup.  Entering calibration setup." ) );
        #endif
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
/*
        Serial.print( F( "0 " ) );
        Serial.print( PLOTTER_MAX_SCALE );
        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( true ); //Fills the arrays with valid values
        */
/* Don't remember why following lines were there
        uint32_t LastPlotPoints_temp[ USING_LM334_WITH_DIGIPOT_BANKS * 2 ]; //2 legs/bank, each leg is one entry        
        Serial.println();
//Then get the readings of desired legs from 
        for( uint8_t bank = 0; bank < USING_LM334_WITH_DIGIPOT_BANKS; bank++ )
        {
#ifdef MAGNIFICATION_FACTOR
            LastPlotPoints_temp[ 0 + ( bank * 2 ) ] = LastPlotPoints[ bank * 2 ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
            LastPlotPoints_temp[ 1 + ( bank * 2 ) ] = LastPlotPoints[ 2 + ( bank * 2 ) ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
#else
            LastPlotPoints_temp[ 0 + ( bank * 2 ) ] = LastPlotPoints[ bank * 2 ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
            LastPlotPoints_temp[ 1 + ( bank * 2 ) ] = LastPlotPoints[ 1 + ( bank * 2 ) ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
#endif
        }
*/
//#ifdef MAGNIFICATION_FACTOR
//        /*reading=*/LastPlotPoints[ bank * 2 ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
//#else
//        /*reading=*/LastPlotPoints[ bank ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
//#endif
//        }
//bool SetDigipotsReferenceLeg( bool JustPerformOneStep = false, uint8_t bank = 0 )
//#error SetDigipotsReferenceLeg() has a bug where it allows out of range setting values
        for( uint8_t bank = 0; bank < USING_LM334_WITH_DIGIPOT_BANKS; bank++ )
        {
            while( SetDigipotsReferenceLeg( true, bank ) == false ) //while false, the entire bank is being zeroed into the desired balance
            {
            #ifdef DEBUG
                Serial.println( F( "Line 1676" ) );
            #endif
                delay( 2 ); // allow some settling time
                Serial.print( PLOTTER_MAX_SCALE );
                Serial.print( F( " " ) );
                ReadAndPlotFromAllADCsInAndOutboard( true ); // I would think the operator would appreciate seeing something like this during calibration
                Serial.println();
                if( CounterForTraceOutOfRangeTooLong[ bank ]++ > 80 ) break; //Limited to prevent endless looping here
            }
            CounterForTraceOutOfRangeTooLong[ bank ] = 0;
            MatchBridgeLegSignalToReference( bank ); //This will do the same on the signal leg
        }
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        Serial.print( F( "0 " ) );
        ReadAndPlotFromAllADCsInAndOutboard( true ); //Fills the arrays with valid values
/* Following line was some forgotten plan
        uint32_t LastPlotPoints_temp[ USING_LM334_WITH_DIGIPOT_BANKS * 2 ]; //2 legs/bank, each leg is one entry        */
        Serial.println();

//Now could turn on wobble and fine tune to find the common mode voltage to realize greatest gain of the outboard ADC BUT it's not that important!
    #else
        #ifdef DEBUG
            Serial.println( F( "setup." ) );
        #endif
    #endif
}

void loop() 
{
    for( uint16_t PlotterLoops = 0; PlotterLoops < 500 / 3; PlotterLoops++ ) 
    {
        MillisStart = millis();
        if( graphline ) ThisReadingTemp = 0;
        else ThisReadingTemp = PLOTTER_MAX_SCALE;
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        Serial.print( ThisReadingTemp ); //This was originally last printed in the group.  It needs to be first instead so the line can be "notched" horizontally without needing to reprint all values.
        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard();
        Serial.println();
/*        old style partial of auto adjust case:
    if( MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS )
    {
        #if ( NUM_OF_OUTBOARDS_PLOTTED > 0 ) && defined AUTO_BRIDGE_BALANCING
            #ifdef MAGNIFICATION_FACTOR
            if( MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS )  BestGuessAnalogInputreading( 1 + ( channel * 2 ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE - BestGuessAnalogInputreading( ( channel - 2 ) * 2 ) );
            #else
            if( MasterReadingsArrayIndex >= NUM_OF_INBOARDS_PLOTTED ) BestGuessAnalogInputreading( 1 + channel ) + BIAS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE - BestGuessAnalogInputreading( ( channel - 2 ) * 2 );
            #endif
        //BestGuessAnalogInputreading index argument is a bank...which doesn't exist except with the outboard ADCs
        #endif
    }
*/
/*
        char nextChar;
        nextChar = 0;
        while( Serial.available() )
        {
//            pinMode( LED_BUILTIN, OUTPUT );                // These lines for blinking the LED are here if you want the LED to blink when data is rec'd
//            digitalWrite( LED_BUILTIN, HIGH );             // These lines for blinking the LED are here if you want the LED to blink when data is rec'd
            nextChar = (char)Serial.read();
            if( nextChar != 0xD && nextChar != 0xA )
            {
                szFull[ strlen( szFull ) + 1 ] = 0;
                szFull[ strlen( szFull ) ] = nextChar;
            }
            else
            {
                if( Serial.available() ) Serial.read();
                nextChar = 0;
            }
        }
//        digitalWrite( LED_BUILTIN, LOW );                  // These lines for blinking the LED are here if you want the LED to blink when data is rec'd
        if( !( szFull[ 0 ] == 0 || nextChar != 0 ) )        //The way this and while loop is set up allows reception of lines with no endings but at a timing cost of one loop()
        {
            #ifdef DEBUG
                while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
                Serial.print( F( "Received " ) );
                Serial.println( szFull );
            #endif
    #ifdef USING_LM334_WITH_DIGIPOT_BANKS
            uint8_t DIGITAL_POT_;
            int offset_integer;
            if( szFull[ 1 ] == 'D' || szFull[ 1 ] == 'd' ) szFull[ 1 ] = '-';
            else if( szFull[ 1 ] == 'U' || szFull[ 1 ] == 'u' ) szFull[ 1 ] = '+';
            if( szFull[ 1 ] == '-' )
            {
                if( szFull[ 2 ] == 0 )
                    offset_integer = -1;
                else
                    offset_integer = 0 - atoi( &szFull[ 2 ] );
            }
            else if( szFull[ 1 ] == '+' )
            {
                if( szFull[ 2 ] == 0 )
                    offset_integer = 1;
                else
                    offset_integer = atoi( &szFull[ 2 ] );
            }
            else goto NoPotChange;
            if( offset_integer > MAXPOTVALUE || offset_integer < 0 - MAXPOTVALUE ) goto NoPotChange;
            if( szFull[ 0 ] == '1' ) DIGITAL_POT_ = DigipotPins[ 0 ];
            else if( szFull[ 0 ] == '2' ) DIGITAL_POT_ = DigipotPins[ 1 ];
            else if( szFull[ 0 ] == '3' ) DIGITAL_POT_ = DigipotPins[ 2 ];
            else if( szFull[ 0 ] == '4' ) DIGITAL_POT_ = DigipotPins[ 3 ];
            else if( szFull[ 0 ] == '5' ) DIGITAL_POT_ = DigipotPins[ 4 ];
            else if( szFull[ 0 ] == '6' ) DIGITAL_POT_ = DigipotPins[ 5 ];
            else goto NoPotChange;
            offsetPotValue( DIGITAL_POT_, offset_integer );
NoPotChange:
    #endif
            szFull[ 0 ] = 0;
            #ifdef DEBUG
                while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
                Serial.println();
            #endif
        }
*/
#if defined ( POT_TEST_WOBBLE_POSITIVE ) || defined ( POT_TEST_WOBBLE_NEGATIVE )
    wobbleloops = ( wobbleloops + 1 ) % 4;
    #ifdef DEBUG
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        Serial.print( F( "Line 1687, wobbleloops = " ) );
        Serial.println( wobbleloops );
    #endif
        if( wobbleloops == 0 )
        {
            wobble();
        }    
#endif
#if defined ( TEST_STEP_UP_DOWN )
        for( uint8_t bank = 0; bank < USING_LM334_WITH_DIGIPOT_BANKS; bank++ )
        {
        #if ( TEST_STEP_UP_DOWN == SINGLESIDE )
            if( potstepdirection )
            {//AdjustBridgeOutputPositive until maxed
                if( !AdjustBridgeOutputPositive( bank ) )
                {
                    potstepdirection = false;
                    AdjustBridgeOutputNegative( bank );
                }
            }
            else
            {
                if( !AdjustBridgeOutputNegative( bank ) )
                {
                    potstepdirection = true;
                    AdjustBridgeOutputPositive( bank );
                }
            }
        #elif ( TEST_STEP_UP_DOWN == COMMONMODE )
            AdjustWholeBridgeCommonmode( bank );
        #else
            ; //I had a reason for this to be here but I don't recall it while I'm adding this comment.  May be future location for some code or maybe it makes code less susceptible to development bugs for the time being?
        #endif
        }
#endif
        while( millis() - MillisStart < MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS )
        {//acquire and process not-plotted readings of inboard analog pins that get used for digipot auto-balancing FUTURE TODO
            ;//or just wait.
        }
    }
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    if( !graphline )
    {//going down
        for( uint8_t LinespaceParametersIndex = 0; LinespaceParametersIndex < NUMBER_OF_LINESPACES; LinespaceParametersIndex++ )
        {
            Serial.print( LinespaceParameters[ LinespaceParametersIndex ].HighLimitOfThisPlotLinespace );
            ReplotLastValuesForAllTraces( true );
            Serial.print( LinespaceParameters[ LinespaceParametersIndex ].ZeroOfThisPlotLinespace );
            ReplotLastValuesForAllTraces( true );
        }
    }
    else
        PlotTimingLineGoingUp();

    graphline = !graphline; // graphline started as false, so it becomes true here on the first complementing of it
}
