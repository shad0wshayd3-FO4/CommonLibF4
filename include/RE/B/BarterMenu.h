#pragma once

#include "RE/B/BSTHashMap.h"
#include "RE/B/BarterMenuTentativeInventoryUIInterface.h"
#include "RE/C/ContainerMenuBase.h"

namespace RE
{
	class __declspec(novtable) BarterMenu :
		public ContainerMenuBase  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BarterMenu };
		static constexpr auto VTABLE{ VTABLE::BarterMenu };
		static constexpr auto MENU_NAME{ "BarterMenu"sv };

		class ItemBarterData
		{
		public:
			// members
			BSTHashMap<std::uint32_t, std::int32_t> stackQuantityMap;  // 00
			std::uint32_t                           capsOwedByPlayer;  // 30
		};
		static_assert(sizeof(ItemBarterData) == 0x38);

		// override
		virtual UI_MESSAGE_RESULTS                   ProcessMessage(UIMessage& a_message) override;                                                                                             // 03
		virtual bool                                 OnButtonEventRelease(const BSFixedString& a_eventName) override;                                                                           // 0F
		virtual void                                 ConfirmInvestment() override;                                                                                                              // 14
		virtual void                                 DoItemTransfer(std::uint32_t a_itemIndex, std::uint32_t a_count, bool a_fromContainer) override;                                           // 15
		virtual bool                                 GetDisplayBarterValues() override;                                                                                                         // 16
		virtual std::uint32_t                        GetItemValue(std::uint32_t a_itemIndex, bool a_inContainer) override;                                                                      // 1A
		virtual const InventoryUserUIInterfaceEntry* GetInventoryItemByListIndex(bool a_inContainer, std::uint32_t a_index) override;                                                           // 1B
		virtual void                                 PopulateMenuObj(ObjectRefHandle a_inventoryRef, const InventoryUserUIInterfaceEntry& a_entry, Scaleform::GFx::Value& a_menuObj) override;  // 1C
		virtual void                                 SetMenuSuppressed(bool a_suppressed) override;                                                                                             // 1D
		virtual void                                 UpdateEncumbranceAndCaps(bool a_inContainer, std::int32_t a_capsDifferential) override;                                                    // 1E
		virtual void                                 UpdateList(bool a_inContainer) override;                                                                                                   // 20

		void ClearTradingData()
		{
			using func_t = decltype(&BarterMenu::ClearTradingData);
			static REL::Relocation<func_t> func{ ID::BarterMenu::ClearTradingData };
			return func(this);
		}

		void CompleteTrade()
		{
			using func_t = decltype(&BarterMenu::CompleteTrade);
			static REL::Relocation<func_t> func{ ID::BarterMenu::CompleteTrade };
			return func(this);
		}

		[[nodiscard]] std::int64_t GetCapsOwedByPlayer()
		{
			using func_t = decltype(&BarterMenu::GetCapsOwedByPlayer);
			static REL::Relocation<func_t> func{ ID::BarterMenu::GetCapsOwedByPlayer };
			return func(this);
		}

		// members
		BSTHashMap<InventoryInterface::Handle*, ItemBarterData*> barteredItems;              // 430
		std::unique_ptr<BSGFxShaderFXTarget>                     capsTransferInfo_mc;        // 460
		std::unique_ptr<BSGFxShaderFXTarget>                     capsTransferBackground_mc;  // 468
		ObjectRefHandle                                          vendorChestRef;             // 470
		ObjectRefHandle                                          vendorActor;                // 474
		BarterMenuTentativeInventoryUIInterface                  playerTentativeInv;         // 478
		BarterMenuTentativeInventoryUIInterface                  containerTentativeInv;      // 4F8
		bool                                                     confirmingTrade;            // 578
	};
	static_assert(sizeof(BarterMenu) == 0x580);
}
