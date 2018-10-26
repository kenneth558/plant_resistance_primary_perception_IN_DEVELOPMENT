//     BEFORE COMPILING THIS SKETCH you must set or confirm the following preprocessor macros appropriately for your configuration and preferences !!!
#define LM334_BRIDGES 1                                        //Number of digipot Wheatstones you have topped with LM334s each leg, (schematically wired before bare DPot bridges) but this sketch revision level not tested beyond 1.  Remove if using Wheatstone bridge with only standard or DPot resistors.  make this the number of bridges with upper resistive elements being LM334s controllable with the MCP4162-104 pots
#define DPOTS_PER_LM334_LEG 3                                  //Not yet tested for any setting except 3, so verify it before trusting fully.  Due to their significant temperature coefficient, LM334s need to be used in pairs so their tempco offsets each other's; i.e., LM334 legs are invalid unless bridged with both legs topped by a LM334
//FUTURE #define BARE_DPOT_LEG_BRIDGES                         //(after LM334 bridges in terms of pin number order) Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg increasing the likelihood 74LV138 decoding will be necessary.
//FUTURE #define BARE_DPOT_LEGS_NOT_BRIDGED                    //(after active bridges in terms of pin number order, passive bridges using manual pots might include these legs)Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
#define NUM_OF_INBOARDS_PLOTTED 2                              //The number of consecutive analog pins to plot, beginning with PIN_A0
#define NUM_OF_OUTBOARDS_PLOTTED 1                             //The number of consecutive "highest-sensitivity ADC" pins to plot, beginning with A0 and, if double-ended, A1.  OUTBOARD ADC ONLY - DOES _NOT_ INCLUDE INBOARD ANALOG INPUT PINS
#define MAGNIFICATION_FACTOR 5                                 //Activates the plotting of magnified traces in all ADC linespaces; upper limit somewhere less than 4,294,967,295. Note: you can disable displaying magnified traces altogether by not defined this macro at all. Proper use of SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS will also disable magnified traces of the first two analog inputs
#define HIGHEST_SENSI_OUTBOARD_ADC_TYPE HX711                  //Proposing that "ADS1231" covers ADS1231; could make this "ADS1232" (ADS1232), "ADS1242" (ADS1242), "AD779x" (AD779x), "AD7780" (AD7780), "HX711" (HX711), "ADS1X15" (ADS1015 or ADS1115), "MAX112x0" (MAX112X0...) or "LTC2400" (LTC2400) but code not included in v.FREE; ONLY ONE TYPE ALLOWED
#define HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC 24     //All ADC values will get scaled to the single-ended aspect of this,  15 is ADS1115 single-ended, 16 for double-ended when two LM334s are used.  change to 11 for ADS1015 single-ended or 12 with two LM334s, (future: change to 24 for HX711--NO b/c there is the ADS1231 at 24 bits)
#define SAMPLE_TIMES 2                                         //To better average out artifacts we over-sample and average.  This value can be tweaked by you to ensure neutralization of power line noise or harmonics of power supplies, etc.....
#define MOST_PROBLEMATIC_INTERFERENCE_FREQ 60                                                               //This is here just in case you think that you might have some interference on a known frequency.
#define DELAY_TIME_BETWEEN_SAMPLES_MS ( 1000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ / SAMPLE_TIMES )          //COARSE ADJUST
#define DELAY_TIME_BETWEEN_SAMPLES_US ( ( ( 1000000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ ) - ( DELAY_TIME_BETWEEN_SAMPLES_MS * SAMPLE_TIMES * 1000 ) ) / SAMPLE_TIMES ) //FINE ADJUST.  THIS GETS ADDED TO COARSE ADJUST, PRECISION = TRUNCATED PRAGMATICALLY TO uSec TO ACKNOWLEDGE SOME OVERHEAD FOR LOOPING SUPPORT CODE   // End of this part of code update
#define FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES 14 //Some boards don't have good definitions and constants for the analog pins :-(
#define PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED 85   //BETWEEN 0 AND 100 indicating how much of the display region in percent to skip when magnified view trace has to get repositioned because trace would be outside region bounds; NO BOUNDS CHECKING IS PROVIDED!!!
#define ANALOG_INPUT_BITS_OF_BOARD 10                                                          //Most Arduino boards are 10-bit resolution, but some can be 12 bits.  For known 12 bit boards (SAM, SAMD and TTGO XI architectures), this gets re-defined below, so generally this can be left as 10 even for those boards
#define SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING 9                     //8 works only usually
#define HIGHEST_SENSI_PGA_GAIN_FACTOR 128                                  //For HX711 a gain of 128 gets applied to channel A. Available to you for your own use PGA=Programmable Gain Amplifier: many ADCs will correlate a gain of one with full-scale being rail-to-rail, while a gain of anything higher correlates to full-scale being in the mV range (most sensitive and most noise-susceptible).
#define MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS 70                            //Sets a maximum speed limit, but actual speed may be further limited by other factors
#define SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS 1                              //If defined allows the rail-to-rail inboard Analog Inputs to be used to adjust digipots, but mainly causes first inboard Analog Inputs to be paired (superimposed in pairs sharing plot-line spaces) so even manual pots can be adjusted easily.
#define PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS  //By defining this macro comparison between signal and reference is no longer possible but it could be less confusing this way since user doesn't need to manually adjust anything with DPots and especially with AUTO_BRIDGE_BALANCING. ADVISE without AUTO_BRIDGE_BALANCING in effect, this macro probably should not be defined either. But regardless for greatest flexibility, that macro won't affect this.
#define AUTO_BRIDGE_BALANCING                                              //increases setup time and during which the plot timing line stays high, then spikes low and high to indicate balancing complete //Turns on auto-balancing in setup(), significant time elapse for this to complete!
//#define CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE true                //Without predictive balancing, this takes too much time if true
//#define DEBUG                                                            //Don't forget that DEBUG is not formatted for Serial plotter, but might work anyway if you'd never print numbers only any DEBUG print line
//#define POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC 0                      //For testing - wobbles digipot settings on bridge index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the signal leg
//#define POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC 0                   //For testing - wobbles digipot settings on bridge index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the reference leg
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
#define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 2                           //sets how soon run-time auto-balancing kicks in when trace goes off scale

//No need to change macros below:
#define CONVERT_TWOS_COMP_TO_SINGLE_ENDED( value_read_from_the_differential_ADC, mask, xorvalue ) ((value_read_from_the_differential_ADC & mask)^xorvalue)
//OTHER MACROS (DEFINES OR RE-DEFINES) ELSEWHERE: VERSION, NUM_OF_INBOARDS_PLOTTED, NUM_OF_OUTBOARDS_PLOTTED, NON_LSB_DPOT_2_B0L0_STARTVALUE - LSB_DPOT_B0L1_STARTVALUE, HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC, DIFFERENTIAL, PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, PLOTTER_MAX_SCALE, HUNDREDTHPLOTTER_MAX_SCALE, SAMPLE_TIMES, SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE, COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG, HEIGHT_OF_A_PLOT_LINESPACE

//FUTURE #define TEST_STEP_UP_DOWN COMMONMODE                                                                  //Available: SINGLESIDE COMMONMODE
//FUTURE #define BARE_DPOT_LEG_BRIDGES, BARE_DPOT_LEGS_NOT_BRIDGED  Subject to change, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define BARE_DPOT_LEG_BRIDGES, BARE_DPOT_LEGS_NOT_BRIDGED  Subject to change, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define BARE_DPOT_LEG_BRIDGES 1                        //(after LM334 bridges in terms of pin number order) Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg increasing the likelihood 74LV138 decoding will be necessary.
//FUTURE #define BARE_DPOT_LEGS_NOT_BRIDGED 1                    //(after active bridges in terms of pin number order, passive bridges using manual pots might include these legs)Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE 
#define DPOTS_PER_BRIDGED_BARE_LEG 3                              //FUTURE Not yet tested for any setting, so verify it before trusting fully
//FUTURE 
#define DPOTS_PER_UNBRIDGED_BARE_LEG 3                              //FUTURE Not yet tested for any setting, so verify it before trusting fully
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES 
//!!! NOTE !!! 270+ lines below this are also macros entitled similar to BANK_X_LEG_X_DPOT_X.  Those macros must also be set to correspond to the pins driving the CS lines of digipots
    #warning These 7 pin numbers get specified normally, but be sure you specify the _digital_pot_CS_pins_ with the MSB set to decode them; i.e., make those pin numbers>= 128, but not these
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
* Date               : 18-OCT-2018
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
*              23 Aug   2018 :  Fixed magnified traces in all respects; added functionality to display digipot calibration effects during calibration in setup(); started adding code to handle multiple digipot banks that utilize dual 74VHC138/74LV138s.  Still no AUTO_BRIDGE_BALANCING
*              23 Aug   2018 :  Magnification factor adjustable downward via a potentiometer if defined POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR with the digital number of an inboard analog input pin.
*              23 Aug   2018 :  added USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES with possibly enough code (just needs testing). Allowed for any ratio of LSB pot step to MSB step with DPOT_RATIO
*              11 Sep   2018 :  Back with new style of arrays useage to make bug-free coding more possible.
*              20 Sep   2018 :  Auto adjust works, but only non-predictively so it is slow.  Added macro CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE thinking someone may not want display to pause during auto balance, but that is even painfully slower still.
*              20 Sep   2018 :  Alpha chars added into output for future expansion beyond Arduino
*              18 Oct   2018 :  Now allows dual digi pot devices: MCP42xxx by manipulating the DPotPin of the first DPot of pkg OR'ing it with 0x40 as the pin of the second DPot in the pkg
*              NEXT          :  Predictive DPot setting by tracking +/- Inboard and Outboard  ADC bits per +LSB bit
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
#define LEGS_PER_DPOT_STYLE_BRIDGE ( 0 )
#define LEGS_PER_ENTIRE_SYSTEM ( 0 )
#if ( ( defined LM334_BRIDGES ) && ( defined DPOTS_PER_LM334_LEG ) && ( LM334_BRIDGES > 0 ) && ( DPOTS_PER_LM334_LEG > 0 ) )
// Limit checking here for number of DPots this sketch can work with.  Be your own developer and expand this capability to fit your needs
    #if ( ( LM334_BRIDGES > 1 ) || ( DPOTS_PER_LM334_LEG > 3 ) )
        #error To utilize that value for LM334_BRIDGES or DPOTS_PER_LM334_LEG, you'll have to develop this sketch further yourself.
    #endif
    #define NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES ( LM334_BRIDGES * DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) //For LM334-tipped bridges //For LM334-tipped bridges
    #define DPOTS_PER_LM334_BRIDGE ( DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE )
    #undef LEGS_PER_DPOT_STYLE_BRIDGE
    #define LEGS_PER_DPOT_STYLE_BRIDGE ( 2 )
    #define LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ( LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE )
