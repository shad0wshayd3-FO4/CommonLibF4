#pragma once

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectRadialBlur :
		public ImageSpaceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectRadialBlur };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectRadialBlur };

		virtual ~ImageSpaceEffectRadialBlur();  // 00

		// override (ImageSpaceEffect)
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual bool IsActive() override;                                                           // 08
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param) override;                         // 09

		inline static REL::Relocation<bool*> bDisable{ REL::ID(2713225) };
	};
	static_assert(sizeof(ImageSpaceEffectRadialBlur) == 0xB0);
}
