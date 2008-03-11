/**
 * \file sideproject4.cpp
 * \brief sideproject4 : implement group behaviour functionalities
 *
 * Copyright (c) 2005 - 2006 David Young.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Log
 *
 * 00-01-21    25/11/06
 * - updated file duer to function name change
 *
 * 00-01-16    17/10/06
 * - mvEnums enumerations changed to mvOptionEnum
 */

#include <GL/glut.h>
#include <iostream>
#include "../Camera.h"
#include <cstdlib>

/*
 * Step 1.0 : include header to use library
 */
#include <mv/mvMotionAI.h>
#include "mvFlyingV.h"
#include "mvMovingAcross.h"
#include <mvReadyMadeLoader.h>

static float left = -1.0;
static float right = 1.0;
static float bottom = -1.0;
static float top = 1.0;
static float nearValue = 1.0;
static float farValue = 100.0;
static float lightPos1[] = {5.0,0.0,5.0,0.0};

static Camera worldCam;
static int windowHeight = 500;
static int windowWidth = 480;

static const float MIN_FRAME_PERIOD = 1.0f/60.0f * 1000.0f;
static float previousTime;
static float elapsedTime = 0.0;
static long int noOfFrames = 0;
static float angle = 0.0;
static double frameRateInterval = 0.0;

#define BUFFER_SIZE 1024
static char buffer[BUFFER_SIZE];
void displayFrameRate(long int frameNo);
void drawText(GLint x, GLint y, char* s, int windowWidth,
              int windowHeight, GLfloat r, GLfloat g, GLfloat b);
void drawGLShape(int drawMode, mvConstShapePtr shapePtr,
   const mvVec3& pos, float r, float g, float b);
void init();
void reshape(int w, int h);
void keyboard(unsigned char key,int x, int y);
void display();
void animate();

#define USE_ARGUMENTV_FILE_ARG_COUNT 2
#define FILE_NAME_ARGV_INDEX 1
char defaultLuaFileName[] = "Test.lua";
char* scriptFileName = NULL;
bool isAnimating = false;

void displayMotionAI();
void displayWaypoint(mvWaypointPtr wp, void* ptr);
void displayObstacle(mvObstaclePtr o, void* ptr);
void displayBody(mvBodyPtr p, void* extraPtr);
void worldFunction(mvWorldPtr tempWorld, void* ptr);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (windowWidth, windowHeight);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Tutorial 2 : Integrating mvMotionAI into an OpenGL application");

   /*
    * Step 2 : initialise mvMotionAI library
    */
   mvInitMotionAI();
   mvErrorEnum initError = mvInitDefaultActions();
   if (initError != MV_NO_ERROR)
   {
      puts("MV INIT ACTIONS ERROR");
   }

   initError = mvInitDefaultForces();
   if (initError != MV_NO_ERROR)
   {
      puts("MV INIT FORCES ERROR");
   }

	mvBaseActionLoader* actionLoader = new mvReadyMadeActionLoader<mvMovingAcross>();

	mvAddBehaviourFunction(MV_PARTICLE, actionLoader);
	mvAddBehaviourFunction(MV_VEHICLE, new mvReadyMadeActionLoader<mvFlyingV>());

   init ();

   // call mvMotionAI
   mvErrorEnum paramError;
   int worldID = mvCreateWorld();

   int bodyID = mvCreateBody(worldID,MV_PARTICLE,MV_SPHERE, 1 , 4 , 0);

   mvAddBehaviourToList(worldID, bodyID, MV_PARTICLE,0,0);

	int behaviourID = mvCreateGroupBehaviour(worldID, MV_VEHICLE);
	int groupID = mvCreateGroup(worldID);

	mvAddMemberIntoGroup(worldID, groupID, bodyID);
	mvAddGroupIntoGroupBehaviour(worldID, behaviourID, groupID);

	float position[4] = {1,1,0,1};
	float initialPos[4] = {0,0,0,1};

	for (int j = 0; j < 10; j++)
	{
		bodyID = mvCreateBody(worldID,MV_PARTICLE,MV_SPHERE, 1 , 4 , 0);
		initialPos[0] = j;
		mvSetBodyParameterv(worldID, bodyID, MV_POSITION, &initialPos[0]);
		mvAddMemberIntoGroup(worldID, groupID, bodyID);
		paramError = mvRegisterGroupBehaviourToBodies(worldID, behaviourID);
		if (paramError)
		{
			std::cout <<"Param Error " << mvGetErrorEnumString(paramError) << std::endl;
		}
		mvSetEntryListNodeParameterv(worldID, bodyID, -1, MV_POSITION, &position[0]);
		mvSetEntryListNodeParameteri(worldID, bodyID, -1, MV_INDEX, bodyID - 1);
	}

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);

   glutMainLoop();
   return EXIT_SUCCESS;
}

