//---------------------------------------------------------------------------//
//!
//! \file   PrintableObject.hpp
//! \author Alex Robinson
//! \brief  Printable object base class declaration
//!
//---------------------------------------------------------------------------//

#ifndef PRINTABLE_OBJECT_HPP
#define PRINTABLE_OBJECT_HPP

// Std Lib Includes
#include <string>
#include <ostream>

namespace HelloWorld{

//! The base class for printable objects
class PrintableObject
{

public:
  
  //! Constructor
  PrintableObject( const std::string &label = "PrintableObject" );

  //! Destructor
  virtual ~PrintableObject()
  { /* ... */ }

  //! Get the object label
  std::string getLabel() const;

  //! Print method for placing the printable object in an output stream.
  virtual void print( std::ostream &os ) const;

private:
  
  // Printable object label
  std::string d_label;
};

//! Stream operator for printing all printable objects
inline std::ostream& operator<<( std::ostream &os, 
				 const HelloWorld::PrintableObject &obj )
{
  os << obj.getLabel() << std::endl;
  obj.print( os );

  return os;
}

} // end HelloWorld namespace

#endif // end PRINTABLE_OBJECT_HPP

//---------------------------------------------------------------------------//
// end PrintableObject.hpp
//---------------------------------------------------------------------------//
