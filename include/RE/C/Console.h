#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/G/GameMenuBase.h"
#include "RE/R/Rumble.h"

namespace RE
{
	struct __declspec(novtable) Console :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::Console };
		static constexpr auto VTABLE{ VTABLE::Console };
		static constexpr auto MENU_NAME{ "Console"sv };

		static void ExecuteCommand(const char* a_command)
		{
			using func_t = decltype(&Console::ExecuteCommand);
			static REL::Relocation<func_t> func{ REL::ID(2248537) };
			return func(a_command);
		}

		[[nodiscard]] static decltype(auto) GetCurrentPickIndex()
		{
			static REL::Relocation<std::int32_t*> currentPickIndex{ REL::ID(2701382) };
			return *currentPickIndex;
		}

		[[nodiscard]] static decltype(auto) GetPickRef()
		{
			static REL::Relocation<ObjectRefHandle*> ref{ REL::ID(2701395) };
			return *ref;
		}

		[[nodiscard]] static decltype(auto) GetPickRefs()
		{
			static REL::Relocation<BSTArray<ObjectRefHandle>*> pickRefs{ REL::ID(2701391) };
			return *pickRefs;
		}

		[[nodiscard]] static ObjectRefHandle GetCurrentPickREFR()
		{
			const auto  idx = GetCurrentPickIndex();
			const auto& refs = GetPickRefs();
			return 0 <= idx && static_cast<std::size_t>(idx) < refs.size() ?
			           refs[static_cast<std::size_t>(idx)] :
			           ObjectRefHandle{};
		}

		void SetCurrentPickREFR(stl::not_null<ObjectRefHandle*> a_refr)
		{
			using func_t = decltype(&Console::SetCurrentPickREFR);
			static REL::Relocation<func_t> func{ REL::ID(2248551) };
			return func(this, a_refr);
		}

		// members
		Rumble::AutoRumblePause* rumbleLock;  // E0
		bool                     minimized;   // E8
	};
	static_assert(sizeof(Console) == 0xF0);
}
