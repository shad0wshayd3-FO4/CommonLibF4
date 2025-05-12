#pragma once

namespace RE
{
	class __declspec(novtable) ThirdPersonState :
		public TESCameraState  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::ThirdPersonState };
		static constexpr auto VTABLE{ VTABLE::ThirdPersonState };
		static constexpr auto STATE{ CameraStates::k3rdPerson };

		// add
		virtual void ProcessWeaponDrawnChange(bool a_drawn);                           // 11
		virtual bool GetFreeRotationMode() const;                                      // 12
		virtual void SetFreeRotationMode(bool a_cameraEnable, bool a_modifyRotation);  // 13
		virtual void UpdateRotation();                                                 // 14
		virtual void HandleLookInput(const NiPoint2& a_input);                         // 15

		// members
		NiQuaternion          rotation;                      // 028
		NiQuaternion          animationRotation;             // 038
		NiPoint3              translation;                   // 048
		NiPoint3              preCollisionTranslation;       // 054
		NiPoint3              targetShoulderOffset;          // 060
		NiPoint3              currentShoulderOffset;         // 06C
		NiPoint3              animationTranslation;          // 078
		NiPoint3              lastTranslation;               // 084
		NiPoint3              rootOffset;                    // 090
		NiPoint3              sideOffsetCollisionBlend;      // 09C
		NiPoint3              nearestHit;                    // 0A8
		NiPoint3              nearestHitDir;                 // 0B4
		NiPoint2              freeRotation;                  // 0C0
		BSFixedString         animatedBoneName;              // 0C8
		NiAVObject*           thirdPersonCameraObj;          // 0D0
		NiNode*               thirdPersonFOVControl;         // 0D8
		NiPointer<NiAVObject> animatedBone;                  // 0E0
		float                 targetZoomOffset;              // 0E8
		float                 currentZoomOffset;             // 0EC
		float                 targetYaw;                     // 0F0
		float                 currentYaw;                    // 0F4
		float                 cameraHeightAdjust;            // 0F8
		float                 savedZoomOffset;               // 0FC
		float                 pitchZoomOffset;               // 100
		float                 zoomChange;                    // 104
		NiPoint2              startTogglePOVFreeRot;         // 108
		float                 collisionRecoveryFactor;       // 110
		float                 savedCollisionPercent;         // 114
		float                 animationBlend;                // 118
		float                 animationBlendDirection;       // 11C
		float                 searchDistanceBlend;           // 120
		float                 searchLastCameraYaw;           // 124
		bool                  freeRotationEnabled;           // 128
		bool                  zoomingInto1st;                // 129
		bool                  show3rdPersonModel;            // 12A
		bool                  preserveRotation;              // 12B
		bool                  animatorMode;                  // 12C
		bool                  applyOffsets;                  // 12D
		bool                  togglePOVPressRegistered;      // 12E
		bool                  wasUsingScreenSpaceLastFrame;  // 12F
		bool                  ironSights;                    // 130
	};
	static_assert(sizeof(ThirdPersonState) == 0x138);
}
