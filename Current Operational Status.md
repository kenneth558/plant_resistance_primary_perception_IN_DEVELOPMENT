**Current Operational Status:** As of 25 Aug 2019, I have the "newest" circuitry working at 5VDC, but it is not fully stable at 3.3VDC when a transient overload condition occurs.   Investigating this...
In using the word "newest" I don't include my upcoming LDO and paralleled MCP4262-502's.  That rev should come out before the end of this month (Sep 2019) as Rev 8.  Please wait for me to publish Rev 8.


Incidentally in the published PCB layout, since the current through the DUT used to measure conductance is referenced to Vcc, any variances in Vcc affect the output.  I am working on a modified layout wherein I've already incorporated an LDO that corrects that one issue, but until I have it able to handle a flex circuit comprising MCP4262-502's needing to be paralleled with U6 [of the old U numbering system which means U8 and higher in the new U numbering system], I can't put the new layout out for general consumption.
