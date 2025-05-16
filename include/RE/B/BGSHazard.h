#pragma once

#include "RE/B/BGSPreloadable.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESImageSpaceModifiableForm.h"
#include "RE/T/TESModel.h"
#include "RE/B/BGSHazardData.h"

namespace RE
{
	class __declspec(novtable) BGSHazard :
		public TESBoundObject,              // 000
		public TESFullName,                 // 068
		public TESModel,                    // 078
		public BGSPreloadable,              // 0A8
		public TESImageSpaceModifiableForm  // 0B0
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSHazard };
		static constexpr auto VTABLE{ VTABLE::BGSHazard };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kHAZD };

		// members
		BGSHazardData data;  // 0C0
	};
	static_assert(sizeof(BGSHazard) == 0x108);
}
