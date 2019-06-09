EESchema Schematic File Version 4
LIBS:uno shield-cache
EELAYER 29 0
EELAYER END
$Descr A2 23386 16535
encoding utf-8
Sheet 1 2
Title ""
Date "05-09-2019"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GNDA #PWR013
U 1 1 5C19D658
P 14800 3375
F 0 "#PWR013" H 14800 3125 50  0001 C CNN
F 1 "GNDA" H 14805 3202 50  0000 C CNN
F 2 "" H 14800 3375 50  0001 C CNN
F 3 "" H 14800 3375 50  0001 C CNN
	1    14800 3375
	1    0    0    -1  
$EndComp
Text Notes 19125 15772 0    47   ~ 0
GWAAMC Training Aid Main Board for UNO with MCP4262 HX711 LM334 REF200 MMBF5462 (2N5462)
Text Notes 19775 15900 0    39   ~ 0
                      (C) Copyright Kenneth L. Anderson 2018-2019
Text Notes 18925 15522 0    58   ~ 0
 1 2
$Comp
L audiojack3_ground_switchtr:AudioJack3_Ground_SwitchTR J1
U 1 1 5C536746
P 1500 2375
F 0 "J1" H 1175 2350 50  0000 L CNN
F 1 "Conn_3.5mm" H 1250 2600 50  0000 L CNN
F 2 "multipackage:Jack_3.5mm_CUI_SJ1-3534NS_Horizontal_CircularHoles" H 1500 2375 50  0001 C CNN
F 3 " ~" H 1500 2375 50  0001 C CNN
F 4 "08  Then check work for inadvertent shorts and opens" H -500 725 50  0001 C CNN "ClickToSortForPlacement"
F 5 "SJ1-3534NS" H 1500 2375 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 1500 2375 50  0001 C CNN "Source"
	1    1500 2375
	1    0    0    1   
$EndComp
$Comp
L power:GNDD #PWR015
U 1 1 5C5C35A0
P 15700 3375
F 0 "#PWR015" H 15700 3125 50  0001 C CNN
F 1 "GNDD" H 15700 3225 50  0000 C CNN
F 2 "" H 15700 3375 50  0001 C CNN
F 3 "" H 15700 3375 50  0001 C CNN
	1    15700 3375
	1    0    0    -1  
$EndComp
$Comp
L AD8244_A:AD8244ARMZ U1
U 4 1 5C72CF84
P 12800 3975
F 0 "U1" H 12950 4075 50  0000 C CNN
F 1 "AD8244ARMZ" H 13100 3875 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 12800 3975 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 12800 3975 50  0001 C CNN
F 4 "01" H 10100 -1825 50  0001 C CNN "PlacementOrder"
F 5 "01" H 10100 -1675 50  0001 C CNN "SortForPlacement"
F 6 "00 00 !Assembly instructions  not complete - do not trust this yet for assembly order!  Place (always means solder herein), then check work for inadvertent shorts and opens" H 10100 -1675 50  0001 C CNN "ClickToSortForPlacement"
F 7 "AD8244ARMZ-R7" H 12800 3975 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12800 3975 50  0001 C CNN "Source"
	4    12800 3975
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR019
U 1 1 5C764394
P 20525 1125
F 0 "#PWR019" H 20525 975 50  0001 C CNN
F 1 "VCC" V 20543 1298 50  0000 C CNN
F 2 "" H 20525 1125 50  0001 C CNN
F 3 "" H 20525 1125 50  0001 C CNN
	1    20525 1125
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR027
U 1 1 5C76F5BF
P 21900 8772
F 0 "#PWR027" H 21900 8622 50  0001 C CNN
F 1 "VCC" H 21917 8945 50  0000 C CNN
F 2 "" H 21900 8772 50  0001 C CNN
F 3 "" H 21900 8772 50  0001 C CNN
	1    21900 8772
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5C794BD3
P 15700 3375
F 0 "#FLG02" H 15700 3450 50  0001 C CNN
F 1 "PWR_FLAG" H 15925 3350 50  0000 C CNN
F 2 "" H 15700 3375 50  0001 C CNN
F 3 "~" H 15700 3375 50  0001 C CNN
	1    15700 3375
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR020
U 1 1 5C7E6F1E
P 21000 9772
F 0 "#PWR020" H 21000 9522 50  0001 C CNN
F 1 "GNDD" H 21004 9617 50  0000 C CNN
F 2 "" H 21000 9772 50  0001 C CNN
F 3 "" H 21000 9772 50  0001 C CNN
	1    21000 9772
	1    0    0    -1  
$EndComp
Text Label 20900 1150 1    60   ~ 0
IOREF
Text Label 20650 2200 0    60   ~ 0
A0
Text Label 20650 2300 0    60   ~ 0
A1
Text Label 20650 2400 0    60   ~ 0
A2
Text Label 20650 2500 0    60   ~ 0
A3
Text Label 20650 2700 0    60   ~ 0
A5(SCL)(1)
Text Label 22250 2900 0    60   ~ 0
0(Rx)
Text Label 22249 2700 0    60   ~ 0
2
Text Label 22250 2800 0    60   ~ 0
1(Tx)
Text Label 22250 2600 0    60   ~ 0
3(**)
Text Label 22249 2500 0    60   ~ 0
4
Text Label 22250 2400 0    60   ~ 0
5(**)
Text Label 22250 2300 0    60   ~ 0
6(**)
Text Label 22249 2200 0    60   ~ 0
7
Text Notes 20225 850  0    60   ~ 0
Shield for Arduino "Uno" board Rev 3.  J2 \naccommodates the advanced style with A6 and \nA7. Not-advanced UNOs will not connect to J2 \npins 1 and 9 so VR3 and VR4 will not work.
Text Label 20800 1200 1    50   ~ 0
RESET(1)
$Comp
L Connector_Generic:Conn_01x01 P1
U 1 1 5C7F64C7
P 22500 647
F 0 "P1" V 22600 647 50  0000 C CNN
F 1 "CONN_01X01" V 22600 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" H 22421 721 20  0001 C CNN
F 3 "" H 22500 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22500 647 50  0001 C CNN "Part_number"
F 6 "n/a" H 22500 647 50  0001 C CNN "Source"
	1    22500 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P2
U 1 1 5C7F64CE
P 22600 647
F 0 "P2" V 22700 647 50  0000 C CNN
F 1 "CONN_01X01" V 22700 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" H 22600 647 20  0001 C CNN
F 3 "" H 22600 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22600 647 50  0001 C CNN "Part_number"
F 6 "n/a" H 22600 647 50  0001 C CNN "Source"
	1    22600 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P3
U 1 1 5C7F64D5
P 22700 647
F 0 "P3" V 22800 647 50  0000 C CNN
F 1 "CONN_01X01" V 22800 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" V 22700 647 20  0001 C CNN
F 3 "" H 22700 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22700 647 50  0001 C CNN "Part_number"
F 6 "n/a" H 22700 647 50  0001 C CNN "Source"
	1    22700 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P4
U 1 1 5C7F64DC
P 22800 647
F 0 "P4" V 22900 647 50  0000 C CNN
F 1 "CONN_01X01" V 22900 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" H 22724 569 20  0001 C CNN
F 3 "" H 22800 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22800 647 50  0001 C CNN "Part_number"
F 6 "n/a" H 22800 647 50  0001 C CNN "Source"
	1    22800 647 
	0    -1   -1   0   
$EndComp
NoConn ~ 22500 847 
NoConn ~ 22600 847 
NoConn ~ 22700 847 
NoConn ~ 22800 847 
Wire Notes Line
	22925 997  22425 997 
Wire Notes Line
	22425 997  22425 497 
$Comp
L Connector_Generic:Conn_02x03_Odd_Even ICSP1
U 1 1 5C7F651F
P 20850 3200
F 0 "ICSP1" H 20900 3517 50  0000 C CNN
F 1 "ICSP Socket" H 20900 3426 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x03_P2.54mm_Vertical" H 20850 3200 50  0001 C CNN
F 3 "~" H 20850 3200 50  0001 C CNN
F 4 "07 Height with all connectors mated.  Then check work for inadvertent shorts and opens" H 11650 0   50  0001 C CNN "ClickToSortForPlacement"
F 5 "SSQ-103-03-T-D" H 20850 3200 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 20850 3200 50  0001 C CNN "Source"
	1    20850 3200
	1    0    0    -1  
$EndComp
Text Label 21150 3200 0    50   ~ 0
MOSI(1)
Text Label 21150 3300 0    50   ~ 0
GND(4)
Text Label 20650 3100 2    50   ~ 0
MISO(1)
Text Label 20650 3200 2    50   ~ 0
SCK(1)
Text Label 20650 3300 2    50   ~ 0
RESET(2)
$Comp
L conn_01x08_maleA:Conn_01x09_Male J2
U 1 1 5C87197B
P 21350 1500
F 0 "J2" H 21450 2050 50  0000 L CNN
F 1 "Power" V 21275 1375 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 21350 1500 50  0001 C CNN
F 3 "~" H 21350 1500 50  0001 C CNN
F 4 "01 Temporary tack solder pin 5 only.  Height with all connectors mated.  Then check work for inadvertent shorts and opens" H 11800 -100 50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0" H 21350 1500 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21350 1500 50  0001 C CNN "Source"
	1    21350 1500
	-1   0    0    -1  
$EndComp
$Comp
L conn_01x08_maleA:Conn_01x08_Male J5
U 1 1 5C8A7B72
P 21850 2500
F 0 "J5" H 21800 2900 50  0000 C CNN
F 1 "Digital" V 21600 2450 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 21850 2500 50  0001 C CNN
F 3 "~" H 21850 2500 50  0001 C CNN
F 4 "11 Height with all connectors mated.  Then check work for inadvertent shorts and opens" H 11650 0   50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0" H 21850 2500 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21850 2500 50  0001 C CNN "Source"
	1    21850 2500
	1    0    0    -1  
$EndComp
Text Label 20400 1425 2    50   ~ 0
GNDD
Text Label 20400 1500 2    50   ~ 0
GNDD
NoConn ~ 22250 2900
NoConn ~ 22250 2800
NoConn ~ 20650 3100
NoConn ~ 20650 3300
$Comp
L power:VCC #PWR023
U 1 1 5CAAC3A7
P 21150 3100
F 0 "#PWR023" H 21150 2950 50  0001 C CNN
F 1 "VCC" H 21167 3273 50  0000 C CNN
F 2 "" H 21150 3100 50  0001 C CNN
F 3 "" H 21150 3100 50  0001 C CNN
	1    21150 3100
	1    0    0    -1  
