#pragma once

namespace RE
{
	struct ImageSpaceLUTData
	{
	public:
		// members
		BSFixedString        filename[4];   // 00
		float                weight[4];     // 20
		NiPointer<NiTexture> niTexture[4];  // 30
		BSGraphics::Texture* texture[4];    // 50
	};
	static_assert(sizeof(ImageSpaceLUTData) == 0x70);
}
