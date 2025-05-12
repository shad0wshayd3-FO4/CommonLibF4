#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSTransform :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSTransform };
		static constexpr auto VTABLE{ VTABLE::BGSTransform };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kTRNS };

		struct TransformData
		{
		public:
			// members
			NiPoint3 position;  // 00
			NiPoint3 rotation;  // 0C
			float    scale;     // 18
			float    minZoom;   // 1C
			float    maxZoom;   // 20
		};
		static_assert(sizeof(TransformData) == 0x24);

		// members
		TransformData data;  // 20
	};
	static_assert(sizeof(BGSTransform) == 0x48);
}
