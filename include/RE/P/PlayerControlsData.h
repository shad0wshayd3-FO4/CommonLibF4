#pragma once

#include "RE/N/NiPoint.h"
#include "RE/S/SpringState.h"

namespace RE
{
	class PlayerControlsData
	{
	public:
		// members
		NiPoint2                        moveInputVec;               // 00
		NiPoint2                        lookInputVec;               // 08
		NiPoint2                        lookInputVecNormalized;     // 10
		NiPoint2                        prevMoveVec;                // 18
		NiPoint2                        prevLookVec;                // 20
		BSSpring::SpringState<NiPoint3> rotationSpeedSpring;        // 28
		bool                            autoMove;                   // 44
		bool                            running;                    // 45
		bool                            togglePOV;                  // 46
		bool                            vanityModeEnabled;          // 47
		bool                            checkHeldStates;            // 48
		bool                            setupHeldStatesForRelease;  // 49
	};
	static_assert(sizeof(PlayerControlsData) == 0x4C);
}
