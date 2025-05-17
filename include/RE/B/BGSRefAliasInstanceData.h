#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSRefAliasInstanceData
	{
	public:
		// members
		TESQuest*              quest;              // 00
		BGSRefAlias*           alias;              // 08
		BSTArray<TESPackage*>* instancedPackages;  // 10
	};
	static_assert(sizeof(BGSRefAliasInstanceData) == 0x18);
}
