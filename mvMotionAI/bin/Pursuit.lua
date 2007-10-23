mvInitMotionAI()
mvInitDefaultActions()
world1 = mvCreateWorld();
body1 = mvCreateBody(world1,'MV_PARTICLE','MV_AABOX',4,1,0);
waypoint1 = mvCreateWaypoint(world1,'MV_AABOX',10,11,4);
-- comments start with --
-- this
--mvSetDefaultBehaviourFactorForBody(world1,body1,1)
errorCode = mvSetEntryListParameter(world1,body1,'MV_WAYPOINT',waypoint1);
print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListParameter(world1,body1,'MV_WAYPOINT'))
entry1 = mvAddBehaviourToList(world1,body1,'MV_SEEK');
print(mvGetEntryListNodeParameter(world1,body1,entry1,'MV_WAYPOINT'))

body2 = mvCreateBody(world1,'MV_PARTICLE','MV_AABOX',4,5,-6);
entry2 = mvAddBehaviourToList(world1,body2,'MV_PURSUIT');
print(entry2)
errorCode = mvSetEntryListNodeParameter(world1, body2, entry2, 'MV_BODY', body1)
print(mvGetErrorEnumString(errorCode))
print(mvGetEntryListParameter(world1,body2,'MV_BODY'))
errorCode = mvSetEntryListNodeParameter(world1, body1, entry2, 'MV_WEIGHT', 0.5)
print(mvGetErrorEnumString(errorCode))

--mvSetDefaultBehaviourFactorForBody(world1,body2,5)
--mvSetEntryListParameter(world1,body2,waypoint1);
--mvAddBehaviourToBody(world1,body1,'MV_SEEK');

