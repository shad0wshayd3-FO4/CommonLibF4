#pragma once

#include "RE/Bethesda/BGSInventoryInterface.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTList.h"
#include "RE/Bethesda/PipboyDataGroup.h"

namespace RE
{
	class PipboyDataGroup;

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
		enum ENTRY_TYPE
		{
			ENTRY_INT = 0,
			ENTRY_FIXED_STRING,
			ENTRY_FLOAT
		};

		enum SORT_ON_FIELD
		{
			SOF_ALPHABETICALLY = 0,
			SOF_DAMAGE,
			SOF_ROF,
			SOF_RANGE,
			SOF_ACCURARY,
			SOF_VALUE,
			SOF_WEIGHT
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

		// members
		PipboyObject* inventoryObject;											// E8
		BSTHashMap<std::uint32_t, PipboyInventoryData::ItemEntry> itemEntries;	// F0
		BSTHashMap<const BGSComponent*, PipboyObject*> invComponents;			// 120
		BSTArray<PipboyObject*> sortedItems;									// 150
		BSTSet<ENUM_FORM_ID> queuedRepopulateCategories;						// 168
	};
}
