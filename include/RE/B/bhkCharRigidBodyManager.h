#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/bhkIWorldStepListener.h"

namespace RE
{
	class bhkCharRigidBodyController;

	class __declspec(novtable) bhkCharRigidBodyManager :
		public bhkIWorldStepListener
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkCharRigidBodyManager };
		inline static constexpr auto VTABLE{ VTABLE::bhkCharRigidBodyManager };

		class ThreadLocalCharRBDeferredCmds;

		virtual ~bhkCharRigidBodyManager();

		// members
		BSTArray<bhkCharRigidBodyController*>                  rigidBodyControllersA;
		BSTHashMap<bhkCharRigidBodyController*, std::uint32_t> rigidBodyControllerIndex;
		BSTArray<ThreadLocalCharRBDeferredCmds>                deferredCommandsA;
	};
	static_assert(sizeof(bhkCharRigidBodyManager) == 0x70);
}
