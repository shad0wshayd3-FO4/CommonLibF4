#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) TESImageSpace :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESImageSpace };
		static constexpr auto VTABLE{ VTABLE::TESImageSpace };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kIMGS };

		// members
		ImageSpaceBaseData   data;          // 20
		TESTexture           lutTexture;    // 78
		NiPointer<NiTexture> niLutTexture;  // 88
	};
	static_assert(sizeof(TESImageSpace) == 0x90);
}
