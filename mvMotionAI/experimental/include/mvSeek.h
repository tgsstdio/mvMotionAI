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
 *
 */
#ifndef MV_SEEK_BHEAVIOUR_OBJECT_H_
#define MV_SEEK_BHEAVIOUR_OBJECT_H_

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include MV_BASE_ACTION_HEADER_FILE_H_

class mvSeek : public mvBaseAction
{
   private:
      mvFloat length;
      mvIndex waypointIndex;

   public:
      mvSeek();
	   virtual bool groupOp(mvGroupBehaviourResultPtr resultModule);
      virtual bool bodyOp(mvBehaviourResultPtr resultModule);

      virtual mvErrorEnum setParameterf(mvParamEnum param, mvFloat num);
      virtual mvErrorEnum setParameteri(mvParamEnum param, mvIndex index);
      virtual mvErrorEnum getParameterf(mvParamEnum param, mvFloat* num) const;
      virtual mvErrorEnum getParameteri(mvParamEnum param, mvIndex* index) const;
      virtual ~mvSeek();
};

class mvCreateSeeks : public mvBaseActionLoader
{
   public:
      mvCreateSeeks();
      virtual mvBaseActionPtr operator()(mvBaseActionPtr defaultBehav);
      virtual ~mvCreateSeeks(){};
};

#endif
