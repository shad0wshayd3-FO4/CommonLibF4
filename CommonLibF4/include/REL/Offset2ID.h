#pragma once

#include "REL/IDDB.h"

namespace REL
{
	class Offset2ID
	{
	public:
		using value_type = IDDB::mapping_t;
		using container_type = std::vector<value_type>;
		using size_type = typename container_type::size_type;
		using const_iterator = typename container_type::const_iterator;
		using const_reverse_iterator = typename container_type::const_reverse_iterator;

		template <class ExecutionPolicy>
		explicit Offset2ID(ExecutionPolicy&& a_policy)  // NOLINT(bugprone-forwarding-reference-overload)
			requires(std::is_execution_policy_v<std::decay_t<ExecutionPolicy>>)
		{
			const auto id2offset = IDDB::get().get_id2offset();
			_offset2id.reserve(id2offset.size());
			_offset2id.insert(_offset2id.begin(), id2offset.begin(), id2offset.end());
			std::sort(a_policy, _offset2id.begin(), _offset2id.end(), [](auto&& a_lhs, auto&& a_rhs) {
				return a_lhs.offset < a_rhs.offset;
			});
		}

		Offset2ID() :
			Offset2ID(std::execution::sequenced_policy{})
		{}

		[[nodiscard]] std::uint64_t operator()(std::size_t a_offset) const
		{
			if (_offset2id.empty()) {
				stl::report_and_fail("data is empty"sv);
			}

			const IDDB::mapping_t elem{ 0, a_offset };
			const auto            it = std::lower_bound(
                _offset2id.begin(),
                _offset2id.end(),
                elem,
                [](auto&& a_lhs, auto&& a_rhs) {
                    return a_lhs.offset < a_rhs.offset;
                });
			if (it == _offset2id.end()) {
				stl::report_and_fail("offset not found"sv);
			}

			return it->id;
		}

		[[nodiscard]] const_iterator begin() const noexcept { return _offset2id.begin(); }
		[[nodiscard]] const_iterator cbegin() const noexcept { return _offset2id.cbegin(); }

		[[nodiscard]] const_iterator end() const noexcept { return _offset2id.end(); }
		[[nodiscard]] const_iterator cend() const noexcept { return _offset2id.cend(); }

		[[nodiscard]] const_reverse_iterator rbegin() const noexcept { return _offset2id.rbegin(); }
		[[nodiscard]] const_reverse_iterator crbegin() const noexcept { return _offset2id.crbegin(); }

		[[nodiscard]] const_reverse_iterator rend() const noexcept { return _offset2id.rend(); }
		[[nodiscard]] const_reverse_iterator crend() const noexcept { return _offset2id.crend(); }

		[[nodiscard]] size_type size() const noexcept { return _offset2id.size(); }

	private:
		container_type _offset2id;
	};
}
