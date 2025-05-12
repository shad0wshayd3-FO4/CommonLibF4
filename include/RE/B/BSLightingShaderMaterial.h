#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"

namespace RE
{
	struct __declspec(novtable) BSLightingShaderMaterial :
		public BSLightingShaderMaterialBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSLightingShaderMaterial };
		static constexpr auto VTABLE{ VTABLE::BSLightingShaderMaterial };
	};
	static_assert(sizeof(BSLightingShaderMaterial) == 0xC0);
}
