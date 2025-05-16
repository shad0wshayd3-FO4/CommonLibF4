#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSSpinLock.h"

namespace RE
{
	struct BGSRefAliasInstanceData;

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
