#pragma once

#include "RE/N/NiPointer.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class NiUpdateData;

	struct CELLJobs
	{
		struct AnimatedRefJobData
		{
		public:
			// members
			NiPointer<NiAVObject> p3d;                    // 00
			ObjectRefHandle       ref;                    // 08
			float                 time;                   // 0C
			std::uint32_t         uiFlags;                // 10
			bool                  allowTransformUpdates;  // 14
		};
		static_assert(sizeof(AnimatedRefJobData) == 0x18);

		struct TransUpdateFunctor
		{
		public:
			// members
			const AnimatedRefJobData* data;        // 00
			NiUpdateData*             updateData;  // 08
		};
		static_assert(sizeof(TransUpdateFunctor) == 0x10);
	};
}
