//        BEFORE COMPILING THIS SKETCH you must set or confirm the following preprocessor macros appropriately for your configuration and preferences !!!
#define LM334_BRIDGES 1                                        //Number of digipot Wheatstones you have topped with LM334s each leg, (schematically wired before bare DPot bridges) but this sketch revision level not tested beyond 1.  Remove if using Wheatstone bridge with only standard or DPot resistors.  make this the number of bridges with upper resistive elements being LM334s controllable with the MCP4162-104 pots
#define DPOTS_PER_LM334_LEG 2                                  //Not yet tested for any setting except 3, so verify it before trusting fully.  Due to their significant temperature coefficient, LM334s need to be used in pairs so their tempco offsets each other's; i.e., LM334 legs are invalid unless bridged with both legs topped by a LM334
#define INBOARDS_PLOTTED 2                              //The number of consecutive analog pins to plot, beginning with PIN_A0
//#define OUTBOARDS_PLOTTED 1                             //The number of consecutive "highest-sensitivity ADC" pins to plot, beginning with A0 and, if double-ended, A1.  OUTBOARD ADC ONLY - DOES _NOT_ INCLUDE INBOARD ANALOG INPUT PINS
//#define MAGNIFICATION_FACTOR 5                                 //Activates the plotting of magnified traces in all ADC linespaces; upper limit somewhere less than 4,294,967,295. Note: you can disable displaying magnified traces altogether by not defined this macro at all. Proper use of SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS will also disable magnified traces of the first two analog inputs
#define HIGHEST_SENSI_OUTBOARD_ADC_TYPE HX711                  //Proposing that "ADS1231" covers ADS1231; could make this "ADS1232" ( ADS1232), "ADS1242" ( ADS1242), "AD779x" ( AD779x), "AD7780" ( AD7780), "HX711" (HX711), "ADS1X15" ( ADS1015 or ADS1115), "MAX112x0" (MAX112X0...) or "LTC2400" (LTC2400) but code not included in v.FREE; ONLY ONE TYPE ALLOWED
#define HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC 24     //All ADC values will get scaled to the single-ended aspect of this,  15 is ADS1115 single-ended, 16 for double-ended when two LM334s are used.  change to 11 for ADS1015 single-ended or 12 with two LM334s, (future: change to 24 for HX711--NO b/c there is the ADS1231 at 24 bits)
#define SAMPLE_TIMES 2                                         //To better average out artifacts we over-sample and average.  This value can be tweaked by you to ensure neutralization of power line noise or harmonics of power supplies, etc.....
#define MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE false//Doesn't catch much - future plan is to have different levels including DEBUG in this
#define MOST_PROBLEMATIC_INTERFERENCE_FREQ 60                                                               //This is here just in case you think that you might have some interference on a known frequency.
#define DELAY_TIME_BETWEEN_SAMPLES_MS ( 1000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ / SAMPLE_TIMES )          //COARSE ADJUST
#define DELAY_TIME_BETWEEN_SAMPLES_US ( ( ( 1000000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ ) - ( DELAY_TIME_BETWEEN_SAMPLES_MS * SAMPLE_TIMES * 1000 ) ) / SAMPLE_TIMES ) //FINE ADJUST.  THIS GETS ADDED TO COARSE ADJUST, PRECISION = TRUNCATED PRAGMATICALLY TO uSec TO ACKNOWLEDGE SOME OVERHEAD FOR LOOPING SUPPORT CODE   // End of this part of code update
#define FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES 14 //Gets changed to 18 for Leonardo. Why this? Some boards don't have good definitions and constants for the analog pins :-(
#define PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED 85   //BETWEEN 0 AND 100 indicating how much of the display region in percent to skip when magnified view trace has to get repositioned because trace would be outside region bounds; NO BOUNDS CHECKING IS PROVIDED!!!
#define ANALOG_INPUT_BITS_OF_BOARD 10                                        //Most Arduino boards are 10-bit resolution, but some can be 12 bits.  For known 12 bit boards (SAM, SAMD and TTGO XI architectures), this gets re-defined below, so generally this can be left as 10 even for those boards
#define SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING 9   //8 works only usually
#define HIGHEST_SENSI_PGA_GAIN_FACTOR 128                                     //PGA=Programmable Gain Amplifier: many ADCs will correlate a gain of one with full-scale being rail-to-rail, while a gain of anything higher correlates to full-scale being in the mV range (most sensitive and most noise-susceptible).  Set of allowable values: 64 and 128 will cause INA+/- to be read.  32 will cause INB+/- to be read. Defining POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_PGA_GAIN_FACTOR will override this macro
#define MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS 1                               //Sets a maximum speed limit, but actual speed may be further limited by other factors
#define SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS 1                                //If defined allows the rail-to-rail inboard Analog Inputs to be used to adjust digipots, but mainly causes first inboard Analog Inputs to be paired (superimposed in pairs sharing plot-line spaces) so even manual pots can be adjusted easily.
//#define PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS  //By defining this macro comparison between signal and reference is no longer possible but it could be less confusing this way since user doesn't need to manually adjust anything with DPots and especially with AUTO_BRIDGE_BALANCING. ADVISE without AUTO_BRIDGE_BALANCING in effect, this macro probably should not be defined either. But regardless for greatest flexibility, that macro won't affect this.
#define AUTO_BRIDGE_BALANCING                                                //is not perfectly robust yet in extremes and circuit faults, but will allow starting at a balanced level //increases setup time and during which the plot timing line stays high, then spikes low and high to indicate balancing complete //Turns on auto-balancing in setup(), significant time elapse for this to complete!
#define CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE true                    //Without predictive balancing, this takes too much time if true
//#define DEBUG                                                              //Don't forget that DEBUG is not formatted for Serial plotter, but might work anyway if you'd never print numbers only any DEBUG print line
#define COMPILE_FOR_DIAGS_ONLY
//#define DIAGS_STEP1                                                          //Optionally define on very first run of diags.
//#define DIAGS_STEP2                                                          //Don't define on very first run of diags
//#define DIAGS_STEP3                                                          //Don't define on very first run of diags
#define DIAGS_STEP4                                                          //Don't define on very first run of diags
#define SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX 0                                    //Can be a single bridge index or the word "ALL"
#define INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC 0       //For testing - wobbles digipot settings on bridge index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the signal leg
#define INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC 0    //For testing - wobbles digipot settings on bridge index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the reference leg
#define DIAGNOSTIC_SQUARE_WAVE_TIME_PERIOD  10
//#define LEAVE_POT_VALUES_ALONE_DURING_SETUP                                         //First run should leave this undefined to load digi pots with some values
#define BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 0  //This offset will be applied to all signal lines of outboard ADCs, not just the first one, until further development.  Write some code yourself to expand.  Inboard Analog Inputs of 10 bits will make much change with little values, 12 bit inboard allows more flexibility here
#ifdef BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0
#define ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 2 //To maintain consistent effect with the above, associated macro, this gets applied inverted. This is in lieu of setting by reading the ADCs and zeroing them.
#endif
#ifdef __LGT8FX8E__
#define BAUD_TO_SERIAL 19200                                                          //This speed is what works best with WeMos XI/TTGO XI board.  Experiment as desired.
#else
#define BAUD_TO_SERIAL 115200                                                         //YOU MAY SET THIS TO THE MAXIMUM VALUE THAT YOUR CONFIGURATION WILL FUNCTION WITH (UNLESS YOU'RE USING THE WeMos XI/TTGO XI, OF COURSE)
#endif
#define DPOT_RATIO ( signed )248 /* DPOT_RATIO: System-wide MSB/LSB.  Ex.: If the LSB digipot is 200 ohms/step and the MSB digipot is 2000 ohms/step, this value will be 10. (2000/200)
                      It is only used relative to the LSB digipot, so there can only be that one digipot per leg allowed to have a smaller resistance
                      per step than other digipots on the leg. All bridge legs in the system must be built with the same ratio scheme, and must always include one and
                      only one LSB digipot, with all non-LSB digipots matching each others' resistance/step values.  This macro limits LSB settings adjustments
                      when another digipot in the leg is set to less than MAX_DPOT_SETTG, but not otherwise, allowing LSB to reach MAX_DPOT_SETTG when non-LSBs are all at MAX_DPOT_SETTG.
                      As far as MAX_DPOT_SETTG, all digipots in the system are bound by the same MAX_DPOT_SETTG value. */
#define MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL 9                                //Number 0 produces smallest sketch giving least data output functionality
#define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 2          //sets how soon run-time auto-balancing kicks in when trace goes off scale
//#define POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_PGA_GAIN_FACTOR 3     //Overrides HIGHEST_SENSI_PGA_GAIN_FACTOR. NOT the digital number for pins! Is more like the leg index //Can use a spare analog input for gain adjustment by connecting wiper of a pot (100K or greater, please) that voltage-divides 0-5 vdc.  //Arduino pin only unless a dedicated ADS1115 is used

//FUTURE
//FUTURE #define BARE_DPOT_LEG_BRIDGES                       //(after LM334 bridges in terms of pin number order) Subject to change NOT CODED FOR YET.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg increasing the likelihood 74LV138 decoding will be necessary.
//FUTURE #define BARE_DPOT_LEGS_UNBRIDGED                    //(after active bridges in terms of pin number order, passive bridges using manual pots might include these legs)Subject to change NOT CODED FOR YET.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define DPOTS_PER_BRIDGED_BARE_LEG 3                //Might work now but not yet tested for any setting, so verify it before trusting fully
//FUTURE #define DPOTS_PER_UNBRIDGED_BARE_LEG 3              //Might work now but not yet tested for any setting, so verify it before trusting fully
//FUTURE #define SD_CHIP_SELECT_PIN 4                    //The free version does not contain the code to utilize SD card storage.  SD card storage only available in the priced ($20) sketch version.
//FUTURE #define WIFI true                                   //The free version does not contain the code to utilize wifi.  Wifi only available in the priced ($20) sketch version.  Buy online at http://GWAAMC.com
//FUTURE #define POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR 4    //NOT the digital number for pins! Is more like the leg index //Can use a spare analog input as magnification attenuator by connecting wiper of a pot (100K or greater, please) that voltage-divides 0-5 vdc.  //Arduino pin only unless a dedicated ADS1115 is used
//FUTURE #define USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
//FUTURE #define TEST_STEP_UP_DOWN COMMONMODE                                // Available: SINGLESIDE COMMONMODE
//FUTURE #define BARE_DPOT_LEG_BRIDGES, BARE_DPOT_LEGS_UNBRIDGED             // Subject to change, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define BARE_DPOT_LEG_BRIDGES 1                                     // (after LM334 bridges in terms of pin number order) Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher settingValues of DPot leg resistances are expected to be required.  This could mean more DPots per leg increasing the likelihood 74LV138 decoding will be necessary.
//FUTURE #define BARE_DPOT_LEGS_UNBRIDGED 1                                  //(If inputting to outboard ADCs these would be after active bridges in terms of pin number order, passive bridges using manual pots might include these legs)Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher settingValues of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define VERBOSITY_LEVEL                                             //To be used instead of and combines DEBUG and MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES                         //Arduino pins can be better utilized with higher numbers of DPots by adding 74LV138s expand the number of DPot CS pins that can be driven with a given number of Arduino pins
//!!! NOTE !!! 531 lines below this are also macros entitled similar to [NON_]LSB_DPOT_BXSIG(or REF)_PIN.  Those macros must also be set to correspond to the pins driving the CS lines of digipots
    #warning These pin numbers get specified normally, but be sure you specify the _digital_pot_CS_pins_ with the MSB set to decode them; i.e., make those pin numbers>= 128, but not these
    #define FIRST_STAGE_3_TO_8_DECODER_A0_PIN1 9                             //
    #define FIRST_STAGE_3_TO_8_DECODER_A1_PIN2 10                             //Second address pin of first stage not necessary if total DPots in the systems <= 2
    #define FIRST_STAGE_3_TO_8_DECODER_A2_PIN3 11                             //Third address pin of first stage not necessary if total DPots in the system <= 4
    //#define FIRST_STAGE_3_TO_8_DECODER_A3_PIN4 12                           //Always the same as FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4 since both reference pin 4
    #ifndef FIRST_STAGE_3_TO_8_DECODER_A3_PIN4
        #define FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4 13                     //Pin 4 either paralleled with final stage's pin 4 (only for up to 8 DPots) or used as a virtual A3. Pin 5 always connects to pin 4 of final stage 74LV138.
    #endif
    //#define FINAL_STAGE_3_TO_8_DECODER_A0_PIN1 9                           //Second stage not necessary if total DPots in the system <= 8
    //#define FINAL_STAGE_3_TO_8_DECODER_A1_PIN2 10                           //Second address pin of second stage not necessary if total DPots in the systems <= 16
    //#define FINAL_STAGE_3_TO_8_DECODER_A2_PIN3 11                           //Third address pin of second stage not necessary if total DPots in the systems <= 32
    //#define FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4 12                       //This connects into both 74LV138 chips on their pins 4 with pins 6 held high. First stage gets its pin 5 signal from second stage pin 15 and second stage pin 5 gets held low. Maximum total DPots = 64
#endif                                                                       //There are two ways to use 74LV138s: if more than 16 DPots, then, in part, the final stage 74LV138 drives all previous stages 74LV138 with its output lines driving pin 4 of previous stages. Up to 16 DPots can be used by two 74LV138s in parallel with, in part, the first 74LV138's pin 4 acting as an A3 and its pin 5 connected to pin 4 of the final 74LV138

//No need to change macros below:
#define CONVERT_TWOS_COMP_TO_SINGLE_ENDED( value_read_from_the_differential_ADC, mask, xorvalue ) ((value_read_from_the_differential_ADC & mask)^xorvalue)
//A FEW OF THE OTHER MACROS (DEFINES OR RE-DEFINES) ELSEWHERE: VERSION, NON_LSB_DPOT_2_B0SIG_STARTVALUE - LSB_DPOT_B0REF_STARTVALUE, HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC, DIFFERENTIAL, PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, PLOTTER_MAX_SCALE, HUNDREDTHPLOTTER_MAX_SCALE, SAMPLE_TIMES, SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE, COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG, HEIGHT_OF_A_PLOT_LINESPACE
#define COPYRIGHT_YEAR "<2018>, <2019>"
/*******************(C) GNU General Public License COPYRIGHT 2019 KENNETH L ANDERSON *********************
       ARDUINO ELECTRICAL RESISTANCE/CONDUCTANCE MONITORING SKETCH
  File Name          : adc_for_plant_tissue.ino
  Author             : KENNETH L ANDERSON
  Version            : v.Free
  Date               : 07-OCT-2019
  Description        : To replicate Cleve Backster's findings that he attributed to a phenomenon he called "Primary Perception".  Basically, this sketch turns an Arduino MCU and optional ADS1115 or HX711 (recommended) into a nicely functional GSR (Galvanic Skin Response) device or poor man's polygraph) in order to learn/demonstrate telempathic gardening.
  Boards tested on   : Uno using ADS1115 (early version), HX711, and inboard analog inputs.
                     : TTGO XI using ADS1115 in an early version
                     : Many other configurations should work fine.
                     : The ATtiny x4, ATtiny x5, ATtiny x61, ATtiny x8  not suitable at all due to not having hardware serial
  Known limitations  : Free version does not use predictive auto bridge balance resulting in painfully slow auto balance when plant conductance goes out of range
                     : Free version does not utilize microcontroller interrupts, so has a lower speed limitation than the professional version
                     : No ability to accept user input from keyboard during run time due to Arduino plotter limitation
                     : Re-compile always needed to effect any changes to configuration
                     : Analog input pins being used are hard-coded to be used in pin number order and their purposes are hard-coded as well
                     : Only a single add-on ADS ADC device and only 1 or 2 differential channels on it is tested
                     : Conventional add-on high-sensitivity ADCs limit their useable common mode differential input range to merely a few millivolts with active or passive clamping
                     : Non-bridged DPot legs are only for outboard ADCs though presumeably single-ended, they are not accommodated for inboard Analog Inputs
                     : Some of these limitations will be addressed in future not-for-free professional versions
      Due to the many preprocessor condition checks throughout this sketch source, the IDE is unable to track bracketed constructs accurately in many places.  What does this
      mean?  If you are used to relying on the IDE's highlighting of a paired bracket to help you know a bracketed construct's boundaries, you'll have to give that convenience up in places in this sketch source code.
********************************************************************************
  THE PRESENT PRODUCT WHICH IS ONLY FOR USE BY SOFTWARE- AND HARDWARE-COMPETENT 
  USERS IS INTENDED TO OFFER VARIOUS CAPABILITIES.  Because absolutely no 
  consideration is expected in return, no contract binding on me, whether offering
  suitability, reliability, functionality, safety, or other, exists.  IF YOU 
  MODIFY THIS SKETCH, I VERY SIMPLY REQUIRE that you not remove, hide, nor 
  denigrate the comments nor data output that refers to Jesus or God or their 
  words in any way.  BY USING THIS PRODUCT YOU EXPRESSLY AND TOTALLY ACCEPT FULL
  LIABILITY for any direct, indirect or consequential damages with respect to any 
  claims arising from software and/or hardware derivations of product. I make 
  absolutely no claim of my own competence, licensure, certification, experience,
  or professional standing other than being an Electronics Technician by formal 
  degree and United States FCC Radiotelephone Operators license, and a software
  developer by limited practical experience, and being formally degreed with 
  Bachelor of General Studies majoring in General Sciences
********************************************************************************
   Changelog:  17 Aug   2019 :  Start adding diags for building the board
               17 Apr   2019 :  Further fixes to allow MCP42xx dual digi-pots - lines 1048 and 1050 pin check changed to 0x40 from 0x400
               15 Apr   2019 :  First use of MCP4262s (instead of MCP4162s) and electrode connect indicator LEDs
               30 Mar   2019 :  Further fixes to allow MCP42xx dual digi-pots
               15 Feb   2019 :  Incorporates run-time gain adjustment with potentiometer wiper connected to Analog Input pin POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_PGA_GAIN_FACTOR when HX711 is used.  ADC inputs channel A will need to be wired parallel with channel B inputs.  Manufacturer will use 3-position switch with two 470K resistors in series between Vcc and GND and the middle switch position connects to middle of the resistor network, other two switch positions connect to Vcc and GND.
               24 Jan   2019 :  In process of modifying linearity diags to accommodate far higher resistances than I originally expected.  Hopefully the circuit itself won't need any modifications.
               21 Jan   2019 :  Reversed the order of traces plotted so that the outboard ADC is in the top group.
               18 Jan   2019 :  Predictive auto-balance working great by adding a fudge factor rather than fixing the formula the rational way
               15 Jan   2019 :  Auto-adjust working pretty fair, but haven't done thorough testing
               14 Jan   2019 :  Auto-adjust working crudely
               14 Jan   2019 :  Fixed the bugs relative to operation other than auto-balancing (auto-adjust).  Auto-adjust still not working beyond setup(), but at least this reversion level sets the bridge balances by the end of setup() when AUTO_BRIDGE_BALANCING is defined
               06 Jan   2019 :  After extensive changes to make this sketch flexible enough to incorporate the enhancements I had in mind I finally got this working in large part
               12 Dec   2018 :  Working on Predictive DPot setting, sketch is published for the purpose of establishing code flow to best support project advancement. 
               28 Nov   2018 :  Begin development on SD card storage + wifi connectivity so training aid can be powered through the power connector and store the data onboard and transmit it online
               17 Nov   2018 :  Functionalities restored that were present before scalability rewrite.
               16 Nov   2018 :  Scalability rewrite.  DO NOT USE PREDATED VERSIONS TO ADVANCE DEVELOPMENT!!!!!!!  Many changes have been made as of this date to accommodate future scalability
               18 Oct   2018 :  Now allows dual digi pot devices: MCP42xxx by manipulating the DPotPin of the first DPot of pkg OR'ing it with 0x40 as the pin of the second DPot in the pkg
               20 Sep   2018 :  Alpha chars added into output for future expansion beyond Arduino
               20 Sep   2018 :  Auto adjust works, but only non-predictively so it is slow.  Added macro CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE thinking someone may not want display to pause during auto balance, but that is even painfully slower still.
               11 Sep   2018 :  Back with new style of arrays useage to make bug-free coding more possible.
               23 Aug   2018 :  Fixed magnified traces in all respects; added functionality to display digipot calibration effects during calibration in setup(); started adding code to handle multiple digipot stacks that utilize dual 74VHC138/74LV138s.  Still no AUTO_BRIDGE_BALANCING
               23 Aug   2018 :  added USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES with possibly enough code (just needs testing). Allowed for any ratio of LSB pot step to MSB step with DPOT_RATIO
               23 Aug   2018 :  Magnification factor adjustable downward via a potentiometer if defined POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR with the digital number of an inboard analog input pin.
               01 Aug   2018 :  Working on vertical positioning of the magnified traces
               31 July  2018 :  I've noticed one sketch bug in the printing of the magnified traces in that they don't stay within bounds any more. Older sketch versions never had that problem. I'm not sure where it began, but it seems to be a memory management problem from my inital troubleshooting rather than any type of algorithm weakness. I'll work on that when I'm able...
               30 July  2018 :  Now able continuously to run-time auto-balance at least with a single HX711 LATER REVISIONS BROKE AUTO_BRIDGE_BALANCING
               29 July  2018 :  With INBOARDINPARALLELWITHHIGHESTSENSI && AUTO_BRIDGE_BALANCING defined, plotspace now excludes the two inboard Analog Input traces, making maximum linespace available for the other more interesting traces
               28 July  2018 :  If using digipots with LM334s, sketch can now auto-balance during setup and target the most sensitive common-mode voltage of a selected outboard ADC...LATER REVISIONS BROKE AUTO_BRIDGE_BALANCING
               27 July  2018 :  Discovered HX711's common-mode level sweet spot for max sensitivity, made COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG with default of half-scale
               26 July  2018 :  Corrected conversion from twos complement differential readings to proper single ended plotting
               20 July  2018 :  Improved plotting with INBOARDINPARALLELWITHHIGHESTSENSI and improved 24-bit plot values
               16 July  2018 :  Removed disparaging comments toward TTGO XI/Wemo XI because we will make the plunge to employ the AD8244 buffer as standard, resulting in those boards being eligible as any other board
               15 July  2018 :  Allow unique digipot initializing settingValue for each pot.  Discovered HX711 input Z is way too low for use without buffers.  Regrouping....
               14 July  2018 :  Improved horizontal timing trace notching - made it shorter and consistent between levels
               13 July  2018 :  Modified plotter timing trace to notch horizontally at range min and max for signal traces when it crosses up and down.  Incorporated digi pot adjustings in debug mode. Enabled bypass of digi pot set in setup()
               18 June  2018 :  Bug fixes relative to displaying multiple traces while one or more are from inboard analog pins
               17 June  2018 :  Corrected pointer reinitialize of analogPinArray that disabled internal Analog Input pins.  Added "while( !Serial );" for Leonardo's native USB; starting to add framework for programmable potentiometers, changed defines to allow for a separate full-scale, lower res ADC and a high res ADC for normal viewing, etc,
               08 June  2018 :  Bugfix for inboard analog inputs above the first one - they didn't print before this fix
               05 June  2018 :  HX711 accommodated, you'll just have to balance the bridge manually
               32 May   2018 :  Added skeleton preprocessor defines for user to compatibly code their own support for a few 24-bit ADCs
               29 May   2018 :  Differential use of ADS1x15 to allow LM334 temperature comp to negative inputs so LM334 can be used on positive inputs
               18 May   2018 :  Anti-aliasing code
               04 May   2018 :  Some 12 bit tweaking so that TTGO/WeMos XI, SAM and SAMD architectures compile with inboard analog inputs to computed at 12 bit even though ANALOG_INPUT_BITS_OF_BOARD is set at default.
               30 April 2018 :  Final inboard 10 bit operation and ADS1X15 operation has been achieved.
               NEXT          :  Predictive DPot setting by tracking +/- Inboard and Outboard ADC bits per +LSB bit
               NEXT          :  Allow using dual digital potentiometers (MCP42XXX) for more lower parts count than when using single pot MCP41XXX
               NEXT          :  EEPROM storage of things like ADC sweet spot, initial digipot settings, etc.  Hardware configs like DPot types & ADC types & other upgradeable hardware version possiblities needs to be able to be set in the hat board rather than EEPROM
               NEXT          :  Accommodate ADS1232 &/or ADS1231
               NEXT          :  Detect hat config and version with 256 versions detection and warning to acquire more recent sketch version when versions > known are found
  TODO:  Arrange for run-time keyboard input to eliminate need to re-compile when changes are made or plotting adjustments are desired.  Will require non-Arduino IDE plotter
         Accommodate more 24-bit adcs like ADS1231
         Accommodate plant growth rate data somehow...visual/optical/height?
         Use interrupts to acquire in the background from ADCs so their always current readings will need no delay to read them as is the case when on demand direct from the device
   These planned enhancements will be reserved for NOT-FOR-FREE sketch versions in the future
  Planned longer-term upgrades are as follows:
  - Am currently coding for diagnostics useful when building the board.
  - Am currently coding for use of less than 3 and more than 3 DPots/leg
  - Am currently coding for using DPots alone, without LM334, in the bridges
  - Am currently coding for using unbridged DPots, single leg only
  - Am currently coding for faster conductance range changes when DUT conductance goes out of range
  - Not coding for other ADC types yet, but will eventually first code for multiple HX711

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
Leonardo note:
"The Leonardo has 12 analog inputs, labeled A0 through A11, all of which can also be used as digital i/o. Pins A0-A5 appear in the same locations as on the Uno; inputs A6-A11 are on digital i/o pins 4, 6, 8, 9, 10, and 12 respectively. "
    - taken from https://www.arduino.cc/en/Main/Arduino_BoardLeonardo
Elsewhere 
*********************************************************************************************************************/
#if ( defined ARDUINO_attiny )
    #error The board you are compiling for does not have the serial in its hardware that this sketch as written is dependent on.  Sorry...
#elif ( defined ARDUINO_ARCH_STM32F4 )
    #error The board you are compiling for has not been accommodated with this sketch as written is dependent on.  Sorry...
#endif
#define VERSION "v.Free"
#include <math.h>
#include <EEPROM.h> // Any board that errors compiling this line is unsuitable to be used for this purpose because it cannot store settings persistently
#ifdef WIFI  //The free version does not contain the code to utilize wifi.  Wifi only available in the priced ($20) sketch version.  
    #error The free version does not contain the code to utilize wifi.  Wifi only available in the priced ($20) sketch version.  Thank you for your understanding
    #include <Ethernet.h>
    #include <Phpoc.h> //This would necessitate a pricey shield
    #include <PhpocExpansion.h>
//Object gets instantiated during setup() for greatest flexibility
#endif
#ifdef SD_CHIP_SELECT_PIN  //The free version does not contain the code to utilize SD card storage.  SD card storage only available in the priced ($20) sketch version.
    #error  The free version does not contain the code to utilize SD card storage.  SD card storage only available in the priced ($20) sketch version.
    #ifndef SPIINCLUDED
        #include "SPI.h" //This is the hardware implementation of SPI with CS pin addressable devices (instead of devices with unidirectional data in and data out pins needing addressed via data).  The software implementation uses shiftIn() instead and is slower but frees up otherwise-CS pins and can be used adjunctive for cases where a chip has no CS pin.  Adafruit_ADS1015 uses the shiftIn() method, so those pins are user's choice.  Not data addressable as would be in I2C
        #define SPIINCLUDED
    #endif
    #include <SD.h>
    boolean bLogging;
    unsigned int logging_address = EEPROMlength - sizeof( boolean );
//Object gets instantiated during setup() for greatest flexibility
#endif

#undef BAUD_RATE
#define BAUD_RATE 57600 //Very much dependent upon the capability of the host computer to process talkback data, not just baud rate of its interface
#if not defined ( __LGT8FX8E__ ) && not defined ( ARDUINO_AVR_YUN ) && not defined ( ARDUINO_AVR_LEONARDO ) && not defined ( ARDUINO_AVR_LEONARDO_ETH ) && not defined ( ARDUINO_AVR_MICRO ) && not defined ( ARDUINO_AVR_ESPLORA ) && not defined ( ARDUINO_AVR_LILYPAD_USB ) && not defined ( ARDUINO_AVR_YUNMINI ) && not defined ( ARDUINO_AVR_INDUSTRIAL101 ) && not defined ( ARDUINO_AVR_LININO_ONE )
    #ifndef RESTORE_FACTORY_DEFAULTS
        #define RESTORE_FACTORY_DEFAULTS
    #endif
#else
    #if defined ( __LGT8FX8E__ )
        #define BAUD_RATE 19200 //During sketch development it was found that the XI tends to revert to baud 19200 after programming or need that rate prior to programming so we can't risk setting baud to anything but that until trusted in the future
        #define LED_BUILTIN 12
//Commonly available TTGO XI/WeMo XI EEPROM library has only .read() and .write() methods, no EEPROM.length().
        #define EEPROMlength 1024
        #define NUM_DIGITAL_PINS 14  //here if necessary or FYI.  TTGO XI has no D13 labeled but it's prob sck, https://www.avrfreaks.net/comment/2247501#comment-2247501 says why D14 and up don't work digital: "lgt8fx8x_init() disables digital with DIDR0 register.   Subsequent pinMode() should enable/disable digital as required.   i.e. needs a patch in wiring_digital.c"
    #endif
#endif
#ifndef EEPROMlength
    #define EEPROMlength EEPROM.length()
#endif


//global variables are declared static to prevent them from being seen by any later user-added compilation units that would try, presumeably inadvertently, through the use of the "extern" cast.  Feel free to change if not inadvertent access is helpful
//Next, force all macros to be coherent with each other
#ifndef OUTBOARDS_PLOTTED
    #define OUTBOARDS_PLOTTED 0
#elif ( 1 > OUTBOARDS_PLOTTED + 0 ) //Evaluates to 1>+0 if the macro was defined as a blank.  Only way I know of to check for blank macros when we need a number in them
    #undef OUTBOARDS_PLOTTED
    #define OUTBOARDS_PLOTTED 0
#endif
#if ( ( defined ARDUINO_ARCH_XI-ORIGINAL ) || ( defined ARDUINO_ARCH_XI ) || ( defined ARDUINO_ARCH_SAM ) || ( defined ARDUINO_ARCH_SAMD ) ) //These are the boards known to have 12 bit analog inputs
    #ifdef ANALOG_INPUT_BITS_OF_BOARD
        #undef ANALOG_INPUT_BITS_OF_BOARD
    #endif
    #define ANALOG_INPUT_BITS_OF_BOARD 12  //These boards have 12 bit
#endif

#define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ( 1 << ( ANALOG_INPUT_BITS_OF_BOARD - 1 ) ) // Needed if HIGHEST_SENSI_OUTBOARD_ADC_TYPE has a sweet spot of max sensitivity, unlike true op-amp.  (HX711 == 306; normal op-amp, which has none == Vcc/2 == 512)
#ifndef INBOARDS_PLOTTED
    #define INBOARDS_PLOTTED 0 //This is used for some lightly thought out formulas in any case, so it must be defined until formulas are re-written to handle null values, but that might not be desirable as it results in more confusing formulas
#elif ( 1 > INBOARDS_PLOTTED + 0 )
    #undef INBOARDS_PLOTTED
    #define INBOARDS_PLOTTED 0
#endif
#ifdef MAGNIFICATION_FACTOR
    #if ( MAGNIFICATION_FACTOR == 0 ) //This value not allowed, assume it to mean 1
        #undef MAGNIFICATION_FACTOR
        #define MAGNIFICATION_FACTOR 1
    #endif
#endif
#ifdef ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0
    #if ( ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 + 1 > 1 )
    #else
        #undef ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0
    #endif
#endif
#ifdef ARDUINO_AVR_LEONARDO
    #undef FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES
    #define FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES 18 //Just saying...  Since the Leonardo has the A0 etc. #defines this won't come into play, but is here for reminder how things are
#endif
#define COMMON_MODE_LEVEL_FOR_MAX_GAIN_OF_UNPLOTTED_ADC_AS_READ_RAW_BY_INBOARD_ANALOG ( signed )307 //We do this for an example how we can configure for setting to a level without actually compiling for any outboard ADCs
#if ( OUTBOARDS_PLOTTED > 0 ) //Since so many of the ADC libraries already use OO classes, we'll set that as a pattern - instantiate prior to executing any code
    #define BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION 6 //Used in predictive steping
    #define HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC / 2 )
    #if ( ( HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC * 2 ) == HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC )
        #define DIFFERENTIAL
    #else
        #ifdef DIFFERENTIAL
            #undef DIFFERENTIAL
        #endif
    #endif
/*  The foloowing section needs further thought if to be used
    #if not ( ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) ) && ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) ) )
        #ifdef MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE
            #undef MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE
        #endif
        #define MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE true
    #endif
*/
    #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1X15 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 ) && ( OUTBOARDS_PLOTTED > 0 )
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
                #error This add-on ADC resolution is not supported in this sketch version.
            #endif
        #endif
    #else
        #define PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC 2 //PROPRIETARY, NOT SPI Must always be dedicated in cases where it doesn't go hi-Z (as in HX711).  This won't work if an ADS1x15 or any other I2C device is also used on this pin
        #define PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC 3 //PROPRIETARY, NOT SPI Must always be dedicated in cases where it doesn't go hi-Z (as in HX711).  This won't work if an ADS1x15 or any other I2C device is also used on this pin
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
            HX711 hx711; // This library allows us to set the pins and gain here or later in a .begin().
            #undef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
            #define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG 307                // If HIGHEST_SENSI_OUTBOARD_ADC_TYPE has a sweet spot of max sensitivity, unlike true op-amp.  (HX711 == 307, ranging from 1.49 to 1.507 vdc depending which scale is used to read it).  This will also be discovered and stored in EEPROM in a future revision
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
    #define BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION 0
    #ifdef HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC
        #undef HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC
    #endif
    #define HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC ANALOG_INPUT_BITS_OF_BOARD
//    #ifdef HIGHEST_SENSI_OUTBOARD_ADC_TYPE
//        #undef HIGHEST_SENSI_OUTBOARD_ADC_TYPE //this would prevent setup from finding linearity unless outboard ADC was operating: undesireable limitation
//    #endif
    #ifdef HIGHEST_SENSI_PGA_GAIN_FACTOR
        #undef HIGHEST_SENSI_PGA_GAIN_FACTOR
    #endif
#endif
#define RED_LED_PIN 6 //ALL LED pins must be in a contiguous block that begins with both LED pins for ADC(0)
#define YELLOW_LED_PIN 5 //ALL LED pins must be in a contiguous block that begins with both LED pins for ADC(0)
#ifndef LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER
    #define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 65536 //really bad idea, will crash at some point
#endif
#ifndef BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0
    #define BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 0
#endif
#if ( INBOARDS_PLOTTED > 0 )
    #ifndef NUM_ANALOG_INPUTS
        #error You are compiling for a board that requires you to manually define the define variable NUM_ANALOG_INPUTS somewhere above this line and re-compile...
    #endif
#else
    #if ( OUTBOARDS_PLOTTED == 0 )
        #error You will need to manually define at least one of the variables INBOARDS_PLOTTED or OUTBOARDS_PLOTTED where they appear in the lines above and re-compile...
If you only have the Arduino without an ADS1X15, then define INBOARDS_PLOTTED.  Otherwise, define OUTBOARDS_PLOTTED and / or both of them.
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
#if ( ( ( INBOARDS_PLOTTED < 2 ) && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS ) || ( defined COMPILE_FOR_DIAGS_ONLY ) )
    #ifdef COMPILE_FOR_DIAGS_ONLY
        #warning You are specifying COMPILE_FOR_DIAGS_ONLY.  If that is not what you want, change that defined macro
        #ifdef LEAVE_POT_VALUES_ALONE_DURING_SETUP
            #undef LEAVE_POT_VALUES_ALONE_DURING_SETUP
        #endif
