#pragma once

#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/I/IMovementPlayerControls.h"

namespace RE
{
	class __declspec(novtable) PlayerControls :
		public BSInputEventReceiver,                    // 000
		public BSTEventSink<MenuOpenCloseEvent>,        // 010
		public BSTEventSink<MenuModeChangeEvent>,       // 018
		public BSTEventSink<TESFurnitureEvent>,         // 020
		public BSTEventSink<UserEventEnabledEvent>,     // 028
		public IMovementPlayerControls,                 // 030
		public BSTEventSink<QuickContainerStateEvent>,  // 038
		public BSTSingletonSDM<PlayerControls>          // 040
	{
	public:
		static constexpr auto RTTI{ RTTI::PlayerControls };
		static constexpr auto VTABLE{ VTABLE::PlayerControls };

		static PlayerControls* GetSingleton()
		{
			static REL::Relocation<PlayerControls**> singleton{ REL::ID(2692013) };
			return *singleton;
		}

		bool CanPerformAction(DEFAULT_OBJECT a_action)
		{
			using func_t = decltype(&PlayerControls::CanPerformAction);
			static REL::Relocation<func_t> func{ REL::ID(565925) };
			return func(this, a_action);
		}

		bool DoAction(DEFAULT_OBJECT a_action, ActionInput::ACTIONPRIORITY a_priority)
		{
			using func_t = decltype(&PlayerControls::DoAction);
			static REL::Relocation<func_t> func{ REL::ID(818081) };
			return func(this, a_action, a_priority);
		}

		void RegisterHandler(PlayerInputHandler* a_handler) { DoRegisterHandler(a_handler, false); }
		void RegisterHandler(HeldStateHandler* a_handler) { DoRegisterHandler(a_handler, true); }

		// members
		PlayerControlsData            data;                    // 044
		BSTArray<PlayerInputHandler*> handlers;                // 090
		BSTArray<HeldStateHandler*>   heldStateHandlers;       // 0A8
		std::uint32_t                 topGraphPoint[3];        // 0C0
		float                         graphPoints[3][10][2];   // 0CC
		BSTArray<ActorHandle>         actionInterestedActors;  // 1C0
		BSSpinLock                    actorArraySpinLock;      // 1D8
		MovementHandler*              movementHandler;         // 1E0
		LookHandler*                  lookHandler;             // 1E8
		SprintHandler*                sprintHandler;           // 1F0
		ReadyWeaponHandler*           readyWeaponHandler;      // 1F8
		AutoMoveHandler*              autoMoveHandler;         // 200
		ToggleRunHandler*             toggleRunHandler;        // 208
		ActivateHandler*              activateHandler;         // 210
		JumpHandler*                  jumpHandler;             // 218
		AttackBlockHandler*           attackHandler;           // 220
		RunHandler*                   runHandler;              // 228
		SneakHandler*                 sneakHandler;            // 230
		TogglePOVHandler*             togglePOVHandler;        // 238
		MeleeThrowHandler*            meleeThrowHandler;       // 240
		GrabRotationHandler*          grabRotationHandler;     // 248
		bool                          notifyingHandlers;       // 250
		bool                          blockPlayerInput;        // 251
		float                         cameraAutoRotationX;     // 254
		float                         cameraAutoRotationY;     // 258

	private:
		void DoRegisterHandler(PlayerInputHandler* a_handler, bool a_isHeldStateHandler)
		{
			using func_t = decltype(&PlayerControls::DoRegisterHandler);
			static REL::Relocation<func_t> func{ REL::ID(2234822) };
			return func(this, a_handler, a_isHeldStateHandler);
		}
	};
	static_assert(sizeof(PlayerControls) == 0x260);
}
