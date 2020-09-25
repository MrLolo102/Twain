#!/bin/bash

echo "Unziping source code ..."
if ! [ -x "$(command -v unzip)" ]; then
  echo 'Error: unzip is not installed.' >&2
  sudo apt install unzip
fi

if [ ! -d ~/catkin_ws/ ]; then
    echo "Craeting folder"
    mkdir ~/catkin_ws
    mkdir ~/catkin_ws/src
fi

unzip -o ~/tmp/$1/$1.zip -d ~/catkin_ws/src/$2
