#!/bin/bash

echo "Building the nodes ..."

source ~/catkin_ws/devel/setup.bash

catkin build --workspace ~/catkin_ws

source ~/catkin_ws/devel/setup.bash

bash ~/catkin_ws/src/$1/run.sh
