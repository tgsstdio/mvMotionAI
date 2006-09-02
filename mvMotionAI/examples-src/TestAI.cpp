#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "MotionAI.h"

extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}

MotionAI* aiModule = NULL;

int main(void)
{

   aiModule = new MotionAI();

   std::cout << "Hello World" << std::endl;
   aiModule->LoadScriptFile("Test.lua");

   delete aiModule; 

   return EXIT_SUCCESS;
};