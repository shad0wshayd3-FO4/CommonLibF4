#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class __declspec(novtable) ExtraLeveledCreature :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraLeveledCreature };
		static constexpr auto VTABLE{ VTABLE::ExtraLeveledCreature };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kLeveledCreature };

		// members
		TESActorBase* originalBase;   // 18
		TESActorBase* templates[13];  // 20
	};
	static_assert(sizeof(ExtraLeveledCreature) == 0x88);
}
