#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	class ContainerItemExtra
	{
	public:
		union Conditional
		{
			Conditional() :
				ownerGlobal(nullptr)
			{}

			~Conditional() = default;

			F4_HEAP_REDEFINE_NEW(Conditional);

			TESGlobal*   ownerGlobal;
			std::int32_t ownerRank;
			void*        u;
		};
		static_assert(sizeof(Conditional) == 0x8);

		ContainerItemExtra() :
			ownerForm(nullptr),
			conditional(),
			healthMult(100.0f)
		{}

		ContainerItemExtra(TESForm* a_owner) :
			ownerForm(a_owner),
			conditional(),
			healthMult(100.0f)
		{}

		F4_HEAP_REDEFINE_NEW(ContainerItemExtra);

		// members
		TESForm*    ownerForm;    // 00
		Conditional conditional;  // 08
		float       healthMult;   // 10
	};
	static_assert(sizeof(ContainerItemExtra) == 0x18);
}
