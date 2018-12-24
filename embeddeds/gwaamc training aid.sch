EESchema Schematic File Version 4
LIBS:gwaamc training aid-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_Coaxial J1
U 1 1 5C1789B3
P 3300 2350
F 0 "J1" H 3200 2600 50  0000 L CNN
F 1 "Conn_Coaxial" H 2950 2500 50  0000 L CNN
F 2 "" H 3300 2350 50  0001 C CNN
F 3 " ~" H 3300 2350 50  0001 C CNN
	1    3300 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5C178B6D
P 3300 2550
F 0 "#PWR?" H 3300 2300 50  0001 C CNN
F 1 "GNDA" H 3305 2377 50  0000 C CNN
F 2 "" H 3300 2550 50  0001 C CNN
F 3 "" H 3300 2550 50  0001 C CNN
	1    3300 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:SPARK_GAP Electrodes_contacting_plant_leaf_surfaces
U 1 1 5C17E040
P 1450 1750
F 0 "Electrodes_contacting_plant_leaf_surfaces" V 1200 1050 50  0000 L BNN
F 1 " " H 1300 1900 50  0000 L BNN
F 2 "" H 1650 1750 50  0001 C CNN
F 3 "~" H 1650 1750 50  0001 C CNN
	1    1450 1750
	0    1    1    0   
$EndComp
$Comp
L Reference_Current:LM334Z U1
U 1 1 5C17E87B
P 3500 1750
F 0 "U1" H 3350 2050 50  0000 R CNN
F 1 "LM334Z" H 3400 1950 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 3525 1575 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 3500 1750 50  0001 C CIN
	1    3500 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C17EA11
P 3500 1550
F 0 "#PWR?" H 3500 1400 50  0001 C CNN
F 1 "+5V" H 3515 1723 50  0000 C CNN
F 2 "" H 3500 1550 50  0001 C CNN
F 3 "" H 3500 1550 50  0001 C CNN
	1    3500 1550
	1    0    0    -1  
$EndComp
$Comp
L MCP4162-104:MCP4162-104(0-100KΩ) DPot1-MSBs...
U 1 1 5C1815C9
P 5950 2000
F 0 "DPot1-MSBs..." V 6600 2200 50  0000 R CNN
F 1 "MCP4162-104(0-100KΩ)" V 6500 2450 50  0000 R CNN
F 2 "" H 5950 2000 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/11195c.pdf" H 5950 2000 50  0001 C CNN
	1    5950 2000
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5C1816AC
P 5100 2000
F 0 "#PWR?" H 5100 1800 50  0001 C CNN
F 1 "GNDD" H 5150 1850 50  0000 C CNN
F 2 "" H 5100 1950 50  0001 C CNN
F 3 "" H 5100 1950 50  0001 C CNN
	1    5100 2000
	1    0    0    -1  
$EndComp
$Comp
L MCP4162-502:MCP4162-502(0-5KΩ) DPot1-LSB
U 1 1 5C18203C
P 4700 2000
F 0 "DPot1-LSB" V 5350 2150 50  0000 R CNN
F 1 "MCP4162-502(0-5KΩ)" V 5250 2450 50  0000 R CNN
F 2 "" H 4700 2000 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/11195c.pdf" H 4700 2000 50  0001 C CNN
	1    4700 2000
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5C1823DA
P 6350 2000
F 0 "#PWR?" H 6350 1750 50  0001 C CNN
F 1 "GNDD" H 6400 1850 50  0000 C CNN
F 2 "" H 6350 2000 50  0001 C CNN
F 3 "" H 6350 2000 50  0001 C CNN
	1    6350 2000
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C1825F8
P 4300 2000
F 0 "#PWR?" H 4300 1850 50  0001 C CNN
F 1 "VCC" H 4250 2150 50  0000 C CNN
F 2 "" H 4300 2000 50  0001 C CNN
F 3 "" H 4300 2000 50  0001 C CNN
	1    4300 2000
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C182632
P 5550 2000
F 0 "#PWR?" H 5550 1850 50  0001 C CNN
F 1 "VCC" H 5500 2150 50  0000 C CNN
F 2 "" H 5550 2000 50  0001 C CNN
F 3 "" H 5550 2000 50  0001 C CNN
	1    5550 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2400 4800 2350
