#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) TESValueForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESValueForm };
		static constexpr auto VTABLE{ VTABLE::TESValueForm };

		[[nodiscard]] static std::uint32_t GetFormValue(const TESForm* a_form, const TBO_InstanceData* a_data)
		{
			using func_t = std::int32_t (*)(const TESForm*, const TBO_InstanceData*);
			static REL::Relocation<func_t> func{ REL::ID(885783) };
			return func(a_form, a_data);
		}

		[[nodiscard]] std::int32_t GetFormValue() const noexcept { return value; }
		static void                SetFormValue(TESForm& a_form, std::int32_t a_value);

		// members
		std::int32_t value;  // 08
	};
	static_assert(sizeof(TESValueForm) == 0x10);
}
