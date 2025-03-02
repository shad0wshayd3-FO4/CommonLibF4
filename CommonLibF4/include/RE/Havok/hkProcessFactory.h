#pragma once

#include "RE/Havok/hkArray.h"
#include "RE/Havok/hkReferencedObject.h"

namespace RE
{
	class hkProcess;
	class hkProcessContext;

	class __declspec(novtable) hkProcessFactory :
		public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hkProcessFactory };
		inline static constexpr auto VTABLE{ VTABLE::hkProcessFactory };

		inline static hkProcessFactory* GetSingleton()
		{
			static REL::Relocation<hkProcessFactory*> singleton{ REL::ID(2702978) };
			return singleton.get();
		}

		hkProcess* CreateProcess(const char* a_name, hkArray<hkProcessContext*>& a_contexts)
		{
			using func_t = decltype(&hkProcessFactory::CreateProcess);
			static REL::Relocation<func_t> func{ REL::ID(2263377) };
			return func(this, a_name, a_contexts);
		}
	};
}
