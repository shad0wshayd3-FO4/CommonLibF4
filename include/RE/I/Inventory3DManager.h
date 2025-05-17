#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSInputEventUser.h"
#include "RE/N/NiPointer.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiQuaternion.h"
#include "RE/B/BGSInventoryItem.h"

namespace RE
{
	class ExtraDataList;
	class LoadedInventoryModel;

	namespace nsInventory3DManager
	{
		class NewInventoryMenuItemLoadTask;
	}

	class __declspec(novtable) Inventory3DManager :
		public BSInputEventUser  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::Inventory3DManager };
		static constexpr auto VTABLE{ VTABLE::Inventory3DManager };

		void Begin3D()
		{
			using func_t = decltype(&Inventory3DManager::Begin3D);
			static REL::Relocation<func_t> func{ ID::Inventory3DManager::Begin3D };
			return func(this);
		}

		void ClearModel()
		{
			using func_t = decltype(&Inventory3DManager::ClearModel);
			static REL::Relocation<func_t> func{ ID::Inventory3DManager::ClearModel };
			return func(this);
		}

		void DisableRendering(const BSFixedString& a_userID)
		{
			using func_t = decltype(&Inventory3DManager::DisableRendering);
			static REL::Relocation<func_t> func{ ID::Inventory3DManager::DisableRendering };
			return func(this, a_userID);
		}

		void EnableRendering(const BSFixedString& a_userID)
		{
			using func_t = decltype(&Inventory3DManager::EnableRendering);
			static REL::Relocation<func_t> func{ ID::Inventory3DManager::EnableRendering };
			return func(this, a_userID);
		}

		void End3D()
		{
			using func_t = decltype(&Inventory3DManager::End3D);
			static REL::Relocation<func_t> func{ ID::Inventory3DManager::End3D };
			return func(this);
		}

		void SetModelScale(float a_scale)
		{
			using func_t = decltype(&Inventory3DManager::SetModelScale);
			static REL::Relocation<func_t> func{ ID::Inventory3DManager::SetModelScale };
			return func(this, a_scale);
		}

		void SetModelScreenPosition(const NiPoint3& a_position, bool a_screenCoords)
		{
			using func_t = decltype(&Inventory3DManager::SetModelScreenPosition);
			static REL::Relocation<func_t> func{ ID::Inventory3DManager::SetModelScreenPosition };
			return func(this, a_position, a_screenCoords);
		}

		// members
		bool                                                          useBoundForScale: 1;             // 010:0
		bool                                                          startedZoomThisFrame: 1;         // 010:1
		bool                                                          useStoredModelPosition: 1;       // 010:2
		bool                                                          rotating: 1;                     // 010:3
		bool                                                          modelPositionInScreenCoords: 1;  // 010:4
		bool                                                          centerOnBoundCenter: 1;          // 010:5
		NiPoint3                                                      modelPosition;                   // 014
		float                                                         modelScale;                      // 020
		BSTArray<LoadedInventoryModel>                                loadedModels;                    // 030
		NiPoint3                                                      initialPosition;                 // 048
		NiPoint3                                                      storedPostion;                   // 054
		NiMatrix3                                                     initialRotation;                 // 060
		NiQuaternion                                                  storedRotation;                  // 090
		NiPoint2                                                      previousInput;                   // 0A0
		NiPointer<nsInventory3DManager::NewInventoryMenuItemLoadTask> loadTask;                        // 0A8
		TESObjectREFR*                                                tempRef;                         // 0B0
		BSTSmartPointer<ExtraDataList>                                originalExtra;                   // 0B8
		BSFixedString                                                 str3DRendererName;               // 0C0
		BGSInventoryItem                                              queuedDisplayItem;               // 0C8
		std::uint32_t                                                 itemExtraIndex;                  // 0D8
		TESForm*                                                      itemBase;                        // 0E0
		std::int8_t                                                   disableInputUserCount;           // 0E8
		BSTSet<BSFixedString>                                         disableRendererUsers;            // 0F0
		float                                                         storedXRotation;                 // 120
		float                                                         zoomDirection;                   // 124
		float                                                         zoomProgress;                    // 128
		float                                                         minZoomModifier;                 // 12C
		float                                                         maxZoomModifier;                 // 130
		std::uint32_t                                                 hightlightedPart;                // 134
		bool                                                          queueShowItem;                   // 138
		bool                                                          mouseRotation;                   // 139
		bool                                                          prevUsesCursorFlag;              // 13A
		bool                                                          prevUpdateUsesCursorFlag;        // 13B
		bool                                                          addedLightsToScene;              // 13C
	};
	static_assert(sizeof(Inventory3DManager) == 0x140);
}
