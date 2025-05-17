#pragma once

namespace RE
{
	class PlayerUpdateEvent
	{
	public:
	};
	static_assert(std::is_empty_v<PlayerUpdateEvent>);
}
