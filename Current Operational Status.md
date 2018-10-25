Current Operational Status is that [this sketch](https://github.com/kenneth558/plant_resistance_primary_perception/blob/Free/sketch%20code/adc_for_plant_tissue.ino) is fully operational in a very specific circuit configuration.  

The specific circuit configuration you'll need with this current sketch version can be described as follows.  The description is to some extent covert because this stage of development will require you to be or become conversant/knowledgeable about things electronic and Arduino anyway.

Two MCP4162-503 with some way to connect into the circuit.  The sketch code refers to these as LSB.

Two or Four MCP4162-104 with some way to connect into the circuit.  (Confused how many? My development circuit is built with four, but two of those four never impact operation.  The sketch thinks there are four.  I believe having only two will work fine.)  The sketch code refers to these as MID and MSB.  Only the MID impacts operation.

Two LM334 ICs with some way to connect into the circuit - each need their + pins connected to Arduino 5v power.  Each also needs one MCP4162-503 digipot resistor and half the amount of MCP4162-104 digipot resistors connected in series between their current programming pins and their - pins.  Connect each digipot CS pin to the appropriate Arduino Digital pin based on comments in the sketch code.

One minimal-wattage resistor of similar resistance as the plant tissue (1 Mohm works for me, and I am amazed that such a common value seems to work) with some way to connect into the circuit.

One AD8244 with soldering where-with-all and skills to match.  These tiny parts are microscopic in size, since they were never intended for use by the hobbyist market.  Solder to the MSOP-10 PCB ADAPTER BOARD listed next or maybe you know of an inexpensive socket you can use instead.  I wish I knew of such a socket, but I don't.

One MSOP-10 PCB ADAPTER BOARD with some way to connect into the circuit.

One HX711 with some way to connect into the circuit.  In my early development work, I got the ADS1015 and ADS1115 working, but have not kept that functionality maintained.  Hopefully it still works.  I advise a unique connection into the ADS1x15 circuit ground as I describe on the page entitled "[More construction details.md](https://github.com/kenneth558/plant_resistance_primary_perception/blob/Free/More%20construction%20details.md)".

Power supply decoupling (low ESR) capacitors as needed with some way to connect into the circuit.  At least .1uF in capacitance.  The digipots may need .5uF-2.0uF or more just for them in totality as I am seeing some artifact in my development circuit that I should investigate later before quitting my day job.

Arduino board with power/serial communications cable.  I am doing my latest development work on a Leonardo, but my earlier work was done on the Uno.  I have written my code to accommodate the TTGO XI, but have never tried the sketch with it.


The changes I am still developing are merely changes to #1) allow more flexibility in the circuit and #2) speed up resistance range changes during use.  Circuitry flexibility hopes are to allow both fewer and more digital potentiometers per bridge leg, to allow bridge legs to be made without LM334s, to allow non-LM334 legs to be unbridged, to accommodate outboard ADCs of types beyond the HX711, and to allow for use of more than just one outboard ADC.

