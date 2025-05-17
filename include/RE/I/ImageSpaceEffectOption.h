#pragma once

#include "RE/I/ImageSpaceEffect.h"

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectOption :
		public ImageSpaceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectOption };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectOption };

		// members
		NiTPrimitiveArray<bool> effectOn;  // B0
	};
	static_assert(sizeof(ImageSpaceEffectOption) == 0xC8);
}