Wire Wire Line
	6050 2400 6050 2350
Text Label 1500 2600 0    50   ~ 0
coaxial_cable
Wire Wire Line
	4800 1600 5950 1600
Entry Wire Line
	4600 2400 4700 2500
Entry Wire Line
	4700 2400 4800 2500
Entry Wire Line
	5850 2400 5950 2500
Entry Wire Line
	5950 2400 6050 2500
Wire Wire Line
	4700 1600 4100 1600
Wire Wire Line
	6050 1600 6050 1500
Text GLabel 7100 4000 2    48   Input ~ 0
<From_MCU_Digital_Pin[s]_driving_this-these_CS[s]
Text GLabel 6950 4400 2    48   Input ~ 0
<From_MCU_Digital_Pins_driving_SCK_and_SDI_for_DPots
Text GLabel 7550 4200 2    48   Input ~ 0
<From_MCU_Digital_Pin_driving_this_CS
Text Notes 3650 3200 0    59   ~ 0
NOTE: Additional matching MSB-level DPots are\nallowed in this P0W-P0B loop.  Only a single \nLSB-level Dpot is allowed which must be of a\nresistance lower than or equal to MSB-level DPots.\nPins 5 and 6 are interchangeable, so the actual\nconnect order will be layout-dependent.
Text Notes 1000 3100 0    59   ~ 0
NOTE: If convenient polarity flipping is desired,\n a 4-way house light switch  may be placed in \nthe electrode circuit between the electrodes and the \ncoaxial cable, assuming you hook it up correctly.
$Comp
L power:GNDA #PWR?
U 1 1 5C18CACA
P 2900 7400
F 0 "#PWR?" H 2900 7150 50  0001 C CNN
F 1 "GNDA" H 2905 7227 50  0000 C CNN
F 2 "" H 2900 7400 50  0001 C CNN
F 3 "" H 2900 7400 50  0001 C CNN
	1    2900 7400
	1    0    0    -1  
$EndComp
$Comp
L Reference_Current:LM334Z U2
U 1 1 5C18CAD0
P 2900 6400
F 0 "U2" H 2770 6446 50  0000 R CNN
F 1 "LM334Z" H 2770 6355 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 2925 6225 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 2900 6400 50  0001 C CIN
	1    2900 6400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C18CAD7
P 2900 6200
F 0 "#PWR?" H 2900 6050 50  0001 C CNN
F 1 "+5V" H 2915 6373 50  0000 C CNN
F 2 "" H 2900 6200 50  0001 C CNN
F 3 "" H 2900 6200 50  0001 C CNN
	1    2900 6200
	1    0    0    -1  
$EndComp
$Comp
L MCP4162-104:MCP4162-104(0-100KΩ) DPot2-MSBs...
U 1 1 5C18CADD
P 5250 6550
F 0 "DPot2-MSBs..." V 4500 6650 50  0000 R CNN
F 1 "MCP4162-104(0-100KΩ)" V 4400 7000 50  0000 R CNN
F 2 "" H 5250 6550 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/11195c.pdf" H 5250 6550 50  0001 C CNN
	1    5250 6550
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5C18CAE4
P 4400 6550
F 0 "#PWR?" H 4400 6350 50  0001 C CNN
F 1 "GNDD" H 4450 6400 50  0000 C CNN
F 2 "" H 4400 6500 50  0001 C CNN
F 3 "" H 4400 6500 50  0001 C CNN
	1    4400 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 6600 2900 6900
$Comp
L MCP4162-502:MCP4162-502(0-5KΩ) DPot2-LSB
U 1 1 5C18CAEB
P 4000 6550
F 0 "DPot2-LSB" V 3250 6650 50  0000 R CNN
F 1 "MCP4162-502(0-5KΩ)" V 3150 7000 50  0000 R CNN
F 2 "" H 4000 6550 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/11195c.pdf" H 4000 6550 50  0001 C CNN
	1    4000 6550
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5C18CAF2
P 5650 6550
F 0 "#PWR?" H 5650 6300 50  0001 C CNN
F 1 "GNDD" H 5700 6400 50  0000 C CNN
F 2 "" H 5650 6550 50  0001 C CNN
F 3 "" H 5650 6550 50  0001 C CNN
	1    5650 6550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C18CAF8
