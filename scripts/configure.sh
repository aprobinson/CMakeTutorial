#!/bin/bash
##---------------------------------------------------------------------------##
## CONFIGURE HelloWorld with CMAKE
##---------------------------------------------------------------------------##

EXTRA_ARGS=$@
HELLOWORLD_PATH=$HOME/THW/cmake/CMakeTutorial/

##---------------------------------------------------------------------------##

rm -rf CMakeCache.txt

##---------------------------------------------------------------------------##

cmake \
    -D CMAKE_INSTALL_PREFIX:PATH=$PWD/../ \
    -D CMAKE_BUILD_TYPE:STRING=RELEASE \
    -D CMAKE_VERBOSE_CONFIGURE:BOOL=ON \
    -D CMAKE_VERBOSE_MAKEFILE:BOOL=ON \
    -D HelloWorld_ENABLE_DBC:BOOL=ON \
    -D HelloWorld_ENABLE_MPI:BOOL=ON \
    $EXTRA_ARGS \
    $HELLOWORLD_PATH
