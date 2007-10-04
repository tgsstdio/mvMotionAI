#include <mv/mvIndexSet.h>

mvIndexSet::mvIndexSet()
{
   beginLoop();
}

mvErrorEnum mvIndexSet::findIndex(mvIndex index) const
{
   std::vector<mvIndex>::const_iterator i, loop_end;
   mvIndex itemKey;

   loop_end = indexes.end();
   for (i = indexes.begin(); i != loop_end; ++i)
   {
      itemKey = *i;
      if (itemKey == index)
      {
         return MV_NO_ERROR;
      }
   }
   return MV_ITEM_NOT_FOUND_IN_LIST;
}

mvErrorEnum mvIndexSet::addIndex(mvIndex index)
{
   if (index == MV_NULL)
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }

   indexes.push_back(index);
   return MV_NO_ERROR;
}

mvErrorEnum mvIndexSet::removeLastInstance(mvIndex index)
{
   std::vector<mvIndex>::reverse_iterator i;
   std::vector<mvIndex>::reverse_iterator loop_end = indexes.rend();
   mvIndex itemKey;

   for (i = indexes.rbegin(); i != loop_end; ++i)
   {
      itemKey = *i;
      if (itemKey == index)
      {
         indexes.erase(i.base());
         beginLoop();
         return MV_NO_ERROR;
      }
   }
   return MV_ITEM_NOT_FOUND_IN_LIST;
}

mvErrorEnum mvIndexSet::removeFirstInstance(mvIndex index)
{
   std::vector<mvIndex>::iterator i;
   std::vector<mvIndex>::iterator loop_end = indexes.end();
   mvIndex itemKey;

   for (i = indexes.begin(); i != loop_end; ++i)
   {
      itemKey = *i;
      if (itemKey == index)
      {
         indexes.erase(i);
         beginLoop();
         return MV_NO_ERROR;
      }
   }
   return MV_ITEM_NOT_FOUND_IN_LIST;
}

mvCount mvIndexSet::getNoOfIndexes() const
{
   return (mvCount) indexes.size();
}

void mvIndexSet::clearAll()
{
   indexes.clear();
   beginLoop();
}

// iterator functions
void mvIndexSet::beginLoop()
{
   mvCurrentIter = indexes.begin();
}

bool mvIndexSet::isLoopFinished() const
{
   return (mvCurrentIter == indexes.end());
}

mvIndex mvIndexSet::getCurrentIndex() const
{
   if (isLoopFinished())
   {
      return MV_NULL;
   }
   else
   {
      return *mvCurrentIter;
   }
}

void mvIndexSet::nextIndex()
{
   ++mvCurrentIter;
}

mvIndexSet::~mvIndexSet()
{
   clearAll();
}

// MV UNIQUE SET

mvUniqueSet::mvUniqueSet()
{
   beginLoop();
}

mvIndex mvUniqueSet::findIndex(mvIndex index) const
{
   std::set<mvIndex>::const_iterator found;

   found = indexes.find(index);
   if (found == indexes.end())
   {
      return MV_NULL;
   }
   else
   {
      return *found;
   }
}

mvErrorEnum mvUniqueSet::addIndex(mvIndex index)
{
   if (index == MV_NULL)
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }

   if (findIndex(index) == MV_NO_ERROR)
   {
      return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
   }
   else
   {
      indexes.insert(index);
      return MV_NO_ERROR;
   }
}

mvErrorEnum mvUniqueSet::removeIndex(mvIndex index)
{
   if (findIndex(index) == MV_NO_ERROR)
   {
      indexes.erase(index);
      return MV_NO_ERROR;
   }
   else
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }
}

mvCount mvUniqueSet::getNoOfIndexes() const
{
   return (mvCount) indexes.size();
}

// iterator functions
void mvUniqueSet::beginLoop()
{
   mvCurrentIter = indexes.begin();
}

bool mvUniqueSet::isLoopFinished() const
{
   return (mvCurrentIter == indexes.end());
}

mvIndex mvUniqueSet::getCurrentIndex() const
{
   if (isLoopFinished())
   {
      return MV_NULL;
   }
   else
   {
      return *mvCurrentIter;
   }
}

void mvUniqueSet::nextIndex()
{
   ++mvCurrentIter;
}

void mvUniqueSet::clearAll()
{
   indexes.clear();
   beginLoop();
}

mvUniqueSet::~mvUniqueSet()
{
   clearAll();
}

/** \class mvGroupIterator
 * \brief For navigating the group object
 */

mvUniqueSetIterator mvUniqueSet::getUniqueSetIterator() const
{
   return mvUniqueSetIterator(indexes);
}

mvUniqueSetIterator::mvUniqueSetIterator(const std::set<mvIndex>& currentSet)
   : currentIndexSet(currentSet)
{
   beginLoop();
}

void mvUniqueSetIterator::beginLoop()
{
   mvCurrentIter = currentIndexSet.begin();
}

bool mvUniqueSetIterator::isLoopFinished() const
{
   return (mvCurrentIter == currentIndexSet.end());
}

mvIndex mvUniqueSetIterator::getCurrentIndex() const
{
   if (isLoopFinished())
   {
      return MV_NULL;
   }
   else
   {
      return *mvCurrentIter;
   }
}

void mvUniqueSetIterator::nextIndex()
{
   if (!isLoopFinished())
   {
      ++mvCurrentIter;
   }
}

