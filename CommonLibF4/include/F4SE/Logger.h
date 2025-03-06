#pragma once

#define F4SE_MAKE_SOURCE_LOGGER(a_func, a_type)                            \
                                                                           \
	template <class... Args>                                               \
	struct [[maybe_unused]] a_func                                         \
	{                                                                      \
		a_func() = delete;                                                 \
                                                                           \
		explicit a_func(                                                   \
			spdlog::format_string_t<Args...> a_fmt,                        \
			Args&&... a_args,                                              \
			std::source_location a_loc = std::source_location::current())  \
		{                                                                  \
			spdlog::log(                                                   \
				spdlog::source_loc{                                        \
					a_loc.file_name(),                                     \
					static_cast<int>(a_loc.line()),                        \
					a_loc.function_name() },                               \
				spdlog::level::a_type,                                     \
				a_fmt,                                                     \
				std::forward<Args>(a_args)...);                            \
		}                                                                  \
	};                                                                     \
                                                                           \
	template <class... Args>                                               \
	a_func(spdlog::format_string_t<Args...>, Args&&...) -> a_func<Args...>;\
                                                                           \
	template <>                                                            \
	struct [[maybe_unused]] a_func<void>                                   \
	{                                                                      \
		a_func() = delete;                                                 \
                                                                           \
		explicit a_func(                                                   \
			spdlog::string_view_t a_str,                                   \
			std::source_location a_loc = std::source_location::current())  \
		{                                                                  \
			spdlog::log(                                                   \
				spdlog::source_loc{                                        \
					a_loc.file_name(),                                     \
					static_cast<int>(a_loc.line()),                        \
					a_loc.function_name() },                               \
				spdlog::level::a_type,                                     \
				a_str);                                                    \
		}                                                                  \
	};                                                                     \
	                                                                       \
	a_func(spdlog::string_view_t) -> a_func<void>;                         \
                                                                           

namespace F4SE::log
{
	// deprecated
	F4SE_MAKE_SOURCE_LOGGER(trace, trace);
	F4SE_MAKE_SOURCE_LOGGER(debug, debug);
	F4SE_MAKE_SOURCE_LOGGER(info, info);
	F4SE_MAKE_SOURCE_LOGGER(warn, warn);
	F4SE_MAKE_SOURCE_LOGGER(error, err);
	F4SE_MAKE_SOURCE_LOGGER(critical, critical);

	[[nodiscard]] std::optional<std::filesystem::path> log_directory();
}

namespace F4SE
{
	F4SE_MAKE_SOURCE_LOGGER(TRACE, trace);
	F4SE_MAKE_SOURCE_LOGGER(DEBUG, debug);
	F4SE_MAKE_SOURCE_LOGGER(INFO, info);
	F4SE_MAKE_SOURCE_LOGGER(WARN, warn);
	F4SE_MAKE_SOURCE_LOGGER(ERROR, err);
	F4SE_MAKE_SOURCE_LOGGER(CRITICAL, critical);
}

#undef F4SE_MAKE_SOURCE_LOGGER
