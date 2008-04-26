// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _LFPE_CONFIG_H_
#define _LFPE_CONFIG_H_

//! Lightfeather Version
#define LFPEVERSION L"0.1.0"

#include <lf/LfConfig.h>



#if defined(_WIN32) && defined(_MSC_VER)
#  ifdef LFPE_EXPORTS
#    define LFPE_DLL_EXPORT __declspec(dllexport)
#    define LFPE_TEMPLATE_EXPORT __declspec(dllexport)
#  else
#    define LFPE_DLL_EXPORT __declspec(dllimport)
#    define LFPE_TEMPLATE_EXPORT
#  endif
#else
#  define LFPE_DLL_EXPORT
#  define LFPE_TEMPLATE_EXPORT
#endif // _WIN32


#endif // _LFPE_CONFIG_H_
