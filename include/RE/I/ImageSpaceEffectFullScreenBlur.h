#pragma once

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectFullScreenBlur :
		public ImageSpaceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectFullScreenBlur };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectFullScreenBlur };

		virtual ~ImageSpaceEffectFullScreenBlur() override;  // 00

		// override (ImageSpaceEffect)
		virtual void Render(BSTriShape* a_geometry, ImageSpaceEffectParam* a_param) override;       // 01
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual void BorrowTextures(ImageSpaceEffectParam* a_param) override;                       // 05
		virtual void ReturnTextures() override;                                                     // 06
		virtual bool IsActive() override;                                                           // 08
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param) override;                         // 09

		inline static REL::Relocation<bool*> bDisable{ REL::ID(2713225) };

		// members
		ImageSpaceTexture buffer[3];  // B0
	};
	static_assert(sizeof(ImageSpaceEffectFullScreenBlur) == 0x128);
}
