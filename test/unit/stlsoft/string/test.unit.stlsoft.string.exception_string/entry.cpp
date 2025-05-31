/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.util.exception_string/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::exception_string`.
 *
 * Created: 3rd February 2011
 * Updated: 30th May 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#define _SCL_SECURE_NO_WARNINGS

#include <stlsoft/util/exception_string.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#ifdef STLSOFT_DEBUG
size_t const NUM_ITERATIONS =   1000u;
#else /* ? STLSOFT_DEBUG */
size_t const NUM_ITERATIONS =   1000000u;
#endif /* STLSOFT_DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void test_default_instance();
    static void test_ctor_1();
    static void test_ctor_2();
    static void test_ctor_3();

    static void test_default_ctor_and_length();
    static void test_default_ctor_and_size();
    static void test_c_string_ctor_1();
    static void test_c_string_ctor_2();
    static void test_copy_ctor_1();
    static void test_copy_ctor_2();
    static void test_slice_ctor_1();
    static void test_slice_ctor_2();

    static void test_string_concatenation_1();
    static void test_string_concatenation_2();
#if _STLSOFT_VER >= 0x010c0000

    static void test_swap_1();
    static void test_swap_2();
    static void test_swap_3();
    static void test_ctor_16();
#endif
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.util.exception_string", verbosity))
    {
        XTESTS_RUN_CASE(test_default_instance);
        XTESTS_RUN_CASE(test_ctor_1);
        XTESTS_RUN_CASE(test_ctor_2);
        XTESTS_RUN_CASE(test_ctor_3);

        XTESTS_RUN_CASE(test_default_ctor_and_length);
        XTESTS_RUN_CASE(test_default_ctor_and_size);
        XTESTS_RUN_CASE(test_c_string_ctor_1);
        XTESTS_RUN_CASE(test_c_string_ctor_2);
        XTESTS_RUN_CASE(test_copy_ctor_1);
        XTESTS_RUN_CASE(test_copy_ctor_2);
        XTESTS_RUN_CASE(test_slice_ctor_1);
        XTESTS_RUN_CASE(test_slice_ctor_2);

        XTESTS_RUN_CASE(test_string_concatenation_1);
        XTESTS_RUN_CASE(test_string_concatenation_2);
#if _STLSOFT_VER >= 0x010c0000

        XTESTS_RUN_CASE(test_swap_1);
        XTESTS_RUN_CASE(test_swap_2);
        XTESTS_RUN_CASE(test_swap_3);
        XTESTS_RUN_CASE(test_ctor_16);
#endif

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define XTESTS_TEST_X_STRING_EQUAL          XTESTS_TEST_MULTIBYTE_STRING_EQUAL


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

    using stlsoft::exception_string;


static void test_default_instance()
{
    exception_string xs;

    XTESTS_TEST_BOOLEAN_TRUE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, xs.size());
}

static void test_ctor_1()
{
    exception_string    xs("abc");

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, xs.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", xs);
}

static void test_ctor_2()
{
    exception_string    xs("abcdefghijklmno", 13u);

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(13u, xs.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklm", xs);
}

static void test_ctor_3()
{
    exception_string    xs("abcdefghijklmno", 3u);

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, xs.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", xs);
}

static void test_default_ctor_and_length()
{
    stlsoft::exception_string xs;

    XTESTS_TEST_BOOLEAN_TRUE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, xs.length());
}

static void test_default_ctor_and_size()
{
    stlsoft::exception_string xs;

    XTESTS_TEST_BOOLEAN_TRUE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, xs.size());
}

static void test_c_string_ctor_1()
{
    stlsoft::exception_string xs("a");

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs);
}

static void test_c_string_ctor_2()
{
    { for (size_t i = 1u; i != NUM_ITERATIONS; i *= 10u)
    {
        std::string s(i, '*');

        stlsoft::exception_string xs(s.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs);
    }}
}

static void test_copy_ctor_1()
{
    stlsoft::exception_string xs1("a");

    XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs1.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs1);

    stlsoft::exception_string xs2(xs1);

    XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs2.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs2);
    XTESTS_TEST_X_STRING_EQUAL(xs1, xs2);
}

static void test_copy_ctor_2()
{
    { for (size_t i = 1u; i != NUM_ITERATIONS; i *= 10u)
    {
        std::string s(i, '*');

        stlsoft::exception_string xs1(s.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs1);

        stlsoft::exception_string xs2(xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs2);
    }}
}

static void test_slice_ctor_1()
{
    stlsoft::exception_string xs("a", 1u);

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs);
}

static void test_slice_ctor_2()
{
    stlsoft::exception_string xs("ab", 1u);

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs);
}

static void test_string_concatenation_1()
{
    stlsoft::exception_string xs1("a");

    XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs1.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs1);

    stlsoft::exception_string xs2 = xs1 + 'b';

    XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, xs2.size());
    XTESTS_TEST_X_STRING_EQUAL("ab", xs2);

    stlsoft::exception_string xs3 = xs1 + "b";

    XTESTS_TEST_BOOLEAN_FALSE(xs3.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, xs3.size());
    XTESTS_TEST_X_STRING_EQUAL("ab", xs3);

    stlsoft::exception_string xs4 = 'b' + xs1;

    XTESTS_TEST_BOOLEAN_FALSE(xs4.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, xs4.size());
    XTESTS_TEST_X_STRING_EQUAL("ba", xs4);

    stlsoft::exception_string xs5 = "b" + xs1;

    XTESTS_TEST_BOOLEAN_FALSE(xs5.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, xs5.size());
    XTESTS_TEST_X_STRING_EQUAL("ba", xs5);
}

static void test_string_concatenation_2()
{
    { for (size_t i = 1u; i != NUM_ITERATIONS; i *= 10u)
    {
        std::string s(i, '*');

        stlsoft::exception_string xs1(s.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs1);

        stlsoft::exception_string xs2 = xs1 + 'b';

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(i + 1u, xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s + "b", xs2);

        stlsoft::exception_string xs3 = xs1 + "b";

        XTESTS_TEST_BOOLEAN_FALSE(xs3.empty());
        XTESTS_TEST_INTEGER_EQUAL(i + 1u, xs3.size());
        XTESTS_TEST_X_STRING_EQUAL(s + "b", xs3);

        stlsoft::exception_string xs4 = 'b' + xs1;

        XTESTS_TEST_BOOLEAN_FALSE(xs4.empty());
        XTESTS_TEST_INTEGER_EQUAL(i + 1u, xs4.size());
        XTESTS_TEST_X_STRING_EQUAL("b" + s, xs4);

        stlsoft::exception_string xs5 = "b" + xs1;

        XTESTS_TEST_BOOLEAN_FALSE(xs5.empty());
        XTESTS_TEST_INTEGER_EQUAL(i + 1u, xs5.size());
        XTESTS_TEST_X_STRING_EQUAL("b" + s, xs5);
    }}
}

#if _STLSOFT_VER >= 0x010c0000

static void test_swap_1()
{
    { for (size_t i = 1u; i != NUM_ITERATIONS; i *= 10u)
    {
        std::string s(i, '*');

        stlsoft::exception_string xs1(s.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs1);

        stlsoft::exception_string xs2;

        XTESTS_TEST_BOOLEAN_TRUE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, xs2.size());

        xs2.swap(xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs2);

        XTESTS_TEST_BOOLEAN_TRUE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, xs1.size());
    }}
}

static void test_swap_2()
{
        std::string s1("abc");
        std::string s2(2000, '~');

        stlsoft::exception_string xs1(s1.c_str());
        stlsoft::exception_string xs2(s2.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(s1.size(), xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s1, xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(s2.size(), xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s2, xs2);

        stlsoft::swap(xs1, xs2);

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(s2.size(), xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s2, xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(s1.size(), xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s1, xs2);
}

static void test_swap_3()
{
        std::string s1("abc");
        std::string s2(2000, '~');

        stlsoft::exception_string xs1(s1.c_str());
        stlsoft::exception_string xs2(s2.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(s1.size(), xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s1, xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(s2.size(), xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s2, xs2);

        std::swap(xs1, xs2);

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(s2.size(), xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s2, xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(s1.size(), xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s1, xs2);
}

static void test_ctor_16()
{
# if 0
    stlsoft::exception_string xs("a");

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs);

    stlsoft::exception_string xs2 = xs + "bcdefghijklmnopqrstuvwxyz";

    XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
    XTESTS_TEST_INTEGER_EQUAL(26u, xs2.size());
    XTESTS_TEST_X_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", xs2);
# endif /* 0 */
}
#endif
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

