#!/bin/bash
set -ex
rm -rf build
mkdir build
cd build
cmake ..
make
