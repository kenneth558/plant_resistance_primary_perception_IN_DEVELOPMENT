 ### DO NOT OPEN PACKAGING FOR U3 (REF200) UNTIL YOU ARE READY TO SOLDER IT IN PLACE AND SOLDER-SEAL SHLD1 AS A SINGLE STEP!  That IC is a high precision component that is designed to give you highest performance when always kept in a very low humidity environment.  This is also why SHLD1 and all the micro-vias under it should be solder-sealed into hermetically sealed containment.  If you open that package too soon, here are the instructions to remedy: 
 1. Calculated shelf life in sealed bag: 12 months at <40C and <90% RH from bag seal date.
 2. Peak component body temperature for attention soldering: 260C(500F)
 3. After bag is opened, devices that will be subjected to reflow solder or other high temperature process must be 
   a) Mounted within 168 hrs of factory conditions of <30C/60% RH, or
   b) Stored per J-STD-033
 4. Devices require bake before mounting if:
   a) Humidity indicator card reads >10%
   b) When 3a or 3b are not met
 5. If baking is required, refer to IPC/JEDEC J-STD-033 for bake procedure.

This project is difficult to build.  If you think you can do it without use of a microscope, I'll bet against you.  If you can find in your heart to get a microscope, you'll be able to put it to good use later to visually magnify growth of the plant at the ends of branches as yet another means of real-time feedback.

The hardest aspect of construction might be soldering the SMDs.  I think it will be easier for you if #1) you use low temperature solder that melts below soldering iron temps of 250 ºC/480 ºF, and #2) your PCBs are NOT tinned (OSH Park gold plating works fantastic) so the surface will be perfectly flat under the MSOP10 - if the MSOP10 pads are already tinned or soldered to, try to clean their surfaces down to a level below the inter-pad solder mask level (don't scrape or sand them clean with anything blunt or you'll also wear down the inter-pad solder mask).  Higher temperatures than 300 ºC tend to cause delamination of the PCB, but more importantly, at least one device, the REF200, cannot withstand a soldering temperature of greater than 260 ºC/500 ºF per the manufacturer's datasheet.  And #3) adhere the components down en masse in each step, then solder them all in one pass.

That advice from someone who has yet to fully succeed soldering together aeven a single board of this project.  So take it with a grain of salt.

Solder that melts at that low of temperature will not be the classic wire solder.  It will be paste solder (I refuse to call it "solder paste" even though that's what it is marketed as) that contains solder in powdered form.  (I prefer only to use the term "solder paste" with the traditional rosin paste that does not contain solder to avoid confusion, but I think I'm ahead of my time there.  You'll actually use what everyone else calls "solder paste"...and keep it refrigerated).

For anyone searching sites that give soldering tips, just remember that most boards are single sided while this project provides the design for a two sided board with components on both sides.  So remember that you'll be soldering components to the second side while the first side's components must not fall off from getting their solder re-flowed.  Decide how you'll keep that first side cool while soldering the second side.

OPTIONAL:  Quick and dirty operation can be achieved with just the Arduino and the DUT with balancing resistor connected to +5 VDC...and electrodes  Just set the appropriate pre-processor macros:  disable the USING_LM334... macro, the NUM_OF_OUTBOARDS... macro [and maybe the SUPERIMPOSE_FIRST_INBOARDS... macro if you want two pins plotted magnified (superimposing disables the magnified view of a signal)].  IOW, the AD8244, digipots, and high sensitivity ADC are optional if you just want to see a plotline respond to your finger touching it.  The digipots also won't do anything for you if you use a rail-to-rail ADC, as the ADS1X15 is.  

You might be able to be notified of my changes to the project by GitHub settings, if you use the Github cloning & tracking feature, maybe...cloning is not a GitHub feature I've ever used, yet.

Electrodes are vaporware as of yet: I'm trying conductive foam or conductive sheet plastic.

Link to BOM: https://github.com/kenneth558/plant_resistance_primary_perception/blob/Free/BOM%20PCB%20Ordering%20links.md

NOTE IF 3.3V OPERATION IS DESIRED:  Pin 5 of J2 will have to be omitted and the pad of the adjacent pin 4 J2 will have to be shorted over to the pad of that pin 5.  I neglected to leave room for the jumper to do this.  Sorry!   Only do this when pin 2 of ICSP1 from the MCU is also providing +3.3V!!!!

If for some odd reason you are stuck using the "not recommended due to far lower resolution" ADS1X15, observe the following 3 points:

 ##### 1.  A decoupling capacitor is required at the ADS1X15 device VDD to GND.  From the datasheet:
>Good power-supply decoupling is important to achieve optimum performance. VDD must be decoupled with at least a 0.1-μF capacitor, as shown in Figure 47. The 0.1-μF bypass capacitor supplies the momentary bursts of extra current required from the supply when the device is converting. Place the bypass capacitor as close to the power-supply pin of the device as possible using low-impedance connections. Use multilayer ceramic chip capacitors (MLCCs) that offer low equivalent series resistance (ESR) and inductance (ESL) characteristics for power-supply decoupling purposes. For very sensitive systems, or for systems in harsh noise environments, avoid the use of vias for connecting the capacitors to the device pins for better noise immunity. The use of multiple vias in parallel lowers the overall inductance, and is beneficial for connections to ground planes.

 ##### 2.  An RC filter to each used ADS1X15 analog input is advised by the manufacturer.  From the datasheet:
>...any noise pick-up along the sensor wiring or the application circuitry can potentially alias into the pass-band. Power line-cycle frequency and harmonics are one common noise source. External noise can also be generated from electromagnetic interference (EMI) or radio frequency interference (RFI) sources, such as nearby motors and cellular phones. Another noise source typically exists on the printed-circuit-board (PCB) itself in the form of clocks and other digital signals. Analog input filtering helps remove unwanted signals from affecting the measurement result...

 ##### 3.  Unused analog input pins of the ADS1X15 should not be connected to GND or more power supply current will be drawn than is necessary.  From the datasheet:
>Either float unused analog inputs, or tie the unused analog inputs to midsupply or VDD. Connecting unused analog inputs to GND is possible, but may yield higher leakage currents than the previous options.

Many other application tips are in the datasheet.  I don't mean to discourage you with technical reading, but those tips _are_ useful, and some diagrams are in there that could help hold your attention.  I won't include any links here b/c they so often go dead.  I'll offer one tip I didn't find stated very clear in the datasheet concerning ADS1X15 ground path.  When the ADS device is configured for single-ended as opposed to differential usage, the reference electrode wire should connect to the ADS1X15 approaching it from the opposite direction that it connects to the Arduino GND.  In other words, looking at the ADS1X15, it is a two sided device, front and back, where two two sides are divided from each other by a single row of pins.  If the Arduino GND connects via the back side, then the reference electrode wire should connect via the front side, and vice versa.  This means that the common practice of soldering header pins that exit only from the back side of the ADS1X15 should be critically reconsidered for its GND pin.  A longer than normal pin or wire should be used so it can provide connection both from the front side of the ADS1X15 and from the back, as in the picture below.![How the ground pin needs to extend from both sides of the ADS board](https://github.com/kenneth558/plant_resistance_primary_perception/blob/Free/embeddeds/adc%20primary%20perception%20ADS%20board%20ground%20pin%20cropped.png)You'll note that I had no long pin so I could only push the standard-length pin halfway through the board.  It was only barely long enough on each side, emphasis on "barely".  

The power decoupling capacitor must *not* be connected on the ADS1X15 signal side of that pin/wire, yet as close as possible on the other (power) side.
