#ifndef MVFACTORYFUNCTIONLIST_H_INCLUDED
#define MVFACTORYFUNCTIONLIST_H_INCLUDED
#include "mvMotionAI-Types.h"

#ifdef MV_FILE_HEADER_TAG_
/**
 * Copyright (c) 2006, 2007 David Young.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#endif

#include <map>
#include MV_ENUMS_HEADER_FILE_H_

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

// derived template
template <class mvClassFactory, class mvClass, class mvParamClass>
class MV_GLOBAL_FUNC_PREFIX mvFactoryFunctionList
{
   private:
      mvCount noOfValidFunctions;
      std::map<mvOptionEnum,mvClassFactory*> fFunctions;

   public:
      mvFactoryFunctionList();
      mvErrorEnum addFactoryFunction(mvOptionEnum key,\
         mvClassFactory* cFactoryPtr);
      void freeAllFactoryFunctions();
      mvClass* createAClassPtr(mvOptionEnum key, mvParamClass defaultClass);
      ~mvFactoryFunctionList();
};

// implementation
#include "mvFactoryFunctionList.hpp"

#endif // MVFACTORYFUNCTIONLIST_H_INCLUDED
