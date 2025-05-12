#pragma once

namespace RE
{
	namespace TESQuestEvent
	{
		enum Type : std::int32_t
		{
			kUpdateQuestActiveStatus = 0x0,
			kUpdateQuestEnableStatus = 0x1,
			kUpdateQuestStageChange = 0x2,
			kUpdateMiscQuestVisibility = 0x3
		};

		struct Event
		{
			TESQuestEvent::Type changeType;  // 00
			TESQuest*           quest;       // 08
		};
		static_assert(sizeof(Event) == 0x10);
	}
}
