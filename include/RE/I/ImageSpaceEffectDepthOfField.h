#pragma once

#include "RE/I/ImageSpaceEffectOption.h"

namespace RE
{
	class __declspec(novtable) ImageSpaceEffectDepthOfField :
		public ImageSpaceEffectOption  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffectDepthOfField };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffectDepthOfField };

		virtual ~ImageSpaceEffectDepthOfField() override;  // 00

		// override (ImageSpaceEffect)
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param) override;  // 03
		virtual void BorrowTextures(ImageSpaceEffectParam* a_param) override;                       // 05
		virtual void ReturnTextures() override;                                                     // 06
		virtual bool IsActive() override;                                                           // 08
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param) override;                         // 09

		// members
		ImageSpaceTexture maskBuffer;  // B0
		ImageSpaceTexture buffer[3];   // F0
		bool              useFog;      // 168
	};
	static_assert(sizeof(ImageSpaceEffectDepthOfField) == 0x170);
}
