#pragma once

#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BGSCreatedObjectManager :
		public BSTSingletonSDM<BGSCreatedObjectManager>  // 00
	{
	public:
		template <class T>
		class BSTCreatedObjectSmartPointerPolicy
		{
		public:
			static void Acquire(stl::not_null<T*> a_ptr)
			{
				const auto manager = BGSCreatedObjectManager::GetSingleton();
				if (manager &&
					a_ptr->IsCreated() &&
					a_ptr->IsAlchemyItem()) {
					manager->IncrementRef(static_cast<AlchemyItem*>(a_ptr));
				}
			}

			static void Release(stl::not_null<T*> a_ptr)
			{
				const auto manager = BGSCreatedObjectManager::GetSingleton();
				if (manager &&
					a_ptr->IsCreated() &&
					a_ptr->IsAlchemyItem()) {
					manager->DecrementRef(static_cast<AlchemyItem*>(a_ptr));
				}
			}
		};

		class CreatedMagicItemData
		{
		public:
			// members
			MagicItem*    createdItem;  // 00
			std::uint32_t count;        // 08
		};
		static_assert(sizeof(CreatedMagicItemData) == 0x10);

		[[nodiscard]] static BGSCreatedObjectManager* GetSingleton()
		{
			static REL::Relocation<BGSCreatedObjectManager**> singleton{ ID::BGSCreatedObjectManager::Singleton };
			return *singleton;
		}

		void DecrementRef(AlchemyItem* a_alchItem)
		{
			using func_t = decltype(&BGSCreatedObjectManager::DecrementRef);
			static REL::Relocation<func_t> func{ ID::BGSCreatedObjectManager::DecrementRef };
			return func(this, a_alchItem);
		}

		void IncrementRef(AlchemyItem* a_alchItem)
		{
			using func_t = decltype(&BGSCreatedObjectManager::IncrementRef);
			static REL::Relocation<func_t> func{ ID::BGSCreatedObjectManager::IncrementRef };
			return func(this, a_alchItem);
		}

		// members
		BSTArray<CreatedMagicItemData>                  weaponEnchantments;      // 08
		BSTArray<CreatedMagicItemData>                  armorEnchantments;       // 20
		BSTHashMap<std::uint32_t, CreatedMagicItemData> potions;                 // 38
		BSTHashMap<std::uint32_t, CreatedMagicItemData> poisons;                 // 68
		BSTSet<MagicItem*>                              queuedDeleteMagicItems;  // 98
		BSSpinLock                                      dataLock;                // C8
	};
	static_assert(sizeof(BGSCreatedObjectManager) == 0xD0);

	extern template class BGSCreatedObjectManager::BSTCreatedObjectSmartPointerPolicy<AlchemyItem>;
	extern template class BGSCreatedObjectManager::BSTCreatedObjectSmartPointerPolicy<TESForm>;

	template <class T>
	using CreatedObjPtr = BSTSmartPointer<T, BGSCreatedObjectManager::BSTCreatedObjectSmartPointerPolicy>;
}
