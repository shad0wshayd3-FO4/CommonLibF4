#pragma once

namespace RE
{
	template <class T, class Manager>
	class BSPointerHandleManagerInterface
	{
	public:
		static BSPointerHandle<T> CreateHandle(T* a_ptr)
		{
			using func_t = decltype(&BSPointerHandleManagerInterface<T, Manager>::CreateHandle);
			static REL::Relocation<func_t> func{ REL::ID(2188375) };
			return func(a_ptr);
		}

		static BSPointerHandle<T> GetHandle(T* a_ptr)
		{
			using func_t = decltype(&BSPointerHandleManagerInterface<T, Manager>::GetHandle);
			static REL::Relocation<func_t> func{ REL::ID(2188676) };
			return func(a_ptr);
		}

		static bool GetSmartPointer(const BSPointerHandle<T>& a_in, NiPointer<T>& a_out)
		{
			using func_t = bool (*)(const BSPointerHandle<T>& a_in, NiPointer<T>& a_out);
			static REL::Relocation<func_t> func{ REL::ID(2188681) };
			return func(a_in, a_out);
		}

		static NiPointer<T> GetSmartPointer(const BSPointerHandle<T>& a_in)
		{
			NiPointer<T> out;
			GetSmartPointer(a_in, out);
			return out;
		}
	};

	extern template class BSPointerHandleManagerInterface<Actor>;
	extern template class BSPointerHandleManagerInterface<Projectile>;
	extern template class BSPointerHandleManagerInterface<TESObjectREFR>;
}
