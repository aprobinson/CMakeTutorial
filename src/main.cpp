//---------------------------------------------------------------------------//
//!
//! \file   main.cpp
//! \author Alex Robinson
//! \brief  The Hello World program.
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <string>
#include <iostream>
#include <sstream>

// HelloWorld Includes
#include "PrintableObject.hpp"
#include "Message.hpp"
#include "Comm.hpp"

int main( int argc, char* argv[] )
{

  int rank = 0;
  int size = 1;

#if HAVE_HelloWorld_MPI
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
#endif
  
  // My name
  std::string my_name( "Proc " );
  std::stringstream proc_number;
  proc_number << my_name << rank;
  my_name = proc_number.str();

  // My recipient
  std::string my_recipient( "World" );

  // My message contents
  std::string my_message_contents( "Hello!" );

  // My message
  HelloWorld::Message my_message( my_name, my_recipient, my_message_contents);

  // Send my message
  std::cout << my_message << std::endl;	

#if HAVE_HellowWorld_MPI
  MPI_Finalize();
#endif
  
  return 0;
}

//---------------------------------------------------------------------------//
// end main.cpp
//---------------------------------------------------------------------------//



