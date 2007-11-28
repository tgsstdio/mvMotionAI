#include "AntiGravity.h"

AntiGravity::AntiGravity(mvOptionEnum forceKey)
{

}

virtual void AntiGravity::filter(mvForceStatus& worldStatus)
{

}

virtual bool AntiGravity::calcFullForces(mvForceResultPtr fResult)
{

}

AntiGravity::~AntiGravity()
{

}

AntiGravityLoader::AntiGravityLoader(mvOptionEnum forceKey)
 : typeKey(forceKey)
{

}

mvBaseForcePtr AntiGravityLoader::operator()(void* extraPtr)
{
   return new AntiGravcty(typeKey);
}

AntiGravityLoader::~AntiGravityLoader()
{

}

