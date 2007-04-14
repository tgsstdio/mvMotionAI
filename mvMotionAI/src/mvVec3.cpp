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
// TODO (White 2#1#): Doxygen documentation
/**
 * \brief constructor
 *
 * default value of vector is (0,0,0)
 */
mvVec3::mvVec3(void)
{
  components[MV_VEC3_X_COMPONENT] = 0;
  components[MV_VEC3_Y_COMPONENT] = 0;
  components[MV_VEC3_Z_COMPONENT] = 0;
}

/**
 * \brief constructor
 * \param[in] X x value of vector
 * \param[in] Y y value of vector
 * \param[in] Z z value of vector
 *
 * value of vector will be (X,Y,Z)
 */
mvVec3::mvVec3(const mvFloat& X, const mvFloat& Y, const mvFloat& Z)
{
  components[MV_VEC3_X_COMPONENT] = X;
  components[MV_VEC3_Y_COMPONENT] = Y;
  components[MV_VEC3_Z_COMPONENT] = Z;
}

/**
 * \brief constructor
 * \param[in] array pointer to a mvFloat array of length 3 (or MV_VEC3_NO_OF_COMPONENTS)
 *
 * value of mvVec3 should be (array[0],array[1],array[2])
 */
mvVec3::mvVec3(const mvFloat* array)
{
  components[MV_VEC3_X_COMPONENT] = array[MV_VEC3_X_COMPONENT];
  components[MV_VEC3_Y_COMPONENT] = array[MV_VEC3_Y_COMPONENT];
  components[MV_VEC3_Z_COMPONENT] = array[MV_VEC3_Z_COMPONENT];
}

/**
 * \brief constructor
 * \param[in] rhs another mvVec3
 *
 * value of mvVec3 should be equal to rhs
 */
mvVec3::mvVec3(const mvVec3& rhs)
{
  components[MV_VEC3_X_COMPONENT] = rhs.components[MV_VEC3_X_COMPONENT];
  components[MV_VEC3_Y_COMPONENT] = rhs.components[MV_VEC3_Y_COMPONENT];
  components[MV_VEC3_Z_COMPONENT] = rhs.components[MV_VEC3_Z_COMPONENT];
}

/**
 * \brief vector addition through + operator
 * \param[in] v Vector on right hand side of + operator
 * \return new instance of mvVec3
 *
 * Returns new instance of mvVec3 that is the result of two mvVec3 vectors
 * (C++ reference or instance) alongside the + operator added together
 * and does not change either vectors. Can be nested with more operations.
 */
mvVec3 mvVec3::operator+ (const mvVec3& v) const
{
   return mvVec3(getX() + v.getX(), getY() + v.getY(), getZ() + v.getZ());
}

/**
 * \brief vector subtraction through - operator
 * \param[in] v Vector on right hand side of - operator
 * \return new instance of mvVec3
 *
 * Returns new instance of mvVec3 that is the result of left hand mvVec3 vector
 * (C++ reference or instance) subtract right side vector (v) of the - operator
 * and does not change either vectors. Can be nested with more operations.
 */
mvVec3 mvVec3::operator- (const mvVec3& v) const
{
   return mvVec3(getX() - v.getX(), getY() - v.getY(), getZ() - v.getZ());
}

/**
 * \brief unary minus or negates vector (-v)
 * \return new instance of mvVec3
 *
 * Returns the current vector's v(a,b,c) negation, which is
 * (-a,-b,-c), as a new mvVec instance. Original vector v is unchanged.
 */
mvVec3 mvVec3::operator- (void) const
{
   return mvVec3(-getX(), -getY(), -getZ());
}

/**
 * \brief vector times scalar product (scale length of vector times argument)
 * \param[in] s Scalar value as a mvFloat value.
 * \return new instance of mvVec3
 *
 * Returns the vector (x * s,y * s,z * s) as a new instance of mvVec3.
 * Original vector v is unchanged and can be nested with more operations.
 */
mvVec3 mvVec3::operator* (const mvFloat s) const
{
   return mvVec3(s * getX(), s * getY(), s * getZ());
}
/**
 * \brief vector divided by a scalar (divide length of vector by argument)
 * \param[in] s Scalar value as a mvFloat value.
 * \return new instance of mvVec3
 *
 * Returns the vector (x/s,y/s,z/s) as a new instance of mvVec3.
 * Original vector v is unchanged and can be nested with more operations.
 * Does not handle division by zero errors.
 */