P 3600 6550
F 0 "#PWR?" H 3600 6400 50  0001 C CNN
F 1 "VCC" H 3617 6723 50  0000 C CNN
F 2 "" H 3600 6550 50  0001 C CNN
F 3 "" H 3600 6550 50  0001 C CNN
	1    3600 6550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C18CAFE
P 4850 6550
F 0 "#PWR?" H 4850 6400 50  0001 C CNN
F 1 "VCC" H 4867 6723 50  0000 C CNN
F 2 "" H 4850 6550 50  0001 C CNN
F 3 "" H 4850 6550 50  0001 C CNN
	1    4850 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 6950 4100 6900
Wire Wire Line
	5350 6950 5350 6900
Wire Wire Line
	4100 6150 5250 6150
Entry Wire Line
	3900 6950 4000 7050
Entry Wire Line
	4000 6950 4100 7050
Entry Wire Line
	5150 6950 5250 7050
Entry Wire Line
	5250 6950 5350 7050
Wire Wire Line
	4000 6150 3400 6150
Wire Wire Line
	5350 6150 5350 6050
Text GLabel 7100 5000 2    48   Input ~ 0
<From_MCU_Digital_Pin[s]_driving_this-these_CS[s]
Text GLabel 6950 5400 2    48   Input ~ 0
<From_MCU_Digital_Pins_driving_SCK_and_SDI_for_DPots
Text GLabel 7550 5200 2    48   Input ~ 0
<From_MCU_Digital_Pin_driving_this_CS
$Comp
L Device:R_US R1
U 1 1 5C18E912
P 2900 7250
F 0 "R1" H 2968 7296 50  0000 L CNN
F 1 "1 MΩ" H 2968 7205 50  0000 L CNN
F 2 "" V 2940 7240 50  0001 C CNN
F 3 "~" H 2900 7250 50  0001 C CNN
	1    2900 7250
	1    0    0    -1  
$EndComp
$Comp
L AD8244_B:AD8244ARMZ U3-B
U 1 1 5C190291
P 2700 4600
F 0 "U3-B" H 2800 4750 50  0000 C CNN
F 1 "U3_AD8244ARMZ" H 2100 4300 50  0000 C CNN
F 2 "Package_MSOP_10" H 2700 4600 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 2700 4600 50  0001 C CNN
	1    2700 4600
	1    0    0    -1  
$EndComp
$Comp
L AD8244_C:AD8244ARMZ U3-C
U 1 1 5C19037E
P 2700 5250
F 0 "U3-C" H 2750 5450 50  0000 C CNN
F 1 "U3_AD8244ARMZ" H 2100 5600 50  0000 C CNN
F 2 "Package_MSOP_10" H 2700 5250 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 2700 5250 50  0001 C CNN
	1    2700 5250
	1    0    0    -1  
$EndComp
$Comp
L AD8244_D:AD8244ARMZ U3-D
U 1 1 5C190461
P 2700 5700
F 0 "U3-D" H 2800 5850 50  0000 C CNN
F 1 "U3_AD8244ARMZ" H 2100 6500 50  0000 C CNN
F 2 "Package_MSOP_10" H 2700 5700 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 2700 5700 50  0001 C CNN
	1    2700 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 5250 2400 5700
Connection ~ 2400 5700
Wire Wire Line
	2400 4600 2400 4000
$Comp
L AD8244_A:AD8244ARMZ U3-A
U 1 1 5C1901B6
P 2700 4000
F 0 "U3-A" H 2700 4150 50  0000 L CNN
F 1 " " H 1900 3800 50  0000 L CNN
F 2 "Package_MSOP_10" H 2700 4000 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 2700 4000 50  0001 C CNN
	1    2700 4000
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C193BB9
P 2600 3600
F 0 "#PWR?" H 2600 3450 50  0001 C CNN
F 1 "VCC" H 2500 3750 50  0000 C CNN
F 2 "" H 2600 3600 50  0001 C CNN
F 3 "" H 2600 3600 50  0001 C CNN
	1    2600 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5C193F33
