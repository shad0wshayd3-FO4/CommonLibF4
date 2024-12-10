#pragma once

#include "RE/Bethesda/PipboyDataGroup.h"

namespace RE
{
	class __declspec(novtable) PipboyWorkshopData :
		public PipboyDataGroup,
		public BSTEventSink<ActorValueEvents::ActorValueChangedEvent>,
		public BSTEventSink<Workshop::WorkshopModeEvent>
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyWorkshopData };
		static constexpr auto VTABLE{ VTABLE::PipboyStatusData };

		virtual ~PipboyWorkshopData() = default;

		virtual BSEventNotifyControl ProcessEvent(const ActorValueEvents::ActorValueChangedEvent& a_event, BSTEventSource<ActorValueEvents::ActorValueChangedEvent>* a_source);  // 01
		virtual BSEventNotifyControl ProcessEvent(const Workshop::WorkshopModeEvent& a_event, BSTEventSource<Workshop::WorkshopModeEvent>* a_source);                            // 02

		// override
		virtual void Populate(bool a_arg1) override;  // 03
		virtual void DoClearData() override;          // 04
		virtual void DoClearSink() override;          // 05

		// members
		PipboyArray*                               workshopArray;          // A8
		BSTHashMap<std::uint32_t, PipboyObject*>   workshopMap;            // B0
		BSTHashMap<BSFixedStringCS, std::int32_t>  ratingUpdateFunctions;  // E0
		BSTHashMap<BSFixedStringCS, std::uint32_t> getValueFunctions;      // 110
	};
	static_assert(sizeof(PipboyWorkshopData) == 0x140);
}