const char* animateFlag = NULL;
const char no_animation[] = "a : Start animation";
const char yes_animation[] = "A : stop Animation";
const char camera_keys[] = "q|Q/w|W/e|E : move camera\nz|Z/x|X/c|c rotates camera\n";

void display(void)
{
   //int i = 0;

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
     worldCam.apply();
     glLightfv(GL_LIGHT0,GL_POSITION,lightPos1);

     glColor3f(0,1,0);
     glBegin(GL_QUADS);
       glNormal3f(0,1,0);
       glVertex3f(20,0,-20);
       glVertex3f(-20,0,-20);
       glVertex3f(-20,0,20);
       glVertex3f(20,0,20);
     glEnd();

     /*
      * MISC: Use teapot to see if animation is on.
      */

     glPushMatrix();
       glRotatef(angle,0,1,0);
       glColor3f(1,1,1);
       glutSolidTeapot(1.0);
     glPopMatrix();

     /*
      * Step 4: Add the user defined function
      * application to interact with mvMotionAI library
      * displayMotionAI;
      */
     displayMotionAI();

   glPopMatrix();
   /*
    * MISC : draw frame rate
    */

   animateFlag = (isAnimating) ? yes_animation : no_animation;
   sprintf(buffer,"tutorial2, 2007\nFrame Rate : %3.3f fps\n%s\n%s\n",frameRateInterval,animateFlag,camera_keys);

   drawText(5, windowHeight - 13, buffer ,windowWidth,windowHeight, 1.0, 1.0, 1.0);
   glFlush();
   glutSwapBuffers();
}

void displayMotionAI()
{
   /*
    * Step 5: For all worlds, we apply the function 'worldFunction'
    * as a function pointer. By passing the function name to mvApplyToAllWorlds
    * and some other parameter. Here we used NULL but you could pass
    * structures, classes and anything that will fit as a void* pointer.
    */
   mvApplyToAllWorlds(worldFunction,NULL);
}

void worldFunction(mvWorldPtr tempWorld, void* entry)
{
   /*
    * Step 6: Here we call other functions to draw the classes
    * inside the mvWorld instance such as mvBody, mvObstacles
    * & mvWaypoints. Each of these functions below take a void function
    * i.e void func(mvClass* object, void* ptr);
    */
   if (tempWorld != NULL)
   {
      tempWorld->applyToAllBodies(displayBody,NULL);
      tempWorld->applyToAllObstacles(displayObstacle,NULL);
      tempWorld->applyToAllWaypoints(displayWaypoint,NULL);
   }
}

/*
 * Step 6a : this function draws the mvBody type in the
 * application
 */
