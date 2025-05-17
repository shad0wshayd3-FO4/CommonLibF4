#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSOutfit :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSOutfit };
		static constexpr auto VTABLE{ VTABLE::BGSOutfit };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kOTFT };

		// members
		BSTArray<TESForm*> outfitItems;  // 20
	};
	static_assert(sizeof(BGSOutfit) == 0x38);
}
