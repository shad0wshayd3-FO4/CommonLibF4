#pragma once

#include "RE/M/Movement.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSMovementType :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMovementType };
		static constexpr auto VTABLE{ VTABLE::BGSMovementType };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMOVT };

		// members
		Movement::TypeData movementTypeData;  // 20
	};
	static_assert(sizeof(BGSMovementType) == 0xA0);
}
