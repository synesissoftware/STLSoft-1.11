/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.memory.C.STLSOFT_C_AUTO_BUFFER/entry.c
 *
 * Purpose: Scratch test for `STLSOFT_C_AUTO_BUFFER()`, etc.
 *
 * Created: 5th August 2011
 * Updated: 23rd August 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/memory/auto_buffer.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_value_type_of_char_internal_1(void);
static void test_value_type_of_char_internal_2(void);
static void test_value_type_of_char_external_1(void);
static void test_value_type_of_char_internal_3(void);
static void test_value_type_of_char_external_2(void);
static void test_value_type_of_char_external_then_internal_1(void);
static void test_value_type_of_int_internal_1(void);
static void test_value_type_of_int_external_1(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.memory.C.STLSOFT_C_AUTO_BUFFER", verbosity))
    {
        XTESTS_RUN_CASE(test_value_type_of_char_internal_1);
        XTESTS_RUN_CASE(test_value_type_of_char_internal_2);
        XTESTS_RUN_CASE(test_value_type_of_char_external_1);
        XTESTS_RUN_CASE(test_value_type_of_char_internal_3);
        XTESTS_RUN_CASE(test_value_type_of_char_external_2);
        XTESTS_RUN_CASE(test_value_type_of_char_external_then_internal_1);
        XTESTS_RUN_CASE(test_value_type_of_int_internal_1);
        XTESTS_RUN_CASE(test_value_type_of_int_external_1);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * Hacking around
 */

#if 0

typedef int         pan_sev_t;
typedef char        pan_char_t;
typedef struct
{
    size_t              len;
    pan_char_t const*   ptr;

}                   pan_slice_t;
#define PANTHEIOS_INIT_RC_OUT_OF_MEMORY (-2)


int pantheios_dispatch(
    pan_sev_t           severity
,   size_t              cchEntry
,   pan_char_t const*   entry
)
{
    ((void)&severity);
    ((void)&cchEntry);
    ((void)&entry);


    STLSOFT_ASSERT('\0' == entry[cchEntry]);

    return 0;
}


int pantheios_log_n(
    pan_sev_t           severity
,   size_t              numSlices
,   pan_slice_t const*  slices
)
{
    ((void)&severity);


    STLSOFT_C_AUTO_BUFFER_DECLARE(pan_char_t, 2048 + 1, buff);

    int         r;
    size_t      n = 0;

    /* Calculate the total size of the log statement, by summation of the slice array */

    { size_t i; for (i = 0; i != numSlices; ++i)
    {
        n += slices[i].len;
    }}

    r = STLSOFT_C_AUTO_BUFFER_INITIALISE(buff, 8);

    if (0 != r)
    {
#ifdef _DEBUG
#else /* ? _DEBUG */
        pantheios_onBailOut4(
#endif /* _DEBUG */

        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    else
    {
        int   r2;
        char* p = buff.ptr;

        { size_t i; for (i = 0; i != numSlices; ++i)
        {
            memcpy(p, slices[i].ptr, sizeof(pan_char_t) * slices[i].len);
            p += slices[i].len;
        }}
        *p = '\0';

#if 0
        PANTHEIOS_CONTRACT_ENFORCE_POSTCONDITION_RETURN_INTERNAL(buff + cch == p, "Written length differs from allocated length");
#endif /* 0 */

        r2 = pantheios_dispatch(severity, buff.size, buff.ptr);

        STLSOFT_C_AUTO_BUFFER_FREE(buff);

        return r2;
    }
}
#endif


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_value_type_of_char_internal_1(void)
{
    STLSOFT_C_AUTO_BUFFER_DECLARE(char, 10, buff);

    if (0 != STLSOFT_C_AUTO_BUFFER_INITIALISE(buff, 8))
    {
        XTESTS_TEST_FAIL("unexpected failure");
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(8u, buff.size);
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, buff.ptr);

        STLSOFT_C_AUTO_BUFFER_FREE(buff);
    }
}

static void test_value_type_of_char_internal_2(void)
{
    char    buff[10];
    void*   ptr;
    size_t  size;
    int     r = stlsoft_C_auto_buffer_initialise(sizeof(char), &buff[0], sizeof(buff) / sizeof(char), 8, &size, &ptr);

    if (0 != r)
    {
        XTESTS_TEST_FAIL("unexpected failure");
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(8u, size);
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr);
        XTESTS_TEST_POINTER_EQUAL(buff, ptr);

        stlsoft_C_auto_buffer_free(sizeof(char), &buff[0], STLSOFT_NUM_ELEMENTS(buff), size, ptr);
    }
}

static void test_value_type_of_char_external_1(void)
{
    char    buff[10];
    void*   ptr;
    size_t  size;
    int     r = stlsoft_C_auto_buffer_initialise(sizeof(char), &buff[0], sizeof(buff) / sizeof(char), 16, &size, &ptr);

    if (0 != r)
    {
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(16u, size);
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr);
        XTESTS_TEST_POINTER_NOT_EQUAL(buff, ptr);

        stlsoft_C_auto_buffer_free(sizeof(char), &buff[0], STLSOFT_NUM_ELEMENTS(buff), size, ptr);
    }
}

static void test_value_type_of_char_internal_3(void)
{
    STLSOFT_C_AUTO_BUFFER_DECLARE(char, 10, XXXX);

    if (0 != STLSOFT_C_AUTO_BUFFER_INITIALISE(XXXX, 8))
    {
        XTESTS_TEST_FAIL("unexpected failure");
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(8u, XXXX.size);
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, XXXX.ptr);

        STLSOFT_C_AUTO_BUFFER_FREE(XXXX);
    }
}

