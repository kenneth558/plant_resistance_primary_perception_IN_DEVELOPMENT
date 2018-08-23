 //        Before compiling this sketch, you must set or confirm the following appropriately for your configuration and preferences !!!
#define NUM_OF_INBOARD_ADCS_TO_PLOT 2                                                              //The number of consecutive analog pins to plot, beginning with PIN_A0
#define NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT 1                                                  //The number of consecutive "highest-sensitivity ADC" pins to plot, beginning with A0 and, if double-ended, A1.  ADDON ADC ONLY - DOES _NOT_ INCLUDE INBOARD ANALOG INPUT PINS
#define HIGHEST_SENSI_ADDON_ADC_TYPE HX711                                                         //Proposing that "ADS1231" covers ADS1231; could make this "ADS1232" (ADS1232), "ADS1242" (ADS1242), "AD779x" (AD779x), "AD7780" (AD7780), "HX711" (HX711), "MAX112x0" (MAX112x0...) or "LTC2400" (LTC2400) but code not included in v.FREE; ONLY ONE TYPE ALLOWED
#define MAGNIFICATION_FACTOR 4                                                                     //Activates the plotting of magnified traces in all ADC linespaces; upper limit somewhere less than 4,294,967,295. Note: you can disable displaying magnified traces altogether by not defined this macro at all. Proper use of FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET will also disable magnified traces of the first two analog inputs
#define HIGHESTBITRESFROMHIGHESTSENSIADDONADC 24                                                   //All ADC values will get scaled to the single-ended aspect of this,  15 is ADS1115 single-ended, 16 for double-ended when two LM334s are used.  change to 11 for ADS1015 single-ended or 12 with two LM334s, (future: change to 24 for HX711--NO b/c there is the ADS1231 at 24 bits)
#define SAMPLE_TIMES 4                                                                             //To better average out artifacts we over-sample and average.  This value can be tweaked by you to ensure neutralization of power line noise or harmonics of power supplies, etc.....
#define MOST_PROBLEMATIC_INTERFERENCE_FREQ 60                                                      //This is here just in case you think that you might have some interference on a known frequency.
#define DELAY_TIME_BETWEEN_SAMPLES_MS ( 1000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ / SAMPLE_TIMES ) //COARSE ADJUST
#define DELAY_TIME_BETWEEN_SAMPLES_US ( ( ( 1000000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ ) - ( DELAY_TIME_BETWEEN_SAMPLES_MS * SAMPLE_TIMES * 1000 ) ) / SAMPLE_TIMES ) //FINE ADJUST.  THIS GETS ADDED TO COARSE ADJUST, PRECISION = TRUNCATED PRAGMATICALLY TO uSec TO ACKNOWLEDGE SOME OVERHEAD FOR LOOPING SUPPORT CODE   // End of this part of code update
#define FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES 14 //Some boards don't have good definitions and constants for the analog pins :-(
#define PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED 50 //BETWEEN 0 AND 100 indicating how much of the display region in percent to skip when magnified view trace has to get repositioned because trace would be outside region bounds; NO BOUNDS CHECKING IS PROVIDED!!!
#define ANALOGINPUTBITSOFBOARD 10                                                                  //Most Arduino boards are 10-bit resolution, but some can be 12 bits.  For known 12 bit boards (SAM, SAMD and TTGO XI architectures), this gets re-defined below, so generally this can be left as 10 even for those boards
#define SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING 9                         //8 works only usually
#define HIGHEST_SENSI_PGA_GAIN_FACTOR 128                                                          //For HX711 a gain of 128 gets applied to channel A. Available to you for your own use PGA=Programmable Gain Amplifier: many ADCs will correlate a gain of one with full-scale being rail-to-rail, while a gain of anything higher correlates to full-scale being in the mV range (most sensitive and most noise-susceptible).
#define MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS 70                                                   //Sets a maximum speed limit, but actual speed may be further limited by other factors
#define USING_LM334_WITH_MCP4162_POT_BANKS                                                            //Number of digipot Wheatstones, but this sketch revision level only handles 0 or 1 here.  Remove if using Wheatstone bridge with only standard resistors.  make true if using bridge with upper resistive elements being LM334s controllable with the MCP4162-104 pots
#define FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET 1 //If defined, allows rail-to-rail inboard Analog Inputs to be used to adjust digipots, but mainly causes first inboard Analog Inputs to be paired (superimposed in pairs sharing plot-line spaces) so even manual pots can be adjusted easily
#define AUTO_BRIDGE_BALANCING  //increases setup time significantly BROKEN FOR NOW                     //Turns on auto-balancing in setup(), significant time elapse for this to complete!
//#define DEBUG                                                                                      //Don't forget that DEBUG is not formatted for Serial plotter, but might work anyway if you'd never print numbers only any DEBUG print line
//#define POTTESTWOBBLEPOSITIVE 0                                                                     //For testing - wobbles digipot settings on bank index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the signal leg
//#define POTTESTWOBBLENEGATIVE 0                                                                     //For testing - wobbles digipot settings on bank index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the reference leg
//#define LEAVEPOTVALUESALONEDURINGSETUP                                                             //First run should leave this undefined to load digi pots with some values
#define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 7 //not well tested                   //sets how soon run-time auto-balancing kicks in when trace goes off scale
#define BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE 0                                                 //Though the name suggests otherwise, this offset will be applied to all signal lines, not just the first one, until further development (I couldn't make this into an array).  Inboard Analog Inputs of 10 bits will make much change with little values, 12 bit inboard allows more flexibility here

#ifdef __LGT8FX8E__
    #define BAUD_TO_SERIAL 19200  //This speed is what works best with WeMos XI/TTGO XI board.  Experiment as desired.
#else
    #define BAUD_TO_SERIAL 57600 //YOU MAY SET THIS TO THE MAXIMUM VALUE THAT YOUR CONFIGURATION WILL FUNCTION WITH (UNLESS YOU'RE USING THE WeMos XI/TTGO XI, OF COURSE)
#endif
//No need to change macros below:
#define CONVERTTWOSCOMPTOSINGLEENDED( value_read_from_the_differential_ADC, mask, xorvalue ) ((value_read_from_the_differential_ADC & mask)^xorvalue)
//OTHER MACROS (DEFINES OR RE-DEFINES) ELSEWHERE: VERSION, NUM_OF_INBOARD_ADCS_TO_PLOT, NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT, DIGIPOT_0_B0L0_STARTVALUE - DIGIPOT_2_B0L1_STARTVALUE, HALFHIGHESTBITRESFROMHIGHESTSENSIADDONADC, DIFFERENTIAL, PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, PLOTTERMAXSCALE, HUNDREDTHPLOTTERMAXSCALE, SAMPLE_TIMES, ANALOGINPUTBITSOFBOARD, SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE, COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG, HEIGHT_OF_A_PLOT_LINESPACE
//FUTURE #define TESTSTEPUPDOWN COMMONMODE                                                                  //Available: SINGLESIDE COMMONMODE
//FUTURE #define USING_DUAL_74LV138_DECODERS
/*******************(C)  COPYRIGHT 2018 KENNETH L ANDERSON *********************
* 
*      ARDUINO ELECTRICAL RESISTANCE/CONDUCTANCE MONITORING SKETCH 
*      
* File Name          : adc_for_plant_tissue.ino
* Author             : KENNETH L ANDERSON
* Version            : v.Free
* Date               : 23-Aug-2018
* Description        : To replicate Cleve Backster's findings that he attributed to a phenomenon he called "Primary Perception".  Basically, this sketch turns an Arduino MCU and optional (recommended) ADS1115 into a nicely functional poor man's polygraph in order to learn/demonstrate telempathic gardening.
* Boards tested on   : Uno using both ADS1115 and inboard analog inputs.  
*                    : TTGO XI using ADS1115.  
*                    : Many other configurations should work fine.  
*                    : The ATTINY85 is not suitable at all due to not having hardware serial
* 
* Known limitations  : No ability to accept user input from keyboard during run time due to Arduino plotter limitation
*                    : Re-compile is needed for any changes to configuration
*                    : Analog input pins being used MUST be the first available analog inputs
*                    : Only a single add-on ADS ADC device and only 1 or 2 differential channels on it is accommodated
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
*              04 May   2018 :  Some 12 bit tweaking so that TTGO/WeMos XI, SAM and SAMD architectures compile with inboard analog inputs to computed at 12 bit even though ANALOGINPUTBITSOFBOARD is set at default.
*              18 May   2018 :  Anti-aliasing code
*              29 May   2018 :  Differential use of ADS1x15 to allow LM334 temperature comp to negative inputs so LM334 can be used on positive inputs
*              32 May   2018 :  Added skeleton preprocessor defines for user to compatibly code their own support for a few 24-bit ADCs
*              05 June  2018 :  HX711 accommodated, you'll just have to balance the bridge manually
*              08 June  2018 :  Bugfix for inboard analog inputs above the first one - they didn't print before this fix
*              17 June  2018 :  Corrected pointer reinitialize of A_PIN_ARRAY that disabled internal Analog Input pins.  Added "while ( !Serial );" for Leonardo's native USB; starting to add framework for programmable potentiometers, changed defines to allow for a separate full-scale, lower res ADC and a high res ADC for normal viewing, etc,
*              18 June  2018 :  Bug fixes relative to displaying multiple traces while one or more are from inboard analog pins
*              13 July  2018 :  Modified plotter timing trace to notch horizontally at range min and max for signal traces when it crosses up and down.  Incorporated digi pot adjustings in debug mode. Enabled bypass of digi pot set in setup()
*              14 July  2018 :  Improved horizontal timing trace notching - made it shorter and consistent between levels
*              15 July  2018 :  Allow unique digipot intializing value for each pot.  Discovered HX711 input Z is way too low for use without buffers.  Regrouping....
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
*              NEXT          :  Magnification factor really needs to be run-time adjustable via a potentiometer.  Very important!
*              NEXT          :  Re-code AUTO_BRIDGE_BALANCING feature to get it working again but with additional ability to plot its effects during calibration
*              NEXT          :  Accommodate ADS1232 &/or ADS1231
*               
*********************************************************************************************************************/
#define VERSION "v.Free"  // Since this never gets used anywhere, it doesn't compile in so no memory is wasted
#include <math.h>
#define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ( 1 << ( ANALOGINPUTBITSOFBOARD - 1 ) ) // Needed f HIGHEST_SENSI_ADDON_ADC_TYPE has a sweet spot of max sensitivity, unlike true op-amp.  (HX711 == 306; normal op-amp, which has none == Vcc/2 == 512)
#ifndef NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT
    #define NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT 0
#elif ( 1 > NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + 0 ) //Evaluates to 1>+0 if the macro was defined as a blank.  Only way I know of to check for blank macros when we need a number in them
    #undef NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT
    #define NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT 0
#endif
#if ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 ) //Since so many of the ADC libraries already use OO classes, we'll set that as a pattern - instantiate prior to executing any code
    #define HALFHIGHESTBITRESFROMHIGHESTSENSIADDONADC ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC / 2 )
    #if ( ( HALFHIGHESTBITRESFROMHIGHESTSENSIADDONADC * 2 ) == HIGHESTBITRESFROMHIGHESTSENSIADDONADC )
        #define DIFFERENTIAL 
    #endif
    #if ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC < 17 ) && ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 )
        #include <Adafruit_ADS1015.h>//for systems using ADS1115/ADS1015  Data addressable I2C, shares bidirectional, open-collector data and clk only with other I2C slaves on same bus, must use the core-defined SDA/SCL pins except ESP8266 and ATtiny85 or see https://www.arduino.cc/en/reference/wire or see the Adafruit_ADS1X15-master README.md