$EndComp
NoConn ~ 1700 2375
$Comp
L power:GNDD #PWR024
U 1 1 5CB66292
P 21150 3300
F 0 "#PWR024" H 21150 3050 50  0001 C CNN
F 1 "GNDD" H 21154 3145 50  0000 C CNN
F 2 "" H 21150 3300 50  0001 C CNN
F 3 "" H 21150 3300 50  0001 C CNN
	1    21150 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR018
U 1 1 5CB8B72F
P 20400 1500
F 0 "#PWR018" H 20400 1250 50  0001 C CNN
F 1 "GNDD" H 20404 1345 50  0000 C CNN
F 2 "" H 20400 1500 50  0001 C CNN
F 3 "" H 20400 1500 50  0001 C CNN
	1    20400 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR028
U 1 1 5CB9E79B
P 22825 1225
F 0 "#PWR028" H 22825 975 50  0001 C CNN
F 1 "GNDD" H 22775 1075 50  0000 C CNN
F 2 "" H 22825 1225 50  0001 C CNN
F 3 "" H 22825 1225 50  0001 C CNN
	1    22825 1225
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG03
U 1 1 5CBCF59E
P 20450 1075
F 0 "#FLG03" H 20450 1150 50  0001 C CNN
F 1 "PWR_FLAG" V 20350 1025 50  0000 C CNN
F 2 "" H 20450 1075 50  0001 C CNN
F 3 "~" H 20450 1075 50  0001 C CNN
	1    20450 1075
	1    0    0    -1  
$EndComp
Wire Wire Line
	20600 9772 21000 9772
Connection ~ 21000 9772
$Comp
L Device:LED D1
U 1 1 5CC7E1A3
P 20600 9222
F 0 "D1" V 20622 9397 50  0000 R CNN
F 1 "Red: Electrodes shorted" H 21647 9322 50  0000 R CNN
F 2 "multipackage:LED_Rectangular_W5.0mm_H2.0mm" H 20600 9222 50  0001 C CNN
F 3 "~" H 20600 9222 50  0001 C CNN
F 4 "07" H 13950 6822 50  0001 C CNN "PlacementOrder"
F 5 "07" H 13950 6822 50  0001 C CNN "SortForPlacement"
F 6 "09  Then check work for inadvertent shorts and opens" H 13950 6822 50  0001 C CNN "ClickToSortForPlacement"
F 7 "SSL-LX2573ID" H 20600 9222 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 20600 9222 50  0001 C CNN "Source"
	1    20600 9222
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5CC7E20B
P 21000 9222
F 0 "D2" V 20997 9122 50  0000 R CNN
F 1 "Yellow: Inadequate electrode conductance" H 22697 9047 50  0000 R CNN
F 2 "multipackage:LED_Rectangular_W5.0mm_H2.0mm_yellow" H 21000 9222 50  0001 C CNN
F 3 "~" H 21000 9222 50  0001 C CNN
F 4 "07" H 13950 6822 50  0001 C CNN "PlacementOrder"
F 5 "07" H 13950 6822 50  0001 C CNN "SortForPlacement"
F 6 "09  Then check work for inadvertent shorts and opens" H 13950 6822 50  0001 C CNN "ClickToSortForPlacement"
F 7 "SSL-LX2573YD" H 21000 9222 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 21000 9222 50  0001 C CNN "Source"
	1    21000 9222
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR016
U 1 1 5CF1EA3B
P 20100 1097
F 0 "#PWR016" H 20100 947 50  0001 C CNN
F 1 "+5V" H 20115 1270 50  0000 C CNN
F 2 "" H 20100 1097 50  0001 C CNN
F 3 "" H 20100 1097 50  0001 C CNN
	1    20100 1097
	-1   0    0    1   
$EndComp
Wire Notes Line
	20200 3547 22900 3547
Wire Notes Line
	20200 497  20200 3547
Wire Notes Line
	21600 2797 21600 3547
Wire Notes Line
	20250 2797 21600 2797
$Comp
L power:VCC #PWR017
U 1 1 5D53A604
P 20100 1097
F 0 "#PWR017" H 20100 947 50  0001 C CNN
F 1 "VCC" H 20100 1247 50  0000 C CNN
F 2 "" H 20100 1097 50  0001 C CNN
F 3 "" H 20100 1097 50  0001 C CNN
	1    20100 1097
	1    0    0    -1  
$EndComp
Wire Wire Line
	20800 8772 21900 8772
$Comp
L Device:Q_NMOS_SGD Q7
U 1 1 5C9AB0B5
P 21800 9572
F 0 "Q7" H 22000 9472 50  0000 L CNN
F 1 "DMN601K-7" H 22000 9372 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 22000 9497 50  0001 L CIN
F 3 "http://www.redrok.com/MOSFET_BS108_200V_250mA_8O_Vth1.5_TO-92.PDF" H 21800 9572 50  0001 L CNN
F 4 "03" H 13950 6822 50  0001 C CNN "PlacementOrder"
F 5 "03" H 13950 6822 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 13950 6822 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 21800 9572 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 21800 9572 50  0001 C CNN "Source"
	1    21800 9572
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 5C9AB15E
P 21900 9222
F 0 "D3" V 22000 9222 50  0000 R CNN
F 1 "Green: Proper electrode conductance" H 23800 9322 50  0000 R CNN
F 2 "multipackage:LED_Rectangular_W5.0mm_H2.0mm_green" H 21900 9222 50  0001 C CNN
F 3 "~" H 21900 9222 50  0001 C CNN
F 4 "07" H 13950 6822 50  0001 C CNN "PlacementOrder"
F 5 "07" H 13950 6822 50  0001 C CNN "SortForPlacement"
F 6 "09  Then check work for inadvertent shorts and opens" H 13950 6822 50  0001 C CNN "ClickToSortForPlacement"
F 7 "http://Arrow.com" H 21900 9222 50  0001 C CNN "Source"
F 8 "SSL-LX2573GD" H 21900 9222 50  0001 C CNN "Part_number"
	1    21900 9222
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R14
U 1 1 5C9AB204
P 21900 8922
F 0 "R14" H 21775 8919 50  0000 C CNN
F 1 "470 Ω" H 22075 8919 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 21940 8912 50  0001 C CNN
F 3 "~" H 21900 8922 50  0001 C CNN
F 4 "02" H 13950 6822 50  0001 C CNN "PlacementOrder"
F 5 "02" H 13950 6822 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 13950 6822 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RK73B1JTTD471J" H 21900 8922 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 21900 8922 50  0001 C CNN "Source"
	1    21900 8922
	1    0    0    -1  
$EndComp
Connection ~ 21900 8772
Wire Wire Line
	21900 9772 21300 9772
Wire Wire Line
	21000 9072 21600 9072
Connection ~ 21000 9072
Connection ~ 21300 9772
Wire Wire Line
	21300 9772 21000 9772
$Sheet
S 2425 650  884  150 
U 5D5A7B87
F0 "Sheet5D5A7B86" 50
F1 "Coax Cable and Diagnostic DUT.sch" 50
$EndSheet
Text Notes 20325 4172 0    50   ~ 0
Magnification \namplitude
Text Notes 21835 4132 0    50   ~ 0
Gain\nadjust\n3 settings
$Comp
L power:GNDD #PWR026
U 1 1 5C90D427
P 21675 4475
F 0 "#PWR026" H 21675 4225 50  0001 C CNN
F 1 "GNDD" H 21679 4320 50  0000 C CNN
F 2 "" H 21675 4475 50  0001 C CNN
F 3 "" H 21675 4475 50  0001 C CNN
	1    21675 4475
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_US VR2
U 1 1 5CB70AF8
P 21675 4325
F 0 "VR2" H 21607 4279 50  0000 R CNN
F 1 "200 KΩ" H 21607 4370 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-2_Single_Horizontal" H 21675 4325 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 21675 4325 50  0001 C CNN
F 4 "12 Power down first, remove solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after" H 12715 -1405 50  0001 C CNN "ClickToSortForPlacement"
F 5 "PTV09A-2030U-B204 or may end in B203 or some resistance in between those.  The 4030 may be 4020 or 4015 for shorter shaft" H 21675 4325 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21675 4325 50  0001 C CNN "Source"
	1    21675 4325
	-1   0    0    1   
$EndComp
$Comp
L power:VCC #PWR025
U 1 1 5C90D42E
P 21675 4175
F 0 "#PWR025" H 21675 4025 50  0001 C CNN
F 1 "VCC" H 21692 4348 50  0000 C CNN
F 2 "" H 21675 4175 50  0001 C CNN
F 3 "" H 21675 4175 50  0001 C CNN
	1    21675 4175
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_US VR1
U 1 1 5DCBBC4B
P 21025 4325
F 0 "VR1" H 20957 4279 50  0000 R CNN
F 1 "200 KΩ" H 20957 4370 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-2_Single_Horizontal" H 21025 4325 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 21025 4325 50  0001 C CNN
F 4 "12 Don't solder, merely press against sides of holes inside them with power on and diags running.  When A0 diags are successful, power down, pull boards apart with great care, then remove J3 and attach it again with a tack solder to J3 pin 2. Power up and run A1 diags using VR2 position similarly (inserted without soldering).   When A1 diags are successful power down, then remove J2, 3, & 4, R1 and solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after" H 12065 -1405 50  0001 C CNN "ClickToSortForPlacement"
F 5 "PTV09A-2030U-B204 or may end in B203 or some resistance in between those.  The 4030 may be 4020 or 4015 for shorter shaft" H 21025 4325 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21025 4325 50  0001 C CNN "Source"
	1    21025 4325
	-1   0    0    1   
$EndComp
$Comp
L power:GNDD #PWR022
U 1 1 5DD017AA
P 21025 4475
F 0 "#PWR022" H 21025 4225 50  0001 C CNN
F 1 "GNDD" H 21029 4320 50  0000 C CNN
F 2 "" H 21025 4475 50  0001 C CNN
F 3 "" H 21025 4475 50  0001 C CNN
	1    21025 4475
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR021
U 1 1 5DD0CD99
P 21025 4175
F 0 "#PWR021" H 21025 4025 50  0001 C CNN
F 1 "VCC" H 21042 4348 50  0000 C CNN
F 2 "" H 21025 4175 50  0001 C CNN
F 3 "" H 21025 4175 50  0001 C CNN
	1    21025 4175
	1    0    0    -1  
$EndComp
$Comp
L conn_01x06_male:Conn_01x06_Male J3
U 1 1 5C90EA9D
P 21250 2400
F 0 "J3" H 21250 2700 50  0000 L CNN
F 1 "Analog" V 21400 2250 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 21350 2300 50  0001 C CNN
F 3 "~" H 21350 2300 50  0001 C CNN
F 4 "01 Temporary tack solder pin 1 only.  Height with all connectors mated.  Then check work for inadvertent shorts and opens" H 11650 0   50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0" H 21250 2400 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21250 2400 50  0001 C CNN "Source"
	1    21250 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_SGD Q6
