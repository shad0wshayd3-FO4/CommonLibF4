#pragma once

#include "RE/Bethesda/InputEvent.h"
#include "RE/Bethesda/MemoryManager.h"

namespace RE
{
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

	struct __declspec(novtable) DisconnectHandler :
		public BSInputEventUser
	{
	public:
		static constexpr auto RTTI{ RTTI::DisconnectHandler };
		static constexpr auto VTABLE{ VTABLE::DisconnectHandler };
	};
	static_assert(sizeof(DisconnectHandler) == 0x10);

	struct __declspec(novtable) MenuOpenHandler :
		public BSInputEventUser  // 00
	{
		static constexpr auto RTTI{ RTTI::MenuOpenHandler };
		static constexpr auto VTABLE{ VTABLE::MenuOpenHandler };
	};
	static_assert(sizeof(MenuOpenHandler) == 0x10);

	struct __declspec(novtable) ScreenshotHandler :
		public BSInputEventUser  // 00
	{
		static constexpr auto RTTI{ RTTI::ScreenshotHandler };
		static constexpr auto VTABLE{ VTABLE::ScreenshotHandler };

		// members
		bool screenshotQueued;       // 10
		bool multiScreenshotQueued;  // 11
	};
	static_assert(sizeof(ScreenshotHandler) == 0x18);
}
