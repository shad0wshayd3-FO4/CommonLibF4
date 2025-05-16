#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiPointer.h"
#include "RE/T/TESPackage.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class NiAVObject;
	class SpectatorThreatInfo;

	class __declspec(novtable) SpectatorPackage :
		public TESPackage  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::SpectatorPackage };
		static constexpr auto VTABLE{ VTABLE::SpectatorPackage };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPACK };

		// members
		std::time_t                   lastPathRequestTime;  // 0C8
		float                         timer;                // 0D0
		float                         conversationTimer;    // 0D4
		float                         eventRadius;          // 0D8
		bool                          flagCompleted;        // 0DC
		NiPoint3                      eventCenter;          // 0E0
		BSTArray<SpectatorThreatInfo> threatInfoList;       // 0F0
		NiPointer<NiAVObject>         debugGeometry;        // 108
	};
	static_assert(sizeof(SpectatorPackage) == 0x110);
}
