#pragma once

#include "Scaleform/G/GFx_StatGroup.h"

namespace Scaleform::GFx
{
	enum StatAmp
	{
		kStatAmp_Default = kStatGroup_GFxAmp,

		kStatAmp_Mem,
		kStatAmp_ProfileFrame,
		kStatAmp_Server,
		kStatAmp_Message,
		kStatAmp_Callstack,
		kStatAmp_InstrBuffer,
	};
}
