#pragma once

namespace RE
{
	enum class KeywordType
	{
		kNone = 0x0,
		kComponentTechLevel = 0x1,
		kAttachPoint = 0x2,
		kComponentProperty = 0x3,
		kInstantiationFilter = 0x4,
		kModAssociation = 0x5,
		kSound = 0x6,
		kAnimArchetype = 0x7,
		kFunctionCall = 0x8,
		kRecipeFilter = 0x9,
		kAttractionType = 0xA,
		kDialogueSubtype = 0xB,
		kQuestTarget = 0xC,
		kAnimFlavor = 0xD,
		kAnimGender = 0xE,
		kAnimFaceArchetype = 0xF,
		kQuestGroup = 0x10,
		kAnimInjured = 0x11,
		kDispelEffect = 0x12,

		kTotal = 0x13
	};
}
