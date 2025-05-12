#pragma once

namespace RE
{
	struct ImageSpaceModData
	{
	public:
		// members
		float                            fadeAmount;            // 00
		float                            fadeR;                 // 04
		float                            fadeG;                 // 08
		float                            fadeB;                 // 0C
		float                            blurRadius;            // 10
		float                            doubleVisionStrength;  // 14
		float                            radiusBlurStrength;    // 18
		float                            radiusBlurRampUp;      // 1C
		float                            radiusBlurStart;       // 20
		float                            radiusBlurRampDown;    // 24
		float                            radiusBlurDownStart;   // 28
		float                            radiusBlurCenterX;     // 2C
		float                            radiusBlurCenterY;     // 30
		ImageSpaceBaseData::DepthOfField depthOfField;          // 34
		float                            motionBlurStrength;    // 4C
	};
	static_assert(sizeof(ImageSpaceModData) == 0x50);
}
