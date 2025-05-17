#pragma once

namespace RE
{
	class CameraStates
	{
	public:
		enum CameraState : std::uint32_t
		{
			kFirstPerson = 0x0,
			kAutoVanity = 0x1,
			kVATS = 0x2,
			kFree = 0x3,
			kIronSights = 0x4,
			kPCTransition = 0x5,
			kTween = 0x6,
			kAnimated = 0x7,
			k3rdPerson = 0x8,
			kFurniture = 0x9,
			kMount = 0xA,
			kBleedout = 0xB,
			kDialogue = 0xC,

			kTotal = 0xD
		};
	};
	using CameraState = CameraStates::CameraState;
}
