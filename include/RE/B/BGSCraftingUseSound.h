#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) BGSCraftingUseSound :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSCraftingUseSound };
		static constexpr auto VTABLE{ VTABLE::BGSCraftingUseSound };

		// members
		BGSSoundDescriptorForm* craftingUseSound;  // 08
	};
	static_assert(sizeof(BGSCraftingUseSound) == 0x10);
}
