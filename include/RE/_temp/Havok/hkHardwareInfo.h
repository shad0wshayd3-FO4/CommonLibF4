#pragma once

#include "RE/Havok/hkReferencedObject.h"

namespace RE
{
	class __declspec(novtable) hkHardwareInfo :
		public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hkHardwareInfo };
		inline static constexpr auto VTABLE{ VTABLE::hkHardwareInfo };

		inline static std::int32_t CalcNumHardwareThreads()
		{
			using func_t = decltype(&hkHardwareInfo::CalcNumHardwareThreads);
			static REL::Relocation<func_t> func{ REL::ID(2260765) };
			return func();
		}

		// members
		std::int32_t  numHardwareThreads;
		std::uint32_t cpuFeatures;
	};
	static_assert(sizeof(hkHardwareInfo) == 0x18);
}
