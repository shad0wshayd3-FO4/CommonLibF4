#pragma once

namespace RE
{
	class __declspec(novtable) ExtraHealth :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraHealth };
		static constexpr auto VTABLE{ VTABLE::ExtraHealth };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kHealth };

		ExtraHealth(float a_health) :
			BSExtraData(TYPE),
			health(a_health)
		{
			stl::emplace_vtable(this);
		}

		// members
		float health;  // 18
	};
	static_assert(sizeof(ExtraHealth) == 0x20);
}
