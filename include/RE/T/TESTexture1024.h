#pragma once

#include "RE/T/TESTexture.h"

namespace RE
{
	class __declspec(novtable) TESTexture1024 :
		public TESTexture  // 10
	{
	public:
		static constexpr auto RTTI{ RTTI::TESTexture1024 };
		static constexpr auto VTABLE{ VTABLE::TESTexture1024 };

		// override (TESTexture)
		std::uint32_t GetMaxAllowedSize() override { return 1024; }  // 07
	};
	static_assert(sizeof(TESTexture1024) == 0x10);
}