P 2250 3700
F 0 "#PWR?" H 2250 3450 50  0001 C CNN
F 1 "GNDA" H 2250 3550 50  0000 C CNN
F 2 "" H 2250 3700 50  0001 C CNN
F 3 "" H 2250 3700 50  0001 C CNN
	1    2250 3700
	1    0    0    -1  
$EndComp
$Comp
L hx711:HX711 ADC1
U 1 1 5C19811F
P 5350 4700
F 0 "ADC1" H 5600 5200 50  0000 C CNN
F 1 "HX711, etc." H 5700 5100 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 5800 5050 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/ads1110.pdf" H 5050 5050 50  0001 C CNN
	1    5350 4700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5C19D658
P 5250 5050
F 0 "#PWR?" H 5250 4800 50  0001 C CNN
F 1 "GNDA" H 5255 4877 50  0000 C CNN
F 2 "" H 5250 5050 50  0001 C CNN
F 3 "" H 5250 5050 50  0001 C CNN
	1    5250 5050
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C19D6AB
P 5250 4200
F 0 "#PWR?" H 5250 4050 50  0001 C CNN
F 1 "VCC" H 5267 4373 50  0000 C CNN
F 2 "" H 5250 4200 50  0001 C CNN
F 3 "" H 5250 4200 50  0001 C CNN
	1    5250 4200
	1    0    0    -1  
$EndComp
Text GLabel 7400 4600 2    48   Input ~ 0
<From_MCU_Digital_Pin_driving_this_PD_SCK
Text GLabel 7550 4800 2    48   Output ~ 0
>To_MCU_Digital_Pin_receiving_this_data
Connection ~ 2400 4000
$Comp
L MCU_Module:Arduino_UNO_R3 MCU
U 1 1 5C1B3A00
P 9850 4350
F 0 "MCU" H 10450 5300 50  0000 C CNN
F 1 "Some_Arduino_MCU" H 10700 5200 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 10000 3300 50  0001 L CNN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 9650 5400 50  0001 C CNN
	1    9850 4350
	1    0    0    -1  
$EndComp
Text Notes 9150 5800 0    56   ~ 0
NOTE: Arduino also gets power rails \nand a serial connection to a computer
Text Notes 6650 6400 0    66   ~ 0
NOTE: Unfortunately, the devices shown do \nnot all share common data protocols except \nthe DPots.  Define the Digital Pin functions \nin preprocessor macros for all the disparate\nprotocols.  Thus, some flexibility remains for \ndriving an additional device or two that may \nhave inflexible pin assignments.
$Comp
L Device:C_Small C1_bank
U 1 1 5C1C2A28
P 4900 4300
F 0 "C1_bank" V 4650 4250 50  0000 C CNN
F 1 "2.05 µF total" V 4750 4250 50  0000 C CNN
F 2 "" H 4900 4300 50  0001 C CNN
F 3 "~" H 4900 4300 50  0001 C CNN
	1    4900 4300
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C2_bank
U 1 1 5C1C5AE4
P 2400 3600
F 0 "C2_bank" V 2350 4050 50  0000 C CNN
F 1 "2.05 µF total" V 2450 4150 50  0000 C CNN
F 2 "" H 2400 3600 50  0001 C CNN
F 3 "~" H 2400 3600 50  0001 C CNN
	1    2400 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	10350 4450 10500 4450
Wire Wire Line
	10500 4450 10500 5550
Wire Wire Line
	10350 4350 10600 4350
$Comp
L 74xx:74LS138 U5...
U 1 1 5C1F1B57
P 9450 2200
F 0 "U5..." H 9450 3200 50  0000 C CNN
F 1 "74LV138 only for large numbers of DPots" H 9700 3100 50  0000 C CNN
F 2 "" H 9450 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS138" H 9450 2200 50  0001 C CNN
	1    9450 2200
	1    0    0    -1  
