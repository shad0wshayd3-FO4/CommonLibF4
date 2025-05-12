#pragma once

namespace RE
{
	class ReadyWeaponHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::ReadyWeaponHandler };
		static constexpr auto VTABLE{ VTABLE::ReadyWeaponHandler };

		explicit constexpr ReadyWeaponHandler(PlayerControlsData& a_data) noexcept :
			PlayerInputHandler(a_data)
		{
		}

		// members
		bool actionTaken{ false };  // 20
	};
	static_assert(sizeof(ReadyWeaponHandler) == 0x28);
}
