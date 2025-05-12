#pragma once

namespace RE
{
	class __declspec(novtable) WeaponAnimationGraphManagerHolder :
		public IAnimationGraphManagerHolder,
		public BSTEventSink<BSAnimationGraphEvent>,
		public BSIntrusiveRefCounted
	{
	public:
		static constexpr auto RTTI{ RTTI::WeaponAnimationGraphManagerHolder };
		static constexpr auto VTABLE{ VTABLE::WeaponAnimationGraphManagerHolder };

		virtual ~WeaponAnimationGraphManagerHolder() = default;  // 00

		// override (BSTEventSink<BSAnimationGraphEvent>)
		BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent& a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;

		// members
		BSTSmartPointer<BSAnimationGraphManager> animationGraphManager;  // 08
		ObjectRefHandle                          owner;                  // 10
	};
	static_assert(sizeof(WeaponAnimationGraphManagerHolder) == 0x28);
}