#else
    #define NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES ( 0 ) //For LM334-tipped bridges
    #define LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ( 0 ) //For LM334-tipped bridges
#endif
#if ( ( defined BARE_DPOT_LEG_BRIDGES ) && ( defined DPOTS_PER_BRIDGED_BARE_LEG ) && ( BARE_DPOT_LEG_BRIDGES > 0 ) && ( DPOTS_PER_BRIDGED_BARE_LEG > 0 ) )
// Limit checking here for number of DPots this sketch can work with.  Be your own developer and expand this capability to fit your needs
    #if ( ( BARE_DPOT_LEG_BRIDGES > 0 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 0 ) )
        #error To utilize that value for BARE_DPOT_LEG_BRIDGES or DPOTS_PER_BRIDGED_BARE_LEG, you'll have to develop this sketch version further yourself.
    #endif
    #define NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES ( BARE_DPOT_LEG_BRIDGES * DPOTS_PER_BRIDGED_BARE_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) //for bare DPot bridges
    #define DPOTS_PER_BARE_LEG_BRIDGE ( DPOTS_PER_BRIDGED_BARE_LEG * LEGS_PER_DPOT_STYLE_BRIDGE )
    #undef LEGS_PER_DPOT_STYLE_BRIDGE
    #define LEGS_PER_DPOT_STYLE_BRIDGE ( 2 )
    #define BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ( BARE_DPOT_LEG_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ) //for bare DPot bridges
#else
    #define NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES ( 0 ) //for bare DPot bridges
    #define BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ( 0 ) //for bare DPot bridges
#endif
#if ( ( defined BARE_DPOT_LEGS_NOT_BRIDGED ) && ( defined DPOTS_PER_UNBRIDGED_BARE_LEG ) && ( BARE_DPOT_LEGS_NOT_BRIDGED > 0 ) && ( DPOTS_PER_UNBRIDGED_BARE_LEG > 0 ) )
// Limit checking here for number of DPots this sketch can work with.  Be your own developer and expand this capability to fit your needs
    #if ( ( NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 ) || ( BARE_DPOT_LEGS_NOT_BRIDGED > 0 ) )
        #error To utilize that value for LM334_BRIDGES or DPOTS_PER_LM334_LEG, you'll have to develop this sketch version further yourself.
    #endif
    #define NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ( BARE_DPOT_LEGS_NOT_BRIDGED * DPOTS_PER_UNBRIDGED_BARE_LEG ) //FUTURE USE for unbridged DPot control
#else
    #define NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ( 0 ) //FUTURE USE for unbridged DPot control
    #define BARE_DPOT_LEGS_NOT_BRIDGED ( 0 )
#endif
#if ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES == 0 )
    #undef LEGS_PER_DPOT_STYLE_BRIDGE //Means there are no bridges with DPots in them
    #undef AUTO_BRIDGE_BALANCING
#endif
#if ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED == 0 )
//
//Here means there are no DPots in the system anywhere
//
    #undef POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC
    #undef POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC
    #undef TEST_STEP_UP_DOWN
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
    #include "SPI.h" //This is the hardware implementation of SPI with CS pin selectable devices, not addressable via data and unidirectional data in and data out pins.  The software implementation uses shiftIn() instead and is slower but flexible which pins get used and can be used adjunctive for cases where a chip has no CS pin.  Adafruit_ADS1015 uses the shiftIn() method, so those pins are user's choice.  Not data addressable as would be in I2C

    #ifdef POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC
        #if ( 1 > POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC + 0 )
            #undef POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC
            #define POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC 0 //make sure it contains a bank index, default is bank 0
        #endif
    #endif
    #ifdef POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC
        #if ( 1 > POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC + 0 )
            #undef POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC
            #define POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC 0 //make sure it contains a bank index, default is bank 0
        #endif
    #endif
    #define NUM_OF_DPOTS ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED )
    static uint8_t DPotPins[ NUM_OF_DPOTS ];
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
    #define LSB_DPOT_B0L0_STARTVALUE 75 //or ( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 

    #define LSB_DPOT_B0L1_PIN 10        // Reference LSB fine adjust digital pot's CS line connected to here
    #define LSB_DPOT_B0L1_STARTVALUE 14 //or ( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 

    #if ( ( DPOTS_PER_LM334_LEG > 1 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 1) )
        #define NON_LSB_DPOT_1_B0L0_PIN 6          // second digital pot of signal leg CS line connected to here.  coarse adjust B positive (signal) leg
        #define NON_LSB_DPOT_1_B0L0_STARTVALUE 122 //or ( MAXPOTSETTG / 2 )  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
    
        #define NON_LSB_DPOT_1_B0L1_PIN 9          // second digital pot of reference leg CS line connected to here.  coarse adjust B negative (reference) leg
        #define NON_LSB_DPOT_1_B0L1_STARTVALUE 114 //or ( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
    
        #if ( ( DPOTS_PER_LM334_LEG > 2 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ) )
            #define NON_LSB_DPOT_2_B0L0_PIN 5         // third digital pot of signal leg CS line connected to here.  coarse adjust B positive (signal) leg
            #define NON_LSB_DPOT_2_B0L0_STARTVALUE 0  //or ( MAXPOTSETTG / 2 )  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
        
            #define NON_LSB_DPOT_2_B0L1_PIN 8         // third digital pot of reference leg CS line connected to here.  coarse adjust B negative (reference) leg
            #define NON_LSB_DPOT_2_B0L1_STARTVALUE 0  //or ( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest 
        #endif
    #endif
    #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 1 )
        #error none of this below works, yet.  It is in process of development; i.e., Only a single bank of digipots is supported at this time...
        #define LSB_DPOT_B1L0_PIN 7  // digital pot's CS line connected to here. fine adjust signal leg
        #define LSB_DPOT_B1L1_PIN 10 // digital pot's CS line connected to here. fine adjust reference leg
        #define LSB_DPOT_B1L0_STARTVALUE ( MAXPOTSETTG / 2 )  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #define LSB_DPOT_B1L1_STARTVALUE ( MAXPOTSETTG / 2 )  //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
        #if ( ( DPOTS_PER_LM334_LEG > 1 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 1) )
            #define NON_LSB_DPOT_1_B1L0_PIN 6  // digital pot's CS line connected to here. coarse adjust signal leg
            #define NON_LSB_DPOT_1_B1L1_PIN 9  // digital pot's CS line connected to here. coarse adjust reference leg
            #define NON_LSB_DPOT_1_B1L0_STARTVALUE ( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
            #define NON_LSB_DPOT_1_B1L1_STARTVALUE ( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
            #if ( ( DPOTS_PER_LM334_LEG > 2 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ) )
                #define NON_LSB_DPOT_2_B1L0_PIN 5  // digital pot's CS line connected to here. coarse adjust signal leg
                #define NON_LSB_DPOT_2_B1L1_PIN 8  // digital pot's CS line connected to here. coarse adjust reference leg
                #define NON_LSB_DPOT_2_B1L0_STARTVALUE ( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
                #define NON_LSB_DPOT_2_B1L1_STARTVALUE ( MAXPOTSETTG / 2 )   //this value in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
            #endif
        #endif
        #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 2 )
            #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 3 )
                #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 4 )
                    #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 5 )
                        #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 6 )
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
//        #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 1 )
//            #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 2 )
//                #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 3 )
//                    #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 4 )
//                        #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 5 )
//                            #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 6 )
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
    #if ( ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * LEGS_PER_DPOT_STYLE_BRIDGE ) < NUM_OF_INBOARDS_PLOTTED ) //use the smaller of the two possibilities
        #define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * LEGS_PER_DPOT_STYLE_BRIDGE )
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
#define DPOT_LEGS_PER_ENTIRE_SYSTEM ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_NOT_BRIDGED )
#if ( DPOT_LEGS_PER_ENTIRE_SYSTEM > NUM_OF_INBOARDS_PLOTTED )
    #define INDEX_OF_OUTBOARDS DPOT_LEGS_PER_ENTIRE_SYSTEM
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
    and LM334_BRIDGES (?inboard pairs 1, 2, 3, etc. or ADDONs n... ) //Besides being used for auto-balancing, these could be used just to allow a wider range of plant tissue conductance.
    and SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS (but is this moot?).  The alternative 
    to this condition in isolation from bridge balancing is just adjusting to plant resistance instead of 

Bridge balancing should not be needed with those ADCs that need a sweet spot to work.  That sweet spot could be hard wired or manual pot adjusted and only 
bridge LEG adjusting should get done????
With those ADCs, the digipots should be able to be put in serial and assigned to
Except that the tempco of the LM334 will then all be on only one leg, thus not able to be balanced out to cancel out, so never mind....
Possibilities:
AUTO...BALANCING is invalid w/o ...POTS and ...PARALLELed > 0
not LM334_BRIDGES - invalidates AUTO...BALANCING
                                  - if inputs are ...PARALLELed > 0 and ...ADDONs exist and INBOARDS > 0, it is for manual pot manipulations while viewing 
                                    traces
                                                             
So: - define ...PARALLELed = 0 if it is undefined
    - undefine USING...POTS if USING...POTS == 0 or if ...INBOARD == 0 and not AUTO...BALANCING and #defined LEAVE_POT_VALUES_ALONE_DURING_SETUP and #not defined DEBUG, the digipots may be useful in debug then re-compile but why would they need to be
    - undefine AUTO...BALANCING if not USING...POTS, or if not ...ADDONs, or if ...PARALLELed == 0
    - define ...PARALLELed = 0 if ...ADDONs == 0, or if not AUTO...BALANCING and ...INBOARD == 0 while USING...POTS
    
 */
