#pragma once

namespace RE
{
	struct ImageSpaceData
	{
	public:
		// members
		ImageSpaceBaseData baseData;           //00
		ImageSpaceModData  modData;            //58
		float              highestTintAmount;  //A8
		float              highestFadeAmount;  //AC
	};
	static_assert(sizeof(ImageSpaceData) == 0xB0);
}