mvVec3 mvVec3::operator/ (const mvFloat s) const
{
   return mvVec3(getX()/s, getY()/s, getZ()/s);
}

/**
 * \brief cosine measure - angle between two vectors
 * \param[in] v Vector to multiplied with current vector
 * \return result as a mvFloat.
 *
 * Returns the result of arccos (cos-1) value of
 * of the dot product of the two normalized vectors a & v
 * as a mvFloat.
 * Formula:
 * if a = this vector, b = vector v
 * c.m = arccos[ (a  . b )/ (|a||b|) ]
 * Original vectors v & a is unchanged by dot function.
 */
mvFloat mvVec3::cosineMeasure(const mvVec3& v) const
{
    mvFloat normalDProduct = normalizedDotProduct(v);
    return mvArcCos(normalDProduct);
}

/**
 * \brief normalized dot product -
 * \param[in] v Vector to multiplied with current vector
 * \return result as a mvFloat.
 *
 * Returns the result of dot product of the two normalized vectors a & v
 * as a mvFloat.
 *
 * Formula:
 * if a = this vector, b = vector v
 * n.d.p = (a . b )\ (|a||b|)
 * Original vectors v & a is unchanged by dot function.
 */
mvFloat mvVec3::normalizedDotProduct(const mvVec3& v) const
{
    mvFloat magnitudeProduct = length();
    mvFloat dProduct = dot(v);

    // length a (this) * length b (v)
    magnitudeProduct *= v.length();

    // a . b / |a||b|
    dProduct /= magnitudeProduct;

    return dProduct;
}

/**
 * \brief dot product
 * \param[in] v Vector to multiplied with current vector
 * \return result as a mvFloat.
 *
 * NOTE : vectors are not normalised in function
 *
 * Returns the total of the dot product of the two vectors a & v as a mvFloat.
 * Dot product is calculated by result = a.x * v.x + a.y * v.y + a.z * v.z
 * Original vectors v & a is unchanged by dot function.
 */
mvFloat mvVec3::dot (const mvVec3& v) const
{
   mvFloat temp = dotXY(v);
   temp += dotZ(v);
   return temp;
}

/**
 * \brief dot product of x components
 * \param[in] v Vector to multiplied with current vector
 * \return result as a mvFloat.
 *
 * NOTE : vectors are not normalised in function
 *
 * Returns the dot product of the two vectors a & v as a mvFloat.
 * Dot product is calculated by result = a.x * v.x
 * Original vectors v & a is unchanged by dotx function.
 */
mvFloat mvVec3::dotX (const mvVec3& v) const
{
   mvFloat temp = getX();
   temp *= v.getX();
   return temp;
}

/**
 * \brief dot product of y components
 * \param[in] v Vector to multiplied with current vector
 * \return result as a mvFloat.
 *
 * NOTE : vectors are not normalised in function
 *
 * Returns the dot product of the two vectors a & v as a mvFloat.
 * Dot product is calculated by result = a.y * v.y
 * Original vectors v & a is unchanged by doty function.
 */
mvFloat mvVec3::dotY (const mvVec3& v) const
{
   mvFloat temp = getY();
   temp *= v.getY();
   return temp;
}

/**
 * \brief dot product of z components
 * \param[in] v Vector to multiplied with current vector
 * \return result as a mvFloat.
 *
 * NOTE : vectors are not normalised in function
 *
 * Returns the dot product of the two vectors a & v as a mvFloat.
 * Dot product is calculated by result = a.z * v.z
 * Original vectors v & a is unchanged by dotz function.
 */
mvFloat mvVec3::dotZ (const mvVec3& v) const
{
   mvFloat temp = getZ();
   temp *= v.getZ();
   return temp;
}

/**
 * \brief dot product of xy components
 * \param[in] v Vector to multiplied with current vector
 * \return result as a mvFloat.
 *
 * NOTE : vectors are not normalised in function
 *
 * Returns the dot product of the two vectors a & v as a mvFloat.
 * Dot product is calculated by result = a.xy * v.xy
 * Original vectors v & a is unchanged by dotxy function.
 */
mvFloat mvVec3::dotXY (const mvVec3& v) const
{
   mvFloat temp = dotX(v);
   temp += dotY(v);
   return temp;
}

