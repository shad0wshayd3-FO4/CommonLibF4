#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/T/TESObjectSTAT.h"
#include "RE/M/MOVABLE_STATIC_DATA.h"

namespace RE
{
	class __declspec(novtable) BGSMovableStatic :
		public TESObjectSTAT,              // 000
		public BGSDestructibleObjectForm,  // 0E8
		public BGSKeywordForm              // 0F8
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMovableStatic };
		static constexpr auto VTABLE{ VTABLE::BGSMovableStatic };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMSTT };

		// members
		BGSSoundDescriptorForm* soundLoop;  // 118
		MOVABLE_STATIC_DATA     data;       // 120
	};
	static_assert(sizeof(BGSMovableStatic) == 0x128);
}