//        #define INBOARDS_PLOTTED ALL 
//        #define DPOT_LEGS MAX
    #endif
    #undef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
#elif !( defined COMPILE_FOR_DIAGS_ONLY )
    #warning You are not specifying COMPILE_FOR_DIAGS_ONLY.  If that is not what you want, change that defined macro
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
#define DPOT_LEGS ( 0 )
// always 0 so no macro needed: #define dPotLegMSBusedAndAvailablesIndexLM334_LEG ( 0 )
#define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG ( 0 )
#define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG ( 0 )

#if ( ( defined LM334_BRIDGES ) && ( defined DPOTS_PER_LM334_LEG ) && ( LM334_BRIDGES > 0 ) && ( DPOTS_PER_LM334_LEG > 0 ) )
// Limit checking here for number of DPots this sketch can work with.  Be your own developer and expand this capability to fit your needs
    #if ( ( LM334_BRIDGES > 1 ) || ( DPOTS_PER_LM334_LEG > 3 ) )
        #error To utilize that value for LM334_BRIDGES or DPOTS_PER_LM334_LEG, you will have to develop this sketch further yourself.
    #endif
    #define DPOTS_IN_ALL_LM334_BRIDGES ( LM334_BRIDGES * DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) //For LM334-tipped bridges //For LM334-tipped bridges
    #define DPOTS_PER_LM334_BRIDGE ( DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE )
    #undef LEGS_PER_DPOT_STYLE_BRIDGE
    #define LEGS_PER_DPOT_STYLE_BRIDGE ( 2 )
    #define LM334_BRIDGE_LEGS ( LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE )
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
    #define DPOTS_IN_ALL_LM334_BRIDGES ( 0 ) //For LM334-tipped bridges
    #define LM334_BRIDGE_LEGS ( 0 ) //For LM334-tipped bridges
#endif
#if ( ( defined BARE_DPOT_LEG_BRIDGES ) && ( defined DPOTS_PER_BRIDGED_BARE_LEG ) && ( BARE_DPOT_LEG_BRIDGES > 0 ) && ( DPOTS_PER_BRIDGED_BARE_LEG > 0 ) )
// Limit checking here for number of DPots this sketch can work with.  Be your own developer and expand this capability to fit your needs
    #if ( ( BARE_DPOT_LEG_BRIDGES > 0 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 0 ) )
        #error To utilize that value for BARE_DPOT_LEG_BRIDGES or DPOTS_PER_BRIDGED_BARE_LEG, you will have to develop this sketch version further yourself.
    #endif
    #define DPOTS_IN_ALL_BARE_LEG_BRIDGES ( BARE_DPOT_LEG_BRIDGES * DPOTS_PER_BRIDGED_BARE_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) //for bare DPot bridges
    #define DPOTS_PER_BARE_LEG_BRIDGE ( DPOTS_PER_BRIDGED_BARE_LEG * LEGS_PER_DPOT_STYLE_BRIDGE )
    #undef LEGS_PER_DPOT_STYLE_BRIDGE
    #define LEGS_PER_DPOT_STYLE_BRIDGE ( 2 )
    #define BARE_BRIDGE_LEGS ( BARE_DPOT_LEG_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ) //for bare DPot bridges
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
    #define DPOTS_IN_ALL_BARE_LEG_BRIDGES ( 0 ) //for bare DPot bridges
    #define BARE_BRIDGE_LEGS ( 0 ) //for bare DPot bridges
#endif

#if ( ( defined BARE_DPOT_LEGS_UNBRIDGED ) && ( defined DPOTS_PER_UNBRIDGED_BARE_LEG ) && ( BARE_DPOT_LEGS_UNBRIDGED > 0 ) && ( DPOTS_PER_UNBRIDGED_BARE_LEG > 0 ) )
// Limit checking here for number of DPots this sketch can work with.  Be your own developer and expand this capability to fit your needs
    #if ( ( DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 ) || ( BARE_DPOT_LEGS_UNBRIDGED > 0 ) )
        #error To utilize that value for LM334_BRIDGES or DPOTS_PER_LM334_LEG, you will have to develop this sketch version further yourself.
    #endif
    #define DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ( BARE_DPOT_LEGS_UNBRIDGED * DPOTS_PER_UNBRIDGED_BARE_LEG ) //FUTURE USE for unbridged DPot control
#else
    #ifdef DPOTS_PER_UNBRIDGED_BARE_LEG
        #undef DPOTS_PER_UNBRIDGED_BARE_LEG
    #endif
    #ifdef BARE_DPOT_LEGS_UNBRIDGED
        #undef BARE_DPOT_LEGS_UNBRIDGED
    #endif
    #define DPOTS_PER_UNBRIDGED_BARE_LEG ( 0 )
    #define DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ( 0 ) //FUTURE USE for unbridged DPot control
    #define BARE_DPOT_LEGS_UNBRIDGED ( 0 )
#endif
//#if ( ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES /*+ BARE_DPOT_LEGS_UNBRIDGED*/ ) > OUTBOARDS_PLOTTED )
//Notice that BARE_DPOT_LEGS_UNBRIDGED is a don't care to allow greatest user flexibility
//#error The number of outboard ADCs is not adequate for the total from the specified values of LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES 
//#endif
#ifdef DPOT_LEGS
    #undef DPOT_LEGS
#endif
#define DPOT_LEGS ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED )
#if ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES == 0 )
    #undef LEGS_PER_DPOT_STYLE_BRIDGE //Means there are no bridges with DPots in them
    #undef AUTO_BRIDGE_BALANCING
#endif
#if ( DPOT_LEGS == 0 )
//
//Here means there are no DPots in the system anywhere
//
    #undef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC
    #undef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC
    #undef TEST_STEP_UP_DOWN
#else
/*
  Using a Microchip MCP4162 digital potentiometer
    [http://bit.ly/iwDmnd]
    http://tronixstuff.com/tutorials > chapter 34 | CC by-sa-nc | John Boxall
    SS – digital 10 to CS of a single digital pot, not abstracted by library call, so can be any pin as determined within main function unidirectional NOT PIN 10 ON LEONARDO - IS FOUND ON LED_BUILTIN_RX (PIN 17) ONLY
    MOSI – digital 11 to inputs of all digital pots unidirectional NOT PIN 11 ON LEONARDO - IS FOUND ON 1CSP ONLY.  REQ'D IN ALL CASES.
    MISO – digital 12 to outputs of all digital pots unidirectional NOT PIN 12 ON LEONARDO - IS FOUND ON 1CSP ONLY.  REQ'D IN SD CARD. OPTIONAL WHEN DPOTS AREN'T SUPPLIED WITH 8.5-12 VDC FOR PERSISTENCE.
    SCK – digital 13 to CLK of all digital pots unidirectional NOT PIN 13 ON LEONARDO - IS FOUND ON 1CSP ONLY
    Clock speed of MCP4162 is 10 MHz max, well capable to use default Arduino speed of 4 MHz.
    EEPROM and nonvolatile settings are only available with >8.5 Vdc to <12.5Vdc applied to CS pins of MCP4162, which we don't have.
    Therefore, we have no need to read data back from digipots b/c we're storing their settings in sketch variables.
*/
    #ifndef SPIINCLUDED
        #include "SPI.h" //This is the hardware implementation of SPI with CS pin addressable devices (instead of devices with unidirectional data in and data out pins needing addressed via data).  The software implementation uses shiftIn() instead and is slower but frees up otherwise-CS pins and can be used adjunctive for cases where a chip has no CS pin.  Adafruit_ADS1015 uses the shiftIn() method, so those pins are user's choice.  Not data addressable as would be in I2C
        #define SPIINCLUDED
    #endif
    #ifdef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC
        #if ( 1 > INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC + 0 )
            #undef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC
            #define INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC 0 //make sure it contains a bridge index or leg for non-bridged legs, default is bridge 0
        #endif
    #endif
    #ifdef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC
        #if ( 1 > INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC + 0 )
            #undef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC
            #define INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC 0 //make sure it contains a bridge index or leg for non-bridged legs, default is bridge 0
        #endif
    #endif

    #define DPOTS ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED )
    #define READ_AND_PLOT_IN_EACH_LAP true
    #define WORK_ON_THE_REFERENCE_LEG true
/*
      The following are globals since their contents can only be calculated at run-time and necessarily must remain accessible by every function without loss or recalculation, or are essential to the calculation of another global
      and we don't want to waste the CPU time of making them into preprocessor macros which would get calculated every single time the macro is used instead of just a single time when the DPotLeg of interest is changed
*/
    //The following variable is intended to be stored in EEPROM once calculated
    #define NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY 2 //one for total in use, one for available
    static uint16_t dPotLegMSBusedAndAvailables[ NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * DPOT_LEGS ]; //This will only be needed on legs with > 1 Dpots: each leg can store totalAllMSBsThisLeg availableAllMSBsThisLeg
//Since the following defines take up no space in compiled rendering unless they get used, leave them here even if never used
    #define MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg )                         ( dPotLegMSBusedAndAvailables[   NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * dPotLeg      ] )
    #define MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg )                     ( dPotLegMSBusedAndAvailables[ ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * dPotLeg ) + 1 ] )
    #define MSB_SETTINGS_TOTAL_REFERENCE_TO_THIS_SIGNAL_LEG( dPotLeg )     ( dPotLegMSBusedAndAvailables[ ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? ( ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * dPotLeg ) + 2 ) : ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * dPotLeg ) ] )
    #define MSB_SETTINGS_AVAILABLE_REFERENCE_TO_THIS_SIGNAL_LEG( dPotLeg ) ( dPotLegMSBusedAndAvailables[ ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? ( ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * dPotLeg ) + 3 ) : ( ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * dPotLeg ) + 1 ) ] )

    #define MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge )        ( dPotLegMSBusedAndAvailables[ bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ?   NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * bridge * LEGS_PER_DPOT_STYLE_BRIDGE       : ( ( ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) * LEGS_PER_DPOT_STYLE_BRIDGE * NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY ) + ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * ( bridge - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) ) )    ] )
    #define MSB_SETTINGS_AVAILABLE_SIGNAL_THIS_BRIDGE( bridge )    ( dPotLegMSBusedAndAvailables[ bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 : ( ( ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) * LEGS_PER_DPOT_STYLE_BRIDGE * NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY ) + ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * ( bridge - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) ) + 1 ) ] )
    #define MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge )     ( dPotLegMSBusedAndAvailables[ bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) + 2 : ( ( ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) * LEGS_PER_DPOT_STYLE_BRIDGE * NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY ) + ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * ( bridge - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) ) )    ] )
    #define MSB_SETTINGS_AVAILABLE_REFERENCE_THIS_BRIDGE( bridge ) ( dPotLegMSBusedAndAvailables[ bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * bridge * LEGS_PER_DPOT_STYLE_BRIDGE ) + 3 : ( ( ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) * LEGS_PER_DPOT_STYLE_BRIDGE * NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY ) + ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBusedAndAvailables_ARRAY * ( bridge - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) ) + 1 ) ] )

/*
    WHY WE DON'T GLOBALLY STORE THE BRIDGE IN CONTEXT LIKE WE DO THESE OTHER VARS:
    Because sending the bridge as an argument instead is never inconvenient as
    it is always handy from where functions are called that need to know it.
    These globals are here b/c otherwise they would have to be recalculated
    multiple times within the same bridge or leg context or else clutter 
    function argument lists into too much ugliness.  Not so with bridge.
*/
    static uint16_t tattoo = 0;
    static uint8_t whichBridgeOrOutboardADCindex = 0;
    static uint16_t indexOfThisDPotCSpinInDPotArrays = 0;
    static uint8_t dPotLeg;
    static uint8_t dPotsPerThisLeg;
    static uint8_t dPotsPerThisBridge;
    static uint8_t mSBgroupSize;
    static uint8_t lSBdPotIndexThisLeg;
    static uint8_t lSBdPotIndexThisLegReference;
    static uint8_t referenceLSBdPotIndexThisBridge;
    static uint8_t firstMSBindexThisLeg;
    static uint8_t firstMSBindexThisLegReference;
    static uint8_t firstReferenceMSBindexThisBridge;
#ifdef __LGT8FX8E__
void EEPROMupdate ( unsigned long address, u8 val )
{
    if( EEPROM.read( address ) != val ) EEPROM.write( address, val );
}
#endif
    static uint8_t whatIsSignalLegThisBridge( uint8_t bridge )
    {
        return ( ( whichBridgeOrOutboardADCindex < ( LM334_BRIDGES + BARE_BRIDGE_LEGS ) ) ? \
        ( whichBridgeOrOutboardADCindex * 2 ) : \
        ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + whichBridgeOrOutboardADCindex - ( LM334_BRIDGES + BARE_BRIDGE_LEGS ) ) );
    }
    uint8_t whatIsBridgeOfThisDPotLeg( uint8_t dPotLeg )
    { //returns the value of whichBridgeOrOutboardADCindex
        return ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ? \
        dPotLeg >> 1 : ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES + dPotLeg - ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) );
    }
    uint8_t whatIsDPotsPerThisLeg( uint8_t dPotLeg )
    { //returns the value of dPotsPerThisLeg
        return ( dPotLeg < LM334_BRIDGE_LEGS ? \
                DPOTS_PER_LM334_LEG : \
                ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                DPOTS_PER_BRIDGED_BARE_LEG : \
                DPOTS_PER_UNBRIDGED_BARE_LEG );
    }
    uint8_t whatIsDPotsPerThisBridge( uint8_t whichBridgeOrOutboardADCindex )
    { //returns the value of dPotsPerThisBridge
        return ( whichBridgeOrOutboardADCindex < LM334_BRIDGES ? \
                ( DPOTS_PER_LM334_LEG << 1 ) : \
                ( whichBridgeOrOutboardADCindex < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? \
                ( DPOTS_PER_BRIDGED_BARE_LEG << 1 ) : \
                DPOTS_PER_UNBRIDGED_BARE_LEG ) );
    }
    uint8_t whatIsMSBgroupSizeInThisDPotLeg( uint8_t dPotLeg )
    { //returns the value of mSBgroupSize
        return ( dPotLeg < LM334_BRIDGE_LEGS ? \
                ( DPOTS_PER_LM334_LEG > 2 ? ( DPOTS_PER_LM334_LEG - 1 ): 1 ): \
                ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ? \
                ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ? ( DPOTS_PER_BRIDGED_BARE_LEG - 1 ): 1 ): \
                ( DPOTS_PER_UNBRIDGED_BARE_LEG > 2 ? ( DPOTS_PER_UNBRIDGED_BARE_LEG - 1 ) : 1 ) ) );
    }
    uint8_t whatIsMSBgroupSizeInThisBridge( uint8_t whichBridgeOrOutboardADCindex )
    { //returns the value of mSBgroupSize
        return ( whichBridgeOrOutboardADCindex < LM334_BRIDGES ? \
                ( DPOTS_PER_LM334_LEG > 2 ? ( DPOTS_PER_LM334_LEG - 1 ): 1 ): \
                ( whichBridgeOrOutboardADCindex < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? \
                ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ? ( DPOTS_PER_BRIDGED_BARE_LEG - 1 ): 1 ): \
                ( DPOTS_PER_UNBRIDGED_BARE_LEG > 2 ? ( DPOTS_PER_UNBRIDGED_BARE_LEG - 1 ) : 1 ) ) );
    }
    uint8_t whatIsLSBdPotIndexThisLeg( uint8_t dPotLeg )
    { //returns the value of lSBdPotIndexThisLeg
        return ( dPotLeg < LM334_BRIDGE_LEGS ? \
                ( dPotLeg * DPOTS_PER_LM334_LEG ) : \
                ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                ( DPOTS_IN_ALL_LM334_BRIDGES + ( ( dPotLeg - LM334_BRIDGE_LEGS ) * DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
                ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + ( ( dPotLeg - ( LM334_BRIDGE_LEGS + DPOTS_IN_ALL_BARE_LEG_BRIDGES ) * DPOTS_PER_UNBRIDGED_BARE_LEG ) ) ) );
    }
    uint8_t whatIsSignalLSBdPotIndexThisBridge( uint8_t whichBridgeOrOutboardADCindex )
    { //returns the value of lSBdPotIndexThisLeg
        return ( whichBridgeOrOutboardADCindex < LM334_BRIDGES ? \
                ( whichBridgeOrOutboardADCindex * DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) : \
                ( whichBridgeOrOutboardADCindex < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? \
                ( DPOTS_IN_ALL_LM334_BRIDGES + ( ( ( whichBridgeOrOutboardADCindex - LM334_BRIDGES ) * LEGS_PER_DPOT_STYLE_BRIDGE ) * DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
                ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + ( ( ( whichBridgeOrOutboardADCindex - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) * LEGS_PER_DPOT_STYLE_BRIDGE ) * DPOTS_PER_UNBRIDGED_BARE_LEG ) ) ) );
    }
    uint8_t whatIsReferenceLSBdPotIndexThisBridge255IfNone( uint8_t whichBridgeOrOutboardADCindex )
    { //returns the value of lSBdPotIndexThisLeg
        return ( whichBridgeOrOutboardADCindex < LM334_BRIDGES ? \
                ( ( whichBridgeOrOutboardADCindex * DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) + DPOTS_PER_LM334_LEG ): \
                ( whichBridgeOrOutboardADCindex < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? \
                ( ( DPOTS_IN_ALL_LM334_BRIDGES + ( ( ( whichBridgeOrOutboardADCindex - LM334_BRIDGES ) * LEGS_PER_DPOT_STYLE_BRIDGE ) * DPOTS_PER_BRIDGED_BARE_LEG ) ) + DPOTS_PER_BRIDGED_BARE_LEG ) : \
                255 /*special value for whenever there isn't even a reference leg in this bridge, let alone such a DPot*/) );
    }
    uint8_t whatIsFirstMSBindexThisLeg( uint8_t dPotLeg )
    {
        return ( dPotLeg < LM334_BRIDGE_LEGS ? \
                ( dPotLeg * DPOTS_PER_LM334_LEG ) + ( ( DPOTS_PER_LM334_LEG > 1 ) ? 1 : 0 ) : \
                ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                ( DPOTS_IN_ALL_LM334_BRIDGES + ( ( dPotLeg - LM334_BRIDGE_LEGS ) * DPOTS_PER_BRIDGED_BARE_LEG ) + ( ( DPOTS_PER_BRIDGED_BARE_LEG > 1 ) ? 1 : 0 ) ) : \
                ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + ( ( dPotLeg - ( LM334_BRIDGE_LEGS + DPOTS_IN_ALL_BARE_LEG_BRIDGES ) * DPOTS_PER_UNBRIDGED_BARE_LEG ) ) + ( ( DPOTS_PER_UNBRIDGED_BARE_LEG > 1 ) ? 1 : 0 ) ) );
    }
    uint8_t whatIsFirstSignalMSBindexThisBridge( uint8_t whichBridgeOrOutboardADCindex )
    {
        return ( whichBridgeOrOutboardADCindex < LM334_BRIDGES ? \
                ( whichBridgeOrOutboardADCindex * DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( ( DPOTS_PER_LM334_LEG > 1 ) ? 1 : 0 ) : \
                ( whichBridgeOrOutboardADCindex < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? \
                ( DPOTS_IN_ALL_LM334_BRIDGES + ( ( ( whichBridgeOrOutboardADCindex - LM334_BRIDGES ) * LEGS_PER_DPOT_STYLE_BRIDGE ) * DPOTS_PER_BRIDGED_BARE_LEG ) + ( ( DPOTS_PER_BRIDGED_BARE_LEG > 1 ) ? 1 : 0 ) ) : \
                ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + ( ( ( whichBridgeOrOutboardADCindex - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) * LEGS_PER_DPOT_STYLE_BRIDGE ) * DPOTS_PER_UNBRIDGED_BARE_LEG ) + ( ( DPOTS_PER_UNBRIDGED_BARE_LEG > 1 ) ? 1 : 0 ) ) ) );
    } 
    uint8_t whatIsFirstReferenceMSBindexThisBridge255IfNone( uint8_t whichBridgeOrOutboardADCindex )
    {
        return ( whichBridgeOrOutboardADCindex < LM334_BRIDGES ? \
                ( ( whichBridgeOrOutboardADCindex * DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) + DPOTS_PER_LM334_LEG + ( ( DPOTS_PER_LM334_LEG > 1 ) ? 1 : 0 ) ): \
                ( whichBridgeOrOutboardADCindex < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? \
                ( ( DPOTS_IN_ALL_LM334_BRIDGES + ( ( ( whichBridgeOrOutboardADCindex - LM334_BRIDGES ) * LEGS_PER_DPOT_STYLE_BRIDGE ) * DPOTS_PER_BRIDGED_BARE_LEG ) ) + DPOTS_PER_BRIDGED_BARE_LEG + ( ( DPOTS_PER_BRIDGED_BARE_LEG > 1 ) ? 1 : 0 ) ) : \
                255 /*special value for whenever there isn't even a reference leg in this bridge, let alone such a DPot*/) );
    }
    void configureFromDPotLeg( void ) //Note that the way the dPotPins array is ordered allows the following to work even with unbridged legs in the system
    { //checking whether this got executed for the signal leg when the current context is for the reference leg: indexOfThisDPotCSpinInDPotArrays < lSBdPotInLegReference ? <signal leg value> : <reference leg value>
    //If the leg has only a single DPot, the mSBgroupSize will be one and both lSBdPotIndexThisLeg and firstMSBindexThisLeg will equate as firstDPotInLeg in signal leg - the reference leg acts similarly.
        dPotsPerThisLeg = whatIsDPotsPerThisLeg( dPotLeg );
        dPotsPerThisBridge = whatIsDPotsPerThisBridge( whatIsBridgeOfThisDPotLeg( dPotLeg ) );
        
        mSBgroupSize = whatIsMSBgroupSizeInThisBridge( whatIsBridgeOfThisDPotLeg( dPotLeg ) );
        
        lSBdPotIndexThisLeg = whatIsLSBdPotIndexThisLeg( dPotLeg );
        lSBdPotIndexThisLegReference = ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? lSBdPotIndexThisLeg + dPotsPerThisLeg : lSBdPotIndexThisLeg;
        referenceLSBdPotIndexThisBridge = whatIsReferenceLSBdPotIndexThisBridge255IfNone( whichBridgeOrOutboardADCindex );
        
        firstMSBindexThisLeg = lSBdPotIndexThisLeg + ( ( dPotsPerThisLeg > 1 ) ? 1 : 0 );
        firstMSBindexThisLegReference = ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? firstMSBindexThisLeg + dPotsPerThisLeg : firstMSBindexThisLeg;
        firstReferenceMSBindexThisBridge = whatIsFirstReferenceMSBindexThisBridge255IfNone( whichBridgeOrOutboardADCindex );
    }
    
    void configureFromDPotIndex()
    {
      dPotLeg = indexOfThisDPotCSpinInDPotArrays < DPOTS_IN_ALL_LM334_BRIDGES ? \
                ( indexOfThisDPotCSpinInDPotArrays / DPOTS_PER_LM334_LEG ) : \
                indexOfThisDPotCSpinInDPotArrays < DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES ? \
                ( LM334_BRIDGE_LEGS + ( ( indexOfThisDPotCSpinInDPotArrays - DPOTS_IN_ALL_LM334_BRIDGES ) / DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
                LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + ( ( indexOfThisDPotCSpinInDPotArrays - ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) / DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED );
      configureFromDPotLeg();
    }
    
    void configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( uint8_t bridge )
    {
        whichBridgeOrOutboardADCindex = bridge;
      dPotLeg = ( whichBridgeOrOutboardADCindex < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( whichBridgeOrOutboardADCindex * LEGS_PER_DPOT_STYLE_BRIDGE ) :  \
      ( ( ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( whichBridgeOrOutboardADCindex - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) );
      configureFromDPotLeg();
    }
    
    void configureForReferenceLegWithBridgeIndex( uint8_t bridge )
    { //Not using configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs b/c would be too wasteful of CPU
        whichBridgeOrOutboardADCindex = bridge;
      dPotLeg = ( whichBridgeOrOutboardADCindex < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( ( whichBridgeOrOutboardADCindex * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1 ) :  \
      ( ( ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( whichBridgeOrOutboardADCindex - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) );
      configureFromDPotLeg();
    }
    #define MAX_DPOT_SETTG ( signed )256 //This settingValue is 1 less than the actual number of steps b/c the lowest setting is 0 - zero indexed, but since it equates to practical zero resistance this works fine
    
    //    #if ( LM334_BRIDGES > 0 ) Just b/c this conforms to the pattern
    //When using one or two 3:8 decoders, note that these pins numbers must be greater than 127
    //Never use bit 6 of DPotPin for anything except to designate the second pot in a dual pkg
    /*
        To scale up to multiple values of digipotsperleg:
      x1   fix LSB_DPOT_B0U4_PIN names and such
      x2   fix index order within DPotSettings and DPotPins
      >3   fix LSB_DPOT_B0SIG_STARTVALUE names and such
      4   fix DPOT_RATIO to something that will work where it is used
      5
      Never use bit 6 of DPotPin for anything except to designate the second pot in a dual pkg
    
    */
    //If a digipot is the second in a MCP42xx pkg, you will OR that digipot's pin number with B01000000 (add 64) like so: #define LSB_DPOT_B0U4_PIN ( 7 + 64 ) would be for when pin 7 is the physical Arduino Digital pin.  MCP41xx packages need no such consideration
    //If you find that you don't understand that, I'd encourage you to learn the topics of converting between hexadecimal, decimal, and binary and to learn bitwise boolean operations
    #define LSB_DPOT_B0SIG_PIN ( 8 + 64 )         //U8-1 Signal LSB fine adjust digital pot's CS line connected to here
//    #define LSB_DPOT_B0SIG_STARTVALUE 0 //309 52 - 54 or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
    #define LSB_DPOT_B0SIG_STARTVALUE 0 //304 52 - 54 or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
//    #define LSB_DPOT_B0SIG_STARTVALUE 83 //52 - 54 or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
    
    #if ( ( DPOTS_PER_LM334_LEG > 0 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 0 ) )
        #define LSB_DPOT_B0REF_PIN 8        //U8-0 Reference LSB fine adjust digital pot's CS line connected to here
//        #define LSB_DPOT_B0REF_STARTVALUE 0 //310 or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
        #define LSB_DPOT_B0REF_STARTVALUE 0 //305 or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
//        #define LSB_DPOT_B0REF_STARTVALUE 87 //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
    //        #define LSB_DPOT_B0REF_STARTVALUE 18 //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two DPots per leg
    #endif
    #if ( ( DPOTS_PER_LM334_LEG > 1 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 1 ) || ( DPOTS_PER_UNBRIDGED_BARE_LEG > 1 ) )
        #define NON_LSB_DPOT_1_B0SIG_PIN ( 7 + 64 )          //U7-1 MSB digital pot of signal leg CS line connected to here.  coarse adjust B positive (signal) leg
//        #define NON_LSB_DPOT_1_B0SIG_STARTVALUE ( MAX_DPOT_SETTG / 4 ) //or ( MAX_DPOT_SETTG / 2 )  //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two or three DPots per leg
        #define NON_LSB_DPOT_1_B0SIG_STARTVALUE 255 //or ( MAX_DPOT_SETTG / 2 )  //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two or three DPots per leg
    #endif
    #if ( ( DPOTS_PER_LM334_LEG > 1 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 1 ) )
        #define NON_LSB_DPOT_1_B0REF_PIN 7         //U7-0 MSB digital pot of reference leg CS line connected to here.  coarse adjust B negative (reference) leg
//        #define NON_LSB_DPOT_1_B0REF_STARTVALUE ( MAX_DPOT_SETTG / 4 ) //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
        #define NON_LSB_DPOT_1_B0REF_STARTVALUE 0 //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
    //        #define NON_LSB_DPOT_1_B0REF_STARTVALUE 117 //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two DPots per leg
    #endif
    #if ( ( DPOTS_PER_LM334_LEG > 2 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ) || ( DPOTS_PER_UNBRIDGED_BARE_LEG > 2 ) )
        #define NON_LSB_DPOT_2_B0SIG_PIN ( 9 + 64 )         // third digital pot of signal leg CS line connected to here.  coarse adjust B positive (signal) leg
        #define NON_LSB_DPOT_2_B0SIG_STARTVALUE 0  //or ( MAX_DPOT_SETTG / 2 )  //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest
    #endif
    #if ( ( DPOTS_PER_LM334_LEG > 2 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ) )
        #define NON_LSB_DPOT_2_B0REF_PIN 9         // third digital pot of reference leg CS line connected to here.  coarse adjust B negative (reference) leg
        #define NON_LSB_DPOT_2_B0REF_STARTVALUE 0  //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest
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
    static int16_t VRsandbox[ NUM_ANALOG_INPUTS - DPOT_LEGS ]; //A spot for reading in the setting of any particular variable resistor potentiometer
    #define VR1_A2 0 //Subscripts for VRsandbox[ ]
    #define VR2_A3 1
    #define VR3_A6 2
    #define VR4_A7 3
    static uint8_t dPotPins[ DPOTS ]; //If I could just figure out how to fill this array here it would sure make for less code clutter
    static uint16_t dPotSettings[ DPOTS ];
    static uint16_t dPotAnchorSettings[ DPOTS ];
    static uint16_t dPotAnchorSettingsEEPROMAddress[ DPOTS ];
    
    #define SOLVENT 2 //Unit subscripts for dPotSettings[ ], dPotAnchorSettings[ ], and dPotAnchorSettingsEEPROMAddress[ ],  Add unit to sub-unit like this: dPotSettings[ SOLVENT + LSB ]
    #define COUNTER_BALANCING_SOLVENT 0 //Unit subscripts for dPotSettings[ ], dPotAnchorSettings[ ], and dPotAnchorSettingsEEPROMAddress[ ],  Add unit to sub-unit like this: dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ]
    #define LSB 0 //Sub unit subscripts for dPotSettings[ ], dPotAnchorSettings[ ], and dPotAnchorSettingsEEPROMAddress[ ],  Add unit to sub-unit like this: dPotSettings[ SOLVENT + LSB ]
    #define MSB 1 //Sub unit subscripts for dPotSettings[ ], dPotAnchorSettings[ ], and dPotAnchorSettingsEEPROMAddress[ ],  Add unit to sub-unit like this: dPotSettings[ SOLVENT + MSB ]
    static bool pinIsArrayed = true;
    #define THIS_IS_OVERT_PIN_NUMBER_INSTEAD_OF_INDEX false
    #define DONT_CONSOLIDATE_MSB_GROUP_SETTINGS_THIS_TIME false
    /* EEPROM and nonvolatile settings are only available with >8.5, <12.5 Vdc applied to CS pins of MCP4162, which we don't have with mere Arduino: */
    #define MATCHING_TO_SIGNAL_LEG true
#endif

#if ( OUTBOARDS_PLOTTED > 0 )
#define SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC - ANALOG_INPUT_BITS_OF_BOARD )
#else
#define SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE 0
#endif

/*
  DEFINING INDEX_OF_INBOARDS_NOT_SUPERIMPOSED:
*/

#if defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS \
    && ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS > 0 )
#if ( ( ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * LEGS_PER_DPOT_STYLE_BRIDGE ) < INBOARDS_PLOTTED ) && ( defined LEGS_PER_DPOT_STYLE_BRIDGE ) ) //use the smaller of the two possibilities
#define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * LEGS_PER_DPOT_STYLE_BRIDGE )
#else
#define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED INBOARDS_PLOTTED
#endif

#else
#define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED 0
#endif

/*
  DEFINING INDEX_OF_INBOARDS_NOT_PLOTTED:
*/

#define INDEX_OF_INBOARDS_NOT_PLOTTED INBOARDS_PLOTTED

/*
  DEFINING INDEX_OF_OUTBOARDS:
*/
#if ( DPOT_LEGS > INBOARDS_PLOTTED )
#define INDEX_OF_OUTBOARDS DPOT_LEGS
#else
#define INDEX_OF_OUTBOARDS INBOARDS_PLOTTED
#endif

struct previous_readings_only_of_inboards_and_outboards
{
  int32_t CurrentUnmagnifiedReading;
  int32_t PreviousUnmagnifiedReading;
  uint8_t IndexInlinespaceParametersArray;
} typedef previous_readings_only;

//To retrieve bridgeleg readings for non-plotting use such as reading their most recent values while adjusting DPots, you must downconvert them with >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE (shift rights).
previous_readings_only masterReadingsArray[ INDEX_OF_OUTBOARDS + OUTBOARDS_PLOTTED ];

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

#define NUMBER_OF_LINESPACES ( INBOARDS_PLOTTED + OUTBOARDS_PLOTTED - ( INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) ) //Each superimposed pair reduces total linespaces by one from total of plotted
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
#define HALF_HEIGHT_OF_A_PLOT_LINESPACE ( HEIGHT_OF_A_PLOT_LINESPACE >> 1 )

#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) )
#define HALF_HEIGHT_INBOARD_SCALE_OF_A_PLOT_LINESPACE ( pow( 2, ANALOG_INPUT_BITS_OF_BOARD - 1 ) )
static uint16_t counterForTraceOutOfRangeTooLong[ OUTBOARDS_PLOTTED ]; //Main intent is for DIFFERENTIAL input ADCs. This is also used to prevent infinite loop with AUTO_BRIDGE_BALANCING
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
    with OUTBOARDS_PLOTTED > 0
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

static uint8_t* analogPinArray = 0; //Initializing to 0 allows functions that would use it to know whether valid or not
void readAndPlotFromAllADCsInAndOutboard( uint32_t, bool = !( ( bool )analogPinArray ) );
#if ( ( defined DPOT_LEGS ) && ( DPOT_LEGS > 0 ) )

    void printDPotSettings()
    {
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      for( uint8_t dPotLeg = 0; dPotLeg < DPOT_LEGS; dPotLeg++ )
      {
        Serial.print( F( "LegUnit<" ) );
        Serial.print( dPotLeg );
        Serial.print( F( ">, dPotsPerThisLeg=<" ) );
        uint8_t dPotsPerThisLeg = ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                                  DPOTS_PER_LM334_LEG : \
                                  ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ? \
                                    DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG );
        Serial.print( dPotsPerThisLeg );
        Serial.print( F( ">" ) );
        for( uint8_t dPotUnit = 0; dPotUnit < dPotsPerThisLeg; dPotUnit++ )
        { //DPOTS_PER_LM334_LEG.
          Serial.print( F( ", dPotUnit=<" ) );
          Serial.print( dPotUnit );
          Serial.print( F( "> dPotPin=<" ) );
          Serial.print( dPotPins[ ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                                  ( ( dPotLeg * DPOTS_PER_LM334_LEG ) + dPotUnit ) : \
                                  ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                                  ( ( ( LM334_BRIDGE_LEGS * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_BRIDGED_BARE_LEG ) ) + dPotUnit ) : \
                                  ( ( ( LM334_BRIDGE_LEGS + DPOTS_PER_BRIDGED_BARE_LEG ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_UNBRIDGED_BARE_LEG ) + dPotUnit ) ] );
    
          Serial.print( F( ">" ) );
    
          bool signalTrueReferenceFalse = ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                                          ( ( dPotLeg % 2 == 0 ) ? true : false ) : \
                                          true;
    
          if( signalTrueReferenceFalse )
            Serial.print( F( ", signal " ) );
          else
            Serial.print( F( ", reference " ) );
          if( dPotUnit == 0 )
            Serial.print( F( "LSB" ) );
          else
            Serial.print( F( "MSB" ) );
          Serial.print( F( " setting=<" ) );
          Serial.print( dPotSettings[ ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                                      ( ( dPotLeg * DPOTS_PER_LM334_LEG ) + dPotUnit ) : \
                                      ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                                      ( ( ( LM334_BRIDGE_LEGS * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_BRIDGED_BARE_LEG ) ) + dPotUnit ) : \
                                      ( ( ( LM334_BRIDGE_LEGS + DPOTS_PER_BRIDGED_BARE_LEG ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_UNBRIDGED_BARE_LEG ) + dPotUnit ) ] );
//How does the value of 259 get into the above array?  Only up to 257 is allowed.
          if( dPotUnit == 0 || dPotUnit == dPotsPerThisLeg )
          {
            Serial.print( F( ">, " ) );
            if( signalTrueReferenceFalse )
              Serial.print( F( "signal" ) );
            else
              Serial.print( F( "reference" ) );
          }
          else Serial.print( F( "> " ) );
          Serial.print( F( "> dPotUnit=<" ) );
          Serial.print( dPotUnit );
          Serial.print( F( "> " ) );
        }
      }
    #else
        ;
    #endif        
    }
    int16_t writeSettingToAsingleDPot( uint8_t, uint16_t, bool = true );
//#error Here is where we are: all calls to MSB_SETTINGS_ need to send leg or bridge.  all calls into the next function need to send indices, not literal pin numbers which call writeSettingToAsingleDPot() directly
    void setMSBdPotOrGroupValueUsingIndicesOnly( uint8_t indexOfThisDPotCSpinInDPotArrays, \
                                 uint16_t settingValue, /*16 bits to allow cumulative settingValue of msb group to about 250 DPots in the group*/ \
                                 bool consolidateMSBsettings = true )
    {
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( "Just entered setMSBdPotOrGroupValueUsingIndicesOnly, " ) );
        Serial.print( F( "indexOfThisDPotCSpinInDPotArrays=<" ) );
        Serial.print( indexOfThisDPotCSpinInDPotArrays );
        Serial.print( F( "lSBdPotIndexThisLeg=<" ) );
        Serial.print( lSBdPotIndexThisLeg );
        Serial.print( F( "> " ) );
    #endif
//TODO: should be able to adjust code to save space by not sending any LSB in here and then can remove following check: just send all LSB into writeSettingToAsingleDPot(), but must keep the offset version in mind
        if( ( indexOfThisDPotCSpinInDPotArrays == whatIsSignalLSBdPotIndexThisBridge( whatIsBridgeOfThisDPotLeg( ( indexOfThisDPotCSpinInDPotArrays < DPOTS_IN_ALL_LM334_BRIDGES ) ? \
                        ( indexOfThisDPotCSpinInDPotArrays / DPOTS_PER_LM334_LEG ) : \
                        ( indexOfThisDPotCSpinInDPotArrays < DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES ) ? \
                        ( LM334_BRIDGE_LEGS + ( ( indexOfThisDPotCSpinInDPotArrays - DPOTS_IN_ALL_LM334_BRIDGES ) / DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
                        LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + ( ( indexOfThisDPotCSpinInDPotArrays - ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) / DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ) ) ) ) || \
        ( indexOfThisDPotCSpinInDPotArrays == whatIsReferenceLSBdPotIndexThisBridge255IfNone( whatIsBridgeOfThisDPotLeg( ( indexOfThisDPotCSpinInDPotArrays < DPOTS_IN_ALL_LM334_BRIDGES ) ? \
                        ( indexOfThisDPotCSpinInDPotArrays / DPOTS_PER_LM334_LEG ) : \
                        ( indexOfThisDPotCSpinInDPotArrays < DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES ) ? \
                        ( LM334_BRIDGE_LEGS + ( ( indexOfThisDPotCSpinInDPotArrays - DPOTS_IN_ALL_LM334_BRIDGES ) / DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
                        LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + ( ( indexOfThisDPotCSpinInDPotArrays - ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) / DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ) ) ) ) )
        {
            Serial.print( F( ", calling writeSettingToAsingleDPot with settingValue=<" ) );
            Serial.print( settingValue );
            Serial.print( F( "> Line <967> " ) );
            writeSettingToAsingleDPot( indexOfThisDPotCSpinInDPotArrays, settingValue ); //These avoid getting MSB group setting consolidated b/c they aren't MSB.  Any MSB will require MSB_SETTINGS_ arrays to get recalculated, so they couldn't get trapped here
        }
        else
        {
        #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
            Serial.print( F( "about to get set to<" ) );
            Serial.print( settingValue );
            Serial.print( F( "> Line <885>" ) );
        #endif
            //Make agnostic to which MSB subunit was spec'd - change to first in group:
            uint8_t dPotLeg = ( indexOfThisDPotCSpinInDPotArrays < DPOTS_IN_ALL_LM334_BRIDGES ) ? \
                ( indexOfThisDPotCSpinInDPotArrays / DPOTS_PER_LM334_LEG ) : \
                ( indexOfThisDPotCSpinInDPotArrays < DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES ) ? \
                ( LM334_BRIDGE_LEGS + ( ( indexOfThisDPotCSpinInDPotArrays - DPOTS_IN_ALL_LM334_BRIDGES ) / DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
                LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + ( ( indexOfThisDPotCSpinInDPotArrays - ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) / DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED );
            uint8_t mSBdPotIndex = whatIsFirstMSBindexThisLeg( dPotLeg );
            uint8_t mSBgroupSize = whatIsMSBgroupSizeInThisDPotLeg( dPotLeg );
            uint16_t settingValueTmp = 0;
            Serial.print( F( ", mSBdPotIndex=<" ) );
            Serial.print( mSBdPotIndex );
            Serial.print( F( "> Line <892>" ) );
    
            if( consolidateMSBsettings )
            {
    /*  start consolidate MSB Settings      */
                uint8_t mSBdPotIndexTmp = mSBdPotIndex;
                for( uint8_t counter = 0; counter < mSBgroupSize - 1; counter++ )
                { //This will fix all but last one which will need to correct for rounding errors
                    Serial.print( F( ", calling writeSettingToAsingleDPot with settingValue=<" ) );
                    Serial.print( settingValue );
                    Serial.print( F( "> Line <995> " ) );
                    writeSettingToAsingleDPot( mSBdPotIndexTmp, ( settingValue / mSBgroupSize ) );
                    mSBdPotIndexTmp++;
                }
                Serial.print( F( ", calling writeSettingToAsingleDPot with settingValue=<" ) );
                Serial.print( settingValue );
                Serial.print( F( "> Line <1001> " ) );
                writeSettingToAsingleDPot( mSBdPotIndexTmp,  settingValue - ( ( ( uint16_t/*force possible rounding errors to re-appear here to compensate for them*/)( settingValue / mSBgroupSize ) ) * ( mSBgroupSize - 1 ) ) ); //correct for rounding errors
    /*   end consolidate MSB Settings         */
            }
            else
            {
                Serial.print( F( ", calling writeSettingToAsingleDPot with settingValue=<" ) );
                Serial.print( settingValue );
                Serial.print( F( "> Line <1009> " ) );
                writeSettingToAsingleDPot( indexOfThisDPotCSpinInDPotArrays, settingValue );
            }
        //Update MSB_SETTINGS_ arrays
            MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) = 0;
            for( uint8_t mSBindexOffset = 0; mSBindexOffset < mSBgroupSize; mSBindexOffset++ )
            {
                MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) += dPotSettings[ mSBdPotIndex + mSBindexOffset ];
            }
    //Update MSB_SETTINGS_AVAILABLE_THIS_LEG arrays to match
            MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg ) = ( mSBgroupSize * MAX_DPOT_SETTG ) - MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg );
        }
    }
    
    int16_t writeSettingToAsingleDPot( uint8_t indexOfThisDPotCSpinInDPotArrays, uint16_t settingValue, bool thisIsIndexForPinNotPinNumberDirectly )
    {
        if( settingValue > 256 )
        {
            Serial.print( F( ", BAD settingValue=<" ) );
            Serial.print( settingValue );
            Serial.print( F( "> Line <1020> " ) );
        }
    #ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
          //This is not tested, it is just a first proposed step to give capability for many ADCs
          if( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) >= 128 )
          { //Pins numbered below 128 are normal digital inboard pins
            //Pins numbered above 127 are outboard pins provided through the dual 74LV138 decoding circuitry
            //The two 74LV138 each have three enable pins but we only use one.
            //It would require 7 pins to address the two devices simultaneously.
            //Use 'em since we have 'em...it'll save a part for latch
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A0_PIN1,  ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & B1 );  //These address bits are always necessary
        #ifdef FIRST_STAGE_3_TO_8_DECODER_A1_PIN2
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A1_PIN2,  ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & B10 ); //These address bits are always necessary
        #endif
        #ifdef FIRST_STAGE_3_TO_8_DECODER_A2_PIN3
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A2_PIN3,  ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & B100 ); //These address bits are always necessary
        #endif
        #ifdef FIRST_STAGE_3_TO_8_DECODER_A3_PIN4
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A3_PIN4,  ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & B1000 ); //These address bits are always necessary
        #endif
        #ifdef FINAL_STAGE_3_TO_8_DECODER_A0_PIN1
            digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A0_PIN1, ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & B1000 ); //This decoder might not be present
        #endif
        #ifdef FINAL_STAGE_3_TO_8_DECODER_A1_PIN2
            digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A1_PIN2, ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & B10000 ); //This decoder might not be present
        #endif
        #ifdef FINAL_STAGE_3_TO_8_DECODER_A2_PIN3
            digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A2_PIN3, ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & B100000 );  //This decoder might not be present
        #endif
            //bit B1000000 is reserved for virtualizing the second DPot in a dual DPot pkg MCP42xxx
            //Never have bit 6 set in elements of dPotPins[ indexOfThisDPotCSpinInDPotArrays ] for anything except to designate the second pot in a dual pkg MCP42xxx
        #ifdef FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4
            digitalWrite( FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4, LOW ); // In prep for next instruction.
        #endif
        #ifdef FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4, LOW ); // In prep for next instruction.
        #endif
          }
    #endif
#ifdef COMPILE_FOR_DIAGS_ONLY
        Serial.print( F( "Line<1084>\n" ) );
      if ( digitalRead( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F ) != HIGH )
        {
            Serial.print( F( "Line<1087> BAD dPot<" ) );
            Serial.print( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F );
            Serial.print( F( "> bar-CS read-back not HIGH=<" ) );
            Serial.print( digitalRead( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F ) );
            Serial.print( F( ">\n" ) );
        }
#endif
      digitalWrite( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F, LOW ); //activates the bar-CS pin
#ifdef COMPILE_FOR_DIAGS_ONLY
      if ( digitalRead( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F ) != LOW )
        {
            Serial.print( F( "Line<1097> BAD dPot<" ) );
            Serial.print( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F );
            Serial.print( F( "> bar-CS read-back not LOW=<" ) );
            Serial.print( digitalRead( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F ) );
            Serial.print( F( ">\n" ) );
        }
#endif
      SPI.transfer( ( settingValue & 0x100 ) ? /*will the second data byte be one or zero?*/\
            ( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x40 ? 0x11 : 1 ) : \
            ( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x40 ? 0x10 : 0 ) ); //This is the way we allow dual dpot devices MCP42xxx
      SPI.transfer( settingValue & 0xFF ); // send settingValue (0~255)
      /**********************************************************************************************************************************************************
        When dual pots are employed (MCP42XXX) this is the way to control the second DPOT in the pkg:  the first digi pot of a pkg is addressed with true pin number,
        the second digipot in the pkg is addressed by adding 64 to the physical pin number driving the pkg, creating a virtual pin number for that second DPot of the pkg
              SPI.transfer( ( settingValue & 0x100 ) ? 0x11 : 0x10 ); //NOTE THE LEADING 1 HERE THAT DOESN'T APPEAR FOR MCP41XXX - it's part of the 0x10
              SPI.transfer( settingValue & 0xff ); // send settingValue (0~255)
    
        In order to utilize this method, both dual pots share a single physical CS (dPotPins[ indexOfThisDPotCSpinInDPotArrays ]) pin (remember ones above 127 pin numbers are connected via 3-to-8 decoders)
        but virtually the second DPot's physical dPotPins[ indexOfThisDPotCSpinInDPotArrays ] must be OR'd with 0x40 (adding 64) in this sketch.  Note that two different schemes of dual DPot can exist:
        duals shared on same leg and duals shared across legs.  By adhering to the afore-described pin numbering methodology, either scheme or both mixed
        throughout the system will work fine.  Note that if any boards have actual physical pins numbered above 64, those cannot be used for DPotPins without sketch
        modification to accommodate it.
    
      ***********************************************************************************************************************************************************/
      digitalWrite( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F, HIGH );
#ifdef COMPILE_FOR_DIAGS_ONLY
      if ( digitalRead( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F ) != HIGH )
        {
            Serial.print( F( "Line<1125> BAD dPot<" ) ) ;
            Serial.print( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F );
            Serial.print( F( "> bar-CS read-back not HIGH=<" ) );
            Serial.print( digitalRead( ( thisIsIndexForPinNotPinNumberDirectly ? dPotPins[ indexOfThisDPotCSpinInDPotArrays ] : indexOfThisDPotCSpinInDPotArrays ) & 0x3F ) );
            Serial.print( F( ">\n" ) );
        }
#endif
    #ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
        #ifdef FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4
            digitalWrite( FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4, HIGH );
        #endif
        #ifdef FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4, HIGH );
        #endif
    #endif
//    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( "Pin <" ) );
        if( thisIsIndexForPinNotPinNumberDirectly ) 
        {
            Serial.print( dPotPins[ indexOfThisDPotCSpinInDPotArrays ] );
        }
        else
        {
            Serial.print( indexOfThisDPotCSpinInDPotArrays );
        }
        Serial.print( F( "> got set to <" ) );
        Serial.print( settingValue );
        Serial.print( F( "> " ) );
//    #endif
    uint16_t settingPrevious = dPotSettings[ indexOfThisDPotCSpinInDPotArrays ];
      if( thisIsIndexForPinNotPinNumberDirectly )
      { //Until we build a different model, analogPinArray is repurposed temporarily to tell dpot-setting functions whether the encoded pin number they are receiving is actually the index within dPotPins[] where the literal pin number is to be looked up or is the literal pin number, in which case the dPotSettings[] will not get written to
        dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] = settingValue;
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
            Serial.print( F( "and settings saved to dPotSettings[" ) );
            Serial.print( indexOfThisDPotCSpinInDPotArrays );
            Serial.print( F( "] " ) );
    #endif
        printDPotSettings();
        return ( dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] - settingPrevious );
      }