/**
 * \brief dot product of xz components
 * \param[in] v Vector to multiplied with current vector
 * \return result as a mvFloat.
 *
 * NOTE : vectors are not normalised in function
 *
 * Returns the dot product of the two vectors a & v as a mvFloat.
 * Dot product is calculated by result = a.xz * v.xz
 * Original vectors v & a is unchanged by dotxz function.
 */
mvFloat mvVec3::dotXZ (const mvVec3& v) const
{
   mvFloat temp = dotX(v);
   temp += dotZ(v);
   return temp;
}

/**
 * \brief dot product of yz components
 * \param[in] v Vector to multiplied with current vector
 * \return result as a mvFloat.
 *
 * NOTE : vectors are not normalised in function
 *
 * Returns the dot product of the two vectors a & v as a mvFloat.
 * Dot product is calculated by result = a.yz * v.yz
 * Original vectors v & a is unchanged by dotyz function.
 */
mvFloat mvVec3::dotYZ (const mvVec3& v) const
{
   mvFloat temp = dotX(v);
   temp += dotZ(v);
   return temp;
}

/**
* \brief length of vector
* \return mvFloat of vector length
*
* Formula : l = sqrt(x2 + y2 + z2)
*/
mvFloat mvVec3::length (void) const
{
   return mvSqrt(lengthSquared());
}

/**
 * \brief length squared
* \return mvFloat of vector length squared
*
* Formula : l . sq = (x2 + y2 + z2)
 */
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

/**
 * \brief normalize: returns normalized version
 * \return mVec3 parallel to original, with unit length of 1
 *
 * NOTE : skip divisiom (i.e normalization) if length is zero
*/
mvVec3 mvVec3::normalize (void) const
{
      /*
      old code of Vec3
      {
        // skip divide if length is zero
           const mvFloat len = length ();
           return (len>0) ? (*this)/len : (*this);
      }
      */

   // skip divide if length is zero
   const mvFloat len = length ();
   return (len>0) ? (*this)/len : (*this);
}

/**
 * \brief in place cross product
 * \param[in] a Vector on Left hand side of equation
 * \param[in] b Vector on Right hand side of equation
 *
 * Result is saved in 'this' vector that is crose product of a & b
 * (i.e modifies "*this" to be A x B)
 * Vectors a & b is unchanged by function.
 * Result is not normalised
 */
void mvVec3::AcrossB(const mvVec3& a,const mvVec3& b)
{
/*
 * [XXX  side effecting -- deprecate this function?  XXX]
       *this = mvVec3 ((a.y * b.z) - (a.z * b.y),
                (a.z * b.x) - (a.x * b.z),
              (a.x * b.y) - (a.y * b.x));
*/
   components[MV_VEC3_X_COMPONENT] = (a.getX() * b.getZ()) - (a.getZ() * b.getY());
   components[MV_VEC3_Y_COMPONENT] = (a.getZ() * b.getX()) - (a.getX() * b.getZ()),
   components[MV_VEC3_Z_COMPONENT] = (a.getX() * b.getY()) - (a.getY() * b.getX());
}

/**
 * \brief cross product
 * \param[in] rhs Right hand side of equation
 * \return mvVec3 of cross product
 *
 * Returns new instance of mvVec3 which contains the result of cross product.
 * Vectors 'this' & 'rhs' is unchanged by function.
 * Result is not normalised
 */
mvVec3 mvVec3::cross(const mvVec3& rhs) const
{
       /*
       {
         **
          *this = mvVec3 ((a.y * b.z) - (a.z * b.y),
                   (a.z * b.x) - (a.x * b.z),
                 (a.x * b.y) - (a.y * b.x));
          **
       };
       */
   return mvVec3((getX() * rhs.getZ()) - (getZ() * rhs.getY()),
               (getZ() * rhs.getX()) - (getX() * rhs.getZ()),
               (getX() * rhs.getY()) - (getY() * rhs.getX()));
}

/**
 * \brief assignment
 * \param[in] rhs Vector of right side of assignment (=)
 * \return C++ mvVec3 reference of vector
 *
 * Set the left hand side (this) to equal the right hand side vector
 * rhs. Vector rhs is unaffected by fucntion
 */
const mvVec3& mvVec3::operator= (const mvVec3& rhs)
{
  components[MV_VEC3_X_COMPONENT] = rhs.components[MV_VEC3_X_COMPONENT];
  components[MV_VEC3_Y_COMPONENT] = rhs.components[MV_VEC3_Y_COMPONENT];
  components[MV_VEC3_Z_COMPONENT] = rhs.components[MV_VEC3_Z_COMPONENT];
  return *this;
}

