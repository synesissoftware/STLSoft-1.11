# STLSoft - History


----


31st May 2025 - 1.11.1-rc2 released
-----------------------------------

 * Added `stlsoft::member_selector_view<>` (alpha version), for span-compatibility in **recls**;
 * Change semantics of `stlsoft::auto_buffer<>#resize()` the size of external allocation is maintained such that shrinking and then regrowing may be done within the existing allocation;
 * InetSTL / UNIXSTL / WinSTL architecture discrimination  canonicalised, expanded, and corrected;
 * Substantial refactoring and testing of `winstl::filesystem_traits<>`;
 * Significant improvements to compatibility with different C and C++ language versions (C90, C99, C11, C17, C23, C++98, C++11, C++14, C++17, C++20, C++23) - detailed in TODO.md;
 * Added compatibility with latest Visual C++ (`_MSC_VER` == 1944);
 * **test.component.inetstl.util.uds_helpers** now works correctly for both Linux and macOS;
 * Brought over several test programs exercising C APIs;
 * **run_all_scratch_tests.sh** now accepts '--verbosity' option;


6th May 2025 - 1.11.1-rc1 released
----------------------------------

 * Various CMake improvements;
 * MinGW compatibility;
 * **UNIXem** compatibility;
 * Windows compatibility;


5th May 2025 - 1.11.1-beta9 released
------------------------------------

 * `stlsoft::basic_string_view` fixed defect in comparison;
 * **example.platformstl.filesystem.readdir_sequence** minor fix;


3rd May 2025 - 1.11.1-beta8 released
------------------------------------

 * Added skipping of hidden directories and files to `unixstl::glob_sequence` and `unixstl::readdir_sequence`;
 * Various example improvements;
 * Updated **TODO.md** with structure and items;


30th April 2025 - 1.11.1-beta7 released
---------------------------------------

 * Support for searching of devices on the file system, primarily concerning `unixstl::glob_sequence` and `unixstl::readdir_sequence`;


28th April 2025 - 1.11.1-beta6 released
---------------------------------------

 * Visual C++ compatibility (including _MSC_VER 1943);
 * CMake / UNIXem compatibility;
 * Refactored / enhanced retrieval of home-directory, including, for Windows, trying first for `"USERPROFILE"` and then falls back to `"HOMEDRIVE"` and `"HOMEPATH"`;
 * **prepare_cmake.sh** / **CMakeLists.txt** : + added '--no-shwild' / `CMAKE_NO_SHWILD`;
 * Added **test.component.winstl.system.directory_functions**;


26th April 2025 - 1.11.1-beta5 released
---------------------------------------

 * Added `platformstl::environment_variable_scope`;
 * Added more unit-tests;
 * MinGW compatibility;
 * `stlsoft::basic_static_string<>` minor fix;
 * Miscellaneous fixes;


22nd April 2025 - 1.11.1-beta4 released
---------------------------------------

 * `unixstl::glob_sequence` now can search for sockets, in addition to files and directories;
 * `stlsoft::cmdargs` added missing member types;


16th April 2025 - 1.11.1-beta3 released
-----------------------------------------

 * Added specialisations of `integral_traits<>` for integer specialisations of `true_typedef<>`;
 * Applied `printf()` format attributes throughout;
 * Defect fix(es) to `unixstl::path_squeeze<>()` / `winstl::path_squeeze<>()`;
 * MinGW compatibility;
 * Wholesale trivial/minor tidying;


23rd February 2025 - 1.11.1-beta2 released
-----------------------------------------

 * `unixstl::readdir_sequence` now can search for sockets, in addition to files and directories;
 * **InetSTL** newly released functionality;
 * GCC (11) compatibility around use of `__builtin_is_constant_evaluated` (when not C++20);
 * **InetSTL** improved compatibility with macOS / Linux;


31st December 2024 - 1.11.1-beta1 released
------------------------------------------

 * Command-line handling components minor improvements and unit-testing;
 * Visual C++ compatibility (including _MSC_VER 1942);
 * MinGW compatibility;
 * Miscellaneous backwards-compatibility fixes;
 * Miscellaneous (near) final fixes and tidying;


28th December 2024 - 1.11.1-alpha28 released
--------------------------------------------

 * substantial reworking of abstraction of memory functions, resulting in performance improvements across numerous components, `stlsoft::auto_buffer<>` in particular;
 * MinGW compatibility;
 * miscellaneous generalisation of code and dependencies;
 * added more test programs;


19th December 2024 - 1.11.1-alpha27 released
--------------------------------------------

 * added `stlsoft::doomgram` and `stlsoft::gram_scope` (from old research repo(s));
 * added **include/stlsoft/diagnostics/gram_utils.hpp**, including `stlsoft::gram_to_strip()`;
 * added `stlsoft::count_hexadecimal_digits()`, and refactored `stlsoft::count_digits()` into `stlsoft::count_decimal_digits()`;
 * added **unixstl/time/comparison_functions.h**, including `unixstl_C_compare_timevals()` / `unixstl::compare()`;
 * added `winstl_C_difference_in_microseconds_QPC()` and `winstl_C_absolute_difference_in_microseconds_QPC()`;
 * `winstl::micro_sleep()` (and `winstl_C_micro_sleep()`) now implemented in terms of active methods for accurate behaviour in small durations (0 < delay_us <= 250000);
 * added `#pause()` and `#unpause()` to stopwatch types (incl. `stlsoft::std_chrono_hrc_stopwatch`, `unixstl::stopwatch()`, `winstl::stopwatch()`);
 * added `#get_kernel_nanoseconds()`, `#get_user_nanoseconds()`, `#get_nanoseconds()` to `unixstl::stopwatch()`;
 * added `#cbegin()` / `#cend()` and `#crbegin()` / `#crend()` methods to `stlsoft::auto_buffer<>`;
 * separated Windows-specific `platformstl::readdir_sequence` into `winstl::readdir_sequence`;
 * added **test.component.platformstl.diagnostics.stopwatch**;
 * added **test.performance.stlsoft.count_digits**;
 * added **test.performance.stlsoft.doomgram**;
 * added **test.performance.stlsoft.gram_utils**;
 * added **test.scratch.winstl.micro_sleep**;
 * added **test.unit.stlsoft.diagnostics.doomgram**;
 * added **test.unit.stlsoft.diagnostics.gram_scope**;
 * added **test.unit.stlsoft.util.count_decimal_digits**;
 * added **test.unit.stlsoft.util.count_hexadecimal_digits**;
 * added **test.unit.winstl.conversion.number.grouping_functions**;
 * **run_all_unit_tests.sh** now respects environment variables `XTESTS_VERBOSITY` and `TEST_VERBOSITY`;
 * miscellaneous minor/trivial improvements;


23rd November 2024 - 1.11.1-alpha26 released
--------------------------------------------

 * added `stlsoft::integral_traits<>` (**stlsoft/traits/integral_traits.hpp**);
 * added `stlsoft::unicode_point_map`;
 * added **test.unit.stlsoft.limits.integral_limits**;
 * added **test.unit.stlsoft.traits.integral_traits**;
 * minor tidying to CMake facilities;


18th November 2024 - 1.11.1-alpha25 released
--------------------------------------------

 * added MSVC MT support;
 * added and applied macro `STLSOFT_IS_CONSTANT_EVALUATED()`, in particular to `stlsoft::auto_buffer<>`;
 * include ordering (around api/internal / api/external helper headers);
 * copy-paste typos;
 * made consistent include ordering (around api/internal / api/external helper headers);


4th November 2024 - 1.11.1-alpha24 released
-------------------------------------------

 * `frequency_map` : ~ now default-specialised on `frequency_map_traits_unordered` when compiling with C++11+;
 * **test.performance.stlsoft.frequency_map** : ~ improved reporting of results ; ~ now uses `stlsoft::std_chrono_hrc_stopwatch`;


28th October 2024 - 1.11.1-alpha23 released
-------------------------------------------

 * `platformstl::basic_file_lines<>` now supports move semantics;
 * Fix to definition of `STLSOFT_MESSAGE_ASSERT()` (for Clang);
 * Minor improvements of ./CMakeLists.txt;
 * **dev/bin/batch_compile_check** now supports '--counts' flag;


