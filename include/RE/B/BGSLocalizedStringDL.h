#pragma once

namespace RE
{
	struct BGSLocalizedStringDL
	{
	public:
		void GetDescription(BSStringT<char>& a_out, const TESForm* a_form) const
		{
			using func_t = decltype(&BGSLocalizedStringDL::GetDescription);
			static REL::Relocation<func_t> func{ REL::ID(523613) };
			return func(this, a_out, a_form);
		}

		[[nodiscard]] BGSLocalizedStrings::ScrapStringBuffer GetText(TESFile& a_file) const
		{
			using func_t = decltype(&BGSLocalizedStringDL::GetText);
			static REL::Relocation<func_t> func{ REL::ID(472297) };
			return func(this, a_file);
		}

		// members
		std::uint32_t id{ 0 };  // 0
	};
	static_assert(sizeof(BGSLocalizedStringDL) == 0x4);
}
