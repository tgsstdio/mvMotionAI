/**
 * \file mvGroupBehaviourResult.h
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

#ifndef MVGROUPBEHAVIOURRESULT_H_INCLUDED
#define MVGROUPBEHAVIOURRESULT_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_GROUP_HEADER_FILE_H_
#include MV_WORLD_HEADER_FILE_H_
#include MV_GROUP_BEHAVIOUR_NODE_HEADER_FILE_H_

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

/** \class mvGroupBehaviourResult
 * \brief A module for retrieving global variables
 */
class MV_GLOBAL_FUNC_PREFIX mvGroupBehaviourResult
{
   public:
      mvWorldPtr world;
      mvGroupNodeMemberListPtr groupMemberList;

	void toFirstMember();
	void toNextMember();
	bool isAtEndOfMemberList() const;
	bool areWorldAndMemberListValid() const;
   mvGroupBehaviourResult(mvWorldPtr currentWorld,\
      mvGroupNodeMemberListPtr currentMList);
   mvWorldPtr getWorldPtr();
   mvGroupNodeMemberListPtr getMemberList() const;
   mvEntryListNodePtr getCurrentMemberNodePtr() const;
   mvBaseActionPtr getCurrentMemberActionDataPtr() const;
   mvBodyPtr getCurrentMemberAsBodyPtr() const;

   mvBodyPtr fetchBodyPtr(mvIndex objIndex) const;
   mvObstaclePtr fetchObstaclePtr(mvIndex objIndex) const;
   mvBaseForcePtr fetchForcePtr(mvIndex objIndex) const;
   mvWaypointPtr fetchWaypointPtr(mvIndex objIndex) const;
   mvGroupPtr fetchGroupPtr(mvIndex objIndex) const;
   mvBehaviourPtr fetchBehaviourPtr(mvIndex objIndex) const;
   mvGroupBehaviourPtr fetchGroupBehaviourPtr(mvIndex objIndex) const;
   mvPathwayPtr fetchPathwayPtr(mvIndex objIndex) const;

   ~mvGroupBehaviourResult();
};

#endif // MVGROUPBEHAVIOURRESULT_H_INCLUDED
