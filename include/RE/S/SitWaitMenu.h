#pragma once

#include "RE/G/GameMenuBase.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class __declspec(novtable) SitWaitMenu :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::SitWaitMenu };
		static constexpr auto VTABLE{ VTABLE::SitWaitMenu };
		static constexpr auto MENU_NAME{ "SitWaitMenu"sv };

		virtual ~SitWaitMenu();  // 00

		// override (GameMenuBase)
		virtual void               Call(const Params&) override;                                                               // 01
		virtual void               MapCodeObjectFunctions() override;                                                          // 02
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                                              // 03
		virtual void               OnMenuStackChanged(const BSFixedString& a_topMenuName, bool a_passesTopMenuTest) override;  // 09

		static void OnEnterFurniture(ObjectRefHandle a_handle)
		{
			using func_t = decltype(&SitWaitMenu::OnEnterFurniture);
			static REL::Relocation<func_t> func{ ID::SitWaitMenu::OnEnterFurniture };
			return func(a_handle);
		}

		static void OnExitFurniture()
		{
			using func_t = decltype(&SitWaitMenu::OnExitFurniture);
			static REL::Relocation<func_t> func{ ID::SitWaitMenu::OnExitFurniture };
			return func();
		}

		// members
		BSTArray<BSFixedString> overridingMenus;  // E0
	};
	static_assert(sizeof(SitWaitMenu) == 0xF8);
}
