EESchema Schematic File Version 4
LIBS:uno shield v1.0 project SMD with aux board-cache
EELAYER 30 0
EELAYER END
$Descr A2 23386 16535
encoding utf-8
Sheet 1 2
Title ""
Date "10-Oct-2019"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GNDA #PWR014
U 1 1 5C19D658
P 14800 5750
F 0 "#PWR014" H 14800 5500 50  0001 C CNN
F 1 "GNDA" H 14805 5577 50  0000 C CNN
F 2 "" H 14800 5750 50  0001 C CNN
F 3 "" H 14800 5750 50  0001 C CNN
	1    14800 5750
	1    0    0    -1  
$EndComp
Text Notes 19125 15772 0    47   ~ 0
GWAAMC Training Aid Main Board for UNO with MCP4262 HX711 LM334 REF200 MMBF5462 (2N5462)
Text Notes 18925 15522 0    58   ~ 0
 1 2
$Comp
L power:GNDD #PWR016
U 1 1 5C5C35A0
P 15575 5800
F 0 "#PWR016" H 15575 5550 50  0001 C CNN
F 1 "GNDD" H 15575 5650 50  0000 C CNN
F 2 "" H 15575 5800 50  0001 C CNN
F 3 "" H 15575 5800 50  0001 C CNN
	1    15575 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR021
U 1 1 5C7E6F1E
P 13000 12200
F 0 "#PWR021" H 13000 11950 50  0001 C CNN
F 1 "GNDD" H 13004 12045 50  0000 C CNN
F 2 "" H 13000 12200 50  0001 C CNN
F 3 "" H 13000 12200 50  0001 C CNN
	1    13000 12200
	1    0    0    -1  
$EndComp
Text Label 20650 2200 0    60   ~ 0
A0
Text Label 20650 2300 0    60   ~ 0
A1
Text Label 20650 2400 0    60   ~ 0
A2
Text Label 20650 2500 0    60   ~ 0
A3
Text Label 22249 2700 0    60   ~ 0
2
Text Label 22250 2600 0    60   ~ 0
3(**)
Text Label 22200 2000 0    60   ~ 0
8
Text Label 22250 2400 0    60   ~ 0
5(**)
Text Label 22250 2300 0    60   ~ 0
6(**)
Text Label 22249 2200 0    60   ~ 0
7
Text Notes 20225 850  0    60   ~ 0
See "Options" box also.\nArduino "Uno" board Rev 3. P2 shown\naccommodates the advanced style with A6 and \nA7.  Ordinarily P2 is numbered 1 to 8.
NoConn ~ 22500 847 
NoConn ~ 22600 847 
NoConn ~ 22700 847 
NoConn ~ 22800 847 
Wire Notes Line
	22925 997  22425 997 
Text Label 21075 4250 0    50   ~ 0
MOSI(1)
Text Label 21075 4350 0    50   ~ 0
GND(4)
Text Label 20575 4250 2    50   ~ 0
SCK(1)
NoConn ~ 20575 4150
NoConn ~ 20575 4350
$Comp
L power:GNDD #PWR027
U 1 1 5CB66292
P 21075 4350
F 0 "#PWR027" H 21075 4100 50  0001 C CNN
F 1 "GNDD" H 21079 4195 50  0000 C CNN
F 2 "" H 21075 4350 50  0001 C CNN
F 3 "" H 21075 4350 50  0001 C CNN
	1    21075 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR033
U 1 1 5CB9E79B
P 22825 1225
F 0 "#PWR033" H 22825 975 50  0001 C CNN
F 1 "GNDD" H 22775 1075 50  0000 C CNN
F 2 "" H 22825 1225 50  0001 C CNN
F 3 "" H 22825 1225 50  0001 C CNN
	1    22825 1225
	1    0    0    -1  
$EndComp
Wire Notes Line
	20250 3822 21600 3822
Text Notes 20050 9097 0    50   ~ 0
Magnification \namplitude
Text Notes 21610 9082 0    50   ~ 0
Gain\nadjust\n3 settings
$Comp
L power:GNDD #PWR029
U 1 1 5C90D427
P 21450 9425
F 0 "#PWR029" H 21450 9175 50  0001 C CNN
F 1 "GNDD" H 21454 9270 50  0000 C CNN
F 2 "" H 21450 9425 50  0001 C CNN
F 3 "" H 21450 9425 50  0001 C CNN
	1    21450 9425
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR023
U 1 1 5DD017AA
P 20800 9425
F 0 "#PWR023" H 20800 9175 50  0001 C CNN
F 1 "GNDD" H 20804 9270 50  0000 C CNN
F 2 "" H 20800 9425 50  0001 C CNN
F 3 "" H 20800 9425 50  0001 C CNN
	1    20800 9425
	1    0    0    -1  
$EndComp
Text Notes 500  4850 0    100  Italic 20
!
Text Notes 475  5025 0    50   Italic 10
    NOT \n    FOR \nVOLTAGE
Wire Wire Line
	22450 2600 21900 2600
Wire Wire Line
	22400 2700 21900 2700
Wire Wire Line
	21900 2300 22500 2300
Wire Wire Line
	21900 2200 22550 2200
Text Notes 10850 9175 0    60   ~ 0
NOTE - These resistors are valued for 5V operation to \nset the reference input of the HX711 for highest gain.\nFuture research is yet to be done for 3.3V operation \nof the HX711 to determine if this value will need to \nbe changed.  It is not expected to be different, based \nsimply on the reasoning that this reference voltage is \nabout half of 3.3V already.\n\nNOTE - These resistors are spec'd tightly to mitigate \ntemperature drift.  If a different tempco is found to \nbe required for ADC1 balance, changing the tempcos \nof these resistors would be the solution.
NoConn ~ 7875 6450
NoConn ~ 14500 7025
$Comp
L power:GNDA #PWR06
U 1 1 5D6610C1
P 7775 6450
F 0 "#PWR06" H 7775 6200 50  0001 C CNN
F 1 "GNDA" H 7625 6375 50  0000 C CNN
F 2 "" H 7775 6450 50  0001 C CNN
F 3 "" H 7775 6450 50  0001 C CNN
	1    7775 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 4775 9500 5225
Wire Wire Line
	10750 4000 10750 4425
$Comp
L power:GNDD #PWR013
U 1 1 5D5FF76B
P 11300 4975
F 0 "#PWR013" H 11300 4725 50  0001 C CNN
F 1 "GNDD" H 11304 4820 50  0000 C CNN
F 2 "" H 11300 4975 50  0001 C CNN
F 3 "" H 11300 4975 50  0001 C CNN
	1    11300 4975
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR08
U 1 1 5D5FE8B7
P 14550 7300
F 0 "#PWR08" H 14550 7050 50  0001 C CNN
F 1 "GNDA" H 14555 7127 50  0000 C CNN
F 2 "" H 14550 7300 50  0001 C CNN
F 3 "" H 14550 7300 50  0001 C CNN
	1    14550 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7475 4350 7475 3750
Wire Wire Line
	7475 3750 7775 3750
Wire Wire Line
	8575 3750 8875 3750
Wire Wire Line
	10950 4325 10975 4325
Wire Wire Line
	10950 3950 10950 4325
Wire Wire Line
	9075 3950 10950 3950
Wire Wire Line
	10750 4425 10975 4425
Wire Wire Line
	8575 4350 8575 3750
Wire Wire Line
	6400 4950 6400 4850
NoConn ~ 10200 4675
Wire Wire Line
	10200 4425 10350 4425
Wire Wire Line
	10200 4575 10250 4575
Wire Wire Line
	22500 2300 22500 5500
Wire Wire Line
	22550 2200 22550 5050
Text Notes 10850 12700 0    50   ~ 0
NOTE:  Check sketch macros for which LED is controlled by which MCU pin.
Text Notes 22775 9975 1    50   ~ 0
NOTE:  Check sketch macros for which LED is controlled by which MCU pin.
Text Notes 22775 6875 1    50   ~ 0
NOTE:  Check sketch macros for which LED is controlled by which MCU pin.
Text Notes 525  15750 0    200  ~ 40
NOTE: Except where indicated otherwise, \ncomponent part numbers and vendors are \nsuggested based on likely imperfect research\nof pricing and availability for the USA in the \nspring of 2019.
Wire Notes Line
	5900 4625 7775 4625
Text Notes 550  3525 0    60   ~ 0
Blue dashes indicate traces that ought to be guarded using similar \nvoltage guard ring.  Remove solder mask from the guard rings to \nguard against surface leakage due to contamination. In addition to \nthe guard rings on the primary side, route a guard ring around any \nvias in the input net on the other side of the board as well.
$Comp
L power:GNDA #PWR05
U 1 1 5CFC03A8
P 6150 4125
F 0 "#PWR05" H 6150 3875 50  0001 C CNN
F 1 "GNDA" H 6155 3952 50  0000 C CNN
F 2 "" H 6150 4125 50  0001 C CNN
F 3 "" H 6150 4125 50  0001 C CNN
	1    6150 4125
	1    0    0    -1  
$EndComp
Text Notes 6175 3050 0    70   ~ 0
2nd stage guard ring source
Text Notes 5950 4550 0    60   ~ 0
2nd stage guard ring route
Text Notes 2175 4600 0    40   ~ 0
1st stage guard trace ring route
Text Notes 10350 6000 0    60   ~ 0
3rd stage guard ring route
Wire Wire Line
	10975 4775 10975 5225
Wire Wire Line
	10975 4675 10900 4675
Wire Wire Line
	10900 4675 10900 5300
Wire Wire Line
	10900 5300 9400 5300
Wire Wire Line
	9400 4775 9400 5300
$Comp
L power:GNDD #PWR01
U 1 1 5D4F4A1E
P 1450 4325
F 0 "#PWR01" H 1450 4075 50  0001 C CNN
F 1 "GNDD" H 1454 4170 50  0000 C CNN
F 2 "" H 1450 4325 50  0001 C CNN
F 3 "" H 1450 4325 50  0001 C CNN
	1    1450 4325
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 4325 1275 4325
Wire Wire Line
	1275 4325 1275 4425
NoConn ~ 1475 4625
Text Label 3050 3625 2    60   ~ 0
1st_stage_guard_ring
Wire Wire Line
	3150 4075 3150 3925
Wire Wire Line
	3575 4650 3800 4650
$Comp
L power:GNDA #PWR02
U 1 1 5D8F459E
P 2625 4175
F 0 "#PWR02" H 2625 3925 50  0001 C CNN
F 1 "GNDA" H 2630 4002 50  0000 C CNN
F 2 "" H 2625 4175 50  0001 C CNN
F 3 "" H 2625 4175 50  0001 C CNN
	1    2625 4175
	1    0    0    -1  
$EndComp
Wire Wire Line
	3025 4175 3025 4075
Wire Wire Line
	3025 4075 3150 4075
Text Label 6150 3925 2    60   ~ 0
2nd_stage_ring
$Comp
L power:GNDA #PWR04
U 1 1 5D99BDAB
P 4425 3725
F 0 "#PWR04" H 4425 3475 50  0001 C CNN
F 1 "GNDA" H 4430 3552 50  0000 C CNN
F 2 "" H 4425 3725 50  0001 C CNN
F 3 "" H 4425 3725 50  0001 C CNN
	1    4425 3725
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3725 4425 3725
Wire Wire Line
	4000 3725 3150 3725
Wire Wire Line
	3150 3725 3150 3925
Connection ~ 3150 3925
Wire Wire Line
	4200 3875 4200 4075
Wire Wire Line
	4200 4075 3900 4075
Wire Wire Line
	3250 4450 3250 4325
Text Notes 2250 11100 0    60   ~ 0
When used as designed (body \nsoldered to PCB and cover used \nremoveably) the height of this \nshield is 10mm and not hermetically \nsealed.\n\nInstead, hermetic sealing is \nsuggested to provide you with \nthe ultimate in long term \nsensitivity stability in scientific\ninstrumentation class useages,\nwhich will also benefit from J1\nbeing a triax connector instead\nof the phone connector shown.\n\nFlex ckt'ing the guarded signal path \nunder the shielding (not yet designed) \ninstead of ringing it would be \nadditional improvement if such ckt is \n100% prevented from flexing \nduring operation.\n\nHermetic sealing is achieved by: \n\n#1) Solder sealing all micro-vias of\nthe PCB under the shield, and\n\n#2) not using the shield body, only \ncarefully and thoroughly soldering \nthe shield top in place with the \ndried dessicant package (supplied \nby manufacturer with U4) stuffed \ninside to minimize moisture \nabsorption by U4 that could degrade\nU4 performance slightly over time in \nhumid environments.
Wire Notes Line
	9425 4750 9425 5325
Wire Notes Line
	11000 5325 11000 4825
Wire Notes Line
	10875 4650 10875 5200
Wire Notes Line
	9525 5200 9525 4800
Wire Notes Line
	9525 4800 9600 4800
Wire Notes Line
	9600 4800 9600 4825
Wire Notes Line
	10725 4450 10725 4025
Wire Notes Line
	9525 4275 9600 4275
Wire Notes Line
	9600 4275 9600 4300
Text Notes 9075 3900 0    60   ~ 0
1st stage guard ring route
Text Notes 9725 5600 0    50   ~ 0
1st stage guard ring route.  Can guard the \n4 dPot traces \nby a single 1st stage guard ring
Text Notes 12200 6700 0    50   ~ 0
3rd stage guard ring source
Text Label 13000 6175 0    60   ~ 0
3rd_stage_guard_ring
Text Notes 1525 5325 0    60   ~ 0
Near-GNDA used \nfor guard ring of \nJ5-PadR
$Comp
L power:GNDD #PWR031
U 1 1 5DC90CA3
P 18600 9575
F 0 "#PWR031" H 18600 9325 50  0001 C CNN
F 1 "GNDD" H 18604 9420 50  0000 C CNN
F 2 "" H 18600 9575 50  0001 C CNN
F 3 "" H 18600 9575 50  0001 C CNN
	1    18600 9575
	1    0    0    -1  
$EndComp
Text Notes 18100 9850 0    50   ~ 0
Alternative developer-user 2
Text Notes 17325 10050 0    50   ~ 0
Alterntive developer-user 1
Text Label 22250 1400 0    50   ~ 0
GNDD
Text Notes 22650 975  0    60   ~ 0
Holes
Wire Wire Line
	22650 1225 22650 1400
Wire Wire Line
	21900 1400 22650 1400
Wire Wire Line
	22650 1225 22825 1225
NoConn ~ 21900 1100
NoConn ~ 21900 1200
NoConn ~ 21900 1300
NoConn ~ 21900 1500
NoConn ~ 21900 1600
NoConn ~ 21900 1700
NoConn ~ 21900 1800
Wire Wire Line
	21425 4250 21425 4550
NoConn ~ 21150 2600
NoConn ~ 21150 2700
Wire Wire Line
	11900 11497 11900 11500
Wire Wire Line
	17450 8775 17450 8950
Wire Wire Line
	17450 9150 17175 9150
Text Label 17175 9150 0    60   ~ 0
A7
Text Label 17175 9375 0    60   ~ 0
A6
Wire Wire Line
	21150 1700 21150 1600
NoConn ~ 21150 1300
NoConn ~ 21150 1800
Wire Wire Line
	17175 9375 17375 9375
Wire Wire Line
	17325 8950 17450 8950
Connection ~ 17450 8950
Wire Wire Line
	17450 8950 17450 9150
Wire Wire Line
	17375 9025 17225 9025
Wire Wire Line
	17225 9025 17225 8950
Connection ~ 17375 9375
Wire Wire Line
	17375 9375 17550 9375
Connection ~ 17225 9025
Wire Wire Line
	17325 8975 17325 8950
Text Notes 575  4250 0    60   ~ 0
With triax cabling employed, \nGNDA would join to cable's guard \nconductor and GNDD to shield.
Wire Wire Line
	6200 4650 7775 4650
Wire Wire Line
	6200 4850 6400 4850
Wire Wire Line
	6200 4750 6275 4750
Wire Wire Line
	3800 4950 3800 5000
Wire Wire Line
	6150 3925 6275 3925
Text Notes 20750 2650 0    47   ~ 0
A4 SDA(1)
Text Notes 20750 2750 0    47   ~ 0
A5 SCL(1)
Text Notes 20275 4150 0    47   ~ 0
MISO(1)
Text Notes 21950 1100 0    47   ~ 0
A5(SCL)(2)
Text Notes 21950 1200 0    47   ~ 0
A4(SDA)(2)
Text Notes 21950 1300 0    47   ~ 0
AREF
Text Notes 21950 1500 0    47   ~ 0
13(SCK)(2)
Text Notes 21950 1600 0    47   ~ 0
12(MISO)(2)
Connection ~ 3250 4650
Wire Wire Line
	3250 4650 3375 4650
Connection ~ 6150 3925
Wire Wire Line
	14150 2925 14150 2875
Wire Wire Line
	14325 2875 14150 2875
Wire Wire Line
	15325 4175 15350 4175
Text Notes 21950 1700 0    47   ~ 0
11(**/MOSI)
Text Notes 21950 1825 0    47   ~ 0
10(**/SS)
Wire Wire Line
	11900 11197 11900 11200
Wire Wire Line
	13000 11200 11900 11200
Connection ~ 11900 11200
Wire Wire Line
	11900 11200 11900 11300
Wire Wire Line
	12100 11500 11900 11500
Wire Wire Line
	12700 11700 12700 11500
Wire Wire Line
	12700 11500 12100 11500
Connection ~ 12100 11500
Wire Wire Line
	12700 11900 12700 12000
Connection ~ 12700 12000
Wire Wire Line
	13000 11400 13000 11500
Wire Wire Line
	13000 12200 12400 12200
Connection ~ 13000 12200
Connection ~ 12100 12200
Wire Wire Line
	11900 11500 11575 11500
Connection ~ 11900 11500
Connection ~ 11575 12200
Wire Wire Line
	11575 12200 12100 12200
Wire Wire Line
	12500 12000 12400 12000
Wire Wire Line
	12400 12000 12400 12200
Connection ~ 12400 12200
Wire Wire Line
	12400 12200 12100 12200
Wire Wire Line
	9700 12200 10725 12200
Connection ~ 10725 12200
Wire Wire Line
	10725 12200 11575 12200
Wire Wire Line
	22600 12525 11275 12525
Wire Wire Line
	11275 12525 11275 12000
Wire Wire Line
	22550 12450 11800 12450
Wire Wire Line
	11800 12450 11800 12000
Wire Wire Line
	10725 11800 11575 11800
Connection ~ 11575 11800
Wire Wire Line
	9700 11200 9700 11600
Wire Wire Line
	9700 11200 11900 11200
Wire Wire Line
	9700 11800 10425 11800
Wire Wire Line
	10425 11800 10425 12000
Connection ~ 9700 11800
Text Notes 20225 4350 0    47   ~ 0
RESET(2)
Wire Wire Line
	15825 9025 15825 8925
Wire Wire Line
	15825 9025 17225 9025
Wire Wire Line
	15925 8975 15925 8925
Wire Wire Line
	15925 8975 17325 8975
Connection ~ 17325 8950
Connection ~ 7775 6450
Wire Wire Line
	19875 2400 21150 2400
Wire Wire Line
	21425 4550 17550 4550
Wire Wire Line
	22550 5450 22550 12450
Wire Wire Line
	22050 5050 22050 7875
Wire Wire Line
	21300 8850 21300 9275
