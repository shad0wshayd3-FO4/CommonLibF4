#pragma once

namespace RE
{
	enum class WARNING_TYPES
	{
		kDefault = 0x0,
		kSystem = 0x1,
		kCombat = 0x2,
		kAnimation = 0x3,
		kAI = 0x4,
		kScripts = 0x5,
		kSaveLoad = 0x6,
		kDialogue = 0x7,
		kQuests = 0x8,
		kPackages = 0x9,
		kEditor = 0xA,
		kModels = 0xB,
		kTextures = 0xC,
		kPlugins = 0xD,
		kMasterFile = 0xE,
		kForms = 0xF,
		kMagic = 0x10,
		kShaders = 0x11,
		kRendering = 0x12,
		kPathfinding = 0x13,
		kMenus = 0x14,
		kAudio = 0x15,
		kCells = 0x16,
		kHavok = 0x17,
		kFaceGen = 0x18,
		kWater = 0x19,
		kInGameMessage = 0x1A,
		kMemory = 0x1B,
		kPerformance = 0x1C,
		kLootJoy = 0x1D,
		kVATS = 0x1E,
		kDismember = 0x1F,
		kCompanion = 0x20,
		kWorkshop = 0x21,
	};
}
