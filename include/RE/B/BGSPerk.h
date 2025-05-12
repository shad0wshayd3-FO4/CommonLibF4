#pragma once

namespace RE
{
	class __declspec(novtable) BGSPerk :
		public TESForm,         // 00
		public TESFullName,     // 20
		public TESDescription,  // 30
		public TESIcon          // 48
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPerk };
		static constexpr auto VTABLE{ VTABLE::BGSPerk };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPERK };

		// members
		PerkData                data;            // 58
		TESCondition            perkConditions;  // 60
		BSTArray<BGSPerkEntry*> perkEntries;     // 68
		BGSPerk*                nextPerk;        // 80
		BGSSoundDescriptorForm* sound;           // 88
		BSFixedStringCS         swfFile;         // 90
	};
	static_assert(sizeof(BGSPerk) == 0x98);
}
