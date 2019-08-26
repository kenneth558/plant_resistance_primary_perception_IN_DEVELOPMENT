**Current Operational Status:** As of 25 Aug 2019, I have the newest circuitry working at both 3.3VDC and 5VDC. Now the sketch needs to catch up with this new circuit, so I still have development to do.


Incidentally, since the current through the DUT used to measure conductance is referenced to Vcc, any variances in Vcc affect the output.  I looked into zenering the VREF, but don't have the board space to place the diode and don't have the urgency to put the time in right now to deal with that.  Such a diode would only correct 5VDC power variances, but I think that is all it would need, since USB connection instabilities only affect 5VDC.  For now, I simply recommend getting the SainSmart UNO that is switchable between 5 and 3.3 V plus gives you access to ADC6 and ADC7 as a bonus.