U 1 1 5CC49AA9
P 20900 9572
F 0 "Q6" H 21100 9472 50  0000 L CNN
F 1 "DMN601K-7" H 21100 9322 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 21100 9497 50  0001 L CIN
F 3 "~" H 20900 9572 50  0001 L CNN
F 4 "03" H 13950 6822 50  0001 C CNN "PlacementOrder"
F 5 "03" H 13950 6822 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 13950 6822 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 20900 9572 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 20900 9572 50  0001 C CNN "Source"
	1    20900 9572
	1    0    0    -1  
$EndComp
Wire Wire Line
	20750 9572 20700 9572
Wire Wire Line
	20750 9572 20750 10025
$Comp
L AD8244_A:AD8244ARMZ U1
U 2 1 5F04F6CF
P 12800 2350
F 0 "U1" H 12950 2450 50  0000 C CNN
F 1 "AD8244ARMZ" H 12975 2550 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 12800 2350 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 12800 2350 50  0001 C CNN
F 4 "AD8244ARMZ-R7" H 12800 2350 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 12800 2350 50  0001 C CNN "Source"
F 6 "00 00 !Assembly instructions  not complete - do not trust this yet for assembly order!  Place (always means solder herein), then check work for inadvertent shorts and opens" H 12800 2350 50  0001 C CNN "ClickToSortForPlacement"
	2    12800 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5F09FFED
P 13000 1475
F 0 "C4" V 13000 1625 50  0000 C CNN
F 1 "0.1 µF" V 13000 1225 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 13000 1475 50  0001 C CNN
F 3 "~" H 13000 1475 50  0001 C CNN
F 4 "08" H 7450 -2325 50  0001 C CNN "PlacementOrder"
F 5 "08" H 8200 -2375 50  0001 C CNN "SortForPlacement"
F 6 "10  Then check work for inadvertent shorts and opens" H 8200 -2375 50  0001 C CNN "ClickToSortForPlacement"
F 7 "CC0402KRX7R7BB104" H 13000 1475 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 13000 1475 50  0001 C CNN "Source"
	1    13000 1475
	0    -1   -1   0   
$EndComp
Connection ~ 13400 2350
Wire Wire Line
	13100 2350 13400 2350
Text Notes 725  2300 0    100  Italic 20
!
Text Notes 700  2475 0    50   Italic 10
    NOT \n    FOR \nVOLTAGE
Wire Wire Line
	14800 2825 14700 2825
Wire Wire Line
	22450 2600 21900 2600
Wire Wire Line
	22400 2700 21900 2700
Wire Wire Line
	21900 2500 22500 2500
Wire Wire Line
	21900 2400 22550 2400
Wire Wire Line
	21900 2300 22600 2300
Wire Wire Line
	21900 2200 22650 2200
$Comp
L uno-shield-rescue:HX711-hx711-uno-shield-rescue ADC1
U 1 1 5C19811F
P 15350 2675
F 0 "ADC1" H 15800 2525 50  0000 C CNN
F 1 "HX711 module" H 15950 2425 50  0000 C CNN
F 2 "multipackage:HX711 module" H 15800 3025 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/ads1110.pdf" H 15050 3025 50  0001 C CNN
F 4 "13" H 10100 -1697 50  0001 C CNN "ClickToSortForPlacement"
F 5 "cheapest https://www.aliexpress.com/item/1PCS-X-HX711-modules-weigh-sensors-for-AD-module-chip-preferred-DIY-Graduation/32851591970.html?spm=2114.search0104.3.1.7ad07d02cMfLjw&ws_ab_test=searchweb0_0,searchweb201602_4_10065_10130_10068_10890_10547_319_10546_317_10548_10545_10696_453_10084_454_10083_10618_10307_537_536_10059_10884_10887_321_322_10103,searchweb201603_52,ppcSwitch_0&algo_expid=c46a3ce9-e8cf-4d7c-8e89-50e4aff4f628-0&algo_pvid=c46a3ce9-e8cf-4d7c-8e89-50e4aff4f628&transAbTest=ae803_3; fast arrival https://www.ebay.com/itm/Dual-Channel-HX711-Weighing-Pressure-Sensor-24-bit-Precision-A-D-Module-Arduino/202679288819?hash=item2f30a083f3:g:xyIAAOSwhXtc2wdH" H 15350 2675 50  0001 C CNN "Source"
F 6 "cheapest CN1501541594; fast arrival Dual Channel HX711" H 15350 2675 50  0001 C CNN "Part_number"
	1    15350 2675
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR014
U 1 1 5C19D6AB
P 15450 2125
F 0 "#PWR014" H 15450 1975 50  0001 C CNN
F 1 "VCC" V 15375 2300 50  0000 C CNN
F 2 "" H 15450 2125 50  0001 C CNN
F 3 "" H 15450 2125 50  0001 C CNN
	1    15450 2125
	0    1    1    0   
$EndComp
Connection ~ 14800 3375
$Comp
L Device:CP_Small C3
U 1 1 5F080FB8
P 13000 1325
F 0 "C3" V 13075 1225 50  0000 C CNN
F 1 "2.2 µF" V 13075 1025 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 13000 1325 50  0001 C CNN
F 3 "~" H 13000 1325 50  0001 C CNN
F 4 "08" H 7450 -2325 50  0001 C CNN "PlacementOrder"
F 5 "08" H 8200 -2375 50  0001 C CNN "SortForPlacement"
F 6 "10  Then check work for inadvertent shorts and opens" H 8200 -2375 50  0001 C CNN "ClickToSortForPlacement"
F 7 "CL21A225KAFNNNG " H 13000 1325 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 13000 1325 50  0001 C CNN "Source"
	1    13000 1325
	0    -1   -1   0   
$EndComp
Wire Wire Line
	14350 3100 15050 3100
Wire Wire Line
	14800 3375 15050 3375
Wire Wire Line
	15575 3375 15700 3375
Connection ~ 15700 3375
Wire Wire Line
	15575 3075 15575 3375
$Comp
L Device:Net-Tie_2 NT1
U 1 1 5D4059A2
P 15250 3075
F 0 "NT1" V 15296 3031 50  0001 R CNN
F 1 "Net-Tie_2" V 15375 3050 50  0001 R CNN
F 2 "multipackage:NetTie-2_THT_Pad1.0mm" H 15250 3075 50  0001 C CNN
F 3 "~" H 15250 3075 50  0001 C CNN
F 4 "n/a" H 15250 3075 50  0001 C CNN "Part_number"
F 5 "n/a" H 15250 3075 50  0001 C CNN "Source"
	1    15250 3075
	1    0    0    -1  
$EndComp
Wire Wire Line
	15575 3075 15350 3075
Wire Wire Line
	15225 1800 15225 1900
$Comp
L AD8244_A:AD8244ARMZ U1
U 1 1 5F04DF16
P 12800 1725
F 0 "U1" H 12900 1825 50  0000 L CNN
F 1 "AD8244ARMZ" H 13100 1825 50  0000 L CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 12800 1725 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 12800 1725 50  0001 C CNN
F 4 "AD8244ARMZ-R7" H 12800 1725 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 12800 1725 50  0001 C CNN "Source"
F 6 "00 00 !Assembly instructions  not complete - do not trust this yet for assembly order!  Place (always means solder herein), then check work for inadvertent shorts and opens" H 12800 1725 50  0001 C CNN "ClickToSortForPlacement"
	1    12800 1725
	1    0    0    -1  
$EndComp
Wire Wire Line
	15150 3075 15050 3075
Wire Wire Line
	15050 3075 15050 3100
Connection ~ 15050 3100
Connection ~ 12700 1325
Wire Wire Line
	12700 1325 12700 1425
Wire Wire Line
	15450 2125 15350 2125
Connection ~ 15225 1900
Wire Wire Line
	15225 1900 15225 1950
Wire Wire Line
	15350 2225 15350 2125
Wire Wire Line
	15350 1900 15225 1900
$Comp
L Device:CP_Small C5
U 1 1 5C854E30
P 15125 1800
F 0 "C5" V 15125 1600 50  0000 C CNN
F 1 "2.2 µF" V 15025 1800 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 15125 1800 50  0001 C CNN
F 3 "~" H 15125 1800 50  0001 C CNN
F 4 "08" H 9575 -1850 50  0001 C CNN "PlacementOrder"
F 5 "08" H 10325 -1900 50  0001 C CNN "SortForPlacement"
F 6 "10  Then check work for inadvertent shorts and opens" H 10325 -1900 50  0001 C CNN "ClickToSortForPlacement"
F 7 "CL21A225KAFNNNG" H 15125 1800 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 15125 1800 50  0001 C CNN "Source"
	1    15125 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	15050 3100 15050 3375
Wire Wire Line
	12900 1325 12900 1475
Connection ~ 13100 1325
Wire Wire Line
	13100 1325 13100 1475
Wire Wire Line
	12700 1325 12900 1325
Connection ~ 12900 1325
Wire Wire Line
	13100 1325 14350 1325
Wire Wire Line
	14350 1325 14350 3100
Text Notes 7900 4725 0    50   ~ 0
NOTE - These resistors are spec'd tightly for mitigating \ntemperature drift.  If a different tempco is determined \nto be required for the board, changing the tempcos of \nthese resistors would be the solution.
$Comp
L Device:R_Small_US R6
U 1 1 5D7C1CE7
P 8375 4075
F 0 "R6" H 8525 4075 50  0000 C CNN
F 1 "44.2 KΩ 0.1% 0.1W(1/10W) ±10ppm/°C (1676343-2)" H 7275 4075 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8375 4075 50  0001 C CNN
F 3 "~" H 8375 4075 50  0001 C CNN
F 4 "http://Arrow.com" H 8375 4075 50  0001 C CNN "Source"
F 5 "1676343-2" H 8375 4075 50  0001 C CNN "Part_number"
	1    8375 4075
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 2350 9400 2350
$Comp
L power:VCC #PWR06
U 1 1 5D6F12A4
P 8375 3275
F 0 "#PWR06" H 8375 3125 50  0001 C CNN
F 1 "VCC" H 8325 3425 50  0000 C CNN
F 2 "" H 8375 3275 50  0001 C CNN
F 3 "" H 8375 3275 50  0001 C CNN
	1    8375 3275
	1    0    0    -1  
