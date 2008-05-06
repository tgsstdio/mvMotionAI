#include "RagdollController.h"
#define MATRIX_X_POS_INDEX (12)
#define MATRIX_Y_POS_INDEX (13)
#define MATRIX_Z_POS_INDEX (14)
#define MATRIX_W_POS_INDEX (15)
#define RAD_TO_DEGREES (57.295779513082320876798154814105)

static void SetBoneTransformation(const NewtonRagDollBone* bone)
{
   mvVec3 currentBodyPos;
   dFloat matrix[16];
   dFloat bodyMatrix[16];
   lf::core::vector3df tempVector;
   mvBodyPtr currentBody = MV_NULL;
   RagdollBoneController* currentController = (RagdollBoneController*)
      NewtonRagDollBoneGetUserData(bone);
   NewtonBody* physicsBody = NULL;
   lf::scene::CSceneNode* controlledNode = NULL;

   if (currentController != NULL)
   {
      currentBody = mvGetBodyPtr(currentController->pModule->getWorldIndex(),\
         currentController->aiBodyID);
      physicsBody = NewtonRagDollBoneGetBody(bone);
      controlledNode = currentController->getControlledObject();
      if (currentBody != MV_NULL && controlledNode != NULL && physicsBody != NULL)
      {

         // set positions
         NewtonRagDollBoneGetGlobalMatrix(bone,&matrix[0]);
            // mvMotionAI
         currentBodyPos.set(matrix[MATRIX_X_POS_INDEX],
            matrix[MATRIX_Y_POS_INDEX],
            matrix[MATRIX_Z_POS_INDEX]);
         currentBody->setPosition(currentBodyPos);

         // set angle
         NewtonGetEulerAngle(matrix,&bodyMatrix[0]);
            // current form is in radians
         currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         //currentBodyPos *= RAD_TO_DEGREES;
         currentBody->setRotation(currentBodyPos);

         //NewtonRagDollBoneGetLocalMatrix(bone,&matrix[0]);
            // CSceneNode
         tempVector.set(matrix[MATRIX_X_POS_INDEX],matrix[MATRIX_Y_POS_INDEX],\
            matrix[MATRIX_Z_POS_INDEX]);
         controlledNode->setPosition(tempVector);

         //NewtonGetEulerAngle(matrix,&bodyMatrix[0]);
            // C Scene Node
         tempVector.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         //tempVector *= RAD_TO_DEGREES;
         controlledNode->setRotation(tempVector);


         // set final velocity
         NewtonBodyGetVelocity(physicsBody, &bodyMatrix[0]);
         currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         currentBody->setFinalVelocity(currentBodyPos);

         // set final force
         NewtonBodyGetForce(physicsBody, &bodyMatrix[0]);
         currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         currentBody->setFinalForce(currentBodyPos);

         // set final torque
         NewtonBodyGetTorque(physicsBody, &bodyMatrix[0]);
         currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         currentBody->setFinalTorque(currentBodyPos);

         // set final omega (in units/per second)
         NewtonBodyGetOmega(physicsBody, &bodyMatrix[0]);
         currentBodyPos.set(bodyMatrix[0],bodyMatrix[1], bodyMatrix[2]);
         currentBody->setFinalOmega(currentBodyPos);

         float bodyMass, ixx, iyy, izz;
         // set final omega (in units/per second)
         NewtonBodyGetMassMatrix(physicsBody, &bodyMass,&ixx,&iyy,&izz);
         currentBody->setMass(bodyMass);

      }
   }
}

