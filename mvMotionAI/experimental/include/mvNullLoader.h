#ifndef MVNULLLOADER_H_INCLUDED
#define MVNULLLOADER_H_INCLUDED

#incluude "mvBaseBehaviour.h"

class mvNullLoader : public mvBaseBehaviourLoader
{
   public:
      mvNullLoader();
      virtual mvBaseBehaviour* operator()(mvBaseBehaviour* defaultBehaviour);
};

#endif // MVNULLLOADER_H_INCLUDED
