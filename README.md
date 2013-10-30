CMakeTutorial
=============

In this branch, the build system is set up to build unit tests and allow 
testing through CTest. After CMake creates the Makefile that is used to build
the system one can run the following command to run all unit tests that were
created:

```
$ python install --replace
$ cd build
$ make test
```

Or you could test as part of the install process:
```
$ python install.py --replace --test
```

The results of each test will be printed.

