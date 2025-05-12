#pragma once

namespace RE
{
	class __declspec(novtable) ExtraAliasInstanceArray :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraAliasInstanceArray };
		static constexpr auto VTABLE{ VTABLE::ExtraAliasInstanceArray };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kAliasInstanceArray };

		// members
		BSTArray<BGSRefAliasInstanceData> aliasArray;      // 18
		BSReadWriteLock                   aliasArrayLock;  // 30
	};
	static_assert(sizeof(ExtraAliasInstanceArray) == 0x38);
}
