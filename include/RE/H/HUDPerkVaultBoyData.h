#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class HUDPerkVaultBoyData
	{
	public:
		// members
		BSFixedString                 SwfName;                      // 00
		const BGSSoundDescriptorForm* soundForm;                    // 08
		bool                          VATSCritAppliedAnim;          // 10
		bool                          VATSCritFillenAnim;           // 11
		bool                          dialogueSpeechChallengeAnim;  // 12
	};
	static_assert(sizeof(HUDPerkVaultBoyData) == 0x18);
}
