#!/bin/bash
DIRECTORY="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
docker run --rm --name java-src -v $DIRECTORY:/src -v $DIRECTORY/.m2:/root/.m2 -w /src maven:3.3-jdk-8 mvn clean install