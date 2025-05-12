#pragma once

namespace RE
{
	template <class T, class Handle>
	class BSPointerHandle
	{
	public:
		BSPointerHandle() noexcept = default;

		template <class Y>
		BSPointerHandle(BSPointerHandle<Y, Handle> a_rhs) noexcept
			requires(std::convertible_to<Y*, T*>)
			:
			_handle(a_rhs._handle)
		{}

		template <class Y>
		explicit BSPointerHandle(Y* a_rhs)
			requires(std::convertible_to<Y*, T*>)
		{
			get_handle(a_rhs);
		}

		~BSPointerHandle() noexcept = default;

		template <class Y>
		BSPointerHandle& operator=(BSPointerHandle<Y, Handle> a_rhs) noexcept
			requires(std::convertible_to<Y*, T*>)
		{
			_handle = a_rhs._handle;
			return *this;
		}

		template <class Y>
		BSPointerHandle& operator=(Y* a_rhs)
			requires(std::convertible_to<Y*, T*>)
		{
			get_handle(a_rhs);
			return *this;
		}

		void reset() noexcept { _handle.reset(); }

		[[nodiscard]] NiPointer<T> get() const
		{
			return BSPointerHandleManagerInterface<T>::GetSmartPointer(*this);
		}

		[[nodiscard]] Handle::HandleType get_handle() noexcept
		{
			return _handle.value();
		}

		[[nodiscard]] explicit operator bool() const noexcept { return _handle.has_value(); }

		[[nodiscard]] friend bool operator==(const BSPointerHandle& a_lhs, const BSPointerHandle& a_rhs) noexcept
		{
			return a_lhs._handle == a_rhs._handle;
		}

		[[nodiscard]] NiPointer<T> operator*() const noexcept
		{
			assert(static_cast<bool>(*this));
			return get();
		}

		[[nodiscard]] NiPointer<T> operator->() const noexcept
		{
			assert(static_cast<bool>(*this));
			return get();
		}

	private:
		template <class, class>
		friend class BSPointerHandle;

		Handle _handle;  // 00
	};

	extern template class BSPointerHandle<Actor>;
	extern template class BSPointerHandle<Projectile>;
	extern template class BSPointerHandle<TESObjectREFR>;

	using ActorHandle = BSPointerHandle<Actor>;
	using ProjectileHandle = BSPointerHandle<Projectile>;
	using ObjectRefHandle = BSPointerHandle<TESObjectREFR>;

	template <class T>
	struct BSCRC32<BSPointerHandle<T>>
	{
	public:
		[[nodiscard]] std::uint32_t operator()(const BSPointerHandle<T>& a_handle) const noexcept
		{
			return BSCRC32<typename BSPointerHandle<T>::native_handle_type>()(a_handle.native_handle());
		}
	};
}
