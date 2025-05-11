#pragma once

#include "RE/Scaleform/Kernel/SF_Stats.h"

namespace RE::Scaleform
{
	enum StatGroup : std::int32_t
	{
		kStatGroup_Renderer = 1 << 6,
		kStatGroup_RenderGen = 2 << 6,
		kStatGroup_GFxFontCache = 3 << 6,
		kStatGroup_GFxMovieData = 4 << 6,
		kStatGroup_GFxMovieView = 5 << 6,
		kStatGroup_GFxRenderCache = 6 << 6,
		kStatGroup_GFxPlayer = 7 << 6,
		kStatGroup_GFxIME = 8 << 6,
		kStatGroup_GFxAmp = 9 << 6,

		// General Memory
		kStat_Image_Mem = kStat_Default_Mem + 1,
		kStat_String_Mem,

		kStat_Debug_Mem,
		kStat_DebugHUD_Mem,
		kStat_DebugTracker_Mem,
		kStat_StatBag_Mem,
	};

	enum HeapId : std::int32_t
	{
		kHeapId_Global = kHeapId_Default,
		kHeapId_MovieDef,
		kHeapId_MovieView,
		kHeapId_MovieData,
		kHeapId_Images,
		kHeapId_OtherHeaps,
		kHeapId_HUDHeaps,
		kHeapId_Video,
	};
}
