/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.unixstl.filesystem.squeeze_functions/entry.cpp
 *
 * Purpose: Unit-tests for `inetstl::squeeze_path`.
 *
 * Created: 29th October 2016
 * Updated: 11th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */


 #include <unixstl/filesystem/squeeze_functions.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <string>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void TEST_NULL_BUFFER();
    static void TEST_SUFFICIENT_SPACE();
    static void TEST_EXACT_SPACE();
    static void TEST_INSUFFICIENT_SPACE();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace {

    typedef std::basic_string<char>                         string_a_t;
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.unixstl.filesystem.squeeze_functions", verbosity))
    {
        XTESTS_RUN_CASE(TEST_NULL_BUFFER);
        XTESTS_RUN_CASE(TEST_SUFFICIENT_SPACE);
        XTESTS_RUN_CASE(TEST_EXACT_SPACE);
        XTESTS_RUN_CASE(TEST_INSUFFICIENT_SPACE);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

static void TEST_NULL_BUFFER()
{
    // stem only
    {
        char const* const input = "abcdef";

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 0);

            TEST_INT_EQ(7, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 4);

            TEST_INT_EQ(7, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 10);

            TEST_INT_EQ(7, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 11);

            TEST_INT_EQ(7, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 12);

            TEST_INT_EQ(7, cch);
        }
    }

    // file name
    {
        char const* const input = "abcdef.ghi";

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 0);

            TEST_INT_EQ(11, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 4);

            TEST_INT_EQ(11, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 10);

            TEST_INT_EQ(11, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 11);

            TEST_INT_EQ(11, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 12);

            TEST_INT_EQ(11, cch);
        }
    }

    // full path
    {
        char const* const input = "/_/xyz/mno/abcdef.ghi";

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 0);

            TEST_INT_EQ(22, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 4);

            TEST_INT_EQ(22, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 10);

            TEST_INT_EQ(22, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 11);

            TEST_INT_EQ(22, cch);
        }

        {
            size_t const cch = unixstl::path_squeeze(input, static_cast<char*>(NULL), 12);

            TEST_INT_EQ(22, cch);
        }
    }
}

static void TEST_SUFFICIENT_SPACE()
{
    // stem only
    {
        char const* const input = "abcdef";

        {
            char            buff[101];
            size_t const    cch = unixstl::path_squeeze(input, &buff[0], STLSOFT_NUM_ELEMENTS(buff));

            TEST_INT_EQ(7, cch);
            TEST_MS_EQ("abcdef", buff);
        }

        {
            char            buff[8];
            size_t const    cch = unixstl::path_squeeze(input, &buff[0], STLSOFT_NUM_ELEMENTS(buff));

            TEST_INT_EQ(7, cch);
            TEST_MS_EQ("abcdef", buff);
        }
    }

    // file name
    {
        // char const* const input = "abcdef.ghi";

    }

    // full path
    {
        // char const* const input = "/_/xyz/mno/abcdef.ghi";

    }
}

static void TEST_EXACT_SPACE()
{
    // stem only
    {
        char const* const input = "abcdef";

        {
            char            buff[7];
            size_t const    cch = unixstl::path_squeeze(input, &buff[0], STLSOFT_NUM_ELEMENTS(buff));

            TEST_INT_EQ(7, cch);
            TEST_MS_EQ("abcdef", buff);
        }
    }

}

static void TEST_INSUFFICIENT_SPACE()
{
    // stem only
    {
        char const* const input = "abcdef";

        {
            char            buff[6] = { '\0', '\1', '\2', '\3', '\4', '\5' };
            size_t const    cch = unixstl::path_squeeze(input, &buff[0], STLSOFT_NUM_ELEMENTS(buff));

            TEST_INT_EQ(6, cch);
            TEST_CHAR_EQ('\0', buff[5]);
            TEST_MS_EQ("a...f", buff);
        }

        {
            char            buff[7] = { '\0', '\1', '\2', '\3', '\4', '\5', '\6' };
            size_t const    cch = unixstl::path_squeeze(input, &buff[0], STLSOFT_NUM_ELEMENTS(buff) - 1);

            TEST_INT_EQ(6, cch);
            TEST_CHAR_EQ('\6', buff[6]);
            TEST_CHAR_EQ('\0', buff[5]);
            TEST_MS_EQ("a...f", buff);
        }

        {
            char            buff[5];
            size_t const    cch = unixstl::path_squeeze(input, &buff[0], STLSOFT_NUM_ELEMENTS(buff));

            TEST_INT_EQ(5, cch);
            TEST_MS_EQ("abcd", buff);
        }

        {
            char            buff[4];
            size_t const    cch = unixstl::path_squeeze(input, &buff[0], STLSOFT_NUM_ELEMENTS(buff));

            TEST_INT_EQ(4, cch);
            TEST_MS_EQ("abc", buff);
        }
    }

}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

