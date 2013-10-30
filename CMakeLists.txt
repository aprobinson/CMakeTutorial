# Define the project name
INCLUDE(${CMAKE_SOURCE_DIR}/cmake/ProjectName.cmake)

# Define the project version
INCLUDE(${CMAKE_SOURCE_DIR}/cmake/Version.cmake)

# Define the minimum required version of CMake
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

# Include the macros that have been defined for this project
INCLUDE(${CMAKE_SOURCE_DIR}/cmake/Macros.cmake)

# Enforce an out-of-source build, no one should be building in the src dir!
ENFORCE_OUT_OF_SOURCE_BUILD()

# Add MPI support if requested
IF(${${PROJECT_NAME}_ENABLE_MPI})
  SET(HAVE_${PROJECT_NAME}_MPI "1")
  ENABLE_MPI_SUPPORT(${PROJECT_NAME}_LIBS)
ENDIF()

# Parse the MPI configure file so that it can be used in our source files
SET(CMAKEDEFINE \#cmakedefine)
CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/cmake/mpi_config.hpp.in
  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_mpi_config.hpp.in)
CONFIGURE_FILE(${CMAKE_BINARY_DIR}/${PROJECT_NAME}_mpi_config.hpp.in
  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_mpi_config.hpp)

# Add the CMAKE_BINARY_DIR to the include path to access config files 
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})

##---------------------------------------------------------------------------##
## Ignore this section for now
##---------------------------------------------------------------------------##

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

##---------------------------------------------------------------------------##

# Set up the project directory hierarchy
ADD_SUBDIRECTORY(src)

