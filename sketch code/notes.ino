/*





            for( ; lsbSetting <= MAX_DPOT_SETTG; lsbSetting++ )
            {
                setDPotOrMSBGroupValue( dPotPins[ lSBDPotOffsetIndexThisLeg ], lsbSetting );           //effect signal leg settings
                dPotSettings[ lSBDPotOffsetIndexThisLeg ] = lsbSetting;
                setDPotOrMSBGroupValue( dPotPins[ lSBDPotOffsetIndexThisLegReference ], lsbSetting );  //effect reference leg settings        
                dPotSettings[ lSBDPotOffsetIndexThisLegReference ] = lsbSetting;
                readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
                Serial.print( F( "Line<3332>" ) );
            }
            Serial.print( F( "Line<3334>" ) );
            lsbSetting = 0;
        #if ( defined INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ) || ( defined INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC ) //to avoid a carry or borrow being generated
            setDPotOrMSBGroupValue( dPotPins[ lSBDPotOffsetIndexThisLeg ], ++lsbSetting );           //effect signal leg settings
            setDPotOrMSBGroupValue( dPotPins[ lSBDPotOffsetIndexThisLegReference ], lsbSetting );  //effect reference leg settings        
        #else
            setDPotOrMSBGroupValue( dPotPins[ lSBDPotOffsetIndexThisLeg ], lsbSetting );           //effect signal leg settings
            setDPotOrMSBGroupValue( dPotPins[ lSBDPotOffsetIndexThisLegReference ], lsbSetting );  //effect reference leg settings        
        #endif
            Serial.print( F( "Line<3343>" ) );
            dPotSettings[ lSBDPotOffsetIndexThisLeg ] = lsbSetting;
            dPotSettings[ lSBDPotOffsetIndexThisLegReference ] = lsbSetting;







*/
