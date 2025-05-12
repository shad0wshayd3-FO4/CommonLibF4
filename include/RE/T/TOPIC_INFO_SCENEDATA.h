#pragma once

namespace RE
{
	struct TOPIC_INFO_SCENEDATA
	{
		BGSScene*     scene;  // 00
		std::uint32_t phase;  // 08
	};
	static_assert(sizeof(TOPIC_INFO_SCENEDATA) == 0x10);
}
