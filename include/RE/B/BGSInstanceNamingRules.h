#pragma once

#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSInstanceNamingRules :
		public TESForm  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSInstanceNamingRules };
		static constexpr auto VTABLE{ VTABLE::BGSInstanceNamingRules };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kINNR };

		class RuleData
		{
		public:
			// members
			BGSLocalizedString text;                      // 00
			BGSKeywordForm     keywords;                  // 08
			float              compareVal;                // 28
			std::int8_t        propertyBridgeArrayIndex;  // 2C
			std::int8_t        operatorType;              // 2D
			std::uint16_t      index;                     // 2E
			bool               revert;                    // 30
		};
		static_assert(sizeof(RuleData) == 0x38);

		struct RuleSet :
			public BSTArray<RuleData>  // 00
		{
		public:
		};
		static_assert(sizeof(RuleSet) == 0x18);

		// members
		ENUM_FORM_ID                            type;          // 020
		RuleSet                                 ruleSets[10];  // 028
		BSTArray<const BGSInstanceNamingRules*> mergeSources;  // 118
	};
	static_assert(sizeof(BGSInstanceNamingRules) == 0x130);
}
