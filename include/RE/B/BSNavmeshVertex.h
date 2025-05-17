#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class BSNavmeshVertex
	{
	public:
		// members
		NiPoint3 location;  // 0
	};
	static_assert(sizeof(BSNavmeshVertex) == 0xC);
}
