#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/I/IKeywordFormBase.h"

namespace RE
{
	class __declspec(novtable) BGSKeywordForm :
		public BaseFormComponent,  // 00
		public IKeywordFormBase    // 08
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSKeywordForm };
		static constexpr auto VTABLE{ VTABLE::BGSKeywordForm };

		// override (BaseFormComponent)
		void InitializeDataComponent() override { return; }  // 02
		void ClearDataComponent() override;                  // 03
		void InitComponent() override { return; }            // 04
		void CopyComponent(BaseFormComponent*) override;     // 06

		// override (IKeywordFormBase)
		bool HasKeyword(const BGSKeyword* a_keyword, const TBO_InstanceData* a_data = nullptr) const override;  // 01
		void CollectAllKeywords(BSScrapArray<const BGSKeyword*>&, const TBO_InstanceData*) const override;      // 02

		// add
		virtual BGSKeyword* GetDefaultKeyword() const { return nullptr; }  // 07

		void CopyKeywords(const std::vector<RE::BGSKeyword*>& a_copiedData);

		void AddKeyword(BGSKeyword* a_keyword)
		{
			using func_t = decltype(&BGSKeywordForm::AddKeyword);
			static REL::Relocation<func_t> func{ REL::ID(2192766) };
			return func(this, a_keyword);
		}

		bool AddKeywords(const std::vector<BGSKeyword*>& a_keywords);

		[[nodiscard]] bool ContainsKeywordString(std::string_view a_editorID) const;
		[[nodiscard]] bool HasKeywordID(TESFormID a_formID) const;
		[[nodiscard]] bool HasKeywordString(std::string_view a_editorID) const;

		void ForEachKeyword(std::function<BSContainer::ForEachResult(BGSKeyword*)> a_callback) const
		{
			if (keywords) {
				for (std::uint32_t idx = 0; idx < numKeywords; ++idx) {
					if (keywords[idx] && a_callback(keywords[idx]) == BSContainer::ForEachResult::kStop) {
						return;
					}
				}
			}
		}

		[[nodiscard]] std::optional<BGSKeyword*> GetKeywordAt(std::uint32_t a_idx) const
		{
			if (a_idx < numKeywords) {
				return std::make_optional(keywords[a_idx]);
			} else {
				return std::nullopt;
			}
		}

		[[nodiscard]] std::optional<std::uint32_t> GetKeywordIndex(BGSKeyword* a_keyword) const
		{
			if (keywords) {
				for (std::uint32_t i = 0; i < numKeywords; ++i) {
					if (keywords[i] == a_keyword) {
						return i;
					}
				}
			}
			return std::nullopt;
		}

		[[nodiscard]] std::uint32_t GetNumKeywords() const { return numKeywords; };

		void RemoveKeyword(BGSKeyword* a_keyword)
		{
			using func_t = decltype(&BGSKeywordForm::RemoveKeyword);
			static REL::Relocation<func_t> func{ REL::ID(921694) };
			return func(this, a_keyword);
		}

		bool RemoveKeywords(const std::vector<BGSKeyword*>& a_keywords);

		// members
		BGSKeyword**  keywords;     // 10
		std::uint32_t numKeywords;  // 18
	};
	static_assert(sizeof(BGSKeywordForm) == 0x20);
}