//      printDPotSettings();//
      return 0;
    }

    void offsetMSBdPotOrGroupValueUsingIndicesOnly( uint8_t indexOfThisDPotCSpinInDPotArrays, int16_t offsetValue )
    { //configureFrom...() and configureFor...() must already be ran 
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      Serial.print( F( " Entering offsetMSBdPotOrGroupValueUsingIndicesOnly=<" ) );
      Serial.print( indexOfThisDPotCSpinInDPotArrays );
      Serial.print( F( "> for pin<" ) );
      Serial.print( dPotPins[ indexOfThisDPotCSpinInDPotArrays ] );
      Serial.print( F( ">, offsetValue<" ) );
      Serial.print( offsetValue );
      Serial.print( F( "> " ) );
    #endif
    #ifdef DEBUG
      //        offsetValue *= 10;  //A magnifier for troubleshooting
      while( !Serial );
      Serial.print( F( "Line<775> offsetValue=" ) );
      Serial.print( offsetValue );
      Serial.print( F( " for Digi pot on pin " ) );
    #endif
//#error The next instruction is part of the problem
        bool thisIsReferenceWhenConfigureWasForSignal = !( indexOfThisDPotCSpinInDPotArrays < lSBdPotIndexThisLegReference );
      Serial.print( F( ">, thisIsReferenceWhenConfigureWasForSignal<" ) );
      Serial.print( thisIsReferenceWhenConfigureWasForSignal );
      if( indexOfThisDPotCSpinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBdPotIndexThisLegReference : lSBdPotIndexThisLeg ) )
      {


        
        
//A truncate error below makes a 1 out of what should equate to 0?
//#error FIX next instruction:
        int16_t borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO = ( offsetValue < 0 ) ? \
            ( ( 0 - ( ( signed )abs( min( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ), 0 ) ) ) ) + \
            DPOT_RATIO - 1 ) / DPOT_RATIO : \
        ( ( max( ( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) - MAX_DPOT_SETTG ), 0 ) + DPOT_RATIO - 1 ) / \
        DPOT_RATIO );
        
//should be a borrow, not a carry anyway: if will go negative, borrow beyond amount needed: ( offsetValue < 0 ) ? ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ]) / DPOT_RATIO : ( ( ( offsetValue+dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) - MAX_DPOT_SETTG ) / DPOT_RATIO ) );

        //recursive call for borrow/carry against the MSB group
//#error This is where we are: carrying should only happen when lsb setting would go over MAX_DPOT_SETTG, borrowing only when would go under zero
      Serial.print( F( ">, " ) );
      if( borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO ) 
          Serial.print( F( "making a recursive call with " ) );
      Serial.print( F( "borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO=<" ) );
      Serial.print( borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO );
      Serial.print( F( ">, max( ( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) - MAX_DPOT_SETTG ), <0> )=<" ) );
      Serial.print( max( ( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) - MAX_DPOT_SETTG ), 0 ) );
      Serial.print( F( ">, offsetValue=<" ) );
      Serial.print( offsetValue );
      Serial.print( F( ">, ( max( ( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) - MAX_DPOT_SETTG ), <0> ) + DPOT_RATIO - <1> )=<" ) );
      Serial.print( ( max( ( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) - MAX_DPOT_SETTG ), 0 ) + DPOT_RATIO - 1 ) );
//      Serial.print( F( ">, DPOT_RATIO - <1> )=<" ) );
//      Serial.print( DPOT_RATIO - 1 );
//      Serial.print( F( ">, <0> - ( ( ( signed )abs( min( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ), <0> ) ) + DPOT_RATIO - <1> ) / DPOT_RATIO )=<" ) );
//      Serial.print( 0 - ( ( ( signed )abs( min( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ), 0 ) ) + DPOT_RATIO - 1 ) / DPOT_RATIO ) );
//      Serial.print( F( ">, ( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) - MAX_DPOT_SETTG )=<" ) );
//      Serial.print( ( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) - MAX_DPOT_SETTG ) );
//      Serial.print( F( ">, ( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) - MAX_DPOT_SETTG ) / DPOT_RATIO )=<" ) );
//      Serial.print( ( ( offsetValue + dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) - MAX_DPOT_SETTG ) / DPOT_RATIO );
      Serial.print( F( ">, " ) );//offsetValue=<" ) );
//      Serial.print( offsetValue );



      if( borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO ) 
      {
        offsetMSBdPotOrGroupValueUsingIndicesOnly( thisIsReferenceWhenConfigureWasForSignal ? dPotsPerThisLeg + firstMSBindexThisLeg : firstMSBindexThisLeg, borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO );
        Serial.print( F( "back after recursive call " ) );
        offsetValue -= borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO * DPOT_RATIO;
      }
        if( !offsetValue ) return;
      Serial.print( F( ", offsetValue now<" ) );//offsetValue now<220>
      Serial.print( offsetValue );
      }
      //Sanity check on offset amount being requested:
    
      Serial.print( F( ">, lSBdPotIndexThisLeg<" ) );
      Serial.print( lSBdPotIndexThisLeg );
      Serial.print( F( ">, MSB_SETTINGS_TOTAL_THIS_LEG<" ) );
      Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) );
      Serial.print( F( ">, MSB_SETTINGS_AVAILABLE_THIS_LEG<" ) );
      Serial.print( MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg ) ); //This value not right FIXME
      Serial.print( F( ">, dPotSettings[ indexOfThisDPotCSpinInDPotArrays ]<" ) );
      Serial.print( dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] );
      Serial.print( F( "> " ) );
    
    if( ( ( offsetValue < 0 ) && \
        ( ( 0 - offsetValue ) > ( ( indexOfThisDPotCSpinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBdPotIndexThisLegReference : lSBdPotIndexThisLeg ) ? \
        dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_REFERENCE_TO_THIS_SIGNAL_LEG( dPotLeg ) : MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) ) ) ) ) ) || \
        ( ( offsetValue > 0 ) && ( offsetValue > ( ( indexOfThisDPotCSpinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBdPotIndexThisLegReference : lSBdPotIndexThisLeg ) ) ? \
        ( MAX_DPOT_SETTG - dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) \
        : ( thisIsReferenceWhenConfigureWasForSignal ? \
        MSB_SETTINGS_AVAILABLE_REFERENCE_TO_THIS_SIGNAL_LEG( dPotLeg ) : MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg ) ) ) ) ) )
    { //Beyond limit being asked for.  This location is where to add carrying/borrowing feature
        Serial.print( F( "Beyond limit of<" ) );
        Serial.print( thisIsReferenceWhenConfigureWasForSignal ? \
MSB_SETTINGS_AVAILABLE_REFERENCE_TO_THIS_SIGNAL_LEG( dPotLeg ) : MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg ) );
        Serial.print( F( ">, MSB_SETTINGS_AVAILABLE_REFERENCE_TO_THIS_SIGNAL_LEG=<" ) );
        Serial.print( MSB_SETTINGS_AVAILABLE_REFERENCE_TO_THIS_SIGNAL_LEG( dPotLeg ) );
        Serial.print( F( ">, MSB_SETTINGS_AVAILABLE_THIS_LEG=<" ) );
        Serial.print( MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg ) );
        Serial.print( F( ">, limiting offset request of <" ) );
        Serial.print( offsetValue );
        Serial.print( F( "> to <" ) );
    
        if( offsetValue < 0 )
        {
            if( indexOfThisDPotCSpinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBdPotIndexThisLegReference : lSBdPotIndexThisLeg ) ) //( ( indexOfThisDPotCSpinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBdPotIndexThisLegReference : lSBdPotIndexThisLeg ) ? dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] 
                offsetValue = 0 - dPotSettings[ indexOfThisDPotCSpinInDPotArrays ];/*a negative LSB value equaling zero minus the current setting*/
            else // : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_REFERENCE_TO_THIS_SIGNAL_LEG : MSB_SETTINGS_TOTAL_THIS_LEG ) ) ) ) )
                offsetValue = 0 - ( signed )( thisIsReferenceWhenConfigureWasForSignal ? ( signed )MSB_SETTINGS_TOTAL_REFERENCE_TO_THIS_SIGNAL_LEG( dPotLeg ) : ( signed )MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) );/*a negative MSB value equaling zero minus the current total*/
        }
        else //if( ( offsetValue < 0 ) && ( offsetValue > ( ( indexOfThisDPotCSpinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBdPotIndexThisLegReference : lSBdPotIndexThisLeg ) ? ( offsetValue > ( MAX_DPOT_SETTG - dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] ) ) : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_REFERENCE_TO_THIS_SIGNAL_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG ) ) ) ) )
            if( indexOfThisDPotCSpinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBdPotIndexThisLegReference : lSBdPotIndexThisLeg ) ) //( ( indexOfThisDPotCSpinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBdPotIndexThisLegReference : lSBdPotIndexThisLeg ) ? dPotSettings[ indexOfThisDPotCSpinInDPotArrays ] 
                offsetValue = dPotSettings[ indexOfThisDPotCSpinInDPotArrays ];/*a negative LSB value equaling the current setting*/
            else // : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_REFERENCE_TO_THIS_SIGNAL_LEG( dPotLeg ) : MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) ) ) ) ) )
                offsetValue = thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_REFERENCE_TO_THIS_SIGNAL_LEG( dPotLeg ) : MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg );/*a positive MSB value equaling the current available*/
    
        Serial.print( offsetValue );
        Serial.print( F( ">." ) );
      }//Sanity enforcement complete
    
    if( indexOfThisDPotCSpinInDPotArrays == \
    ( thisIsReferenceWhenConfigureWasForSignal ? \
    lSBdPotIndexThisLegReference : lSBdPotIndexThisLeg ) )
        offsetValue += dPotSettings[ indexOfThisDPotCSpinInDPotArrays ];
    else
        offsetValue += MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg );
    #ifdef DEBUG
      while( !Serial );
      Serial.print( dPotPins[ indexOfThisDPotCSpinInDPotArrays ] );
      Serial.print( F( " getting " ) );
      Serial.print( offsetValue );
    #endif
      //setMSBdPotOrGroupValueUsingIndicesOnly( const uint8_t DPotPin, uint16_t settingValue ) or writeSettingToAsingleDPot()
      setMSBdPotOrGroupValueUsingIndicesOnly( indexOfThisDPotCSpinInDPotArrays, ( uint16_t )offsetValue );//TODO: could we use writeSettingToAsingleDPot here?  Or is this the only reason to maintain code to differentiate in setMSBdPotOrGroupValueUsingIndicesOnly()
    }

    static int32_t analogInputUnitsTimes64PerMSBLegSettingUnit[ DPOT_LEGS ]; //The "Times64" notion is really modifiable via the macro BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION
    static int32_t legLSBsettingUnitsTimes64PerAnalogInputUnit[ DPOT_LEGS ]; //The "Times64" notion is really modifiable via the macro BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION
    static int32_t startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ DPOT_LEGS ];// = 0; //As of now, I foresee only one leg at a time needing the setting saved except in the setup() which will use a local var for the other leg
    static int16_t startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ DPOT_LEGS ];// = 0; //signed b/c we need to do subtraction with it and save sign
    static int16_t incomingInboardAnalogLevelSignal[ DPOT_LEGS ];// = 0; //signed b/c we need to do subtraction with it and save sign
    int16_t bestOfFour( uint8_t ); //signed b/c we need to do subtraction with it and save sign
    #define MOST_ACCURATE true  //This belongs with the following function declare
    int16_t bestGuessAnalogInputReading( uint8_t = dPotLeg, bool = !MOST_ACCURATE, bool = true ); //signed b/c we need to do subtraction with it and save sign
    #define TARGET_LEVEL_DUMMY_VALUE 0
    #define USE_OPPOSING_LEGS_LEVEL_AS_TARGET_LEVEL true
    static bool thisIsTheMSBPass;
    static int16_t settingStepSize, endLevel, targetLevel; //signed b/c we need to do subtraction with it and save sign
    #define END_LEVEL_VALID true
//#error Next step: reconcile setDPotLegMidPoint() with dPotLegSetpointing()

    void theNewSettingStepSizeInLSBUnits( bool endLevelValid = END_LEVEL_VALID )
    { //endLevel might not be valid yet or might cause division by zero
//What about limits like this:        settingStepSize = ( settingStepSize < 0 ) ? 0 - ( signed )MSB_SETTINGS_TOTAL_THIS_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG;
        if( endLevelValid && ( ( endLevel - incomingInboardAnalogLevelSignal[ dPotLeg ] ) ) ) //so we don't divide by the wrong value or by zero in here
        {
            legLSBsettingUnitsTimes64PerAnalogInputUnit[ dPotLeg ] = ( int32_t )( ( ( ( ( signed )DPOT_RATIO * ( signed )MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) ) + dPotSettings[ lSBdPotIndexThisLeg ] ) - ( ( signed )DPOT_RATIO * ( signed )startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ dPotLeg ] + startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ dPotLeg ] ) ) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) / ( signed )( ( signed )endLevel - ( signed )incomingInboardAnalogLevelSignal[ dPotLeg ] );
            Serial.print( F( "Entered theNewSettingStepSizeInLSBUnits() with level difference=<" ) );
            Serial.print( ( endLevel - incomingInboardAnalogLevelSignal[ dPotLeg ] ) );
            Serial.print( F( "> and step difference=<" ) );
            Serial.print( ( ( signed )( ( signed )DPOT_RATIO * ( signed )MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) ) + dPotSettings[ lSBdPotIndexThisLeg ] ) - ( ( signed )DPOT_RATIO * ( signed )startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ dPotLeg ] + startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ dPotLeg ] ) );
            Serial.print( F( "> and calculated from ( ( signed )DPOT_RATIO * ( signed )MSB_SETTINGS_TOTAL_THIS_LEG ) + dPotSettings[ lSBdPotIndexThisLeg ] ) =<" ) );
            Serial.print( ( signed )( ( signed )DPOT_RATIO * ( signed )MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) ) + dPotSettings[ lSBdPotIndexThisLeg ] );
//            Serial.print( F( ">, =<" ) );
//            Serial.print(  );
            Serial.print( F( "> legLSBsettingUnitsTimes64PerAnalogInputUnit=<" ) );
            Serial.print( legLSBsettingUnitsTimes64PerAnalogInputUnit[ dPotLeg ] );
            Serial.print( F( ">. Calculated settingStepSize=<" ) );
            settingStepSize = ( ( endLevel - targetLevel ) * legLSBsettingUnitsTimes64PerAnalogInputUnit[ dPotLeg ] ) / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION );
            Serial.print( settingStepSize );
            Serial.print( F( "> divd by DPOT_RATIO=<" ) );
            Serial.print( ( ( ( endLevel - targetLevel ) * legLSBsettingUnitsTimes64PerAnalogInputUnit[ dPotLeg ] ) / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) / ( signed )DPOT_RATIO );
            Serial.print( F( ">. " ) );
        }
        else
        {
            settingStepSize = ( incomingInboardAnalogLevelSignal[ dPotLeg ] - targetLevel ) / ( signed )2;
        //The following lines are the key to predictive leg setting
            if( thisIsTheMSBPass )
            {
                settingStepSize = ( incomingInboardAnalogLevelSignal[ dPotLeg ] - targetLevel ) / ( signed )2;
            }
            else
                settingStepSize = ( incomingInboardAnalogLevelSignal[ dPotLeg ] - targetLevel ) / ( signed )2;
        }
        Serial.print( F( "Calculated or not settingStepSize=<" ) );
        Serial.print( settingStepSize );
        Serial.print( F( ">. " ) );
//        analogInputUnitsTimes64PerMSBLegSettingUnit[ dPotLeg ] = ( ( endLevel - incomingInboardAnalogLevelSignal[ ) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) / ( signed )( startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ dPotLeg ] -( signed )MSB_SETTINGS_TOTAL_THIS_LEG );
    //not good yet        legLSBsettingUnitsTimes64PerAnalogInputUnit[ dPotLeg ] = ( ( endLevel - incomingBestGuessAnalogInputreading ) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION )) / ( signed )( startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ dPotLeg ] - dPotSettings[ lSBdPotIndexThisLeg ] );
    //DON'T ALLOW A new STEP SIZE CHANGE to less THAN 1/6 of current IF TARGET HASN'T BEEN ACQUIRED: FROM 20 CAN ONLY GO DOWN TO 3 or -3
    }
    #define REFERENCE_LEG_LEVEL_IS_HIGH 1
    #define REFERENCE_LEG_LEVEL_IS_OPTIMAL 0
    #define REFERENCE_LEG_LEVEL_IS_LOW -1
    static int8_t referenceLegLevelFromLastSettingIt[ LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ];




//#error The return value of this function is not being used very well.  Trackk thingws down and FIXME
    int16_t dPotLegSetpointing( bool readAndPlotInEachLap = !READ_AND_PLOT_IN_EACH_LAP, bool useOpposingLegLevelAsTargetLevel = !USE_OPPOSING_LEGS_LEVEL_AS_TARGET_LEVEL, uint8_t dPotLeg = dPotLeg )
    { //returns the resulting single-try reading of the leg, making it negative if the direction to target level changed?   int16_t value = bestOfFour( dPotLeg )
        bool originalDirectionToTargetLevel, directionToTargetLevel;
        if( useOpposingLegLevelAsTargetLevel && ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) )
            targetLevel = bestGuessAnalogInputReading( dPotLeg + ( ( dPotLeg % 2 ) ? -1 : 1 ), MOST_ACCURATE );
        incomingInboardAnalogLevelSignal[ dPotLeg ] = bestGuessAnalogInputReading( dPotLeg, MOST_ACCURATE );
        if( incomingInboardAnalogLevelSignal[ dPotLeg ] == targetLevel ) return true; //if already there
        originalDirectionToTargetLevel = targetLevel > incomingInboardAnalogLevelSignal[ dPotLeg ];
        startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ dPotLeg ] = MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg );
        startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ dPotLeg ] = dPotSettings[ lSBdPotIndexThisLeg ];
        thisIsTheMSBPass = true;
        int16_t startSettings, startLevel;
        int16_t newStepSize, oldStepSizeDivdBy6;
        

CalculateNewStepSize:
        theNewSettingStepSizeInLSBUnits( !END_LEVEL_VALID );
//        settingStepSize = analogInputUnitsTimes64PerMSBLegSettingUnit[ dPotLeg ] ? \
//            ( 100 * ( signed )( targetLevel - incomingInboardAnalogLevelSignal[ ) ) / analogInputUnitsTimes64PerMSBLegSettingUnit[ dPotLeg ] : \
//             theNewSettingStepSizeInLSBUnits();
//#error Next step: reconcile all the different stepsize calculations, then the borrow/carry problem
        endLevel = incomingInboardAnalogLevelSignal[ dPotLeg ];
        bool firstPass;
        Serial.print( F( "Entered dPotLegSetpointing(" ) );
        Serial.print( dPotLeg );
        Serial.print( F( ") with incomingInboardAnalogLevel=<" ) );
        Serial.print( incomingInboardAnalogLevelSignal[ dPotLeg ] );
        Serial.print( F( ">, targetLevel=<" ) );
        Serial.print( targetLevel );
        Serial.print( F( ">, settingStepSize=<" ) );
        Serial.print( settingStepSize );
        Serial.print( F( ">, readAndPlotInEachLap=<" ) );
        Serial.print( readAndPlotInEachLap );
        Serial.print( F( ">, useOpposingLegLevelAsTargetLevel=<" ) );
        Serial.print( useOpposingLegLevelAsTargetLevel );
        Serial.print( F( ">, analogInputUnitsTimes64PerMSBLegSettingUnit[ dPotLeg ]=<" ) );
        Serial.print( analogInputUnitsTimes64PerMSBLegSettingUnit[ dPotLeg ] );
        Serial.print( F( ">, ( 100 * ( signed )( targetLevel - incomingInboardAnalogLevelSignal[ ) ) / ( analogInputUnitsTimes64PerMSBLegSettingUnit[ dPotLeg ] )=<" ) );
        Serial.print( ( 100 * ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevelSignal[ dPotLeg ] ) ) / ( analogInputUnitsTimes64PerMSBLegSettingUnit[ dPotLeg ] ) );
        Serial.print( F( ">, ( dPotLeg < LM334_BRIDGE_LEGS )=<" ) );
        Serial.print( ( dPotLeg < LM334_BRIDGE_LEGS ) );
        Serial.print( F( ">, ( targetLevel > incomingInboardAnalogLevelSignal)=<" ) );
        Serial.print( ( targetLevel > incomingInboardAnalogLevelSignal[ dPotLeg ] ) );
        Serial.print( F( ">, ( targetLevel - incomingInboardAnalogLevelSignal[ ) / -2=<" ) );
        Serial.print( ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevelSignal[ dPotLeg ] ) / -2 );
        Serial.print( F( ">, ( incomingInboardAnalogLevelSignal[ - targetLevel ) / 2=<" ) );
        Serial.print( ( signed )( ( signed )incomingInboardAnalogLevelSignal[ dPotLeg ] - ( signed )targetLevel ) / ( signed )2 );
        Serial.print( F( "> " ) );
        do //has to be able to loop b/c the legLSBsettingUnitsTimes64PerAnalogInputUnit[ dPotLeg ] might be way off or not set
        { //checked reference leg
            firstPass = true;
            do //has to be able to loop b/c the legLSBsettingUnitsTimes64PerAnalogInputUnit[ dPotLeg ] might be way off or not set
            { //checked reference leg
                if( thisIsTheMSBPass )
                {
                    if( ( signed )( ( settingStepSize < 0 ) ? MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) : MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg ) ) < abs( settingStepSize ) )
                    {
                        theNewSettingStepSizeInLSBUnits();
                        if( !( settingStepSize / ( signed )DPOT_RATIO ) ) 
                            break;
                    }
                }
                else if( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE == targetLevel )
                {
                    break; //This will go outside the MSB loop for the second time and we shouldn't need to come back
                }
                else
                {
//                    if( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE > targetLevel )
//                    {//making sure stepsize polarity is positive for dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ), negative otherwise
                        theNewSettingStepSizeInLSBUnits();
//                        settingStepSize = ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
//                        ( signed )( ( signed )( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )targetLevel ) : \
//                        ( signed )( ( signed )targetLevel - ( signed )( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
//                    }
//                    else
//                    {//making sure stepsize polarity is negative for dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ), positive otherwise
//                        settingStepSize = ( dPotLeg >= ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
//                        ( signed )( ( signed )( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )targetLevel ) :
//                        ( signed )( ( signed )targetLevel - ( signed )( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
//                    }
                }

                if( !thisIsTheMSBPass && ( signed )( ( settingStepSize < 0 ) ?  dPotSettings[ lSBdPotIndexThisLeg ] : MAX_DPOT_SETTG - dPotSettings[ lSBdPotIndexThisLeg ] ) < abs( settingStepSize ) )
                {
                        theNewSettingStepSizeInLSBUnits();
//                    settingStepSize = ( settingStepSize < 0 ) ? \
//                    0 - dPotSettings[ lSBdPotIndexThisLeg ] : \
//                    dPotSettings[ lSBdPotIndexThisLeg ];
                }

                startLevel = endLevel;
                if( thisIsTheMSBPass && !( settingStepSize / ( signed )DPOT_RATIO ) )/*need to advance to LSB level*/ break;
                offsetMSBdPotOrGroupValueUsingIndicesOnly( thisIsTheMSBPass ? firstMSBindexThisLeg : lSBdPotIndexThisLeg, ( thisIsTheMSBPass ) ? ( settingStepSize / ( signed )DPOT_RATIO ) : settingStepSize ); //Force correct polarity  TODO fix so polarity is correct without this extra force
                if( !thisIsTheMSBPass || readAndPlotInEachLap ) 
                {
                    readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE ); //
                    endLevel = masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
                    Serial.print( F( "> new value this leg=<" ) );
                    Serial.print( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
                    Serial.print( F( "> endLevel=<" ) );
                    Serial.print( endLevel );
                    Serial.print( F( "> " ) );
                }
                else
                    endLevel = bestOfFour( dPotLeg );

                if( endLevel == targetLevel ) break;
