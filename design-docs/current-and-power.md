# Current and Power Calculations

## 5V Supply

The 5V rail supplies :

* PT2399 IC
    draws up to ~30ma, less at lower speeds
* CD4020 IC
    Draws up to ~5ua (negligable)
    Output goes straight into a high input impedance buffer so minimal draw there as well.
* ATTiny85
    draws ~2ma (need to properly calculate but it's in this region)
* The 100k Division control potentiometer
    negligable


### Power
