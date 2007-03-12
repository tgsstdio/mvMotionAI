#ifndef MVBASEWORLD_H_INCLUDED
#define MVBASEWORLD_H_INCLUDED

class mvBaseWorld
{

};

class mvBaseWorldLoader
{
   public:
      virtual mvBaseWorld* createWorld(mvOptionEnum type,\
         mvBaseWorld* worldPtr) = 0;
};

#endif // MVBASEWORLD_H_INCLUDED
