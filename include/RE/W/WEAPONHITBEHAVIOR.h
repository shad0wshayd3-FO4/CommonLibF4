#pragma once

namespace RE
{
	enum class WEAPONHITBEHAVIOR : std::int32_t
	{
		kNormal = 0x0,
		kDismemberOnly = 0x1,
		kExplodeOnly = 0x2,
		kNoDismemberOrExplode = 0x3
	};
}
