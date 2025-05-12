#pragma once

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectMotionBlur :
		public ImageSpaceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectMotionBlur };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectMotionBlur };

		virtual ~ImageSpaceEffectMotionBlur();  // 00

		// override (ImageSpaceEffect)
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual bool IsActive() override;                                                           // 08
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param) override;                         // 09
	};
	static_assert(sizeof(ImageSpaceEffectMotionBlur) == 0xB0);
}
