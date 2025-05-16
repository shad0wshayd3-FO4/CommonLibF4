#pragma once

#include "RE/S/StartMenuBase.h"
#include "RE/R/Rumble.h"

namespace RE
{
	class __declspec(novtable) PauseMenu :
		public StartMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PauseMenu };
		static constexpr auto VTABLE{ VTABLE::PauseMenu };
		static constexpr auto MENU_NAME{ "PauseMenu"sv };

		// members
		std::unique_ptr<BSGFxShaderFXTarget>  helpTopicList;            // 228
		std::unique_ptr<BSGFxShaderFXTarget>  helpPanelBrackets;        // 230
		std::unique_ptr<BSGFxShaderFXTarget>  helpListBrackets;         // 238
		std::unique_ptr<BSGFxShaderFXTarget>  helpText;                 // 240
		std::unique_ptr<BSGFxShaderFXTarget>  helpTitleText;            // 248
		std::unique_ptr<BSGFxShaderFXTarget>  helpScrollUp;             // 250
		std::unique_ptr<BSGFxShaderFXTarget>  helpScrollDown;           // 258
		Rumble::AutoRumblePause               rumbleLock;               // 260
		bool                                  hideScreen3D;             // 261
		bool                                  modMenuShaderWasEnabled;  // 262
		bool                                  vatsWasEnabled;           // 263
		bool                                  vatsDepthTestMask;        // 264
		bool                                  quitToMainMenuQueued;     // 265
		bool                                  quitToDesktopQueued;      // 266
		bool                                  noProfileSelected;        // 267
	};
	static_assert(sizeof(PauseMenu) == 0x268);
}
