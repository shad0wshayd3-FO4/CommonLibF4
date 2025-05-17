#pragma once

#include "RE/B/BGSDirectionalAmbientLightingColors.h"
#include "RE/I/INTERIOR_DATA.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSLightingTemplate :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSLightingTemplate };
		static constexpr auto VTABLE{ VTABLE::BGSLightingTemplate };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLGTM };

		// members
		INTERIOR_DATA                       data;                              // 20
		BGSGodRays*                         godRays;                           // B0
		BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;  // B8
	};
	static_assert(sizeof(BGSLightingTemplate) == 0xD8);
}
