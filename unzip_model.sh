#!/bin/bash

echo "Unziping model file ..."

if ! [ -x "$(command -v unzip)" ]; then
  echo 'Error: unzip is not installed.' >&2
  sudo apt install unzip
fi

if [ ! -d ~/model/ ]; then
    echo "Craeting folder"
    mkdir ~/model
fi

unzip -o ~/tmp/$1/$1.zip -d ~/model/$2
