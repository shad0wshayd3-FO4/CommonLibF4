#pragma once

namespace RE
{
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
}