$EndComp
Text Notes 6250 1100 0    58   ~ 0
*NOTE: U5 only used for larger numbers of DPots, useful with "bare" legs or part availability limitations.  \nU5's outputs drive DPot CS lines.  U4 only used for even larger numbers of DPots.  U4's outputs drive E1 \nor E2 of U5, U6, U7, etc. See sketch preprocessor macros and comments for more complete pin assignments \nand requirements.\nU5 pin E1/E2 may instead be driven by an MCU Digital Pin.  Again, see sketch comments.
$Comp
L power:GNDD #PWR?
U 1 1 5C1F1C9A
P 9450 2900
F 0 "#PWR?" H 9450 2650 50  0001 C CNN
F 1 "GNDD" H 9454 2745 50  0000 C CNN
F 2 "" H 9450 2900 50  0001 C CNN
F 3 "" H 9450 2900 50  0001 C CNN
	1    9450 2900
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C1F1D0B
P 9450 1600
F 0 "#PWR?" H 9450 1450 50  0001 C CNN
F 1 "VCC" H 9467 1773 50  0000 C CNN
F 2 "" H 9450 1600 50  0001 C CNN
F 3 "" H 9450 1600 50  0001 C CNN
	1    9450 1600
	1    0    0    -1  
$EndComp
Text Notes 7450 7500 0    97   ~ 0
GWAAMC Training Aid
Text Notes 8200 7650 0    66   ~ 0
18 Dec 2018
Text Notes 7000 7050 0    63   ~ 0
This system is shown using:                Shown not being used:\n1 - LM334 bridge   1 - Uno Arduino      2 - 74LV138; useful with high DPot count\n1 - HX711 24-bit ADC\n1 - LSB DPot/leg            Non-LM334 configuration options include bridged and\n1 - MSB DPot/leg           single leg to replace or augment LM334 option.
$Comp
L 74xx:74LS138 U4
U 1 1 5C19BCAA
P 8000 2200
F 0 "U4" H 7950 3200 50  0000 C CNN
F 1 "74LV138 only needed with larger numbers of DPots" H 6550 3100 50  0000 L CNN
F 2 "" H 8000 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS138" H 8000 2200 50  0001 C CNN
	1    8000 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5C19E5E4
P 8000 2850
F 0 "#PWR?" H 8000 2600 50  0001 C CNN
F 1 "GNDD" H 8004 2695 50  0000 C CNN
F 2 "" H 8000 2850 50  0001 C CNN
F 3 "" H 8000 2850 50  0001 C CNN
	1    8000 2850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C19E67E
P 8000 1600
F 0 "#PWR?" H 8000 1450 50  0001 C CNN
F 1 "VCC" H 8017 1773 50  0000 C CNN
F 2 "" H 8000 1600 50  0001 C CNN
F 3 "" H 8000 1600 50  0001 C CNN
	1    8000 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 1900 8600 1900
Wire Wire Line
	8600 1900 8600 2500
Wire Wire Line
	8600 2500 8950 2500
$Comp
L power:GNDD #PWR?
U 1 1 5C1A4CE3
P 8950 2600
F 0 "#PWR?" H 8950 2350 50  0001 C CNN
F 1 "GNDD" H 9000 2400 50  0000 C CNN
F 2 "" H 8950 2600 50  0001 C CNN
F 3 "" H 8950 2600 50  0001 C CNN
	1    8950 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5C1A4D3E
P 7500 2600
F 0 "#PWR?" H 7500 2350 50  0001 C CNN
F 1 "GNDD" H 7550 2400 50  0000 C CNN
F 2 "" H 7500 2600 50  0001 C CNN
F 3 "" H 7500 2600 50  0001 C CNN
	1    7500 2600
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C1A4DA0
P 8950 2400
F 0 "#PWR?" H 8950 2250 50  0001 C CNN
F 1 "VCC" H 9050 2550 50  0000 C CNN
F 2 "" H 8950 2400 50  0001 C CNN
F 3 "" H 8950 2400 50  0001 C CNN
	1    8950 2400
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C1A4DFB
P 7500 2400
F 0 "#PWR?" H 7500 2250 50  0001 C CNN
F 1 "VCC" H 7600 2550 50  0000 C CNN
F 2 "" H 7500 2400 50  0001 C CNN
F 3 "" H 7500 2400 50  0001 C CNN
	1    7500 2400
	1    0    0    -1  
$EndComp
Text GLabel 8250 3450 0    48   Output ~ 0
<Drives_DPot_CS_pins_when_required
Entry Wire Line
	9950 2600 10050 2500
Entry Wire Line
	9950 2500 10050 2400
Entry Wire Line
	9950 2400 10050 2300
