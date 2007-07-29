/**
 *\file mvVec3.h
 * Copyright (c) 2006 David Young.
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
 * (2006) Code based on Vec3.h + Vec3.cpp from OpenSteer Steering Module (2001-2006)
 *
 * Log
 *
 * 00-01-21  23/11/06  - changed from normalised to normalized
 *
 * 00-01-21  23/11/06  - added cosine measure
 *
 * 00-01-17   -       - add new functions setAll for setting the vector
 */

#ifndef MV_MVVEC3_H_
#define MV_MVVEC3_H_
#include "mvMotionAI-Types.h"
// TODO (White 2#1#): Doxygen documentation

// replacement for OpenSteer's Vec3
/**
 * \brief c array index equivalent to the x component
 */
static const mvIndex MV_VEC3_X_COMPONENT = 0;

/**
 * \brief c array index equivalent to the y component
 */
static const mvIndex MV_VEC3_Y_COMPONENT = 1;

/**
 * \brief c array index equivalent to the z component
 */
static const mvIndex MV_VEC3_Z_COMPONENT = 2;

/**
 * \brief mvVec3's mvFloat array length
 *
 * this constant can be used when iterate over these values
 */
static const mvCount MV_VEC3_NO_OF_COMPONENTS = 3;

/**
 * \class mvVec3 mvVec3.h
 * \brief vector class used in mvMotionAI library for 3D motion
 *
 * this class contains an array of mvFloat (or floating variables) which are
 * used to store details such as position, velocity and force in 3D space.
 */
class mvVec3
{
   private:
      mvFloat components[MV_VEC3_NO_OF_COMPONENTS]; /*!< mvFloat array */

   public:
      mvVec3(void);
      mvVec3(const mvFloat& X, const mvFloat& Y, const mvFloat& Z);
      mvVec3(const mvFloat* array);
      mvVec3(const mvVec3& rhs);

      mvVec3 operator+ (const mvVec3& v) const;
      mvVec3 operator- (const mvVec3& v) const;
      mvVec3 operator- (void) const;
      mvVec3 operator* (const mvFloat s) const;
      mvVec3 operator/ (const mvFloat s) const;
      // rename dot => dot product of normalized values
      mvFloat cosineMeasure(const mvVec3& v) const;
      mvFloat normalizedDotProduct(const mvVec3& v) const;

      // leaves values same
      mvFloat dot (const mvVec3& v) const;

      /*
      mvFloat dotX (const mvVec3& v) const;
      mvFloat dotY (const mvVec3& v) const;
      mvFloat dotZ (const mvVec3& v) const;
      mvFloat dotXY (const mvVec3& v) const;
      mvFloat dotXZ (const mvVec3& v) const;
      mvFloat dotYZ (const mvVec3& v) const;
      */

      mvFloat length (void) const;
      mvFloat lengthSquared (void) const;

      mvVec3 normalize (void) const;
      void AcrossB(const mvVec3& a,const mvVec3& b);
      mvVec3 cross(const mvVec3& rhs) const;
      const mvVec3& operator= (const mvVec3& v);
      const mvVec3&  set (const mvFloat _x, const mvFloat _y, const mvFloat _z);

      const mvVec3& operator+= (const mvVec3& v);
      const mvVec3& operator-= (const mvVec3& v);
      const mvVec3& operator*= (const mvFloat& s);
      const mvVec3& operator+= (const mvFloat& s);
      const mvVec3& operator-= (const mvFloat& s);
      const mvVec3& operator/= (const mvFloat& s);
      bool operator== (const mvVec3& v) const;
      bool operator!= (const mvVec3& v) const;

      /*
      void resetX (void);
      void resetY (void);
      void resetZ (void);
      void resetXYZ(void);
      */
      void setX (const mvFloat& x);
      void setY (const mvFloat& y);
      void setZ (const mvFloat& z);

      /*
      void setXYZ (const mvFloat& x,const mvFloat& y,const mvFloat& z);
      void setAll(const mvVec3& rhs);

      void setAsXUnitVector (void);
      void setAsYUnitVector (void);
      void setAsZUnitVector (void);
      void setToZeroVector(void);

      void addVec3(const mvVec3& rhs);
      void minusVec3(const mvVec3& rhs);
      void timesVec3(const mvVec3& rhs);
      void divideVec3(const mvVec3& rhs);
      // TODO : inplace sign change
      */
      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;

      const mvFloat* getPointer() const;

      /*
      * --------------------------------------------------------------------------
      *  scalar times vector product ("float * Vec3")
      */

      // void matrixMultiply(const mvFloat* matrix, int noOfValues, int order);
      friend mvVec3 operator* (float s, const mvVec3& v);
      //friend std::ostream& operator<< (std::ostream& o, const mvVec3& v);

// TODO (White 2#1#): Distance function between to two points
// TODO (White 2#1#): Distance sqaured between two points

};



#endif
