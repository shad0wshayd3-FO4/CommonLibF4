#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class __declspec(novtable) BGSBendableSpline :
		public TESBoundObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSBendableSpline };
		static constexpr auto VTABLE{ VTABLE::BGSBendableSpline };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kBNDS };

		struct SplineData_Untilv130
		{
		public:
			// members
			float         numTiles;   // 00
			std::uint16_t numSlices;  // 04
			std::uint16_t flags;      // 06
			NiColor       color;      // 08
		};
		static_assert(sizeof(SplineData_Untilv130) == 0x14);

		struct SplineData :
			public SplineData_Untilv130  // 00
		{
		public:
			// members
			float windSensibility;  // 14
			float flexibility;      // 18
		};
		static_assert(sizeof(SplineData) == 0x1C);

		// members
		SplineData     data;        // 68
		BGSTextureSet* textureSet;  // 88
	};
	static_assert(sizeof(BGSBendableSpline) == 0x90);
}
