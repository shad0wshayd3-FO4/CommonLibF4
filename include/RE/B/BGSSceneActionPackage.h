#pragma once

namespace RE
{
	class __declspec(novtable) BGSSceneActionPackage :
		public BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionPackage };
		static constexpr auto VTABlE{ VTABLE::BGSSceneActionPackage };

		std::uint32_t         currentPackIndex;  // 20
		BSTArray<TESPackage*> packages;          // 28
	};
	static_assert(sizeof(BGSSceneActionPackage) == 0x40);
}
