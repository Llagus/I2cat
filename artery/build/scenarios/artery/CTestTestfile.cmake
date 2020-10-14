# CMake generated Testfile for 
# Source directory: /home/aniol/Documents/I2cat/artery/scenarios/artery
# Build directory: /home/aniol/Documents/I2cat/artery/build/scenarios/artery
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(example-inet "/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/aniol/Documents/I2cat/artery/src/artery:/home/aniol/Documents/I2cat/artery/src/traci:/home/aniol/Documents/I2cat/artery/extern/veins/examples/veins:/home/aniol/Documents/I2cat/artery/extern/veins/src/veins:/home/aniol/Documents/I2cat/artery/extern/inet/src:/home/aniol/Documents/I2cat/artery/extern/inet/examples:/home/aniol/Documents/I2cat/artery/extern/inet/tutorials:/home/aniol/Documents/I2cat/artery/extern/inet/showcases" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libINET.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libveins.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/traci/libtraci.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet" "--sim-time-limit=20s")
set_tests_properties(example-inet PROPERTIES  WORKING_DIRECTORY "/home/aniol/Documents/I2cat/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/aniol/Documents/I2cat/artery/cmake/AddOppRun.cmake;169;add_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;2;add_opp_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-security "/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/aniol/Documents/I2cat/artery/src/artery:/home/aniol/Documents/I2cat/artery/src/traci:/home/aniol/Documents/I2cat/artery/extern/veins/examples/veins:/home/aniol/Documents/I2cat/artery/extern/veins/src/veins:/home/aniol/Documents/I2cat/artery/extern/inet/src:/home/aniol/Documents/I2cat/artery/extern/inet/examples:/home/aniol/Documents/I2cat/artery/extern/inet/tutorials:/home/aniol/Documents/I2cat/artery/extern/inet/showcases" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libINET.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libveins.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/traci/libtraci.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet_security" "--sim-time-limit=20s")
set_tests_properties(example-security PROPERTIES  WORKING_DIRECTORY "/home/aniol/Documents/I2cat/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/aniol/Documents/I2cat/artery/cmake/AddOppRun.cmake;169;add_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;3;add_opp_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-inet-mco "/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/aniol/Documents/I2cat/artery/src/artery:/home/aniol/Documents/I2cat/artery/src/traci:/home/aniol/Documents/I2cat/artery/extern/veins/examples/veins:/home/aniol/Documents/I2cat/artery/extern/veins/src/veins:/home/aniol/Documents/I2cat/artery/extern/inet/src:/home/aniol/Documents/I2cat/artery/extern/inet/examples:/home/aniol/Documents/I2cat/artery/extern/inet/tutorials:/home/aniol/Documents/I2cat/artery/extern/inet/showcases" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libINET.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libveins.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/traci/libtraci.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet_mco" "--sim-time-limit=20s")
set_tests_properties(example-inet-mco PROPERTIES  WORKING_DIRECTORY "/home/aniol/Documents/I2cat/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/aniol/Documents/I2cat/artery/cmake/AddOppRun.cmake;169;add_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;4;add_opp_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-inet-mixed-vehicles "/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/aniol/Documents/I2cat/artery/src/artery:/home/aniol/Documents/I2cat/artery/src/traci:/home/aniol/Documents/I2cat/artery/extern/veins/examples/veins:/home/aniol/Documents/I2cat/artery/extern/veins/src/veins:/home/aniol/Documents/I2cat/artery/extern/inet/src:/home/aniol/Documents/I2cat/artery/extern/inet/examples:/home/aniol/Documents/I2cat/artery/extern/inet/tutorials:/home/aniol/Documents/I2cat/artery/extern/inet/showcases" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libINET.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libveins.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/traci/libtraci.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet_multiple_vehicle_types" "--sim-time-limit=20s")
set_tests_properties(example-inet-mixed-vehicles PROPERTIES  WORKING_DIRECTORY "/home/aniol/Documents/I2cat/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/aniol/Documents/I2cat/artery/cmake/AddOppRun.cmake;169;add_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;5;add_opp_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-inet-nakagami "/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/aniol/Documents/I2cat/artery/src/artery:/home/aniol/Documents/I2cat/artery/src/traci:/home/aniol/Documents/I2cat/artery/extern/veins/examples/veins:/home/aniol/Documents/I2cat/artery/extern/veins/src/veins:/home/aniol/Documents/I2cat/artery/extern/inet/src:/home/aniol/Documents/I2cat/artery/extern/inet/examples:/home/aniol/Documents/I2cat/artery/extern/inet/tutorials:/home/aniol/Documents/I2cat/artery/extern/inet/showcases" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libINET.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libveins.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/traci/libtraci.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet_nakagami" "--sim-time-limit=20s")
set_tests_properties(example-inet-nakagami PROPERTIES  WORKING_DIRECTORY "/home/aniol/Documents/I2cat/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/aniol/Documents/I2cat/artery/cmake/AddOppRun.cmake;169;add_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;6;add_opp_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-inet-rsu "/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/aniol/Documents/I2cat/artery/src/artery:/home/aniol/Documents/I2cat/artery/src/traci:/home/aniol/Documents/I2cat/artery/extern/veins/examples/veins:/home/aniol/Documents/I2cat/artery/extern/veins/src/veins:/home/aniol/Documents/I2cat/artery/extern/inet/src:/home/aniol/Documents/I2cat/artery/extern/inet/examples:/home/aniol/Documents/I2cat/artery/extern/inet/tutorials:/home/aniol/Documents/I2cat/artery/extern/inet/showcases" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libINET.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libveins.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/traci/libtraci.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet_rsu" "--sim-time-limit=20s")
set_tests_properties(example-inet-rsu PROPERTIES  WORKING_DIRECTORY "/home/aniol/Documents/I2cat/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/aniol/Documents/I2cat/artery/cmake/AddOppRun.cmake;169;add_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;7;add_opp_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-veins "/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/aniol/Documents/I2cat/artery/src/artery:/home/aniol/Documents/I2cat/artery/src/traci:/home/aniol/Documents/I2cat/artery/extern/veins/examples/veins:/home/aniol/Documents/I2cat/artery/extern/veins/src/veins:/home/aniol/Documents/I2cat/artery/extern/inet/src:/home/aniol/Documents/I2cat/artery/extern/inet/examples:/home/aniol/Documents/I2cat/artery/extern/inet/tutorials:/home/aniol/Documents/I2cat/artery/extern/inet/showcases" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libINET.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libveins.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/traci/libtraci.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cveins" "--sim-time-limit=20s")
set_tests_properties(example-veins PROPERTIES  WORKING_DIRECTORY "/home/aniol/Documents/I2cat/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/aniol/Documents/I2cat/artery/cmake/AddOppRun.cmake;169;add_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;8;add_opp_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-veins-rsu "/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/aniol/Documents/I2cat/artery/src/artery:/home/aniol/Documents/I2cat/artery/src/traci:/home/aniol/Documents/I2cat/artery/extern/veins/examples/veins:/home/aniol/Documents/I2cat/artery/extern/veins/src/veins:/home/aniol/Documents/I2cat/artery/extern/inet/src:/home/aniol/Documents/I2cat/artery/extern/inet/examples:/home/aniol/Documents/I2cat/artery/extern/inet/tutorials:/home/aniol/Documents/I2cat/artery/extern/inet/showcases" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libINET.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libveins.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/traci/libtraci.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cveins_rsu" "--sim-time-limit=20s")
set_tests_properties(example-veins-rsu PROPERTIES  WORKING_DIRECTORY "/home/aniol/Documents/I2cat/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/aniol/Documents/I2cat/artery/cmake/AddOppRun.cmake;169;add_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;9;add_opp_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-envmod "/home/aniol/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/aniol/Documents/I2cat/artery/src/artery:/home/aniol/Documents/I2cat/artery/src/traci:/home/aniol/Documents/I2cat/artery/extern/veins/examples/veins:/home/aniol/Documents/I2cat/artery/extern/veins/src/veins:/home/aniol/Documents/I2cat/artery/extern/inet/src:/home/aniol/Documents/I2cat/artery/extern/inet/examples:/home/aniol/Documents/I2cat/artery/extern/inet/tutorials:/home/aniol/Documents/I2cat/artery/extern/inet/showcases" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libINET.so" "-l" "/home/aniol/Documents/I2cat/artery/build/extern/libveins.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/traci/libtraci.so" "-l" "/home/aniol/Documents/I2cat/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cenvmod" "--sim-time-limit=20s")
set_tests_properties(example-envmod PROPERTIES  WORKING_DIRECTORY "/home/aniol/Documents/I2cat/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/aniol/Documents/I2cat/artery/cmake/AddOppRun.cmake;169;add_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;12;add_opp_test;/home/aniol/Documents/I2cat/artery/scenarios/artery/CMakeLists.txt;0;")
