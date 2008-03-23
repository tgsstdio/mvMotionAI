/**
 * \file mvActionLoaderList.h
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
#ifndef MVACTIONLOADERLIST_H_INCLUDED
#define MVACTIONLOADERLIST_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

//#include MV_BASE_ACTION_HEADER_FILE_H_
#include "mvFactoryFunctionList.h"

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

typedef class mvNewBaseActionInfo& mvNewBaseActionInfoRef;
/**
 * \class mvActionLoaderList
 * \brief a list of factories which create instances of mvBaseActions depending
 * on the mvOptionEnum key provided
 *
 * mvErrorEnum mvActionLoaderList::addFactoryFunction(enum mvOptionEnum key,
 * mvBaseActionLoader actionFactoryPtr);
 *  \arg Brief : Adds to mvBaseAction factory function to list
 *  \arg Param(key) = An unique mvOptionEnum key within the list
 *  \arg Param(actionFactoryPtr) - A pointer to a mvBaseActionLoader object
 *  \arg Returns MV_NO_ERROR or any non zero value if error has occured.
 *
 *  NOTE: this memory pointed by actionFactoryPtr is freed by mvActionLoaderList.
 *  DO NOT free/deallocate the actionFactoryPtr after the addFactoryFunction call.
 *
 * mvBaseActionPtr mvActionLoaderList::createAClassPtr(enum mvOptionEnum key,
 *    mvNewBaseActionInfo& creationInfo);
 *  \arg Brief : Create a mvBaseAction object pointer based on the key provided
 *  \arg Param(key) - An unique mvOptionEnum key within the list
 *  \arg Param(creationInfo) - Provides information when the function has been
 *  called within the library.
 *  \arg Returns a mvBaseActionPtr object or MV_NULL if error has occured.
 *
 *  void mvActionLoaderList::freeAllFactoryFunctions();
 *  \arg  Free all mvBaseActionLoader factories in this list.
 *
 *  mvCount mvActionLoaderList::getNoOfFactoryFunctions() const;
 *  \arg Brief : Retrieves the number of mvBaseActionLoaders within this list
 *  \arg Returns numbers of mvBaseActionLoaders
 */


typedef class MV_GLOBAL_FUNC_PREFIX mvFactoryFunctionList<mvBaseActionLoader,\
   mvBaseAction, mvNewBaseActionInfoRef > mvActionLoaderList;


#endif // MVBEHAVFUNCLIST_H_INCLUDED
