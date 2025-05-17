#pragma once

#include "RE/B/BSInputEventUser.h"
#include "RE/P/PlayerControlsData.h"

namespace RE
{
	class PlayerInputHandler :
		public BSInputEventUser  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PlayerInputHandler };
		static constexpr auto VTABLE{ VTABLE::PlayerInputHandler };

		explicit constexpr PlayerInputHandler(PlayerControlsData& a_data) noexcept :
			data(a_data)
		{}

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~PlayerInputHandler() = default;  // 00

		// add
		virtual void PerFrameUpdate() { return; };  // 09

		// members
		PlayerControlsData& data;                       // 10
		bool                inQuickContainer{ false };  // 18
	};
	static_assert(sizeof(PlayerInputHandler) == 0x20);
}
