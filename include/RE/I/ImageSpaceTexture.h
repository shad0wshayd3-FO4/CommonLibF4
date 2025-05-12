#pragma once

namespace RE
{
	class ImageSpaceTexture
	{
	public:
		// members
		bool                           forceAniso;      // 00
		NiTexture*                     texture;         // 08
		std::int32_t                   renderTarget;    // 10
		std::int32_t                   depthBuffer;     // 14
		std::int32_t                   stencilBuffer;   // 18
		BSGraphics::TextureFilterMode  filterMode;      // 1C
		BSGraphics::TextureAddressMode clampMode;       // 20
		bool                           acquiredTarget;  // 24
	};
	static_assert(sizeof(ImageSpaceTexture) == 0x28);
}
