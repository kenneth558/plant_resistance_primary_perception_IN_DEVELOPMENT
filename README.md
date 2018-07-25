# <p align="center">Telempathic Gardening - Promoting a Reviving Civility (TM)
[Click here to see what this title means](https://github.com/kenneth558/plant_resistance_primary_perception/blob/Free/what%20the%20title%20means.md)
### <p align="center">plans and Arduino sketch for the training aid
-------------
As of 30 April 2018, this sketch is functional, only requiring low-noise construction techniques of the connections and circuitry.  However, until further notice, THIS .INO FILE IS UPDATED **_OFTEN_** FOR IMPROVEMENTS AND BUGFIXES.  
        
If you are using the ADS1015 or ADS1115, using a AD8244 is recommended and be sure to install the supporting library Adafruit_ADS1015 since this sketch depends on it.  Thank you, Adafruit!  If you're using the HX711, using a AD8244 is required and install the .cpp and .h files located here: https://github.com/bogde/HX711 (thank you to bogde) Consideration is being given to adapting a fork of this project to the Raspberry Pi-ish ARM single board computers.  This sketch *version* is FREE so that anyone can enjoy it.  For those of you who can afford to support my work on this project, I will offer a "not-free" sketch version when the parts arrive that has the following enhancements:

-  Arrange for adjustments of various kinds during run time based on keyboard inputs.  The current plotter included with 
        the Arduino IDE does not accommodate this, so this feature will have to be coded with a different language and run
        by software other than the IDE.
-  Use an LM334 or two to prevent power supply noise from plotting (i.e., convert from monitoring resistance to monitoring 
        conductance, which means that power supply noise is eliminated!).  A toroid-based noise suppression coil in series 
        with the LM334 might be needed as one of the supporting components.  Since the part includes a temperature coefficient,
        a second one is also needed for offset for stable balance with temperature drift.
-  Use digital potentiometer (MCP41XX2 or MCP42XX2) for more automated balancing of the two serial resistances.

Add-on ADCs, especially the more affordable ones, tend to have inputs that are of such low-impedance that they don't work unbuffered in this project where the plant is high impedance (high resistance).  That problem might be able to be partially overcome by increasing the leaf surface contact area of the electrodes, but the more reliable and proper way is to buffer the electrodes with an AD8244 when using an outboard ADC (or when using the inboard Analog Inputs if using the TTGO XI/Wemos XI board).  Two challenges with that are the added cost would justify using a more espensive, high input impedance ADC.  I don't know which one[s] would so work because input impedance is not usually specified in ADC datasheets.  The other challenge is the extremely tiny package (MSOP) of the AD8244, not to mention the additional failure risks whenever the complexity and parts count of any electronics device is increased.  With the tiny package, the part is very difficult solder and even just keep track of in a hand-constructed project...it is too easily dropped and not easily found afterward.  The 'M' in MSOP could just as well mean "microscopic".  That said, in the interest of simply moving forward with the project, I'm using the AD8244 in my own development environment, benefiting from the flexibility I gain from using that part to drive whatever ADC I want to develop for.  [My most recent source buying the AD8244.](https://www.arrow.com/en/products/ad8244armz-r7/analog-devices)
  
------------
## So why in the world would you want to observe a plant's electrical conductivity?  Here's the fascinating story:

In the 1960's, a polygraph expert named Cleve Backster, perhaps in a moment of feeling impulsively experimental, attached polygraph electrodes to a plant in his office to see what polygraph results would come from watering the plant.  Note that polygraph electrodes are used to measure electrical conductance of what they are attached to.  Note also that electrical conductance is mathematically inversely related to electrical resistance, so resistance and conductance are two ways of referring to the exact same electrical property, which is examined by quantifying a resultant electrical current that an applied voltage produces.  This is in stark contrast to using electrodes to measure or determine if a voltage (signal) [is] produced by a something-under-test or device-under-test ("DUT"; the plant, in this case), which would require voltmeter or EEG instrumentation.

Mr. Backster hooks up his electrodes and eventually notices that the polygraph machine indicated the electrical conductance of his office plant deviated in response to his mere intention of harming the plant.  You read that correctly.  The plant seemed to be *aware of Mr. Backster's very intentions to do something to the plant* that would substantively affect its well-being, because it responded BEFORE Backster's intended action was ever performed.  Mr. Backster pursued the experiment to see if the results consistently indicated the plant was aware of those intentions, and they very much were!  At the time, there was no known scientific basis for such a phenomenon as plant awareness to ANY extent, much less to the extent of being super-humanly aware of a person's very thoughts as Mr. Backster observed.  Today, quantum physics may offer a scientific explanation for what is happening...and then again, it may not.

Fast-forward to 2006 when Mythbusters television program decided they would investigate the validity of Mr. Backster's observations (Title: Deadly Straw; Season number: 4; Episode number: 22; Air date: September 6, 2006).  When Mythbusters used a polygraph machine as Mr. Backster had, their results confirmed the phenomenon, albeit against their will and against their willingness to document its existence.  So in order to find a halfway-plausible excuse to keep Episode 22 from disrupting their entertainment-business-as-usual, they switched from using a polygraph machine to using an EEG machine, which measures voltage signals produced by neuron bundles instead of measuring the property of resistance.  

To understand how Mythbusters erred in their experiment, you need to realize that measuring a property of something requires the person performing the measurement to produce their own signal and measure the results from applying that signal to the device-under-test.  That is what a polygraph machine does.  An EEG machine, on the other hand, produces no signal of its own - it measures a device-produced signal and is specifically designed to measure the specific type of signal that is produced by a central nervous system neuron bundle that is not found in plants but found in higher organisms.  Plants have no neurons, silly Mythbusters - they don't produce voltage signals that an EEG machine can detect.  Mythbusters ignored their observations obtained from the polygraph machine but thankfully did broadcast the recorded video of their efforts while presenting a deceptive narrative about the positive results so as to try to distract viewers from noticing that they had just proven the existance of "primary perception", as Mr. Backster thought to call his newly-discovered phenomenon.

In the sketch source code of this project, you'll find some self-explanatorily-named constants near the top that you'll need to set for your preferences and configuration.  Find and adjust these:

-  NUM_INPUTS_TO_PLOT_OF_INBOARD_ANALOG
-  NUM_INPUTS_TO_PLOT_OF_ADDON_HIGHEST_SENSI_ADC
-  HIGHEST_SENSI_ADDON_ADC_TYPE (at this time only HX711 is supported)
-  MULTIPLICATION_FACTOR
-  HIGHESTBITRESFROMHIGHESTSENSIADDONADC
-  ANALOGINPUTBITSOFBOARD
-  SAMPLE_TIMES
-  DELAY_TIME_BETWEEN_SAMPLES_MS
-  DELAY_TIME_BETWEEN_SAMPLES_US
-  look for others in the same vicinity that get added because of code enhancements

The specific purpose of this project is to monitor electrical conductance changes of plant tissue, such as a leaf, in vivo.  Tested with Uno, Leonardo, and Wemos XI/TTGO XI.  The TTGO/WeMos board will require either an ADS device or a unity gain buffer (AD8244) to use the TTGO's ADC.  Mac and Windows are assumed to work as well as Linux.  Avoiding STM32F103C8T6 due to bootloader issues in Linux with common USB-serial adapters, avoiding ATTINY85 due to no hardware serial.  Other boards having at least one analog input can be used, or add the very inexpensive ADS1115 or HX711 for best resolution.  IMPORTANT: When selecting a board you'll use for this project, make sure it has a USB port or that you are otherwise able to fashion serial communications. The output from the Arduino is formatted for input into the Arduino IDE serial plotter rather than the serial monitor.  Also, I am well aware of the possibility that the electrical property being monitored may not precisely be conductance but rather the appearance of conductance due to something akin to dynamic polarization, electrically speaking, of plant tissues.  This could be a vitally important factor to consider in electrode "placement-ology", if you will.

With the rudimentary (periodic improvements are to be expected to this project) sketch I publish here for you, you can observe for yourself that plants actually can know your sentiments as they relate to the plant's well-being.  You'll also need to fashion the electrode system and attach it.  I suggest you not get so wrapped up in being scientifically credible that you miss the point of all this.  The point is that the electrical conductance of a plant does respond to someone's intent to substantively affect its well-being.  The point is NOT that any particular readings can be precisely replicated.  With that caveat and because of it, I suggest a very primitive electrode system that does not involve the salinated agar-on-cotton gauze-on-stainless steel system that Mr. Backster thought he had to use for scientific credibility.  Until I am satisfied with successful proof-of-concept of this project, I am suggesting using the more bio-compatible elements of mud inside a coarse-knit pouch made of non-dyed, non-bleached plant-derived fabric like burlap, linen, cotton, and/or hemp.  I suggest for each pouch/electrode used that you fashion a sling to bear the weight of the pouch using a matching strip of fabric.  What bothers me about stainless electrodes is that metals produce galvanic voltage from their very contact with dissimilar materials.  I suspect a galvanic potential could also be generated by contact with some other element of this apparatus also.  The significant chromium content of stainless is another concern I have.

Poke the electrode wires into the pouches (or maybe one into a pouch and one into the soil?), but keep the metal of the wires from direct contact with any plant tissue, since metals are foreign to living organism tissues and so may produce an unaccounted for reaction.  To ensure an acceptable quality contact between the mud and electrode wires, I attach electric motor brushes (made from near biologically inert and oxidatively stable graphite) to the ends of the electrode wires and insert the the brush into the pouch. I prefer using mud instead of salt as an electrolyte for my confidence achieving maximum biocompatibility. Ensure the mud is adequately liquified and the brush is fully inserted into the mud and the muddied pouch is in intimate and stable contact with the leaf or other plant tissue.  You also may want to learn the difference between hypostomatous and hyperstomatous leaves relative to the plant you use if you care to avoid blocking the gas-exchange stomata.  Blocking the stoma with the electrode apparatus may generate yet another source of stress for the plant, thus I recommend stoma-blocking be minimized in terms of time and surface area.  Nearby flourescent lighting and other high-harmonic and/or heavy electric loads may produce unwanted artifacting, so they are best kept away from.

You'll have to rig some sort of pouch-holding device of your own design.  Maybe a large non-conductive (plastic/wooden) easel could be used to support the fabric sling.  Unless your plant has large leaves, you may find it difficult to place opposite electrodes on a single leaf without one pouch shorting across to the opposing pouch, so I suggest trying to put each electrode-pouch on its own leaf.  The weight of the mud-filled pouch on the top side of the leaf will be enough force to maintain a solid electrical contact.  This configuration is for hypostomatous, the most common type leaves you'll be using.

Note that you'll be best served by understanding the electrical circuit being formed by your electrode placements.  As long as you do so, multiple electrodes of each polarity might be of benefit, but I really think you're better off avoiding any circuit more complex than you understand.

**_Note that the electrode circuit must also consist of a resistive component attached by you between the power supply rail and the analog input pin of the signal electrode._**  That resistor is located locally to the board so does not require a third length of wire. The electrode wire not going to the analog input pin goes to signal ground and will be referred to as the reference electrode.  **_All mention of LM334 in this project refers to replacing that resistor with an LM334 and a few support components._**  Signal ground is determined by you as a ground pin of the active device that contains the ADC, preferably a pin provided for the precise purpose of being  signal ground.  For best practice, avoid attaching the reference electrode to any point on circuit board ground that connects to a component other than the ADC device before connecting to the ADC.  Ideally, the value of resistance of the above mentioned resistive component will be as equal as practical to the resistance of the plant tissue under test.  The resistance of the plant tissue between the electrodes can be decreased or increased by adjustment of the surface area in contact with the electrode pouches - more contact area gives less resistance as well as a better signal-to-noise ratio but also probably produces greater undesirable measurement effect. At this stage, end-users are on their own to learn about how to avoid electrical current leakage paths.  As far as avoiding radiated electrical noise, maintain adequate distance from fluorescent and neon lighting and any other source of noise you discover, understanding that your computer and cell phone are definite noise sources.

For those who have to ask the cost of the electronics parts (I happen to be in that category myself) you will be interested to know that I bought the TTGO XI (WeMos XI) for about $1.65 US (free shipping) and the ADS1115 for about $1.73 US (free shipping).  I realize you have to do some soldering or spring loading the contacts that way, but it saved me over $15 US not having to buy an Arduino Due to obtain better resolution than 10 bits.  The added benefit is that I now have 16 bit resolution...well, 15 bit in reality, because of the difference between advertised resolution for balanced/double-ended configurations vs. real resolution of single-ended configurations.  The HX711 can be found for $0.75 US (free shipping).   Note that I bought the parts through AliExpress and had to wait 30 days of shipping b/c I was not willing to pay extra for expedited shipping.  Don't forget the USB cable, interconnect wires, and perfboard/breadboard you'll need.  Note that the inboard 12-bit ADC integrated in the TTGO XI/WeMos XI is worthless unless you want to accept the hassle of designing and constructing your own analog buffering (perhaps with an LM328-based circuit).  This is b/c that board's analog inputs inexplicitely pathetically contain engineered-in unremoveable pull-up conductance.

Note: According to Mr. Backster, the plant under test must have already become "acclimated" to the person performing the primary perception procedures for the phenomenon to be observable.  Take that to mean what you will.  I believe it means you'll need to spend some time initially watering the plant or otherwise caring for it before you can expect significant results from this project.  Until I'm shown wrong, I'm fairly certain that hostile or hurtful sentiments toward the plant are counter-productive to sustained acclimation, Mythbusters!  If you can video record your success with this phenomenon, I will be very interested in including your resultant YouTube video in my playlist here: https://www.youtube.com/playlist?list=PL5o95K6gCP735crox7Aoe7EkTgvywbxmJ.  Note that I am quite UNinterested in videos that express negative sentiments, so I may not link to them.  Instead of exercising your negative power over plants, please try to show us results from POSITIVE sentiments...and thank you for that!

You may be interested to read some of the Biblical justification for this project.  See the document entitled on that subject listed among the documents of this project.

For those who have any regard to NDEs, you would be interested to research Howard Storm's NDE relative to world lifestyle of the future.

Submit an "Issue" or post in the "Wiki" (tabs above) to have me add your Youtube video to the official playlist for this 
project.
