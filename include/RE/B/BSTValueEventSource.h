#pragma once

namespace RE
{
	template <class T>
	class BSTValueEventSource :
		public BSTEventSink<BSTValueRequestEvent<T>>  // 00
	{
	public:
		using event_type = BSTValueRequestEvent<T>;

		// override (BSTEventSink<BSTValueRequestEvent<T>>)
		BSEventNotifyControl ProcessEvent(const event_type& a_event, BSTEventSource<event_type>*) override  // 01
		{
			BSAutoLock l{ dataLock };
			T          event;
			event.optionalValue = optionalValue;
			a_event.valueEventSink.ProcessEvent(event, nullptr);
		}

		// members
		BSTOptional<typename T::value_type> optionalValue;  // ??
		BSSpinLock                          dataLock;       // ??
	};
}
