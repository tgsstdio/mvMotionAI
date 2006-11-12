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
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

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
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "../include" /I "../include-other" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "mvStaticLibVC6 - Win32 Release"
# Name "mvStaticLibVC6 - Win32 Debug"
# Begin Group "Source Files - src"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE="..\src\mvBehaviour-Central.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvBehaviour-Clone.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvBehaviour-Entry.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvBehaviour-Flee.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvBehaviour-List.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvBehaviour-Pursuit.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvBehaviour-Seek.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvBehaviour-SimpleFlock.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvBehaviour-Type.cpp"
# End Source File
# Begin Source File

SOURCE=..\src\mvBehaviour.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvBody.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvEnums.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvForce.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvGroupBehaviour.cpp
# End Source File
# Begin Source File

SOURCE="..\src\mvLuaScript-Behaviour.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvLuaScript-Body.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvLuaScript-Force.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvLuaScript-Group.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvLuaScript-GroupBehaviour.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvLuaScript-Obstacle.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvLuaScript-Pathway.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvLuaScript-Utilities.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvLuaScript-Waypoint.cpp"
# End Source File
# Begin Source File

SOURCE="..\src\mvLuaScript-World.cpp"
# End Source File
# Begin Source File

SOURCE=..\src\mvLuaScript.cpp
# End Source File
# Begin Source File

SOURCE="..\src\mvMotionAI-Utilities.cpp"
# End Source File
# Begin Source File

SOURCE=..\src\mvMotionAI.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvObstacle.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvPathway.cpp
# End Source File
# Begin Source File

SOURCE="..\src\mvScript-Utilities.cpp"
# End Source File
# Begin Source File

SOURCE=..\src\mvVec3.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvWaypoint.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvWorld.cpp
# End Source File
# End Group
# Begin Group "Headers - include folder"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="..\include\mvBehaviour-Central.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvBehaviour-Clone.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvBehaviour-Entry.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvBehaviour-Flee.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvBehaviour-List.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvBehaviour-Pursuit.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvBehaviour-Seek.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvBehaviour-SimpleFlock.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvBehaviour-Type.h"
# End Source File
# Begin Source File

SOURCE=..\include\mvBehaviour.h
# End Source File
# Begin Source File

SOURCE=..\include\mvBody.h
# End Source File
# Begin Source File

SOURCE=..\include\mvEnums.h
# End Source File
# Begin Source File

SOURCE=..\include\mvForce.h
# End Source File
# Begin Source File

SOURCE=..\include\mvGroup.h
# End Source File
# Begin Source File

SOURCE=..\include\mvGroupBehaviour.h
# End Source File
# Begin Source File

SOURCE="..\include\mvLuaScript-Behaviour.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvLuaScript-Body.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvLuaScript-Force.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvLuaScript-Group.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvLuaScript-GroupBehaviour.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvLuaScript-Obstacle.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvLuaScript-Pathway.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvLuaScript-Utilities.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvLuaScript-Waypoint.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvLuaScript-World.h"
# End Source File
# Begin Source File

SOURCE=..\include\mvLuaScript.h
# End Source File
# Begin Source File

SOURCE="..\include\mvMotionAI-Types.h"
# End Source File
# Begin Source File

SOURCE="..\include\mvMotionAI-Utilities.h"
# End Source File
# Begin Source File

SOURCE=..\include\mvMotionAI.h
# End Source File
# Begin Source File

SOURCE=..\include\mvObstacle.h
# End Source File
# Begin Source File

SOURCE=..\include\mvPathway.h
# End Source File
# Begin Source File

SOURCE="..\include\mvScript-Utilities.h"
# End Source File
# Begin Source File

SOURCE=..\include\mvTarget.h
# End Source File
# Begin Source File

SOURCE=..\include\mvVec3.h
# End Source File
# Begin Source File

SOURCE=..\include\mvWaypoint.h
# End Source File
# Begin Source File

SOURCE=..\include\mvWorld.h
# End Source File
# End Group
# Begin Group "Headers - Experimental"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\experimental\include\mvBaseBehaviour.h

!IF  "$(CFG)" == "mvStaticLibVC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "mvStaticLibVC6 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvGlobalFunctions.h

!IF  "$(CFG)" == "mvStaticLibVC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "mvStaticLibVC6 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\experimental\include\mvList.h

!IF  "$(CFG)" == "mvStaticLibVC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "mvStaticLibVC6 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Source - Experimental"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\experimental\src\mvBaseBehaviour.cpp

!IF  "$(CFG)" == "mvStaticLibVC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "mvStaticLibVC6 - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
