#pragma once

namespace RE
{
	class __declspec(novtable) BGSEquipSlot :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSEquipSlot };
		static constexpr auto VTABLE{ VTABLE::BGSEquipSlot };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kEQUP };

		// members
		BSTArray<BGSEquipSlot*> parentSlots;          // 20
		std::uint32_t           flags;                // 38
		ActorValueInfo*         conditionActorValue;  // 40
	};
	static_assert(sizeof(BGSEquipSlot) == 0x48);
}
