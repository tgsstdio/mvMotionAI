#include "mvList.h"
#include "mvForce.h"
#include <cstdlib>
#include <iostream>

int main()
{
   mvItemList<mvForce> forces;
   mvFloat array[10];
   mvErrorEnum error;
   const char* option = NULL;

   std::cout << forces.getNoOfItems() << std::endl;

   if (forces.getCurrentClassPtr() == NULL)
   {
      std::cout << "NO vaslues" << std::endl;
   }

   if (forces.addItem(new mvForce(MV_DRAG_FORCE)) != MV_NO_ERROR)
   {
      std::cout << "Add failed" << std::endl;
   }

   error = forces.getCurrentItemParameters("MV_TYPE", &option);

   if (error)
   {
      puts(mvGetErrorString(error));
   }
   else
   {
      std::cout << "HELLO " << option << std::endl;
   }

   return EXIT_SUCCESS;
}
