#pragma once

namespace RE
{
	class __declspec(novtable) BGSGodRays :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSGodRays };
		static constexpr auto VTABLE{ VTABLE::BGSGodRays };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kGDRY };

		struct GodRaysData
		{
		public:
			// members
			NiColor colorAir;     // 00
			NiColor colorBack;    // 0C
			NiColor colorFwd;     // 18
			float   intensity;    // 24
			float   scatterAir;   // 28
			float   scatterBack;  // 2C
			float   scatterFwd;   // 30
			float   phaseBack;    // 34
			float   phaseFwd;     // 38
		};
		static_assert(sizeof(GodRaysData) == 0x3C);

		// members
		GodRaysData data;  // 20
	};
	static_assert(sizeof(BGSGodRays) == 0x60);
}
