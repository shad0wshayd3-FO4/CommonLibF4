#pragma once

namespace RE
{
	class ImageSpaceModifierFinder
	{
	public:
		// members
		TESImageSpaceModifierForm* modifier;        // 00
		const BSFixedString&       modifierToFind;  // 08
	};
	static_assert(sizeof(ImageSpaceModifierFinder) == 0x10);
}
