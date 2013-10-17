//---------------------------------------------------------------------------//
//!
//! \file   tstMessage.cpp
//! \author Alex Robinson
//! \brief  Message class unit tests.
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <iostream>
#include <string>

// Boost Includes
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

// HelloWorld Includes
#include "Message.hpp"

//---------------------------------------------------------------------------//
// Tests.
//---------------------------------------------------------------------------//
// Check that a Message object can be constructed.
BOOST_AUTO_TEST_CASE( Message_constructor )
{
  std::string sender( "test_sender" );
  std::string recipient( "test_recipient" );
  std::string message_contents( "test_message_contents" );

  HelloWorld::Message test_message( sender, recipient, message_contents );
}

//---------------------------------------------------------------------------//
// Check that the Message object can be printed
BOOST_AUTO_TEST_CASE( Message_print )
{
  std::string sender( "test_sender" );
  std::string recipient( "test_recipient" );
  std::string message_contents( "test_message_contents" );

  HelloWorld::Message test_message( sender, recipient, message_contents );

  // Print the test_message
  std::stringstream output_message;
  test_message.print( output_message );

  // Reference message
  std::stringstream ref_output_message;
  ref_output_message << sender << "->" << recipient << ": "
		     << message_contents << std::endl;
  
  BOOST_CHECK_EQUAL( output_message.str(), ref_output_message.str() );
}

//---------------------------------------------------------------------------//
// end tstMessage.cpp
//---------------------------------------------------------------------------//

