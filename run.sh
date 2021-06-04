#! /bin/bash
docker stop gdb-cpp-image
docker rm gdb-cpp-image
docker build -t gdb-cpp-image .
docker run -v $PWD:/source --rm --name tmp -it --entrypoint /source/build.sh gdb-cpp-image