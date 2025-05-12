#pragma once

namespace RE
{
	class TESFileArray :
		public BSStaticArray<TESFile*>  // 00
	{
	public:
	};
	static_assert(sizeof(TESFileArray) == 0x10);
}
