/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.string.copy_functions/entry.cpp
 *
 * Purpose: Scratch test for string copy functions.
 *
 * Created: 29th September 2016
 * Updated: 23rd August 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


 /* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/string/copy_functions.h>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/util/dimensionof.h>

/* Standard C++ header files */
#include <algorithm>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    void test_string_copy_with_toolarge_destination();
    void test_string_copy_with_exactlysufficient_destination();
    void test_string_copy_with_insufficient_destination();
    void test_string_copy_with_nul_with_toolarge_destination();
    void test_string_copy_with_nul_with_exactlysufficient_destination();
    void test_string_copy_with_nul_with_insufficient_destination();
    void test_string_copy_with_different_lengths();
    void test_string_copy_with_nul_with_different_lengths();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.string.copy_functions", verbosity))
    {
        XTESTS_RUN_CASE(test_string_copy_with_toolarge_destination);
        XTESTS_RUN_CASE(test_string_copy_with_exactlysufficient_destination);
        XTESTS_RUN_CASE(test_string_copy_with_insufficient_destination);
        XTESTS_RUN_CASE(test_string_copy_with_nul_with_toolarge_destination);
        XTESTS_RUN_CASE(test_string_copy_with_nul_with_exactlysufficient_destination);
        XTESTS_RUN_CASE(test_string_copy_with_nul_with_insufficient_destination);
        XTESTS_RUN_CASE(test_string_copy_with_different_lengths);
        XTESTS_RUN_CASE(test_string_copy_with_nul_with_different_lengths);

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

void test_string_copy_with_toolarge_destination()
{
    char        dest[10];
    char const  src[]   =   "source";
    size_t      n;

    ::memset(dest, '~', sizeof(dest));
    strcpy(dest, src);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
    XTESTS_TEST_CHARACTER_EQUAL('~', dest[7]);

    ::memset(dest, '~', sizeof(dest));
    memcpy(dest, src, sizeof(char) * (1 + strlen(src)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
    XTESTS_TEST_CHARACTER_EQUAL('~', dest[7]);

    ::memset(dest, '~', sizeof(dest));
    n = stlsoft::string_copy(dest, dimensionof(dest), src, strlen(src));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
    XTESTS_TEST_CHARACTER_EQUAL('~', dest[7]);

    ::memset(dest, '~', sizeof(dest));
    n = stlsoft::string_copy(dest, dimensionof(dest), stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
    XTESTS_TEST_CHARACTER_EQUAL('~', dest[7]);
# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    ::memset(dest, '~', sizeof(dest));
    n = stlsoft::string_copy(dest, stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
    XTESTS_TEST_CHARACTER_EQUAL('~', dest[7]);

    ::memset(dest, '~', sizeof(dest));
    n = stlsoft::string_copy(dest, src);

    XTESTS_TEST_INTEGER_EQUAL(7u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dest[7]);
    XTESTS_TEST_CHARACTER_EQUAL('~', dest[8]);
# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
}

void test_string_copy_with_exactlysufficient_destination()
{
    char        dest[7];
    char const  src[]   =   "source";
    size_t      n;

    strcpy(dest, src);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);

    memcpy(dest, src, sizeof(char) * (1 + strlen(src)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);

    n = stlsoft::string_copy(dest, dimensionof(dest), src, strlen(src));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);

    n = stlsoft::string_copy(dest, dimensionof(dest), stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    n = stlsoft::string_copy(dest, stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);

    n = stlsoft::string_copy(dest, src);

    XTESTS_TEST_INTEGER_EQUAL(7u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
}

void test_string_copy_with_insufficient_destination()
{
    char        dest[5];
    char const  src[]   =   "source";
    size_t      n;

    n = stlsoft::string_copy(dest, dimensionof(dest), src, strlen(src));

    XTESTS_TEST_INTEGER_EQUAL(5u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("sourc", dest, 5);

    n = stlsoft::string_copy(dest, dimensionof(dest), stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(5u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("sourc", dest, 5);
# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    n = stlsoft::string_copy(dest, stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(5u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("sourc", dest, 5);

    n = stlsoft::string_copy(dest, src);

    XTESTS_TEST_INTEGER_EQUAL(5u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("sourc", dest, 5);
# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
}

void test_string_copy_with_nul_with_toolarge_destination()
{
    char        dest[10];
    char const  src[]   =   "source";
    size_t      n;

    ::memset(dest, '~', sizeof(dest));
    n = stlsoft::string_copy_with_nul(dest, dimensionof(dest), src, strlen(src));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
    XTESTS_TEST_CHARACTER_EQUAL('~', dest[7]);

    ::memset(dest, '~', sizeof(dest));
    n = stlsoft::string_copy_with_nul(dest, dimensionof(dest), stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
    XTESTS_TEST_CHARACTER_EQUAL('~', dest[7]);
# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    ::memset(dest, '~', sizeof(dest));
    n = stlsoft::string_copy_with_nul(dest, stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
    XTESTS_TEST_CHARACTER_EQUAL('~', dest[7]);

    ::memset(dest, '~', sizeof(dest));
    n = stlsoft::string_copy_with_nul(dest, src);

    XTESTS_TEST_INTEGER_EQUAL(7u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dest[7]);
    XTESTS_TEST_CHARACTER_EQUAL('~', dest[8]);
# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
}

void test_string_copy_with_nul_with_exactlysufficient_destination()
{
    char        dest[7];
    char const  src[]   =   "source";
    size_t      n;

    n = stlsoft::string_copy_with_nul(dest, dimensionof(dest), src, strlen(src));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);

    n = stlsoft::string_copy_with_nul(dest, dimensionof(dest), stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    n = stlsoft::string_copy_with_nul(dest, stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);

    n = stlsoft::string_copy_with_nul(dest, src);

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("source", dest);
# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
}

void test_string_copy_with_nul_with_insufficient_destination()
{
    char        dest[5];
    char const  src[]   =   "source";
    size_t      n;

    n = stlsoft::string_copy_with_nul(dest, dimensionof(dest), src, strlen(src));

    XTESTS_TEST_INTEGER_EQUAL(4u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("sour", dest);

    n = stlsoft::string_copy_with_nul(dest, dimensionof(dest), stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(4u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("sour", dest);
# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

    n = stlsoft::string_copy_with_nul(dest, stlsoft::string_slice_m_t::create(src, strlen(src)));

    XTESTS_TEST_INTEGER_EQUAL(4u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("sour", dest);

    n = stlsoft::string_copy_with_nul(dest, src);

    XTESTS_TEST_INTEGER_EQUAL(4u, n);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("sour", dest);
# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
}

void test_string_copy_with_different_lengths()
{
    wchar_t         dest[10];
    wchar_t const*  src =   L"source";
    size_t          n;


    // 0:0

    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 0, src, 0);

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[0]);


    // 1:[012]

    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 1, src, 0);

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[1]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 1, src, 1);

    XTESTS_TEST_INTEGER_EQUAL(1u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L's', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[1]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 1, src, 2);

    XTESTS_TEST_INTEGER_EQUAL(1u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L's', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[1]);


    // 2:[0123]

    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 2, src, 0);

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[1]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[2]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 2, src, 1);

    XTESTS_TEST_INTEGER_EQUAL(1u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L's', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[1]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[2]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 2, src, 2);

    XTESTS_TEST_INTEGER_EQUAL(2u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L's', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'o', dest[1]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[2]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 2, src, 3);

    XTESTS_TEST_INTEGER_EQUAL(2u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L's', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'o', dest[1]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[2]);


    // 6:[4567]

    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 6, src, 4);

    XTESTS_TEST_INTEGER_EQUAL(4u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"sour", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[4]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[5]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 6, src, 5);

    XTESTS_TEST_INTEGER_EQUAL(5u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"sourc", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[5]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[6]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 6, src, 6);

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(L"source", dest, 6);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[6]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[7]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 6, src, 7);

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(L"source", dest, 6);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[6]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[7]);


    // 7:[5678]

    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 7, src, 5);

    XTESTS_TEST_INTEGER_EQUAL(5u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"sourc", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[5]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[6]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 7, src, 6);

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"source", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[6]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[7]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 7, src, 7);

    XTESTS_TEST_INTEGER_EQUAL(7u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(L"source", dest, 6);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[6]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[7]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[8]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[9]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy(dest, 7, src, 8);

    XTESTS_TEST_INTEGER_EQUAL(7u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(L"source", dest, 6);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[6]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[7]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[8]);
}

void test_string_copy_with_nul_with_different_lengths()
{
    wchar_t         dest[10];
    wchar_t const*  src =   L"source";
    size_t          n;


    // 0:0

    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 0, src, 0);

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[0]);


    // 1:[012]

    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 1, src, 0);

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[1]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 1, src, 1);

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[1]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 1, src, 2);

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[1]);


    // 2:[0123]

    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 2, src, 0);

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[1]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[2]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 2, src, 1);

    XTESTS_TEST_INTEGER_EQUAL(1u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L's', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[1]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[2]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 2, src, 2);

    XTESTS_TEST_INTEGER_EQUAL(1u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L's', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[1]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[2]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 2, src, 3);

    XTESTS_TEST_INTEGER_EQUAL(1u, n);
    XTESTS_TEST_CHARACTER_EQUAL(L's', dest[0]);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[1]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[2]);


    // 6:[4567]

    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 6, src, 4);

    XTESTS_TEST_INTEGER_EQUAL(4u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"sour", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[4]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[5]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 6, src, 5);

    XTESTS_TEST_INTEGER_EQUAL(5u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"sourc", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[5]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[6]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 6, src, 6);

    XTESTS_TEST_INTEGER_EQUAL(5u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"sourc", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[5]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[7]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 6, src, 7);

    XTESTS_TEST_INTEGER_EQUAL(5u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"sourc", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[6]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[7]);


    // 7:[5678]

    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 7, src, 5);

    XTESTS_TEST_INTEGER_EQUAL(5u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"sourc", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[5]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[6]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 7, src, 6);

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"source", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[6]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[7]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 7, src, 7);

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"source", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[6]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[7]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[8]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[9]);


    std::fill_n(dest, dimensionof(dest), L'~');
    n = stlsoft::string_copy_with_nul(dest, 7, src, 8);

    XTESTS_TEST_INTEGER_EQUAL(6u, n);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"source", dest);
    XTESTS_TEST_CHARACTER_EQUAL(L'\0', dest[6]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[7]);
    XTESTS_TEST_CHARACTER_EQUAL(L'~', dest[8]);
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

