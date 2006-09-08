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





