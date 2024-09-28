/* /////////////////////////////////////////////////////////////////////////
 * File:    by_library/conversion/interface_cast/interface_cast.cpp
 *
 * Purpose: C++ example program demonstrating use of the Conversion
 *          library's interface_cast component.
 *
 * Created: 9th December 2006
 * Updated: 4th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* COMSTL header files */
#include <comstl/conversion/interface_cast.hpp>

/* STLSoft header files */
#include <stlsoft/smartptr/ref_ptr.hpp>

/* Standard C++ header files */
#include <exception>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main()
{
    try
    {
        /* Get a stream to play with ... */
        LPSTREAM    pstm;
        HRESULT     hr = ::CreateStreamOnHGlobal(NULL, true, &pstm);

        if(SUCCEEDED(hr))
        {
            stlsoft::ref_ptr<IStream>   stm(pstm, false);   /* Eat the reference */

            /* Can the pointer be cast to IStorage*? */
            if(comstl::interface_cast_test<IStorage*>(pstm))
            {
                comstl::interface_cast_noaddref<IStorage*>->SetClass(CLSID_NULL);

                comstl::interface_cast_noaddref<IStorage*>->SetClass(CLSID_NULL);
            }

            /* Can the wrapper be cast to IStorage*? */
            if(comstl::interface_cast_test<IStorage*>(stm))
            {
                // . . .
            }

        }
    }

    short   *ps;
    int     i   =   stlsoft::interface_cast<int>(ps);       // Ok: both same size
    double  d   =   stlsoft::interface_cast<double>(ps);    // Compile error: different size


    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

