#pragma once

#include "RE/M/MemoryManager.h"
#include "RE/N/NiTDefaultAllocator.h"

namespace RE
{
	template <class Key, class T>
	class NiTMapItem
	{
	public:
		using key_type = Key;
		using mapped_type = T;

		F4_HEAP_REDEFINE_NEW(NiTMapItem);

		// members
		NiTMapItem* next;    // 00
		key_type    first;   // 08
		mapped_type second;  // ??
	};

	template <class Allocator, class Key, class T>
	class NiTMapBase
	{
	public:
		using key_type = Key;
		using mapped_type = T;
		using value_type = NiTMapItem<Key, T>;
		using size_type = std::uint32_t;

		class AntiBloatAllocator :
			public Allocator  // 00
		{
		public:
			// members
			size_type size{ 0 };  // ??
		};

		using allocator_type = AntiBloatAllocator;

		virtual ~NiTMapBase();  // 00

	protected:
		virtual std::uint32_t hash_function(key_type a_key) const { return static_cast<std::uint32_t>((std::size_t)a_key % _capacity); }  // 01
		virtual bool          key_eq(key_type a_lhs, key_type a_rhs) const { return a_lhs == a_rhs; }                                     // 02

		virtual void assign_value(value_type* a_value, key_type a_key, mapped_type a_mapped)  // 03
		{
			a_value->first = a_key;
			a_value->second = a_mapped;
		}

		virtual void        clear_value([[maybe_unused]] value_type* a_value) { return; }  // 04
		virtual value_type* malloc_value() = 0;                                            // 05
		virtual void        free_value(value_type* a_value) = 0;                           // 06

	private:
		// members
		std::uint32_t  _capacity;   // 08
		value_type**   _data;       // 10
		allocator_type _allocator;  // 18
	};

	template <class Key, class T>
	class NiTMap :
		public NiTMapBase<DFALL<NiTMapItem<Key, T>>, Key, T>  // 00
	{
	private:
		using super = NiTMapBase<DFALL<NiTMapItem<Key, T>>, Key, T>;

	public:
		using key_type = typename super::key_type;
		using mapped_type = typename super::mapped_type;
		using value_type = typename super::value_type;
		using size_type = typename super::size_type;
		using allocator_type = typename super::allocator_type;

	protected:
		value_type* malloc_value() override { return new value_type(); };          // 05
		void        free_value(value_type* a_value) override { delete a_value; };  // 06
	};
}
