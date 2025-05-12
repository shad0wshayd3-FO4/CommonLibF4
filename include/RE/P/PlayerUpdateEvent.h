#pragma once

namespace RE
{
	struct PlayerUpdateEvent
	{
	public:
	};
	static_assert(std::is_empty_v<PlayerUpdateEvent>);
}
