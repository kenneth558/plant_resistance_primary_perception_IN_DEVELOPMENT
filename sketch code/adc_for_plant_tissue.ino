//        BEFORE COMPILING THIS SKETCH you must set or confirm the following preprocessor macros appropriately for your configuration and preferences !!!
#define LM334_BRIDGES 1                                        //Number of digipot Wheatstones you have topped with LM334s each leg, (schematically wired before bare DPot bridges) but this sketch revision level not tested beyond 1.  Remove if using Wheatstone bridge with only standard or DPot resistors.  make this the number of bridges with upper resistive elements being LM334s controllable with the MCP4162-104 pots
#define DPOTS_PER_LM334_LEG 3                                  //Not yet tested for any setting except 3, so verify it before trusting fully.  Due to their significant temperature coefficient, LM334s need to be used in pairs so their tempco offsets each other's; i.e., LM334 legs are invalid unless bridged with both legs topped by a LM334
#define NUM_OF_INBOARDS_PLOTTED 2                              //The number of consecutive analog pins to plot, beginning with PIN_A0
#define NUM_OF_OUTBOARDS_PLOTTED 1                             //The number of consecutive "highest-sensitivity ADC" pins to plot, beginning with A0 and, if double-ended, A1.  OUTBOARD ADC ONLY - DOES _NOT_ INCLUDE INBOARD ANALOG INPUT PINS
#define MAGNIFICATION_FACTOR 5                                 //Activates the plotting of magnified traces in all ADC linespaces; upper limit somewhere less than 4,294,967,295. Note: you can disable displaying magnified traces altogether by not defined this macro at all. Proper use of SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS will also disable magnified traces of the first two analog inputs
#define HIGHEST_SENSI_OUTBOARD_ADC_TYPE HX711                  //Proposing that "ADS1231" covers ADS1231; could make this "ADS1232" (ADS1232), "ADS1242" (ADS1242), "AD779X" (AD779X), "AD7780" (AD7780), "HX711" (HX711), "ADS1X15" (ADS1015 or ADS1115), "MAX112x0" (MAX112X0...) or "LTC2400" (LTC2400) but code not included in v.FREE; ONLY ONE TYPE ALLOWED
#define HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC 24     //All ADC values will get scaled to the single-ended aspect of this,  15 is ADS1115 single-ended, 16 for double-ended when two LM334s are used.  change to 11 for ADS1015 single-ended or 12 with two LM334s, (future: change to 24 for HX711--NO b/c there is the ADS1231 at 24 bits)
#define SAMPLE_TIMES 2                                         //To better average out artifacts we over-sample and average.  This value can be tweaked by you to ensure neutralization of power line noise or harmonics of power supplies, etc.....
#define MOST_PROBLEMATIC_INTERFERENCE_FREQ 60                                                               //This is here just in case you think that you might have some interference on a known frequency.
#define DELAY_TIME_BETWEEN_SAMPLES_MS ( 1000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ / SAMPLE_TIMES )          //COARSE ADJUST
#define DELAY_TIME_BETWEEN_SAMPLES_US ( ( ( 1000000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ ) - ( DELAY_TIME_BETWEEN_SAMPLES_MS * SAMPLE_TIMES * 1000 ) ) / SAMPLE_TIMES ) //FINE ADJUST.  THIS GETS ADDED TO COARSE ADJUST, PRECISION = TRUNCATED PRAGMATICALLY TO uSec TO ACKNOWLEDGE SOME OVERHEAD FOR LOOPING SUPPORT CODE   // End of this part of code update
#define FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES 14 //Some boards don't have good definitions and constants for the analog pins :-(
#define PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED 85   //BETWEEN 0 AND 100 indicating how much of the display region in percent to skip when magnified view trace has to get repositioned because trace would be outside region bounds; NO BOUNDS CHECKING IS PROVIDED!!!
#define ANALOG_INPUT_BITS_OF_BOARD 10                                                                       //Most Arduino boards are 10-bit resolution, but some can be 12 bits.  For known 12 bit boards (SAM, SAMD and TTGO XI architectures), this gets re-defined below, so generally this can be left as 10 even for those boards
#define SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING 9                                  //8 works only usually
#define HIGHEST_SENSI_PGA_GAIN_FACTOR 128                                  //For HX711 a gain of 128 gets applied to channel A. Available to you for your own use PGA=Programmable Gain Amplifier: many ADCs will correlate a gain of one with full-scale being rail-to-rail, while a gain of anything higher correlates to full-scale being in the mV range (most sensitive and most noise-susceptible).
#define MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS 70                            //Sets a maximum speed limit, but actual speed may be further limited by other factors
#define SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS 1                              //If defined allows the rail-to-rail inboard Analog Inputs to be used to adjust digipots, but mainly causes first inboard Analog Inputs to be paired (superimposed in pairs sharing plot-line spaces) so even manual pots can be adjusted easily.
#define AUTO_BRIDGE_BALANCING                                              //increases setup time and during which the plot timing line stays high, then spikes low and high to indicate balancing complete //Turns on auto-balancing in setup(), significant time elapse for this to complete!
#define CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE true                  //Without predictive balancing, this takes too much time if true
//#define DEBUG                                                            //Don't forget that DEBUG is not formatted for Serial plotter, but might work anyway if you'd never print numbers only any DEBUG print line
#define POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC 0                      //For testing - wobbles digipot settings on bridge index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the signal leg
#define POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC 0                   //For testing - wobbles digipot settings on bridge index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the reference leg
#define WOBBLE_TIME_PERIOD  10
//#define LEAVE_POT_VALUES_ALONE_DURING_SETUP                                               //First run should leave this undefined to load digi pots with some values
#define BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 0        //This offset will be applied to all signal lines of outboard ADCs, not just the first one, until further development.  Write some code yourself to expand.  Inboard Analog Inputs of 10 bits will make much change with little values, 12 bit inboard allows more flexibility here
#ifdef BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0
    #define ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0 0   //To maintain consistent effect with the above, associated macro, this gets applied inverted. This is in lieu of setting by reading the ADCs and zeroing them.
#endif
#ifdef __LGT8FX8E__
    #define BAUD_TO_SERIAL 19200                                                            //This speed is what works best with WeMos XI/TTGO XI board.  Experiment as desired.
#else
    #define BAUD_TO_SERIAL 115200                                                           //YOU MAY SET THIS TO THE MAXIMUM VALUE THAT YOUR CONFIGURATION WILL FUNCTION WITH (UNLESS YOU'RE USING THE WeMos XI/TTGO XI, OF COURSE)
#endif
#define DPOT_RATIO 10 /* DPOT_RATIO: System-wide.  Ex.: If the LSB digipot is 200 ohms/step and the MSB digipot is 2000 ohms/step, this value will be 10. (200/2000)
                      It is only used relative to the LSB digipot, so there can only be that one digipot per leg allowed to have a smaller resistance 
                      per step than other digipots on the leg. All bridge legs in the system must be built with the same ratio scheme, and must always include one and
                      only one LSB digipot, with all non-LSB digipots matching each others' resistance/step values.  This macro limits LSB settings adjustments
                      when another digipot in the leg is set to less than MAXPOTSETTG, but not otherwise, allowing LSB to reach MAXPOTSETTG when non-LSBs are all at MAXPOTSETTG.
                      As far as MAXPOTSETTG, all digipots in the system are bound by the same MAXPOTSETTG value. */
//#define POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR 3                       //NOT the digital number //Can use a spare analog input as magnification attenuator by connecting wiper of a pot (100K or greater, please) that voltage-divides 0-5 vdc.
//#define USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
#define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 20                           //sets how soon run-time auto-balancing kicks in when trace goes off scale

#define CONVERT_TWOS_COMP_TO_SINGLE_ENDED( value_read_from_the_differential_ADC, mask, xorvalue ) ((value_read_from_the_differential_ADC & mask)^xorvalue)

//#define CONVERT_TWOS_COMP_TO_SINGLE_ENDED ( value_read_from_the_differential_ADC, mask, xorvalue ) ( ( value_read_from_the_differential_ADC & mask ) ^xorvalue )
//SOME OF THE OTHER MACROS (DEFINES OR RE-DEFINES) ELSEWHERE: VERSION, NUM_OF_INBOARDS_PLOTTED, NUM_OF_OUTBOARDS_PLOTTED, LSB_DPOT_B0L0_STARTVALUE - DPOT_zero_B0L1_STARTVALUE, HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC, DIFFERENTIAL, PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, PLOTTER_MAX_SCALE, HUNDREDTHPLOTTER_MAX_SCALE, SAMPLE_TIMES, SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE, COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG, HEIGHT_OF_A_PLOT_LINESPACE

//FUTURE #define TEST_STEP_UP_DOWN COMMONMODE                                                                  //Available: SINGLESIDE COMMONMODE
//FUTURE #define BARE_DPOT_LEG_BRIDGES, BARE_DPOT_LEGS_NOT_BRIDGED  Subject to change, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define BARE_DPOT_LEG_BRIDGES 1                        //(after LM334 bridges in terms of pin number order) Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg increasing the likelihood 74LV138 decoding will be necessary.
//FUTURE #define BARE_DPOT_LEGS_NOT_BRIDGED 1                    //(after active bridges in terms of pin number order, passive bridges using manual pots might include these legs)Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define BARE_DPOT_LEG_BRIDGES_RAIL "-"                         //(after LM334 bridges in terms of pin number order) Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg increasing the likelihood 74LV138 decoding will be necessary.
//FUTURE #define BARE_DPOT_LEGS_NOT_BRIDGED_RAIL "-"                    //(after active bridges in terms of pin number order, passive bridges using manual pots might include these legs)Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE 
#define DPOTS_PER_BRIDGED_BARE_LEG 3                              //FUTURE Not yet tested for any setting, so verify it before trusting fully
//FUTURE 
#define DPOTS_PER_UNBRIDGED_BARE_LEG 3                              //FUTURE Not yet tested for any setting, so verify it before trusting fully
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES 
//!!! NOTE !!! 270+ lines below this are also macros entitled similar to BANK_X_LEG_X_DPOT_X.  Those macros must also be set to correspond to the pins driving the CS lines of digipots
    #warning These_ 7 pin numbers get specified normally, but be sure you specify the _digital_pot_CS_pins_ with the MSB set to decode them; i.e., make those pin numbers>= 128, but not these
    #define FIRST_STAGE_3_TO_8_DECODER_A0_PIN 5
    #define FIRST_STAGE_3_TO_8_DECODER_A1_PIN 6
    #define FIRST_STAGE_3_TO_8_DECODER_A2_PIN 7
    #define SECOND_STAGE_3_TO_8_DECODER_A0_PIN 8
    #define SECOND_STAGE_3_TO_8_DECODER_A1_PIN 9
    #define SECOND_STAGE_3_TO_8_DECODER_A2_PIN 10
    #define BOTH_STAGES_3_TO_8_DECODER_ENABLE_PIN 11
#endif
#define COPYRIGHT_YEAR 2018
/*******************(C)  COPYRIGHT 2018 KENNETH L ANDERSON *********************
* 
*      ARDUINO ELECTRICAL RESISTANCE/CONDUCTANCE MONITORING SKETCH 
*      
* File Name          : adc_for_plant_tissue.ino
* Author             : KENNETH L ANDERSON
* Version            : v.Free
* Date               : 04-OCT-2018
* Description        : To replicate Cleve Backster's findings that he attributed to a phenomenon he called "Primary Perception".  Basically, this sketch turns an Arduino MCU and optional (recommended) ADS1115 into a nicely functional poor man's polygraph in order to learn/demonstrate telempathic gardening.
* Boards tested on   : Uno using both ADS1115 and inboard analog inputs.  
*                    : TTGO XI using ADS1115.  
*                    : Many other configurations should work fine.  
*                    : The ATTINY85 is not suitable at all due to not having hardware serial
* 
* Known limitations  : Free version does not use predictive auto bridge balance lending to painfully slow auto balance when plant conductance goes out of range
*                    : No ability to accept user input from keyboard during run time due to Arduino plotter limitation
*                    : Re-compile is needed for any changes to configuration
*                    : Analog input pins being used MUST be the first available analog inputs
*                    : Only a single add-on ADS ADC device and only 1 or 2 differential channels on it is tested
*                    : Conventional add-on high-sensitivity ADCs limit their common mode differential input range to a few millivolts with active or passive clamping
*                    : Some of these limitations will be addressed in future not-for-free versions
*                    
*     Due to the many preprocessor condition checks throughout this sketch source, the IDE is unable to track bracketed constructs accurately in many places. 
*     What does this mean?  If you are used to relying on the IDE's highlighting of a paired bracket to help you know a bracketed construct's boundaries, you'll have to give that convenience up in places in this sketch source code.
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
*        Use dual digital potentiometers (MCP42XXX) for more lower parts count than when using single pot MCP41XXX
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
*              23 Aug   2018 :  Fixed magnified traces in all respects; added functionality to display digipot calibration effects during calibration in setup(); started adding code to handle multiple digipot bridges that utilize dual 74VHC138/74LV138s.  Still no AUTO_BRIDGE_BALANCING
*              23 Aug   2018 :  Magnification factor adjustable downward via a potentiometer if defined POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR with the digital number of an inboard analog input pin.
*              23 Aug   2018 :  added USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES with possibly enough code (just needs testing). Allowed for any ratio of LSB pot step to MSB step with DPOT_RATIO
*              11 Sep   2018 :  Back with new style of arrays useage to make bug-free coding more possible.
*              20 Sep   2018 :  Auto adjust works, but only non-predictively so it is slow.  Added macro CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE thinking someone may not want display to pause during auto balance, but that is even painfully slower still.
*              20 Sep   2018 :  Alpha chars added into output for future expansion beyond Arduino
*                            :  Now allows dual digi pot devices: MCP42xxx by manipulating the DPotPin of the first DPot of pkg OR'ing it with 0x40 as the pin of the second DPot in the pkg
*              NEXT          :  Allow DigiPots without LM334: the direction of effect will be opposite.  New macro: 
*              NEXT          :  EEPROM storage of things like ADC sweet spot, initial digipot settings, etc.  Hardware configs like DPot types & ADC types & other upgradeable hardware version possiblities needs to be able to be set in the hat board rather than EEPROM
*              NEXT          :  Accommodate ADS1232 &/or ADS1231
*              NEXT          :  Detect hat config and version with 256 versions detection and warning to acquire more recent sketch version when versions > known are found
*               
*********************************************************************************************************************/
#define VERSION "v.Free"
#include <math.h>
//global variables are declared static to prevent them from being seen by any later user-added compilation units that would try, presumeably inadvertently, through the use of the "extern" cast
#define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ( 1 << ( ANALOG_INPUT_BITS_OF_BOARD - 1 ) ) // Needed if HIGHEST_SENSI_OUTBOARD_ADC_TYPE has a sweet spot of max sensitivity, unlike true op-amp.  (HX711 == 306; normal op-amp, which has none == Vcc/2 == 512)
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
#ifdef ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0
    #if ( ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0 + 1 > 1 )
    #else
        #undef ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0
    #endif
#endif
#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 ) //Since so many of the ADC libraries already use OO classes, we'll set that as a pattern - instantiate prior to executing any code
    #define HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC / 2 )
    #if ( ( HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC * 2 ) == HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC )
        #define DIFFERENTIAL
    #else
        #ifdef DIFFERENTIAL
            #undef DIFFERENTIAL
        #endif
    #endif
    #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1X15 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 ) && ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
        #include <Adafruit_ADS1015.h> //for systems using ADS1115/ADS1015  Data addressable I2C, shares bidirectional, open-collector data and clk only with other I2C slaves on same bus, must use the core-defined SDA/SCL pins except ESP8266 and ATtiny85 or see https://www.arduino.cc/en/reference/wire or see the Adafruit_ADS1X15-master README.md
/*  
*  With Adafruit_ADS1015.h, SDA, SCL Wemos XI/TTGO XI use A4 for SDA, and A5 is SCL.
*/
        #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 15 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 16 )
            Adafruit_ADS1115 ads;  //For when ADS1115 is being used Data addressable I2C and shares bidirectional, open-collector data and clk only with other I2C slaves on same bus, must use the core-defined SDA/SCL pins except ESP8266 and ATtiny85 or see https://www.arduino.cc/en/reference/wire or see the Adafruit_ADS1X15-master README.md
        #else
            #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 12 )
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
        #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )  //The HX711 does NOT communicate over open-collector I2C; pick your own pins for comming with it other than SS, CLK, MOSI, and MISO of SPI.  The digital interface to the HX711 is a proprietary SPI-like interface using CLK to select and Data is always lo-z (can't share either)
            #include <HX711.h>  //From https://github.com/bogde/HX711  This ADC has no CS pin so the library must use software SPI with dedicated CLK pin.  Not data selectable as would be in I2C, nor CS selectable - must be on dedicated CLK & Data lines
            HX711 hx711( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC ); // This library allows us to set the pins and gain here or later in a .begin().   
            #undef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
            #define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG 306                // If HIGHEST_SENSI_OUTBOARD_ADC_TYPE has a sweet spot of max sensitivity, unlike true op-amp.  (HX711 == 305, ranging from 1.49 to 1.507 vdc depending which scale is used to read it).  This will also be discovered and stored in EEPROM in a future revision
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1232 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1242 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 ) //Which 24-bit ADC is single-ended?  ADS1242 It is 23 bits hopefully
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD7780 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD779x ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == MAX112x0 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == LTC2400 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1231 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #else
            #error “This add-on ADC resolution is not supported in this sketch version."
        #endif
    #endif
