//        BEFORE COMPILING THIS SKETCH you must set or confirm the following preprocessor macros appropriately for your configuration and preferences !!!
#define LM334_BRIDGES 1                                        //Number of digipot Wheatstones you have topped with LM334s each leg, (schematically wired before bare DPot bridges) but this sketch revision level not tested beyond 1.  Remove if using Wheatstone bridge with only standard or DPot resistors.  make this the number of bridges with upper resistive elements being LM334s controllable with the MCP4162-104 pots
#define DPOTS_PER_LM334_LEG 3                                  //Not yet tested for any setting except 3, so verify it before trusting fully.  Due to their significant temperature coefficient, LM334s need to be used in pairs so their tempco offsets each other's; i.e., LM334 legs are invalid unless bridged with both legs topped by a LM334
//FUTURE #define BARE_DPOT_LEG_BRIDGES                         //(after LM334 bridges in terms of pin number order) Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg increasing the likelihood 74LV138 decoding will be necessary.
//FUTURE #define BARE_DPOT_LEGS_UNBRIDGED                    //(after active bridges in terms of pin number order, passive bridges using manual pots might include these legs)Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
#define NUM_OF_INBOARDS_PLOTTED 2                              //The number of consecutive analog pins to plot, beginning with PIN_A0
#define NUM_OF_OUTBOARDS_PLOTTED 1                             //The number of consecutive "highest-sensitivity ADC" pins to plot, beginning with A0 and, if double-ended, A1.  OUTBOARD ADC ONLY - DOES _NOT_ INCLUDE INBOARD ANALOG INPUT PINS
#define MAGNIFICATION_FACTOR 5                                 //Activates the plotting of magnified traces in all ADC linespaces; upper limit somewhere less than 4,294,967,295. Note: you can disable displaying magnified traces altogether by not defined this macro at all. Proper use of SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS will also disable magnified traces of the first two analog inputs
#define HIGHEST_SENSI_OUTBOARD_ADC_TYPE HX711                  //Proposing that "ADS1231" covers ADS1231; could make this "ADS1232" ( ADS1232), "ADS1242" ( ADS1242), "AD779x" ( AD779x), "AD7780" ( AD7780), "HX711" (HX711), "ADS1X15" ( ADS1015 or ADS1115), "MAX112x0" (MAX112X0...) or "LTC2400" (LTC2400) but code not included in v.FREE; ONLY ONE TYPE ALLOWED
#define HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC 24     //All ADC values will get scaled to the single-ended aspect of this,  15 is ADS1115 single-ended, 16 for double-ended when two LM334s are used.  change to 11 for ADS1015 single-ended or 12 with two LM334s, (future: change to 24 for HX711--NO b/c there is the ADS1231 at 24 bits)
#define SAMPLE_TIMES 2                                         //To better average out artifacts we over-sample and average.  This value can be tweaked by you to ensure neutralization of power line noise or harmonics of power supplies, etc.....
//#define MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE true
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
//#define PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS  //By defining this macro comparison between signal and reference is no longer possible but it could be less confusing this way since user doesn't need to manually adjust anything with DPots and especially with AUTO_BRIDGE_BALANCING. ADVISE without AUTO_BRIDGE_BALANCING in effect, this macro probably should not be defined either. But regardless for greatest flexibility, that macro won't affect this.
#define AUTO_BRIDGE_BALANCING                                              //increases setup time and during which the plot timing line stays high, then spikes low and high to indicate balancing complete //Turns on auto-balancing in setup(), significant time elapse for this to complete!
#define CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE true                //Without predictive balancing, this takes too much time if true
//#define DEBUG                                                            //Don't forget that DEBUG is not formatted for Serial plotter, but might work anyway if you'd never print numbers only any DEBUG print line
#define POT_TEST_WOBBLE_SIGNAL_ON_SPECIFIED_OUTBOARD_ADC 0                      //For testing - wobbles digipot settings on bridge index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the signal leg
#define POT_TEST_WOBBLE_REFERENCE_ON_SPECIFIED_OUTBOARD_ADC 0                   //For testing - wobbles digipot settings on bridge index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the reference leg
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
#define DPOT_RATIO 20 /* DPOT_RATIO: System-wide MSB/LSB.  Ex.: If the LSB digipot is 200 ohms/step and the MSB digipot is 2000 ohms/step, this value will be 10. (2000/200)
                      It is only used relative to the LSB digipot, so there can only be that one digipot per leg allowed to have a smaller resistance
                      per step than other digipots on the leg. All bridge legs in the system must be built with the same ratio scheme, and must always include one and
                      only one LSB digipot, with all non-LSB digipots matching each others' resistance/step values.  This macro limits LSB settings adjustments
                      when another digipot in the leg is set to less than MAXPOTSETTG, but not otherwise, allowing LSB to reach MAXPOTSETTG when non-LSBs are all at MAXPOTSETTG.
                      As far as MAXPOTSETTG, all digipots in the system are bound by the same MAXPOTSETTG value. */
//#define POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR 3                       //NOT the digital number //Can use a spare analog input as magnification attenuator by connecting wiper of a pot (100K or greater, please) that voltage-divides 0-5 vdc.
//#define USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
#define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 2000                           //sets how soon run-time auto-balancing kicks in when trace goes off scale

//No need to change macros below:
static bool lSBFirstDPotOrder = true;
#define CONVERT_TWOS_COMP_TO_SINGLE_ENDED( value_read_from_the_differential_ADC, mask, xorvalue ) ((value_read_from_the_differential_ADC & mask)^xorvalue)
//OTHER MACROS (DEFINES OR RE-DEFINES) ELSEWHERE: VERSION, NUM_OF_INBOARDS_PLOTTED, NUM_OF_OUTBOARDS_PLOTTED, NON_LSB_DPOT_2_B0SIG_STARTVALUE - LSB_DPOT_B0REF_STARTVALUE, HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC, DIFFERENTIAL, PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, PLOTTER_MAX_SCALE, HUNDREDTHPLOTTER_MAX_SCALE, SAMPLE_TIMES, SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE, COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG, HEIGHT_OF_A_PLOT_LINESPACE

//FUTURE #define TEST_STEP_UP_DOWN COMMONMODE                                                                  //Available: SINGLESIDE COMMONMODE
//FUTURE #define BARE_DPOT_LEG_BRIDGES, BARE_DPOT_LEGS_UNBRIDGED  Subject to change, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define BARE_DPOT_LEG_BRIDGES 1                        //(after LM334 bridges in terms of pin number order) Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher settingValues of DPot leg resistances are expected to be required.  This could mean more DPots per leg increasing the likelihood 74LV138 decoding will be necessary.
//FUTURE #define BARE_DPOT_LEGS_UNBRIDGED 1                    //(If inputting to outboard ADCs these would be after active bridges in terms of pin number order, passive bridges using manual pots might include these legs)Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher settingValues of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define VERBOSITY_LEVEL  //To be used instead of and combines DEBUG and MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE
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

       ARDUINO ELECTRICAL RESISTANCE/CONDUCTANCE MONITORING SKETCH

  File Name          : adc_for_plant_tissue.ino
  Author             : KENNETH L ANDERSON
  Version            : v.Free
  Date               : 18-OCT-2018
  Description        : To replicate Cleve Backster's findings that he attributed to a phenomenon he called "Primary Perception".  Basically, this sketch turns an Arduino MCU and optional (recommended) ADS1115 into a nicely functional poor man's polygraph in order to learn/demonstrate telempathic gardening.
  Boards tested on   : Uno using both ADS1115 and inboard analog inputs.
                     : TTGO XI using ADS1115.
                     : Many other configurations should work fine.
                     : The ATTINY85 is not suitable at all due to not having hardware serial

  Known limitations  : Free version does not use predictive auto bridge balance lending to painfully slow auto balance when plant conductance goes out of range
                     : No ability to accept user input from keyboard during run time dLM334_BRIDGESue to Arduino plotter limitation
                     : Re-compile is needed for any changes to configuration
                     : Analog input pins being used MUST be the first available analog inputs
                     : Only a single add-on ADS ADC device and only 1 or 2 differential channels on it is tested
                     : Conventional add-on high-sensitivity ADCs limit their common mode differential input range to a few millivolts with active or passive clamping
                     : Non-bridged DPot legs are only for outboard ADCs though presumeably single-ended, they are not accommodated for inboard Analog Inputs
                     : Some of these limitations will be addressed in future not-for-free versions

      Due to the many preprocessor condition checks throughout this sketch source, the IDE is unable to track bracketed constructs accurately in many places.
      What does this mean?  If you are used to relying on the IDE's highlighting of a paired bracket to help you know a bracketed construct's boundaries, you'll have to give that convenience up in places in this sketch source code.

********************************************************************************
  THE PRESENT PRODUCT WHICH IS ONLY FOR USE BY SOFTWARE- AND HARDWARE-COMPETENT USERS
  IS INTENDED TO OFFER VARIOUS CAPABILITIES.  BECAUSE ABSOLUTELY NO CONSIDERATION
  IS EXPECTED IN RETURN, NO CONTRACT, WHETHER OFFERING SUITABILITY, RELIABILITY,
  FUNCTIONALITY, SAFETY, OR OTHER, EXISTS.  BY USING THIS PRODUCT YOU EXPRESSLY AND
  TOTALLY ACCEPT FULL LIABILITY FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES
  WITH RESPECT TO ANY CLAIMS ARISING FROM SOFTWARE AND/OR HARDWARE DERIVATIONS OF PRODUCT.
  I MAKE ABSOLUTELY NO CLAIM OF MY OWN COMPETENCE, LICENSURE, CERTIFICATION, EXPERIENCE,
  OR PROFESSIONAL STANDING OTHER THAN BEING AN ELECTRONICS TECHNICIAN BY FORMAL
  DEGREE AND UNITED STATES FCC RADIOTELEPHONE OPERATORS LICENSE, AND
  A SOFTWARE DEVELOPER BY LIMITED PRACTICAL EXPERIENCE, AND BEING FORMALLY
  DEGREED WITH BACHELOR OF GENERAL STUDIES MAJORED IN GENERAL SCIENCES
********************************************************************************

   Changelog:  30 April 2018 :  Final inboard 10 bit operation and ADS1X15 operation has been achieved.  Future work on free version will be for 12 bit boards only
               04 May   2018 :  Some 12 bit tweaking so that TTGO/WeMos XI, SAM and SAMD architectures compile with inboard analog inputs to computed at 12 bit even though ANALOG_INPUT_BITS_OF_BOARD is set at default.
               18 May   2018 :  Anti-aliasing code
               29 May   2018 :  Differential use of ADS1x15 to allow LM334 temperature comp to negative inputs so LM334 can be used on positive inputs
               32 May   2018 :  Added skeleton preprocessor defines for user to compatibly code their own support for a few 24-bit ADCs
               05 June  2018 :  HX711 accommodated, you'll just have to balance the bridge manually
               08 June  2018 :  Bugfix for inboard analog inputs above the first one - they didn't print before this fix
               17 June  2018 :  Corrected pointer reinitialize of analogPinArray that disabled internal Analog Input pins.  Added "while( !Serial );" for Leonardo's native USB; starting to add framework for programmable potentiometers, changed defines to allow for a separate full-scale, lower res ADC and a high res ADC for normal viewing, etc,
               18 June  2018 :  Bug fixes relative to displaying multiple traces while one or more are from inboard analog pins
               13 July  2018 :  Modified plotter timing trace to notch horizontally at range min and max for signal traces when it crosses up and down.  Incorporated digi pot adjustings in debug mode. Enabled bypass of digi pot set in setup()
               14 July  2018 :  Improved horizontal timing trace notching - made it shorter and consistent between levels
               15 July  2018 :  Allow unique digipot initializing settingValue for each pot.  Discovered HX711 input Z is way too low for use without buffers.  Regrouping....
               16 July  2018 :  Removed disparaging comments toward TTGO XI/Wemo XI because we will make the plunge to employ the AD8244 buffer as standard, resulting in those boards being eligible as any other board
               20 July  2018 :  Improved plotting with INBOARDINPARALLELWITHHIGHESTSENSI and improved 24-bit plot values
               26 July  2018 :  Corrected conversion from twos complement differential readings to proper single ended plotting
               27 July  2018 :  Discovered HX711's common-mode level sweet spot for max sensitivity, made COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG with default of half-scale
               28 July  2018 :  If using digipots with LM334s, sketch can now auto-balance during setup and target the most sensitive common-mode voltage of a selected outboard ADC...LATER REVISIONS BROKE AUTO_BRIDGE_BALANCING
               29 July  2018 :  With INBOARDINPARALLELWITHHIGHESTSENSI && AUTO_BRIDGE_BALANCING defined, plotspace now excludes the two inboard Analog Input traces, making maximum linespace available for the other more interesting traces
               30 July  2018 :  Now able continuously to run-time auto-balance at least with a single HX711 LATER REVISIONS BROKE AUTO_BRIDGE_BALANCING
               31 July  2018 :  I've noticed one sketch bug in the printing of the magnified traces in that they don't stay within bounds any more. Older sketch versions never had that problem. I'm not sure where it began, but it seems to be a memory management problem from my inital troubleshooting rather than any type of algorithm weakness. I'll work on that when I'm able...
               01 Aug   2018 :  Working on vertical positioning of the magnified traces
               23 Aug   2018 :  Fixed magnified traces in all respects; added functionality to display digipot calibration effects during calibration in setup(); started adding code to handle multiple digipot stacks that utilize dual 74VHC138/74LV138s.  Still no AUTO_BRIDGE_BALANCING
               23 Aug   2018 :  Magnification factor adjustable downward via a potentiometer if defined POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR with the digital number of an inboard analog input pin.
               23 Aug   2018 :  added USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES with possibly enough code (just needs testing). Allowed for any ratio of LSB pot step to MSB step with DPOT_RATIO
               11 Sep   2018 :  Back with new style of arrays useage to make bug-free coding more possible.
               20 Sep   2018 :  Auto adjust works, but only non-predictively so it is slow.  Added macro CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE thinking someone may not want display to pause during auto balance, but that is even painfully slower still.
               20 Sep   2018 :  Alpha chars added into output for future expansion beyond Arduino
               18 Oct   2018 :  Now allows dual digi pot devices: MCP42xxx by manipulating the DPotPin of the first DPot of pkg OR'ing it with 0x40 as the pin of the second DPot in the pkg
               16 Nov   2018 :  Scalability changes.  DO NOT USE PREDATED VERSIONS TO ADVANCE DEVELOPMENT!!!!!!!  Many changes have been made as of this date to accommodate future scalability
               NEXT          :  Predictive DPot setting by tracking +/- Inboard and Outboard  ADC bits per +LSB bit
               NEXT          :  Allow DigiPots without LM334: the direction of effect will be opposite.  New macro:
               NEXT          :  EEPROM storage of things like ADC sweet spot, initial digipot settings, etc.  Hardware configs like DPot types & ADC types & other upgradeable hardware version possiblities needs to be able to be set in the hat board rather than EEPROM
               NEXT          :  Accommodate ADS1232 &/or ADS1231
               NEXT          :  Detect hat config and version with 256 versions detection and warning to acquire more recent sketch version when versions > known are found

  TODO:  Arrange for run-time keyboard input to eliminate need to re-compile when changes are made or plotting adjustments are desired.  Will require non-Arduino IDE plotter
         Use dual digital potentiometers (MCP42XXX) for more lower parts count than when using single pot MCP41XXX
         Accommodate more 24-bit amps like ADS1231

   These planned enhancements will be reserved for NOT-FOR-FREE sketch versions in the future

  Should you examine the sketch code you will or may notice it is in a state of transition.  Variable names and useages may be inconsistent and so forth.  That is
  because I am upgrading it with longer-term goals in mind while at the same time adding intermediate features that are easily and quickly coded.

  Planned longer-term upgrades are as follows:
  - Am currently coding for use of less than 3 and more than 3 DPots/leg
  - Am currently coding for using DPots alone, without LM334, in the bridges
  - Am currently coding for using unbridged DPots, single leg only
  - Am currently coding for faster conductance range changes when DUT conductance goes out of range
  - Not coding for other ADC types yet, but will eventually first code for multiple HX711

  These goals necessitate many smaller changes that make an uninformed observer wonder why this or that is so convoluted.  The answer in many cases is
  that I've learned not to make so many changes at a time that the sketch can acquire failures/bugs in more than one or two places because troubleshooting
  would become harder by orders of magnitude.  So the many small modifications to support the longer term goals are being added incrementally without
  breaking the sketch along the way.  Thank you for your tolerance.

  Names are created according to the following conventions:

    PREPROCESSOR_MACROS (ALL_WORDS_IN_ALL_CAPS_AND_JOINED_WITH_DELINEATORS)
    functionNames
        and
    variableNames (eachWordCapitalizedExceptFirst, words joined without delineators)
    OBJECTNAMES (ALLWORDSINALLCAPS, words joined without delineators)
    struct_names (no_capital_letters, words joined with delineators)
    StructMemberNames
        and
    GotoLabels(EachWordCapitalized, words joined without delineators)

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
   With Adafruit_ADS1015.h, SDA, SCL Wemos XI/TTGO XI use A4 for SDA, and A5 is SCL.
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
   If ever would use an ADS1x15 along with this ADC, then see error msg below
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
#error This add-on ADC resolution is not supported in this sketch version
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
#error You'll need to manually define at least one of the variables NUM_OF_INBOARDS_PLOTTED or NUM_OF_OUTBOARDS_PLOTTED where they appear in the lines above and re-compile...
If you only have the Arduino without an ADS1X15, then define NUM_OF_INBOARDS_PLOTTED.  Otherwise, define NUM_OF_OUTBOARDS_PLOTTED and / or both of them.
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
#define TAKE_LEG_VOLTAGE_UP false
#define TAKE_LEG_VOLTAGE_DOWN true
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
#define DPOT_LEGS_PER_ENTIRE_SYSTEM ( 0 )
// always 0 so no macro needed: #define dPotLegMSBUsedAndAvailablesIndexLM334_LEG ( 0 )
#define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG ( 0 )
#define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG ( 0 )

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
#if ( DPOTS_PER_LM334_LEG > 1 )
#undef DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG //move where index is for all next styles legs
#define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG ( 2 * LEGS_PER_DPOT_STYLE_BRIDGE * LM334_BRIDGES ) // one member for Total, one for Available for each leg
#undef DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG //move where index is for next style leg
#define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG ( DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG )
#endif
#else
#ifdef DPOTS_PER_LM334_LEG
#undef DPOTS_PER_LM334_LEG
#endif
#define DPOTS_PER_LM334_LEG ( 0 )
#define LM334_BRIDGES ( 0 )
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
#if ( DPOTS_PER_BRIDGED_BARE_LEG > 1 )
#undef DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG //move where index is for next style leg
#define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG ( DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG + ( 2 * LEGS_PER_DPOT_STYLE_BRIDGE * BARE_DPOT_LEG_BRIDGES ) ) // one member for Total, one for Available for each leg
#endif
#else
#ifdef DPOTS_PER_BRIDGED_BARE_LEG
#undef DPOTS_PER_BRIDGED_BARE_LEG
#endif
#define BARE_DPOT_LEG_BRIDGES ( 0 )
#define DPOTS_PER_BRIDGED_BARE_LEG ( 0 )
#define NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES ( 0 ) //for bare DPot bridges
#define BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ( 0 ) //for bare DPot bridges
#endif

#if ( ( defined BARE_DPOT_LEGS_UNBRIDGED ) && ( defined DPOTS_PER_UNBRIDGED_BARE_LEG ) && ( BARE_DPOT_LEGS_UNBRIDGED > 0 ) && ( DPOTS_PER_UNBRIDGED_BARE_LEG > 0 ) )
// Limit checking here for number of DPots this sketch can work with.  Be your own developer and expand this capability to fit your needs
#if ( ( NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 ) || ( BARE_DPOT_LEGS_UNBRIDGED > 0 ) )
#error To utilize that value for LM334_BRIDGES or DPOTS_PER_LM334_LEG, you'll have to develop this sketch version further yourself.
#endif
#define NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ( BARE_DPOT_LEGS_UNBRIDGED * DPOTS_PER_UNBRIDGED_BARE_LEG ) //FUTURE USE for unbridged DPot control
#else
#ifdef DPOTS_PER_UNBRIDGED_BARE_LEG
#undef DPOTS_PER_UNBRIDGED_BARE_LEG
#endif
#ifdef BARE_DPOT_LEGS_UNBRIDGED
#undef BARE_DPOT_LEGS_UNBRIDGED
#endif
#define DPOTS_PER_UNBRIDGED_BARE_LEG ( 0 )
#define NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ( 0 ) //FUTURE USE for unbridged DPot control
#define BARE_DPOT_LEGS_UNBRIDGED ( 0 )
#endif
#if ( ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES /*+ BARE_DPOT_LEGS_UNBRIDGED*/ ) > NUM_OF_OUTBOARDS_PLOTTED )
//Notice that BARE_DPOT_LEGS_UNBRIDGED is a don't care to allow greatest user flexibility
#error The number of outboard ADCs is not adequate for the total from the specified values of LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES + BARE_DPOT_LEGS_UNBRIDGED
#endif
#define DPOT_LEGS_PER_ENTIRE_SYSTEM ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_UNBRIDGED )
#if ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES == 0 )
#undef LEGS_PER_DPOT_STYLE_BRIDGE //Means there are no bridges with DPots in them
#undef AUTO_BRIDGE_BALANCING
#endif
#if ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED == 0 )
//
//Here means there are no DPots in the system anywhere
//
#undef POT_TEST_WOBBLE_SIGNAL_ON_SPECIFIED_OUTBOARD_ADC
#undef POT_TEST_WOBBLE_REFERENCE_ON_SPECIFIED_OUTBOARD_ADC
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

