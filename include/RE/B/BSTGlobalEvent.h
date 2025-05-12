#pragma once

namespace RE
{
	class BSTGlobalEvent :
		public BSTSingletonSDM<BSTGlobalEvent>
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTGlobalEvent };
		static constexpr auto VTABLE{ RTTI::BSTGlobalEvent };

		struct KillSDMEvent
		{};
		static_assert(sizeof(KillSDMEvent) == 0x01);

		class KillSDMEventSource :
			public BSTEventSource<KillSDMEvent>
		{};
		static_assert(sizeof(KillSDMEventSource) == 0x58);

		template <class Event>
		class EventSource :
			public BSTEventSink<KillSDMEvent>,
			public BSTSingletonSDM<EventSource<Event>>,
			public BSTEventSource<Event>
		{
		public:
			EventSource(KillSDMEventSource* a_source)
			{
				a_source->RegisterSink(this);
			}

			virtual ~EventSource() = default;  // 00

			// override
			virtual BSEventNotifyControl ProcessEvent([[maybe_unused]] const KillSDMEvent& a_event, BSTEventSource<KillSDMEvent>* a_source) override  // 01
			{
				a_source->UnregisterSink(this);
				delete this;

				return BSEventNotifyControl::kContinue;
			}
		};
		static_assert(sizeof(EventSource<void*>) == 0x68);

		virtual ~BSTGlobalEvent();  // 00

		[[nodiscard]] static BSTGlobalEvent* GetSingleton()
		{
			static REL::Relocation<BSTGlobalEvent**> singleton{ REL::ID(2688814) };
			return *singleton;
		}

		// members
		KillSDMEventSource eventSourceSDMKiller;  // 10
	};
	static_assert(sizeof(BSTGlobalEvent) == 0x68);
}
