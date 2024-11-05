
#include <winstl/dl/dl_call.hpp>

#include <stdio.h>
#include <stdlib.h>


int main(int /* argc */, char* /* argv */[])
{
    fprintf(stdout, "WINSTL_ARCH_LABEL_STRING=%s\n", WINSTL_ARCH_LABEL_STRING);

    try
    {
        DWORD const tc = winstl::dl_call<DWORD>("Kernel32.dll", WINSTL_DL_CALL_WINx_STDCALL_LITERAL("GetTickCount"));

        fprintf(stdout, "Kernel32:GetTickCount: %lu\n", static_cast<unsigned long>(tc));
    }
    catch (winstl::missing_entry_point_exception& x)
    {
        fprintf(stderr, "failed to load dynamic function: %s\n", x.what());
    }
    catch (winstl::invalid_calling_convention_exception& x)
    {
        fprintf(stderr, "failed to load dynamic function: %s\n", x.what());
    }
    catch (std::exception& x)
    {
        fprintf(stderr, "general exception (%s): %s\n", typeid(x).name(), x.what());
    }

    return EXIT_SUCCESS;
}
