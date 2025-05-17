#pragma once

#include "RE/P/PipboyValue.h"

namespace RE
{
	template <class T>
	class PipboyPrimitiveValue;  // Forward declaration for specialization **only**

	template <>
	class __declspec(novtable) PipboyPrimitiveValue<std::uint32_t> :
		public PipboyValue
	{
	public:
		virtual ~PipboyPrimitiveValue() {}  // 00

		// override
		virtual void                    CleanDirtyToGame() override {}                                                                                              // 00
		virtual void                    Serialize([[maybe_unused]] Json::Value* a_json) override {}                                                                 // 01
		virtual void                    SerializeChanges([[maybe_unused]] BSBinarySerializer& a_serializer, [[maybe_unused]] bool a_fullSerialization) override {}  // 03
		virtual SERIALIZATION_DATA_TYPE GetType() override { return SERIALIZATION_DATA_TYPE::kUint32; }

		PipboyPrimitiveValue(std::uint32_t a_value, PipboyValue* a_parentValue) :
			PipboyValue(a_parentValue), value(a_value) {}

		void ctor(std::uint32_t a_value, PipboyValue* a_parentValue)
		{
			using func_t = decltype(&PipboyPrimitiveValue<std::uint32_t>::ctor);
			static REL::Relocation<func_t> func{ ID::PipboyPrimitiveValue::uint32::ctor };
			func(this, a_value, a_parentValue);
		}

		operator std::uint32_t() const
		{
			return value;
		}

		// members
		std::uint32_t value;  // 18
	};
	static_assert(sizeof(PipboyPrimitiveValue<std::uint32_t>) == 0x20);

	template <>
	class __declspec(novtable) PipboyPrimitiveValue<bool> :
		public PipboyValue
	{
	public:
		virtual ~PipboyPrimitiveValue() {}  // 00

		// override
		virtual void                    CleanDirtyToGame() override {}                                                                                              // 00
		virtual void                    Serialize([[maybe_unused]] Json::Value* a_json) override {}                                                                 // 01
		virtual void                    SerializeChanges([[maybe_unused]] BSBinarySerializer& a_serializer, [[maybe_unused]] bool a_fullSerialization) override {}  // 03
		virtual SERIALIZATION_DATA_TYPE GetType() override { return SERIALIZATION_DATA_TYPE::kBool; }

		PipboyPrimitiveValue(bool a_value, PipboyValue* a_parentValue) :
			PipboyValue(a_parentValue), value(a_value) {}

		void ctor(bool a_value, PipboyValue* a_parentValue)
		{
			using func_t = decltype(&PipboyPrimitiveValue<bool>::ctor);
			static REL::Relocation<func_t> func{ ID::PipboyPrimitiveValue::boolean::ctor };
			func(this, a_value, a_parentValue);
		}

		operator bool() const
		{
			return value;
		}

		// members
		bool value;  // 18
	};
	static_assert(sizeof(PipboyPrimitiveValue<bool>) == 0x20);
}