static void test_value_type_of_char_external_2(void)
{
    STLSOFT_C_AUTO_BUFFER_DECLARE(char, 10, buff1);

    if (0 != STLSOFT_C_AUTO_BUFFER_INITIALISE(buff1, 16))
    {
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(16u, buff1.size);
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, buff1.ptr);
        XTESTS_TEST_POINTER_NOT_EQUAL(buff1.internal_, buff1.ptr);

        STLSOFT_C_AUTO_BUFFER_FREE(buff1);
    }
}

static void test_value_type_of_char_external_then_internal_1(void)
{
    STLSOFT_C_AUTO_BUFFER_DECLARE(char, 10, buff1);
    int i;
    STLSOFT_C_AUTO_BUFFER_DECLARE(char, 10, buff2);
    int j;

    if (0 != (i = STLSOFT_C_AUTO_BUFFER_INITIALISE(buff1, 16)))
    {
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(16u, buff1.size);
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, buff1.ptr);
        XTESTS_TEST_POINTER_NOT_EQUAL(buff1.internal_, buff1.ptr);

        STLSOFT_C_AUTO_BUFFER_FREE(buff1);
    }

    if (0 != (j = STLSOFT_C_AUTO_BUFFER_INITIALISE(buff2, 10)))
    {
        XTESTS_TEST_FAIL("unexpected failure");
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(10u, buff2.size);
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, buff2.ptr);
        XTESTS_TEST_POINTER_EQUAL(buff2.internal_, buff2.ptr);

        STLSOFT_C_AUTO_BUFFER_FREE(buff2);
    }
}

static void test_value_type_of_int_internal_1(void)
{
    STLSOFT_C_AUTO_BUFFER_DECLARE(int, 10, buff);

    if (0 != STLSOFT_C_AUTO_BUFFER_INITIALISE(buff, 8))
    {
        XTESTS_TEST_FAIL("unexpected failure");
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(8u, buff.size);
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, buff.ptr);

        STLSOFT_C_AUTO_BUFFER_FREE(buff);
    }
}

static void test_value_type_of_int_external_1(void)
{
    STLSOFT_C_AUTO_BUFFER_DECLARE(int, 10, buff1);

    if (0 != STLSOFT_C_AUTO_BUFFER_INITIALISE(buff1, 16))
    {
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(16u, buff1.size);
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, buff1.ptr);
        XTESTS_TEST_POINTER_NOT_EQUAL(buff1.internal_, buff1.ptr);

        STLSOFT_C_AUTO_BUFFER_FREE(buff1);
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

