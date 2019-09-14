**Current Operational Status:** As of 25 Aug 2019, I have Rev. 7 circuitry working at 5VDC, but it is not fully stable at 3.3VDC when a transient overload condition occurs.  On top of that, operating the Rev. 7 PCB has shown me that I needed to make a change to the circuitry.  I've made the design change and await delivery of the new PCB, named Rev. 8.  It will need a flex circuit board plugged into it.  The flex board is designed as well, and I await its delivery.  Please wait until mid- to late-October 2019 for that to arrive, get built, and be tested.

If you wonder what it was about Rev. 7 that I needed to change, it was the fact that I had made the current-to-voltage-signal stage far more sensitive than the LSB dPot could zero in on for screen placement.  IOW, as small as the LSB dPot step was, it simply was not a small enough resistance step to change the trace placement finely enough not to overshoot the entire screen during auto-adjust.  The only solution I could think of to this problem is parallel several of those dPots together...26 of them, in fact.  That is where the flex board comes in - it holds all those other dPots.  By using 26, their entire device resistance value becomes as close as possible to equaling one single resistance step of the MSB dPot.  That is the ideal resistance relationship between LSB and MSB.  The math with proper use of units is as follows:

1 step MSB is                            50000 ohms per device / 256 steps per device = 195.3125 ohms = 195 ohms

a single LSB device full resistance is   5000 ohms per device

number of LSB devices to parallel
    together to make their full
    resistance value equal to 195 ohms is   5000 ohms per device / 195 ohms = 25.6 devices
    

By paralleling a half device more than the optimal number, there will be a small adjustment step region that will be inaccessible in terms of achieving a fine-tune into with any LSB/MSB step combination.  You may actually prefer the alternative to that.  Twenty-five dPots paralleled with each other which would make each adjustment step just a little larger and result in a small adjustment step region of each MSB step that could be adjusted into by either of two MSB/LSB step combinations.  Which scheme is better will depend on the conductance range of DUTs your working with - 25 devices paralleled will be better suited for DUTs with higher conductance (lower DUT resistance).
