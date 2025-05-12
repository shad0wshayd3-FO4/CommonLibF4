#pragma once

namespace RE
{
	template <class T>
	class BSTValueEventSink :
		public BSTEventSink<T>  // 00
	{
	public:
		struct BSTEventValueData
		{
		public:
			// members
			BSTOptional<typename T::value_type> optionalValue;  // 00
			bool                                eventReceived;  // ??
		};

		// override (BSTEventSink<T>)
		virtual BSEventNotifyControl ProcessEvent([[maybe_unused]] const T& a_event, BSTEventSource<T>*) override { return BSEventNotifyControl::kContinue; }  // 01

		// members
		BSTEventValueData eventDataStruct;  // 08
		BSSpinLock        dataLock;         // ??
	};
}
