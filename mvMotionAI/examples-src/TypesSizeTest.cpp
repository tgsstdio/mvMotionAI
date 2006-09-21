/**
 *\file TypesSizesTest.cpp
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
 */
//#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "mvMotionAI.h"

int main(void)
{
   std::cout << "mvMotionAI Type Sizes in bytes" << std::endl
             << "Size of mvMotionAI : " << sizeof(mvMotionAI)  << std::endl
             << "Size of mvEnum : " << sizeof(mvEnum)  << std::endl
             << "Size of mvFloat : " << sizeof(mvFloat)  << std::endl
             << "Size of mvIndex : " << sizeof(mvIndex)  << std::endl
             << "Size of mvCount : " << sizeof(mvCount)  << std::endl
             << "Size of mvWorld : " << sizeof(mvWorld)  << std::endl
             << "Size of mvBehaviour: " << sizeof(mvBehaviour)  << std::endl
             << "Size of mvGroupBehaviour: " << sizeof(mvGroupBehaviour)  << std::endl
             << "Size of mvWaypoint: " << sizeof(mvWaypoint)  << std::endl
             << "Size of mvPathway: " << sizeof(mvPathway)  << std::endl
             << "Size of mvGroup: " << sizeof(mvGroup)  << std::endl
             << "Size of mvObstacle: " << sizeof(mvObstacle)  << std::endl
             << "Size of mvForce: " << sizeof(mvForce)  << std::endl
             << "Size of mvBody: " << sizeof(mvBody)  << std::endl;

   return EXIT_SUCCESS;
};
