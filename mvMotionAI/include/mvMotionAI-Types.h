#ifndef MV_MOTIONAI_TYPES_H_
#define MV_MOTIONAI_TYPES_H_

/**
 * changes the values of 
 * data type in the system
 */

/**
 * FLOATING POINT - used in Vec3 and other places
 */

#define MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT 1
/** comment this line below changes the float type to double **/
#undef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT

#ifdef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT
typedef double mvFloat;
#else 
typedef float mvFloat;
#endif

/**
 * INDEXES & COUNT - used in Vec3 and other places
 */

#define MV_MOTIONAI_INDEX_TYPE_INTEGER 0
#define MV_MOTIONAI_INDEX_TYPE_SHORT 1
#define MV_MOTIONAI_INDEX_TYPE_LONG 2

// alter this value to change the type
#define MV_MOTIONAI_INDEX_TYPE MV_MOTIONAI_INDEX_TYPE_INTEGER

#if MV_MOTIONAI_INDEX_TYPE == MV_MOTIONAI_INDEX_TYPE_SHORT
typedef short mvIndex;
typedef short mvCount;
#elif MV_MOTIONAI_INDEX_TYPE == MV_MOTIONAI_INDEX_TYPE_LONG
typedef long mvIndex;
typedef long mvCount;
#else
typedef int mvIndex;
typedef int mvCount;
#endif

#endif
