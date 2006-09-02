head	1.2;
access;
symbols;
locks; strict;
comment	@// @;


1.2
date	2006.04.07.15.35.28;	author White 2;	state dead;
branches;
next	1.1;
deltatype	text;
kopt	kv;
permissions	444;
commitid	3d0443686be4387;
filename	Collision.cpp;

1.1
date	2006.04.07.15.31.29;	author White 2;	state Exp;
branches;
next	;
deltatype	text;
kopt	kv;
permissions	666;
commitid	c34443685cf407b;
filename	Collision.cpp;


desc
@@


1.2
log
@*** empty log message ***
@
text
@#define MAX_NO_OF_VECTORS_COMPONENTS 3
#include "mvEnum.h"

class AABB_Box
{
   float pos[3];
   float dims[3];
};

static const int MV_AABB_MIN_INDEX = 0;
static const int MV_AABB_MAX_INDEX = 1;

bool AABBtoAABB_Collision(float* pos1, float* pos2, float* dims1, float* dims2)
{
  int i;
  float top;
  float bottom;
  float otop;
  float obottom;

  for (i = 0; i < MAX_NO_OF_VECTORS_COMPONENTS; ++i)
  {
    top = pos1[i] + 0.5f * dims1[i];
	 bottom = pos1[i] - 0.5f * dims1[i];
	 otop = pos2[i] + dims2[i];
	 obottom = pos2[i] - dims2[i];
      
    if (bottom > otop || top > obottom)
	   return false;
  }
  return true;
};

bool SpheretoAABB_Collision(float** aabb_dims, float* sphere_pos, float sphere_radius)
{
  int i;
  float distSq = 0.0f;
  const int minIndex = 0;
  const int maxIndex = 1;
  float delta;

  float radiusSq = sphere_radius;
  radiusSq *= sphere_radius;

  for (i = 0; i < MAX_NO_OF_VECTORS_COMPONENTS; ++i)
  {
    if (sphere_pos[i] > aabb_dims[MV_AABB_MIN_INDEX][i])
    {
      delta = sphere_pos[i];
      delta -= aabb_dims[MV_AABB_MIN_INDEX][i];
      delta *= delta;
      distSq += delta;
    }
    else if (sphere_pos[i] > aabb_dims[MV_AABB_MAX_INDEX][i])
    {
      delta = sphere_pos[i];
      delta -= aabb_dims[MV_AABB_MAX_INDEX][i];
      delta *= delta;
      distSq += delta;
    }
  }
  return (distSq < radiusSq) ? true : false;    
}

bool SpheretoSphere_Colision(float* pos1, float* pos2, float radius1, float radius2)
{
  float distSq = 0.0f;
  float len;
  int i;
  float totalRadius = radius1;
  float radius2Sq = radius2;

  totalRadius *= radius1;
  radius2Sq *= radius2;
  totalRadius += radius2Sq;

  for (i = 0; i < MAX_NO_OF_VECTORS_COMPONENTS; ++i)
  {
     len = pos2[i] - pos1[i];
     len *= len;
     distSq += len;
  }
  return (distSq < totalRadius) ? true : false;
}

bool AAABtoMinAAPlane_Collision(mvEnum index, float** aabb, float* pos)
{
   return (aabb[MV_AABB_MIN_INDEX][index] < pos[index]) ? true : false;
}

bool AAABtoMaxAAPlane_Collision(mvEnum index, float** aabb, float* pos)
{
   return (aabb[MV_AABB_MAX_INDEX][index] > pos[index]) ? true : false;
}

bool SpheretoMinAAplane_Collision(mvEnum index, float radius, float* sphere_pos, float* plane_pos)
{
   float bottom = sphere_pos[index];
   bottom -= radius;

   return (bottom < plane_pos[index]) ? true : false;
}

bool SpheretoMaxAAplane_Collision(mvEnum index, float radius, float* sphere_pos, float* plane_pos)
{
   float top = sphere_pos[index];
   top -= radius;

   return (top < plane_pos[index]) ? true : false;
}

bool AABBtoAACylinder_Collision(float** aabb_dims, mvEnum index, float cylinder_radius,
                                float* cylinder_pos, float cylinder_length)
{
  int i;
  float distSq = 0.0f;
  float delta;
  float radiusSq = cylinder_radius;
  float highest = cylinder_pos[index] + cylinder_length / 2.0f;
  float lowest = cylinder_pos[index] - cylinder_length / 2.0f;

  if (aabb_dims[MV_AABB_MAX_INDEX][index] > highest  
       || aabb_dims[MV_AABB_MIN_INDEX][index] < lowest)
     return false;

  radiusSq *= cylinder_radius;

  for (i = 0; i < MAX_NO_OF_VECTORS_COMPONENTS; ++i)
  {
    if (i != index)
    {
       if (cylinder_pos[i] < aabb_dims[MV_AABB_MIN_INDEX][i])
       {
         delta = cylinder_pos[i];
         delta -= aabb_dims[MV_AABB_MIN_INDEX][i];
         delta *= delta;
         distSq += delta;
       }
       else if (cylinder_pos[i] > aabb_dims[MV_AABB_MAX_INDEX][i])
       { 
         delta = cylinder_pos[i];
         delta -= aabb_dims[MV_AABB_MIN_INDEX][i];
         delta *= delta;
         distSq += delta;
       }
    }
  }

  return (distSq < radiusSq) ? true : false;    
}

@


1.1
log
@First Commit

Still Don't understand CVS
@
text
@@

