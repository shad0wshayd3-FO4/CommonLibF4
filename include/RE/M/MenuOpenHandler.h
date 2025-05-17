#pragma once

#include "RE/B/BSInputEventUser.h"

namespace RE
{
	class __declspec(novtable) MenuOpenHandler :
		public BSInputEventUser  // 00
	{
		static constexpr auto RTTI{ RTTI::MenuOpenHandler };
		static constexpr auto VTABLE{ VTABLE::MenuOpenHandler };
	};
	static_assert(sizeof(MenuOpenHandler) == 0x10);
}