void ReadAndPlotFromAllADCsInAndOutboard( uint32_t, bool = false );
static uint8_t* AnalogPinArray = 0; //Initializing to 0 allows functions that would use it to know whether valid or not
#if defined LM334_BRIDGES
    uint16_t MidTwoOfFourSum( uint8_t /*change from bridge value to leg*/){ return ( 2 * ( 1 << ( ANALOG_INPUT_BITS_OF_BOARD - 1 ) ) );}
    void PrintDPotSettings()
    {
        for( uint8_t DpotLeg = 0; DpotLeg < DPOT_LEGS_PER_ENTIRE_SYSTEM; DpotLeg++ )
        {
            Serial.print( F( "LegUnit[" ) );
            Serial.print( DpotLeg );
            Serial.print( F( "]" ) );
            for( uint8_t digipot_unit = 0; digipot_unit < ( DpotLeg < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? DPOTS_PER_LM334_LEG : ( DpotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ?  DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ); digipot_unit++ )
            {//DPOTS_PER_LM334_LEG
                Serial.print( F( ", DPotPin[" ) );
//Using DpotLeg and digipot_unit, obtain exact element of DPots in system and print its pin number:
//Remember there are three sections within the DPot arrays - first section is 
                Serial.print( DPotPins[ ( DpotLeg * \
                    ( ( DpotLeg < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
                    ( DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) : \
                    ( DpotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
                    ( DPOTS_PER_BRIDGED_BARE_LEG + DPOTS_PER_LM334_LEG ) * LEGS_PER_DPOT_STYLE_BRIDGE : \
                    ( ( DPOTS_PER_BRIDGED_BARE_LEG + DPOTS_PER_LM334_LEG ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + DPOTS_PER_UNBRIDGED_BARE_LEG ) ) ) + digipot_unit ] );
                Serial.print( F( "]" ) );
                if( digipot_unit < DPOTS_PER_LM334_LEG )
                    Serial.print( F( ", signal " ) );
                else
                    Serial.print( F( ", reference " ) );
//#error The next construct isn't working as expected
                if( ( digipot_unit % DPOTS_PER_LM334_LEG ) == 0 )
                    Serial.print( F( "LSB " ) );
                else if( ( digipot_unit % DPOTS_PER_LM334_LEG ) == 1 )
                    Serial.print( F( "MID " ) );
                else
                    Serial.print( F( "MSB " ) );
                Serial.print( F( "setting=" ) );
                Serial.print( DPotSettings[ DpotLeg * + digipot_unit ] );
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
//The next printout only designed for one bridge in entire system.  TODO: fix it
                    if( digipot_unit < DPOTS_PER_LM334_LEG )
                        Serial.print( MidTwoOfFourSum( DpotLeg ) / 2 );
                    else
                        Serial.print( MidTwoOfFourSum( DpotLeg + 1 ) / 2 );
                    Serial.print( F( "> " ) );
                }
            }
        }
    }

    void setPotValue( uint8_t DigitalPotPin, uint16_t value )
    {
        if( DigitalPotPin < 128 ) //Pins numbered below 128 are normal digital inboard pins
        {
            for( uint8_t index = 0; index < DPOTS_PER_LM334_BRIDGE * LM334_BRIDGES; index++ )
            {
                if( DigitalPotPin == DPotPins[ index ] )
                {
                    Serial.print( F( " DPotSettings[" ) );
                    Serial.print( DigitalPotPin );
                    Serial.print( F( "]=" ) );
                    Serial.print( DPotSettings[ index ] );
                    Serial.print( F( ",about to get set to:" ) );
                    Serial.print( value );
                    Serial.print( F( "..." ) );
                    Serial.flush();
                    DPotSettings[ index ] = value < MAXPOTSETTG ? value : MAXPOTSETTG;
                    value = DPotSettings[ index ]; //setting value but it's existence is only until end of function (transient)
                    break;
                }
            }
        }
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
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
        Serial.print( F( "got set. " ) );
        Serial.flush();
    }
    
    void offsetPotValue( uint8_t DigitalPotPin, int offsetvalue )
    {
    #ifdef DEBUG
//        offsetvalue += 40;  //A magnifier for troubleshooting
        while ( !Serial );
        Serial.print( F( "Line 610 offsetvalue=" ) );
        Serial.print( offsetvalue );
        Serial.print( F( " for Digi pot on pin " ) );
    #endif
        for( uint8_t index = 0; index < DPOTS_PER_LM334_BRIDGE * LM334_BRIDGES; index++ )
        {
            if( DigitalPotPin == DPotPins[ index ] )
            {
                if( offsetvalue < 0 ) offsetvalue = max( offsetvalue, 0 - DPotSettings[ index ] ); else if( offsetvalue > 0 ) offsetvalue = min( offsetvalue, MAXPOTSETTG - DPotSettings[ index ] ); DPotSettings[ index ] += offsetvalue; offsetvalue = DPotSettings[ index ]; 
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

    bool stepAdjustDigipotsForThisLeg( uint8_t MSBpotPin, uint16_t* MSBpotValue, uint8_t MIDpotPin, uint16_t* MIDpotValue, uint8_t LSBpotPin, uint16_t* LSBpotValue, bool PosOrNeg = true, bool JustQueryingWhetherSettingsAreMaxedOut = false ) //default direction will be positive
    { // This effectively increments or decrements LSB digipot setting just once
        if( JustQueryingWhetherSettingsAreMaxedOut )
        {//returning false means failure of digipot settings that they are either maxed high or minimized zeroes whichever one was queried
            if( !( *MSBpotValue == *MIDpotValue == *LSBpotValue ) ) return true;
            if( PosOrNeg ) //positive = true,  this means querying whether the settings are maxed high and the voltage will be minimium low
            {
                if( *MSBpotValue == MAXPOTSETTG ) return false;
            }
            else if( *MSBpotValue == 0 ) return false;
            return true;
        }
//        while ( !Serial );
//        Serial.print( F( " stepAdjustDigipotsForThisLeg called" ) );
//        Serial.print( F( " sADFTLc " ) );
        #ifdef DEBUG
            Serial.print( F( " on " ) );
            Serial.print( MSBpotPin );
        #endif
//        Serial.print( F( " going " ) );
//        Serial.print( PosOrNeg ? "up ": "down ");
        #ifdef DEBUG
            Serial.println();
        #endif
        //if going up and TotalValueCoarse is already MAXPOTSETTG * 2, add one to value_fine if it is less than MAXPOTSETTG, else return false; save new value; return true
        //if going up still and either coarse value is MAXPOTSETTG, only increment the other value, save new, return true;
        //if going up and neither coarse value is MAXPOTSETTG, increment MID with a switch statement, save new
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
        uint16_t TotalValueCoarse = *MSBpotValue;
        TotalValueCoarse += *MIDpotValue;  //We abstract it this way to force MSB and MID digi pot values to conform as namesaked
        //Next lines just force significant digit compliance inside digi pot banks
        *MSBpotValue = ( TotalValueCoarse > MAXPOTSETTG ? TotalValueCoarse - MAXPOTSETTG : 0 );
        *MIDpotValue = ( TotalValueCoarse > MAXPOTSETTG ? MAXPOTSETTG : TotalValueCoarse );
        *LSBpotValue = min( MAXPOTSETTG, *LSBpotValue );
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
        setPotValue( MSBpotPin, *MSBpotValue );
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
        setPotValue( MIDpotPin, *MIDpotValue );
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
        for( uint8_t pin = 0; pin < 6; pin++ )
        {
            Serial.print( F( " after calling setPotValue on LSB and MID and MSB DPotSettings[" ) );
            Serial.print( DPotPins[ pin ] );
            Serial.print( F( "]=" ) );
            Serial.print( DPotSettings[ pin ] );
            if( pin < 5 )
                Serial.print( F( ",. " ) );
            else
                Serial.print( F( ",. " ) );
        }
        Serial.flush();

        if( PosOrNeg ) //Positive direction == true
        {
            if( TotalValueCoarse >= MAXPOTSETTG * 2 )
            {
                *MSBpotValue = *MIDpotValue = MAXPOTSETTG;
                setPotValue( MSBpotPin, *MSBpotValue ); //This shouldn't do anything if the pot values conform to MSB and MID already
                setPotValue( MIDpotPin, *MIDpotValue ); //This shouldn't do anything if the pot values conform to MSB and MID already
                setPotValue( LSBpotPin, ++( *LSBpotValue ) > MAXPOTSETTG ? MAXPOTSETTG : *LSBpotValue );
                Serial.print( F( " TotalValueCoarse excessive, MSB digipot set to" ) );
                Serial.print( *MSBpotValue );
                Serial.print( F( ", MID set to" ) );
                Serial.print( *MIDpotValue );
                Serial.print( F( ", LSB set to" ) );
                Serial.print( *LSBpotValue );
                Serial.print( F( ",." ) );
                if( *LSBpotValue > MAXPOTSETTG ) { *LSBpotValue = MAXPOTSETTG; return false; }
                return true;
            }
            if( *LSBpotValue + 1 > ( DPOT_RATIO - 1 ) ) //This catches *LSBpotValue having or about to have a value higher than 9 when it shouldn't.  So we cycle it down
            {
                do 
                {
                    *LSBpotValue = ( uint16_t )( ( int16_t )*LSBpotValue - DPOT_RATIO ); //Yes, this can cause an unsigned to underflow to -1
                } while( ( ++TotalValueCoarse < MAXPOTSETTG * 2 ) && *LSBpotValue + 1 > ( DPOT_RATIO - 1 ) );

                *MSBpotValue = ( TotalValueCoarse > MAXPOTSETTG ?  TotalValueCoarse - MAXPOTSETTG : 0 );
                *MIDpotValue = ( TotalValueCoarse > MAXPOTSETTG ? MAXPOTSETTG : TotalValueCoarse );
                setPotValue( MSBpotPin, *MSBpotValue );
                setPotValue( MIDpotPin, *MIDpotValue );
                Serial.print( F( " called setPotValue on MID and MSB DPotSettings[" ) );
            }
            setPotValue( LSBpotPin, ++( *LSBpotValue ) );
            Serial.print( F( " MSB digipot set pos to" ) );
            Serial.print( *MSBpotValue );
            Serial.print( F( ", MID set pos to" ) );
            Serial.print( *MIDpotValue );
            Serial.print( F( ", LSB set pos to" ) );
            Serial.print( *LSBpotValue );
            Serial.print( F( ",." ) );
            return true;
        }

//Being told to decrement
        if( TotalValueCoarse == 0 && *LSBpotValue == 0 ) return false;
        if( ( int16_t )*LSBpotValue == 0 ) //This catches *LSBpotValue having or about to have a value lower than 0.  So we cycle it up
        {
            *LSBpotValue = DPOT_RATIO;
            *MSBpotValue = ( --TotalValueCoarse > MAXPOTSETTG ? TotalValueCoarse - MAXPOTSETTG : 0 );
            *MIDpotValue = ( TotalValueCoarse > MAXPOTSETTG ? MAXPOTSETTG : TotalValueCoarse );
            setPotValue( MSBpotPin, *MSBpotValue );
            setPotValue( MIDpotPin, *MIDpotValue );
        }
        setPotValue( LSBpotPin, --( *LSBpotValue ) );
        Serial.print( F( " MSB digipot set to" ) );
        Serial.print( *MSBpotValue );
        Serial.print( F( ", MID set to" ) );
        Serial.print( *MIDpotValue );
        Serial.print( F( ", LSB set to" ) );
        Serial.print( *LSBpotValue );
        Serial.print( F( ",." ) );
        return true;
    }

    uint16_t BestOfFour( uint8_t );
    bool AdjustBridgeOutputPositive( uint8_t bank )
    { //If all pots are maxed (positive leg to positive and negative leg to negative) return false
        while( !Serial );
        Serial.print( F( " Entered AdjustBridgeOutputPositive " ) );
        Serial.print( F( " EABOP " ) );
        Serial.print( F( "with bank=" ) );
        Serial.print( bank );
        Serial.print( F( ",." ) );
/* 
lower reference leg voltage if it is higher than commonmode... level until it reaches commonmode..., 
then raise signal leg voltage until can't raise it any more, 
then resume to lower reference leg until can't lower it any more
*/
//to read values from analog pins: use IndexInLinespaceParametersArray and add one (reference) or not (signal)
// If all are maxed out positive, return false: reference leg negative, signal leg positive
//TODO: reduce confusion by converting positive (now digipot settings) to positive voltage (will need to complement various things in code)
        if( !stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false, true ) \
           && !stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true, true ) )
           {
                while( !Serial );
                Serial.print( F( " Leaving AdjustBridgeOutputPositive unable to change" ) );
                Serial.print( F( " LABOP " ) );
                Serial.print( F( "with bank=" ) );
                Serial.print( bank );
                Serial.print( F( ",." ) );
                return false;
           }
/*
        if( ( DPotSettings[ 0 + bank * DPOTS_PER_LM334_BRIDGE ]  + DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] + DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] >= ( 514 + MAXPOTSETTG ) ) && \
            ( DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] + DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] + DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] == 0 ) ) return false;
*/
        while( BestOfFour( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        {
//            Serial.print( F( " raising the reference leg settings since that voltage is higher than optimal " ) );
//            Serial.print( F( " rtrlsstvihto " ) );
//            Serial.flush();
            if( !stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true ) )
                break;
            #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
                ReadAndPlotFromAllADCsInAndOutboard( graphline ? 0 : PLOTTER_MAX_SCALE );
            #endif
        }
        while( OneReadingFromThisOutboardADC( bank ) < HEIGHT_OF_A_PLOT_LINESPACE / 2 )
        {
//            Serial.print( F( " lowering the signal leg settings since the reference leg voltage is optimal " ) );
//            Serial.print( F( " ltslsstrlvio " ) );
//            Serial.flush();
            if( !stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false ) )
                break;
            #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
                ReadAndPlotFromAllADCsInAndOutboard( graphline ? 0 : PLOTTER_MAX_SCALE );
            #endif
        }
        while( OneReadingFromThisOutboardADC( bank ) < HEIGHT_OF_A_PLOT_LINESPACE / 2 )
        {
//            Serial.print( F( " raising the reference leg settings since the signal leg settings are maxed low " ) );
//            Serial.print( F( " rtrlsstslsaml " ) );
//            Serial.flush();
            if( !stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true ) )
            {
                while( !Serial );
                Serial.print( F( " Leaving AdjustBridgeOutputPositive maxed out" ) );
                Serial.print( F( " LABOP " ) );
                Serial.print( F( "with bank=" ) );
                Serial.print( bank );
                Serial.print( F( ",." ) );
                return false;
            }
            #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
                ReadAndPlotFromAllADCsInAndOutboard( graphline ? 0 : PLOTTER_MAX_SCALE );
            #endif
        }
        while( !Serial );
        Serial.print( F( " Leaving AdjustBridgeOutputPositive successful change" ) );
        Serial.print( F( " LABOP " ) );
        Serial.print( F( "with bank=" ) );
        Serial.print( bank );
        Serial.print( F( ",." ) );
    }
    
    bool AdjustBridgeOutputNegative( uint8_t bank )
    { //If all pots are maxed (positive leg to negative and negative leg to positive) return false
        while( !Serial );
        Serial.print( F( " Entered AdjustBridgeOutputNegative " ) );
        Serial.print( F( " EABON " ) );
        Serial.print( F( "with bank=" ) );
        Serial.print( bank );
        Serial.print( F( ",." ) );
        if( !stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true, true ) \
           && !stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false, true ) )
           {
                while( !Serial );
                Serial.print( F( " Leaving AdjustBridgeOutputNegative unable to change" ) );
                Serial.print( F( " LABON " ) );
                Serial.print( F( "with bank=" ) );
                Serial.print( bank );
                Serial.print( F( ",." ) );
              return false; //checks if reference leg is maxed to highest voltage already
           }
                
        while( BestOfFour( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        {
//            Serial.print( F( " lowering the reference leg settings since that voltage is lower than optimal " ) );
//            Serial.print( F( " ltrlssttvilto " ) );
//            Serial.flush();
            if( !stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false ) )
                break;
            #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
                ReadAndPlotFromAllADCsInAndOutboard( graphline ? 0 : PLOTTER_MAX_SCALE );
            #endif
        }
        while( OneReadingFromThisOutboardADC( bank ) > HEIGHT_OF_A_PLOT_LINESPACE / 2 )
        {
//            Serial.print( F( " raising the signal leg settings since the reference leg voltage is optimal " ) );
//            Serial.print( F( " rtslsstrlvio " ) );
//            Serial.flush();
            if( !stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true ) )
                break;
            #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
                ReadAndPlotFromAllADCsInAndOutboard( graphline ? 0 : PLOTTER_MAX_SCALE );
            #endif
        }
        while( OneReadingFromThisOutboardADC( bank ) > HEIGHT_OF_A_PLOT_LINESPACE / 2 )
        {
//            Serial.print( F( " lowering the reference leg settings since the signal leg settings are maxed high " ) );
//            Serial.print( F( " rtrlsstslsamh " ) );
//            Serial.flush();
            if( !stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false ) )
            {
                while( !Serial );
                Serial.print( F( " Leaving AdjustBridgeOutputNegative maxed out" ) );
                Serial.print( F( " LABON " ) );
                Serial.print( F( "with bank=" ) );
                Serial.print( bank );
                Serial.print( F( ",." ) );
                return false;
            }
            #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
                ReadAndPlotFromAllADCsInAndOutboard( graphline ? 0 : PLOTTER_MAX_SCALE );
            #endif
        }
        while( !Serial );
        Serial.print( F( " Leaving AdjustBridgeOutputNegative successful change" ) );
        Serial.print( F( " LABON " ) );
        Serial.print( F( "with bank=" ) );
        Serial.print( bank );
        Serial.print( F( ",." ) );
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
//#error The following lines are where I'm at now. Consider when inboards aren't plotted but handling digipot banks
//Skip printing of indices of inboards beyond what NUM_OF_INBOARDS_PLOTTED specifies, skip index to first outboard
//#error 
/*

#if ( NUM_OF_INBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings LinespaceParametersInboard[ NUM_OF_INBOARDS_PLOTTED ];
#endif
#if defined LM334_BRIDGES && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE )
    previous_readings_only DigipotLeg[ ( LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ) - NUM_OF_INBOARDS_PLOTTED ];
#endif
#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings LinespaceParametersOutboard[ NUM_OF_OUTBOARDS_PLOTTED ];
#endif

 */
//#ifndef MAGNIFICATION_FACTOR
//    for( ; IndexOfLinespaceParameters < max( NUM_OF_INBOARDS_PLOTTED, ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + NUM_OF_OUTBOARDS_PLOTTED; IndexOfLinespaceParameters++ )
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
        if( LinespaceParametersIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) //The same as comparing MasterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED
        {
    #if not defined PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
        #ifdef DEBUG
            while( !Serial ) ; 
            Serial.print( F( ", LastReferencePinPlotPointOrLastMagnifiedPlotPoint = " ) );
            Serial.println( LinespaceParameters[ LinespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
        #endif
            Serial.print( actuals ? LinespaceParameters[ LinespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + LinespaceParameters[ LinespaceParametersIndex ].ZeroOfThisPlotLinespace : 0 ); //I think this looks better than the line above
            Serial.print( F( " " ) );
    #endif
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
            Serial.print( F( " timing line zero of this linespace: " ) );
            Serial.print( LinespaceParameters[ LinespaceParametersIndex ].ZeroOfThisPlotLinespace );
            ReplotLastValuesForAllTraces( true );
            Serial.print( F( " timing line maximum of this linespace: " ) );
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

uint16_t BestOfFour( uint8_t AnalogPinArrayIndex = 0 ) //returns an INBOARD Analog Input pin reading, AnalogPinArrayIndex is also equal to bridge leg
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

uint16_t BestGuessAnalogInputreading( uint8_t AnalogPinArrayIndex, bool finetune = false/*not in use yet*/ ) //AnalogPinArrayIndex will be either one for the reference leg or zero for the signal leg
{ //returns an INBOARD Analog Input pin reading
    uint16_t value, value1;
    unsigned long runningtotal = 0;
    uint8_t times = 0;
    do
    {
//        value = BestOfFour( AnalogPinArrayIndex + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ); //The value of 2 is the number of bridge legs per bank
//        value1 = BestOfFour( AnalogPinArrayIndex + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) );
        value = BestOfFour( AnalogPinArrayIndex );
        value1 = BestOfFour( AnalogPinArrayIndex );
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

#if defined LM334_BRIDGES
static uint8_t SetDigipotsStep = 0;

bool SetDigipotsReferenceLeg( bool JustPerformOneStep = false, uint8_t bank = 0, bool MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG = false ) //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.  
{
    static uint16_t TargetLevel;
    static uint8_t stepsize;
    static uint16_t LastBestGuessAnalogInputreading;
#ifdef DEBUG
    while ( !Serial && ( millis() - MillisStart < 8000 ) );
    Serial.print( F( "Setting up digipots: bridge leg 0 = " ) );
    Serial.print( analogRead( *( AnalogPinArray + 0 + bank ) ) );
    Serial.print( F( ", bridge leg 1 = " ) );
    Serial.print( analogRead( *( AnalogPinArray + 1 + bank ) ) );
    Serial.print( F( ", SetDigipotsStep = " ) );
    Serial.print( SetDigipotsStep );
    Serial.print( F( ", TargetLevel = " ) );
    Serial.print( TargetLevel );
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
    if( !MatchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) TargetLevel = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG;
    else TargetLevel = BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) - BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0; 

/*Next is where the Wheatstone bridge reference leg output (that connects to negative input of highest sensi ADC) is set to TargetLevel voltage level*/
    stepsize = 10;
    static uint16_t startpoint1;
    static uint16_t startpoint2;

    while( ( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) < TargetLevel ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) < TargetLevel )
        {
            startpoint1 = DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            startpoint2 = DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            //Decrease digipot values as long as they respond right
            if( ( DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) && ( DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) ) break;
            if( DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] > stepsize - 1 )
            {
                setPotValue( DPotPins[ 3 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] - stepsize );
                if( JustPerformOneStep )
                {
                    SetDigipotsStep = 1;
                    return false;
                }
SetDigipotsStep1:;
            }
            if( DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] > stepsize - 1 )
            {
                setPotValue( DPotPins[ 4 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] - stepsize );
                if( JustPerformOneStep )
                {
                    SetDigipotsStep = 2;
                    return false;
                }
SetDigipotsStep2:;
            }
        }
        setPotValue( DPotPins[ 3 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint1 );
        setPotValue( DPotPins[ 4 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint2 );
        stepsize >>= 1;
    }
    while( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) < TargetLevel )
    {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 977" ) );
#endif
        stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 5 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false );
        if( JustPerformOneStep )
        {
            SetDigipotsStep = 3;
            return false;
        }
SetDigipotsStep3:;
    }
    stepsize = 10;

    while( ( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) > TargetLevel ) && ( stepsize > 0 ) )
    {//FIXME this loop can never be false when the startpoints get restored?
        while( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) > TargetLevel )
        {
            startpoint1 = DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            startpoint2 = DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            //Decrease digipot values as long as they respond right
            if( ( DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) && ( DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) ) break;
            if( DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] > stepsize - 1 )
            {
                setPotValue( DPotPins[ 3 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] + stepsize );
                if( JustPerformOneStep )
                {
                    SetDigipotsStep = 4;
                    return false;
                }
SetDigipotsStep4:;
            }
            if( DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] > stepsize - 1 )
            {
                setPotValue( DPotPins[ 4 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] + stepsize );
                if( JustPerformOneStep )
                {
                    SetDigipotsStep = 5;
                    return false;
                }
SetDigipotsStep5:; //This bottoms out as far as setting digipots
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "Line 897, BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) )= " ) );
    Serial.print( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) );
    Serial.print( F( ", DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ]= " ) );
    Serial.print( DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] ); //These setting values increase without end FIXME
    Serial.print( F( ", DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] = " ) );
    Serial.print( DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] );
    Serial.print( F( ", DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] = " ) );
    Serial.print( DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] );
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
        setPotValue( DPotPins[ 3 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint1 );
        setPotValue( DPotPins[ 4 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint2 );
        stepsize >>= 1;
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "new stepsize = " ) );
    Serial.println( stepsize );
