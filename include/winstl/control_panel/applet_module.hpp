/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/control_panel/applet_module.hpp
 *
 * Purpose: Control Panel module/applet manipulation classes.
 *
 * Created: 1st April 2006
 * Updated: 20th March 2025
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/control_panel/applet_module.hpp
 *
 * \brief [C++] Definition of the
 *  \link winstl::applet applet\endlink
 *  and
 *  \link winstl::applet_module applet_module\endlink
 *  classes
 *   (\ref group__library__Windows_ControlPanel "Windows Control Panel" Library).
 */

#ifndef WINSTL_INCL_WINSTL_CONTROL_PANEL_HPP_APPLET_MODULE
#define WINSTL_INCL_WINSTL_CONTROL_PANEL_HPP_APPLET_MODULE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CONTROL_PANEL_HPP_APPLET_MODULE_MAJOR    1
# define WINSTL_VER_WINSTL_CONTROL_PANEL_HPP_APPLET_MODULE_MINOR    1
# define WINSTL_VER_WINSTL_CONTROL_PANEL_HPP_APPLET_MODULE_REVISION 25
# define WINSTL_VER_WINSTL_CONTROL_PANEL_HPP_APPLET_MODULE_EDIT     49
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_CONTROL_PANEL_H_FUNCTIONS
# include <winstl/control_panel/functions.h>
#endif /* !WINSTL_INCL_WINSTL_CONTROL_PANEL_H_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_CONTROL_PANEL_ERROR_HPP_EXCEPTIONS
# include <winstl/control_panel/error/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_CONTROL_PANEL_ERROR_HPP_EXCEPTIONS */
#ifndef WINSTL_INCL_WINSTL_STRING_HPP_RESOURCE_STRING
# include <winstl/string/resource_string.hpp>
#endif /* !WINSTL_INCL_WINSTL_STRING_HPP_RESOURCE_STRING */
#ifndef WINSTL_INCL_WINSTL_DL_HPP_MODULE
# include <winstl/dl/module.hpp>
#endif /* !WINSTL_INCL_WINSTL_DL_HPP_MODULE */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
# include <stlsoft/string/simple_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */

#ifndef STLSOFT_INCL_VECTOR
# define STLSOFT_INCL_VECTOR
# include <vector>
#endif /* !STLSOFT_INCL_VECTOR */

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
 * forward declarations
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
class applet_module;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** [IMPLEMENTATION]
 */