#else
    #ifdef HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC
        #undef HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC
    #endif
    #define HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC ANALOG_INPUT_BITS_OF_BOARD
    #ifdef HIGHEST_SENSI_OUTBOARD_ADC_TYPE
        #undef HIGHEST_SENSI_OUTBOARD_ADC_TYPE
    #endif
    #ifdef HIGHEST_SENSI_PGA_GAIN_FACTOR
        #undef HIGHEST_SENSI_PGA_GAIN_FACTOR
    #endif
#endif
#ifndef LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER
    #define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 65536
#endif
#ifndef BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0
    #define BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 0
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
#ifdef LM334_BRIDGES
    #if ( 1 > LM334_BRIDGES + 0 ) //This traps both a null and all negatives - they are invalid and get changed to a 1 value, not a 0 value
        #undef LM334_BRIDGES
        #define LM334_BRIDGES 1  //Make sure it contains an integer
        #warning You are specifying LM334_BRIDGES with no number: Assuming 1 for the number of input pairs that the first analog pins form to read analog signals
    #elif ( LM334_BRIDGES == 0 )
        #undef LM334_BRIDGES     //Zero value means same as undefined so undef it to minimize variations
    #endif
#endif
#ifdef BARE_DPOT_LEG_BRIDGES
    #if ( 1 > BARE_DPOT_LEG_BRIDGES + 0 ) //This traps both a null and all negatives - they are invalid and get changed to a 1 value, not a 0 value
        #undef BARE_DPOT_LEG_BRIDGES
        #define BARE_DPOT_LEG_BRIDGES 1  //Make sure it contains an integer
        #warning You are specifying BARE_DPOT_LEG_BRIDGES with no number: Assuming 1 for the number of input pairs that the first analog pins form to read analog signals
    #elif ( BARE_DPOT_LEG_BRIDGES == 0 )
        #undef BARE_DPOT_LEG_BRIDGES     //Zero value means same as undefined so undef it to minimize variations
    #endif
#endif
#ifdef BARE_DPOT_LEGS_NOT_BRIDGED
    #if ( 1 > BARE_DPOT_LEGS_NOT_BRIDGED + 0 ) //This traps both a null and all negatives - they are invalid and get changed to a 1 value, not a 0 value
        #undef BARE_DPOT_LEGS_NOT_BRIDGED
        #define BARE_DPOT_LEGS_NOT_BRIDGED 1  //Make sure it contains an integer
        #warning You are specifying BARE_DPOT_LEGS_NOT_BRIDGED with no number: Assuming 1 for the number of input pairs that the first analog pins form to read analog signals
    #elif ( BARE_DPOT_LEGS_NOT_BRIDGED == 0 )
        #undef BARE_DPOT_LEGS_NOT_BRIDGED     //Zero value means same as undefined so undef it to minimize variations
    #endif
#endif
#ifdef LM334_BRIDGES
    #define TAKE_LEG_VOLTAGE_UP true
    #define TAKE_LEG_VOLTAGE_DOWN false
    #define TIMES_LIMIT ( 3 * DPOT_RATIO )
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
#if not ( ( defined LM334_BRIDGES ) || ( defined BARE_DPOT_LEG_BRIDGES ) || ( defined BARE_DPOT_LEGS_NOT_BRIDGED ) )
    #undef POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC
    #undef POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC
    #undef TEST_STEP_UP_DOWN
    #undef AUTO_BRIDGE_BALANCING
    #undef DPOTS_PER_BRIDGED_BARE_LEG
    #undef 
#else
    #define NUM_OF_LEGS_PER_BRIDGE 2
    #define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER_NEGATIVE ( 0 - LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
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
    #include "SPI.h" //This is the hardware implementation of SPI with CS pin selectable devices, not addressable via data and unidirectional data in and data out pins.  The software implementation uses shiftIn() instead and is slower but flexible which pins get used and can be used adjunctive for cases where a chip has no CS pin.  Adafruit_ADS1015 uses the shiftIn() method, so those pins are user's choice.  Not data addressable as would be in I2C

    #ifdef POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC
        #if ( 1 > POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC + 0 )
            #undef POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC
            #define POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC 0 //make sure it contains a bridge index, default is bridge 0
        #endif
    #endif
    #ifdef POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC
        #if ( 1 > POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC + 0 )
            #undef POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC
            #define POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC 0 //make sure it contains a bridge index, default is bridge 0
        #endif
    #endif

#if ( defined LM334_BRIDGES ) && ( not defined BARE_DPOT_LEG_BRIDGES ) && ( not defined BARE_DPOT_LEGS_NOT_BRIDGED )
        #define NUM_OF_DPOTS ( DPOTS_PER_LM334_LEG * LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
        #define PINS_NEEDED_TO_READ_DPOT_LEGS ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
        #define NUM_OF_DPOT_CIRCUITS_FOR_OUTBOARDS ( PINS_NEEDED_TO_READ_DPOT_LEGS / 2 )
    #elif ( not defined LM334_BRIDGES ) && ( defined BARE_DPOT_LEG_BRIDGES ) && ( not defined BARE_DPOT_LEGS_NOT_BRIDGED )
        #define NUM_OF_DPOTS ( DPOTS_PER_BRIDGED_BARE_LEG * NUM_OF_LEGS_PER_BRIDGE * BARE_DPOT_LEG_BRIDGES )
        #define PINS_NEEDED_TO_READ_DPOT_LEGS ( BARE_DPOT_LEG_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
        #define NUM_OF_DPOT_CIRCUITS_FOR_OUTBOARDS ( PINS_NEEDED_TO_READ_DPOT_LEGS / 2 )
    #elif ( defined LM334_BRIDGES ) && ( defined BARE_DPOT_LEG_BRIDGES ) && ( not defined BARE_DPOT_LEGS_NOT_BRIDGED )
        #define NUM_OF_DPOTS ( ( DPOTS_PER_LM334_LEG * LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) + ( DPOTS_PER_BRIDGED_BARE_LEG * NUM_OF_LEGS_PER_BRIDGE * BARE_DPOT_LEG_BRIDGES ) )
        #define PINS_NEEDED_TO_READ_DPOT_LEGS ( ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) + ( BARE_DPOT_LEG_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) )
        #define NUM_OF_DPOT_CIRCUITS_FOR_OUTBOARDS ( PINS_NEEDED_TO_READ_DPOT_LEGS / 2 )
    #elif ( not defined LM334_BRIDGES ) && ( not defined BARE_DPOT_LEG_BRIDGES ) && ( defined BARE_DPOT_LEGS_NOT_BRIDGED )
        #define NUM_OF_DPOTS ( DPOTS_PER_UNBRIDGED_BARE_LEG * BARE_DPOT_LEGS_NOT_BRIDGED )
        #define PINS_NEEDED_TO_READ_DPOT_LEGS BARE_DPOT_LEGS_NOT_BRIDGED
        #define NUM_OF_DPOT_CIRCUITS_FOR_OUTBOARDS ( ( PINS_NEEDED_TO_READ_DPOT_LEGS / 2 ) + BARE_DPOT_LEGS_NOT_BRIDGED )
    #elif ( defined LM334_BRIDGES ) && ( not defined BARE_DPOT_LEG_BRIDGES ) && ( defined BARE_DPOT_LEGS_NOT_BRIDGED )
        #define NUM_OF_DPOTS ( ( DPOTS_PER_LM334_LEG * LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) + ( DPOTS_PER_UNBRIDGED_BARE_LEG * BARE_DPOT_LEGS_NOT_BRIDGED ) )
        #define PINS_NEEDED_TO_READ_DPOT_LEGS ( ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) + BARE_DPOT_LEGS_NOT_BRIDGED )
        #define NUM_OF_DPOT_CIRCUITS_FOR_OUTBOARDS ( ( PINS_NEEDED_TO_READ_DPOT_LEGS / 2 ) + BARE_DPOT_LEGS_NOT_BRIDGED )
    #elif ( not defined LM334_BRIDGES ) && ( defined BARE_DPOT_LEG_BRIDGES ) && ( defined BARE_DPOT_LEGS_NOT_BRIDGED )
        #define NUM_OF_DPOTS ( ( DPOTS_PER_BRIDGED_BARE_LEG * NUM_OF_LEGS_PER_BRIDGE * BARE_DPOT_LEG_BRIDGES ) + ( DPOTS_PER_UNBRIDGED_BARE_LEG * BARE_DPOT_LEGS_NOT_BRIDGED ) )
        #define PINS_NEEDED_TO_READ_DPOT_LEGS ( ( BARE_DPOT_LEG_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) + BARE_DPOT_LEGS_NOT_BRIDGED )
        #define NUM_OF_DPOT_CIRCUITS_FOR_OUTBOARDS ( ( PINS_NEEDED_TO_READ_DPOT_LEGS / 2 ) + BARE_DPOT_LEGS_NOT_BRIDGED )
    #elif ( defined LM334_BRIDGES ) && ( defined BARE_DPOT_LEG_BRIDGES ) && ( defined BARE_DPOT_LEGS_NOT_BRIDGED )
        #define NUM_OF_DPOTS ( ( DPOTS_PER_LM334_LEG * LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) + ( DPOTS_PER_BRIDGED_BARE_LEG * NUM_OF_LEGS_PER_BRIDGE * BARE_DPOT_LEG_BRIDGES ) + ( DPOTS_PER_UNBRIDGED_BARE_LEG * BARE_DPOT_LEGS_NOT_BRIDGED ) )
        #define PINS_NEEDED_TO_READ_DPOT_LEGS ( ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) + ( BARE_DPOT_LEG_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) + BARE_DPOT_LEGS_NOT_BRIDGED )
        #define NUM_OF_DPOT_CIRCUITS_FOR_OUTBOARDS ( ( PINS_NEEDED_TO_READ_DPOT_LEGS / 2 ) + BARE_DPOT_LEGS_NOT_BRIDGED )
/* This condition was caught above before this if construct
    #else
        #define PINS_NEEDED_TO_READ_DPOT_LEGS 0
        #define NUM_OF_DPOTS 0
        #define NUM_OF_DPOT_CIRCUITS_FOR_OUTBOARDS 0
*/
#endif
#if ( NUM_OF_DPOT_CIRCUITS_FOR_OUTBOARDS > NUM_OF_OUTBOARDS_PLOTTED )
    #error Are you aware that more DPot legs are getting configured than is justified for the number of ADCs this board has?
    #error If that is really what you want, disable these two error lines
#endif

#if ( PINS_NEEDED_TO_READ_DPOT_LEGS > NUM_ANALOG_INPUTS )
    #error Are you aware that more DPot legs are getting configured than the number of Analog Input pins this board has?
    #error If that is really what you want, disable these two error lines
#endif

#if ( NUM_OF_INBOARDS_PLOTTED > NUM_ANALOG_INPUTS )
    #error Are you aware that this is asking for more NUM_OF_INBOARDS_PLOTTED than the number of Analog Input pins this board has?
    #error If that is really what you want, disable these two error lines
#endif
#if ( not defined LM334_BRIDGES || ( 1 > LM334_BRIDGES + 0 ) )
    #ifdef LM334_BRIDGES
        #undef LM334_BRIDGES
    #endif
    #define LM334_BRIDGES 0
#endif
#if ( not defined BARE_DPOT_LEG_BRIDGES || ( 1 > BARE_DPOT_LEG_BRIDGES + 0 ) )
    #ifdef BARE_DPOT_LEG_BRIDGES
        #undef BARE_DPOT_LEG_BRIDGES
    #endif
    #define BARE_DPOT_LEG_BRIDGES 0
#endif

//start sizes == DPOTS_PER_LM334_LEG
    #define START_LEG_INDEX_OF_BARE_BRIDGES ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
    #define START_DPOT_INDEX_BEGINNING_BARE_BRIDGES ( START_LEG_INDEX_OF_BARE_BRIDGES + ( DPOTS_PER_LM334_LEG * LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) )
//sizes here == DPOTS_PER_UNBRIDGED_BARE_LEG
    #define START_LEG_INDEX_OF_LEGS_NOT_BRIDGED 1 //( ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) + ( NUM_OF_LEGS_PER_BRIDGE * BARE_DPOT_LEG_BRIDGES ) )
    #define START_DPOT_INDEX_BEGINNING_BARE_LEG_UNBRIDGED ( START_DPOT_INDEX_BEGINNING_BARE_BRIDGES + ( DPOTS_PER_BRIDGED_BARE_LEG * NUM_OF_LEGS_PER_BRIDGE * BARE_DPOT_LEG_BRIDGES ) )
//sizes here == DPOTS_PER_UNBRIDGED_BARE_LEG

    #if ( LM334_BRIDGES == 0 )
        #undef LM334_BRIDGES
    #endif
    #if ( BARE_DPOT_LEG_BRIDGES == 0 )
        #undef BARE_DPOT_LEG_BRIDGES
    #endif

    static uint8_t DPotPins[ NUM_OF_DPOTS ]; //This being an array, it can't be filled during preprocessing to make it a type const
    static uint16_t DPotSettings[ NUM_OF_DPOTS ];
    #define MAXPOTSETTG 256

//    #if ( LM334_BRIDGES > 0 ) Just b/c this conforms to the pattern
//When using one or two 3:8 decoders, note that these pins numbers must be greater than 127
//Never use bit 6 of DPotPin for anything except to designate the second pot in a dual pkg
/*
    To scale up to multiple values of digipotsperleg:
x1   fix BANK_0_LEG_0_LSB_DPOT names and such
x2   fix index order within DPotSettings and DPotPins
>3   fix LSB_DPOT_B0L0_STARTVALUE names and such
4   fix DPOT_RATIO to something that will work where it is used
5   
Never use bit 6 of DPotPin for anything except to designate the second pot in a dual pkg
  
*/    
//If a digipot is the second in a pkg, OR that digipot's pin number with B0100000 (add 64) like so: #define LSB_DPOT_B0L0_PIN ( 7 + 64 ) for when pin 7 is the physical pin
//If you find that you don't understand that, I'd encourage you to learn the topics of converting between hexadecimal, decimal, and binary and to learn bitwise boolean operations
    #define LSB_DPOT_B0L0_PIN 7         // Signal LSB fine adjust digital pot's CS line connected to here
    #define LSB_DPOT_B0L0_STARTVALUE 40 //( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 

    #define LSB_DPOT_B0L1_PIN 10        // Reference LSB fine adjust digital pot's CS line connected to here
    #define LSB_DPOT_B0L1_STARTVALUE 1  //or ( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 

#if ( DPOTS_PER_LM334_LEG > 1 )
    #define NON_LSB_DPOT_1_B0L0_PIN 6         // Signal MID digital pot's CS line connected to here
    #define NON_LSB_DPOT_1_B0L0_STARTVALUE 119//or ( MAXPOTSETTG / 2 )  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 

    #define NON_LSB_DPOT_1_B0L1_PIN 9         // Reference MID digital pot's CS line connected to here
    #define NON_LSB_DPOT_1_B0L1_STARTVALUE 114//( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 

#if ( DPOTS_PER_LM334_LEG > 2 )
    #define NON_LSB_DPOT_2_B0L0_PIN 5         // Signal MSB digital pot's CS line connected to here
    #define NON_LSB_DPOT_2_B0L0_STARTVALUE 0  // Reference MSB

    #define NON_LSB_DPOT_2_B0L1_PIN 8         // Reference MSB digital pot's CS line connected to here
    #define NON_LSB_DPOT_2_B0L1_STARTVALUE 0  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
#endif
#endif
    #if ( LM334_BRIDGES > 1 )
        #error none of this below works, yet.  It is in process of development; i.e., Only a single bridge of digipots is supported at this time...
        #define LSB_DPOT_B1L0_PIN 7  // digital pot's CS line connected to here. fine adjust signal leg
        #define LSB_DPOT_B1L1_PIN 10 // digital pot's CS line connected to here. fine adjust reference leg
        #define LSB_DPOT_B1L0_STARTVALUE (MAXPOTSETTG / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #define LSB_DPOT_B1L1_STARTVALUE (MAXPOTSETTG / 2)  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
#if ( DPOTS_PER_LM334_LEG > 1 )
        #define NON_LSB_DPOT_1_B1L0_PIN 6  // digital pot's CS line connected to here. coarse adjust signal leg
        #define NON_LSB_DPOT_1_B1L1_PIN 9  // digital pot's CS line connected to here. coarse adjust reference leg
        #define NON_LSB_DPOT_1_B1L0_STARTVALUE (MAXPOTSETTG / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #define NON_LSB_DPOT_1_B1L1_STARTVALUE (MAXPOTSETTG / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
#if ( DPOTS_PER_LM334_LEG > 2 )
        #define NON_LSB_DPOT_2_B1L0_PIN 5  // digital pot's CS line connected to here. coarse adjust signal leg
        #define NON_LSB_DPOT_2_B1L1_PIN 8  // digital pot's CS line connected to here. coarse adjust reference leg
        #define NON_LSB_DPOT_2_B1L0_STARTVALUE (MAXPOTSETTG / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #define NON_LSB_DPOT_2_B1L1_STARTVALUE (MAXPOTSETTG / 2)   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
