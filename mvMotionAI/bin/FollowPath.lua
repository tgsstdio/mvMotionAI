mvInitMotionAI()
mvInitDefaultActions()
worldID = mvCreateWorld()
w1 = mvCreateWaypoint(worldID, 'MV_AABOX', 4, 0 ,6)
w2 = mvCreateWaypoint(worldID, 'MV_AABOX', 11, 0 ,6)
w3 = mvCreateWaypoint(worldID, 'MV_AABOX', -4, 7 ,0)
p1 = mvCreatePathway(worldID)
mvAddNodeToPathway(worldID, p1, w2);
mvAddNodeToPathway(worldID, p1, w1);
mvAddNodeToPathway(worldID, p1, w3);

b1 = mvCreateBody(worldID, 'MV_PARTICLE', 'MV_SPHERE', 4, 5, 6)
e1 = mvAddBehaviourToList(worldID, b1, 'MV_FOLLOW_PATH', 0, 0)
mvSetEntryListNodeParameter(worldID, b1, e1, 'MV_PATHWAY', p1)

