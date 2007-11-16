mvMotionAI binaries README file

For running mvMotionAI examples (tested on Windows XP):

tutorial1: 
This program shows how to access the mvMotionAI objects via its API interface.

tutorial2:
This program shows how to link an OpenGL application (or any real time application) to the mvMotionAI using its C interface.

tutorial3:
This program extends the code in tutorial2 and shows a user-defined behaviour 
or (mvBaseAction) in action.

The sample applications tutorial2, tutorial3 & sideproject1 require an
installation of OpenGL & GLUT on the system. The example binaries use 
a precompiled DLL library of freeglut (http://freeglut.sourceforge.net/).

sideproject1 :
This program (and its source code) are compiled with Lua 5.1 library
for loading scripting files and displaying it in OpenGL/GLUT application. 
To run the sideproject1, use the following command line argument:

> sideproject1 <script_file>
If no filename is passed then make sure that at least Test.lua is accessible
when calling the application. Source code of the mvMotionAI Lua interface 
can be found in the src/mvLua directory.

The various examples script files included are :
Flee.lua - show a body moving away from a waypoint
Test.lua - objects under gravity
Seek.lua - moving towards a waypoint
Pursuit.lua - chasing after a body
FollowPath.lua - following a pathway made up of mvWaypoints
Evasion.lua - avoiding a body with wander like motion.

The various DLLs of other libraries (freeglut) can be found in bin directory.
All programs contained in this package are under the MIT license or in COPYING
file.

For developers:
The example source can be found in the example-src directory via Subversion
(http://subversion.tigris.org/)

The source code of mvMotionAI library (http://mvmotionai.sourceforge.net/) 
can be accessed by using the following Subversion command:

> svn co https://mvmotionai.svn.sourceforge.net/svnroot/mvmotionai mvmotionai

David Young
2006, 16th Nov 2007.