struct applet_module_base
{
    HINSTANCE   m_hinst;
    APPLET_PROC m_pfn;
    HWND        m_hwnd;
    int         m_flags;

public:
    applet_module_base()
        : m_hinst(NULL)
        , m_pfn(NULL)
        , m_hwnd(NULL)
        , m_flags(0)
    {}
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Represents a Control Panel Applet
 *
 * \ingroup group__library__Windows_ControlPanel
 *
 * Instances of this class are managed by the applet_module class, and
 * available by its subscript operator. For example, the following code
 * retrieves a reference to the first applet and invokes it:
\code
winstl::applet_module&  am  = . . . ;
winstl::applet&         applet0 = am[0];

applet0.open();
\endcode
 *
 */
class applet
{
/// \name Member Types
/// @{
public:
    /// The type of this class
    typedef applet                                          class_type;
    /// The string type
    typedef STLSOFT_NS_QUAL(basic_simple_string)<TCHAR>     string_type;
    /// The index type
    typedef ss_size_t                                       index_type;
private:
    typedef basic_resource_string<
        string_type
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    ,   resource_exception_policy
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    ,   STLSOFT_NS_QUAL(null_exception_policy)
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    >                                                       resource_string_type_;
/// @}

/// \name Construction
/// @{
private:
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    friend class applet_module;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    applet(
        applet_module_base* am
    ,   index_type          index
    );
public:
    /** Releases any resources associated with the instance.
     */
    ~applet() STLSOFT_NOEXCEPT;
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Operations
/// @{
public:
    /** Invokes the applet, with the given window, if specified,
     *   as the dialog parent.
     *
     * \param hwnd [in] Handle to a window that will act as the parent
     *  window for the applet dialog.
     */
    void            open(HWND hwnd = NULL);
    /** Invokes the applet passing a parameter string, with the
     *   given window, if specified, as the dialog parent.
     *
     * \param hwnd [in] Handle to a window that will act as the parent
     *  window for the applet dialog.
     * \param arguments [in] Arguments to pass to the applet.
     */
    void            open(HWND hwnd, TCHAR const* arguments);
/// @}

/// \name Attributes
/// @{
public:
    /// The index of the applet in the containing applet module
    index_type      get_index() const;
    /// The applet name
    string_type     get_name() const;
    /// The description of the applet
    string_type     get_description() const;
    /// The icon associated with the applet
    HICON           get_icon() const;
    /// The user-date, if any, associated with the applet.
    LPARAM          get_data() const;
/// @}

/// \name Members
/// @{
private:
    applet_module_base* const   m_module;
    index_type const            m_index;
    HICON                       m_icon;
    string_type                 m_name;
    string_type                 m_description;
    LPARAM                      m_data;
/// @}
};

/** Represents a Control Panel Applet module, and provides methods
 *   for loading and accessing applets.
 *
 * The following code enumerates all the applet modules in the Windows
 * system directory, and prints out the name and description of each
 * applet contained within.
 *
\code
#include <winstl/filesystem/findfile_sequence.hpp>
#include <winstl/system/system_directory.hpp>
#include <winstl/control_panel/applet_module.hpp>

#include <iostream>

int main()
{
  try
  {
    winstl::system_directory    sysDir;
    winstl::findfile_sequence   files(sysDir, "*.cpl", winstl::findfile_sequence::files);

    { for (winstl::findfile_sequence::const_iterator b = files.begin(); b != files.end(); ++b)
    {
      winstl::applet_module am(*b, winstl::applet_module:dontExpectNonZeroInit);

      winstl::applet_module::const_iterator b = am.begin();
      winstl::applet_module::const_iterator e = am.end();

      std::cout << "path:          " << am.get_path() << std::endl;
      for (; b != e; ++b)
      {
        winstl::applet const  &applet = *b;

        std::cout << " applet index: " << applet.get_index() << std::endl;

        std::cout << "  name:        " << applet.get_name() << std::endl;
        std::cout << "  description: " << applet.get_description() << std::endl;
      }
      std::cout << std::endl;
    }}
  }
  catch (std::exception &x)
  {
    std::cerr << "Exception: " << x.what() << std::endl;
  }

  return 0;
}
\endcode
 *
 * Note the use of the
 * \link winstl::applet_module::load_flags dontExpectNonZeroInit\endlink
 * flag, which is recommended because several common control panel
 * modules do not correctly implement their CPL_INIT handlers.
 *
 * \ingroup group__library__Windows_ControlPanel
 */
class applet_module
#if defined(STLSOFT_COMPILER_IS_DMC)
    : public applet_module_base
#else /* ? compiler */
    : private applet_module_base
#endif /* compiler */
{
/// \name Member Types
/// @{
public:
    /// The type of this class
    typedef applet_module                               class_type;
    /// The value type
    typedef applet                                      value_type;
    /// The size type
    typedef ss_size_t                                   size_type;
    /// The index type
    typedef ss_size_t                                   index_type;
    /// The string type
    typedef STLSOFT_NS_QUAL(basic_simple_string)<TCHAR> string_type;
private:
    typedef STLSOFT_NS_QUAL_STD(vector)<value_type>     applets_type_;
public:
    /// The mutating (non-const) iterator type
    typedef applets_type_::iterator                     iterator;
    /// The non-mutating (const) iterator type
    typedef applets_type_::const_iterator               const_iterator;

#ifdef STLSOFT_CF_CDECL_SUPPORTED
    /// Prototype of <b>cdecl</b> function that receives error notifications.
    typedef void (STLSOFT_CDECL *onFailureC)(TCHAR const* path);
#endif
#ifdef STLSOFT_CF_STDCALL_SUPPORTED
    /// Prototype of <b>stdcall</b> function that receives error notifications.
    typedef void (STLSOFT_STDCALL *onFailureS)(TCHAR const* path);
#endif
private:
    struct error_translator
    {
    public:
        error_translator();
#ifdef STLSOFT_CF_CDECL_SUPPORTED
        error_translator(onFailureC pfn);
#endif
#ifdef STLSOFT_CF_STDCALL_SUPPORTED
        error_translator(onFailureS pfn);
#endif

    private:
        static void STLSOFT_CDECL on_failure(TCHAR const* path);

    private:
        int             cc; // One of STLSOFT_CDECL_VALUE or STLSOFT_STDCALL_VALUE
        union
        {
#ifdef STLSOFT_CF_CDECL_SUPPORTED
            onFailureC  pfnC;
#endif
#ifdef STLSOFT_CF_STDCALL_SUPPORTED
            onFailureS  pfnS;
#endif
        };
    };
/// @}

/// \name Member Constants
/// @{
public:
    /// Flags that moderate the load behaviour.
    enum load_flags
    {
            ignoreIconLoadFailures  =   0x0001  //!< Ignores icon load failures and continues applet loading.
        ,   dontExpectNonZeroInit   =   0x0002  //!< Some applet module entry points don't return 0.
        ,   assumeOneAppletIfNone   =   0x0004  //!< Some applet module entry points return 0 from CPL_GETCOUNT.
    };
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance containing all the applets in the
    ///  given module.
    ///
    /// \param path [in] Path of the applet module.
    /// \param flags [in] Flags that moderate the loading behaviour.
    /// \param hwndParent [in] Handle to a window to act as the parent for
    ///  the dialog(s) of the applet(s) contained in the module
    ///
    /// \exception winstl::control_panel_exception Thrown if the applet module
    ///  initialisation fails.
    /// \exception winstl::resource_exception Thrown if the icon cannot be loaded
    ///  for a given applet, and
    ///  \link applet_module::load_flags ignoreIconLoadFailures\endlink.
    ss_explicit_k applet_module(TCHAR const* path, int flags = ignoreIconLoadFailures, HWND hwndParent = NULL);
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# ifdef STLSOFT_CF_CDECL_SUPPORTED
    ss_explicit_k applet_module(TCHAR const* path, onFailureC pfn, int flags = ignoreIconLoadFailures, HWND hwndParent = NULL);
# endif
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
    ss_explicit_k applet_module(TCHAR const* path, onFailureS pfn, int flags = ignoreIconLoadFailures, HWND hwndParent = NULL);
# endif
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
private:
    applet_module(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;
/// @}

/// \name Attributes
/// @{
public:
    /// The path used to initialise the instance.
    string_type const&  get_path() const;
/// @}

/// \name Accessors
/// @{
public:
    /// The number of applets in the module.
    size_type           size() const;
    /// Returns a mutable (non-const) reference to the applet at the index.
    ///
    /// \param index [in] Applet index
    ///
    /// \note The behaviour is undefined if index >= size()
    value_type&         operator [](index_type index);
    /// Returns a non-mutable (const) reference to the applet at the index.
    ///
    /// \param index [in] Applet index
    ///
    /// \note The behaviour is undefined if index >= size()
    value_type const&   operator [](index_type index) const;
/// @}

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    iterator        begin();
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    iterator        end();
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const;
/// @}

/// \name Implementation
/// @{
private:
    void init_(int flags, HWND hwndParent);
/// @}

/// \name Members
/// @{
private:
    const string_type   m_path;
    dl_module           m_module;
    applets_type_       m_applets;
    error_translator    m_errorTranslator;
/// @}
};


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// applet

inline applet::applet(applet_module_base* am, applet::index_type index)
    : m_module(am)
    , m_index(index)
    , m_icon(NULL)
    , m_name()
    , m_description()
    , m_data(0)
{
    WINSTL_ASSERT(NULL != am);
    WINSTL_ASSERT(0 == index || index < control_panel_get_count(m_module->m_pfn, m_module->m_hwnd));

    WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(0);

    if (!control_panel_init(m_module->m_pfn, m_module->m_hwnd) &&
        0 == (m_module->m_flags & applet_module::dontExpectNonZeroInit))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(control_panel_exception("Applet initialisation failed", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_DLL_INIT_FAILED);

        m_module = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            CPLINFO info = { CPL_DYNAMIC_RES, CPL_DYNAMIC_RES, CPL_DYNAMIC_RES, 0 };

            control_panel_inquire(m_module->m_pfn, m_module->m_hwnd, m_index, &info);

            if (CPL_DYNAMIC_RES != info.idIcon)
            {
                m_icon = ::LoadIcon(m_module->m_hinst, MAKEINTRESOURCE(info.idIcon));

                if (NULL == m_icon &&
                    applet_module::ignoreIconLoadFailures == (m_module->m_flags & applet_module::ignoreIconLoadFailures))
                {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                    STLSOFT_THROW_X(resource_exception("Could not load the applet icon", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError(), MAKEINTRESOURCE(info.idIcon), RT_ICON));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                }
            }

            if (CPL_DYNAMIC_RES != info.idName)
            {
                m_name = resource_string_type_(m_module->m_hinst, info.idName);
            }

            if (CPL_DYNAMIC_RES != info.idInfo)
            {
                m_description = resource_string_type_(m_module->m_hinst, info.idInfo);
            }

            m_data = info.lData;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        }
        catch (...)
        {
            control_panel_uninit(m_module->m_pfn, m_module->m_hwnd);

            throw;
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

inline applet::~applet() STLSOFT_NOEXCEPT
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != m_module);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    if (NULL != NULL)
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    {
        control_panel_uninit(m_module->m_pfn, m_module->m_hwnd);
    }
}

inline void applet::open(HWND hwnd)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != m_module);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    if (NULL != NULL)
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    {
        if (NULL == hwnd)
        {
            hwnd = m_module->m_hwnd;
        }

        control_panel_run(m_module->m_pfn, hwnd, m_index, m_data);
    }
}

