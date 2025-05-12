#pragma once

namespace RE
{
	class alignas(0x10) NiPoint3A :
		public NiPoint3
	{
	public:
		static const NiPoint3A ZERO;

		using NiPoint3::NiPoint3;
	};
	static_assert(sizeof(NiPoint3A) == 0x10);
}
