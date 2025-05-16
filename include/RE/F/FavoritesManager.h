#pragma once

#include "RE/B/BSInputEventSingleUser.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"
#include "RE/N/NiPointer.h"
#include "RE/B/BSTArray.h"
#include "RE/Q/QuickContainerStateEvent.h"

namespace RE
{
	class QueuedFile;

	namespace BGSInventoryListEvent
	{
		struct Event;
	}

	namespace FavoriteMgr_Events
	{
		struct ComponentFavoriteEvent;
	}

	namespace InventoryInterface
	{
		struct FavoriteChangedEvent;
	}

	class __declspec(novtable) FavoritesManager :
		public BSInputEventSingleUser,                                     // 000
		public BSTEventSink<BGSInventoryListEvent::Event>,                 // 020
		public BSTEventSink<InventoryInterface::FavoriteChangedEvent>,     // 028
		public BSTSingletonSDM<FavoritesManager>,                          // 030
		public BSTEventSource<FavoriteMgr_Events::ComponentFavoriteEvent>  // 038
	{
	public:
		static constexpr auto RTTI{ RTTI::FavoritesManager };
		static constexpr auto VTABLE{ VTABLE::FavoritesManager };

		[[nodiscard]] static FavoritesManager* GetSingleton()
		{
			static REL::Relocation<FavoritesManager**> singleton{ REL::ID(2694399) };
			return *singleton;
		}

		[[nodiscard]] bool IsComponentFavorite(const TESBoundObject* a_component)
		{
			using func_t = decltype(&FavoritesManager::IsComponentFavorite);
			static REL::Relocation<func_t> func{ REL::ID(2248752) };
			return func(this, a_component);
		}

		[[nodiscard]] bool UseQuickkeyItem(std::uint32_t a_quickkeyIndex)
		{
			using func_t = decltype(&FavoritesManager::UseQuickkeyItem);
			static REL::Relocation<func_t> func{ REL::ID(2248744) };
			return func(this, a_quickkeyIndex);
		}

		// members
		TESBoundObject*                                  storedFavTypes[12];         // 090
		NiPointer<QueuedFile>                            bufferedFavGeometries[12];  // 0F0
		BSTSet<const BGSConstructibleObject*>            favoriteMods;               // 150
		BSTHashMap<const TESBoundObject*, std::uint32_t> favoritedComponents;        // 180
		BSTSmallArray<std::int32_t, 12>                  weaponLoadedAmmo;           // 1B0
		BSTValueEventSink<QuickContainerStateEvent>      quickContainerMode;         // 1F0
		bool                                             allowStimpakUse;            // 2C8
	};
	static_assert(sizeof(FavoritesManager) == 0x2D0);
}
