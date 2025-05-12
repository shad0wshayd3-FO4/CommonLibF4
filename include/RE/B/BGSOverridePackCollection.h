#pragma once

namespace RE
{
	class __declspec(novtable) BGSOverridePackCollection :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSOverridePackCollection };
		static constexpr auto VTABLE{ VTABLE::BGSOverridePackCollection };

		// members
		BGSListForm* spectatorOverRidePackList;      // 08
		BGSListForm* observeCorpseOverRidePackList;  // 10
		BGSListForm* guardWarnOverRidePackList;      // 18
		BGSListForm* enterCombatOverRidePackList;    // 20
		BGSListForm* followerCommandPackList;        // 28
		BGSListForm* elevatorOverRidePackList;       // 30
	};
	static_assert(sizeof(BGSOverridePackCollection) == 0x38);
}
