#pragma once

#include "Scaleform/G/GFx_AS3_Abc_File.h"
#include "Scaleform/G/GFx_AS3_VMFile.h"
#include "Scaleform/P/Ptr.h"

namespace Scaleform::GFx::AS3
{
	class __declspec(novtable) VMAbcFile :
		public VMFile
	{
	public:
		// members
		Ptr<Abc::File> file;                // 98
		std::byte      padA0[0xE8 - 0xA0];  // A0
	};
	static_assert(sizeof(VMAbcFile) == 0xE8);
}
