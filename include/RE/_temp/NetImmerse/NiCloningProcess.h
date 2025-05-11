#pragma once

#include "RE/Bethesda/BSTHashMap.h"
#include "RE/NetImmerse/NiPoint.h"

namespace RE
{
	class NiObject;

	class NiCloningProcess
	{
	public:
		enum class CopyType
		{
			kNone = 0,
			kCopyExact,
			kCopyUnique,
		};

		// members
		BSTHashMap<NiObject*, NiObject*>      cloneMap;    // 00
		BSTHashMap<NiObject*, bool>           processMap;  // 30
		REX::EnumSet<CopyType, std::uint32_t> copyType;    // 60
		char                                  appendChar;  // 64
		NiPoint3                              scale;       // 68
	};
	static_assert(sizeof(NiCloningProcess) == 0x78);
}
