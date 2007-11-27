mvInitMotionAI()
mvInitDefaultActions()
world1 = mvCreateWorld();
body1 = mvCreateBody(world1,'MV_PARTICLE','MV_AABOX',4,1,0);
centralWaypoint = mvCreateWaypoint(world1,'MV_AABOX',10,11,4);

-- setting the default waypoint of body1, so after this command
-- every new entry will have their waypoint variable = centralWaypoint
param = 'MV_WAYPOINT'
errorCode = mvSetEntryListParameter(world1,body1,param,
	centralWaypoint);
-- checking if variables are passed	
print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListParameter(world1,body1,param))

-- creating beahviour/mvBaseAction 1 
entry1 = mvAddBehaviourToList(world1,body1,'MV_SEEK');

