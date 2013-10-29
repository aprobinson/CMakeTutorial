
SET(
  HEADERS
  PrintableObject.hpp
  Message.hpp
  ContractException.hpp
  Comm.hpp
  ${HEADERS}
  )

# SET(
#   SRC
#   PrintableObject.cpp
#   Message.cpp 
#   )
  
SET(TARGETS
  main
  ${TARGETS})
  
IF(CMAKE_VERBOSE_CONFIGURE)
  MESSAGE("HEADERS = ${HEADERS}")
ENDIF()

ADD_EXECUTABLE( main
  main.cpp
  PrintableObject.cpp
  Message.cpp )

IF(${${PROJECT_NAME}_ENABLE_MPI})
  TARGET_LINK_LIBRARIES(main ${MPI_CXX_LIBRARIES})
ENDIF()

INSTALL(TARGETS ${TARGETS}
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

INSTALL(FILES ${HEADERS}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)
  