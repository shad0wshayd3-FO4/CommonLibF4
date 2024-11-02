#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTexture.h"

namespace RE
{
	namespace BSGraphics
	{
		class Texture;
	}

	struct ImageSpaceBaseData
	{
	public:
		struct HDR  // HNAM
		{
		public:
			// members
			float eyeAdaptSpeed;          // 00
			float bloomBlurRadius;        // 04
			float bloomThreshold;         // 08
			float bloomScale;             // 0C
			float receiveBloomThreshold;  // 10
			float white;                  // 14
			float sunlightScale;          // 18
			float skyScale;               // 1C
			float eyeAdaptStrength;       // 20
		};
		static_assert(sizeof(HDR) == 0x24);

		struct Cinematic  // CNAM
		{
		public:
			// members
			float saturation;  // 0
			float brightness;  // 4
			float contrast;    // 8
		};
		static_assert(sizeof(Cinematic) == 0xC);

		struct Tint  // TNAM
		{
		public:
			struct ColorF
			{
			public:
				// members
				float red;    // 0
				float green;  // 4
				float blue;   // 8
			};
			static_assert(sizeof(ColorF) == 0xC);

			// members
			float  amount;  // 00
			ColorF color;   // 04
		};
		static_assert(sizeof(Tint) == 0x10);

		struct DepthOfField  // DNAM
		{
		public:
			// members
			float strength;          // 00
			float distance;          // 04
			float range;             // 08
			float vignetteRadius;    // 0C
			float vignetteStrength;  // 10
			float mode;              // 14
		};
		static_assert(sizeof(DepthOfField) == 0x18);

		// members
		HDR          hdrData;        // 00
		Cinematic    cinematicData;  // 24
		Tint         tintData;       // 30
		DepthOfField dofData;        // 40
	};
	static_assert(sizeof(ImageSpaceBaseData) == 0x58);

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
