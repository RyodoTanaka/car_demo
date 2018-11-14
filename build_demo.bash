#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROSDOCKER_ARG="$1 $2"

if [ -n "$1" ]; then
    sudo docker build -t autoware/car_demo $DIR --build-arg ROSDOCKER_ARG="$ROSDOCKER_ARG"
else
    sudo docker build -t autoware/car_demo $DIR
fi
