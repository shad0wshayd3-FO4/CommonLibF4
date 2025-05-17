#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class NiUpdateData;

	namespace CELLJobs
	{
		class AnimatedRefJobData
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

		class TransUpdateFunctor
		{
		public:
			// members
			const AnimatedRefJobData* data;        // 00
			NiUpdateData*             updateData;  // 08
		};
		static_assert(sizeof(TransUpdateFunctor) == 0x10);
	};
}
