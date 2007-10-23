worldID = mvCreateWorld()
mvCreateBody(worldID, 'MV_PARTICLE', 'MV_AABOX', 5 ,6 ,7)
mvCreateBody(worldID, 'MV_PARTICLE', 'MV_AABOX', 1 ,6 ,7)
mvCreateBody(worldID, 'MV_PARTICLE', 'MV_AABOX', -3 ,6 ,7)

force = mvCreateForce(worldID, 'MV_GRAVITY');
mvCreateObstacle(worldID, 'MV_SPHERE', 'MV_AIR_OBSTACLE',3, 4);
waypoint = mvCreateWaypoint(worldID, 'MV_SPHERE');
mvSetWaypointParameter(worldID, waypoint, 'MV_RADIUS', 4);

