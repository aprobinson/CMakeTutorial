//---------------------------------------------------------------------------//
//!
//! \file   PrintableObject.cpp
//! \author Alex Robinson
//! \brief  Printable object base class definition
//!
//---------------------------------------------------------------------------//

// HelloWorld Includes
#include "PrintableObject.hpp"
#include "ContractException.hpp"

namespace HelloWorld{

// Constructor
PrintableObject::PrintableObject( const std::string &label )
  : d_label( label )
{ 
  // Make sure that the object label is valid (at least one character)
  testPrecondition( label.size() > 0 );
}

// Get the object label
std::string PrintableObject::getLabel() const
{
  return d_label;
}

// Default print method for placing the printable object in an output stream
void PrintableObject::print( std::ostream& os ) const
{ 
  os << d_label << std::endl; 
}

} // end HelloWorld namespace

//---------------------------------------------------------------------------//
// end PrintableObject.cpp
//---------------------------------------------------------------------------//

