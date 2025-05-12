#pragma once

namespace RE
{
	class __declspec(novtable) TESReactionForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESReactionForm };
		static constexpr auto VTABLE{ VTABLE::TESReactionForm };

		// members
		BSSimpleList<GROUP_REACTION*> reactionList;   // 08
		std::int8_t                   groupFormType;  // 18
	};
	static_assert(sizeof(TESReactionForm) == 0x20);
}
