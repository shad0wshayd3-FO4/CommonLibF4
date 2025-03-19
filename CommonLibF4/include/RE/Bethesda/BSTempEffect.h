#pragma once

#include "RE/Bethesda/BSAttachTechniques.h"
#include "RE/Bethesda/BSModelDB.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSSoundHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/BSTextureDB.h"
#include "RE/NetImmerse/NiMatrix3.h"
#include "RE/NetImmerse/NiObject.h"
#include "RE/NetImmerse/NiQuaternion.h"
#include "RE/NetImmerse/NiSmartPointer.h"

#define F4SE_TEMPEFFECT_UTIL(a_elem)                                    \
	case a_elem::TYPE:                                                  \
		if constexpr (std::is_convertible_v<const a_elem*, const T*>) { \
			return static_cast<const a_elem*>(this);                    \
		}                                                               \
		break

namespace RE
{
	class bhkWorld;
	class BGSDecalEmitter;
	class BGSImpactData;
	class BGSLoadGameBuffer;
	class BGSArtObjectCloneTask;
	class BGSParticleObjectCloneTask;
	class BGSSaveGameBuffer;
	class BGSShaderParticleGeometryData;
	class BSGeometry;
	class BSTempEffectWeaponBlood;
	class BSTempEffectScreenSpaceDecal;
	class BSTempEffectGeometryDecal;
	class BSTempEffectParticle;
	class BSTempEffectDebris;
	class BSTempEffectSPG;
	class BSTerrainEffect;
	class ModelReferenceEffect;
	class NiAVObject;
	class NiSourceTexture;
	class ReferenceEffect;
	class ReferenceEffectController;
	class ShaderReferenceEffect;
	class SummonPlacementEffect;
	class TESObjectCELL;
	class TESObjectREFR;

	namespace BSDeferredDecal
	{
		struct BSDFDecal;
	}

	struct PositionPlayerEvent;
	struct SkinnedDecalCSData;

	enum class TEMP_EFFECT_TYPE
	{
		kTerrain = 0x0,
		kWeaponBlood = 0x1,
		kDecal = 0x2,
		kGeometryDecal = 0x3,
		kParticle = 0x4,
		kDebris = 0x5,
		kSPG = 0x6,
		kDefault = 0x7,
		kRefDefault = 0x8,
		kRefModel = 0x9,
		kRefShader = 0xA,
		kMagicSummon = 0xB
	};

