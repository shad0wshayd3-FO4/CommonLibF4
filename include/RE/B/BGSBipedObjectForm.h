#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) BGSBipedObjectForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSBipedObjectForm };
		static constexpr auto VTABLE{ VTABLE::BGSBipedObjectForm };

		// add
		virtual bool FillsBipedSlot(std::int32_t a_bipedSlot) const;  // 06

		// members
		BIPED_MODEL bipedModelData;  // 08
	};
	static_assert(sizeof(BGSBipedObjectForm) == 0x10);
}
