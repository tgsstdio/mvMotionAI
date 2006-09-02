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
filename	GLTest.cpp;

1.1
date	2006.04.07.15.31.29;	author White 2;	state Exp;
branches;
next	;
deltatype	text;
kopt	kv;
permissions	666;
commitid	c34443685cf407b;
filename	GLTest.cpp;


desc
@@


1.2
log
@*** empty log message ***
@
text
@/**
GLUT Template
2005, David Young
**/

#include <GL/glut.h>
#include "../Camera.h"

static float left = -1.0;
static float right = 1.0;
static float bottom = -1.0;
static float top = 1.0;
static float nearValue = 1.0;
static float farValue = 100.0;
static Camera worldCam;

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
};

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum(left,right,bottom,top,nearValue,farValue);
   gluLookAt( 0 , 0, 2.0, 0, 0 , 0, 0, 1.00, 0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -3.0);
}

void display(void)
{
   int i = 0;

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
     worldCam.apply();
     glutSolidTeapot(1.0);
   glPopMatrix();
   glFlush();
   glutSwapBuffers();
}


/* ARGSUSED1 */
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
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
         exit(0);
         break;
      default:
         break;
   }
};

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
};
@


1.1
log
@First Commit

Still Don't understand CVS
@
text
@@

