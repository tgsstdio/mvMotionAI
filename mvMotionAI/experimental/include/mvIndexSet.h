#ifndef MVUNIQUESET_H_INCLUDED
#define MVUNIQUESET_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include <set>
#include <vector>

class mvIndexSet
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

class mvUniqueSet
{
   private:
      std::set<mvIndex> indexes;
      std::set<mvIndex>::const_iterator mvCurrentIter;

   public:
      mvUniqueSet();
      mvErrorEnum findIndex(mvIndex index) const;
      mvErrorEnum addIndex(mvIndex index);
      mvErrorEnum removeIndex(mvIndex index);
      mvCount getNoOfIndexes() const;

      // iterator functions
      void beginLoop();
      bool isLoopFinished() const;
      mvIndex getCurrentIndex() const;
      void nextIndex();

      void clearAll();
      ~mvUniqueSet();
};

#endif // MVUNIQUESET_H_INCLUDED
