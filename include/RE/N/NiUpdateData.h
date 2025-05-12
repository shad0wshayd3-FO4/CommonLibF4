#pragma once

namespace RE
{
	class NiCamera;

	class NiUpdateData
	{
	public:
		// members
		float         time{ 0.0f };        // 00
		NiCamera*     camera{ nullptr };   // 08
		std::uint32_t flags{ 0 };          // 10
		std::uint32_t renderObjects{ 0 };  // 14
		std::uint32_t fadeNodeDepth{ 0 };  // 18
	};
	static_assert(sizeof(NiUpdateData) == 0x20);
}
