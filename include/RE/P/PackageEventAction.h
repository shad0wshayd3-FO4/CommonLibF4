#pragma once

namespace RE
{
	class PackageEventAction
	{
	public:
		// members
		TESIdleForm*                                       idle;               // 00
		REX::EnumSet<PACK_EVENT_ACTION_TYPE, std::int32_t> type;               // 08
		BGSTopicSubtypeUnion                               topicSubtypeUnion;  // 0C
	};
	static_assert(sizeof(PackageEventAction) == 0x18);
}
