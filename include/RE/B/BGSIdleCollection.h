#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) BGSIdleCollection :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSIdleCollection };
		static constexpr auto VTABLE{ VTABLE::BGSIdleCollection };

		// members
		std::int8_t   idleFlags;          // 08
		std::int8_t   idleCount;          // 09
		TESIdleForm** idleArray;          // 10
		float         timerCheckForIdle;  // 18
	};
	static_assert(sizeof(BGSIdleCollection) == 0x20);
}
