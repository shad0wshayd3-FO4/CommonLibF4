#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSStoryManagerTreeForm :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSStoryManagerTreeForm };
		static constexpr auto VTABLE{ VTABLE::BGSStoryManagerTreeForm };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNONE };

		// add
		virtual std::uint32_t                            QChildCount() const { return 0; }                                           // 4A
		virtual BGSStoryManagerTreeForm*                 GetChild([[maybe_unused]] std::uint32_t a_index) const { return nullptr; }  // 4B
		virtual TESCondition*                            QConditions() = 0;                                                          // 4C
		virtual BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) = 0;                   // 4D

		// members
		std::uint32_t lastVisitorID;  // 20
	};
	static_assert(sizeof(BGSStoryManagerTreeForm) == 0x28);
}
