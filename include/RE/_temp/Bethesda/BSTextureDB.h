#pragma once

#include "RE/Bethesda/BSResource.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTexture.h"

namespace RE
{
	using TextureDBHandle = BSResource::RHandleType<BSResource::Entry<NiPointer<NiTexture>, BSResource::EntryDBTraits<BSTextureDB::DBTraits, BSResource::EntryDB<BSTextureDB::DBTraits>>::CArgs>, BSResource::EntryDB<BSTextureDB::DBTraits>>;
}
