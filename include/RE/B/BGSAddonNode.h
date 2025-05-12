#pragma once

#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class __declspec(novtable) BGSAddonNode :
		public TESBoundObject,       // 00
		public BGSModelMaterialSwap  // 68
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAddonNode };
		static constexpr auto VTABLE{ VTABLE::BGSAddonNode };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kADDN };

		// members
		std::uint32_t           index;               // A8
		BGSSoundDescriptorForm* sound;               // B0
		TESObjectLIGH*          light;               // B8
		ADDON_DATA              data;                // C0
		BSNonReentrantSpinLock  masterParticleLock;  // C4
	};
	static_assert(sizeof(BGSAddonNode) == 0xC8);
}