#endif
#endif
        #if ( LM334_BRIDGES > 2 )
            #if ( LM334_BRIDGES > 3 )
                #if ( LM334_BRIDGES > 4 )
                    #if ( LM334_BRIDGES > 5 )
                        #if ( LM334_BRIDGES > 6 )
                        #endif
                    #endif
                #endif
            #endif
        #endif
    #endif
#endif
    #if ( ( defined ARDUINO_AVR_LEONARDO ) \
    && ( NON_LSB_DPOT_2_B0L0_PIN == 2 || NON_LSB_DPOT_2_B0L0_PIN == 3 \
    || NON_LSB_DPOT_1_B0L0_PIN == 2 || NON_LSB_DPOT_1_B0L0_PIN == 3 \
    || LSB_DPOT_B0L0_PIN == 2 || LSB_DPOT_B0L0_PIN == 3 \
    || NON_LSB_DPOT_2_B0L1_PIN == 2 || NON_LSB_DPOT_2_B0L1_PIN == 3 \
    || NON_LSB_DPOT_1_B0L1_PIN == 2 || NON_LSB_DPOT_1_B0L1_PIN == 3 \
    || LSB_DPOT_B0L1_PIN == 2 || LSB_DPOT_B0L1_PIN == 3 \
    ) )
//        #if ( LM334_BRIDGES > 1 )
//            #if ( LM334_BRIDGES > 2 )
//                #if ( LM334_BRIDGES > 3 )
//                    #if ( LM334_BRIDGES > 4 )
//                        #if ( LM334_BRIDGES > 5 )
//                            #if ( LM334_BRIDGES > 6 )
//                            #endif
//                        #endif
//                    #endif
//                #endif
//            #endif
//        #endif //Expand this if sketch expands
//    )//This style of compiler preprocessor nested definition doesn't really work.  It is here to show the desired concept for Leonardo pin checking 
    
        #error "The pins being used for clock and data of the ADC conflict with the I2C pins used by ADS1x15.  See https://www.arduino.cc/en/reference/wire and the Adafruit_ADS1X15-master README.md.  Remove this warning once you are satisfied one way or another"
/* EEPROM and nonvolatile settings are only available with >8.5, <12.5 Vdc applied to CS pins of MCP4162, which we don't have with mere Arduino: */
    #define MATCHING_TO_SIGNAL_LEG true
#endif

#if ( ARDUINO_ARCH_XI || ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD ) //These are the boards known to have 12 bit analog inputs
    #ifdef ANALOG_INPUT_BITS_OF_BOARD
        #undef ANALOG_INPUT_BITS_OF_BOARD
    #endif
    #define ANALOG_INPUT_BITS_OF_BOARD 12  //These boards have 12 bit
#endif

#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
    #define SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC - ANALOG_INPUT_BITS_OF_BOARD )
#else
    #define SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE 0
#endif

/*
DEFINING INDEX_OF_INBOARDS_NOT_SUPERIMPOSED:
*/

#if defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS \
    && ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS > 0 )

    #if ( ( defined LM334_BRIDGES ) && ( LM334_BRIDGES > 0 ) && ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * NUM_OF_LEGS_PER_BRIDGE ) < NUM_OF_INBOARDS_PLOTTED ) //use the smaller of the two possibilities
        #define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * NUM_OF_LEGS_PER_BRIDGE )
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

#if ( ( defined PINS_NEEDED_TO_READ_DPOT_LEGS ) && ( PINS_NEEDED_TO_READ_DPOT_LEGS > NUM_OF_INBOARDS_PLOTTED ) )
    #define INDEX_OF_OUTBOARDS PINS_NEEDED_TO_READ_DPOT_LEGS
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
uint16_t PlotterLoops;
#ifdef DEBUG
    static char szFull[ ] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#endif
#define HEIGHT_OF_A_PLOT_LINESPACE ( ( uint32_t )pow( 2, HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC ) ) //casting as uint32_t allows calculations properly
#define PLOTTER_MAX_SCALE ( ( uint32_t )( HEIGHT_OF_A_PLOT_LINESPACE * NUMBER_OF_LINESPACES ) )
#define HALF_HEIGHT_OF_A_PLOT_LINESPACE ( ( uint32_t )( HEIGHT_OF_A_PLOT_LINESPACE / 2 ) )
#ifdef AUTO_BRIDGE_BALANCING
    #define HALF_HEIGHT_INBOARD_SCALE_OF_A_PLOT_LINESPACE ( pow( 2, ANALOG_INPUT_BITS_OF_BOARD - 1 ) )
    static uint16_t CounterForTraceOutOfRangeTooLong[ NUM_OF_OUTBOARDS_PLOTTED ]; //This is to prevent infinite loop with AUTO_BRIDGE_BALANCING
#endif
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
void ReadAndPlotFromAllADCsInAndOutboard( uint32_t, bool = false );
static uint8_t* AnalogPinArray = 0; //Initializing to 0 allows functions that would use it to know whether valid or not

#if defined LM334_BRIDGES || defined BARE_DPOT_LEG_BRIDGES
    bool MatchBridgeLegSignalToReference( bool = false, uint8_t = 0, bool = false );
    bool SetDPotsReferenceLeg( bool = false, uint8_t = 0, bool = false, int = 0, const bool = false ); //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.  
#endif
#if defined LM334_BRIDGES || defined BARE_DPOT_LEG_BRIDGES || defined BARE_DPOT_LEGS_NOT_BRIDGED
    uint16_t MidTwoOfFourSum( uint8_t );

    void PrintDPotSettings()
    {
        Serial.print( F( "DPot settings per bridge" ) );
        for( uint8_t LM334_bridge = 0; LM334_bridge < LM334_BRIDGES; LM334_bridge++ ) //( DPOTS_PER_LM334_LEG * LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
        {
            Serial.print( F( ", LM334_bridge[" ) );
            Serial.print( LM334_bridge );
            Serial.print( F( "]" ) );
            for( uint8_t digipot_unit = 0; digipot_unit < DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE; digipot_unit++ )
            {//DPOTS_PER_LM334_LEG
                Serial.print( F( ", DPot[" ) );
                Serial.print( DPotPins[ digipot_unit + ( LM334_bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] );
                Serial.print( F( "]" ) );
                if( digipot_unit < DPOTS_PER_LM334_LEG )
                    Serial.print( F( ", signal " ) );
                else
                    Serial.print( F( ", reference " ) );
//#error The next construct maybe isn't working as expected?
                if( ( digipot_unit % DPOTS_PER_LM334_LEG ) == 0 )
                {
                    Serial.print( F( "LSB " ) );
                }
                if( ( digipot_unit % DPOTS_PER_LM334_LEG ) == DPOTS_PER_LM334_LEG - 1 )
                {
                    Serial.print( F( "MSB " ) );
                }
                else if( ( digipot_unit % DPOTS_PER_LM334_LEG ) != 0 )
                    Serial.print( F( "MID " ) );
                Serial.print( F( "setting=" ) );
                Serial.print( DPotSettings[ digipot_unit + ( LM334_bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] );
                if( digipot_unit == 0 || digipot_unit == DPOTS_PER_LM334_LEG )
                {
                    if( digipot_unit < DPOTS_PER_LM334_LEG )
                        Serial.print( F( ", signal" ) );
                    else
                        Serial.print( F( ", reference" ) );
                    if( AnalogPinArray == 0 )
                    {
                        Serial.println( F( "AnalogPinArray not malloc'd yet. Unable to know pin numbers to read them. Failing" ) );
                        return;
                    }
                    Serial.print( F( " voltage=" ) );
                    if( digipot_unit < DPOTS_PER_LM334_LEG )
                        Serial.print( MidTwoOfFourSum( LM334_bridge ) / 2 );
                    else
                        Serial.print( MidTwoOfFourSum( LM334_bridge + 1 ) / 2 );
                    Serial.print( F( "> " ) );
                }
            }
        }
#ifdef BARE_DPOT_LEG_BRIDGES
        for( uint8_t bare_DPot_bridge = 0; bare_DPot_bridge < BARE_DPOT_LEG_BRIDGES; bare_DPot_bridge++ )
        {;
        }
#endif
#ifdef BARE_DPOT_LEGS_NOT_BRIDGED
        for( uint8_t bare_DPot_leg = 0; bare_DPot_leg < BARE_DPOT_LEGS_NOT_BRIDGED; bare_DPot_leg++ )
        {;
        }
#endif
    }

/*

I would expect the arithmetic and other aspects of algorithms in the following function could be optimized for better speed and/or size, but I'm not up to it right now

*/
    short getPinIndex( const uint8_t DPotPin )
    {
        if( AnalogPinArray == 0 ) return -1;
        for( uint8_t index = 0; index < DPOTS_PER_LM334_LEG * LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE; index++ )
        { 
            if( DPotPin == DPotPins[ index ] )
            {
                Serial.print( F( "Found pin [" ) );
                Serial.print( DPotPin );
                Serial.print( F( "] w/Setting=[" ) );
                Serial.print( DPotSettings[ index ] );
                Serial.print( F( "] about to be manipulated," ) );
                //offset code removed from here
            }
            return index;
        }
        return -1;
    }

    bool setPotValue( uint8_t DPotPin/*can't be ptr b/c needs to set pins by literal numbers in some cases*/, uint16_t value )
    { //This doesn't use the pin index so that non-array pins can be set to 0 during program development testing different size DPot bridges
        Serial.print( F( "DPotSettings[" ) );
        Serial.print( DPotPin );
        Serial.print( F( "]=" ) );
        short index = getPinIndex( DPotPin );
        Serial.print( F( ", =" ) );
        Serial.print( value );
//        Serial.print( F( ",.." ) );
        if( ( value < 0 ) || ( value > MAXPOTSETTG ) ) return false;
        if( index > -1 )
            DPotSettings[ index ] = value;
        Serial.print( F( ", =" ) );
        Serial.print( value );
        Serial.print( F( ",..(binary=" ) );
        Serial.print( value, BIN );
        Serial.print( F( ")" ) );
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
//This is not operational, it is just a first proposed step to give capability for many ADCs
        if( DPotPin >= 128 ) //Pins numbered below 128 are normal digital inboard pins
        {//Pins numbered above 127 are outboard pins provided through the dual 74LV138 decoding circuitry
         //The two 74LV138 each have three enable pins but we only use one.  It would require 7 pins to address the two devices simultaneously.  Use 'em since we have them...it'll save a part for latch
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A0_PIN,  *DPotPin & B1 );  //These address bits are always necessary
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A1_PIN,  *DPotPin & B10 ); //These address bits are always necessary
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A2_PIN,  *DPotPin & B100 ); //These address bits are always necessary
            digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A0_PIN, *DPotPin & B1000 ); //This decoder might not be present
            digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A1_PIN, *DPotPin & B10000 ); //This decoder might not be present
            digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A2_PIN, *DPotPin & B100000 );  //This decoder might not be present
//bit B1000000 (bit 7, 128 and above) is reserved for virtualizing the second DPot in a dual DPot pkg MCP42xxx
//bit B100000 (bit 6, 64) is reserved to designate the second pot in a dual pkg MCP42xxx. Never use bit 6 of *DPotPin for anything except that
            DPotPin = BOTH_STAGES_3_TO_8_DECODER_ENABLE_PIN; // In prep for next instruction DPotPin gets changed to a normal pin number
        }
#endif
//        Serial.print( F( "." ) );
        digitalWrite( DPotPin & 0x3FF, LOW ); //By this line, DPotPin is no longer >= 128 if it ever was
//        Serial.print( DPotPin & 0x3FF );
//        Serial.print( F( "." ) );
//        Serial.print( ( value & 0x100 ) ? ( DPotPin & 0x400 ? 0x11 : 1 ) : ( DPotPin & 0x400 ? 0x10 : 0 ), BIN );
//        Serial.print( ( value & 0x100 ) ? 1 : 0 );
        SPI.transfer( ( value & 0x100 ) ? 1 : 0 );
//        SPI.transfer( ( value & 0x100 ) ? ( DPotPin & 0x400 ? 0x11 : 1 ) : ( DPotPin & 0x400 ? 0x10 : 0 ) ); //This is the way we allow dual DPot devices MCP42xxx
//        Serial.print( F( "." ) );
//        Serial.print( value & 0xFF );
        SPI.transfer( value & 0xFF ); // send value (0~255)
//        Serial.print( F( "." ) );
/**********************************************************************************************************************************************************
When dual pots are employed (MCP42XXX) this is the way to control the second DPOT in the pkg:  the first digi pot of a pkg is addressed with true pin number,
the second digipot in the pkg is addressed by adding 64 to the physical pin number driving the pkg, creating a virtual pin number for that second DPot of the pkg
        SPI.transfer( ( value & 0x100 ) ? 0x11 : 0x10 ); //NOTE THE LEADING ONE HERE THAT DOESN'T APPEAR FOR MCP41XXX
        SPI.transfer( value & 0xff ); // send value (0~255)

  In order to utilize this method, both dual pots share a single physical CS (*DPotPin) pin (remember ones above 127 pin numbers are connected via 3-to-8 decoders)
  but virtually the second DPot's physical *DPotPin must be OR'd with 0x40 (adding 64) in this sketch.  Note that two different schemes of dual DPot can exist: 
  duals shared on same leg and duals shared across legs.  By adhering to the afore-described pin numbering methodology, either scheme or both mixed 
  throughout the system will work fine.  Note that if any boards have actual physical pins numbered above 64, those cannot be used for *DPotPins without sketch
  modification to accommodate it.
  
***********************************************************************************************************************************************************/
        digitalWrite( DPotPin & 0x3FF, HIGH );
