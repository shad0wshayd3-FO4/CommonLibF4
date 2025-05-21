#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	class __declspec(novtable) alignas(0x08) NiRefObject
	{
	public:
		static constexpr auto RTTI{ RTTI::NiRefObject };
		static constexpr auto VTABLE{ VTABLE::NiRefObject };

		NiRefObject()
		{
			REX::EMPLACE_VTABLE(this);
			static REL::Relocation<std::uint32_t*> objects{ ID::NiRefObject::Objects };
			REX::TAtomicRef                        myObjects{ *objects };
			++myObjects;
		}

		virtual ~NiRefObject()  // 00
		{
			static REL::Relocation<std::uint32_t*> objects{ ID::NiRefObject::Objects };
			REX::TAtomicRef                        myObjects{ *objects };
			--myObjects;
		}

		// add
		virtual void DeleteThis() { delete this; }  // 01

		F4_HEAP_REDEFINE_NEW(NiRefObject);

		std::uint32_t DecRefCount()
		{
			REX::TAtomicRef myRefCount{ refCount };
			const auto      newRefCount = --myRefCount;
			if (newRefCount == 0) {
				DeleteThis();
			}
			return newRefCount;
		}

		std::uint32_t IncRefCount()
		{
			REX::TAtomicRef myRefCount{ refCount };
			return ++myRefCount;
		}

		// members
		std::uint32_t refCount{ 0 };  // 08
	};
	static_assert(sizeof(NiRefObject) == 0x10);
}
