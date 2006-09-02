#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "mvMotionAI.h"

int main(void)
{
   std::cout << "Size of mvMotionAI : " << sizeof(mvMotionAI)  << std::endl
             << "Size of mvWorld : " << sizeof(mvWorld)  << std::endl
             << "Size of mvBehaviour: " << sizeof(mvBehaviour)  << std::endl
             << "Size of mvWaypoint: " << sizeof(mvWaypoint)  << std::endl
             << "Size of mvPathway: " << sizeof(mvPathway)  << std::endl
             << "Size of mvGroup: " << sizeof(mvGroup)  << std::endl
             << "Size of mvObstacle: " << sizeof(mvObstacle)  << std::endl
             << "Size of mvForce: " << sizeof(mvForce)  << std::endl
             << "Size of mvBody: " << sizeof(mvBody)  << std::endl;


   return 0;

};
