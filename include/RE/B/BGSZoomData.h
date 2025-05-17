#pragma once

#include "RE/N/NiPoint.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSZoomData :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSZoomData };
		static constexpr auto VTABLE{ VTABLE::BGSZoomData };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kZOOM };

		class Data
		{
		public:
			// members
			float         fovMult;       // 00
			std::uint32_t overlay;       // 04
			std::uint32_t isModFormID;   // 08
			NiPoint3      cameraOffset;  // 0C
		};
		static_assert(sizeof(Data) == 0x18);

		// members
		Data                   zoomData;  // 20
		TESImageSpaceModifier* isMod;     // 38
	};
	static_assert(sizeof(BGSZoomData) == 0x40);
}
