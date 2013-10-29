# Define the minimum required version of CMake
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

# set project directories
SET( PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
SET( HW_CLI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cli )
SET( HW_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )

# Tell CMake where the modules are
SET( 
  CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} 
  "${CMAKE_DIR}/share/cmake-2.8/Modules"
  ${PROJECT_SOURCE_DIR}/cmake
  )

# Define the project name, no need to fully spell it out because it's now in the
# CMAKE_MODULE_PATH, which CMAKE queries for its INCLUDEs
INCLUDE(ProjectName)

# Define the project version
INCLUDE(Version)

# Include the macros that have been defined for this project
INCLUDE(Macros)

# This makes all the libraries build as SHARED
SET(BUILD_SHARED_LIBS true)

# Setup build locations.
IF(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
endif()
IF(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
endif()
IF(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
  SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
ENDIF()

# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH  FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Enforce an out-of-source build, no one should be building in the src dir!
ENFORCE_OUT_OF_SOURCE_BUILD()

# Add MPI support if requested
IF(${${PROJECT_NAME}_ENABLE_MPI})
  SET(HAVE_${PROJECT_NAME}_MPI "1")
  SET(CMAKEDEFINE \#cmakedefine)
  ENABLE_MPI_SUPPORT(${PROJECT_NAME}_LIBS)
ELSE(${${PROJECT_NAME}_ENABLE_MPI})
  SET(HAVE_${PROJECT_NAME}_MPI "0")
  SET(CMAKEDEFINE \#cmakedefine)
ENDIF()

# Parse the MPI configure file so that it can be used in our source files
CONFIGURE_FILE(
  ${CMAKE_SOURCE_DIR}/cmake/mpi_config.hpp.in
  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_mpi_config.hpp.in
  )
CONFIGURE_FILE(
  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_mpi_config.hpp.in
  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_mpi_config.hpp
  )

# Add Design-by-Contract support if requested
IF(${${PROJECT_NAME}_ENABLE_DBC})
  SET(HAVE_${PROJECT_NAME}_DBC "1")
ELSE(${${PROJECT_NAME}_ENABLE_DBC})
  SET(HAVE_${PROJECT_NAME}_DBC "0")
ENDIF()

# Parse the DBC configure file so that is can be used in our source files
CONFIGURE_FILE(
  ${CMAKE_SOURCE_DIR}/cmake/dbc_config.hpp.in
  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_dbc_config.hpp
  )

# Add the CMAKE_BINARY_DIR to the include path to access config files 
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})

# Set up the project directory hierarchy
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(cli)
# Enable testing through CTest
ENABLE_TESTING()
ADD_SUBDIRECTORY(test)