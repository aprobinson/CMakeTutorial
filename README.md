CMakeTutorial
=============

In this branch, the build system is set up link the main executable with the
MPI libraries when a user enables MPI (configuration option). After building
the project with MPI enabled, the executable can be run in parallel using the
following command:

```
$ python install.py --replace
$ mpiexec -n p ./build/src/main
```

The option p is the number of parallel processes to initiate. 

In this branch, the build system is not yet set up to build the project unit
tests. Check out the branch step3 to see how the build system needs to be
set up to allow unit tests to be both built and run. 