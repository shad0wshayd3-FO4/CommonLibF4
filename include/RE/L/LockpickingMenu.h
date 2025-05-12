#pragma once

#include "RE/G/GameMenuBase.h"

namespace RE
{
	class __declspec(novtable) LockpickingMenu :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::LockpickingMenu };
		static constexpr auto VTABLE{ VTABLE::LockpickingMenu };
		static constexpr auto MENU_NAME{ "LockpickingMenu"sv };

		virtual ~LockpickingMenu();  // 00

		// override (GameMenuBase)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                    // 03
		virtual void               AdvanceMovie(float a_timeDelta, std::uint64_t a_time) override;   // 04
		virtual bool               OnButtonEventRelease(const BSFixedString& a_eventName) override;  // 0F

		// override (BSInputEventUser)
		virtual bool ShouldHandleEvent(const InputEvent*) override;       // 01
		virtual void OnThumbstickEvent(const ThumbstickEvent*) override;  // 04
		virtual void OnMouseMoveEvent(const MouseMoveEvent*) override;    // 06
		virtual void OnButtonEvent(const ButtonEvent*) override;          // 08

		static void OpenLockpickingMenu(TESObjectREFR* a_lockedRef)
		{
			using func_t = decltype(&LockpickingMenu::OpenLockpickingMenu);
			static REL::Relocation<func_t> func{ REL::ID(129892) };
			return func(a_lockedRef);
		}

		// members
		NiMatrix3             origPickRotate;           // 0E0
		NiPoint3              origPickTranslate;        // 110
		NiControllerManager*  lockAnimManager;          // 120
		NiControllerSequence* lockIntroAnim;            // 128
		NiControllerSequence* lockRotateAnim;           // 130
		NiControllerManager*  pickAnimManager;          // 138
		NiControllerSequence* pickIntroAnim;            // 140
		NiControllerSequence* pickBendAnim;             // 148
		NiControllerSequence* pickBreakAnim;            // 150
		NiControllerSequence* currPickAnim;             // 158
		NiControllerSequence* currLockAnim;             // 160
		void*                 lockModel;                // 168
		void*                 pickModel;                // 170
		NiPointer<NiNode>     lockRoot;                 // 178
		float                 currPickAnimElapsedSecs;  // 180
		float                 currLockAnimElapsedSecs;  // 184
		float                 pickAngle;                // 188
		float                 lockAngle;                // 18C
		float                 lockDamagePickAngle;      // 190
		float                 pickBreakSecs;            // 194
		BSSoundHandle         pickTensionSound;         // 198
		float                 sweetSpotCenter;          // 1A0
		float                 sweetSpotLength;          // 1A4
		float                 partialPickLength;        // 1A8
		std::uint32_t         picksBroken;              // 1AC
		bool                  modelsInit;               // 1B0
		bool                  animating;                // 1B1
		bool                  turningLock;              // 1B2
		bool                  menuCleanedUp;            // 1B3
		bool                  tutorialMenuOpening;      // 1B4
		bool                  crimeDetected;            // 1B5
		bool                  VATSWasEnabled;           // 1B6
		bool                  VATSDepthTestMask;        // 1B7
	};
	static_assert(sizeof(LockpickingMenu) == 0x1C0);
}
