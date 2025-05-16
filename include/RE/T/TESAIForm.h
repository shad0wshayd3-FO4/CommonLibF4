#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/A/AIDATA_GAME.h"
#include "RE/P/PackageList.h"

namespace RE
{
	class __declspec(novtable) TESAIForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESAIForm };
		static constexpr auto VTABLE{ VTABLE::TESAIForm };

		// members
		AIDATA_GAME aiData;      // 08
		PackageList aiPackList;  // 18
	};
	static_assert(sizeof(TESAIForm) == 0x28);
}