//        Serial.print( F( "got set. " ) );
//        Serial.flush();
    }
    
    int offsetPotValue( uint8_t indexInDPotPinsArray,/*CS of DPot in pkg, can be ptr b/c this is offset so array is built and populated with this pin*/ \
        short value, \
        uint16_t indexLegInVirtualLegList ) //Helps know which ADC, use also to calculate the DPot index in the DPotSettings and DPotPins arrays of the first DPot in this leg

    { //The pins referenced are NOT the Analog Input pins of the board, but rather they are one-per-DPot Digital pins to the CS lines

        uint8_t* DPotPin = &DPotPins[ indexInDPotPinsArray ];

        uint8_t DPotsInThisLeg = \
        indexLegInVirtualLegList < START_LEG_INDEX_OF_BARE_BRIDGES ? \
        DPOTS_PER_LM334_LEG \
        : ( indexLegInVirtualLegList < START_LEG_INDEX_OF_LEGS_NOT_BRIDGED ? \
        DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG );

//determine whether to use START_DPOT_INDEX_BEGINNING_BARE_LEG_UNBRIDGED instead

        uint8_t indexLegsFirstDPotInSettingsArray = \
        indexInDPotPinsArray < START_DPOT_INDEX_BEGINNING_BARE_BRIDGES ? \
        ( indexInDPotPinsArray - ( indexInDPotPinsArray % DPOTS_PER_LM334_LEG ) ) \
        : ( indexInDPotPinsArray < START_LEG_INDEX_OF_LEGS_NOT_BRIDGED ) ? \
        ( indexInDPotPinsArray - ( indexInDPotPinsArray - START_DPOT_INDEX_BEGINNING_BARE_BRIDGES ) % DPOTS_PER_BRIDGED_BARE_LEG ) \
        : indexInDPotPinsArray - ( indexInDPotPinsArray - DPOTS_PER_UNBRIDGED_BARE_LEG ) % DPOTS_PER_UNBRIDGED_BARE_LEG;


        Serial.print( F( "Entering offsetPotValue() with indexLegsFirstDPotInSettingsArray=" ) );
        Serial.print( indexLegsFirstDPotInSettingsArray );
        Serial.print( F( ",. and DPotsInThisLeg=" ) );
        Serial.print( DPotsInThisLeg );
        return setPotValue( DPotPins[ indexInDPotPinsArray ], DPotSettings[ indexInDPotPinsArray ] + value );
        return 0;
/*
NEW STYLE OF ALGORITHM IN PROGRESS BELOW

*/

//#error Where we are: in the middle of changing these args to include relying on the following new macros:
/* INdexes and element sizes of the DPotSettings array calculated from indexLegInVirtualLegList

     indexLegInVirtualLegList < START_LEG_INDEX_OF_BARE_BRIDGES ? DPOTS_PER_LM334_LEG : ( indexLegInVirtualLegList < START_LEG_INDEX_OF_LEGS_NOT_BRIDGED ? DPOTS_PER_UNBRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ) 

//start sizes == DPOTS_PER_LM334_LEG
    #define START_LEG_INDEX_OF_BARE_BRIDGES ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
//sizes here == DPOTS_PER_BRIDGED_BARE_LEG
    #define START_LEG_INDEX_OF_LEGS_NOT_BRIDGED ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) + ( NUM_OF_LEGS_PER_BRIDGE * BARE_DPOT_LEG_BRIDGES )
//sizes here == DPOTS_PER_UNBRIDGED_BARE_LEG
*/
    }

    bool stepAdjustDPotsForThisLeg( uint8_t DigiPotLeg, bool PosOrNeg = TAKE_LEG_VOLTAGE_DOWN, bool JustQueryingWhetherSettingsAreMaxedOut = false ) //default direction will be positive
    { // This effectively increments or decrements LSB digipot setting just once
#if ( DPOTS_PER_LM334_LEG > 2 )
        uint8_t MSBpotPin = DPotPins[ ( DigiPotLeg * DPOTS_PER_LM334_LEG ) + 2 ];
        uint16_t* MSBpotValue = &DPotSettings[ ( DigiPotLeg * DPOTS_PER_LM334_LEG ) + 2 ];
#endif
#if ( DPOTS_PER_LM334_LEG > 1 ) //The MSB will not exist
        uint8_t MIDPotPin = DPotPins[ ( DigiPotLeg * DPOTS_PER_LM334_LEG ) + 1 ];
        uint16_t* MIDPotValue = &DPotSettings[ ( DigiPotLeg * DPOTS_PER_LM334_LEG ) + 1 ];
#endif
        uint8_t LSBpotPin = DPotPins[ DigiPotLeg * DPOTS_PER_LM334_LEG ];
        uint16_t* LSBpotValue = &DPotSettings[ DigiPotLeg * DPOTS_PER_LM334_LEG ];
        if( JustQueryingWhetherSettingsAreMaxedOut )
        {//returning false means failure of digipot settings that they are either maxed high or minimized zeroes whichever one was queried
#if ( DPOTS_PER_LM334_LEG == 3 )
            if( !( *MSBpotValue == *MIDPotValue == *LSBpotValue ) ) return true;
#endif
#if ( DPOTS_PER_LM334_LEG == 2 )
            if( !( *MIDPotValue == *LSBpotValue ) ) return true;
#endif
            if( !PosOrNeg ) //asking whether the voltage is as low as possible by having the setting as high as possible
            {
                if( *LSBpotValue == MAXPOTSETTG ) return false;
            }
            else if( *LSBpotValue == 0 ) return false;
            return true;
        }
//        while ( !Serial );
//        Serial.print( F( " stepAdjustDPotsForThisLeg called" ) );
//        Serial.print( F( " sADFTLc " ) );
        #ifdef DEBUG
            Serial.print( F( " on " ) );
            Serial.print( LSBpotPin );
        #endif
//        Serial.print( F( " going " ) );
//        Serial.print( !PosOrNeg ? "up ": "down ");
        #ifdef DEBUG
            Serial.println();
        #endif
        //if going up and TotalValueCoarse is already MAXPOTSETTG * 2, add one to value_fine if it is less than MAXPOTSETTG, else return false; save new value; return true
        //if going up still and either coarse value is MAXPOTSETTG, only increment the other value, save new, return true;
        //if going up and neither coarse value is MAXPOTSETTG, increment MID with a switch statement, save new
        Serial.print( F( " Entering " ) );
        PrintDPotSettings();
/*
        for( uint8_t pin = 0; pin < 6; pin++ )
        {
            Serial.print( F( " Entering DPotSettings[" ) );
            Serial.print( DPotPins[ pin ] );
            Serial.print( F( "]=" ) );
            Serial.print( DPotSettings[ pin ] );
            if( pin < 5 )
                Serial.print( F( ",. " ) );
            else
                Serial.print( F( ",. " ) );
        }
*/
#if ( DPOTS_PER_LM334_LEG > 1 )
        uint16_t TotalValueCoarse = *MIDPotValue;
#if ( DPOTS_PER_LM334_LEG > 2 )
        TotalValueCoarse += *MSBpotValue;  //We abstract it this way to force MSB and MID digi pot values to conform as namesaked
        //Next lines just force significant digit compliance inside digi pot bridges
        *MSBpotValue = ( TotalValueCoarse > MAXPOTSETTG ? TotalValueCoarse - MAXPOTSETTG : 0 );
#endif
        *MIDPotValue = ( TotalValueCoarse > MAXPOTSETTG ? MAXPOTSETTG : TotalValueCoarse );
#endif
        *LSBpotValue = min( MAXPOTSETTG, *LSBpotValue );
        Serial.print( F( " before calling setPotValue " ) );
        PrintDPotSettings();
/*
        for( uint8_t pin = 0; pin < 6; pin++ )
        {
            Serial.print( F( " before calling setPotValue DPotSettings[" ) );
            Serial.print( DPotPins[ pin ] );
            Serial.print( F( "]=" ) );
            Serial.print( DPotSettings[ pin ] );
            if( pin < 5 )
                Serial.print( F( ",. " ) );
            else
                Serial.print( F( ",. " ) );
        }
        Serial.flush();
*/
#if ( DPOTS_PER_LM334_LEG > 1 )
        setPotValue( MIDPotPin, *MIDPotValue );
#if ( DPOTS_PER_LM334_LEG > 2 )
        setPotValue( MSBpotPin, *MSBpotValue );
#endif
#endif
/*
        for( uint8_t pin = 0; pin < 6; pin++ )
        {
            Serial.print( F( " after calling setPotValue on MSB DPotSettings[" ) );
            Serial.print( DPotPins[ pin ] );
            Serial.print( F( "]=" ) );
            Serial.print( DPotSettings[ pin ] );
            if( pin < 5 )
                Serial.print( F( ",. " ) );
            else
                Serial.print( F( ",. " ) );
        }
        Serial.flush();
*/
/*
        for( uint8_t pin = 0; pin < 6; pin++ )
        {
            Serial.print( F( " after calling setPotValue on MID and MSB DPotSettings[" ) );
            Serial.print( DPotPins[ pin ] );
            Serial.print( F( "]=" ) );
            Serial.print( DPotSettings[ pin ] );
            if( pin < 5 )
                Serial.print( F( ",. " ) );
            else
                Serial.print( F( ",. " ) );
        }
        Serial.flush();
*/
        setPotValue( LSBpotPin, *LSBpotValue );
        Serial.print( F( " after calling setPotValue on LSB and MID and MSB " ) );
        PrintDPotSettings();
/*
        for( uint8_t pin = 0; pin < 6; pin++ )
        {
            Serial.print( F( " after calling setPotValue on LSB and MID and MSB 

            DPotSettings[" ) );
            Serial.print( DPotPins[ pin ] );
            Serial.print( F( "]=" ) );
            Serial.print( DPotSettings[ pin ] );
            if( pin < 5 )
                Serial.print( F( ",. " ) );
            else
                Serial.print( F( ",. " ) );
        }
        Serial.flush();
*/
        if( !PosOrNeg ) //being told to increment settings, decrease volts
        {
#if ( DPOTS_PER_LM334_LEG > 1 )
            if( TotalValueCoarse >= MAXPOTSETTG * 2 )
            {
#if ( DPOTS_PER_LM334_LEG == 2 )
                *MIDPotValue = MAXPOTSETTG;
#endif
#if ( DPOTS_PER_LM334_LEG == 3 )
                *MSBpotValue = *MIDPotValue = MAXPOTSETTG;
                setPotValue( MSBpotPin, *MSBpotValue ); //This shouldn't do anything if the pot values conform to MSB and MID already
#endif
                setPotValue( MIDPotPin, *MIDPotValue ); //This shouldn't do anything if the pot values conform to MSB and MID already
                setPotValue( LSBpotPin, ++( *LSBpotValue ) > MAXPOTSETTG ? MAXPOTSETTG : *LSBpotValue );
                Serial.print( F( " TotalValueCoarse excessive" ) );
#if ( DPOTS_PER_LM334_LEG > 2 )
                Serial.print( F( ", MSB digipot set to" ) );
                Serial.print( *MSBpotValue );
#endif
                Serial.print( F( ", MID set to" ) );
                Serial.print( *MIDPotValue );
                Serial.print( F( ", LSB set to" ) );
                Serial.print( *LSBpotValue );
                Serial.print( F( ",." ) );
                if( *LSBpotValue > MAXPOTSETTG ) { *LSBpotValue = MAXPOTSETTG; return false; }
                return true;
            }
            if( *LSBpotValue + 1 > ( DPOT_RATIO - 1 ) ) 
            { //This catches *LSBpotValue having or about to have a value higher than 9 when it shouldn't.  So we cycle it down
                do 
                {
                    *LSBpotValue = ( uint16_t )( ( int16_t )*LSBpotValue - DPOT_RATIO ); //Yes, this can cause an unsigned to underflow to -1
                } while( ( ++TotalValueCoarse < MAXPOTSETTG * 2 ) && *LSBpotValue + 1 > ( DPOT_RATIO - 1 ) );
                *MIDPotValue = ( TotalValueCoarse > MAXPOTSETTG ? MAXPOTSETTG : TotalValueCoarse );
#if ( DPOTS_PER_LM334_LEG > 2 )
                *MSBpotValue = ( TotalValueCoarse > MAXPOTSETTG ?  TotalValueCoarse - MAXPOTSETTG : 0 );
                setPotValue( MSBpotPin, *MSBpotValue );
#endif
                setPotValue( MIDPotPin, *MIDPotValue );
                Serial.print( F( " called setPotValue on " ) );
                Serial.print( F( "MID and/or MSB DPotSettings DigiPotLeg leg=" ) );
                Serial.print( DigiPotLeg );
                Serial.print( F( ",." ) );
            }
#endif
            setPotValue( LSBpotPin, ++( *LSBpotValue ) );
#if ( DPOTS_PER_LM334_LEG > 2 )
            Serial.print( F( ", MSB digipot set pos=" ) );
            Serial.print( *MSBpotValue );
#if ( DPOTS_PER_LM334_LEG > 1 )
            Serial.print( F( ", MID set pos=" ) );
            Serial.print( *MIDPotValue );
#endif
#endif
            Serial.print( F( ", LSB set pos=" ) );
            Serial.print( *LSBpotValue );
            Serial.print( F( ",." ) );
            return true;
        }

//Being told to decrement settings, increase volts
#if ( DPOTS_PER_LM334_LEG > 1 )
        if( TotalValueCoarse == 0 && *LSBpotValue == 0 ) return false;
#else
        if( *LSBpotValue == 0 ) return false;
#endif
        if( ( int16_t )*LSBpotValue == 0 ) //This catches *LSBpotValue having or about to have a value lower than 0.  So we cycle it up
        {
            *LSBpotValue = DPOT_RATIO;
#if ( DPOTS_PER_LM334_LEG > 1 )
            *MIDPotValue = ( TotalValueCoarse > MAXPOTSETTG ? MAXPOTSETTG : TotalValueCoarse );
#if ( DPOTS_PER_LM334_LEG > 2 )
            *MSBpotValue = ( --TotalValueCoarse > MAXPOTSETTG ? TotalValueCoarse - MAXPOTSETTG : 0 );
            setPotValue( MSBpotPin, *MSBpotValue );
#endif
            setPotValue( MIDPotPin, *MIDPotValue );
#endif
        }
        setPotValue( LSBpotPin, --( *LSBpotValue ) );
#if ( DPOTS_PER_LM334_LEG > 2 )
        Serial.print( F( ", MSB digipot set to" ) );
        Serial.print( *MSBpotValue );
#if ( DPOTS_PER_LM334_LEG > 1 )
        Serial.print( F( ", MID set to" ) );
        Serial.print( *MIDPotValue );
#endif
#endif
        Serial.print( F( ", LSB set to" ) );
        Serial.print( *LSBpotValue );
        Serial.print( F( ",." ) );
        return true;
    }

    bool AdjustBridgeOutputPositive( uint8_t bridge ) //should not exist without any lm334 bridges or any bare bridges
    { //If all pots are maxed (positive leg to positive and negative leg to negative) return false
//        ReadAndPlotFromAllADCsInAndOutboard( !graphline ? 0 : PLOTTER_MAX_SCALE ); // I would think the operator would appreciate seeing something like this during calibration
        while( !Serial );
        Serial.print( F( " Entered AdjustBridgeOutputPositive " ) );
        Serial.print( F( " EABOP " ) );
        Serial.print( F( "with bridge=" ) );
        Serial.print( bridge );
        Serial.print( F( ",." ) );
//to read values from analog pins: use IndexInLinespaceParametersArray and add one (reference) or not (signal)
// If all are maxed out positive, return false: reference leg negative, signal leg positive

        if( !stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, TAKE_LEG_VOLTAGE_UP, true ) \
           && !stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 1, TAKE_LEG_VOLTAGE_DOWN, true ) )
           {
                while( !Serial );
                Serial.print( F( " Leaving AdjustBridgeOutputPositive unable to change" ) );
                Serial.print( F( " LABOP " ) );
                Serial.print( F( "with bridge=" ) );
                Serial.print( bridge );
                Serial.print( F( ",." ) );
                return false;
           }
/* 
lower reference leg voltage if it is higher than commonmode... level until it reaches commonmode..., 
then raise signal leg voltage until can't raise it any more, 
then resume to lower reference leg until can't lower it any more
*/
        if( SetDPotsReferenceLeg( false, bridge, false, -1 ) )
        {
            Serial.print( F( " first if construct true " ) ); 
            if( !MatchBridgeLegSignalToReference( false, bridge, false ) ) //does this return? Apparently not
            {
                Serial.print( F( " second if construct true " ) ); 
                if( !SetDPotsReferenceLeg( false, bridge, true, -1 ) )
                {
                    Serial.print( F( " third if construct true " ) ); 
                    if( !stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, TAKE_LEG_VOLTAGE_UP, true ) )
                    {
                        Serial.print( F( " fourth if construct true " ) ); 
                        if( !stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 1, TAKE_LEG_VOLTAGE_DOWN, true ) ) //while this returns false, the entire bridge is being zeroed into the desired balance
                        {
                            Serial.print( F( " fifth if construct true " ) ); 
                            return false; /*We're relying on the if construct aborting before executing all of it if not necessary*/
                        }
                    }
                }
                else
                {
                    Serial.print( F( " unable to set reference leg correctly " ) ); 
                    return false;
                }
            }
            else
            {
                Serial.print( F( " should now be matched " ) ); 
            }
        }
        else
        {
            Serial.print( F( " unable to set reference leg corrrectly " ) ); 
            return false;
        }
        CounterForTraceOutOfRangeTooLong[ bridge ] = 0;
        while( !Serial );
        Serial.print( F( " Leaving AdjustBridgeOutputPositive successful change" ) );
        Serial.print( F( " LABOP " ) );
        Serial.print( F( "with bridge=" ) );
        Serial.print( bridge );
        Serial.print( F( ",." ) );
        return true;
    }
    
    bool AdjustBridgeOutputNegative( uint8_t bridge )
    { //If all pots are maxed (positive leg to negative and negative leg to positive) return false
        while( !Serial );
        Serial.print( F( " Entered AdjustBridgeOutputNegative " ) );
        Serial.print( F( " EABON " ) );
        Serial.print( F( "with bridge=" ) );
        Serial.print( bridge );
        Serial.print( F( ",." ) );
        if( !stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, TAKE_LEG_VOLTAGE_DOWN, true ) \
           && !stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 1, TAKE_LEG_VOLTAGE_UP, true ) )
           {
                while( !Serial );
                Serial.print( F( " Leaving AdjustBridgeOutputNegative unable to change" ) );
                Serial.print( F( " LABON " ) );
                Serial.print( F( "with bridge=" ) );
                Serial.print( bridge );
                Serial.print( F( ",." ) );
              return false; //checks if reference leg is maxed to highest voltage already
           }
/*
Somewhere below the reference leg is treated wrong so as to make it compensate even though the signal leg could be used for compensate
*/
        if( SetDPotsReferenceLeg( false, bridge, false, 1 ) )
        {
            Serial.print( F( " first if construct true " ) ); 
            if( !MatchBridgeLegSignalToReference( false, bridge, false ) )
            {
                Serial.print( F( " second if construct true " ) ); 
                if( !SetDPotsReferenceLeg( false, bridge, true, 1 ) )
                {
                    Serial.print( F( " third if construct true " ) ); 
                    if( !stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, TAKE_LEG_VOLTAGE_DOWN, true ) )
                    {
                        Serial.print( F( " fourth if construct true " ) ); 
                        if( !stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 1, TAKE_LEG_VOLTAGE_UP, true ) )
                        {
                            Serial.print( F( " fifth if construct true " ) ); 
                            return false; /*We're relying on the if construct aborting before executing all of it if not necessary*/
                        }
                    }
                }
                else
                {
                    Serial.print( F( " unable to set reference leg correctly " ) ); 
                    return false;
                }
            }
            else
            {
                Serial.print( F( " should now be matched " ) ); 
            }
        }
        else
        {
            Serial.print( F( " unable to set reference leg corrrectly " ) ); 
            return false;
        }
        CounterForTraceOutOfRangeTooLong[ bridge ] = 0;
        while( !Serial );
        Serial.print( F( " Leaving AdjustBridgeOutputNegative successful change" ) );
        Serial.print( F( " LABON " ) );
        Serial.print( F( "with bridge=" ) );
        Serial.print( bridge );
        Serial.print( F( ",." ) );
        return true;
    }
#endif //Ends if using lm334 bridges

#if defined LM334_BRIDGES || defined BARE_DPOT_LEGS_NOT_BRIDGED || defined BARE_DPOT_LEG_BRIDGES
    void showDPotSettings( uint8_t ADCnumber )
    { //FUTURE  Might be useful with non-Arduino renderer, encodes DPot settings affecting this ADC to plotter output
      //inboards indices: 0 to < NUM_OF_INBOARDS_PLOTTED
      //outboards indices: INDEX_OF_OUTBOARDS + 0 to < NUM_OF_OUTBOARDS_PLOTTED

        ;
    }
#endif

