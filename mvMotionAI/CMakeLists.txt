PROJECT(MVMOTIONAI CXX)
SET(MOTIONAI_LIB_LOCATIONS
   ${CMAKE_SOURCE_DIR}/lib
   ${CMAKE_SOURCE_DIR}/lib-other
)

SET(MOTIONAI_INCLUDE_LOCATIONS
   ${CMAKE_SOURCE_DIR}/include
   ${CMAKE_SOURCE_DIR}/include-other
)

CONFIGURE_FILE(NEWS ${EXECUTABLE_OUTPUT_PATH}/NEWS COPYONLY)
CONFIGURE_FILE(bin/Test.lua ${EXECUTABLE_OUTPUT_PATH}/Test.lua COPYONLY)
CONFIGURE_FILE(bin/Seek.lua ${EXECUTABLE_OUTPUT_PATH}/Seek.lua COPYONLY)
CONFIGURE_FILE(bin/Flee.lua ${EXECUTABLE_OUTPUT_PATH}/Flee.lua COPYONLY)
CONFIGURE_FILE(bin/Pursuit.lua ${EXECUTABLE_OUTPUT_PATH}/Pursuit.lua COPYONLY)
CONFIGURE_FILE(bin/FollowPath.lua ${EXECUTABLE_OUTPUT_PATH}/FollowPath.lua COPYONLY)
CONFIGURE_FILE(bin/Evasion.lua ${EXECUTABLE_OUTPUT_PATH}/Evasion.lua COPYONLY)
INCLUDE_DIRECTORIES(${MOTIONAI_INCLUDE_LOCATIONS})

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
src/mvFollowPath.cpp
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
src/mvWorld2_Functions.h
src/mvEvasion.cpp)

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
include/mv/mvFollowPath.h
include/mv/mvEvasion.h  
include/mv/mvReadyMadeLoader.h 
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

IF (NOT CMAKE_BUILD_TYPE)
 SET(CMAKE_BUILD_TYPE "Release")
ENDIF (NOT CMAKE_BUILD_TYPE)

OPTION(SHARED_LIB_FORMAT "Build Shared Library Format as DLL(ON) or Static (OFF)"
  OFF)

IF(SHARED_LIB_FORMAT)
	SET(MVMOTIONAI_LIB_NAME "mvMotionAIShared")
	ADD_DEFINITIONS(-DMV_BUILD_DLL)
	SET(MV_LIB_FORMAT SHARED)
ELSE(SHARED_LIB_FORMAT)
	SET(MVMOTIONAI_LIB_NAME "mvMotionAI")
	REMOVE_DEFINITIONS(LIB_FORMAT)
	SET(MV_LIB_FORMAT STATIC)
ENDIF(SHARED_LIB_FORMAT)	   

ADD_LIBRARY(${MVMOTIONAI_LIB_NAME} ${MV_LIB_FORMAT} ${MV_SOURCE_FILES}
   ${MV_HEADER_FILES})
INCLUDE(FindOpenGL)
INCLUDE(FindGLUT)

SET(MV_TUTORIAL_1_DIR examples-src/tutorial1)
SET(MV_TUTORIAL_1_FILES ${MV_TUTORIAL_1_DIR}/tutorial1.cpp)
INCLUDE_DIRECTORIES(${MOTIONAI_INCLUDE_LOCATIONS})
SET(PROGRAM_NAME "tutorial1")
ADD_EXECUTABLE(${PROGRAM_NAME} ${MV_TUTORIAL_1_FILES}) 
TARGET_LINK_LIBRARIES(${PROGRAM_NAME} ${MVMOTIONAI_LIB_NAME})

SET(MV_TUTORIAL_2_DIR examples-src/tutorial2)
SET(GL_CAMERA_FILES examples-src/Camera.h examples-src/Camera.cpp)
INCLUDE_DIRECTORIES(${MOTIONAI_INCLUDE_LOCATIONS} ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})
SET(MV_TUTORIAL_2_FILES ${MV_TUTORIAL_2_DIR}/GLMain.cpp ${GL_CAMERA_FILES})
SET(PROGRAM_NAME "tutorial2")
ADD_EXECUTABLE(${PROGRAM_NAME} ${MV_TUTORIAL_2_FILES}) 
TARGET_LINK_LIBRARIES(${PROGRAM_NAME} ${MVMOTIONAI_LIB_NAME} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

SET(MV_TUTORIAL_3_DIR examples-src/tutorial3)
SET(MV_TUTORIAL_3_FILES ${MV_TUTORIAL_3_DIR}/CustomActionGLMain.cpp ${GL_CAMERA_FILES} ${MV_TUTORIAL_3_DIR}/TimedHop.cpp)
SET(PROGRAM_NAME "tutorial3")
ADD_EXECUTABLE(${PROGRAM_NAME} ${MV_TUTORIAL_3_FILES}) 
TARGET_LINK_LIBRARIES(${PROGRAM_NAME} ${MVMOTIONAI_LIB_NAME} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

IF(SHARED_LIB_FORMAT)
   SET(MV_LUA_INTERFACE_LIB mvLua-Shared)
ELSE(SHARED_LIB_FORMAT)
   SET(MV_LUA_INTERFACE_LIB mvLua)
ENDIF(SHARED_LIB_FORMAT)

IF(MINGW)
   FIND_LIBRARY(LUA_FOUND LUA_LIB PATHS lib-other/mingw/liblua5.1.a)
   FIND_PATH(LUA_HEADERS_FOUND LUA_INCLUDE_DIR include-other/mingw)
ELSE(MINGW)
   IF(MSVC)
      FIND_LIBRARY(LUA_FOUND LUA_LIB PATHS lib-other/mingw/liblua5.1.a)  
      FIND_PATH(LUA_HEADERS_FOUND LUA_INCLUDE_DIR include-other)      
   ELSE(MSVC)
      FIND_LIBRARY(LUA_FOUND LUA_LIB PATHS /usr/lib/liblua5.1.a)  
      FIND_PATH(LUA_HEADERS_FOUND LUA_INCLUDE_DIR /usr/include)       
   ENDIF(MSVC)
ENDIF(MINGW)

IF(LUA_FOUND AND LUA_HEADERS_FOUND)
  INCLUDE_DIRECTORIES(AFTER ${LUA_HEADERS_FOUND})
  SET(MV_LUA_SRC_FILES src/mvLua/mvLua_CFunctions.cpp src/mvLua/mvLua.cpp)
  ADD_LIBRARY(${MV_LUA_INTERFACE_LIB} ${MV_LIB_FORMAT} ${MV_LUA_SRC_FILES})
  TARGET_LINK_LIBRARIES(${MV_LUA_INTERFACE_LIB} ${MVMOTIONAI_LIB_NAME}
     ${LUA_FOUND})
     
   SET(PROGRAM_NAME "sideproject1")
   SET(MV_PROGRAM_FILES_DIR examples-src/sideproject1)
   SET(MV_SIDE_PROJECT_FILES ${MV_PROGRAM_FILES_DIR}/LuaGLTest.cpp 
      ${GL_CAMERA_FILES})   
   ADD_EXECUTABLE(${PROGRAM_NAME} ${MV_SIDE_PROJECT_FILES}) 
   TARGET_LINK_LIBRARIES(${PROGRAM_NAME} ${MV_LUA_INTERFACE_LIB}
      ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES} ${LUA_FOUND})
ENDIF(LUA_FOUND AND LUA_HEADERS_FOUND)

