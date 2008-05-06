#include "PhysicsController.h"
#define MATRIX_X_POS_INDEX (12)
#define MATRIX_Y_POS_INDEX (13)
#define MATRIX_Z_POS_INDEX (14)
#define MATRIX_W_POS_INDEX (15)
#define RAD_TO_DEGREES (57.295779513082320876798154814105)


static void SetTransformationForMotionAI_And_LF(const NewtonBody* body,
   const float* matrix)
{
   mvVec3 currentBodyPos;
   dFloat bodyMatrix[16];
   lf::core::vector3df tempVector;
   mvBodyPtr currentBody = MV_NULL;
   PhysicsController* currentPC = (PhysicsController*) NewtonBodyGetUserData(body);
   lf::scene::CSceneNode* controlledNode = NULL;

   if (currentPC != NULL)
   {
      currentBody = mvGetBodyPtr(currentPC->getPhysicsModule()->getWorldIndex(),\
         currentPC->getBodyIndex());

      controlledNode = currentPC->getControlledObject();
      if (currentBody != MV_NULL && controlledNode != NULL)
      {

         // set positions

            // mvMotionAI
         currentBodyPos.set(matrix[MATRIX_X_POS_INDEX],
            matrix[MATRIX_Y_POS_INDEX],
            matrix[MATRIX_Z_POS_INDEX]);
         currentBody->setPosition(currentBodyPos);
            // CSceneNode
         tempVector.set(matrix[MATRIX_X_POS_INDEX],matrix[MATRIX_Y_POS_INDEX],\
            matrix[MATRIX_Z_POS_INDEX]);
         controlledNode->setPosition(tempVector);

         // set angle
         NewtonGetEulerAngle(matrix,&bodyMatrix[0]);
            // current form is in radians
         currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         currentBodyPos *= RAD_TO_DEGREES;
         currentBody->setRotation(currentBodyPos);
            // C Scene Node
         tempVector.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         //tempVector *= RAD_TO_DEGREES;
         controlledNode->setRotation(tempVector);

         // set final velocity
         NewtonBodyGetVelocity(body, &bodyMatrix[0]);
         currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         currentBody->setFinalVelocity(currentBodyPos);

         // set final force
         NewtonBodyGetForce(body, &bodyMatrix[0]);
         currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         currentBody->setFinalForce(currentBodyPos);

         // set final torque
         NewtonBodyGetTorque(body, &bodyMatrix[0]);
         currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         currentBody->setFinalTorque(currentBodyPos);

         // set final omega (in units/per second)
         NewtonBodyGetOmega(body, &bodyMatrix[0]);
         currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         currentBody->setFinalOmega(currentBodyPos);

      }
   }
}

static void GetForcesFromMotionAI (const NewtonBody* body)
{
   dFloat forces[3];
   mvVec3 tempVector;
   PhysicsController* currentPC = (PhysicsController*) NewtonBodyGetUserData(body);
   mvBodyPtr currentBody = NULL;

   if (currentPC == NULL)
   {
      return;
   }

   currentBody = mvGetBodyPtr(currentPC->getPhysicsModule()->getWorldIndex(),\
      currentPC->getBodyIndex());

   if (currentBody == NULL)
   {
      return;
   }

   tempVector = currentBody->getFinalForce();
   forces[0] = tempVector.getX();
   forces[1] = tempVector.getY();
   forces[2] = tempVector.getZ();
   NewtonBodySetForce (body, forces);

   tempVector = currentBody->getFinalTorque();
   forces[0] = tempVector.getX();
   forces[1] = tempVector.getY();
   forces[2] = tempVector.getZ();
   NewtonBodySetTorque (body, forces);
}


/** @brief PhysicsController
  *
  * @todo: document this function
  */
PhysicsController::PhysicsController(scene::CSceneNode* node,\
      PhysicsModule* phyModule, mvOptionEnum shapeEnum, bool isDebugging) :
   CSceneNodeController(node), debugModel(NULL)
{
   objectType = "PhysicsController";

   lf::core::vector3df initialPos = controlledNode->getPosition();

   PC_ShapeEnum objectShape = PC_CYLINDER;

   if (shapeEnum == MV_AABOX)
   {
      objectShape = PC_BOX;
   }
   else if (shapeEnum == MV_SPHERE)
   {
      objectShape = PC_SPHERE;
   }

   init(phyModule, objectShape, initialPos, 1, 1, 1,node, isDebugging);

   // set mvworld pointer
   bodyIndex = mvCreateBody(physicsUpdater->getWorldIndex(),
      MV_PARTICLE, shapeEnum, initialPos.X,initialPos.Y,initialPos.Z);
}

