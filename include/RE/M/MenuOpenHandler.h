#pragma once

namespace RE
{
	struct __declspec(novtable) MenuOpenHandler :
		public BSInputEventUser  // 00
	{
		static constexpr auto RTTI{ RTTI::MenuOpenHandler };
		static constexpr auto VTABLE{ VTABLE::MenuOpenHandler };
	};
	static_assert(sizeof(MenuOpenHandler) == 0x10);
}
