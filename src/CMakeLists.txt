SET(
  HEADERS ${HEADERS}
  PrintableObject.hpp
  Message.hpp
  ContractException.hpp
  Comm.hpp
  )
  
IF(CMAKE_VERBOSE_CONFIGURE)
  MESSAGE("HEADERS = ${HEADERS}")
ENDIF()

ADD_EXECUTABLE(
  HelloWorld
  main.cpp
  Message.cpp
  PrintableObject.cpp
  )

INSTALL(
  TARGETS HelloWorld
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
  )

INSTALL(
  FILES ${HEADERS}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
  )
  