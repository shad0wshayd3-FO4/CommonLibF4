#pragma once

namespace RE
{
	struct BGSRefAliasInstanceData
	{
	public:
		// members
		TESQuest*              quest;              // 00
		BGSRefAlias*           alias;              // 08
		BSTArray<TESPackage*>* instancedPackages;  // 10
	};
	static_assert(sizeof(BGSRefAliasInstanceData) == 0x18);
}
