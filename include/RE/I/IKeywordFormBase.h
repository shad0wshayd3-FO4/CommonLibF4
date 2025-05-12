#pragma once

namespace RE
{
	class __declspec(novtable) IKeywordFormBase
	{
	public:
		static constexpr auto RTTI{ RTTI::IKeywordFormBase };
		static constexpr auto VTABLE{ VTABLE::IKeywordFormBase };

		virtual ~IKeywordFormBase() = default;  // 00

		// add
		virtual bool HasKeyword(const BGSKeyword* a_keyword, const TBO_InstanceData* a_data = nullptr) const = 0;                   // 01
		virtual void CollectAllKeywords(BSScrapArray<const BGSKeyword*>& a_outKeywords, const TBO_InstanceData* a_data) const = 0;  // 02
	};
	static_assert(sizeof(IKeywordFormBase) == 0x8);
}
