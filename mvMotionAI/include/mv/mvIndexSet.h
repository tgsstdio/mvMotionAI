#ifndef MVUNIQUESET_H_INCLUDED
#define MVUNIQUESET_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

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
#include <set>
#include <vector>

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

class MV_GLOBAL_FUNC_PREFIX mvIndexSet
{
   private:
      std::vector<mvIndex> indexes;
      std::vector<mvIndex>::const_iterator mvCurrentIter;

   public:
      mvIndexSet();
      mvErrorEnum findIndex(mvIndex index) const;
      mvErrorEnum addIndex(mvIndex index);
      mvErrorEnum removeLastInstance(mvIndex index);
      mvErrorEnum removeFirstInstance(mvIndex index);
      mvCount getNoOfIndexes() const;

      void clearAll();
      // iterator functions
      void beginLoop();
      bool isLoopFinished() const;
      mvIndex getCurrentIndex() const;
      void nextIndex();

      ~mvIndexSet();
};

class MV_GLOBAL_FUNC_PREFIX mvUniqueSetIterator
{
   private:
      const std::set<mvIndex>& currentIndexSet;
      std::set<mvIndex>::const_iterator mvCurrentIter;
   public:
      mvUniqueSetIterator(const std::set<mvIndex>& currentIndexSet);
      void beginLoop();
      bool isLoopFinished() const;
      mvIndex getCurrentIndex() const;
      void nextIndex();
};

class MV_GLOBAL_FUNC_PREFIX mvUniqueSet
{
   private:
      std::set<mvIndex> indexes;
      std::set<mvIndex>::const_iterator mvCurrentIter;

   public:
      mvUniqueSet();
      bool containsIndex(mvIndex index) const;
      mvErrorEnum addIndex(mvIndex index);
      mvErrorEnum removeIndex(mvIndex index);
      mvCount getNoOfIndexes() const;
      // TODO : complete this function
      mvUniqueSetIterator getUniqueSetIterator() const;

      // iterator functions
      void beginLoop();
      bool isLoopFinished() const;
      mvIndex getCurrentIndex() const;
      void nextIndex();

      void clearAll();
      ~mvUniqueSet();
};

#endif // MVUNIQUESET_H_INCLUDED
