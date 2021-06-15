#!/bin/sh
DIRECTORY="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
docker run --rm --name node-src -v $DIRECTORY:/src -w /src node npm install mocha
docker run --rm --name node-src -v $DIRECTORY:/src -w /src node npm test 
