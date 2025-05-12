#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class BGSInventoryList :
		public BSTEventSource<BGSInventoryListEvent::Event>  // 00
	{
	public:
		BGSInventoryList(const TESContainer* a_container, ObjectRefHandle a_owner)
		{
			auto native_handle = a_owner.get_handle();
			ctor(a_container, &native_handle);
		}

		F4_HEAP_REDEFINE_NEW(BGSInventoryList)

		[[nodiscard]] static bool StandardObjectCompareCallbackFn(TESBoundObject* a_lhs, TESBoundObject* a_rhs)
		{
			return a_lhs == a_rhs;
		}

		void FindAndWriteStackDataForItem(
			TESBoundObject*                            a_object,
			BGSInventoryItem::StackDataCompareFunctor& a_compareFunc,
			BGSInventoryItem::StackDataWriteFunctor&   a_writeFunc,
			bool (*a_objCompFn)(TESBoundObject*, TESBoundObject*) = StandardObjectCompareCallbackFn,
			bool a_alwaysContinue = false)
		{
			using func_t = decltype(&BGSInventoryList::FindAndWriteStackDataForItem);
			static REL::Relocation<func_t> func{ REL::ID(2194179) };
			return func(this, a_object, a_compareFunc, a_writeFunc, a_objCompFn, a_alwaysContinue);
		}

		// DOES NOT LOCK
		void ForEachStack(
			std::function<bool(BGSInventoryItem&)>                           a_filter,   // return true to iterate stacks
			std::function<bool(BGSInventoryItem&, BGSInventoryItem::Stack&)> a_continue  // return false to return control from function
		)
		{
			for (auto& elem : data) {
				if (a_filter(elem)) {
					for (auto stack = elem.stackData.get(); stack; stack = stack->nextStack.get()) {
						if (!a_continue(elem, *stack)) {
							return;
						}
					}
				}
			}
		}

		void BuildFromContainer(const TESContainer* a_container)
		{
			using func_t = decltype(&BGSInventoryList::BuildFromContainer);
			static REL::Relocation<func_t> func{ REL::ID(2194158) };
			return func(this, a_container);
		}

		// members
		BSTArray<BGSInventoryItem> data;          // 58
		float                      cachedWeight;  // 70
		ObjectRefHandle            owner;         // 74
		BSReadWriteLock            rwLock;        // 78

	private:
		void ctor(const TESContainer* a_container, std::uint32_t* a_owner)
		{
			using func_t = decltype(&BGSInventoryList::ctor);
			static REL::Relocation<func_t> func{ REL::ID(2194153) };
			return func(this, a_container, a_owner);
		}
	};
	static_assert(sizeof(BGSInventoryList) == 0x80);
}
