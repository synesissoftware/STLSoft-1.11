
#include <platformstl/system/pid_sequence.hpp>
#include <platformstl/filesystem/path_functions.h>

#include <iostream>

#include <stdio.h>
#include <stdlib.h>


int main(int /* argc */, char* argv[])
{
    stlsoft::string_slice_m_t const program_name = platformstl::get_executable_name_from_path(argv[0]);

    try
    {
        unsigned const flags    =   0
#ifdef PLATFORMSTL_OS_IS_UNIX
                                |   platformstl::pid_sequence::elideInit
                                |   platformstl::pid_sequence::elideSched
#endif
#ifdef PLATFORMSTL_OS_IS_WINDOWS
                                |   platformstl::pid_sequence::elideIdle
                                |   platformstl::pid_sequence::elideSystem
#endif
                                |   platformstl::pid_sequence::sort
                                ;

        platformstl::pid_sequence const pids(flags);

        std::cout
            << "process ids:"
            << std::endl
            ;

        for (platformstl::pid_sequence::const_iterator i = pids.cbegin(); pids.cend() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << std::endl
                ;
        }
    }
    catch (std::bad_alloc&)
    {
        ::fputs("out of memory\n", stderr);
    }
    catch (std::exception& x)
    {
        std::cerr
            << program_name
            << ": exception (of type "
            << typeid(x).name()
            << "): "
            << x.what()
            << std::endl
            ;
    }

    return EXIT_FAILURE;
}

