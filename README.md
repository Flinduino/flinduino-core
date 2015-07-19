# chipkit-core
Downloadable chipKIT core for use with Arduino 1.6x IDE and UECIDE
## Build Requirements

* [ANT](http://ant.apache.org/)

## Build Instructions

```
ant setup
ant build
ant macosx-build
ant windows-build
ant linux32-build
ant linux64-build
ant raspberrypi-build
ant clean
ant updatepic32prog

ant dist //compress the builds prepare for deployment
```

## Deployment instructions

Option 1:
* `ant dist`
* copy the dist/{OS} zip file to {SketchFolder}/Arduino/hardware
* unzip the the zip file
* start Arduino
* Boards will be listed in the board drop down

Option 2:
* `ant build`
* copy the dist/{OS} folder  to {SketchFolder}/Arduino/hardware
* The user sketch folder needs a folder called hardware.
* start Arduino
* Boards will be listed in the board drop down

```
Copy from dist OS Platform and move to ~/Documents/Arduino/hardware folder
```