#pragma once

namespace RE
{
	struct BSModelDB
	{
		struct DBTraits
		{
			using U_Type = NiPointer<NiNode>;

			struct ArgsType
			{
				// members
				REX::EnumSet<ENUM_LOD_MULT, std::int32_t> lodFadeMult;          // 00
				std::uint32_t                             loadLevel;            // 04
				std::uint8_t                              prepareAfterLoad : 1;  // 08:00
				std::uint8_t                              faceGenModel : 1;      // 08:01
				std::uint8_t                              useErrorMarker : 1;    // 08:02
				std::uint8_t                              performProcess : 1;    // 08:03
				std::uint8_t                              createFadeNode : 1;    // 08:04
				std::uint8_t                              loadTextures : 1;      // 08:05
			};
			static_assert(sizeof(ArgsType) == 0x0C);

			static BSResource::EntryDB<BSModelDB::DBTraits>* GetSingleton()
			{
				static REL::Relocation<BSResource::EntryDB<BSModelDB::DBTraits>**> singleton{ REL::ID(45807) };
				return *singleton;
			}
		};
		static_assert(std::is_empty_v<DBTraits>);

		using Handle = BSResource::RHandleType<BSResource::Entry<NiPointer<NiNode>, BSResource::EntryDBTraits<BSModelDB::DBTraits, BSResource::EntryDB<BSModelDB::DBTraits>>::CArgs>, BSResource::EntryDB<BSModelDB::DBTraits>>;

		struct HandelListHead
		{
			struct HandleList
			{
				// members
				Handle      handle;
				HandleList* next;
			};

			// members
			HandleList* head;
		};
		static_assert(sizeof(HandelListHead) == 0x8);

		static BSResource::ErrorCode Demand(
			const char* a_name,
			Handle& a_result,
			const DBTraits::ArgsType& a_args)
		{
			using func_t = BSResource::ErrorCode(*)(const char*, Handle&, const DBTraits::ArgsType&);
			static REL::Relocation<func_t> func{ REL::ID(1066398) };
			return func(a_name, a_result, a_args);
		}

		static BSResource::ErrorCode Demand(
			const char* a_name,
			NiPointer<NiNode>* a_result,
			const DBTraits::ArgsType& a_args)
		{
			using func_t = BSResource::ErrorCode(*)(const char*, NiPointer<NiNode>*, const DBTraits::ArgsType&);
			static REL::Relocation<func_t> func{ REL::ID(1225688) };
			return func(a_name, a_result, a_args);
		}
	};
}
