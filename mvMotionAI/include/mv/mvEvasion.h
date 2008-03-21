#ifndef MVEVASION_H_INCLUDED
#define MVEVASION_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_ENUMS_HEADER_FILE_H_
#include MV_BASE_ACTION_HEADER_FILE_H_

/**
 * \class mvEvasion
 * \brief derived mvBaseAction - randomly moves away from a moving body
 */
class mvEvasion : public mvBaseAction
{
   private:
      mvFloat m_wanderRadius;
      mvFloat m_wanderLength;
      mvIndex m_pursuingBody;

   public:
      mvEvasion();
      ~mvEvasion();
      virtual mvErrorEnum getParameteri(mvParamEnum paramFlag,\
         mvIndex* index) const;
      virtual mvErrorEnum getParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      virtual mvErrorEnum setParameteri(mvParamEnum paramFlag,\
         mvIndex index);
      virtual mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
	   virtual bool groupOp(mvGroupBehaviourResultPtr resultModule);
      virtual bool bodyOp(mvBehaviourResultPtr resultModule);
};

#endif // MVEVASION_H_INCLUDED
