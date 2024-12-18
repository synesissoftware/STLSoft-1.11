/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.container.unicode_point_map/entry.cpp
 *
 * Purpose: Unit-tests for `stlsoft::unicode_point_map`.
 *
 * Created: 5th November 2024
 * Updated: 17th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* ///////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/containers/unicode_point_map.hpp>


/* ///////////////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#if __cplusplus >= 201103L
# include <list>
#endif
#include <numeric>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_ctor_default_1(void);
    static void test_ctor_default_2(void);
#if __cplusplus >= 201103L

    static void test_ctor_initializer_list_1(void);
    static void test_ctor_initializer_list_2(void);
#endif
    static void test_push_1(void);
    static void test_push_2(void);
    static void test_push_n_1(void);
    static void test_push_n_2(void);
    static void test_clear(void);
//     static void test_merge(void);
//     static void test_op_addassign(void);
//     static void test_op_add(void);
    static void test_swap(void);
    static void test_swap_std(void);
    static void test_iteration_1(void);
//     static void test_iteration_order_1(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.container.unicode_point_map", verbosity))
    {
        XTESTS_RUN_CASE(test_ctor_default_1);
        XTESTS_RUN_CASE(test_ctor_default_2);
#if __cplusplus >= 201103L

        XTESTS_RUN_CASE(test_ctor_initializer_list_1);
        XTESTS_RUN_CASE(test_ctor_initializer_list_2);
#endif
        XTESTS_RUN_CASE(test_push_1);
        XTESTS_RUN_CASE(test_push_2);
        XTESTS_RUN_CASE(test_push_n_1);
        XTESTS_RUN_CASE(test_push_n_2);
        XTESTS_RUN_CASE(test_clear);
        XTESTS_RUN_CASE(test_swap);
        XTESTS_RUN_CASE(test_swap_std);
        XTESTS_RUN_CASE(test_iteration_1);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * utility functions
 */


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{
    using stlsoft::unicode_point_map;


static void test_ctor_default_1()
{
    unicode_point_map const upm;

    XTESTS_TEST_BOOLEAN_TRUE(upm.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.size());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.total());

    XTESTS_TEST_INTEGER_EQUAL(0, upm[' ']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['A']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['a']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['b']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['c']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['d']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['e']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['f']);
}

static void test_ctor_default_2()
{
    unicode_point_map const upm(0x64); // 'd'

    XTESTS_TEST_BOOLEAN_TRUE(upm.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.size());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.total());

    XTESTS_TEST_INTEGER_EQUAL(0, upm[' ']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['A']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['a']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['b']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['c']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['d']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['e']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['f']);
}

#if __cplusplus >= 201103L

static void test_ctor_initializer_list_1(void)
{
    unicode_point_map upm = { 'a', 'b', 'c', 'd', 'd', 'd', 'a' };

    XTESTS_TEST_INTEGER_EQUAL(0, upm[' ']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['A']);
    XTESTS_TEST_INTEGER_EQUAL(2, upm['a']);
    XTESTS_TEST_INTEGER_EQUAL(1, upm['b']);
    XTESTS_TEST_INTEGER_EQUAL(1, upm['c']);
    XTESTS_TEST_INTEGER_EQUAL(3, upm['d']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['e']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['f']);
}

static void test_ctor_initializer_list_2(void)
{
    unicode_point_map upm(0x64, { 'a', 'b', 'c', 'd', 'd', 'd', 'a' });

    XTESTS_TEST_INTEGER_EQUAL(0, upm[' ']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['A']);
    XTESTS_TEST_INTEGER_EQUAL(2, upm['a']);
    XTESTS_TEST_INTEGER_EQUAL(1, upm['b']);
    XTESTS_TEST_INTEGER_EQUAL(1, upm['c']);
    XTESTS_TEST_INTEGER_EQUAL(3, upm['d']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['e']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['f']);
}
#endif

static void test_push_1()
{
    unicode_point_map upm;

    XTESTS_TEST_BOOLEAN_TRUE(upm.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.size());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.total());

    upm.push('a');
    upm.push('b');
    upm.push('a');
    upm.push('c');
    upm.push('d');
    upm.push('d');
    upm.push('d');

    XTESTS_TEST_INTEGER_EQUAL(0, upm[' ']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['A']);
    XTESTS_TEST_INTEGER_EQUAL(2, upm['a']);
    XTESTS_TEST_INTEGER_EQUAL(1, upm['b']);
    XTESTS_TEST_INTEGER_EQUAL(1, upm['c']);
    XTESTS_TEST_INTEGER_EQUAL(3, upm['d']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['e']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['f']);
}