void displayBody(mvBodyPtr p,void* extraPtr)
{
//   mvOptionEnum tempShape;

   if (p != NULL)
   {
      glPushAttrib(GL_LIGHTING_BIT);
      glDisable(GL_LIGHTING);
      // Direction
      glPushMatrix();
         glTranslatef(p->getX(),p->getY(),p->getZ());
         glBegin(GL_LINES);
         // RED TO GREEN - own velocity
         glColor3f(1,0,0);
         glVertex3f(0,0,0);
         glColor3f(0,1,0);
         glVertex3f(p->getVelocity().getX(), p->getVelocity().getY(), p->getVelocity().getZ());
         // GREEN TO BLUE - final velocity
         glEnd();
         glTranslatef(0,1,0);
         glBegin(GL_LINES);
            glColor3f(0,1,0);
            glVertex3f(0,0,0);
            glColor3f(0,0,1);
            glVertex3f(p->getFinalVelocity().getX(), p->getFinalVelocity().getY(), p->getFinalVelocity().getZ());
         glEnd();
      glPopMatrix();
      glPopAttrib();

      drawGLShape(GL_FILL, p->getShape(),p->getPosition(), 1, 1, 1);

   }
}

/*
 * Step 6b : this function draws the mvObstacle type in the
 * application
 */
void displayObstacle(mvObstaclePtr o,void* extraPtr)
{
   //const float offsetY = 0.5;
//   mvOptionEnum tempShape;

   if (o != NULL)
   {
      drawGLShape(GL_FILL, o->getShape(),
         o->getPosition(), 1, 0, 1);
   }
}

void drawGLShape(int drawMode, mvConstShapePtr shapePtr,
   const mvVec3& pos, float r, float g, float b)
{
   mvOptionEnum tempShape;
   mvFloat radius;
   //.. length;
   mvFloat aaboxDimensions[MV_VEC3_NO_OF_COMPONENTS];
   mvCount noOfDimensions;
   mvErrorEnum error;

   glPushMatrix();
      glTranslatef(pos.getX(),pos.getY(),pos.getZ());
      tempShape = shapePtr->getType();
      if (tempShape == MV_AABOX)
      {
         error = shapePtr->getParameterv(MV_SHAPE_DIMENSIONS,
         &aaboxDimensions[0],  &noOfDimensions);
         if (error == MV_NO_ERROR)
         {
            glScalef(aaboxDimensions[0], aaboxDimensions[1],\
            aaboxDimensions[2]);
            glColor3f(r,g,b);
         }
         else
         {
            glColor3f(1,0,0);
         }
         if (drawMode == GL_LINE)
         {
            glutWireCube(1.0);
         }
         else
         {
            glutSolidCube(1.0);
         }
      }
      else if (tempShape == MV_SPHERE)
      {
         error = shapePtr->getParameterf(MV_RADIUS, &radius);
         if (error == MV_NO_ERROR)
         {
            glColor3f(r,g,b);
         }
         else
         {
            glColor3f(1,0,0);
            radius = 1;
         }

         if (drawMode == GL_LINE)
         {
            glutWireSphere(radius,20,20);
         }
         else
         {
            glutSolidSphere(radius,20,20);
         }
      }
      else
      {
         if (drawMode == GL_LINE)
         {
            glutWireOctahedron();
         }
         else
         {
            glutSolidOctahedron();
         }

      }
   glPopMatrix();
}

/*
 * Step 6c : this function draws the mvWaypoint type in the
 * application
 */
void displayWaypoint(mvWaypointPtr wp,void* extraPtr)
{
   if (wp != NULL)
   {
      drawGLShape(GL_LINE, wp->getShape(),
         wp->getPosition(), 1, 1, 0);
   }
}

void animate(void)
{
   float temp = (float) glutGet(GLUT_ELAPSED_TIME);
   float diffTime = temp - previousTime;
   float timeInSecs;

   elapsedTime = glutGet(GLUT_ELAPSED_TIME)/(float)1000.0;
   if (diffTime >  MIN_FRAME_PERIOD)
   {
     timeInSecs = diffTime/1000.0;
	  angle += (float) 25.0 * (timeInSecs);
     previousTime = temp;
     /*
      * Step 7 : To animate mvMotionAI, add elapsed time in seconds to step
      * the worlds forward.
      */
      //std::cout << "BEFORE" <<std::endl;
      mvAllWorldsStepForward(timeInSecs);
      //std::cout << "AFTER" <<std::endl;
   }
   displayFrameRate(noOfFrames);
   glutPostRedisplay();
   noOfFrames++;
}

