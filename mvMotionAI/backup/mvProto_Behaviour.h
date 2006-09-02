
typedef int mvEnum;
typedef char mvChar;
/// then list them all.

enum mvError
{
};
enum mvEnum
{
};
enum mvParams
{
};

const char* mvGetErrorString(mvError errorValue);
const char* mvGetEnumString(mvError errorValue);
const char* mvGetParamsString(mvError errorValue);

class mvProto_BaseBehaviour
{
   public:
      mvProto_BaseBehaviour();
      virtual const char* getAllPossibleParameters(mvCount* noOfElements) const;
      virtual mvEnum getParameterType(const char* params)
      virtual mvEnum getParametersForAllTypes(const char* paramFlag, mvFloat* variablesArray,
         mvEnum* statesArray, mvCount* noOfElements, mvEnum* returnTypes);
      virtual mvEnum setParametersForAllTypes(const char* paramFlag, mvFloat* variablesArray,
         mvEnum* statesArray, mvCount* noOfElements, mvEnum* paramsTypes);
         
      virtual mvEnum getParameters(const char* paramFlag, mvEnum* option) = 0;
      virtual mvEnum getParametersi(const char* paramFlag, mvIndex* option) = 0;
      virtual mvEnum getParametersf(const char* paramFlag, mvFloat* num) = 0;
      virtual mvEnum getParametersv(const char* paramFlag, mvFloat* numArray, int noOfElements) = 0;

      virtual mvEnum getParameter(mvEnum paramFlag, mvEnum* option) = 0;
      virtual mvEnum getParameteri(mvEnum paramFlag, mvEnum option) = 0;
      virtual mvEnum getParameterf(mvEnum paramFlag, mvFloat* num) = 0;
      virtual mvEnum getParameterv(mvEnum paramFlag, mvFloat* numArray, mvCount* noOfElements) = 0;

      virtual mvEnum setParameters(const char* paramFlag, mvEnum* option) = 0;
      virtual mvEnum setParameters(const char* paramFlag, mvIndex* option) = 0;
      virtual mvEnum setParametersf(const char* paramFlag, mvFloat num) = 0;
      virtual mvEnum setParametersv(const char* paramFlag, mvFloat* numArray) = 0;

      virtual mvEnum setParameteri(mvEnum paramFlag, mvEnum option) = 0;
      virtual mvEnum setParameter(mvEnum paramFlag, mvEnum option) = 0;
      virtual mvEnum setParameterf(mvEnum paramFlag, mvFloat num) = 0;
      virtual mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray) = 0;

      virtual mvProto_BaseBehaviour* createGroupEntry(mvProto_BaseBehaviour* options) = 0;
	   virtual mvProto_BaseBehaviour* createBodyEntry(mvProto_BaseBehaviour* options) = 0;
	   virtual void groupOperation(mvWorld* world, mvGroup* groupPtr) = 0;
	   virtual mvVec3 bodyOperation(mvWorld* world,  mvBody* b,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity) = 0;
};
// replacement for OpenSteer's Vec3 
class mvVec3
{
        /**
         * \brief constructor
         */
        mvVec3 (void);
        mvVec3 (float X, float Y, float Z);
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
        mvVec3 operator* (const float s) const;

        /**
          * \brief vector divided by a scalar (divide length of vector by argument)
          */
        mvVec3 operator/ (const float s) const;

        /**
          * \brief dot product
          */
        float dot (const mvVec3& v) const;

        /**
          * \brief length
          */
        float length (void) const;

        /**
          * \brief length squared
          */
        float lengthSquared (void) const;

        /**
          * \brief normalize: returns normalized version (parallel to this, length = 1)
          */
        mvVec3 normalize (void) const
        {
            // skip divide if length is zero
            const float len = length ();
            return (len>0) ? (*this)/len : (*this);
        }


        /**
          * \brief cross product (modify "*this" to be A x B)
          *
          * [XXX  side effecting -- deprecate this function?  XXX]
          */
        void cross(const mvVec3& a, const mvVec3& b)
        {
            *this = Vec3 ((a.y * b.z) - (a.z * b.y),
                          (a.z * b.x) - (a.x * b.z),
                          (a.x * b.y) - (a.y * b.x));
        }

        /**
          * \brief assignment
          */
        mvVec3 operator= (const Vec3& v);

        /**
          * \brief set XYZ coordinates to given three floats
          */
        mvVec3 set (const float _x, const float _y, const float _z);

        /**
          * \brief +=
          */
        mvVec3 operator+= (const mvVec3& v);

        /**
          * \brief -=
          */
        mvVec3 operator-= (const mvVec3& v);

        /**
          * \brief  *=
          */
        mvVec3 operator*= (const float& s);

        /**
          * \brief  += 
          * adds constant float to all members
          */
        mvVec3 operator+= (const float& s);

        /**
          * \brief  -= 
          * subtracts constant float to all members
          */
        mvVec3 operator-= (const float& s);

        /**
          * \brief  /= 
          * divides constant float to all members
          */
        mvVec3 operator/= (const float& s);

        /**
          * \brief equality/inequality
          */
        bool operator== (const mvVec3& v) const;
        bool operator!= (const mvVec3& v) const;

        void resetX (void);
        void resetY (void);
        void resetZ (void);
        void resetXYZ(void);
        void setToZero(void);

        void setX (const float& x);
        void setY (const float& y);
        void setZ (const float& z);

        void setAsXUnitVector (void);
        void setAsYUnitVector (void);
        void setAsZUnitVector (void);

        /**
          * \brief set XYZ coordinates to given three floats
          */
        void setXYZ (const float& _x, const float& _y, const float& _z);

        void matrixMultiply(float* matrix, int noOfValues, int order);

};
