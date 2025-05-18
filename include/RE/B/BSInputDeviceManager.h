#pragma once

#include "RE/B/BSInputDevice.h"
#include "RE/B/BSTSingleton.h"
#include "RE/I/INPUT_DEVICE.h"

namespace RE
{
	class BSInputDeviceManager :
		public BSTSingletonSDM<BSInputDeviceManager>  // 00
	{
	public:
		enum class BS_DEVICES
		{
			kKeyboard = 0x0,
			kMouse = 0x1,
			kGamepad = 0x2,
			kDebugGamepad = 0x3,
			kVirtualKeyboard = 0x4,

			kTotal = 0x5
		};

		[[nodiscard]] static BSInputDeviceManager* GetSingleton()
		{
			static REL::Relocation<BSInputDeviceManager**> singleton{ ID::BSInputDeviceManager::Singleton };
			return *singleton;
		}

		[[nodiscard]] BSInputDevice* GetGamepad() const noexcept
		{
			return devices[std::to_underlying(INPUT_DEVICE::kGamepad)];
		}

		[[nodiscard]] bool IsGamepadConnected() const
		{
			const auto gamepad = GetGamepad();
			return gamepad && gamepad->IsConnected();
		}

		// members
		BSInputDevice* devices[std::to_underlying(INPUT_DEVICE::kTotal)];  // 08
		bool           deviceLightStates[3];                               // 30
		bool           queuedGamepadEnableValue;                           // 33
		bool           valueQueued;                                        // 34
		bool           pollingEnabled;                                     // 35
	};
	static_assert(sizeof(BSInputDeviceManager) == 0x38);
}
