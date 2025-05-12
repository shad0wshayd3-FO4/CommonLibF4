#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class HeldStateHandler :
		public PlayerInputHandler  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::HeldStateHandler };
		static constexpr auto VTABLE{ VTABLE::HeldStateHandler };

		explicit constexpr HeldStateHandler(PlayerControlsData& a_data) noexcept :
			PlayerInputHandler(a_data)
		{
		}

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~HeldStateHandler() = default;  // 00

		// add
		virtual void UpdateHeldStateActive(const ButtonEvent* a_event)  // 10
		{
			heldStateActive = a_event && (a_event->value != 0.0F || a_event->heldDownSecs < 0.0F);
		}

		virtual void SetHeldStateActive(bool a_flag) { heldStateActive = a_flag; }  // 11

		// members
		bool heldStateActive{ false };      // 20
		bool triggerReleaseEvent{ false };  // 21
	};
	static_assert(sizeof(HeldStateHandler) == 0x28);
}
