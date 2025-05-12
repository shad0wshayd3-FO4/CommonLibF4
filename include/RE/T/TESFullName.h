#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) TESFullName :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESFullName };
		static constexpr auto VTABLE{ VTABLE::TESFullName };

		// add
		virtual std::uint32_t GetFullNameLength() const { return fullName.length(); }  // 07
		virtual const char*   GetFullName() const { return fullName.c_str(); }         // 08

		[[nodiscard]] static std::string_view GetFullName(const TESForm& a_form, bool a_strict = false);

		[[nodiscard]] static auto GetSparseFullNameMap()
			-> BSTHashMap<const TESForm*, BGSLocalizedString>&
		{
			static REL::Relocation<BSTHashMap<const TESForm*, BGSLocalizedString>*> sparseFullNameMap{ REL::ID(2661402), -0x8 };
			return *sparseFullNameMap;
		}

		static void SetFullName(TESForm& a_form, std::string_view a_fullName);

		// members
		BGSLocalizedString fullName;  // 08
	};
	static_assert(sizeof(TESFullName) == 0x10);
}
