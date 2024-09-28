/* /////////////////////////////////////////////////////////////////////////
 * File:    by_library/windows_control_panel/windows_control_panel/windows_control_panel.cpp
 *
 * Purpose: C++ example program demonstrating use of the Windows Control
 *          Panel library.
 *
 * Created: 27th May 2006
 * Updated: 4th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* WinSTL header files */
#include <winstl/findfile_sequence.hpp>
#include <winstl/system_directory.hpp>
#include <winstl/control_panel/applet_module.hpp>

/* Standard C++ header files */
#include <iostream>


int main()
{
    try
    {
        winstl::system_directory    sysDir;
        winstl::findfile_sequence   files(sysDir, "*.cpl", winstl::findfile_sequence::files);

        { for(winstl::findfile_sequence::const_iterator b = files.begin(); b != files.end(); ++b)
        {
            winstl::applet_module module(*b, winstl::applet_module::dontExpectNonZeroInit);

            winstl::applet_module::const_iterator   b = module.begin();
            winstl::applet_module::const_iterator   e = module.end();

            std::cout << "path:          " << module.get_path() << std::endl;
            for(; b != e; ++b)
            {
                winstl::applet const    &applet = *b;

                std::cout << " applet index: " << applet.get_index() << std::endl;

                std::cout << "  name:        " << applet.get_name() << std::endl;
                std::cout << "  description: " << applet.get_description() << std::endl;
            }
            std::cout << std::endl;
        }}
    }
    catch (std::exception &x)
    {
        std::cerr << "Exception: " << x.what() << std::endl;
    }

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

