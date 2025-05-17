#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class NiAVObject;

	class SpectatorThreatInfo
	{
	public:
		enum class THREAT_LEVEL;

		// members
		ActorHandle                              source;              // 00
		ActorHandle                              target;              // 04
		REX::EnumSet<THREAT_LEVEL, std::int32_t> threatLevel;         // 08
		std::time_t                              lastPerceivedTime;   // 10
		float                                    radius;              // 18
		NiPoint3                                 lastKnownPosSource;  // 1C
		NiPoint3                                 lastKnownPosTarget;  // 28
		bool                                     hasSource;           // 34
		bool                                     hasTarget;           // 35
		NiPointer<NiAVObject>                    debugGeometry;       // 38
	};
	static_assert(sizeof(SpectatorThreatInfo) == 0x40);
}
