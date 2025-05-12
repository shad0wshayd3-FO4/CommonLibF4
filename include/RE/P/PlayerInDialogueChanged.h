#pragma once

namespace RE
{
	namespace PlayerInDialogueChanged
	{
		struct Event
		{
			bool isPlayerInDialogue;  // 00
		};
		static_assert(sizeof(Event) == 0x1);
	}
}