static void test_push_2()
{
    unicode_point_map upm(0x64); // 'd'

    XTESTS_TEST_BOOLEAN_TRUE(upm.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.size());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.total());

    upm.push('a');
    upm.push('b');
    upm.push('a');
    upm.push('c');
    upm.push('d');
    upm.push('d');
    upm.push('d');

    XTESTS_TEST_INTEGER_EQUAL(0, upm[' ']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['A']);
    XTESTS_TEST_INTEGER_EQUAL(2, upm['a']);
    XTESTS_TEST_INTEGER_EQUAL(1, upm['b']);
    XTESTS_TEST_INTEGER_EQUAL(1, upm['c']);
    XTESTS_TEST_INTEGER_EQUAL(3, upm['d']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['e']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['f']);
}

static void test_push_n_1()
{
    unicode_point_map upm;

    XTESTS_TEST_BOOLEAN_TRUE(upm.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.size());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.total());

    upm.push_n('a', 2);
    upm.push_n('b', -1);
    upm.push_n('c', 0);
    upm.push_n('d', 3);
    upm.push_n('e', 1);
    upm.push_n('e', 1);
    upm.push_n('e', -2);

    XTESTS_TEST_INTEGER_EQUAL(0, upm[' ']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['A']);
    XTESTS_TEST_INTEGER_EQUAL(2, upm['a']);
    XTESTS_TEST_INTEGER_EQUAL(-1, upm['b']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['c']);
    XTESTS_TEST_INTEGER_EQUAL(3, upm['d']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['e']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['f']);
}

static void test_push_n_2()
{
    unicode_point_map upm(0x64); // 'd'

    XTESTS_TEST_BOOLEAN_TRUE(upm.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.size());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.total());

    upm.push_n('a', 2);
    upm.push_n('b', -1);
    upm.push_n('c', 0);
    upm.push_n('d', 3);
    upm.push_n('e', 1);
    upm.push_n('e', 1);
    upm.push_n('e', -2);

    XTESTS_TEST_INTEGER_EQUAL(0, upm[' ']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['A']);
    XTESTS_TEST_INTEGER_EQUAL(2, upm['a']);
    XTESTS_TEST_INTEGER_EQUAL(-1, upm['b']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['c']);
    XTESTS_TEST_INTEGER_EQUAL(3, upm['d']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['e']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['f']);
}

static void test_clear()
{
    unicode_point_map upm;

    XTESTS_TEST_BOOLEAN_TRUE(upm.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.size());
    XTESTS_TEST_INTEGER_EQUAL(0, upm.total());

    upm.push_n('a', 2);
    upm.push_n('b', -1);
    upm.push_n('c', 0);
    upm.push_n('d', 1);
    upm.push_n('d', 1);
    upm.push_n('d', -2);

    XTESTS_TEST_INTEGER_EQUAL(0, upm[' ']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['A']);
    XTESTS_TEST_INTEGER_EQUAL(2, upm['a']);
    XTESTS_TEST_INTEGER_EQUAL(-1, upm['b']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['c']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['d']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['e']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['f']);

    upm.clear();

    XTESTS_TEST_INTEGER_EQUAL(0, upm[' ']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['A']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['a']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['b']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['c']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['d']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['e']);
    XTESTS_TEST_INTEGER_EQUAL(0, upm['f']);
}

static void test_swap(void)
{
    {
        unicode_point_map upm1;
        unicode_point_map upm2;

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());

        upm1.swap(upm2);

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());
    }

    {
        unicode_point_map upm1;
        unicode_point_map upm2;

        upm1.push('A');
        upm1.push('a');
        upm1.push('1');

        upm2.push('B');
        upm2.push('b');
        upm2.push('2');
        upm2.push_n('3', 10);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm2['3']);

        upm1.swap(upm2);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['3']);
    }

    {
        unicode_point_map upm1(0x60);
        unicode_point_map upm2(0x60);

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());

        upm1.swap(upm2);

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());
    }

    {
        unicode_point_map upm1(0x60);
        unicode_point_map upm2(0x60);

        upm1.push('A');
        upm1.push('a');
        upm1.push('1');

        upm2.push('B');
        upm2.push('b');
        upm2.push('2');
        upm2.push_n('3', 10);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm2['3']);

        upm1.swap(upm2);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['3']);
    }

    {
        unicode_point_map upm1(0);
        unicode_point_map upm2(0x60);

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());

        upm1.swap(upm2);

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());
    }

    {
        unicode_point_map upm1(0);
        unicode_point_map upm2(0x60);

        upm1.push('A');
        upm1.push('a');
        upm1.push('1');

        upm2.push('B');
        upm2.push('b');
        upm2.push('2');
        upm2.push_n('3', 10);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm2['3']);

        upm1.swap(upm2);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['3']);
    }
}

