#pragma once

namespace Scaleform::GFx
{
	class FileTypeConstants
	{
	public:
		enum class FileFormatType : std::int32_t
		{
			kUnopened,
			kUnknown,

			kSWF,
			kGFX,

			kJPEG = 10,
			kPNG = 11,
			kGIF = 12,
			kTGA = 13,
			kDDS = 14,
			kHDR = 15,
			kBMP = 16,
			kDIB = 17,
			kPFM = 18,
			kTIFF = 19,

			kWAVE = 20,

			kPVR = 21,
			kETC = 22,
			kSIF = 23,
			kGXT = 24,
			kGTX = 25,

			kNextAvail,
			kMultiFormat = 0xFFFF - 1,
			kOriginal = 0xFFFF
		};
	};
	static_assert(std::is_empty_v<FileTypeConstants>);
}
