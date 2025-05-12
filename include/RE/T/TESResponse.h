#pragma once

namespace RE
{
	struct TESResponse
	{
	public:
		struct RespData
		{
			std::uint16_t percent;
			std::uint8_t  responseID;
			bool          useEmotion;
		};
		static_assert(sizeof(RespData) == 0x4);

		const char* GetResponseText()
		{
			using func_t = decltype(&TESResponse::GetResponseText);
			static REL::Relocation<func_t> func{ REL::ID(2208288) };
			return func(this);
		}

		TESIdleForm* GetSpeakerIdle()
		{
			using func_t = decltype(&TESResponse::GetSpeakerIdle);
			static REL::Relocation<func_t> func{ REL::ID(2208293) };
			return func(this);
		}

		// Members
		BGSLocalizedString                                    responseText;
		TESResponse* pNext;
		TESResponse::RespData                                 data;
		BGSTypedKeywordValue<KeywordType::kAnimFaceArchetype> faceArcheType;
	};
	static_assert(sizeof(TESResponse) == 0x18);
}
