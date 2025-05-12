#pragma once

namespace RE
{
	class BGSEquipIndex
	{
	public:
		~BGSEquipIndex() noexcept {}  // NOLINT(modernize-use-equals-default)

		// members
		std::uint32_t index;  // 0
	};
	static_assert(sizeof(BGSEquipIndex) == 0x4);
}
