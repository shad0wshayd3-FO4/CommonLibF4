#pragma once

namespace RE
{
	class __declspec(novtable) SimpleAnimationGraphManagerHolder :
		public IAnimationGraphManagerHolder
	{
	public:
		static constexpr auto RTTI{ RTTI::SimpleAnimationGraphManagerHolder };
		static constexpr auto VTABLE{ VTABLE::SimpleAnimationGraphManagerHolder };

		virtual ~SimpleAnimationGraphManagerHolder() = default;  // 00

		// add
		virtual void BackgroundTaskFinishedLoading() { return; }  // 01

		// members
		BSTSmartPointer<BSAnimationGraphManager>          animationGraphManager;  // 08
		NiPointer<SimpleAnimationGraphManagerLoadingTask> loadingTask;            // 10
	};
	static_assert(sizeof(SimpleAnimationGraphManagerHolder) == 0x18);
}
