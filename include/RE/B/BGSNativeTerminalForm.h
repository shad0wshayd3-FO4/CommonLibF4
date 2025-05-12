#pragma once

namespace RE
{
	class __declspec(novtable) BGSNativeTerminalForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSNativeTerminalForm };
		static constexpr auto VTABLE{ VTABLE::BGSNativeTerminalForm };

		// members
		BGSTerminal* terminal;  // 08
	};
	static_assert(sizeof(BGSNativeTerminalForm) == 0x10);
}
