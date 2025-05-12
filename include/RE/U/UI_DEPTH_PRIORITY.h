#pragma once

namespace RE
{
	enum class UI_DEPTH_PRIORITY
	{
		kUndefined = 0x0,
		k3DUnderHUD = 0x1,  // WorkshopMenu3D
		kBook = 0x2,        // BookMenu
		kScope = 0x3,       // ScopeMenu
		kSWFLoader = 0x4,
		kHUD = 0x5,
		kStandard = 0x6,         // PipboyMenu, PowerArmorRenderer, HUDRainRenderer, LockpickingMenu3D
		kStandard3DModel = 0x7,  // Container3D, WorkbenchItem3D
		kPipboy = 0x8,
		kTerminal = 0x9,
		kGameMessage = 0xA,
		kPauseMenu = 0xB,
		kLoadingFader = 0xC,
		kLoading3DModel = 0xD,  // BackgroundScreenModel
		kLoadingMenu = 0xE,
		kMessage = 0xF,
		kButtonBarMenu = 0x10,  // FlatScreenModel, HUDScreenModel
		kButtonBarSupressingMenu = 0x11,
		kDebug = 0x12,
		kConsole = 0x13,
		kCursor = 0x14
	};
}
