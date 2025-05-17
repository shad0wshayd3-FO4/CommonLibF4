#pragma once

#include "RE/G/GameMenuBase.h"
#include "RE/B/BSTOptional.h"
#include "RE/D/DifficultyLevel.h"

namespace RE
{
	class __declspec(novtable) StartMenuBase :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::StartMenuBase };
		static constexpr auto VTABLE{ VTABLE::StartMenuBase };

		virtual ~StartMenuBase();  // 00

		// add
		virtual void DoLoadGame(std::int32_t a_saveIndex);  // 14
		virtual void InitMainList();                        // 15
		virtual bool GetIsMenuReady();                      // 16
		virtual void SaveSettings_Derived();                // 17
		virtual void SetMenuColor();                        // 18

		// members
		std::unique_ptr<BSGFxShaderFXTarget>  mainPanel;                      // 0E0
		std::unique_ptr<BSGFxShaderFXTarget>  versionText;                    // 0E8
		std::unique_ptr<BSGFxShaderFXTarget>  mainPanelBackground;            // 0F0
		std::unique_ptr<BSGFxShaderFXTarget>  loadPanelBackground;            // 0F8
		std::unique_ptr<BSGFxShaderFXTarget>  loadPanelBrackets;              // 100
		std::unique_ptr<BSGFxShaderFXTarget>  loadPanelList;                  // 108
		std::unique_ptr<BSGFxShaderFXTarget>  loadPanelPlayerInfo;            // 110
		std::unique_ptr<BSGFxShaderFXTarget>  confirmText;                    // 118
		std::unique_ptr<BSGFxShaderFXTarget>  levelText;                      // 120
		std::unique_ptr<BSGFxShaderFXTarget>  playtimeText;                   // 128
		std::unique_ptr<BSGFxShaderFXTarget>  locationText;                   // 130
		std::unique_ptr<BSGFxShaderFXTarget>  levelMeter;                     // 138
		std::unique_ptr<BSGFxShaderFXTarget>  modsLoadedText;                 // 140
		std::unique_ptr<BSGFxShaderFXTarget>  settingsCategoryList;           // 148
		std::unique_ptr<BSGFxShaderFXTarget>  settingsList;                   // 150
		std::unique_ptr<BSGFxShaderFXTarget>  DLCList;                        // 158
		std::unique_ptr<BSGFxShaderFXTarget>  loadingIcon;                    // 160
		std::unique_ptr<BSGFxShaderFXTarget>  colorReference;                 // 168
		std::unique_ptr<BSGFxShaderFXTarget>  splashScreenText;               // 170
		std::unique_ptr<BSGFxShaderFXTarget>  controlsPanel;                  // 178
		std::unique_ptr<BSGFxShaderFXTarget>  helpPanelBackground;            // 180
		std::unique_ptr<BSGFxShaderFXTarget>  helpListBackground;             // 188
		std::unique_ptr<BSGFxShaderFXTarget>  gamerTagPanel;                  // 190
		std::unique_ptr<BSGFxShaderFXTarget>  gamerTagText;                   // 198
		std::unique_ptr<BSGFxShaderFXTarget>  gamerTagIcon;                   // 1A0
		std::unique_ptr<BSGFxShaderFXTarget>  bethesdaLogo;                   // 1A8
		std::unique_ptr<BSGFxShaderFXTarget>  characterSelectList;            // 1B0
		std::unique_ptr<BSGFxShaderFXTarget>  remapPrompt;                    // 1B8
		std::unique_ptr<BSGFxShaderFXTarget>  settingGuideText;               // 1C0
		std::unique_ptr<BSGFxShaderFXTarget>  blackBackground;                // 1C8
		std::unique_ptr<BSGFxShaderFXTarget>  modManager;                     // 1D0
		std::unique_ptr<BSGFxShaderFXTarget>  DLCImageSizer;                  // 1D8
		std::unique_ptr<BSGFxShaderFXTarget>  DLCPanelBrackets;               // 1E0
		std::unique_ptr<BSGFxShaderFXTarget>  loginObj;                       // 1E8
		std::unique_ptr<BSGFxShaderFXTarget>  motD;                           // 1F0
		BSTOptional<DifficultyLevel>          currentDisplayDifficultyLevel;  // 1F8
		Scaleform::GFx::Value                 saveLoadPanelObj;               // 218
		bool                                  gameDataReady;                  // 220
		bool                                  controlsChanged;                // 221
	};
	static_assert(sizeof(StartMenuBase) == 0x228);
}
