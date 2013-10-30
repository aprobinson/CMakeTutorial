SET(SRC ${CMAKE_SOURCE_DIR}/src)

FIND_PACKAGE(
  Boost 
  REQUIRED
  )

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

# Create the ContractException test
ADD_EXECUTABLE(
  tstContractException 
  tstContractException.cpp
  )

ADD_TEST(ContractException_test tstContractException)

# Create the Message test
ADD_EXECUTABLE(
  tstMessage
  tstMessage.cpp
  ${SRC}/Message.cpp
  ${SRC}/PrintableObject.cpp
  )

ADD_TEST(Message_test tstMessage)
