source ../devel/setup.bash

roscore &

sleep 3

rqt &
rqt_graph &
roslaunch rosbridge_server rosbridge_websocket.launch