Wire Wire Line
	20650 9275 19875 9275
Wire Wire Line
	19875 2400 19875 9275
Wire Wire Line
	19975 2500 19975 8850
Wire Wire Line
	19975 2500 21150 2500
Wire Wire Line
	19975 8850 21300 8850
$Comp
L power:GNDD #PWR018
U 1 1 5D297599
P 17700 1375
F 0 "#PWR018" H 17700 1125 50  0001 C CNN
F 1 "GNDD" H 17704 1220 50  0000 C CNN
F 2 "" H 17700 1375 50  0001 C CNN
F 3 "" H 17700 1375 50  0001 C CNN
	1    17700 1375
	1    0    0    -1  
$EndComp
Text Label 21900 2800 0    60   ~ 0
Tx
Text Label 21900 2900 0    60   ~ 0
Rx
Text Label 17150 1225 0    60   ~ 0
Tx
Text Label 17150 1325 0    60   ~ 0
Rx
Text Notes 17125 975  0    60   ~ 0
STATE_LED
NoConn ~ 17150 1025
Wire Wire Line
	17425 1125 17150 1125
Wire Wire Line
	17700 1375 17550 1375
Wire Wire Line
	17300 1375 17300 1425
Wire Wire Line
	17300 1425 17150 1425
Wire Wire Line
	17550 1625 17550 1475
Connection ~ 17550 1375
Wire Wire Line
	17550 1375 17300 1375
Wire Wire Line
	17825 1125 17825 1300
Wire Wire Line
	17825 1300 17550 1300
Wire Wire Line
	17550 1300 17550 1375
Text Label 20800 1625 2    50   ~ 0
GNDD
Text Label 20800 1700 2    50   ~ 0
GNDD
Text Label 21150 1100 2    60   ~ 0
A6-A7
Wire Notes Line
	20200 747  20200 4600
Wire Notes Line
	20250 3825 20200 3825
Wire Notes Line
	20200 4600 22675 4600
Wire Notes Line
	22675 3825 22675 4600
Wire Wire Line
	21075 4250 21425 4250
Text Notes 14775 1950 0    60   ~ 0
See "Options" box also.\nOnly a single jumper to be used at a time.\nThere are two pinouts of HC-05 style \nmodules and a third for ESP-01 \nadapter, though only one of the modules\ncan be chosen from that lineup.  If\nJ6 pin 3 is needed to be GND for an\nESP-01 adapter, use not only the JP4 shunt \nbut also solder-jumper on board front\nto surrounding copper.  If it is needed for\nconnect to Rx, pad jumpering is available \nnearby.  Note that Tx of one device \nconnects to Rx of the other & vice versa.\nThat is why you'll notice Tx printed on the \nwireless module goes to MCU Rx.
Wire Notes Line
	8075 12750 8075 15550
Wire Notes Line
	18650 15575 18650 12775
Text Notes 8050 13350 0    500  ~ 0
Helpful Parts Not In Circuit
Wire Notes Line
	9025 13475 17925 13475
Text Notes 9090 16060 0    65   ~ 0
· 1 roll Polyimide (Kapton) tape 3/8" wide 6' length or greater.  Use as electrical insulator and place assist. P/N 3057 from Arrow \nor equivalent\n· 38ga magnet wire for trace repairs.  P/N 3522 from Arrow or equivalent\n· Two widely different melting points of Lead-free solder creams (one should contain bismuth), one spool high MP lead-free solder wire.  Larger dia. is better for its stiffness\n· Solder wick P/N TOL-09327 from Arrow or equivalent\n· Soldering colophony (pine or gum ROSIN - NOT with zinc nor ammonium chlorides) flux (can make it yourself)\n· RG316 Coaxial cable 2m/6ft min length\n· Multi-conductor flat IDC ribbon cable or hookup wire.  P/N 2001 to 2006 or 110990044 made in China from Arrow\n· Electrode clamshells; one per leaf electrode.  Having attachment means and gripping spring somewhere along hinge axis and \nhaving enough suspending points spread out to hold clamshell in any specific orientation needed.  \n· 2 Electrode clamshell cushions made from white or ivory color "Kayser-Roth No nonsense knee high 100% nylon socks MADE \nIN USA" UPC 70011195323 (https://www.upcindex.com/70011195323), partially filled with craft-spec styrofoam balls, aka "beads" \nor "beans", approx. 3mm dia.  Per Kayser Roth Consumer Care: "You are able to order the Nononsense Knee Highs on our online \nwebsite nononsense.com. If you are wanting to order them locally you might be able to find them at a Shop-Rite, Walgreens, \nRite-Aid, Food Lion, Harris Teeter, HEB, CVS, or local supermarkets around you."  Yet I actually found them at Wal-Mart.\n· Electrode suspension device of your own making that won't sink into ground and extends a guy strings hang point above DUT\n· Carbon fiber tow, non-impregnated with a gold-plated transition pin per electrode (we have no source yet, but "non-impregnated" \nbasically means "not the shiny type").  The transition pin will interface between the carbon fiber and wiring to the receptacle that\nreceives the coaxial cable plug.  Ensure that conductor material transitions are both (excitation/sense side and return sides of \nthe coax cable) identical so the transitions' galvanic voltages cancel out.\n· Blunt angled or bendable dispensing needle 18ga (eBay or dentist) with syringe body+finger-valved hole, tube, vaccuum pump or modified aquarium pump working in reverse\n\nNOTE - Very high temp solder (K100) not allowed on U4.  The best solder will always be "No Heat SAC305" if you can find it, but \nyou still MUST cleanse gold from pads.  Avoid Pb (leaded) solder unless you understand the behavior of eutectics, how Pb ruins \nother solders, and how gold from ENIG ruins Pb solder.\n
Wire Notes Line
	21575 3825 22915 3825
Wire Notes Line
	8075 12725 18650 12725
$Comp
L power:GNDD #PWR0102
U 1 1 5D43F169
P 17900 9675
F 0 "#PWR0102" H 17900 9425 50  0001 C CNN
F 1 "GNDD" H 17904 9520 50  0000 C CNN
F 2 "" H 17900 9675 50  0001 C CNN
F 3 "" H 17900 9675 50  0001 C CNN
	1    17900 9675
	1    0    0    -1  
$EndComp
Wire Wire Line
	18075 9275 18075 8775
Wire Wire Line
	18075 9275 18250 9275
Wire Wire Line
	17450 8775 18075 8775
Wire Wire Line
	7775 4550 7775 4650
Text Notes 19775 15900 0    39   ~ 0
                         (C) Copyright Kenneth L. Anderson 2018-2019             Ver. 1.0
Text Notes 2400 6325 0    50   ~ 0
Stock shield symbol below slightly \nincorrect:  It is the top that connects \nto GNDA while the bottom is not used
Text Notes 21400 3100 0    50   ~ 0
Directions are of MCU\nfunctions in link to PC
Text Label 17150 1825 0    60   ~ 0
Rx
Text Label 17150 1725 0    60   ~ 0
Tx
Text Notes 22375 1200 0    50   ~ 0
A6 (SCA) and A7 (SCL) on Adafruit Metro M4 Express AirLift\nif you air-wire these over
NoConn ~ 21900 2500
Text Notes 18925 2925 0    60   ~ 0
If level translation \non data lines \nbecomes \nnecessary,\nsee AN97055 and\nAN10441 by NXP.
Wire Wire Line
	17375 9025 17375 9375
Wire Wire Line
	7775 4650 7775 5850
Wire Wire Line
	22600 5450 22550 5450
Wire Wire Line
	21900 2400 22600 2400
Wire Wire Line
	22600 2400 22600 5450
Wire Wire Line
	22650 4725 22650 2000
Wire Wire Line
	21900 2000 22650 2000
Wire Wire Line
	22600 5500 22600 12525
Wire Wire Line
	11675 4425 11800 4425
Wire Wire Line
	3700 4075 3700 4750
NoConn ~ 6250 3625
Text Notes 7450 8425 0    50   ~ 0
Q1,2 pinch-off testing:  Q1,2 need to place enough voltage across LM334 \nto permit full current capability of 1 µA to some mA (equi-spaced steps \nat 68K [256 setting in 50K device] to 13K [66 setting in 50K device]) \nwhile at the same time Q2 presents very high impedance load to U4C pin \n4 as found by proving Q2 has not saturated.
Text Label 10975 4675 2    50   ~ 0
U8-Pad7
Text Label 10975 4775 2    50   ~ 0
U8-Pad8
Wire Wire Line
	7950 4150 7775 4150
Connection ~ 7775 4150
Wire Wire Line
	3225 5350 3225 5450
Wire Wire Line
	3575 5050 3525 5050
Connection ~ 3575 5050
Wire Wire Line
	3575 5250 3575 5450
Wire Wire Line
	3225 5450 3575 5450
$Comp
L uno-shield-v1.0-project-SMD-rescue:AudioJack3_Ground_SwitchTR-audiojack3_ground_switchtr-uno-shield-v1.0-project-SMD-LM662-rescue J5
U 1 1 5C536746
P 1275 4925
F 0 "J5" H 950 4900 50  0000 L CNN
F 1 "Conn_3.5mm" H 825 5150 50  0000 L CNN
F 2 "multipackage:Jack_3.5mm_CUI_SJ1-3534NS_Horizontal_CircularHoles" H 1275 4925 50  0001 C CNN
F 3 " ~" H 1275 4925 50  0001 C CNN
F 4 "25 Requires Kapton tape affixed all around to protect from electrical shorts against surrounding conductors: use two+ layers if expecting user/operator forces.  Place, then check work for inadvertent shorts and opens" H -725 3275 50  0001 C CNN "ClickToSortForPlacement"
F 5 "SJ1-3534NS; Kapton tape: 3057" H 1275 4925 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 1275 4925 50  0001 C CNN "Source"
	1    1275 4925
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J1
U 1 1 5C7F64C7
P 22500 647
F 0 "J1" V 22600 647 50  0000 C CNN
F 1 "CONN_01X01" V 22600 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" H 22421 721 20  0001 C CNN
F 3 "" H 22500 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22500 647 50  0001 C CNN "Part_number"
F 6 "0 For clarity: If U9-U33 & U40 & U41 are not listed because they are on the auxiliary flex board, U9-U32 must be ordered as well.  Same part number and source as U8 and U33, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 22500 647 50  0001 C CNN "Source"
	1    22500 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J2
U 1 1 5C7F64CE
P 22600 647
F 0 "J2" V 22700 647 50  0000 C CNN
F 1 "CONN_01X01" V 22700 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" H 22600 647 20  0001 C CNN
F 3 "" H 22600 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22600 647 50  0001 C CNN "Part_number"
F 6 "0 For clarity: If U9-U33 & U40 & U41 are not listed because they are on the auxiliary flex board, U9-U32 must be ordered as well.  Same part number and source as U8 and U33, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 22600 647 50  0001 C CNN "Source"
	1    22600 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J3
U 1 1 5C7F64D5
P 22700 647
F 0 "J3" V 22800 647 50  0000 C CNN
F 1 "CONN_01X01" V 22800 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" V 22700 647 20  0001 C CNN
F 3 "" H 22700 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22700 647 50  0001 C CNN "Part_number"
F 6 "0 For clarity: If U9-U33 & U40 & U41 are not listed because they are on the auxiliary flex board, U9-U32 must be ordered as well.  Same part number and source as U8 and U33, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 22700 647 50  0001 C CNN "Source"
	1    22700 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 5C7F64DC
P 22800 647
F 0 "J4" V 22900 647 50  0000 C CNN
F 1 "CONN_01X01" V 22900 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" H 22724 569 20  0001 C CNN
F 3 "" H 22800 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22800 647 50  0001 C CNN "Part_number"
F 6 "0 For clarity: If U9-U33 & U40 & U41 are not listed because they are on the auxiliary flex board, U9-U32 must be ordered as well.  Same part number and source as U8 and U33, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 22800 647 50  0001 C CNN "Source"
	1    22800 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even ICSP1
U 1 1 5C7F651F
P 20775 4250
F 0 "ICSP1" H 20675 4575 50  0000 C CNN
F 1 "ICSP Socket" H 20700 4500 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x03_P2.54mm_Vertical" H 20775 4250 50  0001 C CNN
F 3 "~" H 20775 4250 50  0001 C CNN
F 4 "19 Remove the previous JP6 wire and hold the full-size JP6 in its place while placing this.   Set height with all connectors to MCU mated, some connectors may need spaced away from board or otherwise made to fit.   Place using bismuth solder if you have it (provided you used no-lead solder to pre-tin with) for easiest removal.   Then check work for inadvertent shorts and opens.  Replace JP6, if removed, with the style you want - wire or removeable shunt.  Apply Kapton tape anywhere needed as board is mated to MCU, while also ensuring no Vcc conflicts will exist." H 11575 1050 50  0001 C CNN "ClickToSortForPlacement"
F 5 "SSQ-103-03-T-D. Stackables are too often not stocked; unable to source stackable style" H 20775 4250 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 20775 4250 50  0001 C CNN "Source"
	1    20775 4250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x09_Male P2
U 1 1 5C87197B
P 21350 1500
F 0 "P2" H 21450 2050 50  0000 L CNN
F 1 "Power" V 21275 1375 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 21350 1500 50  0001 C CNN
F 3 "~" H 21350 1500 50  0001 C CNN
F 4 "20 Requires more solder than single-sided components and heat for a longer time or the MCU can push the solder pads right off the board.  When MCU is NOT 5V, pin 5 gets removed and pin 4 gets its pad shorted to pin 5 PAD.  When MCU is switchable 5V and 3.3V and you want to be able to switch between the two levels, remove pin 5 still but tie ICSP1 pin 2 into pin 5 PAD with an insulated wire.  Height with all connectors mated and VR1,VR4 leads clear MCU components generously, may need to space away from board some.  Note that the plastic spacer can be adjusted against the pins so the pins extend a little farther from board surface if needed for VR1,VR4 leads to clear MCU components.    Place with dessicant inside using bismuth solder if you have it for easiest removal (provided you used no-lead solder to pre-tin with) .  Then check work for inadvertent shorts and opens." H 11800 -100 50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0. Stackables are too often not stocked; unable to source stackable style.  Consider whether you want to get hookup wire [22-24 ga or so, stranded, multiconductor flat cable] to allow you to runs some diags before you permanently place these large connectors.  Using stranded ribbon cable allows you to also use it with flux as solderwick)." H 21350 1500 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21350 1500 50  0001 C CNN "Source"
	1    21350 1500
	-1   0    0    -1  
$EndComp
$Comp
L uno-shield-v1.0-project-SMD-rescue:Conn_01x08_Male-conn_01x08_maleA-uno-shield-v1.0-project-SMD-LM662-rescue P5
U 1 1 5C8A7B72
P 21850 2500
F 0 "P5" H 21800 2900 50  0000 C CNN
F 1 "Digital" V 21600 2450 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 21850 2500 50  0001 C CNN
F 3 "~" H 21850 2500 50  0001 C CNN
F 4 "21 Requires more solder than single-sided components and heat for a longer time or the MCU can push the solder pads right off the board.  Set height with all connectors mated  and VR1,VR4 leads clear MCU components generously, may need to space away from board some.   Note that the plastic spacer can be adjusted against the pins so the pins extend a little farther from board surface if needed for VR1,VR4 leads to clear MCU components.  Requires more solder than single-sided components and heat for a longer time or the MCU can push the solder pads right off the board.    Use bismuth solder if you have it for easiest removal (provided you used no-lead solder to pre-tin with).  Then check work for inadvertent shorts and opens.  Power up and run diags.  Power down and continue." H 11650 0   50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0. Stackables are too often not stocked; unable to source stackable style" H 21850 2500 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21850 2500 50  0001 C CNN "Source"
	1    21850 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5CC7E1A3
P 11575 11650
F 0 "D1" V 11597 11825 50  0000 R CNN
F 1 "Red: Electrodes shorted" H 12622 11750 50  0000 R CNN
F 2 "multipackage:LED_Rectangular_W5.0mm_H2.0mm" H 11575 11650 50  0001 C CNN
F 3 "~" H 11575 11650 50  0001 C CNN
F 4 "07" H 4925 9250 50  0001 C CNN "PlacementOrder"
F 5 "07" H 4925 9250 50  0001 C CNN "SortForPlacement"
F 6 "08 (Once these get placed, the board won't lay level for placing the other back side components...consider doing those before this if you don't have a heat-resistant, light duty board leveling plan: C3, C4, R8, U6)   For appearance's sake, bend leads all identically.  Then re-tin the pads to the lowest melting point eutectic solder you are able to, then use that same solder to place since LEDs have a very low tolerance to soldering temperatures.  Trying to use dissimilar solder to change the type of tinning will undesireably raise the melting temperature." H 4925 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "SSL-LX2573ID" H 11575 11650 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 11575 11650 50  0001 C CNN "Source"
	1    11575 11650
	0    -1   -1   0   
$EndComp
$Comp
L Device:Q_NMOS_GSD Q7
U 1 1 5C9AB0B5
P 12900 12000
F 0 "Q7" H 13100 11900 50  0000 L CNN
F 1 "DMN601K-7" H 13100 11800 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 13100 11925 50  0001 L CIN
F 3 "https://static6.arrow.com/aropdfconversion/d3486124b1a233cb1531c388ceb5a7bf7f78c2e6/ds30652.pdf" H 12900 12000 50  0001 L CNN
F 4 "03" H 5050 9250 50  0001 C CNN "PlacementOrder"
F 5 "03" H 5050 9250 50  0001 C CNN "SortForPlacement"
F 6 "11 Place then check work.   Heretofore has been components for you to make a judgment whether you're up to this project or not.  Use these quick diagnostics to assess your work: place D1 and D3 by some temporary means like tack soldering (minimal but functional soldering with leads not trimmed for easy removal/reinstall using lowest temp solder available) (observing polarity and leads not touching any other part of board or component condectors!!!!) either side (surface, not edge) of board.  Tack solder 5 volts and ground from unpowered Arduino or other source to ICSP1 pin 2 and ICSP1 pin 6 padded holes and connect your body (if you don't understand research anti-static wrist strap) for the remainder of this project (by a means you'll not forget to re-connect if you have to leave and come back) to circuit ground or PCB ground which most likely is NOT earth ground.   Check for any shorted wiring (especially at the tack soldered items) and apply power across 5VDC and GND and free up your hands.  The green LED should be lit.  Using some tiny metal tool, short across Q3 leads 1 to 2 a few times while watching for the red LED to light up and the green to go out while the short is being applied.  If not full success, remove power, find and fix your circuit mistakes, and try again.  Upon success, remove power.  Tack solder D2.  Fashion a probe wire long enough to touch the probed end to anywhere on the board while the unprobed end is tack soldered to J5 pin pad 1.  Temporary tack solder J2 pin 5 (when MCU is 5V) or J2 pin 4 with its pad shorted to J2 pin 5 pad and J2 pin 5 pin is removed indefinitely or permanently (when MCU is 3.3V) only." H 5050 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 12900 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12900 12000 50  0001 C CNN "Source"
	1    12900 12000
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 5C9AB15E
P 13000 11650
F 0 "D3" V 13100 11650 50  0000 R CNN
F 1 "Green: Proper electrode conductance" H 14900 11750 50  0000 R CNN
F 2 "multipackage:LED_Rectangular_W5.0mm_H2.0mm_green" H 13000 11650 50  0001 C CNN
F 3 "~" H 13000 11650 50  0001 C CNN
F 4 "07" H 5050 9250 50  0001 C CNN "PlacementOrder"
F 5 "07" H 5050 9250 50  0001 C CNN "SortForPlacement"
F 6 "09 Place, then check work" H 5050 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "http://Arrow.com" H 13000 11650 50  0001 C CNN "Source"
F 8 "SSL-LX2573GD" H 13000 11650 50  0001 C CNN "Part_number"
	1    13000 11650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R14
