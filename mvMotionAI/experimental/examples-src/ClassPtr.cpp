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
 */
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>

#include "mvPointerList.h"
/**
 * PROBLEM A : how do you compile files when there is a circular coupled
 *           relationship to classes?
 *
 *            pointer a is member of b => b is pointer in c => c refers
 *            to pointer of a
 *
 * SOLUTION FOR A : for complicated coupling  prior typedef pointers
 *            at the beginning of the code
 *
 * PROBLEM B : how do you compile files when there is a template data structure
 *            class using any type of pointer inside this
 *            complicated coupled system ?
 *
 * SOLUTION FOR B : declared new vector made up of pointers without referring to
 *                 pointers in declaration/implementation, using the
 *                 typedef'fed pointers types
 */
typedef class mvA2* mvBaseActionPtr2;
typedef class mvB* mvResultPtr2;
typedef class mvC* mvWorldPtr2;
typedef class mvD* mvGroupBehaviourPtr2;
typedef class mvE* mvGroupBehaviourNodePtr2;
typedef class mvF* mvBehaviourPtr2;
typedef class mvG* mvBodyPtr2;
typedef class mvH* mvBListPtr2;
typedef class mvI* mvBEntryNodePtr2;
typedef class mvJ* mvBaseActionLoaderPtr2;

// for pointer only
/*
template <class mvClass>
class mvPointerList
{
   std::vector<mvClass> pList;
};
*/

typedef class mvK
{

} mvObstacle2;

typedef class mvH
{
   // mbBList
   mvPointerList<mvBEntryNodePtr2> nodes;
} mvBList;

typedef class mvI
{
   // mvBehaviouEntry
   mvBaseActionPtr2 behav;
} mvBEntryNode;

typedef class mvG
{
   // mvBody
   mvBList list;
} mvBody2;

typedef class mvC
{
   // mvWorld
   mvPointerList<mvGroupBehaviourPtr2> ds; //group behaviours
   mvPointerList<mvBodyPtr2> gs; // mvBody
   mvPointerList<mvBehaviourPtr2> fs; // behaviours
} mvWorld;

typedef class mvD
{
   // group behaviour
   mvBaseActionPtr2 beh;
   mvPointerList<mvGroupBehaviourNodePtr2> nodes;
} mvGroupBehaviour;

typedef class mvF
{
   // behaviour (global)
   mvBaseActionPtr2 beh;
} mvBehaviour;

typedef class mvE
{
   // group behaviour node
   mvBaseActionPtr2 beh;
} mvGroupBehaviourNode;

typedef class mvB
{
   // result class
   mvWorldPtr2 world;
} mvResult;

typedef class mvA2
{
   // base behaviour
   bool do_stuff(mvResultPtr2 b);
} mvBaseAction2;

typedef class mvJ
{
   mvBaseActionPtr2 operator()(mvBaseActionPtr2 db);
} mvBaseActionLoader;

int main(void)
{
   puts("hello");
   return  EXIT_SUCCESS;
}


