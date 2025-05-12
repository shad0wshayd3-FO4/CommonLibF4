#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class __declspec(novtable) ExtraBendableSplineParams :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraBendableSplineParams };
		static constexpr auto VTABLE{ VTABLE::ExtraBendableSplineParams };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kBendableSplineParams };

		struct ParamData_Untilv13
		{
			// members
			float    slack;        // 00
			float    thickness;    // 04
			NiPoint3 halfExtents;  // 08
		};
		static_assert(sizeof(ParamData_Untilv13) == 0x14);

		struct ParamData : public ParamData_Untilv13
		{
			// members
			bool endDetached;  // 14
		};
		static_assert(sizeof(ParamData) == 0x18);

		// members
		ParamData data;  // 18
	};
	static_assert(sizeof(ExtraBendableSplineParams) == 0x30);
}
