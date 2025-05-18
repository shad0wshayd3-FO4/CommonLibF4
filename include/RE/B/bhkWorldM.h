#pragma once

#include "RE/B/bhkWorld.h"

namespace RE
{
	class __declspec(novtable) bhkWorldM :
		public bhkWorld  // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkWorldM };
		inline static constexpr auto VTABLE{ VTABLE::bhkWorldM };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::bhkWorldM };

		virtual ~bhkWorldM();  // 00

		// members
		hkVector4f worldTotalSize;
		hkVector4f borderSize;
		hkVector4f broadPhaseSize;
	};
	static_assert(sizeof(bhkWorldM) == 0x1B0);
}
