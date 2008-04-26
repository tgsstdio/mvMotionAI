// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_PE_SCENE_NODE_CONTROLLER_CONTAINER_H_
#define _C_PE_SCENE_NODE_CONTROLLER_CONTAINER_H_

#include <lfpe/lfpeConfig.h>
#include <lfpe/world/CPeSceneNodeController.h>
#include <lf/Lightfeather.h>

namespace lf
{
namespace pe
{
namespace world
{
	using namespace lf;
	
	class CPeWorld;
	
	//! 
	class LFPE_DLL_EXPORT CPeSceneNodeControllerContainer
	{
	public:
		//! Default Constructor
		CPeSceneNodeControllerContainer();
		
		//! Destructor
		virtual ~CPeSceneNodeControllerContainer();
	
		//! adds a scene node controler
		//! this method is only used internally, do not call it directly!
		void addSceneNodeControler(CPeSceneNodeController* snc);
		
		//! removes a scene node controler
		//! this method is only used internally, do not call it directly!
		void removeSceneNodeControler(CPeSceneNodeController* snc);

		//! translates all SceneNodes attached to scene node controler object
		void translateSceneNodes();
		
	protected:
		//! list with all potential scene node controller objects
		core::list<CPeSceneNodeController*> sceneNodeControlers;
	};
	
} // end namespace world
} // end namespace pe
} // end namespace lf


#endif // _C_PE_SCENE_NODE_CONTROLLER_CONTAINER_H_
