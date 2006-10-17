world1 = mvAddWorld('HELLO_WORLD');
body1 = mvAddBody(world1,'MV_PARTICLE','MV_AABOX',4,1,0);
waypoint1 = mvAddWaypoint(world1,'MV_SINGLE_WAYPOINT','MV_AABOX',10,11,4);
-- comments start with --
-- this
mvSetDefaultBehaviourFactorForBody(world1,body1,1)
mvSetDefaultWaypointForBody(world1,waypoint1,body1);
mvAddBehaviourToBody(world1,body1,'MV_SEEK');

body2 = mvAddBody(world1,'MV_PARTICLE','MV_AABOX',4,5,-6);
mvSetDefaultBodyForBody(world1, body1, body2);
mvSetDefaultBehaviourFactorForBody(world1,body2,0.5)
mvAddBehaviourToBody(world1,body2,'MV_PURSUIT');
mvAddCurrentBodyToCurrentGroup(world1)

mvSetDefaultBehaviourFactorForBody(world1,body2,5)
mvSetDefaultWaypointForBody(world1,waypoint1,body2);
mvAddBehaviourToBody(world1,body1,'MV_SEEK');
