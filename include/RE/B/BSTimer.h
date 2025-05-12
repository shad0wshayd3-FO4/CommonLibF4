#pragma once

namespace RE
{
	class BSTimer
	{
	public:
		[[nodiscard]] static BSTimer* GetSingleton()
		{
			static REL::Relocation<BSTimer*> singleton{ REL::ID(2703179) };
			return singleton.get();
		}

		[[nodiscard]] static float QGlobalTimeMultiplier()
		{
			static REL::Relocation<float*> value{ REL::ID(2666307) };
			return *value;
		}

		[[nodiscard]] static float QGlobalTimeMultiplierTarget()
		{
			static REL::Relocation<float*> value{ REL::ID(2666308) };
			return *value;
		}

		void SetGlobalTimeMultiplier(float a_mult, bool a_now)
		{
			using func_t = decltype(&BSTimer::SetGlobalTimeMultiplier);
			static REL::Relocation<func_t> func{ REL::ID(2267970) };
			return func(this, a_mult, a_now);
		}

		// members
		std::int64_t  highPrecisionInitTime;          // 00
		float         clamp;                          // 08
		float         clampRemainder;                 // 0C
		float         delta;                          // 10
		float         realTimeDelta;                  // 14
		std::uint64_t lastTime;                       // 18
		std::uint64_t firstTime;                      // 20
		std::uint64_t disabledLastTime;               // 28
		std::uint64_t disabledFirstTime;              // 30
		std::uint32_t disableCounter;                 // 38
		bool          useGlobalTimeMultiplierTarget;  // 3C
	};
	static_assert(sizeof(BSTimer) == 0x40);
}