$EndComp
NoConn ~ 7875 3025
NoConn ~ 8475 3875
$Comp
L power:GNDA #PWR05
U 1 1 5D6610C1
P 7775 3025
F 0 "#PWR05" H 7775 2775 50  0001 C CNN
F 1 "GNDA" H 7780 2852 50  0000 C CNN
F 2 "" H 7775 3025 50  0001 C CNN
F 3 "" H 7775 3025 50  0001 C CNN
	1    7775 3025
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2350 9500 2800
Wire Wire Line
	10525 1575 10525 2000
Wire Wire Line
	11100 1600 11275 1600
Wire Wire Line
	11100 1750 11100 1600
Wire Wire Line
	9850 1650 9850 1750
Wire Wire Line
	10000 1650 9850 1650
$Comp
L power:GNDD #PWR010
U 1 1 5D5FFC74
P 10000 1650
F 0 "#PWR010" H 10000 1400 50  0001 C CNN
F 1 "GNDD" H 10004 1495 50  0000 C CNN
F 2 "" H 10000 1650 50  0001 C CNN
F 3 "" H 10000 1650 50  0001 C CNN
	1    10000 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR012
U 1 1 5D5FF76B
P 11275 1600
F 0 "#PWR012" H 11275 1350 50  0001 C CNN
F 1 "GNDD" H 11279 1445 50  0000 C CNN
F 2 "" H 11275 1600 50  0001 C CNN
F 3 "" H 11275 1600 50  0001 C CNN
	1    11275 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR07
U 1 1 5D5FE8B7
P 8375 4175
F 0 "#PWR07" H 8375 3925 50  0001 C CNN
F 1 "GNDA" H 8380 4002 50  0000 C CNN
F 2 "" H 8375 4175 50  0001 C CNN
F 3 "" H 8375 4175 50  0001 C CNN
	1    8375 4175
	1    0    0    -1  
$EndComp
Connection ~ 8875 2425
Wire Wire Line
	8875 2425 8875 2125
Wire Wire Line
	8075 2425 8875 2425
Wire Wire Line
	7775 2125 7775 2225
Wire Wire Line
	7475 1925 7475 1325
Wire Wire Line
	8350 2250 9500 2250
Wire Wire Line
	8350 1525 8350 2250
Wire Wire Line
	7975 1525 8350 1525
Connection ~ 7775 1725
Wire Wire Line
	8250 1725 8250 2350
Wire Wire Line
	7775 1725 8250 1725
Wire Wire Line
	7475 1325 7775 1325
Connection ~ 7475 1325
Wire Wire Line
	7775 1325 8575 1325
Wire Wire Line
	8575 1325 8875 1325
Connection ~ 8575 1325
$Comp
L Device:Q_PJFET_SDG Q1
U 1 1 5D3CA4B3
P 7675 1925
F 0 "Q1" H 7575 2075 50  0000 L CNN
F 1 "MMBF5462 (2N5462)" H 7350 1725 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 7875 2025 50  0001 C CNN
F 3 "~" H 7675 1925 50  0001 C CNN
F 4 "00 Not component, only use temporary solder bridge on board's back side between pin 1 (D) & 2 (S)." H 7675 1925 50  0001 C CNN "ClickToSortForPlacement"
F 5 "MMBF5462" H 7675 1925 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 7675 1925 50  0001 C CNN "Source"
	1    7675 1925
	1    0    0    -1  
$EndComp
Wire Wire Line
	7775 2225 7775 2425
Connection ~ 7775 2225
Wire Wire Line
	6200 2225 7775 2225
$Comp
L Device:R_Small_US R7
U 1 1 5D3506B3
P 8875 4075
F 0 "R7" H 8725 4075 50  0000 C CNN
F 1 "22.6 KΩ 0.1% 0.125W(1/8W) ±10ppm/°C (ERA6ARB2262V)" H 10075 4075 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8875 4075 50  0001 C CNN
F 3 "~" H 8875 4075 50  0001 C CNN
F 4 "http://Arrow.com" H 8875 4075 50  0001 C CNN "Source"
F 5 "ERA6ARB2262V" H 8875 4075 50  0001 C CNN "Part_number"
	1    8875 4075
	1    0    0    -1  
$EndComp
Wire Wire Line
	10725 1900 10750 1900
Wire Wire Line
	10725 1525 10725 1900
Wire Wire Line
	9075 1525 10725 1525
Wire Wire Line
	10525 2000 10750 2000
Wire Wire Line
	8575 1925 8575 1325
$Comp
L Device:Q_PJFET_SDG Q2
U 1 1 5D11525B
P 8775 1925
F 0 "Q2" H 8650 2075 50  0000 L CNN
F 1 "MMBF5462 (2N5462)" H 8450 1700 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 8975 2025 50  0001 C CNN
F 3 "~" H 8775 1925 50  0001 C CNN
F 4 "00 Not component, only use temporary solder bridge on board's back side between pin 1 (D) & 2 (S)." H 8775 1925 50  0001 C CNN "ClickToSortForPlacement"
F 5 "MMBF5462" H 8775 1925 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 8775 1925 50  0001 C CNN "Source"
	1    8775 1925
	1    0    0    -1  
$EndComp
Connection ~ 8875 1325
$Comp
L Reference_Current:REF200AU U3
U 3 1 5D0FCC87
P 7775 2725
F 0 "U3" H 8155 2771 50  0000 L CNN
F 1 "REF200AU" H 8155 2680 50  0000 L CIN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7650 2750 50  0001 R CIN
F 3 "www.ti.com/lit/ds/symlink/ref200.pdf" H 8075 2725 50  0001 C CIN
F 4 "http://Arrow.com" H 7775 2725 50  0001 C CNN "Source"
F 5 "REF200AU" H 7775 2725 50  0001 C CNN "Part_number"
	3    7775 2725
	1    0    0    -1  
$EndComp
$Comp
L Reference_Current:REF200AU U3
U 2 1 5D0FB910
P 8375 3575
F 0 "U3" H 8555 3621 50  0000 L CNN
F 1 "REF200AU" H 8555 3530 50  0000 L CIN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8250 3600 50  0001 R CIN
F 3 "www.ti.com/lit/ds/symlink/ref200.pdf" H 8675 3575 50  0001 C CIN
F 4 "http://Arrow.com" H 8375 3575 50  0001 C CNN "Source"
F 5 "REF200AU" H 8375 3575 50  0001 C CNN "Part_number"
	2    8375 3575
	1    0    0    -1  
$EndComp
$Comp
L Reference_Current:REF200AU U3
U 1 1 5D0F9980
P 6150 1100
F 0 "U3" H 6330 1146 50  0000 L CNN
F 1 "REF200AU" H 6330 1055 50  0000 L CIN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 6025 1125 50  0001 R CIN
F 3 "www.ti.com/lit/ds/symlink/ref200.pdf" H 6450 1100 50  0001 C CIN
F 4 "http://Arrow.com" H 6150 1100 50  0001 C CNN "Source"
F 5 "REF200AU" H 6150 1100 50  0001 C CNN "Part_number"
	1    6150 1100
	1    0    0    -1  
$EndComp
$Comp
L uno-shield-rescue:ADL5315ACPZ-R7-2019-05-19_00-44-38 U2
U 1 1 5CE2F217
P 3800 2225
F 0 "U2" H 5000 2612 60  0000 C CNN
F 1 "ADL5315ACPZ-R7" H 5000 2506 60  0000 C CNN
F 2 "multipackage:ADL5315ACPZ-R7" H 5000 2465 60  0001 C CNN
F 3 "" H 3800 2225 60  0000 C CNN
F 4 "http://Arrow.com" H 3800 2225 50  0001 C CNN "Source"
F 5 "ADL5315ACPZ-R7" H 3800 2225 50  0001 C CNN "Part_number"
	1    3800 2225
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R2
U 1 1 5CE335C5
P 3150 1900
F 0 "R2" V 3075 1875 50  0000 L CNN
F 1 "3.9 KΩ" V 3225 1675 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3150 1900 50  0001 C CNN
F 3 "~" H 3150 1900 50  0001 C CNN
F 4 "http://Arrow.com" H 3150 1900 50  0001 C CNN "Source"
F 5 "AC0603JR-073K9L" H 3150 1900 50  0001 C CNN "Part_number"
	1    3150 1900
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5CE3497C
P 3250 2125
F 0 "C1" H 3050 2125 50  0000 L CNN
F 1 "390 pF" H 2975 2050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0201_0603Metric" H 3250 2125 50  0001 C CNN
F 3 "~" H 3250 2125 50  0001 C CNN
F 4 "http://Arrow.com" H 3250 2125 50  0001 C CNN "Source"
F 5 "GRM0335C1E391JA01D" H 3250 2125 50  0001 C CNN "Part_number"
	1    3250 2125
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5CE92D72
P 3850 1650
F 0 "C2" V 4075 1600 50  0000 L CNN
F 1 ".22 µF" V 3975 1525 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3850 1650 50  0001 C CNN
F 3 "~" H 3850 1650 50  0001 C CNN
F 4 "0603YG224ZAT2A" H 3850 1650 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 3850 1650 50  0001 C CNN "Source"
	1    3850 1650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6400 2525 6400 2425
Wire Wire Line
	6400 2425 6200 2425
$Comp
L power:VCC #PWR011
U 1 1 5C182632
P 11100 2550
F 0 "#PWR011" H 11100 2400 50  0001 C CNN
F 1 "VCC" H 11050 2700 50  0000 C CNN
F 2 "" H 11100 2550 50  0001 C CNN
F 3 "" H 11100 2550 50  0001 C CNN
	1    11100 2550
	-1   0    0    1   
$EndComp
NoConn ~ 10200 2250
NoConn ~ 11450 2250
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U6
U 1 1 5C9A2EF5
P 9850 2150
F 0 "U6" H 10425 1150 60  0000 R CNN
F 1 "MCP4262-502E_UN" H 10275 1150 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 10395 2575 60  0001 C CNN
F 3 "" H 9860 2150 60  0000 C CNN
F 4 "01" H 5500 250 50  0001 C CNN "PlacementOrder"
F 5 "01" H 5500 250 50  0001 C CNN "SortForPlacement"
F 6 "03 Remove solder bridges on JP4 & 5.  Remove R1 to allow board to lie flat.  Place, then check work for inadvertent shorts and opens" H 5500 250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 9850 2150 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 9850 2150 50  0001 C CNN "Source"
	1    9850 2150
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U7
U 1 1 5CA59032
P 11100 2150
F 0 "U7" H 11575 1150 60  0000 R CNN
F 1 "MCP4262-104E_UN" H 11425 1150 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 11645 2575 60  0001 C CNN
F 3 "" H 11110 2150 60  0000 C CNN
F 4 "04 Place, then tack R1 back on.  Temporary tack solder J2 with pin 5 only, J3 with pin 1, and J4 with pin 4 only.  Check for inadvertent shorts and opens.  Power up and run U4-5 diags" H 5500 250 50  0001 C CNN "ClickToSortForPlacement"
F 5 "MCP4262-104E/UN" H 11100 2150 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 11100 2150 50  0001 C CNN "Source"
	1    11100 2150
	-1   0    0    1   
