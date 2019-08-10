### PCB Gerber files
##### Here is a link to the gerber files of my PCB design: https://github.com/kenneth558/plant_resistance_primary_perception/blob/Free/Where%20to%20find%20everything%20for%20making%20your%20own%20GWAAMC%20device/Files%20you%20need%20relative%20to%20the%20printed%20circuit%20board/uno%20shield%20v.6%20PCB%20gerbers.zip.  I suggest NOT getting the tinned option simply because the crowned traces you'll have from it will make it seriously more difficult for you to place the MSOP10 packages.  I really like the gold plating that OSH Park uses for its flat surface, since you'll normally want something other than bare copper so it won't oxidize and prevent solder adhesion.

### PCB Comparison sites
##### Printed circuit boards can be ordered from any one of a multitude of fabricators.  Compare between fabricators by visiting one or more of the fabricator comparison sites like https://www.pcbdirectory.com/get-quotations or https://pcbshopper.com or read the fabricator site collection list at https://www.eevblog.com/wiki/index.php?title=PCB_Manufacturers or search "online pcb quote".

The PCB project is also published by OSH Park PCB fabrication here: https://oshpark.com/shared_projects/45GiirVJ.  They would appreciate your business if you're going to buy the gold plated board (ENIG) only.
 
 I would encourage you to order RoHS (environmental friendly) wherever you're given that option, paying a very slight extra to do so.  Especially if you appreciate me making these plans freely available and so plan to send me your excess.
### BOM https://github.com/kenneth558/plant_resistance_primary_perception/blob/Free/Where%20to%20find%20everything%20for%20making%20your%20own%20GWAAMC%20device/On%20buying%20the%20components/ibom.html or as follows


qty | part number | one or two sources for purchase
--- | ----------- | ---------------------------------------
1|AD8244|Arrow      https://www.arrow.com/en/products/ad8244armz-r7/analog-devices
1|MSOP-10 PCB ADAPTER BOARD FOR THE AD8244 optional.  Not needed if using a PCB designed for MSOP10 like ours is|AlliExpress   https://www.aliexpress.com/item/50PCS-SOT23-MSOP10-UMAX-to-DIP10-Transfer-Board-DIP-Pin-Board-Pitch-Adapter-NEW/32902829277.html?spm=2114.search0204.3.2.602e4baddaQg2A&s=p&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_10130_5726815_10547_10546_10059_10884_10548_315_10545_10887_10696_100031_531_10084_10083_5726915_10103_10618_10307_449,searchweb201603_60,ppcSwitch_5_ppcChannel&priceBeautifyAB=0
.|.|I encourage you to support this project by mailing me your leftover adapter boards, if you appreciate my information-sharing efforts.  Address available if you'll open an "issue" to ask for it.  Thank you!
2|LM334|Arrow      https://www.arrow.com/en/products/lm334znopb/texas-instruments
.|"|AlliExpress   https://www.aliexpress.com/item/5PCS-LM334Z-TO-92-LM334-3-Terminal-Adjustable-Current-Source-new-and-original-IC/32856893079.html?spm=2114.search0204.3.36.129324fersybG8&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_10130_5727215_318_10547_10546_10059_10884_10548_5727315_10545_10887_10696_100031_10084_10083_10103_10618_452_10307_532,searchweb201603_60,ppcSwitch_0_ppcChannel&algo_expid=a3c22483-ce93-4647-bbe5-d1b3482d0749-5&algo_pvid=a3c22483-ce93-4647-bbe5-d1b3482d0749&priceBeautifyAB=0
 1   | MCP4262-502|Digi-Key     https://www.digikey.com/product-detail/en/microchip-technology/MCP4262-502E-UN/MCP4262-502E-UN-ND/1635819 
