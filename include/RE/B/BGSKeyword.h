#pragma once

namespace RE
{
	class __declspec(novtable) BGSKeyword :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSKeyword };
		static constexpr auto VTABLE{ VTABLE::BGSKeyword };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kKYWD };

		[[nodiscard]] static uint16_t GetIndexForTypedKeyword(const BGSKeyword* a_keyword, KeywordType a_type)
		{
			assert(a_type < KeywordType::kTotal);
			const auto keywords = GetTypedKeywords();
			if (keywords) {
				const auto& arr = (*keywords)[std::to_underlying(a_type)];
				for (uint16_t i = 0; i < arr.size(); ++i) {
					if (arr[i] == a_keyword) {
						return i;
					}
				}
			}
			return 0xFFFF;
		}

		[[nodiscard]] static BGSKeyword* GetTypedKeywordByIndex(KeywordType a_type, std::uint16_t a_index)
		{
			assert(a_type < KeywordType::kTotal);
			const auto keywords = GetTypedKeywords();
			if (keywords) {
				const auto& arr = (*keywords)[std::to_underlying(a_type)];
				return a_index < arr.size() ? arr[a_index] : nullptr;
			}
			else {
				return nullptr;
			}
		}

		[[nodiscard]] static auto GetTypedKeywords()
			-> std::optional<std::span<BSTArray<BGSKeyword*>, std::to_underlying(KeywordType::kTotal)>>
		{
			static REL::Relocation<BSTArray<BGSKeyword*>(*)[std::to_underlying(KeywordType::kTotal)]> keywords{ REL::ID(1095775) };
			if (*keywords) {
				return { *keywords };
			}
			else {
				return std::nullopt;
			}
		}

		// members
		BSFixedString formEditorID;  // 20
	};
	static_assert(sizeof(BGSKeyword) == 0x28);
}