void ReplotLastValuesForAllTraces( bool actuals = false )                  //If we don't execute the following construct, the signal traces will lag behind the graphline
{
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Entering ReplotLastValuesForAllTraces" ) );
#endif
    while( !Serial ) ; 
    Serial.print( F( " reprinting most recent plotline values: " ) );
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
//    showDPotSettings( thisADC ); //Not sure about doing this here or where
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

void PlotTimingLineGoingUp( bool TracesAlreadyInitializedToValidReadings = true )
{
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Entering PlotTimingLineGoingUp" ) );
#endif
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.println();
    for( uint8_t LinespaceParametersIndex = NUMBER_OF_LINESPACES - 1; LinespaceParametersIndex != 255; LinespaceParametersIndex-- )
    {
            Serial.print( F( "Timing line zero of this linespace: " ) );
            Serial.print( LinespaceParameters[ LinespaceParametersIndex ].ZeroOfThisPlotLinespace );
            ReplotLastValuesForAllTraces( true );
            Serial.print( F( "Timing line maximum of this linespace: " ) );
            Serial.print( LinespaceParameters[ LinespaceParametersIndex ].HighLimitOfThisPlotLinespace );
            ReplotLastValuesForAllTraces( true );
        #ifdef DEBUG
            while( !Serial ) ; 
                Serial.println();
            Serial.print( F( "Line 826 LinespaceParametersIndex - 1 =" ) );
            Serial.println( LinespaceParametersIndex - 1 );
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

uint16_t MidTwoOfFourSum( uint8_t AnalogPinArrayIndex ) //returns an INBOARD Analog Input pin reading, AnalogPinArrayIndex is also equal to bridge leg
{ //remove from consideration the max and min, then return avg of remaining two
    if( AnalogPinArray == 0 ) 
    {
        Serial.println( F( "MidTwoOfFourSum getting called before AnalogPinArray is initailized.  Failing" ) );
        return 0;
    }
    uint16_t value1 = analogRead( *( AnalogPinArray + AnalogPinArrayIndex ) );
    delay( 2 );
    uint16_t value2 = analogRead( *( AnalogPinArray + AnalogPinArrayIndex ) );
    delay( 2 );
    uint16_t value3 = analogRead( *( AnalogPinArray + AnalogPinArrayIndex ) );
    delay( 2 );
    uint16_t value4 = analogRead( *( AnalogPinArray + AnalogPinArrayIndex ) );
/* */
    Serial.print( F( "Pin[" ) );
    Serial.print( *( AnalogPinArray + AnalogPinArrayIndex ) );
    Serial.print( F( "] where pin index in array=[" ) );
    Serial.print( AnalogPinArrayIndex );
    Serial.print( F( "], reading one=" ) );
    Serial.print( value1 );
    Serial.print( F( ", reading two=" ) );
    Serial.print( value2 );
    Serial.print( F( ", reading three=" ) );
    Serial.print( value3 );
    Serial.print( F( ", reading four=" ) );
    Serial.print( value4 );
    Serial.print( F( ", highest reading=" ) );
    Serial.print( max( max( max( value1, value2 ), value3 ), value4 ) );
    Serial.print( F( ", lowest reading=" ) );
    Serial.print( min( min( min( value1, value2 ), value3 ), value4 ) );
    Serial.print( F( ",<" ) ); //printing something non-numeric here to make plotter ignore numerics it shouldn't plot
    Serial.flush();
    return ( uint16_t )( ( ( unsigned long )( value1 + value2 + value3 + value4 ) ) - ( unsigned long )( max( max( max( value1, value2 ), value3 ), value4 ) + min( min( min( value1, value2 ), value3 ), value4 ) ) );
}

uint32_t OneReadingFromThisOutboardADC( uint8_t );
uint16_t AnalogInputReadingTimes4IfInboard( uint8_t AnalogPinArrayIndex, bool finetune = false ) //AnalogPinArrayIndex will be either one for the reference leg or zero for the signal leg
{ //returns an INBOARD Analog Input pin reading unless finetune is true in which case the 16 LSBits are returned
    if( !finetune ) return ( MidTwoOfFourSum( AnalogPinArrayIndex ) + MidTwoOfFourSum( AnalogPinArrayIndex ) );
//get the outboard reading and take it down to 16 bits:  we need to fine tune it to zero
    uint32_t value0 = OneReadingFromThisOutboardADC( ( uint8_t )( AnalogPinArrayIndex / 2 ) ); //single-ended format back to twos comp
    //We care about is how far from center point voltage and which direction
    if( value0 > HALF_HEIGHT_OF_A_PLOT_LINESPACE )
    {
        if( value0 & 0xFFFF8000 ) value0 |= 0x4000;  //takes it down to 16 bits with bit 14 (ensures it remains positive value) representing all bits higher than it
        return ( value0 & 0x7FFF );  //makes it ones complement instead of twos complement for easier working with unsigned casting
    }
    else if( value0 < HALF_HEIGHT_OF_A_PLOT_LINESPACE )
    { //make it negative one in ones complement
        uint32_t value1 = value0;
        value0 ^= 0xFFFFFFFF;
        value0++;
        if( value1 & 0xFFFF8000 ) 
            value0 |= 0x4000;  //takes it down to 16 bits with bit 14 (ensures it remains positive value) representing all bits higher than it
        return ( value0 | 0x8000 );  //makes it ones complement negative number for easier working with unsigned casting
    }
    return 0;  //exact center
}

#if defined LM334_BRIDGES
static uint8_t SetDPotsStep = 0;

bool SetDPotsReferenceLeg( bool JustPerformOneStep = false, uint8_t bridge = 0, bool MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG = false, int upOnly_downOnly = 0, const bool comingFromMatchBridgeLegSignalToReference = false ) //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.  
{ //goal if upOnly: originates from reading being max high? possible that reference leg may need to go down (if signal leg is below CM)
 // bridge is identical value to OutboardADCindex which is needed for MATCHING_TO_SIGNAL_LEG
    static uint16_t TargetLevel;
    static uint8_t stepsize;
    static uint16_t LastAnalogInputReadingTimes4IfInboard;
//#ifdef DEBUG
    while ( !Serial ) ; //&& ( millis() - MillisStart < 8000 ) );
    Serial.print( F( "Setting up digipots: signal bridge leg=" ) );
    Serial.print( analogRead( *( AnalogPinArray + 0 + bridge ) ) );
    Serial.print( F( ", reference bridge leg=" ) );
    Serial.print( analogRead( *( AnalogPinArray + 1 + bridge ) ) );
    Serial.print( F( ", SetDPotsStep=" ) );
    Serial.print( SetDPotsStep );
    Serial.print( F( ", TargetLevel=" ) );
    Serial.print( TargetLevel );
    Serial.print( F( ", stepsize=" ) );
    Serial.println( stepsize );
//#endif
    if( SetDPotsStep != 0 )
    {
        if( SetDPotsStep == 1 ) goto SetDPotsStep1;
        if( SetDPotsStep == 2 ) goto SetDPotsStep2;
        if( SetDPotsStep == 3 ) goto SetDPotsStep3;
        if( SetDPotsStep == 4 ) goto SetDPotsStep4;
        if( SetDPotsStep == 5 ) goto SetDPotsStep5;
        if( SetDPotsStep == 6 ) goto SetDPotsStep6;
    //    if( SetDPotsStep == 7 ) goto SetDPotsStep7;
    //    if( SetDPotsStep == 8 ) goto SetDPotsStep8;
    //    if( SetDPotsStep == 9 ) goto SetDPotsStep9;
    //    if( SetDPotsStep == 10 ) goto SetDPotsStep10;
    }
    if( !comingFromMatchBridgeLegSignalToReference )
    {
        if( !MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) TargetLevel = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG;
        else TargetLevel = ( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) / 4 ) - BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0;
        Serial.print( F( "TargetLevel changed=" ) );
        Serial.print( TargetLevel );
        Serial.print( F( ". " ) );
        if( MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
            Serial.print( F( "Matching to the signal leg. " ) );


/*Next is where the Wheatstone bridge reference leg output (that connects to negative input of highest sensi ADC) is set to TargetLevel voltage level*/
        if( upOnly_downOnly == 0 )
            upOnly_downOnly = ( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) < TargetLevel ) ? 1 : -1;
        else if( upOnly_downOnly > 0 )
        {
            if( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) <= TargetLevel ) return true; //executes when reference leg voltage is higher than the target voltage and was restricted to go higher only
        }
        else
        {
            if( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) <= TargetLevel ) return true; //executes when reference leg voltage is lower than the target voltage and was restricted to go lower only
        }
        
/************************************************************************
How the set digipot leg functions work:
x1.  Determine the target voltage
x2.  Determine which direction to step
x3.  Determine if the target voltage is the correct direction.  Return if not.
>4.  Taking MID/MSB steps, step in the pre-determined direction until the target voltage is overshot, then back up one step
x5.  Taking LSB steps, step in direction until the target voltage is overshot, then back up one step while storing both the last two steps
x6.  Settle on which of the last two steps produced the closest voltage to the target voltage

*/


        stepsize = 10;
    }
    static uint16_t startpoint1;
    static uint16_t startpoint2;
    static uint8_t whileLoopTimes = 0;
    static bool goingUp = false, goingDown = false;

    if( !comingFromMatchBridgeLegSignalToReference )
    {
        Serial.print( F( "Adjusting the reference leg of digipot bridge[" ) );
        Serial.print( bridge );
        Serial.print( F( "]: " ) );
        if( ( AnalogInputReadingTimes4IfInboard( 1 /*the 1 offset specifies the reference leg for this bridge*/+ ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) < TargetLevel && upOnly_downOnly > -1 ) goingUp = true; //reference leg is lower &/or signal leg is higher plus purpose is consistent
        else goingDown = true;
        if( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) == TargetLevel )
        {
            SetDPotsStep = 0;
            return true;
        }
#if ( DPOTS_PER_LM334_LEG > 1 )
        do
        {
            do
            {
                startpoint2 = DPotSettings[ DPOTS_PER_LM334_LEG + 1 /*this offset specifies the MID for the reference leg this bridge*/ + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ]; //reference leg, MID
#if ( DPOTS_PER_LM334_LEG > 2 )
                startpoint1 = DPotSettings[ DPOTS_PER_LM334_LEG + 2 /*this offset specifies the MSB for the reference leg this bridge*/ + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ]; //reference leg, MSB
                if ( goingUp )
                {
                    //Decrease digipot values as long as they respond right
                    if( ( DPotSettings[ DPOTS_PER_LM334_LEG + 2 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= stepsize - 1 ) \
                        && ( DPotSettings[ DPOTS_PER_LM334_LEG + 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= stepsize - 1 ) ) break;
                    if( DPotSettings[ DPOTS_PER_LM334_LEG + 2 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] > stepsize - 1 )
                    {
                        offsetPotValue( DPOTS_PER_LM334_LEG + 2 /*this offset specifies the MSB for the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), 0 - stepsize, bridge * NUM_OF_LEGS_PER_BRIDGE/*being changed to become DPot index in leg  0. this is index of first DPot of leg of interest*/  );
                        if( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) == TargetLevel )
                        {
                            SetDPotsStep = 0;
                            return true;
                        }
                        if( JustPerformOneStep )
                        {
                            SetDPotsStep = 1;
                            return false;
                        }
                    }
                }
                else
                {
                    //Increase digipot values as long as they respond right
                    if( ( DPotSettings[ DPOTS_PER_LM334_LEG + 2 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] > MAXPOTSETTG - stepsize ) \
                        && ( DPotSettings[ DPOTS_PER_LM334_LEG + 1 /*this offset specifies the MID for the reference leg this bridge*/ + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] > MAXPOTSETTG - stepsize ) ) break;
                    if( DPotSettings[ DPOTS_PER_LM334_LEG + 2 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= MAXPOTSETTG - stepsize )// > stepsize - 1 )
                    {
                        offsetPotValue( DPOTS_PER_LM334_LEG + 2 /*this offset specifies the MSB for the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), stepsize, bridge * NUM_OF_LEGS_PER_BRIDGE/*being changed to become DPot index in leg*/  );
                        if( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) == TargetLevel )
                        {
                            SetDPotsStep = 0;
                            return true;
                        }
                        if( JustPerformOneStep )
                        {
                            SetDPotsStep = 1;
                            return false;
                        }
                    }
                }
#endif
#endif
SetDPotsStep1:
#if ( DPOTS_PER_LM334_LEG > 1 )
                if ( goingUp )
                {
                    if( ( DPotSettings[ DPOTS_PER_LM334_LEG + 1 /*this offset specifies the MID for the reference leg this bridge*/+ ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] > stepsize - 1 ) && ( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) < TargetLevel ) )
                    {
                        offsetPotValue( DPOTS_PER_LM334_LEG + 1/*this offset specifies the MID for the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), 0 - stepsize, bridge * NUM_OF_LEGS_PER_BRIDGE/*being changed to become DPot index in leg*/  );
                        if( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) == TargetLevel )
                        {
                            SetDPotsStep = 0;
                            return true;
                        }
                        if( JustPerformOneStep )
                        {
                            SetDPotsStep = 2;
                            return false;
                        }
                    }
                }
                else
                {
                    if( ( DPotSettings[ DPOTS_PER_LM334_LEG + 1/*this offset specifies the MID for the reference leg this bridge*/ + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ]<= MAXPOTSETTG - stepsize ) && ( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) > TargetLevel ) )
                    {
                        offsetPotValue( DPOTS_PER_LM334_LEG + 1 /*this offset specifies the MID for the reference leg this bridge*/+ ( bridge * NUM_OF_LEGS_PER_BRIDGE ), stepsize, bridge * NUM_OF_LEGS_PER_BRIDGE/*being changed to become DPot index in leg*/  );
                        if( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) == TargetLevel )
                        {
                            SetDPotsStep = 0;
                            return true;
                        }
                        if( JustPerformOneStep )
                        {
                            SetDPotsStep = 2;
                            return false;
                        }
                    }
                }
#endif
SetDPotsStep2:;
#if ( DPOTS_PER_LM334_LEG > 1 )
            }while( goingUp ? ( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) < TargetLevel ) : ( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) > TargetLevel ) );
#if ( DPOTS_PER_LM334_LEG > 2 )
            setPotValue( DPotPins[ DPOTS_PER_LM334_LEG + 2/*this offset specifies the MSB for the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], startpoint1 );
#endif
            setPotValue( DPotPins[ DPOTS_PER_LM334_LEG + 1 /*this offset specifies the MID for the reference leg this bridge*/+ ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], startpoint2 );
            stepsize >>= 1;
        }while( ( goingUp ? ( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) < TargetLevel ) : ( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) > TargetLevel ) ) && ( stepsize > 0 ) );
        Serial.print( F( " after first two do loops, " ) );
#endif
        startpoint2 = AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4;  //Repurposing these two vars.  Store post
        do
        {
            startpoint1 = startpoint2; //Repurposing these two vars. Store pre.  MATCHING_TO_SIGNAL_LEG can only be used when seeking to match signal leg level.
            stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 1/*this offset specifies the reference leg this bridge*/, goingUp ? TAKE_LEG_VOLTAGE_UP : TAKE_LEG_VOLTAGE_DOWN ); //we are stepping down
            startpoint2 = AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4;  //Repurposing these two vars.  Store post
        }while( goingUp ? ( ( AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) < TargetLevel ) : ( ( AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) > TargetLevel ) );
//By/At this point in time the MID and MSB digipots are within one bit of their resolutions and the leg voltage is lower than target voltage IF the reference leg voltage started out too low
//get the hi-res reading into startpoint2 if needed:
        if( MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) startpoint2 = AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );  //Repurposing these two vars.  Store hi-res result
        while( ( AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) < TargetLevel ) //while reference leg voltage is lower is also the signal leg is higher voltage
        { //while reference leg volts is less than target level
    #ifdef DEBUG
        while( !Serial ) ; 
        Serial.println( F( "Looping line 977" ) );
    #endif
            startpoint1 = startpoint2;  //Repurposing these two vars. Store pre.  MATCHING_TO_SIGNAL_LEG can only be used when seeking to match signal leg level.
            stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 1/*this offset specifies the reference leg this bridge*/, TAKE_LEG_VOLTAGE_UP );
            startpoint2 = AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );  //Repurposing these two vars.  Store hi-res result
            if( JustPerformOneStep )
            {
                SetDPotsStep = 3;
                return false;
            }
    SetDPotsStep3:;
        }
    }
    else //if( comingFromMatchBridgeLegSignalToReference ) 
    {
        startpoint2 = AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );
        Serial.print( F( "Adjusting the signal leg of bridge[" ) );
        Serial.print( bridge );
        Serial.print( F( "]: " ) );
    }
    if( MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG || comingFromMatchBridgeLegSignalToReference )
    { //the returns from this AnalogInputReadingTimes4IfInboard() are 24 bit offsets from centered and converted to 16 bits
        //in here, taking the leg down makes the outboard hi-res ADC read higher
        if( startpoint2 & 0x8000 ) //hi-res ADC signal line is negative: the signal leg is lower than reference so the reference leg needs to go lower or signal higher
        {
            while( AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) & 0x8000 ) //leg too low, reference too high, lower it
            { //while signal leg is lower than reference leg, lower reference leg or raise the signal
                if( whileLoopTimes > TIMES_LIMIT )
                {
                    SetDPotsStep = 0;
                    return true;
                }
                startpoint1 = startpoint2;  //Repurposing these two vars. Store pre.  MATCHING_TO_SIGNAL_LEG can only be used when seeking to match signal leg level.
                stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + ( comingFromMatchBridgeLegSignalToReference ? 0/*this offset specifies the signal leg this bridge*/ : 1 /*this offset specifies the reference leg this bridge*/), comingFromMatchBridgeLegSignalToReference ? TAKE_LEG_VOLTAGE_UP : TAKE_LEG_VOLTAGE_DOWN );
                startpoint2 = AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE/*this offset specifies the signal leg this bridge*/, MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );  //Repurposing these two vars.  Store post
                whileLoopTimes++;
                if( JustPerformOneStep )
                {
                    SetDPotsStep = 4;
                    return false;
                }
