#pragma once

namespace RE
{
	class BGSInstancedQuestObjective
	{
	public:
		// members
		BGSQuestObjective* objective;      // 00
		std::uint32_t                                     instanceID;     // 08
		REX::EnumSet<QUEST_OBJECTIVE_STATE, std::int32_t> enstanceState;  // 0C
	};
	static_assert(sizeof(BGSInstancedQuestObjective) == 0x10);
}
