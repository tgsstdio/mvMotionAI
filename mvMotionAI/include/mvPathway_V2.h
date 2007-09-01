#ifndef MVPATHWAY_V2_H_INCLUDED
#define MVPATHWAY_V2_H_INCLUDED

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

#include MV_ENUMS_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_
#include "mvPointerList.h"

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

class MV_GLOBAL_FUNC_PREFIX mvPathwayNode
{
   private:
      mvIndex nodeIndex;
      mvVec3* additionalPoints;
   public:
      mvPathwayNode(mvIndex pwNodeIndex);
      ~mvPathwayNode();
      mvIndex getNodeIndex() const;
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index) const;
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option)\
         const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters) const;

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

};

typedef mvPathwayNode* mvPathwayNodePtr;
typedef mvPathwayNode const * const mvConstPathwayNodePtr;

class MV_GLOBAL_FUNC_PREFIX mvPathway_V2
{
   public:
      bool isEnabled;
      mvPointerList<mvPathwayNodePtr, mvConstPathwayNodePtr> nodes;

      mvPathway_V2();
      mvIndex addNode(mvIndex pWaypoint);
      mvErrorEnum removeNodeAt(mvIndex nodeIndex);
      mvErrorEnum removeLastNodeInstance(mvIndex index);
      mvErrorEnum removeFirstNodeInstance(mvIndex index);
      mvCount getNoOfNodes() const;
      mvIndex setCurrentNode(mvIndex nIndex);

      mvIndex getCurrentNode() const;

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index) const;
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters) const;

      mvErrorEnum setNodeParameteri(mvIndex wpIndex, mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setNodeParameter(mvIndex wpIndex, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setNodeParameterf(mvIndex wpIndex, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setNodeParameterv(mvIndex wpIndex, mvParamEnum paramFlag,\
         mvFloat* numArray);

      mvErrorEnum getNodeParameteri(mvIndex wpIndex, mvParamEnum paramFlag,\
         mvIndex* index) const;
      mvErrorEnum getNodeParameter(mvIndex wpIndex, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getNodeParameterf(mvIndex wpIndex, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getNodeParameterv(mvIndex wpIndex, mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfParameters) const;


      mvErrorEnum getNodeParameteri_str(mvIndex nodeIndex, const char* param,\
         mvIndex* index) const;
      mvErrorEnum getNodeParameter_str(mvIndex nodeIndex, const char* param,\
         const char** option) const;
      mvErrorEnum getNodeParameterf_str(mvIndex nodeIndex, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getNodeParameterv_str(mvIndex nodeIndex, const char* param,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setNodeParameteri_str(mvIndex nodeIndex, const char* param,\
         mvIndex index);
      mvErrorEnum setNodeParameter_str(mvIndex nodeIndex, const char* param,\
         const char* option);
      mvErrorEnum setNodeParameterf_str(mvIndex nodeIndex, const char* param,\
         mvFloat num);
      mvErrorEnum setNodeParameterv_str(mvIndex nodeIndex, const char* param,\
         mvFloat* numArray);

      void removeAllNodes();
      ~mvPathway_V2();
};

#endif // MVPATHWAY_V2_H_INCLUDED
