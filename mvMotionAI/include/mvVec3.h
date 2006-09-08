#ifndef MV_MVVEC3_H_
#define MV_MVVEC3_H_
#include "mvMotionAI-Types.h"
#include <iostream>

// replacement for OpenSteer's Vec3
static const mvIndex MV_VEC3_X_COMPONENT = 0;
static const mvIndex MV_VEC3_Y_COMPONENT = 1;
static const mvIndex MV_VEC3_Z_COMPONENT = 2;
static const mvCount MV_VEC3_NO_OF_COMPONENTS = 3;

class mvVec3
{
   private:
   mvFloat components[MV_VEC3_NO_OF_COMPONENTS];

   public:
   /**
    * \brief constructor
    */
   mvVec3(void);
   mvVec3(const mvFloat& X, const mvFloat& Y, const mvFloat& Z);
   mvVec3(const mvFloat* array);
   mvVec3(const mvVec3& rhs);

   /**
    * \brief vector addition
    */
   mvVec3 operator+ (const mvVec3& v) const;

   /**
    * \brief vector subtraction
    */
   mvVec3 operator- (const mvVec3& v) const;

   /**
    * \brief unary minus
    */
   mvVec3 operator- (void) const;

   /**
    * \brief vector times scalar product (scale length of vector times argument)
    */
   mvVec3 operator* (const mvFloat s) const;

   /**
    * \brief vector divided by a scalar (divide length of vector by argument)
    */
   mvVec3 operator/ (const mvFloat s) const;

   /**
    * \brief dot product
    */
   mvFloat dot (const mvVec3& v) const;
   mvFloat dotX (const mvVec3& v) const;
   mvFloat dotY (const mvVec3& v) const;
   mvFloat dotZ (const mvVec3& v) const;
   mvFloat dotXY (const mvVec3& v) const;
   mvFloat dotXZ (const mvVec3& v) const;
   mvFloat dotYZ (const mvVec3& v) const;

   /**
    * \brief length
    */
   mvFloat length (void) const;

   /**
    * \brief length squared
    */
   mvFloat lengthSquared (void) const;

   /**
    * \brief normalize: returns normalized version (parallel to this, length = 1)
    */
   mvVec3 normalize (void) const;
   /**
   {
     // skip divide if length is zero
        const mvFloat len = length ();
        return (len>0) ? (*this)/len : (*this);
   }
   **/


   /**
    * \brief cross product (modify "*this" to be A x B)
    *
    * [XXX  side effecting -- deprecate this function?  XXX]
    */
    void AcrossB(const mvVec3& a,const mvVec3& b);

   /**
    * \brief cross product
    *
    */
    mvVec3 cross(const mvVec3& rhs) const;
    /**
    {
      **
       *this = mvVec3 ((a.y * b.z) - (a.z * b.y),
                (a.z * b.x) - (a.x * b.z),
              (a.x * b.y) - (a.y * b.x));
       **
    };
    **/

    /**
      * \brief assignment
      */
    const mvVec3& operator= (const mvVec3& v);

    /**
      * \brief set XYZ coordinates to given three floats
      */
    const mvVec3&  set (const mvFloat _x, const mvFloat _y, const mvFloat _z);

    /**
      * \brief +=
      */
    const mvVec3& operator+= (const mvVec3& v);

    /**
      * \brief -=
      */
    const mvVec3& operator-= (const mvVec3& v);

    /**
      * \brief  *=
      */
    const mvVec3& operator*= (const mvFloat& s);

    /**
      * \brief  +=
      * adds constant float to all members
      */
    const mvVec3& operator+= (const mvFloat& s);

    /**
      * \brief  -=
      * subtracts constant float to all members
      */
    const mvVec3& operator-= (const mvFloat& s);

    /**
     * \brief  /=
     * divides constant float to all members
     */
    const mvVec3& operator/= (const mvFloat& s);

    /**
      * \brief equality
      */
    bool operator== (const mvVec3& v) const;
    /**
      * \brief inequality
      */
    bool operator!= (const mvVec3& v) const;

   void resetX (void);
   void resetY (void);
   void resetZ (void);
   void resetXYZ(void);

   void setX (const mvFloat& x);
   void setY (const mvFloat& y);
   void setZ (const mvFloat& z);
    /**
     * \brief set XYZ coordinates to given three floats
     */
   void setXYZ (const mvFloat& x,const mvFloat& y,const mvFloat& z);

   void setAsXUnitVector (void);
   void setAsYUnitVector (void);
   void setAsZUnitVector (void);
   void setToZeroVector(void);

   void addVec3(const mvVec3& rhs);
   void minusVec3(const mvVec3& rhs);
   void timesVec3(const mvVec3& rhs);
   void divideVec3(const mvVec3& rhs);

    /**
     * \brief returns X
     */
   mvFloat getX() const;
    /**
     * \brief returns Y
     */
   mvFloat getY() const;
       /**
     * \brief returns Z
     */
   mvFloat getZ() const;
    /**
     * \brief returns XYZ array pointer
     */
   const mvFloat* getXYZ() const;

    /*
     * --------------------------------------------------------------------------
     *  scalar times vector product ("float * Vec3")
     */

  // void matrixMultiply(const mvFloat* matrix, int noOfValues, int order);
  friend mvVec3 operator* (float s, const mvVec3& v);
  friend std::ostream& operator<< (std::ostream& o, const mvVec3& v);
};



#endif
