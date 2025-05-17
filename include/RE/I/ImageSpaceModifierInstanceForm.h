#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/I/ImageSpaceModifierInstance.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class ImageSpaceModifierInstanceForm :
		public ImageSpaceModifierInstance
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstanceForm };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstanceForm };

		virtual ~ImageSpaceModifierInstanceForm();  // 00

		// override (ImageSpaceModifierInstance)
		virtual bool                            IsExpired() override;                // 28
		virtual void                            Apply() override;                    // 29
		virtual void                            PrintInfo(char* a_buffer) override;  // 2A
		virtual ImageSpaceModifierInstanceForm* IsForm() override;                   // 2B

		static ImageSpaceModifierInstanceForm* Trigger(TESImageSpaceModifier* a_mod, float a_strength, NiAVObject* a_target)
		{
			using func_t = ImageSpaceModifierInstanceForm* (*)(TESImageSpaceModifier*, float, NiAVObject*);
			static REL::Relocation<func_t> func{ ID::ImageSpaceModifierInstanceForm::Trigger1 };
			return func(a_mod, a_strength, a_target);
		}

		static ImageSpaceModifierInstanceForm* Trigger(const BSFixedString& a_name)
		{
			using func_t = ImageSpaceModifierInstanceForm* (*)(const BSFixedString&);
			static REL::Relocation<func_t> func{ ID::ImageSpaceModifierInstanceForm::Trigger2 };
			return func(a_name);
		}

		static void Stop(TESImageSpaceModifier* a_mod)
		{
			using func_t = void (*)(TESImageSpaceModifier*);
			static REL::Relocation<func_t> func{ ID::ImageSpaceModifierInstanceForm::Stop1 };
			return func(a_mod);
		}

		static void Stop(const BSFixedString& a_name)
		{
			using func_t = void (*)(const BSFixedString&);
			static REL::Relocation<func_t> func{ ID::ImageSpaceModifierInstanceForm::Stop2 };
			return func(a_name);
		}

		// members
		TESImageSpaceModifier* imageSpaceMod;      // 28
		TESImageSpaceModifier* lastImageSpaceMod;  // 30
		float                  lastStrength;       // 38
		NiPointer<NiAVObject>  lastTarget;         // 40
		float                  transitionTime;     // 48
	};
	static_assert(sizeof(ImageSpaceModifierInstanceForm) == 0x50);
}
