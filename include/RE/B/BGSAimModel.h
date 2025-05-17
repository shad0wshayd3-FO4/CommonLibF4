#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSAimModel :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAimModel };
		static constexpr auto VTABLE{ VTABLE::BGSAimModel };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kAMDL };

		class Data
		{
		public:
			// members
			float         aimModelMinConeDegrees;             // 00
			float         aimModelMaxConeDegrees;             // 04
			float         aimModelConeIncreasePerShot;        // 08
			float         aimModelConeDecreasePerSec;         // 0C
			std::uint32_t aimModelConeDecreaseDelayMs;        // 10
			float         aimModelConeSneakMultiplier;        // 14
			float         aimModelRecoilDiminishSpringForce;  // 18
			float         aimModelRecoilDiminishSightsMult;   // 1C
			float         aimModelRecoilMaxDegPerShot;        // 20
			float         aimModelRecoilMinDegPerShot;        // 24
			float         aimModelRecoilHipMult;              // 28
			std::uint32_t aimModelRecoilShotsForRunaway;      // 2C
			float         aimModelRecoilArcDeg;               // 30
			float         aimModelRecoilArcRotateDeg;         // 34
			float         aimModelConeIronSightsMultiplier;   // 38
			float         aimModelBaseStability;              // 3C
		};
		static_assert(sizeof(Data) == 0x40);

		// members
		Data aimModelData;  // 20
	};
	static_assert(sizeof(BGSAimModel) == 0x60);
}
