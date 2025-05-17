#pragma once

namespace RE
{
	namespace PlayerInDialogueChanged
	{
		class Event
		{
		public:
			// members
			bool isPlayerInDialogue;  // 00
		};
		static_assert(sizeof(Event) == 0x1);
	}
}
