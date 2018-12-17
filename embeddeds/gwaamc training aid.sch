EESchema Schematic File Version 4
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
P 1950 2200
F 0 "J1" H 1900 2450 50  0000 L CNN
F 1 "Conn_Coaxial" H 1750 2350 50  0000 L CNN
F 2 "" H 1950 2200 50  0001 C CNN
F 3 " ~" H 1950 2200 50  0001 C CNN
	1    1950 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5C178B6D
P 1950 2400
F 0 "#PWR?" H 1950 2150 50  0001 C CNN
F 1 "GNDA" H 1955 2227 50  0000 C CNN
F 2 "" H 1950 2400 50  0001 C CNN
F 3 "" H 1950 2400 50  0001 C CNN
	1    1950 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:SPARK_GAP Electrodes_contacting_plant_leaf
U 1 1 5C17E040
P 700 2200
F 0 "Electrodes_contacting_plant_leaf" V 400 2100 50  0000 L BNN
F 1 " " H 550 2350 50  0000 L BNN
F 2 "" H 900 2200 50  0001 C CNN
F 3 "~" H 900 2200 50  0001 C CNN
	1    700  2200
	0    1    1    0   
$EndComp
Wire Wire Line
	1950 2250 800  2250
$Comp
L Reference_Current:LM334Z U1
U 1 1 5C17E87B
P 2500 1350
F 0 "U1" H 2370 1396 50  0000 R CNN
F 1 "LM334Z" H 2370 1305 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 2525 1175 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 2500 1350 50  0001 C CIN
	1    2500 1350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C17EA11
P 2500 1150
F 0 "#PWR?" H 2500 1000 50  0001 C CNN
F 1 "+5V" H 2515 1323 50  0000 C CNN
F 2 "" H 2500 1150 50  0001 C CNN
F 3 "" H 2500 1150 50  0001 C CNN
	1    2500 1150
	1    0    0    -1  
$EndComp
$Comp
L MCP4162-104:MCP4162-104(0-100KΩ) U1-MSBs...
U 1 1 5C1815C9
P 4700 1700
F 0 "U1-MSBs..." V 4100 1800 50  0000 R CNN
F 1 "MCP4162-104(0-100KΩ)" V 4000 2150 50  0000 R CNN
F 2 "" H 4700 1700 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/11195c.pdf" H 4700 1700 50  0001 C CNN
	1    4700 1700
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5C1816AC
P 3850 1700
F 0 "#PWR?" H 3850 1500 50  0001 C CNN
F 1 "GNDD" H 3900 1550 50  0000 C CNN
F 2 "" H 3850 1650 50  0001 C CNN
F 3 "" H 3850 1650 50  0001 C CNN
	1    3850 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 1550 2500 2200
$Comp
L MCP4162-502:MCP4162-502(0-5KΩ) U1-LSB
U 1 1 5C18203C
P 3450 1700
F 0 "U1-LSB" V 2850 1800 50  0000 R CNN
F 1 "MCP4162-502(0-5KΩ)" V 2750 2150 50  0000 R CNN
F 2 "" H 3450 1700 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/11195c.pdf" H 3450 1700 50  0001 C CNN
	1    3450 1700
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5C1823DA
P 5100 1700
F 0 "#PWR?" H 5100 1450 50  0001 C CNN
F 1 "GNDD" H 5150 1550 50  0000 C CNN
F 2 "" H 5100 1700 50  0001 C CNN
F 3 "" H 5100 1700 50  0001 C CNN
	1    5100 1700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C1825F8
P 3050 1700
F 0 "#PWR?" H 3050 1550 50  0001 C CNN
F 1 "VCC" H 3067 1873 50  0000 C CNN
F 2 "" H 3050 1700 50  0001 C CNN
F 3 "" H 3050 1700 50  0001 C CNN
	1    3050 1700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C182632
P 4300 1700
F 0 "#PWR?" H 4300 1550 50  0001 C CNN
F 1 "VCC" H 4317 1873 50  0000 C CNN
F 2 "" H 4300 1700 50  0001 C CNN
F 3 "" H 4300 1700 50  0001 C CNN
	1    4300 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2100 3550 2050
Wire Bus Line
	4800 2050 4900 2050
Wire Wire Line
	4800 2100 4800 2050
