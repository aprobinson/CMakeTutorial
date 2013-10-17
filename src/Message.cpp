//---------------------------------------------------------------------------//
//!
//! \file   Message.cpp
//! \author Alex Robinson
//! \brief  Definition of a simple class that stores a message.
//!
//---------------------------------------------------------------------------//

// HelloWorld Includes
#include "Message.hpp"
#include "ContractException.hpp"

namespace HelloWorld{

// Default constructor
Message::Message()
  : PrintableObject( "Message" )
{ /* ... */ }

// Constructor
Message::Message( const std::string& sender_name,
		  const std::string& recipient_name,
		  const std::string& sender_message )
  : PrintableObject( "Message" ),
    d_sender_name( sender_name ),
    d_recipient_name( recipient_name ),
    d_stored_message( sender_message )
{  
  // Make sure that the names are valid (at least one character)
  testPrecondition( d_sender_name.size() > 0 );
  testPrecondition( d_recipient_name.size() > 0 );
  // Make sure that the message is valid( at least one character)
  testPrecondition( d_stored_message.size() > 0 );
}

// Change the message recipient
void Message::changeRecipient( const std::string& new_recipient_name )
{ 
  // Make sure that the new recipient name is valid (at least one character)
  testPrecondition( new_recipient_name.size() > 0 );
  
  d_recipient_name = new_recipient_name;
}

// Change the message contents
void Message::changeMessageContents( const std::string& new_message )
{
  // Make sure that the new message is valid (at least one character)
  testPrecondition( new_message.size() > 0 );
  
  d_stored_message = new_message;
}

// Print method (overridden PrintableObject print method)
void Message::print( std::ostream &os )
{
  os << d_sender_name << "->" << d_recipient_name << ": " 
     << d_stored_message << std::endl;
}

} // end HelloWorld namespace

//---------------------------------------------------------------------------//
// end Message.cpp
//---------------------------------------------------------------------------//
