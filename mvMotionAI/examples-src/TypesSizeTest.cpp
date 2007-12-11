/**
 *\file TypesSizesTest.cpp
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
 * Log
 * version
 *
 * 00-03    added version 2 of mvMotionAI classes
 *
 * 00-02    edited to deal with new enums
 */
//#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <mv/mvMotionAI.h>

int main(void)
{
   std::cout << "mvMotionAI type sizes in bytes" << std::endl
             << "mvParamEnum : " << sizeof(mvParamEnum)  << std::endl
             << "mvErrorEnum : " << sizeof(mvErrorEnum)  << std::endl
             << "mvOptionEnum : " << sizeof(mvOptionEnum)  << std::endl
             << "mvFloat : " << sizeof(mvFloat)  << std::endl
             << "mvIndex : " << sizeof(mvIndex)  << std::endl
             << "mvCount : " << sizeof(mvCount)  << std::endl
             << "mvWorld : " << sizeof(mvWorld)  << std::endl
             << "mvBehaviour: " << sizeof(mvBehaviour)  << std::endl
             << "mvGroupBehaviour: " << sizeof(mvGroupBehaviour)  << std::endl
             << "mvWaypoint: " << sizeof(mvWaypoint)  << std::endl
             << "mvPathway: " << sizeof(mvPathway)  << std::endl
             << "mvGroup: " << sizeof(mvGroup)  << std::endl
             << "mvGroupIterator: " << sizeof(mvGroupIterator)  << std::endl
             << "mvObstacle: " << sizeof(mvObstacle)  << std::endl
             << "mvTimer : " << sizeof(mvTimer) << std::endl
             << "mvEntryList : " << sizeof(mvEntryList) << std::endl
             << "mvBehaviourResult: " << sizeof(mvBehaviourResult)  << std::endl
             << "mvForceResult: " << sizeof(mvForceResult)  << std::endl
             << "mvForceStatus: " << sizeof(mvForceStatus)  << std::endl
             << "mvBody: " << sizeof(mvBody)  << std::endl;

   return EXIT_SUCCESS;
}
