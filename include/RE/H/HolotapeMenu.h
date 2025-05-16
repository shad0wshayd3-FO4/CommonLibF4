#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/G/GameMenuBase.h"
#include "RE/B/BSSoundHandle.h"

namespace RE
{
	class MenuOpenCloseEvent;

	class __declspec(novtable) HolotapeMenu :
		public GameMenuBase,                     // 00
		public BSTEventSink<MenuOpenCloseEvent>  // E0
	{
	public:
		static constexpr auto RTTI{ RTTI::HolotapeMenu };
		static constexpr auto VTABLE{ VTABLE::HolotapeMenu };
		static constexpr auto MENU_NAME{ "HolotapeMenu"sv };

		virtual ~HolotapeMenu();  // 00

		// override (GameMenuBase)
		virtual void Call(const Params&) override;                                     // 01
		virtual void MapCodeObjectFunctions() override;                                // 02
		virtual bool CanHandleWhenDisabled(const ButtonEvent* a_event) override;       // 0E
		virtual bool OnButtonEventRelease(const BSFixedString& a_eventName) override;  // 0F

		// add
		virtual void ProcessCancel() = 0;                // 14
		virtual void ProcessChatterImpl(const Params&);  // 15

		// override (BSInputEventUser)
		virtual bool ShouldHandleEvent(const InputEvent* a_event) override;       // 01
		virtual void OnThumbstickEvent(const ThumbstickEvent* a_event) override;  // 04

		// override (BSTEventSink)
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent& a_event, BSTEventSource<MenuOpenCloseEvent>* a_source) override;  // 01

		static void ShowHolotapeInPipboy(const BSFixedString& a_holotapePath)
		{
			using func_t = decltype(&HolotapeMenu::ShowHolotapeInPipboy);
			static REL::Relocation<func_t> func{ REL::ID(217953) };
			return func(a_holotapePath);
		}

		static void ShowHolotapeInTerminal(const BSFixedString& a_holotapePath)
		{
			using func_t = decltype(&HolotapeMenu::ShowHolotapeInTerminal);
			static REL::Relocation<func_t> func{ REL::ID(390509) };
			return func(a_holotapePath);
		}

		// members
		BSTArray<BSSoundHandle> registeredSounds;  // 0E8
		bool                    useOwnCursor;      // 100
		bool                    isMinigame;        // 101
	};
	static_assert(sizeof(HolotapeMenu) == 0x108);
}