//                newStepSize = ;//theNewSettingStepSizeInLSBUnits(); We have preliminarily set things up to need an intermediate variable newStepSize.  Now to fix that

/*
                ( signed )( ( ( signed )targetLevel - ( signed )endLevel ) * settingStepSize ) / ( signed )( ( signed )endLevel - ( signed )startLevel );
*/
/*
                    ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                        ( ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevelSignal[ ) / -2 ) : 
                        ( ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevelSignal[ ) / ( signed )2 );
*/
//                Serial.print( F( "> Line <1211> initial new settingStepSize=<" ) );
//                Serial.print( newStepSize );
                oldStepSizeDivdBy6 = abs( ( signed )settingStepSize / ( signed )6 );
                theNewSettingStepSizeInLSBUnits();
                if( oldStepSizeDivdBy6 >  abs( ( signed )settingStepSize ) ) //abs( newStepSize ) ) //Ex.: first pass step size = 4, next pass step size is 0 but target voltage not reached
                {
                    if( !settingStepSize )
                    {
                        firstPass = false;
                    }
                    settingStepSize = max( 1, oldStepSizeDivdBy6 ); //but inact an additional fix to ensure step polarity is appropriate and allow that 1
                    if( ( ( targetLevel > endLevel ) && ( settingStepSize > 0 ) ) || ( ( targetLevel < endLevel ) && ( settingStepSize < 0 ) ) )
                        settingStepSize = 0 - settingStepSize;
                }
                Serial.print( F( "> Line <1331> new settingStepSize=<" ) );
                Serial.print( settingStepSize );
                Serial.print( F( ">" ) );
                if( !settingStepSize )       //
                    break;               //  Why are we using an intermediate variable? Probably to allow a second calculation on the value being used for :::: purpose of knowing effect on stepsPerLevelUnit so that we could check to ensure > old ( stepsize / 6 )
                if( useOpposingLegLevelAsTargetLevel && ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) )
                    targetLevel = bestGuessAnalogInputReading( dPotLeg + ( ( dPotLeg % 2 ) ? -1 : 1 ), MOST_ACCURATE );
            }  while( endLevel != targetLevel );
            if( !thisIsTheMSBPass ) break; //this is the second time outside first do loop
            thisIsTheMSBPass = false;
            Serial.print( F( "Changing to LSB steps." ) );
            readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE ); //delay some time to settle and take another reading for highest accuracy's sake
            if( useOpposingLegLevelAsTargetLevel && ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) )
            {
                targetLevel = masterReadingsArray[ dPotLeg + ( ( dPotLeg % 2 ) ? -1 : 1 ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
                Serial.print( F( "> Line <1239> adjusted targetLevel=<" ) );
                Serial.print( targetLevel );
                Serial.print( F( "> " ) );
            }
        }while( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) != targetLevel );

//Definition of oscillating: an invalid stepsize has been calculated or endLevel is not approaching targetLevel and !firstPass
        Serial.print( F( "> Line <1210> dPotLeg=<" ) );
        Serial.print( dPotLeg );
        Serial.print( F( "> Line <1212> incomingInboardAnalogLevel=<" ) );
        Serial.print( incomingInboardAnalogLevelSignal[ dPotLeg ] );
        Serial.print( F( "Line <1214> targetLevel=<" ) );
        Serial.print( targetLevel );
        Serial.print( F( "> Line <1216> startLevel=<" ) );
        Serial.print( startLevel );
        Serial.print( F( "> Line <1218> endLevel=<" ) );
        Serial.print( endLevel );
        Serial.print( F( "> Line <1220> newStepSize=<" ) );
        Serial.print( newStepSize );
        Serial.print( F( "> Line <1222> settingStepSize=<" ) );
        Serial.print( settingStepSize );
        Serial.print( F( "> legLSBsettingUnitsTimes64PerAnalogInputUnit[ dPotLeg ]=<" ) );
        referenceLegLevelFromLastSettingIt[ dPotLeg / 2 /*equates to bridge index from either leg index*/ ] = ( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) == COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ? REFERENCE_LEG_LEVEL_IS_OPTIMAL : ( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ? \
        REFERENCE_LEG_LEVEL_IS_HIGH : REFERENCE_LEG_LEVEL_IS_LOW;
        return ( originalDirectionToTargetLevel ? !( targetLevel > bestGuessAnalogInputReading( dPotLeg, MOST_ACCURATE ) ) : !( targetLevel < bestGuessAnalogInputReading( dPotLeg, MOST_ACCURATE ) ) );
    }

    int32_t oneReadingFromThisOutboardADC( uint8_t );
    bool stepAdjustDPotsForThisLeg( bool = TAKE_LEG_VOLTAGE_DOWN, bool = false ); //default direction will be positive
    #if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) )
    bool highestLevelDifferentialBridgeSetpointing( uint8_t OutboardADCindex = whichBridgeOrOutboardADCindex, uint8_t limit = 200/*This value is arbitrary right now*/ )
    {
        counterForTraceOutOfRangeTooLong[ OutboardADCindex ] == 0;
      //Need to insert bounds checking for if signal leg level has not attained very near to reference leg level
      //If midpoint is overshot, stops as if we achieved it
        while( oneReadingFromThisOutboardADC( OutboardADCindex ) > HALF_HEIGHT_OF_A_PLOT_LINESPACE ) //This cannot work for setting the reference leg b/c the signal leg may be out of range!
        {
            if( counterForTraceOutOfRangeTooLong[ OutboardADCindex ]++ > limit ) break; //Limited to prevent endless looping here
            stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN );
            Serial.print( F( "Line <1539>" ) );
            readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
        }
        while( oneReadingFromThisOutboardADC( OutboardADCindex ) < HALF_HEIGHT_OF_A_PLOT_LINESPACE )
        {
            if( counterForTraceOutOfRangeTooLong[ OutboardADCindex ]++ > limit ) break; //Limited to prevent endless looping here
            stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP );
            Serial.print( F( "Line <1401>" ) );
            readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
        }
        if( counterForTraceOutOfRangeTooLong[ OutboardADCindex ] > limit ) 
            return false;
        counterForTraceOutOfRangeTooLong[ OutboardADCindex ] == 0;
    }
    #endif

    #define JUST_QUERYING_WHETHER_SETTINGS_ARE_MAXED_OUT true
    bool stepAdjustDPotsForThisLeg( bool voltsUp, bool justQueryingWhetherSettingsAreMaxedOut ) //default direction will be positive
    { // This returns answer to query or effectively increments or decrements LSB digipot setting just once and returns whether direction to targetLevel stayed the same
    //return false if still needs to take in the same direction
      Serial.print( F( "Going " ) );
      if( voltsUp )
        Serial.print( F( "up" ) );
      else
        Serial.print( F( "down" ) );
      Serial.print( F( " in stepAdjustDPotsForThisLeg=<" ) );
      Serial.print( dPotLeg );
      Serial.print( F( "> targetLevel=<" ) );
      Serial.print( targetLevel );
      Serial.print( F( "> lSBdPotIndexThisLeg=<" ) );
      Serial.print( lSBdPotIndexThisLeg );
      Serial.print( F( "> MSBpotPin=<" ) );
      Serial.print( dPotPins[ firstMSBindexThisLeg ] );
      Serial.print( F( "> DPOTS_PER_LM334_LEG=<" ) );
      Serial.print( DPOTS_PER_LM334_LEG );
        if( dPotSettings[ lSBdPotIndexThisLeg ] > MAX_DPOT_SETTG )
        { //This is an invalid condition - put the setting at half scale
            writeSettingToAsingleDPot( lSBdPotIndexThisLeg, ( uint16_t )( MAX_DPOT_SETTG >> 1 ) ); 
          return false;
        }
        uint8_t oneAboveLastDPotIndexThisLeg = lSBdPotIndexThisLeg + dPotsPerThisLeg;
      if( justQueryingWhetherSettingsAreMaxedOut )
      { //returning false means failure of digipot settings that they are either maxed high or minimized zeroes whichever one was queried
        for( uint8_t dPotIndexThisLeg = lSBdPotIndexThisLeg; dPotIndexThisLeg < oneAboveLastDPotIndexThisLeg; dPotIndexThisLeg++ )
          if( dPotSettings[ dPotIndexThisLeg ] != dPotSettings[ lSBdPotIndexThisLeg ] ) return true;
      }
      if( analogPinArray )
      {
        Serial.print( F( "> dPotLeg=<" ) );
        Serial.print( dPotLeg );
      }
      Serial.print( F( ">" ) );
      //The following construct acts whether justQuerying... or not
      if( voltsUp ) //This means querying whether the settings are maxed high and the voltage will be minimium low
      {
        if( ( dPotSettings[ lSBdPotIndexThisLeg ] == 0 ) && ( MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) == 0 ) )
          return false;
      }
      else
      {
        Serial.print( F( "Line <1066> " ) );
        if( ( dPotSettings[ lSBdPotIndexThisLeg ] >= MAX_DPOT_SETTG ) && ( MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg ) == 0 ) )
          return false;
      }
      if( justQueryingWhetherSettingsAreMaxedOut ) return true;
    #ifdef DEBUG
      Serial.print( F( " on " ) );
      Serial.print( firstMSBindexThisLeg );
    #endif
      //        Serial.print( F( " going " ) );
      //        Serial.print( voltsUp ? "up ": "down ");
    #ifdef DEBUG
      Serial.println();
    #endif
      Serial.print( F( "Line <1097> " ) );
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        for( uint8_t dPotIndexThisLeg = lSBdPotIndexThisLeg; dPotIndexThisLeg < oneAboveLastDPotIndexThisLeg; dPotIndexThisLeg++ )
      {
        Serial.print( F( " Entering dPotSettings[" ) );
        Serial.print( dPotPins[ dPotIndexThisLeg ] );
        Serial.print( F( "]=<" ) );
        Serial.print( dPotSettings[ dPotIndexThisLeg ] );
        Serial.print( F( ">" ) );
      }
    #endif

    if( dPotsPerThisLeg > 1 )
    {
        if( voltsUp ) //Positive direction == true
        { //being told to decrement so the voltage goes up and we already know we have margin somewhere for one step
            Serial.print( F( " Entered with voltsUp as true " ) ); //Was hoping
            if( ( int16_t )dPotSettings[ lSBdPotIndexThisLeg ] == 0 ) //This catches dPotSettings[ lSBdPotIndexThisLeg ] having or about to have a value lower than 0.  So we cycle it up
            { 
                writeSettingToAsingleDPot( lSBdPotIndexThisLeg, DPOT_RATIO - 1 ); //We do it this way so we normally only deal with a single carry or borrow
                setMSBdPotOrGroupValueUsingIndicesOnly( firstMSBindexThisLeg, MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) - 1 );
            }
            else
                writeSettingToAsingleDPot( lSBdPotIndexThisLeg, dPotSettings[ lSBdPotIndexThisLeg ] - 1 );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
            Serial.print( F( " called setMSBdPotOrGroupValueUsingIndicesOnly on MID and MSB DPotSettings[" ) );
#endif
        }
        else
        {
            Serial.print( F( " Entered with voltsUp as false " ) );
//Being told to increment so the voltage goes down
            if( ( int16_t )( dPotSettings[ lSBdPotIndexThisLeg ] == MAX_DPOT_SETTG ) && ( MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg ) > 0 ) )
            {
                writeSettingToAsingleDPot( lSBdPotIndexThisLeg, ( uint16_t )( MAX_DPOT_SETTG + 1 - DPOT_RATIO ) ); //We do it this way so we normally only deal with a single carry or borrow
                setMSBdPotOrGroupValueUsingIndicesOnly( firstMSBindexThisLeg, MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) + 1 );
            }
            else
            {
                writeSettingToAsingleDPot( lSBdPotIndexThisLeg, ( uint16_t )( dPotSettings[ lSBdPotIndexThisLeg ] + 1 ) );
            }
        }
    }
    else
    {
        if( voltsUp ) //Positive direction == true
        {
            dPotSettings[ lSBdPotIndexThisLeg ] -= ( dPotSettings[ lSBdPotIndexThisLeg ] == 0 ) ? 0 : 1;
            writeSettingToAsingleDPot( lSBdPotIndexThisLeg, dPotSettings[ lSBdPotIndexThisLeg ] );
        }
        else
        {
            dPotSettings[ lSBdPotIndexThisLeg ] += ( dPotSettings[ lSBdPotIndexThisLeg ] == MAX_DPOT_SETTG ) ? 0 : 1;
            writeSettingToAsingleDPot( lSBdPotIndexThisLeg, dPotSettings[ lSBdPotIndexThisLeg ] );
        }
    }
    
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
                Serial.print( F( " MSB group set to <" ) );
                Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG ( dPotLeg ));
                Serial.print( F( ">, LSB set pos to <" ) );
                Serial.print( dPotSettings[ lSBdPotIndexThisLeg ] );
                Serial.print( F( ">." ) );
    #endif//return false if still needs to take in the same direction
                Serial.print( F( "Line <1519> targetLevel=<" ) );
                Serial.print( targetLevel );
                Serial.print( F( ">." ) );
    if( !targetLevel ) return true;
        Serial.print( F( "Line <1526>" ) );
        return ( voltsUp ? ( bestGuessAnalogInputReading( dPotLeg, MOST_ACCURATE ) >= targetLevel ) : ( bestGuessAnalogInputReading( dPotLeg, MOST_ACCURATE ) <= targetLevel ) );
    } //End of bool stepAdjustDPotsForThisLeg()
    
    bool setDPotLegMidPoint( uint8_t/* bridge*/, bool /*thisIsReferenceLegOfBridge*/, bool = !READ_AND_PLOT_IN_EACH_LAP, /* = !READ_AND_PLOT_IN_EACH_LAP,*/ bool /*useOpposingLegLevelAsTargetLevel*/ = !USE_OPPOSING_LEGS_LEVEL_AS_TARGET_LEVEL ); //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.
    bool adjustBridgeOutputPositive( uint8_t bridge = whichBridgeOrOutboardADCindex ) //TODO: make this function faster through predictive step sizes
    { //If all pots are maxed (positive leg to positive and negative leg to negative) return false
/***********************************************************************
THIS WHOLE ALGORITHM BELOW NEEDS TO BE REDONE: 
If needing to raise bridge voltage, -
-lower reference leg first if it is greater than CM
until it either reaches CM or bridge becomes balanced
if bridge became balanced, return true
if reference leg is at or reached CM, raise signal leg until it either
rises above CM or bridge becomes balanced.
if bridge became balanced, return true
if is above CM, continue alterating raise signal and lower reference until
either bridge becomes balanced or signal leg is maxed and reference leg is minned
************************************************************************/
/*
We need to come up with a state variable to know whether the reference leg level is optimal, supra-optimal or sub-optimal.
*/
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      while( !Serial );
      Serial.print( F( " Entered adjustBridgeOutputPositive " ) );
      Serial.print( F( " EABOP " ) );
      Serial.print( F( "with bridge=<" ) );
      Serial.print( bridge );
      Serial.print( F( ">." ) );
    #endif
/*
    lower reference leg voltage if it is higher than commonmode... level until it reaches commonmode...,
    during the routine of lowering it, set the state of the level to supra-optimal until it reaches optimal level
    then raise signal leg voltage until can't raise it any more,
    then resume to lower reference leg until can't lower it any more
*/

  //?to read values from analog pins: use IndexInlinespaceParametersArray and add one (reference) or not (signal)?
  // If all are maxed out, return false to signify reference leg maxed negative, signal leg maxed positive
    if( masterReadingsArray[ whatIsSignalLegThisBridge( bridge) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
    { //set reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG    
        configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
      if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP, JUST_QUERYING_WHETHER_SETTINGS_ARE_MAXED_OUT ) ) //This only CHECKS to see if there is any settings headroom to take the bridge up signal leg first.  Does this do a recursive call?  That would be horrible!
      {
        Serial.print( F( "Line <1581>." ) );
        configureForReferenceLegWithBridgeIndex( bridge );
        Serial.print( F( "Line <1583>." ) );
        if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN, JUST_QUERYING_WHETHER_SETTINGS_ARE_MAXED_OUT ) ) //This only CHECKS to see if there is any settings headroom to take the bridge up reference leg now.  Does this do a recursive call?  That would be horrible!
        { 
            Serial.print( F( "Line <1583>." ) );
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
        Serial.print( F( "Line <1411> targetLevel=<" ) );
      }
        Serial.print( F( "Line <1413>. Settings not maxed out and will allow raising the bridge output level." ) );
      //int16_t bestOfFour( uint8_t dPotLegOrIndexedInboardAnalogInput = 0 )
      if( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES )
        { //These are all the bridged so there is a reference leg in these
            configureForReferenceLegWithBridgeIndex( bridge );
    
    //bool setDPotLegMidPoint( uint8_t bridge, bool thisIsReferenceLegOfBridge, bool readAndPlotInEachLap, /* = !READ_AND_PLOT_IN_EACH_LAP,*/ bool useOpposingLegLevelAsTargetLevel = !USE_OPPOSING_LEGS_LEVEL_AS_TARGET_LEVEL ) //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.
    //#error read the following and finish development with it in the interest of coming up with a state variable to know whether the reference leg level is optimal, supra-optimal or sub-optimal.
    //Need to account for why wouldn't reference leg be able to be lowered to optimal.  It will be able to be but the question is 
    //    whether the signal leg can be raised to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG - BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0
    
    //    Essentially, manipulate signal level while reference level sits at COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG 
    //    until it maxes out, then resort to manipulating reference level with the signal level maxed either high or low, so when bridge out needs to
    //    go up check if referenceLegLevelFromLastSettingIt[ bridge ] == REFERENCE_LEG_LEVEL_IS_OPTIMAL
            incomingInboardAnalogLevelSignal[ dPotLeg ] = bestOfFour( dPotLeg );
    
            if( !setDPotLegMidPoint( bridge, WORK_ON_THE_REFERENCE_LEG ) && ( incomingInboardAnalogLevelSignal[ dPotLeg + 1 ] /*this is still reference leg*/ > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG  ) )
                referenceLegLevelFromLastSettingIt[ bridge ] = REFERENCE_LEG_LEVEL_IS_HIGH;
                if( ( bestOfFour( dPotLeg + 1 ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 < incomingInboardAnalogLevelSignal[ dPotLeg ] ) )
                {
                    return false;
                }
        }
    } //Reference leg is now set to normal

    configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
    incomingInboardAnalogLevelSignal[ dPotLeg ] = bestOfFour( dPotLeg );
    targetLevel = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG; 
    //masterReadingsArray[ whatIsSignalLegThisBridge( bridge) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE
    do
  {
                Serial.print( F( " raising the signal leg voltage since the reference leg voltage is optimal " ) );
                Serial.print( F( " ltslsstrlvio " ) );
                Serial.flush();

         if( bestOfFour( dPotLeg ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
         {
           if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP ) )
            {
                if( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES )                
                    break; 
                else return false; //these bridges are actually unbridged legs so they have no reference leg to keep trying with
            }
         }
         else
         {
//            perfectlyBalanceBridgeByTweakingSignalLeg();
             break;
         }

        #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
            readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
        #endif
    } while( dPotLegSetpointing() );

        configureForReferenceLegWithBridgeIndex( bridge );
      while(  bestOfFour( dPotLeg + 1 ) > bestOfFour( dPotLeg ) )
      {
                    Serial.print( F( " lowering the reference leg voltage since the signal leg voltage is maxed out " ) );
                    Serial.print( F( " rtrlsstslsaml " ) );
                    Serial.flush();
        if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN ) )
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

    bool adjustBridgeOutput( uint8_t bridge )
    { return true;//This is not debugged yet, so until later completion of debugging it does nothing
/**********************************************************************************
Original thought was something like:
If needing to lower bridge voltage, -
-raise reference leg first if it is less than CM
until it either reaches CM or bridge becomes balanced
if bridge became balanced, return true
if reference leg is at or reached CM, lower signal leg until it either
goes below CM or bridge becomes balanced.
if bridge became balanced, return true
if is lower than CM, continue alterating lower signal and raise reference until
either bridge becomes balanced or signal leg is minned and reference leg is maxed
First, however, we just need to get things working as best we can with signal leg control only
**********************************************************************************/
/*        if( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES )
        {
            Serial.print( F( "Line<1827>" ) );
             while( ( !needingToLower ? \
( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) : ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ) && \
( !needingToLower ? ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading < masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading ) : 
( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading > masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading ) ) )
             {
                Serial.print( F( "Line<1833>( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + <1> ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE )=<" ) );
                Serial.print( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
                Serial.print( F( "> ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG=<" ) );
                Serial.print( ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );
                Serial.print( F( "> analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) + <1> ]=<" ) );
                Serial.print( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) + 1 ] );
                Serial.print( F( ">offset=<" ) );
                Serial.print( ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) / \
                analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) + 1 ] );
                Serial.print( F( ">." ) );
                int16_t calculatedOffset = ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) / \
( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) + 1 ] / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) );
                if( !calculatedOffset ) break;
                offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge ), calculatedOffset );
                readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
             }
        }
        Serial.print( F( "Line<1843>" ) );
         while( ( !needingToLower ? \
( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) : ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ) && \
( !needingToLower ? ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading < masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading ) : 
( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading > masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading ) ) )
         {
            Serial.print( F( "Line<1833>( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + <1> ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE )=<" ) );
            Serial.print( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
            Serial.print( F( "> ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG=<" ) );
            Serial.print( ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );
            Serial.print( F( "> analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) + <1> ]=<" ) );
            Serial.print( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) + 1 ] );
            Serial.print( F( ">offset=<" ) );
            Serial.print( ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) / \
            analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) + 1 ] );
            Serial.print( F( ">." ) );
            int16_t calculatedOffset = ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) / \
( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) + 1 ] / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) );
            if( !calculatedOffset ) break;
            offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge ), calculatedOffset );
            readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
         }
         while( !needingToLower ? \
( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading < masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading ) : 
( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading > masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading ) )
         {
            Serial.print( F( "Line<1833>( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + <1> ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE )=<" ) );
            Serial.print( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
            Serial.print( F( "> ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG=<" ) );
            Serial.print( ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );
            Serial.print( F( "> legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( bridge ) ]=<" ) );
            Serial.print( legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( bridge ) ] );
            Serial.print( F( ">offset=<" ) );
            Serial.print( ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) / \
            legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( bridge ) ] );
            Serial.print( F( ">." ) );
            int16_t calculatedOffset = ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) * \
( legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( bridge ) ] / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) );
            if( !calculatedOffset ) break;
            offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsSignalLSBdPotIndexThisBridge( bridge ), calculatedOffset );
            readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
         } */
//         while( !needingToLower ? \
//( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading < masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading ) : 
//( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading > masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading ) )
        int16_t calculatedOffset;
         do{
            Serial.print( F( "Line<1896>( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + <1> ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE )=<" ) );
            Serial.print( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
            Serial.print( F( "> ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG=<" ) );
            Serial.print( ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );
            Serial.print( F( "> analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) ]=<" ) );
            Serial.print( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) ] );
            Serial.print( F( ">offset=<" ) );
            Serial.print( ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) / \
            analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) ] );
            Serial.print( F( ">." ) );
            calculatedOffset = ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) / \
( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) ] / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) );
            if( !calculatedOffset ) break;
            offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstSignalMSBindexThisBridge( bridge ), calculatedOffset );
            readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
//The problem with this loop is that it needs to guarantee the end level is close enough that reasonably low LSB adjustment can subsequently be used  to finish the job
         }while( calculatedOffset );
        bool needingToLower = ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading < masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading );
//         while( !needingToLower ? \
//( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading < masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading ) : 
//( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading > masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading ) )
        do {
            Serial.print( F( "Line<1918>( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + <1> ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE )=<" ) );
            Serial.print( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
            Serial.print( F( "> ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG=<" ) );
            Serial.print( ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );
            Serial.print( F( "> legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( bridge ) ]=<" ) );
            Serial.print( legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( bridge ) ] );
            Serial.print( F( ">offset=<" ) );
            Serial.print( ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) / \
            legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( bridge ) ] );
            Serial.print( F( ">." ) );
            calculatedOffset = ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) / \
( legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( bridge ) ] / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) );
            if( !calculatedOffset ) break;
            offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsSignalLSBdPotIndexThisBridge( bridge ), calculatedOffset );
            readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
         }while( calculatedOffset );
