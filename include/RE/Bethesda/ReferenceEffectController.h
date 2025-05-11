#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/NetImmerse/NiPoint.h"

namespace RE
{
	class ActiveEffect;
	class BGSArtObject;
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;
	class NiAVObject;
	class NiNode;
	class ReferenceEffect;
	class TESEffectShader;
	class TESObjectREFR;

	class __declspec(novtable) ReferenceEffectController
	{
	public:
		static constexpr auto RTTI{ RTTI::ReferenceEffectController };
		static constexpr auto VTABLE{ VTABLE::ReferenceEffectController };

		virtual ~ReferenceEffectController();  // 00

		// add
		virtual void             HandleEvent(const BSFixedString& a_event);                 // 01 - { return; }
		virtual float            GetElapsedTime();                                          // 02 - { return 0.0; }
		virtual float            GetScale();                                                // 03 - { return 1.0; }
		virtual void             SwitchAttachedRoot(NiNode* a_root, NiNode* a_attachRoot);  // 04 - { return; }
		virtual const NiPoint3&  GetSourcePosition();                                       // 05 - { return NiPoint3(); }
		virtual bool             GetUseSourcePosition();                                    // 06 - { return true; }
		virtual bool             GetNoInitialFlare();                                       // 07 - { return false; }
		virtual bool             GetEffectPersists();                                       // 08 - { return true; }
		virtual bool             GetGoryVisuals();                                          // 09 - { return false; }
		virtual void             RemoveHitEffect(ReferenceEffect* a_refEffect);             // 0A - { return; }
		virtual TESObjectREFR*   GetTargetReference() = 0;                                  // 0B
		virtual BGSArtObject*    GetHitEffectArt() = 0;                                     // 0C
		virtual TESEffectShader* GetHitEffectShader() = 0;                                  // 0D
		virtual bool             GetManagerHandlesSaveLoad() = 0;                           // 0E
		virtual NiAVObject*      GetAttachRoot();                                           // 0F - { auto ref = GetTargetReference(); return ref ? ref->Get3D() : 0; }
		virtual float            GetParticleAttachExtent();                                 // 10 - { return 0.0; }
		virtual bool             GetUseParticleAttachExtent();                              // 11 - { return false; }
		virtual bool             GetDoParticles();                                          // 12 - { return true; }
		virtual bool             GetParticlesUseLocalSpace();                               // 13 - { return false; }
		virtual bool             GetUseRootWorldRotate();                                   // 14 - { return false; }
		virtual bool             GetIsRootActor();                                          // 15 - { auto ref = GetTargetReference(); return ref ? ref->formType = FormType::ActorCharacter : false; }
		virtual bool             GetClearWhenCellIsUnloaded();                              // 16 - { return false; }
		virtual bool             EffectShouldFaceTarget();                                  // 17 - { return false; }
		virtual TESObjectREFR*   GetFacingTarget();                                         // 18 - { return 0; }
		virtual bool             GetShaderUseParentCell();                                  // 19 - { return true; }
		virtual bool             EffectAttachesToCamera();                                  // 1A - { return false; }
		virtual bool             EffectRotatesWithCamera();                                 // 1B - { return false; }
		virtual bool             GetAllowTargetRoot();                                      // 1C - { return true; }
		virtual bool             IsReadyForAttach();                                        // 1D - { return true; }
		virtual void             SetWindPoint(const NiPoint3& a_point);                     // 1E - { return; }
		virtual const NiPoint3&  GetWindPoint();                                            // 1F - { return NiPoint3(); }
		virtual bool             GetAllowNo3D();                                            // 20 - { return false; }
		virtual void             SaveGame(BGSSaveGameBuffer* a_buf);                        // 21 - { return; }
		virtual void             LoadGame(BGSLoadGameBuffer* a_buf);                        // 22 - { return; }
	};
	static_assert(sizeof(ReferenceEffectController) == 0x8);

	class __declspec(novtable) ActiveEffectReferenceEffectController :
		public ReferenceEffectController  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ActiveEffectReferenceEffectController };
		static constexpr auto VTABLE{ VTABLE::ActiveEffectReferenceEffectController };

		// override (ReferenceEffectController)
		void             HandleEvent(const BSFixedString& a_event) override;                 // 01 - return { effect->HandleEvent(a_event); }
		float            GetElapsedTime() override;                                          // 02 - return { effect->elapsedSeconds; }
		float            GetScale() override;                                                // 03
		void             SwitchAttachedRoot(NiNode* a_root, NiNode* a_attachRoot) override;  // 04 - return { effect->SwitchAttachedRoot(a_root, a_attachRoot); }
		const NiPoint3&  GetSourcePosition() override;                                       // 05
		bool             GetUseSourcePosition() override;                                    // 06
		bool             GetNoInitialFlare() override;                                       // 07
		bool             GetEffectPersists() override;                                       // 08
		bool             GetGoryVisuals() override;                                          // 09
		void             RemoveHitEffect(ReferenceEffect* a_refEffect) override;             // 0A
		TESObjectREFR*   GetTargetReference() override;                                      // 0B
		BGSArtObject*    GetHitEffectArt() override;                                         // 0C
		TESEffectShader* GetHitEffectShader() override;                                      // 0D
		bool             GetManagerHandlesSaveLoad() override;                               // 0E - { return false; }
		bool             EffectShouldFaceTarget() override;                                  // 17
		TESObjectREFR*   GetFacingTarget() override;                                         // 18
		void             SetWindPoint(const NiPoint3& a_point) override;                     // 1E - { windPoint = a_point; }
		const NiPoint3&  GetWindPoint() override;                                            // 1F - { return windPoint; }
		bool             GetAllowNo3D() override;                                            // 20
		void             SaveGame(BGSSaveGameBuffer* a_buf) override;                        // 21
		void             LoadGame(BGSLoadGameBuffer* a_buf) override;                        // 22

		// members
		ActiveEffect*   effect;     // 08
		NiPoint3        windPoint;  // 10
		ObjectRefHandle target;     // 18
	};
	static_assert(sizeof(ActiveEffectReferenceEffectController) == 0x20);

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
