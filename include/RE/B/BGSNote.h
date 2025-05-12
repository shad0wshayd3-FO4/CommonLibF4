#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESWeightForm.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/B/BGSPickupPutdownSounds.h"

namespace RE
{
	class __declspec(novtable) BGSNote :
		public TESBoundObject,         // 000
		public TESWeightForm,          // 068
		public TESValueForm,           // 078
		public TESModel,               // 088
		public TESFullName,            // 0B8
		public TESIcon,                // 0C8
		public BGSPickupPutdownSounds  // 0D8
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSNote };
		static constexpr auto VTABLE{ VTABLE::BGSNote };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNOTE };

		enum NOTE_TYPE : std::int8_t
		{
			kVoice,
			kScene,
			kProgram,
			kTerminal
		};

		BGSSoundDescriptorForm* GetNoteSound()
		{
			return (type == NOTE_TYPE::kVoice) ? noteSound : nullptr;
		}

		BGSScene* GetNoteScene()
		{
			return (type == NOTE_TYPE::kScene) ? TESForm::GetFormByID<BGSScene>(static_cast<std::uint32_t>(noteFormID)) : nullptr;
		}

		const BSFixedString GetNoteProgram()
		{
			return (type == NOTE_TYPE::kProgram) ? programFile : BSFixedString{ ""sv };
		}

		BGSTerminal* GetNoteTerminal()
		{
			return (type == NOTE_TYPE::kTerminal) ? TESForm::GetFormByID<BGSTerminal>(static_cast<std::uint32_t>(noteFormID)) : nullptr;
		}

		// members
		BSFixedString programFile;  // 0F0
		union
		{
			BGSSoundDescriptorForm* noteSound;
			std::size_t             noteFormID;
		};  // 0F8
		std::int8_t type;         // 100
		bool        hasBeenRead;  // 101
	};
	static_assert(sizeof(BGSNote) == 0x108);
}
