INCLUDE_DIRECTORIES(${${PROJECT_NAME}_INCLUDE_DIRS})

FIND_PACKAGE(
  Boost 
  COMPONENTS unit_test_framework 
  REQUIRED
  )

SET(
  TST_LIBS ${TST_LIBS}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  )  

ADD_EXECUTABLE(
  tstContractException 
  tstContractException.cpp
  )

TARGET_LINK_LIBRARIES(tstContractException dl ${TST_LIBS})

ADD_TEST(
  ContractException_test 
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tstContractException
  )

ADD_EXECUTABLE(
  tstMessage
  tstMessage.cpp
  )

TARGET_LINK_LIBRARIES(tstMessage dl ${PROJECT_NAME} ${TST_LIBS})

ADD_TEST(
  Message_test 
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tstMessage
  )