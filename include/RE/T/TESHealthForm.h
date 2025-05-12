#pragma once

namespace RE
{
	class __declspec(novtable) TESHealthForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESHealthForm };
		static constexpr auto VTABLE{ VTABLE::TESHealthForm };

		// override (BaseFormComponent)
		void InitializeDataComponent() override;          // 02
		void ClearDataComponent() override;               // 03
		void CopyComponent(BaseFormComponent*) override;  // 06

		[[nodiscard]] static std::uint32_t GetFormHealth(const TESForm* a_form, const TBO_InstanceData* a_data)
		{
			using func_t = decltype(&TESHealthForm::GetFormHealth);
			static REL::Relocation<func_t> func{ REL::ID(2193227) };
			return func(a_form, a_data);
		}

		// members
		std::uint32_t health;  // 08
	};
	static_assert(sizeof(TESHealthForm) == 0x10);
}
