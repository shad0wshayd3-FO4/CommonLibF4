#pragma once

namespace RE
{
	class __declspec(novtable) hknpBSWorld :
		public hknpWorld
	{
	public:
		static constexpr auto RTTI{ RTTI::hknpBSWorld };
		static constexpr auto VTABLE{ VTABLE::hknpBSWorld };

		virtual ~hknpBSWorld() override;  // 00

		// members
		void* userData;
		BSReadWriteLock           worldLock;
		std::byte                 activateBodyPostCollideSet[48];  // BSTSet<hknpBodyId>
		BSSpinLock                activateBodyPostCollideLock;
		hkMultiMap<std::uint32_t> constrainedBodyFromBody;
	};
	static_assert(sizeof(hknpBSWorld) == 0x730);
}
