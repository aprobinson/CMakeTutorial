CMakeTutorial
=============

This branch shows the HelloWorld project with the absolute minimum build. The
project will use configurable includes for MPI in step1, thus its build system
will grow. This step is here to simply show you the barest essentials required
to build and run an application with some implementation and header files.

Try it out with:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./src/main
```

Check out the step1 branch to see a very basic build system that allows MPI to
be used, installs main, and does lots of other things not included in this
barebones approach!