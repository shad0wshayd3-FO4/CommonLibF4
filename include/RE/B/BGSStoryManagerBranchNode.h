#pragma once

namespace RE
{
	class __declspec(novtable) BGSStoryManagerBranchNode :
		public BGSStoryManagerNodeBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSStoryManagerBranchNode };
		static constexpr auto VTABLE{ VTABLE::BGSStoryManagerBranchNode };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSMBN };

		// members
		BSTArray<BGSStoryManagerNodeBase*> children;  // 48
	};
	static_assert(sizeof(BGSStoryManagerBranchNode) == 0x60);
}
