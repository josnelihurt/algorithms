#! /bin/bash
DIRECTORY=`dirname $0`
$DIRECTORY/stop-docker.sh
docker build -t gdb-cpp-image $DIRECTORY/../docker-build
$DIRECTORY/start-docker.sh