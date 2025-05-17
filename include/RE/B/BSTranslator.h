#pragma once

#include "RE/B/BSTHashMap.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class BSTranslator
	{
	public:
		// members
		BSTHashMap<BSFixedStringWCS, BSFixedStringWCS> translationMap;  //00
	};
	static_assert(sizeof(BSTranslator) == 0x30);
}
