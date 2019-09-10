EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A2 23386 16535
encoding utf-8
Sheet 1 1
Title ""
Date "06-Sep-2019"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 19125 15772 0    47   ~ 0
GWAAMC Training Aid Main Board for UNO with MCP4262 HX711 LM334 REF200 MMBF5462 (2N5462)
Text Notes 18925 15522 0    58   ~ 0
 1 2
Text Notes 525  15750 0    200  ~ 40
NOTE: Except where indicated otherwise, \ncomponent part numbers and vendors are \nsuggested based on likely imperfect research\nof pricing and availability for the USA in the \nspring of 2019.
Wire Notes Line
	8075 13150 8075 15950
Wire Notes Line
	18650 15950 18650 13150
Text Notes 8000 13775 0    500  ~ 0
Helpful Parts Not In Circuit
Wire Notes Line
	9000 13900 17900 13900
Text Notes 8100 15875 0    100  ~ 0
1 roll Polyimide tape 3/8" wide 6' length or greater.  Use as electrical insulator and place assist. P/N 3057 from Arrow or equivalent\n\n38ga magnet wire for U8+ and for trace repairs.  P/N 3522 from Arrow or equivalent\nVery high temp solder (K100) not allowed on U3.\nThe best solder will always be "No Heat SAC305" if you can find it, but you still MUST cleanse gold from pads.\nAvoid Pb (leaded) solder unless you understand the behavior of eutectics, how Pb ruins other solders, and how gold from ENIG ruins it.\nSolder wick P/N TOL-09327 from Arrow or equivalent\nSoldering colophony (pine or gum ROSIN - NOT with zinc or ammonium chloride) flux (can make it yourself)\n\nMulti-conductor flat IDC ribbon cable or hookup wire.  P/N 2001 to 2006 from Arrow\n\nCarbon fiber tow, non-impregnated with a gold-plated connector per electrode (we have no source, yet)
Wire Notes Line
	8075 13150 18650 13150
Wire Notes Line
	8075 15950 18650 15950
Text Notes 19775 15900 0    39   ~ 0
                         (C) Copyright Kenneth L. Anderson 2018-2019             8
Text Label 7825 8850 0    50   ~ 0
8
Text Label 7825 9000 0    50   ~ 0
SCK(1)
NoConn ~ 7825 9100
Text Label 7825 9200 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR020
U 1 1 5D6E2568
P 7475 9400
F 0 "#PWR020" H 7475 9150 50  0001 C CNN
F 1 "GNDD" H 7479 9245 50  0000 C CNN
F 2 "" H 7475 9400 50  0001 C CNN
F 3 "" H 7475 9400 50  0001 C CNN
	1    7475 9400
	1    0    0    -1  
$EndComp
Text Label 7125 9200 2    50   ~ 0
U8-Pad8
Text Label 7125 9100 2    50   ~ 0
U8-Pad7
Text Label 7125 8850 2    50   ~ 0
U8-Pad5
Text Label 7125 8750 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR017
U 1 1 5D6E70E8
P 7475 8600
F 0 "#PWR017" H 7475 8450 50  0001 C CNN
F 1 "+5V" H 7490 8773 50  0000 C CNN
F 2 "" H 7475 8600 50  0001 C CNN
F 3 "" H 7475 8600 50  0001 C CNN
	1    7475 8600
	1    0    0    -1  
$EndComp
Text Label 9600 8900 0    50   ~ 0
8
Text Label 9600 9050 0    50   ~ 0
SCK(1)
NoConn ~ 9600 9150
Text Label 9600 9250 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR034
U 1 1 5D79DE0A
P 9250 9450
F 0 "#PWR034" H 9250 9200 50  0001 C CNN
F 1 "GNDD" H 9254 9295 50  0000 C CNN
F 2 "" H 9250 9450 50  0001 C CNN
F 3 "" H 9250 9450 50  0001 C CNN
	1    9250 9450
	1    0    0    -1  
$EndComp
Text Label 8900 9250 2    50   ~ 0
U8-Pad8
Text Label 8900 9150 2    50   ~ 0
U8-Pad7
Text Label 8900 8900 2    50   ~ 0
U8-Pad5
Text Label 8900 8800 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR025
U 1 1 5D79DE14
P 9250 8650
F 0 "#PWR025" H 9250 8500 50  0001 C CNN
F 1 "+5V" H 9265 8823 50  0000 C CNN
F 2 "" H 9250 8650 50  0001 C CNN
F 3 "" H 9250 8650 50  0001 C CNN
	1    9250 8650
	1    0    0    -1  
$EndComp
Text Label 11200 8875 0    50   ~ 0
8
Text Label 11200 9025 0    50   ~ 0
SCK(1)
NoConn ~ 11200 9125
Text Label 11200 9225 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR036
U 1 1 5D7B739A
P 10850 9425
F 0 "#PWR036" H 10850 9175 50  0001 C CNN
F 1 "GNDD" H 10854 9270 50  0000 C CNN
F 2 "" H 10850 9425 50  0001 C CNN
F 3 "" H 10850 9425 50  0001 C CNN
	1    10850 9425
	1    0    0    -1  
$EndComp
Text Label 10500 9225 2    50   ~ 0
U8-Pad8
Text Label 10500 9125 2    50   ~ 0
U8-Pad7
Text Label 10500 8875 2    50   ~ 0
U8-Pad5
Text Label 10500 8775 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR035
U 1 1 5D7B73A4
P 10850 8625
F 0 "#PWR035" H 10850 8475 50  0001 C CNN
F 1 "+5V" H 10865 8798 50  0000 C CNN
F 2 "" H 10850 8625 50  0001 C CNN
F 3 "" H 10850 8625 50  0001 C CNN
	1    10850 8625
	1    0    0    -1  
