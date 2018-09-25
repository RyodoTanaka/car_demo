#!/usr/bin/env bash

source /opt/ros/kinetic/setup.bash
source /tmp/workspace/script/rosdocker.bash $1 $2
source /tmp/workspace/devel/setup.bash
roslaunch car_demo demo.launch
