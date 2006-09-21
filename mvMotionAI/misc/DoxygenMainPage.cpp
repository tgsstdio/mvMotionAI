#ifndef MOTION_AI_MAIN_PAGE_CPP_
#define MOTION_AI_MAIN_PAGE_CPP_

/*! \mainpage Motion AI - movement based artificial intelligence for 3D objects
 *  
 * \section intro_sec Introduction
 *
 * This module is based on the OpenSteer library/program 2005.
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
 * (ver 00-01-15 : date 21/9/06)  
 * documentation and Lua script support
 *
 *
 * \section Log
 * \subsection log_columns Version     Date     Comments
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
 *00-01-04    27/6/06   - added pursuit & clone behaviour
 *                         
 *
 *00-01-03    21/6/06   - split enums and their string into header and source file.
 *
 *                      - added processing to behaviours with central function : mvProcessBodyBehaviours 
 * 
 *                      - added lua functions for get, remove
 *                      waypoint functions
 *
 *                      - added lua functions for get, remove, add waypoint, add to body
 *                       functions
 *
 *                     - split enums and their string into header and source file.
 *
 *
 *                      - iterator has now working behaviours
 *
 *                     - added behaviour list to mvBody class
 *
 *                    - now using index values instead of pointers, finally
 *                     implemented two beahviours SEEK and FLEE,                    
 *
 *00-01-02  31/5/06  - removing groups from system until better solution
 *                     arrives.
 *
 * 00-01-01  24/5/06    Massive overhaul of class names and functions
 *                  Should progress into creating the first actual behaviour types. Behaviours types likely to 
 *                  be added shortly are CLONE, SEEK, FLEE and PATH FOLLOWING & started work to accommediate 
 *                 SEEK, FLEE, CLONE & FOLLOW PATH support functions
 *
 * 00-01-00   22/5/06   - rename mWorld into mvWorld, allowed forces and 
 *                     groups  
 *
 *                      - initialised behaviours
 *
 *
 *                      - renamed Obstacles into mvObstacle
 *
 *
 *                      - renamed particles and vehicles, grouped them into a group
 *                     under the name of mvBody.
 *
 *
 *                      - renamed target to mvWaypoint.
 *
 *
 *                      - renamed pathways to mvPathway
 *
 *
 *                      - Headers file : Template functions are hard to split
 *
 *
 *                      - initialised forces
 *
 *
 *                      - initialised groups
 *
 *
 *                      - new naming conventions - mv(blah)
 *
 * 00-00-08     9/3/06  
 * - Currently adding a new class; a immediate 
 *                         class called Target to build relationship (i.e behaviour with various objects)
 *
 * 00-00-07		9/3/06
 * - initialised Target Object
 *
 * 00-00-06		6/3/06
 * - initialised particle 
 *
 *                         - add particles and various modifiers to script 
 *
 *                         - adding (hopefully) a temporary Particle array and
 * to mWorld so I can prototype behaviour early.
 *
 * 00-00-05    3/3/06
 * - vehicle : intergration for motion. 
 *
 *                         - adding basic intergrater (Improved Euler)
 * to m world.
 *                         - introducing shapes in obstacle
 *
 *                         - adding motion variables modifiers
 *
 * 00-00-04    22/02/06   
 *                         - Separated MotionAI to allow multiple instances 
 *
 *                         - Hopefully created a overall central module 
 *                      and many world objects
 *
 *                         - added world ID variable 
 *
 *                         - split central motionAI to world components 
 *
 * 00-00-03		14/2/06
 * - declared Pathway class
 *
 *                         - created simple array of waypoints whci can be loaded in
 *                         by scripts 
 *
 *                         - declared single function loadLuaScriptFunctions
 *                      to make code more modular and less dependant.
 *
 *                         - move script function prototypes out of header file into source code  
 *
 *
 * 00-00-02    8/2/06
 * - separated obstacle and vehicle into their own
 *                     header and source files
 *
 *                         - separated from MotionAI.h, created new 
 *                     header and source file.
 *
 *                         - Script : declared beginPathway and endPathWay
 *
 * 00-00-01    7/2/06
 * - created header file based on Opensteer
 *
 *                         - created a overall AI module called MotionAI
 *                       
 *                         - stubs of vehicles and obstacles
 *
 *                         - To use library, declare global instance of aiModule.
 *
 *                         - introduced Vec3 and Utilities from OpenSteer into project
 *                           
 *                         - Script.h & .cpp : created file
 *
 *                         - added scripting language to MotionAI
 *
 *                         - loads lua script files and adds vehicles
 *                     and obstacles
 *
 *                         - created file for all headers need in 
 *                    MotionAI module
 *
 *
 *                      -
 *
 *
 *                      -
 *
 *
 *                      -
 *
 */

#endif

