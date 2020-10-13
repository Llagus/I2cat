echo && echo && echo && echo && echo
echo "============================================================"
while [ $? -eq 0 ]
do
	echo " --> killing pending 11p simulations..."
	sleep 1
	killall opp_run 2> /dev/null
	killall opp_run_release 2> /dev/null
done
echo "============================================================"
echo " --> path: " && echo $PATH
echo " --> pwd:	 " && pwd
echo " --> starting new 11p simulations..."
echo "============================================================"


declare -a all_configs=(
				"grid-traffic_fluid-period"
				"grid-traffic_dense-period"
				"grid-traffic_fluid-period-buildings"
				"grid-traffic_dense-period-buildings"
				"grid-traffic_fluid-error"
				"ronda-emergency"
				"single"
				)

declare -a configs_to_test=(
				"grid-traffic_fluid-period"
				)


MY_NED_PATH="$HOME"

for idx in "${configs_to_test[@]}"
do
echo "------------------------------------------------------------"
xcowsay `echo GUIENV: run [Config $idx]` -t 2 --at=800,100 --cow-size=small
opp_run \
	-n $MY_NED_PATH/v2x-arch_11p/artery/src/artery:$MY_NED_PATH/v2x-arch_11p/artery/src/traci:$MY_NED_PATH/v2x-arch_11p/artery/extern/veins/examples/veins:$MY_NED_PATH/v2x-arch_11p/artery/extern/veins/src/veins:$MY_NED_PATH/v2x-arch_11p/artery/extern/inet/examples:$MY_NED_PATH/v2x-arch_11p/artery/extern/inet/src:$MY_NED_PATH/v2x-arch_11p/artery/extern/inet/tutorials \
	-l ~/v2x-arch_11p/artery/build/src/artery/libartery.so \
	-u Qtenv \
	-f ~/v2x-arch_11p/artery/scenarios/artery/omnetpp.ini \
	-c `echo $idx` &
 	wait
echo "------------------------------------------------------------"
done