/*Then we would have more here relative to the reference leg when signal leg control was insufficient*/
    }
        
    bool adjustBridgeOutputNegative( uint8_t bridge, bool needingToLower = TAKE_LEG_VOLTAGE_DOWN )
    { //If all pots are maxed (positive leg to negative and negative leg to positive) return false
/**********************************************************************************
THIS WHOLE ALGORITHM BELOW NEEDS TO BE REDONE: 
If needing to lower bridge voltage, -
-raise reference leg first if it is less than CM
until it either reaches CM or bridge becomes balanced
if bridge became balanced, return true
if reference leg is at or reached CM, lower signal leg until it either
goes below CM or bridge becomes balanced.
if bridge became balanced, return true
if is lower than CM, continue alterating lower signal and raise reference until
either bridge becomes balanced or signal leg is minned and reference leg is maxed
**********************************************************************************/
      configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      while( !Serial );
      Serial.print( F( " Entered adjustBridgeOutputNegative " ) );
      Serial.print( F( " EABON " ) );
      Serial.print( F( "with bridge=" ) );
      Serial.print( bridge );
      Serial.print( F( ",." ) );
    #endif
      if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN, JUST_QUERYING_WHETHER_SETTINGS_ARE_MAXED_OUT ) )
      {
        configureForReferenceLegWithBridgeIndex( bridge );
           if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP, JUST_QUERYING_WHETHER_SETTINGS_ARE_MAXED_OUT ) )
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
      }
      if( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES )
        {
                configureForReferenceLegWithBridgeIndex( bridge );
    
              while( bestOfFour( dPotLeg ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
              {
                                    Serial.print( F( " making sure reference voltage is not too high " ) );
                        if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP ) ) break;
            #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
                readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
            #endif
              }
              while( bestOfFour( dPotLeg ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
              {
                            Serial.print( F( " raising the reference leg since that voltage is lower than optimal " ) );
                            Serial.print( F( " rtrlsstvilto " ) );
                            Serial.flush();
                if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_UP ) ) break;
            #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
                readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
            #endif
              }
        }
     configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
     while( bestOfFour( dPotLeg ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
      {
            Serial.print( F( " lowering the signal leg voltage since the reference leg voltage is optimal " ) );
            Serial.print( F( " ltslsstrlvio " ) );
            Serial.flush();
            if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN ) )
            {
                if( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES )                
                    break; 
                else return false; //these bridges are actually unbridged legs so they have no reference leg to keep trying with
            }
    #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
        readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
    #endif
      } //must determine here if success b/c leg may be not bridged
     configureForReferenceLegWithBridgeIndex( bridge );
      while( oneReadingFromThisOutboardADC( bridge ) > ( HALF_HEIGHT_OF_A_PLOT_LINESPACE ) )
      {
                    Serial.print( F( " lowering the reference leg voltage since the signal leg settings are maxed low " ) );
                    Serial.print( F( " rtrlsstslsaml " ) );
                    Serial.flush();
        if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN ) )
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
#endif //Ending section for DPots legs more than zero

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
  for( uint8_t linespaceParametersIndex = 0; linespaceParametersIndex < NUMBER_OF_LINESPACES; linespaceParametersIndex++ )
  {
#ifdef DEBUG
    while( !Serial ) ;
    Serial.print( F( "linespaceParametersIndex =" ) );
    Serial.print( linespaceParametersIndex );
    Serial.print( F( ", LastSignalPinPlotPoint =" ) );
    Serial.print( linespaceParameters[ linespaceParametersIndex ].LastSignalPinPlotPoint );
    Serial.print( F( ", ZeroOfThisPlotLinespace =" ) );
    Serial.print( linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace );
    Serial.print( F( ", INDEX_OF_INBOARDS_NOT_SUPERIMPOSED =" ) );
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
      Serial.print( F( ", LastReferencePinPlotPointOrLastMagnifiedPlotPoint =" ) );
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
{
#ifdef DEBUG
  while( !Serial ) ;
  Serial.println( F( "Entering plotTimingLineGoingUp" ) );
#endif
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
//The next line quarantined places the outboard ADCs at the bottom of the screen, which I felt was not the best way.  It is closely related to other lines that must be quarantined also
//  for( uint8_t linespaceParametersIndex = NUMBER_OF_LINESPACES - 1; linespaceParametersIndex != 255; linespaceParametersIndex-- )
  for( uint8_t linespaceParametersIndex = 0; linespaceParametersIndex < NUMBER_OF_LINESPACES; linespaceParametersIndex++ )
  {
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
    Serial.print( F( "Line<826> linespaceParametersIndex - 1 =" ) );
    Serial.println( linespaceParametersIndex - 1 );
#endif
    //        if( tracesAlreadyInitializedToValidReadings ) replotLastValuesForAllTraces( tracesAlreadyInitializedToValidReadings );
    //        else Serial.println();
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println();
    Serial.print( F( "Line<832>, linespaceParametersIndex - 1 =" ) );
    Serial.println( linespaceParametersIndex - 1 );
#endif
  }
#ifdef DEBUG
  while( !Serial ) ;
  Serial.println( F( "Leaving plotTimingLineGoingUp" ) );
#endif
}

int16_t bestOfFour( uint8_t dPotLegOrIndexedInboardAnalogInput = 0 ) //returns an INBOARD Analog Input pin reading, dPotLegOrIndexedInboardAnalogInput is also equal to bridge leg indices
{ //remove from consideration the max and min, then return avg of remaining two  //Re-suse some variables not otherwise in use right now
    uint16_t value1, value2, value3, value4;
    do
    {
#ifdef DEBUG
    Serial.print( F( "Line <1932>, collecting analog readings from A-pin<" ) );
    Serial.print( *( analogPinArray + dPotLegOrIndexedInboardAnalogInput ) );
    Serial.print( F( "> " ) );
#endif
//        delay( 2 );
        value1 = analogRead( analogPinArray ? ( *( analogPinArray + dPotLegOrIndexedInboardAnalogInput ) ) : dPotLegOrIndexedInboardAnalogInput );
//        delay( 12 );
        value2 = analogRead( analogPinArray ? ( *( analogPinArray + dPotLegOrIndexedInboardAnalogInput ) ) : dPotLegOrIndexedInboardAnalogInput );
//        delay( 6 );
        value3 = analogRead( analogPinArray ? ( *( analogPinArray + dPotLegOrIndexedInboardAnalogInput ) ) : dPotLegOrIndexedInboardAnalogInput );
//        delay( 20 );
        value4 = analogRead( analogPinArray ? ( *( analogPinArray + dPotLegOrIndexedInboardAnalogInput ) ) : dPotLegOrIndexedInboardAnalogInput );
    }while( !( ( ( value1 == value2 ) && ( value1 == value3 ) ) || \
    ( ( value1 == value3 ) && ( value1 == value4 ) ) || \
    ( ( value2 == value3 ) && ( value2 == value4 ) ) || \
    ( ( value1 == value2 ) && ( value1 == value4 ) ) ) );//( finalValue != value ) && ( finalValue != value1 ) && ( finalValue != value2 ) && ( finalValue != value3 ) );
    
  return ( ( value1 + value2 + value3 + value4 - ( max( max( max( value1, value2 ), value3 ), value4 ) + min( min( min( value1, value2 ), value3 ), value4 ) ) ) >> 1 );
}

#if ( ( defined DPOT_LEGS ) && ( DPOT_LEGS > 0 ) )
    int16_t bestGuessAnalogInputReading( uint8_t dPotLegOrIndexedInboardAnalogInput, bool mostAccurate, bool usingGlobalValueOfDPotLegForAnalogPinArrayIndex )
    {
        dPotLegOrIndexedInboardAnalogInput = ( ( dPotLegOrIndexedInboardAnalogInput > 0 ) || ( !usingGlobalValueOfDPotLegForAnalogPinArrayIndex ) ) ? dPotLegOrIndexedInboardAnalogInput : dPotLeg;
        uint16_t value;
        unsigned long runningTotal = 0;
        uint8_t times = 0;
        for( ; times < 4; times++ )
        {
            value = bestOfFour( dPotLegOrIndexedInboardAnalogInput );
            runningTotal += value;
        }
        if( mostAccurate )
        {
            for( ; times < 8; times++ )
            {
                value = bestOfFour( dPotLegOrIndexedInboardAnalogInput );
                runningTotal += value;
            }
        }
        else if( ( ( runningTotal / times ) * times ) > runningTotal + ( times >> 1 ) ) //do the truncatings make a runningTotal recreation too high?
            return ( runningTotal / times ) - 1;
        else if( ( ( runningTotal / times ) * times ) < runningTotal - ( ( times >> 1 ) + 1 ) ) //do the truncatings make a runningTotal recreation too low?
            return ( runningTotal / times ) + 1;
        return ( runningTotal / times );
    }

    bool setDPotLegMidPoint( uint8_t bridge, bool thisIsReferenceLegOfBridge, bool readAndPlotInEachLap, bool useOpposingLegLevelAsTargetLevel )
    {
//        uint16_t targetLevel; made to be global
        if( thisIsReferenceLegOfBridge ) 
        {
            configureForReferenceLegWithBridgeIndex( bridge );
        }
        else
        {
            configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
        }        
        targetLevel = \
        ( thisIsReferenceLegOfBridge \
        ? \
        ( useOpposingLegLevelAsTargetLevel \
        ? ( bestGuessAnalogInputReading( dPotLeg - 1, MOST_ACCURATE ) - BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 ) \
        : COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) \
        : \
        ( ( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( bestGuessAnalogInputReading( dPotLeg + 1, MOST_ACCURATE ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 ) : ( 1 << ( ANALOG_INPUT_BITS_OF_BOARD - 1 ) ) ) );

        incomingInboardAnalogLevelSignal[ dPotLeg ] = bestOfFour( dPotLeg ); targetLevel = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG; 

        dPotLegSetpointing( READ_AND_PLOT_IN_EACH_LAP, useOpposingLegLevelAsTargetLevel );

        return true;
    }
#endif
/*
  global vars needed here b/c their value is shared so much between functions
*/
static uint32_t tracespaceToSkipWhenRepositioning, negativeTracespaceToSkipWhenRepositioning;
/*
  #if ( INBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings linespaceParametersInboard[ INBOARDS_PLOTTED ];
  #endif
  #if defined LM334_BRIDGES && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( INBOARDS_PLOTTED < LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE )
    previous_readings_only DigipotLeg[ ( LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ) - INBOARDS_PLOTTED ];
  #endif
  #if ( OUTBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings linespaceParametersOutboard[ OUTBOARDS_PLOTTED ];
  #endif
  How are LastSignalPinPlotPoint and PreviousUnmagnifiedReading differently used?
  linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
*/
static bool duringDPotAdjusting = false;
void plotTheNormalAndMagnifiedSignals( uint8_t masterReadingsArrayIndex ) //linespaceParameters[] has Two indices/elements per every non-magnified trace ifdef MAGNIFICATION_FACTOR, otherwise one per
{
#ifdef DEBUG
  while( !Serial );
  Serial.print( F( "Line <1319> masterReadingsArrayIndex=<" ) );
  Serial.print( masterReadingsArrayIndex );
  Serial.print( F( ">." ) );
#endif
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  Serial.print( F( "unmagnified value:" ) );
#endif
  Serial.print( F( " " ) );
  if( ( masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) && !( masterReadingsArrayIndex % 2 ) ) //This is the case for those ADCs that have just had their
    // current readings refreshed immediately prior to the
    // execution of this function, so use the stored readings.
    //Note also that the standard linespace is designed large
    // enough to always accommodate plotting the full unmagnified reading
  { //this case and the case of masterReadingsArrayIndex < INDEX_OF_OUTBOARDS but not including the case of masterReadingsArrayIndex < INBOARDS_PLOTTED
    // needs to return some values
    linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one of pair
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " Unadjusted value=<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( ">, scaled to inboard analog input resolution:<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
    Serial.print( F( ">" ) );
#endif
#ifdef DEBUG
    Serial.println();
    Serial.print( F( "Line <1289> signal" ) );
#endif
#ifdef MAGNIFICATION_FACTOR
    goto AfterTheMagnifiedPlotted;
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
    Serial.print( F( ">, scaled to inboard analog input resolution:<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
    Serial.print( F( ">" ) );
#endif
#endif
#ifdef DEBUG
    Serial.println();
    Serial.println( F( "Line<1298> reference" ) );
#endif
#ifdef MAGNIFICATION_FACTOR
    Serial.print( F( " " ) );
    goto AfterTheMagnifiedPlotted; // B/c this range is superimposed traces, no magnified plot is indicated
#endif
  }
  /*
      else if( masterReadingsArrayIndex < INBOARDS_PLOTTED )
      {
          linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
          Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one
          #ifdef DEBUG
              Serial.println();
              Serial.println( F( "Line<1277> " ) );
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
    Serial.println( F( "Line<1285> " ) );
#endif
  }
#ifdef DEBUG
  Serial.print( F( "Line<1368> masterReadingsArrayIndex =" ) );
  Serial.print( masterReadingsArrayIndex );
  Serial.print( F( ", CurrentUnmagnifiedReading =" ) );
  Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
  Serial.print( F( ", IndexInlinespaceParametersArray =" ) );
  Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray );
  Serial.print( F( ", ZeroOfThisPlotLinespace =" ) );
  Serial.println( linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace );
#endif
  Serial.print( F( " " ) );
#ifdef MAGNIFICATION_FACTOR
  uint32_t thisPlotPoint;
  /*
    SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS will be one for every pair to superimpose on each other
    INBOARDS_PLOTTED are paired times SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS, then singled
    OUTBOARDS_PLOTTED is taken at face value
  */
#if defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
  if( masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) goto AfterTheMagnifiedPlotted; //if this is one of the two parallel traces, skip the magnified view
#endif

  //Next lines plot a magnified version.  First, MagnifyAdjustment is determined
  //Next we multiply the difference between PreviousUnmagnifiedReading and this one, and see if it would take the trace out of bounds
  //Derive the next plot point for the case of current CurrentUnmagnifiedReading being less than or equal to the last UnmagnifiedReading
    if( duringDPotAdjusting )
        thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint;
    else if( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading > masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading ) //new plot point is higher than previous
    {
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
        thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + ( ( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading ) * ( uint32_t )( ( analogRead( analogPinArray ? ( *( analogPinArray + POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) ) : dPotLegOrIndexedInboardAnalogInput ) >> ANALOG_INPUT_BITS_OF_BOARD ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#else
        thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + ( ( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#endif
        if( thisPlotPoint > HEIGHT_OF_A_PLOT_LINESPACE ) //new plot point is higher than upper limit
            thisPlotPoint = tracespaceToSkipWhenRepositioning;
    }
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR //Arduino only unless a dedicated ADS1115 is used
    else if( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * ( uint32_t )( ( analogRead( analogPinArray ? ( *( analogPinArray + POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) : dPotLegOrIndexedInboardAnalogInput ) >> ANALOG_INPUT_BITS_OF_BOARD ) * MAGNIFICATION_FACTOR ) > linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint )
#else
    else if( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * MAGNIFICATION_FACTOR > linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint )
#endif
        thisPlotPoint = negativeTracespaceToSkipWhenRepositioning;
    else
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
        thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint  - ( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * ( uint32_t )( ( analogRead( analogPinArray ? ( *( analogPinArray + POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) : dPotLegOrIndexedInboardAnalogInput ) ) >> ANALOG_INPUT_BITS_OF_BOARD ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
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
        Serial.println( F( "Line<1356> " ) );
        Serial.println();
#endif
AfterTheMagnifiedPlotted:
#endif
        masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
#ifdef DEBUG
        Serial.println();
#endif
#ifdef AUTO_BRIDGE_BALANCING
#ifdef MAGNIFICATION_FACTOR
        if( masterReadingsArrayIndex < INDEX_OF_OUTBOARDS ) return; /*TRY TO REMEMBER HOW I INTENDED TO USE THIS RETURN VALUE bestGuessAnalogInputReading( 1 + ( ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 - bestGuessAnalogInputReading( ( ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE ) );*/
#else
        if( masterReadingsArrayIndex >= INBOARDS_PLOTTED ) return;/*TRY TO REMEMBER HOW I INTENDED TO USE THIS RETURN VALUE bestGuessAnalogInputReading( 1 + ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 - bestGuessAnalogInputReading( ( ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE );*/
#endif
                    //bestGuessAnalogInputReading index argument is a bridge...which doesn't exist except with the outboard ADCs
#endif
        return;//only saving the reading, don't plot.  These are just LM334 non-plotted bridges
}

#if defined ( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ) || defined ( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC )
#define DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE 1
/*
 * 
 * NOTE: LINEARITY CHECKING IN SETUP() IS NOT COMPATIBLE WITH USING A NON-LSB DPOT FOR diagnostSquareWave() UNLESS YOU WANT TO RE-CODE FOR IT
 * 
 */
static bool potSquareWaveHighLevel = true;
static uint8_t diagnostSquareWavePlotCycleLoops = 0;
void diagnostSquareWave( void )
{ //Adjust active code to amplitude of diagnostSquareWave you need at the moment
    if( duringDPotAdjusting ) return;
//NOTE: LINEARITY CHECKING IN SETUP() IS NOT COMPATIBLE WITH USING A NON-LSB DPOT FOR THIS UNLESS YOU WANT TO RE-CODE FOR IT
    diagnostSquareWavePlotCycleLoops = ( diagnostSquareWavePlotCycleLoops + 1 ) % DIAGNOSTIC_SQUARE_WAVE_TIME_PERIOD;
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Line<2203>, diagnostSquareWavePlotCycleLoops =" ) );
    Serial.println( diagnostSquareWavePlotCycleLoops );
#endif
    if( !diagnostSquareWavePlotCycleLoops )
    {
    #ifdef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC
        offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsSignalLSBdPotIndexThisBridge( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ), \
        potSquareWaveHighLevel ? DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE : ( 0 - DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE ) ); 
    #endif

    #ifdef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC
        offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsReferenceLSBdPotIndexThisBridge255IfNone( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ), \
        potSquareWaveHighLevel ? ( 0 - DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE ) : DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE ); 
    #endif //trap the above if setting tries to go below zero.  goes down first diagnostSquareWave tick
      potSquareWaveHighLevel = !potSquareWaveHighLevel;
    }
}
#endif

//#ifdef AUTO_BRIDGE_BALANCING
//    static uint16_t counterForTraceOutOfRangeTooLong[ OUTBOARDS_PLOTTED ]; //This is to prevent infinite loop with AUTO_BRIDGE_BALANCING
//#endif

int32_t oneReadingFromThisOutboardADC( uint8_t whichOutboardADCindex )
{
#if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 15 )
  thisReadingTemp = ads.readADC_SingleEnded( whichOutboardADCindex );
  while( thisReadingTemp > HEIGHT_OF_A_PLOT_LINESPACE ) thisReadingTemp = ads.readADC_SingleEnded( whichOutboardADCindex );
  return thisReadingTemp;
#else
#ifdef DIFFERENTIAL
#if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 )
  return CONVERT_TWOS_COMP_TO_SINGLE_ENDED( ( whichOutboardADCindex == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HALF_HEIGHT_OF_A_PLOT_LINESPACE /*0x8000*/ );
#else
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_PGA_GAIN_FACTOR
    uint16_t gainWiperSetting = analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_PGA_GAIN_FACTOR ) >> ( ANALOG_INPUT_BITS_OF_BOARD - 3 );
    hx711.set_gain( ( gainWiperSetting < 3 ) ? 32 : ( ( gainWiperSetting < 7 ) ? 64 : 128 ) );
#endif
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

void readAndPlotFromAllADCsInAndOutboard( uint32_t timingLineLevel, bool duringSetup )
{
    for( uint8_t dpotIndex = lSBdPotIndexThisLeg; dpotIndex < lSBdPotIndexThisLeg + dPotsPerThisBridge; dpotIndex++)
    { //the limits are mixing bridge and leg limits b/c lSBdPotIndexThisLeg is referring to the reference leg FIXME
        Serial.print( F( " Line <2288> dpotIndex<" ) );
        Serial.print( dpotIndex );
        Serial.print( F( ">=<" ) );
        Serial.print( dPotSettings[ dpotIndex ] );
        Serial.print( F( ">, " ) );
    }
#if defined ( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ) || defined ( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC )
    diagnostSquareWave();
#endif
    for( uint8_t dpotIndex = lSBdPotIndexThisLeg; dpotIndex < lSBdPotIndexThisLeg + dPotsPerThisBridge; dpotIndex++)
    { //the limits are mixing bridge and leg limits b/c lSBdPotIndexThisLeg is referring to the reference leg FIXME
        Serial.print( F( " Line <2299> dpotIndex<" ) );
        Serial.print( dpotIndex );
        Serial.print( F( ">=<" ) );
        Serial.print( dPotSettings[ dpotIndex ] );
        Serial.print( F( ">, " ) );
    }
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
    //                    Serial.print( F( "analogPinArray =" ) );
    //                    Serial.println( (unsigned long)analogPinArray );
        Serial.print( F( "Line <2330>, collecting analog readings from A-pin<" ) );
        Serial.print( *( analogPinArray + inboardPinIndex ) );
        Serial.print( F( ">. " ) );
        if( inboardPinIndex == 0 )
        {
          Serial.print( F( ", SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE " ) );
          Serial.println( SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
        }
        else Serial.println();
#endif
#if ( SAMPLE_TIMES > 1 )
        uint32_t previousReading = analogRead( *( analogPinArray + inboardPinIndex ) );
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
            delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
#endif
    #if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
            delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
    #endif
#endif
        masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading = analogRead( *( analogPinArray + inboardPinIndex ) );
#if ( SAMPLE_TIMES > 1 )
//lastDirectionOfChangeInLevelFromPreviousReading is used to correct readings for a longer-term rising or dropping voltage: it gives a greater weight to the more recent previous reading
            int8_t lastDirectionOfChangeInLevelFromPreviousReading = ( previousReading > masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading ) ? -1 : ( previousReading < masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading ) ? 1 : 0 ;//values are -1, 0, 1
            masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading += previousReading;
#endif
#ifdef DEBUG
        while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        Serial.print( F( "Value was " ) );
        Serial.print( masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading );
#endif
#if ( SAMPLE_TIMES > 2 )
        for( uint8_t sampleTimes = 2; sampleTimes < SAMPLE_TIMES; sampleTimes++ )
        {
            uint32_t tmpReading;
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
            delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
#endif
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
            delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
#endif
#ifdef DEBUG
            Serial.print( F( "Line <2356>, collecting analog readings from A-pin<" ) );
            Serial.print( *( analogPinArray + inboardPinIndex ) );
            Serial.print( F( "> " ) );
#endif
/*
lastDirectionOfChangeInLevelFromPreviousReading = \
( previousReading < masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading ) ? \
-1 : ( previousReading > masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading ) ? \
1 : 0 ;
*/
            tmpReading = analogRead( *( analogPinArray + inboardPinIndex ) );
//Below: 
            if( !lastDirectionOfChangeInLevelFromPreviousReading || ( lastDirectionOfChangeInLevelFromPreviousReading && \
            ( ( tmpReading < previousReading ) && ( lastDirectionOfChangeInLevelFromPreviousReading < 0 ) ) || ( ( tmpReading > previousReading ) && ( lastDirectionOfChangeInLevelFromPreviousReading > 0 ) ) ) )
            {
                masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading = tmpReading * sampleTimes;
            }
            else if( lastDirectionOfChangeInLevelFromPreviousReading  ) //means direction of changing stopped or reversed, could be due to noise or cessation of change, assume the latter
            {//if readings have changed direction with this latest reading now, post-fill CurrentUnmagnifiedReading with as many multiples of previousReading as have been taken before this and null the flag
                lastDirectionOfChangeInLevelFromPreviousReading = 0; //readings hereafter are all assumed valid
                masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading = previousReading * sampleTimes;
            }
            masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading += tmpReading;
            previousReading = tmpReading;
        }
#endif

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
#if ( SAMPLE_TIMES > 1 )
        masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading /= SAMPLE_TIMES;
#endif
        masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading <<= SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
    }

#if ( INBOARDS_PLOTTED > 0 ) //plot the inboard analogs first and above from readings in masterReadingsArray
    for( uint8_t inboardPinIndex = 0; inboardPinIndex < INBOARDS_PLOTTED; inboardPinIndex++ )
    { //PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
        plotTheNormalAndMagnifiedSignals( inboardPinIndex ); // What was I thinking comment: "not permissible to plot the paired/superimposed traces except with odd indices below INDEX_OF_INBOARDS_NOT_SUPERIMPOSED" ?
#ifdef DEBUG                                         // Maybe a single array element holds both reference and signal plots?
        Serial.println();
#endif
    }
#endif
#if ( OUTBOARDS_PLOTTED > 0 )
  for( uint8_t whichOutboardADCindex = 0; whichOutboardADCindex < OUTBOARDS_PLOTTED; whichOutboardADCindex++ )
  {
#if defined LEGS_PER_DPOT_STYLE_BRIDGE
Start_of_addon_ADC_acquisition:
    bool overscaleIsUnfixable = false;
    while( true ) //comes back to here if CurrentUnmagnifiedReading overscales
    {
#endif
        masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = oneReadingFromThisOutboardADC( whichOutboardADCindex );
    #ifdef DEBUG                                         // Maybe a single array element holds both reference and signal plots?
        Serial.print( F( "Read outboard ADC and put reading into masterReadingsArray position " ) );
        Serial.print( INDEX_OF_OUTBOARDS + whichOutboardADCindex );
        Serial.print( F( ", it being " ) );
        Serial.println( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading );
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
#ifdef DEBUG                                         // Maybe a single array element holds both reference and signal plots?
        Serial.print( F( "Read ADC again, now accumulation divided out is " ) );
    Serial.println( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading / ( sampleTimes + 1 ) );
#endif
    }
    masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading /= SAMPLE_TIMES;
#endif
    masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = ( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading < HEIGHT_OF_A_PLOT_LINESPACE ) ? masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading : HEIGHT_OF_A_PLOT_LINESPACE;

//Here set the indicator LEDs whether shorted or open
#if ( defined RED_LED_PIN && defined YELLOW_LED_PIN )
    if( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading == HEIGHT_OF_A_PLOT_LINESPACE )
    {
        digitalWrite( RED_LED_PIN + ( 2 * whichOutboardADCindex /*allows multiple ADCs*/), HIGH );
        digitalWrite( YELLOW_LED_PIN + ( 2 * whichOutboardADCindex ), LOW );
    }
    else if( !masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading )
    {
        digitalWrite( RED_LED_PIN + ( 2 * whichOutboardADCindex ), LOW );
        digitalWrite( YELLOW_LED_PIN + ( 2 * whichOutboardADCindex ), HIGH );
    }
    else
    {
        digitalWrite( RED_LED_PIN + ( 2 * whichOutboardADCindex ), LOW );
        digitalWrite( YELLOW_LED_PIN + ( 2 * whichOutboardADCindex ), LOW );
    }
#endif
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Line<1687> INDEX_OF_OUTBOARDS =" ) );
    Serial.print( INDEX_OF_OUTBOARDS );
    Serial.print( F( ", whichOutboardADCindex =" ) );
    Serial.println( whichOutboardADCindex );
    Serial.print( F( ", INDEX_OF_OUTBOARDS + whichOutboardADCindex =" ) );
    Serial.println( INDEX_OF_OUTBOARDS + whichOutboardADCindex );
#endif
    for( uint8_t dpotIndex = lSBdPotIndexThisLeg; dpotIndex < lSBdPotIndexThisLeg + dPotsPerThisBridge; dpotIndex++)
    { //the limits are mixing bridge and leg limits b/c lSBdPotIndexThisLeg is referring to the reference leg FIXME
        Serial.print( F( " Line <2420> dpotIndex<" ) );
        Serial.print( dpotIndex );
        Serial.print( F( ">=<" ) );
        Serial.print( dPotSettings[ dpotIndex ] );
        Serial.print( F( ">, " ) );
    }
    plotTheNormalAndMagnifiedSignals( INDEX_OF_OUTBOARDS + whichOutboardADCindex );
    for( uint8_t dpotIndex = lSBdPotIndexThisLeg; dpotIndex < lSBdPotIndexThisLeg + dPotsPerThisBridge; dpotIndex++)
    { //the limits are mixing bridge and leg limits b/c lSBdPotIndexThisLeg is referring to the reference leg FIXME
        Serial.print( F( " Line <2429> dpotIndex<" ) );
        Serial.print( dpotIndex );
        Serial.print( F( ">=<" ) );
        Serial.print( dPotSettings[ dpotIndex ] );
        Serial.print( F( ">, " ) );
    }
  }
#endif
  Serial.println();
}

void blinkMorseCode( char* symbol, uint8_t chars )
{
#ifndef LED_BUILTIN
    #define LED_BUILTIN 13
#endif
    uint16_t dotLength = 95;
    uint16_t symbolSpace = dotLength;
    uint16_t dashLength = dotLength * 4;
    uint16_t letterSpace = dashLength;
    uint16_t wordSpace = ( dotLength * 7 ) - symbolSpace;
    uint16_t messageSpace = wordSpace * 3;
    uint8_t symbolIndex = 0;
    for( uint8_t charIndex = 0; charIndex < chars; charIndex++ )
    {
        for( ; symbol[ symbolIndex ]; symbolIndex++ )
        {
            digitalWrite( LED_BUILTIN, HIGH );
            delay( symbol[ symbolIndex ] == '-' ? dashLength : dotLength );
            digitalWrite( LED_BUILTIN, LOW );
            delay( symbolSpace );
        }
        symbolIndex++;
        digitalWrite( LED_BUILTIN, LOW );
        delay( letterSpace );
    }
}
#if ( DPOT_LEGS > 0 )
//#error Fix all calls to this to utilize correctly mayDistribute then fix all calls to setMSBdPotOrGroupValueUsingIndicesOnly to utilize 
void fixMSB_SETTINGSarraysAndMayDistribute( bool mayDistribute = ( bool )analogPinArray, bool readAndPlot = true )
{
    uint8_t dPotLegBak = dPotLeg;
    Serial.print( F( "Entered inside fixMSB_SETTINGSarraysAndMayDistribute()," ) );
  for( dPotLeg = 0; dPotLeg < DPOT_LEGS; dPotLeg++ )
  {
    uint8_t mSBdPotIndex = whatIsFirstMSBindexThisLeg( dPotLeg );
    uint8_t mSBgroupSize = whatIsMSBgroupSizeInThisDPotLeg( dPotLeg );
    MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) = 0;
//recalculate MSB_SETTINGS_ arrays
    for( uint8_t mSBindexOffset = 0; mSBindexOffset < mSBgroupSize - 1; mSBindexOffset++ )
    {
        if( dPotSettings[ mSBdPotIndex + mSBindexOffset ] > MAX_DPOT_SETTG ) dPotSettings[ mSBdPotIndex + mSBindexOffset ] = MAX_DPOT_SETTG;
        MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) += dPotSettings[ mSBdPotIndex + mSBindexOffset ];
    }
    MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg ) = ( mSBgroupSize * MAX_DPOT_SETTG ) - MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg );
  }
//#endif
    dPotLeg = dPotLegBak;
    configureFromDPotLeg( );
    Serial.print( F( "Exitting fixMSB_SETTINGSarraysAndMayDistribute()." ) );
}
#endif

uint32_t any_high_but_this_or_if_this_low( uint8_t i )
{
    uint32_t result = 0;
    for( uint8_t j = 2; j < 20; j++ )
    {
        if( !digitalRead( i ) ) { bitSet( result, i ); return result; }
        if( j == i ) continue;
//        if( digitalRead( j ) ) { bitSet( result, j ); return result; }
    }
    return false;
}
void setup()
{ //all vars of setup() scope will never compete for space with any vars of loop() scope nor any vars scoped to functions except those called herein, so we have a lot of latitude to be sloppy large with the array sizes herein.  That is the big advantage of a setup() scope for embedded applications.
    Serial.begin( BAUD_TO_SERIAL );
    Serial.setTimeout( 10 );
    //read EEPROM addresses 0 (LSB)and 1 (MSB).  This sketch expects MSB combined with LSB always contain ( NUM_DIGITAL_PINS + 1 ) * 3 for confidence in the remiander of the EEPROM's contents.
#if defined ( RESTORE_FACTORY_DEFAULTS ) && ( defined ( __LGT8FX8E__ ) || defined ( ARDUINO_AVR_YUN ) || defined ( ARDUINO_AVR_LEONARDO ) || defined ( ARDUINO_AVR_LEONARDO_ETH ) || defined ( ARDUINO_AVR_MICRO ) || defined ( ARDUINO_AVR_ESPLORA ) || defined ( ARDUINO_AVR_LILYPAD_USB ) || defined ( ARDUINO_AVR_YUNMINI ) || defined ( ARDUINO_AVR_INDUSTRIAL101 ) || defined ( ARDUINO_AVR_LININO_ONE ) )
#else
    #ifndef __LGT8FX8E__
        EEPROM.get( EEPROMlength - 2, tattoo );
//        tattoo = ( u8 )73;//"I"
//        tattoo += ( u16 )( ( u8 )68 << 8 );//"D".  "DI" makes 17481
/*
        tattoo = ( char )"G";
        tattoo += ( u16 )( "W" << 8 );
*/

/*        tattoo = ( u8 )87;//"W"
        tattoo += ( u16 )( ( u8 )"I" << 8 ); //tattoo == ( u16 )10792
        tattoo = ( u8 )71;//"G" tattoo == ( u16 )40
//        tattoo += ( u16 )( ( u8 )"W" << 8 );
        tattoo = ( u8 )68;//"D"
        tattoo = ( u8 )73;//"I"
*/
    #else
        tattoo = EEPROM.read( EEPROMlength - 2 );
        tattoo += ( u16 )( EEPROM.read( EEPROMlength - 1 ) << 8 );
    #endif
#endif
#ifdef __LGT8FX8E__
    delay( 10000 );//needed for TTGO XI Serial to initialize
#endif
    if( tattoo != ( u16 )17481 ) // Check for tattoo of "DI", means Diagnostics
    {
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        Serial.println();
        Serial.print( "<" );
        Serial.print( tattoo );
        Serial.println( F( ">, no tattoo" ) ); 
        Serial.println( F( "no tattoo, this Arduino has not been configured for this sketch" ) ); 
/*        
 *         add code here to handle first time initialize of EEPROM
*/
    }
    else
    {
        while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
        Serial.println();
        Serial.println( F( "This Arduino has a tattoo so it is configured for this sketch" ) );
    #ifdef SD_CHIP_SELECT_PIN
        unsigned int logging_address = EEPROMlength - sizeof( boolean );//This addressing scheme is only for thermostat
//        unsigned int upper_heat_temp_address = logging_address - sizeof( short );//EEPROMlength - 2; //This is example of useage from my thermostat sketch
        bLogging = ( boolean )EEPROM.read( logging_address );
    #endif
    }
#ifndef __LGT8FX8E__
//    EEPROM.get( lower_heat_temp_address, lower_heat_temp_shorted_times_ten ); //This is example of useage from my thermostat sketch
#else
//    lower_heat_temp_shorted_times_ten = EEPROM.read( lower_heat_temp_address ); //This is example of useage from my thermostat sketch
//    lower_heat_temp_shorted_times_ten += ( u16 )( EEPROM.read( lower_heat_temp_address + 1 ) << 8 ); //This is example of useage from my thermostat sketch
#endif
//    lower_heat_temp_floated = ( float )( ( float )( lower_heat_temp_shorted_times_ten ) / 10 ); //This is example of useage from my thermostat sketch
#ifndef __LGT8FX8E__
//    EEPROM.get( upper_heat_temp_address, upper_heat_temp_shorted_times_ten ); //This is example of useage from my thermostat sketch
#else
//    upper_heat_temp_shorted_times_ten = EEPROM.read( upper_heat_temp_address ); //This is example of useage from my thermostat sketch
//    upper_heat_temp_shorted_times_ten += ( u16 )( EEPROM.read( upper_heat_temp_address + 1 ) << 8 ); //This is example of useage from my thermostat sketch
#endif
//    upper_heat_temp_floated = ( float )( ( float )( upper_heat_temp_shorted_times_ten ) / 10 ); //This is example of useage from my thermostat sketch
      //( pin_specified*3 )and ( pin_specified*3 )+1 contains the EEPROM address where the pin's assigned name is stored.  Pin 0 will always have its name stored at EEPROM address (NUM_DIGITAL_PINS+1 )*3, so address (NUM_DIGITAL_PINS+1 )*3 will always be stored in EEPROM addresses 0 and 1; 0 = ( pin_number*3 )and 1 = (( pin_number*3 )+1 ) )]
      // That will be the way we determine if the EEPROM is configured already or not
      // ( pin_specified*3 )+2 is EEPROM address where the pin's desired inital state is stored
#ifndef __LGT8FX8E__
//    EEPROM.get( upper_cool_temp_address, upper_cool_temp_shorted_times_ten ); //This is example of useage from my thermostat sketch
#else
//    upper_cool_temp_shorted_times_ten = EEPROM.read( upper_cool_temp_address ); //This is example of useage from my thermostat sketch
//    upper_cool_temp_shorted_times_ten += ( u16 )( EEPROM.read( upper_cool_temp_address + 1 ) << 8 ); //This is example of useage from my thermostat sketch
#endif
//    upper_cool_temp_floated = ( float )( ( float )( upper_cool_temp_shorted_times_ten ) / 10 ); //This is example of useage from my thermostat sketch
#ifndef __LGT8FX8E__
//    EEPROM.get( lower_cool_temp_address, lower_cool_temp_shorted_times_ten ); //This is example of useage from my thermostat sketch
#else
//    lower_cool_temp_shorted_times_ten = EEPROM.read( lower_cool_temp_address ); //This is example of useage from my thermostat sketch
//    lower_cool_temp_shorted_times_ten += ( u16 )( EEPROM.read( lower_cool_temp_address + 1 ) << 8 ); //This is example of useage from my thermostat sketch
#endif

#ifdef WIFI
    //Start wifi here.  If using wifi, _local_ SD card storage becomes critical, so smaller RAM devices become unsuitable
#endif
  millisStart = millis();
  while( !Serial && ( millis() - millisStart < 8000 ) ); //Leonardo needs this check
#if ( ANALOG_INPUT_BITS_OF_BOARD != 10 )
        analogReadResolution( ANALOG_INPUT_BITS_OF_BOARD );   //This may very well not be necessary
#endif
#ifdef __LGT8FX8E__
  //    analogReadResolution( 12 );  //I believe this is not necessary
  delay( SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING * 1000 );  // Needed by this board for serial to work
  Serial.println( F( "DEBUG is defined." ) );
#endif
    for( /*all pins*/uint8_t i = 2; i < 20; i++ )
    {
//        mode/*make 'em inputs*/
        pinMode( i, INPUT );
        digitalWrite( i, HIGH);
    }
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  while( !Serial && ( millis() - millisStart < 8000 ) );
  if( Serial )
  {
    uint32_t tracker_by_bitsetting = 0;
    for( /*all pins*/uint8_t i = 2; i < 18; i++ )
    {
        for( /*all pins*/uint8_t j = 2; j < 18; j++ )
        {
            if( j == i ) continue;
    //        mode/*make 'em inputs*/
            pinMode( j, OUTPUT );
            digitalWrite( j, LOW);
        }
        pinMode( i, OUTPUT );
        digitalWrite( i, HIGH);
        tracker_by_bitsetting |= any_high_but_this_or_if_this_low( i );
        for( /*all pins*/uint8_t j = 2; j < 18; j++ )
        {
            if( j == i ) continue;
    //        mode/*make 'em inputs*/
            pinMode( j, INPUT );
        }
        tracker_by_bitsetting |= any_high_but_this_or_if_this_low( i );
        digitalWrite( i, LOW);
        pinMode( i, INPUT );
        for( /*all pins*/uint8_t j = 2; j < 18; j++ )
        {
    //        mode/*make 'em inputs*/
            pinMode( j, OUTPUT );
            digitalWrite( j, HIGH);
            if( !digitalRead( j ) ) bitSet( tracker_by_bitsetting, j );
        }
//        Serial.println( tracker_by_bitsetting, BIN );
    }
    if( tracker_by_bitsetting ) Serial.println( tracker_by_bitsetting, BIN );
      Serial.print( F( VERSION ) );
      Serial.print( F( "\nThank you for your interest in learning GWAAM-Sea to cooperate with God\n" ) );
      Serial.print( F( "bringing His kingdom to earth and His will to be done here as it is in heaven.\n" ) );
      Serial.print( F( "There is no doubt He will eventually answer that prayer of ours...and very, very soon.\n\n" ) );
    #if not defined COMPILE_FOR_DIAGS_ONLY
      Serial.print( F( "This product is normally run in the Serial Plotter, not the Serial Monitor.\n" ) );
      Serial.print( F( "Unless you're interested in this text only output, close this Serial Monitor\n" ) );
      Serial.print( F( "and open the Serial Plotter instead.\n\n" ) );
    #else
      Serial.print( F( "\n\n\nDiagnostics for the GWAAM-Sea Entanglement Gardening and Faith Training Aid\n\n" ) );
    #endif
      Serial.print( F( "(C)" ) );
      Serial.print( COPYRIGHT_YEAR ); /*To prevent this numeric from becoming part of a plotline we must have a non whitespace character adjacent.  Don't try to whitespace-wrap this numeric or it will affect plotting*/
      Serial.print( F( ", Kenneth L. Anderson, Electronics Technician, BT, BGS, MCSE, RDH (ret'd)  d/b/a A Reviving Civility\n\n" ) );
  }
#endif
#ifdef COMPILE_FOR_DIAGS_ONLY

    //Make all pins as inputs and making one at a time an output low (& verify), then high (& verify), then input again.  In that way read from all pins both analog and digital reads, store them and check that value after making it an output low (& verify), then high (& verify), then input again
    //Make all pins as output lows and making one at a time an output low (& verify), then high (& verify), then input again.  In that way read from all pins both analog and digital reads, store them and check that value after making it an output low (& verify), then high (& verify), then input again
    //Make all pins as output highs and making one at a time an output low (& verify), then high (& verify), then input again.  In that way read from all pins both analog and digital reads, store them and check that value after making it an output low (& verify), then high (& verify), then input again
      Serial.print( F( "Follow these instructions:\n" ) );
      Serial.print( F( "Locate two adjustable controls, aka variable resistors, aka potentiometers (choose from VR1-4)\n" ) );
      Serial.print( F( "and temporarily insert them where they will fit, ensuring their three input/output lines\n" ) );
      Serial.print( F( "make firm electrical contact, whether by slight bend force or very minimal solder tack.  Then\n" ) );
      Serial.print( F( "locate where the center lead trace of each runs nearest where you'll tie them in to the\n" ) );
      Serial.print( F( "circuit as built so far: by means using very lightweight scrap wires or jumpers, tie the center\n" ) );
      Serial.print( F( "lead circuit of the lowest number VR (this is the same circuit as one of the Analog Input pins)\n" ) );
      Serial.print( F( "into the circuit of U4 pin <4>, either on that pad or onto a more convenient pad like Q2 pin <1>.\n" ) );
      Serial.print( F( "Tie the center lead circuit of the other VR (the same circuit as a higher numbered Analog Input\n" ) );
      Serial.print( F( "pin) into the circuit of U4 pin <2>.  Solder to pads rather than the VR itself so you can use\n" ) );
      Serial.print( F( "those trimmed leads from the LEDs and not risk pulling a pad off if the VR moves. Kapton tape for\n" ) );
      Serial.print( F( "insulating or spacing can be your friend here.\n\n" ) );
      Serial.print( F( "When ready to continue, re-compile the diagnostics sketch with the macro \"DIAGS_STEP2\" defined\n" ) );
      Serial.print( F( "then upload the sketch and start the plotter tool instead of this monitor tool\n" ) );
    #if ( not defined DIAGS_STEP2 ) && ( not defined DIAGS_STEP3 ) && ( not defined DIAGS_STEP4 )
            while( true );
    #else if DIAGS_STEP2
      Serial.print( F( "Follow these instructions after removing power from the Arduino:\n" ) );
      Serial.print( F( "Carefully remove the pieces of Kapton tape under pin 1s of U5 and U6, DO NOT BEND PINS UP TO DO THIS!\n" ) );
      Serial.print( F( "Solder those pins down now.\n" ) );
      Serial.print( F( "When ready to continue, re-compile the diagnostics sketch with the macro \"DIAGS_STEP3\" defined instead\n" ) );
      Serial.print( F( "of \"DIAGS_STEP2\" and unsolder any VR from pin 4 of U3, replacing it with an R to GNDA from that pin and\n" ) );
      Serial.print( F( "pin 5 of U3\n" ) );
      Serial.print( F( "then upload the sketch and start the plotter tool instead of this monitor tool\n" ) );
    #endif

    for( /*all pins*/uint8_t i = 2; i < 20; i++ )
    {
//        mode/*make 'em inputs*/
        digitalWrite( i, LOW );
        pinMode( i, INPUT );
    }
    #if ( not defined DIAGS_STEP3 ) && ( not defined DIAGS_STEP4 ) 
        while( true )
        {
            Serial.print( 0 );
            Serial.print( F( " " ) );
            Serial.print( analogRead( A0 ) );
            Serial.print( F( " " ) );
            Serial.print( analogRead( A1 ) );
            Serial.print( F( " " ) );
            Serial.println( 1024 );
            delay( 100 );
        }
    #endif
#ifndef DIAGS_STEP4
    for( /*all pins*/uint8_t i = 2; i < 20; i++ )
    {
//        /*show their levels*/
        Serial.print( F( "Pin D<" ) );
        Serial.print( i );
        Serial.print( F( ">=<" ) );
        Serial.print( digitalRead( i ) );
        Serial.print( F( ">, <" ) );
        Serial.print( analogRead( i ) );
        Serial.println( F( ">" ) );
    }
    Serial.println( F( "Sitting at line 2894" ) );
    while( Serial.available() ) Serial.read();
    while( !Serial.available() );
//Analyze the data
    while( Serial.available() ) Serial.read();
    for( /*all pins*/uint8_t i = 2; i < 20; i++ )
    {
//        mode/*make 'em inputs*/
        digitalWrite( i, HIGH );
        pinMode( i, INPUT );
    }
    for( /*all pins*/uint8_t i = 2; i < 20; i++ )
    {
//        /*show their levels*/
        Serial.print( F( "Pin D<" ) );
        Serial.print( i );
        Serial.print( F( ">=<" ) );
        Serial.print( digitalRead( i ) );
        Serial.print( F( ">, <" ) );
        Serial.print( analogRead( i ) );
        Serial.println( F( ">" ) );
    }
    Serial.println( F( "Sitting at line 2916" ) );
    while( Serial.available() ) Serial.read();
    while( !Serial.available() );
//Analyze the data
    while( Serial.available() ) Serial.read();
    for( /*all pins*/uint8_t i = 2; i < 14; i++ )
    {
//        mode/*make 'em outputs*/
        digitalWrite( i, LOW );
        pinMode( i, OUTPUT );
        digitalWrite( i, LOW );
    }
    for( /*all pins*/uint8_t i = 2; i < 20; i++ )
    {
//        /*show their levels*/
        Serial.print( F( "Pin D<" ) );
        Serial.print( i );
        Serial.print( F( ">=<" ) );
        Serial.print( digitalRead( i ) );
        Serial.print( F( ">, <" ) );
        Serial.print( analogRead( i ) );
        Serial.println( F( ">" ) );
    }
    Serial.println( F( "Sitting at line 2939" ) );
    while( Serial.available() ) Serial.read();
    while( !Serial.available() );
//Analyze the data
    while( Serial.available() ) Serial.read();
    for( /*all pins*/uint8_t i = 2; i < 14; i++ )
    {
//        mode/*make 'em outputs*/
        digitalWrite( i, HIGH );
        pinMode( i, OUTPUT );
        digitalWrite( i, HIGH );
    }
    for( /*all pins*/uint8_t i = 2; i < 20; i++ )
    {
//        /*show their levels*/
        Serial.print( F( "Pin D<" ) );
        Serial.print( i );
        Serial.print( F( ">=<" ) );
        Serial.print( digitalRead( i ) );
        Serial.print( F( ">, <" ) );
        Serial.print( analogRead( i ) );
        Serial.println( F( ">" ) );
    }
//    for( all pins )
//        make 'em output lows
//    for( all pins )
//       make 'em output highs
//Make the dpots to full values and just make sure they ALL work.

    for( /*all pins*/uint8_t i = 2; i < 20; i++ )
    {
//        mode/*make 'em inputs*/
        digitalWrite( i, LOW );
        pinMode( i, INPUT );
    }
#endif
#endif

#if ( ( DPOTS > 0 ) || ( defined __SD_H__ ) )
  SPI.begin(); //The CS pin gets specified in the SPI.transfer( CS_pin ) instruction
  SPI.setBitOrder( MSBFIRST );
#endif
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES //This puts pull-ups on the lines even though they remain inputs
        digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A0_PIN1, HIGH );
    #ifdef FIRST_STAGE_3_TO_8_DECODER_A1_PIN2
        digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A1_PIN2, HIGH );
    #endif 
    #ifdef FIRST_STAGE_3_TO_8_DECODER_A2_PIN3
        digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A2_PIN3, HIGH );
    #endif
    #ifdef FIRST_STAGE_3_TO_8_DECODER_A3_PIN4
        digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A3_PIN4, HIGH );
    #endif
    #ifdef FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4
        digitalWrite( FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4, HIGH );
    #endif
    #ifdef FINAL_STAGE_3_TO_8_DECODER_A0_PIN1
        digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A0_PIN1, HIGH );
    #endif
    #ifdef FINAL_STAGE_3_TO_8_DECODER_A1_PIN2
        digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A1_PIN2, HIGH );
    #endif
    #ifdef FINAL_STAGE_3_TO_8_DECODER_A2_PIN3
        digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A2_PIN3, HIGH );
    #endif
    #ifdef FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4
        digitalWrite( FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4, HIGH );
    #endif
#endif
#ifdef LM334_BRIDGES   //This is important to put this first so LM334 get some resistance, but not super important b/c the DPots default to half-setting resistance at power-up, so the only time they MIGHT need this is when the ckt was just merely reset after a previous session that left them setting at zero resistance, but at powerup they go the half value so this is unnecessary for just power
/*  Is this right?
Index=<0> pin=<8> LSB_DPOT_B0SIG_PIN 
Index=<1> pin=<5>  NON_LSB_DPOT_1_B0SIG_PIN
Index=<2> pin=<72>  LSB_DPOT_B0REF_PIN
Index=<3> pin=<69> NON_LSB_DPOT_1_B0REF_PIN */

#if ( LM334_BRIDGES == 1 )
  digitalWrite( SS, HIGH ); //Not needed by slave devices but rather by this board to make it configure itself to be master
  pinMode( SS, OUTPUT );
  for( uint8_t LM334Bridge = 0; LM334Bridge < LM334_BRIDGES; LM334Bridge++ )
  { //This is not scaleable beyond a single LM334_bridge of pots as far as pins, anyway, but at least it will initialize the LM334 digipot arrays to protect the LM334s.  To get valid settingValues beyond the first LM334_bridge, assign them non-looped below this loop for additional LM334_bridges
    dPotPins[ 0 + LM334Bridge ] = LSB_DPOT_B0SIG_PIN;
    dPotSettings[ 0 + LM334Bridge ] = LSB_DPOT_B0SIG_STARTVALUE;  // Storing a copy of the digi pot settingValues in sketch makes it possible to eliminate the MISO pin connection to the data out pins of all digi pots, besides the digi pots data out may not conform strictly to SPI since the MCP41X1 version has one bidirectional data pin
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ 0 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
    pinMode( dPotPins[ 0 + LM334Bridge ] & 0x3F, OUTPUT );
    digitalWrite( dPotPins[ 0 + LM334Bridge ] & 0x3F, HIGH );
    dPotPins[ DPOTS_PER_LM334_LEG + 0 + LM334Bridge ] = LSB_DPOT_B0REF_PIN;
    dPotSettings[ DPOTS_PER_LM334_LEG + 0 + LM334Bridge ] = LSB_DPOT_B0REF_STARTVALUE;
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( DPOTS_PER_LM334_LEG + 0 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ DPOTS_PER_LM334_LEG + 0 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
    pinMode( dPotPins[ 0 + DPOTS_PER_LM334_LEG + LM334Bridge ] & 0x3F, OUTPUT );
    digitalWrite( dPotPins[ 0 + DPOTS_PER_LM334_LEG + LM334Bridge ] & 0x3F, HIGH );
#if ( DPOTS_PER_LM334_LEG > 1 )
    dPotPins[ 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0SIG_PIN;
    dPotSettings[ 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0SIG_STARTVALUE;
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( 1 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ 1 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
    pinMode( dPotPins[ 1 + LM334Bridge ] & 0x3F, OUTPUT );
    digitalWrite( dPotPins[ 1 + LM334Bridge ] & 0x3F, HIGH );
    dPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0REF_PIN;
    dPotSettings[ DPOTS_PER_LM334_LEG + 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0REF_STARTVALUE;
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( DPOTS_PER_LM334_LEG + 1 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
    pinMode( dPotPins[ 1 + DPOTS_PER_LM334_LEG + LM334Bridge ] & 0x3F, OUTPUT );
    digitalWrite( dPotPins[ 1 + DPOTS_PER_LM334_LEG + LM334Bridge ] & 0x3F, HIGH );
#if ( DPOTS_PER_LM334_LEG > 2 )
    dPotPins[ 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0SIG_PIN;
    dPotSettings[ 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0SIG_STARTVALUE;
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( 2 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ 2 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
    pinMode( dPotPins[ 2 + LM334Bridge ] & 0x3F, OUTPUT );
    digitalWrite( dPotPins[ 2 + LM334Bridge ] & 0x3F, HIGH );
    dPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0REF_PIN;
    dPotSettings[ DPOTS_PER_LM334_LEG + 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0REF_STARTVALUE;
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( DPOTS_PER_LM334_LEG + 2 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
#endif
#endif
   pinMode( dPotPins[ 2 + DPOTS_PER_LM334_LEG + LM334Bridge ] & 0x3F, OUTPUT );
    digitalWrite( dPotPins[ 2 + DPOTS_PER_LM334_LEG + LM334Bridge ] & 0x3F, HIGH );
    //  The way this is built makes the DPots get initialized in reverse order from intuitive
  }
  //To increase capacity, follow the naming pattern above
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "DPot arrays filled and CS pins set up. " ) );
#endif
#ifndef LEAVE_POT_VALUES_ALONE_DURING_SETUP 
    for( uint8_t dPotIndex = 0; dPotIndex < DPOTS; dPotIndex++) //THIS ASSUMES THE ABOVE CONSTRUCT FILLS BOTH ARRAYS COMPLETELY
    {
#ifdef NUM_DIGITAL_PINS
      if( ( dPotSettings[ dPotIndex ] > MAX_DPOT_SETTG ) || ( ( dPotPins[ dPotIndex ] & 0x3F ) > NUM_DIGITAL_PINS ) ) break;  //The protection against arrays not fully set up
#else
      if( dPotSettings[ dPotIndex ] > MAX_DPOT_SETTG ) break;  //The protection against arrays not fully set up
#endif
        writeSettingToAsingleDPot( dPotIndex, dPotSettings[ dPotIndex ] );
    }
#ifdef DIAGS_STEP4
 //A6 affects both SOLVENT and COUNTER_BALANCING_SOLVENT in opposite directions, preferring COUNTER_BALANCING_SOLVENT unless it is already maxed high or low (light an alerting LED &/or sound an alerting alarm when SOLVENT is getting adjusted b/c the dilution ratio is also getting changed), for "DC level". A7 simultaneously affects SOLVENT and COUNTER_BALANCING_SOLVENT in same direction for "Dilution ratio": light the red LED when either dPot reached its limit in the direction trying to go
/*  for use as subscripts of dPot settings arrays dPotAnchorSettings[ ], dPotAnchorSettingsEEPROMAddress[ ] and dPotSettings[ ].
    defined SOLVENT 0
    defined COUNTER_BALANCING_SOLVENT 2
    defined LSB 0
    defined MSB 1
*/
        pinMode( RED_LED_PIN, OUTPUT );
        digitalWrite( RED_LED_PIN, LOW);
        pinMode( YELLOW_LED_PIN, OUTPUT );
        digitalWrite( YELLOW_LED_PIN, LOW);
    //ratio LSB/MSB=248/1

        uint8_t start_dPot_index;
        uint8_t end_dPot_index;
        int8_t runTimeOffsetLSB;
        int8_t runTimeOffsetMSB;
//If EEPROM. is good, use it        
    if( tattoo == ( u16 )17481 ) // Checking for tattoo of "DI", means Diagnostics
    {
#ifndef __LGT8FX8E__
//    EEPROM.get( dPotAnchorSettingsEEPROMAddress[ COUNTER_BALANCING_SOLVENT + LSB ], dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] ); //This is example of useage from my thermostat sketch
//    EEPROM.get( dPotAnchorSettingsEEPROMAddress[ COUNTER_BALANCING_SOLVENT + MSB ], dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] ); //This is example of useage from my thermostat sketch
//    EEPROM.get( dPotAnchorSettingsEEPROMAddress[ SOLVENT + LSB ], dPotAnchorSettings[ SOLVENT + LSB ] ); //This is example of useage from my thermostat sketch
//    EEPROM.get( dPotAnchorSettingsEEPROMAddress[ SOLVENT + MSB ], dPotAnchorSettings[ SOLVENT + MSB ] ); //This is example of useage from my thermostat sketch
#else
//    lower_cool_temp_shorted_times_ten = EEPROM.read( lower_cool_temp_address ); //This is example of useage from my thermostat sketch
//    lower_cool_temp_shorted_times_ten += ( u16 )( EEPROM.read( lower_cool_temp_address + 1 ) << 8 ); //This is example of useage from my thermostat sketch
#endif
        dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] = 0;
        start_dPot_index = 3;
        end_dPot_index = 3; //BELOW: START AT 170, GOES DOWN TO 0 TO MATCH ONE STEP DOWN FROM 0, 217 TO 256, 216 (VICE VERSA) 
    }
    else
    { ;
/*        VRsandbox[ VR1-4 ] 
        start_dPot_index = 3;
        end_dPot_index = 3; //BELOW: START AT 170, GOES DOWN TO 0 TO MATCH ONE STEP DOWN FROM 0, 217 TO 256, 216 (VICE VERSA) 
        dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] = 15; //inverting LSB (higher means lower volts)  reduced effect dPot  //256 NO FLEX [0]inverting LSB (higher means lower volts)   pin 72, affects COUNTER_BALANCING_SOLVENT   256 to test for presence of DUT
        dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] = 156;  //inverting MSB //256 NO FLEX  [1]inverting MSB (higher means lower volts)   pin 71, affects COUNTER_BALANCING_SOLVENT   256 to test for presence of DUT.  202 with dPts 2 & 3 at 256 centers a 10 MOhm DUT
        dPotAnchorSettings[ SOLVENT + LSB ] = 15;   //LSB non-inverting, affects U5 //16 TO 20 NO FLEX [2]non-inverting LSB (higher means higher volts)   pin 8, affects SOLVENT.  35-120 to test for presence of DUT
        uint16_t start_dPot_setting = 156; //229 NO FLEX [3]non-inverting (higher means higher volts)   pin 7, affects SOLVENT   217 to test for presence of DUT
        uint16_t end_dPot_setting = 179;  //229 NO FLEX [3]non-inverting (higher means higher volts), affects SOLVENT
        dPotAnchorSettings[ SOLVENT + MSB ] = start_dPot_setting;  //non-inverting MSB, affects SOLVENT
//        uint16_t start_dPot_setting = 205; //229 NO FLEX [3]non-inverting (higher means higher volts)   pin 7, affects SOLVENT   217 to test for presence of DUT
//        uint16_t end_dPot_setting = 207;  //229 NO FLEX [3]non-inverting (higher means higher volts), affects SOLVENT
        
        int8_t step_per_dPot_change = 1; //ABOVE SETTINGS GIVE ALMOST CENTERED A0.  IT'S A LITTLE LOW. BUT COULD BE ABOUT 300
        uint8_t which_dpot_index = start_dPot_index; */
/*#ifndef __LGT8FX8E__
           EEPROM.update( fan_mode_address, fan_mode ); //high; low = 'a'
#else
            
( fan_mode_address, fan_mode );
#endif
#ifndef __LGT8FX8E__
    EEPROM.put( settingOfInterestAddress, temp_specified_shorted_times_ten );
#else
    EEPROMupdate( settingOfInterestAddress, ( u8 )temp_specified_shorted_times_ten );
    EEPROMupdate( settingOfInterestAddress + 1, ( u8 )( temp_specified_shorted_times_ten >> 8 ) );
#endif
*/
#ifndef __LGT8FX8E__
//    EEPROM.put( dPotAnchorSettingsEEPROMAddress[ COUNTER_BALANCING_SOLVENT + LSB ], dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] ); //This is example of useage from my thermostat sketch
//    EEPROM.get( dPotAnchorSettingsEEPROMAddress[ COUNTER_BALANCING_SOLVENT + MSB ], dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] ); //This is example of useage from my thermostat sketch
//    EEPROM.get( dPotAnchorSettingsEEPROMAddress[ SOLVENT + LSB ], dPotAnchorSettings[ SOLVENT + LSB ] ); //This is example of useage from my thermostat sketch
//    EEPROM.get( dPotAnchorSettingsEEPROMAddress[ SOLVENT + MSB ], dPotAnchorSettings[ SOLVENT + MSB ] ); //This is example of useage from my thermostat sketch
#else
//    lower_cool_temp_shorted_times_ten = EEPROM.write( lower_cool_temp_address ); //This is example of useage from my thermostat sketch
//    lower_cool_temp_shorted_times_ten += ( u16 )( EEPROM.read( lower_cool_temp_address + 1 ) << 8 ); //This is example of useage from my thermostat sketch
#endif
    }
//check eeprom for valid values instead of using these hard-coded ones        
//        writeSettingToAsingleDPot( 72, dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ], false );  //inverting reduced effect dPot   pin 72, affects U6
//        writeSettingToAsingleDPot( 71, dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ], false );   //inverting    pin 71, affects U6
//        writeSettingToAsingleDPot( 8, dPotAnchorSettings[ SOLVENT + LSB ], false );   //non-inverting LSB   pin 8, affects SOLVENT
//        writeSettingToAsingleDPot( 2, dPotAnchorSettings[ SOLVENT + LSB ] );   //non-inverting 
//        writeSettingToAsingleDPot( 7, dPotAnchorSettings[ SOLVENT + MSB ], false );     //non-inverting    pin 7, affects SOLVENT
//        dPotAnchorSettings[ which_dpot_index ] = 0;
        while( !Serial.available() )
        {
//            writeSettingToAsingleDPot( 0, dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] );  //inverting  reduced effect dPot, affects U6
/*  In process of thinking through:
CASE A:
Let's use A6 for "DC level": 
when DUT too conductive:
up with SOLVENT (dPotAnchorSettings[ SOLVENT + LSB ] & dPotAnchorSettings[ SOLVENT + MSB ]), down with U6 (dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] & dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ]) when DUT current is higher than circuit is accommodating
or
when DUT not conductive enough:
down with SOLVENT (dPotAnchorSettings[ SOLVENT + LSB ] & dPotAnchorSettings[ SOLVENT + MSB ]), up with U6 (dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] & dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ]) when DUT current is lower than circuit is accommodating

Upper Limit: Either leg’s MSB and LSB both reach  0 for SOLVENT, 257 for U6
Lower Limit: Either leg’s MSB and LSB both reach  257 for SOLVENT, 0 for U6

CASE B:
Let's use A7 for "Inverse Dilution ratio":
both settings going in same direction by same amount.
This should be left at lowest impedance (highest solvent current) that doesn’t swamp the DUT (solute) signal 
YELLOW_LED_PIN
Upper Limit: Either leg’s MSB and LSB both reach 257
Lower Limit: Either leg’s MSB and LSB both reach 0*/
/*
//#error NEW IDEA:
//#error Use VR4_A7 setting to establish dPotSettings[] to a specific dilution ratio (both dPot pairs set the same ( 1023 - VR3_A6 ) / 257 for MSB) and % 257 / 4 or something for LSB ), then apply the DC level demanded by VR3_A6
            VRsandbox[ VR3_A6 ] = analogRead( A6 ) - 512;
            VRsandbox[ VR4_A7 ] = analogRead( A7 );// - 512; //FUTURE TODO: This should not be able to take A0 too far away from its reference level
            if( VRsandbox[ VR3_A6 ] == 511 ) 
            { 
                if( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] == 0 )
                {
                    if( dPotAnchorSettings[ SOLVENT + MSB ] == 257 ) digitalWrite( RED_LED_PIN, HIGH); 
                    else digitalWrite( YELLOW_LED_PIN, HIGH); 
                }
                while( analogRead( A6 ) == 1023 ); 
                if( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] > 0 ) dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ]-- 
                */ /*increases counter_balance current to raise A0*//*; 
                else if( dPotAnchorSettings[ SOLVENT + MSB ] < 256 )  dPotAnchorSettings[ SOLVENT + MSB ]++; /*also save to eeprom*/
/*            }
            
            else if( VRsandbox[ VR3_A6 ] == -512 ) 
            { 
                if( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] == 256 )
                {
                    if( dPotAnchorSettings[ SOLVENT + MSB ] == 0 ) digitalWrite( RED_LED_PIN, HIGH);
                    else if( 0 ); 
                }
                while( analogRead( A6 ) == 0 ); 
                if( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] < 256 ) dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ]++ 
                *//*reduces counter_balance current to lower A0*//*; 
                else if( dPotAnchorSettings[ SOLVENT + MSB ] > 0 )  dPotAnchorSettings[ SOLVENT + MSB ]--; *//*also save to eeprom*/
//            }
//            */
/*
            if( VRsandbox[ VR4_A7 ] == 511 ) //? Let's decide this decreases dilution ratio which increases impedance which increases amount of signal produced so this is intuitive with the volume control concept
            { 
                if( ( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] == 256 ) || ( dPotAnchorSettings[ SOLVENT + MSB ] == 256 ) ) digitalWrite( RED_LED_PIN, HIGH);
                while( analogRead( A7 ) == 1023 ); 
                if( ( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] < 256 ) && ( dPotAnchorSettings[ SOLVENT + MSB ] < 256 ) ) { dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ]++; dPotAnchorSettings[ SOLVENT + MSB ]++; }
*/
                /*also save to eeprom*/ 
/*            } 

            else if( VRsandbox[ VR4_A7 ] == -512 ) //increases dilution ratio, decreases impedance and amount of signal produced
            { 
                if( ( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] == 0 ) || ( dPotAnchorSettings[ SOLVENT + MSB ] == 0 ) ) digitalWrite( RED_LED_PIN, HIGH);
                while( analogRead( A7 ) == 0 ); 
                if( ( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] > 0 ) && ( dPotAnchorSettings[ SOLVENT + MSB ] > 0 ) ) { dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ]--; dPotAnchorSettings[ SOLVENT + MSB ]--; }
                // /*also save to eeprom*/ 
/*            } */
/*            else goto ACT_ON_VRS;
//READ_VRS_AGAIN:
            VRsandbox[ VR3_A6 ] = analogRead( A6 ) - 512;
ACT_ON_VRS:
//Both VRs have been read and recorded into their sandboxes.  Don't read them again
                if( VRsandbox[ VR3_A6 ] > 0 ) { if( VRsandbox[ VR3_A6 ] < 10 ) VRsandbox[ VR3_A6 ] = 0; else VRsandbox[ VR3_A6 ] -= 10; } else if( VRsandbox[ VR3_A6 ] < 0 ) { if( VRsandbox[ VR3_A6 ] > -10 ) VRsandbox[ VR3_A6 ] = 0; else VRsandbox[ VR3_A6 ] += 10; } //put the carrying algo in here
//                if( VRsandbox[ VR4_A7 ] > 0 ) { if( VRsandbox[ VR4_A7 ] < 10 ) VRsandbox[ VR4_A7 ] = 0; else VRsandbox[ VR4_A7 ] -= 10; } else if( VRsandbox[ VR4_A7 ] < 0 ) { if( VRsandbox[ VR4_A7 ] > -10 ) VRsandbox[ VR4_A7 ] = 0; else VRsandbox[ VR4_A7 ] += 10; } //put the carrying algo in here

                dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] = min( max( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] - ( VRsandbox[ VR3_A6 ] / 257 ), 0 ), 256 ); //
                dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ] = min( max( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] - ( VRsandbox[ VR3_A6 ] % 257 ), 0 ), 256 );
                dPotSettings[ SOLVENT + MSB ] = max( min( dPotAnchorSettings[ SOLVENT + MSB ] + ( VRsandbox[ VR3_A6 ] / 257 ), 256 ), 0 ); //
                dPotSettings[ SOLVENT + LSB ] = max( min( dPotAnchorSettings[ SOLVENT + LSB ] + ( VRsandbox[ VR3_A6 ] % 257 ), 256 ), 0 );
//#error The following algo needs to be adjusted so the dilution ratio can be lowered, raised or left stable and the operator knows which is happening:
                dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] = max( min( dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] + ( VRsandbox[ VR4_A7 ] / 1024 ), 1023 ), 0 ); //
                dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ] = max( min( dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ] + ( VRsandbox[ VR4_A7 ] % 1024 ), 1023 ), 0 );
                dPotSettings[ SOLVENT + MSB ] = max( min( dPotSettings[ SOLVENT + MSB ] + ( VRsandbox[ VR4_A7 ] / 1024 ), 1023 ), 0 ); //
                dPotSettings[ SOLVENT + LSB ] = max( min( dPotSettings[ SOLVENT + LSB ] + ( VRsandbox[ VR4_A7 ] % 1024 ), 1023 ), 0 );
*/
//#error Wow this is getting very deep! Decide how does adjustment of VR4_A7 affect dPotAnchorSettings vs. dPotSettings: Simultaneously applies the same (current minus previous VR4_A7 offset) to both just before writeSettingToAsingleDPot for all
//                if( dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] != dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] - ( VRsandbox[ VR3_A6 ] / 256  ) ) /*not all the VR value could get used in the COUNTER_BALANCING_SOLVENT settings, then....*/
//                { ;
//                    dPotSettings[ SOLVENT + MSB ] = min( max( dPotAnchorSettings[ SOLVENT + MSB ] /*+ remainder*/, 256 ), 0 );
//                    dPotSettings[ SOLVENT + LSB ] = min( max( dPotAnchorSettings[ SOLVENT + LSB ] /*+ remainder*/, 256 ), 0 );
//                }
                VRsandbox[ VR1_A2 ] = analogRead( A0 );  //We are going to decide if we neeed to reference (so save) the previous reading.  We also need to decide whether to carry or borrow to keep an in-band signal in its band.
                VRsandbox[ VR3_A6 ] = analogRead( A6 ); //update them
                VRsandbox[ VR4_A7 ] = analogRead( A7 ); //update them
                if( ( VRsandbox[ VR1_A2 > 700 ] ) || ( VRsandbox[ VR1_A2 ] < 180 ) ) //if outside these boundaries, be abrupt when user is cranking on VR3_A6 or VR4_A7
                {//outside the band
//Here comparing with below sure looks like we are mixing LSB/MSB 
//#error The problem is hardware hysteresis!  Likely due to guard ring leakage into guarded traces somewhere.
                    if( ( ( VRsandbox[ VR3_A6 ] == 1023 ) && ( dPotSettings[ SOLVENT + MSB ] != 256 ) ) || ( ( VRsandbox[ VR3_A6 ] != 1023 ) && ( dPotSettings[ SOLVENT + MSB ] != VRsandbox[ VR3_A6 ] / 4 ) ) )
                    {
                        dPotSettings[ SOLVENT + MSB ] = VRsandbox[ VR3_A6 ] / 4;//min( max( dPotAnchorSettings[ SOLVENT + MSB ] + ( VRsandbox[ VR3_A6 ] / 256 ), 0 ), 256 );
                        if( VRsandbox[ VR3_A6 ] == 1023 ) dPotSettings[ SOLVENT + MSB ]++;
                        writeSettingToAsingleDPot( SOLVENT + MSB, dPotSettings[ SOLVENT + MSB ] );  //dPot3 //non-inverting , affects U5
                        Serial.print( F( " wrote <" ) );
                        Serial.print( dPotSettings[ SOLVENT + MSB ] );
                        Serial.print( F( "> to SOLVENT + MSB dPot " ) );
                    }
    
                    if( ( ( VRsandbox[ VR4_A7 ] == 1023 ) && ( dPotSettings[ SOLVENT + MSB ] != 256 ) ) || ( ( VRsandbox[ VR4_A7 ] != 1023 ) && ( dPotSettings[ SOLVENT + MSB ] != VRsandbox[ VR4_A7 ] / 4 ) ) )
                    {
                        dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] = VRsandbox[ VR4_A7 ] / 4;//min( max( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] - ( VRsandbox[ VR3_A6 ] / 256 ), 0 ), 256 );
                        if( VRsandbox[ VR4_A7 ] == 1023 ) dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ]++;
                        writeSettingToAsingleDPot( COUNTER_BALANCING_SOLVENT + MSB, dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] ); //dPot1  //inverting  MSB, affects U6 needs to be dPot what? used to be 1
                        Serial.print( F( " wrote <" ) );
                        Serial.print( dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] );
                        Serial.print( F( "> to COUNTER_BALANCING_SOLVENT + MSB dPot " ) );
        //                Serial.print( COUNTER_BALANCING_SOLVENT + MSB ); //needs to be dPot 1
    
                    }
                }
                else
                {// be less abrupt, notice the offset of 2 before changing
//Here comparing with below sure looks like we are mixing LSB/MSB 
//#error The problem is hardware hysteresis!  Likely due to guard ring leakage into guarded traces somewhere.
                    if( ( ( VRsandbox[ VR3_A6 ] == 1023 ) && ( dPotSettings[ SOLVENT + MSB ] != 256 ) ) || ( ( VRsandbox[ VR3_A6 ] != 1023 ) && ( dPotSettings[ SOLVENT + MSB ] != VRsandbox[ VR3_A6 ] / 4 ) ) )
                    { //only change if two clicks are needed
                        dPotSettings[ SOLVENT + MSB ] = ( dPotSettings[ SOLVENT + MSB ] > ( VRsandbox[ VR3_A6 ] / 4 ) ) ? \
                        ( ( dPotSettings[ SOLVENT + MSB ] > ( ( VRsandbox[ VR3_A6 ] / 4 ) + 2 ) ) ? ( VRsandbox[ VR3_A6 ] / 4 ) : dPotSettings[ SOLVENT + MSB ] ) : \
                        ( ( ( dPotSettings[ SOLVENT + MSB ] + 2 ) < ( VRsandbox[ VR3_A6 ] / 4 ) ) ? ( VRsandbox[ VR3_A6 ] / 4 ) : dPotSettings[ SOLVENT + MSB ] );//min( max( dPotAnchorSettings[ SOLVENT + MSB ] + ( VRsandbox[ VR3_A6 ] / 256 ), 0 ), 256 );
                        if( VRsandbox[ VR3_A6 ] == 1023 ) dPotSettings[ SOLVENT + MSB ]++;
                        writeSettingToAsingleDPot( SOLVENT + MSB, dPotSettings[ SOLVENT + MSB ] );  //dPot3 //non-inverting , affects U5
                        Serial.print( F( " wrote <" ) );
                        Serial.print( dPotSettings[ SOLVENT + MSB ] );
                        Serial.print( F( "> to SOLVENT + MSB dPot " ) );
                    }
    
                    if( ( ( VRsandbox[ VR4_A7 ] == 1023 ) && ( dPotSettings[ SOLVENT + MSB ] != 256 ) ) || ( ( VRsandbox[ VR4_A7 ] != 1023 ) && ( dPotSettings[ SOLVENT + MSB ] != VRsandbox[ VR4_A7 ] / 4 ) ) )
                    {
                        dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] = ( dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] > ( VRsandbox[ VR4_A7 ] / 4 ) ) ? \
                        ( ( dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] > ( ( VRsandbox[ VR4_A7 ] / 4 ) + 2 ) ) ? ( VRsandbox[ VR4_A7 ] / 4 ) : dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] ) : \
                        ( ( ( dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] + 2 ) < ( VRsandbox[ VR4_A7 ] / 4 ) ) ? ( VRsandbox[ VR4_A7 ] / 4 ) : dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] );
                        if( VRsandbox[ VR4_A7 ] == 1023 ) dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ]++;
                        writeSettingToAsingleDPot( COUNTER_BALANCING_SOLVENT + MSB, dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] ); //dPot1  //inverting  MSB, affects U6 needs to be dPot what? used to be 1
                        Serial.print( F( " wrote <" ) );
                        Serial.print( dPotSettings[ COUNTER_BALANCING_SOLVENT + MSB ] );
                        Serial.print( F( "> to COUNTER_BALANCING_SOLVENT + MSB dPot " ) );
        //                Serial.print( COUNTER_BALANCING_SOLVENT + MSB ); //needs to be dPot 1
    
                    }
                    
                }

                VRsandbox[ VR1_A2 ] = analogRead( A2 );
                VRsandbox[ VR2_A3 ] = analogRead( A3 );
                if( ( ( VRsandbox[ VR1_A2 ] == 1023 ) && ( dPotSettings[ SOLVENT + LSB ] != 256 ) ) || ( ( VRsandbox[ VR1_A2 ] != 1023 ) && ( dPotSettings[ SOLVENT + LSB ] != VRsandbox[ VR1_A2 ] / 4 ) ) )
                {
                    dPotSettings[ SOLVENT + LSB ] = VRsandbox[ VR1_A2 ] / 4;//min( max( dPotAnchorSettings[ SOLVENT + LSB ] + ( VRsandbox[ VR3_A6 ] % 256 ), 0 ), 256 );
                    if( VRsandbox[ VR1_A2 ] == 1023 ) dPotSettings[ SOLVENT + LSB ]++;
                    writeSettingToAsingleDPot( SOLVENT + LSB, dPotSettings[ SOLVENT + LSB ] );   //dPot2, affects SOLVENT //dPot2
                    Serial.print( F( " wrote <" ) );
                    Serial.print( dPotSettings[ SOLVENT + LSB ] );
                    Serial.print( F( "> to SOLVENT + LSB dPot " ) );
//                Serial.print( SOLVENT + LSB ); //used to be dPot 2

                }
                if( ( ( VRsandbox[ VR2_A3 ] == 1023 ) && ( dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ] != 256 ) ) || ( ( VRsandbox[ VR2_A3 ] != 1023 ) && ( dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ] != VRsandbox[ VR2_A3 ] / 4 ) ) )
                {
                    dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ] = VRsandbox[ VR2_A3 ] / 4;//min( max( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] - ( VRsandbox[ VR2_A3 ] % 256 ), 0 ), 256 );
                    if( VRsandbox[ VR2_A3 ] == 1023 ) dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ]++;
                    writeSettingToAsingleDPot( COUNTER_BALANCING_SOLVENT + LSB, dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ] ); //dPot0
                    Serial.print( F( " wrote <" ) );
                    Serial.print( dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ] );
                    Serial.print( F( "> to COUNTER_BALANCING_SOLVENT + LSB dPot " ) );
                }    

