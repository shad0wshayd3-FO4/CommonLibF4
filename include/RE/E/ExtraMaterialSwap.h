#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class __declspec(novtable) ExtraMaterialSwap :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraMaterialSwap };
		static constexpr auto VTABLE{ VTABLE::ExtraMaterialSwap };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kMaterialSwap };

		ExtraMaterialSwap() :
			BSExtraData(TYPE)
		{
			REX::EMPLACE_VTABLE(this);
		}

		// members
		BGSMaterialSwap* swap{ nullptr };  // 18
	};
	static_assert(sizeof(ExtraMaterialSwap) == 0x20);
}
