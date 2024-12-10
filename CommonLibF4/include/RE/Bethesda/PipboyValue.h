#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTHashMap.h"

namespace RE
{
	namespace Json
	{
		class Value;
	}

	class BSBinarySerializer;
	class PipboyObject;

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

	class __declspec(novtable) PipboyObject :
		public PipboyValue
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyObject };
		static constexpr auto VTABLE{ VTABLE::PipboyObject };

		virtual ~PipboyObject();  // 00

		// override
		virtual void                    CleanDirtyToGame() override;                                                        // 01
		virtual void                    Serialize(Json::Value* a_json) override;                                            // 02
		virtual void                    SerializeChanges(BSBinarySerializer& a_serializer, bool a_fullSerialize) override;  // 03
		virtual SERIALIZATION_DATA_TYPE GetType() override;                                                                 // 04

		template <typename T>
		T GetMember(const BSFixedString& a_name)
		{
			const auto it = memberMap.find(a_name);
			return (it != memberMap.end()) ? static_cast<T>(it->second) : nullptr;
		}

		void AddMember(const BSFixedString* a_name, PipboyValue* a_member)
		{
			using func_t = decltype(&PipboyObject::AddMember);
			static REL::Relocation<func_t> func{ REL::ID(2225699) };
			return func(this, a_name, a_member);
		}

		// members
		BSTHashMap<BSFixedString, PipboyValue*> memberMap;         // 18
		BSTSet<std::uint32_t>                   addedMemberIDs;    // 48
		BSTArray<std::uint32_t>                 removedMemberIDs;  // 78
		bool                                    newlyCreated;      // 90
	};
	static_assert(sizeof(PipboyObject) == 0x98);
}
