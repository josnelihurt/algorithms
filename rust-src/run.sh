#!/bin/bash
DIRECTORY="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
docker run --rm --user "$(id -u)":"$(id -g)" -v $DIRECTORY:/src -w /src rust:1.23.0 cargo test -v
