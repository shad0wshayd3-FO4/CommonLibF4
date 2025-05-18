#pragma once

#include "RE/H/hkVector4f.h"

namespace RE
{
	class hkAabb
	{
	public:
		// members
		hkVector4f min;  // 00
		hkVector4f max;  // 10
	};
	static_assert(sizeof(hkAabb) == 0x20);
}
