 - When laying out the PCB - 



1.  Long runs across board:  
Any scenario where other yet-to-be-laid-down runs might need to cross current run, weave the trace repetitively from one board side to the other throughout length of travel.  Each stitch should be long enough for one or several cross-directional traces to run side by side each other "underneath" the stitch.
The aforementioned scenario does not and cannot exist along board edges and along the sides of shields and pads of other components where those pads are of longer lengths.  Do NOT weave traces running past and alongside those pads - keep the new traces on one board side or the other for that distance so that the other side of board is totally free to be used for an exact replica (you can't place any vias along these traces without making the other board side non-viable for passing traces, so avoid placing vias alongside the aforementioned edges and extended length pads).  
Similarly and for the same reason, avoid any weaving at all alongside even a short pad while circumventing that pad.

This rule philosophy replaces the notion of having vertical traces on one side of the board and horizontal traces on the opposite board side.  The added advantage is that it allows for better filling of zones (planes).

2.  During weaving of multiple adjacent traces, maintain synchronous stitching so cross-directional traces don't get blocked.

3.  Weaving may not be feasible under shields for sensitive runs or maybe even at all because the traces would then be leaving protection of the shield for every other stitch and/or compromising the continuity/integrity of the ground plane.