#endif
    }
    while( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) > TargetLevel )
    {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1049" ) );
#endif
        stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 5 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true );
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
        if( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ), MATCHING_TO_SIGNAL_LEG ) > TargetLevel )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1114" ) );
#endif
//We must prevent endless looping when out of range: if digipot settings are maxed out in the direction we're wanting them to go, return with SetDigipotsStep = 0 and failure
            if( !stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 5 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true, true ) )
            {
                SetDigipotsStep = 0;
                return false;
            }
            stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 5 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true );
        }
        else if( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ), MATCHING_TO_SIGNAL_LEG ) /*read it again*/ < TargetLevel )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1128" ) );
#endif
//We must prevent endless looping when out of range: if digipot settings are maxed out in the direction we're wanting them to go, return with SetDigipotsStep = 0 and failure
            if( !stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 5 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false, true ) )
            {
                SetDigipotsStep = 0;
                return false;
            }
            stepAdjustDigipotsForThisLeg( DPotPins[ 3 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 3 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 4 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 4 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 5 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 5 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false );
        }
        if( JustPerformOneStep )
        {
            SetDigipotsStep = 7;
            return false;
        }
SetDigipotsStep7:
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.print( F( "Looping line 1143, TargetLevel=" ) );
    Serial.print( TargetLevel );
    Serial.print( F( ", BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ), MATCHING_TO_SIGNAL_LEG )=" ) );
    Serial.println( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ), MATCHING_TO_SIGNAL_LEG ) );
