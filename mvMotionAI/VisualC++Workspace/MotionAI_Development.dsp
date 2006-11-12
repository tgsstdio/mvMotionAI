# Microsoft Developer Studio Project File - Name="MotionAI_Development" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=MotionAI_Development - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MotionAI_Development.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MotionAI_Development.mak" CFG="MotionAI_Development - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MotionAI_Development - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "MotionAI_Development - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MotionAI_Development - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "incluide" /I "include" /I "../include" /I "../include-other" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 freeglut.lib lua50.lib /nologo /subsystem:console /machine:I386 /out:"../bin/mvMotionAI.exe" /libpath:"lib" /libpath:"../lib" /libpath:"../lib-other"

!ELSEIF  "$(CFG)" == "MotionAI_Development - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "../include" /I "../include-other" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 freeglut-debug.lib lua50.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"../lib" /libpath:"../lib-other"

!ENDIF 

# Begin Target

# Name "MotionAI_Development - Win32 Release"
# Name "MotionAI_Development - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\mvBody.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvEnum.cpp
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

SOURCE=..\src\mvVec3.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvWaypoint.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mvWorld.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\mvBody.h
# End Source File
# Begin Source File

SOURCE=..\include\mvEnum.h
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
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\misc\EditedCode.txt
# End Source File
# Begin Source File

SOURCE=..\bin\Test.lua
# End Source File
# End Group
# Begin Group "mvLuaScript Headers"

# PROP Default_Filter ""
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
# End Group
# Begin Group "mvLuaScript Source Files"

# PROP Default_Filter ""
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
# End Group
# Begin Group "Executable Code"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\examples-src\Camera.cpp"
# End Source File
# Begin Source File

SOURCE="..\examples-src\Camera.h"
# End Source File
# Begin Source File

SOURCE="..\examples-src\GLMain.cpp"
# End Source File
# Begin Source File

SOURCE="..\examples-src\Template.cpp"
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE="..\examples-src\TemplateTest.cpp"
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE="..\examples-src\TestAI.cpp"
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "Script central files"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\src\mvScript-Utilities.cpp"
# End Source File
# Begin Source File

SOURCE="..\include\mvScript-Utilities.h"
# End Source File
# End Group
# Begin Group "mvBehaviour source files"

# PROP Default_Filter "cpp"
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
# End Group
# Begin Group "mvBehaviour headers files"

# PROP Default_Filter "h"
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
# End Group
# Begin Group "Prototype files"

# PROP Default_Filter "cpp h c"
# Begin Source File

SOURCE=..\include\mvProto_Behaviour.h
# End Source File
# End Group
# End Target
# End Project