Wire Wire Line
	3550 2050 3600 2050
Text Label 1200 2250 0    50   ~ 0
Coaxial_cable
Wire Wire Line
	3550 1300 4700 1300
Entry Wire Line
	3350 2100 3450 2200
Entry Wire Line
	3450 2100 3550 2200
Entry Wire Line
	4600 2100 4700 2200
Entry Wire Line
	4700 2100 4800 2200
Wire Wire Line
	3450 1300 2850 1300
Wire Wire Line
	2850 1300 2850 2200
Wire Wire Line
	4800 1300 4800 1200
Wire Wire Line
	4800 1200 2750 1200
Wire Wire Line
	2750 1200 2750 1350
Wire Wire Line
	2750 1350 2700 1350
Connection ~ 2500 2200
Wire Wire Line
	2500 2200 2850 2200
Text Notes 5150 2000 0    39   ~ 0
NOTE: MCU=Arduino
Text GLabel 6000 2050 0    28   Output ~ 0
<From_MCU_Digital_Pin[s]_driving_this-these_CS[s]
Text GLabel 6200 2200 0    28   Output ~ 0
<From_MCU_Digital_Pins_driving_SCK_and_SDI_for_DPots
Text GLabel 4450 2050 0    28   Output ~ 0
<From_MCU_Digital_Pin_driving_this_CS
Text Notes 3400 2750 0    39   ~ 0
NOTE: Additional matching MSB-level DPots are\nallowed in this P0W-P0B loop.  Only a single \nLSB-level Dpot is allowed which must be of a\nresistance lower than or equal to MSB-level DPots.
Text Notes 600  2800 0    39   ~ 0
NOTE: If convenient polarity flipping\nis desired, a 4-way house light switch \nmay be placed in the electrode circuit\nbetween the electrodes and the coaxial\ncable, assuming you hook it up correctly.
Wire Wire Line
	800  2200 1750 2200
Wire Wire Line
	700  2400 800  2400
Wire Wire Line
	700  2000 800  2000
Wire Wire Line
	800  2000 800  2200
Wire Wire Line
	800  2250 800  2400
$Comp
L power:GNDA #PWR?
U 1 1 5C18CACA
P 2450 7300
F 0 "#PWR?" H 2450 7050 50  0001 C CNN
F 1 "GNDA" H 2455 7127 50  0000 C CNN
F 2 "" H 2450 7300 50  0001 C CNN
F 3 "" H 2450 7300 50  0001 C CNN
	1    2450 7300
	1    0    0    -1  
$EndComp
$Comp
L Reference_Current:LM334Z U2
U 1 1 5C18CAD0
P 2450 5950
F 0 "U2" H 2320 5996 50  0000 R CNN
F 1 "LM334Z" H 2320 5905 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 2475 5775 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 2450 5950 50  0001 C CIN
	1    2450 5950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C18CAD7
P 2450 5750
F 0 "#PWR?" H 2450 5600 50  0001 C CNN
F 1 "+5V" H 2465 5923 50  0000 C CNN
F 2 "" H 2450 5750 50  0001 C CNN
F 3 "" H 2450 5750 50  0001 C CNN
	1    2450 5750
	1    0    0    -1  
$EndComp
$Comp
L MCP4162-104:MCP4162-104(0-100KΩ) U2-MSBs...
U 1 1 5C18CADD
P 4850 6300
F 0 "U2-MSBs..." V 4250 6400 50  0000 R CNN
F 1 "MCP4162-104(0-100KΩ)" V 4150 6750 50  0000 R CNN
F 2 "" H 4850 6300 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/11195c.pdf" H 4850 6300 50  0001 C CNN
	1    4850 6300
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5C18CAE4
P 4000 6300
F 0 "#PWR?" H 4000 6100 50  0001 C CNN
F 1 "GNDD" H 4050 6150 50  0000 C CNN
F 2 "" H 4000 6250 50  0001 C CNN
F 3 "" H 4000 6250 50  0001 C CNN
	1    4000 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 6150 2450 6800
