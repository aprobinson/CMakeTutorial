CMakeTutorial 
=============

This tutorial is designed to show how one can set up a build system for a
project using CMake. There are five branches the in this repo: step0, step1,
step2, step3 and the master branch. The step0 branch is simply the HelloWorld
project before the build system has been set up. The step1 branch has a very
simple CMake build system. In it one can build the main executable. However
trying to build it with MPI will result in linker errors because no library
linking is done. In the step2 branch the build system is set up to link the main
executable with the MPI libraries if MPI has been enabled by the user.  In the
step3 branch testing support is added and several unit tests are added to the
build system. Finally, the master branch adds in all of the extra bells and
whistles. The main executable source is moved from the core (src) directory to a
new directory called cli. The build system is set up to build a library from the
core source files of the project. The main file is then built and linked with
the core project library. All unit tests are also built and linked with the core
project library. As projects get larger and more complex, this build system
setup can be very useful. An uninstall target was also added, which makes
cleaning up an installed project very easy. You can try it with

```
$> python install.py 
$> cd build
$> make uninstall
```

HelloWorld Configuration Options:
-----------

Several options can be passed to the build system to change the behavior of the
project. The first option is whether the build is a debug build or a release 
build (CMAKE_BUILD_TYPE:STRING=DEBUG or CMAKE_BUILD_TYPE:STRING=RELEASE).
The second option is whether MPI will used with the project 
(HelloWorld_ENABLE_MPI:BOOL=ON or HelloWorld_ENABLE_MPI:BOOL=OFF). The final
option is whether design-by-contract will be used with the project
(HelloWorld_ENABLE_DBC:BOOL=ON or HelloWorld_ENABLE_DBC:BOOL=OFF). 

Unless the cmake command is being run directly by the user, these options 
never need to be chosen in this way. The provided install.py script allows
one to configure the system in a much easier way. 

Running CMake:
-------------

To configure the HelloWorld project the following command can be run:

```
$> cmake -D CMAKE_INSTALL_PREFIX:PATH=path_a -D CMAKE_BUILD_TYPE:STRING=option_a -D CMAKE_VERBOSE_MAKEFILE:BOOL=ON -D HelloWorld_ENABLE_DBC:BOOL=option_b -D HelloWorld_ENABLE_MPI:BOOL=option_c path_b
```

* path_a = Absolute path to directory where binaries, headers and 
           libraries will be installed.
* path_b = Absolute path to the CMakeTutorial directory

* option_a = RELEASE or DEBUG
* option_b = ON or OFF
* option_c = ON or OFF

Using the install.py script one never needs to actually run this command. The 
script simplifies the configuration process by abstracting configuration 
options to simple flags that one can pass. Type ./install.py -h to get a 
description of all the flags that one can pass. In addition the script provides
a valid build and install prefix in case no flags are passed. 

Running main executable in parallel:
---------

Whether or not the main executable is built using MPI it is always valid to run
it using ./main. To run it in parallel, the following command must be used:

```
$> mpiexec -n p main
```

The option p is the number of parallel processes to initiate.

CMake Documentation:
---------

The master branch of this repo uses some of the more advanced CMake commands.
A complete description of all of the CMake commands can be found at http://www.cmake.org/cmake/help/v2.8.12/cmake.html. 

