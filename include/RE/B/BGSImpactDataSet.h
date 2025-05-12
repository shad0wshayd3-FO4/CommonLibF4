#pragma once

#include "RE/B/BGSPreloadable.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSImpactDataSet :
		public TESForm,        // 00
		public BGSPreloadable  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSImpactDataSet };
		static constexpr auto VTABLE{ VTABLE::BGSImpactDataSet };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kIPDS };

		// members
		BSTHashMap<const BGSMaterialType*, BGSImpactData*> impactMap;  // 28
	};
	static_assert(sizeof(BGSImpactDataSet) == 0x58);
}
