/* /////////////////////////////////////////////////////////////////////////
 * File:    by_library/conversion/union_cast/union_cast.cpp
 *
 * Purpose: C++ example program demonstrating use of the Conversion
 *          library's union_cast component.
 *
 * Created: 10th June 2006
 * Updated: 4th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* STLSoft header files */
#include <stlsoft/conversion/union_cast.hpp>

/* Standard C++ header files */
#include <exception>
#include <iostream>

/* Standard C header files */
#include <stdint.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main()
{

    short*      ps;
    intptr_t    i   =   stlsoft::union_cast<intptr_t>(ps);  // Ok: both same size
#ifdef DEMONSTRATE_ERRORS

    char        c   =   stlsoft::union_cast<char>(ps);      // Compile error: different size
#endif


    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

