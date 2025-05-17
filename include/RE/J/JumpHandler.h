#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class JumpHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::JumpHandler };
		static constexpr auto VTABLE{ VTABLE::JumpHandler };

		explicit constexpr JumpHandler(PlayerControlsData& a_data) noexcept :
			PlayerInputHandler(a_data)
		{}

		// members
		bool debounceAlternateExit{ false };  // 20
	};
	static_assert(sizeof(JumpHandler) == 0x28);
}
