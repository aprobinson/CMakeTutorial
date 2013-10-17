//---------------------------------------------------------------------------//
//!
//! \file   Comm.hpp
//! \author Alex Robinson
//! \brief  This file sets up MPI for the project if required
//!
//---------------------------------------------------------------------------//

#ifndef COMM_HPP
#define COMM_HPP

// Include the MPI config file
#include "HelloWorld_mpi_config.hpp"

// If MPI has been enabled, include the necessary mpi files
#ifdef HAVE_HelloWorld_MPI

#include "mpi.h"

#endif

#endif // end COMM_HPP

//---------------------------------------------------------------------------//
// end Comm.hpp
//---------------------------------------------------------------------------//
