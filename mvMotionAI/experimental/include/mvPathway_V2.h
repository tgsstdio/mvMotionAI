#ifndef MVPATHWAY_V2_H_INCLUDED
#define MVPATHWAY_V2_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_
#include "mvPointerList.h"

class mvPathwayNode
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

class mvPathway_V2
{
   public:
      mvPointerList<mvPathwayNodePtr, mvConstPathwayNodePtr> nodes;

      mvPathway_V2();
      mvIndex addNode(mvIndex pWaypoint);
      mvErrorEnum removeNodeAt(mvIndex nodeIndex);
      mvErrorEnum removeCurrentNode();
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

      mvErrorEnum setCurrentNodeParameteri(mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setCurrentNodeParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentNodeParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentNodeParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray);

      mvErrorEnum getCurrentNodeParameteri(mvParamEnum paramFlag,\
         mvIndex* index) const;
      mvErrorEnum getCurrentNodeParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getCurrentNodeParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getCurrentNodeParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      // parameter string functions

      mvErrorEnum getCurrentNodeParametersi(const char* param,\
         mvIndex* index) const;
      mvErrorEnum getCurrentNodeParameters(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentNodeParametersf(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentNodeParametersv(const char* param,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setCurrentNodeParametersi(const char* param,\
         mvIndex index);
      mvErrorEnum setCurrentNodeParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentNodeParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentNodeParametersv(const char* param,\
         mvFloat* numArray);

      mvErrorEnum getNodeParametersi(mvIndex nodeIndex, const char* param,\
         mvIndex* index) const;
      mvErrorEnum getNodeParameters(mvIndex nodeIndex, const char* param,\
         const char** option) const;
      mvErrorEnum getNodeParametersf(mvIndex nodeIndex, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getNodeParametersv(mvIndex nodeIndex, const char* param,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setNodeParametersi(mvIndex nodeIndex, const char* param,\
         mvIndex index);
      mvErrorEnum setNodeParameters(mvIndex nodeIndex, const char* param,\
         const char* option);
      mvErrorEnum setNodeParametersf(mvIndex nodeIndex, const char* param,\
         mvFloat num);
      mvErrorEnum setNodeParametersv(mvIndex nodeIndex, const char* param,\
         mvFloat* numArray);

      void removeAllNodes();
      ~mvPathway_V2();
};

#endif // MVPATHWAY_V2_H_INCLUDED
