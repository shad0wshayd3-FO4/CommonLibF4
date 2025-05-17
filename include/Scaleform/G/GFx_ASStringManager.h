#pragma once

#include "Scaleform/R/RefCountBase.h"

namespace Scaleform::GFx
{
	class __declspec(novtable) alignas(0x08) ASStringManager :
		public RefCountBase<ASStringManager, 324>  // 00
	{
	public:
		[[nodiscard]] ASStringNode* CreateStringNode(const char* a_str)
		{
			using func_t = decltype(&ASStringManager::CreateStringNode);
			static REL::Relocation<func_t> func{ ID::GFx::ASStringManager::CreateStringNode };
			return func(this, a_str);
		}

		// members
		std::byte pad10[0xA0 - 0x10];  // 10
	};
	static_assert(sizeof(ASStringManager) == 0xA0);
}