static void GetBoneForces (const NewtonBody* body)
{
   dFloat forces[3];
   mvVec3 tempVector;
   mvBodyPtr currentBody = MV_NULL;
   RagdollBoneController* currentController = NULL;
   NewtonRagDollBone* physicsBone = NULL;

   physicsBone = (NewtonRagDollBone*) NewtonBodyGetUserData(body);
   if (physicsBone == NULL)
   {
      std::cout << "HELLO 6" << std::endl;
      return;
   }

   currentController = (RagdollBoneController*) NewtonRagDollBoneGetUserData(physicsBone);
   if (currentController == NULL)
   {
      std::cout << "HELLO 3" << std::endl;
      return;
   }

   currentBody = mvGetBodyPtr(currentController->pModule->getWorldIndex(),
      currentController->aiBodyID);
   if (currentBody == MV_NULL)
   {
      std::cout << "HELLO 4" << std::endl;
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

/** @brief move
  *
  * @todo: document this function
  */
void RagdollBoneController::move(u32 frameTime, u32 frameTimeDiff)
{
   if (pModule)
   {
      pModule->setUpdateInterval(getUpdateInterval());
      pModule->move(frameTime, frameTimeDiff);
   }
}

/** @brief RagdollBoneController
  *
  * @todo: document this function
  */
 RagdollBoneController::RagdollBoneController(scene::CSceneNode* node)
   : scene::CSceneNodeController(node), pModule(NULL)
{

}


/** @brief ~RagdollBoneController
  *
  * @todo: document this function
  */
 RagdollBoneController::~RagdollBoneController()
{

}

/** @brief RagdollController
  *
  * @todo: document this function
  */
 RagdollController::RagdollController(PhysicsModule* currentPhysics)
   :  dollPhysics(NULL), pModule(currentPhysics), noOfBones(0)
{
   // create group of bodies
   aiGroupID = mvCreateGroup(pModule->getWorldIndex());
   // TODO : check for errors

   dollPhysics = NewtonCreateRagDoll(pModule->getNewtonWorld());
}

/** @brief addBone
  *
  * @todo: document this function
  */
RagdollBoneController* RagdollController::addBone(scene::CSceneNode* node,
   int parentNodeIndex, mvOptionEnum collisionType,
   const core::vector3df& relativePos, float mass, float length)
{
   RagdollBoneController* tempBoneController = NULL;
   NewtonCollision* tempCollision = NULL;
   NewtonRagDollBone* parentBone = NULL;
   NewtonRagDollBone* currentBone = NULL;
   lf::core::matrix4 relativeMatrix;
   lf::core::vector3df nodePos;
   dFloat sizeArray[3];

   if(dollPhysics)
   {
      if (parentNodeIndex == RAGDOLL_ROOT_NODE_ID)
      {
         parentBone = NULL;
         node->setPosition(relativePos);
         nodePos = node->getPosition();
      }
      else
      {
         parentBone = NewtonRagDollFindBone(dollPhysics, parentNodeIndex);

         if (parentBone != NULL)
         {
            RagdollBoneController* currentController = (RagdollBoneController*)
               NewtonRagDollBoneGetUserData(parentBone);

            lf::core::matrix4 globalMatrix;
            NewtonRagDollBoneGetGlobalMatrix(parentBone,&globalMatrix.M[0]);
            scene::CSceneNode* controlledNode = currentController->getControlledObject();
            //controlledNode->addChild(node);
            nodePos = relativePos;
            nodePos += globalMatrix.getTranslation();
            //node->drop();
            //node->setPosition(relativePos);
         }
         else
         {
            std::cout << "Not found " << std::endl;
         }

      }

      relativeMatrix.setTranslation(relativePos);
      sizeArray[0] = length;
      sizeArray[1] = 0.5;
      sizeArray[2] = 0.5;

      tempBoneController = new RagdollBoneController(node);

      tempCollision = NewtonCreateBox(pModule->getNewtonWorld(),1.5,1.5,1.5,NULL);
      tempBoneController->bonePhysicsCollision = tempCollision;

      currentBone = NewtonRagDollAddBone(dollPhysics, parentBone,\
         tempBoneController, mass, &relativeMatrix.M[0], tempCollision,\
         &sizeArray[0]);
      NewtonRagDollBoneSetID(currentBone, noOfBones);
      std::cout << "Bone ID :  "  << noOfBones << std::endl;
      tempBoneController->bonephysicsID = noOfBones;
      ++noOfBones;
      // mv motion ai
      tempBoneController->aiBodyID = mvCreateBody(pModule->getWorldIndex(),
         MV_PARTICLE,collisionType, nodePos.X, nodePos.Y, nodePos.Z);

      tempBoneController->bonePtr = currentBone;

      sizeArray[0] = 0;
      sizeArray[1] = 0;
      sizeArray[2] = 1;

      NewtonRagDollBoneSetLimits(tempBoneController->bonePtr,
         &sizeArray[0],
         1,
         1,
         1,
         &sizeArray[0],
         1,
         1);

      tempBoneController->debugModel = new DebugPhysicsModel(NewtonRagDollBoneGetBody(currentBone),
         nodePos);
      lf::scene::CModelSceneNode* debugNode = new lf::scene::CModelSceneNode(tempBoneController->debugModel);
      node->addChild(debugNode);
      debugNode->drop();

      NewtonRagDollSetTransformCallback(dollPhysics, SetBoneTransformation);
      NewtonRagDollSetForceAndTorqueCallback(dollPhysics, GetBoneForces);

      NewtonReleaseCollision(pModule->getNewtonWorld(),tempCollision);
      tempBoneController->pModule = this->pModule;
      return tempBoneController;
   }
   else
   {
      return NULL;
   }
}

/** @brief ~RagdollBoneController
  *
  * @todo: document this function
  */
void RagdollController::endConstruction()
{
   if (dollPhysics)
   {
      NewtonRagDollEnd(dollPhysics);
   }
}

/** @brief beginConstruction
  *
  * @todo: document this function
  */
void RagdollController::beginConstruction()
{
   if (dollPhysics)
   {
      NewtonRagDollBegin(dollPhysics);
   }
}


/** @brief ~RagdollController
  *
  * @todo: document this function
  */
 RagdollController::~RagdollController()
{
   if (dollPhysics)
   {
      NewtonDestroyRagDoll(pModule->getNewtonWorld(),dollPhysics);
   }
}

