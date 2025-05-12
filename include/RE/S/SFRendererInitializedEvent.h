#pragma once

namespace RE
{
	struct SFRendererInitializedEvent
	{
	public:
	};
	static_assert(std::is_empty_v<SFRendererInitializedEvent>);
}
