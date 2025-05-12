#pragma once

namespace RE
{
	namespace BSAudioUtil
	{
		inline std::uint16_t ClampFadeTimeSeconds(float a_seconds)
		{
			auto result = a_seconds * 1000;
			return (result > 0xFFFF) ? 0xFFFF : static_cast<std::uint16_t>(a_seconds);
		}
	}
}