void displayFrameRate(long int frameNo)
{

  static const double interval = 1.0;
  static long int frameNoStartInterval = 0;
  static double elapsedTimeStartInterval = 0.0;
  static double tpfPrevious = 0.0;
  static double tpfCurrent = 0.0;
  static int noOfSeconds = 0;

  if (elapsedTime > elapsedTimeStartInterval + interval)

  {
    frameRateInterval = (frameNo - frameNoStartInterval) /
                      (elapsedTime - elapsedTimeStartInterval);
    elapsedTimeStartInterval = elapsedTime;
    frameNoStartInterval = frameNo;
    tpfCurrent = 1000.0/frameRateInterval;
    std::cout << "TPF : " << tpfCurrent << " +/- " << tpfCurrent - tpfPrevious <<std::endl;
    tpfPrevious = tpfCurrent;
    noOfSeconds++;
    /*
    if (noOfSeconds > 10)
    {
      exit(0);
    }
    */
  }
}

/*
 * Ignore these function below
 */

void cleanup()
{
   mvFreeMotionAI();
}

/* ARGSUSED1 */
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'a':
         previousTime = (float) glutGet(GLUT_ELAPSED_TIME);
         glutIdleFunc(animate);
         isAnimating = true;
         glutPostRedisplay();
         break;
      case 'A':
         glutIdleFunc(NULL);
         isAnimating = false;
         glutPostRedisplay();
         break;
      case 'z':
         worldCam.addXRotation(15.0);
         glutPostRedisplay();
         break;
      case 'Z':
         worldCam.addXRotation(-15.0);
         glutPostRedisplay();
         break;
      case 'x':
         worldCam.addYRotation(15.0);
         glutPostRedisplay();
         break;
      case 'X':
         worldCam.addYRotation(-15.0);
         glutPostRedisplay();
         break;
      case 'c':
         worldCam.addZRotation(15.0);
         glutPostRedisplay();
         break;
      case 'C':
         worldCam.addZRotation(-15.0);
         glutPostRedisplay();
         break;
      case 'q':
         worldCam.addXPosition(0.25);
         glutPostRedisplay();
         break;
      case 'Q':
         worldCam.addXPosition(-0.25);
         glutPostRedisplay();
         break;
      case 'w':
         worldCam.addYPosition(0.25);
         glutPostRedisplay();
         break;
      case 'W':
         worldCam.addYPosition(-0.25);
         glutPostRedisplay();
         break;
      case 'e':
         worldCam.addZPosition(0.25);
         glutPostRedisplay();
         break;
      case 'E':
         worldCam.addZPosition(-0.25);
         glutPostRedisplay();
         break;
      case 27:
         cleanup();
         exit(0);
         break;
      default:
         break;
   }
}

void init(void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  worldCam.resetCamera();
  worldCam.addYPosition(3);
  // refresh screen
  displayFrameRate(noOfFrames);
  glutPostRedisplay();
}

void drawText(GLint x, GLint y, char* s, int windowWidth,
              int windowHeight, GLfloat r, GLfloat g, GLfloat b)
{

  /* Fron Luke Bigum's TiledProj,2005*/

  int lines;
  char* p;

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();

  glLoadIdentity();
  glOrtho(0.0, windowWidth,
        0.0, windowHeight, -1.0, 1.0);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();


  glPushAttrib(GL_ENABLE_BIT);
  glDisable(GL_LIGHTING);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_TEXTURE_2D);


  glColor3f(r, g, b);
  glRasterPos2i(x, y);
  for(p = s, lines = 0; *p; p++)
  {
    if (*p == '\n')
    {
      lines++;
      glRasterPos2i(x, y-(lines*15));
      continue;
    }
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *p);
  }

  glPopAttrib();
  glEnable(GL_DEPTH_TEST);
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}

void reshape (int w, int h)
{
   windowWidth = w;
   windowHeight = h;

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum(left,right,bottom,top,nearValue,farValue);
   gluLookAt( 0 , 0, 2.0, 0, 0 , 0, 0, 1.00, 0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -3.0);
}

