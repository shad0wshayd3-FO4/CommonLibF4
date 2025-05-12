#pragma once

namespace RE
{
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
}
