#pragma once

namespace RE
{
	class ImageSpaceBaseData
	{
	public:
		class HDR  // HNAM
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

		class Cinematic  // CNAM
		{
		public:
			// members
			float saturation;  // 0
			float brightness;  // 4
			float contrast;    // 8
		};
		static_assert(sizeof(Cinematic) == 0xC);

		class Tint  // TNAM
		{
		public:
			class ColorF
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

		class DepthOfField  // DNAM
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
}
