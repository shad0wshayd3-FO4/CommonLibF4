#pragma once

namespace RE
{
	class Rumble
	{
	public:
		class AutoRumblePause
		{
		public:
		};
		static_assert(std::is_empty_v<AutoRumblePause>);
	};
	static_assert(std::is_empty_v<Rumble>);
}
