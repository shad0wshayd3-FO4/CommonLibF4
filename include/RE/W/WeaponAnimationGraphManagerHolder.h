#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTEvent.h"
#include "RE/I/IAnimationGraphManagerHolder.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class BSAnimationGraphManager;
	struct BSAnimationGraphEvent;

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
