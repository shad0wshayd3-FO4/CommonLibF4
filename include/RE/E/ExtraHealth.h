#pragma once

#include "RE/B/BSExtraData.h"

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
			REX::EMPLACE_VTABLE(this);
		}

		// members
		float health;  // 18
	};
	static_assert(sizeof(ExtraHealth) == 0x20);
}
