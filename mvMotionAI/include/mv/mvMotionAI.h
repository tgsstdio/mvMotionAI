/**
 * \file mvMotionAI.h
 *
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
 * 00-01-31    19/01/07
 *
 * - now mvMotionAI C interface using mvWorld_V2
 *
 * 00-01-25    23/12/06
 * - changed function signature
 * - Permanent removing item from world  = Remove to Delete
 * - mvRemoveAllWorlds to mvDeleteAllWorlds
 * - Create instead of Add
 * - mvAddWorld to mvCreateAllWorlds
 */
#ifndef MV_GLOBAL_FUNCTIONS_H_
#define MV_GLOBAL_FUNCTIONS_H_

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_WORLD_HEADER_FILE_H_
#include MV_BASE_ACTION_HEADER_FILE_H_
#include MV_BASE_FORCE_HEADER_FILE_H_
#include MV_ENUMS_HEADER_FILE_H_
#include MV_ACTION_LOADER_LIST_HEADER_FILE_H_
#include MV_FORCE_LOADER_LIST_HEADER_FILE_H_
#include MV_STDLIB_HEADER_FILE_H_

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

/**
 * \defgroup mvGlobal Global mvMotionAI functions
 */

// mvMotionAI functions - 13 functions
/**
 *  \ingroup mvGlobal
 *  \brief Initialises mvMotionAI C Interface
 */
MV_GLOBAL_FUNC_PREFIX void mvInitMotionAI();

/**
 *  \ingroup mvGlobal
 *  \brief Frees mvMotionAI C Interface
 */
MV_GLOBAL_FUNC_PREFIX void mvFreeMotionAI();

/**
 * \ingroup mvGlobal
 * \brief Moves all mvWorld instances linked to mvMotionAI C Interface by timeInSecs
 * \param[in] timeInSecs Same time unit to move all worlds
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAllWorldsStepForward(mvFloat timeInSecs);

/**
 * \ingroup mvGlobal
 * \brief Creates a linked mvWorld instance
 * \return Any non zero value or if error has occured, MV_NULL(0) is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWorld(mvIndex saveFileIndex = MV_NULL);

/**
 * \ingroup mvGlobal
 * \brief Deletes all linked mvWorld instances
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllWorlds();

/**
 * \ingroup mvGlobal
 * \brief Gets the pointer to mvWorld pointer by index
 * \param[in] index Index to linked mvWorld instance
 * \return A pointer to mvWorldInstance or if error has occured,
 *  MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvWorldPtr mvGetWorldPtr(mvIndex index);

/**
 * \ingroup mvGlobal
 * \brief Sets the mvMotionAI C interface's current world index
 * \param[in] index Index of possible linked mvWorld instance
 * \return The parameter index or MV_NULL if error has occured
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentWorld(mvIndex index);

/**
 * \ingroup mvGlobal
 * \brief Gets the mvMotionAI C interface's current world as mvIndex
 * \return The index of the current linked mvWorld as mvIndex
 * or MV_NULL if error has occured
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentWorld();

/**
 * \ingroup mvGlobal
 * \brief Get the mvMotionAI C interface's current world as mvWorld pointer
 * \return A pointer to current linked mvWorld instance or MV_NULL if error
 * has occured
 */
MV_GLOBAL_FUNC_PREFIX mvWorldPtr mvGetCurrentWorldPtr();