$EndComp
Text Label 12825 8900 0    50   ~ 0
8
Text Label 12825 9050 0    50   ~ 0
SCK(1)
NoConn ~ 12825 9150
Text Label 12825 9250 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR038
U 1 1 5D7D0E5E
P 12475 9450
F 0 "#PWR038" H 12475 9200 50  0001 C CNN
F 1 "GNDD" H 12479 9295 50  0000 C CNN
F 2 "" H 12475 9450 50  0001 C CNN
F 3 "" H 12475 9450 50  0001 C CNN
	1    12475 9450
	1    0    0    -1  
$EndComp
Text Label 12125 9250 2    50   ~ 0
U8-Pad8
Text Label 12125 9150 2    50   ~ 0
U8-Pad7
Text Label 12125 8900 2    50   ~ 0
U8-Pad5
Text Label 12125 8800 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR037
U 1 1 5D7D0E68
P 12475 8650
F 0 "#PWR037" H 12475 8500 50  0001 C CNN
F 1 "+5V" H 12490 8823 50  0000 C CNN
F 2 "" H 12475 8650 50  0001 C CNN
F 3 "" H 12475 8650 50  0001 C CNN
	1    12475 8650
	1    0    0    -1  
$EndComp
Text Label 14575 8925 0    50   ~ 0
8
Text Label 14575 9075 0    50   ~ 0
SCK(1)
NoConn ~ 14575 9175
Text Label 14575 9275 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR040
U 1 1 5D7E9C90
P 14225 9475
F 0 "#PWR040" H 14225 9225 50  0001 C CNN
F 1 "GNDD" H 14229 9320 50  0000 C CNN
F 2 "" H 14225 9475 50  0001 C CNN
F 3 "" H 14225 9475 50  0001 C CNN
	1    14225 9475
	1    0    0    -1  
$EndComp
Text Label 13875 9275 2    50   ~ 0
U8-Pad8
Text Label 13875 9175 2    50   ~ 0
U8-Pad7
Text Label 13875 8925 2    50   ~ 0
U8-Pad5
Text Label 13875 8825 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR039
U 1 1 5D7E9C9A
P 14225 8675
F 0 "#PWR039" H 14225 8525 50  0001 C CNN
F 1 "+5V" H 14240 8848 50  0000 C CNN
F 2 "" H 14225 8675 50  0001 C CNN
F 3 "" H 14225 8675 50  0001 C CNN
	1    14225 8675
	1    0    0    -1  
$EndComp
Text Label 16100 8925 0    50   ~ 0
8
Text Label 16100 9075 0    50   ~ 0
SCK(1)
NoConn ~ 16100 9175
Text Label 16100 9275 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR042
U 1 1 5D8038AD
P 15750 9475
F 0 "#PWR042" H 15750 9225 50  0001 C CNN
F 1 "GNDD" H 15754 9320 50  0000 C CNN
F 2 "" H 15750 9475 50  0001 C CNN
F 3 "" H 15750 9475 50  0001 C CNN
	1    15750 9475
	1    0    0    -1  
$EndComp
Text Label 15400 9275 2    50   ~ 0
U8-Pad8
Text Label 15400 9175 2    50   ~ 0
U8-Pad7
Text Label 15400 8925 2    50   ~ 0
U8-Pad5
Text Label 15400 8825 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR041
U 1 1 5D8038B7
P 15750 8675
F 0 "#PWR041" H 15750 8525 50  0001 C CNN
F 1 "+5V" H 15765 8848 50  0000 C CNN
F 2 "" H 15750 8675 50  0001 C CNN
F 3 "" H 15750 8675 50  0001 C CNN
	1    15750 8675
	1    0    0    -1  
$EndComp
Text Label 7775 7175 0    50   ~ 0
8
Text Label 7775 7325 0    50   ~ 0
SCK(1)
NoConn ~ 7775 7425
Text Label 7775 7525 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0103
U 1 1 5D88DECC
P 7425 7725
F 0 "#PWR0103" H 7425 7475 50  0001 C CNN
F 1 "GNDD" H 7429 7570 50  0000 C CNN
F 2 "" H 7425 7725 50  0001 C CNN
F 3 "" H 7425 7725 50  0001 C CNN
	1    7425 7725
	1    0    0    -1  
$EndComp
Text Label 7075 7525 2    50   ~ 0
U8-Pad8
Text Label 7075 7425 2    50   ~ 0
U8-Pad7
Text Label 7075 7175 2    50   ~ 0
U8-Pad5
Text Label 7075 7075 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0104
U 1 1 5D88DED6
P 7425 6925
F 0 "#PWR0104" H 7425 6775 50  0001 C CNN
F 1 "+5V" H 7440 7098 50  0000 C CNN
F 2 "" H 7425 6925 50  0001 C CNN
F 3 "" H 7425 6925 50  0001 C CNN
	1    7425 6925
	1    0    0    -1  
$EndComp
Text Label 9550 7225 0    50   ~ 0
8
Text Label 9550 7375 0    50   ~ 0
SCK(1)
NoConn ~ 9550 7475
Text Label 9550 7575 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0105
U 1 1 5D88DEEB
P 9200 7775
F 0 "#PWR0105" H 9200 7525 50  0001 C CNN
F 1 "GNDD" H 9204 7620 50  0000 C CNN
F 2 "" H 9200 7775 50  0001 C CNN
F 3 "" H 9200 7775 50  0001 C CNN
	1    9200 7775
	1    0    0    -1  
