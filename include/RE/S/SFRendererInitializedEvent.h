#pragma once

namespace RE
{
	class SFRendererInitializedEvent
	{
	public:
	};
	static_assert(std::is_empty_v<SFRendererInitializedEvent>);
}