U 1 1 5C9AB204
P 13000 11300
F 0 "R14" H 12875 11297 50  0000 C CNN
F 1 "470 Ω" H 13175 11297 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 13040 11290 50  0001 C CNN
F 3 "~" H 13000 11300 50  0001 C CNN
F 4 "02" H 5050 9200 50  0001 C CNN "PlacementOrder"
F 5 "02" H 5050 9200 50  0001 C CNN "SortForPlacement"
F 6 "06 Place then check work" H 5050 9200 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RC0603JR-07470RL" H 13000 11300 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 13000 11300 50  0001 C CNN "Source"
	1    13000 11300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_US VR2
U 1 1 5CB70AF8
P 21450 9275
F 0 "VR2" H 21382 9229 50  0000 R CNN
F 1 "50 KΩ" H 21382 9320 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-2_Single_Horizontal" H 21450 9275 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 21450 9275 50  0001 C CNN
F 4 "28 Power down first, remove solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after   VR1,VR4 on back side leads must clear MCU components generously" H 12490 3545 50  0001 C CNN "ClickToSortForPlacement"
F 5 "PTV09A-2020F-B503 or may end in B203 or some resistance in between those.  The 2030 may be 2020 or 2015 for shorter shaft" H 21450 9275 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21450 9275 50  0001 C CNN "Source"
	1    21450 9275
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT_US VR1
U 1 1 5DCBBC4B
P 20800 9275
F 0 "VR1" H 20732 9229 50  0000 R CNN
F 1 "50 KΩ" H 20732 9320 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-2_Single_Horizontal" H 20800 9275 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 20800 9275 50  0001 C CNN
F 4 "28 Don't solder, merely press against sides of holes inside them with power on and diags running.  When A0 diags are successful, power down, pull boards apart with great care, then remove J3 and attach it again with a tack solder to J3 pin 2. Power up and run A1 diags using VR2 position similarly (inserted without soldering).   When A1 diags are successful power down, then remove J2, 3, & 4, R1 and solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after.  VR1,VR4 on back side leads must clear MCU components generously" H 11840 3545 50  0001 C CNN "ClickToSortForPlacement"
F 5 "PTV09A-2020F-B503 or may end in B203 or some resistance in between those.  The 2030 may be 2020 or 2015 for shorter shaft" H 20800 9275 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 20800 9275 50  0001 C CNN "Source"
	1    20800 9275
	-1   0    0    1   
$EndComp
$Comp
L uno-shield-v1.0-project-SMD-rescue:Conn_01x06_Male-conn_01x06_male-uno-shield-v1.0-project-SMD-LM662-rescue P3
U 1 1 5C90EA9D
P 21250 2400
F 0 "P3" H 21250 2700 50  0000 L CNN
F 1 "Analog" V 21400 2250 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 21350 2300 50  0001 C CNN
F 3 "~" H 21350 2300 50  0001 C CNN
F 4 "20 Requires more solder than single-sided components and heat for a longer time or the MCU can push the solder pads right off the board.    Place with height with all connectors mated  and VR1,VR4 leads clear MCU components generously, may need to space away from board some.  Note that the plastic spacer can be adjusted against the pins so the pins extend a little farther from board surface if needed for VR1,VR4 leads to clear MCU components.  Use bismuth solder if you have it for easiest removal (provided you used no-lead solder to pre-tin with).  Then check work for inadvertent shorts and opens." H 11650 0   50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0. Stackables are too often not stocked; unable to source stackable style" H 21250 2400 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21250 2400 50  0001 C CNN "Source"
	1    21250 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5F09FFED
P 14150 3025
F 0 "C4" H 14050 3100 50  0000 C CNN
F 1 "0.1 µF" H 14000 2925 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 14150 3025 50  0001 C CNN
F 3 "~" H 14150 3025 50  0001 C CNN
F 4 "08" H 8600 -775 50  0001 C CNN "PlacementOrder"
F 5 "08" H 9350 -825 50  0001 C CNN "SortForPlacement"
F 6 "16 Place then check work as before" H 9350 -825 50  0001 C CNN "ClickToSortForPlacement"
F 7 "CL10B104KB8NNNL" H 14150 3025 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 14150 3025 50  0001 C CNN "Source"
	1    14150 3025
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C3
U 1 1 5F080FB8
P 14325 3025
F 0 "C3" H 14425 3250 50  0000 C CNN
F 1 "10 µF" H 14425 3325 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 14325 3025 50  0001 C CNN
F 3 "~" H 14325 3025 50  0001 C CNN
F 4 "08" H 8775 -625 50  0001 C CNN "PlacementOrder"
F 5 "08" H 9525 -675 50  0001 C CNN "SortForPlacement"
F 6 "16 Observe polarity if electrolytic. Place then check work as before.  " H 9525 -675 50  0001 C CNN "ClickToSortForPlacement"
F 7 "CL10A106KP8NNND" H 14325 3025 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 14325 3025 50  0001 C CNN "Source"
	1    14325 3025
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C5
U 1 1 5C854E30
P 15175 4175
F 0 "C5" V 15275 4275 50  0000 C CNN
F 1 "10 µF" V 15275 4525 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 15175 4175 50  0001 C CNN
F 3 "~" H 15175 4175 50  0001 C CNN
F 4 "08" H 9625 525 50  0001 C CNN "PlacementOrder"
F 5 "08" H 10375 475 50  0001 C CNN "SortForPlacement"
F 6 "14 Observe polarity if electrolytic. Place then check work as before.  " H 10375 475 50  0001 C CNN "ClickToSortForPlacement"
F 7 "only needed with HX711 option: CL10A106KP8NNND" H 15175 4175 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 15175 4175 50  0001 C CNN "Source"
	1    15175 4175
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small_US R6
U 1 1 5D7C1CE7
P 14550 7200
F 0 "R6" H 14425 7275 50  0000 C CNN
F 1 "44.2 KΩ 0.1% 0.1W(1/10W) ±10ppm/°C (1676343-2)" H 13475 7200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 14550 7200 50  0001 C CNN
F 3 "~" H 14550 7200 50  0001 C CNN
F 4 "http://Arrow.com" H 14550 7200 50  0001 C CNN "Source"
F 5 "1676343-2" H 14550 7200 50  0001 C CNN "Part_number"
F 6 "14 Note this is a precision value component so its conductive ends and black surface must remain perfectly undamaged. Place then check work as before" H 14550 7200 50  0001 C CNN "ClickToSortForPlacement"
	1    14550 7200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R7
U 1 1 5D3506B3
P 14850 7200
F 0 "R7" H 14925 7075 50  0000 C CNN
F 1 "22.6 KΩ 0.1% 0.125W(1/8W) ±10ppm/°C (ERA6ARB2262V)" H 15875 6975 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 14850 7200 50  0001 C CNN
F 3 "~" H 14850 7200 50  0001 C CNN
F 4 "http://Arrow.com" H 14850 7200 50  0001 C CNN "Source"
F 5 "ERA6ARB2262V" H 14850 7200 50  0001 C CNN "Part_number"
F 6 "14 Note this is a precision value component so its conductive ends and black surface must remain perfectly undamaged.  Place then check work as before" H 14850 7200 50  0001 C CNN "ClickToSortForPlacement"
	1    14850 7200
	1    0    0    -1  
$EndComp
$Comp
L Reference_Current:REF200AU U4
U 3 1 5D0FCC87
P 7775 6150
F 0 "U4" H 7500 6125 50  0000 L CNN
F 1 "REF200AU" H 7250 6000 50  0000 L CIN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7650 6175 50  0001 R CIN
F 3 "www.ti.com/lit/ds/symlink/ref200.pdf" H 8075 6150 50  0001 C CIN
F 4 "http://Arrow.com" H 7775 6150 50  0001 C CNN "Source"
F 5 "REF200AU (Requires hermetic sealing, so will have dessicant with it that you'll need to place under SHLD1)" H 7775 6150 50  0001 C CNN "Part_number"
F 6 "26 Before opening this shipping package, perform as complete of diagnostics as possible of all circuitry under SHLD1 placed thus far: solder a shorting wire between pins 4 & 5 of U3 (mix & match with pins 1 of both Q1 and Q2) and load the Arduino with GWAAM-Sea Diagnostics 1 and run them.  Remove short between pins 4 and 5 of U3.  Then, from the bottom side of the board, solder seal any and all via holes left unsoldered located within SHLD1 footprint.  Solder seal any and all place-assist holes located within SHLD1 footprint except U3 place-assist holes.  All this should minimize risk of getting interrupted while U3 is left not heremetically sealed.  Tin SHLD1 around outside of bottom edge that will get soldered to its footprint.  Tin SHLD1 footprint on the board, leaving a very SMOOTH & FLAT surface to mate with SHLD1.  Prepare dessicant (trim pkg for edges to be bent over to fit inside SHLD1 holding like a pinch of the silica or clay granules & held in place by Kapton tape without putting pressure on other components) as soon as U3 is placed, and ensure SHLD1 is handy also.  Place U3 and perform diagnostics of U3.  After diags, solder-seal its place-assist holes.  Immediately perform next step." H 7775 6150 50  0001 C CNN "ClickToSortForPlacement"
	3    7775 6150
	1    0    0    -1  
$EndComp
$Comp
L Reference_Current:REF200AU U4
U 2 1 5D0FB910
P 14400 6725
F 0 "U4" H 14580 6771 50  0000 L CNN
F 1 "REF200AU" H 14580 6680 50  0000 L CIN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 14275 6750 50  0001 R CIN
F 3 "www.ti.com/lit/ds/symlink/ref200.pdf" H 14700 6725 50  0001 C CIN
F 4 "http://Arrow.com" H 14400 6725 50  0001 C CNN "Source"
F 5 "REF200AU (Requires hermetic sealing, so will have dessicant with it that you'll need to place under SHLD1)" H 14400 6725 50  0001 C CNN "Part_number"
F 6 "26 Before opening this shipping package, perform as complete of diagnostics as possible of all circuitry under SHLD1 placed thus far: solder a shorting wire between pins 4 & 5 of U3 (mix & match with pins 1 of both Q1 and Q2) and load the Arduino with GWAAM-Sea Diagnostics 1 and run them.  Remove short between pins 4 and 5 of U3.  Then, from the bottom side of the board, solder seal any and all via holes left unsoldered located within SHLD1 footprint.  Solder seal any and all place-assist holes located within SHLD1 footprint except U3 place-assist holes.  All this should minimize risk of getting interrupted while U3 is left not heremetically sealed.  Tin SHLD1 around outside of bottom edge that will get soldered to its footprint.  Tin SHLD1 footprint on the board, leaving a very SMOOTH & FLAT surface to mate with SHLD1.  Prepare dessicant (trim pkg for edges to be bent over to fit inside SHLD1 holding like a pinch of the silica or clay granules & held in place by Kapton tape without putting pressure on other components) as soon as U3 is placed, and ensure SHLD1 is handy also.  Place U3 and perform diagnostics of U3.  After diags, solder-seal its place-assist holes.  Immediately perform next step." H 14400 6725 50  0001 C CNN "ClickToSortForPlacement"
	2    14400 6725
	1    0    0    -1  
$EndComp
$Comp
L uno-shield-v1.0-project-SMD-rescue:ADL5315ACPZ-R7-2019-05-19_00-44-38-uno-shield-rescue-uno-shield-rescue-uno-shield-rescue-uno-shield-v1.0-project-SMD-LM662-rescue U3
U 1 1 5CE2F217
P 3800 4650
F 0 "U3" H 5000 5037 60  0000 C CNN
F 1 "ADL5315ACPZ-R7" H 5000 4931 60  0000 C CNN
F 2 "multipackage:ADL5315ACPZ-R7" H 5000 4890 60  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ADL5315.pdf" H 3800 4650 60  0001 C CNN
F 4 "http://Arrow.com" H 3800 4650 50  0001 C CNN "Source"
F 5 "ADL5315ACPZ-R7" H 3800 4650 50  0001 C CNN "Part_number"
F 6 "03 Being careful not to desolder surrounding components (use the otherwise purposeless body of SHLD1 to protect them, if it helps), tin pads on lateral sides of the component itself and the center and largest pad on bottom side of the component itself.  Ensure that none of the solder tinning on the lateral side pads of the component extends below bottom plane as that solder won't melt while soldering bottom pad to allow component to fully seat against board.  It would be ideal to solder center pin 9 from the back side of board and ensure its attachment to the via and pins 1-8 from front of board.  Pin 9 should be soldered first so you can verify it becomes soundly attached and seated against board, but I don't know a technique to do it while ensuring the other pads will all stay lined up.  When finished soldering, check that surrounding components already placed were not disturbed. Check work for inadvertent shorts and opens. " H 3800 4650 50  0001 C CNN "ClickToSortForPlacement"
	1    3800 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5CE3497C
P 3250 4550
F 0 "C1" H 3125 4350 50  0000 L CNN
F 1 "390 pF" H 2975 4450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3250 4550 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/49ec807b959b60718e041765739a26df3c5be107/cl10c391jb8nnnd-19.pdf" H 3250 4550 50  0001 C CNN
F 4 "http://Arrow.com" H 3250 4550 50  0001 C CNN "Source"
F 5 "CL10C391JB8NNND" H 3250 4550 50  0001 C CNN "Part_number"
F 6 "02 A tiny 0201-size duplicate C1 pad set is on PCB.  Determine which pad set your C1 fits.  Place (always means solder down herein) C1 where and on side that _level_ reference is silk-screened, not angled reference.  Then check work for inadvertent shorts and opens." H 3250 4550 50  0001 C CNN "ClickToSortForPlacement"
	1    3250 4550
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5CE92D72
P 3800 4075
F 0 "C2" V 4025 4025 50  0000 L CNN
F 1 ".22 µF" V 3925 3950 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3800 4075 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/e8d848dc912b3e5d98046e6e34ee002631d712c/y5v.pdf" H 3800 4075 50  0001 C CNN
F 4 "0603YG224ZAT2A" H 3800 4075 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 3800 4075 50  0001 C CNN "Source"
F 6 "14 Place then check work as before" H 3800 4075 50  0001 C CNN "ClickToSortForPlacement"
	1    3800 4075
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R3
U 1 1 5CED190D
P 3475 4650
F 0 "R3" V 3550 4600 50  0000 L CNN
F 1 "3.9 KΩ" V 3375 4575 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3475 4650 50  0001 C CNN
F 3 "~" H 3475 4650 50  0001 C CNN
F 4 "http://Arrow.com" H 3475 4650 50  0001 C CNN "Source"
F 5 "RK73B1JTTD392J order an extra one of this value for the first diagnostic step if you can afford it." H 3475 4650 50  0001 C CNN "Part_number"
F 6 "04 Place then check work " H 3475 4650 50  0001 C CNN "ClickToSortForPlacement"
	1    3475 4650
	0    -1   -1   0   
$EndComp
$Comp
L Device:Q_NMOS_GSD Q3
U 1 1 5CED0C82
P 9600 12000
F 0 "Q3" H 9500 11850 50  0000 L CNN
F 1 "DMN601K-7" H 9300 11750 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 9800 11925 50  0001 L CIN
F 3 "http://www.redrok.com/MOSFET_BS108_200V_250mA_8O_Vth1.5_TO-92.PDF" H 9600 12000 50  0001 L CNN
F 4 "03" H 3050 9250 50  0001 C CNN "PlacementOrder"
F 5 "03" H 3050 9250 50  0001 C CNN "SortForPlacement"
F 6 "07 Place then check work" H 3050 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 9600 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 9600 12000 50  0001 C CNN "Source"
	1    9600 12000
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q4
U 1 1 5CEFAE8D
P 10625 12000
F 0 "Q4" H 10525 11850 50  0000 L CNN
F 1 "DMN601K-7" H 10325 11750 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 10825 11925 50  0001 L CIN
F 3 "http://www.redrok.com/MOSFET_BS108_200V_250mA_8O_Vth1.5_TO-92.PDF" H 10625 12000 50  0001 L CNN
F 4 "03" H 4075 9250 50  0001 C CNN "PlacementOrder"
F 5 "03" H 4075 9250 50  0001 C CNN "SortForPlacement"
F 6 "07 Place then check work" H 4075 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 10625 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 10625 12000 50  0001 C CNN "Source"
	1    10625 12000
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q5
U 1 1 5CC49A39
P 11475 12000
F 0 "Q5" H 11375 11850 50  0000 L CNN
F 1 "DMN601K-7" H 11175 11750 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 11675 11925 50  0001 L CIN
F 3 "http://www.redrok.com/MOSFET_BS108_200V_250mA_8O_Vth1.5_TO-92.PDF" H 11475 12000 50  0001 L CNN
F 4 "03" H 4925 9250 50  0001 C CNN "PlacementOrder"
F 5 "03" H 4925 9250 50  0001 C CNN "SortForPlacement"
F 6 "07 Place then check work" H 4925 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 11475 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 11475 12000 50  0001 C CNN "Source"
	1    11475 12000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R10
U 1 1 5D039973
P 9700 11700
F 0 "R10" H 9550 11900 50  0000 C CNN
F 1 "1 MΩ" H 9525 11775 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9740 11690 50  0001 C CNN
F 3 "~" H 9700 11700 50  0001 C CNN
F 4 "02" H 2050 9100 50  0001 C CNN "PlacementOrder"
F 5 "02" H 2050 9100 50  0001 C CNN "SortForPlacement"
F 6 "06 Place then check work" H 2050 9100 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RK73B1JTTD105J" H 9700 11700 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 9700 11700 50  0001 C CNN "Source"
	1    9700 11700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R1
U 1 1 5D398C0C
P 2500 5000
F 0 "R1" H 2350 5025 50  0000 L CNN
F 1 "100 Ω" H 2250 5100 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2500 5000 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/92767ba402f81f7b2b89a2bb7df37eaf75b9d9b4/sei-rmcf_rmcp.pdf" H 2500 5000 50  0001 C CNN
F 4 "http://Arrow.com" H 2500 5000 50  0001 C CNN "Source"
F 5 "RMCF0603FT100R" H 2500 5000 50  0001 C CNN "Part_number"
F 6 "04 Place then check work" H 2500 5000 50  0001 C CNN "ClickToSortForPlacement"
	1    2500 5000
	-1   0    0    1   
