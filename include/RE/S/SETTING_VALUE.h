#pragma once

namespace RE
{
	union SETTING_VALUE
	{
		std::int8_t   c;
		bool          b;
		float         f;
		std::uint8_t  h;
		std::int32_t  i;
		char* s;
		std::uint32_t u;
		std::uint32_t r;
		std::uint32_t a;
	};
}
