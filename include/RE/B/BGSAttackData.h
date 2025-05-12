#pragma once

namespace RE
{
	class __declspec(novtable) BGSAttackData :
		public NiRefObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAttackData };
		static constexpr auto VTABLE{ VTABLE::BGSAttackData };

		// members
		BSFixedString event;              // 10
		AttackData    data;               // 18
		BGSEquipSlot* weaponEquipSlot;    // 50
		BGSEquipSlot* requiredEquipSlot;  // 58
	};
	static_assert(sizeof(BGSAttackData) == 0x60);
}