/**
 * \brief set XYZ coordinates to given three mvFloats
 * \param[in] _x X component parameter
 * \param[in] _y Y component parameter
 * \param[in] _z Z component parameter
 * \return C++ mvVec3 reference of vector
 *
 * Returns the modified vector with the values of (_x,_y,_z)
 */
const mvVec3& mvVec3::set (const mvFloat _x, const mvFloat _y, const mvFloat _z)
{
  components[MV_VEC3_X_COMPONENT] = _x;
  components[MV_VEC3_Y_COMPONENT] = _y;
  components[MV_VEC3_Z_COMPONENT] = _z;
  return *this;
}

/**
 * \brief += (add togwther and assignment)
 * \param[in] v Vector to be added
 * \return C++ mvVec3 reference of modified vector
 *
 * Returns the modified vector with the values of (x + v.x,y + v.y, z+ v.z)
 */
const mvVec3& mvVec3::operator+= (const mvVec3& v)
{
  components[MV_VEC3_X_COMPONENT] += v.getX();
  components[MV_VEC3_Y_COMPONENT] += v.getY();
  components[MV_VEC3_Z_COMPONENT] += v.getZ();
  return *this;
}

/**
 * \brief -= (calculate differemce them assigmed)
 * \param[in] v Subtracting Vector
 * \return C++ mvVec3 reference of modified vector
 *
 * Returns the modified vector with the values of (x - v.x,y - v.y, z - v.z)
 */
const mvVec3& mvVec3::operator-= (const mvVec3& v)
{
  components[MV_VEC3_X_COMPONENT] -= v.getX();
  components[MV_VEC3_Y_COMPONENT] -= v.getY();
  components[MV_VEC3_Z_COMPONENT] -= v.getZ();
  return *this;
}

/**
* \brief  *= (scaled by constant then assigned)
 * \param[in] s Constant mvFloat value
 * \return C++ mvVec3 reference of modified vector
 *
 * Returns the modified vector with the values of (x * s,y * s, z * s)
 */
const mvVec3& mvVec3::operator*= (const mvFloat& s)
{
  components[MV_VEC3_X_COMPONENT] *= s;
  components[MV_VEC3_Y_COMPONENT] *= s;
  components[MV_VEC3_Z_COMPONENT] *= s;
  return *this;
}


/**
 * \brief  += adds constant mvFloat to all members
 * \param[in] s Constant mvFloat value
 * \return C++ mvVec3 reference of modified vector
 *
 * Returns the modified vector with the values of (x  + s,y + s, z + s)
 */
const mvVec3& mvVec3::operator+= (const mvFloat& s)
{
  components[MV_VEC3_X_COMPONENT] += s;
  components[MV_VEC3_Y_COMPONENT] += s;
  components[MV_VEC3_Z_COMPONENT] += s;
  return *this;
}

/**
 * \brief  -= subtracts constant mvFloat to all members
 * \param[in] s Constant mvFloat value
 * \return C++ mvVec3 reference of modified vector
 *
 * Returns the modified vector with the values of (x  - s,y - s, z - s)
 */
const mvVec3& mvVec3::operator-= (const mvFloat& s)
{
  components[MV_VEC3_X_COMPONENT] -= s;
  components[MV_VEC3_Y_COMPONENT] -= s;
  components[MV_VEC3_Z_COMPONENT] -= s;
  return *this;
}

/**
 * \brief  /= divides constant float to all members
 * \param[in] s Constant mvFloat value
 * \return C++ mvVec3 reference of modified vector
 *
 * Returns the modified vector with the values of (x  / s,y / s, z / s)
 * NOTE: division by zero not handled
 */
const mvVec3& mvVec3::operator/= (const float& s)
{
  components[MV_VEC3_X_COMPONENT] /= s;
  components[MV_VEC3_Y_COMPONENT] /= s;
  components[MV_VEC3_Z_COMPONENT] /= s;
  return *this;
}

/**
 * \brief vector equality
 * \param[in] v Vector to be compared
 * \return boolean i.e true or false
 */
bool mvVec3::operator== (const mvVec3& v) const
{
   if (getX() == v.getX() && getY() == v.getY() && getZ() == v.getZ())
      return true;
   else
      return false;
}

