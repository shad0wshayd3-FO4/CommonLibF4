#pragma once

namespace RE
{
	class __declspec(novtable) ArrowProjectile :
		public MissileProjectile  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::ArrowProjectile };
		static constexpr auto VTABLE{ VTABLE::ArrowProjectile };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPARW };

		// members
		AlchemyItem* poison;  // 2C0
	};
	static_assert(sizeof(ArrowProjectile) == 0x2D0);
}
