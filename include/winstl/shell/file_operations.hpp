/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/shell/file_operations.hpp
 *
 * Purpose: Shell file operations.
 *
 * Created: 12th December 1996
 * Updated: 20th March 2025
 *
 * Thanks:  To Pablo Aguilar for default folder enhancements.
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1996-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file winstl/shell/file_operations.hpp
 *
 * \brief [C++] Definition of Windows Shell file operation functions
 *   (\ref group__library__Windows_Shell "Windows Shell" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SHELL_HPP_FILE_OPERATIONS
#define WINSTL_INCL_WINSTL_SHELL_HPP_FILE_OPERATIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHELL_HPP_FILE_OPERATIONS_MAJOR      2
# define WINSTL_VER_WINSTL_SHELL_HPP_FILE_OPERATIONS_MINOR      1
# define WINSTL_VER_WINSTL_SHELL_HPP_FILE_OPERATIONS_REVISION   9
# define WINSTL_VER_WINSTL_SHELL_HPP_FILE_OPERATIONS_EDIT       106
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes.
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_SHELL_ALLOCATOR
# include <winstl/memory/shell_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_SHELL_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <winstl/winstl.h>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */

#ifndef STLSOFT_INCL_H_SHELLAPI
# define STLSOFT_INCL_H_SHELLAPI
# include <shellapi.h>
#endif /* !STLSOFT_INCL_H_SHELLAPI */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

namespace ximpl_winstl_shell_functions_ {

inline
int
shell_delete_a_(
    HWND                hwnd
,   ws_char_a_t const*  from
,   ws_char_a_t const*  progressTitle
,   FILEOP_FLAGS        flags
,   ws_bool_t*          pbAborted
)
{
    WINSTL_MESSAGE_ASSERT("Null string cannot be specified", NULL != from);

    typedef auto_buffer<ws_char_a_t, 2 + WINSTL_CONST_MAX_PATH, shell_allocator<ws_char_a_t> >  buffer_t;

    ws_size_t   cch =   static_cast<ws_size_t>(::lstrlenA(from));
    buffer_t    buff(1 + cch + 1);

    if (buff.empty())
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_NOT_ENOUGH_MEMORY);

        return ERROR_NOT_ENOUGH_MEMORY;
    }
    else
    {
        SHFILEOPSTRUCTA sos;

        ::lstrcpyA(&buff[0], from);
        buff[cch + 1] = '\0';

        flags   &=  ~(FOF_WANTMAPPINGHANDLE);
        flags   |=  static_cast<FILEOP_FLAGS>((NULL == progressTitle) ? 0 : FOF_SIMPLEPROGRESS);

        sos.hwnd                    =   hwnd;
        sos.wFunc                   =   FO_DELETE;
        sos.pFrom                   =   buff.data();
        sos.pTo                     =   NULL;
        sos.fFlags                  =   flags;
        sos.fAnyOperationsAborted   =   false;
        sos.hNameMappings           =   NULL;
        sos.lpszProgressTitle       =   progressTitle;

        int res =   ::SHFileOperationA(&sos);

        if (0 == res)
        {
            if (NULL != pbAborted)
            {
                *pbAborted = (FALSE != sos.fAnyOperationsAborted);
            }
        }

        return res;
    }
}

