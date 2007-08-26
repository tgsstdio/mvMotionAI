# Microsoft Developer Studio Project File - Name="mvStaticLibVC6" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=mvStaticLibVC6 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mvStaticLibVC6.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mvStaticLibVC6.mak" CFG="mvStaticLibVC6 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mvStaticLibVC6 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mvStaticLibVC6 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mvStaticLibVC6 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "../include" /I "../experimental/include" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "VISUAL_C_VER_6" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../lib/libmvMotionAI-vc6.lib"

!ELSEIF  "$(CFG)" == "mvStaticLibVC6 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "../experimental/include" /I "../include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "VISUAL_C_VER_6" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../lib/libmvMotionAI-vc6-debug.lib"

!ENDIF 

# Begin Target

# Name "mvStaticLibVC6 - Win32 Release"
# Name "mvStaticLibVC6 - Win32 Debug"
# Begin Group "Source - src folder"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\mvEnums.cpp
# End Source File
# Begin Source File

SOURCE="..\src\mvMotionAI-Utilities.cpp"
# End Source File
# Begin Source File

SOURCE=..\src\mvVec3.cpp
# End Source File
# End Group
# Begin Group "Headers - include folder"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\mvEnums.h
# End Source File
# Begin Source File

SOURCE="..\include\mvMotionAI-Types.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvMotionAI-Utilities.h"
# End Source File
# Begin Source File

SOURCE=..\include\mvVec3.h
# End Source File
# End Group
# Begin Group "Headers - experimental/include"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\experimental\include\mvActionLoaderList.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBehaviour_V2.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBehaviourResult.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBody_V2.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBodyCapsule.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvCapsuleList.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvCapsuleList.hpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvFactoryFunctionList.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvFactoryFunctionList.hpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvForceCapsule.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvForceLoaderList.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvGBNodeMemberList.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvGroup_V2.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvGroupBehaviour_V2.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvGroupBNode_V2.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvGroupCapsule.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvIndexSet.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvMotionAI.h
# End Source File
# Begin Source File

SOURCE="..\experimental\include\mvMotionAI_V2-Central.h"
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvObstacle_V2.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvPathway_V2.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvPointerList.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvPointerList.hpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvShape.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvWaypoint_V2.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvWaypointCapsule.h
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvWorld2.h
# End Source File
# End Group
# Begin Group "Source - experimental/src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\experimental\src\mvBehaviour_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvBehaviourResult.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvBody_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvBodyCapsule.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvForceCapsule.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvGroup_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvGroupBehaviour_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvGroupBNode_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvGroupCapsule.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvIndexSet.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvMotionAI.cpp
# End Source File
# Begin Source File

SOURCE="..\experimental\src\mvMotionAI_V2-Central.cpp"
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvObstacle_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvPathway_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvShape.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvWaypoint_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvWaypointCapsule.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvWorld2.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvWorld2_Functions.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvWorld2_Functions.h
# End Source File
# End Group
# Begin Group "mvBaseForces"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\experimental\src\mvBaseForce.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBaseForce.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvForceResult.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvForceResult.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvGravityForce.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvGravityForce.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvUniformAccelForce.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvUniformAccelForce.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvUniformForce.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvUniformForce.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvUniformShiftForce.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvUniformShiftForce.h
# End Source File
# End Group
# Begin Group "mvBaseActions"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\experimental\src\mvBaseAction.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBaseAction.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvFlee.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvFlee.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvGroupBehaviourResult.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvGroupBehaviourResult.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvNullLoader.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvNullLoader.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvPursuit.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvPursuit.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvSeek.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvSeek.h
# End Source File
# End Group
# Begin Group "mvEntryList"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\experimental\src\mvBEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBEntry.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvBEntryList.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBEntryList.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvBEntryListNode.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBEntryListNode.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvBEntryTimer.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBEntryTimer.h
# End Source File
# Begin Source File

SOURCE=..\experimental\src\mvBEntryUtility.cpp
# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvBEntryUtility.h
# End Source File
# End Group
# End Target
# End Project
