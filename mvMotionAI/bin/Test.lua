world1 = mvAddWorld('HELLO');
wpIndex = mvAddWaypoint(world1,'MV_SINGLE_WAYPOINT','MV_AABOX',3,4,5);
body1 = mvAddBody(world1,'MV_PARTICLE','MV_AABOX',-1,5,-2);
group1 = mvAddGroup(world1, 'BOIDS');
mvAddCurrentBodyToCurrentGroup(world1);
mvSetDefaultWaypointForBody(world1, wpIndex, body1);
mvAddBehaviourToBody(world1,body1,'MV_SEEK');

body2 = mvAddBody(world1,'MV_PARTICLE','MV_SPHERE',-1,5,2);
beh2 = mvAddBehaviour(world1,'MV_PURSUIT');
mvSetDefaultBodyForBody(world1, body1, body2);
mvAddBehaviourToBody(world1,body2,'MV_PURSUIT');
--mvAddBehaviourToBody(world1,body2,'MV_EXISTING_BEHAVIOUR',beh2);

gb1 = mvAddGroupBehaviour(world1,'MV_SIMPLE_FLOCK');
mvAddCurrentBodyToCurrentGroup(world1);
mvInsertCurrentGroupIntoCurrentGroupBehaviour(world1);

body2 = mvAddBody(world1,'MV_PARTICLE','MV_SPHERE',4,5,2);
mvSetDefaultBodyForBody(world1, body1, body2);
mvAddBehaviourToBody(world1,body2,'MV_PURSUIT');
mvAddCurrentBodyToCurrentGroup(world1);

body2 = mvAddBody(world1,'MV_PARTICLE','MV_AABOX',4,5,-6);
mvSetDefaultBodyForBody(world1, body1, body2);
mvAddBehaviourToBody(world1,body2,'MV_PURSUIT');
mvAddCurrentBodyToCurrentGroup(world1);

body2 = mvAddBody(world1,'MV_PARTICLE','MV_AABOX',-4,5,-6);
mvSetDefaultBodyForBody(world1, body1, body2);
mvAddBehaviourToBody(world1,body2,'MV_CLONE');
mvAddCurrentBodyToCurrentGroup(world1);

body2 = mvAddBody(world1,'MV_PARTICLE','MV_SPHERE',4,7,-6);
--mvSetDefaultBodyForBody(world1, body1, body2);
mvSetDefaultBodyForCurrentBody(world1,body1);
mvAddBehaviourToBody(world1,body2,'MV_CLONE');
mvAddCurrentBodyToCurrentGroup(world1);

mvSetDefaultBodyForBody(world1, body2, body1);
mvAddBehaviourToBody(world1,body2,'MV_FLEE');

mvAddForce(world1,'MV_UNIFORM_FORCE',0,-2,0);
--print('World',world1);
--print('Waypoint',wpIndex);
--print('Body',body1);
--
--mvAddObstacle(world1,'MV_AABOX','MV_SOLID_OBSTACLE',2,3,1);
--mvAddObstacle(world1,'MV_SPHERE','MV_SOLID_OBSTACLE',2,5,1);
---mvAddBehaviour(world1,'hello','MV_SEEK');
--mvAddCurrentBehaviourToCurrentBody(world1);
--mvAddCurrentWaypointToCurrentBehaviour(world1);
--mvAddCurrentBehaviourToCurrentBody(world1);
--mvAddBehaviour(world1,'hello2','MV_PURSUIT');
--mvAddCurrentBehaviourToCurrentBody(world1);
--mvAddBodyToCurrentBehaviour(world1,body1);
--mvAddCurrentBehaviourToCurrentBody(world1);
