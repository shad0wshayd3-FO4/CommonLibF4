#pragma once

namespace RE
{
	enum class MENU_RENDER_CONTEXT : std::int32_t
	{
		kMenuDelete = 0x0,
		kPreDisplay = 0x1,
		kRenderScreenspace = 0x2,
		kRenderCopyQuads = 0x3,
		kRenderImagespace = 0x4,
		kEnsureDisplayMenuCalled = 0x5,
		kPostDisplay = 0x6
	};
}
