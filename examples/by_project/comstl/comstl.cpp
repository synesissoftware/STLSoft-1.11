
/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <comstl/conversion/interface_cast.hpp> // for comstl::interface_cast (step 2.1)
#include <comstl/util/guid.hpp>                 // for comstl::guid (step 2)
#include <comstl/util/creation_functions.hpp>   // for comstl::co_create_instance (step 2)
#include <comstl/util/initialisers.hpp>         // for comstl::com_init (step 1)
#include <comstl/util/variant.hpp>              // for comstl::variant (step 2.2)
#include <stlsoft/smartptr/ref_ptr.hpp>         // for stlsoft::ref_ptr (steps 2, 2.1 and 2.3)

#include "pantheios.COM.h"                      // for Pantheios.COM interfaces

#include <iostream>


const char PROCESS_IDENTITY[]   =   "comstl test program";


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main()
{
    try
    {
        // 1. The first thing we need to do is to initialise the COM
        // libraries. This is achieve by creating an instance of the
        // com_init class. Because failure is indicated by a throw
        // of comstl::com_initialisation_exception.
        comstl::com_init                init;

        // 2. Create an instance of a COM object. We do this using
        // an overload of comstl::co_create_instance(), which takes
        // a reference to an instance of a "wrapped" object pointer,
        // in the form of a specialisation of the STLSoft smart
        // pointer class template stlsoft::ref_ptr.
        //
        // co_create_instance() deduces the interface to query the
        // object for based on the specialisation of the smart
        // pointer type. In this case, that is IDispatch.
        //
        // The coclass created by co_create_instance() is specified
        // in its first parameter, either a GUID of the Class
        // Identifier (ClassId), or a string containing either the
        // Programmatic Identifier (ProgId) or the string form of
        // the ClassId. In this case, we're using the string form
        // of the ClassId of the Pantheios.COM LoggerManager coclass.
        //
        // Pantheios.COM is the COM mapping of Pantheios, the
        // ultimate C++ logging library; see http://pantheios.org/.
        // You must have downloaded and installed the latest
        // Pantheios.COM release to successfully run this example.
        comstl::guid                    guid("{4E7D5C47-8F96-45DE-905D-AA3E9E592DE3}");
        stlsoft::ref_ptr<IDispatch>     obj1;
        HRESULT                         hr  =   comstl::co_create_instance(guid.get(), obj1);

        if(FAILED(hr))
        {
            throw comstl::com_exception("Failed to create Pantheios.COM.LoggerManager", hr);
        }
        else
        {
            // 2.1. Now we illustrate the use of comstl::interface_cast()
            // cast function to cast (query) from an IDispatch to
            // the specific interface ILoggerManagerMultibyte.
            //
            // This interface is one of a set of "multibyte" interfaces
            // provided as a shortcut to the usual automation interfaces
            // (which are provided by all Pantheios.COM objects for their
            // primary scripting clients) for the rare occasions where
            // they are required in C or C++.
            //
            // If this fails, then it throws an instance of comstl::bad_interface_cast
            stlsoft::ref_ptr<ILoggerManagerMultibyte>   logMgr  =   comstl::interface_cast<ILoggerManagerMultibyte>(obj1);

            // 2.2 If we get this far, it means the COM object exhibits
            // the ILoggerManagerMultibyte interface, so we can start
            // calling methods on it directly. The next thing to do
            // is to get hold of a logger
            //
            // To do this we will need to pass in two VARIANT instances,
            // one for the initialisation arguments, and the other for
            // the filter specification.
            //
            // In both cases, we will use the comstl::variant classes.
            // The string used to construct initArguments requests
            // colours be on (which are on by default anyway), but that
            // severity is hidden.
            // The value 4 used to construct filterSpec instructs the
            // logger to filter out any message with a severity higher
            // than Warning (4) - Notice, Informational and Debug
            // messages are not displayed, as you can see if you execute
            // the example.
            comstl::variant     initArguments("showSeverity=no;showColours=yes");
            comstl::variant     filterSpec(4);
            ILoggerMultibyte    *plogmb;

            hr = logMgr->GetLoggerMultibyte("Console"
                                        ,   PROCESS_IDENTITY
                                        ,   initArguments
                                        ,   filterSpec
                                        ,   &plogmb);

            if(FAILED(hr))
            {
                throw comstl::com_exception("Failed to elicit 'Console' logger", hr);
            }
            else
            {
                // 2.3 In this case we need to use the two parameter constructor
                // of stlsoft::ref_ptr, passing in the interface pointer to the
                // logger instance just created for us, and the boolean literal
                // 'false', which indicates that we do *not* want a reference
                // taken on the interface. Thus, the logger instance consumes
                // the reference and becomes the owner of the logger instance.

                stlsoft::ref_ptr<ILoggerMultibyte>  logger(plogmb, false);  // Need to 'eat' the reference

                // 2.4 Now we just need to log some things
                struct
                {
                    long        severity;
                    char const* message;

                } messages[] =
                {
                        0,  "an emergency message"
                    ,   1,  "an alert message"
                    ,   2,  "a critical message"
                    ,   3,  "an error message"
                    ,   4,  "a warning message"
                    ,   5,  "a notice message"
                    ,   6,  "an informational message"
                    ,   7,  "a debug message"
                };

                { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS_(messages); ++i)
                {
                    logger->LogMultibyte(messages[i].severity, messages[i].message, -1);
                }}
            }
        }
    }
    catch (comstl::bad_interface_cast &x)
    {
        std::cerr << "Failed to 'cast' interface: " << x.what() << std::endl;
    }
    catch (comstl::com_initialisation_exception &x)
    {
        std::cerr << "Failed to initialise COM libraries: " << x.what() << std::endl;
    }
    catch (std::exception &x)
    {
        std::cerr << "Operation failed: " << x.what() << std::endl;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

