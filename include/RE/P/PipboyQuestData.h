#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/P/PipboyDataGroup.h"

namespace RE
{
	namespace PlayerCharacterQuestEvent
	{
		class Event;
	}

	namespace TESQuestEvent
	{
		class Event;
	}

	class __declspec(novtable) PipboyQuestData :
		public PipboyDataGroup,                                 // 00
		public BSTEventSink<PlayerCharacterQuestEvent::Event>,  // 89
		public BSTEventSink<TESQuestEvent::Event>               // A0
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyQuestData };
		static constexpr auto VTABLE{ VTABLE::PipboyQuestData };

		virtual ~PipboyQuestData();

		virtual BSEventNotifyControl ProcessEvent(const PlayerCharacterQuestEvent::Event& a_event, BSTEventSource<PlayerCharacterQuestEvent::Event>* a_source);  // 01
		virtual BSEventNotifyControl ProcessEvent(const TESQuestEvent::Event& a_event, BSTEventSource<TESQuestEvent::Event>* a_source);                          // 02

		virtual void Populate(bool a_arg1) override;  // 03
		virtual void DoClearData() override;          // 04
		virtual void DoClearSink() override;          // 05

		// members
		std::uint32_t sortIndex;             // A8
		PipboyArray*  questArray;            // B0
		void*         objectivesByQuest[6];  // B8 - BSTHashMap<BSTTuple<TESQuest*, std::uint64_t>, BSTArray<BGSInstancedQuestObjective>*>
	};
	static_assert(sizeof(PipboyQuestData) == 0xE8);
}
