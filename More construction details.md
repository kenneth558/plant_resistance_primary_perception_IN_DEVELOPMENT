If for some odd reason you are stuck using the "not recommended due to far lower resolution" ADS1X15, observe the following 3 points:

 ##### 1.  A decoupling capacitor is required at the ADS1X15 device VDD to GND.  From the datasheet:
>Good power-supply decoupling is important to achieve optimum performance. VDD must be decoupled with at least a 0.1-μF capacitor, as shown in Figure 47. The 0.1-μF bypass capacitor supplies the momentary bursts of extra current required from the supply when the device is converting. Place the bypass capacitor as close to the power-supply pin of the device as possible using low-impedance connections. Use multilayer ceramic chip capacitors (MLCCs) that offer low equivalent series resistance (ESR) and inductance (ESL) characteristics for power-supply decoupling purposes. For very sensitive systems, or for systems in harsh noise environments, avoid the use of vias for connecting the capacitors to the device pins for better noise immunity. The use of multiple vias in parallel lowers the overall inductance, and is beneficial for connections to ground planes.

 ##### 2.  An RC filter to each used ADS1X15 analog input is advised by the manufacturer.  From the datasheet:
>...any noise pick-up along the sensor wiring or the application circuitry can potentially alias into the pass-band. Power line-cycle frequency and harmonics are one common noise source. External noise can also be generated from electromagnetic interference (EMI) or radio frequency interference (RFI) sources, such as nearby motors and cellular phones. Another noise source typically exists on the printed-circuit-board (PCB) itself in the form of clocks and other digital signals. Analog input filtering helps remove unwanted signals from affecting the measurement result...

 ##### 3.  Unused analog input pins of the ADS1X15 should not be connected to GND or more power cupply current will be drawn than is necessary.  From the datasheet:
>Either float unused analog inputs, or tie the unused analog inputs to midsupply or VDD. Connecting unused analog inputs to GND is possible, but may yield higher leakage currents than the previous options.


