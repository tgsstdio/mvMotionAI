// Copyright 2006-2008 by Lightfeather-Team
// Written by Matthias Meyer
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#include "CTutorial3.h"
#include <mv/mvMotionAI.h>

#include <iostream>

// constructor is the same as in tutorial1
CTutorial3::CTutorial3() : lastFPS(0) , lastPolyCount(0), cControllerType(0), nControllerType(0)
{

	rwin = CLFRender::getInstance().createRenderWindow(
		core::vector2di(0,0),
		core::vector2d<s32>(1024,768),
		32,
		32,
		render::EWCF_AUTOCLOSE,
		render::EAAF_NONE);

	rwin->setWindowCaption(L"Lightfeather Tutorial 3");
	rwin->setVisible(true);

	rwin->addKeyListener(this);

	rmgr = CResourceManager::getInstancePtr();

	core::stringc mediaDir = CLFOS::getInstance().getFileSystem()->getApplicationDirectory();
	mediaDir += "/../../examples/media";
	rmgr->getFileSystem()->addSearchPath(mediaDir.c_str());

	smgr = rwin->getRenderLayer3D()->getSceneManager();

	CLFRender::getInstance().setAutoSleep(0);

	mvInitMotionAI();
	int world = mvCreateWorld();
	mvCreateForce(world, MV_GRAVITY);
	setupScene();

	setup2D();

}

// destructor
CTutorial3::~CTutorial3()
{

}

// This method contains the main loop of this tutorial
// the main-loop is also the same as in tutorial1
void CTutorial3::run()
{
	bool quitNow = false;

  while(!quitNow)
	{

		u32 polycount = rwin->getTotalPolygonCount();
		u32 oneSecFPS = rwin->getOneSecondFPS();
		// only update the window-caption if either the fps or the number of polygons have changed
		if(lastFPS != oneSecFPS || lastPolyCount != polycount)
		{
			wchar_t tmp[256];
			snwprintf(tmp, 256, L"Lightfeather Tutorial 3 - Polys: %u FPS(1sec):%d", polycount, oneSecFPS );
			rwin->setWindowCaption(tmp);
			lastFPS = oneSecFPS;
			lastPolyCount = polycount;
		}

		quitNow = !CLFRender::getInstance().update();

	}
}

// same setup2d as in tutorial1
void CTutorial3::setup2D()
{
	render::CRenderLayer2D *pane = new render::CRenderLayer2D(
		core::rect<s32>(0,0,rwin->getInnerSize().X,rwin->getInnerSize().Y),
		core::CColorI(0,0,0,255),
		false,
		false,
		false );

	rwin->add(pane);
	pane->drop();

	res::CTexture *ltexture = rmgr->loadTexture("lightfeather.png","lflogo");
	pane->drawImage( ltexture, // the texture to draw
		core::vector2d<s32>( rwin->getInnerSize().X - 210, rwin->getInnerSize().Y -128 ),
		core::vector2d<s32>(256,128),
		render::ETT_TEST);
}


