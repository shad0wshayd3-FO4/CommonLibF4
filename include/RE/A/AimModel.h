#pragma once

namespace RE
{
	class __declspec(novtable) AimModel
	{
	public:
		BGSAimModel::Data               aimModelData;          // 00
		BSSpring::SpringState<NiPoint2> recoilSpring;          // 40
		BSSpring::SpringState<NiPoint2> recoilDiminishSpring;  // 54
		NiPoint2                        targetRecoilHead;      // 68
		NiPoint2                        currentRecoilHead;     // 70
		NiPoint2                        prevRecoilRad;         // 78
		NiPoint2                        preShotAimRad;         // 80
		Actor*                          actor;                 // 88
		float                           fireConeSize;          // 90
		float                           lastShotDeltaMs;       // 94
		unsigned int                    continuousShots;       // 98
	};
	static_assert(sizeof(AimModel) == 0xA0);
}
