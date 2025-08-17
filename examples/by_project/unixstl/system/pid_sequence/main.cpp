
#include <unixstl/system/pid_sequence.hpp>
#include <platformstl/filesystem/path_functions.h>

#include <iostream>

#include <stdio.h>
#include <stdlib.h>


int main(int /* argc */, char* argv[])
{
    stlsoft::string_slice_m_t const program_name = platformstl::get_executable_name_from_path(argv[0]);

    try
    {
        unixstl::pid_sequence const pids(unixstl::pid_sequence::sort | unixstl::pid_sequence::elideInit | unixstl::pid_sequence::elideSched);

        std::cout
            << "process ids:"
            << std::endl
            ;

        for (unixstl::pid_sequence::const_iterator i = pids.cbegin(); pids.cend() != i; ++i)
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