SetDPotsStep4:;
            }
            if( ( startpoint1 & 0x7FFF ) < ( startpoint2 & 0x7FFF ) ) //compare absolute values in ones complement
            {
//We will now return the settings to pre if startpoint2 is greater than startpoint1 if MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
                stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + ( comingFromMatchBridgeLegSignalToReference ? 0 /*this offset specifies the signal leg this bridge*/: 1/*this offset specifies the reference leg this bridge*/ ), comingFromMatchBridgeLegSignalToReference ? TAKE_LEG_VOLTAGE_DOWN : TAKE_LEG_VOLTAGE_UP );
            }
        }
        else  //positive: the signal leg is higher than it so the reference leg needs to go higher
        {
            while( !(AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) & 0x8000 ) ) //leg too low, reference too high, lower it
            { //while signal leg is not a negative from reference leg
                if( whileLoopTimes > TIMES_LIMIT )
                {
                    SetDPotsStep = 0;
                    return true;
                }
                startpoint1 = startpoint2;  //Repurposing these two vars. Store pre.  MATCHING_TO_SIGNAL_LEG can only be used when seeking to match signal leg level.
                stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + ( comingFromMatchBridgeLegSignalToReference ? 0 /*this offset specifies the signal leg this bridge*/: 1/*this offset specifies the reference leg this bridge*/ ), comingFromMatchBridgeLegSignalToReference ? TAKE_LEG_VOLTAGE_DOWN : TAKE_LEG_VOLTAGE_UP );
                startpoint2 = AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );  //Repurposing these two vars.  Store post
                whileLoopTimes++;
                if( JustPerformOneStep )
                {
                    SetDPotsStep = 5;
                    return false;
                }
SetDPotsStep5:;
            }
            if( ( startpoint1 & 0x7FFF ) < ( startpoint2 & 0x7FFF ) ) //compare absolute values in ones complement
            {
//We will now return the settings to pre if startpoint2 is greater than startpoint1 if MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
                stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + ( comingFromMatchBridgeLegSignalToReference ? 0/*this offset specifies the signal leg this bridge*/ : 1/*this offset specifies the reference leg this bridge*/ ), comingFromMatchBridgeLegSignalToReference ? TAKE_LEG_VOLTAGE_UP : TAKE_LEG_VOLTAGE_DOWN );
            }
        }
        SetDPotsStep = 0;
        return true;
    }
    else //these startpoints are inboard resolutions and 1 is lower than target, 2 is not lower reading than target, .   Determine which is closer to target
    {
        while( ( AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) != TargetLevel )
        { 
            if( whileLoopTimes > TIMES_LIMIT )
            {
                SetDPotsStep = 0;
                return true;
            }
            if( startpoint1 > startpoint2 ) //means we started from a higher voltage and worked downwards
            {
                if( ( startpoint1 - TargetLevel ) < ( TargetLevel - startpoint2 ) )
                {
                    startpoint1 = startpoint2;  //Repurposing these two vars. Store pre.  MATCHING_TO_SIGNAL_LEG can only be used when seeking to match signal leg level.
                    stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 1 /*this offset specifies the reference leg this bridge*/, TAKE_LEG_VOLTAGE_UP );
                    startpoint2 = AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );  //Repurposing these two vars.  Store post
                }
                whileLoopTimes++;
            }
            else if( startpoint1 < startpoint2 ) //means we started from a lower voltage and worked upwards
            {
                startpoint1 = AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );  //Repurposing these two vars. Store pre.  MATCHING_TO_SIGNAL_LEG can only be used when seeking to match signal leg level.
                if( ( TargetLevel - startpoint1 ) < ( startpoint2 - TargetLevel ) )
                {
                    stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 1/*this offset specifies the reference leg this bridge*/, TAKE_LEG_VOLTAGE_DOWN );
                }
                startpoint2 = AnalogInputReadingTimes4IfInboard( 1/*this offset specifies the reference leg this bridge*/ + ( bridge * NUM_OF_LEGS_PER_BRIDGE ), MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );  //Repurposing these two vars.  Store post
                whileLoopTimes++;
            }
            else 
            {
                SetDPotsStep = 0;
                return true;
            }
            if( JustPerformOneStep )
            {
                SetDPotsStep = 6;
                return false;
            }
SetDPotsStep6:;
        }
    }
    Serial.print( F( " after first do and while loops. " ) );
    SetDPotsStep = 0;
    return true;
}

bool MatchBridgeLegSignalToReference( bool JustPerformOneStep = false, uint8_t bridge = 0, bool JustQuery = false )
{//BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0
    uint16_t stepsize = 10;    
    uint16_t startpoint1;
    uint16_t startpoint2;
    Serial.print( F( "Entering MatchBridgeLegSignalToReference " ) );
    while( ( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) < AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) + ( 4 * BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) ) && ( stepsize > 0 ) )
    {
        Serial.print( F( "while a " ) );
        while( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) < AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) + ( 4 * BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) )
        {
            Serial.print( F( "while b " ) );
            startpoint1 = DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ];
            startpoint2 = DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ];
            //Decrease digipot values as long as they respond right
            if( ( DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= stepsize - 1 ) && ( DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= stepsize - 1 ) ) break;
            if( DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] > stepsize - 1 ) setPotValue( DPotPins[ 0 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] - stepsize );
            if( DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] > stepsize - 1 ) setPotValue( DPotPins[ 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] - stepsize );
        }
        setPotValue( DPotPins[ 0 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], startpoint1 );
        setPotValue( DPotPins[ 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], startpoint2 );
        stepsize >>= 1;
    }
//Converge on AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) in smaller steps
    while( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) < AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) + ( 4 * BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) )
    {
        Serial.print( F( "while c " ) ); //endlessly here
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1202" ) );
#endif
        stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, TAKE_LEG_VOLTAGE_UP );
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//        Serial.println();
    }
    stepsize = 10;
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Line 1213" ) );
#endif
    while( ( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) > AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) + ( 4 * BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) ) && ( stepsize > 0 ) )
    {
        Serial.print( F( "while d " ) );
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Line 1219" ) );
#endif
        while( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) > AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) + ( 4 * BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) )
        {
            Serial.print( F( "while e signal > reference stepsize=" ) );
            Serial.print( stepsize );
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Line 1225" ) );
#endif
/*
Time waste below with this printout:  Needs operator information printed during it if is running during setup()

Setting up digipots: bridge leg 0 = 313, bridge leg 1 = 306, SetDPotsStep = 8, stepsize = 0
Line 1144
Line 1150
Line 1156
Line 1150
Line 1156
Line 1150
Line 1156
Line 1156
Looping line 1175
stepAdjustDPotsForThisLeg called on 5 going up
Line 1144
Line 1151
Line 1156
Line 1150, AdjustClicks=0
, ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0=2
stepAdjustDPotsForThisLeg called on 5 going down
Line 1150, AdjustClicks=1
, ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0=2
stepAdjustDPotsForThisLeg called on 5 going down
0 Reading pin 18, level appearing as 303, SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE 14
Value was 304.  Done reading pin 18, 2 times, total CurrentUnmagnifiedReading now 613 which should average to 306, now plotting one inboard analog input with magnified version offset for proper positioning:
Reading pin 19, level appearing as 306
Value was 306.  Done reading pin 19, 2 times, total CurrentUnmagnifiedReading now 612 which should average to 306, now plotting one inboard analog input with magnified version offset for proper positioning:
Line 1687 INDEX_OF_OUTBOARDS = 2, whichOutboardADCindex = 0
, INDEX_OF_OUTBOARDS + whichOutboardADCindex = 2
Line 1319 MasterReadingsArrayIndex = 2
9027462
Line 1285 
Line 1368 MasterReadingsArrayIndex = 2, CurrentUnmagnifiedReading = 9027462, IndexInLinespaceParametersArray = 0, ZeroOfThisPlotLinespace = 0
 167773 
Line 1356 


*/
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
            startpoint1 = DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ];
            startpoint2 = DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ];
            //Increase digipot values as long as they respond right
            if( ( DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= stepsize - 1 ) && ( DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= stepsize - 1 ) ) break;
            setPotValue( DPotPins[ 0 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] + stepsize );
            setPotValue( DPotPins[ 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] + stepsize );
        }
        setPotValue( DPotPins[ 0 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], startpoint1 );
        setPotValue( DPotPins[ 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], startpoint2 );
        stepsize >>= 1;
    }
    while( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) > AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) + ( 4 * BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) )
    {
        Serial.print( F( "while f " ) );
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1287" ) );
#endif
        stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, TAKE_LEG_VOLTAGE_DOWN );
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//        Serial.println();
    }
    return true;
//#error //Loop below or farther down is not yet finished
//Converge by one or two consecutive readings
    do
    {
        if( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) > AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) + ( 4 * BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1302" ) );
#endif
            stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 1, TAKE_LEG_VOLTAGE_UP );
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
        }
        else if( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) /*read it again*/ < AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) + ( 4 * BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1314" ) );
#endif
            stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 1, TAKE_LEG_VOLTAGE_DOWN );
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
        }
        if( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) /*read it again*/ != AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) + ( 4 * BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) ) continue;
        
    }while( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) /*read it again*/ != AnalogInputReadingTimes4IfInboard( 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ) + ( 4 * BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) );
#ifdef DEBUG
    while( !Serial );
    Serial.println( F( "Line 1327" ) );
#endif

// Lastly, apply negative ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0 to signal leg LSB digipot
#ifdef ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0
#ifdef DEBUG
    while( !Serial );
    Serial.println( F( "Line 1334" ) );
#endif
    #if ( ( 1 < ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0 + 1 ) || ( -1 > ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0 - 1 ) )
#ifdef DEBUG
    while( !Serial );
    Serial.println( F( "Line 1339" ) );
#endif
        for( uint8_t AdjustClicks = 0; AdjustClicks < abs( ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0 ); AdjustClicks++ )
        {
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "Line 1345, AdjustClicks=" ) );
    Serial.println( AdjustClicks );
    Serial.print( F( ", ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0=" ) );
    Serial.println( ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0 );
#endif
            stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0 > 0 ? TAKE_LEG_VOLTAGE_DOWN : TAKE_LEG_VOLTAGE_UP );
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
        }
    #endif
#endif
//If ADDON ADC affiliated with this bridge reads above zero on avg, lower the signal leg and vice versa
    //refresh the readings
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
//    ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//      Serial.println();
/*    Fine tune into perfect balance:

//    bool stepAdjustDPotsForThisLeg( uint8_t MSBpotPin, uint16_t* MSBpotValue, uint8_t MIDPotPin, uint16_t* MIDPotValue, uint8_t LSBpotPin, uint16_t* LSBpotValue, bool PosOrNeg = true ) //default direction will be positive
    //see what ADDON ADC affiliated with this bridge reads avg
#ifdef MAGNIFICATION_FACTOR
    while( LastPlotPoints[ bridge * NUM_OF_LEGS_PER_BRIDGE ] < 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#else
    while( LastPlotPoints[ bridge ] < 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#endif
    {//reading is too high, lower the leg
        if( stepAdjustDPotsForThisLeg( *( AnalogPinArray + 0 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ), &DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ], *( AnalogPinArray + 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ), &DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ], *( AnalogPinArray + 2 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ), &DPotSettings[ 2 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ], false ) == false ) break;
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//        Serial.println();
    }
#ifdef MAGNIFICATION_FACTOR
     while( LastPlotPoints[ bridge * NUM_OF_LEGS_PER_BRIDGE ] > 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#else
    while( LastPlotPoints[ bridge ] > 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#endif
    {//reading is too low, raise the leg
        if( stepAdjustDPotsForThisLeg( *( AnalogPinArray + 0 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ), &DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ], *( AnalogPinArray + 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ), &DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ], *( AnalogPinArray + 2 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ), &DPotSettings[ 2 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ], true ) == false ) break;
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//        Serial.println();
    }
*/
    return 0;
    return -1;
    return 1;
}

void SetBridgeLegSignalInput( uint8_t bridge )
{
    uint16_t stepsize = 10;    
    uint16_t startpoint1;
    uint16_t startpoint2;
    while( ( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) < 4 * COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) && ( stepsize > 0 ) )
    {
        while( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) < 4 * COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
            startpoint1 = DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ];
            startpoint2 = DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ];
            //Decrease digipot values as long as they respond right
            if( ( DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= stepsize - 1 ) && ( DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= stepsize - 1 ) ) break;
            if( DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] > stepsize - 1 ) setPotValue( DPotPins[ 0 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] - stepsize );
            if( DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] > stepsize - 1 ) setPotValue( DPotPins[ 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] - stepsize );
        }
        setPotValue( DPotPins[ 0 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], startpoint1 );
        setPotValue( DPotPins[ 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], startpoint2 );
        stepsize >>= 1;
    }
//Converge on COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG in smaller steps
    while( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) < 4 * COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
    {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1275" ) );
#endif
        stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, true );
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//        Serial.println();
    }
    stepsize = 10;
    while( ( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) > 4 * COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) && ( stepsize > 0 ) )
    {
        while( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) > 4 * COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
            startpoint1 = DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ];
            startpoint2 = DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ];
            //Decrease digipot values as long as they respond right
            if( ( DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= stepsize - 1 ) && ( DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] <= stepsize - 1 ) ) break;
            setPotValue( DPotPins[ 0 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], DPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] + stepsize );
            setPotValue( DPotPins[ 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], DPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ] + stepsize );
        }
        setPotValue( DPotPins[ 0 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], startpoint1 );
        setPotValue( DPotPins[ 1 + ( bridge * NUM_OF_LEGS_PER_BRIDGE ) ], startpoint2 );
        stepsize >>= 1;
    }

//Converge on COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG in smaller steps
    while( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) > 4 * COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
    {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1302" ) );
#endif
        stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, false );
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//        Serial.println();
    }
//Converge by one or two consecutive readings
    do
    {
        if( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) > 4 * COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1313" ) );
#endif
            stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, false );
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
        }
        else if( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) /*read it again*/ < 4 * COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1321" ) );
#endif
            stepAdjustDPotsForThisLeg( ( bridge * NUM_OF_LEGS_PER_BRIDGE ) + 0, true );
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
        }
        if( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) /*read it again*/ != 4 * COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) continue;
        
    }while( AnalogInputReadingTimes4IfInboard( bridge * NUM_OF_LEGS_PER_BRIDGE ) /*read it again*/ != 4 * COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 );
}
#endif

static uint32_t TracespaceToSkipWhenRepositioning, NegativeTracespaceToSkipWhenRepositioning;
/*
#if ( NUM_OF_INBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings LinespaceParametersInboard[ NUM_OF_INBOARDS_PLOTTED ];
#endif
#if defined LM334_BRIDGES && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
    previous_readings_only DPotLeg[ ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ) - NUM_OF_INBOARDS_PLOTTED ];
#endif
#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings LinespaceParametersOutboard[ NUM_OF_OUTBOARDS_PLOTTED ];
#endif

How are LastSignalPinPlotPoint and PreviousUnmagnifiedReading differently used?

LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastSignalPinPlotPoint = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;

*/
void PlotTheNormalAndMagnifiedSignals( uint8_t MasterReadingsArrayIndex ) //Two indices per every non-magnified trace ifdef MAGNIFICATION_FACTOR, otherwise one per 
{
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "Line 1319 MasterReadingsArrayIndex = " ) );
    Serial.println( MasterReadingsArrayIndex );
