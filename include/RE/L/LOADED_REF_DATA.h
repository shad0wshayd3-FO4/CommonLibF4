#pragma once

namespace RE
{
	struct LOADED_REF_DATA
	{
	public:
		// members
		void*                 handleList;           // 00 - TODO
		NiPointer<NiAVObject> data3D;               // 08
		TESWaterForm*         currentWaterType;     // 10
		float                 relevantWaterHeight;  // 18
		float                 cachedRadius;         // 1C
		std::uint16_t         flags;                // 20
		std::int16_t          underwaterCount;      // 22
	};
	static_assert(sizeof(LOADED_REF_DATA) == 0x28);
}
