/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.winstl.util.struct_initialisers/entry.cpp
 *
 * Purpose: Component test for `winstl::struct_initialisers`.
 *
 * Created: 9th October 2024
 * Updated: 20th March 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <winstl/util/struct_initialisers.hpp>


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
 * forward declarations
 */

namespace {

    // no_init_member_type
    static void test_FILETIME();
    static void test_SYSTEM_INFO();
    static void test_SYSTEMTIME();

    // cbSize_member_type
    static void test_CONSOLE_SCREEN_BUFFER_INFOEX();

    // cb_member_type
    static void test_STARTUPINFOW();

    // cBytes_member_type
    static void test_OFSTRUCT();

    // dwLength_member_type
    static void test_MEMORYSTATUS();

    // dwOSVersionInfoSize_member_type
    static void test_OSVERSIONINFOA();
    static void test_OSVERSIONINFOEXA();

    // dwSize_member_type
    static void test_COMMCONFIG();

    // nLength_member_type
    static void test_SECURITY_ATTRIBUTES();

    // uSize_member_type
    static void test_DRAGINFOA();

    // DCBlength
    static void test_DCB();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.winstl.dl.struct_initialisers", verbosity))
    {
        // no_init_member_type
        XTESTS_RUN_CASE(test_FILETIME);
        XTESTS_RUN_CASE(test_SYSTEM_INFO);
        XTESTS_RUN_CASE(test_SYSTEMTIME);

        // cbSize_member_type
        XTESTS_RUN_CASE(test_CONSOLE_SCREEN_BUFFER_INFOEX);

        // cb_member_type
        XTESTS_RUN_CASE(test_STARTUPINFOW);

        // cBytes_member_type
        XTESTS_RUN_CASE(test_OFSTRUCT);

        // dwLength_member_type
        XTESTS_RUN_CASE(test_MEMORYSTATUS);

        // dwOSVersionInfoSize_member_type
        XTESTS_RUN_CASE(test_OSVERSIONINFOA);
        XTESTS_RUN_CASE(test_OSVERSIONINFOEXA);

        // dwSize_member_type
        XTESTS_RUN_CASE(test_COMMCONFIG);

        // nLength_member_type
        XTESTS_RUN_CASE(test_SECURITY_ATTRIBUTES);

        // uSize_member_type
        XTESTS_RUN_CASE(test_DRAGINFOA);

        // DCBlength
        XTESTS_RUN_CASE(test_DCB);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

    using stlsoft::ss_size_t;


// no_init_member_type

static void test_FILETIME()
{
    FILETIME ft;

    winstl::init_struct(ft);

    XTESTS_TEST_INTEGER_EQUAL(0u, ft.dwLowDateTime);
    XTESTS_TEST_INTEGER_EQUAL(0u, ft.dwHighDateTime);
}

static void test_SYSTEMTIME()
{
    SYSTEMTIME st;

    winstl::init_struct(st);

    XTESTS_TEST_INTEGER_EQUAL(0u, st.wYear);
    XTESTS_TEST_INTEGER_EQUAL(0u, st.wMonth);
    XTESTS_TEST_INTEGER_EQUAL(0u, st.wDayOfWeek);
    XTESTS_TEST_INTEGER_EQUAL(0u, st.wDay);
    XTESTS_TEST_INTEGER_EQUAL(0u, st.wHour);
    XTESTS_TEST_INTEGER_EQUAL(0u, st.wMinute);
    XTESTS_TEST_INTEGER_EQUAL(0u, st.wSecond);
    XTESTS_TEST_INTEGER_EQUAL(0u, st.wMilliseconds);
}

static void test_SYSTEM_INFO()
{
    SYSTEM_INFO si;

    winstl::init_struct(si);

    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwOemId);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.wProcessorArchitecture);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwPageSize);
    XTESTS_TEST_POINTER_EQUAL(0, si.lpMinimumApplicationAddress);
    XTESTS_TEST_POINTER_EQUAL(0, si.lpMaximumApplicationAddress);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwActiveProcessorMask);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwNumberOfProcessors);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwProcessorType);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwAllocationGranularity);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.wProcessorLevel);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.wProcessorRevision);
}


// cbSize_member_type

static void test_CONSOLE_SCREEN_BUFFER_INFOEX()
{
    CONSOLE_SCREEN_BUFFER_INFOEX csbix;

    winstl::init_struct(csbix);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(csbix), csbix.cbSize);

#if 0
    XTESTS_TEST((COORD { 0, 0 } == csbix.dwSize));
    XTESTS_TEST((COORD { 0, 0 } == csbix.dwCursorPosition));
#endif
    XTESTS_TEST_INTEGER_EQUAL(0, csbix.wAttributes);
#if 0
    XTESTS_TEST_INTEGER_EQUAL(0, csbix.srWindow);
    XTESTS_TEST_INTEGER_EQUAL(0, csbix.dwMaximumWindowSize);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0, csbix.wPopupAttributes);
    XTESTS_TEST_BOOLEAN_FALSE(csbix.bFullscreenSupported);
    // COLORREF csbix.ColorTable[16];
}


// cb_member_type

static void test_STARTUPINFOW()
{
    STARTUPINFOW si;

    winstl::init_struct(si);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(si), si.cb);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.lpReserved);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.lpDesktop);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.lpTitle);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwX);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwY);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwXSize);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwYSize);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwXCountChars);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwYCountChars);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwFillAttribute);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.dwFlags);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.wShowWindow);
    XTESTS_TEST_INTEGER_EQUAL(0u, si.cbReserved2);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.lpReserved2);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.hStdInput);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.hStdOutput);
    XTESTS_TEST_POINTER_EQUAL(NULL, si.hStdError);
}


