
#include <stlsoft/stlsoft.h>
#include <platformstl/platformstl.h>
#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
# include <unixstl/unixstl.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <winstl/winstl.h>
#endif

#include <stdio.h>


int main(int argc, char* argv[])
{
    STLSOFT_SUPPRESS_UNUSED(argc);
    STLSOFT_SUPPRESS_UNUSED(argv);

    /* __STDC__ */
    {

#ifdef __STDC__

        fprintf(
            stdout
        ,   "__STDC__ = %d\n"
        ,   __STDC__
        );
        fprintf(stdout, "\n");
#endif
    }


    /* _STLSOFT_VER */
    {

        fprintf(
            stdout
        ,   "STLSoft = %d.%d.%d.%d\n"
        ,   (_STLSOFT_VER >> 24) & 0xff
        ,   (_STLSOFT_VER >> 16) & 0xff
        ,   (_STLSOFT_VER >> 8) & 0xff
        ,   (_STLSOFT_VER >> 0) & 0xff
        );
        fprintf(
            stdout
        ,   "_STLSOFT_VER = 0x%04x%04x\n"
        ,   (unsigned int)((_STLSOFT_VER >> 16) & 0xffff)
        ,   (unsigned int)((_STLSOFT_VER >> 0) & 0xffff)
        );
        fprintf(
            stdout
        ,   "STLSOFT_COMPILER_VERSION_STRING = %s\n"
        ,   STLSOFT_COMPILER_VERSION_STRING
        );
        fprintf(stdout, "\n");
    }

    /* _PLATFORMSTL_VER */
    {

        fprintf(
            stdout
        ,   "PlatformSTL = %d.%d.%d.%d\n"
        ,   (_PLATFORMSTL_VER >> 24) & 0xff
        ,   (_PLATFORMSTL_VER >> 16) & 0xff
        ,   (_PLATFORMSTL_VER >> 8) & 0xff
        ,   (_PLATFORMSTL_VER >> 0) & 0xff
        );
        fprintf(
            stdout
        ,   "_PLATFORMSTL_VER = 0x%04x%04x\n"
        ,   (unsigned int)((_PLATFORMSTL_VER >> 16) & 0xffff)
        ,   (unsigned int)((_PLATFORMSTL_VER >> 0) & 0xffff)
        );
        fprintf(stdout, "\n");
    }


#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)

    /* _UNIXSTL_VER */

    {

        fprintf(
            stdout
        ,   "UNIXSTL = %d.%d.%d.%d\n"
        ,   (_UNIXSTL_VER >> 24) & 0xff
        ,   (_UNIXSTL_VER >> 16) & 0xff
        ,   (_UNIXSTL_VER >> 8) & 0xff
        ,   (_UNIXSTL_VER >> 0) & 0xff
        );
        fprintf(
            stdout
        ,   "_UNIXSTL_VER = 0x%04x%04x\n"
        ,   (unsigned int)((_UNIXSTL_VER >> 16) & 0xffff)
        ,   (unsigned int)((_UNIXSTL_VER >> 0) & 0xffff)
        );
        fprintf(stdout, "\n");
    }
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    /* _WINSTL_VER */
    {

        fprintf(
            stdout
        ,   "WinSTL = %d.%d.%d.%d\n"
        ,   (_WINSTL_VER >> 24) & 0xff
        ,   (_WINSTL_VER >> 16) & 0xff
        ,   (_WINSTL_VER >> 8) & 0xff
        ,   (_WINSTL_VER >> 0) & 0xff
        );
        fprintf(
            stdout
        ,   "_WINSTL_VER = 0x%04x%04x\n"
        ,   (unsigned int)((_WINSTL_VER >> 16) & 0xffff)
        ,   (unsigned int)((_WINSTL_VER >> 0) & 0xffff)
        );
        fprintf(stdout, "\n");
    }
#endif


    return 0;
}

