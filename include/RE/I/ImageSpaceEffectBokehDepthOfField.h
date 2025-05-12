#pragma once

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectBokehDepthOfField :
		public ImageSpaceEffectOption  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectBokehDepthOfField };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectBokehDepthOfField };

		virtual ~ImageSpaceEffectBokehDepthOfField() override;  // 00

		// override (ImageSpaceEffect)
		virtual void Render(BSTriShape* a_geometry, ImageSpaceEffectParam* a_param) override;       // 01
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual bool IsActive() override;                                                           // 08
	};
	static_assert(sizeof(ImageSpaceEffectBokehDepthOfField) == 0xC8);
}