void CTutorial3::setupScene()
{
	cam = new scene::C3DCamera(rwin,
	core::PI / 3.0f,
	1.0f,
	1000.0f,
	true);

	cam->setBackgroundColor(core::CColorI(0,0,255,0));

	// we set the camera back a bit initially so we can see objects rendered at position 0,0,0
	cam->setPosition(core::vector3df(0.0f,0.0f,-20.0f));
	rwin->getRenderLayer3D()->add(cam);
	cam->drop();

	// adding a plane so we can actually see what happens with the controllers, otherwise its hard to see
	// sidenote: the types we use here (vector2df, vector2dui, vector2dub) are typedefs for the vector2d template
	// class with different types: vector2df = vector2d<f32>, vector2dui = vector2d<u32>, vector2dub = vector2d<u8>
	// these typedef exist for most classes, they are just for convenience
	res::CPlaneModel *plane = new res::CPlaneModel("plane1",core::vector2df(100.0f,100.0f), // size of the plane
																													core::vector2dui(5,5), // number of vertexes per dimension
																													core::vector2dui(1,1), // texture-repeat-count
																													true, // horizontal = true, vertical = false
																													core::CColorI(40,40,100,255), // dark blue
																													true); // if true the 0,0 of the plane is in the center of the plane if false
																																// the 0,0 of the plane is at the position of the plane
	plane->getMaterial(0)->setRenderFeature(render::ERPF_COLOR_ONLY);
	scene::CModelSceneNode *planeNode = new scene::CModelSceneNode(plane);
	smgr->addSceneNode(planeNode);
	planeNode->setPosition(core::vector3df(0.0f,-10.0f,0.0f)); // we set the plane a bit lower so the cube "hovers" above it
	planeNode->drop(); // so it gets deleted automatically

	res::CCubeModel *cube = new res::CCubeModel("cube1",5.0f,5.0f,5.0f);
	cube->getMaterial(0)->setRenderFeature(render::ERPF_COLOR_ONLY);

	cubeNode = new scene::CModelSceneNode(cube);
	smgr->addSceneNode(cubeNode);

	cubeNode->setPosition(core::vector3df(0.0f,0.0f,0.0f));
	cubeNode->rotateYDegrees(45.0f);
	cubeNode->rotateXDegrees(-45.0f);

	cubeNode->drop();

	// now we add the initial controllers
	// the initial controllers will be an editor-controller for the camera and a rotationcontroller for the node
	// the editorcontroller is named this way because it behaves like the camera-control in some 3d-editing programs
	// it doesnt use the left mouse button so that is free for selecting (picking) objects
	// by using the editorcontroller you can move/rotate the camera in the following way:
	// hold right mouse button: move mouse up/down = move camera forward/back, move mouse left/right = move camera left/right
	// hold middle mouse button: move mouse up/down = move camera up/down
	// hold shift-key: free look/rotation of camera
	// the rotation-controller will be described later when its instantiated

	// because the settings-related methods are controller-specific, we need to use a temp var that has the
	// same type as the controller, we will later assign it to a more generic scenenode-controller pointer
	scene::CEditorController *editController = new scene::CEditorController( rwin, // the renderwindow the controller gets its events from
																								cam // the camera that is controlled by this controller
																								);
	// now we want to change the behaviour of this controller a bit.
	// all camera-controllers have a CProperties-object with the settings which makes it simple to load/save the settings.
	// so first, we get the current settings from the controller, which will be the default-settings for this
	// camera-controller

	core::CProperties *settings = editController->getSettings();
	// the available settings for the editor-contrtoller are (defaults in parentheses):
	// MOUSE_LOOK: the key used to look around (space)
	// MOUSE_LOOK_MODIFIER: use this if you want to use a modifier-key like [CTRL], [ALT] or [SHIFT] (left shift)
	// XZ_SPEED: speed of movement in x and z directions (left/right, forward backward) (0.1f)
	// Y_SPEED: speed of movement in y direction (up/down) (0.1f)
	// XZ_MODIFIER: modifier to hold down to move cam back/forward/left/right (right mouse button)
	// Y_MODIFIER: modifier to hold down to move up/down (middle mouse button)
	// CAM_ROTATION_SPEED_X: speed of camera rotation in freelook-mode when mouse is moved left/right (0.1f)
	// CAM_ROTATION_SPEED_Y: speed of camera rotation in freelook-mode when mouse is moved up/down (0.1f)
	// XZ_GLOBAL: determines if the camera moves into its local forward/back/left/right-direction or along the world x/z-axis
	// Y_GLOBAL: determines if the camera moves into its local up/down directions or along the world-y-axis
	// now we just change the speeds a bit
	settings->setProperty("XZ_SPEED",0.05f);
	settings->setProperty("Y_SPEED",0.05f);
	// whenever we update the properties of a controller, we need to notify it that the settings have been
	// changed so it re-reads the settings and sets its internal variables to the provided values
	editController->settingsUpdated();

	// now we can set the camController-pointer
	camController = editController;

	// now you probably wonder why we dont add the controller to the camera like cam->addController(camController)
	// but instead add it to the scene(manager).
	// the reason is simple: speed. if we were to add the controller to the controlled object, we would have to
	// check each object in the scene, if it has a controller attached and then execute the controllers move-method
	// every frame. But if we add it to the scene(manager), we just have a nice list of controllers in the scenemanager
	// and dont need to care about, which nodes those controllers handle.
	// imagine a scene with 500 nodes and 10 of those nodes have controllers assigned to them and it will quickly become
	// pretty clear why this is faster.
	smgr->add( camController );

	// we can drop the editcontroller here since the scenemanager grabs it when we add it
	// and then releases (drops) it, when we remove it from the scene
	editController->drop();

	// the rotation controller, rotates a node by the values given in the rotation parameter. the values are given in
	// degrees / second so for this tutorial we will rotate the node by 15 degrees / second around the y-axis
	nodeController = new scene::CRotationController(	cubeNode, // the node that is to be affected by this controller
																										core::vector3df(0.0f,15.0f,0.0f), // the rotation in degrees
																																											// per second on each axis
																										0, // how long the rotation should take, 0 means rotate indefinitely
																										false // use node-loacal axis for rotation (true) or global (false)
																									);

	// add the controller to the scene, for explanation see above
	smgr->add(nodeController);
	// drop the controller, for an explanation see above
	nodeController->drop();
}



