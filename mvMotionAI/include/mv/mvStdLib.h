#ifndef MVESSENTIALS_H_INCLUDED
#define MVESSENTIALS_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_ENUMS_HEADER_FILE_H_
#include MV_ACTION_LOADER_LIST_HEADER_FILE_H_
#include MV_FORCE_LOADER_LIST_HEADER_FILE_H_

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

/**
 * \ingroup mvGlobal
 * \brief Adds the sll default actions of the mvMotionAI library
 * to this action loader list
 * \param[in,out] loader A pointer to a mvActionLoaderList object free of any
 * actions or behaviours.
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 *
 * NOTE: this function should be used when the programmer wishes to use the parts
 * of the library without the mvMotionAI C interface.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultActions(\
   mvActionLoaderListPtr loader);

/**
 * \ingroup mvGlobal
 * \brief Adds the sll default forces of the mvMotionAI library
 * to this force loader list
 * \param[in,out] loader A pointer to a mvForceLoaderList object free of any
 * associated forces.
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 *
 * NOTE: this function should be used when the programmer wishes to use the parts
 * of the library without the mvMotionAI C interface.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultForces(\
   mvForceLoaderListPtr loader);

#endif // MVESSENTIALS_H_INCLUDED