void PhysicsController::init(PhysicsModule* phyModule,
   PhysicsController::PC_ShapeEnum oShapeFlag,
   lf::core::vector3df& initialPos, float dims1, float dims2, float dims3,
   scene::CSceneNode* node, bool isDebugging)
{
   physicsUpdater = phyModule;
   shapeFlag = oShapeFlag;
   lf::core::matrix4 positionMatrix;
   NewtonWorld* pWorldPtr = physicsUpdater->getNewtonWorld();

   switch(shapeFlag)
   {
      case PC_BOX:
         collisionObj = NewtonCreateBox(pWorldPtr,dims1,dims2,dims3, NULL);
         break;
      case PC_SPHERE:
         collisionObj = NewtonCreateSphere(pWorldPtr, dims1,dims2,dims3, NULL);
         break;
      case PC_CYLINDER:
         collisionObj = NewtonCreateCylinder(pWorldPtr, dims1,dims2,NULL);
         break;
      default:
         collisionObj = NewtonCreateCapsule(pWorldPtr, dims1,dims2,NULL);
         break;
   }

   positionMatrix.setTranslation(initialPos);
   // define body object
   bodyObj = NewtonCreateBody(pWorldPtr,collisionObj);

   // set default values
   NewtonReleaseCollision(pWorldPtr, collisionObj);
   NewtonBodySetUserData(bodyObj,this);
   NewtonBodySetMassMatrix (bodyObj, 1.0f, 1.0f, 1.0f, 1.0f);
   NewtonBodySetMatrix(bodyObj, &positionMatrix.M[0]);

   NewtonBodySetTransformCallback(bodyObj, SetTransformationForMotionAI_And_LF);
	NewtonBodySetForceAndTorqueCallback(bodyObj, GetForcesFromMotionAI);

	//
	if (isDebugging)
	{
	   debugModel = new DebugPhysicsModel(bodyObj,initialPos);
	   lf::scene::CModelSceneNode* debugNode =
         new lf::scene::CModelSceneNode(debugModel);
      node->addChild(debugNode);
      debugNode->drop();
	}
}

/** @brief move
  *
  * @todo: document this function
  */
void PhysicsController::move(u32 frameTime, u32 frameTimeDiff)
{
   updatePhysicsLayer();
   physicsUpdater->setUpdateInterval(updateInterval);
   physicsUpdater->move(frameTime, frameTimeDiff);
   updateSceneNode();
}

void PhysicsController::updatePhysicsLayer()
{
   mvVec3 aiTempVec;
   mvBodyPtr aiBody = NULL;

   if (getPhysicsModule() != NULL && m_currentBody != NULL)
   {
      aiBody = mvGetBodyPtr(getPhysicsModule()->getWorldIndex(),\
         currentPC->getBodyIndex());
      if (aiBody != NULL)
      {
       // get ai stats -> set force & torque of physics
         aiTempVec = aiBody->getFinalTorque();
         m_currentBody->SetTorque(aiTempVec.getX(),aiTempVec.getY(),\
            aiTempVec.getZ());

         aiTempVec = aiBody->getFinalForce();
         m_currentBody->SetForce(aiTempVec.getX(),aiTempVec.getY(),\
            aiTempVec.getZ());
      }
   }

}

void PhysicsController::updateSceneNode()
{
   // retrieve data such as rotation & position from physics
   palVector3 physTempVec;
   mvBodyPtr aiBody = NULL;
   mvVec3 aiTempVec;
   lf::core::vector3df nodeTempVec;
   Float rx, ry, rz;

   palMatrix4x4  physLocalMatrix;

   if (getPhysicsModule() != NULL && m_currentBody != NULL)
   {
      aiBody = mvGetBodyPtr(getPhysicsModule()->getWorldIndex(),\
         currentPC->getBodyIndex());
      if (aiBody != NULL)
      {

         // POSITION
         // mvMotionAI
         physLocalMatrix = m_currentBody->GetLocationMatrix();
         mat_get_translation(&physLocalMatrix, &physTempVec);
         m_currentBody->GetPosition(physTempVec);
         aiTempVec.set(physTempVec.x, physTempVec.y, physTempVec.z);
         aiBody->SetPosition(aiTempVec);

         // CSceneNode
         nodeTempVec.set(physTempVec.x, physTempVec.y, physTempVec.z);
         controlledNode->setPosition(nodeTempVec);


         // ROTATION
         mat_get_rotation(physLocalMatrix, &rx, &ry, &rz);
         // current form is in radians
         aiTempVec.set(rx, ry, rz);
         //currentBodyPos *= RAD_TO_DEGREES;
         currentBody->setRotation(aiTempVec);
         // CSceneNode
         nodeTempVec.set(physTempVec.x, physTempVec.y, physTempVec.z);
         //tempVector *= RAD_TO_DEGREES;
         controlledNode->setRotation(nodeTempVec);

            // set final velocity
            NewtonBodyGetVelocity(body, &bodyMatrix[0]);
            currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
            currentBody->setFinalVelocity(currentBodyPos);

            // set final force
            NewtonBodyGetForce(body, &bodyMatrix[0]);
            currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
            currentBody->setFinalForce(currentBodyPos);

            // set final torque
            NewtonBodyGetTorque(body, &bodyMatrix[0]);
            currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
            currentBody->setFinalTorque(currentBodyPos);

            // set final omega (in units/per second)
            NewtonBodyGetOmega(body, &bodyMatrix[0]);
            currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
            currentBody->setFinalOmega(currentBodyPos);
      }
   }
}

/** @brief ~PhysicsController
  *
  * @todo: document this function
  */
 PhysicsController::~PhysicsController()
{
   collisionObj = NULL;

   if (bodyObj)
   {
      NewtonDestroyBody(getPhysicsModule()->getNewtonWorld(),bodyObj);
      bodyObj = NULL;
   }
}

PhysicsModule* PhysicsController::getPhysicsModule()
{
   return physicsUpdater;
}

mvIndex PhysicsController::getBodyIndex() const
{
   return bodyIndex;
}

