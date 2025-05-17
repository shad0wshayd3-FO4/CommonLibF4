#pragma once

#include "RE/P/Projectile.h"

namespace RE
{
	class __declspec(novtable) ConeProjectile :
		public Projectile  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::ConeProjectile };
		static constexpr auto VTABLE{ VTABLE::ConeProjectile };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPCON };

		// members
		float expirationTimer;  // 270
		float coneAngle;        // 274
	};
	static_assert(sizeof(ConeProjectile) == 0x280);
}
