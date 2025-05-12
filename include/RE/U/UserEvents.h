#pragma once

namespace RE
{
	namespace UserEvents
	{
		enum class USER_EVENT_FLAG
		{
			kAll = static_cast<std::underlying_type_t<USER_EVENT_FLAG>>(-1),

			kMovement = 1 << 0,
			kLooking = 1 << 1,
			kActivate = 1 << 2,
			kMenu = 1 << 3,
			kConsole = 1 << 4,
			kPOVSwitch = 1 << 5,
			kFighting = 1 << 6,
			kSneaking = 1 << 7,
			kMainFour = 1 << 8,
			kWheelZoom = 1 << 9,
			kJumping = 1 << 10,
			kVATS = 1 << 11
		};

		enum class INPUT_CONTEXT_ID
		{
			kMainGameplay = 0x0,
			kBasicMenuNav = 0x1,
			kThumbNav = 0x2,
			kVirtualController = 0x3,
			kCursor = 0x4,
			kLThumbCursor = 0x5,
			kConsole = 0x6,
			kDebugText = 0x7,
			kBook = 0x8,
			kDebugOverlay = 0x9,
			kTFC = 0xA,
			kDebugMap = 0xB,
			kLockpick = 0xC,
			kVATS = 0xD,
			kVATSPlayback = 0xE,
			kMultiActivate = 0xF,
			kWorkshop = 0x10,
			kScope = 0x11,
			kSitWait = 0x12,
			kLooksMenu = 0x13,
			kWorkshopAddendum = 0x14,
			kPauseMenu = 0x15,
			kLevelUpMenu = 0x16,
			kLevelUpMenuPrevNext = 0x17,
			kMainMenu = 0x18,
			kQuickContainerMenu = 0x19,
			kSpecialActivateRollover = 0x1A,
			kTwoButtonRollover = 0x1B,
			kQuickContainerMenuPerk = 0x1C,
			kVertibird = 0x1D,
			kPlayBinkMenu = 0x1E,
			kRobotModAddendum = 0x1F,
			kCreationClub = 0x20,

			kTotal = 0x21,

			kNone = 0x22
		};

		enum class SENDER_ID
		{
			kNone = 0x0,
			kGameplay = 0x1,
			kMenu = 0x2,
			kScript = 0x3
		};
	}
	using UEFlag = UserEvents::USER_EVENT_FLAG;
}
