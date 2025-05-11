#include "RE/Bethesda/BSScript/StackFrame.h"
#include "RE/Bethesda/BSResource/BSResourceEnums.h"
#include "RE/Bethesda/BSScript/Stack.h"
#include "RE/Bethesda/BSScript/TypeInfo.h"
#include "RE/Bethesda/BSScript/Variable.h"

namespace RE
{
	namespace BSScript
	{
		std::uint32_t StackFrame::GetPageForFrame() const
		{
			return parent->GetPageForFrame(this);
		}

		Variable& StackFrame::GetStackFrameVariable(std::uint32_t a_index, std::uint32_t a_pageHint) const
		{
			return parent->GetStackFrameVariable(this, a_index, a_pageHint);
		}
	}
}