$Comp
L MCP4162-502:MCP4162-502(0-5KΩ) U2-LSB
U 1 1 5C18CAEB
P 3600 6300
F 0 "U2-LSB" V 3000 6400 50  0000 R CNN
F 1 "MCP4162-502(0-5KΩ)" V 2900 6750 50  0000 R CNN
F 2 "" H 3600 6300 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/11195c.pdf" H 3600 6300 50  0001 C CNN
	1    3600 6300
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5C18CAF2
P 5250 6300
F 0 "#PWR?" H 5250 6050 50  0001 C CNN
F 1 "GNDD" H 5300 6150 50  0000 C CNN
F 2 "" H 5250 6300 50  0001 C CNN
F 3 "" H 5250 6300 50  0001 C CNN
	1    5250 6300
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C18CAF8
P 3200 6300
F 0 "#PWR?" H 3200 6150 50  0001 C CNN
F 1 "VCC" H 3217 6473 50  0000 C CNN
F 2 "" H 3200 6300 50  0001 C CNN
F 3 "" H 3200 6300 50  0001 C CNN
	1    3200 6300
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C18CAFE
P 4450 6300
F 0 "#PWR?" H 4450 6150 50  0001 C CNN
F 1 "VCC" H 4467 6473 50  0000 C CNN
F 2 "" H 4450 6300 50  0001 C CNN
F 3 "" H 4450 6300 50  0001 C CNN
	1    4450 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 6700 3700 6650
Wire Bus Line
	4950 6650 5050 6650
Wire Wire Line
	4950 6700 4950 6650
Wire Wire Line
	3700 6650 3750 6650
Wire Wire Line
	3700 5900 4850 5900
Entry Wire Line
	3500 6700 3600 6800
Entry Wire Line
	3600 6700 3700 6800
Entry Wire Line
	4750 6700 4850 6800
Entry Wire Line
	4850 6700 4950 6800
Wire Wire Line
	3600 5900 2800 5900
Wire Wire Line
	2800 5900 2800 6800
Wire Wire Line
	4950 5900 4950 5800
Wire Wire Line
	4950 5800 2700 5800
Wire Wire Line
	2700 5800 2700 5950
Wire Wire Line
	2700 5950 2650 5950
Connection ~ 2450 6800
Wire Wire Line
	2450 6800 2800 6800
Text Notes 5300 6600 0    39   ~ 0
NOTE: MCU=Arduino
Text GLabel 6150 6650 0    28   Output ~ 0
<From_MCU_Digital_Pin[s]_driving_this-these_CS[s]
Text GLabel 6350 6800 0    28   Output ~ 0
<From_MCU_Digital_Pins_driving_SCK_and_SDI_for_DPots
Text GLabel 4600 6650 0    28   Output ~ 0
<From_MCU_Digital_Pin_driving_this_CS
Text Notes 3550 7350 0    39   ~ 0
NOTE: Additional matching MSB-level DPots are\nallowed in this P0W-P0B loop.  Only a single \nLSB-level Dpot is allowed which must be of a\nresistance lower than or equal to MSB-level DPots.
$Comp
L Device:R_US R1
U 1 1 5C18E912
P 2450 7150
F 0 "R1" H 2518 7196 50  0000 L CNN
F 1 "1 MΩ" H 2518 7105 50  0000 L CNN
F 2 "" V 2490 7140 50  0001 C CNN
F 3 "~" H 2450 7150 50  0001 C CNN
	1    2450 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 6800 2450 7000
$Comp
L AD8244_B:AD8244ARMZ U3-B
U 1 1 5C190291
P 3100 4200
F 0 "U3-B" H 3200 4350 50  0000 C CNN
F 1 "AD8244ARMZ" H 3400 5050 50  0000 C CNN
F 2 "Package_MSOP_10" H 3100 4200 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 3100 4200 50  0001 C CNN
	1    3100 4200
	1    0    0    -1  
$EndComp
$Comp
L AD8244_C:AD8244ARMZ U3-C
U 1 1 5C19037E
P 3100 4850
F 0 "U3-C" H 3150 5050 50  0000 C CNN
F 1 "AD8244ARMZ" H 3400 6350 50  0000 C CNN
F 2 "Package_MSOP_10" H 3100 4850 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 3100 4850 50  0001 C CNN
	1    3100 4850
	1    0    0    -1  
$EndComp
$Comp
L AD8244_D:AD8244ARMZ U3-D
U 1 1 5C190461
P 3100 5300
F 0 "U3-D" H 3200 5450 50  0000 C CNN
F 1 "AD8244ARMZ" H 3400 7250 50  0000 C CNN
F 2 "Package_MSOP_10" H 3100 5300 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 3100 5300 50  0001 C CNN
	1    3100 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 4850 2800 5300
