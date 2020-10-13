#!/bin/bash
OPP_RUN=/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg
NED_FOLDERS="/home/aniol/Downloads/artery/src/artery:/home/aniol/Downloads/artery/src/traci:/home/aniol/Downloads/artery/extern/veins/examples/veins:/home/aniol/Downloads/artery/extern/veins/src/veins:/home/aniol/Downloads/artery/extern/inet/src:/home/aniol/Downloads/artery/extern/inet/examples:/home/aniol/Downloads/artery/extern/inet/tutorials:/home/aniol/Downloads/artery/extern/inet/showcases"
LIBRARIES="-l/home/aniol/Downloads/artery/build/src/artery/libartery_core.so -l/home/aniol/Downloads/artery/build/src/traci/libtraci.so -l/home/aniol/Downloads/artery/build/extern/libveins.so -l/home/aniol/Downloads/artery/build/extern/libINET.so -l/home/aniol/Downloads/artery/build/src/artery/storyboard/libartery_storyboard.so -l/home/aniol/Downloads/artery/build/src/artery/envmod/libartery_envmod.so"

$OPP_RUN -n $NED_FOLDERS $LIBRARIES $@
