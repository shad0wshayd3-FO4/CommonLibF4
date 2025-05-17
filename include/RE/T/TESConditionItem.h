#pragma once

#include "RE/C/CONDITION_ITEM_DATA.h"
#include "RE/C/ConditionCheckParams.h"

namespace RE
{
	class TESConditionItem
	{
	public:
		[[nodiscard]] float GetComparisonValue()
		{
			using func_t = decltype(&TESConditionItem::GetComparisonValue);
			static REL::Relocation<func_t> func{ ID::TESConditionItem::GetComparisonValue };
			return func(this);
		}

		[[nodiscard]] bool IsTrue(TESObjectREFR* a_actionRef, TESObjectREFR* a_targetRef)
		{
			using func_t = bool (*)(TESConditionItem*, TESObjectREFR*, TESObjectREFR*);
			static REL::Relocation<func_t> func{ ID::TESConditionItem::IsTrue1 };
			return func(this, a_actionRef, a_targetRef);
		}

		[[nodiscard]] bool IsTrue(ConditionCheckParams& a_params)
		{
			using func_t = bool (*)(TESConditionItem*, ConditionCheckParams&);
			static REL::Relocation<func_t> func{ ID::TESConditionItem::IsTrue2 };
			return func(this, a_params);
		}

		// members
		TESConditionItem*   next;  // 00
		CONDITION_ITEM_DATA data;  // 08
	};
	static_assert(sizeof(TESConditionItem) == 0x38);
}
