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

-- setting integration mode to XOR or the first entry that is enabled
param = 'MV_MODE'
errorCode = mvSetEntryListParameter(world1,body1,param,
	'MV_XOR');
-- checking if variables are passed	
print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListParameter(world1,body1,param))

-- creating beahviour/mvBaseAction 1 
entry1 = mvAddBehaviourToList(world1,body1,'MV_FLEE');
-- setting integration mode to XOR or the first entry that is enabled

-- is enabled flag
param = 'MV_IS_ENABLED'
isEnabled = 'MV_FALSE'
errorCode = mvSetEntryListNodeParameter(world1,body1,entry1,param,
	isEnabled);
-- checking if variables are passed	
print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListNodeParameter(world1,body1,entry1,param))

-- creating beahviour/mvBaseAction 2 
entry2 = mvAddBehaviourToList(world1,body1,'MV_SEEK');
-- setting integration mode to XOR or the first entry that is enabled

-- is enabled flag
param = 'MV_IS_ENABLED'
isEnabled = 'MV_FALSE'
errorCode = mvSetEntryListNodeParameter(world1,body1,entry2,param,
	isEnabled);
-- checking if variables are passed	
print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListNodeParameter(world1,body1,entry2,param))

-- creating beahviour/mvBaseAction 2 
entry3 = mvAddBehaviourToList(world1,body1,'MV_SEEK');
-- setting integration mode to XOR or the first entry that is enabled

-- weight
param = 'MV_WEIGHT'
errorCode = mvSetEntryListNodeParameter(world1,body1,entry3,param,
	3);
-- checking if variables are passed	
print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListNodeParameter(world1,body1,entry3,param))

-- is enabled flag
param = 'MV_IS_ENABLED'
isEnabled = 'MV_TRUE'
errorCode = mvSetEntryListNodeParameter(world1,body1,entry3,param,
	isEnabled);
-- checking if variables are passed	
print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListNodeParameter(world1,body1,entry3,param))
