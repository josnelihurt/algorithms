#!/bin/bash
DIRECTORY="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
docker build -t gdb-cpp-image $DIRECTORY/docker-build
docker run -v $DIRECTORY:/source --rm --name tmp -it --entrypoint /source/scripts/build-run.sh gdb-cpp-image