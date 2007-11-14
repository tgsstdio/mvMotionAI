/**
 * \file mvFollowPath.h
 *
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
 *
 */
#ifndef MVFOLLOWPATH_H_INCLUDED
#define MVFOLLOWPATH_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_ENUMS_HEADER_FILE_H_
#include MV_BASE_ACTION_HEADER_FILE_H_

/**
 * \class mvFollowPath
 * \brief derived mvBaseAction - moves the mvBody around the mvPathway 
 */

class mvFollowPath : public mvBaseAction
{
   private:
      mvIndex m_insideNode;
      mvIndex m_pathwayIndex;
      mvFloat m_lengthSquared;

   public:
      mvFollowPath();
      mvErrorEnum setParameterf(mvParamEnum param, mvFloat num);
      mvErrorEnum getParameterf(mvParamEnum param, mvFloat* num) const;

      mvErrorEnum setParameteri(mvParamEnum param, mvIndex paramIndex);
      mvErrorEnum getParameteri(mvParamEnum param, mvIndex* paramIndex) const;
	   virtual bool groupOp(mvGroupBehaviourResultPtr resultModule);
      virtual bool bodyOp(mvBehaviourResultPtr resultModule);
      ~mvFollowPath();
};

/**
 * \class mvCreatePathFollower
 * \brief derived mvBaseActionLoader - creates mvSeek
 */

class mvCreatePathFollower : public mvBaseActionLoader
{
   public:
      mvCreatePathFollower();
      virtual mvBaseActionPtr operator()(mvNewBaseActionInfo& actionInfo);
      ~mvCreatePathFollower();
};

#endif // MVFOLLOWPATH_H_INCLUDED
