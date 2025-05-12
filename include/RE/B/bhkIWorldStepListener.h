#pragma once

namespace RE
{
	class __declspec(novtable) bhkIWorldStepListener
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkIWorldStepListener };
		inline static constexpr auto VTABLE{ VTABLE::bhkIWorldStepListener };

		virtual ~bhkIWorldStepListener();

		// members
		BSTArray<BSTArray<NiPointer<bhkNPCollisionObject>>>* deferredReleaseColObjs;
	};
	static_assert(sizeof(bhkIWorldStepListener) == 0x10);
}
