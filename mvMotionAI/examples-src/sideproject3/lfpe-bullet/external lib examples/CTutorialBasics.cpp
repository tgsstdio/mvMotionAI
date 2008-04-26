// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

// Here we have the implementation of our tutorial main class.

// We include the class header, as you might have expected it here.
#include "CTutorialBasics.h"


// In the constructor we also call the base class constructor.
// The 1st parameter is the caption of the render window.
CTutorialBasics::CTutorialBasics() :
	CTestAppBase(L"ODE for Lightfeather Tutorial 01: Basics")
{
	// We also create the instance of the CPeWorld. This is not a singelton,
	// because it is possible to create as many CPeWorld's as needed, to simulate
	// independent physical environments.
	// The world mainly consists of two elemets:
	// - CCollisionSystem
	//   does all the collision stuff (can alse be created separatelly if only collision is needed)
	//   You can acces it by peWorld->getCollisionSystem()
	// - CRigidSystem
	//   The rigid body system
	//   You can acces it by peWorld->getRigidSystem()
	peWorld = new world::CPeWorld();
}

// The destructor simply deletes our CPeWorld.
CTutorialBasics::~CTutorialBasics()
{
	delete peWorld;
}

// We use the method showUsage to print out how the 3rd person controler works to 
// move the cam around.
void CTutorialBasics::showUsage()
{
	CTestAppBase::showUsage();
	
	std::cout << "press right mousebutton to rotate view" << std::endl;
	std::cout << "use mouse wheel to zoom in/out" << std::endl;
}

// Because we need no gui here, it would have not been necessary to override setupGUI.
// Thats why we only call the base implementation.
void CTutorialBasics::setupGUI()
{
	CTestAppBase::setupGUI();
	
}

// setupScene keeps the most interesting part of this tutorial.
void CTutorialBasics::setupScene()
{
	// 1st call the base implementation
	// This creates the camera, a light and a skybox.
	// Also lighting is setup correctly.
	CTestAppBase::setupScene();

	// Now we need to place the camera. To move the camera around easily we add
	// a 3rd person controler
	addThirdPersonControler(
		90.0f,	// initial XY angle
		60.0f,	// initial YXZ angle
		30.0f,	// initial distance of the cam
		5.0f,		// minimum cam distance
		100.0f,	// maximum cam distance
		0.0f		// and cam height offset
		);

	// We also need to set the position of the light.
	// The variable light (lf::scene::CLight) is defined in CTestAppBase 
	// and created in CTestAppBase::setupScene().
	light->setPosition(core::vector3df(10.0f,20.0f,-15.0f));

	// This is the 1st real lfpe call we will make.
	// Because we want to have a jumping ball, we need gravity.
	// By default no gravity is set. We simulate the normal average gravity
	// on earth. The up direction is +Y, so wee need to set the gravity vector
	// to -9.81 in Y direction.  The unit is m/s^2 (acceleration).
	// Because the gravity is a vector, any direction and value is possible.
	peWorld->getRigidSystem()->setGravity(core::vector3df(0.0f, -9.81f, 0.0f));
	
	// Now that we have gravity, we need the floor which will stop our little
	// ball from falling down to hell.
	// As graphical representation we use a simple plane with a nice grass green color.
	// The size is 20x20 and we tile it 10x10.
	// The default position and rotation is 0 as we need it here.
	res::CPlaneModel* floorModel = new res::CPlaneModel(
		"floor", 
		core::vector2d<f32>(20.0f, 20.0f),
		core::vector2d<u32>(10, 10),
		core::vector2d<u8>(1, 1),
		true,
		core::CColorI(0, 255, 0, 255),
		true);
		
	// Now set the render feature to ERPF_COLOR_ONLY (who needs a texture in a physics tutorial ;) )
	floorModel->getMaterial(0)->replaceRenderFeature(render::ERPF_COLOR_ONLY);

	// Now we create the scene node ...
	floorNode = new scene::CModelSceneNode(floorModel);
	
	// .. and add it to the scene graph
	// The variable smgr (lf::scene::CSceneManager) is defined and created in CTestAppBase.
	smgr->addSceneNode(floorNode);

	// Now the physic representation of the floor.
	// Because the floor should be able to collide with other things
	// but it should not be influenced by collisions and other forces like gravity,
	// we only need to create a geom for it and no body.
	// We use a CGeomPlane because it's one of the simplest geoms.
	// The only difference to the CPlaneModel is, that it has no size. This means
	// it goes to the infinity in all directions, but this is no problem for us.
	floorGeom = new collision::CGeomPlane(
		peWorld->getCollisionSystem(),		// Tell the geom in which collision system it is.
		peWorld->getCollisionSystem()->getMainGeomSpace(),			
														// Geoms are grouped togeather into geom spaces.
														// Here we use the default geom space created by the collision system.
														// Most of the geoms must have a geom space, some must not have one.
														// This is why you have to set it every time you create a geom.
		core::vector3df(0.0f, 1.0f, 0.0f),	// The normal vector of the plane (upwards).
		0.0f											// The distance from the origin.
		);
	// Because the floor is not moveable, it is not necessary to connect the scene node to
	// the geom. But a CGeomPlane is an inmoveable geom (defined by ode).
	// We would get errors if we attach it to a body or if a scne node gets attached to.
	
	// Now we create our ball.
	// 1st the model, ...
	res::CSphereModel* ballModel = new res::CSphereModel(
		"ball", 
		2.0f						// radius
		);
	ballModel->getMaterial(0)->replaceRenderFeature(render::ERPF_COLOR_ONLY);
	
	// ... and the scene node
	ballNode = new scene::CModelSceneNode(ballModel);
	smgr->addSceneNode(ballNode);
	
	// 2nd the geom
	ballGeom = new collision::CGeomSphere(
		peWorld->getCollisionSystem(),							// collision system
		peWorld->getCollisionSystem()->getMainGeomSpace(),	// geom space
		2.0f																// radius
		);
		
	// 3rd the body
	ballBody = new rigid::CBody(
		peWorld->getRigidSystem()		// the body just needs the rigid system on construction
		);
		
	// But what would a body be without a mass
	// CMass has a set of functions to set it for different object shapes.
	// You can choose to set by total mass or by density of the material.
	rigid::CMass ballMass;
	ballMass.setSphere(
		950.0f,					// the density, rubber has a density between 920 and 960 kg/m^3
		2.0f						// radius
		);
		
	// Now apply the mass to the body.
	ballBody->setMass(&ballMass);
	
	// Now we have all elements that are necessary to display and simualte the ball.
	// All we have to do now is connecting them togeather.
	// 1st we attach the geom to the body.
	// From now on the geom position/rotation is controlled by the body.
	ballBody->attachGeom(ballGeom);
	
	// 2nd we need to connect the scene node to it.
	// Because both, the geom and the body are derivied from the CPeSceneNodeController
	// we can choose to which one we attach the scene node.
	// You can attach it to both as well, but this is absolutely not necessary.
	// I choose the body, because it is possible to set the same body to more than one geom.
	ballBody->attachSceneNode(ballNode);
	
	// Now that all connections are done we need to set the initial position of the ball.
	// Because the geom and the scene node is attached to the body we only need to set the
	// position of the body.
	ballBody->setPosition(core::vector3df(0.0f, 10.0f, 0.0f));
}

