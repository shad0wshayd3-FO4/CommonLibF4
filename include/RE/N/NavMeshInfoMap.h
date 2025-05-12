#pragma once

#include "RE/B/BSNavmeshInfoMap.h"
#include "RE/P/PrecomputedNavmeshInfoPathMap.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) NavMeshInfoMap :
		public TESForm,                       // 000
		public BSNavmeshInfoMap,              // 020
		public PrecomputedNavmeshInfoPathMap  // 030
	{
	public:
		static constexpr auto RTTI{ RTTI::NavMeshInfoMap };
		static constexpr auto VTABLE{ VTABLE::NavMeshInfoMap };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNAVI };

		// members
		bool                                               updateAll;          // 078
		BSTArray<BSNavmeshInfo*>                           staleNavmeshInfos;  // 080
		BSTHashMap<std::uint32_t, NavMeshInfo*>            infoMap;            // 098
		BSTHashMap<std::size_t, BSTArray<BSNavmeshInfo*>*> ckNavMeshInfoMap;   // 0C8
		BSReadWriteLock                                    mapLock;            // 0F8
		bool                                               init;               // 100
	};
	static_assert(sizeof(NavMeshInfoMap) == 0x108);
}
