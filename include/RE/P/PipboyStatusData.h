#pragma once

namespace RE
{
	class __declspec(novtable) PipboyStatusData :
		public PipboyDataGroup,                               // 00
		public BSTEventSink<PlayerLifeStateChanged::Event>,   // 98
		public BSTEventSink<PlayerInDialogueChanged::Event>,  // A0
		public BSTEventSink<MenuOpenCloseEvent>,              // A8
		public BSTEventSink<BGSInventoryListEvent::Event>,    // B0
		public BSTEventSink<LoadingStatusChanged::Event>,     // B8
		public BSTEventSink<VATSEvents::ModeChange>,          // C0
		public BSTEventSink<UserEventEnabledEvent>            // C8
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyStatusData };
		static constexpr auto VTABLE{ VTABLE::PipboyStatusData };

		virtual ~PipboyStatusData() = default;

		virtual BSEventNotifyControl ProcessEvent(const PlayerLifeStateChanged::Event& a_event, BSTEventSource<PlayerLifeStateChanged::Event>* a_source);    // 01
		virtual BSEventNotifyControl ProcessEvent(const PlayerInDialogueChanged::Event& a_event, BSTEventSource<PlayerInDialogueChanged::Event>* a_source);  // 02
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent& a_event, BSTEventSource<MenuOpenCloseEvent>* a_source);                          // 03
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryListEvent::Event& a_event, BSTEventSource<BGSInventoryListEvent::Event>* a_source);      // 04
		virtual BSEventNotifyControl ProcessEvent(const LoadingStatusChanged::Event& a_event, BSTEventSource<LoadingStatusChanged::Event>* a_source);        // 05
		virtual BSEventNotifyControl ProcessEvent(const VATSEvents::ModeChange& a_event, BSTEventSource<VATSEvents::ModeChange>* a_source);                  // 06
		virtual BSEventNotifyControl ProcessEvent(const UserEventEnabledEvent& a_event, BSTEventSource<UserEventEnabledEvent>* a_source);                    // 07

		// override
		virtual void Populate(bool a_arg1) override;  // 08
		virtual void DoClearData() override;          // 09
		virtual void DoClearSink() override;          // 0A

		// members
		PipboyObject* statusObject;
		PipboyArray* pipboyEffectColorArray;
	};
	static_assert(sizeof(PipboyStatusData) == 0xE0);
}
