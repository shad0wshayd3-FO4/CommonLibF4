#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSShaderProperty.h"
#include "RE/NetImmerse/NiObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class NiTexture;

	class __declspec(novtable) BSTextureSet :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTextureSet };
		static constexpr auto VTABLE{ VTABLE::BSTextureSet };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTextureSet };

		// add
		virtual const BSFixedString* GetTextureFilenameFS(BSShaderProperty::TextureTypeEnum a_type) = 0;                                                                  // 28
		virtual const char*          GetTextureFilename(BSShaderProperty::TextureTypeEnum a_type) = 0;                                                                    // 29
		virtual void                 GetTexture(const void* a_prefetchedHandle, BSShaderProperty::TextureTypeEnum a_type, NiPointer<NiTexture>* a_texture, bool a_srgb);  // 2A
		virtual void                 GetTexture(BSShaderProperty::TextureTypeEnum a_type, NiPointer<NiTexture>* a_texture, bool a_srgb) = 0;                              // 2B
		virtual void                 SetTextureFilename(BSShaderProperty::TextureTypeEnum a_type, const char* a_filename) = 0;                                            // 2C
	};
	static_assert(sizeof(BSTextureSet) == 0x10);

	class __declspec(novtable) BSShaderTextureSet :
		public BSTextureSet  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShaderTextureSet };
		static constexpr auto VTABLE{ VTABLE::BSShaderTextureSet };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSShaderTextureSet };

		static BSShaderTextureSet* CreateObject()
		{
			using func_t = decltype(&BSShaderTextureSet::CreateObject);
			static REL::Relocation<func_t> func{ REL::ID(2316324) };
			return func();
		}

		// members
		BSFixedString textureNames[10];  // 10
	};
	static_assert(sizeof(BSShaderTextureSet) == 0x60);
}