	class __declspec(novtable) BSTempEffect :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTempEffect };
		static constexpr auto VTABLE{ VTABLE::BSTempEffect };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kDefault };

		// add
		virtual void                           Initialize();                                     // 25 - { initialized = true; }
		virtual void                           Attach();                                         // 26 - { return; }
		virtual void                           Detach();                                         // 27 - { return; }
		virtual bool                           Update(float a_arg1);                             // 28
		[[nodiscard]] virtual NiAVObject*      Get3D() const;                                    // 29 - { return 0; }
		[[nodiscard]] virtual bool             GetManagerHandlesSaveLoad() const;                // 2A - { return true; }
		[[nodiscard]] virtual bool             GetClearWhenCellIsUnloaded() const;               // 2B - { return true; }
		[[nodiscard]] virtual TEMP_EFFECT_TYPE GetType() const;                                  // 2C - { return 7; }
		virtual void                           SaveGame(BGSSaveGameBuffer* a_buf);               // 2D
		virtual void                           LoadGame(BGSLoadGameBuffer* a_buf);               // 2E
		virtual void                           FinishLoadGame(BGSLoadGameBuffer* a_buf);         // 2F - { return; }
		[[nodiscard]] virtual bool             IsInterfaceEffect() const;                        // 30 - { return false; }
		virtual void                           SetInterfaceEffect(bool a_set);                   // 31 - { return; }
		[[nodiscard]] virtual bool             GetStackable() const;                             // 32 - { return false; }
		virtual bool                           GetStackableMatch(BSTempEffect* a_effect) const;  // 33 - { return false; }
		virtual void                           Push();                                           // 34 - { return; }
		virtual void                           Pop();                                            // 35 - { return; }
		virtual void                           HandleDeferredDeleteImpl();                       // 36

		template <
			class T,
			class = std::enable_if_t<
				std::negation_v<
					std::disjunction<
						std::is_pointer<T>,
						std::is_reference<T>,
						std::is_const<T>,
						std::is_volatile<T>>>>>
		[[nodiscard]] T* As() noexcept
		{
			return const_cast<T*>(static_cast<const BSTempEffect*>(this)->As<T>());
		}

		template <
			class T,
			class = std::enable_if_t<
				std::negation_v<
					std::disjunction<
						std::is_pointer<T>,
						std::is_reference<T>,
						std::is_const<T>,
						std::is_volatile<T>>>>>
		[[nodiscard]] const T* As() const noexcept
		{
			switch (GetType()) {
				F4SE_TEMPEFFECT_UTIL(BSTerrainEffect);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectWeaponBlood);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectScreenSpaceDecal);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectGeometryDecal);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectParticle);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectDebris);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectSPG);
				F4SE_TEMPEFFECT_UTIL(BSTempEffect);
				F4SE_TEMPEFFECT_UTIL(ReferenceEffect);
				F4SE_TEMPEFFECT_UTIL(ModelReferenceEffect);
				F4SE_TEMPEFFECT_UTIL(ShaderReferenceEffect);
				F4SE_TEMPEFFECT_UTIL(SummonPlacementEffect);
				default:
					break;
			}

			return nullptr;
		}

		// members
		float          lifetime;     // 10
		TESObjectCELL* cell;         // 18
		float          age;          // 20
		bool           initialized;  // 24
		std::uint32_t  effectID;     // 28
	};
	static_assert(sizeof(BSTempEffect) == 0x30);

	class __declspec(novtable) BSTerrainEffect :
		public BSTempEffect,                      // 00
		public BSTEventSink<PositionPlayerEvent>  // 30
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTerrainEffect };
		static constexpr auto VTABLE{ VTABLE::BSTerrainEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kTerrain };

		struct BoneAdjustment
		{
		public:
			// members
			NiMatrix3   rotation;  // 00
			NiAVObject* pBone;     // 30
			float       fZOffset;  // 38
		};
		static_assert(sizeof(BoneAdjustment) == 0x40);

		~BSTerrainEffect() override;

		// members
		NiQuaternion                              orientation;         // 38
		NiPoint3                                  position;            // 48
		BSTArray<BSTerrainEffect::BoneAdjustment> terrainAdjustments;  // 58
		BSTArray<BSTerrainEffect::BoneAdjustment> dynamicAdjustments;  // 70
		NiPointer<NiNode>                         model;               // 88
		BSResource::ID                            modelID;             // 90
		ObjectRefHandle                           target;              // 9C
		NiPointer<bhkWorld>                       physWorld;           // A0
		std::uint32_t                             physGroup;           // A8
		NiPointer<NiAVObject>                     followNode;          // B0
	};
	static_assert(sizeof(BSTerrainEffect) == 0xB8);

	class __declspec(novtable) BSTempEffectWeaponBlood :
		public BSTempEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTempEffectWeaponBlood };
		static constexpr auto VTABLE{ VTABLE::BSTempEffectWeaponBlood };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kWeaponBlood };

		~BSTempEffectWeaponBlood() override;

		// members
		NiPointer<NiAVObject> weapon;        // 30
		float                 fBloodAmount;  // 38
	};
	static_assert(sizeof(BSTempEffectWeaponBlood) == 0x40);

	class __declspec(novtable) BSTempEffectScreenSpaceDecal :
		public BSTempEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::__BSTempEffectScreenSpaceDecal };
		static constexpr auto VTABLE{ VTABLE::__BSTempEffectScreenSpaceDecal };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffectScreenSpaceDecal };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kDecal };

		~BSTempEffectScreenSpaceDecal() override;

		// members
		bool                                  permanent;  // 30
		NiPointer<BSDeferredDecal::BSDFDecal> decal;      // 38
	};
	static_assert(sizeof(BSTempEffectScreenSpaceDecal) == 0x40);

	class __declspec(novtable) BSTempEffectGeometryDecal :
		public BSTempEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTempEffectGeometryDecal };
		static constexpr auto VTABLE{ VTABLE::BSTempEffectGeometryDecal };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffectGeometryDecal };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kGeometryDecal };

		~BSTempEffectGeometryDecal() override;

		// members
		SkinnedDecalCSData*   CSData;         // 30
		TextureDBHandle       baseTexture;    // 38
		NiPointer<BSGeometry> decalGeometry;  // 40
		NiPointer<BSTriShape> geometry;       // 48
		std::uint16_t*        oldIndex;       // 50
		NiPointer<NiNode>     parent;         // 58
		NiPointer<NiNode>     decalParent;    // 68
		alignas(0x10) NiMatrix3 projection;   // 70
		NiPoint3      origin;                 // A0
		NiPoint3      vector;                 // AC
		float         scale;                  // B8
		std::int32_t  numVerts;               // BC
		std::uint32_t bodyParts;              // C0
		float         decalRotation;          // C4
		std::uint8_t  subTex;                 // C8
		bool          decalLoaded;            // C9
		bool          fading;                 // CA
	};
	static_assert(sizeof(BSTempEffectGeometryDecal) == 0xD0);

	class __declspec(novtable) BSTempEffectParticle :
		public BSTempEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTempEffectParticle };
		static constexpr auto VTABLE{ VTABLE::BSTempEffectParticle };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffectParticle };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kParticle };

		~BSTempEffectParticle() override;

		// members
		NiPointer<NiAVObject>                 particleObject;   // 30
		NiPointer<BGSParticleObjectCloneTask> cloneTask;        // 38
		BSModelDB::Handle                     modelHandle;      // 40
		NiPointer<NiNode>                     parentNode;       // 48
		NiMatrix3                             rotation;         // 50
		NiPoint3                              position;         // 80
		float                                 scale;            // 8C
		std::uint32_t                         flags;            // 90
		NiPointer<NiAVObject>                 followObject;     // 98
		NiTransform                           followOffset;     // A0
		BGSImpactData*                        decalImpactData;  // E0
		BGSDecalEmitter*                      decalEmitter;     // E8
		BSSoundHandle                         sound1;           // F0
		BSSoundHandle                         sound2;           // F8
	};
	static_assert(sizeof(BSTempEffectParticle) == 0x100);

	class __declspec(novtable) BSTempEffectDebris :
		public BSTempEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTempEffectDebris };
		static constexpr auto VTABLE{ VTABLE::BSTempEffectDebris };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffectDebris };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kDebris };

		BSTempEffectDebris(
			TESObjectCELL*   a_parentCell,
			float            a_lifetime,
			const char*      a_fileName,
			TESObjectREFR*   a_sourceRef,
			const NiPoint3&  a_position,
			const NiMatrix3& a_rotation,
			const NiPoint3&  a_startLinearVelocity,
			const NiPoint3&  a_startAngularVelocity,
			float            a_scale,
			bool             a_useCache,
			bool             a_addDebrisCount,
			bool             isFirstPerson)
		{
			using func_t = BSTempEffectDebris* (*)(BSTempEffectDebris*, TESObjectCELL*, float, const char*, TESObjectREFR*, const NiPoint3&, const NiMatrix3&, const NiPoint3&, const NiPoint3&, float, bool, bool, bool);
			static REL::Relocation<func_t> func{ REL::ID(2212059) };
			func(this, a_parentCell, a_lifetime, a_fileName, a_sourceRef, a_position, a_rotation, a_startLinearVelocity, a_startAngularVelocity, a_scale, a_useCache, a_addDebrisCount, isFirstPerson);
		}

		~BSTempEffectDebris() override;

		// members
		NiPointer<NiAVObject> debris3D;          // 30
		const char*           debrisFilename;    // 38
		bool                  useDebrisCounter;  // 40
		bool                  forceDelete;       // 41
		bool                  firstPerson;       // 42
	};
	static_assert(sizeof(BSTempEffectDebris) == 0x48);

	class __declspec(novtable) BSTempEffectSPG :
		public BSTempEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTempEffectSPG };
		static constexpr auto VTABLE{ VTABLE::BSTempEffectSPG };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffectSPG };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kSPG };

		~BSTempEffectSPG() override;

		// members
		BGSShaderParticleGeometryData* SPGData;        // 30
		NiPointer<BSGeometry>          geometry;       // 38
		float                          totalFadeTime;  // 40
		float                          fadeTime;       // 44
		bool                           fadeIn;         // 48
	};
	static_assert(sizeof(BSTempEffectSPG) == 0x50);

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

	class __declspec(novtable) ModelReferenceEffect :
		public ReferenceEffect,                     // 00
		public SimpleAnimationGraphManagerHolder,   // 48
		public BSTEventSink<BSAnimationGraphEvent>  // 60
	{
	public:
		static constexpr auto RTTI{ RTTI::ModelReferenceEffect };
		static constexpr auto VTABLE{ VTABLE::ModelReferenceEffect };
		static constexpr auto Ni_RTTI{ Ni_RTTI::ModelReferenceEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kRefModel };

		~ModelReferenceEffect() override;

		// members
		RefAttachTechniqueInput          hitEffectArtData;     // 70
		void*                            loadedDataSubBuffer;  // B8
		BGSArtObject*                    artObject;            // C0
		NiPointer<BGSArtObjectCloneTask> cloneTask;            // C8
		NiPointer<NiAVObject>            artObject3D;          // D0
		std::uint32_t                    flags;                // D4
	};
	static_assert(sizeof(ModelReferenceEffect) == 0xD8);

	class BSMagicShaderParticles
	{
	public:
		using Filter = bool(NiAVObject*);

		// members
		BSModelDB::Handle protoSystem;         // 00
		NiPointer<NiNode> particlesRoot;       // 08
		bool              hasData;             // 10
		bool              attached;            // 11
		bool              stopped;             // 12
		bool              useSizeAdjustments;  // 13
		Filter*           filterFunction;      // 18
	};
	static_assert(sizeof(BSMagicShaderParticles) == 0x20);

	class __declspec(novtable) ShaderReferenceEffect :
		public ReferenceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ShaderReferenceEffect };
		static constexpr auto VTABLE{ VTABLE::ShaderReferenceEffect };
		static constexpr auto Ni_RTTI{ Ni_RTTI::ShaderReferenceEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kRefShader };

		~ShaderReferenceEffect() override;

		// members
		BSMagicShaderParticles                                     particles;               // 048
		BSTArray<BSTTuple<TextureDBHandle, NiPointer<NiTexture>*>> textureRequests;         // 068
		BSTArray<NiPointer<NiAVObject>>                            addOnObjects;            // 080
		BSTArray<BSModelDB::Handle>                                modelHandles;            // 098
		BSTArray<NiPointer<NiAVObject>>                            targetArray;             // 0B0
		BSSoundHandle                                              soundHandle;             // 0C8
		NiPointer<NiSourceTexture>                                 textureShaderTexture;    // 0D0
		NiPointer<NiSourceTexture>                                 textureBlockOutTexture;  // 0D8
		NiPointer<NiSourceTexture>                                 texturePaletteTexture;   // 0E0
		TESBoundObject*                                            wornObject;              // 0E8
		TESEffectShader*                                           effectData;              // 0F0
		BSEffectShaderData*                                        effectShaderData;        // 0F8
		NiPointer<NiAVObject>                                      lastRootNode;            // 100
		float                                                      alphaTimer;              // 104
		float                                                      addonAlpha;              // 108
		float                                                      addonScale;              // 10C
		float                                                      effectShaderAge;         // 110
		std::uint32_t                                              flags;                   // 114
		std::uint32_t                                              pushCount;               // 118
	};
	static_assert(sizeof(ShaderReferenceEffect) == 0x120);

	class __declspec(novtable) SummonPlacementEffect :
		public ReferenceEffect,                     // 00
		public SimpleAnimationGraphManagerHolder,   // 48
		public BSTEventSink<BSAnimationGraphEvent>  // 60
	{
	public:
		static constexpr auto RTTI{ RTTI::SummonPlacementEffect };
		static constexpr auto VTABLE{ VTABLE::SummonPlacementEffect };
		static constexpr auto Ni_RTTI{ Ni_RTTI::SummonPlacementEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kMagicSummon };

		~SummonPlacementEffect() override;

		// members
		BGSArtObject*                    artObject;            // 70
		NiPoint3                         fixedLocation;        // 78
		NiPointer<NiAVObject>            artObject3D;          // 88
		void*                            loadedDataSubBuffer;  // 90
		NiPointer<BGSArtObjectCloneTask> cloneTask;            // 98
		bool                             animationComplete;    // 99
	};
	static_assert(sizeof(SummonPlacementEffect) == 0xA0);
}

#undef F4SE_TEMPEFFECT_UTIL
