#pragma once

namespace RE
{
	class __declspec(novtable) BGSProjectile :
		public TESBoundObject,            // 000
		public TESFullName,               // 068
		public TESModel,                  // 078
		public BGSPreloadable,            // 0A8
		public BGSDestructibleObjectForm  // 0B0
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSProjectile };
		static constexpr auto VTABLE{ VTABLE::BGSProjectile };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPROJ };

		bool CollidesWithSmallTransparentLayer()
		{
			using func_t = decltype(&BGSProjectile::CollidesWithSmallTransparentLayer);
			static REL::Relocation<func_t> func{ REL::ID(2197620) };
			return func(this);
		}

		// members
		BGSProjectileData                       data;              // 0C0
		TESModel                                muzzleFlashModel;  // 150
		REX::EnumSet<SOUND_LEVEL, std::int32_t> soundLevel;        // 180
	};
	static_assert(sizeof(BGSProjectile) == 0x188);
}
