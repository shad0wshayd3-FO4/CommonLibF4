#pragma once

#include "RE/Bethesda/BGSInventoryInterface.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTList.h"
#include "RE/Bethesda/Events.h"
#include "RE/Bethesda/PipboyDataGroup.h"

namespace RE
{
	class PipboyInventoryData :
		public PipboyDataGroup,												// 00
		public BSTEventSink<BGSInventoryListEvent::Event>,					// 98
		public BSTEventSink<ActorEquipManagerEvent::Event>,					// A0
		public BSTEventSink<ActorValueEvents::ActorValueChangedEvent>,		// A8
		public BSTEventSink<PerkValueEvents::PerkEntryUpdatedEvent>,		// B0
		public BSTEventSink<PerkValueEvents::PerkValueChangedEvent>,		// B8
		public BSTEventSink<InventoryInterface::FavoriteChangedEvent>,		// C0
		public BSTEventSink<HolotapeStateChanged::Event>,					// C8
		public BSTEventSink<BGSInventoryItemEvent::Event>,					// D0
		public BSTEventSink<FavoriteMgr_Events::ComponentFavoriteEvent>,	// D8
		public BSTEventSink<PlayerDifficultySettingChanged::Event>			// E0
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyInventoryData };
		static constexpr auto VTABLE{ VTABLE::PipboyInventoryData };

		virtual ~PipboyInventoryData();

		enum ENTRY_TYPE
		{
			ENTRY_INT = 0x0,
			ENTRY_FIXED_STRING = 0x1,
			ENTRY_FLOAT = 0x1
		};

		enum SORT_ON_FIELD
		{
			SOF_ALPHABETICALLY = 0x0,
			SOF_DAMAGE = 0x1,
			SOF_ROF = 0x2,
			SOF_RANGE = 0x3,
			SOF_ACCURARY = 0x4,
			SOF_VALUE = 0x5,
			SOF_WEIGHT = 0x6
		};

		struct StackEntry
		{
			PipboyObject* linkedObject;							// 00
			const InventoryInterface::Handle inventoryHandle;	// 08
		};
		static_assert(sizeof(StackEntry) == 0x10);

		struct ItemEntry
		{
			void*  stackEntries; // 00 - BSTList<PipboyInventoryData::StackEntry*>
		};
		static_assert(sizeof(ItemEntry) == 0x8);

		// override
		virtual BSEventNotifyControl ProcessEvent(const PipboyValueChangedEvent& a_event, BSTEventSource<PipboyValueChangedEvent>* a_source);  // 01

		// add
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryListEvent::Event& a_event, BSTEventSource<BGSInventoryListEvent::Event>* a_source);								// 02
		virtual BSEventNotifyControl ProcessEvent(const ActorEquipManagerEvent::Event& a_event, BSTEventSource<ActorEquipManagerEvent::Event>* a_source);							// 03
		virtual BSEventNotifyControl ProcessEvent(const ActorValueEvents::ActorValueChangedEvent& a_event, BSTEventSource<ActorValueEvents::ActorValueChangedEvent>* a_source);		// 04
		virtual BSEventNotifyControl ProcessEvent(const PerkValueEvents::PerkEntryUpdatedEvent& a_event, BSTEventSource<PerkValueEvents::PerkEntryUpdatedEvent>* a_source);			// 05
		virtual BSEventNotifyControl ProcessEvent(const PerkValueEvents::PerkValueChangedEvent& a_event, BSTEventSource<PerkValueEvents::PerkValueChangedEvent>* a_source);			// 06
		virtual BSEventNotifyControl ProcessEvent(const InventoryInterface::FavoriteChangedEvent& a_event, BSTEventSource<InventoryInterface::FavoriteChangedEvent>* a_source);		// 07
		virtual BSEventNotifyControl ProcessEvent(const HolotapeStateChanged::Event& a_event, BSTEventSource<HolotapeStateChanged::Event>* a_source);								// 08
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryItemEvent::Event& a_event, BSTEventSource<BGSInventoryItemEvent::Event>* a_source);								// 09
		virtual BSEventNotifyControl ProcessEvent(const FavoriteMgr_Events::ComponentFavoriteEvent& a_event, BSTEventSource<FavoriteMgr_Events::ComponentFavoriteEvent>* a_source); // 0A
		virtual BSEventNotifyControl ProcessEvent(const PlayerDifficultySettingChanged::Event& a_event, BSTEventSource<PlayerDifficultySettingChanged::Event>* a_source);			// 0B

		virtual void Populate(bool a_arg1);		// 0C
		virtual void DoClearData();				// 0D
		virtual void DoClearSink();				// 0E

		void RepopulateItemCardsOnSection(ENUM_FORM_ID itemTypeID)
		{
			using func_t = decltype(&PipboyInventoryData::RepopulateItemCardsOnSection);
			static REL::Relocation<func_t> func{ REL::ID(2225279) };
			return func(this, itemTypeID);
		}

		// members
		PipboyObject* inventoryObject;											// E8
		BSTHashMap<std::uint32_t, PipboyInventoryData::ItemEntry> itemEntries;	// F0
		BSTHashMap<const BGSComponent*, PipboyObject*> invComponents;			// 120
		BSTArray<PipboyObject*> sortedItems;									// 150
		BSTSet<ENUM_FORM_ID> queuedRepopulateCategories;						// 168
	};
	static_assert(sizeof(PipboyInventoryData) == 0x198);
}
