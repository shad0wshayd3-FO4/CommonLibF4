#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class __declspec(novtable) BGSOpenCloseForm
	{
	public:
		inline static constexpr auto RTTI{ RTTI::BGSOpenCloseForm };
		inline static constexpr auto VTABLE{ VTABLE::BGSOpenCloseForm };

		enum class OPEN_STATE : std::int32_t
		{
			kNone = 0,
			kOpen = 1,
			kOpening = 2,
			kClosed = 3,
			kClosing = 4
		};

		virtual ~BGSOpenCloseForm() = default;  // 00

		// add
		virtual void HandleOpenStart(TESObjectREFR*, TESObjectREFR*, bool) { return; }   // 01
		virtual void HandleCloseStart(TESObjectREFR*, TESObjectREFR*, bool) { return; }  // 02
		virtual void HandleOpenFinish(TESObjectREFR*, TESObjectREFR*) { return; }        // 03
		virtual void HandleCloseFinish(TESObjectREFR*, TESObjectREFR*) { return; }       // 04

		inline static void AutoCloseRef(const TESObjectREFR* a_ref)
		{
			using func_t = decltype(&BGSOpenCloseForm::AutoCloseRef);
			static REL::Relocation<func_t> func{ ID::BGSOpenCloseForm::AutoCloseRef };
			func(a_ref);
		}

		inline static OPEN_STATE GetOpenState(const TESObjectREFR* a_ref)
		{
			using func_t = decltype(&BGSOpenCloseForm::GetOpenState);
			static REL::Relocation<func_t> func{ ID::BGSOpenCloseForm::GetOpenState };
			return func(a_ref);
		}

		inline static bool HasOnlyOpenCloseAnims(const TESObjectREFR* a_ref)
		{
			using func_t = decltype(&BGSOpenCloseForm::HasOnlyOpenCloseAnims);
			static REL::Relocation<func_t> func{ ID::BGSOpenCloseForm::HasOnlyOpenCloseAnims };
			return func(a_ref);
		}

		inline static bool IsAnimating(const TESObjectREFR* a_ref)
		{
			using func_t = decltype(&BGSOpenCloseForm::IsAnimating);
			static REL::Relocation<func_t> func{ ID::BGSOpenCloseForm::IsAnimating };
			return func(a_ref);
		}

		inline static bool IsOpenCloseEvent(const BSFixedString& a_event, const bool& a_open)
		{
			using func_t = decltype(&BGSOpenCloseForm::IsOpenCloseEvent);
			static REL::Relocation<func_t> func{ ID::BGSOpenCloseForm::IsOpenCloseEvent };
			return func(a_event, a_open);
		}

		inline static bool IsOpenCloseForm(TESForm* a_form)
		{
			using func_t = decltype(&BGSOpenCloseForm::IsOpenCloseForm);
			static REL::Relocation<func_t> func{ ID::BGSOpenCloseForm::IsOpenCloseForm };
			return func(a_form);
		}

		inline static bool SetOpenState(const TESObjectREFR* a_ref, bool a_open, bool a_snap)
		{
			using func_t = decltype(&BGSOpenCloseForm::SetOpenState);
			static REL::Relocation<func_t> func{ ID::BGSOpenCloseForm::SetOpenState };
			return func(a_ref, a_open, a_snap);
		}
	};
	static_assert(sizeof(BGSOpenCloseForm) == 0x8);
}
