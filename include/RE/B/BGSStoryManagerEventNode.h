#pragma once

namespace RE
{
	class __declspec(novtable) BGSStoryManagerEventNode :
		public BGSStoryManagerBranchNode  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSStoryManagerEventNode };
		static constexpr auto VTABLE{ VTABLE::BGSStoryManagerEventNode };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSMEN };

		// members
		const BGSRegisteredStoryEvent* event;  // 60
	};
	static_assert(sizeof(BGSStoryManagerEventNode) == 0x68);
}
