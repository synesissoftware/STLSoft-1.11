/* /////////////////////////////////////////////////////////////////////////
 * Purpose: Illustrates the use of `unixstl::glob_sequence` to search for
 *          the files and directories in a given root-directory.
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <unixstl/filesystem/glob_sequence.hpp>

#include <platformstl/filesystem/path_functions.h>
#include <unixstl/filesystem/filesystem_traits.hpp>

#include <iostream>


typedef unixstl::filesystem_traits<char>    fs_traits_t;
using unixstl::glob_sequence;


int main(int argc, char* argv[])
{
    char const* const   program_name    =   platformstl::get_executable_name_from_path(argv[0]).ptr;
    char const*         root_dir        =   ss_nullptr_k;

    if (argc > 1 && 0 == strcmp("--help", argv[1]))
    {
        std::cout
            << "USAGE: "
            << program_name
            << " <search-directory>"
            << std::endl;

        return EXIT_SUCCESS;
    }

    switch (argc)
    {
    case 1:

        root_dir = ".";
        break;
    case 2:

        root_dir = argv[1];
        break;

    default:

        std::cerr
            << program_name
            << ": "
            << "too many arguments; use --help for usage"
            << std::endl;

        return EXIT_FAILURE;
    }


    {
        std::cout << std::endl;
        std::cout << "searching for directories in '" << root_dir << "':" << std::endl;

        int flags = glob_sequence::absolutePath | glob_sequence::directories;

#ifdef GLOB_BRACE

        flags |= glob_sequence::bracePatterns;

        glob_sequence directories(root_dir, "{.*,*}", flags);

        for (glob_sequence::const_iterator i = directories.begin(); directories.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << "/"
                << std::endl;
        }
#else // ? GLOB_BRACE

        {
            glob_sequence directories(root_dir, ".*", flags);

            for (glob_sequence::const_iterator i = directories.begin(); directories.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << "/"
                    << std::endl;
            }
        }

        {
            glob_sequence directories(root_dir, "*", flags);

            for (glob_sequence::const_iterator i = directories.begin(); directories.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << "/"
                    << std::endl;
            }
        }
#endif // GLOB_BRACE
    }

    {
        std::cout << std::endl;
        std::cout << "searching for non-hidden directories in '" << root_dir << "':" << std::endl;

        int flags = glob_sequence::absolutePath | glob_sequence::directories | glob_sequence::skipHiddenDirs;

#ifdef GLOB_BRACE

        flags |= glob_sequence::bracePatterns;

        glob_sequence directories(root_dir, "{.*,*}", flags);

        for (glob_sequence::const_iterator i = directories.begin(); directories.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << "/"
                << std::endl;
        }
#else // ? GLOB_BRACE

        {
            glob_sequence directories(root_dir, ".*", flags);

            for (glob_sequence::const_iterator i = directories.begin(); directories.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << "/"
                    << std::endl;
            }
        }

        {
            glob_sequence directories(root_dir, "*", flags);

            for (glob_sequence::const_iterator i = directories.begin(); directories.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << "/"
                    << std::endl;
            }
        }
#endif // GLOB_BRACE
    }

    {
        std::cout << std::endl;
        std::cout << "searching for files in '" << root_dir << "':" << std::endl;

        int flags = glob_sequence::absolutePath | glob_sequence::files;

#ifdef GLOB_BRACE

        flags |= glob_sequence::bracePatterns;

        glob_sequence files(root_dir, "{.*,*}", flags);

        for (glob_sequence::const_iterator i = files.begin(); files.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << std::endl;
        }
#else // ? GLOB_BRACE

        {
            glob_sequence files(root_dir, ".*", flags);

            for (glob_sequence::const_iterator i = files.begin(); files.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << std::endl;
            }
        }

        {
            glob_sequence files(root_dir, "*", flags);

            for (glob_sequence::const_iterator i = files.begin(); files.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << std::endl;
            }
        }
#endif // GLOB_BRACE
    }

    {
        std::cout << std::endl;
        std::cout << "searching for non-hidden files in '" << root_dir << "':" << std::endl;

        int flags = glob_sequence::absolutePath | glob_sequence::files | glob_sequence::skipHiddenFiles;

#ifdef GLOB_BRACE

        flags |= glob_sequence::bracePatterns;

        glob_sequence files(root_dir, "{.*,*}", flags);

        for (glob_sequence::const_iterator i = files.begin(); files.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << std::endl;
        }
#else // ? GLOB_BRACE

        {
            glob_sequence files(root_dir, ".*", flags);

            for (glob_sequence::const_iterator i = files.begin(); files.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << std::endl;
            }
        }

        {
            glob_sequence files(root_dir, "*", flags);

            for (glob_sequence::const_iterator i = files.begin(); files.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << std::endl;
            }
        }
#endif // GLOB_BRACE
    }

    {
        std::cout << std::endl;
        std::cout << "searching for devices in '" << root_dir << "':" << std::endl;

        glob_sequence devices(root_dir, "*", glob_sequence::absolutePath | glob_sequence::devices);

        for (glob_sequence::const_iterator i = devices.begin(); devices.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << std::endl;
        }
    }

    {
        std::cout << std::endl;
        std::cout << "searching for sockets in '" << root_dir << "':" << std::endl;

        glob_sequence sockets(root_dir, "*", glob_sequence::absolutePath | glob_sequence::sockets);

        for (glob_sequence::const_iterator i = sockets.begin(); sockets.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << std::endl;
        }
    }

    {
        std::cout << std::endl;
        std::cout << "searching for devices + files + sockets in '" << root_dir << "':" << std::endl;

        glob_sequence entries(root_dir, "*", glob_sequence::absolutePath | glob_sequence::devices | glob_sequence::files | glob_sequence::sockets);

        for (glob_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << std::endl;
        }
    }

    {
        std::cout << std::endl;
        std::cout << "searching for devices + directories + files + sockets in '" << root_dir << "':" << std::endl;

        glob_sequence entries(root_dir, "*", glob_sequence::absolutePath | glob_sequence::devices | glob_sequence::directories | glob_sequence::files | glob_sequence::sockets);

        for (glob_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << (fs_traits_t::is_directory(*i) ? "/" : "")
                << std::endl;
        }
    }

    {
        std::cout << std::endl;
        std::cout << "searching for all entries in '" << root_dir << "':" << std::endl;

        int flags = glob_sequence::absolutePath;

#ifdef GLOB_BRACE

        flags |= glob_sequence::bracePatterns;

        glob_sequence entries(root_dir, "{.*,*}", flags);

        for (glob_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << (fs_traits_t::is_directory(*i) ? "/" : "")
                << std::endl;
        }
#else // ? GLOB_BRACE

        {
            glob_sequence entries(root_dir, ".*", flags);

            for (glob_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << (fs_traits_t::is_directory(*i) ? "/" : "")
                    << std::endl;
            }
        }

        {
            glob_sequence entries(root_dir, "*", flags);

            for (glob_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << (fs_traits_t::is_directory(*i) ? "/" : "")
                    << std::endl;
            }
        }
#endif // GLOB_BRACE
    }

    {
        std::cout << std::endl;
        std::cout << "searching for all non-hidden entries in '" << root_dir << "':" << std::endl;

        int flags = glob_sequence::absolutePath | glob_sequence::skipHiddenDirs | glob_sequence::skipHiddenFiles | glob_sequence::markDirs;

#ifdef GLOB_BRACE

        flags |= glob_sequence::bracePatterns;

        glob_sequence entries(root_dir, "{.*,*}", flags);

        for (glob_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
        {
            std::cout
                << "\t"
                << *i
                << std::endl;
        }
#else // ? GLOB_BRACE

        {
            glob_sequence entries(root_dir, ".*", flags);

            for (glob_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << std::endl;
            }
        }

        {
            glob_sequence entries(root_dir, "*", flags);

            for (glob_sequence::const_iterator i = entries.begin(); entries.end() != i; ++i)
            {
                std::cout
                    << "\t"
                    << *i
                    << std::endl;
            }
        }
#endif // GLOB_BRACE
    }


    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

