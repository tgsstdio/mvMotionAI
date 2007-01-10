#ifndef MVBENTRY_H_INCLUDED
#define MVBENTRY_H_INCLUDED

class mvBEntry
{
   public:
      mvBaseBehaviour* behaviourPtr;
      mvIndex groupIndex;
      mvIndex behaviourIndex;
      mvOptionEnum entryType;

      mvBEntry(mvOptionEnum type, mvIndex bIndex, mvIndex gIndex,\
         mvBaseBehaviour* dBehaviour);
      void setBehaviourPtr(mvBaseBehaviour* behavPtr);
      mvBaseBehaviour* getBehaviourPtr() const;

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters);

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);
      ~mvBEntry();
};

#endif // MVBENTRY_H_INCLUDED
