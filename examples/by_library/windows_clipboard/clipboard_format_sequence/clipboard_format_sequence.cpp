/* /////////////////////////////////////////////////////////////////////////
 * File:    by_library/windows_clipboard/clipboard_format_sequence/clipboard_format_sequence.cpp
 *
 * Purpose: C++ example program demonstrating use of the Windows Clipboard
 *          library.
 *
 * Created: 6th June 2006
 * Updated: 4th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* WinSTL header files */
#include <winstl/clipboard/clipboard_format_sequence.hpp>

/* Standard C++ header files */
#include <iostream>


int main()
{
    try
    {
        winstl::clipboard_format_sequence   formats;

        { for(winstl::clipboard_format_sequence::const_iterator b = files.begin(); b != files.end(); ++b)
        {
            std::cout << "    " << *b << std::endl;
        }}
    }
    catch (winstl::clipboard_scope_exception &x)
    {
        std::cerr << "Exception: " << x.what() << std::endl;
    }

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