Wire Wire Line
	2800 5300 2000 5300
Wire Wire Line
	2000 5300 2000 6800
Connection ~ 2800 5300
Wire Wire Line
	3400 4850 3400 5300
Wire Wire Line
	2800 4200 2800 3650
$Comp
L AD8244_A:AD8244ARMZ U3-A
U 1 1 5C1901B6
P 3100 3650
F 0 "U3-A" H 3100 3800 50  0000 L CNN
F 1 "AD8244ARMZ" H 3150 3950 50  0000 L CNN
F 2 "Package_MSOP_10" H 3100 3650 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 3100 3650 50  0001 C CNN
	1    3100 3650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C193BB9
P 3000 3350
F 0 "#PWR?" H 3000 3200 50  0001 C CNN
F 1 "VCC" H 3000 3550 50  0000 C CNN
F 2 "" H 3000 3350 50  0001 C CNN
F 3 "" H 3000 3350 50  0001 C CNN
	1    3000 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5C193F33
P 3300 3800
F 0 "#PWR?" H 3300 3550 50  0001 C CNN
F 1 "GNDA" H 3450 3700 50  0000 C CNN
F 2 "" H 3300 3800 50  0001 C CNN
F 3 "" H 3300 3800 50  0001 C CNN
	1    3300 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 3950 3150 3950
Wire Wire Line
	3150 3950 3150 3800
Wire Wire Line
	3150 3800 3300 3800
Wire Wire Line
	3400 3650 3700 3650
Wire Wire Line
	3700 4200 3400 4200
$Comp
L hx711:HX711 ADC1
U 1 1 5C19811F
P 5000 4450
F 0 "ADC1" H 5300 4050 50  0000 C CNN
F 1 "HX711 or ADS1X15" H 5550 3950 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 5450 4800 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/ads1110.pdf" H 4700 4800 50  0001 C CNN
	1    5000 4450
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5C19D658
P 4900 4800
F 0 "#PWR?" H 4900 4550 50  0001 C CNN
F 1 "GNDA" H 4905 4627 50  0000 C CNN
F 2 "" H 4900 4800 50  0001 C CNN
F 3 "" H 4900 4800 50  0001 C CNN
	1    4900 4800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C19D6AB
P 4900 4050
F 0 "#PWR?" H 4900 3900 50  0001 C CNN
F 1 "VCC" H 4917 4223 50  0000 C CNN
F 2 "" H 4900 4050 50  0001 C CNN
F 3 "" H 4900 4050 50  0001 C CNN
	1    4900 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 4850 3700 4850
Connection ~ 3400 4850
Text GLabel 6350 4350 0    28   Input ~ 0
<From_MCU_Digital_Pin_driving_this_PD_SCK
Text GLabel 6300 4550 0    28   Input ~ 0
>To_MCU_Digital_Pin_receiving_this_data
Connection ~ 1750 2200
Wire Wire Line
	2450 2200 2500 2200
Wire Wire Line
	1750 2200 2250 2200
Connection ~ 2800 3650
Wire Wire Line
	2250 2200 2250 3650
Wire Wire Line
	2000 6800 2450 6800
$Comp
L MCU_Module:Arduino_UNO_R3 MCU
U 1 1 5C1B3A00
P 7950 3900
F 0 "MCU" H 7950 5078 50  0000 C CNN
F 1 "Some_Arduino_MCU" H 7950 4987 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 8100 2850 50  0001 L CNN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 7750 4950 50  0001 C CNN
	1    7950 3900
	1    0    0    -1  
$EndComp
Text Notes 8800 3550 0    50   ~ 0
Arduino gets power and a \nserial connection to a computer
Text Notes 5000 3450 0    66   ~ 0
NOTE: Devices shown all do not share \ndata over the same Digital Pins except\nthat all DPots share their SCK lines and\ntheir SDI lines.  Define the Digital Pin \nfunctions in preprocessor macros.
Wire Wire Line
	3700 3650 3700 4200
