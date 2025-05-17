#pragma once

#include "Scaleform/G/GFx_StatGroup.h"

namespace Scaleform::GFx
{
	enum StatFontCache
	{
		kStatFC_Default = kStatGroup_GFxFontCache,

		kStatFC_Mem,
		kStatFC_Batch_Mem,
		kStatFC_GlyphCache_Mem,
		kStatFC_Other_Mem
	};
}
