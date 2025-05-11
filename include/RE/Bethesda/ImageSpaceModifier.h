#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/ImageSpaceData.h"
#include "RE/NetImmerse/NiAVObject.h"
#include "RE/NetImmerse/NiObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class TESImageSpaceModifier;
	class TESImageSpaceModifierForm;

	class ImageSpaceModifierFinder
	{
	public:
		// members
		TESImageSpaceModifierForm* modifier;        // 00
		const BSFixedString&       modifierToFind;  // 08
	};
	static_assert(sizeof(ImageSpaceModifierFinder) == 0x10);

	class ImageSpaceModifierInstance :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstance };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstance };

		enum class FLAGS
		{
			kNone = 0,
			kPermanent = 1 << 0,
			kCrossfade = 1 << 1,
			kPreviousCrossfade = 1 << 2,
			kMenuIMOD = 1 << 3,
			kStopped = 1 << 4
		};

		virtual ~ImageSpaceModifierInstance();  // 00

		// add
		virtual bool                            IsExpired();                    // 28
		virtual void                            Apply() = 0;                    // 29
		virtual void                            PrintInfo(char* a_buffer) = 0;  // 2A
		virtual ImageSpaceModifierInstanceForm* IsForm();                       // 2B

		void Stop()
		{
			using func_t = decltype(&ImageSpaceModifierInstance::Stop);
			static REL::Relocation<func_t> func{ REL::ID(2199897) };
			return func(this);
		}

		// members
		float                              strength;  // 10
		NiPointer<NiAVObject>              target;    // 18
		float                              age;       // 20
		REX::EnumSet<FLAGS, std::uint32_t> flags;     // 24
	};
	static_assert(sizeof(ImageSpaceModifierInstance) == 0x28);

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
			static REL::Relocation<func_t> func{ REL::ID(2199906) };
			return func(a_mod, a_strength, a_target);
		}

		static ImageSpaceModifierInstanceForm* Trigger(const BSFixedString& a_name)
		{
			using func_t = ImageSpaceModifierInstanceForm* (*)(const BSFixedString&);
			static REL::Relocation<func_t> func{ REL::ID(2199907) };
			return func(a_name);
		}

		static void Stop(TESImageSpaceModifier* a_mod)
		{
			using func_t = void (*)(TESImageSpaceModifier*);
			static REL::Relocation<func_t> func{ REL::ID(2199909) };
			return func(a_mod);
		}

		static void Stop(const BSFixedString& a_name)
		{
			using func_t = void (*)(const BSFixedString&);
			static REL::Relocation<func_t> func{ REL::ID(2199910) };
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

	class ImageSpaceModifierInstanceTemp :
		public ImageSpaceModifierInstance  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstanceTemp };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstanceTemp };

		virtual ~ImageSpaceModifierInstanceTemp();  // 00

		// override (ImageSpaceModifierInstance)
		virtual bool IsExpired() override;                // 28
		virtual void PrintInfo(char* a_buffer) override;  // 2A

		// members
		float duration;  // 28
	};
	static_assert(sizeof(ImageSpaceModifierInstanceTemp) == 0x30);

	class ImageSpaceModifierInstanceDOF :
		public ImageSpaceModifierInstanceTemp  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstanceDOF };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstanceDOF };

		enum class DepthOfFieldMode
		{
			kFrontBack = 0,
			kFront,
			kBack,
			kNone,
		};

		virtual ~ImageSpaceModifierInstanceDOF();  // 00

		// override (ImageSpaceModifierInstanceTemp)
		virtual void Apply() override;                    // 29
		virtual void PrintInfo(char* a_buffer) override;  // 2A

		static ImageSpaceModifierInstanceDOF* Trigger(
			float            a_distance,
			float            a_range,
			float            a_vignetteRadius,
			float            a_vignetteStrength,
			DepthOfFieldMode a_mode,
			float            a_strength,
			float            a_duration)
		{
			using func_t = decltype(&ImageSpaceModifierInstanceDOF::Trigger);
			static REL::Relocation<func_t> func{ REL::ID(2199922) };
			return func(a_distance, a_range, a_vignetteRadius, a_vignetteStrength, a_mode, a_strength, a_duration);
		}

		// members
		ImageSpaceModData data;  // 30
	};
	static_assert(sizeof(ImageSpaceModifierInstanceDOF) == 0x80);

	class ImageSpaceModifierInstanceRB :
		public ImageSpaceModifierInstanceTemp
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstanceRB };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstanceRB };

		virtual ~ImageSpaceModifierInstanceRB();  // 00

		// override (ImageSpaceModifierInstanceTemp)
		virtual void Apply() override;                    // 29
		virtual void PrintInfo(char* a_buffer) override;  // 2A

		// members
		ImageSpaceModData data;  // 30
	};
	static_assert(sizeof(ImageSpaceModifierInstanceRB) == 0x80);
}
