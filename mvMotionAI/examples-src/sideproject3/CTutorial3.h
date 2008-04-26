// Copyright 2006-2008 by Lightfeather-Team
// Written by Matthias Meyer
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

// as usual, we include lf/Lightfeather.h and add the namespace lf
#include <lf/Lightfeather.h>

using namespace lf;

// we still inherit from keylistener to get the [ESC] event
class CTutorial3 : public input::IKeyListener
{
public:
	// the constructor
	CTutorial3();
	// the destructor
	~CTutorial3();

	// this is the main method of this class which gets called after instantiation from
	// the tutorial2.cpp's main() function
	void run();

	// in this method we initialize the 2d-display (used in this tutorial to display a
	// lf-logo
	void setup2D();

	// this is the method used to setup or 3d view
	void setupScene();

	// this is the method we override from the KeyListener interface class
	// see description above for details
	void keyPressed(input::CKeyEvent& event);

private:
	// variables to hold our renderwindow,resourcemanager,scenemanager and rendercontext
	// so we can use them across method-boundaries within the exmaple
	render::IRenderWindow *rwin;
	CResourceManager *rmgr;
	scene::CSceneManager *smgr;

	// the camera we use to display the 3d-view
	scene::C3DCamera *cam;

  // this time we have the node as a class-variable since we want to be able to change
  // the controller used on the node in the keyPressed method
	scene::CModelSceneNode *cubeNode;

	// pointer to the camerta-controller we are currently using
	scene::CSceneNodeController *camController;

// this var is used to determine the camera-controller to switch to
	u8 cControllerType;

	// pointer to the node-controller thats currently active
	scene::CSceneNodeController *nodeController;

	// this var is used to determine the nodecontroller to switch to
	u8 nControllerType;

	// variables to hold the number of FPS and number of polygons of the last frame so we dont
	// need to update the display of those too often since changing the caption of a window is
	// pretty slow
	s32 lastFPS;
	u32 lastPolyCount;

};