$EndComp
$Comp
L Jumper:SolderJumper_3_Bridged12 JP1
U 1 1 5D8B719E
P 2825 4175
F 0 "JP1" H 2825 4375 50  0000 C CNN
F 1 "C1_leak_mitigator" H 2675 4275 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm_NumberLabels" H 2825 4175 50  0001 C CNN
F 3 "~" H 2825 4175 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0" H 2825 4175 50  0001 C CNN "Part_number"
F 5 "00 (TIPS - Always when sorting this page, make the column's title cell show the little sort direction indicator highlighted and pointing up. Watch any GWAAMC YouTube instructional video.  Solder temperature if using a soldering iron: On the two-lead SMD components use your highest melting temperature solder so they aren't so easily dislocated later when accidentally bumped with hot iron.  Never allow leaded solder to cross contaminate low-temp [bismuth] solders - lead ruins them.  Do your best to keep SMD component leads clean from adhesive tape glue and other sticky, clingy, slimy contaminates that could leave a film where solder will need to adhere to them.  Plated through holes can only be used once on new boards unless they are Hot Air Solder Leveled [HASL] and you are careful to match solders with the factory solder or you are prepared to ream out plating-contaminated solder from the hole, so do NOT assume that tinning plated through holes to prepare the holes themselves for pins or leads is the right thing to do!  Just use them as-is when the time comes even though they won't take the solder as well, or instead you may plug the holes with stainless steel paste dispensing syringe needle/nozzle 20-21 gauge while you tin the annular ring only on the one side opposite the component.  Take care about LEDs and U3 soldering temperatures - they don't stand the temperatures of other components.   U3 special handling - don't open U3 shipping/storage package until these instructions say to; soldering temperature for U3 must never exceed 250C/500F.)     Cleanse gold from all pads on the board by tinning - twice at least on SMD pads - with the same solder composition you'll use on the respective pads, leaving no gold and as little solder as possible on them - solder wick and rosin flux are invaluable for this task, and use some ingenuity on those plated-through holes to ensure they can be cleared out when done tinning them.  Allow 2 to 5 hours on this step alone, since the only way to do this quicker is by industrial HASL; and, yes, all the melted solder mask will look awful. The reasoning? Plating interferes with solder, making untinned pads almost impossible to solder to with this leadless package type.   Now would be the best time to solder-seal hermetically tight all the micro-vias that let light through, if any, within SHLD1 footprint.  Once the components get placed where they shadow the micro-vias, any non-sealed ones will be totally not findable.  Use a bright light shining through to ensure all vias get sealed, but do not seal place-assist holes yet nor U2 center lead hole.  Whether mere solder mask actually hermetically seals adequately is debatable - I would only trust it if it is thick enough to block all light.  Use solder to seal any suspicious micro-vias.  Solder-short pads 1 to 2 of this JP1, keeping all previous solder joints from melting.  Take that precaution throughout assembly." H 2825 4175 50  0001 C CNN "ClickToSortForPlacement"
	1    2825 4175
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_3_Bridged12 JP2
U 1 1 5D936E95
P 4200 3725
F 0 "JP2" H 4200 3900 50  0000 C CNN
F 1 "C2_bias_reducer" H 4200 3825 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm_NumberLabels" H 4200 3725 50  0001 C CNN
F 3 "~" H 4200 3725 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0" H 4200 3725 50  0001 C CNN "Part_number"
F 5 "01 Solder-short pads 1 to 2." H 4200 3725 50  0001 C CNN "ClickToSortForPlacement"
	1    4200 3725
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male P4
U 1 1 5C8B326A
P 21700 1500
F 0 "P4" H 21675 1950 50  0000 C CNN
F 1 "Digital" V 21600 1450 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical" H 21700 1500 50  0001 C CNN
F 3 "~" H 21700 1500 50  0001 C CNN
F 4 "20 Requires more solder than single-sided components and heat for a longer time, especially on the GNDD pin or the MCU can push the solder pads right off the board.  Use bismuth solder if you have it for easiest removal (provided you used no-lead solder to pre-tin with).  Place with height with all connectors mated  and VR1,VR4 leads clear MCU components generously, may need to space away from board some.  Note that the plastic spacer can be adjusted against the pins so the pins extend a little farther from board surface if needed for VR1,VR4 leads to clear MCU components.  Then check work for inadvertent shorts and opens." H 11650 0   50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0. Stackables are too often not stocked; unable to source stackable style" H 21700 1500 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21700 1500 50  0001 C CNN "Source"
	1    21700 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R5
U 1 1 5CFA3142
P 6300 4950
F 0 "R5" V 6200 4925 50  0000 L CNN
F 1 "10 KΩ" V 6100 4775 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6300 4950 50  0001 C CNN
F 3 "~" H 6300 4950 50  0001 C CNN
F 4 "http://Arrow.com" H 6300 4950 50  0001 C CNN "Source"
F 5 "RC0603JR-1310KL" H 6300 4950 50  0001 C CNN "Part_number"
F 6 "05 Place, then check work as before.   The steps up to this one were to install first stage stability ckt for powering up U3.  Pwr supply stability ckts for U1 and ADC1 are next after diagnostics of the work you've done so far:  You have reached the step of applying power voltage to the board, and you MUST not make any mistakes doing so or you'll all too likely damage components that will cost you extra shipping, handling to replace.  As you prepare to continue, be fully aware that any mistakes you make can destroy components when power gets applied.  BE VERY OBSERVANT.  Determine which of +5V or +3V3 your MCU puts on ICSP1 pin 2 before applying MCU power to this board: 5V is default of this PCB design.  If the MCU instead puts 3V on the ICSP1 pin 2, you MUST modify this board at J2 pins 4 & 5 or you'll stress out your MCU and likely damage it!  Such modification inflexibly renders this board unfit for 5V operation since there was not room for jumpers to make this change flexible.  You will bring the Arduino's Vcc to this board's Vcc (the pad of pin 2 JP6 or install JP6 and use the pad of pin 2 ICSP1) and Arduino GND to this board's GNDD somewhere (the pad of J2 pin 6 or 7 is fine) semi-long-term somehow without power, yet, on the Arduino while ensuring nothing of this wiring can short together now nor later.  If you decide to solder anything down for this purpose, make SURE you cleanse the gold from whatever pads you choose so you can melt the joint later...that non-eutectic composition raises the melting point way higher than you'd think - and this was your last warning of that point for the entire board. Once that is done, power up the Arduino and pay no attention to what the Arduino does except make sure it does something to indicate it has power to it.  Devote your attention to the GWAAM-Sea board where you'll carefully (so as not to short anything out) measure and verify these voltages: the T pad of J1 should have 4.0 VDC on it unless the Arduino is a 3.3V device in which case that same pad will have 2.2-2.3 VDC on it.  (If you didn't already know enough before now to touch one voltmeter lead to ground and the other to the named pad then you are not of sufficient ability to be doing this assembly at all - please power down the Arduino and stop right now in that case and decide what you need to learn about voltmetering.  Learn it before coming back to this step.  We are hoping to put up YouTube videos to help everyone in your situation.)  Remove power from Arduino but keep Arduino and this board wired together.  Temporarily use R10, R12, & R13 (these are all interchangeable) in this way: tack R10 between SHLD1 trace and the pad for pin 5 of U4.  The live end is on the pad of pin 5 U4.  We'll use R12 & R13 after this initial voltage check.  Powered up VDC right now on the live end of the temporary R10 resistor should be less than 0.01 VDC.  Power down Arduino.  Next tack R12 and R13 in series with each other bridging across S and T of J1, powering down the Arduino to do so.  With power on again, the VDC on J1 pad T will be just a tad bit less it was than before.  VDC on the live end of the temporary diag resistor will be half that level.  If you can read the meter while shorting across only one of R12-R13 the reading should rise to 4.0 (or 2.2-2.3 in 3.3V systems).  Remove power to continue the assembly.  Remove R10, R12, & R13 and install the extra R3 or other 3.9K where R10 was just removed from: from U4 pad 5 to SHLD1 trace right next to it.  Decide on a way you'll short between S and T of J1 to make the next voltage measurement and apply the short now or when you make that measurement.  Apply power again and measure the live end of that spare R3 with the aforementioned short placed.    With power on again, the VDC on J1 pad T will be just a tad bit less Vcc-1.   Remove power but leave the spare R3 and short of J1 there for another diagnostic step." H 6300 4950 50  0001 C CNN "ClickToSortForPlacement"
	1    6300 4950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R12
U 1 1 5CFE49AF
P 12600 12000
F 0 "R12" V 12700 12025 50  0000 C CNN
F 1 "1 MΩ" V 12500 12000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 12640 11990 50  0001 C CNN
F 3 "~" H 12600 12000 50  0001 C CNN
F 4 "02" H 4950 9400 50  0001 C CNN "PlacementOrder"
F 5 "02" H 4950 9400 50  0001 C CNN "SortForPlacement"
F 6 "06 Place then check work" H 4950 9400 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RC0603FR-071ML " H 12600 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12600 12000 50  0001 C CNN "Source"
	1    12600 12000
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R13
U 1 1 5CFE72EE
P 12700 11800
F 0 "R13" H 12800 11700 50  0000 C CNN
F 1 "1 MΩ" H 12850 11775 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 12740 11790 50  0001 C CNN
F 3 "~" H 12700 11800 50  0001 C CNN
F 4 "02" H 5050 9200 50  0001 C CNN "PlacementOrder"
F 5 "02" H 5050 9200 50  0001 C CNN "SortForPlacement"
F 6 "07 Place then check work" H 5050 9200 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RK73B1JTTD105J" H 12700 11800 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12700 11800 50  0001 C CNN "Source"
	1    12700 11800
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small_US R11
U 1 1 5D04A72D
P 11900 11400
F 0 "R11" H 11775 11397 50  0000 C CNN
F 1 "470 Ω" H 12075 11397 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 11940 11390 50  0001 C CNN
F 3 "~" H 11900 11400 50  0001 C CNN
F 4 "02" H 3950 9300 50  0001 C CNN "PlacementOrder"
F 5 "02" H 3950 9300 50  0001 C CNN "SortForPlacement"
F 6 "07 Place then check work" H 3950 9300 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RC0603JR-07470RL" H 11900 11400 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 11900 11400 50  0001 C CNN "Source"
	1    11900 11400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J6_A7,A6
U 1 1 5D238E1B
P 17225 8750
F 0 "J6_A7,A6" V 17225 9150 50  0000 R CNN
F 1 "Conn_01x02_Male" V 17150 9450 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 17225 8750 50  0001 C CNN
F 3 "~" H 17225 8750 50  0001 C CNN
F 4 "Use part of a second TSW-150-05-T-S/4-103327-0 " H 17225 8750 50  0001 C CNN "Part_number"
F 5 "99" H 17225 8750 50  0001 C CNN "ClickToSortForPlacement"
F 6 "http://Arrow.com" H 17225 8750 50  0001 C CNN "Source"
	1    17225 8750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_POT_US VR3
U 1 1 5DC8E599
P 17700 9375
F 0 "VR3" H 17632 9329 50  0000 R CNN
F 1 "20 KΩ" H 17632 9420 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 17700 9375 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 17700 9375 50  0001 C CNN
F 4 "28 Don't solder, merely press against sides of holes inside them with power on and diags running.  When A0 diags are successful, power down, pull boards apart with great care, then remove J3 and attach it again with a tack solder to J3 pin 2. Power up and run A1 diags using VR2 position similarly (inserted without soldering).   When A1 diags are successful power down, then remove J2, 3, & 4, R1 and solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after.  VR1,VR4 on back side leads must clear MCU components generously" H 8740 3645 50  0001 C CNN "ClickToSortForPlacement"
F 5 "User/developer use only: PTV09A-4030U-B203 or may end in B503 or some resistance in between those.  The 4030 may be 4020 or 4015 for shorter shaft. If using the UNO SMD MCU version with an ATMEGA128P-AU (a TQFP package specifically instead of the UNO with a DIP ATMEGA128P), there are two analog input pins available at the TQFP package on the MCU board that not wired out to any connector.  One or both of these can be, if you are willing to attach tiny wires between them and VR3/4 and write the code, used as seventh and eighth analog inputs A6 & A7.  Then air-wire them or connectorize them somehow across to this extention board and buy the PCB mount vertically oriented version of PTV09 pots to get one or two more user developed, run-time analog input controls into the training board." H 17700 9375 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 17700 9375 50  0001 C CNN "Source"
	1    17700 9375
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D2
U 1 1 5CC7E20B
P 12100 11650
F 0 "D2" V 12097 11550 50  0000 R CNN
F 1 "Yellow: Inadequate electrode conductance" H 13797 11475 50  0000 R CNN
F 2 "multipackage:LED_Rectangular_W5.0mm_H2.0mm_yellow" H 12100 11650 50  0001 C CNN
F 3 "~" H 12100 11650 50  0001 C CNN
F 4 "07" H 5050 9250 50  0001 C CNN "PlacementOrder"
F 5 "07" H 5050 9250 50  0001 C CNN "SortForPlacement"
F 6 "09 Place, then check work" H 5050 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "SSL-LX2573YD" H 12100 11650 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12100 11650 50  0001 C CNN "Source"
	1    12100 11650
	0    -1   -1   0   
$EndComp
$Comp
L Device:Q_NMOS_GSD Q6
U 1 1 5CC49AA9
P 12000 12000
F 0 "Q6" H 12200 11900 50  0000 L CNN
F 1 "DMN601K-7" H 12200 11750 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 12200 11925 50  0001 L CIN
F 3 "~" H 12000 12000 50  0001 L CNN
F 4 "03" H 5050 9250 50  0001 C CNN "PlacementOrder"
F 5 "03" H 5050 9250 50  0001 C CNN "SortForPlacement"
F 6 "10 Place then check work.  " H 5050 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 12000 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12000 12000 50  0001 C CNN "Source"
	1    12000 12000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J7_A7,A6
U 1 1 5CFFF071
P 15925 8725
F 0 "J7_A7,A6" V 15925 8475 50  0000 R CNN
F 1 "Conn_01x02_Female" V 15850 8550 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 15925 8725 50  0001 C CNN
F 3 "~" H 15925 8725 50  0001 C CNN
F 4 "SSA-102-S-T" H 15925 8725 50  0001 C CNN "Part_number"
F 5 "99" H 15925 8725 50  0001 C CNN "ClickToSortForPlacement"
F 6 "http://Arrow.com" H 15925 8725 50  0001 C CNN "Source"
	1    15925 8725
	0    1    -1   0   
$EndComp
$Comp
L Connector:Conn_01x09_Female J6
U 1 1 5D248321
P 16950 1425
F 0 "J6" H 16925 975 50  0000 C CNN
F 1 "Conn_01x09_Female" H 16950 2050 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x09_P2.54mm_Vertical" H 16950 1425 50  0001 C CNN
F 3 "~" H 16950 1425 50  0001 C CNN
F 4 "99  Optional and not ideal.  Direct solder is best." H 16950 1425 50  0001 C CNN "ClickToSortForPlacement"
F 5 "Sockets: 1 qty SL-106-T-10 optional and not ideal and may not fit pin dia.  Direct solder is normally a better option except in experimentation environments and where smaller dia pins can be found if needed." H 16950 1425 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 16950 1425 50  0001 C CNN "Source"
	1    16950 1425
	-1   0    0    1   
$EndComp
$Comp
L Jumper:Jumper_2_Bridged JP4
U 1 1 5D27A949
P 17350 1625
F 0 "JP4" H 17350 1575 50  0000 C CNN
F 1 "HC-05_EN/KEY" H 17825 1550 50  0000 C CNN
F 2 "multipackage:PinHeader_1x02_P2.54mm_Vertical" H 17350 1625 50  0001 C CNN
F 3 "~" H 17350 1625 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0.  ONLY used if wireless module installed" H 17350 1625 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 17350 1625 50  0001 C CNN "Source"
F 6 "99 ONLY used if wireless module installed" H 17350 1625 50  0001 C CNN "ClickToSortForPlacement"
	1    17350 1625
	1    0    0    -1  
$EndComp
$Comp
L Jumper:Jumper_2_Bridged JP5
U 1 1 5D29AEF4
P 17625 1125
F 0 "JP5" H 17625 1075 50  0000 C CNN
F 1 "HC-05_KEY/STATE_LED" H 18075 1200 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 17625 1125 50  0001 C CNN
F 3 "~" H 17625 1125 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0.  ONLY used if wireless module installed" H 17625 1125 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 17625 1125 50  0001 C CNN "Source"
F 6 "99 ONLY used if wireless module installed" H 17625 1125 50  0001 C CNN "ClickToSortForPlacement"
	1    17625 1125
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PJFET_SDG Q2
U 1 1 5D11525B
P 8775 4350
F 0 "Q2" H 8525 4300 50  0000 L CNN
F 1 "MMBF5460 (2N5460)" H 8075 4175 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 8975 4450 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/MMBF5462-D.pdf" H 8775 4350 50  0001 C CNN
F 4 "MMBF5460" H 8775 4350 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 8775 4350 50  0001 C CNN "Source"
F 6 "24 Place, check work, place the diags resistors back that you may have had to move or remove using pad 1 of a MOSFET for any diag resistor to it.  Run the same diags just ran in previous step.  Remove diag resistors." H 8775 4350 50  0001 C CNN "ClickToSortForPlacement"
F 7 "KiCAD library symbol flips D and S" H 8775 4350 50  0001 C CNN "Note"
	1    8775 4350
	1    0    0    -1  
$EndComp
$Comp
L uno-shield-v1.0-project-SMD-rescue:SolderJumper_3_Bridged12-solderjumper_3_bridged12-uno-shield-v1.0-project-SMD-LM662-rescue JP10
U 1 1 5D43B289
P 18400 8975
F 0 "JP10" H 18400 9100 50  0000 C CNN
F 1 "SolderJumper_3_Bridged12" H 17625 8975 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_Pad1.0x1.5mm_NumberLabels" H 18400 8975 50  0001 C CNN
F 3 "~" H 18400 8975 50  0001 C CNN
F 4 "999" H 18400 8975 50  0001 C CNN "ClickToSortForPlacement"
	1    18400 8975
	-1   0    0    -1  
$EndComp
$Comp
L uno-shield-v1.0-project-SMD-rescue:SolderJumper_3_Bridged12-solderjumper_3_bridged12-uno-shield-v1.0-project-SMD-LM662-rescue JP11
U 1 1 5D43C8EF
P 18400 9575
F 0 "JP11" H 18400 9688 50  0000 C CNN
F 1 "SolderJumper_3_Bridged12" H 17600 9600 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_Pad1.0x1.5mm_NumberLabels" H 18400 9575 50  0001 C CNN
F 3 "~" H 18400 9575 50  0001 C CNN
F 4 "999" H 18400 9575 50  0001 C CNN "ClickToSortForPlacement"
	1    18400 9575
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT_US VR4
U 1 1 5DC8FA72
P 18400 9275
F 0 "VR4" H 18332 9229 50  0000 R CNN
F 1 "20 KΩ" H 18332 9320 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 18400 9275 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 18400 9275 50  0001 C CNN
F 4 "28 Don't solder, merely press against sides of holes inside them with power on and diags running.  When A0 diags are successful, power down, pull boards apart with great care, then remove J3 and attach it again with a tack solder to J3 pin 2. Power up and run A1 diags using VR2 position similarly (inserted without soldering).   When A1 diags are successful power down, then remove J2, 3, & 4, R1 and solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after.  VR1,VR4 on back side leads must clear MCU components generously" H 9440 3545 50  0001 C CNN "ClickToSortForPlacement"
F 5 "User/developer use only: PTV09A-4030U-B203 or may end in B503 or some resistance in between those.  The 4030 may be 4020 or 4015 for shorter shaft. If using the UNO SMD MCU version with an ATMEGA128P-AU (a TQFP package specifically instead of the UNO with a DIP ATMEGA128P), there are two analog input pins available at the TQFP package on the MCU board that not wired out to any connector.  One or both of these can be, if you are willing to attach tiny wires between them and VR3/4 and write the code, used as seventh and eighth analog inputs A6 & A7.  Then air-wire them or connectorize them somehow across to this extention board and buy the PCB mount vertically oriented version of PTV09 pots to get one or two more user developed, run-time analog input controls into the training board." H 18400 9275 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 18400 9275 50  0001 C CNN "Source"
	1    18400 9275
	-1   0    0    1   
