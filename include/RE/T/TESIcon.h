#pragma once

#include "RE/T/TESTexture.h"

namespace RE
{
	class __declspec(novtable) TESIcon :
		public TESTexture  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESIcon };
		static constexpr auto VTABLE{ VTABLE::TESIcon };
	};
	static_assert(sizeof(TESIcon) == 0x10);
}
