#include "RE/Bethesda/BSScript/StructTypeInfo.h"

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
