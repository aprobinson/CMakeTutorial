//---------------------------------------------------------------------------//
//!
//! \file   Message.hpp
//! \author Alex Robinson
//! \brief  Declaration of a simple class that stores a message.
//!
//---------------------------------------------------------------------------//

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

// Std Lib Includes
#include <string>
#include <iostream>

namespace HelloWorld{

//! Message class stores a message and can be printed through std::iostream.
class Message : public PrintableObject
{

public:

  //! Default Constructor
  Message();

  //! Constructor
  Message( const std::string& sender_name,
	   const std::string& recipient_name,
	   const std::string& sender_message );

  //! Destructor
  virtual ~Message()
  { /* ... */ }

  //! Change the message recipient
  void changeRecipient( const std::string& new_recipient_name );

  //! Change the message contents
  void changeMessageContents( const std::string& new_message );

  //! Print method (overridden PrintableObject print method)
  void print( std::ostream& os );

private:

  std::string d_sender_name;
  std::string d_recipient_name;
  std::string d_stored_message;

};

} // end HelloWorld namespace

#endif // end MESSAGE_HPP

//---------------------------------------------------------------------------//
// end Message.hpp
//---------------------------------------------------------------------------//
