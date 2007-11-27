mvInitMotionAI()
mvInitDefaultActions()
world1 = mvCreateWorld();
body1 = mvCreateBody(world1,'MV_PARTICLE','MV_AABOX',4,6,0);
centralWaypoint = mvCreateWaypoint(world1,'MV_AABOX',0,2,0);

-- creating behaviour/mvBaseAction 1 
entry1 = mvAddBehaviourToList(world1,body1,'MV_FLEE');

-- setting this parameters (i.e waypoint) after creation 
-- by calling mvSetEntryListNodeParameter
param = 'MV_WAYPOINT'
errorCode = mvSetEntryListNodeParameter(world1,body1,entry1,param,
	centralWaypoint);
-- checking if variables are passed	
print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListNodeParameter(world1,body1,entry3,param))
