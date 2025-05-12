#pragma once

namespace RE
{
	class LookHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::LookHandler };
		static constexpr auto VTABLE{ VTABLE::LookHandler };

		explicit constexpr LookHandler(PlayerControlsData& a_data) noexcept :
			PlayerInputHandler(a_data)
		{
		}

		// members
		float thumbstickMaxedSec{ 0.0f };  // 20
	};
	static_assert(sizeof(LookHandler) == 0x28);
}
