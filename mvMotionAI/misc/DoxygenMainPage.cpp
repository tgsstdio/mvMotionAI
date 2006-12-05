#ifndef MOTION_AI_MAIN_PAGE_CPP_
#define MOTION_AI_MAIN_PAGE_CPP_

/*! \mainpage Motion AI (mvMotionAI) - movement based artificial intelligence for 3D objects
 *  
 * \section intro_sec Introduction
 *
 * Basic motion/velocity integrator library for 3D worlds with 
 * basic behaviours for C++ programs. An important part is the
 * scripting capabilities which allows easy file loading of
 * AI settings. Currently the script library Lua is used and
 * is open source under the MIT license.
 *
 * mvMotionAI is a C/C++ & Lua based artificial intelligence 
 * module dealing with motion type actions such as one body follow 
 * another or moving towards a single point. These types of actions
 * are referred as steering behaviours. As well as these common 
 * behaviours, this library uses a scripting language, so the various
 * settings of each behaviour can be changed without recompiling the program.
 *
 * mvMotionAI uses a OpenGL function interface, as most of the functions 
 * in the library have a prefix of 'mv'.  The main class in the library
 * is the mvWorld, which contains all of the minor classes. mvWorlds
 * contain mvForce (gravity, wind, direction pull), mvObstacles 
 * (non-moving objects which are not yet implemented), mvWaypoints 
 * (points or markers in the world).
 *
 * In the library, each moving item such as a car, a bird or person 
 * is represented as a mvBody. Each mvBody has various properties such as
 * its position, maximum speed, direction in the world. These bodies can
 * be grouped together, Each behaviour has already been written in the
 * library, so there is no feature yet implemented which allows 
 * completely new behaviours to created at run-time.
 * 
 * \section install_sec Installation
 *
 * \subsection step1 Current installation method:
 * Compile source code with own projects, with Lua 5.0 library modules.
 *
 * \subsection step2 Future installation
 * DLLs and lib 
 *  
 * etc...
 *
 * \section progress Current Progress in library module
 * (ver 00-01-21 : date 21/9/06)  
 * documentation and Lua script support
 * 
 * \section otherpages Other Pages
 * - \subpage logpage
 */
 