26th October 2024 - 1.11.1-alpha22 released
-------------------------------------------

 * Single fix to default definition of `STLSOFT_FALLTHROUGH()`;


25th October 2024 - 1.11.1-alpha21 released
-------------------------------------------

 * Added and applied macro `STLSOFT_FALLTHROUGH()`;
 * Added unit-tests for allocator types;


23rd October 2024 - 1.11.1-alpha20 released
-------------------------------------------

 * Version change only;


23rd October 2024 - 1.11.1-alpha19 released
-------------------------------------------

 * Fixes to (new functionality in) `stlsoft::auto_buffer<>`;
 * Fix for (compile-time) defect in `winstl::basic_path<>`;
 * Fix for defect in `winstl::basic_reg_key<>`;
 * MinGW compatibility in **winstl/internal/windows_version_.h**;
 * MinGW compatibility in **winstl/system/console_functions.h**;
 * Necessary warning suppression in `stlsoft::basis_simple_string<>`;
 * Trivial warning fix in `winstl::readonly_memory_mapped_file<>`;
 * Added **test.unit.stlsoft.traits.integral_printf_format_traits**;
 * Brought over **test.unit.winstl.registry.reg_value**;
 * Added **test.unit.winstl.registry.reg_value_sequence**;
 * GCC warnings;
 * CMake build scripts minor fixes;


15th October 2024 - 1.11.1-alpha18 released
-------------------------------------------

 * Legacy (pre VS-2022) Visual C++ compatibility;
 * Win32 compatibity;


13th October 2024 - 1.11.1-alpha17 released
-------------------------------------------

 * `stlsoft::frequency_map<>` enhancements;
 * `unixstl::glob_sequence` enhancements;
 * Fixes and enhancement to `dl_call<>()` (both UNIXSTL and WinSTL);
 * BREAKING CHANGE: Prospective compatibility with C++20 reserved word `module` (both UNIXSTL and WinSTL) by renaming existing `module` class to `dl_module`;
 * GCC 11 compatibility;
 * GCC 14 compatibility;
 * MinGW-64 compatibility;
 * VC++ 17 compatibility;
 * General improvements and simplification for compatibility with C++11 - C++20;
 * CMake build files improvements;
 * Misc. minor fixes and enhancements;
 * Misc. code canonicalisation;
 * Bringing into repo existing (older) test and example programs;


1st October 2024 - 1.11.1-alpha16 released
------------------------------------------

 * `auto_buffer` improvements;
 * `constexpr` applications;
 * Time function enhancements;
 * Brought over previously unreleased example and test programs;
 * Significant simplification of CMake support;
 * Boilerplate file improvements;
 * Miscellaneous improvements;


2nd September 2024 - 1.11.1-alpha15 released
--------------------------------------------

 * Windows ARM64 architecture support;
 * Windows 10/11 operating system detection support;
 * significant simplification of CMake support;
 * minor additions/enhancements to scratch tests;
 * miscellaneous fixes;


21st August 2024 - 1.11.1-alpha14 released
------------------------------------------

* VC++ 17 latest (`_MSC_VER`==1941) compatibility


4th August 2024 - 1.11.1-alpha13 released
-----------------------------------------

* added `platformstl::isatty()` (and `platformstl::platformstl_C_isatty_fd()` and `platformstl::platformstl_C_isatty_stm()`), `unixstl::isatty()` (and `unixstl::unixstl_C_isatty_fd()` and `unixstl::unixstl_C_isatty_stm()`), `winstl::isatty()` (and `winstlstl::winstlstl_C_isatty_fd()` and `winstlstl::winstlstl_C_isatty_stm()`)


3rd August 2024 - 1.11.1-alpha12 released
-----------------------------------------

* `unixstl::readdir_sequence` no longer uses `stlsoft::basic_static_string<>`;
* simplifying CMake compatibility;
* VC++17 compatibility;
* minor fixes;
* now depends on xTests 0.24+


14th July 2024 - 1.11.1-alpha10 released
16th July 2024 - 1.11.1-alpha11 released
----------------------------------------

* CMake compatibility fixes


14th July 2024 - 1.11.1-alpha10 released
----------------------------------------

* Fixing upper limit to **xTests** version as <0.23, in anticipation of imminent changes to **xTests**;
* Compatibility with latest VC++ 17 (with Visual Studio 2022 version 17.10.1, _MSC_FULL_VER=194033811);


9th July 2024 - 1.11.1-alpha9 released
--------------------------------------

* Missing fix to `stlsoft::basic_simple_string`'s `#assign()`;


9th July 2024 - 1.11.1-alpha8 released
--------------------------------------

 * Added `platformstl::get_home_directory()` and related functions;
 * GCC compatibility improvements;
 * CMake improvements;
 * Boilerplate file improvements;
 * More examples and test programs;


5th May 2024 - 1.11.1-alpha7 released
-------------------------------------

 * Visual C++ (17) compatibility;
 * Windows compatibility for CMake;
 * Miscellaneous changes;


29th March 2024 - 1.11.1-alpha6 released
----------------------------------------

 * added unit-test projects **test.unit.stlsoft.conversion.number.group_functions** and **test.unit.stlsoft.conversion.integer_to_lc_string**;
 * partial merge of forthcoming branch 'ss/simple_string-null_object';


29th March 2024 - 1.11.1-alpha5 released
----------------------------------------

 * various GCC-11 compatibility fixes;


18th March 2024 - 1.11.1-alpha4 released
----------------------------------------

 * `stlsoft::basic_simple_string<>` now has `#equal()`;
 * added 'stlsoft::std_chrono_hrc_stopwatch' stopwatch type;
 * various performance improvements;


16th March 2024 - 1.11.1-alpha3 released
----------------------------------------

 * `stlsoft::basic_simple_string<>` now has `#contains()`;
 * `stlsoft::basic_static_string<>` now has `#contains()`;
 * wholesale automated layout canonicalisation;


1st March 2024 - 1.11.1-alpha2 released
---------------------------------------

 * True-Typedef supports stream-insertion (`operator <<()`):
 * added `stlsoft::write_string<>()`;
 * miscellaneous fixes (including C++14/17/20 compatibility);


20th February 2024 - 1.11.1-alpha1 released
-------------------------------------------

 * added `stlsoft::integer_to_base32_string<>()` integer to Base-32-string conversion
 * added `stlsoft::integer_to_base36_string<>()` integer to Base-36-string conversion
 * `stlsoft::basic_simple_string<>` now has `#starts_with()` and `#ends_with()`
 * `stlsoft::basic_static_string<>` now has `#starts_with()` and `#ends_with()`
 * `stlsoft::basic_static_string<>` now has `#substr()`
 * `stlsoft::basic_static_string<>` now has `#front()` and `#back()`
 * `stlsoft::basic_static_string<>` consistently and correctly throws exceptions on any operations that would cause exceeding of internal storage
 * improvement to string insertion helper `string_insert()` to work with stream types that do and do not provide `sentry`
 * added **test.unit.unixstl.filesystem.path** unit-test project


16th February 2024 - 1.10.11 released
-------------------------------------

 * project boilerplate
 * corrected inappropriate use of `ss_typename_param_k`


16th February 2024 - 1.10.10 released
-------------------------------------

 * further tranche of stream insertion operator implementations
 * fixes and enhancements to `stlsoft::util::string_insert`
 * added `stlsoft::meta::hash_sentry` meta-type;
 * added test.unit.unixstl.filesystem.path test project;


12th February 2024 - 1.10.9 released
------------------------------------

 * stlsoft::frequency_map uses traits to select between ordered and unordered representation
 * added test.unit.stlsoft.containers.frequency_map project
 * C++98 compatibility


6th February 2024 - 1.10.8 released
-----------------------------------

 * added dev/bin/batch_compile_check
 * language compatibility fix
 * iterator definition fixes (related to C++17 deprecation of std::iterator)


