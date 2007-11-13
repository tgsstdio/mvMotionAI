mvInitMotionAI()
mvInitDefaultActions()
world1 = mvCreateWorld();
body1 = mvCreateBody(world1,'MV_PARTICLE','MV_AABOX',4,1,0);
waypoint1 = mvCreateWaypoint(world1,'MV_AABOX',10,11,4);
-- comments start with --
-- this
--mvSetDefaultBehaviourFactorForBody(world1,body1,1)
body2 = mvCreateBody(world1,'MV_PARTICLE','MV_AABOX',4,5,-6);

-- pursue body 1
entry2 = mvAddBehaviourToList(world1,body2,'MV_PURSUIT');
--print(entry2)
errorCode = mvSetEntryListNodeParameter(world1, body2, entry2, 'MV_BODY', body1)
--print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListNodeParameter(world1,body2,entry2,'MV_BODY'))
errorCode = mvSetEntryListNodeParameter(world1, body2, entry2, 'MV_WEIGHT', 2.5)
--print(mvGetErrorEnumString(errorCode))
errorCode = mvSetEntryListParameter(world1,body1,'MV_BODY',body2);
print(mvGetErrorEnumString(errorCode))


entry1 = mvAddBehaviourToList(world1,body1,'MV_EVASION');
print(mvGetEntryListNodeParameter(world1,body1,entry1,'MV_WAYPOINT'))
--paramFlag = 'MV_MAX_SPEED'
paramFlag = 'MV_DOMAIN'
errorCode = mvSetBodyParameter(world1, body1, paramFlag, 'MV_XZ_PLANE')
print(mvGetErrorEnumString(errorCode))
print(mvGetBodyParameter(world1,body1,paramFlag))

--paramFlag = 'MV_LENGTH'
--variable = 1
--errorCode = mvSetEntryListParameter(world1,body1,paramFlag,variable);
--print(mvGetErrorEnumString(errorCode))
--print(mvGetEntryListParameter(world1,body1,paramFlag))

--paramFlag = 'MV_RADIUS'
--variable = 5
--errorCode = mvSetEntryListParameter(world1,body1,paramFlag,variable);
--print(mvGetErrorEnumString(errorCode))
--print(mvGetEntryListParameter(world1,body1,paramFlag))

paramFlag = 'MV_IS_CONFINED'
variable = 'MV_TRUE'
errorCode = mvSetEntryListParameter(world1,body1,paramFlag,variable);
print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListParameter(world1,body1,paramFlag))

--mvSetDefaultBehaviourFactorForBody(world1,body2,5)
--mvSetEntryListParameter(world1,body2,waypoint1);
--mvAddBehaviourToBody(world1,body1,'MV_SEEK');
