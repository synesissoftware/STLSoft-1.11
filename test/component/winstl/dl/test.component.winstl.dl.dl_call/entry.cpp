/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.winstl.dl.dl_call/entry.cpp
 *
 * Purpose: Component test for `winstl::dl_call`.
 *
 * Created: 9th October 2024
 * Updated: 9th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <winstl/dl/dl_call.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#if __cplusplus >= 201103L
#include <atomic>
#endif
#include <string>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_Kernel32_GetTickCount(void);
    static void test_Kernel32_GetTickCount64(void);
} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.winstl.dl.dl_call", verbosity))
    {
        XTESTS_RUN_CASE(test_Kernel32_GetTickCount);
        XTESTS_RUN_CASE(test_Kernel32_GetTickCount64);

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
    inline void
    full_fence()
    {
#if __cplusplus >= 201103L

        std::atomic_thread_fence(std::memory_order_seq_cst);
#else

# if 0
# elif defined(_WIN32_WINNT) && \
       _WIN32_WINNT > 0x0502

        ::MemoryBarrier();
# else

        /* no barrier implementation */
# endif
#endif
    }

    static void test_Kernel32_GetTickCount(void)
    {
        try
        {
            DWORD const tc_before = ::GetTickCount();

            full_fence();

            DWORD const tc_dl = winstl::dl_call<DWORD>("Kernel32.dll", WINSTL_DL_CALL_WINx_STDCALL_LITERAL("GetTickCount"));

            full_fence();

            DWORD const tc_after = ::GetTickCount();

            XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(tc_before, tc_dl);
            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(tc_after, tc_dl);
        }
        catch (winstl::missing_entry_point_exception &x)
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("failed to load function", x.what());
        }
    }

    static void test_Kernel32_GetTickCount64(void)
    {
        try
        {
            ULONGLONG const tc_before = ::GetTickCount64();

            full_fence();

            ULONGLONG const tc_dl = winstl::dl_call<ULONGLONG>("Kernel32.dll", WINSTL_DL_CALL_WINx_STDCALL_LITERAL("GetTickCount64"));

            full_fence();

            ULONGLONG const tc_after = ::GetTickCount64();

            XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(tc_before, tc_dl);
            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(tc_after, tc_dl);
        }
        catch (winstl::missing_entry_point_exception &x)
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("failed to load function", x.what());
        }
    }
} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
