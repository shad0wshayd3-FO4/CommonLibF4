#include "RE/B/BSScript_StructTypeInfo.h"

namespace RE
{
	namespace BSScript
	{
		TypeInfo::RawType StructTypeInfo::GetRawType() const
		{
			return TypeInfo::RawType::kStruct;
		}
	}
}
