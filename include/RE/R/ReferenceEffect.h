#pragma once

#include "RE/B/BSTempEffect.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class NiAVObject;
	class ReferenceEffectController;

	class __declspec(novtable) ReferenceEffect :
		public BSTempEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ReferenceEffect };
		static constexpr auto VTABLE{ VTABLE::ReferenceEffect };
		static constexpr auto Ni_RTTI{ Ni_RTTI::ReferenceEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kRefDefault };

		~ReferenceEffect() override;

		// add
		virtual bool        Init();                                // 37
		virtual void        Suspend();                             // 38
		virtual void        Resume();                              // 39
		virtual void        Update3D();                            // 3A
		virtual void        ClearTarget();                         // 3B
		virtual void        UpdateParentCell(NiAVObject* a_root);  // 3C
		virtual void        UpdatePosition();                      // 3D
		virtual NiAVObject* GetAttachRoot();                       // 3E
		virtual bool        GetAttached();                         // 3F
		virtual void        DetachImpl();                          // 40

		// members
		ReferenceEffectController* controller;     // 30
		ObjectRefHandle            target;         // 38
		ObjectRefHandle            aimAtTarget;    // 3C
		bool                       finished;       // 40
		bool                       ownController;  // 41
	};
	static_assert(sizeof(ReferenceEffect) == 0x48);
}
