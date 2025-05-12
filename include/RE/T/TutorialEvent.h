#pragma once

namespace RE
{
	class TutorialEvent
	{
	public:
		// members
		BSFixedString     eventName;  // 00
		const BGSMessage* assocMsg;   // 08
	};
	static_assert(sizeof(TutorialEvent) == 0x10);

}