// running the simulation is straight forward
void CTutorialBasics::doRun()
{
	// remeber: doRun() gets called in the main loop
	
	// 1st we need to collide all geoms
	// this function of CPeWorld makes all necessarry calls to the collision and rigid system
	peWorld->collideGeoms();
	
	// 2nd the simulation itself has to be done.
	// You can choose between step() and quickStep()
	// step() is slower for large systems, but more accurate.
	// quickStep() is faster, but less accurate.
	// Every step function needs the time difference between this and the last step.
	// The variable timeDiff is defined in CTestAppBase and set before doRun() gets called.
	// Because timeDiff is in ms and step/quickStep needs seconds, we have to divide it by 1000.
	peWorld->getRigidSystem()->quickStep(timeDiff / 1000.0f);
	
	// 3rd: Now that all bodies and geoms have there new positions,
	// we need to translate the attached scene nodes.
	// you also can call translateSceneNodes for the collision and rigid system
	// separatelly. But CPeWorld provides a method which does both.
	peWorld->translateSceneNodes();
}

// After the main loop is done, we have to cleanup.
void CTutorialBasics::cleanup()
{
	// Drop the floor geom.
	floorGeom->drop();
	// Remove the floor scene node ...
	floorNode->getParent()->removeChild(floorNode);
	// ... and drop it
	floorNode->drop();

	// Drop the ball geom.
	ballGeom->drop();
	// Drop the ball body.
	ballBody->drop();
	// Remove the floor scene node ...
	ballNode->getParent()->removeChild(ballNode);
	// ... and drop it
	ballNode->drop();

	// now base cleanup
	CTestAppBase::cleanup();
}

// The 1st lfpe tutorial is finished.
// I hope you had some fun by reading it.

// If you want to do some more "dropping" then try the following:
// Drop various objects of different shapes and sizes and see how they collide.
// You can also change the initial position of the new objects a little bit.