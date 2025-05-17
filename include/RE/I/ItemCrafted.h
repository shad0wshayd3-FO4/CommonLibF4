#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	namespace ItemCrafted
	{
		class Event
		{
		public:
			// members
			const TESFurniture*           workbench;
			const BGSConstructibleObject* recipe;
		};

		inline void NotifyOfItemCrafted(const TESFurniture* a_workbench, const BGSConstructibleObject* a_recipe)
		{
			using func_t = decltype(&NotifyOfItemCrafted);
			static REL::Relocation<func_t> func{ ID::ItemCrafted::NotifyOfItemCrafted };
			return func(a_workbench, a_recipe);
		}

		inline void RegisterSink(BSTEventSink<Event>* a_sink)
		{
			using func_t = decltype(&RegisterSink);
			static REL::Relocation<func_t> func{ ID::ItemCrafted::RegisterSink };
			return func(a_sink);
		}

		inline void UnregisterSink(BSTEventSink<Event>* a_sink)
		{
			using func_t = decltype(&UnregisterSink);
			static REL::Relocation<func_t> func{ ID::ItemCrafted::UnregisterSink };
			return func(a_sink);
		}
	}
}
