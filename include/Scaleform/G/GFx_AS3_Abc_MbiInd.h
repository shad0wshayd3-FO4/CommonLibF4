#pragma once

namespace Scaleform::GFx::AS3::Abc
{
	class MbiInd
	{
	public:
		// members
		std::int32_t ind;  // 00
	};
	static_assert(sizeof(MbiInd) == 0x04);
}
