#pragma once

#include "RE/Bethesda/BSResource.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTexture.h"

namespace RE
{
	struct BSTextureDB
	{
	public:
		struct DBTraits
		{
		public:
			using U_Type = NiPointer<NiTexture>;

			struct ArgsType
			{
			public:
				// members
				std::uint32_t loadLevel;         // 00
				bool          isCubeMap;         // 04
				bool          replicateCubeMap;  // 05
				bool          isDDX;             // 06
				bool          isSRGB;            // 07
				bool          allowDegrade;      // 08
			};
			static_assert(sizeof(ArgsType) == 0x0C);

			static BSResource::EntryDB<BSTextureDB::DBTraits>* GetSingleton()
			{
				static REL::Relocation<BSResource::EntryDB<BSTextureDB::DBTraits>**> singleton{ REL::ID(1126862) };
				return *singleton;
			}
		};
		static_assert(std::is_empty_v<DBTraits>);
	};

	using TextureDBHandle = BSResource::RHandleType<BSResource::Entry<NiPointer<NiTexture>, BSResource::EntryDBTraits<BSTextureDB::DBTraits, BSResource::EntryDB<BSTextureDB::DBTraits>>::CArgs>, BSResource::EntryDB<BSTextureDB::DBTraits>>;
}
