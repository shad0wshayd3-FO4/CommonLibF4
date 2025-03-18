#pragma once

namespace REL
{
	using HOOK_HANDLE = std::uint32_t;

	enum class HOOK_TYPE : std::uint32_t
	{
		NONE = 0,
		CALL5 = 2,
		CALL6 = 3,
		JMP5 = 4,
		JMP6 = 5,
		VFT = 6,
	};

	enum class HOOK_STEP : std::uint32_t
	{
		PRELOAD = 1,
		LOAD = 2,
	};

	class HookObject
	{
	public:
		HookObject(const std::uintptr_t a_address);
		HookObject(const std::uintptr_t a_address, const char* a_name);
		HookObject(const std::uintptr_t a_address, const HOOK_TYPE a_type);
		HookObject(const std::uintptr_t a_address, const HOOK_TYPE a_type, const HOOK_STEP a_step);
		HookObject(const std::uintptr_t a_address, const HOOK_STEP a_step);
		HookObject(const std::uintptr_t a_address, const char* a_name, const HOOK_TYPE a_type);
		HookObject(const std::uintptr_t a_address, const char* a_name, const HOOK_TYPE a_type, const HOOK_STEP a_step);

		virtual ~HookObject();

		virtual bool        Init();
		virtual HOOK_HANDLE GetHandle() const;
		virtual const char* GetName() const;
		virtual HOOK_TYPE   GetType() const;
		virtual HOOK_STEP   GetStep() const;
		virtual std::size_t GetSize() const;
		virtual std::size_t GetSizeTrampoline() const;
		virtual bool        GetEnabled() const;
		virtual bool        Enable() = 0;
		virtual bool        Disable() = 0;

	protected:
		std::uintptr_t m_address{ 0 };
		std::string    m_name;
		HOOK_HANDLE    m_handle;
		HOOK_TYPE      m_type{ HOOK_TYPE::NONE };
		HOOK_STEP      m_step{ HOOK_STEP::LOAD };
		std::size_t    m_size{ 8 };
		std::size_t    m_sizeTrampoline{ 0 };
		bool           m_enabled{ false };
	};
}

template <class T>
	requires(std::is_base_of_v<REL::HookObject, T>)
struct std::formatter<T>
{
	template <class ParseContext>
	constexpr auto parse(ParseContext& a_ctx)
	{
		return a_ctx.begin();
	}

	template <class FormatContext>
	constexpr auto format(const T& a_hook, FormatContext& a_ctx) const
	{
		return format_to(a_ctx.out(), "Hook({})", a_hook.GetName());
	}
};
