#pragma once

#include "RE/C/ContainerItemExtra.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	class ContainerObject
	{
	public:
		ContainerObject(TESBoundObject* a_obj, std::int32_t a_count) :
			count(a_count),
			obj(a_obj),
			itemExtra()
		{}

		ContainerObject(TESBoundObject* a_obj, std::int32_t a_count, TESForm* a_ownerForm) :
			count(a_count),
			obj(a_obj),
			itemExtra(new ContainerItemExtra(a_ownerForm))
		{}

		~ContainerObject() = default;

		F4_HEAP_REDEFINE_NEW(ContainerObject);

		// members
		std::int32_t        count;      // 00
		TESBoundObject*     obj;        // 08
		ContainerItemExtra* itemExtra;  // 10
	};
	static_assert(sizeof(ContainerObject) == 0x18);
}
