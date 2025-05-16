#pragma once

namespace Scaleform::GFx
{
	class ResourceId
	{
	public:
		~ResourceId() noexcept {}

		std::uint32_t id;  // 00
	};
	static_assert(sizeof(ResourceId) == 0x4);
}
