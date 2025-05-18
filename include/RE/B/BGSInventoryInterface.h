#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BGSInventoryItem;

	namespace InventoryInterface
	{
		class CountChangedEvent;
		class FavoriteChangedEvent;
	}

	class BGSInventoryInterface :
		BSTSingletonSDM<BGSInventoryInterface>,                   // 00
		BSTEventSource<InventoryInterface::CountChangedEvent>,    // 08
		BSTEventSource<InventoryInterface::FavoriteChangedEvent>  // 60
	{
	public:
		class Agent
		{
		public:
			// members
			std::uint32_t   handleID;   // 0
			ObjectRefHandle itemOwner;  // 4
			std::uint16_t   listIndex;  // 8
			std::uint16_t   refCount;   // A
		};
		static_assert(sizeof(Agent) == 0xC);

		[[nodiscard]] static BGSInventoryInterface* GetSingleton()
		{
			static REL::Relocation<BGSInventoryInterface**> singleton{ ID::BGSInventoryInterface::Singleton };
			return *singleton;
		}

		[[nodiscard]] const BGSInventoryItem* RequestInventoryItem(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::RequestInventoryItem);
			static REL::Relocation<func_t> func{ ID::BGSInventoryInterface::RequestInventoryItem };
			return func(this, a_handleID);
		}

		[[nodiscard]] bool ForceMergeStacks(const std::uint32_t& a_handleID)
		{
			using func_t = decltype(&BGSInventoryInterface::ForceMergeStacks);
			static REL::Relocation<func_t> func{ ID::BGSInventoryInterface::ForceMergeStacks };
			return func(this, a_handleID);
		}

		// members
		BSTArray<Agent> agentArray;  // B8
	};
	static_assert(sizeof(BGSInventoryInterface) == 0xD0);
}