$EndComp
$Comp
L lm334m:LM334M U4
U 1 1 5CDCE965
P 7775 1525
F 0 "U4" H 7655 1571 50  0000 R CNN
F 1 "LM334M" H 8225 1650 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7800 1375 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 7775 1525 50  0001 C CIN
F 4 "LM334M/NOPB" H 7775 1525 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 7775 1525 50  0001 C CNN "Source"
F 6 "06 Then check work for inadvertent shorts and opens" H 7775 1525 50  0001 C CNN "ClickToSortForPlacement"
	1    7775 1525
	1    0    0    -1  
$EndComp
$Comp
L lm334m:LM334M U5
U 1 1 5CDCF5D4
P 8875 1525
F 0 "U5" H 8755 1571 50  0000 R CNN
F 1 "LM334M" H 9300 1650 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8900 1375 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 8875 1525 50  0001 C CIN
F 4 "LM334M/NOPB" H 8875 1525 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 8875 1525 50  0001 C CNN "Source"
F 6 "06 Then check work for inadvertent shorts and opens" H 8875 1525 50  0001 C CNN "ClickToSortForPlacement"
	1    8875 1525
	1    0    0    -1  
$EndComp
Connection ~ 7775 1325
$Comp
L power:VCC #PWR09
U 1 1 5C1825F8
P 9850 2550
F 0 "#PWR09" H 9850 2400 50  0001 C CNN
F 1 "VCC" H 9800 2700 50  0000 C CNN
F 2 "" H 9850 2550 50  0001 C CNN
F 3 "" H 9850 2550 50  0001 C CNN
	1    9850 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	10200 2000 10425 2000
Wire Wire Line
	10425 2000 10425 2975
Wire Wire Line
	10200 2150 10350 2150
Wire Wire Line
	10350 2150 10350 3100
Wire Wire Line
	10200 2350 10200 3225
Wire Wire Line
	11450 2150 11600 2150
Wire Wire Line
	11450 2000 11750 2000
Wire Wire Line
	10350 3100 11600 3100
Wire Wire Line
	10200 3225 11450 3225
Connection ~ 11450 3225
Wire Wire Line
	11450 3225 11950 3225
Wire Wire Line
	11450 2350 11450 3225
Connection ~ 11600 3100
Wire Wire Line
	11600 2150 11600 3100
Wire Wire Line
	11750 2000 11750 2875
Wire Wire Line
	8375 4175 8875 4175
Connection ~ 3800 3025
Wire Wire Line
	3800 2525 3800 3025
Wire Wire Line
	3800 2425 3750 2425
Wire Wire Line
	8875 1325 12700 1325
Wire Wire Line
	11950 3225 11950 5075
Wire Wire Line
	12050 3100 12050 4975
Wire Wire Line
	11600 3100 12050 3100
Wire Wire Line
	12150 2975 12150 4850
Wire Wire Line
	10425 2975 12150 2975
Wire Wire Line
	12250 2875 12250 4725
Wire Wire Line
	11750 2875 12250 2875
Connection ~ 8375 3975
Wire Wire Line
	8375 3875 8375 3975
Wire Wire Line
	12500 1725 11850 1725
Wire Wire Line
	11850 1725 11850 2350
Wire Wire Line
	12500 2350 11850 2350
Connection ~ 11850 2350
Wire Wire Line
	11850 2350 11850 3300
$Comp
L Device:R_US R9
U 1 1 5D44A427
P 13400 2000
F 0 "R9" H 13300 2050 50  0000 C CNN
F 1 "27 Ω" H 13550 2050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 13400 2000 50  0001 C CNN
F 3 "~" H 13400 2000 50  0001 C CNN
F 4 "02" H 10200 -2850 50  0001 C CNN "PlacementOrder"
F 5 "02" H 10200 -2850 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 10200 -2850 50  0001 C CNN "ClickToSortForPlacement"
F 7 "NRC-AS06J270TRF" H 13400 2000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 13400 2000 50  0001 C CNN "Source"
	1    13400 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	13100 1725 13400 1725
Wire Wire Line
	13400 1725 13400 1850
Wire Wire Line
	15025 1800 15025 1875
Wire Wire Line
	13400 2150 13400 2350
Wire Wire Line
	14500 2525 14500 2350
Wire Wire Line
	14500 2825 14500 3975
Wire Wire Line
	13100 3975 14500 3975
Wire Wire Line
	13400 2350 14500 2350
Wire Wire Line
	12700 2025 12775 2025
Wire Wire Line
	14225 2025 14225 3375
Wire Wire Line
	14225 3375 14800 3375
Wire Wire Line
	12775 1875 12775 2025
Connection ~ 15025 1875
Wire Wire Line
	15025 1875 15025 1950
Connection ~ 12775 2025
Wire Wire Line
	12775 2025 14225 2025
$Comp
L power:VCC #PWR08
U 1 1 5D58A5AC
P 8575 1325
F 0 "#PWR08" H 8575 1175 50  0001 C CNN
F 1 "VCC" V 8500 1500 50  0000 C CNN
F 2 "" H 8575 1325 50  0001 C CNN
F 3 "" H 8575 1325 50  0001 C CNN
	1    8575 1325
	1    0    0    -1  
$EndComp
Connection ~ 15150 3075
Wire Wire Line
	12775 1875 15025 1875
Wire Wire Line
	15350 1900 15350 2125
Connection ~ 15350 2125
Wire Wire Line
	14700 2725 14700 2825
Connection ~ 14700 2825
Wire Wire Line
	14700 2825 14500 2825
Wire Wire Line
	14800 2525 14700 2525
Wire Wire Line
	14700 2625 14700 2525
Connection ~ 14700 2525
Wire Wire Line
	14700 2525 14500 2525
Wire Wire Line
	20150 4325 20875 4325
Wire Wire Line
	20750 10025 22550 10025
Wire Wire Line
	20300 10100 22600 10100
Wire Wire Line
	22600 2300 22600 10100
Wire Wire Line
	14500 2350 14500 1500
Wire Wire Line
	14500 1500 19900 1500
Wire Wire Line
	19900 1500 19900 2200
Connection ~ 14500 2350
Wire Wire Line
	16475 2300 16475 3975
Wire Wire Line
	16475 3975 14500 3975
Connection ~ 14500 3975
Wire Wire Line
	11950 5075 19475 5075
Wire Wire Line
	12050 4975 19375 4975
Wire Wire Line
	22650 5450 22550 5450
Wire Wire Line
	22550 5450 22550 10025
Wire Wire Line
	22650 2200 22650 5450
Wire Wire Line
	16925 3650 16925 2725
Wire Wire Line
	15750 2725 16925 2725
Wire Wire Line
	22400 3650 22400 2700
Wire Wire Line
	17075 2625 17075 3775
Wire Wire Line
	17075 3775 22450 3775
Wire Wire Line
	15750 2625 17075 2625
Wire Wire Line
	22450 3775 22450 2600
Wire Wire Line
	22500 2500 22500 4850
Wire Wire Line
	12150 4850 22500 4850
Wire Wire Line
	22550 2400 22550 4725
Wire Wire Line
	12250 4725 22550 4725
Text Notes 19750 10275 0    50   ~ 0
NOTE:  Check sketch macros for which LED is controlled by which MCU pin.
Text Notes 22775 9975 1    50   ~ 0
NOTE:  Check sketch macros for which LED is controlled by which MCU pin.
Text Notes 22775 6875 1    50   ~ 0
NOTE:  Check sketch macros for which LED is controlled by which MCU pin.
Connection ~ 8375 4175
Connection ~ 8875 3975
Wire Wire Line
	8375 3975 8875 3975
$Comp
L Jumper:Jumper_2_Bridged JP2
U 1 1 5CE78051
P 9275 1800
F 0 "JP2" H 9275 1900 50  0000 C CNN
F 1 "Effect reducer" H 9175 1700 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9275 1800 50  0001 C CNN
F 3 "~" H 9275 1800 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0" H 9275 1800 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 9275 1800 50  0001 C CNN "Source"
	1    9275 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9725 1575 10525 1575
Wire Wire Line
	9725 1575 9725 1750
Wire Wire Line
	9725 1750 9500 1750
Wire Wire Line
	9500 1750 9500 1900
Wire Wire Line
	8875 1725 9025 1725
Wire Wire Line
	9025 1725 9025 2000
Connection ~ 8875 1725
Wire Wire Line
	11850 3300 8875 3300
Wire Wire Line
	8875 2425 8875 3300
Wire Wire Line
	8875 3975 12500 3975
$Comp
L Device:R_Small_US R3
U 1 1 5CED190D
P 3475 2225
F 0 "R3" V 3375 2175 50  0000 L CNN
F 1 "100 Ω" V 3300 2050 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3475 2225 50  0001 C CNN
F 3 "~" H 3475 2225 50  0001 C CNN
F 4 "http://Arrow.com" H 3475 2225 50  0001 C CNN "Source"
F 5 "RMCF0603FT100R" H 3475 2225 50  0001 C CNN "Part_number"
	1    3475 2225
	0    -1   -1   0   
$EndComp
Connection ~ 7775 3025
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5CF1E549
P 14800 3375
F 0 "#FLG01" H 14800 3450 50  0001 C CNN
F 1 "PWR_FLAG" H 15025 3425 50  0000 C CNN
F 2 "" H 14800 3375 50  0001 C CNN
F 3 "~" H 14800 3375 50  0001 C CNN
	1    14800 3375
	1    0    0    -1  
$EndComp
Text Notes 525  15750 0    500  ~ 100
NOTE: Except where indicated otherwise, \ncomponent part numbers and vendors are \nsuggested based on likely imperfect research\nof pricing and availability for the USA in the \nspring of 2019.
Wire Notes Line
	1850 2175 4100 2175
Wire Notes Line
	5900 2175 7775 2175
Wire Notes Line
	7775 2175 7775 2150
Wire Notes Line
	7725 2050 7725 2525
Wire Notes Line
	8100 2525 8100 2425
Wire Notes Line
	8075 2450 8875 2450
Wire Notes Line
	8875 2450 8875 2475
Wire Notes Line
	8900 2000 8900 3300
Wire Notes Line
	8875 3250 11850 3250
Wire Notes Line
	11850 3250 11850 3300
Wire Notes Line
	11850 3300 11900 3300
Wire Notes Line
	11900 3300 11900 1725
Wire Notes Line
	11850 1775 12600 1775
Wire Notes Line
	11850 2300 12600 2300
