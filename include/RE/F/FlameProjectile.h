#pragma once

namespace RE
{
	class __declspec(novtable) FlameProjectile :
		public Projectile  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::FlameProjectile };
		static constexpr auto VTABLE{ VTABLE::FlameProjectile };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPFLA };

		// members
		float expirationTimer;  // 270
		float coneAngle;        // 274
	};
	static_assert(sizeof(FlameProjectile) == 0x280);
}
