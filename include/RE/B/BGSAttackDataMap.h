#pragma once

#include "RE/B/BSTHashMap.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiRefObject.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class BGSAttackData;

	class __declspec(novtable) BGSAttackDataMap :
		public NiRefObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAttackDataMap };
		static constexpr auto VTABLE{ VTABLE::BGSAttackDataMap };

		// members
		BSTHashMap<BSFixedString, NiPointer<BGSAttackData>> attackDataMap;    // 10
		TESRace*                                            defaultDataRace;  // 40
	};
	static_assert(sizeof(BGSAttackDataMap) == 0x48);
}
