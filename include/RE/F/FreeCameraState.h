#pragma once

#include "RE/T/TESCameraState.h"
#include "RE/N/NiPoint.h"
#include "RE/B/BSTPoint.h"

namespace RE
{
	class __declspec(novtable) FreeCameraState :
		public TESCameraState
	{
	public:
		static constexpr auto RTTI{ RTTI::FreeCameraState };
		static constexpr auto VTABLE{ VTABLE::FreeCameraState };
		static constexpr auto STATE{ CameraStates::kFree };

		NiPoint3         translation;
		BSTPoint2<float> rotation;
		BSTPoint2<float> upDown;
		BSTPoint2<float> leftThumbstick;
		BSTPoint2<float> rightThumbstick;
		std::int16_t     worldZDirection;
		bool             runInput;
		bool             lockToZPlane;
	};
	static_assert(sizeof(FreeCameraState) == 0x58);
}
