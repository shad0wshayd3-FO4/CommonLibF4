#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BSPrecomputedNavmeshInfoPathMap :
		public BSTSingletonExplicit<BSPrecomputedNavmeshInfoPathMap>  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSPrecomputedNavmeshInfoPathMap };

		// members
		BSTArray<BSTArray<const BSNavmeshInfo*>*>       allPaths;        // 00
		BSTHashMap<const BSNavmeshInfo*, std::uint32_t> infoToIndexMap;  // 18
	};
	static_assert(sizeof(BSPrecomputedNavmeshInfoPathMap) == 0x48);
}
