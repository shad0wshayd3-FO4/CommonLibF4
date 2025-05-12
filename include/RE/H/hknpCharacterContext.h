#pragma once

namespace RE
{
	class __declspec(novtable) hknpCharacterContext :
		public hkReferencedObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::hknpCharacterContext };
		static constexpr auto VTABLE{ VTABLE::hknpCharacterContext };

		enum class CharacterType
		{
			kProxy,
			kRigidBody
		};

		// members
		REX::EnumSet<CharacterType, std::int32_t>                              characterType;             // 10
		hknpCharacterStateManager*                                             stateManager;              // 18
		REX::EnumSet<hknpCharacterState::hknpCharacterStateType, std::int32_t> currentState;              // 20
		REX::EnumSet<hknpCharacterState::hknpCharacterStateType, std::int32_t> previousState;             // 24
		hkBool                                                                 filterEnable;              // 28
		float                                                                  maxLinearAcceleration;     // 2C
		float                                                                  maxLinearSpeed;            // 30
		float                                                                  gain;                      // 34
		hkVector4f                                                             previousSurfaceVelocity;   // 40
		std::int32_t                                                           numUpdatesInCurrentState;  // 50
	};
	static_assert(sizeof(hknpCharacterContext) == 0x60);
}