static void test_swap_std(void)
{
    {
        unicode_point_map upm1;
        unicode_point_map upm2;

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());

        std::swap(upm1, upm2);

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());
    }

    {
        unicode_point_map upm1;
        unicode_point_map upm2;

        upm1.push('A');
        upm1.push('a');
        upm1.push('1');

        upm2.push('B');
        upm2.push('b');
        upm2.push('2');
        upm2.push_n('3', 10);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm2['3']);

        std::swap(upm1, upm2);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['3']);
    }

    {
        unicode_point_map upm1(0x60);
        unicode_point_map upm2(0x60);

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());

        std::swap(upm1, upm2);

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());
    }

    {
        unicode_point_map upm1(0x60);
        unicode_point_map upm2(0x60);

        upm1.push('A');
        upm1.push('a');
        upm1.push('1');

        upm2.push('B');
        upm2.push('b');
        upm2.push('2');
        upm2.push_n('3', 10);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm2['3']);

        std::swap(upm1, upm2);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['3']);
    }

    {
        unicode_point_map upm1(0);
        unicode_point_map upm2(0x60);

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());

        std::swap(upm1, upm2);

        XTESTS_TEST_BOOLEAN_TRUE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm1.total());

        XTESTS_TEST_BOOLEAN_TRUE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, upm2.total());
    }

    {
        unicode_point_map upm1(0);
        unicode_point_map upm2(0x60);

        upm1.push('A');
        upm1.push('a');
        upm1.push('1');

        upm2.push('B');
        upm2.push('b');
        upm2.push('2');
        upm2.push_n('3', 10);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm2['3']);

        std::swap(upm1, upm2);

        XTESTS_TEST_BOOLEAN_FALSE(upm1.empty());
        XTESTS_TEST_INTEGER_EQUAL(4, upm1.size());
        XTESTS_TEST_INTEGER_EQUAL(13, upm1.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm1[' ']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['A']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['C']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['a']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['0']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm1['1']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm1['2']);
        XTESTS_TEST_INTEGER_EQUAL(10, upm1['3']);

        XTESTS_TEST_BOOLEAN_FALSE(upm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.size());
        XTESTS_TEST_INTEGER_EQUAL(3, upm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, upm2[' ']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['A']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['B']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['C']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['a']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['b']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['c']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['0']);
        XTESTS_TEST_INTEGER_EQUAL(1, upm2['1']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['2']);
        XTESTS_TEST_INTEGER_EQUAL(0, upm2['3']);
    }
}

static void test_iteration_1(void)
{
    {
        unicode_point_map const upm;

        XTESTS_TEST(upm.end() == upm.begin());
        XTESTS_TEST(upm.cend() == upm.cbegin());
    }

    {
        unicode_point_map upm;

        upm.push_n('a', -97);

        XTESTS_TEST(upm.end() != upm.begin());
        XTESTS_TEST(upm.cend() != upm.cbegin());

        unicode_point_map::value_type const v = *upm.cbegin();

        XTESTS_TEST_INTEGER_EQUAL(97u, v.first);
        XTESTS_TEST_INTEGER_EQUAL(-97, v.second);
    }

    {
        unicode_point_map upm(1000); // set large ceiling to be assured of order

        upm.push_n('a', -97);
        upm.push_n('b', -98);
        upm.push_n('c', -99);

        XTESTS_TEST(upm.end() != upm.begin());
        XTESTS_TEST(upm.cend() != upm.cbegin());

        unicode_point_map::const_iterator i;

        i = upm.begin();

        {
            unicode_point_map::value_type const v = *i++;

            XTESTS_TEST_INTEGER_EQUAL(97u, v.first);
            XTESTS_TEST_INTEGER_EQUAL(-97, v.second);
        }

        {
            unicode_point_map::value_type const v = *i;

            XTESTS_TEST_INTEGER_EQUAL(98u, v.first);
            XTESTS_TEST_INTEGER_EQUAL(-98, v.second);

            ++i;
        }

        {
            unicode_point_map::value_type const v = *i++;

            XTESTS_TEST_INTEGER_EQUAL(99u, v.first);
            XTESTS_TEST_INTEGER_EQUAL(-99, v.second);
        }

        XTESTS_TEST(upm.end() == i);
    }
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