// cBytes_member_type

static void test_OFSTRUCT()
{
    OFSTRUCT ofs;

    winstl::init_struct(ofs);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(ofs), static_cast<ss_size_t>(ofs.cBytes));
    XTESTS_TEST_INTEGER_EQUAL(0u, ofs.fFixedDisk);
    XTESTS_TEST_INTEGER_EQUAL(0u, ofs.nErrCode);
    XTESTS_TEST_INTEGER_EQUAL(0u, ofs.Reserved1);
    XTESTS_TEST_INTEGER_EQUAL(0u, ofs.Reserved2);
#if 0
    CHAR szPathName[OFS_MAXPATHNAME];
#endif
}


// dwLength_member_type

static void test_MEMORYSTATUS()
{
    MEMORYSTATUS ms;

    winstl::init_struct(ms);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(ms), ms.dwLength);
    XTESTS_TEST_INTEGER_EQUAL(0u, ms.dwMemoryLoad);
    XTESTS_TEST_INTEGER_EQUAL(0u, ms.dwTotalPhys);
    XTESTS_TEST_INTEGER_EQUAL(0u, ms.dwAvailPhys);
    XTESTS_TEST_INTEGER_EQUAL(0u, ms.dwTotalPageFile);
    XTESTS_TEST_INTEGER_EQUAL(0u, ms.dwAvailPageFile);
    XTESTS_TEST_INTEGER_EQUAL(0u, ms.dwTotalVirtual);
    XTESTS_TEST_INTEGER_EQUAL(0u, ms.dwAvailVirtual);
}


// dwOSVersionInfoSize_member_type

static void test_OSVERSIONINFOA()
{
    OSVERSIONINFOA osvi;

    winstl::init_struct(osvi);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(osvi), osvi.dwOSVersionInfoSize);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvi.dwMajorVersion);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvi.dwMinorVersion);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvi.dwBuildNumber);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvi.dwPlatformId);
#if 0
    CHAR   szCSDVersion[ 128 ];     // Maintenance string for PSS usage
#endif
}

static void test_OSVERSIONINFOEXA()
{
    OSVERSIONINFOEXA osvix;

    winstl::init_struct(osvix);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(osvix), osvix.dwOSVersionInfoSize);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvix.dwMajorVersion);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvix.dwMinorVersion);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvix.dwBuildNumber);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvix.dwPlatformId);
#if 0
    CHAR   szCSDVersion[ 128 ];     // Maintenance string for PSS usage
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, osvix.wServicePackMajor);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvix.wServicePackMinor);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvix.wSuiteMask);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvix.wProductType);
    XTESTS_TEST_INTEGER_EQUAL(0u, osvix.wReserved);
}


// dwSize_member_type

static void test_COMMCONFIG()
{
    // NOTE: this specialisation is questionnable, since COMMCONFIG is a
    // variable-length structure

    COMMCONFIG cc;

    winstl::init_struct(cc);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(cc), cc.dwSize);
    XTESTS_TEST_INTEGER_EQUAL(0u, cc.wVersion);
    XTESTS_TEST_INTEGER_EQUAL(0u, cc.wReserved);
#if 0
    XTESTS_TEST_INTEGER_EQUAL(0, cc.dcb);
#endif
    XTESTS_TEST_INTEGER_EQUAL(0u, cc.dwProviderSubType);
    XTESTS_TEST_INTEGER_EQUAL(0u, cc.dwProviderOffset);
    XTESTS_TEST_INTEGER_EQUAL(0u, cc.dwProviderSize);
#if 0
    XTESTS_TEST_INTEGER_EQUAL(0, cc.wcProviderData);
#endif
}


// nLength_member_type

static void test_SECURITY_ATTRIBUTES()
{
    SECURITY_ATTRIBUTES sa;

    winstl::init_struct(sa);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(sa), sa.nLength);
    XTESTS_TEST_POINTER_EQUAL(NULL, sa.lpSecurityDescriptor);
    XTESTS_TEST_BOOLEAN_FALSE(sa.bInheritHandle);
}


// uSize_member_type

static void test_DRAGINFOA()
{
    DRAGINFOA da;

    winstl::init_struct(da);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(da), da.uSize);
#if 0
    POINT pt;
#endif
    XTESTS_TEST_BOOLEAN_FALSE(da.fNC);
    XTESTS_TEST_POINTER_EQUAL(NULL, da.lpFileList);
    XTESTS_TEST_INTEGER_EQUAL(0u, da.grfKeyState);
}


// DCBlength

static void test_DCB()
{
    DCB dcb;

    winstl::init_struct(dcb);

    XTESTS_TEST_INTEGER_EQUAL(sizeof(dcb), dcb.DCBlength);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.BaudRate);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fBinary);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fParity);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fOutxCtsFlow);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fOutxDsrFlow);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fDtrControl);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fDsrSensitivity);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fTXContinueOnXoff);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fOutX);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fInX);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fErrorChar);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fNull);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fRtsControl);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fAbortOnError);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.fDummy2);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.wReserved);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.XonLim);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.XoffLim);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.ByteSize);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.Parity);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.StopBits);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dcb.XonChar);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dcb.XoffChar);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dcb.ErrorChar);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dcb.EofChar);
    XTESTS_TEST_CHARACTER_EQUAL('\0', dcb.EvtChar);
    XTESTS_TEST_INTEGER_EQUAL(0u, dcb.wReserved1);
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

