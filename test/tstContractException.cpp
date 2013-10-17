//---------------------------------------------------------------------------//
//!
//! \file   tstContractException.cpp
//! \author Alex Robinson
//! \brief  Contract Exception class unit tests.
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <string>

// Boost Includes
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

// HelloWorld Includes
#include "ContractException.hpp"

//---------------------------------------------------------------------------//
// Tests.
//---------------------------------------------------------------------------//
// Check that a HelloWorld::ContractException looks different than a 
// std::runtime_error as it inherits from std::logic_error.
BOOST_AUTO_TEST_CASE( ContractException_differentiation_test )
{
  try
  {
    throw HelloWorld::ContractException( "HelloWorld logic error" );
  }
  catch( const std::runtime_error& exception )
  {
    BOOST_CHECK( 0 );
  }
  catch( ... )
  {
    BOOST_CHECK( 1 );
  }
}

//---------------------------------------------------------------------------//
// Check that a HelloWorld::ContractException can be caught and the 
// appropriate error message is written.
BOOST_AUTO_TEST_CASE( ContractException_message_test )
{
  std::string message;

  try
  {
    throw HelloWorld::ContractException( "contract broken" );
  }
  catch( const HelloWorld::ContractException& exception )
  {
    message = std::string( exception.what() );
  }
  catch( ... )
  {
    BOOST_CHECK( 0 );
  }

  const std::string true_message( "contract broken" );
  BOOST_CHECK( 0 == message.compare( true_message ) );
}

//---------------------------------------------------------------------------//
// Check that we can throw a HelloWorld::ContractException with the
// TEST_FOR_EXCEPTION macro
BOOST_AUTO_TEST_CASE( ContractException_throw_test )
{
  try
  {
    TEST_FOR_EXCEPTION( true,
			HelloWorld::ContractException,
			"HelloWorld assertion failed" << std::endl );
  }
  catch( const HelloWorld::ContractException& assertion )
  {
    BOOST_CHECK( 1 );
  }
  catch( ... )
  {
    BOOST_CHECK( 0 );
  }
}

//---------------------------------------------------------------------------//
// Test the precondition check for DBC
BOOST_AUTO_TEST_CASE( ContractException_precondition_test )
{
  try
  {
    testPrecondition( 0 );
    throw std::runtime_error( "this shouldn't be thrown" );
  }
  catch( const HelloWorld::ContractException& exception )
  {
#if HAVE_HelloWorld_DBC
    std::string message( exception.what() );
    std::string partial_message( "Precondition exception" );
    std::string::size_type idx = message.find( partial_message );
    if( idx == std::string::npos )
    {
      BOOST_CHECK( 0 );
    }
#else
    BOOST_CHECK( 0 );
#endif
  }
  catch( ... )
  {
#if HAVE_HelloWorld_DBC
    BOOST_CHECK( 0 );
#endif
  }
}

//---------------------------------------------------------------------------//
// Test the postcondition check for DBC.
BOOST_AUTO_TEST_CASE( ContractException_postcondition_test )
{
  try
  {
    testPostcondition( 0 );
    throw std::runtime_error( "this shouldn't be thrown" );
  }
  catch( const HelloWorld::ContractException& exception )
  {
#if HAVE_HelloWorld_DBC
    std::string message( exception.what() );
    std::string partial_message( "Postcondition exception" );
    std::string::size_type idx = message.find( partial_message );
    if( idx == std::string::npos )
    {
      BOOST_CHECK( 0 );
    }
#else
    BOOST_CHECK( 0 );
#endif
  }
  catch( ... )
  {
#if HAVE_HelloWorld_DBC
    BOOST_CHECK( 0 );
#endif
  }
}

//---------------------------------------------------------------------------//
// Test the invariant check for DBC.
BOOST_AUTO_TEST_CASE( ContractException_invariant_test )
{
  try
  {
    testInvariant( 0 );
    throw std::runtime_error( "this shouldn't be thrown" );
  }
  catch( const HelloWorld::ContractException& exception )
  {
#if HAVE_HelloWorld_DBC
    std::string message( exception.what() );
    std::string partial_message( "Invariant exception" );
    std::string::size_type idx = message.find( partial_message );
    if( idx == std::string::npos )
    {
      BOOST_CHECK( 0 );
    }
#else
    BOOST_CHECK( 0 );
#endif
  }
  catch( ... )
  {
#if HAVE_HelloWorld_DBC
    BOOST_CHECK( 0 );
#endif
  }
}

//---------------------------------------------------------------------------//
// Test that we can remember a value and check it with DBC
BOOST_AUTO_TEST_CASE( ContractException_remember_test )
{
  remember( int test_value_1 = 0 );
  remember( int test_value_2 = 1 );

  try
  {
    testInvariant( test_value_1 );
  }
  catch( const HelloWorld::ContractException& exception )
  {
#if HAVE_HelloWorld_DBC
    BOOST_CHECK( 1 );
#else
    BOOST_CHECK( 0 );
#endif
  }
  catch( ... )
  {
#if HAVE_HelloWorld_DBC
    BOOST_CHECK( 0 );
#endif
  }

  try
  {
    testInvariant( test_value_2 );
    BOOST_CHECK( 1 );
  }
  catch( ... )
  {
    BOOST_CHECK( 0 );
  }
}

//---------------------------------------------------------------------------//
// end tstContractException.cpp
//---------------------------------------------------------------------------//

