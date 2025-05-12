#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSSoundKeywordMapping :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSoundKeywordMapping };
		static constexpr auto VTABLE{ VTABLE::BGSSoundKeywordMapping };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kKSSM };

		// members
		BSTSet<BGSKeyword*>                                keywordSet;         // 20
		BSTHashMap<std::uint32_t, BGSSoundDescriptorForm*> reverbDescMap;      // 50
		BGSSoundDescriptorForm*                            descriptor;         // 80
		BGSSoundDescriptorForm*                            exteriorTail;       // 88
		BGSSoundDescriptorForm*                            vatsDescriptor;     // 90
		float                                              vatsDescThreshold;  // 98
	};
	static_assert(sizeof(BGSSoundKeywordMapping) == 0xA0);
}
