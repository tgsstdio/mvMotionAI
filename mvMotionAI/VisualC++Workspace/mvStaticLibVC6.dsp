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

SOURCE=..\src\mvBehaviour_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvBEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvBEntryList.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvBEntryListNode.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvBEntryTimer.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvBEntryUtility.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvBody_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvBodyCapsule.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvEnums.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvForceCapsule.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvGroup_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvGroupBehaviour_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvGroupBNode_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvGroupCapsule.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvIndexSet.cpp
# End Source File
# Begin Source File

SOURCE="..\src\mvMotionAI-Utilities.cpp"
# End Source File
# Begin Source File

SOURCE=..\src\mvMotionAI.cpp
# End Source File
# Begin Source File

SOURCE="..\src\mvMotionAI_V2-Central.cpp"
# End Source File
# Begin Source File

SOURCE=..\src\mvObstacle_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvPathway_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvShape.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvVec3.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvWaypoint_V2.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvWaypointCapsule.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvWorld2.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvWorld2_Functions.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvWorld2_Functions.h
# End Source File
# End Group
# Begin Group "Headers - include folder"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\mv\mvActionLoaderList.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBaseAction.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBehaviour_V2.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBEntry.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBEntryList.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBEntryListNode.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBEntryTimer.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBEntryUtility.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBody_V2.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBodyCapsule.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvCapsuleList.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvEnums.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvFactoryFunctionList.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvFlee.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvForceCapsule.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvForceLoaderList.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvGroup_V2.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvGroupBehaviour_V2.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvGroupBNode_V2.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvGroupCapsule.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvIndexSet.h
# End Source File
# Begin Source File

SOURCE="..\include\mv\mvMotionAI-Types.h"
# End Source File
# Begin Source File

SOURCE="..\include\mv\mvMotionAI-Utilities.h"
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvMotionAI.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvNullLoader.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvObstacle_V2.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvPathway_V2.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvPointerList.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvShape.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvVec3.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvWaypoint_V2.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvWaypointCapsule.h
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvWorld2.h
# End Source File
# End Group
# Begin Group "mvBaseActions"

# PROP Default_Filter ".cpp;.h"
# Begin Source File

SOURCE=..\src\mvBaseAction.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvBehaviourResult.cpp
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBehaviourResult.h
# End Source File
# Begin Source File

SOURCE=..\src\mvFlee.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvGroupBehaviourResult.cpp
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvGroupBehaviourResult.h
# End Source File
# Begin Source File

SOURCE=..\src\mvNullLoader.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvPursuit.cpp
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvPursuit.h
# End Source File
# Begin Source File

SOURCE=..\src\mvSeek.cpp
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvSeek.h
# End Source File
# End Group
# Begin Group "mvBaseForces"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\mvBaseForce.cpp
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvBaseForce.h
# End Source File
# Begin Source File

SOURCE=..\src\mvForceResult.cpp
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvForceResult.h
# End Source File
# Begin Source File

SOURCE=..\src\mvGravityForce.cpp
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvGravityForce.h
# End Source File
# Begin Source File

SOURCE=..\src\mvUniformAccelForce.cpp
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvUniformAccelForce.h
# End Source File
# Begin Source File

SOURCE=..\src\mvUniformForce.cpp
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvUniformForce.h
# End Source File
# Begin Source File

SOURCE=..\src\mvUniformShiftForce.cpp
# End Source File
# Begin Source File

SOURCE=..\include\mv\mvUniformShiftForce.h
# End Source File
# End Group
# End Target
# End Project
