#pragma once

namespace RE
{
	class __declspec(novtable) DialogueMenu :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::DialogueMenu };
		static constexpr auto VTABLE{ VTABLE::DialogueMenu };
		static constexpr auto MENU_NAME{ "DialogueMenu"sv };

		// Members
		msvc::unique_ptr<BSGFxShaderFXTarget>                   dialogueButtonOBJs[4];
		msvc::unique_ptr<BSGFxShaderFXTarget>                   speechChallengeAnimObj;
		BSTValueEventSink<HUDPerkVaultBoySwfDisplayEvent>       CurrentVBPerk;
		BSTValueEventSource<ShowingDialogueSpeechChallengeAnim> ShowingSpeechChallenge;
		BSTSmartPointer<BSInputEnableLayer>                     inputLayer;
		UserEvents::INPUT_CONTEXT_ID                            CurrentContext;
		bool                                                    IsLookingAtPlayer;
		bool                                                    AreButtonsShown;
	};
	static_assert(sizeof(DialogueMenu) == 0x168);
}