#ifdef POT_TEST_WOBBLE_SIGNAL_ON_SPECIFIED_OUTBOARD_ADC
#if ( 1 > POT_TEST_WOBBLE_SIGNAL_ON_SPECIFIED_OUTBOARD_ADC + 0 )
#undef POT_TEST_WOBBLE_SIGNAL_ON_SPECIFIED_OUTBOARD_ADC
#define POT_TEST_WOBBLE_SIGNAL_ON_SPECIFIED_OUTBOARD_ADC 0 //make sure it contains a bridge index or leg for non-bridged legs, default is bridge 0
#endif
#if ( POT_TEST_WOBBLE_SIGNAL_ON_SPECIFIED_OUTBOARD_ADC > 0 )
#error SINCE THIS HOLDS WHICH BRIDGE IS OF INTEREST, MULTIPLY IT BY # OF DPOTS PER BRIDGE WHERE IT IS USED BUT YOU'LL ALSO HAVE TO ADAPT THE PREPROCESSOR MACRO'D PREFILL PIN NUMBERS BY HAND.  PRIORITIES DON'T ALLOW ME TO DO IT FOR YOU
#endif
#endif
#ifdef POT_TEST_WOBBLE_REFERENCE_ON_SPECIFIED_OUTBOARD_ADC
#if ( 1 > POT_TEST_WOBBLE_REFERENCE_ON_SPECIFIED_OUTBOARD_ADC + 0 )
#undef POT_TEST_WOBBLE_REFERENCE_ON_SPECIFIED_OUTBOARD_ADC
#define POT_TEST_WOBBLE_REFERENCE_ON_SPECIFIED_OUTBOARD_ADC 0 //make sure it contains a bridge index or leg for non-bridged legs, default is bridge 0
#endif
#if ( POT_TEST_WOBBLE_REFERENCE_ON_SPECIFIED_OUTBOARD_ADC > 0 )
#error SINCE THIS HOLDS WHICH BRIDGE IS OF INTEREST, MULTIPLY IT BY # OF DPOTS PER BRIDGE WHERE IT IS USED BUT YOU'LL ALSO HAVE TO ADAPT THE PREPROCESSOR MACRO'D PREFILL PIN NUMBERS BY HAND.  PRIORITIES DON'T ALLOW ME TO DO IT FOR YOU
#endif
#endif

#define NUM_OF_DPOTS ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED )
#define GO_IN_SMALL_STEPS true
#define ADDRESS_THE_REFERENCE_LEG true
/*
  The following are globals since their contents can only be calculated at run-time and necessarily must remain accessible by every function without loss or recalculation, or are essential to the calculation of another global
  and we don't want to waste the CPU time of making them into preprocessor macros which would get calculated every single time the macro is used instead of just a single time when the DPotLeg of interest is changed
*/
static uint8_t dPotPins[ NUM_OF_DPOTS ];
static uint16_t dPotSettings[ NUM_OF_DPOTS ];
#if ( DPOT_LEGS_PER_ENTIRE_SYSTEM > 1 )
#define NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY 2
static uint16_t dPotLegMSBUsedAndAvailables[ NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY * DPOT_LEGS_PER_ENTIRE_SYSTEM ]; //This will only be needed on legs with > 1 Dpots: each leg can store totalAllMSBsThisLeg availableAllMSBsThisLeg
#define MSB_SETTINGS_TOTAL_THIS_LEG ( dPotLegMSBUsedAndAvailables[ NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY * dPotLeg ] )
#define MSB_SETTINGS_AVAILABLE_THIS_LEG ( dPotLegMSBUsedAndAvailables[ ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY * dPotLeg ) + 1 ] )
#define MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG ( dPotLegMSBUsedAndAvailables[ NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY * ( dPotLeg + 1 ) ] )
#define MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG ( dPotLegMSBUsedAndAvailables[ ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY * ( dPotLeg + 1 ) ) + 1 ] )
//usingGlobalValueOfDPotLegForAnalogPinArrayIndex ? \
//( uint16_t* )( unsigned long )&MSB_SETTINGS_TOTAL_THIS_LEG : \
//( uint16_t* ) ( ( unsigned long )&MSB_SETTINGS_TOTAL_THIS_LEG + ( unsigned long ) ( sizeof( dPotLegMSBUsedAndAvailables[ 0 ] ) * NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY ) )
//to
//...( uint16_t* )( unsigned long )&MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG

//( uint16_t* )( unsigned long )&MSB_SETTINGS_AVAILABLE_THIS_LEG : \
//( uint16_t* ) ( ( unsigned long )&MSB_SETTINGS_AVAILABLE_THIS_LEG + ( unsigned long ) ( sizeof( dPotLegMSBUsedAndAvailables[ 0 ] ) * NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY ) )
//to
//...( uint16_t* )( unsigned long )&MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG

#endif
/*
WHY WE DON'T GLOBALLY STORE THE BRIDGE IN CONTEXT LIKE WE DO THESE OTHER VARS:
Because sending the bridge as an argument instead is never inconvenient as
it is always handy from where functions are called that need to know it.
These globals are here b/c otherwise they would have to be recalculated
multiple times within the same bridge or leg context or else clutter 
function argument lists into too much ugliness.  Not so with bridge.
*/
static uint8_t indexOfThisDPotCSPinInDPotArrays = 0;
static uint8_t dPotLeg; // = indexOfThisDPotCSPinInDPotArrays < NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES ? \
( indexOfThisDPotCSPinInDPotArrays / DPOTS_PER_LM334_LEG ) : \
  indexOfThisDPotCSPinInDPotArrays < NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES ? \
  ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + ( ( indexOfThisDPotCSPinInDPotArrays - NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES ) / DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
  LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + ( ( indexOfThisDPotCSPinInDPotArrays - ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ) / NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED );
//static uint8_t dPotLegReference = dPotLeg + 1;

  static uint8_t dPotsPerThisLeg; // = ( dPotLeg < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
DPOTS_PER_LM334_LEG : \
  ( dPotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
    DPOTS_PER_BRIDGED_BARE_LEG : \
    DPOTS_PER_UNBRIDGED_BARE_LEG );

  static uint8_t firstDPotInLeg; // = ( dPotLeg < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
  ( dPotLeg * DPOTS_PER_LM334_LEG ) : \
  ( dPotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ) ? \
  ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + ( ( dPotLeg - LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) * DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
  ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES + ( ( dPotLeg - ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES ) * DPOTS_PER_UNBRIDGED_BARE_LEG ) ) );
  static uint8_t firstDPotInLegReference;// = firstDPotInLeg + dPotsPerThisLeg;

  static uint8_t lSBDPotOffsetThisLeg; // = firstDPotInLeg + ( lSBFirstDPotOrder ? 0 : dPotsPerThisLeg - 1 );
  static uint8_t lSBDPotOffsetThisLegReference;// = lSBDPotOffsetThisLeg + dPotsPerThisLeg;
  
  static uint8_t firstMSBInLeg; // = !lSBFirstDPotOrder ? firstDPotInLeg : firstDPotInLeg + 1;
    static uint8_t firstMSBInLegReference; // = firstMSBInLeg + dPotsPerThisLeg;

  static uint16_t mSBsGroupSize; // = dPotsPerThisLeg - 1; //cast to 16 bits b/c it will be used to divide settingValue which is 16 bits

  static uint8_t lastMSBInLeg; // = firstMSBInLeg + ( uint8_t ) mSBsGroupSize;
  static uint8_t lastMSBInLegReference; // = lastMSBInLeg + dPotsPerThisLeg;

  void configureFromDPotLeg()
{ //checking whether this got executed for the signal leg when the current context is for the reference leg: indexOfThisDPotCSPinInDPotArrays < firstDPotInLegReference ? <signal leg value> : <reference leg value>
  dPotsPerThisLeg = ( dPotLeg < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
                    DPOTS_PER_LM334_LEG : \
                    ( dPotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
                      DPOTS_PER_BRIDGED_BARE_LEG : \
                      DPOTS_PER_UNBRIDGED_BARE_LEG );

  mSBsGroupSize = dPotsPerThisLeg - 1; //cast to 16 bits b/c it will be used to divide settingValue which is 16 bits

  firstDPotInLeg = ( dPotLeg < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
                   ( dPotLeg * DPOTS_PER_LM334_LEG ) : \
                   ( dPotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ) ? \
                   ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + ( ( dPotLeg - LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) * DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
                   ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES + ( ( dPotLeg - ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES ) * DPOTS_PER_UNBRIDGED_BARE_LEG ) ) );
  firstDPotInLegReference = firstDPotInLeg + dPotsPerThisLeg;

  lSBDPotOffsetThisLeg = firstDPotInLeg + ( lSBFirstDPotOrder ? 0 : dPotsPerThisLeg - 1 );
  lSBDPotOffsetThisLegReference = lSBDPotOffsetThisLeg + dPotsPerThisLeg;

  firstMSBInLeg = !lSBFirstDPotOrder ? \
                  firstDPotInLeg : firstDPotInLeg + 1;
  firstMSBInLegReference = firstMSBInLeg + dPotsPerThisLeg;

  lastMSBInLeg = firstMSBInLeg + ( uint8_t ) mSBsGroupSize;
  lastMSBInLegReference = lastMSBInLeg + dPotsPerThisLeg;

}

void configureFromDPotIndex()
{
  dPotLeg = indexOfThisDPotCSPinInDPotArrays < NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES ? \
            ( indexOfThisDPotCSPinInDPotArrays / DPOTS_PER_LM334_LEG ) : \
            indexOfThisDPotCSPinInDPotArrays < NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES ? \
            ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + ( ( indexOfThisDPotCSPinInDPotArrays - NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES ) / DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
            LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + ( ( indexOfThisDPotCSPinInDPotArrays - ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ) / NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED );
  configureFromDPotLeg();
}

void configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( uint8_t bridge )
{
  dPotLeg = ( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) :  LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES + ( ( bridge - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) * LEGS_PER_DPOT_STYLE_BRIDGE );
  configureFromDPotLeg();
}

void configureForReferenceLegWithBridgeIndex( uint8_t bridge )
{ //Not using configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs b/c would be too wasteful of CPU
  dPotLeg = ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1;
  configureFromDPotLeg();
}

#define MAXPOTSETTG 256 //This settingValue is 1 less than the actual number of steps b/c the lowest setting is 0 - zero indexed, but since it equates to practical zero resistance this works fine

//    #if ( LM334_BRIDGES > 0 ) Just b/c this conforms to the pattern
//When using one or two 3:8 decoders, note that these pins numbers must be greater than 127
//Never use bit 6 of DPotPin for anything except to designate the second pot in a dual pkg
/*
    To scale up to multiple values of digipotsperleg:
  x1   fix BANK_0_LEG_0_LSB_DPOT names and such
  x2   fix index order within DPotSettings and DPotPins
  >3   fix LSB_DPOT_B0SIG_STARTVALUE names and such
  4   fix DPOT_RATIO to something that will work where it is used
  5
  Never use bit 6 of DPotPin for anything except to designate the second pot in a dual pkg

*/
//If a digipot is the second in a pkg, you will OR that digipot's pin number with B0100000 (add 64) like so: #define LSB_DPOT_B0SIG_PIN ( 7 + 64 ) would be for when pin 7 is the physical Arduino Digital pin
//If you find that you don't understand that, I'd encourage you to learn the topics of converting between hexadecimal, decimal, and binary and to learn bitwise boolean operations
#define LSB_DPOT_B0SIG_PIN 5         // Signal LSB fine adjust digital pot's CS line connected to here
#define LSB_DPOT_B0SIG_STARTVALUE 56 //52 - 54 or ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
//    #define LSB_DPOT_B0SIG_STARTVALUE 74 //or ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two DPots per leg

#if ( ( DPOTS_PER_LM334_LEG > 0 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 0 ) )
#define LSB_DPOT_B0REF_PIN 8        // Reference LSB fine adjust digital pot's CS line connected to here
#define LSB_DPOT_B0REF_STARTVALUE 57 //or ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
//        #define LSB_DPOT_B0REF_STARTVALUE 18 //or ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two DPots per leg
#endif
#if ( ( DPOTS_PER_LM334_LEG > 1 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 1 ) || ( DPOTS_PER_UNBRIDGED_BARE_LEG > 1 ) )
#define NON_LSB_DPOT_1_B0SIG_PIN 6          // second digital pot of signal leg CS line connected to here.  coarse adjust B positive (signal) leg
#define NON_LSB_DPOT_1_B0SIG_STARTVALUE 129 //or ( MAXPOTSETTG / 2 )  //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two or three DPots per leg
#endif
#if ( ( DPOTS_PER_LM334_LEG > 1 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 1 ) )
#define NON_LSB_DPOT_1_B0REF_PIN 9          // second digital pot of reference leg CS line connected to here.  coarse adjust B negative (reference) leg
#define NON_LSB_DPOT_1_B0REF_STARTVALUE 115 //or ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
//        #define NON_LSB_DPOT_1_B0REF_STARTVALUE 117 //or ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two DPots per leg
#endif
#if ( ( DPOTS_PER_LM334_LEG > 2 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ) || ( DPOTS_PER_UNBRIDGED_BARE_LEG > 2 ) )
#define NON_LSB_DPOT_2_B0SIG_PIN 7         // third digital pot of signal leg CS line connected to here.  coarse adjust B positive (signal) leg
#define NON_LSB_DPOT_2_B0SIG_STARTVALUE 0  //or ( MAXPOTSETTG / 2 )  //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest
#endif
#if ( ( DPOTS_PER_LM334_LEG > 2 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ) )
#define NON_LSB_DPOT_2_B0REF_PIN 10         // third digital pot of reference leg CS line connected to here.  coarse adjust B negative (reference) leg
#define NON_LSB_DPOT_2_B0REF_STARTVALUE 0  //or ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest
#endif
//none of this below works, yet.  It is in process of development; i.e., Only a single bridge of digipots is supported at this time...
#if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 1 )
#error none of this below works, yet.  It is in process of development; i.e., Only a single bridge of digipots is supported at this time...
#define LSB_DPOT_B1SIG_PIN 5  // digital pot's CS line connected to here. fine adjust signal leg
#define LSB_DPOT_B1REF_PIN 8 // digital pot's CS line connected to here. fine adjust reference leg
#define LSB_DPOT_B1SIG_STARTVALUE ( MAXPOTSETTG / 2 )  //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
#define LSB_DPOT_B1REF_STARTVALUE ( MAXPOTSETTG / 2 )  //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
#if ( ( DPOTS_PER_LM334_LEG > 1 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 1) )
#define NON_LSB_DPOT_1_B1SIG_PIN 6  // digital pot's CS line connected to here. coarse adjust signal leg
#define NON_LSB_DPOT_1_B1REF_PIN 9  // digital pot's CS line connected to here. coarse adjust reference leg
#define NON_LSB_DPOT_1_B1SIG_STARTVALUE ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
#define NON_LSB_DPOT_1_B1REF_STARTVALUE ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
#if ( ( DPOTS_PER_LM334_LEG > 2 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ) )
#define NON_LSB_DPOT_2_B1SIG_PIN 7  // digital pot's CS line connected to here. coarse adjust signal leg
#define NON_LSB_DPOT_2_B1REF_PIN 10  // digital pot's CS line connected to here. coarse adjust reference leg
#define NON_LSB_DPOT_2_B1SIG_STARTVALUE ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
#define NON_LSB_DPOT_2_B1REF_STARTVALUE ( MAXPOTSETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest to Vdd/2 - .1V (reads ~493 raw on the 10-bit Analog input)
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
    && ( NON_LSB_DPOT_2_B0SIG_PIN == 2 || NON_LSB_DPOT_2_B0SIG_PIN == 3 \
    || NON_LSB_DPOT_1_B0SIG_PIN == 2 || NON_LSB_DPOT_1_B0SIG_PIN == 3 \
    || LSB_DPOT_B0SIG_PIN == 2 || LSB_DPOT_B0SIG_PIN == 3 \
    || NON_LSB_DPOT_2_B0REF_PIN == 2 || NON_LSB_DPOT_2_B0REF_PIN == 3 \
    || NON_LSB_DPOT_1_B0REF_PIN == 2 || NON_LSB_DPOT_1_B0REF_PIN == 3 \
    || LSB_DPOT_B0REF_PIN == 2 || LSB_DPOT_B0REF_PIN == 3 \
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
#if ( DPOT_LEGS_PER_ENTIRE_SYSTEM > NUM_OF_INBOARDS_PLOTTED )
#define INDEX_OF_OUTBOARDS DPOT_LEGS_PER_ENTIRE_SYSTEM
#else
#define INDEX_OF_OUTBOARDS NUM_OF_INBOARDS_PLOTTED
#endif

struct previous_readings_only_of_inboards_and_outboards
{
  uint32_t CurrentUnmagnifiedReading;
  uint32_t PreviousUnmagnifiedReading;
  uint8_t IndexInlinespaceParametersArray;
} typedef previous_readings_only;

//To retrieve bridgeleg readings for non-plotting use, you must downconvert them with >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE (shift rights).
previous_readings_only masterReadingsArray[ INDEX_OF_OUTBOARDS + NUM_OF_OUTBOARDS_PLOTTED ];

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
linespace_bounds_and_magnify_trace_offsets linespaceParameters[ NUMBER_OF_LINESPACES ]; // INDEX_OF_INBOARDS_NOT_SUPERIMPOSED, being the start index for the not superimposed part of the array is also actually the number of superimposed inboards

static bool graphLine = false;
static uint32_t thisReadingTemp;
static long millisStart;
uint16_t plotterLoops;
#ifdef DEBUG
static char szFull[ ] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                        };
#endif
#define HEIGHT_OF_A_PLOT_LINESPACE ( ( uint32_t )pow( 2, HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC ) ) //casting as uint32_t allows calculations properly
#define PLOTTER_MAX_SCALE ( ( uint32_t )( HEIGHT_OF_A_PLOT_LINESPACE * NUMBER_OF_LINESPACES ) )
#define HALF_HEIGHT_OF_A_PLOT_LINESPACE ( ( uint32_t )( HEIGHT_OF_A_PLOT_LINESPACE / 2 ) )

#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) )
#define HALF_HEIGHT_INBOARD_SCALE_OF_A_PLOT_LINESPACE ( pow( 2, ANALOG_INPUT_BITS_OF_BOARD - 1 ) )
static uint16_t counterForTraceOutOfRangeTooLong[ NUM_OF_OUTBOARDS_PLOTTED ]; //Main intent is for DIFFERENTIAL input ADCs. This is also used to prevent infinite loop with AUTO_BRIDGE_BALANCING
#endif
#define HUNDREDTH_PLOTTER_MAX_SCALE ( PLOTTER_MAX_SCALE / 100 );
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
void readAndPlotFromAllADCsInAndOutboard( uint32_t, bool = false );

static uint8_t* analogPinArray = 0; //Initializing to 0 allows functions that would use it to know whether valid or not
#if ( ( defined DPOT_LEGS_PER_ENTIRE_SYSTEM ) && ( DPOT_LEGS_PER_ENTIRE_SYSTEM > 0 ) )
uint16_t midTwoOfFourSum( uint8_t /*REMEMBER: changing from bridge value to leg*/) {
  return ( 2 * ( 1 << ( ANALOG_INPUT_BITS_OF_BOARD - 1 ) ) );
}
void printDPotSettings()
{
  //    lSBFirstDPotOrder = true; //Only needed during conversion transition
  for( uint8_t dPotLeg = 0; dPotLeg < DPOT_LEGS_PER_ENTIRE_SYSTEM; dPotLeg++ )
  {
    Serial.print( F( "LegUnit<" ) );
    Serial.print( dPotLeg );
    Serial.print( F( ">, dPotsPerThisLeg=<" ) );
    uint8_t dPotsPerThisLeg = ( dPotLeg < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
                              DPOTS_PER_LM334_LEG : \
                              ( dPotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
                                DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG );
    Serial.print( dPotsPerThisLeg );
    Serial.print( F( ">" ) );
    for( uint8_t dPotUnit = 0; dPotUnit < dPotsPerThisLeg; dPotUnit++ )
    { //DPOTS_PER_LM334_LEG.
      Serial.print( F( ", dPotUnit=<" ) );
      Serial.print( dPotUnit );
      Serial.print( F( "> dPotPin=<" ) );
      Serial.print( dPotPins[ ( dPotLeg < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
                              ( ( dPotLeg * DPOTS_PER_LM334_LEG ) + dPotUnit ) : \
                              ( dPotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ) ? \
                              ( ( ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_BRIDGED_BARE_LEG ) ) + dPotUnit ) : \
                              ( ( ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + DPOTS_PER_BRIDGED_BARE_LEG ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_UNBRIDGED_BARE_LEG ) + dPotUnit ) ] );

      //Using dPotLeg and dPotUnit, obtain exact element of DPots in system and print its pin number:
      //Remember there are three major sections of DPot-built inboard elements within the DPot arrays - first section is bridged LM334, the next is bridged DPot non-LM334 ("bare DPot" which react opposite of LM334 to DPot settings changes), the third is non-bridged, bare DPot.  Sections beyond this are just inboards plotted having no DPots
      //                uint8_t indexOfThisDPotCSPinInDPotArrays = ;
      /* Where linespaceParametersIndex is known:

        Serial.print( actuals ? linespaceParameters[ linespaceParametersIndex ].LastSignalPinPlotPoint + linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace: 0 ); //I think this looks better than the line above
        Serial.print( F( " " ) );
        if( linespaceParametersIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) //The same as comparing masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED
          #if not defined PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
              Serial.print( actuals ? linespaceParameters[ linespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace : 0 ); //I think this looks better than the line above
          #endif
        else //outside the range of concern
        {}


        Where masterReadingsArrayIndex is known:

          if( ( masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) && !( masterReadingsArrayIndex % 2 ) ) //This is the case for those ADCs that have just had their current readings refreshed immediately prior to teh execution of this function, so use the stored readings.  Note also that the standard linespace is designed large enough to always accommodate plotting the full unmagnified reading
              Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one of pair
          }
          else if( masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) //This is still the case for those ADCs that have just had their current readings refreshed immediately prior to teh execution of this function, so use the stored readings.  Note also that the standard linespace is designed large enough to always accommodate plotting the full unmagnified reading
          {
          #if not defined PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
              Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color two of pair
          #endif
          }

        Where only dPotLeg index is known: ?

        ( dPotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ) ? \ <dPotLeg % 2 == 0 for reference legs, all others are signal legs>

        ( ( dPotLeg % 2 == 0 ) ? ", signal" : ", reference" ) : \ <all are signal legs>
        ( ( ", signal" )


        dPotsPerThisLeg =
        ( dPotLeg < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
           DPOTS_PER_LM334_LEG : \
           ( dPotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ) ? \
           DPOTS_PER_BRIDGED_BARE_LEG : \
           DPOTS_PER_UNBRIDGED_BARE_LEG
      */
      Serial.print( F( ">" ) );

      bool signalTrueReferenceFalse = ( dPotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ) ? \
                                      ( ( dPotLeg % 2 == 0 ) ? true : false ) : \
                                      true;

      if( signalTrueReferenceFalse )
        Serial.print( F( ", signal " ) );
      else
        Serial.print( F( ", reference " ) );
      //Until the LSB/MSB conversion is complete, this is backwards:
      if( ( !lSBFirstDPotOrder  && ( dPotUnit == dPotsPerThisLeg - 1 ) ) || ( lSBFirstDPotOrder  && ( dPotUnit == 0 ) ) )
        Serial.print( F( "LSB " ) );
      else
        Serial.print( F( "MSB " ) );
      Serial.print( F( "setting=<" ) );
      Serial.print( dPotSettings[ ( dPotLeg < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
                                  ( ( dPotLeg * DPOTS_PER_LM334_LEG ) + dPotUnit ) : \
                                  ( dPotLeg < ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ) ? \
                                  ( ( ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_BRIDGED_BARE_LEG ) ) + dPotUnit ) : \
                                  ( ( ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + DPOTS_PER_BRIDGED_BARE_LEG ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_UNBRIDGED_BARE_LEG ) + dPotUnit ) ] );
      if( dPotUnit == 0 || dPotUnit == dPotsPerThisLeg )
      {
        Serial.print( F( ">, " ) );
        if( signalTrueReferenceFalse )
          Serial.print( F( "signal" ) );
        else
          Serial.print( F( "reference" ) );
        Serial.print( F( " tentative voltage=<" ) );
        if( analogPinArray == 0 )
        {
          Serial.println( F( "analogPinArray not configured yet. Unable to know pin numbers to read any analog level from them>" ) );
          return; //Note that the previous line sends a line feed
        }
        if( dPotUnit == dPotsPerThisLeg )
          Serial.print( midTwoOfFourSum( dPotLeg ) / 2 );
        else
          Serial.print( midTwoOfFourSum( dPotLeg + 1 ) / 2 );
        Serial.print( F( "> " ) );
      }
      else Serial.print( F( "> " ) );
      Serial.print( F( "> dPotUnit=<" ) );
      Serial.print( dPotUnit );
      Serial.print( F( "> " ) );
    }
  }
}

void writeSettingToAsingleDPot( uint8_t, uint16_t );
void setDPotOrMSBGroupValue( uint8_t indexOfThisDPotCSPinInDPotArrays, /*always will either be 1st or last DPot in leg, is currently coming in at one high from setDPotLegMidPoint()*/ \
                             uint16_t settingValue /*16 bits to allow cumulative settingValue of msb group to about 250 DPots in the group*/ )
{
  //        Goal in waiting: make this able to detect whether index is an LSB or an MSB group
  Serial.print( F( "Just entered setDPotOrMSBGroupValue, " ) );
    bool thisIsReferenceWhenConfigureWasForSignal;
  if( !analogPinArray )
  {
    Serial.print( F( "indexOfThisDPotCSPinInDPotArrays=<" ) );
    Serial.print( indexOfThisDPotCSPinInDPotArrays );
  }
  else
  {
    thisIsReferenceWhenConfigureWasForSignal = !( indexOfThisDPotCSPinInDPotArrays < firstDPotInLegReference );
    if( analogPinArray )
    {
        Serial.print( F( "> which is pin #<" ) );
        Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
        Serial.print( F( "> " ) );
    }
    if( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg ) )
      goto AfterMSBCombining;
    Serial.print( F( "> about to get set to<" ) );
    Serial.print( settingValue );
    Serial.print( F( "> " ) );
    
/*
    Serial.print( F( "pin#=<" ) );
    Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
    Serial.print( F( "> from indexOfThisDPotCSPinInDPotArrays=<" ) );
    Serial.print( indexOfThisDPotCSPinInDPotArrays );
    Serial.print( F( "> firstDPotInLeg=<" ) );
    Serial.print( firstDPotInLeg );
    Serial.print( F( "> firstDPotInLegReference=<" ) );
    Serial.print( firstDPotInLegReference ); 
    Serial.print( F( "> raw lSBDPotOffsetThisLeg=<" ) );
    Serial.print( lSBDPotOffsetThisLeg );
    Serial.print( F( "> dPotsPerThisLeg=<" ) );
    Serial.print( dPotsPerThisLeg ); 
    Serial.print( F( "> settingValue=<" ) );
    Serial.print( settingValue );
    Serial.print( F( "> lSBFirstDPotOrder=<" ) );
    Serial.print( lSBFirstDPotOrder );
    Serial.print( F( "> " ) );
    Serial.print( F( "dPotLeg=<" ) );
    Serial.print( dPotLeg );
    Serial.print( F( "> thisIsReferenceWhenConfigureWasForSignal=<" ) );
    Serial.print( thisIsReferenceWhenConfigureWasForSignal );
    Serial.print( F( "> indexOfThisDPotCSPinInDPotArrays=<" ) );
    Serial.print( indexOfThisDPotCSPinInDPotArrays );
    Serial.print( F( "> pin=<" ) );
    Serial.print( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
    Serial.print( F( "> dPotsPerThisLeg=<" ) );
    Serial.print( dPotsPerThisLeg );
    Serial.print( F( "> firstDPotInLeg=<" ) );
    Serial.print( thisIsReferenceWhenConfigureWasForSignal ? firstDPotInLegReference  : firstDPotInLeg );
    Serial.print( F( "> firstMSBInLeg=<" ) );
    Serial.print( thisIsReferenceWhenConfigureWasForSignal ? firstMSBInLegReference : firstMSBInLeg );
    Serial.print( F( "> lSBDPotOffsetThisLeg=<" ) );
    Serial.print( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg );
    Serial.print( F( "> mSBsGroupSize=<" ) );
    Serial.print( mSBsGroupSize );
    Serial.print( F( ">," ) );
    Serial.print( F( "> MSBs available Line957=<" ) );
    Serial.print( MSB_SETTINGS_AVAILABLE_THIS_LEG );
    //            Serial.print( F( "> MSB_SETTINGS_AVAILABLE_THIS_LEG=<" ) );
    //            Serial.print( MSB_SETTINGS_AVAILABLE_THIS_LEG );
    Serial.print( F( "> " ) );
    Serial.print( F( ". Entered MSBCombining section of setDPotOrMSBGroupValue with DPot index=<" ) );
    Serial.print( indexOfThisDPotCSPinInDPotArrays );
    Serial.print( F( "> and pin there=<" ) );
    Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
    Serial.print( F( "> firstMSBInLeg=<" ) );
    Serial.print( thisIsReferenceWhenConfigureWasForSignal ? firstMSBInLegReference : firstMSBInLeg );
    Serial.print( F( ">" ) );
*/
    //Make agnostic to which MSB was spec'd:
    uint8_t mSBDPot = thisIsReferenceWhenConfigureWasForSignal ? firstMSBInLegReference : firstMSBInLeg;
    for( uint8_t counter = 0; counter < mSBsGroupSize - 1; counter++ )
    { //This will fix all but last one which will need to correct for rounding errors
/*
      Serial.print( F( " Line <1096> mSBDPot=<" ) );
      Serial.print( mSBDPot );
      Serial.print( F( "> pin[" ) );
      Serial.print( dPotPins[ mSBDPot ] );
      Serial.print( F( "> dPotSettings=<" ) );
      Serial.print( dPotSettings[ mSBDPot ] );
      Serial.print( F( "> dPotSettings+1=<" ) );
      Serial.print( dPotSettings[ mSBDPot + 1 ] );
      Serial.print( F( "> dPotSettings+2=<" ) );
      Serial.print( dPotSettings[ mSBDPot + 2 ] );
      Serial.print( F( "> dPotSettings+3=<" ) );
      Serial.print( dPotSettings[ mSBDPot + 3 ] );
      Serial.print( F( "> dPotSettings+4=<" ) );
      Serial.print( dPotSettings[ mSBDPot + 4 ] );
      Serial.print( F( "> dPotSettings+5=<" ) );
      Serial.print( dPotSettings[ mSBDPot + 5 ] );
      Serial.print( F( "] about to get set to<" ) );
      Serial.print( settingValue / mSBsGroupSize );
      Serial.print( F( ">, " ) );
*/
      writeSettingToAsingleDPot( mSBDPot, ( settingValue / mSBsGroupSize ) );
/*
      Serial.print( F( "> Line <1102> dPotSettings[" ) );
      Serial.print( dPotPins[ mSBDPot ] );
      Serial.print( F( "] got set to<" ) );
      Serial.print( dPotSettings[ mSBDPot ] );
      Serial.print( F( ">, " ) );
*/
      mSBDPot++;
    }
/*
    Serial.print( F( " Line <1108> dPotSettings[" ) );
    Serial.print( dPotPins[ mSBDPot ] );
    Serial.print( F( "] about to get set to<" ) ); */
//    Serial.print( settingValue - ( ( ( uint16_t/*force possible rounding errors to re-appear here to compensate for them*/)( settingValue / mSBsGroupSize ) ) * ( mSBsGroupSize - 1 ) ) );
    writeSettingToAsingleDPot( mSBDPot,  settingValue - ( ( ( uint16_t/*force possible rounding errors to re-appear here to compensate for them*/)( settingValue / mSBsGroupSize ) ) * ( mSBsGroupSize - 1 ) ) ); //correct for rounding errors
    ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : MSB_SETTINGS_TOTAL_THIS_LEG ) = settingValue; //This makes individual MSB settings not accessible for modifying after analogPinArray is assigned unless you save it's setting, make it zero momentarily while this functions is called
    ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG ) = ( mSBsGroupSize * MAXPOTSETTG ) - settingValue;
/*
    Serial.print( F( "> Line <1113> dPotSettings[" ) );
    Serial.print( dPotPins[ mSBDPot ] );
    Serial.print( F( "] got set to<" ) );
*/
//    Serial.print( settingValue - ( ( ( uint16_t/*force rounding errors to manifest here*/)( settingValue / mSBsGroupSize ) ) * ( mSBsGroupSize - 1 ) ) );
/*
    Serial.print( F( ">, MSB_SETTINGS_TOTAL_THIS_LEG=<" ) );
    Serial.print( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : MSB_SETTINGS_TOTAL_THIS_LEG );
    Serial.print( F( ">, MSB_SETTINGS_AVAILABLE_THIS_LEG=<" ) );
    Serial.print( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG );
    Serial.println( F( "> " ) );
*/
    Serial.flush();
    return;
  }
AfterMSBCombining:
  //LSB pins get fastracked to here
  if( settingValue > MAXPOTSETTG ) settingValue = MAXPOTSETTG;
  else if( settingValue < 0 ) settingValue = 0;
  if( analogPinArray )
  {
    Serial.print( F( "> which is pin #<" ) );
    Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
    Serial.print( F( "> dPotSettings[" ) );
    Serial.print( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays );
    Serial.print( F( "]about to get set to<" ) );
    Serial.print( settingValue );
    Serial.print( F( ">, " ) );
    dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] = settingValue < MAXPOTSETTG ? settingValue : MAXPOTSETTG; //make to accommodate MSB groups
    settingValue = dPotSettings[ indexOfThisDPotCSPinInDPotArrays ]; //setting settingValue but it's existence is only until end of function (transient)
  }
  else
    Serial.print( F( ">" ) );
  writeSettingToAsingleDPot( indexOfThisDPotCSPinInDPotArrays, settingValue );
  Serial.flush();
}

