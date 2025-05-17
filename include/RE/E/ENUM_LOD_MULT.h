#pragma once

namespace RE
{
	enum class ENUM_LOD_MULT : std::int32_t
	{
		kNone = 0x0,
		kObjects = 0x1,
		kItems = 0x2,
		kActors = 0x3,
		kTrees = 0x4,
		kLandscape = 0x5,
		kDistantLOD = 0x6,
		kActorBodyPart = 0x7,
		kRenderedMenu = 0x8,
		kInvisible = 0x9,
		kSkyCell = 0xA,
	};
}
