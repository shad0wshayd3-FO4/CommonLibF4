#pragma once

#include "RE/Bethesda/PipboyArray.h"
#include "RE/Bethesda/PipboyDataGroup.h"

namespace RE
{
	class __declspec(novtable) PipboyLogData :
		public PipboyDataGroup,                    // 00
		public BSTEventSink<TESTrackedStatsEvent>  // 98
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyLogData };
		static constexpr auto VTABLE{ VTABLE::PipboyLogData };

		virtual ~PipboyLogData() = default;  // 00

		virtual BSEventNotifyControl ProcessEvent(const TESTrackedStatsEvent& a_event, BSTEventSource<TESTrackedStatsEvent>* a_source);  // 01

		virtual void Populate(bool a_arg1) override;  // 02
		virtual void DoClearData() override;          // 03
		virtual void DoClearSink() override;          // 04

		// members
		PipboyArray*                             statTypeArray;  // A0
		BSTHashMap<BSFixedString, PipboyObject*> statMap;        // A8
	};
	static_assert(sizeof(PipboyLogData) == 0xD8);
}
