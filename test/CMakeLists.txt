INCLUDE_DIRECTORIES(${${PROJECT_NAME}_INCLUDE_DIRS})

FIND_PACKAGE(
  Boost 
  REQUIRED
  )

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

ADD_EXECUTABLE(
  tstContractException 
  tstContractException.cpp
  )

ADD_TEST(
  ContractException_test 
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tstContractException
  )

ADD_EXECUTABLE(
  tstMessage
  tstMessage.cpp
  )

TARGET_LINK_LIBRARIES(
	tstMessage dl 
	${PROJECT_NAME} 
	)

ADD_TEST(
  Message_test 
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tstMessage
  )
