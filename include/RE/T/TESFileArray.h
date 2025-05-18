#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class TESFile;

	class TESFileArray :
		public BSStaticArray<TESFile*>  // 00
	{
	public:
	};
	static_assert(sizeof(TESFileArray) == 0x10);
}
