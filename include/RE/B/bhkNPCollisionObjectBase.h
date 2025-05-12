#pragma once

#include "RE/N/NiCollisionObject.h"

namespace RE
{
	class __declspec(novtable) bhkNPCollisionObjectBase :
		public NiCollisionObject  // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkNPCollisionObjectBase };
		inline static constexpr auto VTABLE{ VTABLE::bhkNPCollisionObjectBase };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::bhkNPCollisionObjectBase };

		// add
		virtual void LockMotionImpl() = 0;  // 2C

		// members
		NiTFlags<std::uint16_t, bhkNPCollisionObjectBase> flags;  // 18
	};
	static_assert(sizeof(bhkNPCollisionObjectBase) == 0x20);
}
