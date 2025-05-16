#pragma once

#include "RE/T/TESForm.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class __declspec(novtable) BGSAttractionRule :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAttractionRule };
		static constexpr auto VTABLE{ VTABLE::BGSAttractionRule };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kAORU };

		struct ATTRACTION_RULE_DATA
		{
		public:
			// members
			float radius;        // 00
			float minDelay;      // 04
			float maxDelay;      // 08
			bool  requiresLOS;   // 0C
			bool  combatTarget;  // 0D
		};
		static_assert(sizeof(ATTRACTION_RULE_DATA) == 0x10);

		// members
		ATTRACTION_RULE_DATA data;          // 20
		BSFixedString        formEditorID;  // 30
	};
	static_assert(sizeof(BGSAttractionRule) == 0x38);
}
