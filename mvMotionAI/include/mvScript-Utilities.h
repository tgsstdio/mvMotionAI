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
#include "mvEnums.h"

// mv obstacle enums functions check
mvErrorEnum mvScript_checkObstacleShape(const char* shape, mvOptionEnum& dest);
mvErrorEnum mvScript_checkObstacleType(const char* type, mvOptionEnum& dest);
mvErrorEnum mvScript_checkObstacleParamsFlag(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkObstacleParamsv(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkObstacleParamsFlagOptions(const char* option, mvOptionEnum& dest);
// mv waypoints enums functions check
mvErrorEnum mvScript_checkWaypointType(const char* type, mvOptionEnum& dest);
mvErrorEnum mvScript_checkWaypointShape(const char* shape, mvOptionEnum& dest);
mvErrorEnum mvScript_checkWaypointParamsFlag(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkWaypointParamsv(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkWaypointParamsFlagOptions(const char* option, mvOptionEnum& dest);
// mv body script enums functions check
mvErrorEnum mvScript_checkBodyType(const char* type, mvOptionEnum& dest);
mvErrorEnum mvScript_checkBodyShape(const char* shape, mvOptionEnum& dest);
mvErrorEnum mvScript_checkBodyParamsFlag(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkBodyParamsv(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkBodyParamsFlagOptions(const char* option, mvOptionEnum& dest);
// mv force type enum functions check
mvErrorEnum mvScript_checkForceType(const char* type, mvOptionEnum& dest);
mvErrorEnum mvScript_checkForceParamsFlag(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkForceParamsFlagOptions(const char* option, mvOptionEnum& dest);
mvErrorEnum mvScript_checkForceParamsv(const char* params, mvParamEnum& dest);
// mv behaviour type enum validators
mvErrorEnum mvScript_checkBehaviourType(const char* type, mvOptionEnum& dest);
mvErrorEnum mvScript_checkBehaviourParamsIndex(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkBehaviourParamsFlag(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkBehaviourParamsv(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkBehaviourParamsFlagOptions(const char* option, mvOptionEnum& dest);

//mv adding behaviours
mvErrorEnum mvScript_checkAddBehaviourOption(const char* params, mvOptionEnum& dest);

// mv group behaviour
mvErrorEnum mvScript_checkGroupBehaviourType(const char* type, mvOptionEnum& dest);
mvErrorEnum mvScript_checkGroupBehaviourParamsIndex(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkGroupBehaviourParamsFlag(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkGroupBehaviourParamsv(const char* params, mvParamEnum& dest);
mvErrorEnum mvScript_checkGroupBehaviourParamsFlagOptions(const char* option, mvOptionEnum& dest);
#endif





