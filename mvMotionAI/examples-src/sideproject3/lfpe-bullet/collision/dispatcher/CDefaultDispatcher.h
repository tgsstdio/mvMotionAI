#ifndef CDEFAULTDISPATCHER_H_INCLUDED
#define CDEFAULTDISPATCHER_H_INCLUDED

#include <lfpe-bullet/collision/dispatcher/CCollisionDispatcher.h>
#include <lfpe-bullet/collision/config/CCollisionConfiguration.h>

namespace lf
{
namespace pe
{
namespace collision
{
	class CDefaultDispatcher : public CCollisionDispatcher
	{
		public:
			CDefaultDispatcher(CCollisionConfiguration* config);
	};

} // namespace collision
} // ns pe
} // namespace lf

#endif // CDEFAULTDISPATCHER_H_INCLUDED
