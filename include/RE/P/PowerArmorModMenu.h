#pragma once

#include "RE/E/ExamineMenu.h"

namespace RE
{
	class __declspec(novtable) PowerArmorModMenu :
		public ExamineMenu
	{
	public:
		static constexpr auto RTTI{ RTTI::PowerArmorModMenu };
		static constexpr auto VTABLE{ VTABLE::PowerArmorModMenu };
		static constexpr auto MENU_NAME{ "PowerArmorModMenu"sv };

		virtual ~PowerArmorModMenu();  // 00

		// override (ExamineMenu)
		virtual void                 PreDisplay() override;
		virtual void                 BuildCanceled() override;                                                                                                                    // 16
		virtual void                 BuildConfirmed(bool a_ownerIsWorkbench) override;                                                                                            // 17
		virtual bool                 GetWorkbenchHasInventory() override;                                                                                                         // 18
		virtual const ModChoiceData* QCurrentModChoiceData() override;                                                                                                            // 19
		virtual void                 ShowBuildFailureMessage() override;                                                                                                          // 1A
		virtual EQUIP_TYPE           GetInventoryEntryEquipState(const InventoryUserUIInterfaceEntry& a_entry) override;                                                          // 1C
		virtual void                 ShowCurrent3D() override;                                                                                                                    // 1D
		virtual void                 HighlightWeaponPart() override;                                                                                                              // 28
		virtual void                 ResetHighlight() override;                                                                                                                   // 29
		virtual void                 CreateModdedInventoryItem() override;                                                                                                        // 2A
		virtual const char*          GetBuildConfirmButtonLabel() override;                                                                                                       // 30
		virtual void                 GetBuildConfirmQuestion(char* a_buffer, std::uint32_t a_bufferLength) override;                                                              // 31
		virtual bool                 GetCanRepairSelectedItem() override;                                                                                                         // 32
		virtual NiAVObject*          GetCurrent3D() override;                                                                                                                     // 33
		virtual bool                 GetCurrent3DLoaded() override;                                                                                                               // 34
		virtual bool                 GetIsValidInventoryItem(const BGSInventoryItem& a_item, std::uint32_t a_stackID) override;                                                   // 35
		virtual const char*          GetMenuName() override;                                                                                                                      // 36
		virtual void                 OnSwitchBaseItem() override;                                                                                                                 // 37
		virtual void                 PopulateInventoryItemObj(ObjectRefHandle a_owner, const InventoryUserUIInterfaceEntry& a_entry, Scaleform::GFx::Value& a_itemObj) override;  // 38
		virtual void                 RegisterMenuComponents(const Scaleform::GFx::FunctionHandler::Params& a_params) override;                                                    // 39
		virtual void                 RepairSelectedItem() override;                                                                                                               // 3A
		virtual void                 SetFilter() override;                                                                                                                        // 3B
		virtual void                 ToggleItemEquipped() override;                                                                                                               // 3D
		virtual void                 UpdateModChoiceList() override;                                                                                                              // 3F

		// members
		WorkbenchMenuBase::ModChoiceData repairData;                  // 810
		bool                             queuePreviewedPieceAttatch;  // 848
	};
	static_assert(sizeof(PowerArmorModMenu) == 0x850);
}
