#pragma once

namespace RE
{
	class hknpContactSolverType
	{
	public:
		enum class Enum
		{
			kStream = 0x0,
			kMX = 0x1,
			kTotal = 0x2,
		};
	};
	static_assert(std::is_empty_v<hknpContactSolverType>);
}
