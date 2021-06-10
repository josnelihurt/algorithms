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
cd /source/go-src/
/usr/local/go/bin/go mod vendor
/usr/local/go/bin/go build ./...