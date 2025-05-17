#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/S/SubgraphIdentifier.h"

namespace RE
{
	struct SubGraphIdleRootData
	{
	public:
		// members
		SubgraphIdentifier subGraphID;      // 00
		BSFixedString      idleRootName;    // 08
		std::int8_t        count;           // 10
		std::int8_t        activeCount;     // 11
		bool               forFirstPerson;  // 12
	};
	static_assert(sizeof(SubGraphIdleRootData) == 0x18);
}
