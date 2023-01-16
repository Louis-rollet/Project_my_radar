# Project_my_radar
A seconde project on the CSFML library :

It's a simulation of many planes going to on point to an other. Did use Linked list to display as many planes as possible on the screen.
You can add more planes with the A key and try the limit of this code.

Use on Linux or Mac :

`make` and then `./my_radar "plane_and_tower_file"`

In the plane_and_tower_file Aircrafts are described by:

• The letter ‘A’,

• Two integers corresponding to the departure x- and y-coordinates,

• Two integers corresponding to the arrival x- and y-coordinates,

• One integer corresponding to the aircraft’s speed (in pixels per second),

• One integer corresponding to the delay (in seconds) before the aircraft takes off.

Control towers are described by:

• The letter ‘T’,

• Two integers corresponding to the control tower x- and y-coordinates,

• One integer corresponding to the radius of the tower’s control area (corresponding to the percentage
of the greatest side of the window in pixel).


Like this :

A 815 321 1484 166 5 0

T 93 47 19