#endif
        if( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ), MATCHING_TO_SIGNAL_LEG ) /*read it again*/ != TargetLevel ) continue;
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1148" ) );
#endif
        if( JustPerformOneStep )
        {
            SetDigipotsStep = 8;
            return false;
        }
SetDigipotsStep8:;
    }while( BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ), MATCHING_TO_SIGNAL_LEG ) /*read it again*/ != TargetLevel ); //This would create an endless loop if the level is out of range

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

int MatchBridgeLegSignalToReference( uint8_t bank, bool JustQuery = false )
{//BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0
    uint16_t stepsize = 10;    
    uint16_t startpoint1;
    uint16_t startpoint2;
    while( ( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) < BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) < BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
            startpoint1 = DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            startpoint2 = DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            //Decrease digipot values as long as they respond right
            if( ( DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) && ( DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) ) break;
            if( DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] > stepsize - 1 ) setPotValue( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] - stepsize );
            if( DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] > stepsize - 1 ) setPotValue( DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] - stepsize );
            BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE );
        }
        setPotValue( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint1 );
        setPotValue( DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint2 );
        stepsize >>= 1;
    }
//Converge on BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) in smaller steps
    while( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) < BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
    {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1202" ) );
#endif
        stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false );
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
    while( ( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) > BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) && ( stepsize > 0 ) )
    {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Line 1219" ) );
#endif
        while( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) > BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Line 1225" ) );
#endif
/*
Time waste below with this printout:  Needs operator information printed during it if is running during setup()

Setting up digipots: bridge leg 0 = 313, bridge leg 1 = 306, SetDigipotsStep = 8, stepsize = 0
Line 1144
Line 1150
Line 1156
Line 1150
Line 1156
Line 1150
Line 1156
Line 1156
Looping line 1175
stepAdjustDigipotsForThisLeg called on 5 going up
Line 1144
Line 1151
Line 1156
Line 1150, AdjustClicks=0
, ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0=2
stepAdjustDigipotsForThisLeg called on 5 going down
Line 1150, AdjustClicks=1
, ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0=2
stepAdjustDigipotsForThisLeg called on 5 going down
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
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
            startpoint1 = DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            startpoint2 = DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            //Decrease digipot values as long as they respond right
            if( ( DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) && ( DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) ) break;
            setPotValue( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] + stepsize );
            setPotValue( DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] + stepsize );
            BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE );
        }
        setPotValue( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint1 );
        setPotValue( DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint2 );
        stepsize >>= 1;
    }

//Converge on BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) in smaller steps
    while( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) > BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
    {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1287" ) );
#endif
        stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true );
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//        Serial.println();
    }
//Converge by one or two consecutive readings
    do
    {
        if( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) > BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1302" ) );
#endif
            stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true );
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
        }
        else if( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) /*read it again*/ < BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1314" ) );
#endif
            stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false );
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
        }
        if( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) /*read it again*/ != BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) continue;
        
    }while( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) /*read it again*/ != BestGuessAnalogInputreading( 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 );
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
            stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BANK0 > 0 ? false : true  );
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
        }
    #endif
