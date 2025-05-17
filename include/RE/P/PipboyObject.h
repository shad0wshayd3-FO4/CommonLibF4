#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/P/PipboyValue.h"

namespace RE
{
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
			static REL::Relocation<func_t> func{ ID::PipboyObject::AddMember };
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
