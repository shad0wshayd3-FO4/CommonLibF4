#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiObject.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSResource_Stream.h"

namespace RE
{
	namespace BSGraphics
	{
		class Texture;
	}

	namespace BSTextureArray
	{
		class Texture;
	}

	class __declspec(novtable) NiTexture :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiTexture };
		static constexpr auto VTABLE{ VTABLE::NiTexture };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiTexture };

		// add
		virtual BSTextureArray::Texture* IsBSTextureArray() { return nullptr; }  // 28

		static void SetAllowDegrade(bool a_allow)
		{
			using func_t = decltype(&NiTexture::SetAllowDegrade);
			static REL::Relocation<func_t> func{ ID::NiTexture::SetAllowDegrade };
			return func(a_allow);
		}

		[[nodiscard]] std::string_view GetName() const { return name; }

		// members
		BSFixedString                       name;                 // 10
		std::uint32_t                       flags;                // 18
		NiTexture*                          prev;                 // 29
		NiTexture*                          next;                 // 28
		BSTSmartPointer<BSResource::Stream> stream;               // 30
		BSGraphics::Texture*                rendererTexture;      // 38
		std::int8_t                         desiredDegradeLevel;  // 40
		std::int8_t                         savedDegradeLevel;    // 41
		bool                                isDDX: 1;             // 42:0
		bool                                isSRGB: 1;            // 42:1
	};
	static_assert(sizeof(NiTexture) == 0x48);
}
