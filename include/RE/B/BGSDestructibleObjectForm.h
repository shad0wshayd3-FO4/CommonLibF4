#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	struct DestructibleObjectData;

	class __declspec(novtable) BGSDestructibleObjectForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDestructibleObjectForm };
		static constexpr auto VTABLE{ VTABLE::BGSDestructibleObjectForm };

		// members
		DestructibleObjectData* data;  // 08
	};
	static_assert(sizeof(BGSDestructibleObjectForm) == 0x10);
}