30th January 2024 - 1.10.7 released
-----------------------------------

 * enhanced stream insertion operators, when used with types descended from `std::basic_ios<>`, to observe width and alignment for `stlsoft::basic_shim_string<>`, `stlsoft::basic_simple_string<>`, `stlsoft::basic_static_string`, `stlsoft::basic_string_view`, `stlsoft::stlsoft_C_string_slice_m_t`/`stlsoft::stlsoft_C_string_slice_w_t`
 * refactored (almost) all direct calls to disparate parts of the `printf()`-family to use the STLSoft abstractions
 * wholesale refinement of whitespace around conditional control statements;
 * large number of minor and trivial tidyings


28th January 2024 - 1.10.6 released
-----------------------------------

 * simplification and improvement of CMake handling
 * dependency on xTests is now optional (in prepare_cmake.sh)
 * now depends on xTests 0.21.2
 * CMake C language now C11
 * fixed defect in `stlsoft::pod_vector`


18th January 2024 - 1.10.5 released
-----------------------------------

 * C++20 compatibility
 * C17 compatibility
 * introduced several unit-tests (previously in private repo);
 * stlsoft::pod_vector now default-initialses elements in size-constructor


16th January 2024 - 1.10.4 released
-----------------------------------

 * C++17 compatibility
 * unixstl::semaphore now fully implemented on Mac OSX;


12th January 2024 - 1.10.3 released
-----------------------------------

 * warnings fix (Issue 14)
 * fixed sub-project versions (Issue 15)
 * minor project boilerplate fixes and tidying


3rd January 2024 - 1.10.2 released
----------------------------------

 * defect fixes;
 * Min-GW 64-bit compatibility


13th December 2023 - 1.10.1 released
------------------------------------

 * CMake support

26th April 2021 - 1.10.1 (beta 33) released
-------------------------------------------

 * Clang compatibility

26th April 2021 - 1.10.1 (beta 32) released
-------------------------------------------

 * GCC/Clang compatibility

2nd April 2021 - 1.10.1 (beta 31) released
------------------------------------------

 * Clang compatibility
 * provision for customising inline (in C compilation)
 * warnings

29th March 2021 - 1.10.1 (beta 30) released
-------------------------------------------

 * Clang compatibility
 * warnings

16th February 2021 - 1.10.1 (beta 29) released
---------------------------------------------

 * a whole lot of Clang- and GCC-compatibility

18th January 2021 - 1.10.1 (beta 28) released
---------------------------------------------

 * added character-array overloads of fast_strftime()
 * WinSTL hard link information functions now work for directories as well as files
 * various defect fixes

10th January 2021 - 1.10.1 (beta 27) released
---------------------------------------------

 * added string access shims for std::chrono type(s)
 * some GCC compatibility tweaks

4th January 2021 - 1.10.1 (beta 26) released
--------------------------------------------

 * added (UNIXSTL and WinSTL) Path Classification API (from 1.12 work), which work with Windows UNC and long-path root designators and all slash conventions
 * added (UNIXSTL and WinSTL) path parsing function - include/???stl/filesystem/path_parse_functions.h, presenting a consistent set of functions centralised from disparate parts of the libraries
 * BREAKING CHANGES: (UNIXSTL and WinSTL) basic_path<> methods get_file() and get_ext() now return slices, and get_ext() changed semantics to include '.'
 * (UNIXSTL and WinSTL) basic_path<> added move semantics and get_location() method and made swap() method public, as well as numerous defect fixes and consistency improvements implemented in terms of new Path Classification API
 * (UNIXSTL and WinSTL) filesystem_traits<> added path classification and path parsing methods, as well as numerous defect fixes
 * updated copyright info for all files, from Synesis Software to Synesis Information Systems
 * stlsoft::basic_path_buffer<> added resize(), back(), front() methods
 * added added stlsoft_C_(str|wcs)nicmp()
 * raw (C) string slice types moved out of stlsoft:: namespace in C++
 * C++14 compatibility
 * a whole lot of work to reduce dependencies
 * many improvements to GCC compatibility
 * all uses of memcpy() and memset() now in terms of abstractions (in stlsoft/api/internal/memfns.h)
 * BREAKING CHANGES: ~ abstracted out string-handling from *stl::system_traits<> into stlsoft::c_string_traits<>, and removed several unused (and sketchy) functions

14th December 2020 - 1.10.1 (beta 25) released
----------------------------------------------

 * added two more files missing from beta 23 - D'oh!

13th December 2020 - 1.10.1 (beta 24) released
----------------------------------------------

 * added file unixstl/filesystem/path_buffer.hpp missing from beta 23

13th December 2020 - 1.10.1 (beta 23) released
----------------------------------------------

 * basic_file_path_buffer<> is now deprecated in all projects, and all dependent components are modified to use other facilities
 * added platformstl::environment_variable<> class template
 * added (in)equality operators for stlsoft::error_desc
 * added stlsoft::basic_path_buffer<> component, as an alternative to basic_file_path_buffer<>
 * stlsoft::auto_buffer<> class template copy_from() method, and ctor and resize() method that take value for initialisation of (new) elements
 * added stlsoft::strnpbrkn()/wcsnpbrkn() (and added stlsoft_C_(str|wcs)npbrkn())
 * added move constructor to unixstl::module and winstl::module
 * large number of new methods and defect fixes in (platformstl|unixstl|winstl)::filesystem_traits
 * large number of new methods and defect fixes in (platformstl|unixstl|winstl)::system_traits

29th November 2020 - 1.10.1 (beta 22) released
----------------------------------------------

 * added stlsoft::string_to_integer_range()
 * added stlsoft::strnchr(), stlsoft::strnistrn(), stlsoft::strnstrn() C-style string search functions
 * added move constructor to stlsoft::auto_buffer<>
 * added move constructor for stlsoft::scoped_handle<>
 * added move constructor for stlsoft::(basic_)simple_string<>
 * winstl::output_debug_line() overloads expanded to 16-parameters, and changed to use variadic templates where supported
 * stlsoft::split() functions enhanced to: return vector of arbitrary length; allow heterogeneous types for the split elements
 * stlsoft::string_switch() split into two overloads to handle property and unambiguously flag enums, regular enums, and enum classes
 * significant, BREAKING changes to stlsoft::try_parse_to() overloads to avoid ambiguity
 * changed significantly the way in which stlsoft::cstring_maker works, and adjusted all dependent code
 * various additions for compatibility with std::string_view (which is very similar to stlsoft::string_view)
 * fixed case of a bunch of headers

27th July 2020 - 1.10.1 (beta 21) released
------------------------------------------

 * VC++ 15/16 compatibility
 * fixed unixstl::readdir_sequence::empty()

4th July 2020 - 1.10.1 (beta 20) released
-----------------------------------------

 * fixed detecton of shared_ptr and unique_ptr

4th July 2020 - 1.10.1 (beta 19) released
-----------------------------------------

 * added stlsoft::t2w, stlsoft::w2t, stlsoft::t2a, stlsoft::a2t for upcoming Pantheios release
 * added stream insertion operator (generic) for string slice types
 * added compatibility with Visual C++ 15.x and 16.x
 * added support for the ARM architecture (christopherplawrence)

31st October 2019 - 1.10.1 (beta 18) released
---------------------------------------------

 * added stlsoft/system/environment/functions.hpp to enhances stlsoft::environment_variable_exists() with string access shims to support arbitrary string type
 * remove vestigial (and erroneous) winstl/string/spin_policies.hpp
 * various documentation fixes

24th October 2019 - 1.10.1 (beta 17) released
---------------------------------------------

 * GCC 8 compatibility
 * GCC 9 compatibility
 * implemented WinSTL_C_FileInformation_get_SECURITY_DESCRIPTOR_w()
 * improved documentation

13th October 2019 - 1.10.1 (beta 16) released
---------------------------------------------

 * added stlsoft_C_environment_variable_exists_a() / environment_variable_exists() (from STLSoft 1.10-alpha)
 * added stlsoft::count_bits(int) overload
 * added cbegin(), cend(), crbegin(), crend() to platformstl::environment_map
 * significant additions and removals of WinSTL file creation functions
 * added WinSTL security functions (from STLSoft 1.10-alpha)
 * recognising Mac OSX architecture as UNIX
 * canonicalising '\file' description sections
 * suppresses deprecation warning from reporting use of deprecated functions inside other deprecated functions

