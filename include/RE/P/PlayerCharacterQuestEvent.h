#pragma once

namespace RE
{
	class BGSInstancedQuestObjective;

	namespace PlayerCharacterQuestEvent
	{
		enum Type : std::int32_t
		{
			kAddObjective = 0x0,
			kUpdateObjective = 0x1,
			kRemoveQuest = 0x2,
			kRemoveQuestTarget = 0x3,
			kUpdateQuestTarget = 0x4
		};

		class Event
		{
		public:
			// members
			PlayerCharacterQuestEvent::Type changeType;      // 00
			BGSInstancedQuestObjective*     questObjective;  // 08
		};
		static_assert(sizeof(Event) == 0x10);
	}
}
