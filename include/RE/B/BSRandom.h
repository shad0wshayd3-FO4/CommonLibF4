#pragma once

namespace RE
{
	namespace BSRandom
	{
		inline std::uint32_t UnsignedInt(std::uint32_t a_min, std::uint32_t a_max)
		{
			using func_t = decltype(&BSRandom::UnsignedInt);
			static REL::Relocation<func_t> func{ ID::BSRandom::UnsignedInt };
			return func(a_min, a_max);
		}

		inline float Float(float a_min, float a_max)
		{
			using func_t = decltype(&BSRandom::Float);
			static REL::Relocation<func_t> func{ ID::BSRandom::Float };
			return func(a_min, a_max);
		}

		inline float Float0To1()
		{
			using func_t = decltype(&BSRandom::Float0To1);
			static REL::Relocation<func_t> func{ ID::BSRandom::Float0To1 };
			return func();
		}
	}
}