/*
void displayParticle(Particle* p)
{
   if (p != NULL)
   {
     glPushMatrix();
       glPushAttrib(GL_LIGHTING_BIT);
       glDisable(GL_LIGHTING);
       glTranslatef(p->position.x,p->position.y,p->position.z);
       glutWireSphere(p->radius,15,15);
       glPopAttrib();
     glPopMatrix();
   }
};
**

void displayVehicle(Vehicle* v)
{
  **
  static bool firstRun = true;

  if (firstRun)
  {
     std::cout << "Hello" << std::endl;
     firstRun = false;
  }
  **

  glPushMatrix();
    if (v != NULL)
       glTranslatef(v->position.x,v->position.y,v->position.z);
    glPushMatrix();
      glColor3f(1,1,1);
      glTranslatef(0,1.5,0);
      glRotatef(-90,0,1,0);
      glutSolidTetrahedron();
    glPopMatrix();

    **
     * Direction and velocity
     *
    glPushMatrix();
      glTranslatef(0,1.5,0);
      glBegin(GL_LINES);
        glColor3f(1,0,1);
        glVertex3f(0.1f,0,0);
        glVertex3f(v->direction.x + 0.1f,v->direction.y,v->direction.z * 3.0f);

        glColor3f(0,1,1);
        glVertex3f(-0.1f,0,0);
        glVertex3f(v->direction.x -0.1f,v->direction.y,3.0 * v->direction.z * v->currentSpeed/v->maxSpeed);
      glEnd();
    glPopMatrix();

    glColor3f(1,1,0);
    glRotatef(-90,1,0,0);
    glutSolidCone(1.0,1.5,30,30);
  glPopMatrix();
}
**
void displayObstacle(Obstacle* o)
{
   const float offsetY = 0.5;
   glPushMatrix();
     if (o != NULL)
        glTranslatef(o->position.x,o->position.y +  offsetY,o->position.z);
     glColor3f(1,0,0);
     glutSolidCube(1.0);
   glPopMatrix();
}

void displayEndPoint(Vec3* location)
{
   if (location != NULL)
   {
     glPushMatrix();
       glTranslatef(location->x,location->y,location->z);
       glColor3f(1,0,1);
       //glutSolidDodecahedron();
       glutSolidIcosahedron();
     glPopMatrix();
   }
}

void displayWaypoint(Vec3* location)
{
   if (location != NULL)
   {
     glPushMatrix();
       glTranslatef(location->x,location->y,location->z);
       glColor3f(0,1,1);
       //glutSolidOctahedron();
       glutSolidOctahedron();
     glPopMatrix();
   }
};
**
void displayPathway(Pathway *p)
{
   int i = 0;
   int noOfWayPoints;

   if (p != NULL)
   {
      noOfWayPoints = p->noOfWaypoints;
      glPushMatrix();
        **
         * Draws first point
         *
        if (noOfWayPoints > 1)
        {
          displayEndPoint(p->wayPoints[i]);
        }
        *
        Draws lines between points
        *
        glPushAttrib(GL_LIGHTING_BIT);
          glDisable(GL_LIGHTING);
          glBegin(GL_LINES);
          glColor3f(1,1,1);
          for (i = 1; i < noOfWayPoints; i++)
          {
            glVertex3f(p->wayPoints[i]->x,p->wayPoints[i]->y,p->wayPoints[i]->z);
            glVertex3f(p->wayPoints[i-1]->x,p->wayPoints[i-1]->y,p->wayPoints[i-1]->z);
          }
          glEnd();
        glPopAttrib();
        **

        **
         * Draws last end  and waypoints between them
         *
        if (noOfWayPoints >= 2)
        {
          displayEndPoint(p->wayPoints[noOfWayPoints-1]);
        }


        if (noOfWayPoints >= 3)
        {
           for (i = 1; i < noOfWayPoints - 1; i++)
           {
             displayWaypoint(p->wayPoints[i]);
           }
        }

      glPopMatrix();
   }
};
*/