$EndComp
Text Label 8850 7575 2    50   ~ 0
U8-Pad8
Text Label 8850 7475 2    50   ~ 0
U8-Pad7
Text Label 8850 7225 2    50   ~ 0
U8-Pad5
Text Label 8850 7125 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0106
U 1 1 5D88DEF5
P 9200 6975
F 0 "#PWR0106" H 9200 6825 50  0001 C CNN
F 1 "+5V" H 9215 7148 50  0000 C CNN
F 2 "" H 9200 6975 50  0001 C CNN
F 3 "" H 9200 6975 50  0001 C CNN
	1    9200 6975
	1    0    0    -1  
$EndComp
Text Label 11150 7200 0    50   ~ 0
8
Text Label 11150 7350 0    50   ~ 0
SCK(1)
NoConn ~ 11150 7450
Text Label 11150 7550 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0107
U 1 1 5D88DF0A
P 10800 7750
F 0 "#PWR0107" H 10800 7500 50  0001 C CNN
F 1 "GNDD" H 10804 7595 50  0000 C CNN
F 2 "" H 10800 7750 50  0001 C CNN
F 3 "" H 10800 7750 50  0001 C CNN
	1    10800 7750
	1    0    0    -1  
$EndComp
Text Label 10450 7550 2    50   ~ 0
U8-Pad8
Text Label 10450 7450 2    50   ~ 0
U8-Pad7
Text Label 10450 7200 2    50   ~ 0
U8-Pad5
Text Label 10450 7100 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0108
U 1 1 5D88DF14
P 10800 6950
F 0 "#PWR0108" H 10800 6800 50  0001 C CNN
F 1 "+5V" H 10815 7123 50  0000 C CNN
F 2 "" H 10800 6950 50  0001 C CNN
F 3 "" H 10800 6950 50  0001 C CNN
	1    10800 6950
	1    0    0    -1  
$EndComp
Text Label 12775 7225 0    50   ~ 0
8
Text Label 12775 7375 0    50   ~ 0
SCK(1)
NoConn ~ 12775 7475
Text Label 12775 7575 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0109
U 1 1 5D88DF29
P 12425 7775
F 0 "#PWR0109" H 12425 7525 50  0001 C CNN
F 1 "GNDD" H 12429 7620 50  0000 C CNN
F 2 "" H 12425 7775 50  0001 C CNN
F 3 "" H 12425 7775 50  0001 C CNN
	1    12425 7775
	1    0    0    -1  
$EndComp
Text Label 12075 7575 2    50   ~ 0
U8-Pad8
Text Label 12075 7475 2    50   ~ 0
U8-Pad7
Text Label 12075 7225 2    50   ~ 0
U8-Pad5
Text Label 12075 7125 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0110
U 1 1 5D88DF33
P 12425 6975
F 0 "#PWR0110" H 12425 6825 50  0001 C CNN
F 1 "+5V" H 12440 7148 50  0000 C CNN
F 2 "" H 12425 6975 50  0001 C CNN
F 3 "" H 12425 6975 50  0001 C CNN
	1    12425 6975
	1    0    0    -1  
$EndComp
Text Label 14525 7250 0    50   ~ 0
8
Text Label 14525 7400 0    50   ~ 0
SCK(1)
NoConn ~ 14525 7500
Text Label 14525 7600 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0111
U 1 1 5D88DF48
P 14175 7800
F 0 "#PWR0111" H 14175 7550 50  0001 C CNN
F 1 "GNDD" H 14179 7645 50  0000 C CNN
F 2 "" H 14175 7800 50  0001 C CNN
F 3 "" H 14175 7800 50  0001 C CNN
	1    14175 7800
	1    0    0    -1  
$EndComp
Text Label 13825 7600 2    50   ~ 0
U8-Pad8
Text Label 13825 7500 2    50   ~ 0
U8-Pad7
Text Label 13825 7250 2    50   ~ 0
U8-Pad5
Text Label 13825 7150 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0112
U 1 1 5D88DF52
P 14175 7000
F 0 "#PWR0112" H 14175 6850 50  0001 C CNN
F 1 "+5V" H 14190 7173 50  0000 C CNN
F 2 "" H 14175 7000 50  0001 C CNN
F 3 "" H 14175 7000 50  0001 C CNN
	1    14175 7000
	1    0    0    -1  
$EndComp
Text Label 16050 7250 0    50   ~ 0
8
Text Label 16050 7400 0    50   ~ 0
SCK(1)
NoConn ~ 16050 7500
Text Label 16050 7600 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0113
U 1 1 5D88DF67
P 15700 7800
F 0 "#PWR0113" H 15700 7550 50  0001 C CNN
F 1 "GNDD" H 15704 7645 50  0000 C CNN
F 2 "" H 15700 7800 50  0001 C CNN
F 3 "" H 15700 7800 50  0001 C CNN
	1    15700 7800
	1    0    0    -1  
$EndComp
Text Label 15350 7600 2    50   ~ 0
U8-Pad8
Text Label 15350 7500 2    50   ~ 0
U8-Pad7
Text Label 15350 7250 2    50   ~ 0
U8-Pad5
Text Label 15350 7150 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0114
U 1 1 5D88DF71
P 15700 7000
F 0 "#PWR0114" H 15700 6850 50  0001 C CNN
F 1 "+5V" H 15715 7173 50  0000 C CNN
F 2 "" H 15700 7000 50  0001 C CNN
F 3 "" H 15700 7000 50  0001 C CNN
	1    15700 7000
	1    0    0    -1  
