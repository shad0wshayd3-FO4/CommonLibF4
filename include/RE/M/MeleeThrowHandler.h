#pragma once

#include "RE/H/HeldStateHandler.h"

namespace RE
{
	class MeleeThrowHandler :
		public HeldStateHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::MeleeThrowHandler };
		static constexpr auto VTABLE{ VTABLE::MeleeThrowHandler };

		// members
		bool buttonHoldDebounce;  // 28
		bool pressRegistered;     // 29
		bool queueThrow;          // 2A
	};
	static_assert(sizeof(MeleeThrowHandler) == 0x30);
}
