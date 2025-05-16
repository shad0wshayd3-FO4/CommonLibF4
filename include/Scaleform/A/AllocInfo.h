#pragma once

namespace Scaleform
{
	struct AllocInfo
	{
	public:
		~AllocInfo() noexcept {}

		// members
		std::uint32_t statID;
	};
	static_assert(sizeof(AllocInfo) == 0x4);
}
