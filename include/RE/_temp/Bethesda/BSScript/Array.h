#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/TypeInfo.h"
#include "RE/Bethesda/BSScript/Variable.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/MemoryManager.h"

namespace RE
{
	namespace BSScript
	{
		class TypeInfo;
		class Variable;

		class Array :
			public BSIntrusiveRefCounted  // 00
		{
		private:
			// Array * Ctor(const TypeInfo *type_info, std::uint32_t initial_size = 0);

		public:
			using value_type = Variable;
			using size_type = std::uint32_t;
			using difference_type = std::int32_t;
			using reference = value_type&;
			using const_reference = const value_type&;
			using pointer = value_type*;
			using const_pointer = const value_type*;
			using iterator = value_type*;
			using const_iterator = const value_type*;
			using reverse_iterator = std::reverse_iterator<iterator>;
			using const_reverse_iterator = std::reverse_iterator<const_iterator>;

			// Array(const TypeInfo *type_info, std::uint32_t initial_size = 0);
			~Array();

			[[nodiscard]] reference       operator[](size_type a_pos);
			[[nodiscard]] const_reference operator[](size_type a_pos) const;

			[[nodiscard]] reference       front();
			[[nodiscard]] const_reference front() const;

			[[nodiscard]] reference       back();
			[[nodiscard]] const_reference back() const;

			[[nodiscard]] pointer       data() noexcept;
			[[nodiscard]] const_pointer data() const noexcept;

			[[nodiscard]] iterator       begin() noexcept;
			[[nodiscard]] const_iterator begin() const noexcept;
			[[nodiscard]] const_iterator cbegin() const noexcept;

			[[nodiscard]] iterator       end() noexcept;
			[[nodiscard]] const_iterator end() const noexcept;
			[[nodiscard]] const_iterator cend() const noexcept;

			[[nodiscard]] reverse_iterator       rbegin() noexcept;
			[[nodiscard]] const_reverse_iterator rbegin() const noexcept;
			[[nodiscard]] const_reverse_iterator crbegin() const noexcept;

			[[nodiscard]] reverse_iterator       rend() noexcept;
			[[nodiscard]] const_reverse_iterator rend() const noexcept;
			[[nodiscard]] const_reverse_iterator crend() const noexcept;

			[[nodiscard]] bool empty() const noexcept;

			[[nodiscard]] size_type size() const noexcept;

			[[nodiscard]] size_type max_size() const noexcept;

			[[nodiscard]] TypeInfo&       type_info();
			[[nodiscard]] const TypeInfo& type_info() const;

			[[nodiscard]] TypeInfo::RawType type() const;

			// members
			TypeInfo           elementType;   // 08
			BSSpinLock         elementsLock;  // 10
			BSTArray<Variable> elements;      // 18
		};
		static_assert(sizeof(Array) == 0x30);
	}
}
