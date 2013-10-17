CMakeTutorial
=============

A simple cmake build system example.

The root directory of this repo is a template of how I typically organize my
projects. The cmake directory contains some generic files that I use in every
project that will be pulled in by the root CMakeLists.txt file. The scripts
directory contains an example shell script that can be used to run cmake and
configure the project. In-source builds are not permitted in my projects so 
this configure script must be copied to another directory. To use the script, 
the HELLOWORLD_PATH variable must be set to the location of the CMAkeTutorial 
folder on your system. Several options can be changed by using the script. 
These options include whether the build type is a debug build or a release
build, whether or not to conduct a verbose configure, whether or not to
create a verbose make file, whether or not to enable Design-by-Contract,
and whether or not to enable MPI. I encourage you to play with these options
to see how they change the behavior of cmake, the makefile created by cmake, 
and the system. A description of some of the more advanced cmake
commands (many of which are found in the file contained in the cmake directory)
can be found at http://www.cmake.org/cmake/help/v2.8.12/cmake.html. 

-------------------------------------------------------------------------------

Typical Workflow:

1.) Copy configure.sh file to a new directory

2.) Modify HELLOWORLD_PATH variable in configure.sh file so that it contains
    the path to the CMakeTutorial directory.

3.) Modify cmake flags as desired.

4.) Run configure.sh script

5.) Type: make test

6.) If all unit tests pass type: make install

    -Note: the default install_prefix_path is the parent directory of the 
           directory where the configure.sh script executed

7.) Go to the bin directory (../bin) to use the executable created (main)

8.) If MPI support has been turned on type: mpiexec -n x main
    where x is the number of processes to use

-NOTE: After changing configure options and rerunning the configure script
      it is often a good idea to type make clean before rebuilding the
      system.

-------------------------------------------------------------------------------

Example directory structure for build:

root_dir -> build, bin, include, CMakeTutorial

The configure.sh file will be copied to the build directory. The bin and
include directories need not be created manually - CMake will create them
if the do not exist when make install is called from the build directory.
