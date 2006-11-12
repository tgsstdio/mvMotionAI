/**
 * \file mvVec3.cpp
 *
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
 */

#include "mvVec3.h"
#include "mvMotionAI-Utilities.h"

mvVec3::mvVec3(void)
{
  components[MV_VEC3_X_COMPONENT] = 0;
  components[MV_VEC3_Y_COMPONENT] = 0;
  components[MV_VEC3_Z_COMPONENT] = 0;
}

mvVec3::mvVec3(const mvFloat& X, const mvFloat& Y, const mvFloat& Z)
{
  components[MV_VEC3_X_COMPONENT] = X;
  components[MV_VEC3_Y_COMPONENT] = Y;
  components[MV_VEC3_Z_COMPONENT] = Z;
}

mvVec3::mvVec3(const mvFloat* array)
{
  components[MV_VEC3_X_COMPONENT] = array[MV_VEC3_X_COMPONENT];
  components[MV_VEC3_Y_COMPONENT] = array[MV_VEC3_Y_COMPONENT];
  components[MV_VEC3_Z_COMPONENT] = array[MV_VEC3_Z_COMPONENT];
}

mvVec3::mvVec3(const mvVec3& rhs)
{
  components[MV_VEC3_X_COMPONENT] = rhs.components[MV_VEC3_X_COMPONENT];
  components[MV_VEC3_Y_COMPONENT] = rhs.components[MV_VEC3_Y_COMPONENT];
  components[MV_VEC3_Z_COMPONENT] = rhs.components[MV_VEC3_Z_COMPONENT];
}

mvVec3 mvVec3::operator+ (const mvVec3& v) const
{
   return mvVec3(getX() + v.getX(), getY() + v.getY(), getZ() + v.getZ());
}

mvVec3 mvVec3::operator- (const mvVec3& v) const
{
   return mvVec3(getX() - v.getX(), getY() - v.getY(), getZ() - v.getZ());
}

mvVec3 mvVec3::operator- (void) const
{
   return mvVec3(-getX(), -getY(), -getZ());
}

mvVec3 mvVec3::operator* (const mvFloat s) const
{
   return mvVec3(s * getX(), s * getY(), s * getZ());
}

mvVec3 mvVec3::operator/ (const mvFloat s) const
{
   return mvVec3(getX()/s, getY()/s, getZ()/s);
}

mvFloat mvVec3::dot (const mvVec3& v) const
{
   mvFloat temp = dotXY(v);
   temp += dotZ(v);
   return temp;
}

mvFloat mvVec3::dotX (const mvVec3& v) const
{
   mvFloat temp = getX();
   temp *= v.getX();
   return temp;
}

mvFloat mvVec3::dotY (const mvVec3& v) const
{
   mvFloat temp = getY();
   temp *= v.getY();
   return temp;
}

mvFloat mvVec3::dotZ (const mvVec3& v) const
{
   mvFloat temp = getZ();
   temp *= v.getZ();
   return temp;
}

mvFloat mvVec3::dotXY (const mvVec3& v) const
{
   mvFloat temp = dotX(v);
   temp += dotY(v);
   return temp;
}

mvFloat mvVec3::dotXZ (const mvVec3& v) const
{
   mvFloat temp = dotX(v);
   temp += dotZ(v);
   return temp;
}

mvFloat mvVec3::dotYZ (const mvVec3& v) const
{
   mvFloat temp = dotX(v);
   temp += dotZ(v);
   return temp;
}

mvFloat mvVec3::length (void) const
{
   return mvSqrt(lengthSquared());
}

mvFloat mvVec3::lengthSquared (void) const
{
   mvFloat temp = getX();
   mvFloat ySquare = getY();
   mvFloat zSquare = getZ();
   temp *= getX();
   ySquare *= getY();
   zSquare *= getZ();
   temp += ySquare;
   temp += zSquare;
   return temp;
}

mvVec3 mvVec3::normalize (void) const
{
   // skip divide if length is zero
   const mvFloat len = length ();
   return (len>0) ? (*this)/len : (*this);
}

