/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.platformstl.system.system_traits/entry.cpp
 *
 * Purpose: Unit-tests for `platformstl::system_traits`.
 *
 * Created: 29th January 2013
 * Updated: 26th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <platformstl/system/system_traits.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <platformstl/system/environment_variable.hpp>

/* Standard C++ header files */

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_INSUFFICIENT_SPACE(void);
    static void TEST_get_home_directory(void);
    static void test_1_2(void);
    static void test_1_3(void);
    static void test_1_4(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.platformstl.system.system_traits", verbosity))
    {
        XTESTS_RUN_CASE(TEST_INSUFFICIENT_SPACE);
        XTESTS_RUN_CASE(TEST_get_home_directory);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

static void TEST_INSUFFICIENT_SPACE()
{
    size_t const required = platformstl::system_traits<char>::get_home_directory(NULL, 0);

    // TODO: consider (strongly) making the UNIXSTL and WinSTL implementations consistent, and also consider whether it's any use at all to get a partial result

#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)

    if(0 != required)
    {
        { for(size_t i = 1; i != required; ++i)
        {
            stlsoft::auto_buffer<char>  buff(i);

            size_t const cch = platformstl::system_traits<char>::get_home_directory(&buff[0], buff.size());

            XTESTS_TEST_INTEGER_EQUAL(i - 1, cch);
        }}
    }
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    if(0 != required)
    {
        { for(size_t i = 1; i != required; ++i)
        {
            stlsoft::auto_buffer<char>  buff(i);

            size_t const cch = platformstl::system_traits<char>::get_home_directory(&buff[0], buff.size());

            XTESTS_TEST_INTEGER_EQUAL(required, cch);
        }}
    }
#endif

    stlsoft::auto_buffer<char>  buff(required);
    size_t const                actual = platformstl::system_traits<char>::get_home_directory(&buff[0], buff.size());

    XTESTS_TEST_INTEGER_EQUAL(required - 1, actual);
}

static void TEST_get_home_directory()
{
#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)

    platformstl::environment_variable_a HOME("HOME");

    stlsoft::auto_buffer<char>          buff(1 + HOME.size());
    size_t const                        cch = platformstl::system_traits<char>::get_home_directory(&buff[0], buff.size());

    XTESTS_TEST_INTEGER_EQUAL(HOME.size(), cch);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(std::string(HOME), buff.data());

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    platformstl::environment_variable_a HOMEDRIVE("HOMEDRIVE");
    platformstl::environment_variable_a HOMEPATH("HOMEPATH");

    stlsoft::auto_buffer<char>          buff(1 + HOMEDRIVE.size() + HOMEPATH.size());
    size_t const                        cch = platformstl::system_traits<char>::get_home_directory(&buff[0], buff.size());

    XTESTS_TEST_INTEGER_EQUAL(HOMEDRIVE.size() + HOMEPATH.size(), cch);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(std::string(HOMEDRIVE) + std::string(HOMEPATH), buff.data());
#endif
}

static void test_1_2()
{
}

static void test_1_3()
{
}

static void test_1_4()
{
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

