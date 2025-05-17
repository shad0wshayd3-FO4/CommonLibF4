#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IAnimationGraphManagerHolder.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSAnimationGraphManager;
	class SimpleAnimationGraphManagerLoadingTask;

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
