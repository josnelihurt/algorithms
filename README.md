# algorithms
This is a simple repository to include various tests over different data structures and algorithms for learning purposes. This repository uses a dockerized environment that allows us to have a portable environment. The repository can be used from vscode to develop and debug the code.

## build
To build, just run `./run.sh`

## compilation and debugging
based on https://lemariva.com/blog/2020/10/vscode-c-development-and-debugging-containers

## for visual studio code, you will need the following extensions

C/C++ Microsoft
C/C++ Extension Pack

## docker image creation/running
sudo apt-get install sshpass
docker build -t gdb-cpp-image .
docker run -d -p 2222:22 --security-opt seccomp:unconfined -v $PWD:/source --name gdb-cpp-image gdb-cpp-image


REMAINDER: before running for the first time keep in mind that the ssh fingerprint should be known, so you can address it by launching an ssh connection to localhost on port 2222