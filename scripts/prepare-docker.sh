#! /bin/bash
DIRECTORY=`dirname $0`
docker stop gdb-cpp-image
docker rm gdb-cpp-image
docker build -t gdb-cpp-image $DIRECTORY/../docker-build
docker run -d -p 2222:22 --security-opt seccomp:unconfined -v $PWD:/source --name gdb-cpp-image gdb-cpp-image