Entry Wire Line
	9950 2300 10050 2200
Entry Wire Line
	9950 2200 10050 2100
Entry Wire Line
	9950 2100 10050 2000
Entry Wire Line
	9950 2000 10050 1900
Entry Wire Line
	9950 1900 10050 1800
Wire Bus Line
	10050 1700 10400 1700
Entry Wire Line
	8850 2000 8950 1900
Entry Wire Line
	8850 2100 8950 2000
Entry Wire Line
	8850 2200 8950 2100
Entry Wire Line
	7400 2000 7500 1900
Entry Wire Line
	7400 2100 7500 2000
Entry Wire Line
	7400 2200 7500 2100
Entry Wire Line
	7400 2600 7500 2500
Text GLabel 6800 3800 2    48   Input ~ 0
<From_MCU_Digital_pins_alternate_method_to_DPot_CS_pins
Text Notes 8700 2400 1    60   Italic 12
*See note
Text Notes 10750 5000 1    60   Italic 12
*See note
Text Notes 9150 6450 0    56   ~ 0
*NOTE FOR MCU ANALOG PINS:  Low-\nnumbered Analog Input pins are reserved \nfor all existing DPOT-controlled leg outputs.  \nUnused Analog Pins above them may be\nused to display additional plotter traces\nwhen so defined in preprocessor macros.  
Text Notes 3650 3950 0    56   ~ 0
NOTE: Capacitor banks 1 & 2 each consist of a \n2-10 µF tantalum plus a low-ESR sub-µF capacitor \nwhich gets located in direct-as-practical path be-\ntween Vcc of one device to GND of the other device.  \nNOT SHOWN: One decoupling capacitor bank of same \nvalues for all digital parts combined.
Text Notes 650  1300 0    66   ~ 0
NOTE:  The LM334 devices must receive 5 VDC or greater due to their own operating voltage range.  \nTheir functional range will be substantially limited if powered by the 3 or 3.3 VDC of many MCUs.  \nProvide a dedicated positive power supply to them if 5 VDC is not otherwise available, then carefully \nensure the output levels from them are prevented from exceeding the input range of the remaining \ncircuitry.  Alternative: use non-LM334 legs (AKA "bare" legs) & adjust macros
Text Notes 5450 7600 2    60   Italic 12
*See note for the above DPot set
Wire Wire Line
	10600 4350 10600 5600
Wire Wire Line
	3000 4000 3400 4000
Wire Wire Line
	4250 5600 10600 5600
Wire Wire Line
	2750 4150 2750 4300
Wire Wire Line
	3000 5250 3400 5250
Wire Wire Line
	3000 5700 3400 5700
Wire Wire Line
	2600 3700 2600 3600
Connection ~ 2600 3600
Wire Wire Line
	2250 3600 2250 3700
Wire Wire Line
	2300 3600 2250 3600
Wire Wire Line
	4800 4300 4700 4300
Connection ~ 2900 6900
Entry Wire Line
	4700 2500 4800 2600
Entry Wire Line
	4800 2500 4900 2600
Entry Wire Line
	5950 2500 6050 2600
Entry Wire Line
	6050 2500 6150 2600
Entry Wire Line
	4800 2400 4900 2500
Text GLabel 2150 1750 0    67   UnSpc ~ 0
Opt_SW
Wire Wire Line
	4250 4550 4250 4600
Wire Wire Line
	4250 4600 4800 4600
Wire Wire Line
	5750 4600 7400 4600
Wire Wire Line
	5750 4800 7550 4800
Entry Wire Line
	4000 7050 4100 7150
Entry Wire Line
	4100 7050 4200 7150
Entry Wire Line
	5250 7050 5350 7150
Entry Wire Line
	5350 7050 5450 7150
Entry Wire Line
	4100 6950 4200 7050
Wire Bus Line
	5350 6950 6150 6950
Wire Bus Line
	6050 2400 6550 2400
Wire Wire Line
	6350 5200 7550 5200
Wire Wire Line
	2750 4300 2600 4300
Wire Wire Line
	3000 4200 3000 4150
Wire Wire Line
	2750 4150 3000 4150
Wire Wire Line
	6350 2500 6350 4200
Wire Wire Line
	6350 4200 7550 4200
