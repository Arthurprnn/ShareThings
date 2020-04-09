#!/bin/sh

cd ./src
make
cd ./Main
make clean
make
./ShareThings.exe