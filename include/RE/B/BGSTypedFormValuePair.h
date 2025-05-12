#pragma once

namespace RE
{
	namespace BGSTypedFormValuePair
	{
		union SharedVal
		{
			std::uint32_t i;
			float         f;
		};
		static_assert(sizeof(SharedVal) == 0x4);
	}
}
