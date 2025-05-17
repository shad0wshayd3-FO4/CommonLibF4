#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/C/ContainerObject.h"

namespace RE
{
	class __declspec(novtable) TESContainer :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESContainer };
		static constexpr auto VTABLE{ VTABLE::TESContainer };

		void CopyObjectList(const std::vector<ContainerObject*>& a_copiedData)
		{
			const auto oldData = containerObjects;

			const auto newSize = a_copiedData.size();
			const auto newData = calloc<ContainerObject*>(newSize);
			std::ranges::copy(a_copiedData, newData);

			numContainerObjects = static_cast<std::uint32_t>(newSize);
			containerObjects = newData;

			free(oldData);
		}

		void ForEachContainerObject(std::function<bool(ContainerObject&)> a_fn) const
		{
			for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
				auto entry = containerObjects[i];
				if (entry) {
					if (!a_fn(*entry)) {
						break;
					}
				}
			}
		}

		bool AddObject(TESBoundObject* a_object, std::int32_t a_count, TESForm* a_owner)
		{
			bool added = false;
			for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
				if (const auto entry = containerObjects[i]; entry && entry->obj == a_object) {
					entry->count += a_count;
					added = true;
					break;
				}
			}
			if (!added) {
				std::vector<ContainerObject*> copiedData{ containerObjects, containerObjects + numContainerObjects };
				const auto                    newObj = new ContainerObject(a_object, a_count, a_owner);
				copiedData.push_back(newObj);
				CopyObjectList(copiedData);
				return true;
			}
			return added;
		}

		bool AddObjectsToContainer(std::map<TESBoundObject*, std::int32_t>& a_objects, TESForm* a_owner)
		{
			for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
				if (const auto entry = containerObjects[i]; entry && entry->obj) {
					if (auto it = a_objects.find(entry->obj); it != a_objects.end()) {
						entry->count += it->second;
						a_objects.erase(it);
					}
				}
			}
			if (!a_objects.empty()) {
				std::vector<ContainerObject*> copiedData{ containerObjects, containerObjects + numContainerObjects };
				for (auto& [object, count] : a_objects) {
					const auto newObj = new ContainerObject(object, count, a_owner);
					copiedData.push_back(newObj);
				}
				CopyObjectList(copiedData);
			}
			return true;
		}

		// members
		ContainerObject** containerObjects;     // 08
		std::uint32_t     numContainerObjects;  // 10
	};
	static_assert(sizeof(TESContainer) == 0x18);
}
