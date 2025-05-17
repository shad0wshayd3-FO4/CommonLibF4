#pragma once

namespace RE
{
	enum class SCRIPT_OUTPUT;
	class ConditionCheckParams;
	class TESConditionItem;

	class TESCondition
	{
	public:
		[[nodiscard]] explicit operator bool() const noexcept { return head != nullptr; }

		[[nodiscard]] bool operator()(TESObjectREFR* a_actionRef, TESObjectREFR* a_targetRef) const
		{
			return IsTrue(a_actionRef, a_targetRef);
		}

		[[nodiscard]] bool IsTrue(TESObjectREFR* a_actionRef, TESObjectREFR* a_targetRef) const
		{
			using func_t = decltype(&TESCondition::IsTrue);
			static REL::Relocation<func_t> func{ REL::ID(2211989) };
			return func(this, a_actionRef, a_targetRef);
		}

		[[nodiscard]] bool IsTrueForAllButFunction(ConditionCheckParams& a_paramData, SCRIPT_OUTPUT a_function) const
		{
			using func_t = decltype(&TESCondition::IsTrueForAllButFunction);
			static REL::Relocation<func_t> func{ REL::ID(1182457) };
			return func(this, a_paramData, a_function);
		}

		void ClearAllConditionItems() const
		{
			using func_t = decltype(&TESCondition::ClearAllConditionItems);
			static REL::Relocation<func_t> func{ REL::ID(2211988) };
			return func(this);
		}

		// members
		TESConditionItem* head;  // 0
	};
	static_assert(sizeof(TESCondition) == 0x8);
}
