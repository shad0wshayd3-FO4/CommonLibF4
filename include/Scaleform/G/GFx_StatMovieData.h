#pragma once

#include "Scaleform/G/GFx_StatGroup.h"

namespace Scaleform::GFx
{
	enum StatMovieData
	{
		kStatMD_Default = kStatGroup_GFxMovieData,

		kStatMD_Mem,
		kStatMD_CharDefs_Mem,
		kStatMD_ShapeData_Mem,
		kStatMD_Tags_Mem,
		kStatMD_Fonts_Mem,
		kStatMD_Images_Mem,
		kStatMD_ASBinaryData_Mem,
		kStatMD_Other_Mem,

		kStatMD_Time,
		kStatMD_Load_Tks,
		kStatMD_Bind_Tks
	};
}
