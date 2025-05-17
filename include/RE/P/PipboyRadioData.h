#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/P/PipboyDataGroup.h"

namespace RE
{
	namespace RadioManager
	{
		class PipboyFrequencyDetectionEvent;
		class PipboyRadioTuningEvent;
	}

	class __declspec(novtable) PipboyRadioData :
		public PipboyDataGroup,                                            // 00
		public BSTEventSink<RadioManager::PipboyFrequencyDetectionEvent>,  // 98
		public BSTEventSink<RadioManager::PipboyRadioTuningEvent>          // A0
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyRadioData };
		static constexpr auto VTABLE{ VTABLE::PipboyRadioData };

		virtual ~PipboyRadioData() = default;

		virtual BSEventNotifyControl ProcessEvent(const RadioManager::PipboyFrequencyDetectionEvent& a_event, BSTEventSource<RadioManager::PipboyFrequencyDetectionEvent>* a_source);  // 01
		virtual BSEventNotifyControl ProcessEvent(const RadioManager::PipboyRadioTuningEvent& a_event, BSTEventSource<RadioManager::PipboyRadioTuningEvent>* a_source);                // 02

		virtual void Populate(bool a_arg1) override;  // 03
		virtual void DoClearData() override;          // 04
		virtual void DoClearSink() override;          // 05

		// members
		PipboyArray* radioStations;  // A8
	};
	static_assert(sizeof(PipboyRadioData) == 0xB0);
}
