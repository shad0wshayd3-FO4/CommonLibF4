#pragma once

#include "Scaleform/G/GFx_AS3_Abc_ConstPool.h"
#include "Scaleform/G/GFx_AS3_Abc_MethodTable.h"
#include "Scaleform/G/GFx_AS3_Abc_MetadataTable.h"
#include "Scaleform/G/GFx_AS3_Abc_TraitTable.h"
#include "Scaleform/G/GFx_AS3_Abc_ClassTable.h"
#include "Scaleform/G/GFx_AS3_Abc_ScriptTable.h"
#include "Scaleform/G/GFx_AS3_Abc_MethodBodyTable.h"
#include "Scaleform/S/String.h"
#include "Scaleform/R/RefCountBase.h"
#include "Scaleform/N/NewOverrideBase.h"

namespace Scaleform::GFx::AS3::Abc
{
	class __declspec(novtable) alignas(0x10) File :
		public RefCountImpl,  // 00
		public NewOverrideBase<338>
	{
	public:
		virtual ~File();  // 00

		// members
		std::uint32_t   dataSize;      // 010
		String          source;        // 018
		std::uint16_t   minorVersion;  // 020
		std::uint16_t   majorVersion;  // 022
		ConstPool       constPool;     // 028
		MethodTable     methods;       // 0E0
		MetadataTable   metadata;      // 0F8
		TraitTable      traits;        // 110
		ClassTable      classes;       // 128
		ScriptTable     scripts;       // 140
		MethodBodyTable methodBodies;  // 158
	};
	static_assert(sizeof(File) == 0x170);
}