$EndComp
Text Label 7750 5350 0    50   ~ 0
8
Text Label 7750 5500 0    50   ~ 0
SCK(1)
NoConn ~ 7750 5600
Text Label 7750 5700 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0115
U 1 1 5D8ACEFB
P 7400 5900
F 0 "#PWR0115" H 7400 5650 50  0001 C CNN
F 1 "GNDD" H 7404 5745 50  0000 C CNN
F 2 "" H 7400 5900 50  0001 C CNN
F 3 "" H 7400 5900 50  0001 C CNN
	1    7400 5900
	1    0    0    -1  
$EndComp
Text Label 7050 5700 2    50   ~ 0
U8-Pad8
Text Label 7050 5600 2    50   ~ 0
U8-Pad7
$Comp
L power:+5V #PWR0116
U 1 1 5D8ACF05
P 7400 5100
F 0 "#PWR0116" H 7400 4950 50  0001 C CNN
F 1 "+5V" H 7415 5273 50  0000 C CNN
F 2 "" H 7400 5100 50  0001 C CNN
F 3 "" H 7400 5100 50  0001 C CNN
	1    7400 5100
	1    0    0    -1  
$EndComp
Text Label 9525 5400 0    50   ~ 0
8
Text Label 9525 5550 0    50   ~ 0
SCK(1)
NoConn ~ 9525 5650
Text Label 9525 5750 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0117
U 1 1 5D8ACF1A
P 9175 5950
F 0 "#PWR0117" H 9175 5700 50  0001 C CNN
F 1 "GNDD" H 9179 5795 50  0000 C CNN
F 2 "" H 9175 5950 50  0001 C CNN
F 3 "" H 9175 5950 50  0001 C CNN
	1    9175 5950
	1    0    0    -1  
$EndComp
Text Label 8825 5750 2    50   ~ 0
U8-Pad8
Text Label 8825 5650 2    50   ~ 0
U8-Pad7
$Comp
L power:+5V #PWR0118
U 1 1 5D8ACF24
P 9175 5150
F 0 "#PWR0118" H 9175 5000 50  0001 C CNN
F 1 "+5V" H 9190 5323 50  0000 C CNN
F 2 "" H 9175 5150 50  0001 C CNN
F 3 "" H 9175 5150 50  0001 C CNN
	1    9175 5150
	1    0    0    -1  
$EndComp
Text Label 11125 5375 0    50   ~ 0
8
Text Label 11125 5525 0    50   ~ 0
SCK(1)
NoConn ~ 11125 5625
Text Label 11125 5725 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0119
U 1 1 5D8ACF39
P 10775 5925
F 0 "#PWR0119" H 10775 5675 50  0001 C CNN
F 1 "GNDD" H 10779 5770 50  0000 C CNN
F 2 "" H 10775 5925 50  0001 C CNN
F 3 "" H 10775 5925 50  0001 C CNN
	1    10775 5925
	1    0    0    -1  
$EndComp
Text Label 10425 5725 2    50   ~ 0
U8-Pad8
Text Label 10425 5625 2    50   ~ 0
U8-Pad7
Text Label 10425 5375 2    50   ~ 0
U8-Pad5
Text Label 10425 5275 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0120
U 1 1 5D8ACF43
P 10775 5125
F 0 "#PWR0120" H 10775 4975 50  0001 C CNN
F 1 "+5V" H 10790 5298 50  0000 C CNN
F 2 "" H 10775 5125 50  0001 C CNN
F 3 "" H 10775 5125 50  0001 C CNN
	1    10775 5125
	1    0    0    -1  
$EndComp
Text Label 12750 5400 0    50   ~ 0
8
Text Label 12750 5550 0    50   ~ 0
SCK(1)
NoConn ~ 12750 5650
Text Label 12750 5750 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0121
U 1 1 5D8ACF58
P 12400 5950
F 0 "#PWR0121" H 12400 5700 50  0001 C CNN
F 1 "GNDD" H 12404 5795 50  0000 C CNN
F 2 "" H 12400 5950 50  0001 C CNN
F 3 "" H 12400 5950 50  0001 C CNN
	1    12400 5950
	1    0    0    -1  
$EndComp
Text Label 12050 5750 2    50   ~ 0
U8-Pad8
Text Label 12050 5650 2    50   ~ 0
U8-Pad7
Text Label 12050 5400 2    50   ~ 0
U8-Pad5
Text Label 12050 5300 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0122
U 1 1 5D8ACF62
P 12400 5150
F 0 "#PWR0122" H 12400 5000 50  0001 C CNN
F 1 "+5V" H 12415 5323 50  0000 C CNN
F 2 "" H 12400 5150 50  0001 C CNN
F 3 "" H 12400 5150 50  0001 C CNN
	1    12400 5150
	1    0    0    -1  
$EndComp
Text Label 14500 5425 0    50   ~ 0
8
Text Label 14500 5575 0    50   ~ 0
SCK(1)
NoConn ~ 14500 5675
Text Label 14500 5775 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0123
U 1 1 5D8ACF77
P 14150 5975
F 0 "#PWR0123" H 14150 5725 50  0001 C CNN
F 1 "GNDD" H 14154 5820 50  0000 C CNN
F 2 "" H 14150 5975 50  0001 C CNN
F 3 "" H 14150 5975 50  0001 C CNN
	1    14150 5975
	1    0    0    -1  
