
#include <unixstl/dl/dl_call.hpp>

#include <stdio.h>
#include <stdlib.h>


int main(int /* argc */, char* /* argv */[])
{
    fprintf(stdout, "UNIXSTL_ARCH_LABEL_STRING=%s\n", UNIXSTL_ARCH_LABEL_STRING);

    try
    {
#ifdef UNIXSTL_OS_IS_LINUX

        double const r = unixstl::dl_call<double>("libm.so.6", "fabs", -123.0);

        fprintf(stdout, "libm.so:fabs: %f\n", r);
#endif
#ifdef UNIXSTL_OS_IS_MACOSX

        int const r = unixstl::dl_call<int>("/usr/lib/system/libsystem_pthread.dylib", "sched_yield");

        fprintf(stdout, "libsystem_pthread.dylib:sched_yield: %d\n", r);
#endif
    }
    catch (unixstl::missing_entry_point_exception& x)
    {
        fprintf(stderr, "failed to load dynamic function: %s\n", x.what());
    }
    catch (std::exception& x)
    {
        fprintf(stderr, "general exception (%s): %s\n", typeid(x).name(), x.what());
    }

    return EXIT_SUCCESS;
}
