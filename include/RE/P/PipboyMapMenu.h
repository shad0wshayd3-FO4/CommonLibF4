#pragma once

#include "RE/P/PipboySubMenu.h"
#include "RE/B/BSScaleformExternalTexture.h"

namespace RE
{
	class __declspec(novtable) PipboyMapMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyMapMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyMapMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyMapMenu::UpdateData);
			static REL::Relocation<func_t> func{ REL::ID(2224074) };
			return func(this);
		}

		// members
		BSScaleformExternalTexture worldMapTexture;                 // 18
		Scaleform::GFx::Value      mapPageObj;                      // 30
		std::uint32_t              centeredQuestMarkerID;           // 50
		std::uint32_t              centeredMapMarkerID;             // 54
		std::uint32_t              queuedFastTravelId;              // 58
		bool                       mapTexturesSentToMenu;           // 5C
		bool                       requestedDelayedLocalMapRender;  // 5D
	};
	static_assert(sizeof(PipboyMapMenu) == 0x60);
}