$EndComp
Text Label 13800 5775 2    50   ~ 0
U8-Pad8
Text Label 13800 5675 2    50   ~ 0
U8-Pad7
Text Label 13800 5425 2    50   ~ 0
U8-Pad5
Text Label 13800 5325 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0124
U 1 1 5D8ACF81
P 14150 5175
F 0 "#PWR0124" H 14150 5025 50  0001 C CNN
F 1 "+5V" H 14165 5348 50  0000 C CNN
F 2 "" H 14150 5175 50  0001 C CNN
F 3 "" H 14150 5175 50  0001 C CNN
	1    14150 5175
	1    0    0    -1  
$EndComp
Text Label 16025 5425 0    50   ~ 0
8
Text Label 16025 5575 0    50   ~ 0
SCK(1)
NoConn ~ 16025 5675
Text Label 16025 5775 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0125
U 1 1 5D8ACF96
P 15675 5975
F 0 "#PWR0125" H 15675 5725 50  0001 C CNN
F 1 "GNDD" H 15679 5820 50  0000 C CNN
F 2 "" H 15675 5975 50  0001 C CNN
F 3 "" H 15675 5975 50  0001 C CNN
	1    15675 5975
	1    0    0    -1  
$EndComp
Text Label 15325 5775 2    50   ~ 0
U8-Pad8
Text Label 15325 5675 2    50   ~ 0
U8-Pad7
Text Label 15325 5425 2    50   ~ 0
U8-Pad5
Text Label 15325 5325 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0126
U 1 1 5D8ACFA0
P 15675 5175
F 0 "#PWR0126" H 15675 5025 50  0001 C CNN
F 1 "+5V" H 15690 5348 50  0000 C CNN
F 2 "" H 15675 5175 50  0001 C CNN
F 3 "" H 15675 5175 50  0001 C CNN
	1    15675 5175
	1    0    0    -1  
$EndComp
Text Label 7725 3525 0    50   ~ 0
8
Text Label 7725 3675 0    50   ~ 0
SCK(1)
NoConn ~ 7725 3775
Text Label 7725 3875 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0127
U 1 1 5D8CCFA8
P 7375 4075
F 0 "#PWR0127" H 7375 3825 50  0001 C CNN
F 1 "GNDD" H 7379 3920 50  0000 C CNN
F 2 "" H 7375 4075 50  0001 C CNN
F 3 "" H 7375 4075 50  0001 C CNN
	1    7375 4075
	1    0    0    -1  
$EndComp
Text Label 7025 3875 2    50   ~ 0
U8-Pad8
Text Label 7025 3775 2    50   ~ 0
U8-Pad7
$Comp
L power:+5V #PWR0128
U 1 1 5D8CCFB2
P 7375 3275
F 0 "#PWR0128" H 7375 3125 50  0001 C CNN
F 1 "+5V" H 7390 3448 50  0000 C CNN
F 2 "" H 7375 3275 50  0001 C CNN
F 3 "" H 7375 3275 50  0001 C CNN
	1    7375 3275
	1    0    0    -1  
$EndComp
Text Label 9500 3575 0    50   ~ 0
8
Text Label 9500 3725 0    50   ~ 0
SCK(1)
NoConn ~ 9500 3825
Text Label 9500 3925 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0129
U 1 1 5D8CCFC7
P 9150 4125
F 0 "#PWR0129" H 9150 3875 50  0001 C CNN
F 1 "GNDD" H 9154 3970 50  0000 C CNN
F 2 "" H 9150 4125 50  0001 C CNN
F 3 "" H 9150 4125 50  0001 C CNN
	1    9150 4125
	1    0    0    -1  
$EndComp
Text Label 8800 3925 2    50   ~ 0
U8-Pad8
Text Label 8800 3825 2    50   ~ 0
U8-Pad7
Text Label 8800 3575 2    50   ~ 0
U8-Pad5
Text Label 8800 3475 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0130
U 1 1 5D8CCFD1
P 9150 3325
F 0 "#PWR0130" H 9150 3175 50  0001 C CNN
F 1 "+5V" H 9165 3498 50  0000 C CNN
F 2 "" H 9150 3325 50  0001 C CNN
F 3 "" H 9150 3325 50  0001 C CNN
	1    9150 3325
	1    0    0    -1  
$EndComp
Text Label 11100 3550 0    50   ~ 0
8
Text Label 11100 3700 0    50   ~ 0
SCK(1)
NoConn ~ 11100 3800
Text Label 11100 3900 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0131
U 1 1 5D8CCFE6
P 10750 4100
F 0 "#PWR0131" H 10750 3850 50  0001 C CNN
F 1 "GNDD" H 10754 3945 50  0000 C CNN
F 2 "" H 10750 4100 50  0001 C CNN
F 3 "" H 10750 4100 50  0001 C CNN
	1    10750 4100
	1    0    0    -1  
$EndComp
Text Label 10400 3900 2    50   ~ 0
U8-Pad8
Text Label 10400 3800 2    50   ~ 0
U8-Pad7
Text Label 10400 3550 2    50   ~ 0
U8-Pad5
Text Label 10400 3450 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0132
U 1 1 5D8CCFF0
P 10750 3300
F 0 "#PWR0132" H 10750 3150 50  0001 C CNN
F 1 "+5V" H 10765 3473 50  0000 C CNN
F 2 "" H 10750 3300 50  0001 C CNN
F 3 "" H 10750 3300 50  0001 C CNN
	1    10750 3300
	1    0    0    -1  
