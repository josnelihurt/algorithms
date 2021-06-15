#!/bin/bash
DIRECTORY="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
docker run -it --rm --name python-src -v $DIRECTORY:/src -w /src python:3 python test.py