#endif
//If ADDON ADC affiliated with this bank reads above zero on avg, lower the signal leg and vice versa
    //refresh the readings
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
//    ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//      Serial.println();
/*    Fine tune into perfect balance:

//    bool stepAdjustDigipotsForThisLeg( uint8_t MSBpotPin, uint16_t* MSBpotValue, uint8_t MIDpotPin, uint16_t* MIDpotValue, uint8_t LSBpotPin, uint16_t* LSBpotValue, bool PosOrNeg = true ) //default direction will be positive
    //see what ADDON ADC affiliated with this bank reads avg
#ifdef MAGNIFICATION_FACTOR
    while( LastPlotPoints[ bank * LEGS_PER_DPOT_STYLE_BRIDGE ] < 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#else
    while( LastPlotPoints[ bank ] < 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#endif
    {//reading is too high, lower the leg
        if( stepAdjustDigipotsForThisLeg( *( AnalogPinArray + 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ), &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], *( AnalogPinArray + 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ), &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], *( AnalogPinArray + 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ), &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false ) == false ) break;
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//        Serial.println();
    }
#ifdef MAGNIFICATION_FACTOR
     while( LastPlotPoints[ bank * LEGS_PER_DPOT_STYLE_BRIDGE ] > 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#else
    while( LastPlotPoints[ bank ] > 0 )// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
#endif
    {//reading is too low, raise the leg
        if( stepAdjustDigipotsForThisLeg( *( AnalogPinArray + 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ), &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], *( AnalogPinArray + 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ), &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], *( AnalogPinArray + 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ), &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true ) == false ) break;
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

void SetBridgeLegSignalInput( uint8_t bank )
{//BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0
    uint16_t stepsize = 10;    
    uint16_t startpoint1;
    uint16_t startpoint2;
    while( ( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
            startpoint1 = DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            startpoint2 = DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            //Decrease digipot values as long as they respond right
            if( ( DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) && ( DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) ) break;
            if( DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] > stepsize - 1 ) setPotValue( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] - stepsize );
            if( DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] > stepsize - 1 ) setPotValue( DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] - stepsize );
            BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE );
        }
        setPotValue( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint1 );
        setPotValue( DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint2 );
        stepsize >>= 1;
    }
//Converge on COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG in smaller steps
    while( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
    {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1275" ) );
#endif
        stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false );
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//        Serial.println();
    }
    stepsize = 10;
    while( ( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) && ( stepsize > 0 ) )
    {
        while( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
            startpoint1 = DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            startpoint2 = DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ];
            //Decrease digipot values as long as they respond right
            if( ( DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) && ( DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] <= stepsize - 1 ) ) break;
            setPotValue( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] + stepsize );
            setPotValue( DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ] + stepsize );
            BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE );
        }
        setPotValue( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint1 );
        setPotValue( DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], startpoint2 );
        stepsize >>= 1;
    }

//Converge on COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG in smaller steps
    while( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
    {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1302" ) );
#endif
        stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true );
//        Serial.print( PLOTTER_MAX_SCALE );
//        Serial.print( F( " " ) );
        ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//        Serial.println();
    }
//Converge by one or two consecutive readings
    do
    {
        if( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1313" ) );
#endif
            stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], true );
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
        }
        else if( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) /*read it again*/ < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
        {
#ifdef DEBUG
    while( !Serial ) ; 
    Serial.println( F( "Looping line 1321" ) );
#endif
            stepAdjustDigipotsForThisLeg( DPotPins[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 0 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], DPotPins[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 1 + ( bank * DPOTS_PER_LM334_BRIDGE ) ],  DPotPins[ 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ], &DPotSettings[ 2 + ( bank * DPOTS_PER_LM334_BRIDGE ) ], false );
//            Serial.print( PLOTTER_MAX_SCALE );
//            Serial.print( F( " " ) );
            ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//            Serial.println();
        }
        if( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) continue;
        
    }while( BestGuessAnalogInputreading( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 );
}
#endif

static uint32_t TracespaceToSkipWhenRepositioning, NegativeTracespaceToSkipWhenRepositioning;
/*
#if ( NUM_OF_INBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings LinespaceParametersInboard[ NUM_OF_INBOARDS_PLOTTED ];
#endif
#if defined LM334_BRIDGES && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE )
    previous_readings_only DigipotLeg[ ( LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ) - NUM_OF_INBOARDS_PLOTTED ];
#endif
#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings LinespaceParametersOutboard[ NUM_OF_OUTBOARDS_PLOTTED ];
#endif

How are LastSignalPinPlotPoint and PreviousUnmagnifiedReading differently used?

LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastSignalPinPlotPoint = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;

*/
void PlotTheNormalAndMagnifiedSignals( uint8_t MasterReadingsArrayIndex ) //LinespaceParameters[] has Two indices/elements per every non-magnified trace ifdef MAGNIFICATION_FACTOR, otherwise one per 
{
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "Line 1319 MasterReadingsArrayIndex = " ) );
    Serial.println( MasterReadingsArrayIndex );