void writeSettingToAsingleDPot( uint8_t indexOfThisDPotCSPinInDPotArrays, uint16_t settingValue )
{
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
  //This is not tested, it is just a first proposed step to give capability for many ADCs
  if( ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) >= 128 )
  { //Pins numbered below 128 are normal digital inboard pins
    //Pins numbered above 127 are outboard pins provided through the dual 74LV138 decoding circuitry
    //The two 74LV138 each have three enable pins but we only use one.
    //It would require 7 pins to address the two devices simultaneously.
    //Use 'em since we have them...it'll save a part for latch
    digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A0_PIN,  ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B1 );  //These address bits are always necessary
    digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A1_PIN,  ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B10 ); //These address bits are always necessary
    digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A2_PIN,  ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B100 ); //These address bits are always necessary
    digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A0_PIN, ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B1000 ); //This decoder might not be present
    digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A1_PIN, ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B10000 ); //This decoder might not be present
    digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A2_PIN, ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B100000 );  //This decoder might not be present
    //bit B1000000 is reserved for virtualizing the second DPot in a dual DPot pkg MCP42xxx
    //Never use bit 6 of dPotPins[ indexOfThisDPotCSPinInDPotArrays ] for anything except to designate the second pot in a dual pkg MCP42xxx
    digitalWrite( BOTH_STAGES_3_TO_8_DECODER_ENABLE_PIN, LOW ); // In prep for next instruction
  }
#endif
  digitalWrite( ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & 0x3FF, LOW );
  SPI.transfer( ( settingValue & 0x100 ) ? ( ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : \
                indexOfThisDPotCSPinInDPotArrays ) & 0x400 ? 0x11 : 1 ) : \
                ( ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : \
                    indexOfThisDPotCSPinInDPotArrays ) & 0x400 ? 0x10 : 0 ) ); //This is the way we allow dual dpot devices MCP42xxx
  SPI.transfer( settingValue & 0xFF ); // send settingValue (0~255)
  /**********************************************************************************************************************************************************
    When dual pots are employed (MCP42XXX) this is the way to control the second DPOT in the pkg:  the first digi pot of a pkg is addressed with true pin number,
    the second digipot in the pkg is addressed by adding 64 to the physical pin number driving the pkg, creating a virtual pin number for that second DPot of the pkg
          SPI.transfer( ( settingValue & 0x100 ) ? 0x11 : 0x10 ); //NOTE THE LEADING 1 HERE THAT DOESN'T APPEAR FOR MCP41XXX - it's part of the 0x10
          SPI.transfer( settingValue & 0xff ); // send settingValue (0~255)

    In order to utilize this method, both dual pots share a single physical CS (dPotPins[ indexOfThisDPotCSPinInDPotArrays ]) pin (remember ones above 127 pin numbers are connected via 3-to-8 decoders)
    but virtually the second DPot's physical dPotPins[ indexOfThisDPotCSPinInDPotArrays ] must be OR'd with 0x40 (adding 64) in this sketch.  Note that two different schemes of dual DPot can exist:
    duals shared on same leg and duals shared across legs.  By adhering to the afore-described pin numbering methodology, either scheme or both mixed
    throughout the system will work fine.  Note that if any boards have actual physical pins numbered above 64, those cannot be used for DPotPins without sketch
    modification to accommodate it.

  ***********************************************************************************************************************************************************/
  digitalWrite( ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & 0x3FF, HIGH );
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
    digitalWrite( BOTH_STAGES_3_TO_8_DECODER_ENABLE_PIN, HIGH );
#endif
Serial.print( F( "Pin <" ) );
if( analogPinArray ) 
{
Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
}
else
{
Serial.print( indexOfThisDPotCSPinInDPotArrays );
}
  Serial.print( F( "> got set to <" ) );
  Serial.print( settingValue );
  Serial.print( F( "> " ) );
  if( analogPinArray ) 
  {
    dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] = settingValue;
      Serial.print( F( "and settings saved to dPotSettings[" ) );
        Serial.print( indexOfThisDPotCSPinInDPotArrays );
      Serial.print( F( "] " ) );
  }
  if( !analogPinArray ) Serial.println();
  Serial.flush();
}

void offsetDPotOrMSBGroupValue( uint8_t indexOfThisDPotCSPinInDPotArrays, int16_t/*has to be signed*/ offsetValue )
{ //configureFrom...() and configureFor...() must already be ran //Making able to handle MSB groups
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  Serial.print( F( " Entering offsetDPotOrMSBGroupValue for pin<" ) );
  Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
  Serial.print( F( ">, offsetValue<" ) );
  Serial.print( offsetValue );
  Serial.print( F( "> " ) );
#endif
#ifdef DEBUG
  //        offsetValue *= 10;  //A magnifier for troubleshooting
  while( !Serial );
  Serial.print( F( "Line 775 offsetValue=" ) );
  Serial.print( offsetValue );
  Serial.print( F( " for Digi pot on pin " ) );
#endif
    bool thisIsReferenceWhenConfigureWasForSignal = !( indexOfThisDPotCSPinInDPotArrays < firstDPotInLegReference );
  Serial.print( F( ">, thisIsReferenceWhenConfigureWasForSignal<" ) );
  Serial.print( thisIsReferenceWhenConfigureWasForSignal );
//thisIsReferenceWhenConfigureWasForSignal ? dPotsPerThisLeg + 
  if( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg ) )
  {
    int16_t borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO = ( \
        ( offsetValue < 0 ) ?/*LSB is needing*/( ( offsetValue + dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) / DPOT_RATIO )/*borrows signed negative*/ : \
        /*LSB is needing*/( ( offsetValue - ( MAXPOTSETTG - dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) ) / DPOT_RATIO )/*carries signed positive*/ );
    //recursive call for borrow/carry against the MSB group
  Serial.print( F( ">, making a recursive call with borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO<" ) );
  Serial.print( borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO );
  Serial.print( F( ">..." ) );
    offsetDPotOrMSBGroupValue( thisIsReferenceWhenConfigureWasForSignal ? dPotsPerThisLeg + firstMSBInLeg : firstMSBInLeg, borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO );
  Serial.print( F( "back after recursive call " ) );
    offsetValue -= borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO * DPOT_RATIO;
  Serial.print( F( ", offsetValue now<" ) );
  Serial.print( offsetValue );
  Serial.print( F( ">, with offsetValue now<" ) );
  Serial.print( offsetValue );
  }
  //Sanity check on offset amount being requested:

//#error Fix the next lines like we had them fixed once already!

//if to go negative, check for underflow
//if to go positive, check for overflow 
  Serial.print( F( ">, lSBDPotOffsetThisLeg<" ) );
  Serial.print( lSBDPotOffsetThisLeg );
  Serial.print( F( ">, MSB_SETTINGS_TOTAL_THIS_LEG<" ) );
  Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
  Serial.print( F( ">, MSB_SETTINGS_AVAILABLE_THIS_LEG<" ) );
  Serial.print( MSB_SETTINGS_AVAILABLE_THIS_LEG );
  Serial.print( F( ">, dPotSettings[ indexOfThisDPotCSPinInDPotArrays ]<" ) );
  Serial.print( dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] );
  Serial.print( F( "> " ) );

if( ( offsetValue < 0 ) && ( ( 0 - offsetValue ) > ( ( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg ) ? dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : MSB_SETTINGS_TOTAL_THIS_LEG ) ) ) ) || \
    ( ( offsetValue > 0 ) && ( offsetValue > ( ( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg ) ? ( offsetValue > ( MAXPOTSETTG - dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) ) : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG ) ) ) ) ) )
{ //Beyond limit being asked for.  This location is where to add carrying/borrowing feature
    Serial.print( F( "Beyond limit, limiting offset request of <" ) );
    Serial.print( offsetValue );
    Serial.print( F( "> to <" ) );

    if( offsetValue < 0 ) // && ( ( 0 - offsetValue ) > 
    {
        if( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg ) ) //( ( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg ) ? dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] 
            offsetValue = 0 - dPotSettings[ indexOfThisDPotCSPinInDPotArrays ];/*a negative LSB value equaling zero minus the current setting*/
        else // : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : MSB_SETTINGS_TOTAL_THIS_LEG ) ) ) ) )
            offsetValue = 0 - ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : MSB_SETTINGS_TOTAL_THIS_LEG );/*a negative MSB value equaling zero minus the current total*/
    }
    else //if( ( offsetValue < 0 ) && ( offsetValue > ( ( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg ) ? ( offsetValue > ( MAXPOTSETTG - dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) ) : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG ) ) ) ) )
        if( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg ) ) //( ( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg ) ? dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] 
            offsetValue = dPotSettings[ indexOfThisDPotCSPinInDPotArrays ];/*a negative LSB value equaling the current setting*/
        else // : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : MSB_SETTINGS_TOTAL_THIS_LEG ) ) ) ) )
            offsetValue = thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG;/*a positive MSB value equaling the current available*/

    Serial.print( offsetValue );
    Serial.print( F( ">." ) );
  }//Sanity enforcement complete

if( indexOfThisDPotCSPinInDPotArrays == \
( thisIsReferenceWhenConfigureWasForSignal ? \
lSBDPotOffsetThisLegReference : lSBDPotOffsetThisLeg ) )
    offsetValue += dPotSettings[ indexOfThisDPotCSPinInDPotArrays ];
else
    offsetValue += MSB_SETTINGS_TOTAL_THIS_LEG;
#ifdef DEBUG
  while( !Serial );
  Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
  Serial.print( F( " getting " ) );
  Serial.print( offsetValue );
