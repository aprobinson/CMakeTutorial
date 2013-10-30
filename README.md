CMakeTutorial
=============

This branch shows the most basic build system that one can set up for the
HelloWorld project. Using the build system, the main executable can be created.
However, attempting to build the executable with MPI will result in linker
errors because the build system is not yet set up to link against external
libraries. Check out branch step2 to see how one sets up the build system to
link against the external MPI libraries.