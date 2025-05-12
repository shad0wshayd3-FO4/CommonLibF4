#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) BGSMenuDisplayObject :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMenuDisplayObject };
		static constexpr auto VTABLE{ VTABLE::BGSMenuDisplayObject };

		// members
		TESBoundObject* menuDispObject;  // 08
	};
	static_assert(sizeof(BGSMenuDisplayObject) == 0x10);
}
