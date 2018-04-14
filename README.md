# Monitor Plant Tissue Electrical Resistance/Conductance

To monitor electrical resistance changes of plant tissue, such as a leaf, in vivo.  Wemos XI/TTGO XI for cheapest 12-bit 
resolution in Linux with good bootloader and hardware serial.  Avoiding STM32F103C8T6 due to bootloader issues in Linux 
with common USB-serial adapters, avoiding ATTINY85 due to no hardware serial, and avoiding boards whose analog 
resolution is less than 12 bits.  Mac and Windows are assumed to work as well as Linux.  Other boards having at least 
one analog input can be used with little modification.  Be sure you buy a board with a USB port or otherwise are able to 
fashion serial communications.  Periodic improvements are to be expected to this project.

Why would you want to do this?  Here's the story:

In the 1960's, a polygraph expert named Cleve Backster, in a moment of feeling impulsively experimental, attached 
polygraph electrodes to a plant in his office.  Note that polygraph electrodes are used to measure electrical 
conductance of what they are attached to.  Note also that electrical conductance is mathematically inversely related to 
electrical resistance, so resistance and conductance are two ways of referring to the exact same electrical property and 
quantifying a resultant electrical current that an applied voltage produces.  This is in stark contrast to using 
electrodes to measure or determine if a voltage (signal) [is] produced by a something-under-test, which would require 
voltmeter or EEG instrumentation.

Mr. Backster hooks up his electrodes and eventually notices that the polygraph machine indicated the electrical
resistance/conductance of his office plant deviated in response to his mere intention of harming the plant.  You read 
that correctly.  The plant was obviously aware of Mr. Backster's very intentions to do something to the plant that would 
substantively affect its well-being.  At the time, there was no known scientific basis for such a phenomenon as plant 
awareness to ANY extent, much less to the extent of being super-humanly aware of a person's very thoughts as Mr. 
Backster observed.  Today, quantum physics may offer a scientific explanation for what is happening...and then again, it 
may not.

Fast-forward to 2006 when Mythbusters television program decided they would investigate the validity of Mr. Backster's 
observations (Title: Deadly Straw, Season number: 4, Episode number: 22, Air date: September 6, 2006).  When Mythbusters
used a polygraph machine as Mr. Backster had, their results confirmed the phenomenon, albeit against their will and 
against their desire to document its existence.  So in order to find a halfway-plausible excuse to keep Episode 22 from 
disrupting their entertainment-business-as-usual, they switched from using a polygraph machine to using an EEG machine, 
which measures voltage signals produced by neuron bundles instead of measuring the property of resistance; remember that 
elevctrical conductance is a property of the plant tissue, NOT a signal produced by the plant.  Plants have no neurons, 
silly Mythbusters - they don't produce voltage signals.  Mythbusters ignored their observations obtained from the 
polygraph machine but thankfully did broadcast the recorded video of their efforts while presenting a deceptive 
narrative to try to distract viewers from noticing that they had just proven the existance of "primary perception", as 
Mr. Backster thought to call his newly-discovered phenomenon.

With the rudimentary (periodic improvements are to be expected to this project) sketch I publish here for you, you can 
observe for yourself that plants actually can know your intentions relative to affecting their well-being.  You'll also 
need to fashion the electrode system and attach it.  I suggest you not get so wrapped up in being scientifically 
credible that you miss the point of all this.  The point is that the electrical resistance of a plant can respond to 
someone's intent to substantively affect its well-being.  The point is NOT that any particular readings can be precisely 
replicated.  With that caveat and because of it, I suggest a very primitive electrode system that does not involve the 
salt-impregnated agar-on-cotton gauze-on-stainless steel system that Mr. Backster thought he had to use for scientific 
credibility.  I would suggest the more bio-compatible elements of mud inside a pure, coarse-knit linen pouch (true linen 
is made of very biocompatible flax).  Poke the electrode wires into the pouches, but keep the metal of the wires from 
direct contact with any plant tissue, since metals are foreign to living organism tissues and so may produce an 
unaccounted for reaction.  To ensure an acceptable quality contact between the mud and electrode wires, I attach 
electric motor brushes (made from near biologically inert and oxidatively stable graphite) to the ends of the electrode 
wires and insert the the brush into the pouch. I prefer using mud instead of salt as an electrolyte for my confidence 
achieving maximum biocompatibility.  I ensure the mud is adequately liquified and the brush is fully inserted into the 
mud and the muddied pouch is in intimate and stable contact with the leaf or other plant tissue.  You'll have to rig 
some sort of pouch-holding device of your own design.
Unless your plant has large leaves, you may find it difficult to place opposite electrodes on a single leaf without one 
pouch shorting across to the opposing pouch, so I suggest trying to put each electrode-pouch on its own leaf.  Note that 
you'll be best served by understanding the electrical circuit being formed by your electrode placements.  As long as you 
do so, multiple electrodes of each polarity are acceptable.

Note that the electrode circuit must also consist of a resistive component attached by you between the power supply rail 
and the analog input pin of the signal electrode.  That resistor is located locally to the board so does not require 
a third length of wire. The electrode wire not going to the analog input pin goes to signal ground and will be referred 
to as the reference electrode.  Signal ground is determined by you as a ground pin of the active device that contains 
the ADC, preferably a pin provided for the precise purpose of being  signal ground.  For best practice, avoid attaching 
the reference electrode to any point on circuit board ground that connects to a component other than the ADC device 
before connecting to the ADC.  Ideally, the value of resistance of this component will be as equal as practical to the 
resistance of the plant tissue under test.  The resistance of the plant tissue between the electrodes can be decreased 
or increased by adjustment of the surface area in contact with the electrode pouches - more contact are gives less 
resistance as well as a better signal-to-noise ratio but also probably produces greater undesirable measurement effect.  
At this stage, end-users are on their own to learn about how to avoid electrical current leakage paths.  As far as avoiding radiated electrical noise, maintain adequate distance from flourscent and neon lighting and any other source of noise you discover.

Note: According to Mr. Backster, the plant under test must have already become "acclimated" to the person performing the
primary perception procedures for the phenomenon to be observable.  Take that to mean what you will.  I believe it means 
you'll need to spend some time initially watering the plant or otherwise caring for it before you can expect significant 
results from this project.  Until I'm shown wrong, I'm fairly certain that hostile or hurtful sentiments toward the plant are counter-productive to sustained acclimation, Mythbusters!

For you Bible-believers, you may be interested to read some of the Biblical justification for this project.  See the document entitled per that subject listed among the documents of this project.
