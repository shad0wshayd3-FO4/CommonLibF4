#pragma once

namespace RE
{
	class SneakHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::SneakHandler };
		static constexpr auto VTABLE{ VTABLE::SneakHandler };

		explicit constexpr SneakHandler(PlayerControlsData& a_data) noexcept :
			PlayerInputHandler(a_data)
		{
		}
	};
	static_assert(sizeof(SneakHandler) == 0x20);
}