//                Serial.print( COUNTER_BALANCING_SOLVENT + LSB ); //needs to be dPot what? used to be 0



//                Serial.print( SOLVENT + MSB ); //used to be dPot 3
/*
                Serial.print( F( " wrote <" ) );
//                    Serial.print( dPot2_setting );
                Serial.print( F( "> to " ) );
                Serial.print( F( " dPot2" ) );
//                if( start_dPot_setting != U5[ 1 ] ) { U5[ 1 ] = start_dPot_setting; writeSettingToAsingleDPot( SOLVENT + MSB, U5[ 1 ] ); }   //non-inverting , affects U5
                Serial.print( F( " wrote <" ) );
//                    Serial.print( start_dPot_setting );
                Serial.print( F( "> to " ) );
                Serial.print( F( " dPot3" ) );
    */
    
    
        //        dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] = 21;  //inverting
        //            delay( 50 );
          //      }
                for( uint8_t i = 0; i < 25; i++ )
                {
                    Serial.print( F( " 0= " ) );
                    Serial.print( 0 );
                    Serial.print( F( " analogRead(A0)= " ) );
                    Serial.print( analogRead( A0 ) );  //IF GREATER THAN 307 OR LESS THAN 305 ADJUST DPOTS TO BRING IT BACK
/*
                    if( analogRead( A0 ) > 607 ) if( ( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] ) == 256 ) runTimeOffsetLSB = -1;
                    else if( analogRead( A0 ) < 205 ) runTimeOffsetLSB = 1;
                    else goto ANALOG0_READING_FINE; */
//                    dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] = min( max( dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] - ( VRsandbox[ VR3_A6 ] % 256 ), 0 ), 256 );
//                    writeSettingToAsingleDPot( COUNTER_BALANCING_SOLVENT + LSB, dPotSettings[ COUNTER_BALANCING_SOLVENT + LSB ] ); //dPot0
ANALOG0_READING_FINE:
                    Serial.print( F( " analogRead(A1)= " ) );
                    Serial.print( analogRead( A1 ) );
//                    Serial.print( F( " analogRead(A6)= " ) );
//                    Serial.print( analogRead( A6 ) );
//                    Serial.print( F( " analogRead(A7)= " ) );
//                    Serial.print( analogRead( A7 ) );
                    Serial.print( F( " 1024= " ) );
        //            Serial.print(  dPotAnchorSettings[ which_dpot_index ] );
        //            Serial.print( F( " which_dpot_index=<" ) );
        //            Serial.print(  which_dpot_index );
        //            Serial.print( F( "> " ) );
                    Serial.println( 1024 );
                    if( digitalRead( YELLOW_LED_PIN ) == HIGH ) digitalWrite( YELLOW_LED_PIN, LOW);
                    if( digitalRead( RED_LED_PIN ) == HIGH ) digitalWrite( RED_LED_PIN, LOW);

                    delay( 1 );
                }
