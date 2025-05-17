#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class __declspec(novtable) ExtraCellWaterType :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraCellWaterType };
		static constexpr auto VTABLE{ VTABLE::ExtraCellWaterType };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kWaterType };

		// members
		TESWaterForm* water;  // 18
	};
	static_assert(sizeof(ExtraCellWaterType) == 0x20);
}
