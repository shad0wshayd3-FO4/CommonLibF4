#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiPointer.h"

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
