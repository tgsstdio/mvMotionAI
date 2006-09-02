#ifndef CAMERA_H
#define CAMERA_H
/*
Camera - this class converts translations
so that the camera can be move relative to 
the world coordinates
2004, David Young
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

