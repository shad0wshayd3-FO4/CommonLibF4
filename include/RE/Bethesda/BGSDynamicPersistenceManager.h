#pragma once

#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class QueuedPromoteReferencesTask;

	class BGSDynamicPersistenceManager :
		public BSTSingletonExplicit<BGSDynamicPersistenceManager>
	{
	public:
		[[nodiscard]] static BGSDynamicPersistenceManager* GetSingleton()
		{
			static REL::Relocation<BGSDynamicPersistenceManager**> singleton{ REL::ID(109630) };
			return *singleton;
		}

		bool PromoteReference(TESObjectREFR* a_refr, TESForm* a_owner)
		{
			using func_t = decltype(&BGSDynamicPersistenceManager::PromoteReference);
			static REL::Relocation<func_t> func{ REL::ID(1300345) };
			return func(this, a_refr, a_owner);
		}

		bool DemoteReference(TESObjectREFR* a_refr, TESForm* a_owner, bool a_allowActors = false)
		{
			using func_t = decltype(&BGSDynamicPersistenceManager::DemoteReference);
			static REL::Relocation<func_t> func{ REL::ID(222813) };
			return func(this, a_refr, a_owner, a_allowActors);
		}

		// members
		BSTArray<NiPointer<QueuedPromoteReferencesTask>> taskArray;      // 00
		BSSpinLock                                       taskArrayLock;  // 18
		volatile std::int32_t                            pauseCount;     // 20
	};
	static_assert(sizeof(BGSDynamicPersistenceManager) == 0x28);
}
