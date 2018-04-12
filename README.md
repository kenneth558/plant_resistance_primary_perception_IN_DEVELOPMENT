# Measure or Monitor Plant Tissue Resistance

To measure electrical resistance of plant tissue such as a leaf.  Wemos XI/TTGO XI for cheapest 12-bit resolution in Linux
with good bootloader and hardware serial.  Avoiding STM32F103C8T6 due to bootloader issues in Linux with common USB-serial
adapters, avoiding ATTINY85 due to no hardware serial.  Avoiding boards whose analog resolution is less than 12 bits.

Why would you want to do this?  Here's the story:

In the 1960's, a polygraph expert named Cleve Backster, in a moment of feeling impulsively experimental, attached polygraph
electrodes to a plant in his office.  Note that polygraph electrodes are used to measure electrical conductance of what 
they are attached to.  Note also that electrical conductance is mathematically inversely related to electrical resistance,
so resistance and conductance are two ways of referring to the exact same physical phenomenon of quantifying a resultant 
electrical current that an applied voltage produces.  This is in stark contrast to using electrodes to measure or determine
if a voltage [is] produced by a something-under-test, which would require voltmeter or EEG instrumentation.

Mr. Backster eventually noticed that the polygraph machine indicated the electrical resistance/conductance of his office
plant deviated in response to his mere intention of harming the plant.  You read that correctly.  The plant was obviously 
aware of Mr. Backster's very intentions to do something to the plant that would substantively affect its well-being.  At 
the time, there was no known scientific basis for such a phenomenon as plant awareness to ANY extent, much less to the 
extent of being super-humanly aware of a person's very thoughts as Mr. Backster observed.

Fast-forward to 2006 when Mythbusters television program decided they would investigate the validity of Mr. Backsters 
observations (Title: Deadly Straw, Season number: 4, Episode number: 22, Air date: September 6, 2006).  When Mythbusters
used a polygraph machine as Mr. Backster had, their results confirmed the phenomenon, albeit against their will and against
their desire to document its existence.  In order to find a halfway-plausible excuse to keep Episode 22 from disrupting 
their entertainment-business-as-usual, they switched from using a polygraph machine to using an EEG machine, which measures
voltage signals produced by neuron bundles instead of measuring the property of resistance, which involves no signal 
production.  Plants have no neurons, silly Mythbusters.  They ignored their observations obtained from the polygraph
machine but thankfully did broadcast the recorded video of their efforts while presenting a false narrative to try to 
distract viewers from noticing that they had just proven the existance of "primary perception", as Mr. Backster thought to
call it.

With the rudimentary sketch I publish here for you, you can observe for yourself that plants actually can know your 
intentions relative to affecting their well-being.  You'll also need to fashion the electrode system and attach it.  I 
suggest you not get so wrapped up in being scientifically credible that you miss the point of all this.  The point is that
the electrical resistance of a plant can respond to someone's intent to substantively affect its well-being, not that any
particular readings can be precisely replicated.  With that caveat and because of it, I suggest a very primitive electrode
system that does not involve the salt-impregnated agar-on-cotton gauze-on-stainless steel system that Mr. Backster thought
he had to use for scientific credibility.  I would suggest the more bio-compatible elements of mud inside a pure, coarse-
knit linen pouch (true linen is made of flax).  Poke the electrode wires into the pouches, but keep the metal of the wires
from direct contact with any plant tissue, since metals are foreign to living organism tissues and sp produce an 
unaccounted for reaction.  To ensure an acceptable quality contact between the mud and electrode wires, I attach electric
motor brushes (made from near biologically inert graphite) to the ends of the electrode wires and insert the the brush 
into the pouch. I prefer using mud instead of salt as an electrolyte for my confidence achieving maximum biocompatibility.