#endif
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( " unmagnified value: " ) );
    if( ( MasterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) && !( MasterReadingsArrayIndex % 2 ) ) //This is the case for those ADCs that have just had their
                                                                                                                 // current readings refreshed immediately prior to the 
                                                                                                                 // execution of this function, so use the stored readings.
                                                                                                                 //Note also that the standard linespace is designed large 
                                                                                                                 // enough to always accommodate plotting the full unmagnified reading
    {//this case and the case of MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS but not including the case of MasterReadingsArrayIndex < NUM_OF_INBOARDS_PLOTTED 
     // needs to return some values
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
    else if( MasterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) //This is still the case for those ADCs that have just had their current readings refreshed 
                                                                             // immediately prior to the execution of this function, so use the stored readings.  
                                                                             //Note also that the standard linespace is designed large enough to always accommodate plotting
                                                                             // the full unmagnified reading
    {
        LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;
    #if not defined PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
        Serial.print( MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading + LinespaceParameters[ MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color two of pair
    #endif
    #ifdef DEBUG
        Serial.println();
        Serial.println( F( "Line 1298 reference" ) );
    #endif
    #ifdef MAGNIFICATION_FACTOR
        Serial.print( F( " " ) );
        goto AFTER_THE_MAGNIFIED_PLOTTED; // B/c this range is superimposed traces, no magnified plot is indicated
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
        ThisPlotPoint = LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] + ( ( ThisReading - LinespaceParameters[ channel ].PreviousUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#else
        ThisPlotPoint = LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] + ( ( ThisReading - LinespaceParameters[ channel ].PreviousUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#endif
        if( ThisPlotPoint > HEIGHT_OF_A_PLOT_LINESPACE ) //new plot point is higher than upper limit
            ThisPlotPoint = TracespaceToSkipWhenRepositioning;
    }
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
    else if( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR ) > LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] )
#else
    else if( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * MAGNIFICATION_FACTOR > LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] )
#endif
        ThisPlotPoint = NegativeTracespaceToSkipWhenRepositioning;
    else
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
        ThisPlotPoint = LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] - ( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#else
        ThisPlotPoint = LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] - ( ( LinespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#endif
    Serial.print( LinespaceParameters[ channel ].ZeroOfThisPlotLinespace + ThisPlotPoint ); 
    Serial.print( F( " " ) );
    LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] = ThisPlotPoint;


*/
AFTER_THE_MAGNIFIED_PLOTTED:
#endif
MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading = MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading;
#ifdef DEBUG
        Serial.println();
#endif
#ifdef AUTO_BRIDGE_BALANCING
    #ifdef MAGNIFICATION_FACTOR
    if( MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS ) return BestGuessAnalogInputreading( 1 + ( ( MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 - BestGuessAnalogInputreading( ( ( MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ) - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE ) );
    #else
    if( MasterReadingsArrayIndex >= NUM_OF_INBOARDS_PLOTTED ) return BestGuessAnalogInputreading( 1 + ( MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 - BestGuessAnalogInputreading( ( ( MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray ) - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE );
    #endif
//BestGuessAnalogInputreading index argument is a bank...which doesn't exist except with the outboard ADCs
#endif
return;//only saving the reading, don't plot.  These are just LM334 non-plotted banks
}

#if defined ( POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC ) || defined ( POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC )
static bool potwobbledirection = true;
static uint8_t wobbleloops = 0;
void wobble( void )
{ //Adjust active code to amount of wobble you need at the moment
#ifdef POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC
//        offsetPotValue( DPotPins[ 0 + ( POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC * LEGS_PER_DPOT_STYLE_BRIDGE ) ], potwobbledirection ? 1 : -1 );
//        offsetPotValue( DPotPins[ 1 + ( POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC * LEGS_PER_DPOT_STYLE_BRIDGE ) ], potwobbledirection ? 1 : -1 );
        offsetPotValue( DPotPins[ 2 + ( POT_TEST_WOBBLE_SIGNAL_ON_THIS_OUTBOARD_ADC * LEGS_PER_DPOT_STYLE_BRIDGE ) ], potwobbledirection ? 1 : -1 ); //digipot 2 of this bank is the third (0=first) and is the LSB digipot of the signal side
#endif
#ifdef POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC
//        offsetPotValue( DPotPins[ 3 + ( POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC * LEGS_PER_DPOT_STYLE_BRIDGE ) ], potwobbledirection ? -1 : 1 );
//        offsetPotValue( DPotPins[ 4 + ( POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC * LEGS_PER_DPOT_STYLE_BRIDGE ) ], potwobbledirection ? -1 : 1 );
        offsetPotValue( DPotPins[ 5 + ( POT_TEST_WOBBLE_REFERENCE_ON_THIS_OUTBOARD_ADC * LEGS_PER_DPOT_STYLE_BRIDGE ) ], potwobbledirection ? -1 : 1 ); //digipot 5 of this bank is the sixth (0=first) and is the LSB digipot of the reference side
#endif
    potwobbledirection = !potwobbledirection;
}
#endif

//#ifdef AUTO_BRIDGE_BALANCING
//    static uint16_t CounterForTraceOutOfRangeTooLong[ NUM_OF_OUTBOARDS_PLOTTED ]; //This is to prevent infinite loop with AUTO_BRIDGE_BALANCING
//#endif

uint32_t OneReadingFromThisOutboardADC( uint8_t whichOutboardADCindex )
{
    #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 15 )
        ThisReadingTemp = ads.readADC_SingleEnded( whichOutboardADCindex );
        while( ThisReadingTemp > HEIGHT_OF_A_PLOT_LINESPACE ) ThisReadingTemp = ads.readADC_SingleEnded( whichOutboardADCindex );
        return ThisReadingTemp;
    #else
        #ifdef DIFFERENTIAL
            #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 )
                return CONVERT_TWOS_COMP_TO_SINGLE_ENDED( ( whichOutboardADCindex == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x8000*/ );
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
    Serial.print( F( " timing line value: " ) );
    Serial.print( TimingLineLevel );
    Serial.print( F( " " ) );
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
    {  //PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
        PlotTheNormalAndMagnifiedSignals( InboardPinIndex ); // What was I thinking comment: "not permissible to plot the paired/superimposed traces except with odd indices below INDEX_OF_INBOARDS_NOT_SUPERIMPOSED" ?
        #ifdef DEBUG                                         // Maybe a single array element holds both reference and signal plots?
            Serial.println();
        #endif
    }
#endif

#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
    for( uint8_t whichOutboardADCindex = 0; whichOutboardADCindex < NUM_OF_OUTBOARDS_PLOTTED; whichOutboardADCindex++ )
    {
        #ifdef LM334_BRIDGES 
Start_of_addon_ADC_acquisition:
            bool OverscaleIsUnfixable = false;
            while( true ) //comes back to here if CurrentUnmagnifiedReading overscales
            {
        #endif
        #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 15 )
            MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = ads.readADC_SingleEnded( whichOutboardADCindex );
            while( MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ] > HEIGHT_OF_A_PLOT_LINESPACE ) //TODO: verify the need for this check
            {
                MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = ads.readADC_SingleEnded( whichOutboardADCindex );
            }
        #else
            #ifdef DIFFERENTIAL
                #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 )
                    MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = CONVERT_TWOS_COMP_TO_SINGLE_ENDED( ( whichOutboardADCindex == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), ( uint32_t )(  - 1 ), HEIGHT_OF_A_PLOT_LINESPACE >> 1 );  // Convert to single-ended style
                #else
                    #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 )
//                                hx711.power_up();
                        MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = CONVERT_TWOS_COMP_TO_SINGLE_ENDED( hx711.read(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x800000*/ );
//                                CurrentUnmagnifiedReading = 0xFFFFFF;//= hx711.read_average( 9 );
                        
//                                hx711.power_down();
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
            #else //then figure it is Single-ended
            #endif
        #endif
        #ifdef LM334_BRIDGES 
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
                MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading += OneReadingFromThisOutboardADC( whichOutboardADCindex );
            }
            MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading /= SAMPLE_TIMES;
        #endif
        MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = ( MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading < HEIGHT_OF_A_PLOT_LINESPACE ) ? MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading : HEIGHT_OF_A_PLOT_LINESPACE;
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

#ifdef LM334_BRIDGES   //This is important to put this first so LM334 get some resistance

    #if ( LM334_BRIDGES == 1 )
    pinMode( SS, OUTPUT );
    digitalWrite( SS, HIGH ); //Not needed by slave devices but rather by this board to make it configure itself to be master
//
    for( uint8_t LM334_bridge = 0; LM334_bridge < LM334_BRIDGES; LM334_bridge++ )
    { //This is not scaleable beyond a single LM334_bridge of pots as far as pins, anyway, but at least it will initialize the digipot arrays.  To get valid values beyond the first LM334_bridge, assign them non-looped below this loop for additional LM334_bridges
//DPOTS_PER_LM334_BRIDGE ( DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE )
goto oldstyle;
//In process of changing to accommodate 1 or 2 DPots per LM334 leg
        DPotSettings[ 0 + LM334_bridge ] = LSB_DPOT_B0L0_STARTVALUE;  // Storing a copy of the digi pot values in sketch makes it possible to eliminate the MISO pin connection to the data out pins of all digi pots, besides the digi pots data out may not conform strictly to SPI since the MCP41X1 version has one bidirectional data pin
        DPotSettings[ 0 + DPOTS_PER_LM334_LEG + LM334_bridge ] = LSB_DPOT_B0L1_STARTVALUE;
        #if ( DPOTS_PER_LM334_LEG > 1 )
            DPotSettings[ 1 + LM334_bridge ] = LSB_DPOT_B0L0_STARTVALUE;
            DPotSettings[ 1 + DPOTS_PER_LM334_LEG + LM334_bridge ] = NON_LSB_DPOT_2_B0L1_STARTVALUE;
            #if ( DPOTS_PER_LM334_LEG > 2 ) 
                DPotSettings[ 2 + LM334_bridge ] = NON_LSB_DPOT_1_B0L1_STARTVALUE;
                DPotSettings[ 2 + DPOTS_PER_LM334_LEG + LM334_bridge ] = LSB_DPOT_B0L1_STARTVALUE;
            #endif
        #endif
oldstyle:
        DPotSettings[ 0 + LM334_bridge ] = NON_LSB_DPOT_2_B0L0_STARTVALUE;  // Storing a copy of the digi pot values in sketch makes it possible to eliminate the MISO pin connection to the data out pins of all digi pots, besides the digi pots data out may not conform strictly to SPI since the MCP41X1 version has one bidirectional data pin
        DPotSettings[ 1 + LM334_bridge ] = NON_LSB_DPOT_1_B0L0_STARTVALUE;
        DPotSettings[ 2 + LM334_bridge ] = LSB_DPOT_B0L0_STARTVALUE;
        DPotSettings[ DPOTS_PER_LM334_LEG + 0 + LM334_bridge ] = NON_LSB_DPOT_2_B0L1_STARTVALUE;
        DPotSettings[ DPOTS_PER_LM334_LEG + 1 + LM334_bridge ] = NON_LSB_DPOT_1_B0L1_STARTVALUE;
        DPotSettings[ DPOTS_PER_LM334_LEG + 2 + LM334_bridge ] = LSB_DPOT_B0L1_STARTVALUE;
    
        DPotPins[ 0 + LM334_bridge ] = NON_LSB_DPOT_2_B0L0_PIN; 
        DPotPins[ 1 + LM334_bridge ] = NON_LSB_DPOT_1_B0L0_PIN;
        DPotPins[ 2 + LM334_bridge ] = LSB_DPOT_B0L0_PIN;
        DPotPins[ DPOTS_PER_LM334_LEG + 0 + LM334_bridge ] = NON_LSB_DPOT_2_B0L1_PIN;
        DPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334_bridge ] = NON_LSB_DPOT_1_B0L1_PIN;
        DPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334_bridge ] = LSB_DPOT_B0L1_PIN;
    }
//To increase capacity, follow the naming pattern above
Serial.print( F( "DPot arrays filled " ) );

    for( uint8_t LM334_bridge = 0; LM334_bridge < LM334_BRIDGES; LM334_bridge++ )
    {
        pinMode( DPotPins[ 0 + LM334_bridge ], OUTPUT );
        pinMode( DPotPins[ 1 + LM334_bridge ], OUTPUT );
        pinMode( DPotPins[ 2 + LM334_bridge ], OUTPUT );
        pinMode( DPotPins[ 0 + DPOTS_PER_LM334_LEG + LM334_bridge ], OUTPUT );
        pinMode( DPotPins[ 1 + DPOTS_PER_LM334_LEG + LM334_bridge ], OUTPUT );
        pinMode( DPotPins[ 2 + DPOTS_PER_LM334_LEG + LM334_bridge ], OUTPUT );
        digitalWrite( DPotPins[ 0 + LM334_bridge ], HIGH );
        digitalWrite( DPotPins[ 1 + LM334_bridge ], HIGH );
        digitalWrite( DPotPins[ 2 + LM334_bridge ], HIGH );
        digitalWrite( DPotPins[ 0 + DPOTS_PER_LM334_LEG + LM334_bridge ], HIGH );
        digitalWrite( DPotPins[ 1 + DPOTS_PER_LM334_LEG + LM334_bridge ], HIGH );
        digitalWrite( DPotPins[ 2 + DPOTS_PER_LM334_LEG + LM334_bridge ], HIGH );
        SPI.begin();
        SPI.setBitOrder( MSBFIRST );
    #ifndef LEAVE_POT_VALUES_ALONE_DURING_SETUP //This causes digipot stored settings not to match digipots, but at least they stay put to what they were last set to
        setPotValue( DPotPins[ 0 + LM334_bridge ], DPotSettings[ 0 + LM334_bridge ] );
        setPotValue( DPotPins[ 1 + LM334_bridge ], DPotSettings[ 1 + LM334_bridge ] );
        setPotValue( DPotPins[ 2 + LM334_bridge ], DPotSettings[ 2 + LM334_bridge ] );
        setPotValue( DPotPins[ 0 + DPOTS_PER_LM334_LEG + LM334_bridge ], DPotSettings[ 0 + DPOTS_PER_LM334_LEG + LM334_bridge ] );
        setPotValue( DPotPins[ 1 + DPOTS_PER_LM334_LEG + LM334_bridge ], DPotSettings[ 1 + DPOTS_PER_LM334_LEG + LM334_bridge ] );
        setPotValue( DPotPins[ 2 + DPOTS_PER_LM334_LEG + LM334_bridge ], DPotSettings[ 2 + DPOTS_PER_LM334_LEG + LM334_bridge ] );
    #endif
    }
    Serial.print( F( "DPot pins set up " ) );
    #else
        #error This sketch is not entirely able to handle multiple digipot banks at this revision level
    #endif
#endif
MillisStart = millis();
#ifdef __LGT8FX8E__
//    analogReadResolution( 12 );  //I believe this is not necessary
    delay( SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING * 1000 );  // Needed by this board for serial to work
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
#ifndef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
    #define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG HALF_HEIGHT_OF_A_PLOT_LINESPACE
#endif
        LinespaceParameters[ LinespacesIndex ].HighLimitOfThisPlotLinespace = ( NUMBER_OF_LINESPACES - LinespacesIndex ) * HEIGHT_OF_A_PLOT_LINESPACE;
        LinespaceParameters[ LinespacesIndex ].ZeroOfThisPlotLinespace = LinespaceParameters[ LinespacesIndex ].HighLimitOfThisPlotLinespace - HEIGHT_OF_A_PLOT_LINESPACE;
        LinespaceParameters[ LinespacesIndex ].LastSignalPinPlotPoint = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
        LinespaceParameters[ LinespacesIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
        MasterReadingsArray[ MasterReadingsArrayIndex ].PreviousUnmagnifiedReading = MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS ? COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG : HALF_HEIGHT_OF_A_PLOT_LINESPACE;
        MasterReadingsArray[ MasterReadingsArrayIndex ].CurrentUnmagnifiedReading = MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS ? COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG : HALF_HEIGHT_OF_A_PLOT_LINESPACE;
        MasterReadingsArray[ MasterReadingsArrayIndex ].IndexInLinespaceParametersArray = LinespacesIndex;
//                  Note that INDEX_OF_INBOARDS_NOT_SUPERIMPOSED is an index for MasterReadingsArray and actually is equal to the number of InboardSuperimposed that exist
        if( LinespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) //The two arrays correlate 1:2 until INDEX_OF_INBOARDS_NOT_SUPERIMPOSED
        {
            MasterReadingsArray[ MasterReadingsArrayIndex + 1 ].PreviousUnmagnifiedReading = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG;
            MasterReadingsArray[ MasterReadingsArrayIndex + 1 ].CurrentUnmagnifiedReading = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG;
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
    #if ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_NOT_BRIDGED + NUM_OF_INBOARDS_PLOTTED > 0 )
        AnalogPinArray = ( uint8_t * )malloc( max( NUM_OF_INBOARDS_PLOTTED, LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_NOT_BRIDGED ) );
        Serial.print( max( NUM_OF_INBOARDS_PLOTTED, LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_NOT_BRIDGED ) );
    #else
        Serial.print( 0 );
    #endif
    Serial.println( F( "] bytes ram" ) );
        #if ( NUM_OF_INBOARDS_PLOTTED > 0 ) || ( defined NUM_OF_DPOTS )
        //Hereafter is the pattern.  If you have more analog pins, add them according to the pattern.
        #ifdef NUM_ANALOG_INPUTS
        #ifdef PIN_A0
            for( uint8_t i = 0; i < max( NUM_OF_INBOARDS_PLOTTED, LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_NOT_BRIDGED ); i++ )
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
                for( uint8_t i = 0; i < max( NUM_OF_INBOARDS_PLOTTED, LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_NOT_BRIDGED ); i++ )
                    *( AnalogPinArray + i ) = i + FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES;
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
        #if defined LM334_BRIDGES && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE )
            for( uint8_t i = 0; i < ( LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ); i++ )
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
        for( uint8_t bridgeIndex = 0; bridgeIndex < NUM_OF_OUTBOARDS_PLOTTED; bridgeIndex++ )
            CounterForTraceOutOfRangeTooLong[ bridgeIndex ] = 0;
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
        uint32_t LastPlotPoints_temp[ LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ]; //2 legs/bank, each leg is one entry        
        Serial.println();
//Then get the readings of desired legs from 
        for( uint8_t bank = 0; bank < LM334_BRIDGES; bank++ )
        {
#ifdef MAGNIFICATION_FACTOR
            LastPlotPoints_temp[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ] = LastPlotPoints[ bank * LEGS_PER_DPOT_STYLE_BRIDGE ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
            LastPlotPoints_temp[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ] = LastPlotPoints[ 2 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
#else
            LastPlotPoints_temp[ 0 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ] = LastPlotPoints[ bank * LEGS_PER_DPOT_STYLE_BRIDGE ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
            LastPlotPoints_temp[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ] = LastPlotPoints[ 1 + ( bank * LEGS_PER_DPOT_STYLE_BRIDGE ) ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
#endif
        }
*/
//#ifdef MAGNIFICATION_FACTOR
//        /*reading=*/LastPlotPoints[ bank * LEGS_PER_DPOT_STYLE_BRIDGE ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
//#else
//        /*reading=*/LastPlotPoints[ bank ] >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;// + LinespaceParameters[ channel ].ZeroOfThisPlotLinespace;
//#endif
//        }
//bool SetDigipotsReferenceLeg( bool JustPerformOneStep = false, uint8_t bank = 0 )
//#error SetDigipotsReferenceLeg() has a bug where it allows out of range setting values  
//        PrintDPotSettings();
        Serial.println( F( " Setting up LM334 and bare digipot bridge legs " ) );
        for( uint8_t LM334_bridge = 0; LM334_bridge < LM334_BRIDGES; LM334_bridge++ )
        {
            while( SetDigipotsReferenceLeg( true, LM334_bridge ) == false ) //while false, the entire bank is being zeroed into the desired balance
            {
            #ifdef DEBUG
                Serial.println( F( "Line 2374" ) );
            #endif
                delay( 2 ); // allow some settling time
//                Serial.print( PLOTTER_MAX_SCALE );
//                Serial.print( F( " " ) );
                ReadAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
//                Serial.println();
                if( CounterForTraceOutOfRangeTooLong[ LM334_bridge ]++ > 80 ) break; //Limited to prevent endless looping here
            }
            CounterForTraceOutOfRangeTooLong[ LM334_bridge ] = 0;
/*            int SignalLineHighOrLow = \  */
            MatchBridgeLegSignalToReference( LM334_bridge ); //This will do the same on the signal leg
/*            if( SignalLineHighOrLow < 0 ) ;
            else if( SignalLineHighOrLow > 0 ) ; */
        }
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
//        Serial.print( F( "0 " ) );
        Serial.println( F( " done setting up digipot bridge legs, now take very first readings since powering on: " ) );
        ReadAndPlotFromAllADCsInAndOutboard( 0, true ); //Fills the arrays with valid values
/* Following line was some forgotten plan
        uint32_t LastPlotPoints_temp[ LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ]; //2 legs/bank, each leg is one entry        */
//        Serial.println();

//Now could turn on wobble and fine tune to find the common mode voltage to realize greatest gain of the outboard ADC BUT it's not that important!
    #else
        #ifdef DEBUG
            Serial.println( F( "setup." ) );
        #endif
    #endif

    for( uint8_t CSIndex = 0; CSIndex < NUM_OF_DPOTS; CSIndex++ )
    {
        Serial.print( F( "DPotSettings[" ) );
        Serial.print( DPotPins[ CSIndex ] );
        Serial.print( F( "]=" ) );
        Serial.print( DPotSettings[ CSIndex ] );
        if( CSIndex < NUM_OF_DPOTS - 1 )
            Serial.print( F( ",. " ) );
        else
            Serial.print( F( ",. " ) );
    }

    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( " End of setup() " ) );
}

void loop() 
{
    for( uint8_t CSIndex = 0; CSIndex < NUM_OF_DPOTS; CSIndex++ )
    {
        Serial.print( F( "DPotSettings[" ) );
        Serial.print( DPotPins[ CSIndex ] );
        Serial.print( F( "]=" ) );
        Serial.print( DPotSettings[ CSIndex ] );
        if( CSIndex < NUM_OF_DPOTS - 1 )
            Serial.print( F( ",. " ) );
        else
            Serial.print( F( ",. " ) );
    }
    for( PlotterLoops = 0; PlotterLoops < 500 / 3; PlotterLoops++ ) 
    {
        MillisStart = millis();
//        if( graphline ) ThisReadingTemp = 0;
//        else ThisReadingTemp = PLOTTER_MAX_SCALE;
//        Serial.print( ThisReadingTemp ); //This was originally last printed in the group.  It needs to be first instead so the line can be "notched" horizontally without needing to reprint all values.
//        Serial.print( F( " " ) );
//        ReadAndPlotFromAllADCsInAndOutboard( ThisReadingTemp );
        ReadAndPlotFromAllADCsInAndOutboard( graphline ? 0 : PLOTTER_MAX_SCALE );
    #ifdef AUTO_BRIDGE_BALANCING
        for( uint8_t whichOutboardADCindex = 0; whichOutboardADCindex < NUM_OF_OUTBOARDS_PLOTTED; whichOutboardADCindex++ )
        {
            if( MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading >= HEIGHT_OF_A_PLOT_LINESPACE - 1 ) //means signal leg is higher
            {
                Serial.print( F( " reading maxed out " ) );
                if( --CounterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] < -LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
                {
    //Process: raise reference leg if it is lower than commonmode... level until it reaches commonmode..., then lower signal leg until can't lower it any more, then resume to raise reference leg until can't raise it any more
    //                SetBridgeLegSignalInput( whichOutboardADCindex ); // Instead maybe use AdjustBridgeOutput ative( bank );
                    Serial.print( F( "for longer than allowed " ) );
                    AdjustBridgeOutputNegative( whichOutboardADCindex );
                    PlotterLoops = 0;
                }
            }
            else if( MasterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading == 0 ) //means reference leg is higher
            {
                Serial.print( F( " reading zeroed out " ) );
                if( ++CounterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] > LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
                {
    //Process: lower reference leg if it is higher than commonmode... level until it reaches commonmode..., then raise signal leg until can't raise it any more, then resume to lower reference leg until can't lower it any more
    //                SetBridgeLegSignalInput( whichOutboardADCindex ); // Instead maybe use AdjustBridgeOutput ative( bank );
                    Serial.print( F( "for longer than allowed " ) );
                    AdjustBridgeOutputPositive( whichOutboardADCindex );
                    PlotterLoops = 0;
                }
            }
            else
            {
                CounterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] = 0;
            }
        }
    #endif
//        Serial.println();
/*        old style partial of auto adjust case:
    if( MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS )
    {
        #if ( NUM_OF_OUTBOARDS_PLOTTED > 0 ) && defined AUTO_BRIDGE_BALANCING
            #ifdef MAGNIFICATION_FACTOR
            if( MasterReadingsArrayIndex < INDEX_OF_OUTBOARDS )  BestGuessAnalogInputreading( 1 + ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 - BestGuessAnalogInputreading( ( channel - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE ) );
            #else
            if( MasterReadingsArrayIndex >= NUM_OF_INBOARDS_PLOTTED ) BestGuessAnalogInputreading( 1 + channel ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 - BestGuessAnalogInputreading( ( channel - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE );
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
    #ifdef LM334_BRIDGES
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
            if( offset_integer > MAXPOTSETTG || offset_integer < 0 - MAXPOTSETTG ) goto NoPotChange;
            if( szFull[ 0 ] == '1' ) DIGITAL_POT_ = DPotPins[ 0 ];
            else if( szFull[ 0 ] == '2' ) DIGITAL_POT_ = DPotPins[ 1 ];
            else if( szFull[ 0 ] == '3' ) DIGITAL_POT_ = DPotPins[ 2 ];
            else if( szFull[ 0 ] == '4' ) DIGITAL_POT_ = DPotPins[ 3 ];
            else if( szFull[ 0 ] == '5' ) DIGITAL_POT_ = DPotPins[ 4 ];
            else if( szFull[ 0 ] == '6' ) DIGITAL_POT_ = DPotPins[ 5 ];
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
        for( uint8_t bank = 0; bank < LM334_BRIDGES; bank++ )
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