13th September 2019 - 1.10.1 (beta 15) released
-----------------------------------------------

 * added stlsoft::fast_strftime() and stlsoft::fast_wcsftime() as drop-in replacements for std::strftime() and std::wcsftime()
 * added get_ptr() shim overload for std::shared_ptr and std::unique_ptr
 * added stlsoft::get_top() attribute shim
 * stlsoft::basic_string_view<>::substr()
 * added winstl_C_format_message_strerror_w()
 * removed stlsoft::literal_cast<>
 * various portability improvements to newer compilers

4th August 2019 - 1.10.1 (beta 14) released
-------------------------------------------

 * added SECURITY_DESCRIPTOR helpers()
 * stlsoft::w2m and stlsoft::m2w now more general

16th April 2019 - 1.10.1 (beta 13) released
-------------------------------------------

 * fixed STLSOFT_ALWAYS_FALSE() / STLSOFT_ALWAYS_TRUE()
 * platformstl::FILE_stream : ~ fixing character-encoding function selection defect
 * canonicalising source file structure

26th December 2018 - 1.10.1 (beta 12) released
----------------------------------------------

 * added sas_to_string() (and related) functions
 * added stlsoft::errno_exception (from 1.12 branch)
 * added stlsoft::locale_scope
 * STLSoft's struct tm String Access Shims now work for arbitrary locale
 * UNIXSTL's timeval String Access Shims now work for arbitrary locale

22nd December 2018 - 1.10.1 (beta 11) released
----------------------------------------------

 * stlsoft::ref_ptr : + borrow(); + own()
 * winstl::environment_variable : + data(); + equal(); + equal_ignore_case(); + exists(); + operators ==() and !=()

20th December 2018 - 1.10.1 (beta 10) released
----------------------------------------------

 * winstl::process_mutex() now takes an optional EVENT handle which will be signalled if the mutex experiences an abandoned acquire
 * special_string_instance now provides generic (SAS) (in)equality operators automatically
 * try_parse_to_bool() semantics firmed up

12th June 2018 - 1.10.1 (beta 9) released
-----------------------------------------

 * Borland compatibility

11th June 2018 - 1.10.1 (beta 8) released
-----------------------------------------

 * fixing break to UNIX-compatibility introduced in beta-6/7

9th June 2018 - 1.10.1 (beta 7) released
----------------------------------------

 * auto_buffer<> now supports limited form of pointer arithmethic via operator -()
 * added subscript operator for auto_array_destructor<>
 * VC++ 14.1x compatibility
 * refactoring of copy-proscriptions

9th June 2018 - 1.10.1 (beta 6) released
----------------------------------------

 * refactored in terms of external API
 * removed empty/meaningless "compatibility" sections
 * canonicalising proscribed construction methods
 * simplifying, and prospective changes (for getting to 1.12)

15th May 2017 - 1.10.1 (beta 5) released
----------------------------------------

 * enhanced STLSOFT_SUPPRESS_UNUSED() to work with rvalues

19th February 2017 - 1.10.1 (beta 3) released
---------------------------------------------

 Further to 1.10.1 (beta 2):

 * a whole bunch of non-functional changes to make the codebase more
   consistent and amenable to further automatic instrumentation by script
   auto-validation script compatibility, and ensure all files have full
   inclusion control
 * fixing get_FILE_ptr() shim namespace issues
 * winstl::token_information has additional compatibility up to W8/Svr12,
   and now defaults to throwing instances of winstl::security_exception

28th January 2017 - 1.10.1 (beta 2) released
--------------------------------------------

 Further to 1.10.1 (beta 1):

 * work on STLSoft integer_to_string functions to loosen non-array forms'
   preconditions, reduce dependencies in rest of codebase to
   integer_to_decimal_string()-only;
 * filesystem_traits - refactored is_dots() and starts_with_dots() to
   accomodate GCC 4.9 pedanticism
 * exposing unixstl/winstl types spin_mutex_no_yield and spin_mutex_yield to
   platformstl namespace
 * a large number of changes to improve compatibility with UNIX, Clang,
   GCC, and MinGW
 * hiding/suppressing unused typedefs

14th January 2017 - 1.10.1 (beta 1) released
--------------------------------------------

 After ten years (10!), STLSoft 1.10 is finally out of alpha. The first
 release, 1.10.1 beta 1, comprises all the established components from
 previous versions along with several new components that have been
 available in the 1.10 alpha (delta) update and a large number of
 components previously unreleased.

 * major reworking of exceptions hierarchy, including provision of project
   and library identifiers, status-code, and message translation
 * several new special-string-instance types, including home_directory,
   host_name, temporary_directory, temporary_file_name
 * new string access shims, for types including timeval, type_info
 * new attribute shims, including: get_synch_handle, get_FILE_ptr
 * new logical shims, including: is_empty, is_null
 * new high-performance conversion functions (based around the extant
   technology in stlsoft::integer_to_string()): integer_to_decimal_string(),
   integer_to_hexadecimal_string(), integer_to_octal_string(),
   integer_to_lc_string(), integer_to_zero_padded_decimal_string()
 * new conversion parsing functions: string_to_bool(), string_to_integer()
 * new scoped_method class template
 * new scoped_lambda class template
 * new bit-testing functions
 * substantially improved atomic function support
 * substantially improved spin_mutex class templates and policies
 * new diagnostic stopwatch classes and logging functions
 * new platformstl::file_stream_base class template and policies
 * new string slice classes that are compatible (but do not depend on) other
   Synesis projects (such as FastFormat and Pantheios)
 * new time comparison functions and operators, conversion cast and
   functions, elicitation functions, modification functions, and validation
   functions
 * ... and many many other improvements and additions ...

============================================================================



============================================================================

1st October 2016 - 1.9.130 released
-----------------------------------

 * minor tidyings


17th July 2016 - 1.9.129 released
---------------------------------

 * minor tidyings


4th May 2016 - 1.9.126 released
-------------------------------

 * improvements to Windows Registry library


14th February 2016 - 1.9.125 released
-------------------------------------

 * various minor warnings / compiler compatibilities


15th November 2015 - 1.9.124 released
-------------------------------------

 * MSVC++ does not support __func__


15th November 2015 - 1.9.123 released
-------------------------------------

 * added STLSOFT_NOEXCEPT
 * changed no-throw declaration from stlsoft_throw_0() to STLSOFT_NOEXCEPT
 * STLSOFT_CF_EXPLICIT_KEYWORD_SUPPORT => STLSOFT_CF_explicit_KEYWORD_SUPPORT
 * STLSOFT_CF_MUTABLE_KEYWORD_SUPPORT => STLSOFT_CF_mutable_KEYWORD_SUPPORT
 * STLSOFT_CF_BUILTIN_nullptr_SUPPORT => STLSOFT_CF_nullptr_KEYWORD_SUPPORT
 * STLSOFT_CF_OVERRIDE_KEYWORD_SUPPORT => STLSOFT_CF_override_KEYWORD_SUPPORT
 * STLSOFT_CF_constexpr_KEYWORD_SUPPORT
 * STLSOFT_CF_final_KEYWORD_SUPPORT
 * added token_information<>::get(), token_information<>::size()
 * correct use of deallocate()


1st November 2015 - 1.9.122 released
------------------------------------

 * added STLSOFT_PRETTY_FUNCTION_SYMBOL
 * now prefers __func__ over __FUNCTION__ for STLSOFT_FUNCTION_SYMBOL
 * added (recognition of) support for nullptr
 * added (recognition of) support for static_assert
 * added ss_override_k / STLSOFT_CF_OVERRIDE_KEYWORD_SUPPORT
 * added STLSOFT_DEBUG
 * Clang compatibility
 * Windows-emulation compatibility
 * replaced dodgy use of memset()
 * forward compatibility with 1.10+


26th September 2015 - 1.9.121 released
--------------------------------------

 * Clang-compatibility


27th August 2015 - 1.9.120 released
-----------------------------------

 * optimised stlsoft::auto_buffer::swap() method
 * added unixstl_C_get_console_width() / unixstl::get_console_width()
 * WinSTL ToolHelp library widestring-compatibility
 * VC++ 14 compatibility


