#pragma once

namespace RE
{
	class __declspec(novtable) BGSTextureModel :
		public TESModel  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSTextureModel };
		static constexpr auto VTABLE{ VTABLE::BGSTextureModel };
	};
	static_assert(sizeof(BGSTextureModel) == 0x30);
}
