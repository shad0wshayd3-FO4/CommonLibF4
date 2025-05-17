#include "RE/B/BGSKeywordForm.h"

namespace RE
{
	void BGSKeywordForm::CopyKeywords(const std::vector<BGSKeyword*>& a_copiedData)
	{
		const auto oldData = keywords;

		const auto newSize = a_copiedData.size();
		const auto newData = calloc<BGSKeyword*>(newSize);
		std::ranges::copy(a_copiedData, newData);

		numKeywords = static_cast<std::uint32_t>(newSize);
		keywords = newData;

		free(oldData);
	}

	bool BGSKeywordForm::AddKeywords(const std::vector<BGSKeyword*>& a_keywords)
	{
		std::vector<BGSKeyword*> copiedData{ keywords, keywords + numKeywords };
		std::ranges::remove_copy_if(a_keywords, std::back_inserter(copiedData), [&](auto& keyword) {
			return std::ranges::find(copiedData, keyword) != copiedData.end();
		});
		CopyKeywords(copiedData);
		return true;
	}

	bool BGSKeywordForm::ContainsKeywordString(std::string_view a_editorID) const
	{
		bool result = false;
		ForEachKeyword([&](const BGSKeyword* a_keyword) {
			if (a_keyword->formEditorID.contains(a_editorID)) {
				result = true;
				return BSContainer::ForEachResult::kStop;
			}
			return BSContainer::ForEachResult::kContinue;
		});
		return result;
	}

	bool BGSKeywordForm::HasKeywordID(TESFormID a_formID) const
	{
		bool result = false;
		ForEachKeyword([&](const BGSKeyword* a_keyword) {
			if (a_keyword->GetFormID() == a_formID) {
				result = true;
				return BSContainer::ForEachResult::kStop;
			}
			return BSContainer::ForEachResult::kContinue;
		});
		return result;
	}

	bool BGSKeywordForm::HasKeywordString(std::string_view a_editorID) const
	{
		bool result = false;
		ForEachKeyword([&](const BGSKeyword* a_keyword) {
			if (a_keyword->formEditorID == a_editorID) {
				result = true;
				return BSContainer::ForEachResult::kStop;
			}
			return BSContainer::ForEachResult::kContinue;
		});
		return result;
	}

	bool BGSKeywordForm::RemoveKeywords(const std::vector<BGSKeyword*>& a_keywords)
	{
		std::vector<BGSKeyword*> copiedData{ keywords, keywords + numKeywords };
		if (std::erase_if(copiedData, [&](auto& keyword) { return std::ranges::find(a_keywords, keyword) != a_keywords.end(); }) > 0) {
			CopyKeywords(copiedData);
			return true;
		}
		return false;
	}
}
