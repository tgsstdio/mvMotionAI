#ifndef MVWORLDINTERFACE_H_INCLUDED
#define MVWORLDINTERFACE_H_INCLUDED

#define WORLD_FUNC(a) std::cout << (a) << std::endl

#define DECLARE_WORLD_FUNC(a)\
	void printAlpha()(std::cout << #a << std::endl;)

/*
      mvBodyPtr getBodyPtr(mvIndex index);
      mvBodyPtr getCurrentBodyPtr();
      mvIndex setCurrentBody(mvIndex index);
      mvErrorEnum deleteBody(mvIndex index);
      void deleteAllBodies();
      void applyToAllBodies(void (someFunction)(mvBodyPtr, void*),\
         void* extraPtr);
      void applyToAllBodiesByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setBodyParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setBodyParametero(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setBodyParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setBodyParametero_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setBodyParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setBodyParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum getBodyParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getBodyParametero(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getBodyParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getBodyParametero_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getBodyParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getBodyParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;
*/

#endif // MVWORLDINTERFACE_H_INCLUDED