Wire Wire Line
	4000 1750 4000 1500
Wire Wire Line
	4000 1500 6050 1500
Wire Wire Line
	3600 1750 4000 1750
Wire Wire Line
	3400 4000 3400 4600
Wire Wire Line
	3400 5700 3400 5250
Connection ~ 3400 5250
Text GLabel 1400 1750 0    68   BiDi ~ 14
-LEAF-
Wire Bus Line
	8250 3450 9100 3450
Connection ~ 3500 2350
Wire Wire Line
	3500 2350 4100 2350
Wire Wire Line
	3500 1850 3500 2350
Wire Wire Line
	4100 1600 4100 2350
Entry Wire Line
	3000 2450 3100 2350
Entry Wire Line
	3000 2500 3100 2400
Entry Wire Line
	2900 2600 3000 2500
Wire Wire Line
	3300 2400 3100 2400
Wire Wire Line
	3100 2350 3500 2350
Entry Wire Line
	2850 2650 2950 2550
Entry Wire Line
	2850 2600 2950 2500
Entry Wire Line
	2950 2500 3050 2400
Wire Wire Line
	2850 2650 1400 2650
Wire Wire Line
	2850 2600 1400 2600
Entry Wire Line
	1300 2550 1400 2650
Entry Wire Line
	1300 2500 1400 2600
Entry Wire Line
	1250 2500 1350 2600
Entry Wire Line
	1300 2400 1400 2300
Entry Wire Line
	1250 2400 1350 2300
Wire Wire Line
	1400 2300 2750 2300
Entry Wire Line
	1300 2350 1400 2250
Entry Wire Line
	2750 2300 2850 2200
Entry Wire Line
	2750 2250 2850 2150
Wire Wire Line
	1400 2250 2750 2250
Entry Wire Line
	2800 2250 2900 2150
Text Notes 2200 1850 0    38   ~ 0
Twisted pair with \noptional 4-way switch \ninserted to flip polarity
Entry Wire Line
	2100 1700 2200 1600
Entry Wire Line
	1700 1900 1800 1800
Entry Wire Line
	1700 1600 1800 1700
Entry Wire Line
	2100 1800 2200 1900
Entry Wire Line
	2150 1850 2250 1950
Entry Wire Line
	1650 1550 1750 1650
Entry Wire Line
	2150 1650 2250 1550
Entry Wire Line
	1650 1950 1750 1850
Entry Wire Line
	800  1850 900  1750
Entry Wire Line
	850  3100 950  3200
$Comp
L power:Earth_Protective #PWR?
U 1 1 5C7829BA
P 1300 7100
F 0 "#PWR?" H 1550 6850 50  0001 C CNN
F 1 "Earth_Protective" H 1750 6950 50  0001 C CNN
F 2 "" H 1300 7000 50  0001 C CNN
F 3 "~" H 1300 7000 50  0001 C CNN
	1    1300 7100
	1    0    0    -1  
$EndComp
Text GLabel 850  3100 0    32   BiDi ~ 0
Unused_leaf
Wire Wire Line
	10500 5550 4450 5550
Wire Wire Line
	3400 6150 3400 6900
Wire Wire Line
	2900 6900 3400 6900
Wire Wire Line
	3250 6050 3250 6400
Wire Wire Line
	3250 6050 5350 6050
Wire Wire Line
	3100 6400 3250 6400
Wire Wire Line
	2400 5700 2400 6900
Wire Wire Line
	2400 6900 2900 6900
Wire Wire Line
	2100 3200 3500 3200
Wire Wire Line
	2100 3200 2100 4000
Wire Wire Line
	3500 2350 3500 3200
Wire Wire Line
	900  2400 950  3600
Text Notes 1200 6800 1    81   ~ 0
DUT stem
Wire Wire Line
	900  2400 800  1900
Wire Wire Line
	800  1900 850  1600
Text GLabel 1400 3450 0    32   BiDi ~ 0
Unused_leaf
Text GLabel 1300 2100 0    32   BiDi ~ 0
Unused_leaf
Entry Wire Line
	950  3550 1050 3450
Entry Wire Line
	850  2200 950  2100
Wire Wire Line
	1300 5350 950  3600