/**
 * \brief vector inequality
 * \param[in] v Vector to be compared
 * \return boolean i.e true or false
 */
bool mvVec3::operator!= (const mvVec3& v) const
{
   return !(*this ==(v));
}

/**
 * \brief reset x component
 *
 * sets x component of vector to zero
 */
void mvVec3::resetX (void)
{
  components[MV_VEC3_X_COMPONENT] = 0;
}

/**
 * \brief reset y component
 *
 * sets y component of vector to zero
 */
void mvVec3::resetY (void)
{
  components[MV_VEC3_Y_COMPONENT] = 0;
}

/**
 * \brief reset z component
 *
 * sets z component of vector to zero
 */
void mvVec3::resetZ (void)
{
  components[MV_VEC3_Z_COMPONENT] = 0;
}
/**
 * \brief reset vector
 *
 * set all members to zero
 */
void mvVec3::resetXYZ(void)
{
  components[MV_VEC3_X_COMPONENT] = 0;
  components[MV_VEC3_Y_COMPONENT] = 0;
  components[MV_VEC3_Z_COMPONENT] = 0;
}

/**
 * \brief reset vector
 *
 * set all members to zero i.e same as resetXYZ
 */
void mvVec3::setToZeroVector(void)
{
   resetXYZ();
}

/**
 * \brief set x component of vector
 * \param[in] x X component value
 */
void mvVec3::setX (const mvFloat& x)
{
   components[MV_VEC3_X_COMPONENT] = x;
}

/**
 * \brief set y component of vector
 * \param[in] y Y component value
 */
void mvVec3::setY (const mvFloat& y)
{
   components[MV_VEC3_Y_COMPONENT] = y;
}

/**
 * \brief set z component of vector
 * \param[in] z Z component value
 */
void mvVec3::setZ (const mvFloat& z)
{
   components[MV_VEC3_Z_COMPONENT] = z;
}

/**
 * \brief set XYZ coordinates to given three floats
 * \param[in] x X component value
 * \param[in] y Y component value
 * \param[in] z Z component value
 *
 * NOTE: similar to set but does not return C++ reference
 */
void mvVec3::setXYZ (const mvFloat& x,const mvFloat& y,const mvFloat& z)
{
   components[MV_VEC3_X_COMPONENT] = x;
   components[MV_VEC3_Y_COMPONENT] = y;
   components[MV_VEC3_Z_COMPONENT] = z;
}

/**
 * \brief set vector to be x unit vector or i
 */
void mvVec3::setAsXUnitVector (void)
{
   components[MV_VEC3_X_COMPONENT] = 1;
   components[MV_VEC3_Y_COMPONENT] = 0;
   components[MV_VEC3_Z_COMPONENT] = 0;
}

/**
 * \brief set vector to be y unit vector or j
 */
void mvVec3::setAsYUnitVector (void)
{
   components[MV_VEC3_X_COMPONENT] = 0;
   components[MV_VEC3_Y_COMPONENT] = 1;
   components[MV_VEC3_Z_COMPONENT] = 0;
}

/**
 * \brief set vector to be z unit vector or k
 */
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

/**
* \brief returns X
*/
mvFloat mvVec3::getX() const
{
  return components[MV_VEC3_X_COMPONENT];
}

/**
* \brief returns Y
*/
mvFloat mvVec3::getY() const
{
  return components[MV_VEC3_Y_COMPONENT];
}

/**
* \brief returns Z
*/
mvFloat mvVec3::getZ() const
{
  return components[MV_VEC3_Z_COMPONENT];
}

/**
* \brief returns XYZ array pointer
* \return const mvFloat array pointer of length 3
*/
const mvFloat* mvVec3::getXYZ() const
{
   return &components[0];
}

//void mvVec3::matrixMultiply(const mvFloat* matrix, int noOfValues, int order);

mvVec3 operator* (mvFloat s, const mvVec3& v)
{
   return v*s;
}

/*
no iostream in library - code bloat
std::ostream& operator<< (std::ostream& o, const mvVec3& v)
{
   return o << "(" << v.getX() << "," << v.getY() << "," << v.getZ() << ")";
}
*/

/** @brief set current vector to parameter
  *
  */
void mvVec3::setAll(const mvVec3& rhs)
{
   setX(rhs.getX());
   setY(rhs.getY());
   setZ(rhs.getZ());
}