inline
int
shell_delete_w_(
    HWND                hwnd
,   ws_char_w_t const*  from
,   ws_char_w_t const*  progressTitle
,   FILEOP_FLAGS        flags
,   ws_bool_t*          pbAborted
)
{
    WINSTL_MESSAGE_ASSERT("Null string cannot be specified", NULL != from);

    typedef auto_buffer<ws_char_w_t, 2 + WINSTL_CONST_MAX_PATH, shell_allocator<ws_char_w_t> >  buffer_t;

    ws_size_t   cch =   static_cast<ws_size_t>(::lstrlenW(from));
    buffer_t    buff(1 + cch + 1);

    if (buff.empty())
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_NOT_ENOUGH_MEMORY);

        return ERROR_NOT_ENOUGH_MEMORY;
    }
    else
    {
        SHFILEOPSTRUCTW sos;

        ::lstrcpyW(&buff[0], from);
        buff[cch + 1] = '\0';

        flags   &=  ~(FOF_WANTMAPPINGHANDLE);
        flags   |=  static_cast<FILEOP_FLAGS>((NULL == progressTitle) ? 0 : FOF_SIMPLEPROGRESS);

        sos.hwnd                    =   hwnd;
        sos.wFunc                   =   FO_DELETE;
        sos.pFrom                   =   buff.data();
        sos.pTo                     =   NULL;
        sos.fFlags                  =   flags;
        sos.fAnyOperationsAborted   =   false;
        sos.hNameMappings           =   NULL;
        sos.lpszProgressTitle       =   progressTitle;

        int res =   ::SHFileOperationW(&sos);

        if (0 == res)
        {
            if (NULL != pbAborted)
            {
                *pbAborted = (FALSE != sos.fAnyOperationsAborted);
            }
        }

        return res;
    }
}
} // namespace ximpl_winstl_shell_functions_
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_a_t const* from
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(NULL, from, NULL, 0, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_a_t const*  from
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(NULL, from, NULL, 0, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param flags One or more of the FILEOP_FLAGS values.
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored.
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_a_t const*  from
,   FILEOP_FLAGS        flags
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(NULL, from, NULL, flags, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param flags One or more of the FILEOP_FLAGS values.
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_a_t const*  from
,   FILEOP_FLAGS        flags
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(NULL, from, NULL, flags, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_a_t const*  from
,   ws_char_a_t const*  progressTitle
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(NULL, from, progressTitle, 0, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_a_t const*  from
,   ws_char_a_t const*  progressTitle
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(NULL, from, progressTitle, 0, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param flags One or more of the FILEOP_FLAGS values.
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored. The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_a_t const*  from
,   ws_char_a_t const*  progressTitle
,   FILEOP_FLAGS        flags
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(NULL, from, progressTitle, flags, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param flags One or more of the FILEOP_FLAGS values.
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored. The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_a_t const*  from
,   ws_char_a_t const*  progressTitle
,   FILEOP_FLAGS        flags
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(NULL, from, progressTitle, flags, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_a_t const*  from
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(hwnd, from, NULL, 0, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_a_t const*  from
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(hwnd, from, NULL, 0, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param flags One or more of the FILEOP_FLAGS values.
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored.
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_a_t const*  from
,   FILEOP_FLAGS        flags
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(hwnd, from, NULL, flags, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param flags One or more of the FILEOP_FLAGS values.
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored.
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_a_t const*  from
,   FILEOP_FLAGS        flags
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(hwnd, from, NULL, flags, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_a_t const*  from
,   ws_char_a_t const*  progressTitle
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(hwnd, from, progressTitle, 0, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_a_t const*  from
,   ws_char_a_t const*  progressTitle
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(hwnd, from, progressTitle, 0, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param flags One or more of the FILEOP_FLAGS values.
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored. The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_a_t const*  from
,   ws_char_a_t const*  progressTitle
,   FILEOP_FLAGS        flags
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(hwnd, from, progressTitle, flags, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param flags One or more of the FILEOP_FLAGS values.
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored. The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_a_t const*  from
,   ws_char_a_t const*  progressTitle
,   FILEOP_FLAGS        flags
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_a_(hwnd, from, progressTitle, flags, &bAborted);
}



/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_w_t const* from
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(NULL, from, NULL, 0, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_w_t const*  from
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(NULL, from, NULL, 0, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param flags One or more of the FILEOP_FLAGS values.
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored.
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_w_t const*  from
,   FILEOP_FLAGS        flags
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(NULL, from, NULL, flags, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param flags One or more of the FILEOP_FLAGS values.
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_w_t const*  from
,   FILEOP_FLAGS        flags
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(NULL, from, NULL, flags, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_w_t const*  from
,   ws_char_w_t const*  progressTitle
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(NULL, from, progressTitle, 0, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_w_t const*  from
,   ws_char_w_t const*  progressTitle
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(NULL, from, progressTitle, 0, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param flags One or more of the FILEOP_FLAGS values.
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored. The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_w_t const*  from
,   ws_char_w_t const*  progressTitle
,   FILEOP_FLAGS        flags
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(NULL, from, progressTitle, flags, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param flags One or more of the FILEOP_FLAGS values.
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored. The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    ws_char_w_t const*  from
,   ws_char_w_t const*  progressTitle
,   FILEOP_FLAGS        flags
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(NULL, from, progressTitle, flags, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_w_t const*  from
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(hwnd, from, NULL, 0, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_w_t const*  from
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(hwnd, from, NULL, 0, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param flags One or more of the FILEOP_FLAGS values.
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored.
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_w_t const*  from
,   FILEOP_FLAGS        flags
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(hwnd, from, NULL, flags, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param flags One or more of the FILEOP_FLAGS values.
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored.
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_w_t const*  from
,   FILEOP_FLAGS        flags
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(hwnd, from, NULL, flags, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_w_t const*  from
,   ws_char_w_t const*  progressTitle
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(hwnd, from, progressTitle, 0, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_w_t const*  from
,   ws_char_w_t const*  progressTitle
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(hwnd, from, progressTitle, 0, &bAborted);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param flags One or more of the FILEOP_FLAGS values.
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored. The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_w_t const*  from
,   ws_char_w_t const*  progressTitle
,   FILEOP_FLAGS        flags
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(hwnd, from, progressTitle, flags, NULL);
}

/** Requests the shell to delete the given file
 *
 * \ingroup group__library__Windows_Shell
 *
 * \param hwnd Handle to the window that will act as the parent to any dialogs displayed
 * \param from The file to delete
 * \param progressTitle String to be displayed describing the operation
 * \param flags One or more of the FILEOP_FLAGS values.
 * \param bAborted A Boolean that will indicate whether the operation was aborted
 *
 * \note Throws std::bad_alloc on allocation failure on translators that support it
 *
 * \note The FOF_WANTMAPPINGHANDLE flag is always ignored. The flag FOF_SIMPLEPROGRESS is automatically added if progressTitle is non-\c nullptr
 *
 * \return A status code indicating the success of the operation
 *
 * \retval 0 The operation completed successfully
 * \retval ERROR_NOT_ENOUGH_MEMORY This is returned only when compiling with translators that do not support throwing std::bad_alloc on memory allocation failure
 * \retval !0 Any other Win32 error code
 */
inline
int
shell_delete(
    HWND                hwnd
,   ws_char_w_t const*  from
,   ws_char_w_t const*  progressTitle
,   FILEOP_FLAGS        flags
,   ws_bool_t&          bAborted
)
{
    using namespace ximpl_winstl_shell_functions_;

    return shell_delete_w_(hwnd, from, progressTitle, flags, &bAborted);
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SHELL_HPP_FILE_OPERATIONS */

/* ///////////////////////////// end of file //////////////////////////// */

