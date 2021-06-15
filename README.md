# About this repository
This repository holds various tests over some data structures and algorithms for learning and practicing. I will try to test the algorithms' implementation in different languages and using different approaches.

# directory structure
Inside the root folder, there is a script named `run.sh`. This script will call all the `run.sh` for the following sub-folders
 cpp-src
 go-src
 java-src
 net-src
 node-src
 npm-src
 python-src
 rust-src

This repository uses a dockerized environment that allows us to have a portable environment. It can be used from any machine with docker eliminating the need of installing and configuring dependencies. In the case of C++ environment will be tedious in case I just jump to another computer. My favorite language is C++, so most of the work can be found under `cpp-src` folder, though I want to have all the languages sharp.


## build
To build, just run `./run.sh`

## compilation and debugging only supported on cpp-src
based on https://lemariva.com/blog/2020/10/vscode-c-development-and-debugging-containers

### In order to use visual studio code, you will need the following extensions

C/C++ Microsoft
C/C++ Extension Pack

## docker image creation/running
sudo apt-get install sshpass
docker build -t gdb-cpp-image .
docker run -d -p 2222:22 --security-opt seccomp:unconfined -v $PWD:/source --name gdb-cpp-image gdb-cpp-image


REMAINDER: before running for the first time keep in mind that the ssh fingerprint should be known, so you can address it by launching an ssh connection to localhost on port 2222

# About the author
If you wanna know about my professional career or just wanna contact me to discussing some technical issue or improvement in this code you can find me on https://josnelihurt.me or https://www.linkedin.com/in/josnelihurt-rodriguez-57268877/