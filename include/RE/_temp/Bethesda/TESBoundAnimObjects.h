#pragma once

namespace RE
{
	namespace TESSoundDefs
	{
		struct RepeaterData
		{
		public:
			// members
			float minDelay;   // 0
			float maxDelay;   // 4
			bool  stackable;  // 8
		};
		static_assert(sizeof(RepeaterData) == 0xC);
	}
}