inline void applet::open(HWND hwnd, TCHAR const* arguments)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != m_module);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    if (NULL != NULL)
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    {
        if (NULL == arguments ||
            '\0' == *arguments)
        {
            this->open(hwnd);
        }
        else
        {
            if (NULL == hwnd)
            {
                hwnd = m_module->m_hwnd;
            }

            control_panel_run(m_module->m_pfn, hwnd, m_index, arguments);
        }
    }
}

inline applet::index_type applet::get_index() const
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != m_module);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    if (NULL == m_module)
    {
        return ~index_type(0);
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    return m_index;
}

inline applet::string_type applet::get_name() const
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != m_module);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    if (NULL == m_module)
    {
        return m_name;
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    if (m_name.empty())
    {
        NEWCPLINFO  info    =   { sizeof(info), 0, 0, 0, NULL, { '\0' }, { '\0' }, { '\0' } };

        control_panel_newinquire(m_module->m_pfn, m_module->m_hwnd, m_index, &info);

        return info.szName;
    }

    return m_name;
}

inline applet::string_type applet::get_description() const
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != m_module);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    if (NULL == m_module)
    {
        return m_description;
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    if (m_description.empty())
    {
        NEWCPLINFO  info    =   { sizeof(info), 0, 0, 0, NULL, { '\0' }, { '\0' }, { '\0' } };

        control_panel_newinquire(m_module->m_pfn, m_module->m_hwnd, m_index, &info);

        return info.szInfo;
    }

    return m_description;
}