void mvVec3::AcrossB(const mvVec3& a,const mvVec3& b)
{
/*
       *this = mvVec3 ((a.y * b.z) - (a.z * b.y),
                (a.z * b.x) - (a.x * b.z),
              (a.x * b.y) - (a.y * b.x));
*/
   components[MV_VEC3_X_COMPONENT] = (a.getX() * b.getZ()) - (a.getZ() * b.getY());
   components[MV_VEC3_Y_COMPONENT] = (a.getZ() * b.getX()) - (a.getX() * b.getZ()),
   components[MV_VEC3_Z_COMPONENT] = (a.getX() * b.getY()) - (a.getY() * b.getX());
}

mvVec3 mvVec3::cross(const mvVec3& rhs) const
{
   /**/
   return mvVec3((getX() * rhs.getZ()) - (getZ() * rhs.getY()),
               (getZ() * rhs.getX()) - (getX() * rhs.getZ()),
               (getX() * rhs.getY()) - (getY() * rhs.getX()));
   /**/
}

const mvVec3& mvVec3::operator= (const mvVec3& rhs)
{
  components[MV_VEC3_X_COMPONENT] = rhs.components[MV_VEC3_X_COMPONENT];
  components[MV_VEC3_Y_COMPONENT] = rhs.components[MV_VEC3_Y_COMPONENT];
  components[MV_VEC3_Z_COMPONENT] = rhs.components[MV_VEC3_Z_COMPONENT];
  return *this;
}

const mvVec3& mvVec3::set (const mvFloat _x, const mvFloat _y, const mvFloat _z)
{
  components[MV_VEC3_X_COMPONENT] = _x;
  components[MV_VEC3_Y_COMPONENT] = _y;
  components[MV_VEC3_Z_COMPONENT] = _z;
  return *this;
}

const mvVec3& mvVec3::operator+= (const mvVec3& v)
{
  components[MV_VEC3_X_COMPONENT] += v.getX();
  components[MV_VEC3_Y_COMPONENT] += v.getY();
  components[MV_VEC3_Z_COMPONENT] += v.getZ();
  return *this;
}

const mvVec3& mvVec3::operator-= (const mvVec3& v)
{
  components[MV_VEC3_X_COMPONENT] -= v.getX();
  components[MV_VEC3_Y_COMPONENT] -= v.getY();
  components[MV_VEC3_Z_COMPONENT] -= v.getZ();
  return *this;
}

const mvVec3& mvVec3::operator*= (const mvFloat& s)
{
  components[MV_VEC3_X_COMPONENT] *= s;
  components[MV_VEC3_Y_COMPONENT] *= s;
  components[MV_VEC3_Z_COMPONENT] *= s;
  return *this;
}

const mvVec3& mvVec3::operator+= (const mvFloat& s)
{
  components[MV_VEC3_X_COMPONENT] += s;
  components[MV_VEC3_Y_COMPONENT] += s;
  components[MV_VEC3_Z_COMPONENT] += s;
  return *this;
}

const mvVec3& mvVec3::operator-= (const mvFloat& s)
{
  components[MV_VEC3_X_COMPONENT] -= s;
  components[MV_VEC3_Y_COMPONENT] -= s;
  components[MV_VEC3_Z_COMPONENT] -= s;
  return *this;
}

const mvVec3& mvVec3::operator/= (const float& s)
{
  components[MV_VEC3_X_COMPONENT] /= s;
  components[MV_VEC3_Y_COMPONENT] /= s;
  components[MV_VEC3_Z_COMPONENT] /= s;
  return *this;
}

bool mvVec3::operator== (const mvVec3& v) const
{
   if (getX() == v.getX() && getY() == v.getY() && getZ() == v.getZ())
      return true;
   else
      return false;
}

bool mvVec3::operator!= (const mvVec3& v) const
{
   if (getX() == v.getX() && getY() == v.getY() && getZ() == v.getZ())
      return true;
   else
      return false;
}

void mvVec3::resetX (void)
{
  components[MV_VEC3_X_COMPONENT] = 0;
}

void mvVec3::resetY (void)
{
  components[MV_VEC3_Y_COMPONENT] = 0;
}