/*
    //            writeSettingToAsingleDPot( 0, dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + LSB ] );  //inverting - this is the reduced effect dPot, affects U6
                    Serial.print( F( " wrote <" ) );
                    Serial.print( dPot0_setting );
                    Serial.print( F( "> to " ) );
                    Serial.print( F( " dPot0" ) );
    //            writeSettingToAsingleDPot( 1, dPotAnchorSettings[ COUNTER_BALANCING_SOLVENT + MSB ] );  //inverting MSB, affects U6
                    Serial.print( F( " wrote <" ) );
                    Serial.print( dPot1_setting );
                    Serial.print( F( "> to " ) );
                    Serial.print( F( " dPot1" ) );
    //            writeSettingToAsingleDPot( 2, dPotAnchorSettings[ SOLVENT + LSB ] );  //1 amplitude can = amplitude of about 12-15 of index 0 where 0 at setting of 3, affects U5
                    Serial.print( F( " wrote <" ) );
                    Serial.print( dPot2_setting );
                    Serial.print( F( "> to " ) );
                    Serial.print( F( " dPot2" ) );
                if( end_dPot_setting != dPotAnchorSettings[ SOLVENT + MSB ] ) { dPotAnchorSettings[ SOLVENT + MSB ] = end_dPot_setting; writeSettingToAsingleDPot( SOLVENT + MSB, dPotAnchorSettings[ SOLVENT + MSB ] ); }   //non-inverting , affects U5
                    Serial.print( F( " wrote <" ) );
                    Serial.print( end_dPot_setting );
                    Serial.print( F( "> to " ) );
                    Serial.print( F( " dPot3" ) );
    //        dPotAnchorSettings[ 1 ] = 22;  //inverting
    //            delay( 500 );
                for( uint8_t i = 0; i < 25; i++ )
                {
                    Serial.print( F( " 0= " ) );
                    Serial.print( 0 );
                    Serial.print( F( " analogRead(A0)= " ) );
                    Serial.print( analogRead( A0 ) );
                    Serial.print( F( " analogRead(A1)= " ) );
                    Serial.print( analogRead( A1 ) );
                    Serial.print( F( " analogRead(A6)= " ) );
                    Serial.print( analogRead( A6 ) );
                    Serial.print( F( " analogRead(A7)= " ) );
                    Serial.print( analogRead( A7 ) );
                    Serial.print( F( " 1024= " ) );
        //            Serial.print(  dPotAnchorSettings[ which_dpot_index ] );
        //            Serial.print( F( " which_dpot_index=<" ) );
        //            Serial.print(  which_dpot_index );
        //            Serial.print( F( "> " ) );
                    Serial.println( 1024 );
                    delay( 1 );
                }
*/
//            delay( 500 );
//            writeSettingToAsingleDPot( which_dpot_index, dPotAnchorSettings[ which_dpot_index ] );
//            dPotAnchorSettings[ which_dpot_index ] += step_per_dPot_change;
//            if( ( ( step_per_dPot_change > 0 ) && ( dPotAnchorSettings[ which_dpot_index ] > end_dPot_setting ) ) || ( ( step_per_dPot_change < 0 ) && ( dPotAnchorSettings[ which_dpot_index ] < end_dPot_setting ) ) ) 
/*                { dPotAnchorSettings[ which_dpot_index ] = start_dPot_setting; which_dpot_index++; if( which_dpot_index > end_dPot_index ) 
                    which_dpot_index = start_dPot_index; 
                    dPotAnchorSettings[ which_dpot_index ] = start_dPot_setting; } */
        }
#endif

/******************************************************************************
    Tuning process:
    1.  Ensure a DUT of a conductance value between minimum and maximum is connected.  Otherwise illuminate & extinguish red & yellow LED and recheck
    2.  Extinguish red and yellow LEDs which illuminates green LED
    3.  MAYBE:  Ensure U5 &/or stage is at least 2.5 to 3 uA
    4.  Adjust U5 &/or U6 as needed for A0 to equal A1
    5.  Begin to continuously display A0 and ADC1 levels, adjusting U5 &/or U6 as needed at every reading






If the entire dPotPins[] and dPotAnchorSettings[] did NOT get filled, or some DPots 
aren't being used as in a test so need to be set to zero, insert code here either
to fill out the arrays and/or set the unused DPots to desired settings:*/
//        writeSettingToAsingleDPot( DPotPin, setting, THIS_IS_OVERT_PIN_NUMBER_INSTEAD_OF_INDEX );
/*******************************************************************************/
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "DPots set up.\n" ) );
#endif
#endif
#elif ( LM334_BRIDGES > 1 )
#error This sketch is not entirely able to handle multiple digipot bridges at this revision level
#endif
#endif

  
  

#ifdef COMPILE_FOR_DIAGS_ONLY 
    #ifndef DIAGS_STEP4
        uint8_t which_dpot_index = 0;
        dPotSettings[ which_dpot_index ] = 0;
        while( !Serial.available() )
        {
            Serial.print( 0 );
            Serial.print( F( " " ) );
            Serial.print( analogRead( A0 ) );
            Serial.print( F( " " ) );
            Serial.print( analogRead( A3 ) );
            Serial.print( F( " " ) );
            Serial.print(  dPotSettings[ which_dpot_index ] );
            Serial.print( F( " which_dpot_index=<" ) );
            Serial.print(  which_dpot_index );
            Serial.print( F( "> " ) );
            Serial.println( 1024 );
            writeSettingToAsingleDPot( which_dpot_index, dPotSettings[ which_dpot_index ] );
            dPotSettings[ which_dpot_index ]++; //analogRead( A3 ) / 4;
            if( dPotSettings[ which_dpot_index ] > 256 ) { dPotSettings[ which_dpot_index ] = 0; which_dpot_index++; if( which_dpot_index > 0 ) which_dpot_index = 0; dPotSettings[ which_dpot_index ] = 0; }
            delay( 10 );
        }
        Serial.print( F( "When ready to continue, re-compile the diagnostics sketch with the macro \"DIAGS_STEP4\" defined instead\n" ) );
        Serial.print( F( "of \"DIAGS_STEP3\" and unsolder any VR from pin 4 of U3, replacing it with an R to GNDA from that pin and\n" ) );
        Serial.print( F( "pin 5 of U3\n" ) );
        Serial.print( F( "then upload the sketch and start the plotter tool instead of this monitor tool\n" ) );
        while( !Serial.available() );
        while( Serial.available() );
    #else
        
    #endif
#endif









millisStart = millis();
#if defined LEGS_PER_DPOT_STYLE_BRIDGE
#ifdef DEBUG
  while( !Serial && ( millis() - millisStart < 8000 ) );
  Serial.println( F( "Digi pots set up" ) );
#endif
#endif
#if ( OUTBOARDS_PLOTTED > 0 )
#if ( RED_LED_PIN && YELLOW_LED_PIN )
    for( uint8_t whichOutboardADCindex = 0; whichOutboardADCindex < OUTBOARDS_PLOTTED; whichOutboardADCindex++)
    {
        pinMode( RED_LED_PIN + ( 2 * whichOutboardADCindex ), OUTPUT );
        digitalWrite( RED_LED_PIN + ( 2 * whichOutboardADCindex ), LOW);
        pinMode( YELLOW_LED_PIN + ( 2 * whichOutboardADCindex ), OUTPUT );
        digitalWrite( YELLOW_LED_PIN + ( 2 * whichOutboardADCindex ), LOW);
    }
#endif
#if !( ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD )
  analogReference( DEFAULT ); //This is the voltage level of max bit value on analog input
#else
  analogReference( AR_DEFAULT ); //
#endif
#endif
#ifdef DEBUG
  while( !Serial && ( millis() - millisStart < 8000 ) );
  Serial.print( F( "Starting setup with SDA & SCL & SCK & A4 & A5 & INDEX_OF_OUTBOARDS =" ) );
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
  Serial.print( F( "OUTBOARDS_PLOTTED " ) );
  Serial.println( OUTBOARDS_PLOTTED );
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
#if ( OUTBOARDS_PLOTTED > 0 )
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
        #define MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT OUTBOARDS_PLOTTED
        #ifdef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
            #define RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT INBOARDS_PLOTTED
        #endif
    #else
        #define MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT 0
        #define ( OUTBOARDS_PLOTTED + RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT INBOARDS_PLOTTED )
    #endif
  */
#ifdef DEBUG
  millisStart = millis();
  while( !Serial && ( millis() - millisStart < 8000 ) );
  //                    Serial.print( F( "MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT " ) );
  //                    Serial.println( MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT );
  //                    Serial.print( F( "RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT " ) );
  //                    Serial.println( RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT );
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "Initializing HX711..." ) );
#endif
#endif
  /*
     With the library being used, the .begin() method is not needed if the HX711 was declared earlier prior to setup().  The reason I'm doing it here is simply to suggest some measure of future consistency across all ADCs since other ADC libraries may not allow one or the other...
  */
  hx711.begin( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, HIGHEST_SENSI_PGA_GAIN_FACTOR );  // if the third parameter is ommited the default gain value 128 & channel A is used by the library
#ifdef DEBUG
  millisStart = millis();
  while( !Serial && ( millis() - millisStart < 8000 ) ); //We limit the time to wait for serial ready
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.println( F( "done initializing HX711." ) );
#endif
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
  //    if( OUTBOARDS_PLOTTED + INBOARDS_PLOTTED > 1 ) linespaceParameters[ 0 ].ZeroOfThisPlotLinespace = PLOTTER_MAX_SCALE - HEIGHT_OF_A_PLOT_LINESPACE;

#ifdef DEBUG
  while( !Serial );
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.println( F( "The following numbers count up to the highest index of linespaces to be displayed:" ) );
#endif
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
    Serial.print( F( ", Line<1852> linespacesIndex =" ) );
    Serial.print( linespacesIndex );
    Serial.print( F( ", Line<1854> masterReadingsArrayIndex =" ) );
    Serial.print( masterReadingsArrayIndex );
    Serial.print( F( " " ) );
#endif
#if ( ( not defined COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) && ( OUTBOARDS_PLOTTED > 0 ) )
    #define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG HALF_HEIGHT_OF_A_PLOT_LINESPACE
#endif

//The next line quarantined places the outboard ADCs at the bottom of the screen, which I felt was not the best way.  It is closely related to other lines that must be quarantined also
//    linespaceParameters[ linespacesIndex ].HighLimitOfThisPlotLinespace = ( NUMBER_OF_LINESPACES - linespacesIndex ) * HEIGHT_OF_A_PLOT_LINESPACE;
    linespaceParameters[ linespacesIndex ].HighLimitOfThisPlotLinespace = ( linespacesIndex + 1 ) * HEIGHT_OF_A_PLOT_LINESPACE;


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
    Serial.print( F( "linespaceParameters[<" ) );
    Serial.print( linespacesIndex );
    Serial.print( F( ">].HighLimitOfThisPlotLinespace ==" ) );
    Serial.print( linespaceParameters[ linespacesIndex ].HighLimitOfThisPlotLinespace );
    Serial.print( F( ", ZeroOfThisPlotLinespace ==" ) );
    Serial.print( linespaceParameters[ linespacesIndex ].ZeroOfThisPlotLinespace );
    Serial.print( F( ", LastReferencePinPlotPointOrLastMagnifiedPlotPoint ==" ) );
    Serial.print( linespaceParameters[ linespacesIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
    Serial.print( F( ", PreviousUnmagnifiedReading ==" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading );
    Serial.print( F( ", CurrentUnmagnifiedReading ==" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( ", IndexInlinespaceParametersArray ==" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray );
    if( linespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 )
    {
      Serial.print( F( ", + 1 PreviousUnmagnifiedReading ==" ) );
      Serial.print( masterReadingsArray[ masterReadingsArrayIndex + 1 ].PreviousUnmagnifiedReading );
      Serial.print( F( ", + 1 CurrentUnmagnifiedReading ==" ) );
      Serial.print( masterReadingsArray[ masterReadingsArrayIndex + 1 ].CurrentUnmagnifiedReading );
      Serial.print( F( ", + 1 IndexInlinespaceParametersArray ==" ) );
      Serial.print( masterReadingsArray[ masterReadingsArrayIndex + 1 ].IndexInlinespaceParametersArray );
    }
    Serial.println();
#endif
    masterReadingsArrayIndex++;
    if( linespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) masterReadingsArrayIndex++; //skip the one we had to take care of in this linepsace iteration
  }
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "Plotting rising timing line: " ) );
#endif
  plotTimingLineGoingUp( false ); //The false makes all traces originate at global zero.  It seems to look better that way
  //no calls using analogPinArray can be made prior to now.
  //Next the pin translation table is allocated and filled the Analog Input pins needed
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "malloc'd [" ) );
#endif

#if ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED + INBOARDS_PLOTTED > 0 )
  analogPinArray = ( uint8_t * )malloc( max( INBOARDS_PLOTTED, LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED ) );
    #if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
      Serial.print( max( INBOARDS_PLOTTED, LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED ) );
    #endif
#else
    #if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
      Serial.print( 0 );
    #endif
#endif
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.println( F( "] bytes ram for the inboard Analog Input pins needed" ) );
#endif

#if ( INBOARDS_PLOTTED > 0 ) || ( defined DPOTS )
  //Hereafter is the pattern.  If you have more analog pins, add them according to the pattern.
#ifdef NUM_ANALOG_INPUTS
#ifdef PIN_A0
  for( uint8_t i = 0; i < max( INBOARDS_PLOTTED, LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED ); i++ )
  {
//    *( analogPinArray + i ) = i; //Won't work for Leonardo's upper set where A6 is on D4 and equals 24
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
  for( uint8_t i = 0; i < max( INBOARDS_PLOTTED, LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED ); i++ )
    *( analogPinArray + i ) = i + FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES;
#endif //end of PIN_A0 check
#endif
#endif
  while( !Serial /*|| sdcard is online*/); // wait for serial port to connect. Needed for Leonardo's native USB
#ifdef DEBUG
  Serial.println( F( "DEBUG is defined." ) );
  for( uint8_t i = 0; i < max( INBOARDS_PLOTTED, LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED ); i++ )
  {
        Serial.print( F( " analogPinArray[" ) );
        Serial.print( i );
        Serial.print( F( "]=<" ) );
        Serial.print( *( analogPinArray + i ) );
        Serial.print( F( ">" ) );
  }
  for( uint8_t i = 0; i < DPOTS; i++ )
  {
        Serial.print( F( " dPotPins[" ) );
        Serial.print( i );
        Serial.print( F( "]=<" ) );
        Serial.print( *( dPotPins + i ) );
        Serial.print( F( ">" ) );
  }
#endif

#if ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 )
    for( uint8_t legIndex = 0; legIndex < DPOT_LEGS; legIndex++ )
    {
        legLSBsettingUnitsTimes64PerAnalogInputUnit[ legIndex ] = 0; //Will have to remain this way until EEPROM is untilized  //TODO: start with the EEPROM stored legLSBsettingUnitsTimes64PerAnalogInputUnit
        analogInputUnitsTimes64PerMSBLegSettingUnit[ legIndex ] = 0; //Will have to remain this way until EEPROM is untilized  //TODO: start with the EEPROM stored legLSBsettingUnitsTimes64PerAnalogInputUnit
        startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ legIndex ] = 0; //Will have to remain this way until EEPROM is untilized  //TODO: start with the EEPROM stored legLSBsettingUnitsTimes64PerAnalogInputUnit
        startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ legIndex ] = 0; //Will have to remain this way until EEPROM is untilized  //TODO: start with the EEPROM stored legLSBsettingUnitsTimes64PerAnalogInputUnit
    }
#endif
#ifdef SD_CHIP_SELECT_PIN
    #define SDCARD_FILE_NAME "gwaamc.dat"
   if( !SD.begin( SD_CHIP_SELECT_PIN ) )
   {
    #if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
            Serial.print( F( "Failed SD card initialize code=<" ) );
            Serial.print( SD.begin( SD_CHIP_SELECT_PIN ) );
    #endif
    SDCardFailMsg:
    #if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
            Serial.print( F( ">. Disable definition of SD_CARD_STORAGE_CS_PIN and re-compile or fix the SD card problem" ) );
            Serial.flush();
    #endif
            pinMode( LED_BUILTIN, OUTPUT );
            while( true ) //Ends execution
            {
                const char msg[] = { '.', '.', '.', 0,/*S*/\
                              '-', '.', '.', 0,       /*D*/\
                              0,\
                              '-', '.', '-', '.', 0,  /*C*/\
                              '.', '-', 0,            /*A*/\
                              '.', '-', '.', 0,       /*R*/\
                              '-', '.', '.', 0 };     /*D*/
                blinkMorseCode( msg, 7 );
                delay( 900 ); //without the delays we would have to substitute some no-op semicolons
            } //Ends execution here
       }
       File sdcardFile = SD.open( SDCARD_FILE_NAME, FILE_WRITE );
        if( !sdcardFile )
       {
    #if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
            Serial.print( F( "Failed SD card file " ) );
            Serial.print( F( SDCARD_FILE_NAME ) );
            Serial.print( F( " returned error code from open for write attempt=<" ) );
            Serial.print( SD.open( SDCARD_FILE_NAME, FILE_WRITE ) );
    #endif
                goto SDCardFailMsg;
       }
        sdcardFile.close();
#endif
#if ( not defined __LGT8FX8E__ ) && ( defined DEBUG )
    Serial.print( F( "   Operator convenience delay so operator can prepare as needed..." ) );
    delay( 5000 );
#endif
#ifdef DEBUG
    Serial.println();
    Serial.println( F( "Done delaying for operator convenience or hardware init " ) );
    Serial.println( F( "Some running parameters:" ) );
    Serial.print( F( "analogPinArray=<" ) );
    Serial.print( (unsigned long)analogPinArray );
    Serial.println( F( ">" ) );
#if defined LEGS_PER_DPOT_STYLE_BRIDGE && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( INBOARDS_PLOTTED < DPOT_LEGS )
  for( uint8_t i = 0; i < DPOT_LEGS; i++ )
#else
  for( uint8_t i = 0; i < INBOARDS_PLOTTED; i++ )
#endif
    {
        pinMode( *( analogPinArray + i ), INPUT );
        bitSet( DIDR0, i );
        Serial.print( F( "<" ) );
        Serial.print( *( analogPinArray + i ) );
        Serial.println( F( ">" ) );
        
        Serial.print( F( "PLOTTER_MAX_SCALE=<" ) );
        Serial.print( PLOTTER_MAX_SCALE );
        Serial.print( F( "> legLSBsettingUnitsTimes64PerAnalogInputUnit[ i ]=<" ) );
        Serial.print( legLSBsettingUnitsTimes64PerAnalogInputUnit[ i ] );
        Serial.print( F( "> and ( uint32_t )( OUTBOARDS_PLOTTED + INBOARDS_PLOTTED )=<" ) );
        Serial.print( ( uint32_t )( OUTBOARDS_PLOTTED + INBOARDS_PLOTTED ) );
        Serial.println( F( ">" ) );
    }
    //add other prints here to your liking
#endif //end of DEBUG
  //Start of DPot MSB group settings storing for each DPot leg
#if ( DPOT_LEGS > 0 )
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( "Entering prefill construct DPOT_LEGS=<" ) );
    Serial.print( DPOT_LEGS );
    Serial.print( F( "> DPOTS_PER_BRIDGED_BARE_LEG=<" ) );
    Serial.print( DPOTS_PER_BRIDGED_BARE_LEG );
    Serial.print( F( "> " ) );
//Next is filling fast lookup arrays for MSB_SETTINGS_
#endif
    duringDPotAdjusting = true;
    Serial.print( F( "Line<3189>." ) );
    for( dPotLeg = 0; dPotLeg < DPOT_LEGS; dPotLeg++ )
    {
        uint8_t firstMSBdPotIndex = whatIsFirstMSBindexThisLeg( dPotLeg );
        uint8_t mSBgroupSize = whatIsMSBgroupSizeInThisDPotLeg( dPotLeg );
        MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) = 0;
        for( uint8_t mSBindexOffset = 0; mSBindexOffset < mSBgroupSize - 1; mSBindexOffset++ )
        {
            if( dPotSettings[ firstMSBdPotIndex + mSBindexOffset ] > MAX_DPOT_SETTG ) dPotSettings[ firstMSBdPotIndex + mSBindexOffset ] = MAX_DPOT_SETTG;
            MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg ) += dPotSettings[ firstMSBdPotIndex + mSBindexOffset ];
        }
        MSB_SETTINGS_AVAILABLE_THIS_LEG( dPotLeg ) = ( mSBgroupSize * MAX_DPOT_SETTG ) - MSB_SETTINGS_TOTAL_THIS_LEG( dPotLeg );
    }
    Serial.print( F( "Line<3210>." ) );

#if ( ( defined SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX ) && ( not defined LEAVE_POT_VALUES_ALONE_DURING_SETUP ) )
    Serial.print( F( "Line<3277>Starting linearity diags." ) );
#if ( SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX == ALL )
    #define LINEARITY_BRIDGE_RANGE_START ( 0 )
    #define BRIDGE_LINEARITY_RANGE_END ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES + BARE_DPOT_LEGS_UNBRIDGED )
#elif ( 0 < SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX + 0 )
    #define LINEARITY_BRIDGE_RANGE_START ( SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX )
    #define BRIDGE_LINEARITY_RANGE_END ( SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX + 1 )
#else   
    #define LINEARITY_BRIDGE_RANGE_START ( 0 )
    #define BRIDGE_LINEARITY_RANGE_END ( 1 )
#endif
#define NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ( BRIDGE_LINEARITY_RANGE_END - LINEARITY_BRIDGE_RANGE_START )
#if ( ( BRIDGE_LINEARITY_RANGE_END - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) > 0 )
    #define NUMBER_OF_LEGS_IN_LINEARITY_DIAGS ( ( NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS * 2 ) - ( BRIDGE_LINEARITY_RANGE_END - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) )
#else
    #define NUMBER_OF_LEGS_IN_LINEARITY_DIAGS ( NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS * 2 )
#endif
//The following vars get used in subtraction and needing the resultant sign preserved so they have to get signed. Best do it here
    int32_t startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ];
    int16_t startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ];
    int32_t startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ]; //This leaves an unused member for all BARE_DPOT_LEGS_UNBRIDGED but is of !no concern whatsoever! since this array is only setup() scope plus we actually do check status but will always be false
    int16_t startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ]; //This leaves an unused member for all BARE_DPOT_LEGS_UNBRIDGED but is of !no concern whatsoever! since this array is only setup() scope plus we actually do check status but will always be false
    int16_t lSBsettingsBakSignalSetupScopeOnly[ NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ];
    int16_t lSBsettingsBakReferenceSetupScopeOnly[ NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ];
    int16_t incomingInboardAnalogLevelSignalSetupScopeOnly[ NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ];
    int16_t incomingInboardAnalogLevelReferenceSetupScopeOnly[ NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ];
#if ( defined INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ) || ( defined INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC )
    int16_t steppingLSBallLegsSetting = MAX_DPOT_SETTG - abs( DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE ); //to avoid a carry or borrow being generated
#else
    int16_t steppingLSBallLegsSetting = MAX_DPOT_SETTG;
#endif
    int32_t mSBcurrentLimitSettingForLinearityTest = 50; //This applies to the last MSB only
    int32_t mSBgroupSettingsBakSignalSetupScopeOnly[ NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ];
    int32_t mSBgroupSettingsBakReferenceSetupScopeOnly[ NUMBER_OF_BRIDGES_IN_LINEARITY_DIAGS ];
//    uint32_t maxMSBsetting = 200;//MSB_SETTINGS_AVAILABLE_THIS_LEG;
    Serial.print( F( "Line<3409>LINEARITY_BRIDGE_RANGE_START=<" ) );
    Serial.print( LINEARITY_BRIDGE_RANGE_START );
    Serial.print( F( ">,Line<3411> BRIDGE_LINEARITY_RANGE_END=<" ) );
    Serial.print( BRIDGE_LINEARITY_RANGE_END );
    Serial.print( F( ">." ) );

    for( uint8_t bridge = LINEARITY_BRIDGE_RANGE_START; bridge < BRIDGE_LINEARITY_RANGE_END; bridge++ )
    {
#ifdef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
        incomingInboardAnalogLevelReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
#endif
        incomingInboardAnalogLevelSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
/*
        Serial.print( F( "Line<3425>bridge=<" ) );
        Serial.print( bridge );
        Serial.print( F( ">Line<3427>whatIsSignalLSBdPotIndexThisBridge( bridge )=<" ) );
        Serial.print( whatIsSignalLSBdPotIndexThisBridge( bridge ) );
        Serial.print( F( ">Line<3429>whatIsReferenceLSBdPotIndexThisBridge255IfNone( bridge )=<" ) );
        Serial.print( whatIsReferenceLSBdPotIndexThisBridge255IfNone( bridge ) );
        Serial.print( F( ">Line<3431>whatIsFirstSignalMSBindexThisBridge( bridge )=<" ) );
        Serial.print( whatIsFirstSignalMSBindexThisBridge( bridge ) );
        Serial.print( F( ">Line<3433>whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge )=<" ) );
        Serial.print( whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge ) );
        Serial.print( F( ">." ) );
*/
//        startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
//        startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
//        startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
//        startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
        startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
        startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
        startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
        startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
        lSBsettingsBakSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = dPotSettings[ whatIsSignalLSBdPotIndexThisBridge( bridge ) /*LSB of signal leg*/];
        if( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) 
        {
#ifdef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
            incomingInboardAnalogLevelReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0;
#endif
            lSBsettingsBakReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = dPotSettings[ whatIsReferenceLSBdPotIndexThisBridge255IfNone( bridge ) /*LSB of reference leg*/];
            writeSettingToAsingleDPot( whatIsReferenceLSBdPotIndexThisBridge255IfNone( bridge ), steppingLSBallLegsSetting );  //effect reference leg settings        
            mSBgroupSettingsBakReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge );       //store reference leg settings
            setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge ), MAX_DPOT_SETTG * whatIsMSBgroupSizeInThisBridge( bridge ) );
        }
        writeSettingToAsingleDPot( whatIsSignalLSBdPotIndexThisBridge( bridge ), steppingLSBallLegsSetting );           //effect signal leg settings
        mSBgroupSettingsBakSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge );                //store signal leg settings 
        setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstSignalMSBindexThisBridge( bridge ), MAX_DPOT_SETTG * whatIsMSBgroupSizeInThisBridge( bridge ) );
//        Serial.print( F( "Line<3459>" ) );
    }
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE ); //Need to make sure the level are not higher than target levels or make reference leg=signal leg now
//    Serial.print( F( "Line<3461>" ) );
    uint8_t stillSomeLegsLeft = NUMBER_OF_LEGS_IN_LINEARITY_DIAGS;
    uint8_t maxMSBgroupSizeInThisRange = 1;
    int32_t j = MAX_DPOT_SETTG; //since the unsigned version is 16 bits we need 17 bits in the signed version
    for( uint16_t whichMSBindex = 0; whichMSBindex < maxMSBgroupSizeInThisRange; whichMSBindex++ )
    {
/*
        Serial.print( F( "Line<3466>whichMSBindex=<" ) );
        Serial.print( whichMSBindex );
        Serial.print( F( "> maxMSBgroupSizeInThisRange=<" ) );
        Serial.print( maxMSBgroupSizeInThisRange );
        Serial.print( F( ">." ) );
*/
        for( j = MAX_DPOT_SETTG; j >= 0; j-- )
        {
            Serial.print( F( "Line<3473>" ) );
//This for loop simply adjusts the "whichMSBindex" dpot resistance setting downward in all bridges needing it (voltage goes positive b/c dpots are all in the positive half of their leg)
            for( uint8_t bridge = LINEARITY_BRIDGE_RANGE_START; bridge < BRIDGE_LINEARITY_RANGE_END; bridge++ )
            {//exit this loop when no more bridges have whichMSBindex MSB dpots
                if( whatIsMSBgroupSizeInThisBridge( bridge ) > maxMSBgroupSizeInThisRange ) maxMSBgroupSizeInThisRange = whatIsMSBgroupSizeInThisBridge( bridge );

                Serial.print( F( " Line <3477> Linearity dPot settings:MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE=<" ) );
                Serial.print( MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge ) );
                Serial.print( F( "> MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE=<" ) );
                Serial.print( MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) );
                Serial.print( F( "> startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ]=<" ) );
                Serial.print( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
                Serial.print( F( "> startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ]=<" ) );
                Serial.print( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
                Serial.print( F( ">, " ) );

                if( ( whichMSBindex == ( whatIsMSBgroupSizeInThisBridge - 1 ) && j < mSBcurrentLimitSettingForLinearityTest ) || whichMSBindex > ( whatIsMSBgroupSizeInThisBridge - 1 ) )
                { //This entire bridge has no setting margin left
                    continue;//go to next bridge
                }
                if( !startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )// && !leg_0_IsSignal_1_IsReference )
                {
                    setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstSignalMSBindexThisBridge( bridge ) + whichMSBindex, j, DONT_CONSOLIDATE_MSB_GROUP_SETTINGS_THIS_TIME );//For circuit testing, can compare consolidating run with not
                    Serial.print( F( " changed signal leg settings=<" ) );
                    Serial.print( j );
                    Serial.print( F( ">, " ) );
                }
                if( !startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] && ( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) )
                {
                    setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge ) + whichMSBindex, j, DONT_CONSOLIDATE_MSB_GROUP_SETTINGS_THIS_TIME );//For circuit testing, can compare consolidating run with not
                    Serial.print( F( " changed reference leg settings=<" ) );
                    Serial.print( j );
                    Serial.print( F( ">, " ) );
                }
            }
            readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
            for( uint8_t bridge = LINEARITY_BRIDGE_RANGE_START; bridge < BRIDGE_LINEARITY_RANGE_END; bridge++ )
            {
                if( ( whichMSBindex == ( whatIsMSBgroupSizeInThisBridge - 1 ) && j < mSBcurrentLimitSettingForLinearityTest ) || whichMSBindex > ( whatIsMSBgroupSizeInThisBridge - 1 ) )
                { //This entire bridge is done with this aspect of diags, ignore it
                    continue;//go to next bridge
                }
    #ifdef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
            //compare leg reading to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG and capture the first reading making it go lower
                if( !startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )
                { //This should probably check incomingInboardAnalogLevelSignalSetupScopeOnly instead
        #if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) ) //Notice we don't care if it is actually operating so we use macros defined even when not getting compiled for outboard ADCs.  Switch out the HX711 macro for whatever you need
                    if( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_OF_UNPLOTTED_ADC_AS_READ_RAW_BY_INBOARD_ANALOG )
        #else
                    if( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        #endif
                    {
//#error We need to examine in light of magnified traces and not superimposed traces and not intermixed (lm334 one each type plus bare bridged one each type)
    //Save this setting to calculate settingSteps/levelUnits ratios
//                        setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstSignalMSBindexThisBridge( bridge ), MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge ) + ( ( MAX_DPOT_SETTG / DPOT_RATIO ) / 4 )/*here we do have to consolidate*/ ); //Division by 4 will place the expected lsb pinpointing in the upper range so as to best minimize the effect of the inconsistent by one starting point
//                        setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstSignalMSBindexThisBridge( bridge ), MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge ) + 1 );//For circuit testing, can compare consolidating run with not
                        startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge );
                        incomingInboardAnalogLevelSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = masterReadingsArray[ ( bridge * 2 ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
/*
                        Serial.print( F( "Line<3523>first signal msb setting to hit desired CM level=<" ) );
                        Serial.print( j );
                        Serial.print( F( "> bridge=<" ) );
                        Serial.print( bridge );
                        Serial.print( F( "> ( masterReadingsArray.CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE )=<" ) );
                        Serial.print( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
                        Serial.print( F( "> startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly=<" ) );
                        Serial.print( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
                        Serial.print( F( "> MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE=<" ) );
                        Serial.print( MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge ) );
                        if( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) Serial.print( F( "> MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE=<" ) );
                        if( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) Serial.print( MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) );
                        Serial.print( F( ">, " ) );
*/
                        if( !( --stillSomeLegsLeft ) ) break;
                    }
                }
                if( !startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] && ( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) )
                { //This should probably check incomingInboardAnalogLevelReferenceSetupScopeOnly instead
        #if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) ) //Notice we don't care if it is actually operating
                    if( ( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) /*will exclude bare unbridged legs*/ && \
                    ( ( masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_OF_UNPLOTTED_ADC_AS_READ_RAW_BY_INBOARD_ANALOG ) )
        #else
                    if( ( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) /*will exclude bare unbridged legs*/ && \
                    ( ( masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) )
        #endif
                    {
//                        setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge ), MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) + ( ( MAX_DPOT_SETTG / DPOT_RATIO ) / 4 )/*here we do have to consolidate*/ ); //Division by 4 will place the expected lsb pinpointing in the upper range so as to best minimize the effect of the inconsistent by one starting point
//                        setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge ), MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) );//For circuit testing, can compare consolidating run with not
                        startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge );
                        incomingInboardAnalogLevelReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
/*
                        Serial.print( F( "Line<3555>first reference msb setting to hit desired CM level=<" ) );
                        Serial.print( j );
                        Serial.print( F( "> ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE )=<" ) );
                        Serial.print( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
                        Serial.print( F( "> startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReference=<" ) );
                        Serial.print( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
                        Serial.print( F( "> MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE=<" ) );
                        Serial.print( MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge ) );
                        Serial.print( F( "> MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE=<" ) );
                        Serial.print( MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) );
                        Serial.print( F( ">, " ) );
*/
                        if( !( --stillSomeLegsLeft ) ) break;
                    }
                }
    #endif
            }
            if( !stillSomeLegsLeft ) break;
        } //This loops through the MSB group setting range
        if( !stillSomeLegsLeft ) break;
    }
    Serial.print( F( "Line<3495>" ) );
