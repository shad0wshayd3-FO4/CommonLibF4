#pragma once

#include "RE/Havok/hkVector4.h"

namespace RE
{
	class hkAabb
	{
	public:
		// members
		hkVector4f min;
		hkVector4f max;
	};
	static_assert(sizeof(hkAabb) == 0x20);
}
