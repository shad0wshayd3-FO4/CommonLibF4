#pragma once

namespace RE
{
	class hkBaseObject
	{
	public:
		// add
		virtual ~hkBaseObject();                          // 00
		virtual void __first_virtual_table_function__();  // 01
	};
	static_assert(sizeof(hkBaseObject) == 0x08);
}
