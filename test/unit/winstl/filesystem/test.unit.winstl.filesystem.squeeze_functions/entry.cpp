/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.winstl.filesystem.squeeze_functions/entry.cpp
 *
 * Purpose: Unit-tests for `winstl::squeeze_path`.
 *
 * Created: 29th October 2016
 * Updated: 15th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <winstl/filesystem/squeeze_functions.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.winstl.filesystem.squeeze_functions", verbosity))
    {

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {


#if 0

SCENARIO("testing winstl/filesystem/squeeze_functions.hpp", "[file-system]") {

    GIVEN("a file name only") {

        char const* const input = "abcdef.ghi";

        THEN("check passing in a null buffer") {

            size_t  cch = winstl::path_squeeze(input, static_cast<char*>(NULL), 0);

            CHECK(11u == cch);
        }

        AND_THEN("check passing in a buffer length of 0") {

            char    buffer[1] = { '~' };
            size_t  cch = winstl::path_squeeze(input, buffer, 0);

            CHECK(0u == cch);
            CHECK('~' == buffer[0]);
        }

        AND_THEN("checking passing in a too-small buffer (length 1)") {

            char    buffer[1];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(1u == cch);
            CHECK('\0' == buffer[0]);
        }

        AND_THEN("checking passing in a too-small buffer (length 2)") {

            char    buffer[2];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(2u == cch);
            CHECK(string_a_t("a") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 3)") {

            char    buffer[3];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(3u == cch);
            CHECK(string_a_t("ab") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 4)") {

            char    buffer[4];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(4u == cch);
            CHECK(string_a_t("abc") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 5)") {

            char    buffer[5];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(5u == cch);
            CHECK(string_a_t("abcd") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 6)") {

            char    buffer[6];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(6u == cch);
            CHECK(string_a_t("a...i") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 7)") {

            char    buffer[7];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(7u == cch);
            CHECK(string_a_t("a...hi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 8)") {

            char    buffer[8];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(8u == cch);
            CHECK(string_a_t("ab...hi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 9)") {

            char    buffer[9];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(9u == cch);
            CHECK(string_a_t("ab...ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 10)") {

            char    buffer[10];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(10u == cch);
            CHECK(string_a_t("abc...ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 11)") {

            char    buffer[11];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(11u == cch);
            CHECK(string_a_t(input) == buffer);
        }

        AND_THEN("checking passing in an adequate buffer (length 12)") {

            char    buffer[12];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(11u == cch);
            CHECK(string_a_t(input) == buffer);
        }

        AND_THEN("checking passing in an adequate buffer (length 120)") {

            char    buffer[120];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(11u == cch);
            CHECK(string_a_t(input) == buffer);
        }
    }

    GIVEN("a relative path") {

        char const* const input = "/_/xyz/mno/abcdef.ghi";

        THEN("check passing in a null buffer") {

            size_t  cch = winstl::path_squeeze(input, static_cast<char*>(NULL), 0);

            CHECK(22u == cch);
        }

        AND_THEN("check passing in a buffer length of 0") {

            char    buffer[1] = { '~' };
            size_t  cch = winstl::path_squeeze(input, buffer, 0);

            CHECK(0u == cch);
            CHECK('~' == buffer[0]);
        }

        AND_THEN("checking passing in a too-small buffer (length 1)") {

            char    buffer[1];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(1u == cch);
            CHECK('\0' == buffer[0]);
        }

        AND_THEN("checking passing in a too-small buffer (length 2)") {

            char    buffer[2];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(2u == cch);
            CHECK(string_a_t("a") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 3)") {

            char    buffer[3];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(3u == cch);
            CHECK(string_a_t("ab") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 4)") {

            char    buffer[4];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(4u == cch);
            CHECK(string_a_t("abc") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 5)") {

            char    buffer[5];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(5u == cch);
            CHECK(string_a_t("abcd") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 6)") {

            char    buffer[6];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(6u == cch);
            CHECK(string_a_t("a...i") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 7)") {

            char    buffer[7];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(7u == cch);
            CHECK(string_a_t("a...hi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 8)") {

            char    buffer[8];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(8u == cch);
            CHECK(string_a_t("ab...hi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 9)") {

            char    buffer[9];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(9u == cch);
            CHECK(string_a_t("ab...ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 10)") {

            char    buffer[10];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(10u == cch);
            CHECK(string_a_t("abc...ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 11)") {

            char    buffer[11];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(11u == cch);
            CHECK(string_a_t("abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 12 - 17)") {

            char    buffer[17];

            for (size_t n = 12; n != 16; ++n)
            {
                size_t  cch = winstl::path_squeeze(input, buffer, n);

                CHECK(11u == cch);
                CHECK(string_a_t("abcdef.ghi") == buffer);
            }
        }

        AND_THEN("checking passing in a too-small buffer (length 16)") {

            char    buffer[16];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(16u == cch);
            CHECK(string_a_t("/.../abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 17)") {

            char    buffer[17];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(17u == cch);
            CHECK(string_a_t("/_.../abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 18)") {

            char    buffer[18];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(18u == cch);
            CHECK(string_a_t("/_/.../abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 19)") {

            char    buffer[19];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(19u == cch);
            CHECK(string_a_t("/_/x.../abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in an adequate buffer (length 20)") {

            char    buffer[20];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(20u == cch);
            CHECK(string_a_t("/_/xy.../abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in an adequate buffer (length 21)") {

            char    buffer[21];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(21u == cch);
            CHECK(string_a_t("/_/xyz.../abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in an adequate buffer (length 22)") {

            char    buffer[22];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(22u == cch);
            CHECK(string_a_t(input) == buffer);
        }

        AND_THEN("checking passing in an adequate buffer (length 23)") {

            char    buffer[23];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(22u == cch);
            CHECK(string_a_t(input) == buffer);
        }

        AND_THEN("checking passing in an adequate buffer (length 220)") {

            char    buffer[220];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(22u == cch);
            CHECK(string_a_t(input) == buffer);
        }
    }

    GIVEN("a drive-rooted path") {

        char const* const input = "H:/xyz/mno/abcdef.ghi";

        THEN("check passing in a null buffer") {

            size_t  cch = winstl::path_squeeze(input, static_cast<char*>(NULL), 0);

            CHECK(22u == cch);
        }

        AND_THEN("check passing in a buffer length of 0") {

            char    buffer[1] = { '~' };
            size_t  cch = winstl::path_squeeze(input, buffer, 0);

            CHECK(0u == cch);
            CHECK('~' == buffer[0]);
        }

        AND_THEN("checking passing in a too-small buffer (length 1)") {

            char    buffer[1];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(1u == cch);
            CHECK('\0' == buffer[0]);
        }

        AND_THEN("checking passing in a too-small buffer (length 2)") {

            char    buffer[2];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(2u == cch);
            CHECK(string_a_t("a") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 3)") {

            char    buffer[3];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(3u == cch);
            CHECK(string_a_t("ab") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 4)") {

            char    buffer[4];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(4u == cch);
            CHECK(string_a_t("abc") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 5)") {

            char    buffer[5];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(5u == cch);
            CHECK(string_a_t("abcd") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 6)") {

            char    buffer[6];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(6u == cch);
            CHECK(string_a_t("a...i") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 7)") {

            char    buffer[7];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(7u == cch);
            CHECK(string_a_t("a...hi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 8)") {

            char    buffer[8];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(8u == cch);
            CHECK(string_a_t("ab...hi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 9)") {

            char    buffer[9];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(9u == cch);
            CHECK(string_a_t("ab...ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 10)") {

            char    buffer[10];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(10u == cch);
            CHECK(string_a_t("abc...ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 11)") {

            char    buffer[11];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(11u == cch);
            CHECK(string_a_t("abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 12 - 17)") {

            char    buffer[17];

            for (size_t n = 12; n != 18; ++n)
            {
                size_t  cch = winstl::path_squeeze(input, buffer, n);

                CHECK(11u == cch);
                CHECK(string_a_t("abcdef.ghi") == buffer);
            }
        }

        AND_THEN("checking passing in a too-small buffer (length 18)") {

            char    buffer[18];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(18u == cch);
            CHECK(string_a_t("H:/.../abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 19)") {

            char    buffer[19];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(19u == cch);
            CHECK(string_a_t("H:/x.../abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 20)") {

            char    buffer[20];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(20u == cch);
            CHECK(string_a_t("H:/xy.../abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in a too-small buffer (length 21)") {

            char    buffer[21];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(21u == cch);
            CHECK(string_a_t("H:/xyz.../abcdef.ghi") == buffer);
        }

        AND_THEN("checking passing in an adequate buffer (length 22)") {

            char    buffer[22];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(22u == cch);
            CHECK(string_a_t(input) == buffer);
        }

        AND_THEN("checking passing in an adequate buffer (length 220)") {

            char    buffer[220];
            size_t  cch = winstl::path_squeeze(input, buffer, dimensionof(buffer));

            CHECK(22u == cch);
            CHECK(string_a_t(input) == buffer);
        }
    }
}
#endif

} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

