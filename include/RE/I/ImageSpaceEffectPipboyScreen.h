#pragma once

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectPipboyScreen :
		public ImageSpaceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectPipboyScreen };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectPipboyScreen };

		virtual ~ImageSpaceEffectPipboyScreen();  // 00

		// override (ImageSpaceEffect)
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual void ReturnTextures() override;                                                     // 06
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param) override;                         // 09

		inline static REL::Relocation<bool*> bPowerArmorPipboy{ REL::ID(1065542) };

		// members
		NiPointer<NiTexture> scanlineTexture;  // B0
		NiPointer<NiTexture> vScanTexture;     // B8
	};
	static_assert(sizeof(ImageSpaceEffectPipboyScreen) == 0xC0);
}
