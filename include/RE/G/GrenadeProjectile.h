#pragma once

#include "RE/P/Projectile.h"

namespace RE
{
	class __declspec(novtable) GrenadeProjectile :
		public Projectile  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::GrenadeProjectile };
		static constexpr auto VTABLE{ VTABLE::GrenadeProjectile };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPGRE };

		// members
		BGSDecalGroup* decalGroup;           // 270
		bool           collisionGroupReset;  // 278
	};
	static_assert(sizeof(GrenadeProjectile) == 0x280);
}