inline HICON applet::get_icon() const
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != m_module);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    if (NULL == m_module)
    {
        return NULL;
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    if (NULL == m_icon)
    {
        NEWCPLINFO  info    =   { sizeof(info), 0, 0, 0, NULL, { '\0' }, { '\0' }, { '\0' } };

        control_panel_newinquire(m_module->m_pfn, m_module->m_hwnd, m_index, &info);

        return info.hIcon;
    }

    return m_icon;
}

inline
LPARAM
applet::get_data() const
{
    return m_data;
}

// applet_module::error_translator

inline applet_module::error_translator::error_translator()
    : cc(STLSOFT_CDECL_VALUE)
{
    pfnC    =   on_failure;
}

#ifdef STLSOFT_CF_CDECL_SUPPORTED
inline applet_module::error_translator::error_translator(applet_module::onFailureC pfn)
    : cc(STLSOFT_CDECL_VALUE)
{
    pfnC    =   pfn;
}
#endif

#ifdef STLSOFT_CF_STDCALL_SUPPORTED
inline applet_module::error_translator::error_translator(applet_module::onFailureS pfn)
    : cc(STLSOFT_STDCALL_VALUE)
{
    pfnS    =   pfn;
}
#endif

inline /* static */ void STLSOFT_CDECL applet_module::error_translator::on_failure(TCHAR const*  /* path */)
{}

