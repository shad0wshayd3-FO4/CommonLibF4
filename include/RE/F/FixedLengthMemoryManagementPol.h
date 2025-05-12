#pragma once

namespace RE
{
	template <class CharT, std::uint16_t N>
	class FixedLengthMemoryManagementPol
	{
	public:
		using value_type = CharT;
		using size_type = std::uint16_t;
		using propagate_on_container_move_assignment = std::false_type;

		[[nodiscard]] value_type* allocate(size_type a_count)
		{
			if (a_count <= N) {
				return _buffer;
			}
			else {
				stl::report_and_fail("failed to satisfy allocation request"sv);
			}
		}

		void deallocate(value_type* a_ptr, size_type a_count)
		{
			assert(a_ptr == _buffer);
			assert(a_count <= N);
		}

	private:
		value_type _buffer[N]{ static_cast<value_type>(0) };
	};
}
