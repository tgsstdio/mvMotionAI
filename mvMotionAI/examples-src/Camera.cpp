/**
 * \file Camera.cpp
 *
 * Copyright (c) 2004 - 2006 David Young.
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
 */

#include "Camera.h"
#include <GL/glut.h>

void Camera::applyTranslation()
{
   glTranslatef(-xPosition,-yPosition,-zPosition);
}

void Camera::applyRotation()
{
   glRotatef(xRotate,1.0f,0.0f,0.0f);
   glRotatef(yRotate,0.0f,1.0f,0.0f);
   glRotatef(zRotate,0.0f,0.0f,1.0f);
}

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
}

void Camera::setCameraAround()
{
   rotationMethod = CAMERA_AROUND;
}

void Camera::setCameraOn()
{
   rotationMethod = CAMERA_ON;
}

Camera::Camera(float x, float y, float z)
{
   xPosition = x;
   yPosition = y;
   zPosition = z;
   xRotate = 0.0f;
   yRotate = 0.0f;
   zRotate = 0.0f;
}

void Camera::resetCamera()
{
   xPosition = 0.0f;
   yPosition = 0.0f;
   zPosition = 0.0f;
   xRotate = 0.0f;
   yRotate = 0.0f;
   zRotate = 0.0f;
}

void Camera::setCamera(float x, float y,float z)
{
   xPosition = x;
   yPosition = y;
   zPosition = z;
}

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
}

// add rotation
void Camera::addXRotation(float xAngle)
{
   xRotate += xAngle;
}

void Camera::addYRotation(float yAngle)
{
   yRotate += yAngle;
}

void Camera::addZRotation(float zAngle)
{
   zRotate += zAngle;
}

// add  Position
void Camera::addXPosition(float x)
{
   xPosition += x;
}

void Camera::addYPosition(float y)
{
   yPosition += y;
}

void Camera::addZPosition(float z)
{
   zPosition += z;
}

// set rotation
void Camera::setXRotation(float xAngle)
{
   xRotate = xAngle;
}

void Camera::setYRotation(float yAngle)
{
   yRotate = yAngle;
}

void Camera::setZRotation(float zAngle)
{
   zRotate = zAngle;
}

// set  Position
void Camera::setXPosition(float x)
{
   xPosition = x;
}

void Camera::setYPosition(float y)
{
   yPosition = y;
}

void Camera::setZPosition(float z)
{
   zPosition = z;
}

// get rotation
float Camera::getXRotation() const
{
   return xRotate;
}

float Camera::getYRotation() const
{
   return yRotate;
}

float Camera::getZRotation() const
{
   return zRotate;
}

// get position
float Camera::getXPosition() const
{
   return xPosition;
}

float Camera::getYPosition() const
{
   return yPosition;
}

float Camera::getZPosition() const
{
   return zPosition;
}


