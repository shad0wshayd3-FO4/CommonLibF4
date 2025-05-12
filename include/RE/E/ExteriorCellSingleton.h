#pragma once

#include "RE/B/BSTSingleton.h"

namespace RE
{
	class ExteriorCellSingleton :
		public BSTSingletonExplicit<ExteriorCellSingleton>
	{
	public:
		[[nodiscard]] static ExteriorCellSingleton* GetSingleton()
		{
			static REL::Relocation<ExteriorCellSingleton**> singleton{ REL::ID(2689084) };
			return *singleton;
		}

		//members
		NiPointer<bhkWorldM> exteriorWorld;
	};
	static_assert(sizeof(ExteriorCellSingleton) == 0x8);
}
