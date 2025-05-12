#pragma once

namespace RE
{
	class __declspec(novtable) BGSMessage :
		public TESForm,        // 00
		public TESFullName,    // 20
		public TESDescription  // 30
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMessage };
		static constexpr auto VTABLE{ VTABLE::BGSMessage };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMESG };

		void AddButton(MESSAGEBOX_BUTTON* btn)
		{
			using func_t = decltype(&BGSMessage::AddButton);
			static REL::Relocation<func_t> func{ REL::ID(236744) };
			return func(this, btn);
		}

		std::uint32_t GetConvertedDescription(BSFixedString& a_result)
		{
			using func_t = decltype(&BGSMessage::GetConvertedDescription);
			static REL::Relocation<func_t> func{ REL::ID(8331) };
			return func(this, a_result);
		}

		// members
		BGSMenuIcon*                     icon;         // 48
		TESQuest*                        ownerQuest;   // 50
		BSSimpleList<MESSAGEBOX_BUTTON*> buttonList;   // 58
		BSFixedStringCS                  swfFile;      // 68
		BGSLocalizedString               shortName;    // 70
		std::uint32_t                    flags;        // 78
		std::uint32_t                    displayTime;  // 7C
	};
	static_assert(sizeof(BGSMessage) == 0x80);
}