#endif
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
//    showDPotSettings( thisADC );
    Serial.print( F( " unmagnified value: " ) );
    if( ( MasterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) && !( MasterReadingsArrayIndex % 2 ) ) //This is the case for those ADCs that have just had their current readings refreshed immediately prior to teh execution of this function, so use the stored readings.  Note also that the standard linespace is designed large enough to always accommodate plotting the full unmagnified reading
    {//this case and the case of MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS but not including the case of MasterReadingsArrayIndex < NUM_OF_INBOARDS_PLOTTED needs to return some values
        LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastSignalPinPlotPoint = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading + LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one of pair
    #ifdef DEBUG
        Serial.println();
        Serial.println( F( "Line 1289 signal" ) );
    #endif
    #ifdef MAGNIFICATION_FACTOR
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
    Serial.print( F( " magnified value: " ) );
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
        ThisPlotPoint = LastPlotPoints[ ( channel * NUM_OF_LEGS_PER_BRIDGE ) + 1 ] + ( ( ThisReading - LinespaceParameters[ channel ].PreviousUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#else
        ThisPlotPoint = LastPlotPoints[ ( channel * NUM_OF_LEGS_PER_BRIDGE ) + 1 ] + ( ( ThisReading - LinespaceParameters[ channel ].PreviousUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#endif
        if( ThisPlotPoint > HEIGHT_OF_A_PLOT_LINESPACE ) //new plot point is higher than upper limit
            ThisPlotPoint = TracespaceToSkipWhenRepositioning;
    }
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
    else if( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR ) > LastPlotPoints[ ( channel * NUM_OF_LEGS_PER_BRIDGE ) + 1 ] )
#else
    else if( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * MAGNIFICATION_FACTOR > LastPlotPoints[ ( channel * NUM_OF_LEGS_PER_BRIDGE ) + 1 ] )
#endif
        ThisPlotPoint = NegativeTracespaceToSkipWhenRepositioning;
    else
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
        ThisPlotPoint = LastPlotPoints[ ( channel * NUM_OF_LEGS_PER_BRIDGE ) + 1 ] - ( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#else
        ThisPlotPoint = LastPlotPoints[ ( channel * NUM_OF_LEGS_PER_BRIDGE ) + 1 ] - ( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#endif
    Serial.print( LinespaceParameters[ channel ].ZeroOfThisPlotLinespace + ThisPlotPoint ); 
    Serial.print( F( " " ) );
    LastPlotPoints[ ( channel * NUM_OF_LEGS_PER_BRIDGE ) + 1 ] = ThisPlotPoint;


*/
AFTER_THE_MAGNIFIED_PLOTTED:
#endif
MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;
#ifdef DEBUG
        Serial.println();
#endif
#ifdef AUTO_BRIDGE_BALANCING
    #ifdef MAGNIFICATION_FACTOR
    if( MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS ) return ( ( AnalogInputReadingTimes4IfInboard( 1 + ( ( MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ) * NUM_OF_LEGS_PER_BRIDGE ) - AnalogInputReadingTimes4IfInboard( ( ( MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ) - 2 ) * NUM_OF_LEGS_PER_BRIDGE ) ) ) / 4 ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0;
    #else
    if( MasterReadingsArrayIndex >= NUM_OF_INBOARDS_PLOTTED ) return ( ( AnalogInputReadingTimes4IfInboard( 1 + ( MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ) ) - AnalogInputReadingTimes4IfInboard( ( ( MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ) - 2 ) * NUM_OF_LEGS_PER_BRIDGE ) ) / 4 ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0;
    #endif
//AnalogInputReadingTimes4IfInboard index argument is a bridge...which doesn't exist except with the outboard ADCs
#endif
return;//only saving the reading, don't plot.  These are just LM334 non-plotted bridges
}

#if defined ( POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC ) || defined ( POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC )
static bool potwobbledirection = true;
static uint8_t wobbleloops = 0;
void wobble( void )
{ //Adjust active code to amount of wobble you need at the moment
#ifdef POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC
#if ( ( NUM_OF_OUTBOARDS_PLOTTED == 0 ) && ( DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE > 1 ) )  //Why? to be large enough change for inboards to plot definitively
        offsetPotValue( DPotPins[ 1 + ( POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ], potwobbledirection ? -1 : 1, POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC * NUM_OF_LEGS_PER_BRIDGE/*being changed to become DPot index in leg*/ );
#else
        offsetPotValue( DPotPins[ 0 + ( POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ], potwobbledirection ? -1 : 1, POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC * NUM_OF_LEGS_PER_BRIDGE/*being changed to become DPot index in leg*/ );
#endif
#endif

#ifdef POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC
#if ( ( NUM_OF_OUTBOARDS_PLOTTED == 0 ) && ( DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE > 1 ) )    //Why? to be large enough change for inboards to plot definitively
        offsetPotValue( DPotPins[ 1 + ( POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ], potwobbledirection ? -1 : 1, POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC * NUM_OF_LEGS_PER_BRIDGE/*being changed to become DPot index in leg*/ );
#else
        offsetPotValue( DPotPins[ 0 + ( POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC * DPOTS_PER_LM334_LEG * NUM_OF_LEGS_PER_BRIDGE ) ], potwobbledirection ? -1 : 1, POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC * NUM_OF_LEGS_PER_BRIDGE/*being changed to become DPot index in leg*/ );
#endif
#endif
    potwobbledirection = !potwobbledirection;
}
#endif

uint32_t OneReadingFromThisOutboardADC( uint8_t OutboardADCindex )
{
    #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 15 )
        ThisReadingTemp = ads.readADC_SingleEnded( OutboardADCindex );
        while( ThisReadingTemp > HEIGHT_OF_A_PLOT_LINESPACE ) ThisReadingTemp = ads.readADC_SingleEnded( OutboardADCindex );
        return ThisReadingTemp;
    #else
        #ifdef DIFFERENTIAL
            #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 )
                return CONVERT_TWOS_COMP_TO_SINGLE_ENDED( ( OutboardADCindex == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x8000*/ );
            #else
                #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 )
    //                                            hx711.power_up();
                        return CONVERT_TWOS_COMP_TO_SINGLE_ENDED( hx711.read(), HEIGHT_OF_A_PLOT_LINESPACE - 1/*mask of significant bits 24 or 32, etc*/, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x800000 which bit is sign bit*/ );
    //                                            ThisReadingTemp = 0xFFFFFF; //hx711.read_average( 9 );
    //                                            hx711.power_down();
                #else
                    #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1232 )
                    #else
                        #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1242 )
                        #else
                            #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD7780 )
                            #else
                                #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD779x )
                                #else
                                    #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == MAX211x0 )
                                    #else
                                        #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == LTC2400 )
                                        #else
                                            #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1231 )
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
    #endif
}

void ReadAndPlotFromAllADCsInAndOutboard( uint32_t TimingLineLevel, bool DuringSetup = false )
{
    Serial.println();
    Serial.print( F( "Timing line value: " ) ); //When the value printed is set off with a space on each side it gets plotted
    Serial.print( TimingLineLevel );
    Serial.print( F( " " ) );
#ifdef LM334_BRIDGES
    PrintDPotSettings();
#else
    Serial.print( F( "not using digipots " ) );
#endif
    for( uint8_t InboardPinIndex = 0; InboardPinIndex < INDEX_OF_OUTBOARDS; InboardPinIndex++ )
    {
//        #ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
//                    Serial.print( F( "AnalogPinArray = " ) );
//                    Serial.println( (unsigned long)AnalogPinArray );
            Serial.print( F( " Pin to read=" ) );
            Serial.print( *( AnalogPinArray + InboardPinIndex ) );
            Serial.print( F( ", raw level=" ) );
            Serial.print( MidTwoOfFourSum( InboardPinIndex ) / 2 );
            Serial.print( F( ">, " ) );
//        #endif
        MasterReadingsArray[ InboardPinIndex ].CurrentUnmagnifiedReading = analogRead( *( AnalogPinArray + InboardPinIndex ) );
        #ifdef DEBUG
            while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
            Serial.print( F( "Value was " ) );
            Serial.print( MasterReadingsArray[ InboardPinIndex ].CurrentUnmagnifiedReading );
        #endif
    #if ( SAMPLE_TIMES > 1 )
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
    #endif
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
    for( uint8_t OutboardADCindex = 0; OutboardADCindex < NUM_OF_OUTBOARDS_PLOTTED; OutboardADCindex++ )
    {
        #ifdef LM334_BRIDGES 
            bool OverscaleIsUnfixable = false; //Currently not used, not sure if ever will be again
            while( true ) //comes back to here if CurrentUnmagnifiedReading overscales
            {
        #endif
        MasterReadingsArray[ INDEX_OF_OUTBOARDS + OutboardADCindex ].CurrentUnmagnifiedReading = OneReadingFromThisOutboardADC( OutboardADCindex );
        #ifdef LM334_BRIDGES 
                break;
            }
        #endif
        #if ( SAMPLE_TIMES > 1 )
            for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
            {
                #if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
                    delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
                #endif
                #if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
                    delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
                #endif
                MasterReadingsArray[ INDEX_OF_OUTBOARDS + OutboardADCindex ].CurrentUnmagnifiedReading += OneReadingFromThisOutboardADC( OutboardADCindex );
            }
            MasterReadingsArray[ INDEX_OF_OUTBOARDS + OutboardADCindex ].CurrentUnmagnifiedReading /= SAMPLE_TIMES;
        #endif
        MasterReadingsArray[ INDEX_OF_OUTBOARDS + OutboardADCindex ].CurrentUnmagnifiedReading = ( MasterReadingsArray[ INDEX_OF_OUTBOARDS + OutboardADCindex ].CurrentUnmagnifiedReading < HEIGHT_OF_A_PLOT_LINESPACE ) ? MasterReadingsArray[ INDEX_OF_OUTBOARDS + OutboardADCindex ].CurrentUnmagnifiedReading : HEIGHT_OF_A_PLOT_LINESPACE;
#ifdef DEBUG
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        Serial.print( F( "Line 1687 INDEX_OF_OUTBOARDS = " ) );
        Serial.print( INDEX_OF_OUTBOARDS );
        Serial.print( F( ", OutboardADCindex = " ) );
        Serial.println( OutboardADCindex );
        Serial.print( F( ", INDEX_OF_OUTBOARDS + OutboardADCindex = " ) );
        Serial.println( INDEX_OF_OUTBOARDS + OutboardADCindex );
#endif
        PlotTheNormalAndMagnifiedSignals( INDEX_OF_OUTBOARDS + OutboardADCindex );
    }
#endif
    Serial.println();
}

void setup()
{
Serial.begin( BAUD_TO_SERIAL );//This speed is what works best with WeMos XI/TTGO XI board.
while ( !Serial ); //Leonardo needs this check
MillisStart = millis();
#ifdef __LGT8FX8E__
//    analogReadResolution( 12 );  //I believe this is not necessary
    delay( SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING * 1000 );  // Needed by this board for serial to work
#endif
while ( !Serial && ( millis() - MillisStart < 8000 ) );
Serial.println( F( VERSION ) );
Serial.println( F( "Thank you for your interest in learning telempathic gardening to cooperate with God" ) );
Serial.println( F( "bringing His kingdom to earth and His will to be done here as it is in heaven." ) );
Serial.println( F( "There is no doubt He will eventually answer that prayer of ours...and very, very soon." ) );
Serial.println();
Serial.println( F( "This product is normally run in the Serial Plotter, not the Serial Monitor." ) );
Serial.println( F( "Unless you're interested in this text only output, close this Serial Monitor" ) );
Serial.println( F( "and open the Serial Plotter instead." ) );
Serial.println();
Serial.print( F( "(C)" ) );
Serial.print( COPYRIGHT_YEAR ); /*To prevent this numeric from becoming part of a plotline we must have a non whitespace character adjacent.  Don't try to whitespace-wrap this numeric or it will affect plotting*/
Serial.println( F( ", Kenneth L. Anderson, Electronics Technician, BT, BGS, MCSE, RDH (ret'd)  d/b/a A Reviving Civility" ) );
Serial.println();
#ifdef LM334_BRIDGES   //This is important to put this first so LM334 get some resistance, but it must wait until SPI is began
    SPI.begin();
    SPI.setBitOrder( MSBFIRST );
    Serial.println( F( "LM334_BRIDGES" ) );
    #if ( LM334_BRIDGES == 1 )
    pinMode( SS, OUTPUT );
    digitalWrite( SS, HIGH ); //Not needed by slave devices but rather by this board to make it configure itself to be master
//
    for( uint8_t LM334_bridge = 0; LM334_bridge < LM334_BRIDGES; LM334_bridge++ )
    { //This is not scaleable beyond a single LM334_bridge of pots as far as pins, anyway, but at least it will initialize the digipot arrays.  To get valid values beyond the first LM334_bridge, assign them non-looped below this loop for additional LM334_bridges
  // Storing a copy of the digi pot values in sketch makes it possible to eliminate the MISO pin connection to the data out pins of all digi pots, besides the digi pots data out may not conform strictly to SPI since the MCP41X1 version has one bidirectional data pin
        DPotPins[ 0 + LM334_bridge ] = LSB_DPOT_B0L0_PIN; 
        Serial.print( F( "Stored pin number[" ) );
        Serial.print( DPotPins[ 0 + LM334_bridge ] );
        Serial.print( F( "] at pin array index[" ) );
        Serial.print( 0 + LM334_bridge );
        Serial.println( F( "]" ) );
        DPotSettings[ 0 + LM334_bridge ] = LSB_DPOT_B0L0_STARTVALUE;
        DPotPins[ DPOTS_PER_LM334_LEG + LM334_bridge ] = LSB_DPOT_B0L1_PIN;
        Serial.print( F( "Stored pin number[" ) );
        Serial.print( DPotPins[ DPOTS_PER_LM334_LEG + LM334_bridge ] );
        Serial.print( F( "] at pin array index[" ) );
        Serial.print( DPOTS_PER_LM334_LEG + LM334_bridge );
        Serial.println( F( "]" ) );
        DPotSettings[ DPOTS_PER_LM334_LEG + LM334_bridge ] = LSB_DPOT_B0L1_STARTVALUE;
#if ( DPOTS_PER_LM334_LEG > 1 )
        DPotPins[ 1 + LM334_bridge ] = NON_LSB_DPOT_1_B0L0_PIN;
        Serial.print( F( "Stored pin number[" ) );
        Serial.print( DPotPins[ 1 + LM334_bridge ] );
        Serial.print( F( "] at pin array index[" ) );
        Serial.print( 1 + LM334_bridge );
        Serial.println( F( "]" ) );
        DPotSettings[ 1 + LM334_bridge ] = NON_LSB_DPOT_1_B0L0_STARTVALUE;
        DPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334_bridge ] = NON_LSB_DPOT_1_B0L1_PIN;
        Serial.print( F( "Stored pin number[" ) );
        Serial.print( DPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334_bridge ] );
        Serial.print( F( "] at pin array index[" ) );
        Serial.print( DPOTS_PER_LM334_LEG + 1 + LM334_bridge );
        Serial.println( F( "]" ) );
        DPotSettings[ DPOTS_PER_LM334_LEG + 1 + LM334_bridge ] = NON_LSB_DPOT_1_B0L1_STARTVALUE;
#if ( DPOTS_PER_LM334_LEG > 2 )
        DPotPins[ 2 + LM334_bridge ] = NON_LSB_DPOT_2_B0L0_PIN;
        Serial.print( F( "Stored pin number[" ) );
        Serial.print( DPotPins[ 2 + LM334_bridge ] );
        Serial.print( F( "] at pin array index[" ) );
        Serial.print( 2 + LM334_bridge );
        Serial.println( F( "]" ) );
        DPotSettings[ 2 + LM334_bridge ] = NON_LSB_DPOT_2_B0L0_STARTVALUE;
        DPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334_bridge ] = NON_LSB_DPOT_2_B0L1_PIN;
        Serial.print( F( "Stored pin number[" ) );
        Serial.print( DPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334_bridge ] );
        Serial.print( F( "] at pin array index[" ) );
        Serial.print( DPOTS_PER_LM334_LEG + 2 + LM334_bridge );
        Serial.println( F( "]" ) );
        DPotSettings[ DPOTS_PER_LM334_LEG + 2 + LM334_bridge ] = NON_LSB_DPOT_2_B0L1_STARTVALUE;    
#endif
#endif
    }
    PrintDPotSettings();
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
    pinMode( BOTH_STAGES_3_TO_8_DECODER_ENABLE_PIN, OUTPUT );
    digitalWrite( BOTH_STAGES_3_TO_8_DECODER_ENABLE_PIN, HIGH );
#endif
    for( uint8_t LM334_bridge = 0; LM334_bridge < LM334_BRIDGES; LM334_bridge++ )
    {
        if( DPotPins[ 0 + LM334_bridge ] < 128 )
        {
            pinMode( DPotPins[ 0 + LM334_bridge ] & 0x3FF, OUTPUT ); //What is the  & 0x3FF all about?  This allows use of dual digi pot parts: MCP42XXX
            pinMode( DPotPins[ DPOTS_PER_LM334_LEG + LM334_bridge ] & 0x3FF, OUTPUT );
#if ( DPOTS_PER_LM334_LEG > 1 )
            pinMode( DPotPins[ 1 + LM334_bridge ] & 0x3FF, OUTPUT );
            pinMode( DPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334_bridge ] & 0x3FF, OUTPUT );
#if ( DPOTS_PER_LM334_LEG > 2 )
            pinMode( DPotPins[ 2 + LM334_bridge ] & 0x3FF, OUTPUT );
            pinMode( DPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334_bridge ] & 0x3FF, OUTPUT );
#endif
#endif
            digitalWrite( DPotPins[ 0 + LM334_bridge ] & 0x3FF, HIGH );  // HIGH is the normal waiting for next command level
            digitalWrite( DPotPins[ DPOTS_PER_LM334_LEG + LM334_bridge ] & 0x3FF, HIGH );
#if ( DPOTS_PER_LM334_LEG > 1 )
            digitalWrite( DPotPins[ 1 + LM334_bridge ] & 0x3FF, HIGH );
            digitalWrite( DPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334_bridge ] & 0x3FF, HIGH );
#if ( DPOTS_PER_LM334_LEG > 2 )
            digitalWrite( DPotPins[ 2 + LM334_bridge ] & 0x3FF, HIGH );
            digitalWrite( DPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334_bridge ] & 0x3FF, HIGH );
#endif
#endif
        }
    #ifndef LEAVE_POT_VALUES_ALONE_DURING_SETUP //This causes digipot stored settings not to match digipots, but at least they stay put to what they were last set to
        setPotValue( DPotPins[ 0 + LM334_bridge ], DPotSettings[ 0 + LM334_bridge ] );
        setPotValue( DPotPins[ DPOTS_PER_LM334_LEG + LM334_bridge ], DPotSettings[ DPOTS_PER_LM334_LEG + LM334_bridge ] );
#if ( DPOTS_PER_LM334_LEG > 1 )
        setPotValue( DPotPins[ 1 + LM334_bridge ], DPotSettings[ 1 + LM334_bridge ] );
        setPotValue( DPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334_bridge ], DPotSettings[ DPOTS_PER_LM334_LEG + 1 + LM334_bridge ] );
#if ( DPOTS_PER_LM334_LEG > 2 )
        setPotValue( DPotPins[ 2 + LM334_bridge ], DPotSettings[ 2 + LM334_bridge ] );
        setPotValue( DPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334_bridge ], DPotSettings[ DPOTS_PER_LM334_LEG + 2 + LM334_bridge ] );
/* REMOVE THIS CODE v_BELOW_v IF YOU SEE IT.  IT IS INADVERTANTLY OVERLOOKED AND INTENDED TO BE REMOVED FROM PRODUCTION VERSIONS */
#else
setPotValue( 5, 0 ); //No space in DPot... arrays for these values, so we must utilize the boolean argument
setPotValue( 8, 0 );
 /* REMOVE THIS CODE ^ABOVE^ IF YOU SEE IT.  IT IS INADVERTANTLY OVERLOOKED AND INTENDED TO BE REMOVED FROM PRODUCTION VERSIONS */
#endif
#endif
    #endif
    }
//    #else
//        #error This sketch is not entirely able to handle multiple digipot bridges at this revision level
    #endif
#endif

#ifdef LM334_BRIDGES
    #ifdef DEBUG
        while ( !Serial && ( millis() - MillisStart < 8000 ) );
        Serial.println( F( "Digi pots set up" ) );
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
#ifdef LM334_BRIDGES
        Serial.print( F( "LM334_BRIDGES " ) );
        Serial.println( LM334_BRIDGES );
#else
        Serial.println( F( "LM334_BRIDGES not defined" ) );
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
        #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 )
        //   ads.setGain( GAIN_TWOTHIRDS );  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)  //The extra ones are here for reference 
           ads.setGain( GAIN_ONE );        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV  //This allows a simple power rail excitation supply to voltage divider
        //   ads.setGain( GAIN_TWO );        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
        //   ads.setGain( GAIN_FOUR );       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
        //   ads.setGain( GAIN_EIGHT );      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
        //   ads.setGain( GAIN_SIXTEEN );    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
            ads.begin();
        #else
            #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 )
            /*
                #ifdef LM334_BRIDGES
                    #define MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT NUM_OF_OUTBOARDS_PLOTTED
                    #ifdef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
                        #define RAIL_TO_RAIL_OR_OTHERWISE_NOT_DPOT_BRIDGE_DEPENDENT_ADCS_PRESENT NUM_OF_INBOARDS_PLOTTED
                    #endif
                #else
                    #define MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT 0
                    #define ( NUM_OF_OUTBOARDS_PLOTTED + RAIL_TO_RAIL_OR_OTHERWISE_NOT_DPOT_BRIDGE_DEPENDENT_ADCS_PRESENT NUM_OF_INBOARDS_PLOTTED )
                #endif
                */
                #ifdef DEBUG
                    MillisStart = millis();
                    while ( !Serial && ( millis() - MillisStart < 8000 ) );
//                    Serial.print( F( "MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT " ) );
//                    Serial.println( MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT );
//                    Serial.print( F( "RAIL_TO_RAIL_OR_OTHERWISE_NOT_DPOT_BRIDGE_DEPENDENT_ADCS_PRESENT " ) );
//                    Serial.println( RAIL_TO_RAIL_OR_OTHERWISE_NOT_DPOT_BRIDGE_DEPENDENT_ADCS_PRESENT );
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
                #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1232 )
                #else
                    #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1242 )
                    #else
                        #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD7780 )
                        #else
                            #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD779x )
                            #else
                                #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == MAX112x0 )
                                #else
                                    #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == LTC2400 )
                                    #else
                                        #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1231 )
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
    Serial.print( F( "Plotting rising timing line: " ) );
    PlotTimingLineGoingUp( false ); //The false makes all traces originate at global zero.  It seems to look better that way
//no calls using AnalogPinArray can be made prior to now.
//Next the pin translation table is allocated then filled
        Serial.print( F( "malloc'd [" ) );
    #if defined LM334_BRIDGES /* && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS */ && ( NUM_OF_INBOARDS_PLOTTED < LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
        AnalogPinArray = ( uint8_t * )malloc( 2 * LM334_BRIDGES );
        Serial.print( 2 * LM334_BRIDGES );
    #elif ( NUM_OF_INBOARDS_PLOTTED > 0 )
        AnalogPinArray = ( uint8_t * )malloc( NUM_OF_INBOARDS_PLOTTED );
        Serial.print( NUM_OF_INBOARDS_PLOTTED );
    #else
        Serial.print( 0 );
    #endif
        Serial.println( F( "] bytes ram" ) );
        #if ( NUM_OF_INBOARDS_PLOTTED > 0 ) || ( defined LM334_BRIDGES /*&& defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && defined AUTO_BRIDGE_BALANCING && not defined LEAVE_POT_VALUES_ALONE_DURING_SETUP*/ )
        //Hereafter is the pattern.  If you have more analog pins, add them according to the pattern.
        #ifdef NUM_ANALOG_INPUTS
        #ifdef PIN_A0
            #if defined LM334_BRIDGES /*&& defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS */ && ( NUM_OF_INBOARDS_PLOTTED < LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
            for( uint8_t i = 0; i < ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ); i++ )
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
            #if defined LM334_BRIDGES && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
                for( uint8_t i = 0; i < ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ); i++ )
            #else
                for( uint8_t i = 0; i < NUM_OF_INBOARDS_PLOTTED; i++ )
            #endif
                    *(AnalogPinArray + i) = i + FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES;
            #endif //end of PIN_A0 check
        #endif
    #endif
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    #if ( not defined __LGT8FX8E__ ) && ( defined DEBUG )
        Serial.print( F( "Operator convenience delay so operator can prepare as needed..." ) );
        delay( 5000 );
    #endif
    Serial.println();
    Serial.println( F( "Done delaying for operator convenience or hardware init " ) );
    #ifdef DEBUG
        Serial.println( F( "Some running parameters:" ) );
        Serial.print( F( "AnalogPinArray = " ) );
        Serial.println( (unsigned long)AnalogPinArray );
        #if defined LM334_BRIDGES && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE )
            for( uint8_t i = 0; i < ( LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ); i++ )
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
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); //Fills the arrays with valid values
        */