// applet_module

inline void applet_module::init_(int flags, HWND hwndParent)
{
    WINSTL_ASSERT(NULL == m_hwnd);
    WINSTL_ASSERT(NULL == m_pfn);

    WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(0);

    if (NULL == m_module.get_symbol("CPlApplet", m_pfn))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(control_panel_exception("Control panel entry point not found", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else
    {
        m_flags =   flags;
        m_hwnd  =   hwndParent;
        m_hinst =   m_module.get_module_handle();

        size_type numApplets  =   control_panel_get_count(m_pfn, m_hwnd);

        if (0 == numApplets &&
            assumeOneAppletIfNone == (m_flags & assumeOneAppletIfNone))
        {
            numApplets = 1;
        }

        { for (size_type index = 0; index != numApplets; ++index)
        {
            m_applets.push_back(applet(this, index));
        }}
    }
}

inline applet_module::applet_module(TCHAR const* path, int flags /* = ignoreIconLoadFailures */, HWND hwndParent /* = NULL */)
    : m_path(path)
    , m_module(path)
    , m_applets()
    , m_errorTranslator()
{
    init_(flags, hwndParent);
}

#ifdef STLSOFT_CF_CDECL_SUPPORTED
inline applet_module::applet_module(TCHAR const* path, applet_module::onFailureC pfn, int flags /* = ignoreIconLoadFailures */, HWND hwndParent /* = NULL */)
    : m_path(path)
    , m_module(path)
    , m_applets()
    , m_errorTranslator(pfn)
{
    init_(flags, hwndParent);
}
#endif

#ifdef STLSOFT_CF_STDCALL_SUPPORTED
inline applet_module::applet_module(TCHAR const* path, applet_module::onFailureS pfn, int flags /* = ignoreIconLoadFailures */, HWND hwndParent /* = NULL */)
    : m_path(path)
    , m_module(path)
    , m_applets()
    , m_errorTranslator(pfn)
{
    init_(flags, hwndParent);
}
#endif

inline applet_module::string_type const& applet_module::get_path() const
{
    return m_path;
}

inline applet_module::size_type applet_module::size() const
{
    return m_applets.size();
}

inline applet_module::value_type &applet_module::operator [](index_type index)
{
    WINSTL_MESSAGE_ASSERT("Invalid index", index < size());

    return m_applets[index];
}

inline applet_module::value_type const& applet_module::operator [](index_type index) const
{
    WINSTL_MESSAGE_ASSERT("Invalid index", index < size());

    return m_applets[index];
}

inline applet_module::iterator applet_module::begin()
{
    return m_applets.begin();
}

inline applet_module::iterator applet_module::end()
{
    return m_applets.end();
}

inline applet_module::const_iterator applet_module::begin() const
{
    return m_applets.begin();
}

inline applet_module::const_iterator applet_module::end() const
{
    return m_applets.end();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !WINSTL_INCL_WINSTL_CONTROL_PANEL_HPP_APPLET_MODULE */

/* ///////////////////////////// end of file //////////////////////////// */

