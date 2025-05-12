#pragma once

namespace RE
{
	class __declspec(novtable) TESIdleForm :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESIdleForm };
		static constexpr auto VTABLE{ VTABLE::TESIdleForm };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kIDLE };

		bool CheckConditions(TESObjectREFR* a_actionRef, TESObjectREFR* a_targetRef, bool a_recurseUp)
		{
			if (!conditions.IsTrue(a_actionRef, a_targetRef)) {
				return false;
			}

			if (a_recurseUp) {
				if (parentIdle) {
					return parentIdle->CheckConditions(a_actionRef, a_targetRef, a_recurseUp);
				}
			}

			return true;
		}

		// members
		TESCondition    conditions;         // 20
		IDLE_DATA       data;               // 28
		NiFormArray* childIdles;         // 30
		TESIdleForm* parentIdle;         // 38
		TESIdleForm* prevIdle;           // 40
		BSFixedString   behaviorGraphName;  // 48
		BSFixedString   animEventName;      // 50
		BSFixedString   animFileName;       // 58
		BSStringT<char> formEditorID;       // 60
	};
	static_assert(sizeof(TESIdleForm) == 0x70);
}
