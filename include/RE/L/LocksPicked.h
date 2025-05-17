#pragma once

namespace RE
{
	class LocksPicked
	{
	public:
		class Event
		{
		public:
		};
		static_assert(std::is_empty_v<LocksPicked::Event>);

		[[nodiscard]] static BSTEventSource<LocksPicked::Event>* GetEventSource()
		{
			using func_t = decltype(&LocksPicked::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(594991) };
			return func();
		}
	};
	static_assert(std::is_empty_v<LocksPicked>);
}
