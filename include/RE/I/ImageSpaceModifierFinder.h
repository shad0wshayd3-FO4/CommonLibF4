#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class TESImageSpaceModifierForm;

	class ImageSpaceModifierFinder
	{
	public:
		// members
		TESImageSpaceModifierForm* modifier;        // 00
		const BSFixedString&       modifierToFind;  // 08
	};
	static_assert(sizeof(ImageSpaceModifierFinder) == 0x10);
}
