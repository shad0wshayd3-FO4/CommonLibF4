#pragma once

namespace RE
{
	class __declspec(novtable) PlayerCamera :
		public TESCamera,                             // 000
		public BSInputEventReceiver,                  // 038
		public BSTEventSink<IdleInputEvent>,          // 048
		public BSTEventSink<UserEventEnabledEvent>,   // 050
		public BSTEventSink<OtherEventEnabledEvent>,  // 058
		public BSTSingletonSDM<PlayerCamera>          // 060
	{
	public:
		static constexpr auto RTTI{ RTTI::PlayerCamera };
		static constexpr auto VTABLE{ VTABLE::PlayerCamera };

		[[nodiscard]] static PlayerCamera* GetSingleton()
		{
			static REL::Relocation<PlayerCamera**> singleton{ REL::ID(2688801) };
			return *singleton;
		}

		[[nodiscard]] BSTSmartPointer<TESCameraState> GetState(CameraState a_state) const
		{
			return cameraStates[a_state];
		}

		template <class T>
		[[nodiscard]] BSTSmartPointer<T> GetState() const  //
			requires(std::derived_from<T, TESCameraState>)
		{
			return BSTSmartPointer{ static_cast<T*>(cameraStates[T::STATE].get()) };
		}

		TESCameraState* PopState()
		{
			using func_t = decltype(&PlayerCamera::PopState);
			static REL::Relocation<func_t> func{ REL::ID(2248424) };
			return func(this);
		}

		TESCameraState* PushState(CameraState a_state)
		{
			using func_t = decltype(&PlayerCamera::PushState);
			static REL::Relocation<func_t> func{ REL::ID(0) };
			return func(this, a_state);
		}

		void ToggleFreeCameraMode(bool a_freezeTime)
		{
			using func_t = decltype(&PlayerCamera::ToggleFreeCameraMode);
			static REL::Relocation<func_t> func{ REL::ID(2248368) };
			return func(this, a_freezeTime);
		}

		void SetState(TESCameraState* a_newstate) const
		{
			using func_t = decltype(&PlayerCamera::SetState);
			static REL::Relocation<func_t> func{ REL::ID(2214742) };
			return func(this, a_newstate);
		}

		void StartFurnitureMode(TESObjectREFR* a_furniture)
		{
			using func_t = decltype(&PlayerCamera::StartFurnitureMode);
			static REL::Relocation<func_t> func{ REL::ID(0) };
			return func(this, a_furniture);
		}

		void StartPipboyMode(bool a_forcePipboyModeCamera)
		{
			using func_t = decltype(&PlayerCamera::StartPipboyMode);
			static REL::Relocation<func_t> func{ REL::ID(2248358) };
			return func(this, a_forcePipboyModeCamera);
		}

		void StopPipboyMode()
		{
			using func_t = decltype(&PlayerCamera::StopPipboyMode);
			static REL::Relocation<func_t> func{ REL::ID(2248359) };
			return func(this);
		}

		bool QCameraEquals(CameraState a_state)
		{
			using func_t = decltype(&PlayerCamera::QCameraEquals);
			static REL::Relocation<func_t> func{ REL::ID(2248421) };
			return func(this, a_state);
		}

		// members
		ActorHandle                                                          cameraTarget;                        // 064
		BSTSmallArray<BSTSmartPointer<TESCameraState>, CameraStates::kTotal> tempReturnStates;                    // 068
		BSTSmartPointer<TESCameraState>                                      cameraStates[CameraStates::kTotal];  // 0E0
		hknpBodyId                                                           cameraBodyID;                        // 148
		hkRefPtr<hknpShape>                                                  cameraShape;                         // 150
		hkRefPtr<hknpBSWorld>                                                physicsWorld;                        // 158
		ActorHandle                                                          savedCollidedActor;                  // 160
		ObjectRefHandle                                                      collisionIgnoredReference;           // 164
		float                                                                worldFOV;                            // 168
		float                                                                firstPersonFOV;                      // 16C
		float                                                                fovAdjustCurrent;                    // 170
		float                                                                fovAdjustTarget;                     // 174
		float                                                                fovAdjustPerSec;                     // 178
		float                                                                fovAnimatorAdjust;                   // 17C
		float                                                                collisionDistPercent;                // 180
		float                                                                curPlayerVisible;                    // 184
		NiPoint3                                                             bufferedCameraPos;                   // 188
		float                                                                heading;                             // 194
		float                                                                timeInPitchZero;                     // 198
		float                                                                originalPitchToZero;                 // 19C
		std::uint32_t                                                        furnitureCollisionGroup;             // 1A0
		bool                                                                 allowAutoVanityMode;                 // 1A4
		bool                                                                 bowZoomedIn;                         // 1A5
		bool                                                                 freeRotationReady;                   // 1A6
		bool                                                                 cameraPosBuffered;                   // 1A7
		bool                                                                 zeroOutPitch;                        // 1A8
		bool                                                                 adjustFOV;                           // 1A9
		bool                                                                 trailerCameraMode;                   // 1AA
		bool                                                                 pipboyMode;                          // 1AB
		bool                                                                 savedFadeOutCloseActors;             // 1AC
	};
	static_assert(sizeof(PlayerCamera) == 0x1B0);
}
