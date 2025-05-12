#pragma once

namespace RE
{
	class __declspec(novtable) BGSEquipType :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSEquipType };
		static constexpr auto VTABLE{ VTABLE::BGSEquipType };

		// add
		[[nodiscard]] virtual BGSEquipSlot* GetEquipSlot([[maybe_unused]] const TBO_InstanceData* a_data) const { return equipSlot; }  // 06
		virtual void                        SetEquipSlot(BGSEquipSlot* a_slot) { equipSlot = a_slot; }                                 // 07

		// members
		BGSEquipSlot* equipSlot;  // 08
	};
	static_assert(sizeof(BGSEquipType) == 0x10);

}
