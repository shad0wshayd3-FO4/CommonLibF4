#pragma once

#include "RE/N/NiPointer.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class NiTexture;

	class BSScaleformExternalTexture
	{
	public:
		// members
		NiPointer<NiTexture> gamebryoTexture;  // 00
		std::uint32_t        renderTarget;     // 08
		BSFixedString        texturePath;      // 10
	};
	static_assert(sizeof(BSScaleformExternalTexture) == 0x18);
}
