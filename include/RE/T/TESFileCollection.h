#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class TESFile;

	class TESFileCollection
	{
	public:
		// members
		BSTArray<TESFile*> files;       // 00
		BSTArray<TESFile*> smallFiles;  // 18
	};
	static_assert(sizeof(TESFileCollection) == 0x30);
}