$EndComp
Text Label 12725 3575 0    50   ~ 0
8
Text Label 12725 3725 0    50   ~ 0
SCK(1)
NoConn ~ 12725 3825
Text Label 12725 3925 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0133
U 1 1 5D8CD005
P 12375 4125
F 0 "#PWR0133" H 12375 3875 50  0001 C CNN
F 1 "GNDD" H 12379 3970 50  0000 C CNN
F 2 "" H 12375 4125 50  0001 C CNN
F 3 "" H 12375 4125 50  0001 C CNN
	1    12375 4125
	1    0    0    -1  
$EndComp
Text Label 12025 3925 2    50   ~ 0
U8-Pad8
Text Label 12025 3825 2    50   ~ 0
U8-Pad7
Text Label 12025 3575 2    50   ~ 0
U8-Pad5
Text Label 12025 3475 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0134
U 1 1 5D8CD00F
P 12375 3325
F 0 "#PWR0134" H 12375 3175 50  0001 C CNN
F 1 "+5V" H 12390 3498 50  0000 C CNN
F 2 "" H 12375 3325 50  0001 C CNN
F 3 "" H 12375 3325 50  0001 C CNN
	1    12375 3325
	1    0    0    -1  
$EndComp
Text Label 14475 3600 0    50   ~ 0
8
Text Label 14475 3750 0    50   ~ 0
SCK(1)
NoConn ~ 14475 3850
Text Label 14475 3950 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0135
U 1 1 5D8CD024
P 14125 4150
F 0 "#PWR0135" H 14125 3900 50  0001 C CNN
F 1 "GNDD" H 14129 3995 50  0000 C CNN
F 2 "" H 14125 4150 50  0001 C CNN
F 3 "" H 14125 4150 50  0001 C CNN
	1    14125 4150
	1    0    0    -1  
$EndComp
Text Label 13775 3950 2    50   ~ 0
U8-Pad8
Text Label 13775 3850 2    50   ~ 0
U8-Pad7
Text Label 13775 3600 2    50   ~ 0
U8-Pad5
Text Label 13775 3500 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0136
U 1 1 5D8CD02E
P 14125 3350
F 0 "#PWR0136" H 14125 3200 50  0001 C CNN
F 1 "+5V" H 14140 3523 50  0000 C CNN
F 2 "" H 14125 3350 50  0001 C CNN
F 3 "" H 14125 3350 50  0001 C CNN
	1    14125 3350
	1    0    0    -1  
$EndComp
Text Label 16000 3600 0    50   ~ 0
8
Text Label 16000 3750 0    50   ~ 0
SCK(1)
NoConn ~ 16000 3850
Text Label 16000 3950 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0137
U 1 1 5D8CD043
P 15650 4150
F 0 "#PWR0137" H 15650 3900 50  0001 C CNN
F 1 "GNDD" H 15654 3995 50  0000 C CNN
F 2 "" H 15650 4150 50  0001 C CNN
F 3 "" H 15650 4150 50  0001 C CNN
	1    15650 4150
	1    0    0    -1  
$EndComp
Text Label 15300 3950 2    50   ~ 0
U8-Pad8
Text Label 15300 3850 2    50   ~ 0
U8-Pad7
Text Label 15300 3600 2    50   ~ 0
U8-Pad5
Text Label 15300 3500 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0138
U 1 1 5D8CD04D
P 15650 3350
F 0 "#PWR0138" H 15650 3200 50  0001 C CNN
F 1 "+5V" H 15665 3523 50  0000 C CNN
F 2 "" H 15650 3350 50  0001 C CNN
F 3 "" H 15650 3350 50  0001 C CNN
	1    15650 3350
	1    0    0    -1  
$EndComp
Text Label 17850 8950 0    50   ~ 0
8
Text Label 17850 9100 0    50   ~ 0
SCK(1)
NoConn ~ 17850 9200
Text Label 17850 9300 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0139
U 1 1 5D8EC9AE
P 17500 9500
F 0 "#PWR0139" H 17500 9250 50  0001 C CNN
F 1 "GNDD" H 17504 9345 50  0000 C CNN
F 2 "" H 17500 9500 50  0001 C CNN
F 3 "" H 17500 9500 50  0001 C CNN
	1    17500 9500
	1    0    0    -1  
