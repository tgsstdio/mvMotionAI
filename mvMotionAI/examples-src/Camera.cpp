#include "Camera.h"
#include <GL/glut.h>

void Camera::applyTranslation()
{
   glTranslatef(-xPosition,-yPosition,-zPosition);
};

void Camera::applyRotation()
{
   glRotatef(xRotate,1.0f,0.0f,0.0f);
   glRotatef(yRotate,0.0f,1.0f,0.0f);
   glRotatef(zRotate,0.0f,0.0f,1.0f);
};

/*
   float xPosition;
	float yPosition;
	float zPosition;
	float xRotate;
	float yRotate;
	float zRotate;
*/

Camera::Camera()
{
   resetCamera();
   rotationMethod = CAMERA_AROUND;
};

void Camera::setCameraAround()
{
   rotationMethod = CAMERA_AROUND;
};

void Camera::setCameraOn()
{
   rotationMethod = CAMERA_ON;
};

Camera::Camera(float x, float y, float z)
{
   xPosition = x;
   yPosition = y;
   zPosition = z;
   xRotate = 0.0f;
   yRotate = 0.0f;
   zRotate = 0.0f;
};

void Camera::resetCamera()
{
   xPosition = 0.0f;
   yPosition = 0.0f;
   zPosition = 0.0f;
   xRotate = 0.0f;
   yRotate = 0.0f;
   zRotate = 0.0f;
};

void Camera::setCamera(float x, float y,float z)
{
   xPosition = x;
   yPosition = y;
   zPosition = z;
};

void Camera::apply()
{
   if (rotationMethod == CAMERA_AROUND)
   {
      applyTranslation();
      applyRotation();
   }
   else if (rotationMethod == CAMERA_ON)
   {
      applyRotation();
      applyTranslation();
   }
};

// add rotation
void Camera::addXRotation(float xAngle)
{
   xRotate += xAngle;
};

void Camera::addYRotation(float yAngle)
{
   yRotate += yAngle;
};

void Camera::addZRotation(float zAngle)
{
   zRotate += zAngle;
};

// add  Position
void Camera::addXPosition(float x)
{
   xPosition += x;
};

void Camera::addYPosition(float y)
{
   yPosition += y;
};

void Camera::addZPosition(float z)
{
   zPosition += z;
};

// set rotation
void Camera::setXRotation(float xAngle)
{
   xRotate = xAngle;
};

void Camera::setYRotation(float yAngle)
{
   yRotate = yAngle;
};

void Camera::setZRotation(float zAngle)
{
   zRotate = zAngle;
};

// set  Position
void Camera::setXPosition(float x)
{
   xPosition = x;
};

void Camera::setYPosition(float y)
{
   yPosition = y;
};

void Camera::setZPosition(float z)
{
   zPosition = z;
};

// get rotation
float Camera::getXRotation() const
{
   return xRotate;
};

float Camera::getYRotation() const
{
   return yRotate;
};

float Camera::getZRotation() const
{
   return zRotate;
};

// get position
float Camera::getXPosition() const
{
   return xPosition;
};

float Camera::getYPosition() const
{
   return yPosition;
};

float Camera::getZPosition() const
{
   return zPosition;
};


