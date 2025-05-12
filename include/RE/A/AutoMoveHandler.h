#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class AutoMoveHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::AutoMoveHandler };
		static constexpr auto VTABLE{ VTABLE::AutoMoveHandler };

		explicit constexpr AutoMoveHandler(PlayerControlsData& a_data) noexcept :
			PlayerInputHandler(a_data)
		{
		}
	};
	static_assert(sizeof(AutoMoveHandler) == 0x20);
}
