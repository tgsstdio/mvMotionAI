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
 * Log
 * Version     Date
 * 00-01-31    20/1/07
 *
 * - changed function signatures & removed commented code
 *
 * 00-01-29    11/1/07
 *
 * - changing bodyOperation signature to 5+ parameters & return type to only one
 *   super class for result and input
 */
#ifndef MV_BASE_ACTION_H_
#define MV_BASE_ACTION_H_

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include MV_BEHAVIOUR_RESULT_HEADER_FILE_H_
#include MV_GROUP_BEHAVIOUR_RESULT_HEADER_FILE_H_

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

class MV_GLOBAL_FUNC_PREFIX mvBaseAction
{
   private:
      mvOptionEnum bType;

   public:
      mvBaseAction(mvOptionEnum type);
      mvOptionEnum getType() const;

      virtual mvErrorEnum getParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      virtual mvErrorEnum getParameteri(mvParamEnum paramFlag,\
         mvIndex* index) const;
      virtual mvErrorEnum getParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      virtual mvErrorEnum getParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfElements) const;

      virtual mvErrorEnum setParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      virtual mvErrorEnum setParameteri(mvParamEnum paramFlag,\
         mvIndex index);
      virtual mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      virtual mvErrorEnum setParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray);

      /** \brief user defined behaviour operation for single body
       * \param[inout] resultModule module for retrieve and setting motion
       * \return values true (perform) / false (break/ no operation)
       */
	   virtual bool groupOp(mvGroupBehaviourResultPtr resultModule) = 0;

      /** \brief user defined behaviour operation for group operation
       * \param[inout] resultModule module for retrieving and setting
       * cooperative variables
       * \return values true (perform) / false (break/ no operation)
       */
      virtual bool bodyOp(mvBehaviourResultPtr resultModule) = 0;

      virtual ~mvBaseAction();
};

class MV_GLOBAL_FUNC_PREFIX mvBaseActionLoader
{
   public:
      virtual mvBaseActionPtr operator()(\
         mvBaseActionPtr defaultBehaviour) = 0;
      mvBaseActionLoader();
      virtual ~mvBaseActionLoader(){};
};

#endif
