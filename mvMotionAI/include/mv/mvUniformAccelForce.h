/**
 * \file mvUniformAccelForce.h
 * Copyright (c) 2006, 2007 David Young.
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
 */
#ifndef MVUNIFORMACCELFORCE_H_INCLUDED
#define MVUNIFORMACCELFORCE_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_BASE_FORCE_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_

/**
 * \class mvUniformAccelForce
 * \brief derived mvBaseForce - applies uniform acceleration to bodies
 */
class mvUniformAccelForce: public mvBaseForce
{
   private:
      mvVec3 uAccel;
   public:
      mvUniformAccelForce();
      virtual void filter(mvForceStatus& worldStatus);
      virtual bool calcFullForces(mvForceResultPtr fResult);
      virtual ~mvUniformAccelForce();
};

/**
 * \class mvUniformAccelForceLoader
 * \brief derived mvBaseForceLoader - creates mvUniformAccelForce
 */
class mvUniformAccelForceLoader : public mvBaseForceLoader
{
   public:
      mvUniformAccelForceLoader();
      virtual mvBaseForcePtr operator()(\
         void* extraPtr);
      virtual ~mvUniformAccelForceLoader()
      {

      }
};

#endif // MVUNIFORMACCELFORCE_H_INCLUDED
