#pragma once

#include "RE/G/GameMenuBase.h"

namespace RE
{
	class __declspec(novtable) CursorMenu :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::CursorMenu };
		static constexpr auto VTABLE{ VTABLE::CursorMenu };
		static constexpr auto MENU_NAME{ "CursorMenu"sv };

		// members
		std::unique_ptr<BSGFxShaderFXTarget> cursor;  // E0
	};
	static_assert(sizeof(CursorMenu) == 0xE8);
}
