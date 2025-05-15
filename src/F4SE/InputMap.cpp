#include "F4SE/InputMap.h"

#include "RE/C/ControlMap.h"
#include "RE/P/PC_GAMEPAD_TYPE.h"

#include "REX/PS4/SCEPAD.h"
#include "REX/W32/DINPUT.h"
#include "REX/W32/USER32.h"
#include "REX/W32/XINPUT.h"

namespace F4SE
{
	std::uint32_t InputMap::XInputToScePadOffset(std::uint32_t keyMask)
	{
		switch (keyMask) {
			case REX::W32::XINPUT_GAMEPAD_DPAD_UP:
				return REX::PS4::SCE_PAD_BUTTON_UP;
			case REX::W32::XINPUT_GAMEPAD_DPAD_DOWN:
				return REX::PS4::SCE_PAD_BUTTON_DOWN;
			case REX::W32::XINPUT_GAMEPAD_DPAD_LEFT:
				return REX::PS4::SCE_PAD_BUTTON_LEFT;
			case REX::W32::XINPUT_GAMEPAD_DPAD_RIGHT:
				return REX::PS4::SCE_PAD_BUTTON_RIGHT;
			case REX::W32::XINPUT_GAMEPAD_START:
				return REX::PS4::SCE_PAD_BUTTON_OPTIONS;
			case REX::W32::XINPUT_GAMEPAD_BACK:
				return REX::PS4::SCE_PAD_BUTTON_TOUCH_PAD;
			case REX::W32::XINPUT_GAMEPAD_LEFT_THUMB:
				return REX::PS4::SCE_PAD_BUTTON_L3;
			case REX::W32::XINPUT_GAMEPAD_RIGHT_THUMB:
				return REX::PS4::SCE_PAD_BUTTON_R3;
			case REX::W32::XINPUT_GAMEPAD_LEFT_SHOULDER:
				return REX::PS4::SCE_PAD_BUTTON_L1;
			case REX::W32::XINPUT_GAMEPAD_RIGHT_SHOULDER:
				return REX::PS4::SCE_PAD_BUTTON_R1;
			case REX::W32::XINPUT_GAMEPAD_A:
				return REX::PS4::SCE_PAD_BUTTON_CROSS;
			case REX::W32::XINPUT_GAMEPAD_B:
				return REX::PS4::SCE_PAD_BUTTON_CIRCLE;
			case REX::W32::XINPUT_GAMEPAD_X:
				return REX::PS4::SCE_PAD_BUTTON_SQUARE;
			case REX::W32::XINPUT_GAMEPAD_Y:
				return REX::PS4::SCE_PAD_BUTTON_TRIANGLE;
			default:
				return keyMask;
		}
	}

	std::uint32_t InputMap::ScePadOffsetToXInput(std::uint32_t keyMask)
	{
		switch (keyMask) {
			case REX::PS4::SCE_PAD_BUTTON_UP:
				return REX::W32::XINPUT_GAMEPAD_DPAD_UP;
			case REX::PS4::SCE_PAD_BUTTON_DOWN:
				return REX::W32::XINPUT_GAMEPAD_DPAD_DOWN;
			case REX::PS4::SCE_PAD_BUTTON_LEFT:
				return REX::W32::XINPUT_GAMEPAD_DPAD_LEFT;
			case REX::PS4::SCE_PAD_BUTTON_RIGHT:
				return REX::W32::XINPUT_GAMEPAD_DPAD_RIGHT;
			case REX::PS4::SCE_PAD_BUTTON_OPTIONS:
				return REX::W32::XINPUT_GAMEPAD_START;
			case REX::PS4::SCE_PAD_BUTTON_TOUCH_PAD:
				return REX::W32::XINPUT_GAMEPAD_BACK;
			case REX::PS4::SCE_PAD_BUTTON_L3:
				return REX::W32::XINPUT_GAMEPAD_LEFT_THUMB;
			case REX::PS4::SCE_PAD_BUTTON_R3:
				return REX::W32::XINPUT_GAMEPAD_RIGHT_THUMB;
			case REX::PS4::SCE_PAD_BUTTON_L1:
				return REX::W32::XINPUT_GAMEPAD_LEFT_SHOULDER;
			case REX::PS4::SCE_PAD_BUTTON_R1:
				return REX::W32::XINPUT_GAMEPAD_RIGHT_SHOULDER;
			case REX::PS4::SCE_PAD_BUTTON_CROSS:
				return REX::W32::XINPUT_GAMEPAD_A;
			case REX::PS4::SCE_PAD_BUTTON_CIRCLE:
				return REX::W32::XINPUT_GAMEPAD_B;
			case REX::PS4::SCE_PAD_BUTTON_SQUARE:
				return REX::W32::XINPUT_GAMEPAD_X;
			case REX::PS4::SCE_PAD_BUTTON_TRIANGLE:
				return REX::W32::XINPUT_GAMEPAD_Y;
			default:
				return keyMask;
		}
	}

