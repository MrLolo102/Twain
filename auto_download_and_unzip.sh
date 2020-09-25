#!/bin/bash

echo "Downloading source code from server"
echo "Params size: $#"
echo "Downloading URL: $1"
echo "Creating folder: $2"

DIR="~/tmp/"
if [ ! -d "$DIR" ]; then
  echo "Creating tmp folder"
  mkdir ~/tmp
fi

mkdir ~/tmp/$2
if ! [ -x "$(command -v wget)" ]; then
  echo 'Error: unzip is not installed.' >&2
  sudo apt install wget
fi
wget $1 -O ~/tmp/$2/$2.zip


