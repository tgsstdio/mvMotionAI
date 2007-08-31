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
include/mvActionLoaderList.h
include/mvBEntry.h
include/mvBEntryList.h
include/mvBEntryListNode.h
include/mvBEntryTimer.h
include/mvBEntryUtility.h
include/mvBaseAction.h
include/mvBaseForce.h
include/mvBehaviourResult.h
include/mvBehaviour_V2.h
include/mvBodyCapsule.h
include/mvBody_V2.h
include/mvCapsuleList.h
include/mvCapsuleList.hpp
include/mvEnums.h
include/mvFactoryFunctionList.h
include/mvFactoryFunctionList.hpp
include/mvFlee.h
include/mvForceCapsule.h
include/mvForceLoaderList.h
include/mvForceResult.h
include/mvGravityForce.h
include/mvGroupBNode_V2.h
include/mvGroupBehaviourResult.h
include/mvGroupBehaviour_V2.h
include/mvGroupCapsule.h
include/mvGroup_V2.h
include/mvIndexSet.h
include/mvMotionAI-Types.h
include/mvMotionAI-Utilities.h
include/mvMotionAI.h
include/mvMotionAI_V2-Central.h
include/mvNullLoader.h
include/mvObstacle_V2.h
include/mvPathway_V2.h
include/mvPointerList.h
include/mvPointerList.hpp
include/mvPursuit.h
include/mvSeek.h
include/mvShape.h
include/mvUniformAccelForce.h
include/mvUniformForce.h
include/mvUniformShiftForce.h
include/mvVec3.h
include/mvWaypointCapsule.h
include/mvWaypoint_V2.h
include/mvWorld2.h
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

SET(MVMOTIONAI_LIB_NAME "libmvMotionAI")
ADD_LIBRARY(${MVMOTIONAI_LIB_NAME} ${MV_SOURCE_FILES}
   ${MV_HEADER_FILES})
   
SET(MVMOTIONAI_SHARED_LIB_NAME "libmvMotionAIShared")
ADD_LIBRARY(${MVMOTIONAI_SHARED_LIB_NAME} MODULE ${MV_SOURCE_FILES}
   ${MV_HEADER_FILES})