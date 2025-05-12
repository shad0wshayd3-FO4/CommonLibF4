#pragma once

namespace RE
{
	class DoorTeleportData
	{
	public:
		enum class TELEPORT_DATA_FLAGS
		{
			kNoAlarm = 0x0,
			kInstant = 0x1,
			kRelative = 0x4
		};

		// members
		TESObjectCELL*  transitionCell;  // 00
		ObjectRefHandle linkedDoor;      // 08
		NiPoint3        position;        // 0C
		NiPoint3        rotation;        // 18
		std::uint8_t    flags;           // 24
	};
	static_assert(sizeof(DoorTeleportData) == 0x28);
}
