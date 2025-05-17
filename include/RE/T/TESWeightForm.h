#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) TESWeightForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESWeightForm };
		static constexpr auto VTABLE{ VTABLE::TESWeightForm };

		[[nodiscard]] static float GetFormWeight(const TESForm* a_form, const TBO_InstanceData* a_data)
		{
			using func_t = float (*)(const TESForm*, const TBO_InstanceData*);
			static REL::Relocation<func_t> func{ ID::TESWeightForm::GetFormWeight };
			return func(a_form, a_data);
		}

		[[nodiscard]] float GetFormWeight() const noexcept { return weight; }
		void                SetFormWeight(float a_weight) noexcept { weight = a_weight; }

		// members
		float weight;  // 08
	};
	static_assert(sizeof(TESWeightForm) == 0x10);
}
