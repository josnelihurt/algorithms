# algorithms
This is a simple repository to include various tests over different data structures and algorithms for learning purposes 


## compilation and debugging
based on https://lemariva.com/blog/2020/10/vscode-c-development-and-debugging-containers

## for visual studio code you will need the following extensions

C/C++ Microsoft
C/C++ Extension Pack

## docker image creation/running

docker build -t gdb-cpp-image .
docker run -d -p 2222:22 --security-opt seccomp:unconfined -v $PWD:/source --name gdb-cpp-image gdb-cpp-image
