#pragma once

#include "Scaleform/A/Array.h"
#include "Scaleform/G/GFx_StatMovieView.h"
#include "Scaleform/G/GFx_State.h"
#include "Scaleform/P/Ptr.h"
#include "Scaleform/R/Render_Point.h"
#include "Scaleform/R/Render_Rect.h"
#include "Scaleform/R/Render_TreeShape.h"
#include "Scaleform/S/StatBasicValues.h"

namespace Scaleform::GFx
{
	class CharacterHandle;
	class InteractiveObject;

	class alignas(0x10) FocusGroupDescr
	{
	public:
		enum
		{
			kTabableArray_Initialized = 0x1,
			kTabableArray_WithFocusEnabled = 0x2
		};

		// members
		Ptr<Render::TreeShape>                             focusRectNode;     // 00
		ArrayDH<Ptr<InteractiveObject>, kStatMV_Other_Mem> tabableArray;      // 08
		mutable void*                                      lastFocused;       // 28 - mutable WeakPtr<InteractiveObject>
		Ptr<CharacterHandle>                               modalClip;         // 30
		std::uint32_t                                      lastFocusKeyCode;  // 38
		alignas(0x8) Render::Rect<float> lastFocusedRect;                     // 40
		bool         focusRectShown;                                          // 50
		std::uint8_t tabableArrayStatus;                                      // 51
	};
	static_assert(sizeof(FocusGroupDescr) == 0x60);
}