/**
 * \ingroup mvGlobal
 * \brief Apply some function to all linked mvWorld using mvWorldPtr pointers
 * \param[in] someFunction A function is the form of void func(mvWorldPtr, void*)
 * which is executed on pointers to currently existing linked mvWorld instances
 * \param[in,out] extraPtr A void pointer to any object that is passed to the
 * function someFunction.
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorlds(\
   void (someFunction)(mvWorldPtr,void*),void* extraPtr);

/**
 * \ingroup mvGlobal
 * \brief Apply some function to all linked mvWorld by their indexes
 * \param[in] someFunction A function is the form of void func(mvIndex, void*)
 * which is executed on all indexes of currently existing linked mvWorld instances
 * \param[in,out] extraPtr A void pointer to any object that is passed to the
 * function someFunction.
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorldsByIndex(\
   void(someFunction)(mvIndex, void* extraPtr), void* extraPtr);

/**
 * \ingroup mvGlobal
 * \brief Initialises all default actions (and their keys) on the mvMotionAI
 * C interface
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultActions();

/**
 * \ingroup mvGlobal
 * \brief Initialises all default forces (and their keys) on the mvMotionAI
 * C interface
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultForces();
//MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultBodies();

/**
 * \ingroup mvGlobal
 * \brief Initialises both the default actions and forces (and their keys)
 * on the mvMotionAI C interface
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitAllDefaults();

/**
 * \ingroup mvGlobal
 * \brief Free all actions (and their keys) connected the mvMotionAI
 * C interface
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultActions();

/**
 * \ingroup mvGlobal
 * \brief Free all forces (and their keys) connected the mvMotionAI
 * C interface
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultForces();
//MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultBodies();
/**
 * \ingroup mvGlobal
 * \brief Free all forces and all actions (and their keys) connected
 * the mvMotionAI C interface
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeAllDefaults();

/**
 * \ingroup mvGlobal
 * \brief Adding a new derived mvBaseForceLoader (and its key) to
 * the mvMotionAI C interface
 * \param[in] bType A unique key used when ...CreateForce(TYPE) is used
 * \param[in] loader A pointer referring to a mvBaseForce factory object
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 *
 * NOTE: the mvBaseForceLoaderPtr loader 's associated memory is freed by the
 * mvMotionAI C interface. DO NOT free this pointer after making the
 * mvAddForceFunction call.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddForceFunction(mvOptionEnum bType,\
   mvBaseForceLoaderPtr loader);

/**
 * \ingroup mvGlobal
 * \brief Create a new mvBaseForce object via the mvMotionAI C interface using
 * a type key
 * \param[in] type A unique key used when ...CreateForce(TYPE) is used
 * \return A mvBaseForce pointer to new object or if error has occured, MV NULL
 *
 * NOTE: this function is really for testing if new added mvBaseForceLoader
 * are working correctly after a call to mvAddForceFunction.
 */
MV_GLOBAL_FUNC_PREFIX mvBaseForcePtr mvCreateNewForceFromLoader(\
   mvOptionEnum type);

/**
 * \ingroup mvGlobal
 * \brief Adding a new derived mvBaseActionLoader (and its key) to
 * the mvMotionAI C interface
 * \param[in] bType A unique key used when a new action is created
 * \param[in] loader A pointer referring to a mvBaseAction factory object
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 *
 * NOTE: the mvBaseActionLoaderPtr loader 's associated memory is freed by the
 * mvMotionAI C interface. DO NOT free this pointer after making the
 * mvAddBehaviourFunction call.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourFunction(mvOptionEnum bType,\
   mvBaseActionLoaderPtr loader);

/**
 * \ingroup mvGlobal
 * \brief Create a new mvBaseAction object via the mvMotionAI C interface using
 * a type key
 * \param[in] type A unique key used when a new action is created
 * \return A mvBaseForce pointer to new object or if error has occured, MV NULL
 *
 * NOTE: this function is really for testing if new added mvBaseActionLoader
 * are working correctly after a call to mvAddBehaviourFunction.
 */
MV_GLOBAL_FUNC_PREFIX mvBaseActionPtr mvCreateNewBehaviourFromLoader(\
   mvOptionEnum type);

/**
 * \ingroup mvGlobal
 * \brief Set the user data pointer of the mvWorld instance
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] tempData A void pointer to any object
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 *
 * NOTE: the user data pointer within mvWorld instances are not freed by the
 * mvMotionAI library
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldUserData(mvIndex worldIndex,
   void* tempData);

/**
 * \ingroup mvGlobal
 * \brief Gets the user data pointer of the mvWorld instance
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \return A pointer used as user data of the mvWorld or MV_NULL
 * if error has occured
 */
MV_GLOBAL_FUNC_PREFIX void* mvGetWorldUserData(mvIndex worldIndex);

// world instance functions

