#pragma once

namespace RE
{
	class __declspec(novtable) BSISoundOutputModel
	{
	public:
		static constexpr auto RTTI{ RTTI::BSISoundOutputModel };
		static constexpr auto VTABLE{ VTABLE::BSISoundOutputModel };

		struct BSIAttenuationCharacteristics;

		virtual ~BSISoundOutputModel() = default;  // 00

		// add
		virtual bool                                 DoGetUsesHRTF() const = 0;                                                                               // 01
		virtual bool                                 DoGetHasSpeakerBias() const = 0;                                                                         // 02
		virtual bool                                 DoGetSpeakerBias(std::uint32_t a_srcChannels, std::uint32_t a_channel, float (&a_levels)[8]) const = 0;  // 03
		virtual bool                                 DoGetAttenuatesWithDistance() const = 0;                                                                 // 04
		virtual bool                                 DoGetUseDoppler() const = 0;                                                                             // 05
		virtual bool                                 DoGetUseSoSDelay() const = 0;                                                                            // 06
		virtual bool                                 DoGetAudibility(float a_distance) const = 0;                                                             // 07
		virtual std::uint32_t                        DoGetSupportedInputChannels() const = 0;                                                                 // 08
		virtual const BSIAttenuationCharacteristics* DoGetAttenuation() const = 0;                                                                            // 09
		virtual float                                DoGetReverbSendLevel() const = 0;                                                                        // 0A
		virtual bool                                 DoGetSupportsMonitor(std::uint32_t a_monitorID) const = 0;                                               // 0B
		virtual std::uint16_t                        DoGetStaticAttenuation() const = 0;                                                                      // 0C
		virtual const BSIAudioEffectChain*           DoGetEffectChain() const = 0;                                                                            // 0D
		virtual const char*                          DoGetDebugID() const = 0;                                                                                // 0E
		virtual bool                                 DoGetTryPlayThroughController() const = 0;                                                               // 0F
	};
	static_assert(sizeof(BSISoundOutputModel) == 0x8);
}
