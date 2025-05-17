#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) TESProduceForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESProduceForm };
		static constexpr auto VTABLE{ VTABLE::TESProduceForm };

		// members
		BGSSoundDescriptorForm* harvestSound;      // 08
		TESBoundObject*         produceItem;       // 10
		std::int8_t             produceChance[4];  // 18
	};
	static_assert(sizeof(TESProduceForm) == 0x20);
}
