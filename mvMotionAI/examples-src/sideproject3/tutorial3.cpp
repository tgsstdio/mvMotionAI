// Copyright 2006-2008 by Lightfeather-Team
// Written by Matthias Meyer
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

// This tutorial will be about scenenode-controllers.
// Scenenode-controllers are a way to change a scenenode's position and rotation
// automatically over time, without having to call node->setPosition() and
// node->rotateXDegrees() and and such.
// Since cameras are scenenodes (even though they are not necessarily added into
// the scenegraph), you can use controllers also to control the camera(s). In fact,
// this is the preferred way to control cameras.
// The existing controllers are:
// CEditorController: a controller used for cameras with controls like in 3d-editing programs
// CFPSController: a controller used for cameras with controls like in first-person games
// CThirdPersonController: a controller used with a camera and a node with controls like in
// 												games where you see your character from a 3rd-person perspective
// CFaceViewPlaneController: a controller to make a node always face the cameras viewplane
// CFlyCircleController: a controller to make a node move in a circle
// CFlyForwardController: a controller to make a node move straight in its forward-direction
// CFlyLineController: a controller to make a node move along a line
// CFlySplineController: a controller to make a node move along a spline-curve
// CMaintainRotationController: a controller to make a node maintain its rotation regardless
//															of the rotation of the parent node (usually the child node
//															adds its own rotation to the parent's rotation
// CRotationController: a controller to make a node rotate in place
// Note that even though the first three controllers were specifically created for
// use with cameras, you can also use them with any other type of scenenode.
// also note, that we wont use all of the controllers in this tutorial but you should
// get a good introduction to use controllers in general

// use: press [c] to switch the camera-controller, press [n] to switch the node-controller
// press [ESC] to quit

// IMPORTANT NOTE: the tutorials build on each other, so if you want to understand
// whats going on, we recommend to read them in order.

// rest is the same as in tutorial1
#include <lf/Lightfeather.h>

#include "CTutorial3.h"

using namespace lf;

int main(int argc, char *argv[])
{
	lf::initLF();

	CTutorial3 *ex = new CTutorial3();
	ex->run();

	delete ex;
	lf::deinitLF();

}