#endif
  //setDPotOrMSBGroupValue( const uint8_t DPotPin, uint16_t settingValue ) or writeSettingToAsingleDPot()
  setDPotOrMSBGroupValue( indexOfThisDPotCSPinInDPotArrays, ( uint16_t )offsetValue );
}

//#error The following function needs to get fixed next
bool stepAdjustDPotsForThisLeg( bool voltsDown = TAKE_LEG_VOLTAGE_DOWN, bool justQueryingWhetherSettingsAreMaxedOut = false ) //default direction will be positive
//    bool stepAdjustDPotsForThisLeg( uint8_t firstMSBInLeg, uint16_t* mSBpotValue, uint8_t mIDpotPinIndex, uint16_t* mIDpotValue, uint8_t lSBDPotOffsetThisLeg, uint16_t* lSBpotValue, \
bool voltsDown = true, bool justQueryingWhetherSettingsAreMaxedOut = false, bool dPotNamesReversed = false, bool lSBFirstDPotOrder = false ) //defaults: direction will be positive, not justquerying, not reversed
//If entering (calling) this function with !usingGlobalValueOfDPotLegForAnalogPinArrayIndex, ensure the globals for the signal leg of this bridge DID get configured, since they are consequently the reference point for in here
{ // This effectively increments or decrements LSB digipot setting just once
  //For transitional purposes, recreate dPotLeg, etc of future function
  //NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES
  //    dPotNamesReversed = true; //Only needed during conversion transition
  //    lSBFirstDPotOrder = true; //Only needed during conversion transition
  //real ones
  //    uint16_t* firstDPotInLeg = lSBFirstDPotOrder ? lSBpotValue : mSBpotValue; //Only needed during conversion transition, easily changed to LSB when ready
  //    uint8_t firstDPotInLeg = ( uint8_t )( ( ( unsigned long )firstDPotInLeg - ( unsigned long )dPotSettings ) / sizeof( dPotSettings[ 0 ] ) ); //equates to the DPot index of MSBpot in the two Dpot arrays
  //            #error                                                                                                                     //used to reverse-engineer which leg is of concern
  //temp ones:
  //    uint16_t* firstDPotInLeg = lSBFirstDPotOrder ? lSBpotValue : mSBpotValue; //Only needed during conversion transition, easily changed to LSB when ready
  //    uint8_t firstDPotInLeg = 2;
  //    ( uint8_t )( ( ( unsigned long )firstDPotInLeg - ( unsigned long )dPotSettings ) / sizeof( dPotSettings[ 0 ] ) ); //equates to the DPot index of MSBpot in the two Dpot arrays
  //reverse-engineer which leg is of concern: only useful until function conversion is completed at which time this will be an argument sent in
  //    uint8_t dPotLeg = firstDPotInLeg < NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES ? \
  //        ( ( ( unsigned long )firstDPotInLeg - ( unsigned long )dPotSettings ) / ( sizeof( dPotSettings[ 0 ] ) * DPOTS_PER_LM334_LEG ) )\
  //        : firstDPotInLeg < NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES + NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES ? \
  //        ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM  + ( ( ( unsigned long )firstDPotInLeg - ( unsigned long )dPotSettings[ NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES ] ) / ( sizeof( dPotSettings[ 0 ] ) * DPOTS_PER_BRIDGED_BARE_LEG ) ) ) \
  //        : LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + ( ( ( unsigned long )firstDPotInLeg - ( unsigned long )dPotSettings[ LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ] ) / ( sizeof( dPotSettings[ 0 ] ) * NUM_OF_DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ) );
  Serial.print( F( "Going " ) );
  if( voltsDown )
    Serial.print( F( "down" ) );
  else
    Serial.print( F( "up" ) );
  Serial.print( F( " in stepAdjustDPotsForThisLeg =<" ) );
  Serial.print( dPotLeg );
  Serial.print( F( "> firstDPotInLeg=<" ) );
  Serial.print( firstDPotInLeg );
  Serial.print( F( "> MSBpotPin=<" ) );
  Serial.print( dPotPins[ firstMSBInLeg ] );
  Serial.print( F( "> sizeof( dPotSettings[0]=<" ) );
  Serial.print( sizeof( dPotSettings[ 0 ] ) );
  Serial.print( F( "> DPOTS_PER_LM334_LEG=<" ) );
  Serial.print( DPOTS_PER_LM334_LEG );
  //        uint8_t dPotLeg = /*don't make locals, use terciaries instead:*/
  // ( usingGlobalValueOfDPotLegForAnalogPinArrayIndex ) ? dPotLeg : ( dPotLeg + 1 )
  //uint8_t firstDPotInLeg =
  // ( usingGlobalValueOfDPotLegForAnalogPinArrayIndex ) ? firstDPotInLeg : ( firstDPotInLeg + dPotsPerThisLeg ); //equates to the DPot index of MSBpot in the two Dpot arrays
  //uint8_t lSBDPotOffsetThisLeg =
  // ( usingGlobalValueOfDPotLegForAnalogPinArrayIndex ) ? lSBDPotOffsetThisLeg : ( lSBDPotOffsetThisLeg + dPotsPerThisLeg )
  //uint8_t firstMSBInLeg =
  // ( usingGlobalValueOfDPotLegForAnalogPinArrayIndex ) ? firstMSBInLeg : ( firstMSBInLeg + dPotsPerThisLeg );
  //uint16_t* lSBpotValue = \
  // &dPotSettings[ ( usingGlobalValueOfDPotLegForAnalogPinArrayIndex ) ? lSBDPotOffsetThisLeg : ( lSBDPotOffsetThisLeg + dPotsPerThisLeg ) ];
  //uint16_t* mSBpotValue =
  // ( usingGlobalValueOfDPotLegForAnalogPinArrayIndex ) ? \
  // ( uint16_t* )( unsigned long )&MSB_SETTINGS_TOTAL_THIS_LEG : \
  // ( uint16_t* )( ( unsigned long )&MSB_SETTINGS_TOTAL_THIS_LEG + \
  // ( unsigned long )( sizeof( dPotLegMSBUsedAndAvailables[ 0 ] ) * \
  // NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY );
  /*
      if( dPotNamesReversed && ( dPotsPerThisLeg > 1 ) )
      {//reverse MSB and LSB pins and settingValues without explicitely making a temporary variable
          mSBpotValue += ( unsigned long )lSBpotValue; //I don't know why, but this is the only casting needed in my IDE environment in this construct.  If yours errors out elsewhere in this construct, add more of these castings
          lSBpotValue = mSBpotValue - lSBpotValue;
          mSBpotValue -= lSBpotValue;
          firstMSBInLeg += lSBDPotOffsetThisLeg;
          lSBDPotOffsetThisLeg = firstMSBInLeg - lSBDPotOffsetThisLeg;
          firstMSBInLeg -= lSBDPotOffsetThisLeg;
      }
  */
  //from    uint8_t lastDPotIndexThisLeg = firstDPotInLeg + dPotsPerThisLeg;   to v
    uint8_t lastDPotIndexThisLeg = firstDPotInLeg + dPotsPerThisLeg - 1;
  //Limit checking not tested :TODO test all this limit coding
  if( justQueryingWhetherSettingsAreMaxedOut )
  { //returning false means failure of digipot settings that they are either maxed high or minimized zeroes whichever one was queried
    for( uint8_t dPotIndexThisLeg = firstDPotInLeg; dPotIndexThisLeg <= lastDPotIndexThisLeg; dPotIndexThisLeg++ )
      if( dPotSettings[ dPotIndexThisLeg ] != dPotSettings[ firstDPotInLeg ] ) return true;
  }
skipMakingLocalDPotLeg:
  if( analogPinArray )
  {
    Serial.print( F( "> dPotLeg=<" ) );
    Serial.print( dPotLeg );
  }
  Serial.print( F( ">" ) );
  //The following construct acts whether justQuerying... or not
  if( voltsDown ) //This means querying whether the settings are maxed high and the voltage will be minimium low
  {
    Serial.print( F( "Line <1066> " ) );
    if( ( dPotSettings[ lSBDPotOffsetThisLeg ] == MAXPOTSETTG ) && ( MSB_SETTINGS_AVAILABLE_THIS_LEG == 0 ) )
      return false;
  }
  else
  {
    if( ( dPotSettings[ lSBDPotOffsetThisLeg ] == 0 ) && ( MSB_SETTINGS_TOTAL_THIS_LEG == 0 ) )
      return false;
  }
  if( justQueryingWhetherSettingsAreMaxedOut ) return true;
  //        while( !Serial );
  //        Serial.print( F( " stepAdjustDPotsForThisLeg called" ) );
  //        Serial.print( F( " sADFTLc " ) );
#ifdef DEBUG
  Serial.print( F( " on " ) );
  Serial.print( firstMSBInLeg );
#endif
  //        Serial.print( F( " going " ) );
  //        Serial.print( voltsDown ? "down ": "up ");
#ifdef DEBUG
  Serial.println();
#endif
  //if going up and totalValueCoarse is already MAXPOTSETTG * 2, add one to value_fine if it is less than MAXPOTSETTG, else return false; save new value; return true
  //if going up still and either coarse value is MAXPOTSETTG, only increment the other value, save new, return true;
  //if going up and neither coarse value is MAXPOTSETTG, increment MID with a switch statement, save new
  //        for( uint8_t pin = 0; pin < 6; pin++ )
  Serial.print( F( "Line <1097> " ) );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    for( uint8_t dPotIndexThisLeg = firstDPotInLeg; dPotIndexThisLeg <= lastDPotIndexThisLeg; dPotIndexThisLeg++ )
  {
    Serial.print( F( " Entering dPotSettings[" ) );
    Serial.print( dPotPins[ dPotIndexThisLeg ] );
    Serial.print( F( "]=<" ) );
    Serial.print( dPotSettings[ dPotIndexThisLeg ] );
    Serial.print( F( ">" ) );
  }
#endif
  uint16_t totalValueCoarse = MSB_SETTINGS_TOTAL_THIS_LEG;
#if ( DPOTS_PER_LM334_LEG != 3 )
    #error Not able to handle this number of DPots per leg
#endif
  //TODO: make more efficient:
//  uint16_t* thisDPotValuePtr = &MSB_SETTINGS_TOTAL_THIS_LEG;   /* firstDPotInLeg will be MSB until conversion complete  */
//        uint16_t* thisDPotValuePtr = MSBpotValue;   /* firstDPotInLeg will be MSB until conversion complete  */

  //        for( uint8_t dPotIndexThisLeg = 0; dPotIndexThisLeg < dPotsPerThisLeg - 1/*number of MSB DPots per this leg*/; dPotIndexThisLeg++ ) //Visit all MSBs traversing the leg from one short of MSD to one shy of LSB
  //        { //proceed relative direction from MSB to one short of LSB, absolute direction depends on whether [possibly renamed] LSB is located above or below [possibly renamed] MSB in array
  //            thisDPotValuePtr = ( unsigned long )lSBpotValue > ( unsigned long )mSBpotValue ? thisDPotValuePtr + ( unsigned long )sizeof( dPotSettings[ 0 ] ) : thisDPotValuePtr - ( unsigned long )sizeof( dPotSettings[ 0 ] ); //[in/de]crement one towards LSB but break if == LSB
  //            if( thisDPotValuePtr == lSBpotValue ) break; //not necessary
  //            totalValueCoarse += ( int )*thisDPotValuePtr; //Totaling the MSBs to know if borrowing/carrying will be possible if indicated
  //        }
        if( voltsDown ) //Positive direction == true
        { //being told to decrement so the voltage goes up
            Serial.print( F( " Entered with voltsDown as true " ) );
            if( ( dPotSettings[ lSBDPotOffsetThisLeg ] > DPOT_RATIO - 1 ) && ( dPotSettings[ lSBDPotOffsetThisLeg ] >= MAXPOTSETTG ) && ( mSBsGroupSize >= 1 /*stops the next evaluation from being divide by zero*/) && ( totalValueCoarse / mSBsGroupSize ) < MAXPOTSETTG ) //This catches dPotSettings[ lSBDPotOffsetThisLeg ] having or about to have a value higher than DPOT_RATIO - 1 when it needn't.  So we cycle it down
            { //This loop is preparatory just to know if the entire DPot leg has some range remaining
                Serial.print( F( " taking away  DPOT_RATIO chunks from dPotSettings[ lSBDPotOffsetThisLeg ] " ) );
                do //!!!!! THIS LOOP DOES NOT CHANGE THE REAL DPOT SETTING AT ALL.  IS IT EXPECTED TO? NO. GETS DONE A FEW LINES BELOW
                {
                    dPotSettings[ lSBDPotOffsetThisLeg ] = ( uint16_t )( dPotSettings[ lSBDPotOffsetThisLeg ] - DPOT_RATIO );
//                    *MSBpotValue++; //This is implicitely occurring in the while condition
                } while( ( ++totalValueCoarse < ( MAXPOTSETTG * mSBsGroupSize ) ) && dPotSettings[ lSBDPotOffsetThisLeg ] > DPOT_RATIO - 1 );
            }
//Now we've either taken dPotSettings[ lSBDPotOffsetThisLeg ] down to less than DPOT_RATIO or maxed out our carrying to MSB or both.  We'd better know which
//Possibilities:  There is only one DPot in the leg so return false if dPotSettings[ lSBDPotOffsetThisLeg ] >= MAXPOTSETTG:
            if( dPotsPerThisLeg == 1 )
            {
                if( dPotSettings[ lSBDPotOffsetThisLeg ] >= MAXPOTSETTG )
                {
                    dPotSettings[ lSBDPotOffsetThisLeg ] = MAXPOTSETTG; //this will make maxed at MAXPOTSETTG
                    return false;
                }
            }
            else 
            {
                if( totalValueCoarse >= ( MAXPOTSETTG * mSBsGroupSize ) )
                {
    //             or totalValueCoarse has reached its maximum and dPotSettings[ lSBDPotOffsetThisLeg ] >= MAXPOTSETTG so return false after setting MSBs using a for construct
                    if( dPotSettings[ lSBDPotOffsetThisLeg ] >= MAXPOTSETTG )
                    {
//                        for()
                        return false;
                    }
    //             or totalValueCoarse has reached its maximum and dPotSettings[ lSBDPotOffsetThisLeg ] < MAXPOTSETTG so just go on
                }
                else
                {
    //             or totalValueCoarse has not reached its maximum so dPotSettings[ lSBDPotOffsetThisLeg ] is now == DPOT_RATIO - 1 so it will produce one more carry and needs to end as zero: make it ( 0 - 1 ) now
                    if( dPotSettings[ lSBDPotOffsetThisLeg ] == DPOT_RATIO - 1 ) dPotSettings[ lSBDPotOffsetThisLeg ] = ( uint16_t )( 0 - 1 );  //Would be nice to be able to cast this by typeof rather than explicitely
    //             or totalValueCoarse has not reached its maximum so dPotSettings[ lSBDPotOffsetThisLeg ] is now < DPOT_RATIO - 1 so just go on
                }
            }
//
//            *MSBpotValue = ( totalValueCoarse > MAXPOTSETTG * mSBsGroupSize ?  totalValueCoarse - ( MAXPOTSETTG * mSBsGroupSize ) : 0 );
//#error No good.  The next line should not happen usually and sets to zero anyway WHAT WAS I THINKING?
//            offsetDPotOrMSBGroupValue( firstMSBInLeg, ( totalValueCoarse > ( MAXPOTSETTG * mSBsGroupSize ) ) ?  totalValueCoarse - ( MAXPOTSETTG * mSBsGroupSize ) : 0 );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
            Serial.print( F( " called setDPotOrMSBGroupValue on MID and MSB DPotSettings[" ) );
#endif

            if( dPotSettings[ lSBDPotOffsetThisLeg ] != MAXPOTSETTG )
            {
                dPotSettings[ lSBDPotOffsetThisLeg ] = min( MAXPOTSETTG, ++( dPotSettings[ lSBDPotOffsetThisLeg ] ) );
                setDPotOrMSBGroupValue( lSBDPotOffsetThisLeg, dPotSettings[ lSBDPotOffsetThisLeg ] );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
                Serial.print( F( " MSB group set to <" ) );
                Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
                Serial.print( F( ">, LSB set pos to" ) );
                Serial.print( dPotSettings[ lSBDPotOffsetThisLeg ] );
                Serial.print( F( ",." ) );
#endif
                return true;
            }
            return false;
        }
        Serial.print( F( " The voltsDown must be false " ) );
//Being told to increment so the voltage goes down
        if( totalValueCoarse == 0 && dPotSettings[ lSBDPotOffsetThisLeg ] == 0 ) return false; //no setting range left to decrease
        if( ( int16_t )dPotSettings[ lSBDPotOffsetThisLeg ] == 0 ) //This catches dPotSettings[ lSBDPotOffsetThisLeg ] having or about to have a value lower than 0.  So we cycle it up
        {
            dPotSettings[ lSBDPotOffsetThisLeg ] = DPOT_RATIO;
//            *MSBpotValue = ( --totalValueCoarse > MAXPOTSETTG * mSBsGroupSize ? totalValueCoarse - ( MAXPOTSETTG * mSBsGroupSize ) : 0 );
            setDPotOrMSBGroupValue( firstMSBInLeg, MSB_SETTINGS_TOTAL_THIS_LEG - 1 );
        }
        setDPotOrMSBGroupValue( lSBDPotOffsetThisLeg, --( dPotSettings[ lSBDPotOffsetThisLeg ] ) );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( " MSB group set to " ) );
        Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
        Serial.print( F( ", LSB set to" ) );
        Serial.print( dPotSettings[ lSBDPotOffsetThisLeg ] );
        Serial.print( F( ",." ) );
#endif
        return true;
    } //End of bool stepAdjustDPotsForThisLeg()

