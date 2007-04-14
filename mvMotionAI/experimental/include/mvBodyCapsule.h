#ifndef MVBODYCAPSULE_H_INCLUDED
#define MVBODYCAPSULE_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_BODY_HEADER_FILE_H_

class mvBodyCapsule
{
   protected:
      mvBodyPtr encapsulatedBody;
   public:
      mvVec3 futurePosition;
      mvVec3 futureFinalVelocity;
      mvVec3 futureRotation;

      mvBodyCapsule(mvBodyPtr capsuleBody);
      mvConstBodyPtr getConstBodyPtr() const;
      mvBodyPtr getBodyPtr() const;

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

      ~mvBodyCapsule();
};

typedef class mvBodyCapsule* mvBodyCapsulePtr;

#endif // MVBODYCAPSULE_H_INCLUDED