/*  
*  With Adafruit_ADS1015.h, SDA, SCL Wemos XI/TTGO XI use A4 for SDA, and A5 is SCL.
*/
        #if ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 15 ) || ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 16 )
            Adafruit_ADS1115 ads;  //For when ADS1115 is being used Data addressable I2C and shares bidirectional, open-collector data and clk only with other I2C slaves on same bus, must use the core-defined SDA/SCL pins except ESP8266 and ATtiny85 or see https://www.arduino.cc/en/reference/wire or see the Adafruit_ADS1X15-master README.md
        #else
            #if ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 11 ) || ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 12 )
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
        #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == HX711 ) && ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 24 )  //The HX711 does NOT communicate over open-collector I2C; pick your own pins for comming with it other than SS, CLK, MOSI, and MISO of SPI.  The digital interface to the HX711 is a proprietary SPI-like interface using CLK to select and Data is always lo-z (can't share either)
            #include <HX711.h>  //From https://github.com/bogde/HX711  This ADC has no CS pin so the library must use software SPI with dedicated CLK pin.  Not data selectable as would be in I2C, nor CS selectable - must be on dedicated CLK & Data lines
            HX711 hx711( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC ); // This library allows us to set the pins and gain here or later in a .begin().   
            #undef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
            #define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG 290                // If HIGHEST_SENSI_ADDON_ADC_TYPE has a sweet spot of max sensitivity, unlike true op-amp.  (HX711 == 305, ranging from 1.49 to 1.507 vdc depending which scale is used to read it).  This will also be discovered and stored in EEPROM in a future revision
        #else
            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1232 ) && ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 24 )
            #else
                #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1242 ) && ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 24 ) //Which 24-bit ADC is single-ended?  ADS1242 It is 23 bits hopefully
                #else
                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == AD7780 ) && ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 24 )
                    #else
                        #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == AD779x ) && ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 24 )
                        #else
                            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == MAX112x0 ) && ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 24 )
                            #else
                                #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == LTC2400 ) && ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 24 )
                                #else
                                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == ADS1231 ) && ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 24 )
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
    #undef HIGHESTBITRESFROMHIGHESTSENSIADDONADC
    #define HIGHESTBITRESFROMHIGHESTSENSIADDONADC ANALOGINPUTBITSOFBOARD
    #undef HIGHEST_SENSI_ADDON_ADC_TYPE
    #undef FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET
    #undef HIGHEST_SENSI_PGA_GAIN_FACTOR
#endif
#ifndef NUM_OF_INBOARD_ADCS_TO_PLOT
    #define NUM_OF_INBOARD_ADCS_TO_PLOT 0
#endif
#ifndef LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER
    #define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 65536
#endif
#ifndef BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE
    #define BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE 0
#endif
#if ( NUM_OF_INBOARD_ADCS_TO_PLOT > 0 )
    #ifndef NUM_ANALOG_INPUTS
#error Sorry, but you will have to manually define the define variable NUM_ANALOG_INPUTS somewhere above this line and re-compile...
    #endif
#else
    #if ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT == 0 )
You'll need to manually define at least one of the variables NUM_OF_INBOARD_ADCS_TO_PLOT or NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT where they appear in the lines above and re-compile...
If you only have the Arduino without an ADS1X15, then define NUM_OF_INBOARD_ADCS_TO_PLOT.  Otherwise, define NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT and/or both of them.
    #endif
#endif
#if defined MAGNIFICATION_FACTOR && ( ( PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED > 100 ) || ( PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED < 0 ) )
#error Sorry, but the macro PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED is out of bounds
#endif

//The following undefines likely obsolete a number of macro checks in the body of sketch but I haven't gone through to clean them up
#ifdef USING_LM334_WITH_MCP4162_POT_BANKS
    #if ( 1 > USING_LM334_WITH_MCP4162_POT_BANKS + 0 )
        #undef USING_LM334_WITH_MCP4162_POT_BANKS
        #define USING_LM334_WITH_MCP4162_POT_BANKS 1 //make sure it contains an integer
    #endif
#endif
#ifdef FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET
    #if ( 1 > FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET + 0 )
        #undef FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET
        #define FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET 1
    #endif
#endif
#ifndef USING_LM334_WITH_MCP4162_POT_BANKS
    #undef POTTESTWOBBLEPOSITIVE
    #undef POTTESTWOBBLENEGATIVE
    #undef TESTSTEPUPDOWN
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
    #ifdef FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET //To allow the number of banks on either macro
        #if ( FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET > USING_LM334_WITH_MCP4162_POT_BANKS )
            #undef USING_LM334_WITH_MCP4162_POT_BANKS
            #define USING_LM334_WITH_MCP4162_POT_BANKS FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET
        #endif
    #endif
    #ifdef POTTESTWOBBLEPOSITIVE
        #if ( 1 > POTTESTWOBBLEPOSITIVE + 0 )
            #undef POTTESTWOBBLEPOSITIVE
            #define POTTESTWOBBLEPOSITIVE 0 //make sure it contains a bank index, default is bank 0
        #endif
    #endif
    #ifdef POTTESTWOBBLENEGATIVE
        #if ( 1 > POTTESTWOBBLENEGATIVE + 0 )
            #undef POTTESTWOBBLENEGATIVE
            #define POTTESTWOBBLENEGATIVE 0 //make sure it contains a bank index, default is bank 0
        #endif
    #endif
    #define NUM_OF_DIGIPOTS_PER_BANK 6
    #define NUM_OF_DIGIPOTS ( NUM_OF_DIGIPOTS_PER_BANK * USING_LM334_WITH_MCP4162_POT_BANKS )
    uint8_t digipot_pins[ NUM_OF_DIGIPOTS ];
    static uint16_t digipot_values[ NUM_OF_DIGIPOTS ];
    #define MAXPOTVALUE 257

//    #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 0 ) Just b/c this conforms to the pattern
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
    #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 1 ) //none of this below works, yet.  It is in process of development...
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
        #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 2 )
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
            #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 3 )
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
                #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 4 )
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
                    #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 5 )
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
                        #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 6 )
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
//        #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 1 )
//            #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 2 )
//                #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 3 )
//                    #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 4 )
//                        #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 5 )
//                            #if ( USING_LM334_WITH_MCP4162_POT_BANKS > 6 )
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

//global variables are declared static to prevent them from being seen by any later user-added compilation units that would try, presumeably inadvertently, through the use of the "extern" cast

/*
 * 
 * The following pin defines are for the WeMos XI/TTGO XI board only
 * Change per your board layout if you need some non-standard Arduino 10-bit analog inputs.  Uno et. al. should work just fine without needing your attention
 * 
 */

static uint8_t *A_PIN_ARRAY;
struct magnify_adjustment_and_display_zero
{
#ifdef MAGNIFICATION_FACTOR
    uint32_t magnify_adjustment;
#endif
#if defined MAGNIFICATION_FACTOR || defined AUTO_BRIDGE_BALANCING
    uint32_t previous_unmagnified_reading; //also reference last_plot_points ( magnified ) to see if the new magnified point would be out of limits so that it will need to be placed at +/- PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED from the opposite limit it would violate 
                                       //also needed for autobalancing
#endif
    uint32_t zero_of_this_plot_linespace;
    uint32_t high_limit_of_this_plot_linespace;
} typedef magnify_adjustment_and_display_zero;

#if ( ARDUINO_ARCH_XI || ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD ) //These are the boards known to have 12 bit analog inputs
    #ifdef ANALOGINPUTBITSOFBOARD
        #undef ANALOGINPUTBITSOFBOARD
    #endif
    #define ANALOGINPUTBITSOFBOARD 12  //These boards have 12 bit
#endif

#if ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 )
    #define SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC - ANALOGINPUTBITSOFBOARD )
#else
    #define SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE 0
#endif

magnify_adjustment_and_display_zero screen_offsets_of_linespaces[ NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT ];
static bool graphline = false;
static uint32_t this_reading, this_readingTemp;
#ifdef MAGNIFICATION_FACTOR
    static uint32_t last_plot_points[ ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT ) * 2 ];
#else
    static uint32_t last_plot_points[ NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT ];
#endif
static long millis_start;
static char szFull[ ] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#ifndef NUM_OF_INBOARD_ADCS_TO_PLOT
    #define NUM_OF_INBOARD_ADCS_TO_PLOT 0
#elif ( 1 > NUM_OF_INBOARD_ADCS_TO_PLOT + 0 )
    #undef NUM_OF_INBOARD_ADCS_TO_PLOT
    #define NUM_OF_INBOARD_ADCS_TO_PLOT 0
#endif
#define HEIGHT_OF_A_PLOT_LINESPACE ( ( uint32_t )pow( 2, HIGHESTBITRESFROMHIGHESTSENSIADDONADC ) )
#define HALF_HEIGHT_OF_A_PLOT_LINESPACE ( HEIGHT_OF_A_PLOT_LINESPACE / 2 )
#if ( NUM_OF_INBOARD_ADCS_TO_PLOT == 0 )
    #define PLOTTERMAXSCALE ( HEIGHT_OF_A_PLOT_LINESPACE * ( ( uint32_t )( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT ) ) )
#elif defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 ) && ( NUM_OF_INBOARD_ADCS_TO_PLOT > 1 )
    #define PLOTTERMAXSCALE ( HEIGHT_OF_A_PLOT_LINESPACE * ( ( uint32_t )( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT - 1 ) ) )
#else
    #define PLOTTERMAXSCALE ( HEIGHT_OF_A_PLOT_LINESPACE * ( ( uint32_t )( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT ) ) )
#endif

//#if not defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET || ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT == 0 ) || ( NUM_OF_INBOARD_ADCS_TO_PLOT != 2 )
//    #define PLOTTERMAXSCALE ( HEIGHT_OF_A_PLOT_LINESPACE * ( ( uint32_t )( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT ) ) )
//#else
//    #define PLOTTERMAXSCALE ( HEIGHT_OF_A_PLOT_LINESPACE * ( ( uint32_t )( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT - 1 ) ) )
//#endif
#define HundredthPLOTTERMAXSCALE ( PLOTTERMAXSCALE / 100 );
#ifndef SAMPLE_TIMES
    #define SAMPLE_TIMES 1
#elif ( 1 > SAMPLE_TIMES + 0 )
    #undef SAMPLE_TIMES
    #define SAMPLE_TIMES 1
#endif
/*  development notes to self:
Is FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET (1, 2, 3, etc. ) ever needed?

AUTO_BRIDGE_BALANCING means both initial setup & ongoing adjustment: initial adjustment means setting pots to EEPROM settings or defines settings and for 
sweet spot ADCs it fines tunes during setup and re-stores that in EEPROM

defined AUTO_BRIDGE_BALANCING should only be allowed to be the case 
    with NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0
    and USING_LM334_WITH_MCP4162_POT_BANKS (?inboard pairs 1, 2, 3, etc. or ADDONs n... ) //Besides being used for auto-balancing, these could be used just to allow a wider range of plant tissue conductance.
    and FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET (but is this moot?).  The alternative 
    to this condition in isolation from bridge balancing is just adjusting to plant resistance instead of 

Bridge balancing should not be needed with those ADCs that need a sweet spot to work.  That sweet spot could be hard wired or manual pot adjusted and only 
bridge LEG adjusting should get done????
With those ADCs, the digipots should be able to be put in serial and assigned to
Except that the tempco of the LM334 will then all be on only one leg, thus not able to be balanced out to cancel out, so never mind....
Possibilities:
AUTO...BALANCING is invalid w/o ...POTS and ...PARALLELed > 0
not USING_LM334_WITH_MCP4162_POT_BANKS - invalidates AUTO...BALANCING
                                  - if inputs are ...PARALLELed > 0 and ...ADDONs exist and INBOARDS > 0, it is for manual pot manipulations while viewing 
                                    traces
                                                             
So: - define ...PARALLELed = 0 if it is undefined
    - undefine USING...POTS if USING...POTS == 0 or if ...INBOARD == 0 and not AUTO...BALANCING and #defined LEAVEPOTVALUESALONEDURINGSETUP and #not defined DEBUG, the digipots may be useful in debug then re-compile but why would they need to be
    - undefine AUTO...BALANCING if not USING...POTS, or if not ...ADDONs, or if ...PARALLELed == 0
    - define ...PARALLELed = 0 if ...ADDONs == 0, or if not AUTO...BALANCING and ...INBOARD == 0 while USING...POTS
    
 */
