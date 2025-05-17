#pragma once

#include "RE/C/ContainerMenuBase.h"

namespace RE
{
	class __declspec(novtable) ContainerMenu :
		public ContainerMenuBase  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::ContainerMenu };
		static constexpr auto VTABLE{ VTABLE::ContainerMenu };
		static constexpr auto MENU_NAME{ "ContainerMenu"sv };

		// override
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                                                                                             // 03
		virtual void               DoItemTransfer(std::uint32_t a_itemIndex, std::uint32_t a_count, bool a_fromContainer) override;                                           // 15
		virtual bool               GetCanEquipItem(std::uint32_t a_itemIndex, bool a_inContainer) override;                                                                   // 17
		virtual bool               GetIsItemEquipped(std::uint32_t a_itemIndex, bool a_inContainer) override;                                                                 // 18
		virtual void               ToggleItemEquipped(std::uint32_t a_itemIndex, bool a_inContainer) override;                                                                // 19
		virtual void               PopulateMenuObj(ObjectRefHandle a_inventoryRef, const InventoryUserUIInterfaceEntry& a_entry, Scaleform::GFx::Value& a_menuObj) override;  // 22
		virtual void               UpdateItemPickpocketInfo(std::int32_t a_index, bool a_inContainer, std::int32_t a_count) override;                                         // 25
		virtual void               UpdateList(bool a_inContainer) override;                                                                                                   // 26

		void TakeAllItems()
		{
			using func_t = decltype(&ContainerMenu::TakeAllItems);
			static REL::Relocation<func_t> func{ ID::ContainerMenu::TakeAllItems };
			return func(this);
		}

		// members
		std::unique_ptr<BSGFxShaderFXTarget>  pickpocketInfo_mc;         // 430
		std::uint32_t                         valueStolenFromContainer;  // 438
		bool                                  containerAccessed;         // 43C
		bool                                  addedTempItems;            // 43D
		bool                                  plantedExplosiveWeapon;    // 43E
		bool                                  containerIsAnimatingOpen;  // 43F
	};
	static_assert(sizeof(ContainerMenu) == 0x440);
}
