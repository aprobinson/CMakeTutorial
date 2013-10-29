# Define the minimum required version of CMake
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

# set project directories
SET( PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
SET( PROJ_CLI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cli )
SET( PROJ_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
SET( PROJ_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test )

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

# Set the runtime install path
SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

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
ADD_SUBDIRECTORY(${PROJ_SRC_DIR})
ADD_SUBDIRECTORY(${PROJ_CLI_DIR})
# Enable testing through CTest
ENABLE_TESTING()
ADD_SUBDIRECTORY(${PROJ_TEST_DIR})