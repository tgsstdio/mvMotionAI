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
//#include "mvList.h"
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
typedef class mvA* mvBaseBehaviourPtr;
typedef class mvB* mvResultPtr;
typedef class mvC* mvWorldPtr;
typedef class mvD* mvGroupBehaviourPtr;
typedef class mvE* mvGroupBehaviourNodePtr;
typedef class mvF* mvBehaviourPtr;
typedef class mvG* mvBodyPtr;
typedef class mvH* mvBListPtr;
typedef class mvI* mvBEntryNodePtr;
typedef class mvJ* mvBaseBehaviourLoaderPtr;

// for pointer only
template <class mvClass>
class mvPointerList
{
   std::vector<mvClass> pList;
};

typedef class mvK
{

} mvObstacle;

typedef class mvH
{
   // mbBList
   mvPointerList<mvBEntryNodePtr> nodes;
} mvBList;

typedef class mvI
{
   // mvBehaviouEntry
   mvBaseBehaviourPtr behav;
} mvBEntryNode;

typedef class mvG
{
   // mvBody
   mvBList list;
} mvBody;

typedef class mvC
{
   // mvWorld
   mvPointerList<mvGroupBehaviourPtr> ds; //group behaviours
   mvPointerList<mvBodyPtr> gs; // mvBody
   mvPointerList<mvBehaviourPtr> fs; // behaviours
} mvWorld;

typedef class mvD
{
   // group behaviour
   mvBaseBehaviourPtr beh;
   mvPointerList<mvGroupBehaviourNodePtr> nodes;
} mvGroupBehaviour;

typedef class mvF
{
   // behaviour (global)
   mvBaseBehaviourPtr beh;
} mvBehaviour;

typedef class mvE
{
   // group behaviour node
   mvBaseBehaviourPtr beh;
} mvGroupBehaviourNode;

typedef class mvB
{
   // result class
   mvWorldPtr world;
} mvResult;

typedef class mvA
{
   // base behaviour
   bool do_stuff(mvResultPtr b);
} mvBaseBehaviour;

typedef class mvJ
{
   mvBaseBehaviourPtr operator()(mvBaseBehaviourPtr db);
} mvBaseBehaviourLoader;

int main(void)
{
   puts("hello");
   return  EXIT_SUCCESS;
}


