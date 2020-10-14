#!/bin/bash
OPP_RUN=/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg
NED_FOLDERS="/home/aniol/Documents/I2cat/artery/src/artery:/home/aniol/Documents/I2cat/artery/src/traci:/home/aniol/Documents/I2cat/artery/extern/veins/examples/veins:/home/aniol/Documents/I2cat/artery/extern/veins/src/veins:/home/aniol/Documents/I2cat/artery/extern/inet/src:/home/aniol/Documents/I2cat/artery/extern/inet/examples:/home/aniol/Documents/I2cat/artery/extern/inet/tutorials:/home/aniol/Documents/I2cat/artery/extern/inet/showcases"
LIBRARIES="-l/home/aniol/Documents/I2cat/artery/build/src/artery/libartery_core.so -l/home/aniol/Documents/I2cat/artery/build/src/traci/libtraci.so -l/home/aniol/Documents/I2cat/artery/build/extern/libveins.so -l/home/aniol/Documents/I2cat/artery/build/extern/libINET.so -l/home/aniol/Documents/I2cat/artery/build/src/artery/storyboard/libartery_storyboard.so -l/home/aniol/Documents/I2cat/artery/build/src/artery/envmod/libartery_envmod.so"

$OPP_RUN -n $NED_FOLDERS $LIBRARIES $@
