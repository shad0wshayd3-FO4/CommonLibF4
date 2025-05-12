#pragma once

namespace RE
{
	class __declspec(novtable) BGSBehaviorGraphModel :
		public TESModel  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSBehaviorGraphModel };
		static constexpr auto VTABLE{ VTABLE::BGSBehaviorGraphModel };
	};
	static_assert(sizeof(BGSBehaviorGraphModel) == 0x30);
}