Many other application tips are in the datasheet.  I don't mean to discourage you with technical reading, but those tips _are_ useful, and some diagrams are in there that could help hold your attention.  I won't include any links here b/c they so often go dead.  I'll offer one tip I didn't find stated very clear in the datasheet concerning ADS1X15 ground path.  When the ADS device is configured for single-ended as opposed to differential usage, the reference electrode wire should connect to the ADS1X15 approaching it from the opposite direction that it connects to the Arduino GND.  In other words, looking at the ADS1X15, it is a two sided device, front and back, where two two sides are divided from each other by a single row of pins.  If the Arduino GND connects via the back side, then the reference electrode wire should connect via the front side, and vice versa.  This means that the common practice of soldering header pins that exit only from the back side of the ADS1X15 should be critically reconsidered for its GND pin.  A longer than normal pin or wire should be used so it can provide connection both from the front side of the ADS1X15 and from the back, as in the picture below.![How the ground pin needs to extend from both sides of the ADS board](https://github.com/kenneth558/plant_resistance_primary_perception/blob/Free/embeddeds/adc%20primary%20perception%20ADS%20board%20ground%20pin%20cropped.png)You'll note that I had no long pin so I could only push the standard-length pin halfway through the board.  It was only barely long enough on each side, emphasis on "barely".  

The power decoupling capacitor must *not* be connected on the ADS1X15 signal side of that pin/wire, yet as close as possible on the other (power) side.

Another note electronics-wise is that if you don't use an AD8244 the inputs of the ADS device will draw current (S-H capacitor charging current) from the device under test (DUT) connected.  The amount of that current depends on the the input voltage difference from 0.7 volts.  The electronics-saavy reader recognizes that voltage as a silicon diode junction voltage that will exist on the input pin when nothing is connected to it.  However, the current drawn is NOT that of a resistive load but rather, when used with the high impedance application of this project, a capacitive load.  The point being that the RC filter capacitance added to the input pins as mentioned in point 2 above actually increases the DC readings a small amount from what they would read without any added  capacitors on the input pins.  I only state this because I was initially puzzled by the input difference myself before I understood why a capacitor was changing the input voltage, and I don't want you to waste your time worrying about it if you notice it.  The AD8244 is designed to isolate the DUT from that S-H capacitor charging current.

 ##### 4.  My reply to:
"Your demo in Lincoln interests me and I would like to know all the details, schema and everything I need to know to replicate your idea!"

You'll find the sketch under the "sketch code" folder in that GitHub location.  I'm keeping two sketches out there so one I call the nightly version.  "Weekly" is more accurate on that.

A verbal description follows the schematic: ![the circuit](https://github.com/kenneth558/plant_resistance_primary_perception/blob/Free/embeddeds/GWAAMC%20System%20single%20page.png)
The signal input is from a Wheatstone bridge circuit whose legs span the 5 VDC supply voltage.  My sketch is being written to accommodate more bridges to other DUTs, but I'll use the singular tense as I describe this to you.  Both legs of the bridge ("signal" and "reference" legs) are topped by one LM334 per leg, controlled by three (soon to be two) digipots making two LM334s and six (soon to be four) digipots per bridge.  "Topped" means each of the two LM334s connect to 5 VDC power with their (+) pin (lead).  Their (-) pin is the leg midpoint.  The controlling resistance formed by the digipots connects between the (R) pin and the (-) pin.  The (R) pin is called ADJ in some references.  

The midpoint of the signal leg of the bridge connects to the DUT (device under test: the plant) with the signal electrode, while the other electrode is the ground electrode connecting from somewhere else on the plant near the signal electrode to signal ground of the circuit.  The two electrodes sandwich a leaf between them.  The load resistance in the reference leg has been a 1 MOhm resistor for all of the R&D time.  That value also seemed to work surprisingly well whenever I attached electrodes to an actual plant.  I'm sure different plants and electrode surface areas will result in that resistance value being adjusted upward in the future or for different circumstances.

The digipots need to be low-noise; i.e., you should not use the popular X9Cxxx digipots because they have internal charge pumps that generate noise.  Charge pumps are needed in digipots to save settings to EEPROM, so you'll be stuck using pots that can't save their settings in order to have low noise.  The digipots I've successfully tested are the MCP4162-104 and MCP4162-502 (two of each will handle one bridge).  Those values are 100 KOhm and 5 KOhm, and you would control each LM334 with one 100K pot and one 5K pot in series with each other. Please note that in my development circuit I actually use more 100K pots thinking I would get greater range but discovered the LM334 doesn't seem to have the range at 5VDC to handle adjustment resistance higher than 100K, so you could save yourself a couple parts from what the sketch during development is capable of if you just use one of the 100K pots in series with the 5K pot per LM334.  Save a package of each value by using the MCP4262-x0x instead because that part is a dual digipot, but in such a tiny package that they are FAR more difficult to handle and solder.

Other pin assignments:  

SS – digital 10 to CS of a single digital pot, not abstracted by library call, so can be any pin as determined within main function 
      unidirectional NOT PIN 10 ON LEONARDO - IS FOUND ON LED_BUILTIN_RX (PIN 17) ONLY

MOSI – digital 11 to inputs of all digital pots unidirectional NOT PIN 11 ON LEONARDO - IS FOUND ON 1CSP ONLY.  REQ'D IN ALL CASES.

MISO – digital 12 to outputs of all digital pots unidirectional NOT PIN 12 ON LEONARDO - IS FOUND ON 1CSP ONLY.  NOT USED 
      CURRENTLY BECAUSE WITHOUT 8 TO 12 VDC EEPROM VOLTAGE, SETTINGS CAN'T BE SAVED INSIDE THE DIGPOTS, SO OF COURSE THEY CAN'T BE 
      READ BACK OUT FROM THE DIGIPOTS.

SCK – digital 13 to CLK of all digital pots unidirectional NOT PIN 13 ON LEONARDO - IS FOUND ON 1CSP ONLY


As I describe in the sentence above, I use an extra, unnecessary 100K pot per LM334, so the CS pin numbers in early sketches are wasting two pins, if you care to shift the digital pins for the CS line down in the sketch.  The Arduino Digital pins are set in the sketch to preprocessor macros called "BANK_0_LEG_0_DIGITAL_POT_0" and similar.  If you use the two digipot per leg design, the MSB namesaked digipots need to be skipped in favor of only the MID and LSB namesaked ones; hence, the MSB pins are wasted if you don't shift the others down.  If the sketch version you obtained does not have MID pots, then your sketch is "two pot per leg ready".

A wire from the signal leg midpoint of the bridge and a wire from the reference leg midpoint connect to input pins of an AD8244 quad unity-gain buffer.  The two unused buffers must have their inputs connected to something - it is perfectly within design ratings to parallel the buffers together to ensure no floating inputs, so I do that.  The two buffered outputs from that AD8244 go to analog to digital (A-to-D) pins of the first two Arduino Analog Input pins AND (i.e., "in parallel with") the two input pins of some higher sensitivity ADC of your choice (only HX711 and ADS1X15 supported now).  Use power decoupling capacitors where power wires run any distance.

DATA and CLK to the ADC are set by preprocessor macros PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC and PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC to pins 2 and 3 unless you change them.  Remember to set HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC and HIGHEST_SENSI_OUTBOARD_ADC_TYPE to the appropriate value for the ADC you might use.

OPTIONAL:  Quick and dirty operation can be achieved with just the Arduino and the DUT with balancing resistor connected to +5 VDC...and electrodes  Just set the appropriate pre-processor macros:  disable the USING_LM334... macro, the NUM_OF_OUTBOARDS... macro [and maybe the SUPERIMPOSE_FIRST_INBOARDS... macro if you want two pins plotted magnified (superimposing disables the magnified view of a signal)].  IOW, the AD8244, digipots, and high sensitivity ADC are optional if you just want to see a plotline respond to your finger touching it.  The digipots also won't do anything for you if you use a rail-to-rail ADC, as the ADS1X15 is.  

You might be able to be notified of my changes to the project by GitHub settings, if you look around in GitHub, maybe...that's not a GitHub feature I've ever used, yet.

Electrodes are vaporware as of yet: I'm trying conductive foam or conductive sheet plastic.


 ##### 5.  Tony provides this parts list, which doesn't include the Arduino and its cable to your computer:  
 #### TIP: If you are cost-sensitive, decide where you'll buy everything from before placing any order.

qty - part number, then one or two sources for purchase
##### 1   - AD8244
Arrow      https://www.arrow.com/en/products/ad8244armz-r7/analog-devices

 ##### 1   -  MSOP-10 PCB ADAPTER BOARD FOR THE AD8244
AlliExpress   https://www.aliexpress.com/item/50PCS-SOT23-MSOP10-UMAX-to-DIP10-Transfer-Board-DIP-Pin-Board-Pitch-Adapter-NEW/32902829277.html?spm=2114.search0204.3.2.602e4baddaQg2A&s=p&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_10130_5726815_10547_10546_10059_10884_10548_315_10545_10887_10696_100031_531_10084_10083_5726915_10103_10618_10307_449,searchweb201603_60,ppcSwitch_5_ppcChannel&priceBeautifyAB=0
 I encourage you to support this project by mailing me your leftover adapter boards, if you appreciate my information-sharing efforts.  Address available if you'll open an "issue" to ask for it.  Thank you!

 ##### 2   - LM334
Arrow      https://www.arrow.com/en/products/lm334znopb/texas-instruments

AlliExpress   https://www.aliexpress.com/item/5PCS-LM334Z-TO-92-LM334-3-Terminal-Adjustable-Current-Source-new-and-original-IC/32856893079.html?spm=2114.search0204.3.36.129324fersybG8&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_10130_5727215_318_10547_10546_10059_10884_10548_5727315_10545_10887_10696_100031_10084_10083_10103_10618_452_10307_532,searchweb201603_60,ppcSwitch_0_ppcChannel&algo_expid=a3c22483-ce93-4647-bbe5-d1b3482d0749-5&algo_pvid=a3c22483-ce93-4647-bbe5-d1b3482d0749&priceBeautifyAB=0

 ##### Either 1   - MCP4262-502
Arrow     https://www.digikey.com/product-detail/en/microchip-technology/MCP4262-502E-UN/MCP4262-502E-UN-ND/1635819 or https://www.mouser.com/ProductDetail/Microchip-Technology/MCP4262-502E-UN?qs=sGAEpiMZZMuD%2F7PTYBwKqUWe8PKqoc794Kb1a2FsZsY%3D or https://www.newark.com/microchip/mcp4262-502e-mf/dfn-dual-8bit-nv-spi-rheo/dp/96AC0682?st=MCP4262-502
 ##### or 2   - MCP4162-502
Arrow     https://www.arrow.com/en/products/mcp4162-502ep/microchip-technology

##### Either 1   - MCP4262-104
Arrow      https://www.arrow.com/en/products/mcp4262-104eun/microchip-technology
 ##### or 2   - MCP4162-104
Arrow      https://www.arrow.com/en/products/mcp4162-104ep/microchip-technology
      
 ##### 2   - 27 Ohm +-20% resistor, axial leads unless you are a good solderer
Example: https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CF18JT27R0/CF18JT27R0CT-ND/2022704
Buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list: https://www.google.com/search?q=22+ohm+%220.25w%22+axial+resistor&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=sY58XMDxFoXXjwTf0KyQAw&ved=0ahUKEwiAjsjCuefgAhWF64MKHV8oCzIQuw0IwQQoAQ  color code = red violet black

 ##### 3   - 470 Ohm +-20% resistor, axial leads unless you are a good solderer.  Qty 2 if buying 2 color LED
Example: https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CF14JT470R/CF14JT470RCT-ND/1830342
Buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list: https://www.google.com/search?q=680+ohm+"0.25w"+axial+resistor&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=sY58XMDxFoXXjwTf0KyQAw&ved=0ahUKEwiAjsjCuefgAhWF64MKHV8oCzIQuw0IwQQoAQ  color code = yellow violet brown

 ##### 1   - 3.3 KOhm +-20% resistor, axial leads unless you are a good solderer
 Example: https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CF18JT3K30/CF18JT3K30CT-ND/2022754
Buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list similar to above.  Color code = orange orange red

 ##### 1   - 1 MOhm +-20% resistor, axial leads unless you are a good solderer
 Example: https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CF18JT1M00/CF18JT1M00CT-ND/2022814
Buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list similar to above.  Color code = brown black green 

 ##### 2   - 2.0 µF 16 volt+ tantalum capacitor, radial, low ESR
Example: https://www.arrow.com/en/products/t356a225k016at/kemet-corporation or buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list being careful for adequate voltage: https://www.google.com/search?q=buy+2.2+%C2%B5F+tantalum+capacitor+radial&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=4o18XKHyNaG0jwTpoK2wBg&ved=0ahUKEwih64zguOfgAhUh2oMKHWlQC2YQuw0I0QgoAQ

 ##### 2   - 0.1 µF ceramic capacitor, radial, low dissipation factor
 Example: https://www.arrow.com/en/products/c323c104m5r5ta/kemet-corporation or buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list: https://www.google.com/search?q=buy+.01+%C2%B5F+ceramic+capacitor+radial&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=so18XKXjG4GMjwTx8ZjAAw&ved=0ahUKEwilhIHJuOfgAhUBxoMKHfE4BjgQuw0I7wgoAg

 ##### 1   - 0.01 µF ceramic capacitor, radial
 Example: https://www.arrow.com/en/products/ncd103m100z5uf/nic-components or buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list: https://www.google.com/search?q=buy+.01+%C2%B5F+ceramic+capacitor+radial&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=so18XKXjG4GMjwTx8ZjAAw&ved=0ahUKEwilhIHJuOfgAhUBxoMKHfE4BjgQuw0I7wgoAg

 ##### 2   - two color (Bicolor, RGB, Multicolor will also work OK) LED or two different colored LEDs.  Rectangular (2mm x 5mm) size (at last check, the red one following mistakenly shows the wrong shape in the picture).  High efficiency (high mcd per mA) is best due to little power available
Example: Yellow - https://www.arrow.com/en/products/ssl-lx2573yd/lumex, 
         Red - https://www.arrow.com/en/products/ssl-lx2573id/lumex
Buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list: https://www.google.com/search?q=mcd+led+efficiency+t-1&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=SZd8XKXcC43SsAXcpqaQBQ&ved=0ahUKEwjlpMLbwefgAhUNKawKHVyTCVIQuw0ItgMoAQ

 ##### 2 MOSFETs to drive the LEDs:
 Example: https://www.arrow.com/en/products/vn2106n3-g/microchip-technology
 
 ##### 2   - Potentiometer 50 KOhm or other high value, rotary operation, linear taper, single turn w/knob or cap and mounting means or PCB mount (AKA top adjust)
Examples: https://www.arrow.com/en/products/ptv09a-4030u-b204/bourns
or
https://www.jameco.com/z/RV09AF-40-20K-B500K-Taiwan-Alpha-Electronic-500K-Ohm-50-mW-9-mm-20-0-787-Inch-Knurl-Shaft-Solder-Lugs-Linear-Taper-Potentiometer_2272231.html
or
https://www.digikey.com/product-detail/en/bourns-inc/PTV09A-4030U-B204/PTV09A-4030U-B204-ND/3781141
or formulate your own search


 ##### 1   - HX711 ADC (recommended unless you can code for own ADC)
AlliExpress   https://www.aliexpress.com/item/Dual-Channel-HX711-Weighing-Pressure-Sensor-24-bit-Precision-A-D-Module-for-arduino-DIY-Electronic/32878181081.html?spm=2114.search0204.3.2.5f8a7264S5dDtV&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_10130_5726815_10547_10546_10059_10884_10548_315_10545_10887_10696_100031_531_10084_10083_5726915_10103_10618_10307_449,searchweb201603_60,ppcSwitch_5_ppcChannel&algo_expid=719ad9df-13c6-42bc-adff-e19814e28dae-0&algo_pvid=719ad9df-13c6-42bc-adff-e19814e28dae&priceBeautifyAB=0

Newer Version of the HX711 is available instead, but not yet tested:
AlliExpress   https://www.aliexpress.com/item/Free-shipping-Goose-electronic-HX711-module-weighing-sensor-24-AD-module-pressure-sensor-AD-module-SCM/32441222056.html?spm=2114.search0204.3.31.5f8a7264S5dDtV&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_10130_5726815_10547_10546_10059_10884_10548_315_10545_10887_10696_100031_531_10084_10083_5726915_10103_10618_10307_449,searchweb201603_60,ppcSwitch_5_ppcChannel&algo_expid=719ad9df-13c6-42bc-adff-e19814e28dae-4&algo_pvid=719ad9df-13c6-42bc-adff-e19814e28dae&priceBeautifyAB=0

or 1 - ADS1X15 ADC (not recommended due to far lower resolution, so only if it's all that you can come up with...and favor the ADS1115), or code for your own ADC

Hard-soldered piece of 2-wire cable (shielded or coax advised) from electrodes to circuit   
OR   
3.5mm stereo audio PCB mount jack (https://www.arrow.com/en/products/sj1-3523ng/cui-inc), related extender cable (.5m = https://www.arrow.com/en/products/770-10040-00050/cnc-tech-llc 1m = https://www.arrow.com/en/products/770-10040-00100/cnc-tech-llc 1.5m = https://www.arrow.com/en/products/770-10040-00150/cnc-tech-llc), and 3.5mm stereo audio cable mount jack (https://www.arrow.com/en/products/152001/lumberg);   

electrode assemblies with enough wiring to attach to the above 2-wire cable, optional 4-way light switch at the plant end of that coax (can give you the flexibility to reverse the electrical polarity to the plant),  Interconnects and soldering equipment, wiring, circuit substrate, mounting brackets and the like...  If desoldering for repurposing parts, consider doing so with low melt point desoldering solder: https://www.ebay.com/itm/Solder-wire-low-melting-point-124C-1m-1mm-Bi55-5-Pb44-5-alloy-good-desoldering/171173385076?epid=1531599266&hash=item27daba9374:g:JpIAAOSwq19XBnVh_trksid=p2047675.c100005.m1851
