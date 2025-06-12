#pragma once

namespace RE
{
	class Rumble
	{
	public:
		enum RUMBLE_TYPE : std::uint32_t
		{
			kBigMotor = 0x0,
			kSmallMotor = 0x1
		};

		enum RUMBLE_PATTERN : std::uint32_t
		{
			kConstant = 0x0,
			kPeriodicSquare = 0x1,
			kPeriodicTriangle = 0x2,
			kPeriodicSawtooth = 0x3,
		};

		class AutoRumblePause
		{
		public:
		};
		static_assert(std::is_empty_v<AutoRumblePause>);
	};
	static_assert(std::is_empty_v<Rumble>);
}
