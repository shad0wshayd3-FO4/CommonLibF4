#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/C/CellAttachDetachEvent.h"

namespace RE
{
	namespace CellAttachDetachEventSource
	{
		class CellAttachDetachEventSourceSingleton :
			public BSTSingletonImplicit<CellAttachDetachEventSourceSingleton>
		{
		public:
			[[nodiscard]] static CellAttachDetachEventSourceSingleton& GetSingleton()
			{
				using func_t = decltype(&CellAttachDetachEventSourceSingleton::GetSingleton);
				static REL::Relocation<func_t> func{ ID::CellAttachDetachEvent::GetEventSource };
				return func();
			}

			// members
			BSTEventSource<CellAttachDetachEvent> source;  // 00
		};
		static_assert(sizeof(CellAttachDetachEventSourceSingleton) == 0x58);
	}
}
