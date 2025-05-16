#pragma once

#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/B/BSTTuple.h"
#include "RE/T/TESCondition.h"
#include "RE/B/BGSTypedKeywordValue.h"
#include "RE/B/BGSTypedFormValuePair.h"

namespace RE
{
	class __declspec(novtable) BGSConstructibleObject :
		public TESForm,                 // 00
		public BGSPickupPutdownSounds,  // 20
		public TESDescription           // 38
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSConstructibleObject };
		static constexpr auto VTABLE{ VTABLE::BGSConstructibleObject };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCOBJ };

		struct ConstructibleObjectData
		{
		public:
			// members
			std::uint16_t numConstructed;    // 0
			std::uint16_t workshopPriority;  // 2
		};
		static_assert(sizeof(ConstructibleObjectData) == 0x4);

		[[nodiscard]] TESForm*      GetCreatedItem() const noexcept { return createdItem; }
		[[nodiscard]] std::uint16_t GetWorkshopPriority() const noexcept { return data.workshopPriority; }

		// members
		BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* requiredItems;   // 50
		TESCondition                                                    conditions;      // 58
		TESForm*                                                        createdItem;     // 60
		BGSKeyword*                                                     benchKeyword;    // 68
		ConstructibleObjectData                                         data;            // 70
		BGSTypedKeywordValueArray<KeywordType::kRecipeFilter>           filterKeywords;  // 78
	};
	static_assert(sizeof(BGSConstructibleObject) == 0x88);
}
