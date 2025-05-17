#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	namespace BSResource
	{
		class ID;
	}

	class __declspec(novtable) TESModel :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESModel };
		static constexpr auto VTABLE{ VTABLE::TESModel };

		// override (BaseFormComponent)
		void InitializeDataComponent() override;          // 02
		void ClearDataComponent() override;               // 03
		void CopyComponent(BaseFormComponent*) override;  // 06

		// add
		virtual const char*           GetModel() const { return model.c_str(); }          // 07
		virtual void                  SetModel(const char* a_model) { model = a_model; }  // 08
		virtual BGSModelMaterialSwap* GetAsModelMaterialSwap() { return nullptr; }        // 09

		// members
		BSFixedString   model;            // 08
		BSResource::ID* textures;         // 10
		BSResource::ID* materials;        // 18
		std::uint32_t*  addons;           // 20
		std::int8_t     numTextures;      // 28
		std::int8_t     numTexturesSRGB;  // 29
		std::int8_t     numAddons;        // 2A
		std::int8_t     numMaterials;     // 2B
		std::int8_t     flags;            // 2C
	};
	static_assert(sizeof(TESModel) == 0x30);
}
