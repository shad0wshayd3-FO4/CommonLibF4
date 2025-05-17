#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BGSEquipSlot;
	class BGSObjectInstance;
	class EquippedItem;

	namespace ActorEquipManagerEvent
	{
		struct Event;
	}

	class ActorEquipManager :
		public BSTSingletonSDM<ActorEquipManager>,            // 00
		public BSTEventSource<ActorEquipManagerEvent::Event>  // 08
	{
	public:
		[[nodiscard]] static ActorEquipManager* GetSingleton()
		{
			static REL::Relocation<ActorEquipManager**> singleton{ REL::ID(2690994) };
			return *singleton;
		}

		bool EquipObject(
			Actor*                   a_actor,
			const BGSObjectInstance& a_object,
			std::uint32_t            a_stackID,
			std::uint32_t            a_number,
			const BGSEquipSlot*      a_slot,
			bool                     a_queueEquip,
			bool                     a_forceEquip,
			bool                     a_playSounds,
			bool                     a_applyNow,
			bool                     a_locked)
		{
			using func_t = decltype(&ActorEquipManager::EquipObject);
			static REL::Relocation<func_t> func{ REL::ID(2231392) };
			return func(this, a_actor, a_object, a_stackID, a_number, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow, a_locked);
		}

		bool UnequipObject(
			Actor*                   a_actor,
			const BGSObjectInstance* a_object,
			std::uint32_t            a_number,
			const BGSEquipSlot*      a_slot,
			std::uint32_t            a_stackID,
			bool                     a_queueEquip,
			bool                     a_forceEquip,
			bool                     a_playSounds,
			bool                     a_applyNow,
			const BGSEquipSlot*      a_slotBeingReplaced)
		{
			using func_t = decltype(&ActorEquipManager::UnequipObject);
			static REL::Relocation<func_t> func{ REL::ID(2231395) };
			return func(this, a_actor, a_object, a_number, a_slot, a_stackID, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow, a_slotBeingReplaced);
		}

		void UnequipItem(Actor* a_actor, const EquippedItem* a_equippedItem, bool a_queueEquip)
		{
			using func_t = decltype(&ActorEquipManager::UnequipItem);
			static REL::Relocation<func_t> func{ REL::ID(2231399) };
			return func(this, a_actor, a_equippedItem, a_queueEquip);
		}
	};
	static_assert(sizeof(ActorEquipManager) == 0x60);
}
