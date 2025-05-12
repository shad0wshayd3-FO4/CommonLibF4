#pragma once

namespace RE
{
	struct BSTranslator
	{
	public:
		// members
		BSTHashMap<BSFixedStringWCS, BSFixedStringWCS> translationMap;  //00
	};
	static_assert(sizeof(BSTranslator) == 0x30);
}
