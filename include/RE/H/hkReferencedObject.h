#pragma once

#include "RE/H/hkBaseObject.h"

namespace RE
{
	class hkReferencedObject :
		public hkBaseObject
	{
	public:
		// members
		std::uint32_t memSizeAndRefCount;  // 08
	};
	static_assert(sizeof(hkReferencedObject) == 0x10);
}
