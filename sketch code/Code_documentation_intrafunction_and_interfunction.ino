/*
 * fix occurances of printing line numbers
 * effect various levels of verbosity
 * test with just two and just one dpot per leg


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
*/

/*

static uint16_t startLevelForCalculatingSettingUnitsPerAnalogUnit, startMSBSettingForCalculatingSettingUnitsPerAnalogUnit, startLSBSettingForCalculatingSettingUnitsPerAnalogUnit;
uint16_t bestOfFour( uint8_t );
#define MOST_ACCURATE true  //This belongs with the following function declare
uint16_t bestGuessAnalogInputreading( uint8_t = dPotLeg, bool = !MOST_ACCURATE, bool = true );
#define TARGET_LEVEL_DUMMY_VALUE 0
bool lowestLevelDPotLegSetpointing( uint16_t incomingInboardAnalogLevel, uint16_t targetLevel, bool justPerformOneStep = false )
{
}

bool stepAdjustDPotsForThisLeg( bool = TAKE_LEG_VOLTAGE_DOWN, uint16_t = 0, bool = false ); //default direction will be positive
bool midLevelDPotLegSetpointing( uint16_t incomingBestGuessAnalogInputreading, uint16_t targetLevel, bool justPerformOneStep = false )
{ //midLevelDPotLegSetpointing should do this stepsizes thing also but with LSB and bestGuessAnalogInputreading
}

uint16_t thirdLevelDPotLegSetpointing( uint16_t incomingBestGuessAnalogInputreading, uint16_t targetLevel, bool justPerformOneStep = false ) //The return value is used to caculate referenceLSBSettingUnitsPerAnalogInputUnit[ dPotLeg ] and analogInputUnitsPerReferenceMSBSettingUnit[ dPotLeg ]
{ //midLevelDPotLegSetpointing should do this stepsizes thing also but with LSB and bestGuessAnalogInputreading
}

#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) )
bool highestLevelDifferentialBridgeSetpointing( uint8_t OutboardADCindex = whichBridgeOrOutboardADCindex, uint8_t limit = 15 )
{
}

bool setDPotLegMidPoint( uint8_t, bool, bool = !GO_IN_SMALL_STEPS, bool  = !USE_SIGNAL_LEGS_LEVEL_AS_TARGET_LEVEL ); //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.
bool adjustBridgeOutputPositive( uint8_t bridge = whichBridgeOrOutboardADCindex ) //TODO: make this function faster through predictive step sizes
{ //If all pots are maxed (positive leg to positive and negative leg to negative) return false
}

bool setDPotLegMidPoint( uint8_t, bool , bool = !GO_IN_SMALL_STEPS,  bool  = !USE_SIGNAL_LEGS_LEVEL_AS_TARGET_LEVEL ); //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.

bool adjustBridgeOutputPositive( uint8_t bridge = whichBridgeOrOutboardADCindex ) //TODO: make this function faster through predictive step sizes
{ //If all pots are maxed (positive leg to positive and negative leg to negative) return false
}

bool adjustBridgeOutputNegative( uint8_t bridge )
{ //If all pots are maxed (positive leg to negative and negative leg to positive) return false
}

uint16_t bestGuessAnalogInputreading( uint8_t dPotLegOrIndexedInboardAnalogInput, bool mostAccurate, bool usingGlobalValueOfDPotLegForAnalogPinArrayIndex )
//#else
//uint16_t bestGuessAnalogInputreading( uint8_t dPotLegOrIndexedInboardAnalogInput, bool mostAccurate, bool usingGlobalValueOfDPotLegForAnalogPinArrayIndex, uint8_t dPotLeg )
{ //returns an INBOARD Analog Input pin reading, same as leg reading
}

static uint8_t setDPotsStep = 0;
bool setDPotLegMidPoint( uint8_t bridge, bool thisIsReferenceLegOfBridge, bool justPerformOneStep, bool useSignalLegLevelAsTargetLevel ) //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.
{ //recursive calls to this will not work if statics are used
}

1.  make best guess adjustment [caller checks if differential reading came into range, stayed same direction or changed direction]
2a. if came into differential range, adjust toward half scale until overshoots, then STOP
2b. if stayed same direction check if any closer, if yes recalculate a new setting and loop else stop if not
2c. if changed direction recalculate a new setting and loop







 */
