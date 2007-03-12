#ifndef MVBASEBODY_H_INCLUDED
#define MVBASEBODY_H_INCLUDED

class mvBaseBody
{

};

class mvBaseBodyLoader
{
   virtual mvBaseBody* createBody(mvOptionEnum type,\
      mvBaseBody* defaultBody);
};

#endif // MVBASEBODY_H_INCLUDED
