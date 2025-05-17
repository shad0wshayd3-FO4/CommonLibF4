#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class BSLight;

	class BSShaderPropertyLightData
	{
	public:
		// members
		std::uint32_t      lightListFence;    // 00
		std::uint32_t      shadowAccumFlags;  // 04
		std::uint32_t      lightListChanged;  // 08
		BSTArray<BSLight*> lightList;         // 10
	};
	static_assert(sizeof(BSShaderPropertyLightData) == 0x28);
}
