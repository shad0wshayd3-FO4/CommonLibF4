#pragma once

#include "RE/T/TESForm.h"
#include "RE/B/BSISoundDescriptor.h"

namespace RE
{
	class __declspec(novtable) BGSSoundDescriptorForm :
		public TESForm,            // 00
		public BSISoundDescriptor  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSoundDescriptorForm };
		static constexpr auto VTABLE{ VTABLE::BGSSoundDescriptorForm };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSNDR };

		// members
		BGSSoundDescriptor* impl;  // 28
	};
	static_assert(sizeof(BGSSoundDescriptorForm) == 0x30);
}
