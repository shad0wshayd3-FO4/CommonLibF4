#pragma once

#include "RE/A/AttachTechniqueInput.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class bhkWorld;

	class __declspec(novtable) RefAttachTechniqueInput :
		public BSAttachTechniques::AttachTechniqueInput  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::RefAttachTechniqueInput };
		static constexpr auto VTABLE{ VTABLE::RefAttachTechniqueInput };

		// members
		TESObjectREFR* object;           // 20
		TESRace*       race;             // 28
		bhkWorld*      havokWorld;       // 30
		std::uint32_t  collisionGroup;   // 38
		BSFixedString  techniqueSuffix;  // 40
	};
	static_assert(sizeof(RefAttachTechniqueInput) == 0x48);
}