void CTutorial3::keyPressed(input::CKeyEvent& event)
{

	switch(event.getKey())
	{
		case input::KEY_ESCAPE:
			// we close the window, so on the next call to CLFRender::update() it will return false and the app will be exited
			rwin->closeWindow();
			break;
		case input::KEY_KEY_C:
			// switch the camera-controller
			// first of all we consume the event so the renderwindow doesnt try to pass it on to the
			// newly added cameracontroller nor the old cameracontroller which we are going to remove
			event.consume();
			// since we drop()ed the pointer to the controller, when we remove the old controller from the scene,
			// it will automatically be removed from memory
			smgr->remove(camController);
			// now determine which controller is next
			cControllerType++;
			if(cControllerType == 3)
			{
				cControllerType = 0;
			}
			// now we add the new controller
			switch(cControllerType)
			{
				case 0: // editorController, for explanation see above
				{
					scene::CEditorController *editController = new scene::CEditorController( rwin, cam );
					core::CProperties *settings = editController->getSettings();
					settings->setProperty("XZ_SPEED",0.05f);
					settings->setProperty("Y_SPEED",0.05f);
					editController->settingsUpdated();
					camController = editController;
					smgr->add( camController );
					editController->drop();
					break;
				}
				case 1: // fpscontroller
					// the fpscontroller, like the thirdperson cameracontroller now inherits from movementcontroller which means
					// that it has the same properties-access and also the same properties for movement.
					// The common properties are:
					// MOVE_FORWARD: key used to move the node forward (cursor up)
					// MOVE_BACKWARD: key used to move the node backward (cursor down)
					// TURN_LEFT: key to turn the node counter-clockwise (cursor left)
					// TURN_RIGHT: key to turn the node clockwise ( cursor right)
					// STRAFE_LEFT: key to move the node to the left (A)
					// STRAFE_RIGHT: key to move the node to the right (D)
					// FORWARDSPEED: speed with which to move forward
					// BACKWARDSPEED: speed with which to move backwards
					// STRAFELEFTSPEED: speed with which to strafe left
					// STRAFERIGHTSPEED: speed with which to strafe right
					// RUNSPEED: speed with which to move the node (70.0f) this gets multiplied by forward/back etc. speeds
					// TURNSPEED: speed with which to turn the node (0.1f)

					// additionally the FPSController has the following properties:
					// ROTATE_X_SPEED: speed of node(camera) rotation when you move the mouse left/right (100.0f)
					// ROTATE_Y_SPEED: speed of node(camera) rotation when you move the mouse up/down (100.0f)
					// MIN_PITCH_Y: can be used to restrict the freedom of rotation around the y-axis for the node (0.0f)
					// MAX_PITCH_Y: can be used to restrict the freedom of rotation around the y-axis for the node (0.0f),
					// MIN & MAX = 0 means unrestricted
					// INVERT_X: invert rotation when mouse is moved right/left (false)
					// INVERT_Y: invert rotation when mouse is moved up/down (false)
					camController = new scene::CFPSController(rwin, // the renderwindow this controller gets its mouse/key-events from
																										cam, // the node to controll with this controller, in this case the camera
																										true 	// if set to true, the controller has control over the visibility
																													// of the mouse-cursor
																										);
					smgr->add(camController);
					camController->drop();
					break;
				case 2: // thirdpersoncontroller
					// this tutorial is really bad to display how this controller works, since you cant see how the
					// node moves relatively to the world while not moving relative to the camera (cursorup/cursordown,a,d keys)
					// you might want to also look at test6 where this controller is also used
					camController = new scene::CThirdPersonController(rwin, // the renderwindow this controller gets its mouse/key events from
																														cam, // the camera to control with this controller
																														cubeNode // the node to control with this controller
																														);
					smgr->add(camController);
					camController->drop();
					// we use the default settings here so we dont have to get the properties and such, we demonstrated that with the
					// editorcontroller. however, the available settings for the 3rdperson-controller are:
					// ZOOM_IN: key to zoom in on the node (W)
					// ZOOM_OUT: key to zoom out from the node (S)
					// INIT_CAM_NODE_DISTANCE: initial distance between cam and node (100.0f)
					// INIT_CAM_ANGLE_XZ: initial angle of the cam relative to the node around y-axis (180.0f = look at node from behind)
					// INIT_CAM_ANGLE_YXZ: initial angle at which the cam looks at the node (45.0f = 45 degrees down)
					// INIT_NODE_ANGLE_XZ: initial rotation of the node
					// ROTATION_MODIFIER: modifier to use to rotate the cam around the node (mouse-button2 = right mouse button)
					// CAM_ROTATION_SPEED_X: speed of rotation of the cam around the node (1.0f)
					// CAM_ROTATION_SPEED_Y: speed of rotation of the cam around the node (1.0f)
					// ZOOM_SPEED: speed of the change of the distance between cam and node (1.0f)
					// MIN_CAM_NODE_DISTANCE: minimum distance between cam and node (zooming)(5.0f)
					// MAX_CAM_NODE_DISTANCE: maximum distance between cam and node (zooming)(200.0f)
					// ROTATE_NODE_WITH_CAM: if set to true, the node will be rotated when the cam is rotated (false)
					// ROTATE_CAM_WITH_NODE: if set to true, the camera will be rotated when the node is rotated (false)
					// CAM_HEIGHT_OFFSET_FROM_NODE: this determines, where the cam looks with regard to the node (ie if node is a char if cam looks
					// at floor or at head of node, determined by the height) (0.0f)

					break;
			}

			break;
		case input::KEY_KEY_N:
			// switch the node-controller
			// since we drop()ed the pointer to the controller, when we remove the old controller from the scenem,
			// it will automatically be removed from memory
			smgr->remove(nodeController);
			// now determine which controller is next
			nControllerType++;
			if(nControllerType == 3)
			{
				nControllerType = 0;
			}
			// now we add the new controller
			switch(nControllerType)
			{
				case 0: // rotationController, for explanation see above
					nodeController = new scene::CRotationController(cubeNode, core::vector3df(0.0f,15.0f,0.0f));
					smgr->add(nodeController);
					nodeController->drop();
					break;
				case 1: // flycirclecontroller
					// as the name says, this controller lets the node move in a circle.
					nodeController = new scene::CFlyCircleController(	cubeNode, // the node that is to be controller by this controller
																														core::vector3df(0.0f,0.0f,0.0f), // the center around which to circle
																														core::vector3df(15.0f,0.0f,30.0f), // the axis around which to fly the circle
																																																// in degrees
																														10.0f, // the radius of the circle to be flown
																														1.0f // the speed at which to fly the circle in circles/second
																														);
					smgr->add(nodeController);
					nodeController->drop();
					break;
				case 2: // faceviewplanecontroller
					// this controller rotates the node in such a way that it always faces the cameras viewplane
					// in this tutorial you will notice that the side of the cube that faces the camera
					// is always a perfect square, which would of course not be the case without this controller
					nodeController = new scene::CFaceViewPlaneController(cubeNode,// the node that is to be controlled,
																															 cam // the camera to face the viewplane of
																															 );
					smgr->add(nodeController);
					nodeController->drop();
					break;
			}

			break;

	}

}

