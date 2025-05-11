#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTList.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/NetImmerse/NiPoint.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	namespace BSResource::Archive2
	{
		class StreamOpenedEvent;
	}

	class GridCellArray;
	class GridDistantArray;
	class ImageSpaceModifierInstance;
	class LoadedAreaBound;
	class NavMeshInfoMap;
	class NiAVObject;
	class NiFogProperty;
	class NiNode;
	class Sky;
	class TESNPC;
	class TESObjectCELL;
	class TESWorldSpace;

	struct bhkPickData;
	struct PositionPlayerEvent;

	class TES :
		public BSTEventSink<BSResource::Archive2::StreamOpenedEvent>,  // 000
		public BSTEventSink<PositionPlayerEvent>                       // 008
	{
	public:
		static constexpr auto RTTI{ RTTI::TES };
		static constexpr auto VTABLE{ VTABLE::TES };

		using TACCallbackFunc_t = void(TESObjectCELL*, void*, void*);

		struct ParticleObjectCache
		{
		public:
			// members
			NiPointer<NiAVObject>  model;   // 00
			NiPointer<NiAVObject>* clones;  // 08
			ParticleObjectCache*   next;    // 10
		};
		static_assert(sizeof(ParticleObjectCache) == 0x18);

		virtual ~TES();  // 00

		// override (BSTEventSink<BSResource::ArchiveStreamOpenedEvent>)
		BSEventNotifyControl ProcessEvent(const BSResource::Archive2::StreamOpenedEvent& a_event, BSTEventSource<BSResource::Archive2::StreamOpenedEvent>* a_eventSource) override;  // 01 - { return BSEventNotifyControl::kContinue; }

		// override (BSTEventSink<PositionPlayerEvent>)
		BSEventNotifyControl ProcessEvent(const PositionPlayerEvent& a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;  // 01

		[[nodiscard]] static TES* GetSingleton()
		{
			static REL::Relocation<TES**> singleton{ REL::ID(2698044) };
			return *singleton;
		}

		// members
		GridDistantArray*                                   gridDistant;                    // 010
		GridCellArray*                                      gridCells;                      // 018
		NiNode*                                             objRoot;                        // 020
		NiNode*                                             lodLandRoot;                    // 028
		NiNode*                                             objLODWaterRoot;                // 030
		NiDirectionalLight*                                 objLight;                       // 038
		NiFogProperty*                                      objFog;                         // 040
		std::int32_t                                        currentGridX;                   // 044
		std::int32_t                                        currentGridY;                   // 048
		std::int32_t                                        currentQueuedX;                 // 04C
		std::int32_t                                        currentQueuedY;                 // 050
		TESObjectCELL*                                      interiorCell;                   // 058
		TESObjectCELL**                                     interiorBuffer;                 // 060
		TESObjectCELL**                                     exteriorBuffer;                 // 068
		std::uint32_t                                       tempInteriorBufferSize;         // 070
		std::uint32_t                                       tempExteriorBufferSize;         // 074
		std::int32_t                                        saveGridX;                      // 078
		std::int32_t                                        saveGridY;                      // 07C
		TACCallbackFunc_t*                                  tacCallbackFunc;                // 080
		void*                                               tacCallbackData;                // 088
		TESRegion*                                          tacRegionFilter;                // 090
		Sky*                                                sky;                            // 098
		BSSimpleList<NiPointer<ImageSpaceModifierInstance>> activeImageSpaceModifiers;      // 0A0
		std::uint32_t                                       totalToLoad;                    // 0B0
		std::uint32_t                                       loaded;                         // 0B4
		std::uint64_t                                       cellCaptureStartTime;           // 0B8
		bool                                                disablePercentageUpdate;        // 0C0
		bool                                                showLANDborders;                // 0C1
		bool                                                fadeWhenLoading;                // 0C2
		bool                                                forceUpdateMultiBoundExterior;  // 0C3
		bool                                                collisionBoxes;                 // 0C4
		bool                                                runningCellTests;               // 0C5
		bool                                                runningCellTests2;              // 0C6
		bool                                                runningGraphicsTests;           // 0C7
		bool                                                runningCellListGraphicsTests;   // 0C8
		bool                                                runningSubmergedObjectTest;     // 0C9
		bool                                                allowUnusedPurge;               // 0CA
		float                                               cellDeltaX;                     // 0D0
		float                                               cellDeltaY;                     // 0D4
		TESWorldSpace*                                      worldSpace;                     // 0D8
		BSTArray<BSTTuple<TESActorBase*, std::uint16_t>>    deadCount;                      // 0E0
		NiPointer<QueuedFile>                               preloadedAddonNodes;            // 0F8
		NiPointer<NiTexture>                                bloodDecalPreload1;             // 100
		NiPointer<QueuedFile>                               preloadedForms;                 // 108
		NiPointer<QueuedFile>                               preloadedDefaultModels;         // 110
		TES::ParticleObjectCache*                           particleCacheHead;              // 118
		std::uint32_t                                       placeableWaterCount;            // 120
		NavMeshInfoMap*                                     navMeshInfoMap;                 // 128
		NiPointer<LoadedAreaBound>                          loadedAreaBound;                // 130
	};
	static_assert(sizeof(TES) == 0x138);
}
