#!/bin/bash

git add ./arduino/Robot
git add ./monografia

sudo cp ./arduino/Robot/* /usr/share/arduino/libraries/Robot/

git commit -m $1
git push -u origin master