$EndComp
$Comp
L uno-shield-v1.0-project-SMD-rescue:SolderJumper_3_Bridged12-solderjumper_3_bridged12-uno-shield-v1.0-project-SMD-LM662-rescue JP9
U 1 1 5D43D9B5
P 17700 9675
F 0 "JP9" H 17700 9788 50  0000 C CNN
F 1 "SolderJumper_3_Bridged12" H 17525 9925 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_Pad1.0x1.5mm_NumberLabels" H 17700 9675 50  0001 C CNN
F 3 "~" H 17700 9675 50  0001 C CNN
F 4 "999" H 17700 9675 50  0001 C CNN "ClickToSortForPlacement"
	1    17700 9675
	-1   0    0    1   
$EndComp
$Comp
L Device:Q_PJFET_SDG Q1
U 1 1 5D3CA4B3
P 7675 4350
F 0 "Q1" H 7375 4350 50  0000 L CNN
F 1 "MMBF5460 (2N5460)" H 6750 4275 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 7875 4450 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/MMBF5462-D.pdf" H 7675 4350 50  0001 C CNN
F 4 "MMBF5460" H 7675 4350 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 7675 4350 50  0001 C CNN "Source"
F 6 "24 Place, check work, place the diags resistors back that you may have had to move or remove using pad 1 of a MOSFET for any diag resistor to it.  Run the same diags just ran in previous step.  Remove diag resistors." H 7675 4350 50  0001 C CNN "ClickToSortForPlacement"
F 7 "KiCAD library symbol flips D and S" H 7675 4350 50  0001 C CNN "Note"
	1    7675 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R9
U 1 1 5CFBF015
P 6150 4025
F 0 "R9" H 5975 4075 50  0000 L CNN
F 1 "10 KΩ" H 5825 3975 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6150 4025 50  0001 C CNN
F 3 "~" H 6150 4025 50  0001 C CNN
F 4 "http://Arrow.com" H 6150 4025 50  0001 C CNN "Source"
F 5 "RC0603JR-1310KL" H 6150 4025 50  0001 C CNN "Part_number"
F 6 "14 Place then check work" H 6150 4025 50  0001 C CNN "ClickToSortForPlacement"
	1    6150 4025
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R8
U 1 1 5D899630
P 8050 4150
F 0 "R8" V 8150 4100 50  0000 L CNN
F 1 "15 KΩ" V 7950 4025 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8050 4150 50  0001 C CNN
F 3 "~" H 8050 4150 50  0001 C CNN
F 4 "http://Arrow.com" H 8050 4150 50  0001 C CNN "Source"
F 5 "RNCP0603FTD15K0" H 8050 4150 50  0001 C CNN "Part_number"
F 6 "14 Place. For best immunity from physical vibrations, ensure the ends make contact with copper trace itself rather than only to solder.   Then check work" H 8050 4150 50  0001 C CNN "ClickToSortForPlacement"
	1    8050 4150
	0    1    1    0   
$EndComp
$Comp
L Regulator_Linear:MCP1700-3002E_SOT23 U1
U 1 1 5DA5755D
P 3225 5050
F 0 "U1" H 3100 5175 50  0000 C CNN
F 1 "3V LDO" H 3325 5175 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3225 5275 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001826D.pdf" H 3225 5050 50  0001 C CNN
F 4 "http://Arrow.com" H 3225 5050 50  0001 C CNN "Source"
F 5 "18 Place then check work" H 3225 5050 50  0001 C CNN "ClickToSortForPlacement"
F 6 "MCP1700T-3002E/TT" H 3225 5050 50  0001 C CNN "Part_number"
	1    3225 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 5DADD1F4
P 3575 5150
F 0 "C7" H 3600 5075 50  0000 L CNN
F 1 "1uF" H 3600 5000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3575 5150 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/1f443eab4acf01f089a96c9291c2d9208a40ac8/nmchc.pdf" H 3575 5150 50  0001 C CNN
F 4 "C0603X105M4RACAUTO7411 or NMC0603Y5V105Z10TRPF or C0603C105K4PALTU or NMC0603X7R105K6.3TRPF" H 3575 5150 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 3575 5150 50  0001 C CNN "Source"
F 6 "09 Place, then check work" H 3575 5150 50  0001 C CNN "ClickToSortForPlacement"
	1    3575 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R4
U 1 1 5DB14AB4
P 3675 4950
F 0 "R4" H 3700 4850 50  0000 L CNN
F 1 "21 KΩ" H 3700 4775 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3675 4950 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/3cece72dd289ffbadc164fbcd05f638dd7240f7b/rc_datasheet_150330.pdf.pdf" H 3675 4950 50  0001 C CNN
F 4 "http://Arrow.com" H 3675 4950 50  0001 C CNN "Source"
F 5 "RC1608F2102CS" H 3675 4950 50  0001 C CNN "Part_number"
F 6 "09 Place, then check work" H 3675 4950 50  0001 C CNN "ClickToSortForPlacement"
	1    3675 4950
	1    0    0    -1  
$EndComp
NoConn ~ 3800 4850
Wire Wire Line
	9500 4000 9500 4325
Wire Wire Line
	9500 4000 10750 4000
$Comp
L uno-shield-v1.0-project-SMD-rescue:MCP4262-xxxE_UN-2019-03-19_09-09-09-uno-shield-v1.0-project-SMD-LM662-rescue U7
U 1 1 5C9A2EF5
P 9850 4575
F 0 "U7" H 10050 3675 60  0000 R CNN
F 1 "MCP4262-503E/UN" H 10450 3575 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 10395 5000 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 9860 4575 60  0001 C CNN
F 4 "01" H 5500 2675 50  0001 C CNN "PlacementOrder"
F 5 "01" H 5500 2675 50  0001 C CNN "SortForPlacement"
F 6 "12 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place.  For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  Temporary tack solder J2 with pin 5 only, J3 with pin 1, and J4 with pin 4 only.  Check for inadvertent shorts and opens." H 5500 2675 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-503E/UN" H 9850 4575 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 9850 4575 50  0001 C CNN "Source"
	1    9850 4575
	-1   0    0    1   
$EndComp
Text Label 10975 4425 2    50   ~ 0
U8-Pad5
Text Label 10975 4325 2    50   ~ 0
U8-Pad6
Wire Notes Line
	9525 4025 9525 4275
$Comp
L Reference_Current:REF200AU U4
U 1 1 5D0F9980
P 6150 3325
F 0 "U4" H 5775 3625 50  0000 L CNN
F 1 "REF200AU" H 5650 3525 50  0000 L CIN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 6025 3350 50  0001 R CIN
F 3 "www.ti.com/lit/ds/symlink/ref200.pdf" H 6450 3325 50  0001 C CIN
F 4 "http://Arrow.com" H 6150 3325 50  0001 C CNN "Source"
F 5 "REF200AU (Requires hermetic sealing, so will have dessicant with it that you'll need to place under SHLD1)" H 6150 3325 50  0001 C CNN "Part_number"
F 6 "26 Before opening this shipping package, perform as complete of diagnostics as possible of all circuitry under SHLD1 placed thus far: solder a shorting wire between pins 4 & 5 of U3 (mix & match with pins 1 of both Q1 and Q2) and load the Arduino with GWAAM-Sea Diagnostics 1 and run them.  Remove short between pins 4 and 5 of U3.  Then, from the bottom side of the board, solder seal any and all via holes left unsoldered located within SHLD1 footprint.  Solder seal any and all place-assist holes located within SHLD1 footprint except U3 place-assist holes.  All this should minimize risk of getting interrupted while U3 is left not heremetically sealed.  Tin SHLD1 around outside of bottom edge that will get soldered to its footprint.  Tin SHLD1 footprint on the board, leaving a very SMOOTH & FLAT surface to mate with SHLD1.  Prepare dessicant (trim pkg for edges to be bent over to fit inside SHLD1 holding like a pinch of the silica or clay granules & held in place by Kapton tape without putting pressure on other components) as soon as U3 is placed, and ensure SHLD1 is handy also.  Place U3 and perform diagnostics of U3.  After diags, solder-seal its place-assist holes.  Immediately perform next step." H 6150 3325 50  0001 C CNN "ClickToSortForPlacement"
	1    6150 3325
	1    0    0    -1  
$EndComp
Wire Wire Line
	22050 5050 22550 5050
Wire Wire Line
	22650 4725 21950 4725
Wire Wire Line
	21950 4725 21950 7800
Wire Wire Line
	22500 5500 22600 5500
Text Label 10200 4425 0    50   ~ 0
7
Text Label 11800 4425 0    50   ~ 0
8
Text Notes 6650 4825 0    50   ~ 0
      > Solute >\n(aka DUT mirrored current)
Text Notes 7950 4650 1    55   ~ 0
|<Solvent<\n
Text Notes 7700 5850 1    50   ~ 0
<  Solution  <
Text Notes 8050 5800 0    50   ~ 0
<Mirrored solution<
Text Notes 9000 5600 1    50   ~ 0
< Counter-Balancing   Solvent <\n
Text Notes 5775 7750 0    70   Italic 14
NOTE THE ABOVE UNUSUAL USE OF, AND DISTINCTION BETWEEN CHEMISTRY TERMS \n"SOLUTE", "SOLVENT", AND "SOLUTION" ANALOGOUSLY APPLIED TO ELECTRICAL CURRENT
Wire Wire Line
	6200 4950 6200 12000
Connection ~ 6200 4950
Wire Notes Line
	8275 4100 8275 4750
Wire Wire Line
	7975 3950 7975 3900
Wire Notes Line
	9375 4125 9375 4450
Wire Wire Line
	8350 3900 8350 4675
Wire Wire Line
	8150 4150 8250 4150
Wire Wire Line
	8250 4150 8250 4775
Wire Wire Line
	9500 5225 10975 5225
Wire Wire Line
	11675 4575 11975 4575
Wire Wire Line
	11675 4775 11725 4775
Wire Wire Line
	11800 4425 11800 7800
Wire Wire Line
	11800 7800 21950 7800
Wire Wire Line
	10350 4425 10350 5475
Wire Wire Line
	11725 7875 22050 7875
Wire Wire Line
	10200 4775 10200 5675
Wire Wire Line
	10250 4575 10250 5625
Wire Wire Line
	11725 5475 10350 5475
Wire Wire Line
	11725 5475 11725 7875
Wire Notes Line
	9050 3925 10975 3925
Wire Notes Line
	8900 4075 8900 4250
Wire Notes Line
	9525 5200 10850 5200
Wire Notes Line
	9425 5350 11000 5350
Wire Notes Line
	9525 4025 10725 4025
Wire Wire Line
	6275 4750 6275 3925
Wire Wire Line
	6200 12000 9400 12000
Text Notes 6500 6250 0    65   ~ 0
        Solution Mirror\nMax current rating: \n     3 to 4 mA
Text Notes 7775 7125 0    60   ~ 0
         Signal Forming High-Z node - The signal on A0 is formed by the \n        electromotively forced exit, if you will, of the mirrored solute current \n        (aka "twice-mirrored DUT current") by the Solution Mirror against the \n        node's attached impedances.  The higher those and previous signal \n        path impedances remain, the better signal EMF is generated by said \n        current, so keep this area clean and guarded with 3rd stage guard trace.  \n        The perfectionist will consider doing away with guard rings in favor of \n        using air-travel wires and leads for the current signal path - see pg 11 \n        TI LMC662 datasheet SNOSC51C – APRIL 1998 – REVISED MARCH 2013
Text Notes 8575 6150 0    50   ~ 0
Mirrored solute, having its DC component \nnulled by the counter-balancing solvent \nstage, is transformed into the signal of interest
Wire Wire Line
	9400 4150 9400 4425
Wire Wire Line
	9400 4425 9500 4425
Wire Wire Line
	8875 4150 9325 4150
Wire Notes Line
	8900 4125 9375 4125
Wire Notes Line
	9375 4450 9575 4450
Connection ~ 7775 4650
Text Label 13175 4425 2    60   ~ 0
A1
Wire Notes Line
	7750 4475 7750 5850
Text Notes 17000 8450 0    70   ~ 0
Construction diagnostics may use one of \nthese VRs for solute dilution control or \nother purposes
Wire Wire Line
	10250 5625 11975 5625
Wire Wire Line
	11975 5625 11975 7625
Wire Wire Line
	10200 5675 11900 5675
Wire Wire Line
	7975 3900 8350 3900
Wire Notes Line
	7800 4075 7800 4225
Wire Notes Line
	8375 3925 8000 3925
Wire Notes Line
	8225 4125 7800 4125
Wire Notes Line
	8325 4700 9600 4700
Wire Notes Line
	8375 3875 8375 4700
Wire Notes Line
	8225 4750 9450 4750
Wire Wire Line
	8075 5850 8875 5850
Wire Wire Line
	8250 4775 9400 4775
Wire Wire Line
	8350 4675 9500 4675
Text Notes 7800 5550 0    50   ~ 0
For optimal LM334 \nperformance, inject \nsolvent until solution = 2 \nor 3 µA.  Beyond that, \nsignal dilutes unnecessarily \nunless the diluted effect is \ndesired.  Solvent total is \nlimited to about 4 µA \nby R8
Text Notes 8175 6250 0    50   ~ 0
Counter-Balancing Solvent total is limited by U4C to Solution total
Text Notes 6600 5100 0    50   ~ 0
Solute total is limited to \n750 µA by R3 + R1, and \nagain to 3.69 mA by R5
Text Notes 9050 5500 0    50   ~ 0
Sets DC \nlevel at \nA0 to \ntrack \noutboard \nADC's \nreference input \non A1.
Wire Wire Line
	3575 3925 3150 3925
Wire Wire Line
	3575 3925 3575 5050
Wire Wire Line
	15050 7200 15050 7350
Connection ~ 14550 7300
Wire Wire Line
	14550 7300 14850 7300
Text Label 21150 1900 2    60   ~ 0
A7
Wire Wire Line
	21075 4150 21250 4150
Wire Wire Line
	8575 3750 8575 2875
Wire Wire Line
	8575 2875 14150 2875
Wire Wire Line
	6400 2875 6400 4850
Wire Wire Line
	7475 3750 7475 2875
Connection ~ 7475 2875
Wire Wire Line
	7475 2875 7975 2875
Wire Wire Line
	15050 7350 15650 7350
Wire Wire Line
	15650 7100 15650 7350
Wire Wire Line
	14850 7100 14850 7075
Wire Wire Line
	14400 7075 14550 7075
Connection ~ 14550 7075
Wire Wire Line
	14550 7075 14550 7100
Connection ~ 14850 7075
Wire Wire Line
	14850 7075 14850 7000
Wire Wire Line
	11900 5675 11900 7700
Connection ~ 11900 5675
Connection ~ 11975 5625
$Comp
L power:GNDA #PWR017
U 1 1 600B421C
P 12775 3800
F 0 "#PWR017" H 12775 3550 50  0001 C CNN
F 1 "GNDA" H 12925 3675 50  0000 C CNN
F 2 "" H 12775 3800 50  0001 C CNN
F 3 "" H 12775 3800 50  0001 C CNN
	1    12775 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	12775 3800 12700 3800
Wire Wire Line
	12700 3800 12700 3925
Wire Wire Line
	12700 3925 12625 3925
$Comp
L uno-shield-v1.0-project-SMD-rescue:MCP4262-xxxE_UN-2019-03-19_09-09-09-uno-shield-v1.0-project-SMD-LM662-rescue U34
U 1 1 60107CA8
P 13775 4925
F 0 "U34" H 13850 4325 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 14150 4425 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 14320 5350 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 13785 4925 60  0001 R CNN
F 4 "15 Since solder paste template is correct only while the U7 cut-away is still attached, tinning and placing may need to be done then.  Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place.  For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  Then check work for inadvertent shorts and opens" H 8175 3025 50  0001 C CNN "ClickToSortForPlacement"
F 5 "MCP4262-502E/UN" H 13775 4925 50  0001 C CNN "Part_number"
F 6 "http://digikey.com" H 13775 4925 50  0001 C CNN "Source"
	1    13775 4925
	-1   0    0    1   
$EndComp
$Comp
L power:GNDD #PWR0164
U 1 1 60127E63
P 13775 5325
F 0 "#PWR0164" H 13775 5075 50  0001 C CNN
F 1 "GNDD" V 13775 5100 50  0000 C CNN
F 2 "" H 13775 5325 50  0001 C CNN
F 3 "" H 13775 5325 50  0001 C CNN
	1    13775 5325
	0    -1   -1   0   
$EndComp
Connection ~ 14150 2875
Wire Wire Line
	17425 4250 17425 7625
Wire Wire Line
	11975 7625 17425 7625
Wire Wire Line
	17550 4550 17550 7700
Wire Wire Line
	11900 7700 17550 7700
Wire Wire Line
	14275 4775 14275 6175
Wire Wire Line
	14275 6175 17750 6175
Wire Wire Line
	17750 6175 17750 7700
Wire Wire Line
	17750 7700 21875 7700
Wire Wire Line
	21875 7700 21875 3400
Wire Wire Line
	21875 3400 22700 3400
Wire Wire Line
	22700 3400 22700 1900
Wire Wire Line
	22700 1900 21900 1900
Text Label 22200 1900 0    50   ~ 0
9(**)
Text Label 14125 4775 0    50   ~ 0
9(**)
NoConn ~ 14125 5025
Connection ~ 8575 2875
Text Notes 12350 5350 0    50   ~ 0
U36 pins 5 & 8 are \ninterchangeable \nuntil sketch is written
Wire Wire Line
	12425 3525 12350 3525
$Comp
L Device:C_Small C8
U 1 1 60536096
P 12925 4900
F 0 "C8" V 12925 4650 50  0000 L CNN
F 1 "10-51 pF" V 12850 4450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 12925 4900 50  0001 C CNN
F 3 "~" H 12925 4900 50  0001 C CNN
F 4 "choose from NMC-L0603NPO200J50TRPF, NMC0603NPO240F50TRPF, NMC0603NPO510J50TRPF, 101R14N330GV4T, et. al." V 12925 4900 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" V 12925 4900 50  0001 C CNN "Source"
F 6 "14 Place then check work as before" H 12925 4900 50  0001 C CNN "ClickToSortForPlacement"
	1    12925 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	14850 2300 21150 2300
Wire Wire Line
	14750 2200 21150 2200
Wire Wire Line
	15750 7100 15650 7100
Wire Wire Line
	12350 3725 12425 3725
Wire Wire Line
	14750 2200 14750 3625
Text Label 13025 3625 0    60   ~ 0
A0
$Comp
L Device:C_Small C10
U 1 1 609B9800
P 12725 3325
F 0 "C10" V 12625 3250 50  0000 L CNN
F 1 ".022 µF" V 12825 3225 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 12725 3325 50  0001 C CNN
F 3 "~" H 12725 3325 50  0001 C CNN
F 4 "GRM1887U1A223JA01D" V 12725 3325 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" V 12725 3325 50  0001 C CNN "Source"
F 6 "14 Place then check work as before" H 12725 3325 50  0001 C CNN "ClickToSortForPlacement"
	1    12725 3325
	0    1    1    0   
