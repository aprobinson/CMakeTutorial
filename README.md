CMakeTutorial
=============

In this branch, the build system is set up to build unit tests and allow 
testing through CTest. After CMake create the Makefile that is used to build
the system one can run the following command to run all unit tests that were
created:

```
$> cd build
$> make test
```

Or you could test as part of the install process:
```
python install.py --test
```

The results of each test will be printed.

