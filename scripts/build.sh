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

cd /source/go-src/
/usr/local/go/bin/go mod vendor
/usr/local/go/bin/go build ./...

if [[ "$arg" == "runUnitTest" ]] 
then
  /usr/local/go/bin/go test -short=1 -count=2 -cover -v ./...
fi
echo "done with go build"

cd /source/rust-src/
cargo build
if [[ "$arg" == "runUnitTest" ]]
then
  cargo test -v
fi
echo "done with rust build"