/* Don't remember why following lines were there
        uint32_t LastPlotPoints_temp[ LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ]; //2 legs/bridge, each leg is one entry        
        Serial.println();
//Then get the readings of desired legs from 
        for( uint8_t LM334_bridge = 0; LM334_bridge < LM334_BRIDGES; LM334_bridge++ )
        {
#ifdef MAGNIFICATION_FACTOR
            LastPlotPoints_temp[ 0 + ( LM334_bridge * NUM_OF_LEGS_PER_BRIDGE ) ] = LastPlotPoints[ LM334_bridge * NUM_OF_LEGS_PER_BRIDGE ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
            LastPlotPoints_temp[ 1 + ( LM334_bridge * NUM_OF_LEGS_PER_BRIDGE ) ] = LastPlotPoints[ 2 + ( LM334_bridge * NUM_OF_LEGS_PER_BRIDGE ) ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
#else
            LastPlotPoints_temp[ 0 + ( LM334_bridge * NUM_OF_LEGS_PER_BRIDGE ) ] = LastPlotPoints[ LM334_bridge * NUM_OF_LEGS_PER_BRIDGE ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
            LastPlotPoints_temp[ 1 + ( LM334_bridge * NUM_OF_LEGS_PER_BRIDGE ) ] = LastPlotPoints[ 1 + ( LM334_bridge * NUM_OF_LEGS_PER_BRIDGE ) ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
#endif
        }
*/
//#ifdef MAGNIFICATION_FACTOR
//        /*reading=*/LastPlotPoints[ LM334_bridge * NUM_OF_LEGS_PER_BRIDGE ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
//#else
//        /*reading=*/LastPlotPoints[ LM334_bridge ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
//#endif
//        }
//bool SetDPotsReferenceLeg( bool JustPerformOneStep = false, uint8_t LM334_bridge = 0 )
//#error SetDPotsReferenceLeg() has a bug where it allows out of range setting values  
        PrintDPotSettings();
//Serial.flush();
//delay( 99999 );
        Serial.println( F( " setting up digipot bridge legs " ) );
        for( uint8_t LM334_bridge = 0; LM334_bridge < LM334_BRIDGES; LM334_bridge++ )
        {
            while( SetDPotsReferenceLeg( true, LM334_bridge ) == false ) //while false, the entire LM334_bridge is being zeroed into the desired balance
            {
            #ifdef DEBUG
                Serial.println( F( "Line 2374" ) );
            #endif
                delay( 2 ); // allow some settling time
//                Serial.print( PLOTTER_MAX_SCALE );
//                Serial.print( F( " " ) );
                ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//                Serial.println();
                if( CounterForTraceOutOfRangeTooLong[ LM334_bridge ]++ > 80 ) 
                {
                    Serial.println();
                    Serial.println();
                    Serial.println();
                    Serial.println();
                    break; //Limited to prevent endless looping here
                }
            }
//            ReadAndPlotFromAllADCsInAndOutboard( 0, true ); // I would think the operator would appreciate seeing something like this during calibration
            CounterForTraceOutOfRangeTooLong[ LM334_bridge ] = 0;
/*            int SignalLineHighOrLow = \  */
//Serial.flush();
//delay( 99999 );
//MatchBridgeLegSignalToReference( bool JustPerformOneStep = false, uint8_t LM334_bridge, bool JustQuery = false )

//#error
/*

THE NEXT WHILE CONSTRUCT IS AN ENDLESS LOOP DUE TO SOME RECENT CHANGES IN FUNCTIONS THAT IT CALLS, NEVER GOES INTO NOR BEYOND THE WHILE LOOP

*/
            while( MatchBridgeLegSignalToReference( false, LM334_bridge ) == false ) //This will do the same on the signal leg
            {
                ReadAndPlotFromAllADCsInAndOutboard( ( CounterForTraceOutOfRangeTooLong[ LM334_bridge ] % 2 == 0 ) ? 0 : PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//                Serial.println();
                if( CounterForTraceOutOfRangeTooLong[ LM334_bridge ]++ > 18 ) 
                {
                    Serial.println();
                    Serial.println();
                    Serial.println();
                    Serial.println();
                    break; //Limited to prevent endless looping here
                }
            }
            ReadAndPlotFromAllADCsInAndOutboard( 0, true ); // I would think the operator would appreciate seeing something like this during calibration
            CounterForTraceOutOfRangeTooLong[ LM334_bridge ] = 0;


/*            if( SignalLineHighOrLow < 0 ) ;
            else if( SignalLineHighOrLow > 0 ) ; */
        }
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
//        Serial.print( F( "0 " ) );
        Serial.println( F( " done setting up digipot bridge legs, now take very first readings since powering on: " ) );
        ReadAndPlotFromAllADCsInAndOutboard( 0, true ); //Fills the arrays with valid values
/* Following line was some forgotten plan
        uint32_t LastPlotPoints_temp[ LM334_BRIDGES * NUM_OF_LEGS_PER_BRIDGE ]; //2 legs/bridge, each leg is one entry        */
//        Serial.println();

//Now could turn on wobble and fine tune to find the common mode voltage to realize greatest gain of the outboard ADC BUT it's not that important!
    #else
        #ifdef DEBUG
            Serial.println( F( "setup." ) );
        #endif
    #endif
    #if ( ( defined LM334_BRIDGES ) && ( LM334_BRIDGES > 0 ) )
    PrintDPotSettings();
    #endif
/*
    for( uint8_t pin = 0; pin < 6; pin++ )
    {
        Serial.print( F( "DPotSettings[" ) );
        Serial.print( DPotPins[ pin ] );
        Serial.print( F( "]=" ) );
        Serial.print( DPotSettings[ pin ] );
        if( pin < 5 )
            Serial.print( F( ",. " ) );
        else
            Serial.print( F( ",. " ) );
    }
*/
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( " End of setup() " ) );
//    Serial.flush();
//    delay( 99999 );
}

void loop() 
{
    for( PlotterLoops = 0; PlotterLoops < 500 / 3; PlotterLoops++ ) 
    {
        MillisStart = millis();
        ReadAndPlotFromAllADCsInAndOutboard( graphline ? 0 : PLOTTER_MAX_SCALE );
    #ifdef AUTO_BRIDGE_BALANCING
        for( uint8_t OutboardADCindex = 0; OutboardADCindex < NUM_OF_OUTBOARDS_PLOTTED; OutboardADCindex++ )
        {
            if( MasterReadingsArray[ INDEX_OF_OUTBOARDS + OutboardADCindex ].CurrentUnmagnifiedReading >= HEIGHT_OF_A_PLOT_LINESPACE - 1 ) //means signal leg is higher
            {
                Serial.print( F( " reading maxed out " ) );
                if( --CounterForTraceOutOfRangeTooLong[ OutboardADCindex ] < LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER_NEGATIVE )
                {
    //Process: raise reference leg if it is lower than commonmode... level until it reaches commonmode..., then lower signal leg until can't lower it any more, then resume to raise reference leg until can't raise it any more
                    Serial.print( F( "for longer than allowed " ) );
//            ReadAndPlotFromAllADCsInAndOutboard( !graphline ? 0 : PLOTTER_MAX_SCALE ); // I would think the operator would appreciate seeing something like this during calibration
                    AdjustBridgeOutputNegative( OutboardADCindex );
                    PlotterLoops = 0;
                }
            }
            else if( MasterReadingsArray[ INDEX_OF_OUTBOARDS + OutboardADCindex ].CurrentUnmagnifiedReading == 0 ) //means reference leg is higher
            {
                Serial.print( F( " reading zeroed out " ) );
                if( ++CounterForTraceOutOfRangeTooLong[ OutboardADCindex ] > LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
                {
    //Process: lower reference leg if it is higher than commonmode... level until it reaches commonmode..., then raise signal leg until can't raise it any more, then resume to lower reference leg until can't lower it any more
                    Serial.print( F( "for longer than allowed " ) );
//            ReadAndPlotFromAllADCsInAndOutboard( !graphline ? 0 : PLOTTER_MAX_SCALE ); // I would think the operator would appreciate seeing something like this during calibration
                    AdjustBridgeOutputPositive( OutboardADCindex );
                    PlotterLoops = 0;
                }
            }
            else
            {
                CounterForTraceOutOfRangeTooLong[ OutboardADCindex ] = 0;
            }
        }
    #endif
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
    #ifdef LM334_BRIDGES
            uint8_t DPOT_;
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
            if( offset_integer > MAXPOTSETTG || offset_integer < 0 - MAXPOTSETTG ) goto NoPotChange;
            if( szFull[ 0 ] == '1' ) DPOT_ = DPotPins[ 0 ];
            else if( szFull[ 0 ] == '2' ) DPOT_ = DPotPins[ 1 ];
            else if( szFull[ 0 ] == '3' ) DPOT_ = DPotPins[ 2 ];
            else if( szFull[ 0 ] == '4' ) DPOT_ = DPotPins[ 3 ];
            else if( szFull[ 0 ] == '5' ) DPOT_ = DPotPins[ 4 ];
            else if( szFull[ 0 ] == '6' ) DPOT_ = DPotPins[ 5 ];
            else goto NoPotChange;
            offsetPotValue( DPOT_, offset_integer//being changed to become DPot index in leg  );
NoPotChange:
    #endif
            szFull[ 0 ] = 0;
            #ifdef DEBUG
                while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
                Serial.println();
            #endif
        }
*/
#if defined ( POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC ) || defined ( POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC )
    wobbleloops = ( wobbleloops + 1 ) % WOBBLE_TIME_PERIOD;
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
        for( uint8_t LM334_bridge = 0; LM334_bridge < LM334_BRIDGES; LM334_bridge++ )
        {
        #if ( TEST_STEP_UP_DOWN == SINGLESIDE )
            if( potstepdirection )
            {//AdjustBridgeOutputPositive until maxed
                if( !AdjustBridgeOutputPositive( LM334_bridge ) )
                {
                    potstepdirection = false;
                    AdjustBridgeOutputNegative( LM334_bridge );
                }
            }
            else
            {
                if( !AdjustBridgeOutputNegative( LM334_bridge ) )
                {
                    potstepdirection = true;
                    AdjustBridgeOutputPositive( LM334_bridge );
                }
            }
        #elif ( TEST_STEP_UP_DOWN == COMMONMODE )
            AdjustWholeBridgeCommonmode( LM334_bridge );
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
            Serial.print( F( " upper bounds of this linespace " ) );
            Serial.print( LinespaceParameters[ LinespaceParametersIndex ].HighLimitOfThisPlotLinespace );
            ReplotLastValuesForAllTraces( true );
            Serial.print( F( " lower bounds of this linespace " ) );
            Serial.print( LinespaceParameters[ LinespaceParametersIndex ].ZeroOfThisPlotLinespace );
            ReplotLastValuesForAllTraces( true );
        }
    }
    else
        PlotTimingLineGoingUp();

    graphline = !graphline; // graphline started as false, so it becomes true here on the first complementing of it
}