.|"|Mouser       https://www.mouser.com/ProductDetail/Microchip-Technology/MCP4262-502E-UN?qs=sGAEpiMZZMuD%2F7PTYBwKqUWe8PKqoc794Kb1a2FsZsY%3D or https://www.microchipdirect.com/product/MCP4262?keywords=MCP4262-502E%2FUN
1|MCP4262-104|Arrow      https://www.arrow.com/en/products/mcp4262-104eun/microchip-technology
2|27 Ohm +-20% resistor, axial leads unless you are a good SMD solderer|Arrow      https://www.arrow.com/en/products/cf14jt27r0/stackpole-electronics
.|"|Digi-Key   https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CF18JT27R0/CF18JT27R0CT-ND/2022704
.|"|Buy from one of the mentioned vendors or Jameco, Mouser, Newark or shop from list: https://www.google.com/search?q=22+ohm+%220.25w%22+axial+resistor&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=sY58XMDxFoXXjwTf0KyQAw&ved=0ahUKEwiAjsjCuefgAhWF64MKHV8oCzIQuw0IwQQoAQ  color code = red violet black
3|470 Ohm +-20% resistor, axial leads unless you are a good SMD solderer. |Arrow      https://www.arrow.com/en/products/cf14jt470r/stackpole-electronics
.|"|Digi-Key   https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CF14JT470R/CF14JT470RCT-ND/1830342
.|"|Buy from one of the mentioned vendors or Jameco, Mouser, Newark or shop from list: https://www.google.com/search?q=680+ohm+"0.25w"+axial+resistor&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=sY58XMDxFoXXjwTf0KyQAw&ved=0ahUKEwiAjsjCuefgAhWF64MKHV8oCzIQuw0IwQQoAQ  color code = yellow violet brown
1|3.3 KOhm +-20% resistor, axial leads unless you are a good SMD solderer|Arrow      https://www.arrow.com/en/products/cf14jt3k30/stackpole-electronics
.|"|Digi-Key   https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CF18JT3K30/CF18JT3K30CT-ND/2022754
.|"|Buy from one of the mentioned vendors or Jameco, Mouser, Newark or shop from list similar to above.  Color code = orange orange red
2|1 MOhm +-20% resistor, axial leads unless you are a good SMD solderer|Arrow      https://www.arrow.com/en/products/cf14jt1m00/stackpole-electronics
.|"|Digi-Key   https://www.digikey.com/products/en?keywords=CF18JT1M00CT-ND
.|"|Buy from one of the mentioned vendors or Jameco, Mouser, Newark or shop from list similar to above.  Color code = brown black green 
1|1.5 MOhm +-20% resistor, axial leads unless you are a good SMD solderer|Arrow      https://www.arrow.com/en/products/cf14jt1m50/stackpole-electronics
.|"|Digi-Key   https://www.digikey.com/products/en?keywords=CF18JT1M50CT-ND
.|"|Buy from one of the mentioned vendors or Jameco, Mouser, Newark or shop from list similar to above.  Color code = brown green green ...
.|"|For the purist, a low-noise (metal film) resistor here does make some sense, but most likely you'll need to place two in series to obtain the correct resistance value.  The shopping exercise is left up to you.
1|2.2 MOhm +-20% resistor, axial leads unless you are a good SMD solderer|Arrow      https://www.arrow.com/en/products/cf14jt2m20/stackpole-electronics
.|"|Digi-Key   https://www.digikey.com/products/en?keywords=CF18JT2M20CT-ND
.|"|Buy from one of the mentioned vendors or Jameco, Mouser, Newark or shop from list similar to above.  Color code = red red green 
2|2.0 µF 16 volt+ tantalum capacitor, radial, low ESR|Arrow      https://www.arrow.com/en/products/t356a225k016at/kemet-corporation
.|"|or buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list being careful for adequate voltage: https://www.google.com/search?q=buy+2.2+%C2%B5F+tantalum+capacitor+radial&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=4o18XKHyNaG0jwTpoK2wBg&ved=0ahUKEwih64zguOfgAhUh2oMKHWlQC2YQuw0I0QgoAQ
2|0.1 µF ceramic capacitor, radial, low dissipation factor|Arrow      https://www.arrow.com/en/products/c323c104m5r5ta/kemet-corporation 
.|"|or buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list: https://www.google.com/search?q=buy+.01+%C2%B5F+ceramic+capacitor+radial&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=so18XKXjG4GMjwTx8ZjAAw&ved=0ahUKEwilhIHJuOfgAhUBxoMKHfE4BjgQuw0I7wgoAg
.|"|1   - 0.01 µF ceramic capacitor, radial
.|"|Arrow      https://www.arrow.com/en/products/ncd103m100z5uf/nic-components 
.|"|or buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list: https://www.google.com/search?q=buy+.01+%C2%B5F+ceramic+capacitor+radial&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=so18XKXjG4GMjwTx8ZjAAw&ved=0ahUKEwilhIHJuOfgAhUBxoMKHfE4BjgQuw0I7wgoAg
.|"|3   - tri color LED or three different colored LEDs: Red, Amber, and Green.  Rectangular (2mm x 5mm) size.  High efficiency (high mcd per mA) is best due to little power available
.|"|Arrow    Yellow - https://www.arrow.com/en/products/ssl-lx2573yd/lumex,
.|"|Red - https://www.arrow.com/en/products/ssl-lx2573id/lumex, and
.|"|Green - https://www.arrow.com/en/products/ssl-lx2573gd/lumex
.|"|Buy from one of the mentioned vendors or Jameco, Digi-Key, Mouser, Newark or shop from list: https://www.google.com/search?q=mcd+led+efficiency+t-1&client=firefox-b-1-d&biw=810&bih=1361&tbm=shop&tbs=p_ord:p&ei=SZd8XKXcC43SsAXcpqaQBQ&ved=0ahUKEwjlpMLbwefgAhUNKawKHVyTCVIQuw0ItgMoAQ
3|MOSFETs to drive the LEDs:|Arrow      https://www.arrow.com/en/products/vn2106n3-g/microchip-technology
2|Potentiometer 50 KOhm or other high value, rotary operation, linear taper, single turn w/knob or cap and mounting means or PCB mount (AKA top adjust)|Arrow      https://www.arrow.com/en/products/ptv09a-4015f-b503/bourns
.|"|https://www.arrow.com/en/products/ptv09a-4030u-b203/bourns
.|"|https://www.jameco.com/z/RV09AF-40-20K-B500K-Taiwan-Alpha-Electronic-500K-Ohm-50-mW-9-mm-20-0-787-Inch-Knurl-Shaft-Solder-Lugs-Linear-Taper-Potentiometer_2272231.html
.|"|https://www.digikey.com/product-detail/en/bourns-inc/PTV09A-4030U-B204/PTV09A-4030U-B204-ND/3781141
.|"|or formulate your own search.  Shorten the shaft you're shopping for (i.e. - take the 4030 in the part number down to 4025, 4020 or 4015) to obtain a wider variety of shopping results, keep the taper to be linear (stay away from ordering audio tapers where that "B" in the part number becomes an "A".
1|ICSP 6 contact socket header|Arrow  long pins: https://www.arrow.com/en/products/ssq-103-03-t-d/samtec 
.|"|or shorter: https://www.arrow.com/en/products/bl206g/fischer-elektronik 
.|"|or https://www.mouser.com/ProductDetail/Samtec/SSW-103-01-T-D?qs=sGAEpiMZZMvffgRu4KC1R5Idk0xWU0s0Ld%252B52Hf5l5s%3D.    
.|"|The length of pins matters when you might decide to use long pins for the other four inter-board header connectors to space the boards farther apart.
1|HX711 ADC (recommended unless you can code for own ADC)|AlliExpress   https://www.aliexpress.com/item/Dual-Channel-HX711-Weighing-Pressure-Sensor-24-bit-Precision-A-D-Module-for-arduino-DIY-Electronic/32878181081.html?spm=2114.search0204.3.2.5f8a7264S5dDtV&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_10130_5726815_10547_10546_10059_10884_10548_315_10545_10887_10696_100031_531_10084_10083_5726915_10103_10618_10307_449,searchweb201603_60,ppcSwitch_5_ppcChannel&algo_expid=719ad9df-13c6-42bc-adff-e19814e28dae-0&algo_pvid=719ad9df-13c6-42bc-adff-e19814e28dae&priceBeautifyAB=0
1|header strip with at least 32 pins if it is a breakaway type|Arrow  short pins:    https://www.arrow.com/en/products/77311-802-36lf/amphenol-fci 
.|"|or, if not a breakaway, 4 different strips of lengths 6, 8, 8, and 10.  You might have leftover header strips with longer pins, in which case the ICSP 6 contact socket header will need to be the longer pin version or else trim all the long pins down to a suitable length.
   
 ##### Repeat tip: If you're not satisfied with any of the sourcing links I've provided, search https://www.findchips.com/search/ for the part.

