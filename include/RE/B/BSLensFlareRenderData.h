#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiPointer.h"
#include "RE/B/BSSpinLock.h"

namespace RE
{
	class BSLensFlareSpriteRenderData;

	class BSLensFlareRenderData
	{
	public:
		static constexpr auto RTTI{ RTTI::BSLensFlareRenderData };

		// members
		float                                            fadeDistRadiusScale;  // 00
		float                                            colorInfluence;       // 04
		BSTArray<NiPointer<BSLensFlareSpriteRenderData>> sprites;              // 08
		BSSpinLock                                       lock;                 // 20
		std::uint32_t                                    refCount;             // 28
	};
	static_assert(sizeof(BSLensFlareRenderData) == 0x30);
}
