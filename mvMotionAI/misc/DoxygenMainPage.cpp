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
 * be grouped together. Some of the behaviour (or mvBaseActions) has been
 * been written in the library and now in version 00-02-00+ there is a 
 * feature in the library which allows completely new user-defined
 * behaviours to added at compile time (but not yet run-time).
 * 
 * \section install_sec Installation
 *
 * \subsection step1 Current installation method:
 * Compile source code with own projects, with Lua 5.1 library modules.
 *
 * \subsection step2 Future installation
 * To use the library with a project, there must be a STL 
 * (such as vector, list and sets) implementation along with the C++ compiler.
 * 
 * To incorporate the mvMotionAI library, only one file/line is needed to be 
 * included/declared in your code.
 *
 * \#include \<mv/mvMotionAI.h\>
 * 
 * To build a shared library, add the flag MV_BUILD_DLL to compiler process.
 *
 * To build a static library, leave out the MV_BUILD_DLL flag when compiling.
 *
 * \section progress Current Progress in library module
 * (ver 00-02-25 : date 18/10/07)  
 * Adding more documentation in mvMotionAI C interface.
 * 
 * \section other_pages Other pages
 * - \subpage readme_txt
 * - \subpage logpage
 * - \subpage license
 * - \subpage authors
 * - \subpage todo_page 
 */

#endif

