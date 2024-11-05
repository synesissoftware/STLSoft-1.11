/* /////////////////////////////////////////////////////////////////////////
 * File:    by_library/diagnostics/processtimes_stopwatch.cpp
 *
 * Purpose: C++ example program demonstrating use of the Diagnostics
 *          library's processtimes_stopwatch component.
 *
 * Created: 9th June 2006
 * Updated: 4th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* PlatformSTL header files */
#include <platformstl/diagnostics/stopwatch.hpp>
#include <platformstl/diagnostics/processtimes_stopwatch.hpp>
#include <platformstl/synch/sleep_functions.h>

/* Standard C++ header files */
#include <exception>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h> // for EXIT_FAILURE, EXIT_SUCCESS


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main()
{
    // 1.a. Create an instance of the platformstl::processtimes_stopwatch. (On
    // UNIX this will resolve to unixstl::processtimes_stopwatch; on Win32 it
    // will resolve to winstl::processtimes_stopwatch.)
    platformstl::processtimes_stopwatch usageCounter;
    // 1.b. Create an instance of the platformstl::stopwatch that
    // will be used to measure the elapsed times.
    platformstl::stopwatch              elapsedCounter;

    // 2. Begin the measurement
    usageCounter.start();
    elapsedCounter.start();

    // 3.a. A loop that will consume some user time.
    { for (volatile size_t i = 0; i != 0x1fffffff; )
    {
        size_t j = i;
        i = ++j;
    }}
    // 3.b. A loop that will consume some kernel time.
    { for (volatile size_t i = 0; i != 0x1ffff; )
    {
        size_t j = i;
        i = ++j;

        fprintf(stdout, " \b");
    }}
    // 3.c. A sleep, for five seconds, to separate elapsed and usage times.
    platformstl::micro_sleep(5 * 1000 * 1000);

    // 4. End the measurement
    usageCounter.stop();
    elapsedCounter.stop();

    // 5.a. Display the number of whole seconds of elapsed time
    cout << "elapsed interval (s):  " << static_cast<unsigned>(elapsedCounter.get_seconds()) << endl;
    // 6.a. Display the number of whole milliseconds of user time.
    cout << "elapsed interval (ms): " << static_cast<unsigned>(elapsedCounter.get_milliseconds()) << endl;
    // 7.a. Display the number of whole microseconds of user time.
    cout << "elapsed interval (us): " << static_cast<unsigned>(elapsedCounter.get_microseconds()) << endl;

    // 5.b. Display the number of whole seconds of user time.
    cout << "user interval (s):     " << static_cast<unsigned>(usageCounter.get_user_seconds()) << endl;
    // 6.b. Display the number of whole milliseconds of user time.
    cout << "user interval (ms):    " << static_cast<unsigned>(usageCounter.get_user_milliseconds()) << endl;
    // 7.b. Display the number of whole microseconds of user time.
    cout << "user interval (us):    " << static_cast<unsigned>(usageCounter.get_user_microseconds()) << endl;

    // 5.c. Display the number of whole seconds of kernel time.
    cout << "kernel interval (s):   " << static_cast<unsigned>(usageCounter.get_kernel_seconds()) << endl;
    // 6.c. Display the number of whole milliseconds of kernel time.
    cout << "kernel interval (ms):  " << static_cast<unsigned>(usageCounter.get_kernel_milliseconds()) << endl;
    // 7.c. Display the number of whole microseconds of kernel time.
    cout << "kernel interval (us):  " << static_cast<unsigned>(usageCounter.get_kernel_microseconds()) << endl;

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