void mvVec3::resetZ (void)
{
  components[MV_VEC3_Z_COMPONENT] = 0;
}

void mvVec3::resetXYZ(void)
{
  components[MV_VEC3_X_COMPONENT] = 0;
  components[MV_VEC3_Y_COMPONENT] = 0;
  components[MV_VEC3_Z_COMPONENT] = 0;
}

void mvVec3::setToZeroVector(void)
{
   resetXYZ();
}

void mvVec3::setX (const mvFloat& x)
{
   components[MV_VEC3_X_COMPONENT] = x;
}

void mvVec3::setY (const mvFloat& y)
{
   components[MV_VEC3_Y_COMPONENT] = y;
}

void mvVec3::setZ (const mvFloat& z)
{
   components[MV_VEC3_Z_COMPONENT] = z;
}

void mvVec3::setXYZ (const mvFloat& x,const mvFloat& y,const mvFloat& z)
{
   components[MV_VEC3_X_COMPONENT] = x;
   components[MV_VEC3_Y_COMPONENT] = y;
   components[MV_VEC3_Z_COMPONENT] = z;
}

void mvVec3::setAsXUnitVector (void)
{
   components[MV_VEC3_X_COMPONENT] = 1;
   components[MV_VEC3_Y_COMPONENT] = 0;
   components[MV_VEC3_Z_COMPONENT] = 0;
}

void mvVec3::setAsYUnitVector (void)
{
   components[MV_VEC3_X_COMPONENT] = 0;
   components[MV_VEC3_Y_COMPONENT] = 1;
   components[MV_VEC3_Z_COMPONENT] = 0;
}

void mvVec3::setAsZUnitVector (void)
{
   components[MV_VEC3_X_COMPONENT] = 0;
   components[MV_VEC3_Y_COMPONENT] = 0;
   components[MV_VEC3_Z_COMPONENT] = 1;
}

void mvVec3::addVec3(const mvVec3& rhs)
{
  components[MV_VEC3_X_COMPONENT] += rhs.getX();
  components[MV_VEC3_Y_COMPONENT] += rhs.getY();
  components[MV_VEC3_Z_COMPONENT] += rhs.getZ();
}

void mvVec3::minusVec3(const mvVec3& rhs)
{
  components[MV_VEC3_X_COMPONENT] -= rhs.getX();
  components[MV_VEC3_Y_COMPONENT] -= rhs.getY();
  components[MV_VEC3_Z_COMPONENT] -= rhs.getZ();
}

void mvVec3::timesVec3(const mvVec3& rhs)
{
  components[MV_VEC3_X_COMPONENT] *= rhs.getX();
  components[MV_VEC3_Y_COMPONENT] *= rhs.getY();
  components[MV_VEC3_Z_COMPONENT] *= rhs.getZ();
}

void mvVec3::divideVec3(const mvVec3& rhs)
{
  components[MV_VEC3_X_COMPONENT] /= rhs.getX();
  components[MV_VEC3_Y_COMPONENT] /= rhs.getY();
  components[MV_VEC3_Z_COMPONENT] /= rhs.getZ();
}

mvFloat mvVec3::getX() const
{
  return components[MV_VEC3_X_COMPONENT];
}

mvFloat mvVec3::getY() const
{
  return components[MV_VEC3_Y_COMPONENT];
}

mvFloat mvVec3::getZ() const
{
  return components[MV_VEC3_Z_COMPONENT];
}


const mvFloat* mvVec3::getXYZ() const
{
   return &components[0];
}

//void mvVec3::matrixMultiply(const mvFloat* matrix, int noOfValues, int order);

mvVec3 operator* (mvFloat s, const mvVec3& v)
{
   return v*s;
}

std::ostream& operator<< (std::ostream& o, const mvVec3& v)
{
   return o << "(" << v.getX() << "," << v.getY() << "," << v.getZ() << ")";
}

/** @brief set current vector to parameter
  *
  */
void mvVec3::setAll(const mvVec3& rhs)
{
   setX(rhs.getX());
   setY(rhs.getY());
   setZ(rhs.getZ());
}

