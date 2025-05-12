#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/I/IClientVM.h"
#include "RE/I/IStackCallbackSaveInterface.h"

namespace RE
{
	class __declspec(novtable) GameVM :
		public BSScript::IClientVM,                           // 0000
		public BSScript::IStackCallbackSaveInterface,         // 0008
		public BSTEventSink<BSScript::StatsEvent>,            // 0010
		public BSTEventSink<InputEnableLayerDestroyedEvent>,  // 0018
		public BSTEventSink<PositionPlayerEvent>,             // 0020
		public BSTEventSink<TESFormDeleteEvent>,              // 0028
		public BSTEventSink<TESFormIDRemapEvent>,             // 0030
		public BSTEventSink<TESInitScriptEvent>,              // 0037
		public BSTEventSink<TESResolveNPCTemplatesEvent>,     // 0040
		public BSTEventSink<TESUniqueIDChangeEvent>,          // 0048
		public BSTSingletonSDM<GameVM>,                       // 0050
		public BSTEventSource<GameScript::StatsEvent>         // 0058
	{
	public:
		static constexpr auto RTTI{ RTTI::GameVM };
		static constexpr auto VTABLE{ VTABLE::GameVM };

		[[nodiscard]] static GameVM* GetSingleton()
		{
			static REL::Relocation<GameVM**> singleton{ REL::ID(2689134) };
			return *singleton;
		}

		[[nodiscard]] BSTSmartPointer<BSScript::IVirtualMachine> GetVM() const noexcept { return impl; }

		bool QueuePostRenderCall(const BSTSmartPointer<GameScript::DelayFunctor>& a_functor)
		{
			using func_t = decltype(&GameVM::QueuePostRenderCall);
			static REL::Relocation<func_t> func{ REL::ID(2251314) };
			return func(this, a_functor);
		}

		void RegisterForAllGameEvents()
		{
			using func_t = decltype(&GameVM::RegisterForAllGameEvents);
			static REL::Relocation<func_t> func{ REL::ID(2251353) };
			return func(this);
		}

		void SendEventToObjectAndRelated(
			std::size_t                                                                   a_object,
			const BSFixedString&                                                          a_eventName,
			const BSTThreadScrapFunction<bool(BSScrapArray<BSScript::Variable>&)>&        a_args,
			const BSTThreadScrapFunction<bool(const BSTSmartPointer<BSScript::Object>&)>& a_filter,
			const BSTSmartPointer<BSScript::IStackCallbackFunctor>&                       a_callback)
		{
			using func_t = decltype(&GameVM::SendEventToObjectAndRelated);
			static REL::Relocation<func_t> func{ REL::ID(367992) };
			return func(this, a_object, a_eventName, a_args, a_filter, a_callback);
		}

		// members
		BSTSmartPointer<BSScript::IVirtualMachine>                          impl;                           // 00B0
		BSScript::IVMSaveLoadInterface*                                     saveLoadInterface;              // 00B8
		BSScript::IVMDebugInterface*                                        debugInterface;                 // 00C0
		BSScript::SimpleAllocMemoryPagePolicy                               memoryPagePolicy;               // 00C8
		BSScript::CompiledScriptLoader                                      scriptLoader;                   // 00F8
		GameScript::Logger                                                  logger;                         // 0130
		GameScript::HandlePolicy                                            handlePolicy;                   // 01E0
		GameScript::ObjectBindPolicy                                        objectBindPolicy;               // 0288
		BSTSmartPointer<BSScript::IStore>                                   scriptStore;                    // 0360
		GameScript::FragmentSystem                                          fragmentSystem;                 // 0368
		GameScript::Profiler                                                profiler;                       // 04F0
		GameScript::SavePatcher                                             savePatcher;                    // 05F0
		BSSpinLock                                                          freezeLock;                     // 05F8
		bool                                                                frozen;                         // 0600
		BSSpinLock                                                          vmTimeLock;                     // 0604
		std::uint32_t                                                       currentTime;                    // 060C
		std::uint32_t                                                       currentMenuModeTime;            // 0610
		std::uint32_t                                                       currentGameTime;                // 0614
		bool                                                                updateHasBeenRun;               // 0618
		bool                                                                saveLoad;                       // 0619
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>   renderSafeFunctorPool1;         // 0620
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>  renderSafeFunctorQueue1;        // 2638
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>   renderSafeFunctorPool2;         // 2660
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>  renderSafeFunctorQueue2;        // 4678
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>   postRenderFunctorPool1;         // 46A0
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>  postRenderFunctorQueue1;        // 66B8
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>   postRenderFunctorPool2;         // 66E0
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>  postRenderFunctorQueue2;        // 86F8
		BSSpinLock                                                          renderSafeQueueLock;            // 8720
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* renderSafeQueueToReadFrom;      // 8728
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* renderSafeQueueToWriteTo;       // 8730
		BSSpinLock                                                          postRenderQueueLock;            // 8738
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* postRenderQueueToReadFrom;      // 8740
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* postRenderQueueToWriteTo;       // 8748
		BSSpinLock                                                          userLogLock;                    // 8750
		BSTHashMap<BSFixedString, BSScript::ErrorLogger*>                   userLogs;                       // 8758
		BSSpinLock                                                          statsWarningLock;               // 8788
		std::uint32_t                                                       initialSuspendOverageTime;      // 8790
		std::uint32_t                                                       initialRunningOverageTime;      // 8794
		std::uint32_t                                                       initialStackMemoryOverageTime;  // 8798
		std::uint32_t                                                       lastWarningTime;                // 879C
		std::uint32_t                                                       overflowFlags;                  // 87A0
	};
	static_assert(sizeof(GameVM) == 0x87A8);
}