Text GLabel 850  4200 0    32   BiDi ~ 0
Unused_leaf
Text GLabel 1600 4550 0    32   BiDi ~ 0
Unused_leaf
Text GLabel 1100 5000 0    32   BiDi ~ 0
Unused_leaf
Text GLabel 1750 6000 0    32   BiDi ~ 0
Unused_leaf
Entry Wire Line
	1300 6100 1400 6000
Entry Wire Line
	1150 4650 1250 4550
Entry Wire Line
	1000 4300 1100 4400
Entry Wire Line
	1000 4300 1100 4400
Entry Wire Line
	900  4200 1000 4300
Entry Wire Line
	1100 5000 1200 5100
Entry Wire Line
	1150 5050 1250 5150
Text Notes 650  7700 0    95   ~ 19
Device Under Test \n(DUT)
Wire Wire Line
	2900 6900 2900 7150
Wire Wire Line
	2900 1550 2900 2150
Wire Wire Line
	2850 1950 2850 2150
Wire Wire Line
	1250 2400 1250 2500
Wire Wire Line
	1300 2400 1300 2500
Text Notes 2800 2150 2    39   Italic 0
(Switch wiring overlaps straight-through \nwiring for drawing purposes only.  Do not \nwire both ways simultaneously, of course)
Wire Wire Line
	6350 7050 6350 5200
Connection ~ 4250 4600
Wire Wire Line
	4250 4600 4250 5600
Wire Wire Line
	2100 4000 2400 4000
Wire Wire Line
	3000 4600 3400 4600
Connection ~ 3400 4600
Wire Wire Line
	3400 4600 4250 4600
Wire Wire Line
	3400 4800 4450 4800
Connection ~ 4450 4800
Wire Wire Line
	4450 4800 4800 4800
Wire Wire Line
	3400 4800 3400 5250
Wire Wire Line
	4450 4800 4450 5550
Wire Bus Line
	10400 1700 10400 3150
Wire Bus Line
	8850 3300 7400 3300
Connection ~ 7400 3300
Wire Bus Line
	7400 3300 6700 3300
Wire Bus Line
	6950 5400 6550 5400
Wire Bus Line
	6550 5400 6550 7150
Wire Bus Line
	7100 5000 6150 5000
Wire Bus Line
	6150 5000 6150 6950
Wire Bus Line
	6950 4400 6150 4400
Wire Bus Line
	7100 4000 6550 4000
Wire Bus Line
	9100 3150 10400 3150
Wire Bus Line
	9100 3150 9100 3450
Wire Bus Line
	6550 2400 6550 4000
Wire Bus Line
	6800 3800 6700 3800
Wire Bus Line
	6700 3300 6700 3800
Wire Bus Line
	6150 2600 6150 4400
Text Notes 7300 7250 0    58   ~ 0
1 
Wire Wire Line
	2500 3600 2600 3600
Wire Wire Line
	5250 4200 5250 4300
Wire Wire Line
	5000 4300 5250 4300
Connection ~ 5250 4300
$Comp
L power:GNDA #PWR?
U 1 1 5C1E5690
P 3000 4200
F 0 "#PWR?" H 3000 3950 50  0001 C CNN
F 1 "GNDA" H 3150 4100 50  0000 C CNN
F 2 "" H 3000 4200 50  0001 C CNN
F 3 "" H 3000 4200 50  0001 C CNN
	1    3000 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5C1E56EB
P 4700 4300
F 0 "#PWR?" H 4700 4050 50  0001 C CNN
F 1 "GNDA" H 4705 4127 50  0000 C CNN
F 2 "" H 4700 4300 50  0001 C CNN
F 3 "" H 4700 4300 50  0001 C CNN
	1    4700 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 5350 1300 7100
Wire Wire Line
	4900 2500 6350 2500
Wire Wire Line
	4200 7050 6350 7050
Wire Bus Line
	8850 2000 8850 3300
Wire Bus Line
	4800 2600 6150 2600
Wire Wire Line
	1450 1950 2850 1950
Wire Wire Line
	1450 1550 2900 1550
Wire Bus Line
	4100 7150 6550 7150
Wire Bus Line
	7400 2000 7400 3300
Wire Bus Line
	10050 1700 10050 2500
$EndSCHEMATC
