#pragma once

#include "Scaleform/R/Render_ContextImpl_Entry.h"
#include "Scaleform/R/Render_ContextImpl_EntryPageBase.h"

namespace Scaleform::Render::ContextImpl
{
	class EntryPage :
		public EntryPageBase  // 000
	{
	public:
		// members
		Entry entries[72];  // 038
	};
	static_assert(sizeof(EntryPage) == 0xFF8);
}
