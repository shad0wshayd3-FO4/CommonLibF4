#pragma once

namespace RE
{
	class TESConditionItem
	{
	public:
		[[nodiscard]] float GetComparisonValue()
		{
			using func_t = decltype(&TESConditionItem::GetComparisonValue);
			static REL::Relocation<func_t> func{ REL::ID(2212007) };
			return func(this);
		}

		[[nodiscard]] bool IsTrue(TESObjectREFR* a_actionRef, TESObjectREFR* a_targetRef)
		{
			using func_t = bool (*)(TESConditionItem*, TESObjectREFR*, TESObjectREFR*);
			static REL::Relocation<func_t> func{ REL::ID(2212008) };
			return func(this, a_actionRef, a_targetRef);
		}

		[[nodiscard]] bool IsTrue(ConditionCheckParams& a_params)
		{
			using func_t = bool (*)(TESConditionItem*, ConditionCheckParams&);
			static REL::Relocation<func_t> func{ REL::ID(2212009) };
			return func(this, a_params);
		}

		// members
		TESConditionItem*   next;  // 00
		CONDITION_ITEM_DATA data;  // 08
	};
	static_assert(sizeof(TESConditionItem) == 0x38);
}
