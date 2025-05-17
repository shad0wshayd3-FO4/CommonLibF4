#pragma once

#include "RE/E/ExamineConfirmMenu.h"

namespace RE
{
	class __declspec(novtable) ModConfirmCallback :
		public ExamineConfirmMenu::ICallback  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::__ModConfirmCallback };
		static constexpr auto VTABLE{ VTABLE::__ModConfirmCallback };

		ModConfirmCallback(ExamineMenu* a_thisMenu) :
			ExamineConfirmMenu::ICallback(a_thisMenu)
		{
			stl::emplace_vtable(this);
		}

		virtual ~ModConfirmCallback() = default;  // 00

		// override
		virtual void OnAccept() override;  // 01

		F4_HEAP_REDEFINE_NEW(ModConfirmCallback);
	};
	static_assert(sizeof(ModConfirmCallback) == 0x10);
}