uint16_t bestOfFour( uint8_t );
bool adjustBridgeOutputPositive( uint8_t bridge )
{ //If all pots are maxed (positive leg to positive and negative leg to negative) return false
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  while( !Serial );
  Serial.print( F( " Entered adjustBridgeOutputPositive " ) );
  Serial.print( F( " EABOP " ) );
  Serial.print( F( "with bridge=" ) );
  Serial.print( bridge );
  Serial.print( F( ",." ) );
#endif
  /*
    lower reference leg voltage if it is higher than commonmode... level until it reaches commonmode...,
    then raise signal leg voltage until can't raise it any more,
    then resume to lower reference leg until can't lower it any more
  */
  //to read values from analog pins: use IndexInlinespaceParametersArray and add one (reference) or not (signal)
  // If all are maxed out positive, return false: reference leg negative, signal leg positive
  //TODO: reduce confusion by converting positive (now digipot settings) to positive voltage (will need to complement various things in code)
  if( true) //!stepAdjustDPotsForThisLeg( 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 2 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 2 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], false, true ) \
    //           && !stepAdjustDPotsForThisLeg( 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], true, true ) )
  {
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    while( !Serial );
    Serial.print( F( " Leaving adjustBridgeOutputPositive unable to change" ) );
    Serial.print( F( " LABOP " ) );
    Serial.print( F( "with bridge=" ) );
    Serial.print( bridge );
    Serial.print( F( ",." ) );
#endif
    return false;
  }
  /*
          if( ( dPotSettings[ 0 + bridge * DPOTS_PER_LM334_BRIDGE ]  + dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] + dPotSettings[ 2 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] >= ( 514 + MAXPOTSETTG ) ) && \
              ( dPotSettings[ 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] + dPotSettings[ 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] + dPotSettings[ 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] == 0 ) ) return false;
  */
  while( bestOfFour( 1 + ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
  {
    //            Serial.print( F( " raising the reference leg settings since that voltage is higher than optimal " ) );
    //            Serial.print( F( " rtrlsstvihto " ) );
    //            Serial.flush();
    //            if( !stepAdjustDPotsForThisLeg( 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], true ) )
    break;
#if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#endif
  }
  while( oneReadingFromThisOutboardADC( bridge ) < HEIGHT_OF_A_PLOT_LINESPACE / 2 )
  {
    //            Serial.print( F( " lowering the signal leg settings since the reference leg voltage is optimal " ) );
    //            Serial.print( F( " ltslsstrlvio " ) );
    //            Serial.flush();
    //            if( !stepAdjustDPotsForThisLeg( 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 2 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 2 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], false ) )
    break;
#if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#endif
  }
  while( oneReadingFromThisOutboardADC( bridge ) < HEIGHT_OF_A_PLOT_LINESPACE / 2 )
  {
    //            Serial.print( F( " raising the reference leg settings since the signal leg settings are maxed low " ) );
    //            Serial.print( F( " rtrlsstslsaml " ) );
    //            Serial.flush();
    if( true ) //!stepAdjustDPotsForThisLeg( 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], true ) )
    {
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      while( !Serial );
      Serial.print( F( " Leaving adjustBridgeOutputPositive maxed out" ) );
      Serial.print( F( " LABOP " ) );
      Serial.print( F( "with bridge=" ) );
      Serial.print( bridge );
      Serial.print( F( ",." ) );
#endif
      return false;
    }
#if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#endif
  }
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  while( !Serial );
  Serial.print( F( " Leaving adjustBridgeOutputPositive successful change" ) );
  Serial.print( F( " LABOP " ) );
  Serial.print( F( "with bridge=" ) );
  Serial.print( bridge );
  Serial.print( F( ",." ) );
#endif
}

bool adjustBridgeOutputNegative( uint8_t bridge )
{ //If all pots are maxed (positive leg to negative and negative leg to positive) return false
  configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  while( !Serial );
  Serial.print( F( " Entered adjustBridgeOutputNegative " ) );
  Serial.print( F( " EABON " ) );
  Serial.print( F( "with bridge=" ) );
  Serial.print( bridge );
  Serial.print( F( ",." ) );
#endif
  //        if( !stepAdjustDPotsForThisLeg( 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 2 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 2 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], true, true ) \
  //           && !stepAdjustDPotsForThisLeg( 3 + ( bridge *  ), &dPotSettings[ 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], false, true ) )
  {
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    while( !Serial );
    Serial.print( F( " Leaving adjustBridgeOutputNegative unable to change" ) );
    Serial.print( F( " LABON " ) );
    Serial.print( F( "with bridge=" ) );
    Serial.print( bridge );
    Serial.print( F( ",." ) );
#endif
    return false; //checks if reference leg is maxed to highest voltage already
  }

  while( bestOfFour( 1 + ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
  {
    //            Serial.print( F( " lowering the reference leg settings since that voltage is lower than optimal " ) );
    //            Serial.print( F( " ltrlssttvilto " ) );
    //            Serial.flush();
    //            if( !stepAdjustDPotsForThisLeg( 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], false ) )
    break;
#if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#endif
  }
  while( oneReadingFromThisOutboardADC( bridge ) > HEIGHT_OF_A_PLOT_LINESPACE / 2 )
  {
    //            Serial.print( F( " raising the signal leg settings since the reference leg voltage is optimal " ) );
    //            Serial.print( F( " rtslsstrlvio " ) );
    //            Serial.flush();
    //            if( !stepAdjustDPotsForThisLeg( 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 2 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 2 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], true ) )
    break;
#if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#endif
  }
  while( oneReadingFromThisOutboardADC( bridge ) > HEIGHT_OF_A_PLOT_LINESPACE / 2 )
  {
    //            Serial.print( F( " lowering the reference leg settings since the signal leg settings are maxed high " ) );
    //            Serial.print( F( " rtrlsstslsamh " ) );
    //            Serial.flush();
    if( true ) //!stepAdjustDPotsForThisLeg( 1+ ( bridge * DPOTS_PER_this_BRIDGE ), &dPotSettings[ 3 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 4 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ), &dPotSettings[ 5 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ], false ) )
    {
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      while( !Serial );
      Serial.print( F( " Leaving adjustBridgeOutputNegative maxed out" ) );
      Serial.print( F( " LABON " ) );
      Serial.print( F( "with bridge=" ) );
      Serial.print( bridge );
      Serial.print( F( ",." ) );
#endif
      return false;
    }
#if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#endif
  }
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  while( !Serial );
  Serial.print( F( " Leaving adjustBridgeOutputNegative successful change" ) );
  Serial.print( F( " LABON " ) );
  Serial.print( F( "with bridge=" ) );
  Serial.print( bridge );
  Serial.print( F( ",." ) );
#endif
}
#endif

void replotLastValuesForAllTraces( bool actuals = false )                  //If we don't execute the following construct, the signal traces will lag behind the graphLine
{ //1st pin bad coming in
#ifdef DEBUG
  while( !Serial ) ;
  Serial.println( F( "Entering replotLastValuesForAllTraces" ) );
#endif
  while( !Serial ) ;
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  Serial.print( F( " reprinting most recent plotline values: " ) );
#else
  Serial.print( F( " " ) );
#endif
  /*

    #if ( NUM_OF_INBOARDS_PLOTTED > 0 )
      linespace_bounds_magnify_trace_offsets_and_previous_readings linespaceParametersInboard[ NUM_OF_INBOARDS_PLOTTED ];
    #endif
    #if defined LM334_BRIDGES && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE )
      previous_readings_only DigipotLeg[ ( LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ) - NUM_OF_INBOARDS_PLOTTED ];
    #endif
    #if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
      linespace_bounds_magnify_trace_offsets_and_previous_readings linespaceParametersOutboard[ NUM_OF_OUTBOARDS_PLOTTED ];
    #endif

  */
  //#ifndef MAGNIFICATION_FACTOR
  //    for( ; IndexOflinespaceParameters < max( NUM_OF_INBOARDS_PLOTTED, ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * LEGS_PER_DPOT_STYLE_BRIDGE ) ) + NUM_OF_OUTBOARDS_PLOTTED; IndexOflinespaceParameters++ )
  for( uint8_t linespaceParametersIndex = 0; linespaceParametersIndex < NUMBER_OF_LINESPACES; linespaceParametersIndex++ )
  {
#ifdef DEBUG
    while( !Serial ) ;
    Serial.print( F( "linespaceParametersIndex = " ) );
    Serial.print( linespaceParametersIndex );
    Serial.print( F( ", LastSignalPinPlotPoint = " ) );
    Serial.print( linespaceParameters[ linespaceParametersIndex ].LastSignalPinPlotPoint );
    Serial.print( F( ", ZeroOfThisPlotLinespace = " ) );
    Serial.print( linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace );
    Serial.print( F( ", INDEX_OF_INBOARDS_NOT_SUPERIMPOSED = " ) );
    Serial.println( INDEX_OF_INBOARDS_NOT_SUPERIMPOSED );
#endif
    Serial.print( actuals ? linespaceParameters[ linespaceParametersIndex ].LastSignalPinPlotPoint + linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace : 0 ); //I think this looks better than the line above
    Serial.print( F( " " ) );
    // INDEX_OF_INBOARDS_NOT_SUPERIMPOSED actually equals the number of InboardSuperimposed that exist
    if( linespaceParametersIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) //The same as comparing masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED
    {
#if not defined PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
#ifdef DEBUG
      while( !Serial ) ;
      Serial.print( F( ", LastReferencePinPlotPointOrLastMagnifiedPlotPoint = " ) );
      Serial.println( linespaceParameters[ linespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
#endif
      Serial.print( actuals ? linespaceParameters[ linespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace : 0 ); //I think this looks better than the line above
      Serial.print( F( " " ) );
#endif
      continue;
    }
    else //skip the following if the above was true
    {
      ;
#ifdef MAGNIFICATION_FACTOR
      Serial.print( actuals ? linespaceParameters[ linespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace : 0 ); //I think this looks better than the line above
      Serial.print( F( " " ) );
#endif
    }
  }
  Serial.println();
#ifdef DEBUG
  while( !Serial ) ;
  Serial.println( F( "Leaving replotLastValuesForAllTraces" ) );
#endif
}
//

void plotTimingLineGoingUp( bool tracesAlreadyInitializedToValidReadings = true )
{ //doesn't work in loop() when there is more than one linespace: it runs one too many indices?
#ifdef DEBUG
  while( !Serial ) ;
  Serial.println( F( "Entering plotTimingLineGoingUp" ) );
#endif
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  for( uint8_t linespaceParametersIndex = NUMBER_OF_LINESPACES - 1; linespaceParametersIndex != 255; linespaceParametersIndex-- )
  {
    /*
            if( linespaceParametersIndex > 1 ) //plot only double instances until the last one
            {
                Serial.println(); //temporary for debugging
                Serial.print( linespaceParameters[ linespaceParametersIndex - 1 ].HighLimitOfThisPlotLinespace );
                Serial.print( F( " " ) );//?
                #ifdef DEBUG
                    while( !Serial ) ;
                    Serial.println();
                    Serial.println( F( "Line 815" ) );
                #endif
                if( tracesAlreadyInitializedToValidReadings )
                    replotLastValuesForAllTraces( tracesAlreadyInitializedToValidReadings );
                else
                    Serial.println();
                #ifdef DEBUG
                    while( !Serial ) ;
                    Serial.println();
                    Serial.println( F( "Line 820" ) );
                #endif
            }
    */
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " timing line zero of this linespace: " ) );
#else
    Serial.print( F( " " ) );
#endif
    Serial.print( linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace );
    replotLastValuesForAllTraces( true );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " timing line zero of this linespace: " ) );
#else
    Serial.print( F( " " ) );
#endif
    Serial.print( linespaceParameters[ linespaceParametersIndex ].HighLimitOfThisPlotLinespace );
    replotLastValuesForAllTraces( true );
    //        Serial.print( linespaceParameters[ linespaceParametersIndex - 1 ].HighLimitOfThisPlotLinespace );
    Serial.print( F( " " ) );//?
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println();
    Serial.print( F( "Line 826 linespaceParametersIndex - 1 =" ) );
    Serial.println( linespaceParametersIndex - 1 );
#endif
    //        if( tracesAlreadyInitializedToValidReadings ) replotLastValuesForAllTraces( tracesAlreadyInitializedToValidReadings );
    //        else Serial.println();
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println();
    Serial.print( F( "Line 832, linespaceParametersIndex - 1 =" ) );
    Serial.println( linespaceParametersIndex - 1 );
#endif
  }
#ifdef DEBUG
  while( !Serial ) ;
  Serial.println( F( "Leaving plotTimingLineGoingUp" ) );
#endif
}

uint16_t bestOfFour( uint8_t analogPinArrayIndex = 0 ) //returns an INBOARD Analog Input pin reading, analogPinArrayIndex is also equal to bridge leg
{ //remove from consideration the max and min, then return avg of remaining two  //Re-suse some variables not otherwise in use right now
  uint16_t value = analogRead( *( analogPinArray + analogPinArrayIndex ) );
  delay( 2 );
  uint16_t value1 = analogRead( *( analogPinArray + analogPinArrayIndex ) );
  delay( 2 );
  uint16_t value2 = analogRead( *( analogPinArray + analogPinArrayIndex ) );
  delay( 2 );
  uint16_t val4 = analogRead( *( analogPinArray + analogPinArrayIndex ) );
  return ( uint16_t )( ( ( long )( value + value1 + value2 + val4 ) ) - ( max( max( max( value, value1 ), value2 ), val4 ) + min( min( min( value, value1 ), value2 ), val4 ) ) ) / 2;
}

uint16_t bestGuessAnalogInputreading( uint8_t analogPinArrayIndex = 0, bool fineTune = false/*not in use yet*/, bool usingGlobalValueOfDPotLegForAnalogPinArrayIndex = true )
{ //returns an INBOARD Analog Input pin reading, same as leg reading
  analogPinArrayIndex = ( ( analogPinArrayIndex > 0 ) || ( !usingGlobalValueOfDPotLegForAnalogPinArrayIndex ) ) ? analogPinArrayIndex : dPotLeg;
  uint16_t value, value1;
  unsigned long runningTotal = 0;
  uint8_t times = 0;
  //    do
  //    {
  //        value = bestOfFour( analogPinArrayIndex + ( dPotLeg * LEGS_PER_DPOT_STYLE_BRIDGE ) ); //The value of 2 is the number of bridge legs per bridge
  //        value1 = bestOfFour( analogPinArrayIndex + ( dPotLeg * LEGS_PER_DPOT_STYLE_BRIDGE ) );
  value = bestOfFour( analogPinArrayIndex );
  //        value1 = bestOfFour( analogPinArrayIndex );
  for( ; times < 4; times++ )
  {
    runningTotal += value;
    //            runningTotal += value1;
  }
  //    }while( false );//value != value1 );
  //    if( !fineTune ) return value;
  return ( runningTotal / times );
  //The following wish isn't a good method
  //        return ( uint16_t )( runningTotal / ( unsigned long ) times );
}

#if defined LEGS_PER_DPOT_STYLE_BRIDGE //need to replace hard-coded MSBgroup/LSB offsets with preprocessor-defined ones
static uint8_t setDPotsStep = 0;

bool setDigipotsReferenceLegOld( uint8_t bridge = 0, bool thisIsReferenceLegOfBridge = true, bool justPerformOneStep = false, bool matchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG = false ) //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.
{
  static uint16_t targetLevel;
  static uint8_t stepSize;
  static uint16_t lastbestGuessAnalogInputreading;
  //    static int8_t lSBDPotOffsetInLeg;
  //    static int8_t  firstMSBInLeg;
  //    static int8_t mSBsGroupSize;
  //    static int8_t dPotLeg;
  while( !Serial && ( millis() - millisStart < 8000 ) );
  Serial.print( F( "Just entered setDigipotsReferenceLeg to set up DPots of " ) );
  if( !matchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
    Serial.print( F( "reference" ) );
  else
    Serial.print( F( "signal" ) );
  Serial.print( F( " leg of bridge<" ) );
  Serial.print( bridge ); //This is not accurate the first go around b/c configureForReferenceLegWithBridgeIndex() has not been run yet
  Serial.print( F( "> " ) );
#ifdef DEBUG
  while( !Serial && ( millis() - millisStart < 8000 ) );
  configureForReferenceLegWithBridgeIndex( bridge );
  Serial.print( F( "Setting up digipots: bridge leg 0 = " ) );
  Serial.print( analogRead( *( analogPinArray + 0 + dPotLeg ) ) );
  Serial.print( F( ", bridge leg 1 = " ) );
  Serial.print( analogRead( *( analogPinArray + 1 + dPotLeg ) ) );
  Serial.print( F( ", setDPotsStep = " ) );
  Serial.print( setDPotsStep );
  Serial.print( F( ", targetLevel = " ) );
  Serial.print( targetLevel );
  Serial.print( F( ", stepSize = " ) );
  Serial.println( stepSize );
#endif
  if( setDPotsStep != 0 )
  {
    if( setDPotsStep == 1 ) goto SetDPotsStep1;
    if( setDPotsStep == 2 ) goto SetDPotsStep2;
    if( setDPotsStep == 3 ) goto SetDPotsStep3;
    if( setDPotsStep == 4 ) goto SetDPotsStep4;
    if( setDPotsStep == 5 ) goto SetDPotsStep5;
    if( setDPotsStep == 6 ) goto SetDPotsStep6;
    if( setDPotsStep == 7 ) goto SetDPotsStep7;
    if( setDPotsStep == 8 ) goto SetDPotsStep8;
    if( setDPotsStep == 9 ) goto SetDPotsStep9;
    //    if( setDPotsStep == 10 ) goto setDPotsStep10;
  }
  configureForReferenceLegWithBridgeIndex( bridge );

  targetLevel = \
        ( thisIsReferenceLegOfBridge \
        ? \
        ( matchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG \
        ? ( bestGuessAnalogInputreading( dPotLeg - 1 ) - BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) \
        : COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) \
        : \
        ( ( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( bestGuessAnalogInputreading( dPotLeg + 1 ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) : ( 1 << ( ANALOG_INPUT_BITS_OF_BOARD - 1 ) ) ) );
/*
  if( !matchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) targetLevel = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG;
  else targetLevel = bestGuessAnalogInputreading( dPotLeg - 1 ) - BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0;
*/
  /*Next is where the Wheatstone bridge reference leg output (that connects to negative input of highest sensi ADC) is set to targetLevel voltage level*/
  stepSize = 10;
  static uint16_t startPoint1;
  static uint16_t startPoint2;
  //#error In process of changing the bridge/leg offsets within this function to accommodate the argument of bridge being sent in instead of leg
  //    dPotLeg = ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1; //1 is the offset for the reference leg within the bridge
  //    lSBDPotOffsetInLeg = lSBFirstDPotOrder ? ( ( dPotLeg >= LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? /*this leg is a bare bridged legs style so use DPOTS_PER_BRIDGED_BARE_LEG*/ \
  //                         DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_LM334_LEG ) : \
  //                         ( dPotLeg >= LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? ( DPOTS_PER_BRIDGED_BARE_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) - 1 : ( DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) - 1;
  //     firstMSBInLeg = !lSBFirstDPotOrder ? ( ( dPotLeg >= LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? /*this leg is a bare bridged legs style so use DPOTS_PER_BRIDGED_BARE_LEG*/ \
  //                         DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_LM334_LEG ) : \
  //                         ( dPotLeg >= LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? \
  //                         DPOTS_PER_BRIDGED_BARE_LEG + 1 : DPOTS_PER_LM334_LEG + 1;
  //    mSBsGroupSize = ( dPotLeg >= LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) ? DPOTS_PER_BRIDGED_BARE_LEG - 1: DPOTS_PER_LM334_LEG - 1;
  //Use dPotLegMSBUsedAndAvailables[ dPotLeg * TOTAL_OFFSET ] and dPotLegMSBUsedAndAvailables[ dPotLeg * AVAILABLE_OFFSET ]
  // lSBFirstDPotOrder will either be true or false
  //#error Test carefully while this function gets converted
  startPoint1 = MSB_SETTINGS_TOTAL_THIS_LEG;//msb
  while( ( bestGuessAnalogInputreading( dPotLeg ) < targetLevel ) && ( stepSize > 1 ) )
  { //while the voltage is too low and step size large
    while( bestGuessAnalogInputreading( dPotLeg ) < targetLevel )
    { //checked reference leg
      startPoint1 = MSB_SETTINGS_TOTAL_THIS_LEG;//msb
      //Decrease digipot settingValues as long as they respond right
      if( MSB_SETTINGS_TOTAL_THIS_LEG <= stepSize - 1 ) break;
      if( MSB_SETTINGS_TOTAL_THIS_LEG > stepSize - 1 )
      {
        Serial.print( F( "While loop A firstMSBInLeg=<" ) );
        Serial.print( firstMSBInLeg );
        Serial.print( F( "> " ) );
        offsetDPotOrMSBGroupValue( firstMSBInLeg, 0 - stepSize );
        if( justPerformOneStep )
        {
          setDPotsStep = 1;
          return false;
        }
SetDPotsStep1:;
SetDPotsStep2:;
        //#error Where we're at - remove extra lables, ensure correct MSB or LSB gets sent
      }
    }
    Serial.print( F( "While loop C " ) );
    setDPotOrMSBGroupValue( firstMSBInLeg, startPoint1 );
    stepSize >>= 1;
  }
  //if voltage not too low or step size = 1, gets here, but it should only be step size and voltage should still be low
  while( bestGuessAnalogInputreading( dPotLeg ) < targetLevel )
  {
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println( F( "Looping line 977" ) );
#endif
    Serial.print( F( "While loop N " ) );
    stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP );
    if( justPerformOneStep ) //lsb
    {
      setDPotsStep = 3;
      return false;
    }
SetDPotsStep3:;
  }
  //if voltage not too low
  stepSize = 10;

  while( ( bestGuessAnalogInputreading( dPotLeg ) > targetLevel ) && ( stepSize > 1 ) )
  { //FIXME this loop can never be false when the startPoints get restored?
    while( bestGuessAnalogInputreading( dPotLeg ) > targetLevel )
    {
      //#error FIX THE INDEXING FOR dPotSettings[].  Send a DPot index, either LSB or first MSB should both work.  but Change to offsetpotvalue()
      startPoint1 = MSB_SETTINGS_TOTAL_THIS_LEG;//msb group
      //Decrease digipot settingValues as long as they respond right
      if( MSB_SETTINGS_TOTAL_THIS_LEG <= stepSize - 1 ) break;
      if( MSB_SETTINGS_TOTAL_THIS_LEG > stepSize - 1 )
      {
        Serial.print( F( "While loop E firstMSBInLeg=<" ) );
        Serial.print( firstMSBInLeg );
        Serial.print( F( "> " ) );
        offsetDPotOrMSBGroupValue( firstMSBInLeg, stepSize ); //adds to settings of MSB group
        if( justPerformOneStep )
        {
          setDPotsStep = 4;
          return false;
        }
SetDPotsStep4:;
SetDPotsStep5:; //This bottoms out as far as setting digipots
#ifdef DEBUG
        while( !Serial );
        Serial.print( F( "Line 897, bestGuessAnalogInputreading( dPotLeg )= " ) );
        Serial.print( bestGuessAnalogInputreading( dPotLeg ) );
        Serial.print( F( ", dPotSettings[ 3 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ]= " ) );
        Serial.print( dPotSettings[ 3 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ] ); //These setting settingValues increase without end FIXME
        Serial.print( F( ", dPotSettings[ 4 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ] = " ) );
        Serial.print( dPotSettings[ 4 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ] );
        Serial.print( F( ", dPotSettings[ 5 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ] = " ) );
        Serial.print( dPotSettings[ 5 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ] );
        Serial.print( F( ", stepSize=" ) );
        Serial.println( stepSize );
#endif
      }
#ifdef DEBUG
      while( !Serial );
      Serial.print( F( "Line 903, stepSize=" ) );
      Serial.println( stepSize );
#endif
    }
    Serial.print( F( "While loop G " ) );
    setDPotOrMSBGroupValue( firstMSBInLeg, startPoint1 );
    stepSize >>= 1;
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "new stepSize = " ) );
    Serial.println( stepSize );
#endif
  }
  while( bestGuessAnalogInputreading( dPotLeg ) > targetLevel )
  {
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println( F( "Looping line 1049" ) );
#endif
    Serial.print( F( "While loop M " ) );
    stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN );
    if( justPerformOneStep ) //lsb
    {
      setDPotsStep = 6;
      return false;
    }
SetDPotsStep6:;
  }
  //Converge by two consecutive readings
  do
  { //This leg is the  reference, so we need to take a little extra time: avg out more samples
    if( bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG ) > targetLevel )
    {
#ifdef DEBUG
      while( !Serial ) ;
      Serial.println( F( "Looping line 1114" ) );
#endif
      //We must prevent endless looping when out of range: if digipot settings are maxed out in the direction we're wanting them to go, return with setDPotsStep = 0 and failure
      Serial.print( F( "While loop L " ) );
      if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN, true ) )
      { //lsb
        setDPotsStep = 0;
        return false;
      }
      Serial.print( F( "While loop K " ) );
      stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN, true );
    }
    else if( bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG ) /*read it again*/ < targetLevel )
    {
#ifdef DEBUG
      while( !Serial ) ;
      Serial.println( F( "Looping line 1128" ) );
#endif
      //We must prevent endless looping when out of range: if digipot settings are maxed out in the direction we're wanting them to go, return with setDPotsStep = 0 and failure
      Serial.print( F( "While loop J " ) );
      if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP, false ) )
      { //lsb
        setDPotsStep = 0;
        return false;
      }
      Serial.print( F( "While loop I " ) );
      stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP, false );
    }
    if( justPerformOneStep )
    {
      setDPotsStep = 7;
      return false;
    }
SetDPotsStep7:
#ifdef DEBUG
    while( !Serial ) ;
    Serial.print( F( "Looping line 1143, targetLevel=" ) );
    Serial.print( targetLevel );
    Serial.print( F( ", bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG )=" ) );
    Serial.println( bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG ) );
