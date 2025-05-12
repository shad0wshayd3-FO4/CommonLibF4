#pragma once

namespace RE
{
	struct __declspec(novtable) BIPED_MODEL
	{
	public:
		// members
		std::uint32_t bipedObjectSlots;  // 0
	};
	static_assert(sizeof(BIPED_MODEL) == 0x4);
}
