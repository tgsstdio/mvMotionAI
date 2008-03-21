#ifndef MVREADYMADELOADER_H_INCLUDED
#define MVREADYMADELOADER_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_BASE_ACTION_HEADER_FILE_H_

template <class mvBaseActionClass>
class MV_GLOBAL_FUNC_PREFIX mvReadyMadeActionLoader : public mvBaseActionLoader
{
	private:
		mvOptionEnum actionKey;
		mvBaseActionPtr exampleGroupAction;

	public:
		mvReadyMadeActionLoader(mvOptionEnum key = MV_OPTION_ENUM_KEY_IS_INVALID)
		{
			actionKey = key;

			mvNewBaseActionInfo groupData(actionKey,\
				mvNewBaseActionInfo::MV_NEW_GB_GROUP_MEMBER_OP,
				MV_NULL,	MV_NULL);

			exampleGroupAction = MV_NULL;
			exampleGroupAction = (*this)(groupData);
		}

		virtual mvBaseActionPtr operator()(mvNewBaseActionInfo& info)
		{
			if (info.isGroupMemberNodeLookup())
			{
				return exampleGroupAction;
			}
			else
			{
				return new mvBaseActionClass();
			}
		}

		virtual ~mvReadyMadeActionLoader()
		{
			if (exampleGroupAction)
			{
				delete exampleGroupAction;
			}
		}
};

template <class mvBaseActionClass>
class MV_GLOBAL_FUNC_PREFIX mvReadyMadeCustomEnumActionLoader : public mvBaseActionLoader
{
	private:
		mvBaseActionPtr exampleGroupAction;
		mvOptionEnum actionFlag;

	public:
		mvReadyMadeCustomEnumActionLoader(mvOptionEnum key)
		{
			actionFlag = key;
			mvNewBaseActionInfo groupData(actionFlag,\
				mvNewBaseActionInfo::MV_NEW_GB_GROUP_MEMBER_OP,
				MV_NULL,	MV_NULL);

			exampleGroupAction = MV_NULL;
			exampleGroupAction = (*this)(groupData);
		}

		virtual mvBaseActionPtr operator()(mvNewBaseActionInfo& info)
		{
			if (info.isGroupMemberNodeLookup())
			{
				return exampleGroupAction;
			}
			else
			{
				return new mvBaseActionClass(actionFlag);
			}
		}

		virtual ~mvReadyMadeCustomEnumActionLoader()
		{
			if (exampleGroupAction)
			{
				delete exampleGroupAction;
			}
		}
};


#endif // MVREADYMADELOADER_H_INCLUDED
