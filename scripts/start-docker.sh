#! /bin/bash
docker run -d -p 2222:22 --security-opt seccomp:unconfined -v $PWD:/source -v $PWD/java-src/.m2:/root/.m2 --name gdb-cpp-image gdb-cpp-image