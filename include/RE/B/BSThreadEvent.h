#pragma once

namespace RE
{
	class BSThreadEvent
	{
	public:
		enum class Event
		{
			kOnStartup = 0x0,
			kOnShutdown = 0x1
		};

		static void InitSDM()
		{
			using func_t = decltype(&BSThreadEvent::InitSDM);
			static REL::Relocation<func_t> func{ ID::BSThreadEvent::InitSDM };
			return func();
		}
	};
	static_assert(std::is_empty_v<BSThreadEvent>);
}
