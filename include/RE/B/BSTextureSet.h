#pragma once

#include "RE/N/NiObject.h"
#include "RE/N/NiPointer.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSShaderProperty.h"

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
}