$EndComp
$Comp
L power:GNDA #PWR0166
U 1 1 609BAB90
P 12825 3325
F 0 "#PWR0166" H 12825 3075 50  0001 C CNN
F 1 "GNDA" V 12925 3175 50  0000 C CNN
F 2 "" H 12825 3325 50  0001 C CNN
F 3 "" H 12825 3325 50  0001 C CNN
	1    12825 3325
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6150 3025 6150 2875
Wire Wire Line
	6150 3625 6150 3925
Connection ~ 7475 3750
Connection ~ 8575 3750
Wire Wire Line
	14150 3125 14150 3175
Wire Wire Line
	14150 3175 14325 3175
Connection ~ 14325 3175
Connection ~ 6400 4850
Wire Wire Line
	14125 4775 14275 4775
Wire Wire Line
	14125 4925 14225 4925
Wire Wire Line
	14225 4925 14225 5450
Connection ~ 11975 5450
Wire Wire Line
	11975 5450 11975 5625
Wire Wire Line
	11975 4575 11975 5450
Wire Wire Line
	11975 5450 14225 5450
Wire Wire Line
	14125 5125 14125 5400
Connection ~ 11900 5400
Wire Wire Line
	11900 5400 11900 5675
Wire Wire Line
	11900 4775 11900 5400
Wire Wire Line
	11900 5400 14125 5400
Wire Wire Line
	12825 4900 12825 5025
Wire Wire Line
	13025 4900 13025 4425
Connection ~ 13025 4425
Connection ~ 12825 5025
Wire Wire Line
	14550 7075 14850 7075
Wire Wire Line
	12425 4325 12350 4325
Wire Wire Line
	13025 4900 13025 5125
Wire Wire Line
	13025 5125 13250 5125
Connection ~ 13025 4900
Wire Wire Line
	13400 4775 13425 4775
Text Notes 13200 3775 0    20   ~ 0
U34 important parameters are very low input \nV-offset, unity gain stable, RRIO, low input I-bias or \nZCO, min. 3Vdc - 5.5 Vdc operation
Wire Wire Line
	14850 2300 14850 3850
Connection ~ 15650 7100
$Comp
L Device:C_Small C9
U 1 1 5E2A37DE
P 12925 5625
F 0 "C9" V 12975 5475 50  0000 L CNN
F 1 ".022 µF" V 13050 5450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 12925 5625 50  0001 C CNN
F 3 "~" H 12925 5625 50  0001 C CNN
F 4 "GRM1887U1A223JA01D" V 12925 5625 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" V 12925 5625 50  0001 C CNN "Source"
F 6 "14 Place then check work as before" H 12925 5625 50  0001 C CNN "ClickToSortForPlacement"
	1    12925 5625
	0    1    1    0   
$EndComp
$Comp
L power:GNDA #PWR012
U 1 1 5E2A5689
P 13025 5625
F 0 "#PWR012" H 13025 5375 50  0001 C CNN
F 1 "GNDA" V 13050 5425 50  0000 C CNN
F 2 "" H 13025 5625 50  0001 C CNN
F 3 "" H 13025 5625 50  0001 C CNN
	1    13025 5625
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDA #PWR09
U 1 1 5E2A74AF
P 12575 6700
F 0 "#PWR09" H 12575 6450 50  0001 C CNN
F 1 "GNDA" H 12725 6575 50  0000 C CNN
F 2 "" H 12575 6700 50  0001 C CNN
F 3 "" H 12575 6700 50  0001 C CNN
	1    12575 6700
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LTC6081xMS8 U35
U 1 1 6000B34C
P 12725 3625
F 0 "U35" H 13000 3575 50  0000 C CNN
F 1 "OPA2388IDGKR" H 12975 3500 50  0000 C CNN
F 2 "Package_SO:VSSOP-8_3.0x3.0mm_P0.65mm" H 12725 3625 50  0001 C CNN
F 3 "http://www.ti.com/document-viewer/OPA2388/datasheet" H 12725 3625 50  0001 C CNN
F 4 "OPA2388IDGKR" H 12725 3625 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 12725 3625 50  0001 C CNN "Source"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  " H 12725 3625 50  0001 C CNN "ClickToSortForPlacement"
	1    12725 3625
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LTC6081xMS8 U35
U 2 1 6000CFD7
P 12725 4425
F 0 "U35" H 12925 4350 50  0000 C CNN
F 1 "OPA2388IDGKR" H 12850 4250 50  0000 C CNN
F 2 "Package_SO:VSSOP-8_3.0x3.0mm_P0.65mm" H 12725 4425 50  0001 C CNN
F 3 "http://www.ti.com/document-viewer/OPA2388/datasheet" H 12725 4425 50  0001 C CNN
F 4 "OPA2388IDGKR" H 12725 4425 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 12725 4425 50  0001 C CNN "Source"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  " H 12725 4425 50  0001 C CNN "ClickToSortForPlacement"
	2    12725 4425
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LTC6081xMS8 U2
U 1 1 5E295E77
P 12675 6175
F 0 "U2" H 12850 6075 50  0000 C CNN
F 1 "OPA2388IDGKR" H 12800 6000 50  0000 C CNN
F 2 "Package_SO:VSSOP-8_3.0x3.0mm_P0.65mm" H 12675 6175 50  0001 C CNN
F 3 "http://www.ti.com/document-viewer/OPA2388/datasheet" H 12675 6175 50  0001 C CNN
F 4 "OPA2388IDGKR" H 12675 6175 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 12675 6175 50  0001 C CNN "Source"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  " H 12675 6175 50  0001 C CNN "ClickToSortForPlacement"
	1    12675 6175
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LTC6081xMS8 U2
U 2 1 5E29AE5A
P 15350 7100
F 0 "U2" H 15550 7025 50  0000 C CNN
F 1 "OPA2388IDGKR" H 15475 6925 50  0000 C CNN
F 2 "Package_SO:VSSOP-8_3.0x3.0mm_P0.65mm" H 15350 7100 50  0001 C CNN
F 3 "http://www.ti.com/document-viewer/OPA2388/datasheet" H 15350 7100 50  0001 C CNN
F 4 "OPA2388IDGKR" H 15350 7100 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 15350 7100 50  0001 C CNN "Source"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  " H 15350 7100 50  0001 C CNN "ClickToSortForPlacement"
	2    15350 7100
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LTC6081xMS8 U2
U 3 1 5E2FAFC1
P 12675 6175
F 0 "U2" H 12850 6075 50  0001 C CNN
F 1 "OPA2388IDGKR" H 12800 6000 50  0000 C CNN
F 2 "Package_SO:VSSOP-8_3.0x3.0mm_P0.65mm" H 12675 6175 50  0001 C CNN
F 3 "http://www.ti.com/document-viewer/OPA2388/datasheet" H 12675 6175 50  0001 C CNN
F 4 "OPA2388IDGKR" H 12675 6175 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 12675 6175 50  0001 C CNN "Source"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  " H 12675 6175 50  0001 C CNN "ClickToSortForPlacement"
	3    12675 6175
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LTC6081xMS8 U35
U 3 1 5E338B6D
P 12725 3625
F 0 "U35" H 13000 3575 50  0001 C CNN
F 1 "OPA2388IDGKR" H 12925 3500 50  0001 C CNN
F 2 "Package_SO:VSSOP-8_3.0x3.0mm_P0.65mm" H 12725 3625 50  0001 C CNN
F 3 "http://www.ti.com/document-viewer/OPA2388/datasheet" H 12725 3625 50  0001 C CNN
F 4 "OPA2388IDGKR" H 12725 3625 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 12725 3625 50  0001 C CNN "Source"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  " H 12725 3625 50  0001 C CNN "ClickToSortForPlacement"
	3    12725 3625
	1    0    0    -1  
$EndComp
NoConn ~ 21150 1500
Text Label 21150 1400 2    50   ~ 0
+3.3V
$Comp
L power:+3.3V #PWR0114
U 1 1 5EBC144C
P 2925 4900
F 0 "#PWR0114" H 2925 4750 50  0001 C CNN
F 1 "+3.3V" H 2950 5050 50  0001 C CNN
F 2 "" H 2925 4900 50  0001 C CNN
F 3 "" H 2925 4900 50  0001 C CNN
	1    2925 4900
	1    0    0    -1  
$EndComp
Text Label 2925 4900 2    50   ~ 0
+3.3V
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5EBC57F0
P 21150 1400
F 0 "#FLG0103" H 21150 1475 50  0001 C CNN
F 1 "PWR_FLAG" V 21150 1528 50  0001 L CNN
F 2 "" H 21150 1400 50  0001 C CNN
F 3 "~" H 21150 1400 50  0001 C CNN
	1    21150 1400
	0    -1   -1   0   
$EndComp
$Sheet
S 11750 900  875  150 
U 5EFC5A04
F0 "Quantum_MCP4262-502_25x_expansion_new_flex_for_GWAAM-Sea_Aid" 50
F1 "Quantum MCP4262-502 25x expansion new flex for GWAAM-Sea Aid.sch" 50
$EndSheet
Text Label 1475 4925 0    50   ~ 0
J5-PadR
Text Label 2000 4725 0    50   ~ 0
J5-PadR
Text Label 2000 4900 0    50   ~ 0
J5-PadT
Text Label 1475 4725 0    50   ~ 0
J5-PadT
Text Label 1475 5025 0    50   ~ 0
J5-PadS
Text Label 2000 5025 0    50   ~ 0
J5-PadS
Wire Wire Line
	3700 4750 3800 4750
Wire Notes Line
	12150 3150 12150 5475
Wire Notes Line
	12150 5475 14300 5475
Wire Notes Line
	11825 3150 12150 3150
Text Notes 13825 2475 0    60   Italic 12
These components need not \nbe located under shield
Wire Notes Line
	11825 2250 11825 3150
Wire Notes Line
	14250 5475 14250 6275
Wire Notes Line
	14300 6275 16600 6275
Wire Notes Line
	16600 6275 16600 2250
Wire Notes Line
	13825 2250 13825 2500
Wire Notes Line
	13825 2500 15150 2500
Wire Notes Line
	15150 2500 15150 2250
Wire Notes Line
	11825 2250 16600 2250
Text Notes 9825 11075 0    60   Italic 12
These components need not \nbe located under shield
Text Notes 18975 9525 0    60   Italic 12
These components need not \nbe located under shield
Connection ~ 8875 4150
$Comp
L uno-shield-v1.0-project-SMD-rescue:LM334M-lm334m-uno-shield-v1.0-project-SMD-LM662-rescue U6
U 1 1 5CDCF5D4
P 8875 3950
F 0 "U6" H 8925 4225 50  0000 R CNN
F 1 "LM334M" H 9025 4325 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8900 3800 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 8875 3950 50  0001 C CIN
F 4 "LM334M/NOPB" H 8875 3950 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 8875 3950 50  0001 C CNN "Source"
F 6 "23 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Before placing, run the diags that use the ohmmeter.  Place then check work, you may allow up to three of pins 5-8 to fly free since none of them have electrical connection.  Place short between pins 2 and 5 of U4 and place 1.5 MOhm from Q2 pins 1 & 2 to GND.  For best immunity from physical vibrations, ensure U5 and U6 leads 1,2, and 4 make contact with copper trace itself rather than only to solder.  Place a short between pins 1 & 2 of Q1. Make sure the added shorts cannot get bumped so to lift the pads they attach to.  Run diags.  Remove shorts on Q1 and Q2." H 8875 3950 50  0001 C CNN "ClickToSortForPlacement"
	1    8875 3950
	1    0    0    -1  
$EndComp
$Comp
L uno-shield-v1.0-project-SMD-rescue:LM334M-lm334m-uno-shield-v1.0-project-SMD-LM662-rescue U5
U 1 1 5CDCE965
P 7775 3950
F 0 "U5" H 7825 4225 50  0000 R CNN
F 1 "LM334M" H 7925 4325 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7800 3800 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 7775 3950 50  0001 C CIN
F 4 "LM334M/NOPB" H 7775 3950 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 7775 3950 50  0001 C CNN "Source"
F 6 "23 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Before placing, run the diags that use the ohmmeter.  Place then check work, you may allow up to three of pins 5-8 to fly free since none of them have electrical connection.  Place short between pins 2 and 5 of U4 and place 1.5 MOhm from Q2 pins 1 & 2 to GND.  For best immunity from physical vibrations, ensure U5 and U6 leads 1,2, and 4 make contact with copper trace itself rather than only to solder.  Place a short between pins 1 & 2 of Q1. Make sure the added shorts cannot get bumped so to lift the pads they attach to.  Run diags.  Remove shorts on Q1 and Q2." H 7775 3950 50  0001 C CNN "ClickToSortForPlacement"
	1    7775 3950
	1    0    0    -1  
$EndComp
$Comp
L Reference_Current:LM334Z U41
U 1 1 5E18A526
P 19725 11525
F 0 "U41" H 19595 11571 50  0000 R CNN
F 1 "LM334Z-LFT1" H 19595 11480 50  0000 R CNN
F 2 "multipackage:TO-92_Spread_for_LM334Z" H 19750 11350 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 19725 11525 50  0001 C CIN
F 4 "LM334Z/LFT1" H 19725 11525 50  0001 C CNN "Part_number"
F 5 "http://digikey.com Two components needed" H 19725 11525 50  0001 C CNN "Source"
F 6 "01 " H 19725 11525 50  0001 C CNN "ClickToSortForPlacement"
	1    19725 11525
	1    0    0    -1  
$EndComp
Wire Wire Line
	19725 11725 19925 11725
$Comp
L power:GNDA #PWR019
U 1 1 5E1F7DD3
P 16750 12025
F 0 "#PWR019" H 16750 11775 50  0001 C CNN
F 1 "GNDA" H 16755 11852 50  0000 C CNN
F 2 "" H 16750 12025 50  0001 C CNN
F 3 "" H 16750 12025 50  0001 C CNN
	1    16750 12025
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR020
U 1 1 5E1F917A
P 19925 11925
F 0 "#PWR020" H 19925 11675 50  0001 C CNN
F 1 "GNDA" H 19930 11752 50  0000 C CNN
F 2 "" H 19925 11925 50  0001 C CNN
F 3 "" H 19925 11925 50  0001 C CNN
	1    19925 11925
	1    0    0    -1  
$EndComp
Text Label 16500 11925 2    60   ~ 0
A6
Text Label 19700 11825 2    60   ~ 0
A7
Wire Wire Line
	19700 11825 19725 11825
Wire Wire Line
	19725 11825 19725 11725
Connection ~ 19725 11725
Text Notes 15850 12025 0    50   ~ 0
Developer-user 1
Text Notes 19600 12325 0    50   ~ 0
Developer-user 2
Text Notes 16950 12625 0    60   ~ 12
These LM334 components, attached or not to flexible \n3-wire ribbon cables, not depicted, MUST be located under \nshields to monitor the temperature of the two most \ntemperature-sensitive components, yet TBA.  Ensure \nintimate thermal contact for useful results.  Distribute \nactive devices among shields during R & D phase, accommodate both \ndevices by laying footprints being under each shield for possible future use.
Text Notes 19450 10925 0    80   ~ 0
A6/A7, if present on MCU, are best used with \nU40 and U41 for software temperature \ncompensating based on the temperature of \nwhatever two most temperature sensitive \ncomponents, which are yet TBA, are under the \nshield[s].  Alternately, one or both may be \nused with VR3/VR4.  Ensure that only one of \nthose options is connected to A6/A7.  
$Comp
L Device:R_Small_US R17
U 1 1 5E2C16A1
P 19925 11625
F 0 "R17" H 19993 11671 50  0000 L CNN
F 1 "14.7 KΩ  0.1% 0.063W ±25ppm/°C (NTR06B1472CTRF)" H 19993 11580 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 19925 11625 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/669b41e07e7b791c3fd809a54c1187fadb989b67/697940354256393ntr.pdf" H 19925 11625 50  0001 C CNN
F 4 "http://Arrow.com Order two: R15 & R17" H 19925 11625 50  0001 C CNN "Source"
F 5 "NTR06B1472CTRF" H 19925 11625 50  0001 C CNN "Part_number"
F 6 "01 " H 19925 11625 50  0001 C CNN "ClickToSortForPlacement"
	1    19925 11625
	1    0    0    -1  
$EndComp
Connection ~ 19925 11725
$Comp
L Device:R_Small_US R16
U 1 1 5E1B253A
P 16750 11925
F 0 "R16" H 16800 11875 50  0000 L CNN
F 1 "390 KΩ 0.1% 0.063W ±25ppm/°C (CPF0603B390KE1)" H 16800 12000 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 16750 11925 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/a97c085df217e1ed86a021becbd4caec4d5559d7/817849869510639817842178598239eng_ds_1773200_g.pdf" H 16750 11925 50  0001 C CNN
F 4 "http://Arrow.com" H 16750 11925 50  0001 C CNN "Source"
F 5 "CPF0603B390KE1" H 16750 11925 50  0001 C CNN "Part_number"
F 6 "01 " H 16750 11925 50  0001 C CNN "ClickToSortForPlacement"
	1    16750 11925
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R18
U 1 1 5E2C6E26
P 19925 11825
F 0 "R18" H 19993 11871 50  0000 L CNN
F 1 "390 KΩ 0.1% 0.063W ±25ppm/°C (CPF0603B390KE1)" H 19993 11780 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 19925 11825 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/a97c085df217e1ed86a021becbd4caec4d5559d7/817849869510639817842178598239eng_ds_1773200_g.pdf" H 19925 11825 50  0001 C CNN
F 4 "http://Arrow.com" H 19925 11825 50  0001 C CNN "Source"
F 5 "CPF0603B390KE1" H 19925 11825 50  0001 C CNN "Part_number"
F 6 "01 " H 19925 11825 50  0001 C CNN "ClickToSortForPlacement"
	1    19925 11825
	1    0    0    -1  
$EndComp
Text Notes 17200 11325 0    50   ~ 0
A6,A7 = 1.796 VDC @ 25°C = 367.8 steps analog @ 5Vdc\nTempCo @ 5Vdc= +1.35 steps/°C = +3.27 steps/°F\nTempCo @ 3.3Vdc= +2.04 steps/°C = +5 steps/°F
Wire Notes Line
	2500 4600 2500 4750
Wire Notes Line
	2500 4600 4075 4600
Wire Notes Line
	2025 4750 2500 4750
Wire Wire Line
	2475 4725 2475 4650
Wire Wire Line
	2475 4650 3250 4650
Wire Wire Line
	2350 5025 2350 5350
Wire Wire Line
	2000 5025 2350 5025
Wire Notes Line
	2425 4925 2425 5150
Wire Notes Line
	2425 5150 2500 5150
Wire Notes Line
	2000 4925 2425 4925
Wire Notes Line
	2000 5025 1475 5025
Wire Wire Line
	2000 4725 1475 4925
Wire Wire Line
	2000 4725 2475 4725
Wire Wire Line
	2000 4900 2500 4900
Wire Wire Line
	1475 4725 2000 4900
