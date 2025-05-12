#pragma once

namespace RE
{
	template <class CharT, std::uint16_t>
	class DynamicMemoryManagementPol
	{
	public:
		using value_type = CharT;
		using size_type = std::uint16_t;
		using propagate_on_container_move_assignment = std::true_type;

		[[nodiscard]] value_type* allocate(size_type a_count) { return calloc<value_type>(a_count); }

		void deallocate(value_type* a_ptr, size_type) { free(a_ptr); }
	};
}