/**
 * \page logpage Log
 * \section mvMotionAI Log
 * \subsection log_columns Version     Date     Comments
 * 
 * version 00-01-21
 * = add more lua script loading functions   
 * - changed naming conventions
 * - added more documentation
 * - changed/added/merged enumerations in mvEnums.h
 *
 * 00-01-20
 * - changed libmvMotionAI to libmvMotion-mingw.a 
 * - added more Doxygen documentation
 * - checked updated Code::Blocks workspace
 *
 * 00-01-19
 * - added more readme .txt files in include-other, lib-other, lib, bin
 *
 * 00-01-18
 * - added ubuntu Code::Blocks project options
 * - added ubuntu dapper drake i386 example applications
 *
 * 00-01-17
 * - implemented more set and get functionality for
 *  -# mvWorld
 *  -# mvBody
 *  -# mvObstacle
 *  -# mvGroup
 *  -# mvGroupBehaviour
 *  -# mvBehaviour
 * - changed magic lua pop index numbers for named constants for
 *   debugging purposes
 * - implement world nudge body + lua functions
 * - implemented Lua equivalent functions for set/get functions
 * - updated MVC6 workspace : some errors (behaviours not operating correctly)
 * - TODO : pathway functions
 * 
 * 00-01-16
 * - enumeration mvEnum split into 3 different enumeration types
 *   -# mvParamEnum - parameter query enum type for retrieving / setting values
 *   -# mvErrorEnum - error return values
 *   -# mvOptionEnum - state and type values
 * - update function type
 * - updated sample programs for new enumerations
 *
 * 00-01-15
 * - added MIT licenses to headers and source files
 * - added + implemented, Lua support functions, application in headers
 *   & sources,
 * - Code::Blocks project files, shows a list of implemented Lua functions.
 * - added an executable for mvMotionAI types.
 * - added documentation.
 * - added Log.txt
 *
 * 00-01-05 (27/6/06) - 00-01-14 (21/09/06)
 * 
 * - added mvMotionAI to SourceForge.org
 *   
 * - behaviour framework is made up of individual behaviours, global behaviour
 *   and global group behaviours
 *   
 * - Code::Blocks IDE workspaces included with MSVC++ 6 workspace
 *  
 * - Source code in src, headers in include, dependencies in
 *   lib-other & include-other, examples included in example-src,
 *   misc files in misc, documentation in docs,
 *
 * - types headers included
 *
 * - more log entries inside Log.txt 
 *  
 *
 *00-01-04    27/6/06   
 * - added pursuit & clone behaviour
 *                         
 *
 *00-01-03    21/6/06 
 * - split enums and their string into header and source file.
 * - added processing to behaviours with central function 
 *   -# mvProcessBodyBehaviours
 * - added lua functions for get, remove waypoint functions
 * - added lua functions for get, remove, add waypoint, add to body
 *   functions
 * - split enums and their string into header and source file.
 * - iterator has now working behaviours
 * - added behaviour list to mvBody class
 * - now using index values instead of pointers, finally
 *  implemented two beahviours SEEK and FLEE, 
 *
 *00-01-02  31/5/06 
 *  - removing groups from system until better solution arrives.
 *
 * 00-01-01  24/5/06  
 * - Massive overhaul of class names and functions
 *  -# Should progress into creating the first actual behaviour types. 
 * Behaviours types likely to be added shortly are CLONE, SEEK, FLEE and 
 * PATH FOLLOWING & started work to accommediate SEEK, FLEE, CLONE 
 * & FOLLOW PATH support functions
 *
 * 00-01-00   22/5/06  
 * - rename mWorld into mvWorld, allowed forces and groups 
 * - initialised behaviours
 * - renamed Obstacles into mvObstacle
 * - renamed particles and vehicles, grouped them into a group
 *   under the name of mvBody.
 * - renamed target to mvWaypoint.
 * - renamed pathways to mvPathway
 * - Headers file : Template functions are hard to split
 * - initialised forces
 * - initialised groups
 * - new naming conventions - mv(blah)
 *
 * 00-00-08     9/3/06  
 * - Currently adding a new class; a immediate  class called Target
 *   to build relationship (i.e behaviour with various objects)
 *
 * 00-00-07		9/3/06
 * - initialised Target Object
 *
 * 00-00-06		6/3/06
 * - initialised particle 
 * - add particles and various modifiers to script 
 * - adding (hopefully) a temporary Particle array and to mWorld
 *   so I can prototype behaviour early.
 *
 * 00-00-05    3/3/06
 * - vehicle : intergration for motion. 
 * - adding basic intergrater (Improved Euler) to m world.
 * - introducing shapes in obstacle
 * - adding motion variables modifiers
 *
 * 00-00-04    22/02/06   
 * - Separated MotionAI to allow multiple instances 
 * - Hopefully created a overall central module and many world objects
 * - added world ID variable 
 * - split central motionAI to world components 
 *
 * 00-00-03		14/2/06
 * - declared Pathway class
 * - created simple array of waypoints which can be loaded in
 *  by scripts 
 * - declared single function loadLuaScriptFunctions to make code
 *   more modular and less dependant.
 * - move script function prototypes out of header file into source code  
 *
 * 00-00-02    8/2/06
 * - separated obstacle and vehicle into their own header and source files
 * - separated from MotionAI.h, created new header and source file.
 * - Script : declared beginPathway and endPathWay
 *
 * 00-00-01    7/2/06
 * - created header file based on Opensteer
 * - created a overall AI module called MotionAI
 * - stubs of vehicles and obstacles
 * - To use library, declare global instance of aiModule.
 * - introduced Vec3 and Utilities from OpenSteer into project
 * - Script.h & .cpp : created file
 * - added scripting language to MotionAI
 * - loads lua script files and adds vehicles and obstacles
 * - created file for all headers need in MotionAI module
 */

#endif

