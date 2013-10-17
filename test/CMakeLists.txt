SET(SRC ${CMAKE_SOURCE_DIR}/src)

ADD_EXECUTABLE(tstContractException
  tstContractException.cpp)
ADD_TEST(ContractException_test tstContractException)

ADD_EXECUTABLE(tstMessage
  tstMessage.cpp
  ${SRC}/Message.cpp
  ${SRC}/PrintableObject.cpp)
ADD_TEST(Message_test tstMessage)