PROJECT(MVMOTIONAI CXX)
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib ${CMAKE_SOURCE_DIR}/lib-other)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/include-other)

SET(MV_SOURCE_FILES
src/mvBEntry.cpp
src/mvBEntryList.cpp
src/mvBEntryListNode.cpp
src/mvBEntryTimer.cpp
src/mvBEntryUtility.cpp
src/mvBaseAction.cpp
src/mvBaseForce.cpp
src/mvBehaviourResult.cpp
src/mvBehaviour_V2.cpp
src/mvBodyCapsule.cpp
src/mvBody_V2.cpp
src/mvEnums.cpp
src/mvFlee.cpp
src/mvForceCapsule.cpp
src/mvForceResult.cpp
src/mvGravityForce.cpp
src/mvGroupBNode_V2.cpp
src/mvGroupBehaviourResult.cpp
src/mvGroupBehaviour_V2.cpp
src/mvGroupCapsule.cpp
src/mvGroup_V2.cpp
src/mvIndexSet.cpp
src/mvMotionAI-Utilities.cpp
src/mvMotionAI.cpp
src/mvMotionAI_V2-Central.cpp
src/mvNullLoader.cpp
src/mvObstacle_V2.cpp
src/mvPathway_V2.cpp
src/mvPursuit.cpp
src/mvSeek.cpp
src/mvShape.cpp
src/mvUniformAccelForce.cpp
src/mvUniformForce.cpp
src/mvUniformShiftForce.cpp
src/mvVec3.cpp
src/mvWaypointCapsule.cpp
src/mvWaypoint_V2.cpp
src/mvWorld2.cpp
src/mvWorld2_Functions.cpp
src/mvWorld2_Functions.h)

SET(MV_HEADER_FILES
include/mv/mvActionLoaderList.h
include/mv/mvBEntry.h
include/mv/mvBEntryList.h
include/mv/mvBEntryListNode.h
include/mv/mvBEntryTimer.h
include/mv/mvBEntryUtility.h
include/mv/mvBaseAction.h
include/mv/mvBaseForce.h
include/mv/mvBehaviourResult.h
include/mv/mvBehaviour_V2.h
include/mv/mvBodyCapsule.h
include/mv/mvBody_V2.h
include/mv/mvCapsuleList.h
include/mv/mvCapsuleList.hpp
include/mv/mvEnums.h
include/mv/mvFactoryFunctionList.h
include/mv/mvFactoryFunctionList.hpp
include/mv/mvFlee.h
include/mv/mvForceCapsule.h
include/mv/mvForceLoaderList.h
include/mv/mvForceResult.h
include/mv/mvGravityForce.h
include/mv/mvGroupBNode_V2.h
include/mv/mvGroupBehaviourResult.h
include/mv/mvGroupBehaviour_V2.h
include/mv/mvGroupCapsule.h
include/mv/mvGroup_V2.h
include/mv/mvIndexSet.h
include/mv/mvMotionAI-Types.h
include/mv/mvMotionAI-Utilities.h
include/mv/mvMotionAI.h
include/mv/mvNullLoader.h
include/mv/mvObstacle_V2.h
include/mv/mvPathway_V2.h
include/mv/mvPointerList.h
include/mv/mvPointerList.hpp
include/mv/mvPursuit.h
include/mv/mvSeek.h
include/mv/mvShape.h
include/mv/mvUniformAccelForce.h
include/mv/mvUniformForce.h
include/mv/mvUniformShiftForce.h
include/mv/mvVec3.h
include/mv/mvWaypointCapsule.h
include/mv/mvWaypoint_V2.h
include/mv/mvWorld2.h
)

IF(MSVC)
  IF(MSVC60)
    SET(LIB_FLAGS -DVISUAL_C_VER_6)
    ADD_DEFINITIONS(${LIB_FLAGS})
  ELSE(MSVC60)
    SET(LIB_FLAGS -DVISUAL_C_VER_8)
    ADD_DEFINITIONS(${LIB_FLAGS})
  ENDIF(MSVC60)
ENDIF(MSVC)

MESSAGE("LIB DEFINES are ${LIB_FLAGS}")

OPTION(LIB_FORMAT "Build LIbrary Format as DLL(ON) or Static (OFF)"
  ON)
IF(LIB_FORMAT)
	SET(MVMOTIONAI_SHARED_LIB_NAME "libmvMotionAIShared")
	ADD_DEFINITIONS(-DMV_BUILD_DLL)
	ADD_LIBRARY(${MVMOTIONAI_SHARED_LIB_NAME} MODULE ${MV_SOURCE_FILES}
	   ${MV_HEADER_FILES})
ELSE(LIB_FORMAT)
	SET(MVMOTIONAI_LIB_NAME "libmvMotionAI")
	REMOVE_DEFINITIONS(LIB_FORMAT)
	ADD_LIBRARY(${MVMOTIONAI_LIB_NAME} ${MV_SOURCE_FILES}
	   ${MV_HEADER_FILES})
ENDIF(LIB_FORMAT)	   
INCLUDE(FindOpenGL)
INCLUDE(FindGLUT)

