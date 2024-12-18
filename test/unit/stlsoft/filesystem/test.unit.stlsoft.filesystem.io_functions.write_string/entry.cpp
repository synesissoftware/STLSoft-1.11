/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.filesystem.io_functions.write_string/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::write_string<>()`.
 *
 * Created: 22nd January 2024
 * Updated: 17th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/filesystem/io_functions/write_string.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>
#include <xtests/util/temp_file.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <platformstl/filesystem/FILE_stream.hpp>
#include <platformstl/filesystem/file_lines.hpp>

/* Standard C++ header files */
#include <string>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_write_css_n_empty(void);
    static void test_write_css_n_1_character(void);
    static void test_write_css_n_1_long_string(void);
    static void test_write_css_n_3_strings(void);

    static void test_write_css_empty(void);
    static void test_write_css_1_character(void);
    static void test_write_css_1_long_string(void);
    static void test_write_css_3_strings(void);

    static void test_write_stdstring_empty(void);
    static void test_write_stdstring_1_character(void);
    static void test_write_stdstring_1_long_string(void);
    static void test_write_stdstring_3_strings(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.filesystem.io_functions.write_string", verbosity))
    {
        XTESTS_RUN_CASE(test_write_css_n_empty);
        XTESTS_RUN_CASE(test_write_css_n_1_character);
        XTESTS_RUN_CASE(test_write_css_n_1_long_string);
        XTESTS_RUN_CASE(test_write_css_n_3_strings);

        XTESTS_RUN_CASE(test_write_css_empty);
        XTESTS_RUN_CASE(test_write_css_1_character);
        XTESTS_RUN_CASE(test_write_css_1_long_string);
        XTESTS_RUN_CASE(test_write_css_3_strings);

        XTESTS_RUN_CASE(test_write_stdstring_empty);
        XTESTS_RUN_CASE(test_write_stdstring_1_character);
        XTESTS_RUN_CASE(test_write_stdstring_1_long_string);
        XTESTS_RUN_CASE(test_write_stdstring_3_strings);


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
    using ::xtests::cpp::util::temp_file;


static void test_write_css_n_empty()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        stlsoft::write_string(stm, "", 0);
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(0u, lines.size());
    }
}

static void test_write_css_n_1_character()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        stlsoft::write_string(stm, "a", 1);
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", lines[0]);
    }
}

static void test_write_css_n_1_long_string()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        stlsoft::write_string(stm, "abcdefghijklmnopqrstuvwxyz", 26);
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", lines[0]);
    }
}

static void test_write_css_n_3_strings()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        stlsoft::write_string(stm, "abc\n", 4);
        stlsoft::write_string(stm, "defg\n", 5);
        stlsoft::write_string(stm, "hi\n", 3);
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(3u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defg", lines[1]);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("hi", lines[2]);
    }
}


static void test_write_css_empty()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        stlsoft::write_string(stm, "");
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(0u, lines.size());
    }
}

static void test_write_css_1_character()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        stlsoft::write_string(stm, "a");
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", lines[0]);
    }
}

static void test_write_css_1_long_string()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        stlsoft::write_string(stm, "abcdefghijklmnopqrstuvwxyz");
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", lines[0]);
    }
}

static void test_write_css_3_strings()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        stlsoft::write_string(stm, "abc\n");
        stlsoft::write_string(stm, "defg\n");
        stlsoft::write_string(stm, "hi\n");
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(3u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defg", lines[1]);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("hi", lines[2]);
    }
}


static void test_write_stdstring_empty()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        std::string const           s;

        stlsoft::write_string(stm, s);
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(0u, lines.size());
    }
}

static void test_write_stdstring_1_character()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        std::string const           s("a");

        stlsoft::write_string(stm, s);
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", lines[0]);
    }
}

static void test_write_stdstring_1_long_string()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        std::string const           s("abcdefghijklmnopqrstuvwxyz");

        stlsoft::write_string(stm, s);
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", lines[0]);
    }
}

static void test_write_stdstring_3_strings()
{
    temp_file   f(temp_file::DeleteOnClose | temp_file::EmptyOnOpen | temp_file::CloseOnOpen);


    {
        platformstl::FILE_stream    stm(f.c_str(), "w");

        std::string const           s1("abc\n");
        std::string const           s2("defg\n");
        std::string const           s3("hi\n");

        stlsoft::write_string(stm, s1);
        stlsoft::write_string(stm, s2);
        stlsoft::write_string(stm, s3);
    }

    {
        platformstl::file_lines     lines(f.c_str());

        XTESTS_TEST_INTEGER_EQUAL(3u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defg", lines[1]);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("hi", lines[2]);
    }
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