//Done stepping both legs' MSB groups, now put them where they belong for LSB stepping or back to original if no LSB stepping indicated
    Serial.print( F( " " ) );
    Serial.print( linespaceParameters[ NUMBER_OF_LINESPACES - 1 ].HighLimitOfThisPlotLinespace * 0.95 ); //this prints a type cast float
    replotLastValuesForAllTraces( true );
    for( uint8_t bridge = LINEARITY_BRIDGE_RANGE_START; bridge < BRIDGE_LINEARITY_RANGE_END; bridge++ )
    {
        int32_t savedMSBsettingsThisLeg;
        if( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) )
        {   
            savedMSBsettingsThisLeg = MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge );
            Serial.print( F( "Line<3581>reference leg will go back, savedMSBsettingsThisLeg=<" ) );
            Serial.print( savedMSBsettingsThisLeg );
            if( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )
            {
               setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge ), ( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] + ( ( MAX_DPOT_SETTG / DPOT_RATIO ) / 4 ) )/*here we do have to consolidate*/ ); //Division by 4 will place the expected lsb pinpointing in the upper range so as to best minimize the effect of the inconsistent by one starting point
                Serial.print( F( "> line<3675> reference leg went back to<" ) );
                Serial.print( ( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] + ( ( MAX_DPOT_SETTG / DPOT_RATIO ) / 4 ) ) );
            }
            else
            {
                setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge ), mSBgroupSettingsBakReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] /*here we do have to consolidate*/);       //reference leg. First in case unbridged
                Serial.print( F( "> line<3681> reference leg went back to<" ) );
                Serial.print( mSBgroupSettingsBakReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
            }
            delay( 2 ); //Let levels settle
            readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );//b/c the next line needs the current reading
            analogInputUnitsTimes64PerMSBLegSettingUnit[ ( bridge * 2 ) + 1 ] = ( ( ( masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( incomingInboardAnalogLevelReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] ) ) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) / \
                ( MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) - savedMSBsettingsThisLeg );
            Serial.print( F( ">, masterReadingsArray[ ( bridge * <2> ) + <1> ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE=<" ) );
            Serial.print( masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
            Serial.print( F( ">, incomingInboardAnalogLevelReferenceSetupScopeOnly=<" ) );
            Serial.print( incomingInboardAnalogLevelReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
            Serial.print( F( ">, reference MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE=<" ) );
            Serial.print( MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) );
            Serial.print( F( ">, savedMSBsettingsThisLeg=<" ) );
            Serial.print( savedMSBsettingsThisLeg );
            Serial.print( F( ">, division is between<" ) );
            Serial.print( ( ( masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE - incomingInboardAnalogLevelReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] ) ) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) );
            Serial.print( F( ">and<" ) );
            Serial.print( MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) - savedMSBsettingsThisLeg );
            Serial.print( F( ">, reference analogInputUnitsTimes64PerMSBLegSettingUnit=<" ) );
            Serial.print( analogInputUnitsTimes64PerMSBLegSettingUnit[ ( bridge * 2 ) + 1 ] ); //evaluates to -1.  ????
            Serial.print( F( ">. " ) );
        }
        savedMSBsettingsThisLeg = MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge );
        Serial.print( F( ">, signal leg will go back, savedMSBsettingsThisLeg=<" ) );
        Serial.print( savedMSBsettingsThisLeg );//The 256 setting somehow gets changed to 259?
        Serial.print( F( ">, to dPot index=<" ) );
        Serial.print( whatIsFirstSignalMSBindexThisBridge( bridge ) );
        Serial.print( F( "> " ) );
        if( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )
        {
           setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstSignalMSBindexThisBridge( bridge ), ( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] + ( ( MAX_DPOT_SETTG / DPOT_RATIO ) / 4 ) )/*here we do have to consolidate*/ ); //Division by 4 will place the expected lsb pinpointing in the upper range so as to best minimize the effect of the inconsistent by one starting point
            Serial.print( F( " line<3710> signal leg went back to<" ) );
            Serial.print( ( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] + ( ( MAX_DPOT_SETTG / DPOT_RATIO ) / 4 ) )/*here we do have to consolidate*/ );
        }
        else
        {
            setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstSignalMSBindexThisBridge( bridge ), mSBgroupSettingsBakSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );                //signal leg
            Serial.print( F( "> line<3716> signal leg went back to<" ) );
            Serial.print( mSBgroupSettingsBakSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
        }
        delay( 2 ); //Let levels settle
        readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#define FUDGE_FACTOR_PERCENT_BECAUSE_TOO_BUSY_TO_GET_THE_FORMULA_ANY_CLOSER_THE_RATIONAL_WAY ( signed )( 115 )
        analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) ] = ( float )( ( float )FUDGE_FACTOR_PERCENT_BECAUSE_TOO_BUSY_TO_GET_THE_FORMULA_ANY_CLOSER_THE_RATIONAL_WAY / ( float )100 ) * \
( ( ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( incomingInboardAnalogLevelSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] ) ) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) / \
( MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge ) - savedMSBsettingsThisLeg ) );
        Serial.print( F( ">, masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE=<" ) );
        Serial.print( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
        Serial.print( F( ">, incomingInboardAnalogLevelSignalSetupScopeOnly=<" ) );
        Serial.print( incomingInboardAnalogLevelSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
        Serial.print( F( ">, MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE=<" ) );
        Serial.print( MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge ) );
        Serial.print( F( ">, signal analogInputUnitsTimes64PerMSBLegSettingUnit=<" ) );
        Serial.print( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( bridge ) ] );
        Serial.print( F( ">. " ) );
    }
    Serial.print( F( " " ) );
    Serial.print( linespaceParameters[ NUMBER_OF_LINESPACES - 1 ].HighLimitOfThisPlotLinespace * 0.95 );
    replotLastValuesForAllTraces( true );
    for( uint8_t bridge = LINEARITY_BRIDGE_RANGE_START; bridge < BRIDGE_LINEARITY_RANGE_END; bridge++ )
    {
//Save this analogLevel to calculate settingSteps/levelUnits ratios
        incomingInboardAnalogLevelSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
#ifdef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
        if( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) incomingInboardAnalogLevelReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
#endif
    
        Serial.print( F( " MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE=<" ) );
        Serial.print( MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge ) );
        Serial.print( F( "> MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE=<" ) );
        Serial.print( MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) );
        Serial.print( F( ">, " ) );
    }
//Those legs that never reached their level are characterized by !startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly or !startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly  
        //Proceed to step up on LSBs
    stillSomeLegsLeft = NUMBER_OF_LEGS_IN_LINEARITY_DIAGS - stillSomeLegsLeft;
    Serial.print( F( " " ) );
    Serial.print( linespaceParameters[ NUMBER_OF_LINESPACES - 1 ].HighLimitOfThisPlotLinespace * 0.7 );
    replotLastValuesForAllTraces( true );
    for( uint8_t bridge = LINEARITY_BRIDGE_RANGE_START; bridge < BRIDGE_LINEARITY_RANGE_END; bridge++ )
    {
        bool signalLegNotReachedBeyondLevel;// = true;
        bool referenceLegNotReachedBeyondLevel;// = true;
        signalLegNotReachedBeyondLevel = true;
        referenceLegNotReachedBeyondLevel = true;
        #if ( defined INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ) || ( defined INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC ) //to avoid a carry or borrow being generated
            for( ; steppingLSBallLegsSetting >= abs( DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE ); steppingLSBallLegsSetting-- ) //allow margin for square wave to decrement and increment since we can't deal with that inject code changing MSB group settings
        #else
            for( ; steppingLSBallLegsSetting >=0; steppingLSBallLegsSetting-- )
        #endif
            {
                if( signalLegNotReachedBeyondLevel ) writeSettingToAsingleDPot( whatIsSignalLSBdPotIndexThisBridge( bridge ), steppingLSBallLegsSetting );
                if( referenceLegNotReachedBeyondLevel && ( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) ) writeSettingToAsingleDPot( whatIsReferenceLSBdPotIndexThisBridge255IfNone( bridge ), steppingLSBallLegsSetting ); //TODO ensure all literal pin number references to writeSettingToAsingleDPot() send THIS_IS_OVERT_PIN_NUMBER_INSTEAD_OF_INDEX argument
                Serial.print( F( " Line<3532>whatIsSignalLSBdPotIndexThisBridge=<" ) );
                Serial.print( whatIsSignalLSBdPotIndexThisBridge( bridge ) );
                Serial.print( F( "> whatIsReferenceLSBDPotIndexThisBridge255IfNone=<" ) );
                Serial.print( whatIsReferenceLSBdPotIndexThisBridge255IfNone( bridge ) );
                Serial.print( F( ">, " ) );
                readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
    #ifdef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
                if( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )
                {

            #if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) )
                    if( ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) >= COMMON_MODE_LEVEL_FOR_MAX_GAIN_OF_UNPLOTTED_ADC_AS_READ_RAW_BY_INBOARD_ANALOG ) && \
                    !startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )
            #else
                    if( ( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) >= COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) && \
                    !startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )
            #endif
                    {
                        startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = steppingLSBallLegsSetting; //Stores this first find to be later averaged with first miss
                        startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0; //Stops this check
                    }
                }
                else if( startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )
                {
            #if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) )
                    if( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_OF_UNPLOTTED_ADC_AS_READ_RAW_BY_INBOARD_ANALOG )
            #else
                    if( ( masterReadingsArray[ whatIsSignalLegThisBridge( bridge ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
            #endif
                    {
//                        LSBsettingsPerLevelUnit = steppingLSBallLegsSetting - startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ];
//Ending setting needs to be halfway between steppingLSBallLegsSetting and startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ]: ( ( steppingLSBallLegsSetting + startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] ) >> 1 )
            #if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) ) 
                        legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( bridge ) ] = \
                            ( ( ( steppingLSBallLegsSetting + startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] + 2 /*2 is for rounding*/) >> 2 ) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION )) / ( incomingInboardAnalogLevelSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_OF_UNPLOTTED_ADC_AS_READ_RAW_BY_INBOARD_ANALOG );
            #else
                        legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( bridge ) ] = \
                            ( ( ( steppingLSBallLegsSetting + startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] + 2 /*2 is for rounding*/) >> 2 ) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) / ( incomingInboardAnalogLevelSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );
            #endif
                        Serial.print( F( "startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly=<" ) );
                        Serial.print( startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
                        Serial.print( F( ">, " ) );
//FIXME TODO - VERIFY ALGORITHM FOLLOWING LINE
                        writeSettingToAsingleDPot( whatIsSignalLSBdPotIndexThisBridge( bridge ), dPotSettings[ whatIsSignalLSBdPotIndexThisBridge( bridge ) ] + ( ( dPotSettings[ whatIsSignalLSBdPotIndexThisBridge( bridge ) ] - startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] ) / 2 ) ); //TODO ensure all literal pin number references to writeSettingToAsingleDPot() send THIS_IS_OVERT_PIN_NUMBER_INSTEAD_OF_INDEX argument
                        startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0; //do only after calculating all ratios
                        signalLegNotReachedBeyondLevel = false;
                        if( !( --stillSomeLegsLeft ) ) break;
                    }
                }
                if( startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] ) //assumed && bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) else startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[] could never have gotten to be true in the first place
                {
        #if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) )
                    if( ( ( masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) >= COMMON_MODE_LEVEL_FOR_MAX_GAIN_OF_UNPLOTTED_ADC_AS_READ_RAW_BY_INBOARD_ANALOG ) && \
                    !startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )
        #else
                    if( ( ( masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) >= COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) && \
                    !startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )
        #endif
                    {
                        startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = steppingLSBallLegsSetting; //Stores this first find to be later averaged with first miss
                        startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0; //Stops this check
                    }
                }
                else if( startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] )
                {

        #if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) )
                    if( ( masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_OF_UNPLOTTED_ADC_AS_READ_RAW_BY_INBOARD_ANALOG )
        #else
                    if( ( masterReadingsArray[ ( bridge * 2 ) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
        #endif
                    {
        #if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) ) 
                        legLSBsettingUnitsTimes64PerAnalogInputUnit[ ( bridge * 2 ) + 1 ] = ( float )( ( float )100 / ( float )FUDGE_FACTOR_PERCENT_BECAUSE_TOO_BUSY_TO_GET_THE_FORMULA_ANY_CLOSER_THE_RATIONAL_WAY ) * \
                            ( ( ( steppingLSBallLegsSetting + startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] + 2 /*2 is for rounding*/) >> 2 /*gets the average of the two*/) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) / ( incomingInboardAnalogLevelReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_OF_UNPLOTTED_ADC_AS_READ_RAW_BY_INBOARD_ANALOG );
        #else
                        legLSBsettingUnitsTimes64PerAnalogInputUnit[ ( bridge * 2 ) + 1 ] = ( float )( ( float )100 / ( float )FUDGE_FACTOR_PERCENT_BECAUSE_TOO_BUSY_TO_GET_THE_FORMULA_ANY_CLOSER_THE_RATIONAL_WAY ) * \
                            ( ( ( steppingLSBallLegsSetting + startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] + 2 /*2 is for rounding*/) >> 2 /*gets the average of the two*/) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) / ( incomingInboardAnalogLevelReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] - ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG );
        #endif
                        Serial.print( F( "startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly=<" ) );
                        Serial.print( startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
                        Serial.print( F( "> MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE=<" ) );
                        Serial.print( MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge ) );
                        Serial.print( F( "> MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE=<" ) );
                        Serial.print( MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) );
                        Serial.print( F( ">, " ) );
//                        LSBsettingsPerLevelUnitReference = steppingLSBallLegsSetting - startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ];
//Ending setting needs to be halfway between steppingLSBallLegsSetting and startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ]: ( ( steppingLSBallLegsSetting + startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] ) >> 1 )
//FIXME TODO - VERIFY ALGORITHM FOLLOWING LINE
                        writeSettingToAsingleDPot( whatIsReferenceLSBdPotIndexThisBridge255IfNone( bridge ), dPotSettings[ whatIsReferenceLSBdPotIndexThisBridge255IfNone( bridge ) ] + ( ( dPotSettings[ whatIsReferenceLSBdPotIndexThisBridge255IfNone( bridge ) ] - startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] ) / 2 ) ); //TODO ensure all literal pin number references to writeSettingToAsingleDPot() send THIS_IS_OVERT_PIN_NUMBER_INSTEAD_OF_INDEX argument
                        startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnitReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] = 0; //do only after calculating all ratios
                        referenceLegNotReachedBeyondLevel = false;
                        if( !( --stillSomeLegsLeft ) ) break;
                    }
                }
            }
    #endif
        Serial.print( F( "MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE=<" ) );
        Serial.print( MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( bridge ) );
        Serial.print( F( "> Line<3645>MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE=<" ) );
        Serial.print( MSB_SETTINGS_TOTAL_REFERENCE_THIS_BRIDGE( bridge ) );
        Serial.print( F( ">, " ) );
    } //Line 
/*    
    for( uint8_t bridge = LINEARITY_BRIDGE_RANGE_START; bridge < BRIDGE_LINEARITY_RANGE_END; bridge++ )
    {
        //Next, reset all of them back to their stored settings
            writeSettingToAsingleDPot( lSBdPotIndexThisLeg, lSBsettingsBakSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );           //signal leg
            setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstSignalMSBindexThisBridge( bridge ), mSBgroupSettingsBakSignalSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
           if( bridge < ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) )
           {
                writeSettingToAsingleDPot( whatIsReferenceLSBdPotIndexThisBridge255IfNone( bridge ), lSBsettingsBakReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );  //reference leg         
                setMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstReferenceMSBindexThisBridge255IfNone( bridge ), mSBgroupSettingsBakReferenceSetupScopeOnly[ bridge - LINEARITY_BRIDGE_RANGE_START ] );
           }
    }
*/
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#endif
#endif
#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) && ( defined LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER ) )
  for( uint8_t bridgeIndex = 0; bridgeIndex < OUTBOARDS_PLOTTED; bridgeIndex++ )
    counterForTraceOutOfRangeTooLong[ bridgeIndex ] = 0;
#endif
//TODO: Retrieve legLSBsettingUnitsPerAnalogInputUnit from EEPROM but verify EEPROM code number first 
#ifdef DEBUG
  Serial.println( F( "initial setup.  Entering calibration setup." ) );
#else
    Serial.println();
#endif
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  printDPotSettings();
  Serial.print( F( " Setting up LM334 and bare digipot bridge legs after prefill. " ) );
#endif
Serial.print( F( " DPOTS_IN_ALL_LM334_BRIDGES=<" ) );
Serial.print( DPOTS_IN_ALL_LM334_BRIDGES );
Serial.print( F( ">, DPOTS_IN_ALL_BARE_LEG_BRIDGES=<" ) );
Serial.print( DPOTS_IN_ALL_BARE_LEG_BRIDGES );
Serial.print( F( ">, DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED=<" ) );
Serial.print( DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED );
Serial.print( F( ">, LM334_BRIDGES=<" ) );
Serial.print( LM334_BRIDGES );
Serial.print( F( ">, BARE_DPOT_LEG_BRIDGES=<" ) );
Serial.print( BARE_DPOT_LEG_BRIDGES );
Serial.print( F( ">, BARE_DPOT_LEGS_UNBRIDGED=<" ) );
Serial.print( BARE_DPOT_LEGS_UNBRIDGED );
Serial.print( F( ">. " ) );

#if ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 )
    for( uint8_t legIndex = 0; legIndex < DPOT_LEGS; legIndex++ )
    {
        Serial.print( F( " legLSBsettingUnitsTimes64PerAnalogInputUnit[" ) );
        Serial.print( legIndex );
        Serial.print( F( "]=<" ) );
        Serial.print( legLSBsettingUnitsTimes64PerAnalogInputUnit[ legIndex ] );
        Serial.print( F( ">. " ) );
    }
#endif
#if defined AUTO_BRIDGE_BALANCING && not defined LEAVE_POT_VALUES_ALONE_DURING_SETUP
  for( uint8_t bridge = 0; bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES; bridge++ )
  { //while( oneReadingFromThisOutboardADC( bridge ) > HALF_HEIGHT_OF_A_PLOT_LINESPACE )
//NO NEED for this setDPotLegMidPoint DOES IT BASED ON THE SECOND ARG:    configureForReferenceLegWithBridgeIndex( uint8_t bridge );
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Calling setDPotLegMidPoint() for Legs of bridge <" ) );
    Serial.print( bridge );
    Serial.print( F( ">, reference leg first:" ) );
#endif
//BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0
//ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 0 //To maintain consistent effect with the above, associated macro, this gets applied inverted. This is in lieu of setting by reading the ADCs and zeroing them.

    uint32_t analogLegLevel;
//    analogLegLevel = bestGuessAnalogInputReading( ( bridge * 2 ) + 1, MOST_ACCURATE );
    analogLegLevel = masterReadingsArray[ whatIsSignalLegThisBridge( bridge) + 1 ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
    referenceLegLevelFromLastSettingIt[ bridge ] = ( analogLegLevel == COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ? REFERENCE_LEG_LEVEL_IS_OPTIMAL : ( analogLegLevel > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ? \
    REFERENCE_LEG_LEVEL_IS_HIGH : REFERENCE_LEG_LEVEL_IS_LOW;
    if( referenceLegLevelFromLastSettingIt[ bridge ] != REFERENCE_LEG_LEVEL_IS_OPTIMAL ) //Context is reference leg
    {
        Serial.print( F( "REFERENCE_LEG_LEVEL_IS<" ) );
        Serial.print( analogLegLevel );
        Serial.print( F( ">. " ) );
#if not ( ( defined SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX ) && ( not defined LEAVE_POT_VALUES_ALONE_DURING_SETUP ) )
        setDPotLegMidPoint( bridge, WORK_ON_THE_REFERENCE_LEG, READ_AND_PLOT_IN_EACH_LAP ); // ) //while false, the entire bridge is being zeroed into the desired balance
#endif
    }
    else
        Serial.print( F( "REFERENCE_LEG_LEVEL_IS_OPTIMAL. " ) );
    analogLegLevel = masterReadingsArray[ whatIsSignalLegThisBridge( bridge) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
    if( analogLegLevel != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 ) //Context is signal leg
    {
        Serial.print( F( "SIGNAL_LEG_LEVEL_IS<" ) );
        Serial.print( analogLegLevel );
        Serial.print( F( ">. " ) );
#if not ( ( defined SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX ) && ( not defined LEAVE_POT_VALUES_ALONE_DURING_SETUP ) )
        setDPotLegMidPoint( bridge, !WORK_ON_THE_REFERENCE_LEG, READ_AND_PLOT_IN_EACH_LAP, USE_OPPOSING_LEGS_LEVEL_AS_TARGET_LEVEL ); // ) //while false, the entire bridge is being zeroed into the desired balance
#endif
    }
    else
        Serial.print( F( "SIGNAL_LEG_LEVEL_IS_OPTIMAL. " ) );
    configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
#if ( defined ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 ) && ( ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 > 0 )
    offsetMSBdPotOrGroupValueUsingIndicesOnly( lSBdPotIndexThisLeg, ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 );
#endif
/*
#ifdef DIFFERENTIAL
      if( counterForTraceOutOfRangeTooLong[ bridge ]++ > 80 ) break; //Limited to prevent endless looping here
#endif
    }
    */
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( "Finished calling setDPotLegMidPoint() both legs of bridge." ) );
#endif
#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) )
    uint32_t readingOfADC = oneReadingFromThisOutboardADC( bridge );
    if( ( readingOfADC > 0 ) && ( readingOfADC < HEIGHT_OF_A_PLOT_LINESPACE - 1 ) )
    {
        int16_t retryLimit = 200;
        if( !highestLevelDifferentialBridgeSetpointing( bridge, retryLimit ) )
        {
            Serial.print( F( "Unable to balance bridge<" ) );
            Serial.print( bridge );
            Serial.print( F( ">: intent was that it now be within<" ) );
            Serial.print( retryLimit );
            Serial.print( F( "> LSB DPot setting from center point. Might you have an LSB DPot whose value needs more retries than that?" ) );
        }
    }
    else
    {
        Serial.print( F( "Error level from bridge<" ) );
        Serial.print( bridge );
        Serial.print( F( ": intent was that it now be reading within its range." ) );
    }
#endif
#if ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 )
#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) && ( defined LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER ) )
    counterForTraceOutOfRangeTooLong[ bridge ] = 0;  //size of this array is OUTBOARDS_PLOTTED, so there is one member per bridge but needs to be one per dpot bridge plus one per non-bridged dpot leg.  Assume both are the same for now
#endif
//    while( !setDPotLegMidPoint( bridge, !WORK_ON_THE_REFERENCE_LEG, READ_AND_PLOT_IN_EACH_LAP ) ); // == false ) //while false, the entire bridge is being zeroed into the desired balance
/*
#ifdef DIFFERENTIAL
      if( counterForTraceOutOfRangeTooLong[ bridge ]++ > 80 ) break; //Limited to prevent endless looping here
#endif
    }
    */

#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) && ( defined LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER ) )
    counterForTraceOutOfRangeTooLong[ bridge ] = 0;  //size of this array is OUTBOARDS_PLOTTED, so there is one member per bridge but needs to be one per dpot bridge plus one per non-bridged dpot leg.  Assume both are the same for now
#endif
  }
  for( uint8_t bareUnbridgedLeg = LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES; bareUnbridgedLeg < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES + BARE_DPOT_LEGS_UNBRIDGED; bareUnbridgedLeg++ )
  {
    setDPotLegMidPoint( bareUnbridgedLeg, !WORK_ON_THE_REFERENCE_LEG, !READ_AND_PLOT_IN_EACH_LAP ); 
  }
#endif
//#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  Serial.println( F( " done setting up digipot bridge legs, now take very first readings since powering on: " ) );
//#endif

  readAndPlotFromAllADCsInAndOutboard( 0, true ); //Fills the arrays with valid values

  //Now could turn on diagnostSquareWave and fine tune to find the common mode voltage to realize greatest gain of the outboard ADC BUT it's not that important!
  //    #else
  //        #ifdef DEBUG
  //            Serial.println( F( "setup." ) );
  //        #endif
#endif //End of auto-balancing aspect of setup()

#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  for( uint8_t csIndex = 0; csIndex < DPOTS; csIndex++ )
  {
    Serial.print( F( "dPotSettings[" ) );
    Serial.print( dPotPins[ csIndex ] );
    Serial.print( F( "]=<" ) );
    Serial.print( dPotSettings[ csIndex ] );
    if( csIndex < DPOTS - 1 )
      Serial.print( F( ">,. " ) );
    else
      Serial.print( F( ">,. " ) );
  }
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  Serial.print( F( " End of setup() " ) );
#endif
    duringDPotAdjusting = false;
}

void loop()
{
    int16_t potentialMSBoffset;
    int16_t savedMSBsettingsThisLeg;
    int32_t potentialLSBoffset;
    int16_t savedLSBsettingsThisLeg;
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
#if ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 )
  for( uint8_t csIndex = 0; csIndex < DPOTS; csIndex++ )
  {
    Serial.print( F( "dPotSettings[" ) );
    Serial.print( dPotPins[ csIndex ] );
    Serial.print( F( "]=" ) );
    Serial.print( dPotSettings[ csIndex ] );
    if( csIndex < DPOTS - 1 )
      Serial.print( F( ",. " ) );
    else
      Serial.print( F( ",. " ) );
  }
#endif
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
#ifdef AUTO_BRIDGE_BALANCING //Unsure of how to relate this macro and macro DIFFERENTIAL
    for( uint8_t whichOutboardADCindex = 0; whichOutboardADCindex < OUTBOARDS_PLOTTED; whichOutboardADCindex++ )
    {
      if( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading >= HEIGHT_OF_A_PLOT_LINESPACE - 1 )
      {
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
            Serial.print( F( " reading apparently maxed out " ) );
    #endif
    #if ( defined DIFFERENTIAL ) && ( defined LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
            if( ++counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] > LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
            {
                potentialMSBoffset = 1;
                goto NeedsAdjustment;
            }
    #else
        ;
    #endif
      }
      else if( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading == 0 ) //means reference leg is higher
      { ;
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
            Serial.print( F( " reading apparently zeroed out " ) );
    #endif
    #if ( defined DIFFERENTIAL ) && ( defined LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
            if( 0 - --counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] > LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
            {
              //Process: lower reference leg if it is higher than commonmode... level until it reaches commonmode..., then raise signal leg until can't raise it any more, then resume to lower reference leg until can't lower it any more
              //                setSignalBridgeLegInput( whichOutboardADCindex ); // Instead maybe use AdjustBridgeOutput ative( bridge );
                potentialMSBoffset = -1;
NeedsAdjustment:;
        #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
                  Serial.print( F( "for longer than allowed " ) );
        #endif
//                configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( whichOutboardADCindex );
//procedure to adjust leg: check reference leg to see if it is off in the same direction of best CM level.  if not, work on signal leg after reference leg is set to best CM
                if( !startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ] )
                {
                    startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ] = MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( whichOutboardADCindex );
                }
                else
                {
/*FUTURE: recalculate setting units per analog unit*/
                    startLSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ] = \
                    dPotSettings[ whatIsSignalLSBdPotIndexThisBridge( whichOutboardADCindex ) ];
                    incomingInboardAnalogLevelSignal[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ] = masterReadingsArray[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
                }

//                potentialMSBoffset = ( int16_t )\
//( ( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG - ( masterReadingsArray[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) ) / ( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ] / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) );
              if( potentialMSBoffset ) //> 1 ) || ( potentialMSBoffset < -1 ) ) 
              {
/*
                    Serial.print( F( "Line <4081>potentialMSBoffset=<" ) );
                    Serial.print( potentialMSBoffset );
                    Serial.print( F( "> masterReadingsArray[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE=<" ) );
                    Serial.print( masterReadingsArray[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
                    Serial.print( F( "> ( signed )( pow( <2>, ANALOG_INPUT_BITS_OF_BOARD ) * ( <100> - PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) ) / <100>=<" ) );
                    Serial.print( ( ( signed )pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) * ( 100 - PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) ) / 100 );
                    Serial.print( F( "> ( masterReadingsArray[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( ( pow( <2>, ANALOG_INPUT_BITS_OF_BOARD ) * ( <100> - PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) ) / <100> )=<" ) );
                    Serial.print( ( masterReadingsArray[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( ( ( signed )pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) * ( 100 - PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) ) / 100 ) );
                    Serial.print( F( ">.analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ]=<" ) );
                    Serial.print( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ] );
                    Serial.print( F( "> ( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ] / ( signed )pow( <2>, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) )=<" ) );
                    Serial.print( ( analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ] / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) );
                    Serial.print( F( ">." ) );
*/
//May want to Calculate new analogInputUnitsTimes64PerMSBLegSettingUnit based on level response of previous instruction
//                    startMSBsettingForCalculatingSettingUnitsPerAnalogInputUnit[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ] = MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( whichOutboardADCindex );
//analogInputUnitsTimes64PerMSBLegSettingUnit[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ] = \
//( ( ( bestOfFour( whatIsSignalLegThisBridge( whichOutboardADCindex ) ) ) - ( masterReadingsArray[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) ) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) / \
//( MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( whichOutboardADCindex ) - savedMSBsettingsThisLeg );
/*
                Serial.print( F( "New analogInputUnitsTimes64PerMSBLegSettingUnit would be=<" ) );
                Serial.print( ( ( ( bestOfFour( whatIsSignalLegThisBridge( whichOutboardADCindex ) ) ) - ( masterReadingsArray[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) ) * ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION ) ) / \
( MSB_SETTINGS_TOTAL_SIGNAL_THIS_BRIDGE( whichOutboardADCindex ) - savedMSBsettingsThisLeg ) );
                Serial.print( F( ">." ) ); */
                offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsFirstSignalMSBindexThisBridge( whichOutboardADCindex ), potentialMSBoffset );
              }
              else
              {
/*savedLSBsettingsThisLeg = */
//                potentialLSBoffset = \
//( legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ] * ( \
//( masterReadingsArray[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) \
//- \
//( signed )COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG \
//) ) / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION );
                Serial.print( F( "Line<4108>Needs LSB offset of=<" ) );
                Serial.print( potentialLSBoffset );
                Serial.print( F( ">." ) );
                offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsSignalLSBdPotIndexThisBridge( whichOutboardADCindex ), potentialLSBoffset );
                  potentialLSBoffset = 0;
              }
              plotterLoops = 0;
            }
    #else
        ;
    #endif
      }
    #ifdef DIFFERENTIAL
          else if( counterForTraceOutOfRangeTooLong ) //Trace has been out of range but now back in.  Stick it where we want it
          { //TODO: FIXME Debug why this quarrantined code does not work properly
//            potentialLSBoffset = ( legLSBsettingUnitsTimes64PerAnalogInputUnit[ whatIsSignalLegThisBridge( whichOutboardADCindex ) ] * \
//            ( ( signed )( HALF_HEIGHT_OF_A_PLOT_LINESPACE >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - \
//            ( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) ) ) / ( signed )pow( 2, BITS_TO_LEFT_SHIFT_TO_KEEP_HIGH_RESOLUTION );
//            offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsSignalLSBdPotIndexThisBridge( whichOutboardADCindex ), potentialLSBoffset / HIGHEST_SENSI_PGA_GAIN_FACTOR );
            offsetMSBdPotOrGroupValueUsingIndicesOnly( whatIsSignalLSBdPotIndexThisBridge( whichOutboardADCindex ), counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] > 0 ? 1 : counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] < 0 ? -1 : 0);
            counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] = 0;
          }
    #endif
    }
#endif
    //        Serial.println();
    /* The following commented code can be used for keyboard input */
#ifdef DEBUG
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
                if( offset_integer > MAX_DPOT_SETTG || offset_integer < 0 - MAX_DPOT_SETTG ) goto NoPotChange;
                if( szFull[ 0 ] == '1' ) DIGITAL_POT_ = dPotPins[ 0 ];
                else if( szFull[ 0 ] == '2' ) DIGITAL_POT_ = dPotPins[ 1 ];
                else if( szFull[ 0 ] == '3' ) DIGITAL_POT_ = dPotPins[ 2 ];
                else if( szFull[ 0 ] == '4' ) DIGITAL_POT_ = dPotPins[ 3 ];
                else if( szFull[ 0 ] == '5' ) DIGITAL_POT_ = dPotPins[ 4 ];
                else if( szFull[ 0 ] == '6' ) DIGITAL_POT_ = dPotPins[ 5 ];
                else goto NoPotChange;
                indexOfThisDPotCSpinInDPotArrays = atoi( &szFull[ 0 ] ) - 1;
                configureFromDPotIndex();
                offsetMSBdPotOrGroupValueUsingIndicesOnly( DIGITAL_POT_, offset_integer ); //configureFrom...() and configureFor...() must already be ran
                Serial.print( F( "Dpot " ) );
                Serial.print( DIGITAL_POT_ );
                Serial.print( F( " now set to " ) );
                Serial.println( dPotSettings[ atoi( &szFull[ 0 ] ) ] );
      NoPotChange:
        #endif
                szFull[ 0 ] = 0;
//                #ifdef DEBUG
                    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
                    Serial.println();
//                #endif
            }
#endif
/*    */
#if defined ( TEST_STEP_UP_DOWN ) //This may be defunct
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
      ;//in case preprocessor conditions cause no other code to form in here
#endif
    }
#endif
    for( uint8_t dPotIndex = 0; dPotIndex < DPOTS; dPotIndex++) //THIS ASSUMES THE ABOVE CONSTRUCT FILLS BOTH ARRAYS COMPLETELY
    {
#ifdef NUM_DIGITAL_PINS
      if( ( dPotSettings[ dPotIndex ] > MAX_DPOT_SETTG ) || ( dPotPins[ dPotIndex ] > NUM_DIGITAL_PINS ) ) break;  //The protection against arrays not fully set up
#else
      if( dPotSettings[ dPotIndex ] > MAX_DPOT_SETTG ) break;  //The protection against arrays not fully set up
#endif
        writeSettingToAsingleDPot( dPotPins[ dPotIndex ], dPotSettings[ dPotIndex ], THIS_IS_OVERT_PIN_NUMBER_INSTEAD_OF_INDEX );  //b/c the analog pin array not set up, this needs pin numbers like this, not pin indexes
    }
    while( millis() - millisStart < MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS )
    { //acquire and process not-plotted readings of inboard analog pins that get used for digipot auto-balancing FUTURE TODO
      ;//or just wait.
    }
  }
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  if( !graphLine )
  { //going down
//The next line quarantined places the outboard ADCs at the bottom of the screen, which I felt was not the best way.  It is closely related to other lines that must be quarantined also
//    for( uint8_t linespaceParametersIndex = 0; linespaceParametersIndex < NUMBER_OF_LINESPACES; linespaceParametersIndex++ )
    for( uint8_t linespaceParametersIndex = NUMBER_OF_LINESPACES - 1; linespaceParametersIndex != 255; linespaceParametersIndex-- )
    {
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      Serial.print( F( " upper bounds of this linespace" ) );
#endif
      Serial.print( F( " " ) );
      Serial.print( linespaceParameters[ linespaceParametersIndex ].HighLimitOfThisPlotLinespace );
      replotLastValuesForAllTraces( true );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      Serial.print( F( " lower bounds of this linespace" ) );
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
