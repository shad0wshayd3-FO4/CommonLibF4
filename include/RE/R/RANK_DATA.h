#pragma once

#include "RE/B/BGSLocalizedString.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class RANK_DATA
	{
	public:
		// members
		BGSLocalizedString maleRankTitle;    // 00
		BGSLocalizedString femaleRankTitle;  // 08
		TESTexture         textureInsignia;  // 10
	};
	static_assert(sizeof(RANK_DATA) == 0x20);
}