#endif
    if( bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG ) /*read it again*/ != targetLevel ) continue;
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println( F( "Looping line 1148" ) );
#endif
    if( justPerformOneStep )
    {
      setDPotsStep = 8;
      return false;
    }
SetDPotsStep8:;
  } while( bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG ) /*read it again*/ != targetLevel ); //This would create an endless loop if the level is out of range

  /* This notion is for if a single reference dPotLeg leg of the first digipot dPotLeg suffices for the reference legs of all ADDON digipot dPotLegs to minimize parts count of multiple digipot dPotLeg systems.  Is not being pursued at this time....
      static uint8_t channel;
      for( channel = 0; channel < NUM_OF_OUTBOARDS_PLOTTED; channel++ )
      {
          setSignalBridgeLegInput( channel );
          if( justPerformOneStep )
          {
              setDPotsStep = 10;
              return false;
          }
  */
SetDPotsStep9:;
  /*    }*/
  setDPotsStep = 0;
  return true;
}

bool setDPotLegMidPoint( uint8_t bridge = 0, bool thisIsReferenceLegOfBridge = ADDRESS_THE_REFERENCE_LEG, bool justPerformOneStep = !GO_IN_SMALL_STEPS, bool matchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG = false ) //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.
{
  static uint16_t targetLevel;
  static uint8_t stepSize;
  static uint16_t lastbestGuessAnalogInputreading;
  while( !Serial && ( millis() - millisStart < 8000 ) );
  Serial.print( F( "Just entered setDPotLegMidPoint to set up DPots of " ) );
    if( bridge < LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM )
    {
      if( thisIsReferenceLegOfBridge )
        Serial.print( F( "reference" ) );
      else
        Serial.print( F( "signal" ) );
      Serial.print( F( " leg of " ) );
      Serial.print( F( "bridge<" ) );
      Serial.print( bridge );
    }
    else
    {
      Serial.print( F( "BARE_DPOT_LEGS_UNBRIDGED<" ) );
      Serial.print( bridge - ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM ) );
    }
  Serial.print( F( "> " ) );
#ifdef DEBUG
  while( !Serial && ( millis() - millisStart < 8000 ) );
  if( thisIsReferenceLegOfBridge ) 
      configureForReferenceLegWithBridgeIndex( bridge );
  else
        configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
  Serial.print( F( "Setting up digipots: bridge leg 0 = " ) );
  Serial.print( analogRead( *( analogPinArray + 0 + dPotLeg ) ) );
  Serial.print( F( ", bridge leg 1 = " ) );
  Serial.print( analogRead( *( analogPinArray + 1 + dPotLeg ) ) );
  Serial.print( F( ", setDPotsStep = " ) );
  Serial.print( setDPotsStep );
  Serial.print( F( ", targetLevel = " ) );
  Serial.print( targetLevel );
  Serial.print( F( ", stepSize = " ) );
  Serial.println( stepSize );
#endif
  if( setDPotsStep != 0 )
  {
    if( setDPotsStep == 1 ) goto SetDPotsStep1;
    if( setDPotsStep == 2 ) goto SetDPotsStep2;
    if( setDPotsStep == 3 ) goto SetDPotsStep3;
    if( setDPotsStep == 4 ) goto SetDPotsStep4;
    if( setDPotsStep == 5 ) goto SetDPotsStep5;
    if( setDPotsStep == 6 ) goto SetDPotsStep6;
  }
  if( thisIsReferenceLegOfBridge ) 
      configureForReferenceLegWithBridgeIndex( bridge );
  else
        configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
  targetLevel = \
( thisIsReferenceLegOfBridge \
? \
( matchLevelToSignalLegInsteadOfToCOMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG \
? ( bestGuessAnalogInputreading( dPotLeg - 1 ) - BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) \
: COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) \
: \
( ( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( bestGuessAnalogInputreading( dPotLeg + 1 ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) : ( 1 << ( ANALOG_INPUT_BITS_OF_BOARD - 1 ) ) ) );

  /*Next is where the Wheatstone bridge reference leg output (that connects to negative input of highest sensi ADC) is set to targetLevel voltage level*/
  stepSize = 10;
  static uint16_t startPoint1;
  static uint16_t startPoint2;
  startPoint1 = MSB_SETTINGS_TOTAL_THIS_LEG;//msb
  while( ( bestGuessAnalogInputreading( dPotLeg ) < targetLevel ) && ( stepSize > 1 ) )
  { //while the voltage is too low and step size large
    while( bestGuessAnalogInputreading( dPotLeg ) < targetLevel )
    { //checked reference leg
      startPoint1 = MSB_SETTINGS_TOTAL_THIS_LEG;//msb
      //Decrease digipot settingValues as long as they respond right
      if( MSB_SETTINGS_TOTAL_THIS_LEG <= stepSize - 1 ) break;
      if( MSB_SETTINGS_TOTAL_THIS_LEG > stepSize - 1 )
      {
        Serial.print( F( "While loop A firstMSBInLeg=<" ) );
        Serial.print( firstMSBInLeg );
        Serial.print( F( "> " ) );
        offsetDPotOrMSBGroupValue( firstMSBInLeg, 0 - stepSize );
        if( justPerformOneStep )
        {
          setDPotsStep = 1;
          return false;
        }
SetDPotsStep1:;
      }
    }
    Serial.print( F( "While loop C " ) );
    setDPotOrMSBGroupValue( firstMSBInLeg, startPoint1 );
    stepSize >>= 1;
  }
  //if voltage not too low or step size = 1, gets here, but it should only be step size and voltage should still be low
  while( bestGuessAnalogInputreading( dPotLeg ) < targetLevel )
  {
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println( F( "Looping line 977" ) );
#endif
    Serial.print( F( "While loop N " ) );
    stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP );
    if( justPerformOneStep ) //lsb
    {
      setDPotsStep = 2;
      return false;
    }
SetDPotsStep2:;
  }
  //if voltage not too low
  stepSize = 10;

  while( ( bestGuessAnalogInputreading( dPotLeg ) > targetLevel ) && ( stepSize > 1 ) )
  { //FIXME this loop can never be false when the startPoints get restored?
    while( bestGuessAnalogInputreading( dPotLeg ) > targetLevel )
    {
      //#error FIX THE INDEXING FOR dPotSettings[].  Send a DPot index, either LSB or first MSB should both work.  but Change to offsetpotvalue()
      startPoint1 = MSB_SETTINGS_TOTAL_THIS_LEG;//msb group
      //Decrease digipot settingValues as long as they respond right
      if( MSB_SETTINGS_TOTAL_THIS_LEG <= stepSize - 1 ) break;
      if( MSB_SETTINGS_TOTAL_THIS_LEG > stepSize - 1 )
      {
        Serial.print( F( "While loop E firstMSBInLeg=<" ) );
        Serial.print( firstMSBInLeg );
        Serial.print( F( "> " ) );
        offsetDPotOrMSBGroupValue( firstMSBInLeg, stepSize ); //adds to settings of MSB group
        if( justPerformOneStep )
        {
          setDPotsStep = 3;
          return false;
        }
SetDPotsStep3:; //This bottoms out as far as setting digipots
#ifdef DEBUG
        while( !Serial );
        Serial.print( F( "Line 897, bestGuessAnalogInputreading( dPotLeg )= " ) );
        Serial.print( bestGuessAnalogInputreading( dPotLeg ) );
        Serial.print( F( ", dPotSettings[ 3 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ]= " ) );
        Serial.print( dPotSettings[ 3 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ] ); //These setting settingValues increase without end FIXME
        Serial.print( F( ", dPotSettings[ 4 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ] = " ) );
        Serial.print( dPotSettings[ 4 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ] );
        Serial.print( F( ", dPotSettings[ 5 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ] = " ) );
        Serial.print( dPotSettings[ 5 + ( dPotLeg * DPOTS_PER_LM334_BRIDGE ) ] );
        Serial.print( F( ", stepSize=" ) );
        Serial.println( stepSize );
#endif
      }
#ifdef DEBUG
      while( !Serial );
      Serial.print( F( "Line 903, stepSize=" ) );
      Serial.println( stepSize );
#endif
    }
    Serial.print( F( "While loop G " ) );
    setDPotOrMSBGroupValue( firstMSBInLeg, startPoint1 );
    stepSize >>= 1;
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( "new stepSize = " ) );
    Serial.println( stepSize );
#endif
  }
  while( bestGuessAnalogInputreading( dPotLeg ) > targetLevel )
  {
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println( F( "Looping line 1049" ) );
#endif
    Serial.print( F( "While loop M " ) );
    stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN );
    if( justPerformOneStep ) //lsb
    {
      setDPotsStep = 4;
      return false;
    }
SetDPotsStep4:;
  }
  //Converge by two consecutive readings
  do
  { //This leg is the  reference, so we need to take a little extra time: avg out more samples
    if( bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG ) > targetLevel )
    {
#ifdef DEBUG
      while( !Serial ) ;
      Serial.println( F( "Looping line 1114" ) );
#endif
      //We must prevent endless looping when out of range: if digipot settings are maxed out in the direction we're wanting them to go, return with setDPotsStep = 0 and failure
      Serial.print( F( "While loop L " ) );
      if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN, true ) )
      { //lsb
        setDPotsStep = 0;
        return false;
      }
      Serial.print( F( "While loop K " ) );
      stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN, true );
    }
    else if( bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG ) /*read it again*/ < targetLevel )
    {
#ifdef DEBUG
      while( !Serial ) ;
      Serial.println( F( "Looping line 1128" ) );
#endif
      //We must prevent endless looping when out of range: if digipot settings are maxed out in the direction we're wanting them to go, return with setDPotsStep = 0 and failure
      Serial.print( F( "While loop J " ) );
      if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP, false ) )
      { //lsb
        setDPotsStep = 0;
        return false;
      }
      Serial.print( F( "While loop I " ) );
      stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP, false );
    }
    if( justPerformOneStep )
    {
      setDPotsStep = 5;
      return false;
    }
SetDPotsStep5:
#ifdef DEBUG
    while( !Serial ) ;
    Serial.print( F( "Looping line 1143, targetLevel=" ) );
    Serial.print( targetLevel );
    Serial.print( F( ", bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG )=" ) );
    Serial.println( bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG ) );
#endif
    if( bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG ) /*read it again*/ != targetLevel ) continue;
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println( F( "Looping line 1148" ) );
#endif
    if( justPerformOneStep )
    {
      setDPotsStep = 6;
      return false;
    }
SetDPotsStep6:;
  } while( bestGuessAnalogInputreading( dPotLeg, MATCHING_TO_SIGNAL_LEG ) /*read it again*/ != targetLevel ); //This would create an endless loop if the level is out of range

  /* This notion is for if a single reference dPotLeg leg of the first digipot dPotLeg suffices for the reference legs of all ADDON digipot dPotLegs to minimize parts count of multiple digipot dPotLeg systems.  Is not being pursued at this time....
      static uint8_t channel;
      for( channel = 0; channel < NUM_OF_OUTBOARDS_PLOTTED; channel++ )
      {
          setSignalBridgeLegInput( channel );
          if( justPerformOneStep )
          {
              setDPotsStep = 10;
              return false;
          }
  */
  /*    }*/
  setDPotsStep = 0;
  return true;
}