Text Notes 525  875  0    70   ~ 0
Blue dashes indicate traces \nthat ought to be guarded \nusing similar voltage guard trace.
Wire Wire Line
	6150 800  7475 800 
Wire Wire Line
	7475 800  7475 1325
$Comp
L Device:R_Small_US R4
U 1 1 5CFBF015
P 6150 1500
F 0 "R4" H 5875 1600 50  0000 L CNN
F 1 "10 KΩ" H 5800 1475 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6150 1500 50  0001 C CNN
F 3 "~" H 6150 1500 50  0001 C CNN
F 4 "http://Arrow.com" H 6150 1500 50  0001 C CNN "Source"
F 5 "NRC06J103TRF" H 6150 1500 50  0001 C CNN "Part_number"
	1    6150 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR04
U 1 1 5CFC03A8
P 6150 1600
F 0 "#PWR04" H 6150 1350 50  0001 C CNN
F 1 "GNDA" H 6155 1427 50  0000 C CNN
F 2 "" H 6150 1600 50  0001 C CNN
F 3 "" H 6150 1600 50  0001 C CNN
	1    6150 1600
	1    0    0    -1  
$EndComp
Text Notes 4400 1075 0    70   ~ 0
2nd stage guard trace source
Wire Wire Line
	7475 1925 7225 1925
Wire Wire Line
	7225 1925 7225 2425
Wire Wire Line
	7225 2425 6400 2425
Connection ~ 7475 1925
Connection ~ 6400 2425
Text Notes 6175 2150 0    60   ~ 0
2nd stage guard trace route
Text Notes 1800 2150 0    60   ~ 0
1st stage guard trace route
Text Notes 8650 3225 0    60   ~ 0
3rd stage guard trace route (A0)
$Comp
L Device:Q_NMOS_SGD Q3
U 1 1 5CED0C82
P 19025 9575
F 0 "Q3" H 18925 9425 50  0000 L CNN
F 1 "DMN601K-7" H 18725 9325 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 19225 9500 50  0001 L CIN
F 3 "http://www.redrok.com/MOSFET_BS108_200V_250mA_8O_Vth1.5_TO-92.PDF" H 19025 9575 50  0001 L CNN
F 4 "03" H 12475 6825 50  0001 C CNN "PlacementOrder"
F 5 "03" H 12475 6825 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 12475 6825 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 19025 9575 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 19025 9575 50  0001 C CNN "Source"
	1    19025 9575
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3025 7775 3025
$Comp
L Device:Q_NMOS_SGD Q4
U 1 1 5CEFAE8D
P 19825 9575
F 0 "Q4" H 19725 9425 50  0000 L CNN
F 1 "DMN601K-7" H 19525 9325 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 20025 9500 50  0001 L CIN
F 3 "http://www.redrok.com/MOSFET_BS108_200V_250mA_8O_Vth1.5_TO-92.PDF" H 19825 9575 50  0001 L CNN
F 4 "03" H 13275 6825 50  0001 C CNN "PlacementOrder"
F 5 "03" H 13275 6825 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 13275 6825 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 19825 9575 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 19825 9575 50  0001 C CNN "Source"
	1    19825 9575
	1    0    0    -1  
$EndComp
Wire Wire Line
	19925 9775 19125 9775
$Comp
L Device:Q_NMOS_SGD Q5
U 1 1 5CC49A39
P 20500 9575
F 0 "Q5" H 20400 9425 50  0000 L CNN
F 1 "DMN601K-7" H 20200 9325 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 20700 9500 50  0001 L CIN
F 3 "http://www.redrok.com/MOSFET_BS108_200V_250mA_8O_Vth1.5_TO-92.PDF" H 20500 9575 50  0001 L CNN
F 4 "03" H 13950 6825 50  0001 C CNN "PlacementOrder"
F 5 "03" H 13950 6825 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 13950 6825 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 20500 9575 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 20500 9575 50  0001 C CNN "Source"
	1    20500 9575
	1    0    0    -1  
$EndComp
Wire Wire Line
	20600 9775 19925 9775
Connection ~ 19925 9775
Wire Wire Line
	19625 9575 19625 9375
Wire Wire Line
	19625 9375 19125 9375
Wire Wire Line
	20600 9771 20600 9772
Connection ~ 20600 9772
Wire Wire Line
	20600 9772 20600 9775
Wire Wire Line
	20300 9575 20300 10100
Wire Wire Line
	20600 9372 20600 9375
Wire Wire Line
	19925 9375 20600 9375
Connection ~ 20600 9375
$Comp
L Device:R_US R10
U 1 1 5D039973
P 19625 9225
F 0 "R10" H 19525 9322 50  0000 C CNN
F 1 "1 MΩ" H 19775 9275 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 19665 9215 50  0001 C CNN
F 3 "~" H 19625 9225 50  0001 C CNN
F 4 "02" H 11975 6625 50  0001 C CNN "PlacementOrder"
F 5 "02" H 11975 6625 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 11975 6625 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RC0603FR-071ML " H 19625 9225 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 19625 9225 50  0001 C CNN "Source"
	1    19625 9225
	1    0    0    -1  
$EndComp
Connection ~ 19625 9375
Wire Wire Line
	20800 8775 19625 8775
Wire Wire Line
	19625 8775 19625 9075
Wire Wire Line
	20800 8772 20800 8775
Wire Wire Line
	10750 2350 10750 2800
Wire Wire Line
	9500 2800 10750 2800
Wire Wire Line
	10750 2250 10675 2250
Wire Wire Line
	10675 2250 10675 2875
Wire Wire Line
	10675 2875 9400 2875
Wire Wire Line
	9400 2350 9400 2875
$Comp
L AD8244_A:AD8244ARMZ U1
U 3 1 5F050747
P 3450 1650
F 0 "U1" H 3575 1500 50  0000 C CNN
F 1 "AD8244ARMZ" H 3500 1400 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 3450 1650 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 3450 1650 50  0001 C CNN
F 4 "AD8244ARMZ-R7" H 3450 1650 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 3450 1650 50  0001 C CNN "Source"
F 6 "00 00 !Assembly instructions  not complete - do not trust this yet for assembly order!  Place (always means solder herein), then check work for inadvertent shorts and opens" H 3450 1650 50  0001 C CNN "ClickToSortForPlacement"
	3    3450 1650
	-1   0    0    1   
$EndComp
Wire Wire Line
	3750 2325 3800 2325
Wire Wire Line
	3750 2325 3750 2425
Connection ~ 3750 2325
Text Notes 2675 1175 0    60   ~ 0
1st stage guard trace source
Wire Notes Line
	3650 1675 3775 1675
Wire Notes Line
	3775 1675 3775 2475
Wire Notes Line
	3775 2475 3800 2475
$Comp
L Device:RF_Shield_Two_Pieces SHLD1
U 1 1 5D39733F
P 1450 3350
F 0 "SHLD1" H 2180 3414 50  0000 L CNN
F 1 "Device_RF_Shield_Two_Pieces" H 2180 3323 50  0000 L CNN
F 2 "multipackage:Masach_Tech_MS26320_26x19.50mm" H 1450 3250 50  0001 C CNN
F 3 "~" H 1450 3250 50  0001 C CNN
F 4 "MS263-20 (just the cover)" H 1450 3350 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 1450 3350 50  0001 C CNN "Source"
	1    1450 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R1
U 1 1 5D398C0C
P 2150 2425
F 0 "R1" V 2075 2400 50  0000 L CNN
F 1 "100 Ω" V 2250 2300 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2150 2425 50  0001 C CNN
F 3 "~" H 2150 2425 50  0001 C CNN
F 4 "http://Arrow.com" H 2150 2425 50  0001 C CNN "Source"
F 5 "RMCF0603FT100R" H 2150 2425 50  0001 C CNN "Part_number"
	1    2150 2425
	0    1    1    0   
$EndComp
$Comp
L power:GNDD #PWR01
U 1 1 5D4815B2
P 1450 3750
F 0 "#PWR01" H 1450 3500 50  0001 C CNN
F 1 "GNDD" H 1454 3595 50  0000 C CNN
F 2 "" H 1450 3750 50  0001 C CNN
F 3 "" H 1450 3750 50  0001 C CNN
	1    1450 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR02
U 1 1 5D4F4A1E
P 1675 1775
F 0 "#PWR02" H 1675 1525 50  0001 C CNN
F 1 "GNDD" H 1679 1620 50  0000 C CNN
F 2 "" H 1675 1775 50  0001 C CNN
F 3 "" H 1675 1775 50  0001 C CNN
	1    1675 1775
	1    0    0    -1  
$EndComp
Wire Wire Line
	1675 1775 1500 1775
Wire Wire Line
	1500 1775 1500 1875
Wire Wire Line
	2050 2425 1850 2425
Wire Wire Line
	1850 2425 1850 2475
Wire Wire Line
	1850 2475 1700 2475
Wire Wire Line
	1700 2175 1850 2175
Wire Wire Line
	1850 2175 1850 2225
NoConn ~ 1700 2075
Wire Wire Line
	9025 2000 9275 2000
Connection ~ 9275 2000
Wire Wire Line
	9275 2000 9500 2000
Wire Wire Line
	9275 1600 9275 1575
Wire Wire Line
	9275 1575 9525 1575
Text Label 2000 1400 0    60   ~ 0
1st_stage_guard_trace
Wire Wire Line
	3150 1650 3150 1500
Wire Wire Line
	3150 1500 2000 1500
Wire Wire Line
	2000 1500 2000 1400
Wire Wire Line
	3575 2225 3800 2225
Wire Wire Line
	2325 3025 2325 2425
Wire Wire Line
	2250 2425 2325 2425
Wire Wire Line
	2325 3025 3800 3025
$Comp
L Jumper:SolderJumper_3_Open JP1
U 1 1 5D8B719E
P 2825 1750
F 0 "JP1" H 2650 1825 50  0000 C CNN
F 1 "C1_leak_mitigator" H 2400 1900 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" H 2825 1750 50  0001 C CNN
F 3 "~" H 2825 1750 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0" H 2825 1750 50  0001 C CNN "Part_number"
	1    2825 1750
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR03
U 1 1 5D8F459E
P 2625 1750
F 0 "#PWR03" H 2625 1500 50  0001 C CNN
F 1 "GNDA" H 2630 1577 50  0000 C CNN
F 2 "" H 2625 1750 50  0001 C CNN
F 3 "" H 2625 1750 50  0001 C CNN
	1    2625 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3025 1750 3025 1650
Wire Wire Line
	3025 1650 3150 1650
Connection ~ 3150 1650
Wire Wire Line
	3050 1900 2825 1900
