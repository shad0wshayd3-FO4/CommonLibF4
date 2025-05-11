#pragma once

namespace RE
{
	struct hkcdRayQueryFlags
	{
		enum Enum
		{
			kNone = 0,
			kDisableBackFacingTriangleHits = 1 << 0,
			kDisableFrontFacingTriangleHits = 1 << 1,
			kEnableInsideHits = 1 << 2
		};
	};
}
