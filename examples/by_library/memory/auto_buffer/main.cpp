/* /////////////////////////////////////////////////////////////////////////
 * File:    by_library/memory/auto_buffer/auto_buffer.cpp
 *
 * Purpose: C++ example program demonstrating use of the Memory library
 *          component auto_buffer.
 *
 * Created: 15th September 2006
 * Updated: 9th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* STLSoft header files */
#include <stlsoft/memory/auto_buffer.hpp>


/* Standard C++ header files */
#include <exception>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C header files */
#include <stdlib.h> // for EXIT_FAILURE, EXIT_SUCCESS

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main()
{
    try
    {
        stlsoft::auto_buffer<char, 64>  buff(0);

        // Resize within the bounds of the internal buffer
        buff.resize(10);

        ::memset(&buff[0], 1, buff.size());

        // Resize outside the bounds of the internal buffer, and go to the heap
        buff.resize(100);

        ::memset(&buff[0], 2, buff.size());

        return EXIT_SUCCESS;
    }
    catch (std::exception& x)
    {
        cerr << "Error: " << x.what() << endl;

        return EXIT_FAILURE;
    }
    catch (...)
    {
        cerr << "Unknown error" << endl;

        return EXIT_FAILURE;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