#ifdef USING_LM334_WITH_MCP4162_POT_BANKS
    void setPotValue( uint8_t digital_pot_pin, uint16_t value )
    {
        for( uint8_t index = 0; index < NUM_OF_DIGIPOTS_PER_BANK * USING_LM334_WITH_MCP4162_POT_BANKS; index++ )
        {
            if( digital_pot_pin == digipot_pins[ index ] )
            {
                digipot_values[ index ] = value < MAXPOTVALUE ? value : MAXPOTVALUE;
                value = digipot_values[ index ];
                break;
            }
        }
//To accommodate multiple banks of digipots, replace the digitalWrite commands with decoding algorithm, and add dual 74LV138 decoding;i.e. lines 1-3 to the first 74LV138, lines 4-6 to the second which allows 8 banks of up to 7 devices each or 7 banks up to 8 device each.  Choose 8 banks, 7 devices:
//Downside: all bank selecting pins must originate from one and the same port so port manipulation can be used to eliminate spurious bank cross-selections that would occur if bank selecting had to be done just one pin at a time
//Additional advantage: that scheme can also be used without the dual 74LV138 decoding circuitry, so TODO: convert sketch to utilize this scheme
/*
 * #define DIGITAL_POT_A0_PIN = n ( 0 - 5 for 6 pots/leg )
 * #define BANK_PORT = n ( port address )
 * #define BANK_PORT_DDR = n ( DDR address )
 * #define BIT_POSITION_WITHIN_PORT_OF_BANK_SELECT_A[ 0 ] = n ( 0 - 7 )
 * etc. as needed; in setup() configure DDR register for the BANK_PORT making the pins outputs and all 1's just so the banks.  Other supporting code is required as well to simulate persistency, etc.
port/register commands must be used selecting the bank with this scheme
digitalWrite( DIGITAL_POT_A0_PIN, ( digital_pot_pin & B1 ) ? 1 : 0 );
digitalWrite( DIGITAL_POT_A1_PIN, ( digital_pot_pin & B10 ) ? 1 : 0 );
digitalWrite( DIGITAL_POT_A2_PIN, ( digital_pot_pin & B100 ) ? 1 : 0 );
uint8_t pin_mask_to_bank = B11000111; //initialize the address bits to zeroes

for( uint8_t whichbit = 0; whichbit < 3; whichbit++ )
    bitWrite( pin_mask_to_bank, BIT_POSITION_WITHIN_PORT_OF_BANK_SELECT_A[ whichbit ], bitRead( digital_pot_pin, whichbit ) );
       OR
pin_mask_to_bank |= ( digital_pot_pin & B1000 ? 1 : 0 ) << BIT_POSITION_WITHIN_PORT_OF_BANK_SELECT_A[ 0 ];
pin_mask_to_bank |= ( digital_pot_pin & B10000 ? 1 : 0 ) << BIT_POSITION_WITHIN_PORT_OF_BANK_SELECT_A[ 1 ];
pin_mask_to_bank |= ( digital_pot_pin & B100000 ? 1 : 0 ) << BIT_POSITION_WITHIN_PORT_OF_BANK_SELECT_A[ 2 ];

BANK_PORT &= pin_mask_to_bank; //ANDs a 3 line address into pins (pulls down the zeroes, leaves the ones high)
SPI.transfer( ( value & 0x100 ) ? 1 : 0 );
SPI.transfer( value & 0xFF ); // send value (0~255)
BANK_PORT &= ~pin_mask_to_bank;
//Alternate code for line above:
//pin_mask_to_bank = 0xFF;
pin_mask_to_bank &= 0 << BIT_POSITION_WITHIN_PORT_OF_BANK_SELECT_A[ 0 ];
pin_mask_to_bank &= 0 << BIT_POSITION_WITHIN_PORT_OF_BANK_SELECT_A[ 1 ];
pin_mask_to_bank &= 0 << BIT_POSITION_WITHIN_PORT_OF_BANK_SELECT_A[ 2 ];
*/
      digitalWrite( digital_pot_pin, LOW );
      SPI.transfer( ( value & 0x100 ) ? 1 : 0 );
      SPI.transfer( value & 0xff ); // send value (0~255)
      digitalWrite( digital_pot_pin, HIGH );
    }
    
    void offsetPotValue( uint8_t digital_pot_pin, int16_t offsetvalue )
    {
    #ifdef DEBUG
//        offsetvalue += 40;  //A magnifier for troubleshooting
        while ( !Serial );
        Serial.print( F( "Digi pot on pin " ) );
    #endif
        for( uint8_t index = 0; index < NUM_OF_DIGIPOTS_PER_BANK * USING_LM334_WITH_MCP4162_POT_BANKS; index++ )
        {
            if( digital_pot_pin == digipot_pins[ index ] )
            {
                if( offsetvalue < 0 ) offsetvalue = max( offsetvalue, 0 - digipot_values[ index ] ); else if( offsetvalue > 0 ) offsetvalue = min( offsetvalue, MAXPOTVALUE - digipot_values[ index ] ); digipot_values[ index ] += offsetvalue; offsetvalue = digipot_values[ index ]; 
                break;
            }
        }
        #ifdef DEBUG
            while ( !Serial );
            Serial.print( digital_pot_pin );
            Serial.print( F( " getting " ) );
            Serial.print( offsetvalue );
        #endif
      digitalWrite( digital_pot_pin, LOW );
      SPI.transfer( ( offsetvalue & 0x100 /*This restricts data to step numbers only.  Maybe you'd want to open it up for other type data...*/) ? 1 : 0 );
      SPI.transfer( offsetvalue & 0xff ); // send value (0~255)
      digitalWrite( digital_pot_pin, HIGH );
    #ifdef DEBUG
        while ( !Serial );
        Serial.print( F( ". Digi pot on pin " ) );
        Serial.print( digital_pot_pin );
        Serial.print( F( " got a " ) );
        Serial.println( offsetvalue );
    #endif
    }

    bool adjust_values_for_this_leg( uint8_t MSB_pot_pin, uint16_t* MSB_pot_value, uint8_t MID_pot_pin, uint16_t* MID_pot_value, uint8_t LSB_pot_pin, uint16_t* LSB_pot_value, bool pos_or_neg = true ) //default direction will be positive
    {
        #ifdef DEBUG
            while ( !Serial );
            Serial.print( F( "adjust_values_for_this_leg called on " ) );
            Serial.print( MSB_pot_pin );
            Serial.print( F( " going " ) );
            Serial.println( pos_or_neg ? "up": "down");
        #endif
        //if going up and total_value_coarse is already MAXPOTVALUE * 2, add one to value_fine if it is less than MAXPOTVALUE, else return false; save new value; return true
        //if going up still and either coarse value is MAXPOTVALUE, only increment the other value, save new, return true;
        //if going up and neither coarse value is MAXPOTVALUE, increment MID with a switch statement, save new
        uint16_t total_value_coarse = *MSB_pot_value;
        total_value_coarse += *MID_pot_value;  //We abstract it this way to force MSB and MID digi pot values to conform as namesaked
        //Next lines just force significant digit compliance inside digi pots
        *MSB_pot_value = ( total_value_coarse > MAXPOTVALUE ? total_value_coarse - MAXPOTVALUE : 0 );
        *MID_pot_value = ( total_value_coarse > MAXPOTVALUE ? MAXPOTVALUE : total_value_coarse );
        *LSB_pot_value = min( MAXPOTVALUE, *LSB_pot_value );
        
        setPotValue( MSB_pot_pin, *MSB_pot_value );
        setPotValue( MID_pot_pin, *MID_pot_value );
        setPotValue( LSB_pot_pin, *LSB_pot_value );

        if( pos_or_neg ) //Positive direction == true
        {
            if( total_value_coarse >= MAXPOTVALUE * 2 )
            {
                *MSB_pot_value = *MID_pot_value = MAXPOTVALUE;
                setPotValue( MSB_pot_pin, *MSB_pot_value ); //This shouldn't do anything if the pot values conform to MSB and MID already
                setPotValue( MID_pot_pin, *MID_pot_value ); //This shouldn't do anything if the pot values conform to MSB and MID already
                setPotValue( LSB_pot_pin, ++( *LSB_pot_value ) > MAXPOTVALUE ? MAXPOTVALUE : *LSB_pot_value );
                if( *LSB_pot_value > MAXPOTVALUE ) { *LSB_pot_value = MAXPOTVALUE; return false; }
                return true;
            }
            if( *LSB_pot_value + 1 > 9 ) //This catches *LSB_pot_value having or about to have a value higher than 9 when it shouldn't.  So we cycle it down
            {
                do 
                {
                    *LSB_pot_value = ( uint16_t )( ( int16_t )*LSB_pot_value - 10 ); //Yes, this can cause an unsigned to underflow to -1
                } while( ( ++total_value_coarse < MAXPOTVALUE * 2 ) && *LSB_pot_value + 1 > 9 );

                *MSB_pot_value = ( total_value_coarse > MAXPOTVALUE ?  total_value_coarse - MAXPOTVALUE : 0 );
                *MID_pot_value = ( total_value_coarse > MAXPOTVALUE ? MAXPOTVALUE : total_value_coarse );
                setPotValue( MSB_pot_pin, *MSB_pot_value );
                setPotValue( MID_pot_pin, *MID_pot_value );
            }
            setPotValue( LSB_pot_pin, ++( *LSB_pot_value ) );
            return true;
        }

//Being told to decrement
        if( total_value_coarse == 0 && *LSB_pot_value == 0 ) return false;
        if( ( int16_t )*LSB_pot_value == 0 ) //This catches *LSB_pot_value having or about to have a value lower than 0.  So we cycle it up
        {
            *LSB_pot_value = 10;
            *MSB_pot_value = ( --total_value_coarse > MAXPOTVALUE ? total_value_coarse - MAXPOTVALUE : 0 );
            *MID_pot_value = ( total_value_coarse > MAXPOTVALUE ? MAXPOTVALUE : total_value_coarse );
            setPotValue( MSB_pot_pin, *MSB_pot_value );
            setPotValue( MID_pot_pin, *MID_pot_value );
        }
        setPotValue( LSB_pot_pin, --( *LSB_pot_value ) );
        return true;
    }

    bool adjust_whole_bridge_positive( uint8_t bank )
    {
        // If all are maxed out positive, return false
        if( ( digipot_values[ 0 + bank * NUM_OF_DIGIPOTS_PER_BANK ]  + digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] >= ( 514 + MAXPOTVALUE ) ) && \
            ( digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] == 0 ) ) return false;