	std::uint32_t InputMap::GamepadMaskToKeycode(std::uint32_t keyMask)
	{
		if (RE::ControlMap::GetSingleton()->pcGamePadMapType == RE::PC_GAMEPAD_TYPE::kOrbis) {
			keyMask = ScePadOffsetToXInput(keyMask);
		}

		switch (keyMask) {
			case REX::W32::XINPUT_GAMEPAD_DPAD_UP:
				return kGamepadButtonOffset_DPAD_UP;
			case REX::W32::XINPUT_GAMEPAD_DPAD_DOWN:
				return kGamepadButtonOffset_DPAD_DOWN;
			case REX::W32::XINPUT_GAMEPAD_DPAD_LEFT:
				return kGamepadButtonOffset_DPAD_LEFT;
			case REX::W32::XINPUT_GAMEPAD_DPAD_RIGHT:
				return kGamepadButtonOffset_DPAD_RIGHT;
			case REX::W32::XINPUT_GAMEPAD_START:
				return kGamepadButtonOffset_START;
			case REX::W32::XINPUT_GAMEPAD_BACK:
				return kGamepadButtonOffset_BACK;
			case REX::W32::XINPUT_GAMEPAD_LEFT_THUMB:
				return kGamepadButtonOffset_LEFT_THUMB;
			case REX::W32::XINPUT_GAMEPAD_RIGHT_THUMB:
				return kGamepadButtonOffset_RIGHT_THUMB;
			case REX::W32::XINPUT_GAMEPAD_LEFT_SHOULDER:
				return kGamepadButtonOffset_LEFT_SHOULDER;
			case REX::W32::XINPUT_GAMEPAD_RIGHT_SHOULDER:
				return kGamepadButtonOffset_RIGHT_SHOULDER;
			case REX::W32::XINPUT_GAMEPAD_A:
				return kGamepadButtonOffset_A;
			case REX::W32::XINPUT_GAMEPAD_B:
				return kGamepadButtonOffset_B;
			case REX::W32::XINPUT_GAMEPAD_X:
				return kGamepadButtonOffset_X;
			case REX::W32::XINPUT_GAMEPAD_Y:
				return kGamepadButtonOffset_Y;
			case 0x9:  // Left Trigger game-defined ID
				return kGamepadButtonOffset_LT;
			case 0xA:  // Right Trigger game-defined ID
				return kGamepadButtonOffset_RT;
			default:
				return kMaxMacros;  // Invalid
		}
	}

	std::uint32_t InputMap::GamepadKeycodeToMask(std::uint32_t keyCode)
	{
		std::uint32_t keyMask;

		switch (keyCode) {
			case kGamepadButtonOffset_DPAD_UP:
				keyMask = REX::W32::XINPUT_GAMEPAD_DPAD_UP;
				break;
			case kGamepadButtonOffset_DPAD_DOWN:
				keyMask = REX::W32::XINPUT_GAMEPAD_DPAD_DOWN;
				break;
			case kGamepadButtonOffset_DPAD_LEFT:
				keyMask = REX::W32::XINPUT_GAMEPAD_DPAD_LEFT;
				break;
			case kGamepadButtonOffset_DPAD_RIGHT:
				keyMask = REX::W32::XINPUT_GAMEPAD_DPAD_RIGHT;
				break;
			case kGamepadButtonOffset_START:
				keyMask = REX::W32::XINPUT_GAMEPAD_START;
				break;
			case kGamepadButtonOffset_BACK:
				keyMask = REX::W32::XINPUT_GAMEPAD_BACK;
				break;
			case kGamepadButtonOffset_LEFT_THUMB:
				keyMask = REX::W32::XINPUT_GAMEPAD_LEFT_THUMB;
				break;
			case kGamepadButtonOffset_RIGHT_THUMB:
				keyMask = REX::W32::XINPUT_GAMEPAD_RIGHT_THUMB;
				break;
			case kGamepadButtonOffset_LEFT_SHOULDER:
				keyMask = REX::W32::XINPUT_GAMEPAD_LEFT_SHOULDER;
				break;
			case kGamepadButtonOffset_RIGHT_SHOULDER:
				keyMask = REX::W32::XINPUT_GAMEPAD_RIGHT_SHOULDER;
				break;
			case kGamepadButtonOffset_A:
				keyMask = REX::W32::XINPUT_GAMEPAD_A;
				break;
			case kGamepadButtonOffset_B:
				keyMask = REX::W32::XINPUT_GAMEPAD_B;
				break;
			case kGamepadButtonOffset_X:
				keyMask = REX::W32::XINPUT_GAMEPAD_X;
				break;
			case kGamepadButtonOffset_Y:
				keyMask = REX::W32::XINPUT_GAMEPAD_Y;
				break;
			case kGamepadButtonOffset_LT:
				keyMask = 0x9;  // Left Trigger game-defined ID
				break;
			case kGamepadButtonOffset_RT:
				keyMask = 0xA;  // Right Trigger game-defined ID
				break;
			default:
				keyMask = 0xFF;  // Invalid
				break;
		}

		if (RE::ControlMap::GetSingleton()->pcGamePadMapType == RE::PC_GAMEPAD_TYPE::kOrbis) {
			keyMask = XInputToScePadOffset(keyMask);
		}

		return keyMask;
	}
}
