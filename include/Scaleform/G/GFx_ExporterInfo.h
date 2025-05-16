#pragma once

#include "Scaleform/F/Flags.h"
#include "Scaleform/G/GFx_FileTypeConstants.h"

namespace Scaleform::GFx
{
	struct ExporterInfo
	{
	public:
		enum class ExportFlagConstants : std::uint32_t
		{
			kGlyphTexturesExported = 1 << 0,
			kGradientTexturesExported = 1 << 1,
			kGlyphsStripped = 1 << 4
		};

		// members
		Flags<FileTypeConstants::FileFormatType> format;       // 00
		const char*                              prefix;       // 08
		const char*                              swfName;      // 10
		std::uint16_t                            version;      // 18
		Flags<ExportFlagConstants>               exportFlags;  // 1C
	};
	static_assert(sizeof(ExporterInfo) == 0x20);
}
