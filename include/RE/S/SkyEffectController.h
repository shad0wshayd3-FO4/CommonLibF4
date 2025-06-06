#pragma once

#include "RE/R/ReferenceEffectController.h"

namespace RE
{
	class __declspec(novtable) SkyEffectController :
		public ReferenceEffectController  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::SkyEffectController };
		static constexpr auto VTABLE{ VTABLE::SkyEffectController };

		// override (ReferenceEffectController)
		void             RemoveHitEffect(ReferenceEffect* a_refEffect) override;  // 0A - { return; }
		TESObjectREFR*   GetTargetReference() override;                           // 0B - { return g_thePlayer; }
		BGSArtObject*    GetHitEffectArt() override;                              // 0C - { return GetSkyReferenceEffectArt(); }
		TESEffectShader* GetHitEffectShader() override;                           // 0D - { return 0; }
		bool             GetManagerHandlesSaveLoad() override;                    // 0E - { return 0; }
		NiAVObject*      GetAttachRoot() override;                                // 0F
		bool             EffectAttachesToCamera() override;                       // 1A - { return true; }
		bool             EffectRotatesWithCamera() override;                      // 1B
	};
	static_assert(sizeof(SkyEffectController) == 0x8);
}
