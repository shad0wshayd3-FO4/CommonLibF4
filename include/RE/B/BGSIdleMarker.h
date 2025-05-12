#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/T/TESModel.h"
#include "RE/B/BGSIdleCollection.h"

namespace RE
{
	class __declspec(novtable) BGSIdleMarker :
		public TESBoundObject,    // 00
		public BGSKeywordForm,    // 68
		public TESModel,          // 88
		public BGSIdleCollection  // B8
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSIdleMarker };
		static constexpr auto VTABLE{ VTABLE::BGSIdleMarker };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kIDLM };

		// members
		BGSKeyword* animArchType;  // D8
		BGSKeyword* flavorAnim;    // E0
	};
	static_assert(sizeof(BGSIdleMarker) == 0xE8);
}
