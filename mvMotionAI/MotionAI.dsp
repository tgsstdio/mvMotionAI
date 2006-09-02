# Microsoft Developer Studio Project File - Name="MotionAI" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=MotionAI - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MotionAI.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MotionAI.mak" CFG="MotionAI - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MotionAI - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "MotionAI - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MotionAI - Win32 Release"

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
# ADD CPP /nologo /W3 /GX /O2 /I "include" /I "..include" /I "../include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 lua51.lib /nologo /subsystem:console /machine:I386 /libpath:"../lib"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

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
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..include" /I "include" /I "../include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 lua50.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"../lib"
# SUBTRACT LINK32 /nodefaultlib

!ENDIF 

# Begin Target

# Name "MotionAI - Win32 Release"
# Name "MotionAI - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Behaviour.cpp
# End Source File
# Begin Source File

SOURCE=..\Camera.cpp
# End Source File
# Begin Source File

SOURCE=.\GLMain.cpp

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MotionAI.cpp
# End Source File
# Begin Source File

SOURCE=.\MWorld.cpp
# End Source File
# Begin Source File

SOURCE=.\Obstacle.cpp
# End Source File
# Begin Source File

SOURCE=.\Particle.cpp
# End Source File
# Begin Source File

SOURCE=.\Pathway.cpp
# End Source File
# Begin Source File

SOURCE=.\Vec3.cpp
# End Source File
# Begin Source File

SOURCE=.\Vehicle.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Behaviour.h
# End Source File
# Begin Source File

SOURCE=..\Camera.h
# End Source File
# Begin Source File

SOURCE=.\MotionAI.h
# End Source File
# Begin Source File

SOURCE=.\MWorld.h
# End Source File
# Begin Source File

SOURCE=.\Obstacle.h
# End Source File
# Begin Source File

SOURCE=.\Particle.h
# End Source File
# Begin Source File

SOURCE=.\Pathway.h
# End Source File
# Begin Source File

SOURCE=.\Target.h
# End Source File
# Begin Source File

SOURCE=.\Unimotor.h
# End Source File
# Begin Source File

SOURCE=.\Utilities.h
# End Source File
# Begin Source File

SOURCE=.\Vec3.h
# End Source File
# Begin Source File

SOURCE=.\Vehicle.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\PROJECT\AbstractVehicle.h

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ADDcODE.PDF

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DOxygenMainPage.h

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\Test.lua

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Lua Script Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\Script-Behaviour.cpp"
# End Source File
# Begin Source File

SOURCE=".\Script-Behaviour.h"
# End Source File
# Begin Source File

SOURCE=".\Script-MWorld.cpp"
# End Source File
# Begin Source File

SOURCE=".\Script-MWorld.h"
# End Source File
# Begin Source File

SOURCE=".\Script-Obstacle.cpp"
# End Source File
# Begin Source File

SOURCE=".\Script-Obstacle.h"
# End Source File
# Begin Source File

SOURCE=".\Script-Particle.cpp"
# End Source File
# Begin Source File

SOURCE=".\Script-Particle.h"
# End Source File
# Begin Source File

SOURCE=".\Script-Pathway.cpp"
# End Source File
# Begin Source File

SOURCE=".\Script-Pathway.h"
# End Source File
# Begin Source File

SOURCE=".\Script-Vehicle.cpp"
# End Source File
# Begin Source File

SOURCE=".\Script-Vehicle.h"
# End Source File
# Begin Source File

SOURCE=.\Script.cpp
# End Source File
# Begin Source File

SOURCE=.\Script.h
# End Source File
# End Group
# Begin Group "New Template Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Collision.cpp
# End Source File
# Begin Source File

SOURCE=.\mvBehaviour.h

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mvBody.cpp
# End Source File
# Begin Source File

SOURCE=.\mvBody.h

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mvEnum.h

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mvGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\mvGroup.h

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mvMotionAI.h
# End Source File
# Begin Source File

SOURCE=.\mvObstacle.cpp
# End Source File
# Begin Source File

SOURCE=.\mvObstacle.h

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mvPathway.cpp
# End Source File
# Begin Source File

SOURCE=.\mvPathway.h

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mvWaypoint.cpp
# End Source File
# Begin Source File

SOURCE=.\mvWaypoint.h

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mvWorld.cpp
# End Source File
# Begin Source File

SOURCE=.\mvWorld.h

!IF  "$(CFG)" == "MotionAI - Win32 Release"

!ELSEIF  "$(CFG)" == "MotionAI - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TemplateTest.cpp
# End Source File
# End Group
# End Target
# End Project
