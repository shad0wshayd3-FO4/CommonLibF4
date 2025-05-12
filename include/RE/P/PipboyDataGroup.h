#pragma once

namespace RE
{
	class PipboyDataGroup :
		public BSTEventSource<PipboyValueChangedEvent>  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyDataGroup };
		static constexpr auto VTABLE{ VTABLE::PipboyDataGroup };

		virtual ~PipboyDataGroup() = default;  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const PipboyValueChangedEvent& a_event, BSTEventSource<PipboyValueChangedEvent>* a_source);  // 01

		// add
		virtual void Populate(bool a_arg1) = 0;  // 02
		virtual void DoClearData() = 0;          // 03
		virtual void DoClearSink() = 0;          // 04

		// members
		REX::W32::CRITICAL_SECTION pipboyDataMutex;  // 60
		PipboyThrottleManager*     throttleManager;  // 88
		PipboyValue*               rootValue;        // 90
	};
	static_assert(sizeof(PipboyDataGroup) == 0x98);
}
