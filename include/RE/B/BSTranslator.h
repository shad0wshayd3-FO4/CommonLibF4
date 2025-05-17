#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"

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
