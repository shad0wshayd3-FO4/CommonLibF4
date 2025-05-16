#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/P/PipboyDataGroup.h"

namespace RE
{
	class PerkPointIncreaseEvent;
	struct PlayerUpdateEvent;

	namespace ActorEquipManagerEvent
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

	namespace HourPassed
	{
		struct Event;
	}

	namespace LevelIncrease
	{
		struct Event;
	}

	namespace PerkValueEvents
	{
		struct PerkEntryUpdatedEvent;
	}

	namespace PlayerActiveEffectChanged
	{
		struct Event;
	}

	namespace PlayerCharacterQuestEvent
	{
		struct Event;
	}

	namespace PlayerDifficultySettingChanged
	{
		struct Event;
	}

	namespace SPECIALMenuEvent
	{
		struct NameChangedEvent;
	}

	class __declspec(novtable) PipboyPlayerInfoData :
		public PipboyDataGroup,                                         // 00
		public BSTEventSink<ActorValueEvents::ActorValueChangedEvent>,  // 98
		public BSTEventSink<BGSInventoryListEvent::Event>,              // A0
		public BSTEventSink<ActorEquipManagerEvent::Event>,             // A8
		public BSTEventSink<LevelIncrease::Event>,                      // B0
		public BSTEventSink<PerkPointIncreaseEvent>,                    // B8
		public BSTEventSink<PerkValueEvents::PerkEntryUpdatedEvent>,    // C0
		public BSTEventSink<HourPassed::Event>,                         // C8
		public BSTEventSink<SPECIALMenuEvent::NameChangedEvent>,        // D0
		public BSTEventSink<PlayerUpdateEvent>,                         // D8
		public BSTEventSink<BGSInventoryItemEvent::Event>,              // E0
		public BSTEventSink<PlayerActiveEffectChanged::Event>,          // E8
		public BSTEventSink<PlayerCharacterQuestEvent::Event>,          // F0
		public BSTEventSink<PlayerDifficultySettingChanged::Event>      // F8
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyPlayerInfoData };
		static constexpr auto VTABLE{ VTABLE::PipboyPlayerInfoData };

		virtual ~PipboyPlayerInfoData() = default;

		virtual BSEventNotifyControl ProcessEvent(const ActorValueEvents::ActorValueChangedEvent& a_event, BSTEventSource<ActorValueEvents::ActorValueChangedEvent>* a_source);  // 01
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryListEvent::Event& a_event, BSTEventSource<BGSInventoryListEvent::Event>* a_source);                          // 02
		virtual BSEventNotifyControl ProcessEvent(const ActorEquipManagerEvent::Event& a_event, BSTEventSource<ActorEquipManagerEvent::Event>* a_source);                        // 03
		virtual BSEventNotifyControl ProcessEvent(const LevelIncrease::Event& a_event, BSTEventSource<LevelIncrease::Event>* a_source);                                          // 04
		virtual BSEventNotifyControl ProcessEvent(const PerkPointIncreaseEvent& a_event, BSTEventSource<PerkPointIncreaseEvent>* a_source);                                      // 05
		virtual BSEventNotifyControl ProcessEvent(const PerkValueEvents::PerkEntryUpdatedEvent& a_event, BSTEventSource<PerkValueEvents::PerkEntryUpdatedEvent>* a_source);      // 06
		virtual BSEventNotifyControl ProcessEvent(const HourPassed::Event& a_event, BSTEventSource<HourPassed::Event>* a_source);                                                // 07
		virtual BSEventNotifyControl ProcessEvent(const SPECIALMenuEvent::NameChangedEvent& a_event, BSTEventSource<SPECIALMenuEvent::NameChangedEvent>* a_source);              // 08
		virtual BSEventNotifyControl ProcessEvent(const PlayerUpdateEvent& a_event, BSTEventSource<PlayerUpdateEvent>* a_source);                                                // 09
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryItemEvent::Event& a_event, BSTEventSource<BGSInventoryItemEvent::Event>* a_source);                          // 0A
		virtual BSEventNotifyControl ProcessEvent(const PlayerActiveEffectChanged::Event& a_event, BSTEventSource<PlayerActiveEffectChanged::Event>* a_source);                  // 0B
		virtual BSEventNotifyControl ProcessEvent(const PlayerCharacterQuestEvent::Event& a_event, BSTEventSource<PlayerCharacterQuestEvent::Event>* a_source);                  // 0C
		virtual BSEventNotifyControl ProcessEvent(const PlayerDifficultySettingChanged::Event& a_event, BSTEventSource<PlayerDifficultySettingChanged::Event>* a_source);        // 0D

		// override
		virtual void Populate(bool a_arg1) override;  // 0E
		virtual void DoClearData() override;          // 0F
		virtual void DoClearSink() override;          // 10

		// members
		PipboyObject* playerInfoObject;
	};
	static_assert(sizeof(PipboyPlayerInfoData) == 0x108);
}
