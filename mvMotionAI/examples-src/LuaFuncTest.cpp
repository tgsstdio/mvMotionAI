/**
 *\file LuaFuncTest.cpp
 * Copyright (c) 2006 David Young.
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
#include <iostream>
#include "mvMotionAI.h"
#include "mvLuaScript.h"

//const char** mvGetLuaWorldFunctions();
//mvCount mvGetNoOfLuaWorldFunctions();

void displayLuaFunctions(char* stringTitle,const char** arrayPtr, mvCount noOfElements)
{
    int i;
    const char* lineBreak = "=============";

	std::cout << lineBreak << std::endl
	          << stringTitle << std::endl
	          << "No Of Functions : "
	          << noOfElements << std::endl
              << lineBreak << std::endl;
	for (i = 0; i < noOfElements; i++)
    {
	   std::cout << arrayPtr[i] << std::endl;
    }
    std::cout << std::endl;
};

int main()
{
    const char** arrayPtr = NULL;
    int i;
    mvCount noOfElements = 0;

	std::cout << "mvMotionAI Lua Functions" << std::endl;
    displayLuaFunctions("mvMotionAI",mvGetLuaMotionAIFunctions(),mvGetNoOfLuaMotionAIFunctions());
    displayLuaFunctions("mvWorld",mvGetLuaWorldFunctions(),mvGetNoOfLuaWorldFunctions());
    displayLuaFunctions("mvBody",mvGetLuaBodyFunctions(),mvGetNoOfLuaBodyFunctions());
    displayLuaFunctions("mvObstacle",mvGetLuaObstacleFunctions(),mvGetNoOfLuaObstacleFunctions());
    displayLuaFunctions("mvWaypoint",mvGetLuaWaypointFunctions(),mvGetNoOfLuaWaypointFunctions());
    displayLuaFunctions("mvBehaviour",mvGetLuaBehaviourFunctions(),mvGetNoOfLuaBehaviourFunctions());
    displayLuaFunctions("mvForce",mvGetLuaForceFunctions(),mvGetNoOfLuaForceFunctions());
    displayLuaFunctions("mvPathway",mvGetLuaPathwayFunctions(),mvGetNoOfLuaPathwayFunctions());
    displayLuaFunctions("mvGroup",mvGetLuaGroupFunctions(),mvGetNoOfLuaGroupFunctions());
    displayLuaFunctions("mvGroupBehaviour",mvGetLuaGroupBehaviourFunctions(),mvGetNoOfLuaGroupBehaviourFunctions());

	return 0;
}
