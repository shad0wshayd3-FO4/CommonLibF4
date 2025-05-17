#include "RE/B/BGSKeyword.h"

namespace RE
{
	namespace detail
	{
		BGSKeyword* BGSKeywordGetTypedKeywordByIndex(KeywordType a_type, std::uint16_t a_index)
		{
			return BGSKeyword::GetTypedKeywordByIndex(a_type, a_index);
		}

		std::uint16_t BGSKeywordGetIndexForTypedKeyword(BGSKeyword* a_keyword, KeywordType a_type)
		{
			return BGSKeyword::GetIndexForTypedKeyword(a_keyword, a_type);
		}
	}
}
