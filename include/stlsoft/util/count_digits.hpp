/* STLSOFT:FILE_DEPRECATED */

#include <stlsoft/stlsoft.h>

#if _STLSOFT_VER >= 0x010c0000
# error This file is now obsolete. Instead include the precise header file that you require
#else

# ifndef _STLSOFT_SUPPRESS_WARNING_IN_OBSOLETE_FILES
#  ifdef STLSOFT_PPF_pragma_message_SUPPORT
#   pragma message(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) "): This file is now obsolete and will be removed in a forthcoming version. Instead include the precise header file that you require")
#  endif
# endif

# include <stlsoft/util/count_digits.h>

# ifdef __cplusplus

/* /////////////////////////////////////////////////////////////////////////
 * API functions (C++ obsolete)
 */

#  ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#  endif /* STLSOFT_NO_NAMESPACE */

/** Counts the number of decimal digits in \c i
 */
inline
size_t
count_digits(
    ss_uint8_t i
)
{
    return count_decimal_digits(i);
}

/** Counts the number of decimal digits in \c i
 */
inline
size_t
count_digits(
    ss_uint16_t i
)
{
    return count_decimal_digits(i);
}

/** Counts the number of decimal digits in \c i
 */
inline
size_t
count_digits(
    ss_uint32_t i
)
{
    return count_decimal_digits(i);
}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE

/** Counts the number of decimal digits in \c i
 */
inline
size_t
count_digits(
    unsigned int i
)
{
    return count_decimal_digits(i);
}

#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

/** Counts the number of decimal digits in \c i
 */
inline
size_t
count_digits(
    ss_uint64_t const& i
)
{
    return count_decimal_digits(i);
}


#  ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#  endif /* STLSOFT_NO_NAMESPACE */
# endif /* __cplusplus */
#endif

/* ///////////////////////////// end of file //////////////////////////// */

