/**
 * \file TEMPLATE IMPLEMENTATION of mvFactoryFunctionrList.h
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
 *  using HPP file for template implementation
 */
template <class mvClassFactory, class mvClass, class mvParamClass>
mvFactoryFunctionList<mvClassFactory,mvClass,mvParamClass>\
   ::mvFactoryFunctionList()
{
   noOfValidFunctions = 0;
}

template <class mvClassFactory, class mvClass, class mvParamClass>
mvErrorEnum mvFactoryFunctionList<mvClassFactory,mvClass,mvParamClass>\
   ::addFactoryFunction(mvOptionEnum key, mvClassFactory* cFactoryPtr)
{
   // check if behaviour key exists
   class std::map<mvOptionEnum,mvClassFactory*>::iterator checkKey;

   // if loader is null, return error
   if (cFactoryPtr == MV_NULL)
   {
      return MV_FUNCTION_LOADER_IS_NULL;
   }

   checkKey = fFunctions.find(key);

   // if found key exist in map, return false
   if (checkKey != fFunctions.end())
   {
      return  MV_INVALID_FUNCTION_LOADER_INITIALIZATION;
   }

   fFunctions.insert(std::make_pair(key, cFactoryPtr));
   ++noOfValidFunctions;

   return MV_NO_ERROR;
}

template <class mvClassFactory, class mvClass, class mvParamClass>
void mvFactoryFunctionList<mvClassFactory,mvClass,mvParamClass>::\
   freeAllFactoryFunctions()
{
   class std::map<mvOptionEnum,mvClassFactory*>::iterator i;
   class std::map<mvOptionEnum,mvClassFactory*>::iterator mapEnd;

   mapEnd = fFunctions.end();
   for (i = fFunctions.begin(); i != mapEnd; ++i)
   {
      delete i->second;
      i->second = MV_NULL;
   }
   noOfValidFunctions = 0;
   fFunctions.clear();
}

template <class mvClassFactory, class mvClass, class mvParamClass>
mvClass* mvFactoryFunctionList<mvClassFactory,mvClass,mvParamClass>\
   ::createAClassPtr(mvOptionEnum key, mvParamClass defaultClass)
{
   // check if behaviour key exists
   class std::map<mvOptionEnum,mvClassFactory*>::iterator checkKey;
   mvClassFactory* fFunc = MV_NULL;

   checkKey = fFunctions.find(key);

   if (checkKey == fFunctions.end())
   {
      return MV_NULL;
   }

   fFunc = checkKey->second;
   if (fFunc != MV_NULL)
      return (*fFunc)(defaultClass);
   else
      return MV_NULL;
}

template <class mvClassFactory, class mvClass, class mvParamClass>
mvFactoryFunctionList<mvClassFactory,mvClass,mvParamClass>\
   ::~mvFactoryFunctionList()
{
   freeAllFactoryFunctions();
   noOfValidFunctions = 0;
}