//Target leg to adjust is the one that brings the negative leg closet to its midpoint: determine how far away from midpoint the negative leg is:
        if( ( ( ( digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) * MAXPOTVALUE ) + ( digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) ) > 66177 /*This is half of total resistance in terms of digi pot units*/ )
        {
            if( adjust_values_for_this_leg( digipot_pins[ 3 ], digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 4 ], digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 5 ], digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false ) ) return true;
            else return adjust_values_for_this_leg( digipot_pins[ 0 ], digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 ], digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 2 ], digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
        }
        else if( adjust_values_for_this_leg( digipot_pins[ 0 ], digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 ], digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 2 ], digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false ) ) return true;
        return adjust_values_for_this_leg( digipot_pins[ 3 ], digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 4 ], digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 5 ], digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
    }
    
    bool adjust_whole_bridge_negative( uint8_t bank ) //bank not utilized yet
    { //Determine which leg is closest to Vcc/2 and tweak that first.  If all pots are maxed (positive leg to negative and negative leg to positive) return false
        if( ( digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] == 0 ) && \
            ( digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] >= MAXPOTVALUE * 2 ) && ( digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > 256 ) ) return false;
//Target leg to adjust is the one that brings the negative leg closet to its midpoint: determine how far away from midpoint the negative leg is:
        if( ( ( ( digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) * MAXPOTVALUE ) + ( digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) ) < 66177 /*This is half of total resistance in terms of digi pot units*/ )
        {
            if( adjust_values_for_this_leg( digipot_pins[ 3 ], digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 4 ], digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 5 ], digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) ) return true;
            else return adjust_values_for_this_leg( digipot_pins[ 0 ], digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 ], digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 2 ], digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
        }
        else if( adjust_values_for_this_leg( digipot_pins[ 0 ], digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 ], digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 2 ], digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ) ) return true;
        return adjust_values_for_this_leg( digipot_pins[ 3 ], digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 4 ], digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 5 ], digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
    }
#endif

void plotvaluesforalltraces( bool actuals = false )                  //If we don't execute the following construct, the signal traces will lag behind the graphline
{//conditional last_plot_points indexes from range NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT (guessing): magnified traces, analog 0 & 1 which could be outside the range
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Entering plotvaluesforalltraces" ) );
#endif
    Serial.print( F( " " ) );
    for( uint8_t i = 0; i < NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT; i++ )
    {
#ifdef MAGNIFICATION_FACTOR
//        Serial.print( actuals ? last_plot_points[ i * 2 ] + screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace : screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace );
        Serial.print( actuals ? last_plot_points[ i * 2 ] + screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace : 0 ); //I think this looks better than the line above
        Serial.print( F( " " ) );
        #if defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 )
            #if ( NUM_OF_INBOARD_ADCS_TO_PLOT == 1 )
                if( i > 0 )
            #elif ( NUM_OF_INBOARD_ADCS_TO_PLOT > 1 )
                if( i > 1 )
            #endif
        #endif
            if( true )
            {
//                Serial.print( actuals ? last_plot_points[ ( i * 2 ) + 1 ] + screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace : screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace );
                Serial.print( actuals ? last_plot_points[ ( i * 2 ) + 1 ] + screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace : 0 ); //I think this looks better than the line above
                Serial.print( F( " " ) );
            }
#else //in #ifdef MAGNIFICATION_FACTOR construct: no magnified traces in the array
//        Serial.print( actuals ? last_plot_points[ i ] + screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace : screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace );
        Serial.print( actuals ? last_plot_points[ i ] + screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace : 0 ); //I think this looks better than the line above
        Serial.print( F( " " ) );
#endif
    }
    Serial.println();
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Leaving plotvaluesforalltraces" ) );
#endif
}

