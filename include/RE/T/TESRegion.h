#pragma once

#include "RE/B/BSSimpleList.h"
#include "RE/T/TESForm.h"
#include "RE/N/NiColor.h"

namespace RE
{
	class TESRegionDataList;
	class TESRegionPointList;

	class __declspec(novtable) TESRegion :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESRegion };
		static constexpr auto VTABLE{ VTABLE::TESRegion };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kREGN };

		// add
		virtual bool Validate();  // 49

		// members
		TESRegionDataList*                 dataList;             // 20
		BSSimpleList<TESRegionPointList*>* pointLists;           // 28
		TESWorldSpace*                     worldSpace;           // 30
		TESWeather*                        currentWeather;       // 38
		NiColor                            emittanceColor;       // 40
		float                              lodDistanceModifier;  // 4C
		float                              occlusionAccuracy;    // 50
	};
	static_assert(sizeof(TESRegion) == 0x58);
}
