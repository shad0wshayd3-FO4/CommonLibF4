#pragma once

namespace RE
{
	class hkcdRayQueryFlags
	{
	public:
		enum class Enum
		{
			kNoFlags = 0x0,
			kDisableBackFacingTriangleHits = 0x1,
			kDisableFrontFacingTriangleHits = 0x2,
			kEnableInsideHits = 0x4,
			kEnableExtraTriangleBevelplanes = 0x8
		};
	};
	static_assert(std::is_empty_v<hkcdRayQueryFlags>);
}
