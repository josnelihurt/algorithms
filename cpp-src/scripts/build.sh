#! /bin/bash
arg=""
if [ $# -eq 1 ]
  then
    arg=$1
fi

mkdir -p /source/build && \
cd /source/build && \
cmake ../ -DCMAKE_BUILD_TYPE=Debug && \
make -j4 $arg
echo "done with cpp build"