$EndComp
Text Label 17150 9300 2    50   ~ 0
U8-Pad8
Text Label 17150 9200 2    50   ~ 0
U8-Pad7
Text Label 17150 8950 2    50   ~ 0
U8-Pad5
Text Label 17150 8850 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0140
U 1 1 5D8EC9B8
P 17500 8700
F 0 "#PWR0140" H 17500 8550 50  0001 C CNN
F 1 "+5V" H 17515 8873 50  0000 C CNN
F 2 "" H 17500 8700 50  0001 C CNN
F 3 "" H 17500 8700 50  0001 C CNN
	1    17500 8700
	1    0    0    -1  
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U12
U 1 1 5D6AAC30
P 7475 9000
F 0 "U12" H 7350 8625 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 7400 8525 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 8020 9425 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 7485 9000 60  0001 C CNN
F 4 "01" H 3125 7100 50  0001 C CNN "PlacementOrder"
F 5 "01" H 3125 7100 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 3125 7100 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 7475 9000 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 7475 9000 50  0001 C CNN "Source"
	1    7475 9000
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U16
U 1 1 5D79DE00
P 9250 9050
F 0 "U16" H 9125 8675 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 9175 8575 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 9795 9475 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 9260 9050 60  0001 C CNN
F 4 "01" H 4900 7150 50  0001 C CNN "PlacementOrder"
F 5 "01" H 4900 7150 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 4900 7150 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 9250 9050 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 9250 9050 50  0001 C CNN "Source"
	1    9250 9050
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U20
U 1 1 5D7B7390
P 10850 9025
F 0 "U20" H 10725 8650 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 10775 8550 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 11395 9450 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 10860 9025 60  0001 C CNN
F 4 "01" H 6500 7125 50  0001 C CNN "PlacementOrder"
F 5 "01" H 6500 7125 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 6500 7125 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 10850 9025 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 10850 9025 50  0001 C CNN "Source"
	1    10850 9025
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U24
U 1 1 5D7D0E54
P 12475 9050
F 0 "U24" H 12350 8675 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 12400 8575 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 13020 9475 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 12485 9050 60  0001 C CNN
F 4 "01" H 8125 7150 50  0001 C CNN "PlacementOrder"
F 5 "01" H 8125 7150 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 8125 7150 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 12475 9050 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 12475 9050 50  0001 C CNN "Source"
	1    12475 9050
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U28
U 1 1 5D7E9C86
P 14225 9075
F 0 "U28" H 14100 8700 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 14150 8600 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 14770 9500 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 14235 9075 60  0001 C CNN
F 4 "01" H 9875 7175 50  0001 C CNN "PlacementOrder"
F 5 "01" H 9875 7175 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 9875 7175 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 14225 9075 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 14225 9075 50  0001 C CNN "Source"
	1    14225 9075
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U32
U 1 1 5D8038A3
P 15750 9075
F 0 "U32" H 15625 8700 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 15675 8600 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 16295 9500 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 15760 9075 60  0001 C CNN
F 4 "01" H 11400 7175 50  0001 C CNN "PlacementOrder"
F 5 "01" H 11400 7175 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 11400 7175 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 15750 9075 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 15750 9075 50  0001 C CNN "Source"
	1    15750 9075
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U11
U 1 1 5D88DEC2
P 7425 7325
F 0 "U11" H 7300 6950 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 7350 6850 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 7970 7750 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 7435 7325 60  0001 C CNN
F 4 "01" H 3075 5425 50  0001 C CNN "PlacementOrder"
F 5 "01" H 3075 5425 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 3075 5425 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 7425 7325 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 7425 7325 50  0001 C CNN "Source"
	1    7425 7325
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U15
U 1 1 5D88DEE1
P 9200 7375
F 0 "U15" H 9075 7000 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 9125 6900 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 9745 7800 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 9210 7375 60  0001 C CNN
F 4 "01" H 4850 5475 50  0001 C CNN "PlacementOrder"
F 5 "01" H 4850 5475 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 4850 5475 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 9200 7375 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 9200 7375 50  0001 C CNN "Source"
	1    9200 7375
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U19
U 1 1 5D88DF00
P 10800 7350
F 0 "U19" H 10675 6975 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 10725 6875 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 11345 7775 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 10810 7350 60  0001 C CNN
F 4 "01" H 6450 5450 50  0001 C CNN "PlacementOrder"
F 5 "01" H 6450 5450 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 6450 5450 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 10800 7350 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 10800 7350 50  0001 C CNN "Source"
	1    10800 7350
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U23
U 1 1 5D88DF1F
P 12425 7375
F 0 "U23" H 12300 7000 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 12350 6900 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 12970 7800 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 12435 7375 60  0001 C CNN
F 4 "01" H 8075 5475 50  0001 C CNN "PlacementOrder"
F 5 "01" H 8075 5475 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 8075 5475 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 12425 7375 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 12425 7375 50  0001 C CNN "Source"
	1    12425 7375
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U27
U 1 1 5D88DF3E
P 14175 7400
F 0 "U27" H 14050 7025 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 14100 6925 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 14720 7825 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 14185 7400 60  0001 C CNN
F 4 "01" H 9825 5500 50  0001 C CNN "PlacementOrder"
F 5 "01" H 9825 5500 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 9825 5500 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 14175 7400 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 14175 7400 50  0001 C CNN "Source"
	1    14175 7400
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U31
U 1 1 5D88DF5D
P 15700 7400
F 0 "U31" H 15575 7025 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 15625 6925 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 16245 7825 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 15710 7400 60  0001 C CNN
F 4 "01" H 11350 5500 50  0001 C CNN "PlacementOrder"
F 5 "01" H 11350 5500 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 11350 5500 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 15700 7400 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 15700 7400 50  0001 C CNN "Source"
	1    15700 7400
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U10
U 1 1 5D8ACEF1
P 7400 5500
F 0 "U10" H 7275 5125 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 7325 5025 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 7945 5925 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 7410 5500 60  0001 C CNN
F 4 "01" H 3050 3600 50  0001 C CNN "PlacementOrder"
F 5 "01" H 3050 3600 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 3050 3600 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 7400 5500 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 7400 5500 50  0001 C CNN "Source"
	1    7400 5500
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U14
U 1 1 5D8ACF10
P 9175 5550
F 0 "U14" H 9050 5175 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 9100 5075 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 9720 5975 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 9185 5550 60  0001 C CNN
F 4 "01" H 4825 3650 50  0001 C CNN "PlacementOrder"
F 5 "01" H 4825 3650 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 4825 3650 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 9175 5550 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 9175 5550 50  0001 C CNN "Source"
	1    9175 5550
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U18
U 1 1 5D8ACF2F
P 10775 5525
F 0 "U18" H 10650 5150 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 10700 5050 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 11320 5950 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 10785 5525 60  0001 C CNN
F 4 "01" H 6425 3625 50  0001 C CNN "PlacementOrder"
F 5 "01" H 6425 3625 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 6425 3625 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 10775 5525 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 10775 5525 50  0001 C CNN "Source"
	1    10775 5525
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U22
U 1 1 5D8ACF4E
P 12400 5550
F 0 "U22" H 12275 5175 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 12325 5075 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 12945 5975 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 12410 5550 60  0001 C CNN
F 4 "01" H 8050 3650 50  0001 C CNN "PlacementOrder"
F 5 "01" H 8050 3650 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 8050 3650 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 12400 5550 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 12400 5550 50  0001 C CNN "Source"
	1    12400 5550
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U26
U 1 1 5D8ACF6D
P 14150 5575
F 0 "U26" H 14025 5200 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 14075 5100 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 14695 6000 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 14160 5575 60  0001 C CNN
F 4 "01" H 9800 3675 50  0001 C CNN "PlacementOrder"
F 5 "01" H 9800 3675 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 9800 3675 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 14150 5575 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 14150 5575 50  0001 C CNN "Source"
	1    14150 5575
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U30
U 1 1 5D8ACF8C
P 15675 5575
F 0 "U30" H 15550 5200 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 15600 5100 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 16220 6000 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 15685 5575 60  0001 C CNN
F 4 "01" H 11325 3675 50  0001 C CNN "PlacementOrder"
F 5 "01" H 11325 3675 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 11325 3675 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 15675 5575 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 15675 5575 50  0001 C CNN "Source"
	1    15675 5575
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U9
U 1 1 5D8CCF9E
P 7375 3675
F 0 "U9" H 7250 3300 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 7300 3200 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 7920 4100 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 7385 3675 60  0001 C CNN
F 4 "01" H 3025 1775 50  0001 C CNN "PlacementOrder"
F 5 "01" H 3025 1775 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 3025 1775 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 7375 3675 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 7375 3675 50  0001 C CNN "Source"
	1    7375 3675
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U13
U 1 1 5D8CCFBD
P 9150 3725
F 0 "U13" H 9025 3350 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 9075 3250 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 9695 4150 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 9160 3725 60  0001 C CNN
F 4 "01" H 4800 1825 50  0001 C CNN "PlacementOrder"
F 5 "01" H 4800 1825 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 4800 1825 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 9150 3725 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 9150 3725 50  0001 C CNN "Source"
	1    9150 3725
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U17
U 1 1 5D8CCFDC
P 10750 3700
F 0 "U17" H 10625 3325 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 10675 3225 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 11295 4125 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 10760 3700 60  0001 C CNN
F 4 "01" H 6400 1800 50  0001 C CNN "PlacementOrder"
F 5 "01" H 6400 1800 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 6400 1800 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 10750 3700 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 10750 3700 50  0001 C CNN "Source"
	1    10750 3700
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U21
U 1 1 5D8CCFFB
P 12375 3725
F 0 "U21" H 12250 3350 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 12300 3250 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 12920 4150 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 12385 3725 60  0001 C CNN
F 4 "01" H 8025 1825 50  0001 C CNN "PlacementOrder"
F 5 "01" H 8025 1825 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 8025 1825 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 12375 3725 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 12375 3725 50  0001 C CNN "Source"
	1    12375 3725
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U25
U 1 1 5D8CD01A
P 14125 3750
F 0 "U25" H 14000 3375 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 14050 3275 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 14670 4175 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 14135 3750 60  0001 C CNN
F 4 "01" H 9775 1850 50  0001 C CNN "PlacementOrder"
F 5 "01" H 9775 1850 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 9775 1850 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 14125 3750 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 14125 3750 50  0001 C CNN "Source"
	1    14125 3750
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U29
U 1 1 5D8CD039
P 15650 3750
F 0 "U29" H 15525 3375 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 15575 3275 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 16195 4175 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 15660 3750 60  0001 C CNN
F 4 "01" H 11300 1850 50  0001 C CNN "PlacementOrder"
F 5 "01" H 11300 1850 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 11300 1850 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 15650 3750 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 15650 3750 50  0001 C CNN "Source"
	1    15650 3750
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U33
U 1 1 5D8EC9A4
P 17500 9100
F 0 "U33" H 17375 8725 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 17425 8625 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 18045 9525 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 17510 9100 60  0001 C CNN
F 4 "01" H 13150 7200 50  0001 C CNN "PlacementOrder"
F 5 "01" H 13150 7200 50  0001 C CNN "SortForPlacement"
F 6 "15 NOT WELL ACCOMMODATED ON BOARD REV 7 AND BELOW: PATCHING IN WOULD REQUIRE PARALLELING ALL PINS EXCEPT 9 WITH 32 GA WIRES OR SMALLER.  With Rev 8 flex board, check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place, then check work for inadvertent shorts and opens" H 13150 7200 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 17500 9100 50  0001 C CNN "Part_number"
F 8 "http://www.digikey.com" H 17500 9100 50  0001 C CNN "Source"
	1    17500 9100
	-1   0    0    1   
$EndComp
Text Label 8825 5300 2    50   ~ 0
U8-Pad6
Text Label 8825 5400 2    50   ~ 0
U8-Pad5
Text Label 7050 5350 2    50   ~ 0
U8-Pad5
Text Label 7050 5250 2    50   ~ 0
U8-Pad6
Text Label 7025 3425 2    50   ~ 0
U8-Pad6
Text Label 7025 3525 2    50   ~ 0
U8-Pad5
$EndSCHEMATC
