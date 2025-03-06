#pragma once

namespace RE
{
	class __declspec(novtable) hkBaseObject
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hkBaseObject };
		inline static constexpr auto VTABLE{ VTABLE::hkBaseObject };

		virtual ~hkBaseObject() = default;  // 00

		// add
		virtual void __first_virtual_table_function__() { return; }  // 01
	};
	static_assert(sizeof(hkBaseObject) == 0x8);
}
