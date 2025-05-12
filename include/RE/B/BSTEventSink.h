#pragma once

namespace RE
{
	template <class>
	class BSTEventSource;

	template <class Event>
	class __declspec(novtable) BSTEventSink
	{
	public:
		virtual ~BSTEventSink() = default;  // 00

		// add
		virtual BSEventNotifyControl ProcessEvent(const Event& a_event, BSTEventSource<Event>* a_source) = 0;  // 01
	};
	static_assert(sizeof(BSTEventSink<void*>) == 0x8);
}
