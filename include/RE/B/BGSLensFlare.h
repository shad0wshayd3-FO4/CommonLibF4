#pragma once

#include "RE/T/TESForm.h"
#include "RE/B/BSLensFlareRenderData.h"

namespace RE
{
	class __declspec(novtable) BGSLensFlare :
		public TESForm,               // 00
		public BSLensFlareRenderData  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSLensFlare };
		static constexpr auto VTABLE{ VTABLE::BGSLensFlare };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLENS };
	};
	static_assert(sizeof(BGSLensFlare) == 0x50);
}
