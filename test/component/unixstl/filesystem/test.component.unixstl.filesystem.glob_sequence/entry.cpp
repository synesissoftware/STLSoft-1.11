/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.unixstl.filesystem.glob_sequence/entry.cpp
 *
 * Purpose: Component test for `unixstl::glob_sequence`.
 *
 * Created: 24th January 2009
 * Updated: 27th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

//#define UNIXSTL_GLOB_SEQUENCE_TRUST_ONLYDIR
//#define UNIXSTL_GLOB_SEQUENCE_TRUST_ONLYFILE
#define UNIXSTL_GLOB_SEQUENCE_DONT_TRUST_MARK

#include <unixstl/filesystem/glob_sequence.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <unixstl/filesystem/filesystem_traits.hpp>
#include <unixstl/filesystem/path.hpp>
#include <unixstl/filesystem/current_directory.hpp>

/* Standard C++ header files */
#include <string>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_1_00(void);

    static void test_1_13(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);
    static void test_1_20(void);
    static void test_1_21(void);
    static void test_1_22(void);
    static void test_1_23(void);
    static void test_1_24(void);
    static void test_1_25(void);
    static void test_1_26(void);
    static void test_1_27(void);
    static void test_1_28(void);
    static void test_1_29(void);
    static void test_1_30(void);

    static void test_2_13(void);
    static void test_2_14(void);
    static void test_2_15(void);
    static void test_2_16(void);
    static void test_2_17(void);
    static void test_2_18(void);
    static void test_2_19(void);
    static void test_2_20(void);
    static void test_2_21(void);
    static void test_2_22(void);
    static void test_2_23(void);
    static void test_2_24(void);
    static void test_2_25(void);
    static void test_2_26(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.unixstl.filesystem.glob_sequence", verbosity))
    {
        XTESTS_RUN_CASE(test_1_00);

        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);
        XTESTS_RUN_CASE(test_1_20);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_1_24);
        XTESTS_RUN_CASE(test_1_25);
        XTESTS_RUN_CASE(test_1_26);
        XTESTS_RUN_CASE(test_1_27);
        XTESTS_RUN_CASE(test_1_28);
        XTESTS_RUN_CASE(test_1_29);
        XTESTS_RUN_CASE(test_1_30);

        XTESTS_RUN_CASE(test_2_13);
        XTESTS_RUN_CASE(test_2_14);
        XTESTS_RUN_CASE(test_2_15);
        XTESTS_RUN_CASE(test_2_16);
        XTESTS_RUN_CASE(test_2_17);
        XTESTS_RUN_CASE(test_2_18);
        XTESTS_RUN_CASE(test_2_19);
        XTESTS_RUN_CASE(test_2_20);
        XTESTS_RUN_CASE(test_2_21);
        XTESTS_RUN_CASE(test_2_22);
        XTESTS_RUN_CASE(test_2_23);
        XTESTS_RUN_CASE(test_2_24);
        XTESTS_RUN_CASE(test_2_25);
        XTESTS_RUN_CASE(test_2_26);

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

    typedef unixstl::glob_sequence              glob_sequence_t;
    typedef unixstl::filesystem_traits<char>    traits_m_t;
    typedef unixstl::basic_path<char>           path_m_t;

static void test_1_00(void)
{
}


static void test_1_13()
{
    glob_sequence_t files(".");

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
#if 0

        XTESTS_TEST_FAIL("dot directory should be elided");

        return;
#else /* ? 0 */

        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
#endif /* 0 */
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_14()
{
    glob_sequence_t files(".", glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_15()
{
    glob_sequence_t files("..");

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_16()
{
    glob_sequence_t files("..", glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_17()
{
    glob_sequence_t files(".", glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(".", *b);
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_18()
{
    glob_sequence_t files(".", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(".", *b);
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_19()
{
    glob_sequence_t files("..", glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_20()
{
    glob_sequence_t files("..", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_21()
{
    glob_sequence_t files("./*.*", glob_sequence_t::files);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_22()
{
    glob_sequence_t directories("./*.*", glob_sequence_t::directories);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_23()
{
    glob_sequence_t files("./*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_24()
{
    glob_sequence_t directories("./*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_25()
{
    glob_sequence_t files("../*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_26()
{
    glob_sequence_t directories("../*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_27()
{
    glob_sequence_t files(".*");

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));

        XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(".", *b);
        XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("..", *b);
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_28()
{
    glob_sequence_t files(".*", glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_29()
{
#ifdef GLOB_PERIOD
    glob_sequence_t files(".*", glob_sequence_t::matchPeriod);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));

        XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(".", *b);
        XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("..", *b);
    }}

    XTESTS_TEST_PASSED();
#endif /* GLOB_PERIOD */
}

static void test_1_30()
{
#ifdef GLOB_PERIOD
    glob_sequence_t files(".*", glob_sequence_t::includeDots | glob_sequence_t::matchPeriod);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
#endif /* GLOB_PERIOD */
}


static void test_2_13()
{
    glob_sequence_t files(".", ".");

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
#if 0

        XTESTS_TEST_FAIL("dot directory should be elided");
        return;
#else /* ? 0 */

        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
#endif /* 0 */
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_14()
{
    glob_sequence_t files(".", ".", glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_15()
{
    glob_sequence_t files(".", "..");

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_16()
{
    glob_sequence_t files(".", "..", glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_17()
{
    glob_sequence_t files(".", ".", glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_18()
{
    glob_sequence_t files(".", ".", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_19()
{
    glob_sequence_t files(".", "..", glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_20()
{
    glob_sequence_t files(".", "..", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_21()
{
    glob_sequence_t files(".", "*.*", glob_sequence_t::files);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_22()
{
    glob_sequence_t directories(".", "*.*", glob_sequence_t::directories);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_23()
{
    glob_sequence_t files(".", "*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_24()
{
    glob_sequence_t directories(".", "*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_25()
{
    glob_sequence_t files("..", "*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_26()
{
    glob_sequence_t directories("..", "*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