Text Label 6325 1450 0    60   ~ 0
2nd_stage_guard_trace
$Comp
L Jumper:SolderJumper_3_Open JP3
U 1 1 5D936E95
P 4200 1300
F 0 "JP3" H 4275 1400 50  0000 C CNN
F 1 "C2_bias_reducer" H 3875 1400 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" H 4200 1300 50  0001 C CNN
F 3 "~" H 4200 1300 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0" H 4200 1300 50  0001 C CNN "Part_number"
	1    4200 1300
	-1   0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0101
U 1 1 5D99BDAB
P 4425 1300
F 0 "#PWR0101" H 4425 1050 50  0001 C CNN
F 1 "GNDA" H 4430 1127 50  0000 C CNN
F 2 "" H 4425 1300 50  0001 C CNN
F 3 "" H 4425 1300 50  0001 C CNN
	1    4425 1300
	1    0    0    -1  
$EndComp
Connection ~ 3750 1650
Wire Wire Line
	3750 1650 3750 2325
Wire Wire Line
	4400 1300 4425 1300
Wire Wire Line
	4000 1300 3150 1300
Wire Wire Line
	3150 1300 3150 1500
Connection ~ 3150 1500
Wire Wire Line
	4200 1450 4200 1650
Wire Wire Line
	4200 1650 3950 1650
Connection ~ 3250 2225
Wire Wire Line
	3250 2225 3375 2225
Wire Wire Line
	1850 2225 3250 2225
Wire Wire Line
	3250 2025 3250 1900
Wire Wire Line
	6150 1400 6200 1400
Wire Wire Line
	6200 1400 6200 1450
Wire Wire Line
	6200 1450 6325 1450
Connection ~ 6150 1400
NoConn ~ 6250 1400
Text Notes 725  7175 0    80   ~ 0
When used as designed (body \nsoldered to PCB and cover used \nremoveably) the height of this \nshield is 10mm and not hermetically \nsealed.\n\nInstead, hermetic sealing is \nsuggested to provide you with \nthe ultimate in long term \nsensitivity stability.\n\nHermetic sealing is achieved by: \n\n#1) Solder sealing all micro-vias of\nthe PCB under the shield, and\n\n#2) not using the shield body, only \ncarefully and thoroughly soldering \nthe shield top in place with the \ndried dessicant package (supplied \nby manufacturer with U1) stuffed \ninside to minimize moisture \nabsorption by U1 that could degrade\nU1 performance slightly over time in \nhumid environments.
Wire Notes Line
	7775 1775 8250 1775
Wire Notes Line
	7875 1500 8375 1500
Wire Notes Line
	8375 1500 8375 2225
Wire Notes Line
	8375 2225 9625 2225
Wire Notes Line
	9625 2225 9625 2175
Wire Notes Line
	8225 1775 8225 2325
Wire Notes Line
	8225 2325 9375 2325
Wire Notes Line
	9375 2325 9375 2900
Wire Notes Line
	9375 2900 10775 2900
Wire Notes Line
	10775 2900 10775 2400
Wire Notes Line
	10775 2400 10875 2400
Wire Notes Line
	10850 1875 10750 1875
Wire Notes Line
	10750 1875 10750 1500
Wire Notes Line
	10750 1500 9000 1500
Wire Notes Line
	8875 1775 9000 1775
Wire Notes Line
	9000 1775 9000 2050
Wire Notes Line
	9000 2050 9625 2050
Wire Notes Line
	9625 2050 9625 2025
Wire Notes Line
	10850 2225 10625 2225
Wire Notes Line
	10625 2225 10625 2775
Wire Notes Line
	10625 2775 9525 2775
Wire Notes Line
	9525 2775 9525 2375
Wire Notes Line
	9525 2375 9600 2375
Wire Notes Line
	9600 2375 9600 2400
Wire Notes Line
	10850 2025 10500 2025
Wire Notes Line
	10500 2025 10500 1600
Wire Notes Line
	10500 1600 9750 1600
Wire Notes Line
	9750 1800 9525 1800
Wire Notes Line
	9525 1800 9525 1850
Wire Notes Line
	9525 1850 9600 1850
Wire Notes Line
	9600 1850 9600 1875
Wire Notes Line
	9750 1600 9750 1800
Text Notes 9875 1475 0    60   ~ 0
1st stage guard trace route
Text Notes 9400 2975 0    60   ~ 0
1st stage guard trace route
Text Notes 12250 1175 0    70   ~ 0
3rd stage guard trace source
Text Label 13400 1775 0    60   ~ 0
3rd_stage_guard_trace
Wire Notes Line
	1600 2525 1900 2525
Wire Notes Line
	1900 2525 1900 2475
Wire Notes Line
	1900 2475 2050 2475
Text Notes 1075 2750 0    60   ~ 0
GNDA used for guard trace here
Wire Wire Line
	21525 3925 21525 4325
Wire Wire Line
	16925 3650 22400 3650
$Comp
L Device:R_POT_US VR3
U 1 1 5DC8E599
P 21025 5575
F 0 "VR3" H 20957 5529 50  0000 R CNN
F 1 "200 KΩ" H 20957 5620 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 21025 5575 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 21025 5575 50  0001 C CNN
F 4 "12 Don't solder, merely press against sides of holes inside them with power on and diags running.  When A0 diags are successful, power down, pull boards apart with great care, then remove J3 and attach it again with a tack solder to J3 pin 2. Power up and run A1 diags using VR2 position similarly (inserted without soldering).   When A1 diags are successful power down, then remove J2, 3, & 4, R1 and solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after" H 12065 -155 50  0001 C CNN "ClickToSortForPlacement"
F 5 "User/developer (\"hacker\") use only: PTV09A-4030U-B204 or may end in B203 or some resistance in between those.  The 4030 may be 4020 or 4015 for shorter shaft. If using the UNO SMD MCU version with an ATMEGA128P-AU (a TQFP package specifically instead of the UNO with a DIP ATMEGA128P), there are two analog input pins available at the TQFP package on the MCU board that not wired out to any connector.  One or both of these can be, if you are willing to attach tiny wires between them and VR3/4 and write the code, used as seventh and eighth analog inputs A6 & A7.  Then air-wire them or connectorize them somehow across to this extention board and buy the PCB mount vertically oriented version of PTV09 pots to get one or two more user developed, run-time analog input controls into the training board." H 21025 5575 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21025 5575 50  0001 C CNN "Source"
	1    21025 5575
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT_US VR4
U 1 1 5DC8FA72
P 21725 5475
F 0 "VR4" H 21657 5429 50  0000 R CNN
F 1 "200 KΩ" H 21657 5520 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 21725 5475 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 21725 5475 50  0001 C CNN
F 4 "12 Don't solder, merely press against sides of holes inside them with power on and diags running.  When A0 diags are successful, power down, pull boards apart with great care, then remove J3 and attach it again with a tack solder to J3 pin 2. Power up and run A1 diags using VR2 position similarly (inserted without soldering).   When A1 diags are successful power down, then remove J2, 3, & 4, R1 and solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after" H 12765 -255 50  0001 C CNN "ClickToSortForPlacement"
F 5 "User/developer (\"hacker\") use only: PTV09A-4030U-B204 or may end in B203 or some resistance in between those.  The 4030 may be 4020 or 4015 for shorter shaft. If using the UNO SMD MCU version with an ATMEGA128P-AU (a TQFP package specifically instead of the UNO with a DIP ATMEGA128P), there are two analog input pins available at the TQFP package on the MCU board that not wired out to any connector.  One or both of these can be, if you are willing to attach tiny wires between them and VR3/4 and write the code, used as seventh and eighth analog inputs A6 & A7.  Then air-wire them or connectorize them somehow across to this extention board and buy the PCB mount vertically oriented version of PTV09 pots to get one or two more user developed, run-time analog input controls into the training board." H 21725 5475 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21725 5475 50  0001 C CNN "Source"
	1    21725 5475
	-1   0    0    1   
$EndComp
$Comp
L power:GNDD #PWR032
U 1 1 5DC90CA3
P 21725 5625
F 0 "#PWR032" H 21725 5375 50  0001 C CNN
F 1 "GNDD" H 21729 5470 50  0000 C CNN
F 2 "" H 21725 5625 50  0001 C CNN
F 3 "" H 21725 5625 50  0001 C CNN
	1    21725 5625
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR030
U 1 1 5DC91543
P 21025 5725
F 0 "#PWR030" H 21025 5475 50  0001 C CNN
F 1 "GNDD" H 21029 5570 50  0000 C CNN
F 2 "" H 21025 5725 50  0001 C CNN
F 3 "" H 21025 5725 50  0001 C CNN
	1    21025 5725
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR031
U 1 1 5DC91A88
P 21725 5325
F 0 "#PWR031" H 21725 5175 50  0001 C CNN
F 1 "VCC" H 21742 5498 50  0000 C CNN
F 2 "" H 21725 5325 50  0001 C CNN
F 3 "" H 21725 5325 50  0001 C CNN
	1    21725 5325
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR029
U 1 1 5DC922E1
P 21025 5425
F 0 "#PWR029" H 21025 5275 50  0001 C CNN
F 1 "VCC" H 21042 5598 50  0000 C CNN
F 2 "" H 21025 5425 50  0001 C CNN
F 3 "" H 21025 5425 50  0001 C CNN
	1    21025 5425
	1    0    0    -1  
