#include "mvBaseAction.h"
#include MV_ENUMS_HEADER_FILE_H_
//#include <iostream>
#include <cstdlib>
#include <cstdio>
//#include <map>
#include <utility>

#include "mvSeek.h"
//#include "mvFlee.h"
//#include "mvClone.h"
//#include "mvPursuit.h"
#include "mvActionLoaderList.h"

int main(void)
{
   mvVec3 a,b,c;
   mvActionLoaderList bList;
   mvBaseAction* child;
   int i;

   puts("Hekkio");

   mvSeek s;

   s.groupOp(NULL);
   s.bodyOp(NULL);
   std::cout << a <<  " " << b << " " << c << std::endl
             <<  mvGetOptionString(s.getType()) << std::endl;

   // adding functions
   puts(mvGetErrorString(bList.addBehaviourFunction(MV_SEEK,   new mvCreateSeeks()     )));
   //puts(mvGetErrorString(bList.addBehaviourFunction(MV_FLEE,   new mvCreateFlees()     )));
   //puts(mvGetErrorString(bList.addBehaviourFunction(MV_PURSUIT,new mvCreatePursuits()  )));
   //puts(mvGetErrorString(bList.addBehaviourFunction(MV_CLONE,  new mvCreateClones()    )));

   mvOptionEnum options[] = {MV_SEEK, MV_FLEE, MV_PURSUIT, MV_CLONE};

   for (i = 0 ; i < 4; i++)
   {
      child = bList.createBehaviour(options[i],NULL);
      if (child == NULL)
      {
         puts("NULL Returned");
      }
      else
      {
         puts(mvGetOptionString(child->getType()));
         child->groupOp(NULL);
         child->bodyOp(NULL);
         delete child;
      }
   }

   return EXIT_SUCCESS;
}
