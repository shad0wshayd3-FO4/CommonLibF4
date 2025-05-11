#pragma once

#include "RE/Bethesda/BGSSaveLoad.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTMessageQueue.h"
#include "RE/Bethesda/BSTTuple.h"

namespace RE
{
	class BSPackedTask;
	class NiCamera;
	class TESPageCache;

	struct PositionPlayerEvent;

	class BSPackedTaskQueue
	{
	public:
		// members
		BSTCommonScrapHeapMessageQueue<BSPackedTask> queue;  // 00
		void (*UnpackFunc_t)(const BSPackedTask&);           // 28
	};
	static_assert(sizeof(BSPackedTaskQueue) == 0x30);

	class Main :
		public BSTEventSink<PositionPlayerEvent>
	{
	public:
		virtual ~Main();  // 00

		[[nodiscard]] static Main* GetSingleton()
		{
			static REL::Relocation<Main**> singleton{ REL::ID(2698043) };
			return *singleton;
		}

		// override
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent& a_event, BSTEventSource<PositionPlayerEvent>* a_source) override;  // 01

		[[nodiscard]] static NiCamera* WorldRootCamera()
		{
			using func_t = decltype(&Main::WorldRootCamera);
			static REL::Relocation<func_t> func{ REL::ID(2228956) };
			return func();
		}

		[[nodiscard]] static bool QGameSystemsShouldUpdate()
		{
			static REL::Relocation<bool*> singleton{ REL::ID(2698031) };
			return *singleton;
		}

		[[nodiscard]] static bool QGameDataLoaded()
		{
			static REL::Relocation<bool*> singleton{ REL::ID(2698032) };
			return *singleton;
		}

		void SetCameraFOV(float a_fov)
		{
			using func_t = decltype(&Main::SetCameraFOV);
			static REL::Relocation<func_t> func{ REL::ID(2228973) };
			return func(this, a_fov);
		}

		// members
		BSTArray<BSTTuple<float, BSPointerHandle<Actor>>> sortedVisibleHighActors;      // 08
		std::uint32_t                                     localMapRenderDelay;          // 20
		bool                                              quitGame;                     // 24
		bool                                              resetGame;                    // 25
		bool                                              fullReset;                    // 26
		bool                                              gameActive;                   // 27
		bool                                              onIdle;                       // 28
		bool                                              reloadContent;                // 29
		bool                                              freezeTime;                   // 2A
		bool                                              freezeNextFrame;              // 2B
		REX::W32::HWND                                    hwnd;                         // 30
		void*                                             instance;                     // 38
		std::uint32_t                                     threadID;                     // 40
		ScrapHeap                                         packedTaskHeap;               // 48
		BSPackedTaskQueue                                 taskQueue;                    // D8
		ScrapHeap                                         secondaryPackedTaskHeap;      // 108
		BSPackedTaskQueue                                 secondaryTaskQueue;           // 198
		TESPageCache*                                     pageCache;                    // 1C8
		bool                                              inMenuMode;                   // 1D0
		bool                                              inDialog;                     // 1D1
		bool                                              renderingMenuBG;              // 1D2
		bool                                              signOutPending;               // 1D3
		BSSaveDataSystemUtilityImage                      saveDataBackgroundImages[3];  // 1D8
		BSSaveDataSystemUtilityImage                      saveDataIconImages[3];        // 220
	};
	static_assert(sizeof(Main) == 0x268);
}