Text Notes 8800 4225 0    50   ~ 0
S
Text Notes 8650 4325 0    50   ~ 0
G
Text Notes 8800 4650 0    50   ~ 0
D
Text Notes 7700 4225 0    50   ~ 0
S
Text Notes 7550 4325 0    50   ~ 0
G
Text Notes 7675 4550 0    50   ~ 0
D
Text Notes 8225 2825 0    60   ~ 0
NOTE: Operation currently at +3.3V is a lttle \nsickly, likely due to the following note.\n\nNOTE FOR 3.3V OPERATION - In 3.3V operation, \nthe voltage drop that Q2 adds for the sake of\nhighest output impedance against U4C might not \nallow 3.3V operation with an outboard ADC.  If \nthat is found to be the case, that JFET may be \nshorted across D to S with the expected result to \nbe reduced signal formation.\n\nMMBF5460 (2N5460) NOTE:   Q1 contributes \nnothing to functionality except to permit using the \nsame voltage guard trace for both U7 and U8-33 \nsince they are co-located, distant from other guard \ntraces, and their guard trace weaves between board \nsides leaving no room for another.
Text Notes 6875 7400 0    60   ~ 0
NOTE: A flex/aux board solely for the guarded signal path is also a sensible feature.\nNOTE: The direction/size of U2A I-bias could significantly affect LSB stepping.
Wire Wire Line
	15050 7000 14850 7000
Wire Wire Line
	11625 5850 8875 5850
Wire Wire Line
	12825 5625 12575 5625
Wire Wire Line
	12575 5875 12575 5625
Text Notes 575  5875 0    60   ~ 12
Securely immobilize DUT \ncable to reduce \npiezoelectric and \ntriboelectric effects
Connection ~ 8875 5850
Wire Wire Line
	14400 7025 14400 7075
Wire Wire Line
	8875 4550 8875 4825
Connection ~ 3575 5450
Wire Wire Line
	2350 5350 2500 5350
Wire Wire Line
	2500 5100 2500 5350
Connection ~ 2500 5350
Wire Wire Line
	2500 5350 2500 5450
Wire Wire Line
	4875 5250 5000 5450
Wire Wire Line
	5000 6450 7775 6450
Wire Wire Line
	3800 5000 4050 5000
Wire Wire Line
	4050 5000 4050 5250
Wire Wire Line
	4050 5250 4875 5250
Wire Wire Line
	3675 5050 3575 5050
Wire Wire Line
	3675 4850 3675 4750
Wire Wire Line
	3675 4750 3700 4750
Connection ~ 3700 4750
Wire Wire Line
	2975 4325 2825 4325
$Comp
L Device:R_Small_US R2
U 1 1 5CE335C5
P 3075 4325
F 0 "R2" V 3150 4250 50  0000 L CNN
F 1 "100 Ω" V 3000 4275 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3075 4325 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/92767ba402f81f7b2b89a2bb7df37eaf75b9d9b4/sei-rmcf_rmcp.pdf" H 3075 4325 50  0001 C CNN
F 4 "http://Arrow.com" H 3075 4325 50  0001 C CNN "Source"
F 5 "RMCF0603FT100R" H 3075 4325 50  0001 C CNN "Part_number"
F 6 "04 Place then check work as before" H 3075 4325 50  0001 C CNN "ClickToSortForPlacement"
	1    3075 4325
	0    1    1    0   
$EndComp
Wire Wire Line
	3175 4325 3250 4325
Wire Wire Line
	3150 3725 3050 3625
Connection ~ 3150 3725
Wire Wire Line
	17425 4250 20575 4250
Text Notes 11825 2350 0    50   ~ 0
This box not depicted as a guard ring
Wire Wire Line
	12575 6475 12575 6700
Text Notes 2250 11825 0    60   ~ 0
More info may be read from \n"Counting Electrons:\nMaking Ultra-high Sensitivity\nFemtoamp Measurements"\nauthored by Vicki Wong,\npublished by Analog Devices
Text Notes 12025 3025 0    50   ~ 0
Possible U2,U35 alternatives to investigate \n(single or dual device numbering listed, but \nonly the dual version would be drop-in): \nOPA388 (best) OPA320 OPA325 OPA369 \nTLV369  ADA4500-2 AD8572 MAX44290\nMAX44263 MAX9618\n[ADA4505-2 AD8505 AD8506 AD8508\nAD8236-NO (yucky input offset voltage)]
Connection ~ 13400 4775
Text Notes 12230 4595 1    50   ~ 0
This box not depicted as a guard ring
Text Notes 16375 6250 2    50   ~ 0
This box not depicted as a guard ring
Text Notes 16575 2825 3    50   ~ 0
This box not depicted as a guard ring
Wire Wire Line
	13025 3625 13175 3625
Wire Wire Line
	12975 6175 13400 6175
Wire Wire Line
	13400 4775 13400 5825
Wire Wire Line
	12375 6275 12075 6275
Wire Wire Line
	11625 6275 11625 5850
Wire Notes Line
	11575 6325 12425 6325
Wire Notes Line
	12425 6325 12425 6300
Wire Notes Line
	11575 5900 8100 5900
Wire Notes Line
	11575 5900 11575 6325
Wire Notes Line
	8900 4475 8900 5900
Wire Wire Line
	12375 6075 12375 5825
Wire Wire Line
	12375 5825 13400 5825
Connection ~ 13400 5825
Wire Wire Line
	13400 5825 13400 6175
Wire Wire Line
	12350 4025 13400 4025
Wire Wire Line
	12350 3725 12350 4025
Wire Wire Line
	13400 4025 13400 4775
Wire Wire Line
	12425 4525 12350 4525
Wire Wire Line
	12350 4525 12350 5025
Wire Wire Line
	12350 5025 12825 5025
Wire Wire Line
	12350 3525 12350 3125
Wire Wire Line
	13275 3850 13275 4425
Wire Wire Line
	13275 4425 13025 4425
Wire Wire Line
	13275 3850 14850 3850
Wire Wire Line
	13200 4675 13200 5025
Wire Wire Line
	13200 4675 13425 4675
Connection ~ 13200 5025
Wire Wire Line
	13200 5025 13425 5025
Wire Wire Line
	12825 5025 13200 5025
Text Notes 13025 6600 0    20   ~ 0
U2 important parameters are extremely low \ninput I-bias, unity gain stable, very low input \nV-offset, zero input crossover distortion \n(Zero-Crossover, ZCO: free from input bias \ncurrent non-linearity), RRO, no lock-up RRI, \nmin. 3Vdc - 5.5 Vdc operation.\nZCO admittedly would not be required of an \ninverting stage (transimpedance), but that \nwould be far too limiting on the dynamic range \nsince dPots for Rf aren't available in the GΩ range.\nWide dynamic range is critical in this product \nfor it to be relevant in non-laboratory environments.
$Comp
L Device:RF_Shield_One_Piece SHLD1
U 1 1 5D39733F
P 1275 6900
F 0 "SHLD1" H 1175 7375 50  0000 L CNN
F 1 "MS263-20C (cover only of MS263-20)" H 625 7275 50  0000 L CNN
F 2 "multipackage:Masach_Tech_MS26320_26x19.50mm" H 1275 6800 50  0001 C CNN
F 3 "https://www.masach.com/rf-shield-ms263-20-emi-shielded-can.html" H 1275 6800 50  0001 C CNN
F 4 "MS263-20 (will use only the cover to keep hermetic sealed)" H 1275 6900 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 1275 6900 50  0001 C CNN "Source"
F 6 "27  Verify every place-assist hole inside shield footprint is sealed and take one last opportunity to ensure all other holes there as well are fully sealed against air travel.  Thoroughly solder in place with dessicant inside using bismuth solder if you have it for easiest removal." H 1275 6900 50  0001 C CNN "ClickToSortForPlacement"
	1    1275 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:RF_Shield_One_Piece SHLD2
U 1 1 5F0D2397
P 2925 6900
F 0 "SHLD2" H 2825 7350 50  0000 L CNN
F 1 "MS263-20C (cover only of MS263-20)" H 2250 7275 50  0000 L CNN
F 2 "multipackage:Masach_Tech_MS26320_26x19.50mm" H 2925 6800 50  0001 C CNN
F 3 "https://www.masach.com/rf-shield-ms263-20-emi-shielded-can.html" H 2925 6800 50  0001 C CNN
F 4 "MS263-20 (will use only the cover to keep hermetic sealed)" H 2925 6900 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 2925 6900 50  0001 C CNN "Source"
F 6 "27  Verify every place-assist hole inside shield footprint is sealed and take one last opportunity to ensure all other holes there as well are fully sealed against air travel.  Thoroughly solder in place with dessicant inside using bismuth solder if you have it for easiest removal." H 2925 6900 50  0001 C CNN "ClickToSortForPlacement"
	1    2925 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:RF_Shield_One_Piece SHLD3
U 1 1 5F20A334
P 4525 6900
F 0 "SHLD3" H 4425 7350 50  0000 L CNN
F 1 "MS544-10C (cover only of MS544-10)" H 3850 7275 50  0000 L CNN
F 2 "multipackage:Masach_Tech_MS54410_54x23.90mm" H 4525 6800 50  0001 C CNN
F 3 "https://www.masach.com/rf-shield-ms263-20-emi-shielded-can.html" H 4525 6800 50  0001 C CNN
F 4 "MS263-20 (will use only the cover to keep hermetic sealed)" H 4525 6900 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 4525 6900 50  0001 C CNN "Source"
F 6 "27  Verify every place-assist hole inside shield footprint is sealed and take one last opportunity to ensure all other holes there as well are fully sealed against air travel.  Thoroughly solder in place with dessicant inside using bismuth solder if you have it for easiest removal." H 4525 6900 50  0001 C CNN "ClickToSortForPlacement"
	1    4525 6900
	1    0    0    -1  
$EndComp
Connection ~ 13175 3625
Wire Wire Line
	13175 3625 13175 3125
Wire Wire Line
	12350 3125 13175 3125
Wire Wire Line
	13175 3625 14750 3625
Wire Wire Line
	12350 4325 12350 4125
Wire Wire Line
	20800 1625 20800 1700
Wire Wire Line
	21150 1700 20800 1700
Connection ~ 21150 1700
$Comp
L power:GNDD #PWR0144
U 1 1 5F6A18C2
P 1275 7300
F 0 "#PWR0144" H 1275 7050 50  0001 C CNN
F 1 "GNDD" H 1279 7145 50  0000 C CNN
F 2 "" H 1275 7300 50  0001 C CNN
F 3 "" H 1275 7300 50  0001 C CNN
	1    1275 7300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0145
U 1 1 5F6A1F16
P 2925 7300
F 0 "#PWR0145" H 2925 7050 50  0001 C CNN
F 1 "GNDD" H 2929 7145 50  0000 C CNN
F 2 "" H 2925 7300 50  0001 C CNN
F 3 "" H 2925 7300 50  0001 C CNN
	1    2925 7300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0170
U 1 1 5F6A2581
P 4525 7300
F 0 "#PWR0170" H 4525 7050 50  0001 C CNN
F 1 "GNDD" H 4529 7145 50  0000 C CNN
F 2 "" H 4525 7300 50  0001 C CNN
F 3 "" H 4525 7300 50  0001 C CNN
	1    4525 7300
	1    0    0    -1  
$EndComp
Text Notes 14550 10950 0    50   ~ 0
See "Options" box also.\nIf using the UNO SMD MCU version with an ATMEGA128P-AU (a \nTQFP package specifically instead of the UNO with a DIP \nATMEGA128P), there are two analog input pins available at the \nTQFP package on the MCU board that are often not wired out to \nany connector.  Their TQFP pin numbers are 19 (A6) and 22 (A7).\n\nWhile you are building this project and before deciding on the \nlength of J2, look at your Arduino to see if A6 and A7 are wired \nout to some connector.  If so, you're in luck - just determine \nthose details.  If your Arduino does not break out A6 and A7 \nfor you, decide whether you have a use for A6 &/or A7.  If so, \nyou will connect with PH-MVS-5370 pogo pins soldered atop \nslightly retracted P2 pins 9 and 1 (this board) and FFC bare pad \n(MCU board) instead of socket and pin.  Or buy an UNO that\ndoes break out A6 and A7.\n\n\n\nExample of an Arduino with the directly pinout supported at\nhttps://www.aliexpress.com\n/item\n/Real-tracking-number-100-new-chip-high-quality-UNO-R3-MEGA328P-CH340G-for-Arduino-Compatible-Improved\n/1933684816.html?spm=a2g0o.cart.0.0.7cd53c00hidtIP
$Comp
L Jumper:SolderJumper_3_Bridged12 JP8
U 1 1 5D438593
P 17700 9075
F 0 "JP8" H 17700 9280 50  0000 C CNN
F 1 "SolderJumper_3_Bridged12" H 17550 9475 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_Pad1.0x1.5mm_NumberLabels" H 17700 9075 50  0001 C CNN
F 3 "~" H 17700 9075 50  0001 C CNN
F 4 "999" H 17700 9075 50  0001 C CNN "ClickToSortForPlacement"
	1    17700 9075
	-1   0    0    -1  
$EndComp
Wire Wire Line
	17500 9075 17500 9200
Wire Wire Line
	17500 9200 17700 9200
Wire Wire Line
	17700 9200 17700 9225
Connection ~ 17700 9225
Wire Wire Line
	17500 9600 17500 9675
Wire Wire Line
	18400 9425 18400 9475
Wire Wire Line
	18400 9475 18200 9475
Wire Wire Line
	18200 9475 18200 9575
Connection ~ 18400 9425
Wire Wire Line
	18400 9125 18400 9075
Wire Wire Line
	18400 9075 18200 9075
Wire Wire Line
	18200 9075 18200 8975
Connection ~ 18400 9125
Wire Wire Line
	17500 9600 17700 9600
Connection ~ 17700 9525
Wire Wire Line
	17700 9525 17700 9600
Wire Notes Line
	22400 475  22400 850 
Text Notes 22000 950  0    30   Italic 0
Ignore pad error in pcbnew
Wire Notes Line
	21975 850  21975 1000
Wire Notes Line
	21975 850  22400 850 
Wire Notes Line
	21975 1000 22450 1000
Wire Wire Line
	2500 5450 3225 5450
Text Notes 12025 6625 0    20   ~ 0
Not possible to guard from\npin 4 if soldered down, but \nsince that is a constant  and\nnon-nuisance leakage, the \npurpose of this ckt is not \ncompromised unless un-\nusually high impedance is\ndesired.  In that case, suspend \npin 4 with its wire in air.
$Comp
L Jumper:SolderJumper_2_Bridged JP3
U 1 1 5EC42B5E
P 15200 5750
F 0 "JP3" H 15200 5650 50  0000 C CNN
F 1 "Cut_JP3_if_installing_HX711_option" H 15300 5475 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged2Bar_Pad1.0x1.5mm" H 15200 5750 50  0001 C CNN
F 3 "~" H 15200 5750 50  0001 C CNN
F 4 "99" H 15200 5750 50  0001 C CNN "ClickToSortForPlacement"
	1    15200 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	15350 5750 15575 5750
Wire Wire Line
	15050 5750 14800 5750
Connection ~ 14800 5750
Wire Wire Line
	15750 6100 15750 7100
Text Notes 9025 4575 0    50   ~ 10
Short \nacross \nD-S in \n3.3Vdc\nif nec.
Text Notes -675 -200 0    1000 ~ 200
3Vdc operation see notes re: Q2!
Wire Wire Line
	9325 4300 9325 4150
Connection ~ 9325 4150
Wire Wire Line
	9325 4150 9400 4150
Wire Wire Line
	9325 4600 9325 4825
Wire Wire Line
	9325 4825 8875 4825
Connection ~ 8875 4825
Wire Wire Line
	8875 4825 8875 5850
$Comp
L Jumper:SolderJumper_2_Open JP6
U 1 1 5E21975A
P 9325 4450
F 0 "JP6" V 8950 4450 50  0000 C CNN
F 1 "Bridge in 3Vdc" V 9475 4425 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_Pad1.0x1.5mm" H 9325 4450 50  0001 C CNN
F 3 "~" H 9325 4450 50  0001 C CNN
F 4 "01 " H 9325 4450 50  0001 C CNN "ClickToSortForPlacement"
	1    9325 4450
	0    1    1    0   
$EndComp
Text Notes 19975 11400 0    50   ~ 0
Two footprints for U41 laid down but \nboth cannot be used simultaneously.\nUse either SHLD1 or SHLD2 side at \nany one time.
$Comp
L Device:R_Small_US R19
U 1 1 5F4F0D08
P 12075 5625
F 0 "R19" H 12100 5425 50  0000 L CNN
F 1 "Optional_Rf" H 11975 5525 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 12075 5625 50  0001 C CNN
F 3 "~" H 12075 5625 50  0001 C CNN
F 4 "01 " H 12075 5625 50  0001 C CNN "ClickToSortForPlacement"
	1    12075 5625
	1    0    0    -1  
$EndComp
Connection ~ 12075 6275
Wire Wire Line
	12075 6275 11625 6275
Wire Wire Line
	13250 5125 13250 5525
Wire Wire Line
	13250 5525 12075 5525
Connection ~ 13250 5125
Wire Wire Line
	13250 5125 13425 5125
Wire Wire Line
	12075 5725 12075 6275
Wire Notes Line
	12150 6325 12150 5525
Text Notes 475  3025 0    100  ~ 20
Options Box:  3 Vdc (instead of 5Vdc) - Q2 unused, solder-short Q2 footprint D to S, possibly lower sensitivity result, verify ICSP1 power as desired\n               HX711 - Use only for extreme sensitivity; will then require C5 and C6 and the specified PCB version\n               A6 and A7 - These Analog Inputs are found on some of the better UNO\n                 Arduino boards, but all SMD UNO -AU boards have capability for the\n                 hacker who is willing to tap onto pins 19 and 22 of the ATMEGA328P-\n                 AU.   Jumpers 7 & 12 allow purely optional name switch at P2 Power/\n                 Reset header.\n               Triax cable from J5 - shield would be GNDD\n               JP1 and JP2 - UNTESTED If either or both are changed to other side with \n                 cut and solder, they can prolong lives of C1/C2.  \n               HX-05 - UNTESTED and no code developed.  Various wirings exist of this\n                 board.  Ensure which jumper configuration for your style.   Intended to \n                 allow an alternative to USB communications for plotting\n               Alternative Op Amps - Careful: I-bias linearity of U2A is very consequential\n               R19 Rf- Value might be in the G Ohms
Text Label 21150 1200 2    60   ~ 0
CFG-IOREF-A6
$Comp
L Jumper:SolderJumper_3_Bridged12 JP7
U 1 1 5F78F589
P 20100 1000
F 0 "JP7" V 20146 1068 50  0000 L CNN
F 1 "SolderJumper_3_Bridged12" V 20055 1068 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_Pad1.0x1.5mm" H 20100 1000 50  0001 C CNN
F 3 "~" H 20100 1000 50  0001 C CNN
F 4 "99 " H 20100 1000 50  0001 C CNN "ClickToSortForPlacement"
	1    20100 1000
	0    -1   -1   0   
$EndComp
Text Label 20100 1200 2    50   ~ 0
A6
Wire Wire Line
	20250 1000 20700 1000
Wire Wire Line
	20700 1000 20700 1100
Wire Wire Line
	20700 1100 21150 1100
$Comp
L Jumper:SolderJumper_2_Open JP12
U 1 1 5F7BF81B
P 20250 1200
F 0 "JP12" H 20250 1325 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 20275 1400 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 20250 1200 50  0001 C CNN
F 3 "~" H 20250 1200 50  0001 C CNN
F 4 "99 " H 20250 1200 50  0001 C CNN "ClickToSortForPlacement"
	1    20250 1200
	-1   0    0    1   