Newer Version of the HX711 is available instead, but not yet tested:

AlliExpress   https://www.aliexpress.com/item/Free-shipping-Goose-electronic-HX711-module-weighing-sensor-24-AD-module-pressure-sensor-AD-module-SCM/32441222056.html?spm=2114.search0204.3.31.5f8a7264S5dDtV&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_10130_5726815_10547_10546_10059_10884_10548_315_10545_10887_10696_100031_531_10084_10083_5726915_10103_10618_10307_449,searchweb201603_60,ppcSwitch_5_ppcChannel&algo_expid=719ad9df-13c6-42bc-adff-e19814e28dae-4&algo_pvid=719ad9df-13c6-42bc-adff-e19814e28dae&priceBeautifyAB=0

or 1 - ADS1X15 ADC (not recommended due to far lower resolution, so only if it's all that you can come up with...and favor the ADS1115), or code for your own ADC

 ##### Hard-soldered piece of 2-wire cable (shielded or coax advised) from electrodes to circuit   
OR   
3.5mm stereo audio PCB mount jack (Arrow   https://www.arrow.com/en/products/sj1-3523ng/cui-inc), related extender cable (.5m = https://www.arrow.com/en/products/770-10040-00050/cnc-tech-llc 1m = https://www.arrow.com/en/products/770-10040-00100/cnc-tech-llc 1.5m = https://www.arrow.com/en/products/770-10040-00150/cnc-tech-llc), and 3.5mm stereo audio cable mount jack (https://www.arrow.com/en/products/152001/lumberg);   

 ##### electrode assemblies with enough wiring to attach to the above 2-wire cable, optional 4-way light switch at the plant end of that coax (can give you the flexibility easily to reverse the electrical polarity through the plant),  Interconnects and soldering equipment, wiring, circuit substrate, mounting brackets and the like...  If desoldering for repurposing parts, consider doing so with low melt point desoldering solder: https://www.arrow.com/en/products/2668/adafruit-industries or https://www.ebay.com/itm/Solder-wire-low-melting-point-124C-1m-1mm-Bi55-5-Pb44-5-alloy-good-desoldering/171173385076?epid=1531599266&hash=item27daba9374:g:JpIAAOSwq19XBnVh_trksid=p2047675.c100005.m1851

The order of soldering components to the flat circuit board is that the flattest components are placed first, the tallest last, except that no component can cover unused-as-yet solder pads that will need to be soldered to later for a component on the opposite side.  Solder to those pads first of all.  At least one of the semi-conductor components above is engineered with this Oriental-originating caution:

RELIABILITY NOTE:
OUR MANY YEARS OF EXPERIENCE DATA ACCUMULATION INDICATE
THAT SOLDER HEAT IS A MAJOR CAUSE OF EARLY AND FUTURE
FAILURE.  PLEASE PAY ATTENTION TO YOUR SOLDERING PROCESS.

Despite the grammar fail, you'll do well to take to heart its meaning, both for components and the printed circuit board.

### BOM Comparison sites
https://www.findchips.com/search/
AliExpress   https://www.aliexpress.com
Arrow https://www.arrow.com
Mouser https://www.mouser.com
Digi-Key https://www.digikey.com
Jameco https://www.jameco.com
Newark https://www.newark.com/
eevblog Wiki article https://www.eevblog.com/wiki/index.php?title=Component_Search_Engines
 
###  If you end up ordering excess parts and circuit boards and you appreciate my efforts at making these plans available for free to you, I would appreciate donations of your excess.  Please open an "Issue" to ask me for address.
