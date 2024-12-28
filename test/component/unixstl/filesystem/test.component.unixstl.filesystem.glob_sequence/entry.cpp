/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.unixstl.filesystem.glob_sequence/entry.cpp
 *
 * Purpose: Component test for `unixstl::glob_sequence`.
 *
 * Created: 24th January 2009
 * Updated: 28th December 2024
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
#include <xtests/util/temp_directory.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <unixstl/filesystem/filesystem_traits.hpp>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_empty_directory();

    static void test_dot();
    static void test_dot_and_includeDots();
    static void test_dotdot();
    static void test_dotdot_and_includeDots();
    static void test_dot_and_absolutePath();
    static void test_dot_and_absolutePath_includeDots();
    static void test_dotdot_and_absolutePath();
    static void test_dotdot_and_absolutePath_includeDots();
    static void test_dotslashstardotstar_and_files();
    static void test_dotslashstardotstar_and_directories();
    static void test_dotslashstardotstar_and_files_absolutePath();
    static void test_dotslashstardotstar_and_directories_absolutePath();
    static void test_dotdotslashstardotstar_and_files_absolutePath();
    static void test_dotdotslashstardotstar_and_directories_absolutePath();
    static void test_dotstar();
    static void test_dotstar_and_includeDots();
    static void test_dotstar_and_matchPeriod();
    static void test_dotstar_and_includeDots_matchPeriod();

    static void test_dot_and_dot();
    static void test_dot_and_dot_and_includeDots();
    static void test_dot_and_dotdot();
    static void test_dot_and_dotdot_and_includeDots();
    static void test_dot_and_dot_and_absolutePath();
    static void test_dot_and_dot_and_absolutePath_includeDots();
    static void test_dot_and_dotdot_and_absolutePath();
    static void test_dot_and_dotdot_and_absolutePath_includeDots();
    static void test_dot_and_stardotstar_and_files();
    static void test_dot_and_stardotstar_and_directories();
    static void test_dot_and_stardotstar_and_files_absolutePath();
    static void test_dot_and_stardotstar_and_directories_absolutePath();
    static void test_dotdot_and_stardotstar_and_files_absolutePath();
    static void test_dotdot_and_stardotstar_and_directories_absolutePath();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.unixstl.filesystem.glob_sequence", verbosity))
    {
        XTESTS_RUN_CASE(test_empty_directory);

        XTESTS_RUN_CASE(test_dot);
        XTESTS_RUN_CASE(test_dot_and_includeDots);
        XTESTS_RUN_CASE(test_dotdot);
        XTESTS_RUN_CASE(test_dotdot_and_includeDots);
        XTESTS_RUN_CASE(test_dot_and_absolutePath);
        XTESTS_RUN_CASE(test_dot_and_absolutePath_includeDots);
        XTESTS_RUN_CASE(test_dotdot_and_absolutePath);
        XTESTS_RUN_CASE(test_dotdot_and_absolutePath_includeDots);
        XTESTS_RUN_CASE(test_dotslashstardotstar_and_files);
        XTESTS_RUN_CASE(test_dotslashstardotstar_and_directories);
        XTESTS_RUN_CASE(test_dotslashstardotstar_and_files_absolutePath);
        XTESTS_RUN_CASE(test_dotslashstardotstar_and_directories_absolutePath);
        XTESTS_RUN_CASE(test_dotdotslashstardotstar_and_files_absolutePath);
        XTESTS_RUN_CASE(test_dotdotslashstardotstar_and_directories_absolutePath);
        XTESTS_RUN_CASE(test_dotstar);
        XTESTS_RUN_CASE(test_dotstar_and_includeDots);
        XTESTS_RUN_CASE(test_dotstar_and_matchPeriod);
        XTESTS_RUN_CASE(test_dotstar_and_includeDots_matchPeriod);

        XTESTS_RUN_CASE(test_dot_and_dot);
        XTESTS_RUN_CASE(test_dot_and_dot_and_includeDots);
        XTESTS_RUN_CASE(test_dot_and_dotdot);
        XTESTS_RUN_CASE(test_dot_and_dotdot_and_includeDots);
        XTESTS_RUN_CASE(test_dot_and_dot_and_absolutePath);
        XTESTS_RUN_CASE(test_dot_and_dot_and_absolutePath_includeDots);
        XTESTS_RUN_CASE(test_dot_and_dotdot_and_absolutePath);
        XTESTS_RUN_CASE(test_dot_and_dotdot_and_absolutePath_includeDots);
        XTESTS_RUN_CASE(test_dot_and_stardotstar_and_files);
        XTESTS_RUN_CASE(test_dot_and_stardotstar_and_directories);
        XTESTS_RUN_CASE(test_dot_and_stardotstar_and_files_absolutePath);
        XTESTS_RUN_CASE(test_dot_and_stardotstar_and_directories_absolutePath);
        XTESTS_RUN_CASE(test_dotdot_and_stardotstar_and_files_absolutePath);
        XTESTS_RUN_CASE(test_dotdot_and_stardotstar_and_directories_absolutePath);

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

    typedef unixstl::glob_sequence                          glob_sequence_t;
    typedef unixstl::filesystem_traits<char>                traits_m_t;

    using ::xtests::cpp::util::temp_directory;


static void test_empty_directory()
{
    temp_directory temp_dir(temp_directory::EmptyOnClose | temp_directory::EmptyOnOpen | temp_directory::RemoveOnClose);

    {
        glob_sequence_t gs(temp_dir.c_str(), glob_sequence_t::files);

        XTESTS_TEST_BOOLEAN_TRUE(gs.empty());
    }

    {
        glob_sequence_t gs(temp_dir.c_str(), "*.*", glob_sequence_t::files);

        XTESTS_TEST_BOOLEAN_TRUE(gs.empty());
    }

    {
        glob_sequence_t gs(temp_dir.c_str(), "*.*");

        XTESTS_TEST_BOOLEAN_TRUE(gs.empty());
    }
}

static void test_dot()
{
    glob_sequence_t files(".");

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_includeDots()
{
    glob_sequence_t files(".", glob_sequence_t::includeDots);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotdot()
{
    glob_sequence_t files("..");

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotdot_and_includeDots()
{
    glob_sequence_t files("..", glob_sequence_t::includeDots);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_absolutePath()
{
    glob_sequence_t files(".", glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(".", *b);
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_absolutePath_includeDots()
{
    glob_sequence_t files(".", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(".", *b);
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotdot_and_absolutePath()
{
    glob_sequence_t files("..", glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotdot_and_absolutePath_includeDots()
{
    glob_sequence_t files("..", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotslashstardotstar_and_files()
{
    glob_sequence_t files("./*.*", glob_sequence_t::files);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotslashstardotstar_and_directories()
{
    glob_sequence_t directories("./*.*", glob_sequence_t::directories);

    { for (glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotslashstardotstar_and_files_absolutePath()
{
    glob_sequence_t files("./*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotslashstardotstar_and_directories_absolutePath()
{
    glob_sequence_t directories("./*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotdotslashstardotstar_and_files_absolutePath()
{
    glob_sequence_t files("../*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotdotslashstardotstar_and_directories_absolutePath()
{
    glob_sequence_t directories("../*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotstar()
{
    glob_sequence_t files(".*");

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));

        XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(".", *b);
        XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("..", *b);
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotstar_and_includeDots()
{
    glob_sequence_t files(".*", glob_sequence_t::includeDots);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotstar_and_matchPeriod()
{
#ifdef GLOB_PERIOD
    glob_sequence_t files(".*", glob_sequence_t::matchPeriod);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));

        XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(".", *b);
        XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("..", *b);
    }}

    XTESTS_TEST_PASSED();
#endif /* GLOB_PERIOD */
}

static void test_dotstar_and_includeDots_matchPeriod()
{
#ifdef GLOB_PERIOD
    glob_sequence_t files(".*", glob_sequence_t::includeDots | glob_sequence_t::matchPeriod);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
#endif /* GLOB_PERIOD */
}

static void test_dot_and_dot()
{
    glob_sequence_t files(".", ".");

#ifdef STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
    { for (glob_sequence_t::const_reverse_iterator b = files.crbegin(); b != files.crend(); ++b)
#else
    { for (glob_sequence_t::const_iterator b = files.cbegin(); b != files.cend(); ++b)
#endif
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_dot_and_includeDots()
{
    glob_sequence_t files(".", ".", glob_sequence_t::includeDots);

#ifdef STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
    { for (glob_sequence_t::const_reverse_iterator b = files.rbegin(); b != files.rend(); ++b)
#else
    { for (glob_sequence_t::const_reverse_iterator b = files.begin(); b != files.end(); ++b)
#endif
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_dotdot()
{
    glob_sequence_t files(".", "..");

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_dotdot_and_includeDots()
{
    glob_sequence_t files(".", "..", glob_sequence_t::includeDots);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_dot_and_absolutePath()
{
    glob_sequence_t files(".", ".", glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_dot_and_absolutePath_includeDots()
{
    glob_sequence_t files(".", ".", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_dotdot_and_absolutePath()
{
    glob_sequence_t files(".", "..", glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_dotdot_and_absolutePath_includeDots()
{
    glob_sequence_t files(".", "..", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_stardotstar_and_files()
{
    glob_sequence_t files(".", "*.*", glob_sequence_t::files);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_stardotstar_and_directories()
{
    glob_sequence_t directories(".", "*.*", glob_sequence_t::directories);

    { for (glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_stardotstar_and_files_absolutePath()
{
    glob_sequence_t files(".", "*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dot_and_stardotstar_and_directories_absolutePath()
{
    glob_sequence_t directories(".", "*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotdot_and_stardotstar_and_files_absolutePath()
{
    glob_sequence_t files("..", "*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_dotdot_and_stardotstar_and_directories_absolutePath()
{
    glob_sequence_t directories("..", "*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for (glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

