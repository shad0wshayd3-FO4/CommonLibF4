#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class TerminalHacked
	{
	public:
		class Event
		{
		public:
			// members
			ObjectRefHandle terminal;  // 00
		};
		static_assert(sizeof(Event) == 0x04);

		[[nodiscard]] static BSTEventSource<TerminalHacked::Event>* GetEventSource()
		{
			using func_t = decltype(&TerminalHacked::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TerminalHacked::GetEventSource };
			return func();
		}
	};
	static_assert(std::is_empty_v<TerminalHacked>);
}
