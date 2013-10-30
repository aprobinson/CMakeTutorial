SET(
  HEADERS ${HEADERS}
  PrintableObject.hpp
  Message.hpp
  Comm.hpp
  )

ADD_EXECUTABLE(
  main
  main.cpp
  Message.cpp
  PrintableObject.cpp
  )
