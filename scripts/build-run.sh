#! /bin/bash
DIRECTORY=`dirname $0`
echo "********************************************************************************"
echo "building ..."
$DIRECTORY/build.sh 
echo "********************************************************************************"
echo "running cpp version of the testing"
/source/build/testbin
echo "********************************************************************************"
echo "running go version of the testing"
cd /source/go-src/
./run.sh