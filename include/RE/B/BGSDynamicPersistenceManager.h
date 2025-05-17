#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/N/NiPointer.h"
#include "RE/B/BSSpinLock.h"

namespace RE
{
	class QueuedPromoteReferencesTask;

	class BGSDynamicPersistenceManager :
		public BSTSingletonExplicit<BGSDynamicPersistenceManager>
	{
	public:
		[[nodiscard]] static BGSDynamicPersistenceManager* GetSingleton()
		{
			static REL::Relocation<BGSDynamicPersistenceManager**> singleton{ ID::BGSDynamicPersistenceManager::Singleton };
			return *singleton;
		}

		bool PromoteReference(TESObjectREFR* a_refr, TESForm* a_owner)
		{
			using func_t = decltype(&BGSDynamicPersistenceManager::PromoteReference);
			static REL::Relocation<func_t> func{ ID::BGSDynamicPersistenceManager::PromoteReference };
			return func(this, a_refr, a_owner);
		}

		bool DemoteReference(TESObjectREFR* a_refr, TESForm* a_owner, bool a_allowActors = false)
		{
			using func_t = decltype(&BGSDynamicPersistenceManager::DemoteReference);
			static REL::Relocation<func_t> func{ ID::BGSDynamicPersistenceManager::DemoteReference };
			return func(this, a_refr, a_owner, a_allowActors);
		}

		// members
		BSTArray<NiPointer<QueuedPromoteReferencesTask>> taskArray;      // 00
		BSSpinLock                                       taskArrayLock;  // 18
		volatile std::int32_t                            pauseCount;     // 20
	};
	static_assert(sizeof(BGSDynamicPersistenceManager) == 0x28);
}
