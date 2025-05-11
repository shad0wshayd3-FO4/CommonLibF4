#pragma once

#include "RE/Havok/hkBaseObject.h"

namespace RE
{
	class hkClass;

	class __declspec(novtable) hkReferencedObject :
		public hkBaseObject  // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hkReferencedObject };
		inline static constexpr auto VTABLE{ VTABLE::hkReferencedObject };

		hkReferencedObject()
		{
			stl::emplace_vtable(this);
		}

		// add
		virtual const hkClass* GetClassType() const { return nullptr; }             // 02
		virtual void           DeleteThisReferencedObject() const { delete this; }  // 03

		void AddReference()
		{
			using func_t = decltype(&hkReferencedObject::AddReference);
			static REL::Relocation<func_t> func{ REL::ID(2259213) };
			func(this);
		}

		void RemoveReference()
		{
			using func_t = decltype(&hkReferencedObject::RemoveReference);
			static REL::Relocation<func_t> func{ REL::ID(2195747) };
			func(this);
		}

		// members
		std::uint32_t memSizeAndRefCount{ static_cast<std::uint32_t>(-65535) };  // 08
	};
	static_assert(sizeof(hkReferencedObject) == 0x10);
}
