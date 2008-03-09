/**
 *\file mvLFVec3.h
 * Copyright (c) 2008 David Young.
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
 * 00-02-50
 * - converted vector class into lightheader vector3df holder class
 */

#ifndef MV_MVVEC3_H_
#define MV_MVVEC3_H_

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include <lf/lightfeather.h>

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

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

class MV_GLOBAL_FUNC_PREFIX mvVec3
{
	private:
		mvVec3(const lf::core::vector3df& rhs);

	public:
      lf::core::vector3d<mvFloat> components;
      mvVec3(void);
      explicit mvVec3(const mvFloat& X, const mvFloat& Y, const mvFloat& Z);
      explicit mvVec3(const mvFloat* array);
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

      void setX (const mvFloat& x);
      void setY (const mvFloat& y);
      void setZ (const mvFloat& z);

      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;

		mvCount extractVecToArray(mvFloat* array) const;
      const mvFloat* getPointer() const;
      void  toZeroVec();
      void  randomiseNormal();

      friend mvVec3 operator* (float s, const mvVec3& v);
};



#endif
