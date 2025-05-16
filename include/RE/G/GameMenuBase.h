#pragma once

#include "RE/I/IMenu.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSSpinLock.h"
#include "RE/S/SendHUDMessage.h"
#include "RE/B/BSGFxShaderFXTarget.h"
#include "RE/B/BSTOptional.h"
#include "RE/H/HUDModeType.h"
#include "RE/B/ButtonHintBar.h"

namespace RE
{
	class GameMenuBase :
		public IMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::GameMenuBase };
		static constexpr auto VTABLE{ VTABLE::GameMenuBase };

		GameMenuBase()
		{
			customRendererName = "FlatScreenModel";
		}

		virtual ~GameMenuBase() = default;

		// override
		virtual void SetIsTopButtonBar(bool a_isTopButtonBar) override  // 08
		{
			using func_t = decltype(&GameMenuBase::SetIsTopButtonBar);
			static REL::Relocation<func_t> func{ REL::ID(2223204) };
			return func(this, a_isTopButtonBar);
		}

		virtual void OnMenuDisplayStateChanged() override  // 0A
		{
			using func_t = decltype(&GameMenuBase::OnMenuDisplayStateChanged);
			static REL::Relocation<func_t> func{ REL::ID(2223205) };
			return func(this);
		}

		virtual void OnAddedToMenuStack() override  // 0B
		{
			IMenu::OnAddedToMenuStack();
			if (this->menuHUDMode.has_value()) {
				SendHUDMessage::PushHUDMode(this->menuHUDMode.value());
			}
		}

		virtual void OnRemovedFromMenuStack() override  // 0C
		{
			IMenu::OnRemovedFromMenuStack();
			if (this->menuHUDMode.has_value()) {
				SendHUDMessage::PopHUDMode(this->menuHUDMode.value());
			}
		}

		virtual bool CacheShaderFXQuadsForRenderer_Impl() override  // 10
		{
			using func_t = decltype(&GameMenuBase::CacheShaderFXQuadsForRenderer_Impl);
			static REL::Relocation<func_t> func{ REL::ID(2223200) };
			return func(this);
		}

		virtual void TransferCachedShaderFXQuadsForRenderer(const BSFixedString& a_rendererName) override  // 11
		{
			using func_t = decltype(&GameMenuBase::TransferCachedShaderFXQuadsForRenderer);
			static REL::Relocation<func_t> func{ REL::ID(65166) };
			return func(this, a_rendererName);
		}

		virtual void SetViewportRect(const NiRect<float>& a_viewportRect) override  // 12
		{
			using func_t = decltype(&GameMenuBase::SetViewportRect);
			static REL::Relocation<func_t> func{ REL::ID(2223202) };
			return func(this, a_viewportRect);
		}

		// add
		virtual void AppendShaderFXInfos(BSTAlignedArray<UIShaderFXInfo>& a_colorFXInfos, BSTAlignedArray<UIShaderFXInfo>& a_backgroundFXInfos) const  // 13
		{
			using func_t = decltype(&GameMenuBase::AppendShaderFXInfos);
			static REL::Relocation<func_t> func{ REL::ID(2223203) };
			return func(this, a_colorFXInfos, a_backgroundFXInfos);
		}

		void SetUpButtonBar(BSGFxShaderFXTarget& a_parentObject, const char* a_buttonBarPath, HUDColorTypes a_colorType)
		{
			using func_t = decltype(&GameMenuBase::SetUpButtonBar);
			static REL::Relocation<func_t> func{ REL::ID(2223197) };
			func(this, a_parentObject, a_buttonBarPath, a_colorType);
		}

		// members
		BSTArray<BSGFxShaderFXTarget*>        shaderFXObjects;              // 70
		std::unique_ptr<BSGFxShaderFXTarget>  filterHolder;                 // 88
		std::unique_ptr<ButtonHintBar>        buttonHintBar;                // 90
		BSTAlignedArray<UIShaderFXInfo>       cachedColorFXInfos;           // 98
		BSTAlignedArray<UIShaderFXInfo>       cachedBackgroundFXInfos;      // B0
		BSReadWriteLock                       cachedQuadsLock;              // C8
		BSTOptional<HUDModeType>              menuHUDMode{ std::nullopt };  // D0
	};
	static_assert(sizeof(GameMenuBase) == 0xE0);
}
