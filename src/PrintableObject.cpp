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
PrintableObject::PrintableObject( const std::string &label = "PrintableObject")
  : d_label( label )
{ 
  // Make sure that the object label is valid (at least one character)
  testPrecondition( label.size() > 0 );
}

// Default print method for placing the printable object in an output stream
PrintableObject::print( std::ostream& os ) const
{ 
  os << d_label << std:endl; 
}

// Stream operator for printing all printable objects
inline std::ostream& operator<<( std::ostream &os,
				 const HelloWorld::PrintableObject &obj )
{
  os << obj.getLabel() << std::endl;
  obj.print( os );

  return os;
}

} // end HelloWorld namespace

//---------------------------------------------------------------------------//
// end PrintableObject.cpp
//---------------------------------------------------------------------------//

