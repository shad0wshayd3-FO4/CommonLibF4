#pragma once

namespace RE
{
	class __declspec(novtable) BSISoundCategory
	{
	public:
		static constexpr auto RTTI{ RTTI::BSISoundCategory };
		static constexpr auto VTABLE{ VTABLE::BSISoundCategory };

		virtual ~BSISoundCategory() = default;  // 00

		// add
		virtual bool          Matches(BSISoundCategory* a_toCheck, bool a_exclusive) const = 0;                                 // 01
		virtual float         GetCategoryVolume() const = 0;                                                                    // 02
		virtual void          SetCategoryVolume(float a_newVolume) = 0;                                                         // 03
		virtual float         GetCategoryFrequency() const = 0;                                                                 // 04
		virtual void          SetCategoryFrequency(float a_newFreq) = 0;                                                        // 05
		virtual std::uint16_t GetCategoryAttenuation(BSISoundCategoryUtils::FadeType a_type) const = 0;                         // 06
		virtual void          SetCategoryAttenuation(BSISoundCategoryUtils::FadeType a_type, std::uint16_t a_attenuation) = 0;  // 07
		virtual bool          CategoryPaused() const = 0;                                                                       // 08
		virtual void          SetCategoryPaused(bool a_paused, bool a_exclusive) = 0;                                           // 09
		virtual bool          CategoryMute() const = 0;                                                                         // 0A
		virtual void          SetCategoryMute(bool a_mute, bool a_exclusive) = 0;                                               // 0B
		virtual float         GetMinFrequencyMult() const = 0;                                                                  // 0C
		virtual bool          GetBlockSpeedChange() const = 0;                                                                  // 0D
		virtual bool          GetSkipOPMOverrides() const = 0;                                                                  // 0E
		virtual const char* GetDebugID() const = 0;                                                                           // 0F
	};
	static_assert(sizeof(BSISoundCategory) == 0x8);
}