$EndComp
Text Notes 21425 6025 0    50   ~ 0
Developer-user 2
Text Notes 20650 6025 0    50   ~ 0
Developer-user 1
Text Notes 17875 6850 0    50   ~ 0
If using the UNO SMD MCU version with an ATMEGA128P-AU (a \nTQFP package specifically instead of the UNO with a DIP \nATMEGA128P), there are two analog input pins available at the \nTQFP package on the MCU board that are often not wired out to \nany connector.  Their TQFP pin numbers are 19 (A6) and 22 (A7).\n\nWhile you are building this project and before deciding on the \nlength of J2, look at your Arduino to see if A6 and A7 are wired \nto J2, both J2 and J3 joined into one single connector, and A6 \nand A7 labeled on pins 9 and 1 of J2.  If you got lucky just build \nthis board as is.  If your Arduino does not break out A6 and A7 \nlike that, decide whether you have a use for A6 &/or A7.  If so, \nyou will connect with PH-MVS-5370 pogo pins soldered atop \nslightly retracted J2 pins 9 and 1 (this board) and FFC bare pad \n(MCU board) instead of socket and pin.  \n\nFor the Arduino with the directly pinout supported see\nhttps://www.aliexpress.com\n/item\n/Real-tracking-number-100-new-chip-high-quality-UNO-R3-MEGA328P-CH340G-for-Arduino-Compatible-Improved\n/1933684816.html?spm=a2g0o.cart.0.0.7cd53c00hidtIP
Text Label 22250 1400 0    50   ~ 0
GNDD
Text Notes 22550 997  0    60   ~ 0
Holes
Text Label 22250 1100 0    60   ~ 0
A5(SCL)(2)
Text Label 22250 1200 0    60   ~ 0
A4(SDA)(2)
Text Label 22250 1300 0    60   ~ 0
AREF
Text Label 22250 1500 0    60   ~ 0
13(SCK)(2)
Text Label 22250 1600 0    60   ~ 0
12(MISO)(2)
Text Label 22250 1700 0    60   ~ 0
11(**/MOSI)
Text Label 22250 1800 0    60   ~ 0
10(**/SS)
Text Label 22250 1900 0    60   ~ 0
9(**)
Text Label 22250 2000 0    60   ~ 0
8
$Comp
L Connector:Conn_01x10_Male J4
U 1 1 5C8B326A
P 21700 1500
F 0 "J4" H 21800 2000 50  0000 C CNN
F 1 "Digital" V 21600 1450 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical" H 21700 1500 50  0001 C CNN
F 3 "~" H 21700 1500 50  0001 C CNN
F 4 "01 Temporary tack solder pin 4 only.  Height with all connectors mated.  Then check work for inadvertent shorts and opens" H 11650 0   50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0" H 21700 1500 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21700 1500 50  0001 C CNN "Source"
	1    21700 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	22250 1600 21900 1600
Wire Wire Line
	21900 1700 22250 1700
Wire Wire Line
	22250 1800 21900 1800
Wire Wire Line
	21900 1900 22250 1900
Wire Wire Line
	21900 1500 22250 1500
Wire Wire Line
	21900 1300 22250 1300
Wire Wire Line
	22250 1200 21900 1200
Wire Wire Line
	21900 1100 22250 1100
Wire Wire Line
	22250 2000 21900 2000
Wire Wire Line
	22650 1225 22650 1400
Wire Wire Line
	21900 1400 22650 1400
Wire Wire Line
	22650 1225 22825 1225
NoConn ~ 22250 1100
NoConn ~ 22250 1200
NoConn ~ 22250 1300
NoConn ~ 22250 1500
NoConn ~ 22250 1600
NoConn ~ 22250 1700
NoConn ~ 22250 1800
NoConn ~ 22250 1900
NoConn ~ 22250 2000
Wire Wire Line
	19375 3200 19375 4975
Wire Wire Line
	19375 3200 20650 3200
Wire Wire Line
	21425 3200 21150 3200
Wire Wire Line
	21425 3200 21425 3500
Text Label 20650 2600 0    60   ~ 0
A4(SDA)(1)
NoConn ~ 20650 2600
NoConn ~ 20650 2700
Wire Wire Line
	20650 2600 21150 2600
Wire Wire Line
	20650 2700 21150 2700
Wire Wire Line
	20175 2500 20175 3925
Wire Wire Line
	20175 3925 21525 3925
Wire Wire Line
	20175 2500 21150 2500
Wire Wire Line
	20150 2400 20150 4325
Wire Wire Line
	20150 2400 21150 2400
Wire Wire Line
	16475 2300 21150 2300
Wire Wire Line
	19900 2200 21150 2200
$Comp
L Device:R_Small_US R5
U 1 1 5CFA3142
P 6300 2525
F 0 "R5" V 6200 2500 50  0000 L CNN
F 1 "10 KΩ" V 6100 2350 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6300 2525 50  0001 C CNN
F 3 "~" H 6300 2525 50  0001 C CNN
F 4 "http://Arrow.com" H 6300 2525 50  0001 C CNN "Source"
F 5 "NRC06J103TRF" H 6300 2525 50  0001 C CNN "Part_number"
	1    6300 2525
	0    -1   -1   0   
$EndComp
Connection ~ 6200 2525
$Comp
L Device:R_Small_US R8
U 1 1 5CFCFAA5
P 9625 1575
F 0 "R8" V 9525 1525 50  0000 L CNN
F 1 "100 Ω" V 9450 1400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9625 1575 50  0001 C CNN
F 3 "~" H 9625 1575 50  0001 C CNN
F 4 "http://Arrow.com" H 9625 1575 50  0001 C CNN "Source"
F 5 "RMCF0603FT100R" H 9625 1575 50  0001 C CNN "Part_number"
	1    9625 1575
	0    1    1    0   
$EndComp
Connection ~ 9725 1575
$Comp
L Device:R_US R12
U 1 1 5CFE49AF
P 21450 9575
F 0 "R12" V 21550 9600 50  0000 C CNN
F 1 "1 MΩ" V 21350 9575 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 21490 9565 50  0001 C CNN
F 3 "~" H 21450 9575 50  0001 C CNN
F 4 "02" H 13800 6975 50  0001 C CNN "PlacementOrder"
F 5 "02" H 13800 6975 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 13800 6975 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RC0603FR-071ML " H 21450 9575 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 21450 9575 50  0001 C CNN "Source"
	1    21450 9575
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R13
U 1 1 5CFE72EE
P 21600 9425
F 0 "R13" H 21700 9325 50  0000 C CNN
F 1 "1 MΩ" H 21450 9325 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 21640 9415 50  0001 C CNN
F 3 "~" H 21600 9425 50  0001 C CNN
F 4 "02" H 13950 6825 50  0001 C CNN "PlacementOrder"
F 5 "02" H 13950 6825 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 13950 6825 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RC0603FR-071ML " H 21600 9425 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 21600 9425 50  0001 C CNN "Source"
	1    21600 9425
	-1   0    0    1   
$EndComp
Wire Wire Line
	21300 9575 21300 9772
Wire Wire Line
	21600 9072 21600 9275
Wire Wire Line
	21600 9575 21600 9572
Wire Wire Line
	21300 9772 21300 9775
$Comp
L Device:R_US R11
U 1 1 5D04A72D
P 20800 8925
F 0 "R11" H 20675 8922 50  0000 C CNN
F 1 "470 Ω" H 20975 8922 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 20840 8915 50  0001 C CNN
F 3 "~" H 20800 8925 50  0001 C CNN
F 4 "02" H 12850 6825 50  0001 C CNN "PlacementOrder"
F 5 "02" H 12850 6825 50  0001 C CNN "SortForPlacement"
F 6 "06 Then check work for inadvertent shorts and opens" H 12850 6825 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RK73B1JTTD471J" H 20800 8925 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 20800 8925 50  0001 C CNN "Source"
	1    20800 8925
	1    0    0    -1  
$EndComp
Wire Wire Line
	20600 9072 20800 9072
Connection ~ 20800 8775
Wire Wire Line
	20800 9072 20800 9075
Connection ~ 20800 9072
Wire Wire Line
	20800 9072 21000 9072
$Comp
L Device:C_Small C6
U 1 1 5D06E63A
P 15125 1950
F 0 "C6" V 15125 2150 50  0000 C CNN
F 1 "0.1 µF" V 15000 1950 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 15125 1950 50  0001 C CNN
F 3 "~" H 15125 1950 50  0001 C CNN
F 4 "08" H 9575 -1850 50  0001 C CNN "PlacementOrder"
F 5 "08" H 10325 -1900 50  0001 C CNN "SortForPlacement"
F 6 "10  Then check work for inadvertent shorts and opens" H 10325 -1900 50  0001 C CNN "ClickToSortForPlacement"
F 7 "CC0402KRX7R7BB104" H 15125 1950 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 15125 1950 50  0001 C CNN "Source"
	1    15125 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	21575 5475 21500 5475
Wire Wire Line
	21500 4975 20775 4975
Wire Wire Line
	20775 4975 20775 5150
Wire Wire Line
	20775 5350 20500 5350
Wire Wire Line
	21900 2800 22250 2800
Wire Wire Line
	22250 2900 21900 2900
Text Label 21050 1100 0    60   ~ 0
A6
Wire Wire Line
	21050 1100 21150 1100
Text Label 21025 1900 0    60   ~ 0
A7
Wire Wire Line
	21025 1900 21150 1900
Text Label 20500 5350 0    60   ~ 0
A7
Text Label 20500 5575 0    60   ~ 0
A6
Wire Wire Line
	21500 4975 21500 5475
Wire Wire Line
	21150 1200 20900 1200
Wire Wire Line
	20900 1200 20900 1150
Wire Wire Line
	21150 1300 20800 1300
Wire Wire Line
	20800 1300 20800 1200
Text Label 20675 1075 1    60   ~ 0
3.3v
Wire Wire Line
	21150 1400 20675 1400
Wire Wire Line
	20675 1400 20675 1075
Wire Wire Line
	21150 1500 20525 1500
Wire Wire Line
	20525 1500 20525 1125
Wire Wire Line
	20450 1075 20450 1125
Wire Wire Line
	20450 1125 20525 1125
Connection ~ 20525 1125
Wire Wire Line
	20400 1425 20400 1475
Wire Wire Line
	21150 1600 20575 1600
Wire Wire Line
	20575 1600 20575 1550
Wire Wire Line
	20575 1550 20475 1550
Wire Wire Line
	20475 1550 20475 1475
Wire Wire Line
	20475 1475 20400 1475
Connection ~ 20400 1475
Wire Wire Line
	20400 1475 20400 1500
Wire Wire Line
	21150 1700 21150 1600
Connection ~ 21150 1600
Text Label 20375 1775 2    60   ~ 0
Vin
Wire Wire Line
	21150 1800 20375 1800
Wire Wire Line
	20375 1800 20375 1775
NoConn ~ 20900 1150
NoConn ~ 20800 1200
NoConn ~ 20675 1075
NoConn ~ 20375 1775
Wire Wire Line
	18825 9575 6200 9575
Wire Wire Line
	6200 2525 6200 9575
Wire Wire Line
	21425 3500 19475 3500
Wire Wire Line
	19475 3500 19475 5075
Wire Wire Line
	20500 5575 20700 5575
$Comp
L Connector:Conn_01x02_Female J6_A6,A7
U 1 1 5D238E1B
P 20550 4950
F 0 "J6_A6,A7" V 20550 5350 50  0000 R CNN
F 1 "Conn_01x02_Female" V 20450 5825 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 20550 4950 50  0001 C CNN
F 3 "~" H 20550 4950 50  0001 C CNN
	1    20550 4950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	20650 5150 20775 5150
Connection ~ 20775 5150
Wire Wire Line
	20775 5150 20775 5350
Wire Wire Line
	20700 5575 20700 5225
Wire Wire Line
	20700 5225 20550 5225
Wire Wire Line
	20550 5225 20550 5150
Connection ~ 20700 5575
Wire Wire Line
	20700 5575 20875 5575
$EndSCHEMATC