void setSignalBridgeLegInput( uint8_t bridge )
{ //BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0
  uint16_t stepSize = 10;
  uint16_t startPoint1;
  uint16_t startPoint2;
  //ensure this does not corrupt nor get corrupted by the calling function:
  configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
  while( ( bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) && ( stepSize > 0 ) )
  {
    while( bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
    {
      startPoint1 = dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ];
      startPoint2 = dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ];
      //Decrease digipot settingValues as long as they respond right
      if( ( dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] <= stepSize - 1 ) && ( dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] <= stepSize - 1 ) ) break;
      if( dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] > stepSize - 1 ) setDPotOrMSBGroupValue( 0 + ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ), dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] - stepSize );
      if( dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] > stepSize - 1 ) setDPotOrMSBGroupValue( 1 + ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ), dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] - stepSize );
      bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE );
    }
    setDPotOrMSBGroupValue( 0 + ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ), startPoint1 );
    setDPotOrMSBGroupValue( 1 + ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ), startPoint2 );
    stepSize >>= 1;
  }
  //Converge on COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG in smaller steps
  while( bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
  {
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println( F( "Looping line 1275" ) );
#endif
    stepAdjustDPotsForThisLeg( false );
    //        Serial.print( PLOTTER_MAX_SCALE );
    //        Serial.print( F( " " ) );
    readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
    //        Serial.println();
  }
  stepSize = 10;
  while( ( bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) && ( stepSize > 0 ) )
  {
    while( bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
    {
      startPoint1 = dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ];
      startPoint2 = dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ];
      //Decrease digipot settingValues as long as they respond right
      if( ( dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] <= stepSize - 1 ) && ( dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] <= stepSize - 1 ) ) break;
      setDPotOrMSBGroupValue( 0 + ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ), dPotSettings[ 0 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] + stepSize );
      setDPotOrMSBGroupValue( 1 + ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ), dPotSettings[ 1 + ( bridge * DPOTS_PER_LM334_BRIDGE ) ] + stepSize );
      bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE );
    }
    setDPotOrMSBGroupValue( 0 + ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ), startPoint1 );
    setDPotOrMSBGroupValue( 1 + ( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ), startPoint2 );
    stepSize >>= 1;
  }

  //Converge on COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG in smaller steps
  while( bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
  {
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println( F( "Looping line 1302" ) );
#endif
    stepAdjustDPotsForThisLeg( true );
    //        Serial.print( PLOTTER_MAX_SCALE );
    //        Serial.print( F( " " ) );
    readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
    //        Serial.println();
  }
  //Converge by one or two consecutive readings
  do
  {
    if( bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
    {
#ifdef DEBUG
      while( !Serial ) ;
      Serial.println( F( "Looping line 1313" ) );
#endif
      stepAdjustDPotsForThisLeg( true );
      //            Serial.print( PLOTTER_MAX_SCALE );
      //            Serial.print( F( " " ) );
      readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
      //            Serial.println();
    }
    else if( bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) /*read it again*/ < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 )
    {
#ifdef DEBUG
      while( !Serial ) ;
      Serial.println( F( "Looping line 1321" ) );
#endif
      //bool stepAdjustDPotsForThisLeg( bool voltsDown = TAKE_LEG_VOLTAGE_DOWN, bool justQueryingWhetherSettingsAreMaxedOut = false, bool dPotNamesReversed = false ) //default direction will be positive
      stepAdjustDPotsForThisLeg( false );
      //            Serial.print( PLOTTER_MAX_SCALE );
      //            Serial.print( F( " " ) );
      readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
      //            Serial.println();
    }
    if( bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 ) continue;

  } while( bestGuessAnalogInputreading( bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) /*read it again*/ != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 );
}
#endif
/*
  global vars needed here b/c their value is shared so much between functions
*/
static uint32_t tracespaceToSkipWhenRepositioning, negativeTracespaceToSkipWhenRepositioning;
/*
  #if ( NUM_OF_INBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings linespaceParametersInboard[ NUM_OF_INBOARDS_PLOTTED ];
  #endif
  #if defined LM334_BRIDGES && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE )
    previous_readings_only DigipotLeg[ ( LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ) - NUM_OF_INBOARDS_PLOTTED ];
  #endif
  #if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings linespaceParametersOutboard[ NUM_OF_OUTBOARDS_PLOTTED ];
  #endif

  How are LastSignalPinPlotPoint and PreviousUnmagnifiedReading differently used?

  linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;

*/
void plotTheNormalAndMagnifiedSignals( uint8_t masterReadingsArrayIndex ) //linespaceParameters[] has Two indices/elements per every non-magnified trace ifdef MAGNIFICATION_FACTOR, otherwise one per
{
#ifdef DEBUG
  while( !Serial );
  Serial.print( F( "Line 1319 masterReadingsArrayIndex = " ) );
  Serial.println( masterReadingsArrayIndex );
#endif
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  Serial.print( F( " unmagnified value:" ) );
#endif
  Serial.print( F( " " ) );
  if( ( masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) && !( masterReadingsArrayIndex % 2 ) ) //This is the case for those ADCs that have just had their
    // current readings refreshed immediately prior to the
    // execution of this function, so use the stored readings.
    //Note also that the standard linespace is designed large
    // enough to always accommodate plotting the full unmagnified reading
  { //this case and the case of masterReadingsArrayIndex < INDEX_OF_OUTBOARDS but not including the case of masterReadingsArrayIndex < NUM_OF_INBOARDS_PLOTTED
    // needs to return some values
    linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one of pair
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " Unadjusted value=<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( ">, scaled to inboard analog input resolution:<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
    Serial.print( F( "> " ) );
#endif
#ifdef DEBUG
    Serial.println();
    Serial.println( F( "Line 1289 signal" ) );
#endif
#ifdef MAGNIFICATION_FACTOR
    goto AFTER_THE_MAGNIFIED_PLOTTED;
#endif
  }
  else if( masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) //This is still the case for those ADCs that have just had their current readings refreshed
    // immediately prior to the execution of this function, so use the stored readings.
    //Note also that the standard linespace is designed large enough to always accommodate plotting
    // the full unmagnified reading
  {
    linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
#if not defined PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color two of pair
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " Unadjusted value=<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( ">, scaled to analog input resolution:<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
    Serial.print( F( ">" ) );
#endif
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
      else if( masterReadingsArrayIndex < NUM_OF_INBOARDS_PLOTTED )
      {
          linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
          Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one
          #ifdef DEBUG
              Serial.println();
              Serial.println( F( "Line 1277 " ) );
          #endif
      }
  */
  else //non-superimposed inboards and all outboards
  {
    linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " Unadjusted value=<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( ">, scaled to inboard analog input resolution:<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
    Serial.print( F( ">" ) );
#endif
#ifdef DEBUG
    Serial.println();
    Serial.println( F( "Line 1285 " ) );
#endif
  }
#ifdef DEBUG
  Serial.print( F( "Line 1368 masterReadingsArrayIndex = " ) );
  Serial.print( masterReadingsArrayIndex );
  Serial.print( F( ", CurrentUnmagnifiedReading = " ) );
  Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
  Serial.print( F( ", IndexInlinespaceParametersArray = " ) );
  Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray );
  Serial.print( F( ", ZeroOfThisPlotLinespace = " ) );
  Serial.println( linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace );
#endif
  Serial.print( F( " " ) );
#ifdef MAGNIFICATION_FACTOR
  uint32_t thisPlotPoint;
  /*
    SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS will be one for every pair to superimpose on each other
    NUM_OF_INBOARDS_PLOTTED are paired times SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS, then singled
    NUM_OF_OUTBOARDS_PLOTTED is taken at face value
  */
#if defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
  if( masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) goto AFTER_THE_MAGNIFIED_PLOTTED; //if this is one of the two parallel traces, skip the magnified view
#endif

  //Next lines plot a magnified version.  First, MagnifyAdjustment is determined
  //Next we multiply the difference between PreviousUnmagnifiedReading and this one, and see if it would take the trace out of bounds
  //Derive the next plot point for the case of current CurrentUnmagnifiedReading being less than or equal to the last UnmagnifiedReading
  if( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading > masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading ) //new plot point is higher than previous
  {
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
    thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + ( ( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#else
    thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + ( ( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#endif
                    if( thisPlotPoint > HEIGHT_OF_A_PLOT_LINESPACE ) //new plot point is higher than upper limit
                    thisPlotPoint = tracespaceToSkipWhenRepositioning;
  }
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
                else if( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR ) > linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint )
#else
                else if( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * MAGNIFICATION_FACTOR > linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint )
#endif
                    thisPlotPoint = negativeTracespaceToSkipWhenRepositioning;
  else
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
    thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint  - ( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#else
    thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint - ( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#endif
                    linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = thisPlotPoint;
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
                    Serial.print( F( " magnified value: " ) );
#else
                    Serial.print( F( " " ) );
#endif
                    Serial.print( linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
                    Serial.print( F( " " ) );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
                    Serial.print( F( "Unadjusted value=<" ) );
                    Serial.print( linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
                    Serial.print( F( ">, scaled to inboard analog input resolution:<" ) );
                    Serial.print( linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
                    Serial.print( F( "> " ) );
#endif
#ifdef DEBUG
                    Serial.println();
                    Serial.println( F( "Line 1356 " ) );
                    Serial.println();
#endif
                    /* Previous algorithm that I think worked fine:

                        if( ThisReading > linespaceParameters[ channel ].PreviousUnmagnifiedReading ) //new reading is higher than previous
                        {
                      #ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
                            thisPlotPoint = LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] + ( ( ThisReading - linespaceParameters[ channel ].PreviousUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
                      #else
                            thisPlotPoint = LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] + ( ( ThisReading - linespaceParameters[ channel ].PreviousUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
                      #endif
                            if( thisPlotPoint > HEIGHT_OF_A_PLOT_LINESPACE ) //new plot point is higher than upper limit
                                thisPlotPoint = tracespaceToSkipWhenRepositioning;
                        }
                      #ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
                        else if( ( linespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR ) > LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] )
                      #else
                        else if( ( linespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * MAGNIFICATION_FACTOR > LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] )
                      #endif
                            thisPlotPoint = negativeTracespaceToSkipWhenRepositioning;
                        else
                      #ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
                            thisPlotPoint = LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] - ( ( linespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
                      #else
                            thisPlotPoint = LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] - ( ( linespaceParameters[ channel ].PreviousUnmagnifiedReading - ThisReading ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
                      #endif
                        Serial.print( linespaceParameters[ channel ].ZeroOfThisPlotLinespace + thisPlotPoint );
                        Serial.print( F( " " ) );
                        LastPlotPoints[ ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ] = thisPlotPoint;


                    */
                    AFTER_THE_MAGNIFIED_PLOTTED:
#endif
                    masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
#ifdef DEBUG
                    Serial.println();
#endif
#ifdef AUTO_BRIDGE_BALANCING
#ifdef MAGNIFICATION_FACTOR
                    if( masterReadingsArrayIndex < INDEX_OF_OUTBOARDS ) return bestGuessAnalogInputreading( 1 + ( ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 - bestGuessAnalogInputreading( ( ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE ) );
#else
                    if( masterReadingsArrayIndex >= NUM_OF_INBOARDS_PLOTTED ) return bestGuessAnalogInputreading( 1 + ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 - bestGuessAnalogInputreading( ( ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE );
#endif
                    //bestGuessAnalogInputreading index argument is a bridge...which doesn't exist except with the outboard ADCs
#endif
                    return;//only saving the reading, don't plot.  These are just LM334 non-plotted bridges
  }

#if defined ( POT_TEST_WOBBLE_SIGNAL_ON_SPECIFIED_OUTBOARD_ADC ) || defined ( POT_TEST_WOBBLE_REFERENCE_ON_SPECIFIED_OUTBOARD_ADC )
static bool potWobbleDirection = true;
static uint8_t wobbleLoops = 0;
#define WOBBLE_AMPLITUDE 1
void wobble( void )
{ //Adjust active code to amount of wobble you need at the moment
uint8_t* analogPinArrayTemp = analogPinArray;
analogPinArray = 0; //the setDPotOrMSBGroupValue functions check this for whether to consider their first argument as a real pin number or as an index to pin number within  analogPinArray[] for auto-carry/borrow (which we don't want right here until it gets perfected)
#ifdef POT_TEST_WOBBLE_SIGNAL_ON_SPECIFIED_OUTBOARD_ADC  //SINCE THIS HOLDS WHICH BRIDGE IS OF INTEREST, MULTIPLY IT BY # OF DPOTS PER BRIDGE BUT YOU'LL ALSO HAVE TO ADAPT THE PREPROCESSOR MACRO'D PIN NUMBERS BY HAND
    #ifdef NON_LSB_DPOT_1_B0SIG_PIN
    if( dPotSettings[ 0 ] < WOBBLE_AMPLITUDE ) //then we need to borrow one unit from msb group and add DPOT_RATIO to this
    {
        setDPotOrMSBGroupValue( NON_LSB_DPOT_1_B0SIG_PIN, dPotSettings[ 1 ] - 1 );
        setDPotOrMSBGroupValue( LSB_DPOT_B0SIG_PIN, dPotSettings[ 0 ] + DPOT_RATIO );
    }
    #endif
    setDPotOrMSBGroupValue( LSB_DPOT_B0SIG_PIN, dPotSettings[ 0 ] + ( potWobbleDirection ? WOBBLE_AMPLITUDE : ( 0 - WOBBLE_AMPLITUDE ) ) );
#endif //trap the above if setting tries to go below zero
#ifdef POT_TEST_WOBBLE_REFERENCE_ON_SPECIFIED_OUTBOARD_ADC
    #ifdef NON_LSB_DPOT_1_B0REF_PIN
    if( dPotSettings[ ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ] < WOBBLE_AMPLITUDE )
    {
        setDPotOrMSBGroupValue( NON_LSB_DPOT_1_B0REF_PIN, dPotSettings[ ( ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ) + 1 ] - 1 );
        setDPotOrMSBGroupValue( LSB_DPOT_B0REF_PIN, dPotSettings[ ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ] + DPOT_RATIO );
    }
    #endif 
    setDPotOrMSBGroupValue( LSB_DPOT_B0REF_PIN, dPotSettings[ ( NUM_OF_DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( NUM_OF_DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ] + ( !potWobbleDirection ? WOBBLE_AMPLITUDE : ( 0 - WOBBLE_AMPLITUDE ) ) );
#endif //trap the above if setting tries to go below zero
analogPinArray = analogPinArrayTemp; //restore proper value
  potWobbleDirection = !potWobbleDirection;
}
#endif

//#ifdef AUTO_BRIDGE_BALANCING
//    static uint16_t counterForTraceOutOfRangeTooLong[ NUM_OF_OUTBOARDS_PLOTTED ]; //This is to prevent infinite loop with AUTO_BRIDGE_BALANCING
//#endif

uint32_t oneReadingFromThisOutboardADC( uint8_t whichOutboardADCindex )
{
#if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 15 )
  thisReadingTemp = ads.readADC_SingleEnded( whichOutboardADCindex );
  while( thisReadingTemp > HEIGHT_OF_A_PLOT_LINESPACE ) thisReadingTemp = ads.readADC_SingleEnded( whichOutboardADCindex );
  return thisReadingTemp;
#else
#ifdef DIFFERENTIAL
#if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 )
  return CONVERT_TWOS_COMP_TO_SINGLE_ENDED( ( whichOutboardADCindex == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x8000*/ );
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 )
  //                                            hx711.power_up();
  return CONVERT_TWOS_COMP_TO_SINGLE_ENDED( hx711.read(), HEIGHT_OF_A_PLOT_LINESPACE - 1/*mask of significant bits 24 or 32, etc*/, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x800000 which bit is sign bit*/ );
  //                                            thisReadingTemp = 0xFFFFFF; //hx711.read_average( 9 );
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

void readAndPlotFromAllADCsInAndOutboard( uint32_t timingLineLevel, bool duringSetup = false )
{
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  Serial.print( F( " timing line value:" ) );
#endif
  Serial.print( F( " " ) );
  Serial.print( timingLineLevel );
  Serial.print( F( " " ) );
  for( uint8_t inboardPinIndex = 0; inboardPinIndex < INDEX_OF_OUTBOARDS; inboardPinIndex++ )
  {
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    //                    Serial.print( F( "analogPinArray = " ) );
    //                    Serial.println( (unsigned long)analogPinArray );
    Serial.print( F( "Reading pin " ) );
    Serial.print( *( analogPinArray + inboardPinIndex ) );
    Serial.print( F( ", level appearing as " ) );
    Serial.print( analogRead( *( analogPinArray + inboardPinIndex ) ) );
    if( inboardPinIndex == 0 )
    {
      Serial.print( F( ", SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE " ) );
      Serial.println( SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
    }
    else Serial.println();
#endif
    masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading = analogRead( *( analogPinArray + inboardPinIndex ) );
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Value was " ) );
    Serial.print( masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading );;
#endif

    for( uint8_t sampleTimes = 1; sampleTimes < SAMPLE_TIMES; sampleTimes++ )
    {
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
      delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
#endif
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
      delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
#endif
      masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading += analogRead( *( analogPinArray + inboardPinIndex ) );
    }
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( ".  Done reading pin " ) );
    Serial.print( *( analogPinArray + inboardPinIndex ) );
    Serial.print( F( ", " ) );
    Serial.print( SAMPLE_TIMES );
    Serial.print( F( " times, total CurrentUnmagnifiedReading now " ) );
    Serial.print( masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( " which should average to " ) );
    Serial.print( masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading / SAMPLE_TIMES );
    Serial.println( F( ", now plotting one inboard analog input with magnified version offset for proper positioning:" ) );
#endif
    masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading /= SAMPLE_TIMES;
    masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading <<= SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
  }

#if ( NUM_OF_INBOARDS_PLOTTED > 0 ) //plot the inboard analogs first and above from readings in masterReadingsArray
  for( uint8_t inboardPinIndex = 0; inboardPinIndex < NUM_OF_INBOARDS_PLOTTED; inboardPinIndex++ )
  { //PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
    plotTheNormalAndMagnifiedSignals( inboardPinIndex ); // What was I thinking comment: "not permissible to plot the paired/superimposed traces except with odd indices below INDEX_OF_INBOARDS_NOT_SUPERIMPOSED" ?
#ifdef DEBUG                                         // Maybe a single array element holds both reference and signal plots?
    Serial.println();
#endif
  }
#endif

#if ( NUM_OF_OUTBOARDS_PLOTTED > 0 )
  for( uint8_t whichOutboardADCindex = 0; whichOutboardADCindex < NUM_OF_OUTBOARDS_PLOTTED; whichOutboardADCindex++ )
  {
#if defined LEGS_PER_DPOT_STYLE_BRIDGE
Start_of_addon_ADC_acquisition:
    bool overscaleIsUnfixable = false;
    while( true ) //comes back to here if CurrentUnmagnifiedReading overscales
    {
#endif
#if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 15 )
      masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = ads.readADC_SingleEnded( whichOutboardADCindex );
      while( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ] > HEIGHT_OF_A_PLOT_LINESPACE ) //TODO: verify the need for this check
      {
        masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = ads.readADC_SingleEnded( whichOutboardADCindex );
      }
#else
#ifdef DIFFERENTIAL
#if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 )
      masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = CONVERT_TWOS_COMP_TO_SINGLE_ENDED( ( whichOutboardADCindex == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), ( uint32_t )(  - 1 ), HEIGHT_OF_A_PLOT_LINESPACE >> 1 );  // Convert to single-ended style
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 )
      //                                hx711.power_up();
      masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = CONVERT_TWOS_COMP_TO_SINGLE_ENDED( hx711.read(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x800000*/ );
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
#if defined LEGS_PER_DPOT_STYLE_BRIDGE
      break;
    }
#endif
#if ( defined SAMPLE_TIMES ) && ( SAMPLE_TIMES > 0 )
    for( uint8_t sampleTimes = 1; sampleTimes < SAMPLE_TIMES; sampleTimes++ )
    {
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
      delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
#endif
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
      delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
#endif
      masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading += oneReadingFromThisOutboardADC( whichOutboardADCindex );
    }
    masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading /= SAMPLE_TIMES;
#endif
    masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = ( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading < HEIGHT_OF_A_PLOT_LINESPACE ) ? masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading : HEIGHT_OF_A_PLOT_LINESPACE;
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Line 1687 INDEX_OF_OUTBOARDS = " ) );
    Serial.print( INDEX_OF_OUTBOARDS );
    Serial.print( F( ", whichOutboardADCindex = " ) );
    Serial.println( whichOutboardADCindex );
    Serial.print( F( ", INDEX_OF_OUTBOARDS + whichOutboardADCindex = " ) );
    Serial.println( INDEX_OF_OUTBOARDS + whichOutboardADCindex );
#endif
    plotTheNormalAndMagnifiedSignals( INDEX_OF_OUTBOARDS + whichOutboardADCindex );
  }
#endif
  Serial.println();
}

void setup()
{
  Serial.begin( BAUD_TO_SERIAL );//This speed is what works best with WeMos XI/TTGO XI board.
  while( !Serial ); //Leonardo needs this check
  millisStart = millis();
#ifdef __LGT8FX8E__
  //    analogReadResolution( 12 );  //I believe this is not necessary
  delay( SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING * 1000 );  // Needed by this board for serial to work
  Serial.println( F( "DEBUG is defined." ) );
#endif
  while( !Serial && ( millis() - millisStart < 8000 ) );
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
#if ( NUM_OF_DPOTS > 0 )
  SPI.begin();
  SPI.setBitOrder( MSBFIRST );
#endif
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
    digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A0_PIN, HIGH );
    digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A1_PIN, HIGH );
    digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A2_PIN, HIGH );
    digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A0_PIN, HIGH );
    digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A1_PIN, HIGH );
    digitalWrite( SECOND_STAGE_3_TO_8_DECODER_A2_PIN, HIGH );
    digitalWrite( BOTH_STAGES_3_TO_8_DECODER_ENABLE_PIN, HIGH );
#endif
#ifdef LM334_BRIDGES   //This is important to put this first so LM334 get some resistance, but not super important b/c they default to half-setting at power-up, so the only time they MIGHT need this is when the ckt was just merely reset after a previous session that left them setting at zero resistance, but hey...
#if ( LM334_BRIDGES == 1 )
  pinMode( SS, OUTPUT );
  digitalWrite( SS, HIGH ); //Not needed by slave devices but rather by this board to make it configure itself to be master
  for( uint8_t LM334Bridge = 0; LM334Bridge < LM334_BRIDGES; LM334Bridge++ )
  { //This is not scaleable beyond a single LM334_bridge of pots as far as pins, anyway, but at least it will initialize the LM334 digipot arrays to protect the LM334s.  To get valid settingValues beyond the first LM334_bridge, assign them non-looped below this loop for additional LM334_bridges
    dPotPins[ 0 + LM334Bridge ] = LSB_DPOT_B0SIG_PIN;
    dPotSettings[ 0 + LM334Bridge ] = LSB_DPOT_B0SIG_STARTVALUE;  // Storing a copy of the digi pot settingValues in sketch makes it possible to eliminate the MISO pin connection to the data out pins of all digi pots, besides the digi pots data out may not conform strictly to SPI since the MCP41X1 version has one bidirectional data pin
    Serial.print( F( " Index=<" ) );
    Serial.print( LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ 0 + LM334Bridge ] );
    Serial.print( F( "> " ) );
    pinMode( dPotPins[ 0 + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 0 + LM334Bridge ], HIGH );
    dPotPins[ DPOTS_PER_LM334_LEG + 0 + LM334Bridge ] = LSB_DPOT_B0REF_PIN;
    dPotSettings[ DPOTS_PER_LM334_LEG + 0 + LM334Bridge ] = LSB_DPOT_B0REF_STARTVALUE;
    Serial.print( F( " Index=<" ) );
    Serial.print( DPOTS_PER_LM334_LEG + 0 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ DPOTS_PER_LM334_LEG + 0 + LM334Bridge ] );
    Serial.print( F( "> " ) );
    pinMode( dPotPins[ 0 + DPOTS_PER_LM334_LEG + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 0 + DPOTS_PER_LM334_LEG + LM334Bridge ], HIGH );
#if ( DPOTS_PER_LM334_LEG > 1 )
    dPotPins[ 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0SIG_PIN;
    dPotSettings[ 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0SIG_STARTVALUE;
    Serial.print( F( " Index=<" ) );
    Serial.print( 1 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ 1 + LM334Bridge ] );
    Serial.print( F( "> " ) );
    pinMode( dPotPins[ 1 + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 1 + LM334Bridge ], HIGH );
    dPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0REF_PIN;
    dPotSettings[ DPOTS_PER_LM334_LEG + 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0REF_STARTVALUE;
    Serial.print( F( " Index=<" ) );
    Serial.print( DPOTS_PER_LM334_LEG + 1 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334Bridge ] );
    Serial.print( F( "> " ) );
    pinMode( dPotPins[ 1 + DPOTS_PER_LM334_LEG + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 1 + DPOTS_PER_LM334_LEG + LM334Bridge ], HIGH );
#if ( DPOTS_PER_LM334_LEG > 2 )
    dPotPins[ 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0SIG_PIN;
    dPotSettings[ 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0SIG_STARTVALUE;
    Serial.print( F( " Index=<" ) );
    Serial.print( 2 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ 2 + LM334Bridge ] );
    Serial.print( F( "> " ) );
    pinMode( dPotPins[ 2 + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 2 + LM334Bridge ], HIGH );
    dPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0REF_PIN;
    dPotSettings[ DPOTS_PER_LM334_LEG + 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0REF_STARTVALUE;
    Serial.print( F( " Index=<" ) );
    Serial.print( DPOTS_PER_LM334_LEG + 2 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334Bridge ] );
    Serial.print( F( "> " ) );
    pinMode( dPotPins[ 2 + DPOTS_PER_LM334_LEG + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 2 + DPOTS_PER_LM334_LEG + LM334Bridge ], HIGH );
    //  The way this is built makes the DPots get initialized in reverse order from intuitive
#ifndef LEAVE_POT_VALUES_ALONE_DURING_SETUP //This causes digipot stored settings not to match digipots, but at least they stay put to what they were last set to
    setDPotOrMSBGroupValue( dPotPins[ 2 + LM334Bridge ], dPotSettings[ 2 + LM334Bridge ] );
    setDPotOrMSBGroupValue( dPotPins[ 2 + DPOTS_PER_LM334_LEG + LM334Bridge ], dPotSettings[ 2 + DPOTS_PER_LM334_LEG + LM334Bridge ] );
#endif
#endif
#ifndef LEAVE_POT_VALUES_ALONE_DURING_SETUP //This causes digipot stored settings not to match digipots, but at least they stay put to what they were last set to
    setDPotOrMSBGroupValue( dPotPins[ 1 + LM334Bridge ], dPotSettings[ 1 + LM334Bridge ] );
    setDPotOrMSBGroupValue( dPotPins[ 1 + DPOTS_PER_LM334_LEG + LM334Bridge ], dPotSettings[ 1 + DPOTS_PER_LM334_LEG + LM334Bridge ] );
#endif
#endif
#ifndef LEAVE_POT_VALUES_ALONE_DURING_SETUP //This causes digipot stored settings not to match digipots, but at least they stay put to what they were last set to
    setDPotOrMSBGroupValue( dPotPins[ 0 + LM334Bridge ], dPotSettings[ 0 + LM334Bridge ] );
    setDPotOrMSBGroupValue( dPotPins[ 0 + DPOTS_PER_LM334_LEG + LM334Bridge ], dPotSettings[ 0 + DPOTS_PER_LM334_LEG + LM334Bridge ] );
#endif
  }
  //To increase capacity, follow the naming pattern above
  Serial.print( F( "DPot arrays filled " ) );

  Serial.print( F( "DPot pins set up " ) );
#else
#error This sketch is not entirely able to handle multiple digipot bridges at this revision level
#endif
#endif
  millisStart = millis();
#if defined LEGS_PER_DPOT_STYLE_BRIDGE
#ifdef DEBUG
  while( !Serial && ( millis() - millisStart < 8000 ) );
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
  while( !Serial && ( millis() - millisStart < 8000 ) );
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
    #if defined LEGS_PER_DPOT_STYLE_BRIDGE
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
  millisStart = millis();
  while( !Serial && ( millis() - millisStart < 8000 ) );
  //                    Serial.print( F( "MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT " ) );
  //                    Serial.println( MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT );
  //                    Serial.print( F( "RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT " ) );
  //                    Serial.println( RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT );
  Serial.print( F( "Initializing HX711..." ) );
#endif
  /*
     With the library being used, the .begin() method is not needed if the HX711 was declared earlier prior to setup().  The reason I'm doing it superfluously here is simply to suggest some measure of future consistency across all ADCs since other ADC libraries may not allow one or the other...
  */
  hx711.begin( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, HIGHEST_SENSI_PGA_GAIN_FACTOR );  // if the third parameter is ommited the default gain value 128 & channel A is used by the library
#ifdef DEBUG
  millisStart = millis();
  while( !Serial && ( millis() - millisStart < 8000 ) ); //We limit the time to wait for serial ready
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
  tracespaceToSkipWhenRepositioning = ( HEIGHT_OF_A_PLOT_LINESPACE * PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) / 100;
  negativeTracespaceToSkipWhenRepositioning = HEIGHT_OF_A_PLOT_LINESPACE - ( HEIGHT_OF_A_PLOT_LINESPACE * PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) / 100;
#endif
  //    if( NUM_OF_OUTBOARDS_PLOTTED + NUM_OF_INBOARDS_PLOTTED > 1 ) linespaceParameters[ 0 ].ZeroOfThisPlotLinespace = PLOTTER_MAX_SCALE - HEIGHT_OF_A_PLOT_LINESPACE;

#ifdef DEBUG
  while( !Serial );
  Serial.println( F( "The following numbers count up to the highest index of linespaces to be displayed:" ) );
#endif
  // INDEX_OF_INBOARDS_NOT_SUPERIMPOSED actually equals the number of InboardSuperimposed exist
  for( uint8_t linespacesIndex = 0; linespacesIndex < NUMBER_OF_LINESPACES; linespacesIndex++ )
  {
    uint8_t masterReadingsArrayIndex;
    if( linespacesIndex == 0 ) masterReadingsArrayIndex = 0;
    if( ( masterReadingsArrayIndex == INDEX_OF_INBOARDS_NOT_PLOTTED ) && ( masterReadingsArrayIndex < INDEX_OF_OUTBOARDS ) )
      //        {
      masterReadingsArrayIndex = INDEX_OF_OUTBOARDS; //whatever members are not plotted get skipped
    //            linespacesIndex--; //ensure this linepsace doesn't get skipped
    //            continue;
    //        }
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( ", Line 1852 linespacesIndex = " ) );
    Serial.print( linespacesIndex );
    Serial.print( F( ", Line 1854 masterReadingsArrayIndex = " ) );
    Serial.print( masterReadingsArrayIndex );
    Serial.print( F( " " ) );
#endif
#ifndef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
#define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG HALF_HEIGHT_OF_A_PLOT_LINESPACE
#endif
    linespaceParameters[ linespacesIndex ].HighLimitOfThisPlotLinespace = ( NUMBER_OF_LINESPACES - linespacesIndex ) * HEIGHT_OF_A_PLOT_LINESPACE;
    linespaceParameters[ linespacesIndex ].ZeroOfThisPlotLinespace = linespaceParameters[ linespacesIndex ].HighLimitOfThisPlotLinespace - HEIGHT_OF_A_PLOT_LINESPACE;
    linespaceParameters[ linespacesIndex ].LastSignalPinPlotPoint = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
    linespaceParameters[ linespacesIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
    masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading = masterReadingsArrayIndex < INDEX_OF_OUTBOARDS ? COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG : HALF_HEIGHT_OF_A_PLOT_LINESPACE;
    masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading = masterReadingsArrayIndex < INDEX_OF_OUTBOARDS ? COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG : HALF_HEIGHT_OF_A_PLOT_LINESPACE;
    masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray = linespacesIndex;
    //                  Note that INDEX_OF_INBOARDS_NOT_SUPERIMPOSED is an index for masterReadingsArray and actually is equal to the number of InboardSuperimposed that exist
    if( linespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) //The two arrays correlate 1:2 until INDEX_OF_INBOARDS_NOT_SUPERIMPOSED
    {
      masterReadingsArray[ masterReadingsArrayIndex + 1 ].PreviousUnmagnifiedReading = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG;
      masterReadingsArray[ masterReadingsArrayIndex + 1 ].CurrentUnmagnifiedReading = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG;
      masterReadingsArray[ masterReadingsArrayIndex + 1 ].IndexInlinespaceParametersArray = linespacesIndex;
    }
#ifdef MAGNIFICATION_FACTOR
    else
      linespaceParameters[ linespacesIndex ].MagnifyAdjustment = 0;
#endif
#ifdef DEBUG
    while( !Serial );
    //        Serial.println();
    Serial.print( F( "linespaceParameters[ " ) );
    Serial.print( linespacesIndex );
    Serial.print( F( " ].HighLimitOfThisPlotLinespace == " ) );
    Serial.print( linespaceParameters[ linespacesIndex ].HighLimitOfThisPlotLinespace );
    Serial.print( F( ", ZeroOfThisPlotLinespace == " ) );
    Serial.print( linespaceParameters[ linespacesIndex ].ZeroOfThisPlotLinespace );
    Serial.print( F( ", LastReferencePinPlotPointOrLastMagnifiedPlotPoint == " ) );
    Serial.print( linespaceParameters[ linespacesIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
    Serial.print( F( ", PreviousUnmagnifiedReading == " ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading );
    Serial.print( F( ", CurrentUnmagnifiedReading == " ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( ", IndexInlinespaceParametersArray == " ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray );
    if( linespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 )
    {
      Serial.print( F( ", + 1 PreviousUnmagnifiedReading == " ) );
      Serial.print( masterReadingsArray[ masterReadingsArrayIndex + 1 ].PreviousUnmagnifiedReading );
      Serial.print( F( ", + 1 CurrentUnmagnifiedReading == " ) );
      Serial.print( masterReadingsArray[ masterReadingsArrayIndex + 1 ].CurrentUnmagnifiedReading );
      Serial.print( F( ", + 1 IndexInlinespaceParametersArray == " ) );
      Serial.print( masterReadingsArray[ masterReadingsArrayIndex + 1 ].IndexInlinespaceParametersArray );
    }
    Serial.println();
#endif
    masterReadingsArrayIndex++;
    if( linespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) masterReadingsArrayIndex++; //skip the one we had to take care of in this linepsace iteration
  }
  Serial.print( F( "Plotting rising timing line: " ) );
  plotTimingLineGoingUp( false ); //The false makes all traces originate at global zero.  It seems to look better that way
  //no calls using analogPinArray can be made prior to now.
  //Next the pin translation table is allocated and filled the Analog Input pins needed
  Serial.print( F( "malloc'd [" ) );
#if ( LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_UNBRIDGED + NUM_OF_INBOARDS_PLOTTED > 0 )
  analogPinArray = ( uint8_t * )malloc( max( NUM_OF_INBOARDS_PLOTTED, LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_UNBRIDGED ) );
  Serial.print( max( NUM_OF_INBOARDS_PLOTTED, LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_UNBRIDGED ) );
#else
  Serial.print( 0 );
#endif
  Serial.println( F( "] bytes ram for the inboard Analog Input pins needed" ) );
#if ( NUM_OF_INBOARDS_PLOTTED > 0 ) || ( defined NUM_OF_DPOTS )
  //Hereafter is the pattern.  If you have more analog pins, add them according to the pattern.
#ifdef NUM_ANALOG_INPUTS
#ifdef PIN_A0
  for( uint8_t i = 0; i < max( NUM_OF_INBOARDS_PLOTTED, LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_UNBRIDGED ); i++ )
  {
    if( i == 0 )
      *( analogPinArray + i ) = PIN_A0;
#ifdef PIN_A1
    else if( i == 1 )
      *( analogPinArray + i ) = PIN_A1;
#ifdef PIN_A2
    else if( i == 2 )
      *( analogPinArray + i ) = PIN_A2;
#ifdef PIN_A3
    else if( i == 3 )
      *( analogPinArray + i ) = PIN_A3;
#ifdef PIN_A4
    else if( i == 4 )
      *( analogPinArray + i ) = PIN_A4;
#ifdef PIN_A5
    else if( i == 5 )
      *( analogPinArray + i ) = PIN_A5;
#ifdef PIN_A6
    else if( i == 6 )
      *( analogPinArray + i ) = PIN_A6;
#ifdef PIN_A7
    else if( i == 7 )
      *( analogPinArray + i ) = PIN_A7;
#ifdef PIN_A8
    else if( i == 8 )
      *( analogPinArray + i ) = PIN_A8;
#ifdef PIN_A9
    else if( i == 9 )
      *( analogPinArray + i ) = PIN_A9;
#ifdef PIN_A10
    else if( i == 10 )
      *( analogPinArray + i ) = PIN_A10;
#ifdef PIN_A11
    else if( i == 11 )
      *( analogPinArray + i ) = PIN_A11;
#ifdef PIN_A12
    else if( i == 12 )
      *( analogPinArray + i ) = PIN_A12;
#ifdef PIN_A13
    else if( i == 13 )
      *( analogPinArray + i ) = PIN_A13;
#ifdef PIN_A14
    else if( i == 14 )
      *( analogPinArray + i ) = PIN_A14;
#ifdef PIN_A15
    else if( i == 15 )
      *( analogPinArray + i ) = PIN_A15;
#ifdef PIN_A16
    else if( i == 16 )
      *( analogPinArray + i ) = PIN_A16;
#ifdef PIN_A17
    else if( i == 17 )
      *( analogPinArray + i ) = PIN_A17;
#ifdef PIN_A18
    else if( i == 18 )
      *( analogPinArray + i ) = PIN_A18;
#ifdef PIN_A19
    else if( i == 19 )
      *( analogPinArray + i ) = PIN_A19;
#ifdef PIN_A20
    else if( i == 20 )
      *( analogPinArray + i ) = PIN_A20;
#ifdef PIN_A21
    else if( i == 21 )
      *( analogPinArray + i ) = PIN_A21;
#ifdef PIN_A22
    else if( i == 22 )
      *( analogPinArray + i ) = PIN_A22;
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
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  Serial.println( F( "Creating analog pin definitions" ) );
#endif
  for( uint8_t i = 0; i < max( NUM_OF_INBOARDS_PLOTTED, LM334_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_BRIDGE_LEGS_PER_ENTIRE_SYSTEM + BARE_DPOT_LEGS_UNBRIDGED ); i++ )
    *( analogPinArray + i ) = i + FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES;
#endif //end of PIN_A0 check
#endif
#endif
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
#ifdef DEBUG
  Serial.println( F( "DEBUG is defined." ) );
#endif
#if ( not defined __LGT8FX8E__ ) && ( defined DEBUG )
  Serial.print( F( "   Operator convenience delay so operator can prepare as needed..." ) );
  delay( 5000 );
#endif
#ifdef DEBUG
  Serial.println();
  Serial.println( F( "Done delaying for operator convenience or hardware init " ) );
  Serial.println( F( "Some running parameters:" ) );
  Serial.print( F( "analogPinArray = " ) );
  Serial.println( (unsigned long)analogPinArray );
#if defined LEGS_PER_DPOT_STYLE_BRIDGE && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( NUM_OF_INBOARDS_PLOTTED < DPOT_LEGS_PER_ENTIRE_SYSTEM )
  for( uint8_t i = 0; i < DPOT_LEGS_PER_ENTIRE_SYSTEM; i++ ) //Mixing preprocessor macros means we can't use the terciary function
#else
  for( uint8_t i = 0; i < NUM_OF_INBOARDS_PLOTTED; i++ )
#endif
    Serial.println( *( analogPinArray + i ) );
  Serial.print( F( "PLOTTER_MAX_SCALE = " ) );
  Serial.print( PLOTTER_MAX_SCALE );
  Serial.print( F( " and ( uint32_t )( NUM_OF_OUTBOARDS_PLOTTED + NUM_OF_INBOARDS_PLOTTED ) = " ) );
  Serial.println( ( uint32_t )( NUM_OF_OUTBOARDS_PLOTTED + NUM_OF_INBOARDS_PLOTTED ) );

  //add other prints here to your liking
  Serial.print( F( "End of " ) );
#endif //end of DEBUG
  //Start of DPot MSB group settings storing for each DPot leg

  Serial.print( F( "Entering prefill construct " ) );
  for( dPotLeg = 0; dPotLeg < DPOT_LEGS_PER_ENTIRE_SYSTEM; dPotLeg++ )
  {
    configureFromDPotLeg(); //Req'd before using MSB_SETTINGS_ macros if dPotLeg ever changes in this scope
    Serial.print( F( "Prefilling Used and Availables for leg<" ) );
    Serial.print( dPotLeg );
    Serial.print( F( "> " ) );
    MSB_SETTINGS_TOTAL_THIS_LEG = 0;
    MSB_SETTINGS_AVAILABLE_THIS_LEG = 0;
    //prefill MSB_SETTINGS_TOTAL_THIS_LEG and MSB_SETTINGS_AVAILABLE_THIS_LEG
    for( uint8_t mSBDPot = 0; mSBDPot < mSBsGroupSize; mSBDPot++ )
    { //This loop and its followup instruction merely conforms the afore-cleared two struct elements to reality
      MSB_SETTINGS_TOTAL_THIS_LEG += dPotSettings[ firstMSBInLeg + mSBDPot ];
      //            Serial.print( F( "total this MSB group=<" ) );
      //            Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
      //            Serial.print( F( "> " ) );
    }
    MSB_SETTINGS_AVAILABLE_THIS_LEG = ( mSBsGroupSize * MAXPOTSETTG ) - MSB_SETTINGS_TOTAL_THIS_LEG;
    //        Serial.print( F( "available this MSB group=<" ) );
    //        Serial.print( MSB_SETTINGS_AVAILABLE_THIS_LEG );
    //        Serial.print( F( "> " ) );
    //Next line distributes MSB DPot settings evenly amongst entire MSB group DPots, so should only be used once per leg and not on LSB DPots
    setDPotOrMSBGroupValue( firstMSBInLeg, MSB_SETTINGS_TOTAL_THIS_LEG );
    Serial.print( F( "finished setDPotOrMSBGroupValue DPOT_LEGS_PER_ENTIRE_SYSTEM=<" ) );
    Serial.print( DPOT_LEGS_PER_ENTIRE_SYSTEM );
    Serial.print( F( "> leg<" ) );
    Serial.print( dPotLeg );
    Serial.print( F( "> " ) );
  }
#ifdef AUTO_BRIDGE_BALANCING
  for( uint8_t bridgeIndex = 0; bridgeIndex < NUM_OF_OUTBOARDS_PLOTTED; bridgeIndex++ )
    counterForTraceOutOfRangeTooLong[ bridgeIndex ] = 0;
#endif
#if defined AUTO_BRIDGE_BALANCING && not defined LEAVE_POT_VALUES_ALONE_DURING_SETUP
#ifdef DEBUG
  Serial.println( F( "initial setup.  Entering calibration setup." ) );
#endif
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  printDPotSettings();
  Serial.println( F( " Setting up LM334 and bare digipot bridge legs after prefill. " ) );

  for( uint8_t bridge = 0; bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES; bridge++ )
  {
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Calling setDPotLegMidPoint() for bridge <" ) );
    Serial.print( bridge );
    Serial.print( F( "> " ) );
    configureForReferenceLegWithBridgeIndex( bridge );
/*
    while( setDPotLegMidPoint( bridge, ADDRESS_THE_REFERENCE_LEG, GO_IN_SMALL_STEPS ) == false ) //while false, the entire bridge is being zeroed into the desired balance
    {
#ifdef DEBUG
      Serial.println( F( "Line 2374" ) );
#endif
      delay( 2 ); // allow some settling time
      readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
#ifdef DIFFERENTIAL
      if( counterForTraceOutOfRangeTooLong[ bridge ]++ > 80 ) break; //Limited to prevent endless looping here
#endif
    }
#ifdef DIFFERENTIAL
    counterForTraceOutOfRangeTooLong[ bridge ] = 0;  //size of this array is NUM_OF_OUTBOARDS_PLOTTED, so there is one member per bridge but needs to be one per dpot bridge plus one per non-bridged dpot leg.  Assume both are the same for now
#endif
    while( setDPotLegMidPoint( bridge, !ADDRESS_THE_REFERENCE_LEG, GO_IN_SMALL_STEPS ) == false ) //while false, the entire bridge is being zeroed into the desired balance
    {
#ifdef DEBUG
      Serial.println( F( "Line 2374" ) );
#endif
      delay( 2 ); // allow some settling time
      readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
#ifdef DIFFERENTIAL
      if( counterForTraceOutOfRangeTooLong[ bridge ]++ > 80 ) break; //Limited to prevent endless looping here
#endif
    }
*/
  }
  for( uint8_t bareUnbridgedLeg = LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES; bareUnbridgedLeg < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES + BARE_DPOT_LEGS_UNBRIDGED; bareUnbridgedLeg++ )
  {
    configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bareUnbridgedLeg );
    setDPotLegMidPoint( bareUnbridgedLeg, !ADDRESS_THE_REFERENCE_LEG, !GO_IN_SMALL_STEPS ); 
  }

  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  Serial.println( F( " done setting up digipot bridge legs, now take very first readings since powering on: " ) );
  readAndPlotFromAllADCsInAndOutboard( 0, true ); //Fills the arrays with valid values

  //Now could turn on wobble and fine tune to find the common mode voltage to realize greatest gain of the outboard ADC BUT it's not that important!
  //    #else
  //        #ifdef DEBUG
  //            Serial.println( F( "setup." ) );
  //        #endif
#endif //End of auto-balancing aspect of setup()

  for( uint8_t csIndex = 0; csIndex < NUM_OF_DPOTS; csIndex++ )
  {
    Serial.print( F( "dPotSettings[" ) );
    Serial.print( dPotPins[ csIndex ] );
    Serial.print( F( "]=<" ) );
    Serial.print( dPotSettings[ csIndex ] );
    if( csIndex < NUM_OF_DPOTS - 1 )
      Serial.print( F( ">,. " ) );
    else
      Serial.print( F( ">,. " ) );
  }
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  Serial.print( F( " End of setup() " ) );
}

void loop()
{
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  for( uint8_t csIndex = 0; csIndex < NUM_OF_DPOTS; csIndex++ )
  {
    Serial.print( F( "dPotSettings[" ) );
    Serial.print( dPotPins[ csIndex ] );
    Serial.print( F( "]=" ) );
    Serial.print( dPotSettings[ csIndex ] );
    if( csIndex < NUM_OF_DPOTS - 1 )
      Serial.print( F( ",. " ) );
    else
      Serial.print( F( ",. " ) );
  }
#endif
  for( plotterLoops = 0; plotterLoops < 500 / 3; plotterLoops++ )
  {
    millisStart = millis();
    //        if( graphLine ) thisReadingTemp = 0;
    //        else thisReadingTemp = PLOTTER_MAX_SCALE;
    //        Serial.print( thisReadingTemp ); //This was originally last printed in the group.  It needs to be first instead so the line can be "notched" horizontally without needing to reprint all values.
    //        Serial.print( F( " " ) );
    //        readAndPlotFromAllADCsInAndOutboard( thisReadingTemp );
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
goto AutoAdjustNotWorkingYet;
#ifdef AUTO_BRIDGE_BALANCING //Unsure of how to relate this macro and macro DIFFERENTIAL
    for( uint8_t whichOutboardADCindex = 0; whichOutboardADCindex < NUM_OF_OUTBOARDS_PLOTTED; whichOutboardADCindex++ )
    {
      if( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading >= HEIGHT_OF_A_PLOT_LINESPACE - 1 ) //means signal leg is higher
      { ;
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( " reading maxed out " ) );
#endif
#ifdef DIFFERENTIAL
        if( --counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] < -LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
        {
          //Process: raise reference leg if it is lower than commonmode... level until it reaches commonmode..., then lower signal leg until can't lower it any more, then resume to raise reference leg until can't raise it any more
          //                setSignalBridgeLegInput( whichOutboardADCindex ); // Instead maybe use AdjustBridgeOutput ative( bridge );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
          Serial.print( F( "for longer than allowed " ) );
#endif
            configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( whichOutboardADCindex );
          adjustBridgeOutputNegative( whichOutboardADCindex );
          plotterLoops = 0;
        }
#endif
      }
      else if( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading == 0 ) //means reference leg is higher
      { ;
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( " reading zeroed out " ) );
#endif
#ifdef DIFFERENTIAL
        if( ++counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] > LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
        {
          //Process: lower reference leg if it is higher than commonmode... level until it reaches commonmode..., then raise signal leg until can't raise it any more, then resume to lower reference leg until can't lower it any more
          //                setSignalBridgeLegInput( whichOutboardADCindex ); // Instead maybe use AdjustBridgeOutput ative( bridge );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
          Serial.print( F( "for longer than allowed " ) );
#endif
            configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( whichOutboardADCindex );
          adjustBridgeOutputPositive( whichOutboardADCindex );
          plotterLoops = 0;
        }
#endif
AutoAdjustNotWorkingYet:;
      }
#ifdef DIFFERENTIAL
      else
      {
        counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] = 0;
      }
#endif
    }
#endif
    //        Serial.println();
    /*        old style partial of auto adjust case:
        if( masterReadingsArrayIndex < INDEX_OF_OUTBOARDS )
        {
            #if ( NUM_OF_OUTBOARDS_PLOTTED > 0 ) && defined AUTO_BRIDGE_BALANCING
                #ifdef MAGNIFICATION_FACTOR
                if( masterReadingsArrayIndex < INDEX_OF_OUTBOARDS )  bestGuessAnalogInputreading( 1 + ( channel * LEGS_PER_DPOT_STYLE_BRIDGE ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 - bestGuessAnalogInputreading( ( channel - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE ) );
                #else
                if( masterReadingsArrayIndex >= NUM_OF_INBOARDS_PLOTTED ) bestGuessAnalogInputreading( 1 + channel ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BANK0 - bestGuessAnalogInputreading( ( channel - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE );
                #endif
            //bestGuessAnalogInputreading index argument is a bridge...which doesn't exist except with the outboard ADCs
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
                    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
                    Serial.print( F( "Received " ) );
                    Serial.println( szFull );
                #endif
        #if defined LEGS_PER_DPOT_STYLE_BRIDGE
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
                if( szFull[ 0 ] == '1' ) DIGITAL_POT_ = dPotPins[ 0 ];
                else if( szFull[ 0 ] == '2' ) DIGITAL_POT_ = dPotPins[ 1 ];
                else if( szFull[ 0 ] == '3' ) DIGITAL_POT_ = dPotPins[ 2 ];
                else if( szFull[ 0 ] == '4' ) DIGITAL_POT_ = dPotPins[ 3 ];
                else if( szFull[ 0 ] == '5' ) DIGITAL_POT_ = dPotPins[ 4 ];
                else if( szFull[ 0 ] == '6' ) DIGITAL_POT_ = dPotPins[ 5 ];
                else goto NoPotChange;
                offsetDPotOrMSBGroupValue( DIGITAL_POT_, offset_integer );
      NoPotChange:
        #endif
                szFull[ 0 ] = 0;
                #ifdef DEBUG
                    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
                    Serial.println();
                #endif
            }
    */
#if defined ( POT_TEST_WOBBLE_SIGNAL_ON_SPECIFIED_OUTBOARD_ADC ) || defined ( POT_TEST_WOBBLE_REFERENCE_ON_SPECIFIED_OUTBOARD_ADC )
    wobbleLoops = ( wobbleLoops + 1 ) % WOBBLE_TIME_PERIOD;
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Line 1687, wobbleLoops = " ) );
    Serial.println( wobbleLoops );
#endif
    if( wobbleLoops == 0 )
    {
      wobble();
    }
#endif
#if defined ( TEST_STEP_UP_DOWN )
    for( uint8_t bridge = 0; bridge < LM334_BRIDGES; bridge++ )
    {
#if ( TEST_STEP_UP_DOWN == SINGLESIDE )
      if( potstepdirection )
      { //adjustBridgeOutputPositive until maxed
        if( !adjustBridgeOutputPositive( bridge ) )
        {
          potstepdirection = false;
          adjustBridgeOutputNegative( bridge );
        }
      }
      else
      {
        if( !adjustBridgeOutputNegative( bridge ) )
        {
          potstepdirection = true;
          adjustBridgeOutputPositive( bridge );
        }
      }
#elif ( TEST_STEP_UP_DOWN == COMMONMODE )
      AdjustWholeBridgeCommonmode( bridge );
#else
      ; //I had a reason for this to be here but I don't recall it while I'm adding this comment.  May be future location for some code or maybe it makes code less susceptible to development bugs for the time being?
#endif
    }
#endif
    while( millis() - millisStart < MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS )
    { //acquire and process not-plotted readings of inboard analog pins that get used for digipot auto-balancing FUTURE TODO
      ;//or just wait.
    }
  }
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  if( !graphLine )
  { //going down
    for( uint8_t linespaceParametersIndex = 0; linespaceParametersIndex < NUMBER_OF_LINESPACES; linespaceParametersIndex++ )
    {
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      Serial.print( F( " upper bounds of this linespace" ) );
#endif
      Serial.print( F( " " ) );
      Serial.print( linespaceParameters[ linespaceParametersIndex ].HighLimitOfThisPlotLinespace );
      replotLastValuesForAllTraces( true );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      Serial.print( F( " lower bounds of this linespace " ) );
#endif
      Serial.print( F( " " ) );
      Serial.print( linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace );
      replotLastValuesForAllTraces( true );
    }
  }
  else
    plotTimingLineGoingUp();

  graphLine = !graphLine; // graphLine started as false, so it becomes true here on the first complementing of it
}
