#pragma once

#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BGSTypedKeywordValue.h"

namespace RE
{
	class TESResponse
	{
	public:
		class RespData
		{
			std::uint16_t percent;
			std::uint8_t  responseID;
			bool          useEmotion;
		};
		static_assert(sizeof(RespData) == 0x4);

		const char* GetResponseText()
		{
			using func_t = decltype(&TESResponse::GetResponseText);
			static REL::Relocation<func_t> func{ ID::TESResponse::GetResponseText };
			return func(this);
		}

		TESIdleForm* GetSpeakerIdle()
		{
			using func_t = decltype(&TESResponse::GetSpeakerIdle);
			static REL::Relocation<func_t> func{ ID::TESResponse::GetSpeakerIdle };
			return func(this);
		}

		// members
		BGSLocalizedString                                    responseText;
		TESResponse*                                          pNext;
		RespData                                              data;
		BGSTypedKeywordValue<KeywordType::kAnimFaceArchetype> faceArcheType;
	};
	static_assert(sizeof(TESResponse) == 0x18);
}