/* WORLD FUNCTIONS  = 18 */

/**
 * \ingroup mvGlobal
 * \brief Moves a mvWorld by an anount of time
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] timeInSecs The time in secs used for integration
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 *
 * NOTE : each mvWorld has its own time-keeping variables.
 * Each call to mvWorldStep will updates those values.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvWorldStep(mvIndex worldIndex,\
   mvFloat timeInSecs);
/**
 * \ingroup mvGlobal
 * \brief Moves a mvBody with a linked mvWorld by an anount of time
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] bodyIndex The index of a mvBody inside that mvWorld
 * \param[in] timeInSecs The time in secs used for integration
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 *
 * NOTE : each mvWorld has its own time-keeping variables.
 * Each call of mvNudgeBody will NOT updates those values.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvFloat timeInSecs);

/**
 * \ingroup mvGlobal
 * \brief Moves a mvBody with a linked mvWorld by an anount of time
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] bodyIndex The index of a mvBody inside that mvWorld
 * \param[in] timeInSecs The time in secs used for integration
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 *
 * NOTE : each mvWorld has its own time-keeping variables.
 * Each call of mvStepBody will updates those values.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvStepBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvFloat timeInSecs);

/**
 * \ingroup mvGlobal
 * \brief Gets a state/options variable of a linked mvWorld instance
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] param The parameter or variable type that the programmer wants to
 *  retrieve
 * \param[out] option A pointer to a mvOptionEnum
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametero(mvIndex worldIndex,\
	mvParamEnum param, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \brief Gets a single index variable of a linked mvWorld instance
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] param The parameter or variable type that the programmer wants to
 *  retrieve
 * \param[out] index A pointer to a mvIndex location
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameteri(mvIndex worldIndex,\
	mvParamEnum param, mvIndex* index);
/**
 * \ingroup mvGlobal
 * \brief Gets a single mvFloat variable of a linked mvWorld instance
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] param The parameter or variable type that the programmer wants to
 *  retrieve
 * \param[out] num A pointer to mvFloat variable
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterf(mvIndex worldIndex,\
	mvParamEnum param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \brief Gets an array of mvFloats or vector variable of a linked mvWorld instance
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] param The parameter or variable type that the programmer wants to
 *  retrieve
 * \param[out] array A pointer to a mvFloat array of appropriate size
 * (>= MV_MAX_NO_OF_PARAMETERS)
 * \param[out] noOfParameters The number of variables returned by this function
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterv(mvIndex worldIndex,\
	mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
// TODO : finish doxygen comments
/**
 * \ingroup mvGlobal
 * \brief Retrieves mvWorld's option variable in string format
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] param The parameter or variable type that the programmer wants to
 *  retrieve
 * \param[out] option A pointer to C string pointer location
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametero_str(mvIndex worldIndex,\
	const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \brief Retrieves mvWorld's index variable in string format
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] param The parameter or variable type that the programmer wants to
 *  retrieve
 * \param[out] index A location to mvIndex variable.
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameteri_str(mvIndex worldIndex,\
	const char* param, mvIndex* index);
/**
 * \ingroup mvGlobal
 * \brief Retrieves mvWorld's single mvFloat variable in string format
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] param The parameter or variable type that the programmer wants to
 *  retrieve
 * \param[out] num A location to mvFloat variable.
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterf_str(mvIndex worldIndex,\
	const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \brief Retrieves linked mvWorld's floating vector in string format
 * \param[in] worldIndex The index of the linked mvWorld instance
 * \param[in] param The parameter or variable type that the programmer wants to
 *  retrieve
 * \param[out] array A pointer to a mvFloat array of appropriate size
 * (>= MV_MAX_NO_OF_PARAMETERS)
 * \param[out] noOfParameters The number of variables returned by this function
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterv_str(mvIndex worldIndex,\
	const char* param, mvFloat* array, mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametero(mvIndex worldIndex,\
	mvParamEnum param, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameteri(mvIndex worldIndex,\
	mvParamEnum param, mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterf(mvIndex worldIndex,\
	mvParamEnum param, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterv(mvIndex worldIndex,\
   mvParamEnum param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametero_str(mvIndex worldIndex,\
   const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameteri_str(mvIndex worldIndex,\
   const char* param, mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterf_str(mvIndex worldIndex,\
   const char* param, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterv_str(mvIndex worldIndex,\
   const char* param, mvFloat* array);

/*
 * C pointer foreach functions = 8
 * for C++ class methods
 */
 /**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBodies(mvIndex worldIndex,\
   void (someFunction)(mvBodyPtr,void*),void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstacles(mvIndex worldIndex,\
   void (someFunction)(mvObstaclePtr,void*),void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypoints(mvIndex worldIndex,\
   void (someFunction)(mvWaypointPtr,void*),void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathways(mvIndex worldIndex,\
   void (someFunction)(mvPathwayPtr,void*),void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroups(mvIndex worldIndex,\
   void (someFunction)(mvGroupPtr,void*),void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllBehaviours(mvIndex worldIndex,\
   void (someFunction)(mvBehaviourPtr,void*),void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehaviours(\
   mvIndex worldIndex, void (someFunction)(mvGroupBehaviourPtr,void*),\
   void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllForces(mvIndex worldIndex,\
   void (someFunction)(mvBaseForcePtr,void*),void* extraPtr);

/*
 * mvIndex foreach functions = 8
 * for using C interface functions
 */

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBodiesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex,mvIndex,void*),void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstaclesByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex,void*),\
   void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypointsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex,void*),\
   void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathwaysByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBehavioursByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehavioursByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllForcesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex,mvIndex, void*), void* extraPtr);

