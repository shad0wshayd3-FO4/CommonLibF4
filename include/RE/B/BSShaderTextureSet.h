#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTextureSet.h"

namespace RE
{
	class __declspec(novtable) BSShaderTextureSet :
		public BSTextureSet  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShaderTextureSet };
		static constexpr auto VTABLE{ VTABLE::BSShaderTextureSet };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSShaderTextureSet };

		static BSShaderTextureSet* CreateObject()
		{
			using func_t = decltype(&BSShaderTextureSet::CreateObject);
			static REL::Relocation<func_t> func{ ID::BSShaderTextureSet::CreateObject };
			return func();
		}

		// members
		BSFixedString textureNames[10];  // 10
	};
	static_assert(sizeof(BSShaderTextureSet) == 0x60);
}
