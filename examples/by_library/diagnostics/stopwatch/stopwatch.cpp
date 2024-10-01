/* /////////////////////////////////////////////////////////////////////////
 * File:    by_library/diagnostics/stopwatch.cpp
 *
 * Purpose: C++ example program demonstrating use of the Performance library.
 *
 * Created: 22nd May 2006
 * Updated: 4th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* PlatformSTL header files */
#include <platformstl/diagnostics/stopwatch.hpp>

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
    // 1. Create an instance of the platformstl::stopwatch. (On
    // UNIX this will resolve to unixstl::stopwatch; on Win32 it
    // will resolve to winstl::stopwatch.)
    platformstl::stopwatch    sw;

    // 2. Begin the measurement
    sw.start();

    // 3. A loop that will consume some time.
    { for (volatile size_t i = 0; i != 0x1fffffff; )
    {
        size_t j = i;
        i = ++j;
    }}

    // 4. End the measurement
    sw.stop();

    // 5. Display the number of whole seconds that have elapsed.
    cout << "interval (s):  " << static_cast<unsigned>(sw.get_seconds()) << endl;
    // 6. Display the number of whole milliseconds that have elapsed.
    cout << "interval (ms): " << static_cast<unsigned>(sw.get_milliseconds()) << endl;
    // 7. Display the number of whole microseconds that have elapsed.
    cout << "interval (us): " << static_cast<unsigned>(sw.get_microseconds()) << endl;

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

