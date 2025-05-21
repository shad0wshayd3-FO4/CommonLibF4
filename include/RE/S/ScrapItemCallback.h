#pragma once

#include "RE/E/ExamineConfirmMenu.h"

namespace RE
{
	class __declspec(novtable) ScrapItemCallback :
		public ExamineConfirmMenu::ICallback  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::__ScrapItemCallback };
		static constexpr auto VTABLE{ VTABLE::__ScrapItemCallback };

		ScrapItemCallback(ExamineMenu* a_thisMenu, std::uint32_t a_itemIndex) :
			ExamineConfirmMenu::ICallback(a_thisMenu),
			itemIndex(a_itemIndex)
		{
			REX::EMPLACE_VTABLE(this);
		}

		virtual ~ScrapItemCallback() = default;  // 00

		// override
		virtual void OnAccept() override;  // 01

		F4_HEAP_REDEFINE_NEW(ScrapItemCallback);

		// members
		std::uint32_t itemIndex;  // 10
	};
	static_assert(sizeof(ScrapItemCallback) == 0x18);
}