$EndComp
Text Label 20100 800  2    60   ~ 0
A7
Wire Wire Line
	20400 1200 21150 1200
Wire Wire Line
	2925 4900 2925 5050
Wire Wire Line
	6150 2875 6400 2875
Connection ~ 6400 2875
Wire Wire Line
	6400 2875 7475 2875
Connection ~ 5000 5450
Connection ~ 3225 5450
Wire Wire Line
	5000 5450 5000 6450
$Comp
L Device:C_Small C11
U 1 1 5E58E83B
P 17450 1475
F 0 "C11" V 17550 1500 50  0000 C CNN
F 1 "0.1 µF" V 17575 1725 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 17450 1475 50  0001 C CNN
F 3 "~" H 17450 1475 50  0001 C CNN
F 4 "08" H 11900 -2325 50  0001 C CNN "PlacementOrder"
F 5 "08" H 12650 -2375 50  0001 C CNN "SortForPlacement"
F 6 "16 Place then check work as before" H 12650 -2375 50  0001 C CNN "ClickToSortForPlacement"
F 7 "CL10B104KB8NNNL" H 17450 1475 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 17450 1475 50  0001 C CNN "Source"
	1    17450 1475
	0    1    1    0   
$EndComp
Connection ~ 17550 1475
Wire Wire Line
	17550 1475 17550 1375
Wire Wire Line
	17350 1475 17350 1525
$Comp
L power:GNDD #PWR0171
U 1 1 5EB17E59
P 14950 4175
F 0 "#PWR0171" H 14950 3925 50  0001 C CNN
F 1 "GNDD" H 14950 4025 50  0000 C CNN
F 2 "" H 14950 4175 50  0001 C CNN
F 3 "" H 14950 4175 50  0001 C CNN
	1    14950 4175
	1    0    0    -1  
$EndComp
Wire Wire Line
	15025 4175 14950 4175
Wire Notes Line
	11675 4175 11675 4975
Wire Notes Line
	11675 4975 10975 4975
Wire Notes Line
	10975 3925 10975 4975
Wire Notes Line
	10975 4175 11675 4175
$Comp
L Connector_private:Conn_01x01_Male J7
U 1 1 5EA3BBB0
P 11175 4325
F 0 "J7" H 11147 4257 50  0001 R CNN
F 1 "Conn_01x01_Male" H 11147 4348 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 11175 4325 50  0001 C CNN
F 3 "~" H 11175 4325 50  0001 C CNN
F 4 "99 " H 11175 4325 50  0001 C CNN "ClickToSortForPlacement"
	1    11175 4325
	-1   0    0    1   
$EndComp
$Comp
L Connector_private:Conn_01x01_Male J8
U 1 1 5EA70580
P 11175 4425
F 0 "J8" H 11147 4357 50  0001 R CNN
F 1 "Conn_01x01_Male" H 11147 4448 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 11175 4425 50  0001 C CNN
F 3 "~" H 11175 4425 50  0001 C CNN
F 4 "99 " H 11175 4425 50  0001 C CNN "ClickToSortForPlacement"
	1    11175 4425
	-1   0    0    1   
$EndComp
$Comp
L Connector_private:Conn_01x01_Male J10
U 1 1 5EA707B9
P 11175 4675
F 0 "J10" H 11147 4607 50  0001 R CNN
F 1 "Conn_01x01_Male" H 11147 4698 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 11175 4675 50  0001 C CNN
F 3 "~" H 11175 4675 50  0001 C CNN
F 4 "99 " H 11175 4675 50  0001 C CNN "ClickToSortForPlacement"
	1    11175 4675
	-1   0    0    1   
$EndComp
$Comp
L Connector_private:Conn_01x01_Male J11
U 1 1 5EA70B32
P 11175 4775
F 0 "J11" H 11147 4707 50  0001 R CNN
F 1 "Conn_01x01_Male" H 11147 4798 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 11175 4775 50  0001 C CNN
F 3 "~" H 11175 4775 50  0001 C CNN
F 4 "99 " H 11175 4775 50  0001 C CNN "ClickToSortForPlacement"
	1    11175 4775
	-1   0    0    1   
$EndComp
$Comp
L Connector_private:Conn_01x01_Male J14
U 1 1 5EA71446
P 11475 4425
F 0 "J14" H 11447 4357 50  0001 R CNN
F 1 "Conn_01x01_Male" H 11447 4448 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 11475 4425 50  0001 C CNN
F 3 "~" H 11475 4425 50  0001 C CNN
F 4 "99 " H 11475 4425 50  0001 C CNN "ClickToSortForPlacement"
	1    11475 4425
	1    0    0    -1  
$EndComp
$Comp
L Connector_private:Conn_01x01_Male J15
U 1 1 5EA719EF
P 11475 4575
F 0 "J15" H 11447 4507 50  0001 R CNN
F 1 "Conn_01x01_Male" H 11447 4598 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 11475 4575 50  0001 C CNN
F 3 "~" H 11475 4575 50  0001 C CNN
F 4 "99 " H 11475 4575 50  0001 C CNN "ClickToSortForPlacement"
	1    11475 4575
	1    0    0    -1  
$EndComp
$Comp
L Connector_private:Conn_01x01_Male J16
U 1 1 5EA71C03
P 11475 4775
F 0 "J16" H 11447 4707 50  0001 R CNN
F 1 "Conn_01x01_Male" H 11447 4798 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 11475 4775 50  0001 C CNN
F 3 "~" H 11475 4775 50  0001 C CNN
F 4 "99 " H 11475 4775 50  0001 C CNN "ClickToSortForPlacement"
	1    11475 4775
	1    0    0    -1  
$EndComp
$Comp
L Connector_private:Conn_01x01_Male J13
U 1 1 5EA71E63
P 11300 4775
F 0 "J13" H 11272 4707 50  0001 R CNN
F 1 "Conn_01x01_Male" H 11272 4798 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 11300 4775 50  0001 C CNN
F 3 "~" H 11300 4775 50  0001 C CNN
F 4 "99 " H 11300 4775 50  0001 C CNN "ClickToSortForPlacement"
	1    11300 4775
	0    1    1    0   
$EndComp
Text Label 11975 4575 0    50   ~ 0
SCK(1)
Text Label 11900 4775 0    50   ~ 0
MOSI(1)
Wire Notes Line
	17000 11775 15325 11775
Wire Notes Line
	15325 11100 17000 11100
Text Notes 15420 11600 0    50   ~ 0
MCP4262-502E/UN board-on-board\nmodule, Part 2 of 2 Consists of U40 \nLM334Z/LFT1and R15 current set\nresistor
Wire Wire Line
	16550 11825 16750 11825
Wire Wire Line
	16550 11925 16500 11925
Connection ~ 16550 11825
Wire Wire Line
	16550 11825 16550 11925
Wire Notes Line
	17000 11100 17000 11775
Wire Notes Line
	15325 11100 15325 11775
Wire Wire Line
	16550 11775 16550 11825
Wire Wire Line
	15575 5750 15575 5800
$Comp
L power:GNDD #PWR011
U 1 1 5D5FFC74
P 9850 4975
F 0 "#PWR011" H 9850 4725 50  0001 C CNN
F 1 "GNDD" H 9854 4820 50  0000 C CNN
F 2 "" H 9850 4975 50  0001 C CNN
F 3 "" H 9850 4975 50  0001 C CNN
	1    9850 4975
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5E3D0D07
P 21525 4350
F 0 "#FLG0102" H 21525 4425 50  0001 C CNN
F 1 "PWR_FLAG" V 21625 4300 50  0001 C CNN
F 2 "" H 21525 4350 50  0001 C CNN
F 3 "~" H 21525 4350 50  0001 C CNN
	1    21525 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	21075 4350 21525 4350
Connection ~ 21075 4350
NoConn ~ 22400 2700
NoConn ~ 22450 2600
$Comp
L Connector_private:Conn_01x01_Male J9
U 1 1 5E3D142C
P 11300 4350
F 0 "J9" H 11272 4282 50  0001 R CNN
F 1 "Conn_01x01_Male" H 11272 4373 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 11300 4350 50  0001 C CNN
F 3 "~" H 11300 4350 50  0001 C CNN
F 4 "99 " H 11300 4350 50  0001 C CNN "ClickToSortForPlacement"
	1    11300 4350
	0    -1   -1   0   
$EndComp
Text Notes 11150 4125 0    40   ~ 0
MCP4262-502E/UN \nboard-on-board\nmodule, Part 1of 2\nConsists of U8-U33 \nall these pins in parallel
Wire Wire Line
	17150 1525 17350 1525
Connection ~ 12625 3325
$Comp
L power:VCC #PWR0101
U 1 1 5E40CA8E
P 12625 3325
F 0 "#PWR0101" H 12625 3175 50  0001 C CNN
F 1 "VCC" V 12643 3452 50  0000 L CNN
F 2 "" H 12625 3325 50  0001 C CNN
F 3 "" H 12625 3325 50  0001 C CNN
	1    12625 3325
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0103
U 1 1 5E431E1A
P 21250 4150
F 0 "#PWR0103" H 21250 4000 50  0001 C CNN
F 1 "VCC" H 21267 4323 50  0000 C CNN
F 2 "" H 21250 4150 50  0001 C CNN
F 3 "" H 21250 4150 50  0001 C CNN
	1    21250 4150
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E432EC6
P 21075 4150
F 0 "#FLG0101" H 21075 4225 50  0001 C CNN
F 1 "PWR_FLAG" H 21075 4323 50  0001 C CNN
F 2 "" H 21075 4150 50  0001 C CNN
F 3 "~" H 21075 4150 50  0001 C CNN
	1    21075 4150
	1    0    0    -1  
$EndComp
Connection ~ 21075 4150
$Comp
L power:VCC #PWR0104
U 1 1 5E43478C
P 7975 2875
F 0 "#PWR0104" H 7975 2725 50  0001 C CNN
F 1 "VCC" H 7992 3048 50  0000 C CNN
F 2 "" H 7975 2875 50  0001 C CNN
F 3 "" H 7975 2875 50  0001 C CNN
	1    7975 2875
	1    0    0    -1  
$EndComp
Connection ~ 7975 2875
Wire Wire Line
	7975 2875 8575 2875
$Comp
L power:VCC #PWR0105
U 1 1 5E43585F
P 19725 11325
F 0 "#PWR0105" H 19725 11175 50  0001 C CNN
F 1 "VCC" H 19742 11498 50  0000 C CNN
F 2 "" H 19725 11325 50  0001 C CNN
F 3 "" H 19725 11325 50  0001 C CNN
	1    19725 11325
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0106
U 1 1 5E436967
P 12575 5625
F 0 "#PWR0106" H 12575 5475 50  0001 C CNN
F 1 "VCC" V 12593 5752 50  0000 L CNN
F 2 "" H 12575 5625 50  0001 C CNN
F 3 "" H 12575 5625 50  0001 C CNN
	1    12575 5625
	0    -1   -1   0   
$EndComp
Connection ~ 12575 5625
$Comp
L power:VCC #PWR0107
U 1 1 5E4383FC
P 13775 4525
F 0 "#PWR0107" H 13775 4375 50  0001 C CNN
F 1 "VCC" V 13792 4653 50  0000 L CNN
F 2 "" H 13775 4525 50  0001 C CNN
F 3 "" H 13775 4525 50  0001 C CNN
	1    13775 4525
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0108
U 1 1 5E4396A8
P 11300 4150
F 0 "#PWR0108" H 11300 4000 50  0001 C CNN
F 1 "VCC" V 11318 4277 50  0000 L CNN
F 2 "" H 11300 4150 50  0001 C CNN
F 3 "" H 11300 4150 50  0001 C CNN
	1    11300 4150
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0109
U 1 1 5E43A85E
P 14400 6425
F 0 "#PWR0109" H 14400 6275 50  0001 C CNN
F 1 "VCC" V 14417 6553 50  0000 L CNN
F 2 "" H 14400 6425 50  0001 C CNN
F 3 "" H 14400 6425 50  0001 C CNN
	1    14400 6425
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0110
U 1 1 5E43BBB4
P 17900 9075
F 0 "#PWR0110" H 17900 8925 50  0001 C CNN
F 1 "VCC" H 17917 9248 50  0000 C CNN
F 2 "" H 17900 9075 50  0001 C CNN
F 3 "" H 17900 9075 50  0001 C CNN
	1    17900 9075
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0111
U 1 1 5E43CCF0
P 18600 8975
F 0 "#PWR0111" H 18600 8825 50  0001 C CNN
F 1 "VCC" H 18617 9148 50  0000 C CNN
F 2 "" H 18600 8975 50  0001 C CNN
F 3 "" H 18600 8975 50  0001 C CNN
	1    18600 8975
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0112
U 1 1 5E43DE3E
P 9850 4175
F 0 "#PWR0112" H 9850 4025 50  0001 C CNN
F 1 "VCC" V 9867 4303 50  0000 L CNN
F 2 "" H 9850 4175 50  0001 C CNN
F 3 "" H 9850 4175 50  0001 C CNN
	1    9850 4175
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0113
U 1 1 5E43F00A
P 20800 9125
F 0 "#PWR0113" H 20800 8975 50  0001 C CNN
F 1 "VCC" H 20817 9298 50  0000 C CNN
F 2 "" H 20800 9125 50  0001 C CNN
F 3 "" H 20800 9125 50  0001 C CNN
	1    20800 9125
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0115
U 1 1 5E44017B
P 21450 9125
F 0 "#PWR0115" H 21450 8975 50  0001 C CNN
F 1 "VCC" H 21467 9298 50  0000 C CNN
F 2 "" H 21450 9125 50  0001 C CNN
F 3 "" H 21450 9125 50  0001 C CNN
	1    21450 9125
	1    0    0    -1  
$EndComp
Wire Wire Line
	3575 5450 5000 5450
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 5E443868
P 15050 5750
F 0 "#FLG0104" H 15050 5825 50  0001 C CNN
F 1 "PWR_FLAG" H 15050 5923 50  0000 C CNN
F 2 "" H 15050 5750 50  0001 C CNN
F 3 "~" H 15050 5750 50  0001 C CNN
	1    15050 5750
	1    0    0    -1  
$EndComp
Connection ~ 15050 5750
$Comp
L power:VCC #PWR0116
U 1 1 5E471496
P 11900 11200
F 0 "#PWR0116" H 11900 11050 50  0001 C CNN
F 1 "VCC" H 11917 11373 50  0000 C CNN
F 2 "" H 11900 11200 50  0001 C CNN
F 3 "" H 11900 11200 50  0001 C CNN
	1    11900 11200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0117
U 1 1 5E481852
P 17350 1475
F 0 "#PWR0117" H 17350 1325 50  0001 C CNN
F 1 "VCC" H 17367 1648 50  0000 C CNN
F 2 "" H 17350 1475 50  0001 C CNN
F 3 "" H 17350 1475 50  0001 C CNN
	1    17350 1475
	1    0    0    -1  
$EndComp
Connection ~ 17350 1475
Text Label 10950 4950 2    60   ~ 0
1st_stage_guard_ring
$Comp
L conn_01x01_male_tiny_pin_number:Conn_01x01_Male J12
U 1 1 5E3F1E2B
P 11150 4950
F 0 "J12" H 11150 5050 50  0001 C CNN
F 1 "Conn_01x01_Male" H 11150 4850 50  0001 C CNN
F 2 "multipackage:Hole_0.9mm" H 11150 4950 50  0001 C CNN
F 3 "~" H 11150 4950 50  0001 C CNN
F 4 "99 " H 11150 4950 50  0001 C CNN "ClickToSortForPlacement"
	1    11150 4950
	-1   0    0    1   
$EndComp
Wire Wire Line
	14325 2875 15350 2875
Wire Wire Line
	15350 2875 15350 4175
Connection ~ 14325 2875
$Comp
L Connector_private:Conn_01x01_Male J17
U 1 1 5E42066F
P 16550 11575
F 0 "J17" H 16522 11507 50  0001 R CNN
F 1 "Conn_01x01_Male" H 16522 11598 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 16550 11575 50  0001 C CNN
F 3 "~" H 16550 11575 50  0001 C CNN
F 4 "99 " H 16550 11575 50  0001 C CNN "ClickToSortForPlacement"
	1    16550 11575
	0    1    1    0   
$EndComp
Wire Wire Line
	12350 4125 14475 4125
Wire Wire Line
	14325 3175 14325 4000
Wire Wire Line
	14475 4125 14475 6100
Wire Wire Line
	14475 6100 15750 6100
Wire Wire Line
	14800 5750 14700 5750
Wire Wire Line
	14700 5750 14700 4000
Wire Wire Line
	14700 4000 14325 4000
Text Label 15750 6950 2    50   ~ 0
U2-Pad6
$Comp
L Connector_private:Conn_01x01_Male J21
U 1 1 5E7974CC
P 11475 4890
F 0 "J21" H 11447 4822 50  0001 R CNN
F 1 "Conn_01x01_Male" H 11447 4913 50  0001 R CNN
F 2 "multipackage:Hole_0.9mm" H 11475 4890 50  0001 C CNN
F 3 "~" H 11475 4890 50  0001 C CNN
F 4 "99 " H 11475 4890 50  0001 C CNN "ClickToSortForPlacement"
	1    11475 4890
	1    0    0    -1  
$EndComp
Wire Wire Line
	11675 4890 11725 4890
Wire Wire Line
	11725 4890 11725 4775
Connection ~ 11725 4775
Wire Wire Line
	11725 4775 11900 4775
Text Notes 13060 19490 0    400  ~ 0
NOTES FOR ASSEMBLY:
Text Notes 13125 21570 0    150  ~ 0
Number of unique parts: 27\nNumber of SMT parts: 69\nNumber of fine pitch parts: 29\nNumber of leadless placements: 1 with exposed pad\nResistors R6, R7, R15-18 are 0.1% values and minimal temperature co-efficients \nLeave assembly of U4, U40, U41 for End User, not counted in above numbers\nLeave assembly of Through Hole components for End User, not counted in above numbers\nLeave assembly of shields SHLD1, 2, 3 for End User, not counted in above numbers
Text Notes 580  17220 0    400  ~ 0
NOTES FOR FABRICATION:
Text Notes 645  23140 0    150  ~ 0
THIS DATA OVERRIDES ANSWERS GIVEN IN QUESTIONAIRE:\n\nLayers = 2\nTG material is 170 or greater FR4\nBoard thickness smaller section = .8\nBoard thickness larger section = .8 to 1.6 as convenient\nMin hole size = .254 mm = 10 mil\nMin track spacing = .2 mm = 7.87 mil\nDefault solder mask, both sides\nWhite silkscreen, both sides\nNot high frequency\nNot controlled impedance\nNot gold fingers\nPreferred surface = lead free HASL\nCu weight = 2 oz\n\nFOLLOW GERBERS EXACTLY INCLUDING:\n- If this design has 2 mm holes shown between sections, those holes are not plated, and the number of designs in panel is 2 instead of 1.\n- off-center holes in pads, \n- dangling net traces, \n- a single sided Through Hole pad, \n- silk screen on copper, \n- solder mask customizations,\n- solder paste customizations\n\n
Text Notes 5045 5500 0    50   ~ 0
NOTE:  Pad 9 best practice \nwill include PTH via &/or\nextending traces for \nsoldering survival
Text Notes 12495 4930 2    50   ~ 0
This box not depicted as a guard ring
$EndSCHEMATC
