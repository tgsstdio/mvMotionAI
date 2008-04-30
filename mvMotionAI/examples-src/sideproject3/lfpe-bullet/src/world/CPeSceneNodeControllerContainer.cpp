// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#include <lfpe-bullet/world/CPeSceneNodeControllerContainer.h>
#include <lfpe-bullet/world/CPeBulletWorld.h>


namespace lf
{
namespace pe
{
namespace world
{
		//! default-constructor
		CPeSceneNodeControllerContainer::CPeSceneNodeControllerContainer()
		{

		}

		//! destructor
		CPeSceneNodeControllerContainer::~CPeSceneNodeControllerContainer()
		{

		}

		//! adds a scene node controler
		void CPeSceneNodeControllerContainer::addSceneNodeControler(CPeSceneNodeController* snc)
		{
			sceneNodeControlers.push_back(snc);
		}

		//! removes a scene node controler
		void CPeSceneNodeControllerContainer::removeSceneNodeControler(CPeSceneNodeController* snc)
		{
			core::list<CPeSceneNodeController*>::Iterator it = sceneNodeControlers.begin();
			for(; it != sceneNodeControlers.end(); ++it)
			{
				if(snc == (*it))
				{
					sceneNodeControlers.erase(it);
					break;
				}
			}
		}

		//! translates all SceneNodes attached to scene node controler object
		void CPeSceneNodeControllerContainer::translateSceneNodes()
		{
			core::list<CPeSceneNodeController*>::Iterator it = sceneNodeControlers.begin();
			for( ; it != sceneNodeControlers.end(); ++it )
			{
				( (CPeSceneNodeController*)*it )->assignTranslation();
			}
		}


} // end namespace world
} // end namespace pe
} // end namespace lf


