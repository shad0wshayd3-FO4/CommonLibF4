#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/B/BGSProjectileData.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESModel.h"

namespace RE
{
	enum class SOUND_LEVEL;

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
			static REL::Relocation<func_t> func{ ID::BGSProjectile::CollidesWithSmallTransparentLayer };
			return func(this);
		}

		// members
		BGSProjectileData                       data;              // 0C0
		TESModel                                muzzleFlashModel;  // 150
		REX::EnumSet<SOUND_LEVEL, std::int32_t> soundLevel;        // 180
	};
	static_assert(sizeof(BGSProjectile) == 0x188);
}