26th August 2015 - 1.9.119 released
-----------------------------------

 * Visual C++ 14 (Visual Studio 2015) compatibility
 * compatibility with GCC 4.x's LLVM library
 * 64-bit compatibility fixes
 * various fixes for increased compiler pedanticism
 * corrections to ensure that all .h files are C-compatible
 * forward-compatibility (to STLSoft 1.12) for numerous macros
 * various minor fixes
 * various minor changes


31st May 2014 - 1.9.118 released
--------------------------------

 * added Visual C++ 12 (VS 2013) compatibility
 * added struct initialisers for CONSOLE_SCREEN_BUFFER_INFO & CONSOLE_SCREEN_BUFFER_INFOEX
 * added second overload of winstl::filesystem_traits::ensure_dir_end() that takes a pointer to a length-added counter variable
 * added forward-compatibility with STLSoft 1.10's substantially enhanced and expanded synchronisation exception hierarchy to Synchronisation Library types
 * added winstl::system_traits::get_home_directory() (although it's only operative in 1.10+ or when using 1.10 alpha with 1.9)
 * various minor fixes
 * various minor changes


16th February 2013 - 1.9.117 released
-------------------------------------

 * added Visual C++ 11 compatibility
 * various minor changes


19th August 2012 - 1.9.116 released
-----------------------------------

 * fixed defect in winstl::pipe::close_write()
 * various other minor warning suppression and reformatting


31st July 2012 - 1.9.115 released
---------------------------------

 * stlsoft::integer_to_string() new overloads with out-parameter as pointer; deprecated overloads with out-parameter as reference
 * winstl::integral_printf_traits added octal_format_a/w(), hexadecimal_format_a/w(), decimal_format_a/w(); deprecated format_a/w() and hex_format_a/w() methods, and size_min, size_max, and size member constants
 * Windows 7-compatibility for winstl::drophandle_sequence
 * winstl::spin_mutex now uses SwitchToThread if _WIN32_WINNT >= 0x0400
 * added winstl::added GetTimeFormat_msExA/W() by which custom time markers can be specified


4th June 2012 - 1.9.114 released
--------------------------------

 * added unixstl::filesystem_traits::is_socket(char_type const*) method
 * added unixstl::filesystem_traits::is_link(char_type const*) method
 * added unixstl::filesystem_traits::is_socket(stat_data_type const*) method
 * added unixstl::filesystem_traits::find_next_path_name_separator() method
 * added unixstl::filesystem_traits::find_last_path_name_separator() method
 * unixstl::filesystem_traits::get_full_path_name() now canonicalises '.'/'..'-trailing paths
 * unixstl::readdir_sequence.hpp now includes directory name in thrown exception


4th June 2012 - 1.9.113 released
--------------------------------

 * Intel C/C++ 12 support
 * support for STLSOFT_COMPILE_VERBOSE; deprecation of _STLSOFT_COMPILE_VERBOSE
 * fixed unixstl::filesystem_traits::broken get_current_directory()
 * fixed unixstl::filesystem_traits::broken invalid_file_handle_value()
 * fixed unixstl::filesystem_traits::is_file() / is_directory() / is_link()
 * numerous improvements to unixstl::filesystem_traits::glob_sequence
 * unixstl::readdir_sequence correction to elide sockets from search results
 * winstl/time/conversion_functions.h renaming (and deprecation) of non-standard C function names


7th February 2012 - 1.9.112 released
------------------------------------

 * added winstl_C_format_message_strerror_a(), an analogue of strerror() for Windows API "error" codes
 * adjusted discrimination of exception-support macros, based on presence of GCC compiler's __EXCEPTIONS symbol
 * minor VC++ compatibility fix for stlsoft/shims/access/string/std/exception.hpp


30th November 2011 - 1.9.111 released
-------------------------------------

 * fix for GCC 4.5+ unixstl::filesystem_traits


25th November 2011 - 1.9.110 released
-------------------------------------

 * fix for GCC 4.5+ unixstl::filesystem_traits
 * added result_code_type to both unixstl::system_traits and winstl::system_traits
 * correction(s)/enhancement(s) to which of MFCSTL's string access shim headers are automatically included
 * added discrimination of new pre-processor symbol PLATFORMSTL_NO_PLATFORM_NAMESPACE, to ease dependent library implementation
 * avoidance of false memory-leak reports in use of stlsoft::truncation_test


13th August 2011 - 1.9.109 released
-----------------------------------

 * added rbegin()/rend() to stlsoft::frequency_map<>
 * added push_n() to stlsoft::frequency_map<>
 * refactored throw statement(s) in terms of STLSOFT_THROW_X() throughout
 * added reset() method to stlsoft::shared_ptr<>
 * added various STLSoft deprecation macros
 * added is_path_rooted(), is_path_absolute(), and is_path_UNC() methods to unixstl::filesystem_traits<>
 * added two-parameters overloads of is_path_rooted(), is_path_absolute(), and is_path_UNC() methods to winstl::filesystem_traits<>
 * include/winstl/error/error_functions.h: substantial refactoring of format_message()-family of functions (and their C analogues)


31st January 2011 - 1.9.108 released
------------------------------------

 * changed erroneously named new unixstl::/winstl::filesystem_traits method's name from invalid_handle_value() to invalid_file_handle_value()
 * added third, defaulted, template parameter to stlsoft::frequency_map for specification of predicate


30th January 2011 - 1.9.107 released
------------------------------------

 * added data() member to stlsoft::multibyte2wide and stlsoft::wide2multibyte
 * added data() member to winstl::multibyte2wide and winstl::wide2multibyte
 * improved performance of of c_str_len(_a|_w)() shim overloads of stlsoft::multibyte2wide and stlsoft::wide2multibyte
 * improved performance of of c_str_len(_a|_w)() shim overloads of winstl::multibyte2wide and winstl::wide2multibyte
 * added equal() method and operator ==/!=() non-member functions to unixstl::memory_mapped_file
 * added equal() method and operator ==/!=() non-member functions to winstl::memory_mapped_file
 * added non-member unixstl::swap() function for unixstl::memory_mapped_file
 * added non-member platformstl::swap() function for platformstl::memory_mapped_file
 * changed definition of unixstl::memory_mapped_file::size_type to be size_t
 * added invalid_handle_value() method to unixstl::filesystem_traits<>
 * added invalid_handle_value() method to winstl::filesystem_traits<>
 * added added get_file_size(stat_data_type const&) and get_file_size(stat_data_type const*) overloads to unixstl::filesystem_traits<>
 * added added get_file_size(stat_data_type const&) and get_file_size(stat_data_type const*) overloads to winstl::filesystem_traits<>
 * reduced dependencies on other string access shim overloads in winstl::error_desc


28th December 2010 - 1.9.106 released
-------------------------------------

 * workaround for Intel compile error


27th December 2010 - 1.9.105 released
-------------------------------------

 * several new minor facilities in stlsoft::frequency_map
 * improved compiler-compatibility in stlsoft::multibyte2wide and stlsoft::wide2multibyte
 * WinSTL now recognises Win64 architecture when _WIN64 is defined even when WIN64 is not


22nd November 2010 - 1.9.104 released
-------------------------------------

 * refactored wide string exception string access shim functions, to avoid so-called "deprecated" (standard) functions when using VC++
 * expanded internal buffers of shim strings for exception string access shims, from 10 to 100


21st November 2010 - 1.9.103 released
-------------------------------------

 * changed mechanism of discriminating Dinkumware standard library versions
 * added typedefs for path_a and path_w to introduce them into the platformstl namespace


8th November 2010 - 1.9.102 released
------------------------------------

 * added wide string string access shims for std::exception
 * fixed infinite-recursion defects in ambient shim function definitions
 * other compatibility fixes


30th September 2010 - 1.9.101 released
--------------------------------------

 * stlsoft::transform_iterator can now support transformation to types that do not support default construction
 * fixed defect in stlsoft::transform_iterator
 * platformstl::basic_file_lines refactored, and exception-safety enhanced
 * winstl::memory_mapped_file refactored in preparation for substantial enhancement in 1.10; also no longer supports compilers that do not have native 64-bit integers


12th August 2010 - 1.9.100 released
-----------------------------------

 * added stlsoft/iterators/common/string_concatenation_flags.hpp
 * string_concatenator_iterator now strictly skips separator insertion for empty elements if no flags are specified, and always inserts separator if string_concatenation_flags::AlwaysSeparate is specified
 * added performance_counter_init::get_period_and_restart() method
 * added STLSOFT_CC_CDECL_VALUE, STLSOFT_CC_FASTCALL_VALUE, STLSOFT_CC_STDCALL_VALUE
 * special_string_instance now uses atomic_int_type
 * string_tokeniser iterator dereference operator changed to disallow return of mutable instance
 * string_view has improved comparison algorithm
 * added 3-, 4-, and 5-parameter overloads of stlsoft::minimum() and stlsoft::maximum()
 * various fixes and enhancements to platformstl::file_lines
 * added size() and empty() methods to winstl::environment_variable
 * implemented winstl::system_traits::str_n_compare_no_case()


21st June 2010 - 1.9.99 released
--------------------------------

 * added filesystem_traits::str_fs_compare() (UNIXSTL & WinSTL)
 * added filesystem_traits::str_fs_n_compare() (UNIXSTL & WinSTL)
 * added str_n_compare_no_case declaration to system_traits (UNIXSTL & WinSTL)
 * added assoc_select_first() and assoc_select_second() creator functions for associative_select_iterator
 * incorporated Manfred Ehrhart's fixes for associative_select_iterator
 * Borland/GCC-compatibility fixes
 * GCC-compatibility fixes
 * nullptr support correction for VC++
 * various minor fixes


7th June 2010 - 1.9.98 released
-------------------------------

 * added range overload of stlsoft::read_line(), so can read lines from an iterator range
 * added nullptr (C++0x) support for VC++ 10
 * added swap() method to stlsoft::basic_shim_string
 * added 3, 4, 5, and 6-split overloads to stlsoft::split()
 * added sized-string ctor, data() and size() methods, and string access shims (to simplify xTests-based unit-testing, if nothing else) to stlsoft::exception_string
 * added VARIANT_BOOL overload to comstl::method_cast()
 * added platformstl::file_lines empty() method
 * separated PlatformSTL's atomic types into separate file platformstl/synch/atomic_types.h
 * separated UNIXSTL's atomic types into separate file unixstl/synch/atomic_types.h
 * separated WinSTL's atomic types into separate file winstl/synch/atomic_types.h
 * fixed winstl::memory_mapped_file to handle case where an offset is specified but there are 0 remaining bytes in the file to be mapped at that location: constructs an instance with 0 size
 * fixed potential memory leak of format-message-string if windows_exception creation throws an exception
 * moved COMSTL_CCH_GUID to comstl/comstl.h from comstl/shims/access/string/guid.hpp
 * adjusted winstl::drophandle_sequence for Win64 compatibility
 * adjusted winstl::version_info for Win64 compatibility
 * various components no longer rely on operator += of exception_string type, in preparation for 1.10 versions


4th April 2010 - 1.9.97 released
--------------------------------

 * added stlsoft::copy_preinc() and stlsoft::copy_postinc() algorithms
 * added str_set() method to unixstl::/winstl::system_traits
 * added unixstl/shims/conversion/to_uint64/stat.hpp
 * added missing widestring specialisation of inetstl::filesystem_traits::is_path_name_separator()
 * stlsoft::basic_error_desc synthesises widestring functionality if wcserror() is not available
 * exposes widestring version of platformstl::system_traits from UNIXSTL
 * comstl::variant compatibility with exception-support disabled
 * removed erroneous definitions of strtol(), strtoul(), strtod()
 * added missing 'mode' parameter to unixstl::module::load(), and uses 'mode' parameter passed to constructor template
 * typename corrections to platformstl::basic_file_path_buffer and platformstl::basic_path
 * improved discrimination of Visual C++ 9 / 10
 * fixed defective arithmetic in unixstl::/winstl::memory_mapped_file
 * refactored implementation of winstl::reg_key::create_key() to avoid infinite loop faults


10th March 2010 - 1.9.96 released
---------------------------------

 * Visual C++ 10 compatibility


7th March 2010 - 1.9.95 released
--------------------------------

 * minor interface modifications to comstl::com_exception


5th March 2010 - 1.9.94 released
--------------------------------

 * corrected omission of inline from swap for unixstl::memory_mapped_file
 * corrected omission of inline from swap for winstl::memory_mapped_file


15th February 2010 - 1.9.93 released
------------------------------------

 * STLSOFT_CF_NAMESPACE_SUPPORT is now only defined in C++ compilation units
 * added WINSTL_CONST_MAX_PATH, which is now used instead of _MAX_PATH throughout winstl


11th February 2010 - 1.9.92 released
------------------------------------

 * added inetstl::filesystem_traits<>::is_path_name_separator()


2nd February 2010 - 1.9.91 released
-----------------------------------

 * introducing unixstl::/winstl::remove_directory_recurse() into platformstl namespace
 * removal of dependency on so-called "unsafe" string functions
 * elimination of calls to memcpy() in path classes
 * throwing of exception in make_absolute() if failed to get full path


21st January 2010 - 1.9.90 released
-----------------------------------

 * fixed defect in unixstl::filesystem_traits<>::get_full_path_name() when passed "."
 * header ordering workaround for GCC 3.4's strange COM headers on Windows


19th January 2010 - 1.9.89 released
-----------------------------------

 * fixed defective stream inserter for stlsoft::error_desc
 * fixed erroneous push-pop in include/acestl/reactor/custom_event_handler.hpp:
 * safe-string compatibility for various UNIXSTL system/filesystem components


12th January 2010 - 1.9.88 released
-----------------------------------

 * added throwOnAccessFailure search flag to winstl::basic_findfile_sequence, along with supporting code
 * added winstl::access_exception
 * full integer handling for comstl::variant
 * addition of max_size() static method to basic_file_path_buffer class template
 * change of max_size() method to be static in basic_path
 * fixed longstanding incompatibility between reverse_iterator and const_reverse_iterator
 * C compatibility fixes
 * compatibility with GCC 3.4
 * truncation_test is now a function template (rather than a macro to an internal function)
 * deprecation/removal of reserved symbols, and replacement with valid symbols


11th August 2009 - 1.9.87 released
----------------------------------

 * trivial formatting changes


24th July 2009 - 1.9.86 released
--------------------------------

 * added STLSOFT_CF_THISCALL_SUPPORTED
 * added thiscall overloads of mem_fun_ref() and mem_fun_ref_void()
 * Borland compatibility for scoped_handle
 * fix to unixstl::filesystem_traits::get_full_path_name() (to detect when path contains reserved characters)


16th June 2009 - 1.9.85 released
--------------------------------

 * added merge() and swap() to stlsoft::frequence_map class template
 * winstl::listview_sequence::value_type::string_type (aka lvs_string_t) is now overrideable via the preprocessor, in preparation for future expansion of flexibility


23rd May 2009 - 1.9.84 released
-------------------------------

 * fixed defect in winstl::basic_reg_key::set_value() for REG_MULTI_SZ values (widestring only)
 * "safe string" library and widestring support for stlsoft::basic_error_desc
 * various 64-bit LP64 compatibility changes


19th May 2009 - 1.9.83 released
-------------------------------

 * fixed defects in winstl::basic_reg_value::value_sz()/value_multi_sz()
 * fixed defects in exception-safety in winstl::basic_reg_value and winstl::basic_reg_key
 * various minor fixes and documentation mods


15th May 2009 - 1.9.82 released
-------------------------------

 * added winstl::reg_traits<>::reg_delete_tree()
 * added IOStreams compatibility for winstl::findfile_sequence::value_type


7th May 2009 - 1.9.81 released
------------------------------

 * now recognises __func__, provided by Sun Pro, via STLSOFT_CF_func_SYMBOL_SUPPORT
 * abstracts __FUNCTION__ support to STLSOFT_FUNCTION_SYMBOL


6th May 2009 - 1.9.80 released
------------------------------

 * now recognises support for variadic macros and #pragma once for later versions of Borland C/C++
 * SunPro compatibility improvements for UNIXSTL synchronisation components
 * fixes to defects in stlsoft::basic_simple_string at() and 5-parameter compare() methods
 * basic_path class templates (both UNIXSTL and WinSTL versions) now implement assignment operator differently to avoid possibilities of infinite loops (which can happen when a type with an opposing string encoding is used)
 * correction to stlsoft::auto_buffer to ensure allocators are involved in swap() operations
 * correction to struct in_addr string access shims for compatibility with big-endian architectures
 * various changes for compatibility with "safe string" library


2nd May 2009 - 1.9.79 released
------------------------------

 * UNIX compatibility for InetSTL
 * "safe string" library compatibility for InetSTL


27th April 2009 - 1.9.78 released
---------------------------------

 * fixed serious defect in atlstl::copy_enumerator_impl::Reset()
 * stlsoft::shared_ptr now works correctly if fails to allocate counter
   variable in conditions where exception handling is not supported
 * stlsoft::c_str_data_a(struct fm const*) now correctly handles case where
   tm pointer is NULL
 * corrected behaviour of get_environment_variable for both UNIXSTL and
   WinSTL system_traits traits classes
 * various compiler compatibility fixes
 * various documentation corrections


9th March 2009 - 1.9.77 released
--------------------------------

 * corrected invalid invariants in memory_mapped_file classes in UNIXSTL and
   WinSTL


6th March 2009 - 1.9.76 released
--------------------------------

 * added swap() methods to memory_mapped_file classes in UNIXSTL and WinSTL
 * corrected defect in VC++ detection of bad_alloc support (which only
   affects VC++ 6 or earlier)


26th February 2009 - 1.9.75 released
------------------------------------

 * tidied up COMSTL documentation
 * tidied up scoped_handle use in winstl::memory_mapped_file
 * added checks to detect at compile time accidental use of &stat_data with winstl::filesystem_traits<>::get_file_size()
 * fixed defect in winstl::basic_reg_value::value_sz(), whereby the nul-terminator is included in the resultant string length
 * tidied up winstl::basic_path, and added max_size() method
 * tidied up winstl::basic_commandline_parser, added substring-constructor, and changed subscript operator to allow indexing (but not use) of the end element


13th February 2009 - 1.9.74 released
------------------------------------

 * further implementation of special Borland version of stlsoft::scoped_handle
 * further workarounds to Borland code generation defects in stlsoft::basic_simple_string and platformstl::basic_file_lines


3rd February 2009 - 1.9.73 released
-----------------------------------

 * added partial support for Borland 5.9.x and 6.1.x; to support use of Borland with Pantheios
 * re-applied VC++ 7.1 workaround eroneously removed in 1.9.70


1st February 2009 - 1.9.72 released
-----------------------------------

 * added char_copy() methods to filesystem_traits classes in UNIXSTL, as part of move away from "unsafe" string functions
 * fixed defect in winstl::squeeze_path() whereby wrong length is returned if buffer size is < 5 and the file length < buffer size
 * removes unwanted trailing slash in application directory from winstl::basic_searchpath_sequence
 * further work to remove dependency on "unsafe" string functions


28th January 2009 - 1.9.71 released
-----------------------------------

 * fixed DMC++ incompatibility introduced in 1.9.70


25th January 2009 - 1.9.70 released
-----------------------------------

 * improved stlsoft::find_next_token() function templates to ensure that all empty fields are reported to caller
 * added char_copy() methods to filesystem_traits classes in InetSTL and WinSTL, as part of move away from "unsafe" string functions
 * minor enhancements to platformstl::readdir_sequence, to disambiguate constructor overloads
 * removed all "unsafe" string functions from winstl::basic_findfile_sequence class template and supporting components
 * improved winstl::basic_path class template to ensure proper behaviour in corner cases of use of push() and pop() methods


23rd January 2009 - 1.9.69 released
-----------------------------------

 * improved robustness of winstl::path_squeeze
 * more "Safe String" library compatibility changes


19th January 2009 - 1.9.68 released
-----------------------------------

 * fix defect, and updated docs, for stlsoft::must_init utility class template


17th January 2009 - 1.9.67 released
-----------------------------------

 * compatibility with GCC on Fedora on PPC
 * correction of semantics of null_allocator


4th January 2009 - 1.9.66 released
----------------------------------

 * compatibility with GCC 4.3's pedantic precedence warnings
 * compatibility with SunPro compiler for limit_traits


1st January 2009 - 1.9.65 released
----------------------------------

 * "Safe String" library compatibility changes


28th December 2008 - 1.9.64 released
------------------------------------

 * fix to string access shims for VARIANT


9th December 2008 - 1.9.63 released
-----------------------------------

 * optimised stlsoft::basic_string_view::reserve()
 * enhanced compatibility for stlsoft::fixed_array_?d class templates


1st December 2008 - 1.9.62 released
-----------------------------------

 * fixed defect in interface_cast<> and try_interface_cast<>
 * improved compatibility with Visual C++ 9
 * speculative support for Intel C/C++ 11.0
 * fixed defect in winstl::to_SYSTEMTIME(DATE) overload


19th November 2008 - 1.9.61 released
------------------------------------

 * better compatibility with SAPI.h for COMSTL's sapi_util.hpp
 * documentation markup improvements for a number of files


27th October 2008 - 1.9.60 released
-----------------------------------

 * added stlsoft::apply_const()
 * added stlsoft/conversion/m2w.hpp


25th October 2008 - 1.9.59 released
-----------------------------------

 * change in ATLSTL's property method helpers to avoid infinite loop in
   Visual C++ 6 problem when implementing property puts to CComBSTR
 * fixed compile error with GCC when using VARIANTs in C compilation units


16th October 2008 - 1.9.58 released
-----------------------------------

 * fixed major defect introduced in 1.9.52 to WinSTL's time string access
   shims
 * fixed minor defects in COMSTL's VARIANT string access shims
 * fixed defect in documentation generation whereby examples were omitted
 * reduced compilation dependencies in STLSoft's time string access shims

10th October 2008 - 1.9.57 released
-----------------------------------

 * addition of missing const_reference member type in various Windows
   controls collection classes
 * C / C++ compatibility fixes for COMSTL
 * fix of minor non-standard name in winstl::int_to_string() supporting
   class
 * a large number of files were altered in minor ways, to do with whitespace
   and the placement of * and & symbols
 * several files' documentation markup was cleaned up

1st October 2008 - 1.9.56 released
----------------------------------

 * a large number of minor enhancements to the documentation markup
 * fixes to defects to include guards in UNIXSTL

27th September 2008 - 1.9.55 released
-------------------------------------

 * corrected defects in stlsoft::wide2multibyte and stlsoft::multibyte2wide
   conversion classes
 * fixes to various x64 defects related to use of inappropriate calling
   convention specifiers with use of dl_call
 * sundry other modifications in internal pre-processor facilities and
   small improvements to Watcom compatibility

15th September 2008 - 1.9.54 released
-------------------------------------

 * added stlsoft::exception_string::truncate() method
 * removed dependency of UDATE for to_FILETIME() and to_SYSTEMTIME() shim
   overloads for DATE type

14th September 2008 - 1.9.53 released
-------------------------------------

 * changed definition of STLSOFT_STATIC_ASSERT() to work with GCC
 * defect defect in pre-condition enforcement of
   winstl::system_traits::expand_environment_strings()

11th September 2008 - 1.9.52 released
-------------------------------------

 * fixed for warnings in 64-bit compilation (VC9) in WinSTL string access
   shims for SYSTEMTIME; also added extra safeguard against external race
   condition

7th September 2008 - 1.9.51 released
------------------------------------

 * workaround for defective exception-throwing behaviour of
   stlsoft::conversion_error with VC6
 * fixed defect in WinSTL string access shims for SYSTEMTIME that faults
   when asked to process an invalid time value

3rd September 2008 - 1.9.50 released
------------------------------------

 * added stlsoft character conversion typedefs m2w, w2m, t2m, m2t
 * fix for VC++ 6 defect in requiring return code after exception throw

2nd September 2008 - 1.9.49 released
------------------------------------

 * fix for DMC++ defect in winstl::reg_value function template definition
 * added winstl character conversion typedefs m2w, w2m, t2m, m2t

23rd August 2008 - 1.9.48 released
----------------------------------

 * added comstl/util/CY_functions.h
 * added comstl/util/DECIMAL_functions.h
 * added comstl/util/VARIANT_functions.h
 * added comstl::variant conversion constructor for DECIMAL
 * fixed bug in stlsoft::trim_all()
 * added winstl::basic_error_desc<>::empty()

12th August 2008 - 1.9.47 released
----------------------------------

 * enhancement of stlsoft::read_line() function template to work with
   various line-termination sequences
 * enhancement of fixed array classes to allow zero size
 * winstl::clipboard_format_sequence enhancements to iterator type profile
 * winstl::clipboard_scope defect fix and documentation enhancement
 * syntactic modification of contract enforcement statements to a large
   number of components to address warnings with GCC 4.3 in pedantic mode

11th August 2008 - 1.9.46 released
----------------------------------

 * defect fixes to stlsoft::pod_vector
 * reduced coupling, and increased functionality, of stlsoft::format_bytes()
 * sundry compatibility improvements

8th June 2008 - 1.9.45 released
-------------------------------

 * enhancement to stlsoft::to_uint64 conversion shim for ULARGE_INTEGER
 * more Win-64 compatibility changes
 * fixes to winstl::basic_path class template

1st June 2008 - 1.9.44 released
-------------------------------

 * bug fix in winstl/shims/access/string/LSA_UNICODE_STRING.hpp, required
   for newly released flecxx library

31st May 2008 - 1.9.43 released
-------------------------------

 * more Win64-compatibility modifications
 * more Safe String library modifications
 * expanded the stlsoft::get_FILE_ptr attribute shim for MFC's CStdioFile

17th May 2008 - 1.9.42 released
-------------------------------

 * more Win64-compatibility modifications
 * more Safe String library modifications

13th May 2008 - 1.9.41 released
-------------------------------

 * bug fix for GCC compilation on PowerPC that was broken with 1.9.40

13th May 2008 - 1.9.40 released
-------------------------------

 * significant refactoring of compiler-capability discrimination for GCC and
   VC++
 * compatibility fixes for SunPro compilers
 * bug fix in integral_printf_traits (introduced in 1.9.39)

11th May 2008 - 1.9.39 released
-------------------------------

 * next tranche of changes for Win64 support

4th May 2008 - 1.9.38 released
------------------------------

 * next tranche of changes for Win64 support

3rd May 2008 - 1.9.37 released
------------------------------

 * first tranche of changes for Win64 support

30th April 2008 - 1.9.36 released
---------------------------------

 * added support for FreeBSD operating system

29th April 2008 - 1.9.35 released
---------------------------------

 * added value_multi_sz() to winstl::reg_value

25th April 2008 - 1.9.34 released
---------------------------------

 * renamed winstl::get_hwnd attribute shim to winstl::get_HWND
 * minor adjustments to Sun Pro support
 * library feature discrimination symbol cleanup
 * refactored error/exception handling in Windows Registry library

25th April 2008 - 1.9.33 released
---------------------------------

 * added support for the SunPro C and C++ compilers
 * various mods to ensure headers are self-contained when used with
    Windows "lean and mean" suppression symbols

22nd April 2008 - 1.9.32 released
---------------------------------

 * fix for VC++ 8/9 linker error in the allocator_selector
 * refactoring of string access shim headers for lightweight compilation

13th April 2008 - 1.9.31 released
---------------------------------

 * exception hierarchy refactoring
 * bug fix to stlsoft::must_init

3rd April 2008 - 1.9.30 released
--------------------------------

 * tidying of distribution

3rd March 2008 - 1.9.29 released
--------------------------------

 * more preparation for safe string library compatibility

24th March 2008 - 1.9.28 released
---------------------------------

 * enhancement to winstl::reg_key class
 * preparation for safe string library compatibility
 * bug fix for C-compilation in winstl/controls/functions.h

17th March 2008 - 1.9.27 released
---------------------------------

 * support for Visual C++ 9 (Visual C++ 2008)
 * fixed pre-processor typo that breaks GCC -pedantic
 * added item-data functions for list-/combo-boxes

15th March 2008 - 1.9.26 released
---------------------------------

 * definition, where appropriate, of STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT,
   denoting that a particular compiler supports the __FUNCTION__
   pre-processor symbol

9th March 2008 - 1.9.24 released
--------------------------------

 * wholesale increase of use of forward include guards, to reduce
   compilation times

8th March 2008 - 1.9.24 released
--------------------------------

 * finishing up some missed std::swap refactoring

20th February 2008 - 1.9.23 released
------------------------------------

 * fix for minor compiler compatibility issue

8th February 2008 - 1.9.22 released
-----------------------------------

 * refactored unixstl/synch/util/features.h

5th February 2008 - 1.9.21 released
-----------------------------------

 * fixed a bug in platformstl/synch/util/features.h

3rd February 2008 - 1.9.20 released
-----------------------------------

 * added new stlsoft::singlethreaded_tss_index synchronisation utility class

2nd February 2008 - 1.9.19 released
-----------------------------------

 * enhancement of SAPI utility header for COMSTL

27th January 2008 - 1.9.18 released
-----------------------------------

 * enhancement of STLSoft's integral_printf_trait component to support
   Pantheios 1.0.1 beta 91
 * release of SAPI utility header for COMSTL

5th January 2008 - 1.9.17 released
----------------------------------

 * bug fix for UNIXSTL on Leopard/GCC 4.0.1

29th December 2007 - 1.9.16 released
------------------------------------

 * bug fix in stlsoft::printf_traits
 * bug fix in winstl::GetTimeFormat_msA/W
 * other minor bug fixes
 * minor feature enhancements & refactoring

24th December 2007 - 1.9.15 released
------------------------------------

 * minor bug fix for C compilation

23rd December 2007 - 1.9.14 released
------------------------------------

 * updated stlsoft version (_STLSOFT_VER) missing in 1.9.13

20th December 2007 - 1.9.13 released
------------------------------------

 * features enhancements to fixed array classes

19th December 2007 - 1.9.12 released
------------------------------------

 * features enhancements to fixed array classes

17th December 2007 - 1.9.11 released
------------------------------------

 * minor modifications and bug-fixes

10th December 2007 - 1.9.10 released
------------------------------------

 * bug fix for recls (http://recls.org/)
 * minor feature enhancements

19th November 2007 - 1.9.9 released
-----------------------------------

 shim fixes in UNIXSTL

18th November 2007 - 1.9.8 released
-----------------------------------

 compatibility with Borland C/C++ 5.82 (Turbo C++); now supports VOLE

16th November 2007 - 1.9.7 released
-----------------------------------

 Win 64-bit compilation support; not perfect yet
 Borland Turbo C++ v5.82 support; not perfect yet
 new stlsoft::get_FILE_ptr shim
 new platformstl::file_lines class
 new winstl::to_DATE conversion shim
 major enhancements to unixstl::memory_mapped_file
 multiple compiler compatibility enhancement fixes
 minor compilation warning fixes

25th September 2007 - 1.9.6 released
------------------------------------

 bug fixes - mostly minor


2nd August 2007 - 1.9.5 released
--------------------------------

 minor additions and bug fixes


2nd August 2007 - 1.9.4 released
--------------------------------

 __VA_ARGS__ compiler-support detection


29th July 2007 - 1.9.3 released
-------------------------------

 A couple of small additions.

 Documentation still outstanding ... resolved soon. Hopefully.


2nd June 2007 - 1.9.2 released
------------------------------

 A few changes and updates to various components, primarily to support the
 release of recls 1.8.10 (http://recls.org/downloads.html).

 The elephant in the living room is still the lack of documentation. It's
 coming ... honest.


30th April 2007 - 1.9.1 released (for Extended STL, volume 1: CD)
-----------------------------------------------------------------

 There has been an enormous amount of change in STLSoft from the last
 release, 1.8.9 (October 2005), to the new release, 1.9.1 (April/May 2007).

 Consequently, I just can't muster the effort at this time to detail the
 entire set of changes. The one big change I will note, however, is that
 the library files no longer reside in the root directory, e.g.

   comstl_bstr_functions.h

 and are now in appropriate sub-directories under the sub-project
 sub-directories, e.g.

   comstl/string/bstr_functions.h


<!-- ########################### end of file ########################### -->

