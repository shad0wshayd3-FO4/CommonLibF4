#pragma once

namespace REX
{
	enum class LOG_LEVEL
	{
		TRACE = 0,
		DEBUG = 1,
		INFO = 2,
		WARN = 3,
		ERROR = 4,
		CRITICAL = 5,
	};

	void LOG(const std::source_location a_loc, const LOG_LEVEL a_level, const std::string_view a_fmt);

	template <class... T>
	void LOG(const std::source_location a_loc, const LOG_LEVEL a_level, const std::format_string<T...> a_fmt, T&&... a_args)
	{
		LOG(a_loc, a_level, std::vformat(a_fmt.get(), std::make_format_args(a_args...)));
	}

	template <class... T>
	struct TRACE
	{
		TRACE() = delete;

		explicit TRACE(const std::format_string<T...> a_fmt, T&&... a_args, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::TRACE, a_fmt, std::forward<T>(a_args)...);
		}
	};

	template <>
	struct TRACE<void>
	{
		TRACE() = delete;

		explicit TRACE(const std::string_view a_fmt, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::TRACE, a_fmt);
		}
	};

	template <class... T>
	struct DEBUG
	{
		DEBUG() = delete;

		explicit DEBUG(const std::format_string<T...> a_fmt, T&&... a_args, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::DEBUG, a_fmt, std::forward<T>(a_args)...);
		}
	};

	template <>
	struct DEBUG<void>
	{
		DEBUG() = delete;

		explicit DEBUG(const std::string_view a_fmt, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::DEBUG, a_fmt);
		}
	};

	template <class... T>
	struct INFO
	{
		INFO() = delete;

		explicit INFO(const std::format_string<T...> a_fmt, T&&... a_args, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::INFO, a_fmt, std::forward<T>(a_args)...);
		}
	};

	template <>
	struct INFO<void>
	{
		INFO() = delete;

		explicit INFO(const std::string_view a_fmt, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::INFO, a_fmt);
		}
	};

	template <class... T>
	struct WARN
	{
		WARN() = delete;

		explicit WARN(const std::format_string<T...> a_fmt, T&&... a_args, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::WARN, a_fmt, std::forward<T>(a_args)...);
		}
	};

	template <>
	struct WARN<void>
	{
		WARN() = delete;

		explicit WARN(const std::string_view a_fmt, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::WARN, a_fmt);
		}
	};

	template <class... T>
	struct ERROR
	{
		ERROR() = delete;

		explicit ERROR(const std::format_string<T...> a_fmt, T&&... a_args, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::ERROR, a_fmt, std::forward<T>(a_args)...);
		}
	};

	template <>
	struct ERROR<void>
	{
		ERROR() = delete;

		explicit ERROR(const std::string_view a_fmt, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::ERROR, a_fmt);
		}
	};

	template <class... T>
	struct CRITICAL
	{
		CRITICAL() = delete;

		explicit CRITICAL(const std::format_string<T...> a_fmt, T&&... a_args, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::CRITICAL, a_fmt, std::forward<T>(a_args)...);
		}
	};

	template <>
	struct CRITICAL<void>
	{
		CRITICAL() = delete;

		explicit CRITICAL(const std::string_view a_fmt, const std::source_location a_loc = std::source_location::current())
		{
			LOG(a_loc, LOG_LEVEL::CRITICAL, a_fmt);
		}
	};

	template <class... T>
	TRACE(const std::format_string<T...>, T&&...) -> TRACE<T...>;
	TRACE(const std::string_view) -> TRACE<void>;

	template <class... T>
	DEBUG(const std::format_string<T...>, T&&...) -> DEBUG<T...>;
	DEBUG(const std::string_view) -> DEBUG<void>;

	template <class... T>
	INFO(const std::format_string<T...>, T&&...) -> INFO<T...>;
	INFO(const std::string_view) -> INFO<void>;

	template <class... T>
	WARN(const std::format_string<T...>, T&&...) -> WARN<T...>;
	WARN(const std::string_view) -> WARN<void>;

	template <class... T>
	ERROR(const std::format_string<T...>, T&&...) -> ERROR<T...>;
	ERROR(const std::string_view) -> ERROR<void>;

	template <class... T>
	CRITICAL(const std::format_string<T...>, T&&...) -> CRITICAL<T...>;
	CRITICAL(const std::string_view) -> CRITICAL<void>;
}
