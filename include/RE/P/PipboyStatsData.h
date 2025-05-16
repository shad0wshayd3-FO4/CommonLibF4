#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/P/PipboyDataGroup.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	struct ConditionBoyEvent;

	namespace ActorItemEquipped
	{
		struct Event;
	}

	namespace ActorValueEvents
	{
		struct ActorValueChangedEvent;
	}

	namespace BGSInventoryItemEvent
	{
		struct Event;
	}

	namespace BGSInventoryListEvent
	{
		struct Event;
	}

	namespace PlayerActiveEffectChanged
	{
		struct Event;
	}

	class __declspec(novtable) PipboyStatsData :
		public PipboyDataGroup,                                         // 00
		public BSTEventSink<ActorValueEvents::ActorValueChangedEvent>,  // 98
		public BSTEventSink<BGSInventoryListEvent::Event>,              // A0
		public BSTEventSink<PlayerActiveEffectChanged::Event>,          // A8
		public BSTEventSink<ConditionBoyEvent>,                         // B0
		public BSTEventSink<ActorItemEquipped::Event>,                  // B8
		public BSTEventSink<BGSInventoryItemEvent::Event>               // C0
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyStatsData };
		static constexpr auto VTABLE{ VTABLE::PipboyStatsData };

		virtual ~PipboyStatsData() = default;

		virtual BSEventNotifyControl ProcessEvent(const ActorValueEvents::ActorValueChangedEvent& a_event, BSTEventSource<ActorValueEvents::ActorValueChangedEvent>* a_source);  // 01
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryListEvent::Event& a_event, BSTEventSource<BGSInventoryListEvent::Event>* a_source);                          // 02
		virtual BSEventNotifyControl ProcessEvent(const PlayerActiveEffectChanged::Event& a_event, BSTEventSource<PlayerActiveEffectChanged::Event>* a_source);                  // 03
		virtual BSEventNotifyControl ProcessEvent(const ConditionBoyEvent& a_event, BSTEventSource<ConditionBoyEvent>* a_source);                                                // 04
		virtual BSEventNotifyControl ProcessEvent(const ActorItemEquipped::Event& a_event, BSTEventSource<ActorItemEquipped::Event>* a_source);                                  // 05
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryItemEvent::Event& a_event, BSTEventSource<BGSInventoryItemEvent::Event>* a_source);                          // 06

		// override
		virtual void Populate(bool a_arg1) override;  // 07
		virtual void DoClearData() override;          // 08
		virtual void DoClearSink() override;          // 09

		// members
		PipboyObject*                                            playerStatsObject;       // C8
		PipboyArray*                                             activeEffectsArray;      // D0
		BSTHashMap<MagicItem*, PipboyObject*>                    activeEffectsMap;        // D8
		BSTHashMap<BSTSmartPointer<ActiveEffect>, PipboyObject*> activeEffectEntriesMap;  // 108
	};
	static_assert(sizeof(PipboyStatsData) == 0x138);
}
