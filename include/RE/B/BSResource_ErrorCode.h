#pragma once

namespace RE::BSResource
{
	enum class ErrorCode : std::uint32_t
	{
		kNone = 0x0,
		kNotExist = 0x1,
		kInvalidPath = 0x2,
		kFileError = 0x3,
		kInvalidType = 0x4,
		kMemoryError = 0x5,
		kBusy = 0x6,
		kInvalidParam = 0x7,
		kUnsupported = 0x8
	};
}
