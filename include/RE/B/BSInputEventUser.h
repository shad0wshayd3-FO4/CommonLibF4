#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	class ButtonEvent;
	class CharacterEvent;
	class CursorMoveEvent;
	class DeviceConnectEvent;
	class InputEvent;
	class MouseMoveEvent;
	class KinectEvent;
	class ThumbstickEvent;

	class alignas(0x08) BSInputEventUser
	{
	public:
		static constexpr auto RTTI{ RTTI::BSInputEventUser };
		static constexpr auto VTABLE{ VTABLE::BSInputEventUser };

		virtual ~BSInputEventUser() = default;  // 00

		// add
		virtual bool ShouldHandleEvent(const InputEvent*) { return false; }       // 01
		virtual void OnKinectEvent(const KinectEvent*) { return; }                // 02
		virtual void OnDeviceConnectEvent(const DeviceConnectEvent*) { return; }  // 03
		virtual void OnThumbstickEvent(const ThumbstickEvent*) { return; }        // 04
		virtual void OnCursorMoveEvent(const CursorMoveEvent*) { return; }        // 05
		virtual void OnMouseMoveEvent(const MouseMoveEvent*) { return; }          // 06
		virtual void OnCharacterEvent(const CharacterEvent*) { return; }          // 07
		virtual void OnButtonEvent(const ButtonEvent*) { return; }                // 08

		F4_HEAP_REDEFINE_NEW(BSInputEventUser);

		// members
		bool inputEventHandlingEnabled{ true };  // 08
	};
	static_assert(sizeof(BSInputEventUser) == 0x10);
}
