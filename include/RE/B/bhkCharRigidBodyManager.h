#pragma once

namespace RE
{
	class __declspec(novtable) bhkCharRigidBodyManager :
		public bhkIWorldStepListener
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkCharRigidBodyManager };
		inline static constexpr auto VTABLE{ VTABLE::bhkCharRigidBodyManager };

		struct ThreadLocalCharRBDeferredCmds;

		virtual ~bhkCharRigidBodyManager();

		// members
		BSTArray<bhkCharRigidBodyController*>                  rigidBodyControllersA;
		BSTHashMap<bhkCharRigidBodyController*, std::uint32_t> rigidBodyControllerIndex;
		BSTArray<ThreadLocalCharRBDeferredCmds>                deferredCommandsA;
	};
	static_assert(sizeof(bhkCharRigidBodyManager) == 0x70);
}
