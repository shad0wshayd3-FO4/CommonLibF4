#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSCameraPath :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSCameraPath };
		static constexpr auto VTABLE{ VTABLE::BGSCameraPath };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCPTH };

		// members
		TESCondition                 conditions;  // 20
		BSSimpleList<BGSCameraShot*> shots;       // 28
		PATH_DATA                    data;        // 38
		NiFormArray*                 childPaths;  // 40
		BGSCameraPath*               parentPath;  // 48
		BGSCameraPath*               prevPath;    // 50
	};
	static_assert(sizeof(BGSCameraPath) == 0x58);
}
