#ifndef MVREADYMADELOADER_H_INCLUDED
#define MVREADYMADELOADER_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

template <class mvBaseActionClass>
class mvReadyMadeActionLoader : public mvBaseActionLoader
{
	public:
		mvReadyMadeActionLoader()
		{

		}

		virtual mvBaseAction* operator()(mvNewBaseActionInfo& info);
		virtual ~mvReadyMadeActionLoader()
		{

		}
};

template <class mvBaseActionClass>
mvBaseAction* mvReadyMadeActionLoader<mvBaseActionClass>::operator()(mvNewBaseActionInfo& info)
{
	return new mvBaseActionClass();
}

#endif // MVREADYMADELOADER_H_INCLUDED
