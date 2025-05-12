#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) TESDescription :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESDescription };
		static constexpr auto VTABLE{ VTABLE::TESDescription };

		// override (BaseFormComponent)
		void InitializeDataComponent() override  // 02
		{
			fileOffset = 0;
			chunkOffset = 0;
		}

		void ClearDataComponent() override { return; }    // 03
		void CopyComponent(BaseFormComponent*) override;  // 06

		void GetDescription(BSString& a_outString, const TESForm* a_form = nullptr)
		{
			using func_t = decltype(&TESDescription::GetDescription);
			static REL::Relocation<func_t> func{ REL::ID(2193019) };
			return func(this, a_outString, a_form);
		}

		// members
		std::uint32_t        fileOffset;       // 08
		std::uint32_t        chunkOffset;      // 0C
		BGSLocalizedStringDL descriptionText;  // 10
	};
	static_assert(sizeof(TESDescription) == 0x18);
}
