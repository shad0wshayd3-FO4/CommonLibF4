#pragma once

namespace RE
{
	enum class ENUM_COMPARISON_CONDITION : std::int32_t
	{
		kEqual = 0x0,
		kNotEqual = 0x1,
		kGreaterThan = 0x2,
		kGreaterThanEqual = 0x3,
		kLessThan = 0x4,
		kLessThanEqual = 0x5
	};
}
