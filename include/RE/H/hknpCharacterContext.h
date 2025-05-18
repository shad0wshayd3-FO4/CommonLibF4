#pragma once

#include "RE/H/hkReferencedObject.h"
#include "RE/H/hknpCharacterState.h"
#include "RE/H/hkBool.h"
#include "RE/H/hkVector4f.h"

namespace RE
{
	class hknpCharacterStateManager;

	class hknpCharacterContext :
		public hkReferencedObject
	{
	public:
		enum class CharacterType;

		CharacterType                              characterType;             // 10
		const hknpCharacterStateManager*           stateManager;              // 18
		hknpCharacterState::hknpCharacterStateType currentState;              // 20
		hknpCharacterState::hknpCharacterStateType previousState;             // 24
		hkBool                                     filterEnable;              // 28
		float                                      maxLinearAcceleration;     // 2C
		float                                      maxLinearSpeed;            // 30
		float                                      gain;                      // 34
		std::byte                                  pad38[0x04];               // 38
		hkVector4f                                 previousSurfaceVelocity;   // 40
		std::int32_t                               numUpdatesInCurrentState;  // 50
		std::byte                                  pad54[0x0C];               // 54
	};
	static_assert(sizeof(hknpCharacterContext) == 0x60);
}
