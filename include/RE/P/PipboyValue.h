#pragma once

namespace RE
{
	class __declspec(novtable) PipboyValue
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyValue };
		static constexpr auto VTABLE{ VTABLE::PipboyValue };

		enum SERIALIZATION_DATA_TYPE : std::uint8_t
		{
			kBool = 0x0,
			kInt8 = 0x1,
			kUint8 = 0x2,
			kInt32 = 0x3,
			kUint32 = 0x4,
			kFloat = 0x5,
			kString = 0x6,
			kArray = 0x7,
			kObject = 0x8,
		};

		virtual ~PipboyValue() = default;  // 00

		// add
		virtual void                    CleanDirtyToGame();                                                        // 01
		virtual void                    Serialize(Json::Value* a_json) = 0;                                        // 02
		virtual void                    SerializeChanges(BSBinarySerializer& a_serializer, bool a_fullSerialize);  // 03
		virtual SERIALIZATION_DATA_TYPE GetType() = 0;                                                             // 04

		PipboyValue(PipboyValue* a_parentValue)
		{
			ctor(a_parentValue);
		};

		void ctor(PipboyValue* a_parentValue)
		{
			using func_t = decltype(&PipboyValue::ctor);
			REL::Relocation<func_t> func{ REL::ID(2225915) };
			return func(this, a_parentValue);
		}

		// members
		std::uint32_t id;                  // 08
		bool          isDirtyGame;         // 0C
		bool          isDirtyToCompanion;  // 0D
		PipboyValue*  parentValue;         // 10
	};
	static_assert(sizeof(PipboyValue) == 0x18);
}
