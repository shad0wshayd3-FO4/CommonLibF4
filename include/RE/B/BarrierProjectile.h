#pragma once

#include "RE/B/BSTArray.h"
#include "RE/P/Projectile.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class __declspec(novtable) BarrierProjectile :
		public Projectile  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BarrierProjectile };
		static constexpr auto VTABLE{ VTABLE::BarrierProjectile };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPBAR };

		class CollisionData
		{
		public:
			// members
			ObjectRefHandle ref;    // 0
			std::uint32_t   count;  // 4
		};
		static_assert(sizeof(CollisionData) == 0x8);

		// members
		float                   width;          // 270
		BSTArray<CollisionData> collisionData;  // 278
	};
	static_assert(sizeof(BarrierProjectile) == 0x290);
}
