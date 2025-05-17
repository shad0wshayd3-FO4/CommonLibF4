#pragma once

#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class AnimationDataCleanupEvent;
	class AnimationDataSetupEvent;
	class BGSSynchronizedAnimationInstance;

	class __declspec(novtable) BGSSynchronizedAnimationManager :
		public BSTEventSink<AnimationDataSetupEvent>,            // 00
		public BSTEventSink<AnimationDataCleanupEvent>,          // 08
		public BSTSingletonSDM<BGSSynchronizedAnimationManager>  // 10
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSynchronizedAnimationManager };
		static constexpr auto VTABLE{ VTABLE::BGSSynchronizedAnimationManager };

		virtual ~BGSSynchronizedAnimationManager();  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const AnimationDataSetupEvent&, BSTEventSource<AnimationDataSetupEvent>*) override;      // 01
		virtual BSEventNotifyControl ProcessEvent(const AnimationDataCleanupEvent&, BSTEventSource<AnimationDataCleanupEvent>*) override;  // 02

		[[nodiscard]] static BGSSynchronizedAnimationManager* GetSingleton()
		{
			static REL::Relocation<BGSSynchronizedAnimationManager**> singleton{ ID::BGSSynchronizedAnimationManager::Singleton };
			return *singleton;
		}

		[[nodiscard]] bool IsReferenceInSynchronizedScene(ObjectRefHandle a_ref)
		{
			using func_t = decltype(&BGSSynchronizedAnimationManager::IsReferenceInSynchronizedScene);
			static REL::Relocation<func_t> func{ ID::BGSSynchronizedAnimationManager::IsReferenceInSynchronizedScene };
			return func(this, a_ref);
		}

		// members
		BSTArray<BSTSmartPointer<BGSSynchronizedAnimationInstance>> currentSynchAnims;  // 18
		BSReadWriteLock                                             synchAnimsLock;     // 30
		std::int32_t                                                atomicSyncLock;     // 38
		BSSpinLock                                                  internalsLock;      // 3C
	};
	static_assert(sizeof(BGSSynchronizedAnimationManager) == 0x48);
}
