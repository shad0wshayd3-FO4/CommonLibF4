#pragma once

#include "RE/B/BSTSingleton.h"

namespace RE
{
	namespace CellAttachDetachEventSource
	{
		struct CellAttachDetachEventSourceSingleton :
			public BSTSingletonImplicit<CellAttachDetachEventSourceSingleton>
		{
		public:
			[[nodiscard]] static CellAttachDetachEventSourceSingleton& GetSingleton()
			{
				using func_t = decltype(&CellAttachDetachEventSourceSingleton::GetSingleton);
				static REL::Relocation<func_t> func{ REL::ID(862142) };
				return func();
			}

			// members
			BSTEventSource<CellAttachDetachEvent> source;  // 00
		};
		static_assert(sizeof(CellAttachDetachEventSourceSingleton) == 0x58);
	}
}
