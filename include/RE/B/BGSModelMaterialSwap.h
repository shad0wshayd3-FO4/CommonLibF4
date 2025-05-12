#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	class __declspec(novtable) BGSModelMaterialSwap :
		public TESModel  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSModelMaterialSwap };
		static constexpr auto VTABLE{ VTABLE::BGSModelMaterialSwap };

		// members
		BGSMaterialSwap* swapForm;             // 30
		float            colorRemappingIndex;  // 38
	};
	static_assert(sizeof(BGSModelMaterialSwap) == 0x40);
}
