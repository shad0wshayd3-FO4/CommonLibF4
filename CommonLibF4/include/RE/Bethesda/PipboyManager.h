#pragma once

#include "RE/Bethesda/BGSInventoryInterface.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSInputEventUser.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSSoundHandle.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTPoint.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class BGSNote;
	class BGSTerminal;
	class TESBoundObject;
	class TESObjectREFR;

	struct BSAnimationGraphEvent;

	class IsPipboyActiveEvent :
		public BSTValueEvent<bool>  // 00
	{
	public:
	};
	static_assert(sizeof(IsPipboyActiveEvent) == 0x02);

	class PipboyRadioController
	{
	public:
		// members
		float chaseStation;  // 00
	};
	static_assert(sizeof(PipboyRadioController) == 0x04);

	class __declspec(novtable) PipboyManager :
		public BSTEventSink<BSAnimationGraphEvent>,  // 00
		public BSInputEventUser,                     // 08
		public BSTSingletonSDM<PipboyManager>        // 18
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyManager };
		static constexpr auto VTABLE{ VTABLE::PipboyManager };

		enum class LOWER_REASON
		{
			kNone = 0x0,
			kBook = 0x1,
			kPerkGrid = 0x2,
			kInspect = 0x3
		};

		virtual ~PipboyManager();  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent& a_event, BSTEventSource<BSAnimationGraphEvent>* a_source) override;  // 01
		virtual bool                 ShouldHandleEvent(const InputEvent*) override;                                                                 // 02
		virtual void                 OnButtonEvent(const ButtonEvent*) override;                                                                    // 09
		virtual void                 OnMouseMoveEvent(const MouseMoveEvent*) override;                                                              // 07
		virtual void                 OnThumbstickEvent(const ThumbstickEvent*) override;                                                            // 05

		[[nodiscard]] static PipboyManager* GetSingleton()
		{
			static REL::Relocation<PipboyManager**> singleton{ REL::ID(2691945) };
			return *singleton;
		}

		void AddMenuToPipboy(IMenu& a_menu, const NiRect<float>& a_standVP, const NiRect<float>& a_powerVP)
		{
			using func_t = decltype(&PipboyManager::AddMenuToPipboy);
			static REL::Relocation<func_t> func{ REL::ID(2225453) };
			return func(this, a_menu, a_standVP, a_powerVP);
		}

		void ClosedownPipboy()
		{
			using func_t = decltype(&PipboyManager::ClosedownPipboy);
			static REL::Relocation<func_t> func{ REL::ID(2225480) };
			return func(this);
		}

		void EnablePipboyShader()
		{
			using func_t = decltype(&PipboyManager::EnablePipboyShader);
			static REL::Relocation<func_t> func{ REL::ID(2225484) };
			return func(this);
		}

		void InitPipboy()
		{
			using func_t = decltype(&PipboyManager::InitPipboy);
			static REL::Relocation<func_t> func{ REL::ID(2225479) };
			return func(this);
		}

		void LowerPipboy(LOWER_REASON a_reason)
		{
			using func_t = decltype(&PipboyManager::LowerPipboy);
			static REL::Relocation<func_t> func{ REL::ID(2225454) };
			return func(this, a_reason);
		}

		void OnPipboyCloseAnim()
		{
			using func_t = decltype(&PipboyManager::OnPipboyCloseAnim);
			static REL::Relocation<func_t> func{ REL::ID(2225457) };
			return func(this);
		}

		void OnPipboyCloseAnimFailed()
		{
			using func_t = decltype(&PipboyManager::OnPipboyCloseAnimFailed);
			static REL::Relocation<func_t> func{ REL::ID(2225459) };
			return func(this);
		}

		void OnPipboyClosed()
		{
			using func_t = decltype(&PipboyManager::OnPipboyClosed);
			static REL::Relocation<func_t> func{ REL::ID(592088) };
			return func(this);
		}

		void OnPipboyOpenAnim()
		{
			using func_t = decltype(&PipboyManager::OnPipboyOpenAnim);
			static REL::Relocation<func_t> func{ REL::ID(1500318) };
			return func(this);
		}

		void OnPipboyOpenAnimFailed()
		{
			using func_t = decltype(&PipboyManager::OnPipboyOpenAnimFailed);
			static REL::Relocation<func_t> func{ REL::ID(702357) };
			return func(this);
		}

		void OnPipboyOpened()
		{
			using func_t = decltype(&PipboyManager::OnPipboyOpened);
			static REL::Relocation<func_t> func{ REL::ID(1299608) };
			return func(this);
		}

		void PlayItemAnimOnClose()
		{
			using func_t = decltype(&PipboyManager::PlayItemAnimOnClose);
			static REL::Relocation<func_t> func{ REL::ID(377837) };
			return func(this);
		}

		void PlayPipboyCloseAnim(bool a_noAnim)
		{
			using func_t = decltype(&PipboyManager::PlayPipboyCloseAnim);
			static REL::Relocation<func_t> func{ REL::ID(273927) };
			return func(this, a_noAnim);
		}

		void PlayPipboyGenericOpenAnim(const BSFixedString& a_menu, const BSFixedString& a_anim, bool a_noAnim)
		{
			using func_t = decltype(&PipboyManager::PlayPipboyGenericOpenAnim);
			static REL::Relocation<func_t> func{ REL::ID(809076) };
			return func(this, a_menu, a_anim, a_noAnim);
		}

		void PlayPipboyLoadHolotapeAnim(BGSNote* a_holotape, bool a_noAnim)
		{
			using func_t = decltype(&PipboyManager::PlayPipboyLoadHolotapeAnim);
			static REL::Relocation<func_t> func{ REL::ID(477096) };
			return func(this, a_holotape, a_noAnim);
		}

		void PlayPipboyOpenAnim(const RE::BSFixedString& a_menuName)
		{
			using func_t = decltype(&PipboyManager::PlayPipboyOpenAnim);
			static REL::Relocation<func_t> func{ REL::ID(663900) };
			return func(this, a_menuName);
		}

		void PlayPipboyOpenTerminalAnim(BGSTerminal* a_terminal)
		{
			using func_t = decltype(&PipboyManager::PlayPipboyOpenTerminalAnim);
			static REL::Relocation<func_t> func{ REL::ID(743427) };
			return func(this, a_terminal);
		}

		void ProcessLoweringReason()
		{
			using func_t = decltype(&PipboyManager::ProcessLoweringReason);
			static REL::Relocation<func_t> func{ REL::ID(302903) };
			return func(this);
		}

		bool QPipboyActive()
		{
			using func_t = decltype(&PipboyManager::QPipboyActive);
			static REL::Relocation<func_t> func{ REL::ID(470886) };
			return func(this);
		}

		void RaisePipboy()
		{
			using func_t = decltype(&PipboyManager::RaisePipboy);
			static REL::Relocation<func_t> func{ REL::ID(726763) };
			return func(this);
		}

		void RefreshPipboyRenderSurface()
		{
			using func_t = decltype(&PipboyManager::RefreshPipboyRenderSurface);
			static REL::Relocation<func_t> func{ REL::ID(81339) };
			return func(this);
		}

		void StartAnimationGraphListening()
		{
			using func_t = decltype(&PipboyManager::StartAnimationGraphListening);
			static REL::Relocation<func_t> func{ REL::ID(714713) };
			return func(this);
		}

		void StopAnimationGraphListening()
		{
			using func_t = decltype(&PipboyManager::StopAnimationGraphListening);
			static REL::Relocation<func_t> func{ REL::ID(621144) };
			return func(this);
		}

		void UpdateCursorConstraint(bool a_enable)
		{
			using func_t = decltype(&PipboyManager::UpdateCursorConstraint);
			static REL::Relocation<func_t> func{ REL::ID(900802) };
			return func(this, a_enable);
		}

		// members
		BSSoundHandle                            pipboyHumSound;          // 01C
		BSTPoint2<float>                         inputVector;             // 024
		BSTPoint2<float>                         newInput;                // 02C
		NiPointer<BSTriShape>                    debugModeGeom;           // 038
		Inventory3DManager                       inv3DModelManager;       // 040
		BGSNote*                                 holotapeToLoad;          // 180
		BGSTerminal*                             terminalToLoad;          // 188
		BSFixedString                            menuToOpen;              // 190
		BSFixedString                            openAnimEvent;           // 198
		BSFixedString                            closeAnimEvent;          // 1A0
		REX::EnumSet<LOWER_REASON, std::int32_t> loweringReason;          // 1A8
		PipboyRadioController                    radioController;         // 1AC
		TESBoundObject*                          itemAnimOnClose;         // 1B0
		ObjectRefHandle                          fastTravelLocation;      // 1B8
		InventoryInterface::Handle               inspectRequestItem;      // 1BC
		std::uint32_t                            inspectRequestStack;     // 1C0
		bool                                     pipboyExamineMode;       // 1C4
		bool                                     pipboyExamineDirtyFlag;  // 1C5
		bool                                     pipboyOpening;           // 1C6
		bool                                     pipboyClosing;           // 1C7
		BSTValueEventSource<IsPipboyActiveEvent> pipboyActive;            // 1C8
		bool                                     ignoreOpeningFlag;       // 1E0
		bool                                     autoSaveOnClose;         // 1E1
		bool                                     pipboyMenuCloseQueued;   // 1E2
		bool                                     pipboyRaising;           // 1E3
		bool                                     wasMotionBlurActive;     // 1E4
		bool                                     wasPipboyLightActive;    // 1E5
	};
	static_assert(sizeof(PipboyManager) == 0x1F0);
}
