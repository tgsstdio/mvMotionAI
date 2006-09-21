/**
 *\file mvScript-Utilities.h
 * Copyright (c) 2006 David Young.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef MV_SCRIPT_UTILITIES_H_
#define MV_SCRIPT_UTILITIES_H_
#include "mvEnum.h"

// mv obstacle enums functions check
mvEnum mvScript_checkObstacleType(const char* shape);
mvEnum mvScript_checkObstacleState(const char* state);
mvEnum mvScript_checkObstacleParamsFlag(const char* params);
mvEnum mvScript_checkObstacleParamsv(const char* params);
mvEnum mvScript_checkObstacleParamsFlagOptions(const char* option);
// mv waypoints enums functions check
mvEnum mvScript_checkWaypointType(const char* type);
mvEnum mvScript_checkWaypointShape(const char* shape);
mvEnum mvScript_checkWaypointParamsFlag(const char* params);
mvEnum mvScript_checkWaypointParamsv(const char* params);
mvEnum mvScript_checkWaypointParamsFlagOptions(const char* option);
// mv body script enums functions check
mvEnum mvScript_checkBodyType(const char* type);
mvEnum mvScript_checkBodyShape(const char* shape);
mvEnum mvScript_checkBodyParamsFlag(const char* params);
mvEnum mvScript_checkBodyParamsv(const char* params);
mvEnum mvScript_checkBodyParamsFlagOptions(const char* option);
// mv force type enum functions check
mvEnum mvScript_checkForceType(const char* type);
mvEnum mvScript_checkForceParamsFlag(const char* params);
mvEnum mvScript_checkForceParamsFlagOptions(const char* option);
mvEnum mvScript_checkForceParamsv(const char* params);
// mv behaviour type enum validators
mvEnum mvScript_checkBehaviourType(const char* type);
mvEnum mvScript_checkBehaviourParamsIndex(const char* params);
mvEnum mvScript_checkBehaviourParamsFlag(const char* params);
mvEnum mvScript_checkBehaviourParamsv(const char* params);
mvEnum mvScript_checkBehaviourParamsFlagOptions(const char* option);

//mv adding behaviours
mvEnum mvScript_checkAddBehaviourParams(const char* params);

// mv group behaviour
mvEnum mvScript_checkGroupBehaviourType(const char* type);
mvEnum mvScript_checkGroupBehaviourParamsIndex(const char* params);
mvEnum mvScript_checkGroupBehaviourParamsFlag(const char* params);
mvEnum mvScript_checkGroupBehaviourParamsv(const char* params);
mvEnum mvScript_checkGroupBehaviourParamsFlagOptions(const char* option);
#endif





