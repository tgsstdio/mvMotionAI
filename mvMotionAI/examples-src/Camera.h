#ifndef CAMERA_H
#define CAMERA_H
/**
 * \file Camera.h
 * \brief this class converts translations
 * so that the camera can be move relative to
 * the world coordinates
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

enum CameraMovement{CAMERA_AROUND, CAMERA_ON};

class Camera
{
   private:
     void applyTranslation();
     CameraMovement rotationMethod;
     float xPosition;
	  float yPosition;
	  float zPosition;
	  float xRotate;
	  float yRotate;
	  float zRotate;

   public:
      Camera();
      void applyRotation();
      void resetCamera();
	   Camera(float x, float y, float z);
      void setCamera(float x, float y,float z);
      void apply();

      // add rotation
      void addXRotation(float xAngle);
      void addYRotation(float yAngle);
	   void addZRotation(float zAngle);
      // add  Position
      void addXPosition(float x);
	   void addYPosition(float y);
	   void addZPosition(float z);

      // set rotation
      void setXRotation(float xAngle);
      void setYRotation(float yAngle);
	   void setZRotation(float zAngle);

      // set  Position
      void setXPosition(float x);
	   void setYPosition(float y);
	   void setZPosition(float z);

      // get rotation
      float getXRotation() const;
      float getYRotation() const;
      float getZRotation() const;
      // get position
      float getXPosition() const;
      float getYPosition() const;
      float getZPosition() const;

      void setCameraAround();
      void setCameraOn();
      void setCameraMotion(CameraMovement cm);
};

#endif

