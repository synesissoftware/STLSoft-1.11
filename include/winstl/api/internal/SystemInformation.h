/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/api/internal/SystemInformation.h
 *
 * Purpose: Internal preprocessor aliases for internal Windows' System
 *          Information Functions API.
 *
 * Created: 24th December 2016
 * Updated: 25th May 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2025, Matthew Wilson and Synesis Information Systems
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


/* WARNING: this file contains undocumented internal features that are
 * subject to change at any time, so if you use them it is at your own risk.
 */

#ifndef WINSTL_INCL_WINSTL_API_internal_h_SystemInformation
#define WINSTL_INCL_WINSTL_API_internal_h_SystemInformation


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_MemoryManagement
# include <winstl/api/external/MemoryManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_MemoryManagement */
#ifndef WINSTL_INCL_WINSTL_API_external_h_SystemInformation
# include <winstl/api/external/SystemInformation.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_SystemInformation */


/* /////////////////////////////////////////////////////////////////////////
 * Windows' System Information Functions
 */


/** T.B.C.
 *
 * \return The number of characters written if cchFilename is sufficient to
 *  hold the entire string; the number of characters required (including for
 *  terminating NUL character) if not
 */
STLSOFT_INLINE
DWORD
WINSTL_API_INTERNAL_SystemInformation_GetWindowsDirectoryA(
    CHAR    buff[]
,   DWORD   cchBuff
) STLSOFT_NOEXCEPT
{
    DWORD const n = WINSTL_API_EXTERNAL_SystemInformation_GetWindowsDirectoryA(buff, cchBuff);

    if (n > cchBuff)
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_INSUFFICIENT_BUFFER);

        if (0 != cchBuff)
        {
            buff[0] = '\0';
        }
    }

    return n;
}

/** T.B.C.
 *
 * \return The number of characters written if cchFilename is sufficient to
 *  hold the entire string; the number of characters required (including for
 *  terminating NUL character) if not
 */
STLSOFT_INLINE
DWORD
WINSTL_API_INTERNAL_SystemInformation_GetWindowsDirectoryW(
    WCHAR   buff[]
,   DWORD   cchBuff
) STLSOFT_NOEXCEPT
{
    DWORD const n = WINSTL_API_EXTERNAL_SystemInformation_GetWindowsDirectoryW(buff, cchBuff);

    if (n > cchBuff)
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_INSUFFICIENT_BUFFER);

        if (0 != cchBuff)
        {
            buff[0] = L'\0';
        }
    }

    return n;
}


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_API_internal_h_SystemInformation */

/* ///////////////////////////// end of file //////////////////////////// */

