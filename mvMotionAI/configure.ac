#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ(2.50)
AC_INIT(mvMotionAI, 00-01-70, david.young.email@gmail.com)
AM_INIT_AUTOMAKE(mvMotionAI, 1.0)
AM_CONFIG_HEADER(config.h)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([limits.h stddef.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_C_VOLATILE
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_CHECK_FUNCS([floor modf sqrt fmod])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
AC_PROG_RANLIB