world1 = mvAddWorld('HELLO_WORLD');
body1 = mvAddBody(world1,'MV_PARTICLE','MV_AABOX',4,1,0);
waypoint1 = mvAddWaypoint(world1,'MV_SINGLE_WAYPOINT','MV_AABOX',10,11,4);
-- comments start with --
-- this
mvSetDefaultWaypointForBody(world1,waypoint1,body1);
mvAddBehaviourToBody(world1,body1,'MV_FLEE')
