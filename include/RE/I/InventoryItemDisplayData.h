#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/I/InventoryUserUIInterfaceEntry.h"
#include "Scaleform/G/GFx_Value.h"

namespace RE
{
	class InventoryItemDisplayData
	{
	public:
		InventoryItemDisplayData(
			const ObjectRefHandle                a_inventoryRef,
			const InventoryUserUIInterfaceEntry& a_entry)
		{
			ctor(a_inventoryRef, a_entry);
		}

		void PopulateFlashObject(Scaleform::GFx::Value& a_flashObject)
		{
			a_flashObject.SetMember("text"sv, itemName.c_str());
			a_flashObject.SetMember("count"sv, itemCount);
			a_flashObject.SetMember("equipState"sv, equipState);
			a_flashObject.SetMember("filterFlag"sv, filterFlag);
			a_flashObject.SetMember("isLegendary"sv, isLegendary);
			a_flashObject.SetMember("favorite"sv, isFavorite);
			a_flashObject.SetMember("taggedForSearch"sv, isTaggedForSearch);
			a_flashObject.SetMember("isBetterThanEquippedItem"sv, isBetterThanEquippedItem);
		}

		// members
		BSFixedStringCS itemName;                           // 00
		std::uint32_t   itemCount{ 0 };                     // 08
		std::uint32_t   equipState{ 0 };                    // 0C
		std::uint32_t   filterFlag{ 0 };                    // 10
		bool            isLegendary{ false };               // 14
		bool            isFavorite{ false };                // 15
		bool            isTaggedForSearch{ false };         // 16
		bool            isBetterThanEquippedItem{ false };  // 17

	private:
		InventoryItemDisplayData* ctor(
			const ObjectRefHandle                a_inventoryRef,
			const InventoryUserUIInterfaceEntry& a_entry)
		{
			using func_t = decltype(&InventoryItemDisplayData::ctor);
			static REL::Relocation<func_t> func{ ID::InventoryItemDisplayData::ctor };
			return func(this, a_inventoryRef, a_entry);
		}
	};
	static_assert(sizeof(InventoryItemDisplayData) == 0x18);
}