/* body functions */
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBody(mvIndex worldIndex,\
   mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z,\
   mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBody_str(mvIndex worldIndex,\
   const char* bType, const char* bShape, mvFloat x, mvFloat y, mvFloat z,\
   mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvBody instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvBodyPtr mvGetBodyPtr(mvIndex worldIndex,\
   mvIndex bodyIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentBody(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvBody instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvBodyPtr mvGetCurrentBodyPtr(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentBody(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteBody(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllBodies(mvIndex worldIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvIndex mvAddBehaviourToList(mvIndex worldIndex,\
   mvIndex bodyIndex, mvOptionEnum bType, mvIndex behaviourIndex,\
   mvIndex groupIndex, mvIndex saveFileIndex = MV_NULL);
MV_GLOBAL_FUNC_PREFIX mvIndex mvAddBehaviourToList_str(mvIndex worldIndex,\
   mvIndex listIndex, const char* bType, mvIndex behaviourIndex,\
   mvIndex groupIndex, mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveBehaviourFromList(mvIndex worldIndex,\
   mvIndex listIndex, mvIndex entryIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllBehavioursFromList(\
   mvIndex worldIndex, mvIndex listIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentEntryFromList(mvIndex worldIndex,\
   mvIndex listIndex);

//mvObstacle 41 functions =  9 + 16 + 16
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateObstacle(mvIndex worldIndex,\
   mvOptionEnum oShape, mvOptionEnum oState, mvFloat x, mvFloat y, mvFloat z,\
   mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateObstacle_str(mvIndex worldIndex,\
   const char* oShape, const char* oState, mvFloat x, mvFloat y, mvFloat z,\
   mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvObstacle instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvObstaclePtr mvGetObstaclePtr(mvIndex worldIndex,\
   mvIndex bodyIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentObstacle(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvObstacle instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvObstaclePtr mvGetCurrentObstaclePtr(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentObstacle(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteObstacle(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllObstacles(mvIndex worldIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleAsWorldBoundary(\
   mvIndex worldIndex, mvIndex obstacleIndex);

/*mvWaypoint No Of Functions : 46 = 6 + 16 + 16 + 8 */
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWaypoint(mvIndex worldIndex,\
   mvOptionEnum wShape, mvFloat x, mvFloat y, mvFloat z,\
   mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWaypoint_str(mvIndex worldIndex,\
   const char* wShape, mvFloat x, mvFloat y, mvFloat z,\
   mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvWaypoint instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvWaypointPtr mvGetWaypointPtr(mvIndex worldIndex,\
	 mvIndex index);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentWaypoint(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvWaypoint instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvWaypointPtr mvGetCurrentWaypointPtr(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentWaypoint(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteWaypoint(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllWaypoints(mvIndex worldIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat array);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParametero_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
   mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddForceIntoWaypoint(mvIndex worldIndex,\
   mvIndex waypointIndex, mvIndex forceIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveForceFromWaypoint(mvIndex worldIndex,\
   mvIndex waypointIndex, mvIndex forceIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllWaypointsFromForce(\
   mvIndex worldIndex, mvIndex forceIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllForcesFromWaypoint(\
   mvIndex worldIndex, mvIndex waypointIndex);

/*
 *mvBehaviour
 *No Of Functions : 39 = 5 + 2 + 16 + 16
 */
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBehaviour(mvIndex worldIndex,\
   mvOptionEnum bType, mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBehaviour_str(mvIndex worldIndex,\
   const char* bType, mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvBehaviour instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvBehaviourPtr mvGetBehaviourPtr(mvIndex worldIndex,\
	 mvIndex index);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentBehaviour(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvBehaviour instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvBehaviourPtr mvGetCurrentBehaviourPtr(\
   mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentBehaviour(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteBehaviour(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllBehaviours(mvIndex worldIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParametero_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
   mvCount* noOfParameters);

//=============
//No Of Functions : 37 = 5 + 16 + 16
//=============
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateForce(mvIndex worldIndex,\
   mvOptionEnum fType, mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateForce_str(mvIndex worldIndex,\
   const char* fType, mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvBaseForce instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvBaseForcePtr mvGetForcePtr(mvIndex worldIndex,\
	 mvIndex index);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentForce(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvBaseForce instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvBaseForcePtr mvGetCurrentForcePtr(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentForce(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteForce(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllForces(mvIndex worldIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array,\
   mvCount* noOfParameters);

//=============
//mvPathway No Of Functions : 115 = 5 + 16 + 16 (37) + 12 + 32 + 32 + 2
//=============
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreatePathway(mvIndex worldIndex,\
   mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvPathway instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvPathwayPtr mvGetPathwayPtr(mvIndex worldIndex,\
	 mvIndex index);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentPathway(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvPathway instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvPathwayPtr mvGetCurrentPathwayPtr(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentPathway(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeletePathway(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllPathways(mvIndex worldIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);

// add waypoints to paths or Pathway Node
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvAddNodeToPathway(mvIndex worldIndex,\
   mvIndex pathwayIndex, mvIndex nodeIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveNodeFromPathway(mvIndex worldIndex,\
   mvIndex pathwayIndex, mvIndex nodeIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllNodesFromPathway(\
   mvIndex worldIndex,mvIndex pathwayIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentNodeOfPathway(mvIndex worldIndex,\
   mvIndex pathwayIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemovePathwayNodeAt(mvIndex worldIndex,\
   mvIndex pathwayIndex, mvIndex nodeIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameteri(\
   mvIndex worldIndex,mvIndex pathwayIndex,  mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParametero(mvIndex worldIndex,\
   mvIndex pathwayIndex, mvIndex nodeIndex, mvParamEnum paramFlag,\
   mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameterf(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameterv(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameteri_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParametero_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameterf_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameterv_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameteri(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParametero(mvIndex worldIndex,\
   mvIndex pathwayIndex, mvIndex nodeIndex, mvParamEnum paramFlag,\
   mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameterf(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameterv(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameteri_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParametero_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameterf_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameterv_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters);

//=============
//mvGroup No Of Functions : 51 = 8 + 5 + 16 + 16 + 2 + 4
//=============
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroup(mvIndex worldIndex,\
   mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvGroup instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvGroupPtr mvGetGroupPtr(mvIndex worldIndex,\
	 mvIndex index);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentGroup(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvGroup instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvGroupPtr mvGetCurrentGroupPtr(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentGroup(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteGroup(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllGroups(mvIndex worldIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddMemberIntoGroup(mvIndex worldIndex,\
   mvIndex mIndex, mvIndex groupIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveMemberFromGroup(mvIndex worldIndex,\
   mvIndex groupIndex, mvIndex memberIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllMembersFromGroup(\
   mvIndex worldIndex, mvIndex mIndex);


// TODO : GROUP SET OPERATIONS LATER
/*
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvCombineGroups(mvIndex worldIndex,
   mvIndex groupA, mvIndex groupB, mvOptionEnum operation);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetOperationOnGroup(mvIndex worldIndex,
   mvIndex groupIndex, mvOptionEnum operation);
*/

//=============
// GROUP BEHAVIOURS
//No Of Functions : 75 = 5 + 4 + 4 + 32 + 32
//=============
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroupBehaviour(mvIndex worldIndex,\
   mvOptionEnum gbType, mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroupBehaviour_str(mvIndex worldIndex,\
	const char* gbType, mvIndex saveFileIndex = MV_NULL);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvGroupBehaviour instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvGroupBehaviourPtr mvGetGroupBehaviourPtr(\
   mvIndex worldIndex, mvIndex index);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentGroupBehaviour(mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvGroupBehaviour instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvGroupBehaviourPtr mvGetCurrentGroupBehaviourPtr(\
mvIndex worldIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentGroupBehaviour(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteGroupBehaviour(mvIndex worldIndex,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllGroupBehaviours(\
   mvIndex worldIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllGroupsFromGroupBehaviour(\
   mvIndex worldIndex, mvIndex gbIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag,\
   mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParametero(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParametero_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat array);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParametero(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameteri_str(\
	mvIndex worldIndex, mvIndex index, const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParametero_str(\
	mvIndex worldIndex, mvIndex index, const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterf_str(\
	mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterv_str(\
	mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
	mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameteri(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
	mvParamEnum paramFlag, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParametero(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameterf(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameterv(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameteri_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvIndex paramIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParametero_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameterf_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex, const char* param,\
	mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameterv_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex, const char* param,\
	mvFloat* array);


/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameteri(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParametero(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameterf(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameterv(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
	mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameteri_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParametero_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameterf_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameterv_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters);

// add group to group behaviours
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddGroupIntoGroupBehaviour(\
   mvIndex worldIndex,mvIndex groupBehaviour, mvIndex groupIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveGroupFromGroupBehaviour(\
   mvIndex worldIndex, mvIndex groupBehaviour, mvIndex groupIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameteri(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParametero(
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterf(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterv(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParametero_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameteri(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParametero(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterf(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterv(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParametero_str(\
   mvIndex worldIndex, mvIndex listIndex,mvIndex nodeIndex, const char* param,
   const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat* array, mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameteri(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParametero(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvOptionEnum option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterf(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterv(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvIndex index);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParametero_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, const char* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat* array);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameteri(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParametero(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvOptionEnum* option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterf(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterv(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvIndex* outIndex);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParametero_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param,\
   const char** option);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat* num);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllEntryLists(mvIndex worldIndex,\
   void (someFunction)(mvEntryListPtr, void*), void* extraPtr);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetUserData(mvIndex worldIndex,\
   mvParamEnum objectType, mvIndex objectIndex, void* userData);
/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX void* mvGetUserData(mvIndex worldIndex,\
   mvParamEnum objectType, mvIndex objectIndex);
/**
 * \ingroup mvGlobal
 * \return A unique index or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvIndex mvFindMemberInGroup(mvIndex worldIndex,
   mvIndex groupIndex, mvIndex memberIndex);
/**
 * \ingroup mvGlobal
 * \return A pointer to mvEntryList instance or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvEntryListPtr mvGetEntryListPtr(mvIndex worldIndex,\
   mvIndex entryListIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRegisterAllGroupBehavioursToBodies(mvIndex\
	worldIndex);

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRegisterGroupBehaviourToBodies(mvIndex\
	worldIndex, mvIndex groupBehaviour);

#endif