void plot_timing_line_going_up( bool traces_already_initialized_to_valid_readings = true )
{
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Entering plot_timing_line_going_up" ) );
#endif
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
#if defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT ) && ( NUM_OF_INBOARD_ADCS_TO_PLOT > 1 )
    for( uint8_t i = NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT - 1; i > 0; i-- )
    {
        if( i > 1 ) //plot only double instances until the last one
#else
    for( uint8_t i = NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT - 1; i != 255; i-- )
    {
        if( i > 0 ) //plot only double instances until the last one
#endif
        {
            Serial.print( screen_offsets_of_linespaces[ i ].high_limit_of_this_plot_linespace );
            #ifdef DEBUG
                while( !Serial ) ; 
                Serial.println( F( "Line 508" ) );
            #endif
            plotvaluesforalltraces( traces_already_initialized_to_valid_readings );
            #ifdef DEBUG
                while( !Serial ) ; 
                Serial.println( F( "Line 513" ) );
            #endif
        }
        Serial.print( screen_offsets_of_linespaces[ i ].high_limit_of_this_plot_linespace );
        #ifdef DEBUG
            while( !Serial ) ; 
            Serial.print( F( "Line 519 i=" ) );
            Serial.println( i );
        #endif
        plotvaluesforalltraces( traces_already_initialized_to_valid_readings );
        #ifdef DEBUG
            while( !Serial ) ; 
            Serial.print( F( "Line 524, i=" ) );
            Serial.println( i );
        #endif
    }
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Leaving plot_timing_line_going_up" ) );
#endif
}

uint16_t bestoffour( uint8_t analog_pin_array_index = 0 )
{ //remove from consideration the max and min, then return avg of remaining two  //Re-suse some variables not otherwise in use right now
    uint16_t value = analogRead( *( A_PIN_ARRAY + analog_pin_array_index ) );
    delay( 2 );
    uint16_t value1 = analogRead( *( A_PIN_ARRAY + analog_pin_array_index ) );
    delay( 2 );
    uint16_t value2 = analogRead( *( A_PIN_ARRAY + analog_pin_array_index ) );
    delay( 2 );
    uint16_t val4 = analogRead( *( A_PIN_ARRAY + analog_pin_array_index ) );
    return ( uint16_t )( ( ( long )( value + value1 + value2 + val4 ) ) - ( max( max( max( value, value1 ), value2 ), val4 ) + min( min( min( value, value1 ), value2 ), val4 ) ) ) / 2;
}

uint16_t BestGuessAnalogInputreading( uint8_t analog_pin_array_index, bool finetune = false, uint8_t bank = 0 )
{
    uint16_t value, value1;
    unsigned long runningtotal = 0;
    uint8_t times = 0;
    do
    {
        value = bestoffour( analog_pin_array_index + ( bank * 2 ) );
        value1 = bestoffour( analog_pin_array_index + ( bank * 2 ) );
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

#if defined USING_LM334_WITH_MCP4162_POT_BANKS
static uint8_t set_digipots_step = 0;

bool set_digipots_reference_leg( bool just_perform_one_step = false, uint8_t bank = 0 ) //All this does is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
{
    static uint8_t stepsize;
//#error Determine why this loops through steps 4,5 without changes getting made starting with line 894.
#ifdef DEBUG
    while ( !Serial && ( millis() - millis_start < 8000 ) );
    Serial.print( F( "Setting up digipots: bridge leg 0 = " ) );
    Serial.print( analogRead( *( A_PIN_ARRAY + 0 + bank ) ) ); //This array was not initialized for a digipot array but should have been.  Is currently only defined for displaying pins
    Serial.print( F( ", bridge leg 1 = " ) );
    Serial.print( analogRead( *( A_PIN_ARRAY + 1 + bank ) ) );
    Serial.print( F( ", set_digipots_step = " ) );
    Serial.print( set_digipots_step );
    Serial.print( F( ", stepsize = " ) );
    Serial.println( stepsize );
#endif
if( set_digipots_step != 0 )
{
    if( set_digipots_step == 1 ) goto set_digipots_step1;
    if( set_digipots_step == 2 ) goto set_digipots_step2;
    if( set_digipots_step == 3 ) goto set_digipots_step3;
    if( set_digipots_step == 4 ) goto set_digipots_step4;
    if( set_digipots_step == 5 ) goto set_digipots_step5;
    if( set_digipots_step == 6 ) goto set_digipots_step6;
    if( set_digipots_step == 7 ) goto set_digipots_step7;
    if( set_digipots_step == 8 ) goto set_digipots_step8;
    if( set_digipots_step == 9 ) goto set_digipots_step9;
//    if( set_digipots_step == 10 ) goto set_digipots_step10;
}

/*Next is where the Wheatstone bridge reference leg output (that connects to negative input of highest sensi ADC) is set to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG voltage level*/
    stepsize = 10;
    static uint16_t startpoint1;
    static uint16_t startpoint2;

    while( ( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        {
            startpoint1 = digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            if( digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 )
            {
                setPotValue( digipot_pins[ 3 + ( bank * 2 ) ], digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
                if( just_perform_one_step )
                {
                    set_digipots_step = 1;
                    return false;
                }
set_digipots_step1:;
            }
            if( digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 )
            {
                setPotValue( digipot_pins[ 4 + ( bank * 2 ) ], digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
                if( just_perform_one_step )
                {
                    set_digipots_step = 2;
                    return false;
                }
set_digipots_step2:;
            }
        }
        setPotValue( digipot_pins[ 3 + ( bank * 2 ) ], startpoint1 );
        setPotValue( digipot_pins[ 4 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
    }
    while( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
    {
        adjust_values_for_this_leg( digipot_pins[ 3 + ( bank * 2 ) ], &digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 4 + ( bank * 2 ) ], &digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 5 + ( bank * 2 ) ], &digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
        if( just_perform_one_step )
        {
            set_digipots_step = 3;
            return false;
        }
set_digipots_step3:;
    }
    stepsize = 10;

    while( ( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) && ( stepsize > 0 ) )
    {//FIXME this loop can never be false when the startpoints get restored?
        while( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        {
            startpoint1 = digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            if( digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 )
            {
                setPotValue( digipot_pins[ 3 + ( bank * 2 ) ], digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
                if( just_perform_one_step )
                {
                    set_digipots_step = 4;
                    return false;
                }
set_digipots_step4:;
            }
            if( digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 )
            {
                setPotValue( digipot_pins[ 4 + ( bank * 2 ) ], digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
                if( just_perform_one_step )
                {
                    set_digipots_step = 5;
                    return false;
                }
set_digipots_step5:; //This bottoms out as far as setting digipots
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "Line 897, BestGuessAnalogInputreading( 1 + ( bank * 2 ) )= " ) );
    Serial.print( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) );
    Serial.print( F( ", digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ]= " ) );
    Serial.print( digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] ); //These setting values increase without end FIXME
    Serial.print( F( ", digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] = " ) );
    Serial.print( digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
    Serial.print( F( ", digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] = " ) );
    Serial.print( digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
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
        setPotValue( digipot_pins[ 3 + ( bank * 2 ) ], startpoint1 );
        setPotValue( digipot_pins[ 4 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "new stepsize = " ) );
    Serial.println( stepsize );
#endif
    }
    while( BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
    {
        adjust_values_for_this_leg( digipot_pins[ 3 + ( bank * 2 ) ], &digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 4 + ( bank * 2 ) ], &digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 5 + ( bank * 2 ) ], &digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
        if( just_perform_one_step )
        {
            set_digipots_step = 6;
            return false;
        }
set_digipots_step6:;
    }
//Converge by two consecutive readings
    do
    {//This leg is the  reference, so we need to take a little extra time: avg out more samples
        if( BestGuessAnalogInputreading( 1 + ( bank * 2 ), FINETUNE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        {
            adjust_values_for_this_leg( digipot_pins[ 3 + ( bank * 2 ) ], &digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 4 + ( bank * 2 ) ], &digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 5 + ( bank * 2 ) ], &digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
        }
        else if( BestGuessAnalogInputreading( 1 + ( bank * 2 ), FINETUNE ) /*read it again*/ < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        {
            adjust_values_for_this_leg( digipot_pins[ 3 + ( bank * 2 ) ], &digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 4 + ( bank * 2 ) ], &digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 5 + ( bank * 2 ) ], &digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
        }
        if( just_perform_one_step )
        {
            set_digipots_step = 7;
            return false;
        }
set_digipots_step7:
        if( BestGuessAnalogInputreading( 1 + ( bank * 2 ), FINETUNE ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) continue;
        if( just_perform_one_step )
        {
            set_digipots_step = 8;
            return false;
        }
set_digipots_step8:;
    }while( BestGuessAnalogInputreading( 1 + ( bank * 2 ), FINETUNE ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );

/* This notion is for if a single reference bank leg of the first digipot bank suffices for the reference legs of all ADDON digipot banks to minimize parts count of multiple digipot bank systems.  Is not being pursued at this time....
    static uint8_t channel;
    for( channel = 0; channel < NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT; channel++ )
    {
        set_bridge_leg_signal_input( channel );
        if( just_perform_one_step )
        {
            set_digipots_step = 10;
            return false;
        }
*/
set_digipots_step9:;
/*    }*/
    set_digipots_step = 0;
    return true;
}
void read_and_plot_from_all_ADCs_in_and_outboard( bool );

bool match_bridge_leg_signal_to_reference( uint8_t bank )
{//BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE
    uint16_t stepsize = 10;    
    uint16_t startpoint1;
    uint16_t startpoint2;
    while( ( BestGuessAnalogInputreading( bank * 2 ) < BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * 2 ) < BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
        {
            startpoint1 = digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            if( digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 ) setPotValue( digipot_pins[ 0 + ( bank * 2 ) ], digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
            if( digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 ) setPotValue( digipot_pins[ 1 + ( bank * 2 ) ], digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
            BestGuessAnalogInputreading( bank * 2 );
        }
        setPotValue( digipot_pins[ 0 + ( bank * 2 ) ], startpoint1 );
        setPotValue( digipot_pins[ 1 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
    }
//Converge on BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) in smaller steps
    while( BestGuessAnalogInputreading( bank * 2 ) < BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
    {
        adjust_values_for_this_leg( digipot_pins[ 0 + ( bank * 2 ) ], &digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 + ( bank * 2 ) ], &digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 2 + ( bank * 2 ) ], &digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
    }
    stepsize = 10;
    while( ( BestGuessAnalogInputreading( bank * 2 ) > BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * 2 ) > BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
        {
            startpoint1 = digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            setPotValue( digipot_pins[ 0 + ( bank * 2 ) ], digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
            setPotValue( digipot_pins[ 1 + ( bank * 2 ) ], digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
            BestGuessAnalogInputreading( bank * 2 );
        }
        setPotValue( digipot_pins[ 0 + ( bank * 2 ) ], startpoint1 );
        setPotValue( digipot_pins[ 1 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
    }

//Converge on BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) in smaller steps
    while( BestGuessAnalogInputreading( bank * 2 ) > BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
    {
        adjust_values_for_this_leg( digipot_pins[ 0 + ( bank * 2 ) ], &digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 + ( bank * 2 ) ], &digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 2 + ( bank * 2 ) ], &digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
    }
//Converge by one or two consecutive readings
    do
    {
        if( BestGuessAnalogInputreading( bank * 2 ) > BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
        {
            adjust_values_for_this_leg( digipot_pins[ 0 + ( bank * 2 ) ], &digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 + ( bank * 2 ) ], &digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 2 + ( bank * 2 ) ], &digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
        }
        else if( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ < BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
        {
            adjust_values_for_this_leg( digipot_pins[ 0 + ( bank * 2 ) ], &digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 + ( bank * 2 ) ], &digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 2 + ( bank * 2 ) ], &digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
        }
        if( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ != BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE ) continue;
        
    }while( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ != BestGuessAnalogInputreading( 1 + ( bank * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE );

//If ADDON ADC affiliated with this bank reads above zero on avg, lower the signal leg and vice versa
    //refresh the readings
//    read_and_plot_from_all_ADCs_in_and_outboard( true ); // I would think the operator would appreciate seeing something like this during calibration
/*    Fine tune into perfect balance:

//    bool adjust_values_for_this_leg( uint8_t MSB_pot_pin, uint16_t* MSB_pot_value, uint8_t MID_pot_pin, uint16_t* MID_pot_value, uint8_t LSB_pot_pin, uint16_t* LSB_pot_value, bool pos_or_neg = true ) //default direction will be positive
    //see what ADDON ADC affiliated with this bank reads avg
#ifdef MAGNIFICATION_FACTOR
    while( last_plot_points[ bank * 2 ] < 0 )// + screen_offsets_of_linespaces[ channel ].zero_of_this_plot_linespace;
#else
    while( last_plot_points[ bank ] < 0 )// + screen_offsets_of_linespaces[ channel ].zero_of_this_plot_linespace;
#endif
    {//reading is too high, lower the leg
        if( adjust_values_for_this_leg( *( A_PIN_ARRAY + 0 + ( bank * 2 ) ), &digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], *( A_PIN_ARRAY + 1 + ( bank * 2 ) ), &digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], *( A_PIN_ARRAY + 2 + ( bank * 2 ) ), &digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false ) == false ) break;
        read_and_plot_from_all_ADCs_in_and_outboard( true ); // I would think the operator would appreciate seeing something like this during calibration
    }
#ifdef MAGNIFICATION_FACTOR
     while( last_plot_points[ bank * 2 ] > 0 )// + screen_offsets_of_linespaces[ channel ].zero_of_this_plot_linespace;
#else
    while( last_plot_points[ bank ] > 0 )// + screen_offsets_of_linespaces[ channel ].zero_of_this_plot_linespace;
#endif
    {//reading is too low, raise the leg
        if( adjust_values_for_this_leg( *( A_PIN_ARRAY + 0 + ( bank * 2 ) ), &digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], *( A_PIN_ARRAY + 1 + ( bank * 2 ) ), &digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], *( A_PIN_ARRAY + 2 + ( bank * 2 ) ), &digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true ) == false ) break;
        read_and_plot_from_all_ADCs_in_and_outboard( true ); // I would think the operator would appreciate seeing something like this during calibration
    }
*/
    return true;
    return false;
}

void set_bridge_leg_signal_input( uint8_t bank ) //When bank starts being used in the future, the digipots are what needs to get changed herein
{//BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE
    uint16_t stepsize = 10;    
    uint16_t startpoint1;
    uint16_t startpoint2;
    while( ( BestGuessAnalogInputreading( bank * 2 ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * 2 ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
        {
            startpoint1 = digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            if( digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 ) setPotValue( digipot_pins[ 0 + ( bank * 2 ) ], digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
            if( digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] > stepsize - 1 ) setPotValue( digipot_pins[ 1 + ( bank * 2 ) ], digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] - stepsize );
            BestGuessAnalogInputreading( bank * 2 );
        }
        setPotValue( digipot_pins[ 0 + ( bank * 2 ) ], startpoint1 );
        setPotValue( digipot_pins[ 1 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
    }
//Converge on COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG in smaller steps
    while( BestGuessAnalogInputreading( bank * 2 ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
    {
        adjust_values_for_this_leg( digipot_pins[ 0 + ( bank * 2 ) ], &digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 + ( bank * 2 ) ], &digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 2 + ( bank * 2 ) ], &digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
    }
    stepsize = 10;
    while( ( BestGuessAnalogInputreading( bank * 2 ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * 2 ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
        {
            startpoint1 = digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            startpoint2 = digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ];
            //Decrease digipot values as long as they respond right
            if( ( digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) && ( digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] <= stepsize - 1 ) ) break;
            setPotValue( digipot_pins[ 0 + ( bank * 2 ) ], digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
            setPotValue( digipot_pins[ 1 + ( bank * 2 ) ], digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] + stepsize );
            BestGuessAnalogInputreading( bank * 2 );
        }
        setPotValue( digipot_pins[ 0 + ( bank * 2 ) ], startpoint1 );
        setPotValue( digipot_pins[ 1 + ( bank * 2 ) ], startpoint2 );
        stepsize >>= 1;
    }

//Converge on COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG in smaller steps
    while( BestGuessAnalogInputreading( bank * 2 ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
    {
        adjust_values_for_this_leg( digipot_pins[ 0 + ( bank * 2 ) ], &digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 + ( bank * 2 ) ], &digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 2 + ( bank * 2 ) ], &digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
    }
//Converge by one or two consecutive readings
    do
    {
        if( BestGuessAnalogInputreading( bank * 2 ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
        {
            adjust_values_for_this_leg( digipot_pins[ 0 + ( bank * 2 ) ], &digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 + ( bank * 2 ) ], &digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 2 + ( bank * 2 ) ], &digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], true );
        }
        else if( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE )
        {
            adjust_values_for_this_leg( digipot_pins[ 0 + ( bank * 2 ) ], &digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], digipot_pins[ 1 + ( bank * 2 ) ], &digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ],  digipot_pins[ 2 + ( bank * 2 ) ], &digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ], false );
        }
        if( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE ) continue;
        
    }while( BestGuessAnalogInputreading( bank * 2 ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE );
}
#endif

static uint32_t tracespace_to_skip_when_repositioning, negative_tracespace_to_skip_when_repositioning;

#if ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 ) && defined AUTO_BRIDGE_BALANCING
int plot_the_normal_and_magnified_signals( uint8_t channel )
#else
void plot_the_normal_and_magnified_signals( uint8_t channel )
#endif
{
#ifdef DEBUG
        while( !Serial );
        Serial.println();
        Serial.print( F( "plot line index " ) );
        Serial.println( channel ); 
#endif
    this_reading = this_reading / SAMPLE_TIMES;
    this_reading = this_reading < HEIGHT_OF_A_PLOT_LINESPACE ? this_reading : HEIGHT_OF_A_PLOT_LINESPACE;
#ifdef MAGNIFICATION_FACTOR
        last_plot_points[ channel * 2 ] = this_reading;// + screen_offsets_of_linespaces[ channel ].zero_of_this_plot_linespace;
#else
        last_plot_points[ channel ] = this_reading;// + screen_offsets_of_linespaces[ channel ].zero_of_this_plot_linespace;
#endif
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( this_reading + screen_offsets_of_linespaces[ channel ].zero_of_this_plot_linespace ); //This is color one
    Serial.print( F( " " ) );
#ifdef MAGNIFICATION_FACTOR
    uint32_t this_plot_point;
    #if defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 )
        #if ( NUM_OF_INBOARD_ADCS_TO_PLOT == 1 )
            if( channel < 1 ) goto AFTER_THE_MAGNIFIED_PLOTTED;//if this is one of the two parallel traces, skip the magnified view
        #elif ( NUM_OF_INBOARD_ADCS_TO_PLOT >= 2 )
            if( channel < 2 ) goto AFTER_THE_MAGNIFIED_PLOTTED;//if this is one of the two parallel traces, skip the magnified view
        #endif
    #endif
    //Next lines plot a magnified version.  First, magnify_adjustment is determined

//Next we multiply the difference between previous_unmagnified_reading and this one, and see if it would take the trace out of bounds
//Derive the next plot point for the case of current this_reading being less than or equal to the last this_reading
    if( this_reading > screen_offsets_of_linespaces[ channel ].previous_unmagnified_reading ) //new reading is higher than previous
    {
        this_plot_point = last_plot_points[ ( channel * 2 ) + 1 ] + ( ( this_reading - screen_offsets_of_linespaces[ channel ].previous_unmagnified_reading ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
        if( this_plot_point > HEIGHT_OF_A_PLOT_LINESPACE ) //new plot point is higher than upper limit
            this_plot_point = tracespace_to_skip_when_repositioning;
    }
    else if( ( screen_offsets_of_linespaces[ channel ].previous_unmagnified_reading - this_reading ) * MAGNIFICATION_FACTOR > last_plot_points[ ( channel * 2 ) + 1 ] )
        this_plot_point = negative_tracespace_to_skip_when_repositioning;
    else
        this_plot_point = last_plot_points[ ( channel * 2 ) + 1 ] - ( ( screen_offsets_of_linespaces[ channel ].previous_unmagnified_reading - this_reading ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
    Serial.print( screen_offsets_of_linespaces[ channel ].zero_of_this_plot_linespace + this_plot_point ); 
    Serial.print( F( " " ) );
    last_plot_points[ ( channel * 2 ) + 1 ] = this_plot_point;
AFTER_THE_MAGNIFIED_PLOTTED:
#endif
screen_offsets_of_linespaces[ channel ].previous_unmagnified_reading = this_reading;
#if ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 ) && defined AUTO_BRIDGE_BALANCING
    return BestGuessAnalogInputreading( 1 + ( ( channel - 2 ) * 2 ) ) + BIAS_TO_APPLY_TO_SIGNAL1_TO_CENTER_TRACE - BestGuessAnalogInputreading( ( channel - 2 ) * 2 );
#endif
}

#if defined ( POTTESTWOBBLEPOSITIVE ) || defined ( POTTESTWOBBLENEGATIVE )
static bool potwobbledirection = true;
static uint8_t wobbleloops = 0;
void wobble( void )
{ //Adjust active code to amount of wobble you need at the moment
#ifdef POTTESTWOBBLEPOSITIVE
//        offsetPotValue( digipot_pins[ 0 + ( POTTESTWOBBLEPOSITIVE * 2 ) ], potwobbledirection ? 1 : -1 );
//        offsetPotValue( digipot_pins[ 1 + ( POTTESTWOBBLEPOSITIVE * 2 ) ], potwobbledirection ? 1 : -1 );
        offsetPotValue( digipot_pins[ 2 + ( POTTESTWOBBLEPOSITIVE * 2 ) ], potwobbledirection ? 1 : -1 );
#endif
#ifdef POTTESTWOBBLENEGATIVE
//        offsetPotValue( digipot_pins[ 3 + ( POTTESTWOBBLENEGATIVE * 2 ) ], potwobbledirection ? -1 : 1 );
//        offsetPotValue( digipot_pins[ 4 + ( POTTESTWOBBLENEGATIVE * 2 ) ], potwobbledirection ? -1 : 1 );
        offsetPotValue( digipot_pins[ 5 + ( POTTESTWOBBLENEGATIVE * 2 ) ], potwobbledirection ? -1 : 1 );
#endif
    potwobbledirection = !potwobbledirection;
}
#endif

#ifdef AUTO_BRIDGE_BALANCING
    static uint16_t counter_for_trace_out_of_range_too_long[ NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT ]; //This is to prevent infinite loop with AUTO_BRIDGE_BALANCING
#endif

void read_and_plot_from_all_ADCs_in_and_outboard( bool during_setup = false )
{
#if ( NUM_OF_INBOARD_ADCS_TO_PLOT > 0 ) //plot the inboard analogs first and above
    for( uint8_t which_ADC_subunit = 0; which_ADC_subunit < NUM_OF_INBOARD_ADCS_TO_PLOT; which_ADC_subunit++ )
    {
        #ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
//                    Serial.print( F( "A_PIN_ARRAY = " ) );
//                    Serial.println( (unsigned long)A_PIN_ARRAY );
            Serial.print( F( "Reading pin " ) );
            Serial.print( *( A_PIN_ARRAY + which_ADC_subunit ) );
            Serial.print( F( ", level appearing as " ) );
            Serial.print( analogRead( *( A_PIN_ARRAY + which_ADC_subunit ) ) );
            if( which_ADC_subunit == 0 )
            {
                Serial.print( F( ", SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE " ) );
                Serial.println( SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
            }
            else Serial.println();
        #endif
        this_reading = analogRead( *( A_PIN_ARRAY + which_ADC_subunit ) );
        #ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
            Serial.print( F( "Value was " ) );
            Serial.print( this_reading );;
        #endif

        for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
        {
            #if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
                            delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
            #endif
            #if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
                            delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
            #endif
            this_reading += analogRead( *( A_PIN_ARRAY + which_ADC_subunit ) );
        }
        #ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
            Serial.print( F( ".  Done reading pin " ) );
            Serial.print( *( A_PIN_ARRAY + which_ADC_subunit ) );
            Serial.print( F( ", " ) );
            Serial.print( SAMPLE_TIMES );
            Serial.print( F( " times, total this_reading now " ) );
            Serial.print( this_reading );
            Serial.print( F( " which should average to " ) );
            Serial.print( this_reading / SAMPLE_TIMES );
            Serial.println( F( ", now plotting one inboard analog input with magnified version offset for proper positioning:" ) );
        #endif
        /*value = */ this_reading <<= SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
        plot_the_normal_and_magnified_signals( which_ADC_subunit );
        #ifdef DEBUG
            Serial.println();
        #endif
    }
#endif

#if ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 )
    for( uint8_t which_ADC_subunit = 0; which_ADC_subunit < NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT; which_ADC_subunit++ )
    {
        #ifdef USING_LM334_WITH_MCP4162_POT_BANKS 
Start_of_addon_ADC_acquisition:
            bool overscale_is_unfixable = false;
            while( true ) //comes back to here if this_reading overscales
            {
        #endif
        #if ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 11 ) || ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 15 )
            this_reading = ads.readADC_SingleEnded( which_ADC_subunit );
            while( this_reading > HEIGHT_OF_A_PLOT_LINESPACE ) //TODO: verify the need for this check
            {
                this_reading = ads.readADC_SingleEnded( which_ADC_subunit );
            }
        #else
            #ifdef DIFFERENTIAL
                #if ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC < 17 )
                    this_reading = CONVERTTWOSCOMPTOSINGLEENDED( ( which_ADC_subunit == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), ( uint32_t )(  - 1 ), HEIGHT_OF_A_PLOT_LINESPACE >> 1 );  // Convert to single-ended style
                #else
                    #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == HX711 )
//                                hx711.power_up();
                        this_reading = CONVERTTWOSCOMPTOSINGLEENDED( hx711.read(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x800000*/ );
//                                this_reading = 0xFFFFFF;//= hx711.read_average( 9 );
                        
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
        #ifdef USING_LM334_WITH_MCP4162_POT_BANKS 
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
                #if ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 11 ) || ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC == 15 )
                    this_readingTemp = ads.readADC_SingleEnded( which_ADC_subunit );
                    while( this_readingTemp > HEIGHT_OF_A_PLOT_LINESPACE ) this_readingTemp = ads.readADC_SingleEnded( which_ADC_subunit );
                #else
                    #ifdef DIFFERENTIAL
                        #if ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC < 17 )
                            this_readingTemp = CONVERTTWOSCOMPTOSINGLEENDED( ( which_ADC_subunit == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x8000*/ );
                        #else
                            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == HX711 )
                                #ifdef DEBUG
                                    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
//                                            Serial.println( F( "Reading differential this_readingTemp" ) );
                                #endif
//                                            hx711.power_up();
                                    this_readingTemp = CONVERTTWOSCOMPTOSINGLEENDED( hx711.read(), HEIGHT_OF_A_PLOT_LINESPACE - 1/*mask of significant bits 24 or 32, etc*/, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x800000 which bit is sign bit*/ );
//                                            this_readingTemp = 0xFFFFFF; //hx711.read_average( 9 );
                                    
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
//                                    Serial.print( F( "Read adjusted differential this_readingTemp " ) );
//                                    Serial.println( this_readingTemp );
                        #endif
                    #endif
                #endif
                this_reading += this_readingTemp;
        }
        #endif
/*
#ifdef USING_LM334_WITH_MCP4162_POT_BANKS && #ifdef DEBUG
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] = " ) );
    Serial.print( digipot_values[ 0 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
    Serial.print( F( ", digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] = " ) );
    Serial.print( digipot_values[ 1 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
    Serial.print( F( ", digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] = " ) );
    Serial.print( digipot_values[ 2 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( ", digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] = " ) );
    Serial.print( digipot_values[ 3 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
    Serial.print( F( ", digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] = " ) );
    Serial.print( digipot_values[ 4 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
    Serial.print( F( ", digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] = " ) );
    Serial.println( digipot_values[ 5 + ( bank * NUM_OF_DIGIPOTS_PER_BANK ) ] );
#endif
*/
//    #if defined USING_LM334_WITH_MCP4162_POT_BANKS && defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && defined AUTO_BRIDGE_BALANCING && not defined LEAVEPOTVALUESALONEDURINGSETUP && NUM_OF_INBOARD_ADCS_TO_PLOT < 2
//                plot_the_normal_and_magnified_signals( which_ADC_subunit + 2 );
//    #else
//#error This next construct was developed when it was in loop() only, I don't know how it will work in setup():

/*
#ifdef AUTO_BRIDGE_BALANCING
    #ifdef DEBUG
        while( !Serial );
        Serial.println( F( "Line 1296 Checking auto balance readings" ) );
    #endif
//#error Carefully examine the following lines for logic, especially the indexes :
        int reading_after_computed = plot_the_normal_and_magnified_signals( which_ADC_subunit + 2 );
        if( reading_after_computed < 0 ) // means signal leg is higher
            if( --counter_for_trace_out_of_range_too_long[ which_ADC_subunit ] < -LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
                set_bridge_leg_signal_input( which_ADC_subunit );
        else if( reading_after_computed > 0 ) //means reference leg is higher
            if( ++counter_for_trace_out_of_range_too_long[ which_ADC_subunit ] > LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
                set_bridge_leg_signal_input( which_ADC_subunit );
        else
            counter_for_trace_out_of_range_too_long[ which_ADC_subunit ] = 0;
//    #else
//        plot_the_normal_and_magnified_signals( which_ADC_subunit + NUM_OF_INBOARD_ADCS_TO_PLOT );
    #endif
*/
// INSTEAD JUST:
        plot_the_normal_and_magnified_signals( which_ADC_subunit + 2 );

//    #endif
    }
#endif
}

void setup() 
{
Serial.begin( BAUD_TO_SERIAL );//This speed is what works best with WeMos XI/TTGO XI board.
#ifdef USING_LM334_WITH_MCP4162_POT_BANKS   //This is important to put this first so LM334 get some resistance
    #if ( USING_LM334_WITH_MCP4162_POT_BANKS == 1 )
    pinMode( SS, OUTPUT );
    digitalWrite( SS, HIGH ); //Not needed by slave devices but rather by this board to make it configure itself to be master
//
    digipot_values[ 0 ] = DIGIPOT_0_B0L0_STARTVALUE;  // Storing a copy of the digi pot values in sketch makes it possible to eliminate the MISO pin connection to the data out pins of all digi pots, besides the digi pots data out may not conform strictly to SPI since the MCP41X1 version has one bidirectional data pin
    digipot_values[ 1 ] = DIGIPOT_1_B0L0_STARTVALUE;
    digipot_values[ 2 ] = DIGIPOT_2_B0L0_STARTVALUE;
    digipot_values[ 3 ] = DIGIPOT_0_B0L1_STARTVALUE;
    digipot_values[ 4 ] = DIGIPOT_1_B0L1_STARTVALUE;
    digipot_values[ 5 ] = DIGIPOT_2_B0L1_STARTVALUE;

    digipot_pins[ 0 ] = BANK_0_LEG_0_DIGITAL_POT_0;
    digipot_pins[ 1 ] = BANK_0_LEG_0_DIGITAL_POT_1;
    digipot_pins[ 2 ] = BANK_0_LEG_0_DIGITAL_POT_2;
    digipot_pins[ 3 ] = BANK_0_LEG_1_DIGITAL_POT_0;
    digipot_pins[ 4 ] = BANK_0_LEG_1_DIGITAL_POT_1;
    digipot_pins[ 5 ] = BANK_0_LEG_1_DIGITAL_POT_2;
        
    for( uint8_t index = 0; index < USING_LM334_WITH_MCP4162_POT_BANKS; index++ )
    {
        pinMode( digipot_pins[ 0 + index ], OUTPUT );
        pinMode( digipot_pins[ 1 + index ], OUTPUT );
        pinMode( digipot_pins[ 2 + index ], OUTPUT );
        pinMode( digipot_pins[ 3 + index ], OUTPUT );
        pinMode( digipot_pins[ 4 + index ], OUTPUT );
        pinMode( digipot_pins[ 5 + index ], OUTPUT );
        digitalWrite( digipot_pins[ 0 + index ], HIGH );
        digitalWrite( digipot_pins[ 1 + index ], HIGH );
        digitalWrite( digipot_pins[ 2 + index ], HIGH );
        digitalWrite( digipot_pins[ 3 + index ], HIGH );
        digitalWrite( digipot_pins[ 4 + index ], HIGH );
        digitalWrite( digipot_pins[ 5 + index ], HIGH );
        SPI.begin();
        SPI.setBitOrder( MSBFIRST );
    #ifndef LEAVEPOTVALUESALONEDURINGSETUP //This causes digipot stored settings not to match digipots, but at least they stay put to what they were last set to
        setPotValue( digipot_pins[ 0 + index ], digipot_values[ 0 + index ] );
        setPotValue( digipot_pins[ 1 + index ], digipot_values[ 1 + index ] );
        setPotValue( digipot_pins[ 2 + index ], digipot_values[ 2 + index ] );
        setPotValue( digipot_pins[ 3 + index ], digipot_values[ 3 + index ] );
        setPotValue( digipot_pins[ 4 + index ], digipot_values[ 4 + index ] );
        setPotValue( digipot_pins[ 5 + index ], digipot_values[ 5 + index ] );
    #endif
        #ifdef DEBUG
            while ( !Serial && ( millis() - millis_start < 8000 ) );
            Serial.println( F( "Digi pots set up" ) );
        #endif
    }
    #else
        #error This sketch is not entirely able to handle multiple digipot banks at this revision level
    #endif
#endif
    #if ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 ) 
        #if !( ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD )
            analogReference( DEFAULT ); //This is the voltage level of max bit value on analog input
        #else
            analogReference( AR_DEFAULT ); //
        #endif
    #endif    
    #ifdef DEBUG
        millis_start = millis();
        while ( !Serial && ( millis() - millis_start < 8000 ) );
        Serial.print( F( "Starting setup with SDA & SCL & SCK & A4 & A5 = " ) );
        Serial.print( SDA );
        Serial.print( F( " & " ) );
        Serial.print( SCL );
        Serial.print( F( " & " ) );
        Serial.print( SCK );
        Serial.print( F( " & " ) );
        Serial.print( A4 );
        Serial.print( F( " & " ) );
        Serial.println( A5 );
    #endif
    //#ifndef ARDUINO_AVR_DIGISPARKPRO
    //    analogReadResolution( ADC_RES_BIT );
    //#endif
    #if ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 )
        #if ( HIGHESTBITRESFROMHIGHESTSENSIADDONADC < 17 )
        //   ads.setGain( GAIN_TWOTHIRDS );  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)  //The extra ones are here for reference 
           ads.setGain( GAIN_ONE );        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV  //This allows a simple power rail excitation supply to voltage divider
        //   ads.setGain( GAIN_TWO );        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
        //   ads.setGain( GAIN_FOUR );       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
        //   ads.setGain( GAIN_EIGHT );      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
        //   ads.setGain( GAIN_SIXTEEN );    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
            ads.begin();
        #else
            #if ( HIGHEST_SENSI_ADDON_ADC_TYPE == HX711 )
                #ifdef DEBUG
                    millis_start = millis();
                    while ( !Serial && ( millis() - millis_start < 8000 ) );
                    Serial.print( F( "Initializing HX711..." ) );
                #endif
/*
 * With the library being used, the .begin() method is not needed if the HX711 was declared earlier prior to setup().  The reason I'm doing it superfluously here is simply to suggest some measure of future consistency across all ADCs since other ADC libraries may not allow one or the other...
 */
                hx711.begin( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, HIGHEST_SENSI_PGA_GAIN_FACTOR );  // if the third parameter is ommited the default gain value 128 & channel A is used by the library
                #ifdef DEBUG
                    millis_start = millis();
                    while ( !Serial && ( millis() - millis_start < 8000 ) ); //We limit the time to wait for serial ready
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

    if( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT > 1 ) screen_offsets_of_linespaces[ 0 ].zero_of_this_plot_linespace = PLOTTERMAXSCALE - HEIGHT_OF_A_PLOT_LINESPACE;

#ifdef DEBUG
        while( !Serial );
        Serial.println( F( "The following numbers count up to the highest index of traces to be displayed:" ) );
#endif

    for( uint8_t i = 0; i < NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT; i++ )
    {
#ifdef MAGNIFICATION_FACTOR
        screen_offsets_of_linespaces[ i ].magnify_adjustment = 0;
        tracespace_to_skip_when_repositioning = ( HEIGHT_OF_A_PLOT_LINESPACE * PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) / 100;
        negative_tracespace_to_skip_when_repositioning = HEIGHT_OF_A_PLOT_LINESPACE - ( HEIGHT_OF_A_PLOT_LINESPACE * PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) / 100;
#endif
#ifdef DEBUG
        while( !Serial );
        Serial.print( F( "Line 1170" ) );
//        Serial.print( i );
#endif
        if( i == 0 )
        {
#ifdef DEBUG
        while( !Serial );
        Serial.print( F( ", Line 1177 " ) );
//        Serial.print( i );
#endif
            screen_offsets_of_linespaces[ i ].high_limit_of_this_plot_linespace = PLOTTERMAXSCALE;
            screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace = PLOTTERMAXSCALE - HEIGHT_OF_A_PLOT_LINESPACE;
        }
#if defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 ) && ( NUM_OF_INBOARD_ADCS_TO_PLOT > 1 )
        else if( i == 1 )
        {
    #ifdef DEBUG
        while( !Serial );
        Serial.print( F( ", Line 1188 " ) );
//        Serial.print( i );
    #endif
            screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace = screen_offsets_of_linespaces[ i - 1 ].zero_of_this_plot_linespace;
            screen_offsets_of_linespaces[ i ].high_limit_of_this_plot_linespace = screen_offsets_of_linespaces[ i - 1 ].high_limit_of_this_plot_linespace;
        }
#endif
        else
        {
    #ifdef DEBUG
        while( !Serial );
        Serial.print( F( ", Line 1198 " ) );
//        Serial.print( i );
    #endif
            screen_offsets_of_linespaces[ i ].high_limit_of_this_plot_linespace = screen_offsets_of_linespaces[ i - 1 ].zero_of_this_plot_linespace;
            screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace = screen_offsets_of_linespaces[ i ].high_limit_of_this_plot_linespace - HEIGHT_OF_A_PLOT_LINESPACE;
        }
#ifdef MAGNIFICATION_FACTOR
        screen_offsets_of_linespaces[ i ].previous_unmagnified_reading = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
        last_plot_points[ i * 2 ] = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
        last_plot_points[ ( i * 2 ) + 1 ] = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
#else
        last_plot_points[ i ] = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
#endif
#ifdef DEBUG
        while( !Serial );
        Serial.print( i );
        Serial.print( F( " zero_of_this_plot_linespace == " ) );
        Serial.print( screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace );
        Serial.print( F( ", high_limit_of_this_plot_linespace == " ) );
        Serial.println( screen_offsets_of_linespaces[ i ].high_limit_of_this_plot_linespace );
#endif
    }
    plot_timing_line_going_up( false ); //The false makes all traces originate at global zero.  It seems to look better that way

//Next the pin translation table is allocated then filled
    #if defined USING_LM334_WITH_MCP4162_POT_BANKS && defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_INBOARD_ADCS_TO_PLOT < USING_LM334_WITH_MCP4162_POT_BANKS * 2 )
        A_PIN_ARRAY = ( uint8_t * )malloc( 2 * USING_LM334_WITH_MCP4162_POT_BANKS );
    #elif ( NUM_OF_INBOARD_ADCS_TO_PLOT > 0 )
        A_PIN_ARRAY = ( uint8_t * )malloc( NUM_OF_INBOARD_ADCS_TO_PLOT );
    #endif
        #if ( NUM_OF_INBOARD_ADCS_TO_PLOT > 0 ) || ( defined USING_LM334_WITH_MCP4162_POT_BANKS && defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && defined AUTO_BRIDGE_BALANCING && not defined LEAVEPOTVALUESALONEDURINGSETUP )
        //Hereafter is the pattern.  If you have more analog pins, add them according to the pattern.
        #ifdef NUM_ANALOG_INPUTS
        #ifdef PIN_A0
            #if defined USING_LM334_WITH_MCP4162_POT_BANKS && defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_INBOARD_ADCS_TO_PLOT < USING_LM334_WITH_MCP4162_POT_BANKS * 2 )
            for( uint8_t i = 0; i < ( USING_LM334_WITH_MCP4162_POT_BANKS * 2 ); i++ )
            #else
            for( uint8_t i = 0; i < NUM_OF_INBOARD_ADCS_TO_PLOT; i++ )
            #endif
            {
                if( i == 0 )
                    *(A_PIN_ARRAY + i) = PIN_A0;
                #ifdef PIN_A1
                    else if( i == 1 )
                        *(A_PIN_ARRAY + i) = PIN_A1;
                    #ifdef PIN_A2
                    else if( i == 2 )
                        *(A_PIN_ARRAY + i) = PIN_A2;
                        #ifdef PIN_A3
                    else if( i == 3 )
                        *(A_PIN_ARRAY + i) = PIN_A3;
                            #ifdef PIN_A4
                    else if( i == 4 )
                        *(A_PIN_ARRAY + i) = PIN_A4;
                                #ifdef PIN_A5
                    else if( i == 5 )
                        *(A_PIN_ARRAY + i) = PIN_A5;
                                    #ifdef PIN_A6
                    else if( i == 6 )
                        *(A_PIN_ARRAY + i) = PIN_A6;
                                        #ifdef PIN_A7
                    else if( i == 7 )
                        *(A_PIN_ARRAY + i) = PIN_A7;
                                            #ifdef PIN_A8
                    else if( i == 8 )
                        *(A_PIN_ARRAY + i) = PIN_A8;
                                                #ifdef PIN_A9
                    else if( i == 9 )
                        *(A_PIN_ARRAY + i) = PIN_A9;
                                                    #ifdef PIN_A10
                    else if( i == 10 )
                        *(A_PIN_ARRAY + i) = PIN_A10;
                                                        #ifdef PIN_A11
                    else if( i == 11 )
                        *(A_PIN_ARRAY + i) = PIN_A11;
                                                            #ifdef PIN_A12
                    else if( i == 12 )
                        *(A_PIN_ARRAY + i) = PIN_A12;
                                                                #ifdef PIN_A13
                    else if( i == 13 )
                        *(A_PIN_ARRAY + i) = PIN_A13;
                                                                    #ifdef PIN_A14
                    else if( i == 14 )
                        *(A_PIN_ARRAY + i) = PIN_A14;
                                                                        #ifdef PIN_A15
                    else if( i == 15 )
                        *(A_PIN_ARRAY + i) = PIN_A15;
                                                                            #ifdef PIN_A16
                    else if( i == 16 )
                        *(A_PIN_ARRAY + i) = PIN_A16;
                                                                                #ifdef PIN_A17
                    else if( i == 17 )
                        *(A_PIN_ARRAY + i) = PIN_A17;
                                                                                    #ifdef PIN_A18
                    else if( i == 18 )
                        *(A_PIN_ARRAY + i) = PIN_A18;
                                                                                        #ifdef PIN_A19
                    else if( i == 19 )
                        *(A_PIN_ARRAY + i) = PIN_A19;
                                                                                            #ifdef PIN_A20
                    else if( i == 20 )
                        *(A_PIN_ARRAY + i) = PIN_A20;
                                                                                                #ifdef PIN_A21
                    else if( i == 21 )
                        *(A_PIN_ARRAY + i) = PIN_A21;
                                                                                                    #ifdef PIN_A22
                    else if( i == 22 )
                        *(A_PIN_ARRAY + i) = PIN_A22;
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
            #if defined USING_LM334_WITH_MCP4162_POT_BANKS && defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_INBOARD_ADCS_TO_PLOT < USING_LM334_WITH_MCP4162_POT_BANKS * 2 )
                for( uint8_t i = 0; i < ( USING_LM334_WITH_MCP4162_POT_BANKS * 2 ); i++ )
            #else
                for( uint8_t i = 0; i < NUM_OF_INBOARD_ADCS_TO_PLOT; i++ )
            #endif
                    *(A_PIN_ARRAY + i) = i + FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES;
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
        Serial.print( F( "A_PIN_ARRAY = " ) );
        Serial.println( (unsigned long)A_PIN_ARRAY );
        #if defined USING_LM334_WITH_MCP4162_POT_BANKS && defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_INBOARD_ADCS_TO_PLOT < USING_LM334_WITH_MCP4162_POT_BANKS * 2 )
            for( uint8_t i = 0; i < ( USING_LM334_WITH_MCP4162_POT_BANKS * 2 ); i++ )
        #else
            for( uint8_t i = 0; i < NUM_OF_INBOARD_ADCS_TO_PLOT; i++ )
        #endif
            Serial.println( *( A_PIN_ARRAY + i ) );
        Serial.print( F( "PLOTTERMAXSCALE = " ) );
        Serial.print( PLOTTERMAXSCALE );
        Serial.print( F( " and ( uint32_t )( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT ) = " ) );
        Serial.println( ( uint32_t )( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT + NUM_OF_INBOARD_ADCS_TO_PLOT ) );
        
        //add other prints here to your liking
        
        Serial.print( F( "End of " ) );
    #endif //end of DEBUG
    #ifdef AUTO_BRIDGE_BALANCING
        for( uint8_t index; index < NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT; index++ )
            counter_for_trace_out_of_range_too_long[ index ] = 0;
    #endif
//#error this area below is where I'm at in development
    #if defined AUTO_BRIDGE_BALANCING && not defined LEAVEPOTVALUESALONEDURINGSETUP
        #ifdef DEBUG
            Serial.println( F( "initial setup.  Entering calibration setup." ) );
        #endif
        Serial.print( PLOTTERMAXSCALE );
        Serial.print( F( " " ) );
        read_and_plot_from_all_ADCs_in_and_outboard( true );
        uint32_t last_plot_points_temp[ USING_LM334_WITH_MCP4162_POT_BANKS * 2 ]; //2 legs/bank, each leg is one entry        
        Serial.println();
//Then get the readings of desired legs from 
        for( uint8_t bank = 0; bank < USING_LM334_WITH_MCP4162_POT_BANKS; bank++ )
        {
#ifdef MAGNIFICATION_FACTOR
            last_plot_points_temp[ 0 + ( bank * 2 ) ] = last_plot_points[ bank * 2 ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
            last_plot_points_temp[ 1 + ( bank * 2 ) ] = last_plot_points[ 2 + ( bank * 2 ) ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
#else
            last_plot_points_temp[ 0 + ( bank * 2 ) ] = last_plot_points[ bank * 2 ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
            last_plot_points_temp[ 1 + ( bank * 2 ) ] = last_plot_points[ 1 + ( bank * 2 ) ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
#endif
        }
/*        
How the indexing compares: each unit of USING_LM334_WITH_MCP4162_POT_BANKS covers a digipot bank with 2 legs, therefore 2 inboard ADC pins
Each entry in last_plot_points[] correlates to the unmagnified or magnified trace of pins, so either 1 (no magnification) or 2 (magnification) array entries per pin
So each unit of USING_LM334_WITH_MCP4162_POT_BANKS could group last_plot_points[] into 2 or 4 entries, not caring about entires 1 and 3 when magnified==true.
set_digipots_reference_leg() has done one entire bank by the time it returns true
*/
//#ifdef MAGNIFICATION_FACTOR
//        /*reading=*/last_plot_points[ bank * 2 ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;// + screen_offsets_of_linespaces[ channel ].zero_of_this_plot_linespace;
//#else
//        /*reading=*/last_plot_points[ bank ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;// + screen_offsets_of_linespaces[ channel ].zero_of_this_plot_linespace;
//#endif
//        }
//bool set_digipots_reference_leg( bool just_perform_one_step = false, uint8_t bank = 0 )
//#error set_digipots_reference_leg() has a bug where it allows out of range setting values
        for( uint8_t bank = 0; bank < USING_LM334_WITH_MCP4162_POT_BANKS; bank++ )
        {
            while( set_digipots_reference_leg( true, bank ) == false ) //while false, the entire bank is being zeroed into the desired balance
            {
            #ifdef DEBUG
                Serial.println( F( "Line 1676" ) );
            #endif
                delay( 2 ); // allow some settling time
                Serial.print( PLOTTERMAXSCALE );
                Serial.print( F( " " ) );
                read_and_plot_from_all_ADCs_in_and_outboard( true ); // I would think the operator would appreciate seeing something like this during calibration
                Serial.println();
                if( counter_for_trace_out_of_range_too_long[ bank ]++ > 80 ) break; //Limited to prevent endless looping here
            }
            counter_for_trace_out_of_range_too_long[ bank ] = 0;
            match_bridge_leg_signal_to_reference( bank ); //This will do the same on the signal leg
        }
        Serial.print( 0 );
        Serial.print( F( " " ) );
        read_and_plot_from_all_ADCs_in_and_outboard( true ); // I would think the operator would appreciate seeing something like this during calibration
        Serial.println();
        Serial.print( PLOTTERMAXSCALE );
        Serial.print( F( " " ) );
        read_and_plot_from_all_ADCs_in_and_outboard( true ); // I would think the operator would appreciate seeing something like this during calibration
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
    for( uint16_t plotter_loops = 0; plotter_loops < 500 / 3; plotter_loops++ ) 
    {
        millis_start = millis();
/* */
        if( graphline ) this_readingTemp = 0;
        else this_readingTemp = PLOTTERMAXSCALE;
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        Serial.print( this_readingTemp ); //This was originally last printed in the group.  It needs to be first instead so the line can be "notched" horizontally without needing to reprint all values.
        Serial.print( F( " " ) );
/* 
FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET causes index of pin designator cross reference never to be any different
FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET with NUM_OF_INBOARD_ADCS_TO_PLOT == 2 && ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 ) to plot and plotall differently
screen_offsets_of_linespaces array shall NOT be used for digipot setting in AUTO_BRIDGE_BALANCING.  Instead use *( A_PIN_ARRAY ) and *(A_PIN_ARRAY + 1 ) only to set digipots which it already does


*/

//#if defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 ) && ( NUM_OF_INBOARD_ADCS_TO_PLOT == 1 ) This condition will mean one i index will need to be skipped
        read_and_plot_from_all_ADCs_in_and_outboard();
/*
        if( graphline ) this_readingTemp = 0;
        else this_readingTemp = PLOTTERMAXSCALE;
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        Serial.println( this_readingTemp );
*/
        Serial.println();

        while( millis() - millis_start < MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS );
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
    #ifdef USING_LM334_WITH_MCP4162_POT_BANKS
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
            if( szFull[ 0 ] == '1' ) DIGITAL_POT_ = digipot_pins[ 0 ];
            else if( szFull[ 0 ] == '2' ) DIGITAL_POT_ = digipot_pins[ 1 ];
            else if( szFull[ 0 ] == '3' ) DIGITAL_POT_ = digipot_pins[ 2 ];
            else if( szFull[ 0 ] == '4' ) DIGITAL_POT_ = digipot_pins[ 3 ];
            else if( szFull[ 0 ] == '5' ) DIGITAL_POT_ = digipot_pins[ 4 ];
            else if( szFull[ 0 ] == '6' ) DIGITAL_POT_ = digipot_pins[ 5 ];
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
#if defined ( POTTESTWOBBLEPOSITIVE ) || defined ( POTTESTWOBBLENEGATIVE )
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
#if defined ( TESTSTEPUPDOWN )
#if ( TESTSTEPUPDOWN == SINGLESIDE )
    if( potstepdirection )
    {//adjust_whole_bridge_positive until maxed
        if( !adjust_whole_bridge_positive( 0 ) )
        {
            potstepdirection = false;
            adjust_whole_bridge_negative( 0 );
        }
    }
    else
    {
        if( !adjust_whole_bridge_negative( 0 ) )
        {
            potstepdirection = true;
            adjust_whole_bridge_positive( 0 );
        }
    }
#elif ( TESTSTEPUPDOWN == COMMONMODE )
    adjust_whole_bridge_commonmode();
#endif
#endif
    }
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
#if defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 ) && ( NUM_OF_INBOARD_ADCS_TO_PLOT > 0 )
    for( uint8_t i = 1; i < NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT; i++ )
#else
    for( uint8_t i = 0; i < NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT; i++ )
#endif
    {
        if( !graphline )
        {//going down
            Serial.print( screen_offsets_of_linespaces[ i ].high_limit_of_this_plot_linespace );
            plotvaluesforalltraces( true );
            Serial.print( screen_offsets_of_linespaces[ i ].zero_of_this_plot_linespace );
            plotvaluesforalltraces( true );
        }
        else
        {//going up
#if defined FIRST_INBOARDS_ARE_IN_PAIRS_AND_EACH_PAIR_IS_IN_PARALLEL_WITH_ONE_HIGHEST_SENSI_ADC_INPUT_SET && ( NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT > 0 ) && ( NUM_OF_INBOARD_ADCS_TO_PLOT > 0 )
            while( i < 2 ) i++;
#endif
#ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
            Serial.print( F( "Line 1553 screen_offsets_of_linespaces[ " ) );
            Serial.print( NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT - i - 1 );
            Serial.println( F( " ].zero_of_this_plot_linespace" ) );
#endif
            Serial.print( screen_offsets_of_linespaces[ NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT - i - 1 ].zero_of_this_plot_linespace );
            plotvaluesforalltraces( true );
#ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
            Serial.print( F( "Line 1561 screen_offsets_of_linespaces[ " ) );
            Serial.print( NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT - i - 1 );
            Serial.println( F( " ].high_limit_of_this_plot_linespace" ) );
#endif
            Serial.print( screen_offsets_of_linespaces[ NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT - i - 1 ].high_limit_of_this_plot_linespace );
            plotvaluesforalltraces( true );
            if( i == NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT - 1 )
            {
#ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
            Serial.print( F( "Line 1571 screen_offsets_of_linespaces[ " ) );
            Serial.print( NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT - i - 1 );
            Serial.println( F( " ].high_limit_of_this_plot_linespace" ) );
#endif
                Serial.print( screen_offsets_of_linespaces[ NUM_OF_INBOARD_ADCS_TO_PLOT + NUM_OF_ADDON_HIGHEST_SENSI_ADCS_TO_PLOT - i - 1 ].high_limit_of_this_plot_linespace );
                plotvaluesforalltraces( true );
            }
        }
    }
    graphline = !graphline; // graphline started as false, so it becomes true here on the first complementing of it
}
