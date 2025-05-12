#pragma once

namespace RE
{
	struct CELLJobs
	{
		struct AnimatedRefJobData
		{
		public:
			NiPointer<NiAVObject>                                         p3d;
			BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>> ref;
			float                                                         time;
			std::uint32_t                                                 uiFlags;
			bool                                                          allowTransformUpdates;
		};
		static_assert(sizeof(AnimatedRefJobData) == 0x18);

		struct TransUpdateFunctor
		{
		public:
			const CELLJobs::AnimatedRefJobData* data;
			NiUpdateData* updateData;
		};
		static_assert(sizeof(TransUpdateFunctor) == 0x10);
	};
}
