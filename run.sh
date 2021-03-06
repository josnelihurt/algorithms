#!/bin/bash
DIRECTORY="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
echo ================================================================================================
./cpp-src/run.sh
echo ================================================================================================
./go-src/run.sh
echo ================================================================================================
./java-src/run.sh
echo ================================================================================================
./net-src/run.sh
echo ================================================================================================
./node-src/run.sh
echo ================================================================================================
./python-src/run.sh
echo ================================================================================================
./rust-src/run.sh
echo ================================================================================================