$Comp
L Device:C_Small C1
U 1 1 5C1C2A28
P 4550 3900
F 0 "C1" V 4500 3750 50  0000 C CNN
F 1 "0.05 µF" V 4400 3900 50  0000 C CNN
F 2 "" H 4550 3900 50  0001 C CNN
F 3 "~" H 4550 3900 50  0001 C CNN
	1    4550 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	4700 4050 4900 4050
$Comp
L power:GNDD #PWR?
U 1 1 5C1C4E62
P 4450 3900
F 0 "#PWR?" H 4450 3650 50  0001 C CNN
F 1 "GNDD" H 4454 3745 50  0000 C CNN
F 2 "" H 4450 3900 50  0001 C CNN
F 3 "" H 4450 3900 50  0001 C CNN
	1    4450 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5C1C5AE4
P 2750 3350
F 0 "C2" V 2550 3200 50  0000 C CNN
F 1 "0.05 µF" V 2650 3200 50  0000 C CNN
F 2 "" H 2750 3350 50  0001 C CNN
F 3 "~" H 2750 3350 50  0001 C CNN
	1    2750 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 3350 3000 3350
Connection ~ 3000 3350
$Comp
L power:GNDD #PWR?
U 1 1 5C1C6E06
P 2650 3350
F 0 "#PWR?" H 2650 3100 50  0001 C CNN
F 1 "GNDD" H 2654 3195 50  0000 C CNN
F 2 "" H 2650 3350 50  0001 C CNN
F 3 "" H 2650 3350 50  0001 C CNN
	1    2650 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4550 3700 4850
Wire Wire Line
	3700 4350 3700 4200
Connection ~ 3700 4200
Connection ~ 4900 4050
Wire Wire Line
	4700 4050 4700 3900
Wire Wire Line
	4700 3900 4650 3900
Connection ~ 2250 2200
Wire Wire Line
	2250 2200 2500 2200
Wire Wire Line
	2750 3650 2800 3650
Wire Wire Line
	2250 3650 2800 3650
Wire Wire Line
	3700 4350 4200 4350
Wire Wire Line
	8450 4000 8600 4000
Wire Wire Line
	8600 4000 8600 5150
Wire Wire Line
	8600 5150 4300 5150
Wire Wire Line
	4300 5150 4300 4550
Wire Wire Line
	3700 4550 4300 4550
Connection ~ 4300 4550
Wire Wire Line
	4300 4550 4450 4550
Wire Wire Line
	8450 3900 8700 3900
Wire Wire Line
	8700 3900 8700 5250
Wire Wire Line
	8700 5250 4200 5250
Wire Wire Line
	4200 5250 4200 4350
Wire Bus Line
	3600 6800 5150 6800
Wire Bus Line
	3450 2200 5000 2200
Connection ~ 4200 4350
Wire Wire Line
	4200 4350 4450 4350
$Comp
L 74xx:74LS138 U4
U 1 1 5C1F1B57
P 7600 1600
F 0 "U4" H 8000 2350 50  0000 C CNN
F 1 "74LV138" H 8000 2250 50  0000 C CNN
F 2 "" H 7600 1600 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS138" H 7600 1600 50  0001 C CNN
	1    7600 1600
	1    0    0    -1  
$EndComp
Text Notes 8250 1700 0    50   ~ 0
NOTE: U4 only used for large numbers \nof DPots.  Its outputs drive DPot CS lines.\nSee sketch comments.
$Comp
L power:GNDD #PWR?
U 1 1 5C1F1C9A
P 7600 2300
F 0 "#PWR?" H 7600 2050 50  0001 C CNN
F 1 "GNDD" H 7604 2145 50  0000 C CNN
F 2 "" H 7600 2300 50  0001 C CNN
F 3 "" H 7600 2300 50  0001 C CNN
	1    7600 2300
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5C1F1D0B
P 7600 1000
F 0 "#PWR?" H 7600 850 50  0001 C CNN
F 1 "VCC" H 7617 1173 50  0000 C CNN
F 2 "" H 7600 1000 50  0001 C CNN
F 3 "" H 7600 1000 50  0001 C CNN
	1    7600 1000
	1    0    0    -1  
$EndComp
Text Notes 7450 7500 0    58   ~ 0
GWAAMC Training Aid
Text Notes 8200 7650 0    50   ~ 0
17 Dec 2018
Text Notes 8150 6700 0    89   ~ 0
A Reviving Civility
$EndSCHEMATC
