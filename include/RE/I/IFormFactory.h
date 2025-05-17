#pragma once

#include "RE/E/ENUM_FORM_ID.h"

namespace RE
{
	enum class OBJECT_CATEGORY_TYPE;
	enum class OBJECT_TYPE;

	class __declspec(novtable) IFormFactory
	{
	public:
		static constexpr auto RTTI{ RTTI::IFormFactory };
		static constexpr auto VTABLE{ VTABLE::IFormFactory };

		virtual ~IFormFactory();  // 00

		// add
		[[nodiscard]] virtual TESForm*                   DoCreate() = 0;                                // 01
		[[nodiscard]] virtual const char*                GetFormName() const = 0;                       // 02
		[[nodiscard]] virtual ENUM_FORM_ID               GetFormID() const = 0;                         // 03
		[[nodiscard]] virtual const char*                GetObjectName() const { return nullptr; }      // 04
		[[nodiscard]] virtual OBJECT_TYPE                GetObjectType() const;                         // 05
		[[nodiscard]] virtual OBJECT_CATEGORY_TYPE       GetObjectCategory() const;                     // 06
		[[nodiscard]] virtual BGSMod::Property::BridgeI* GetPropertyBridge() const { return nullptr; }  // 07

		[[nodiscard]] static auto GetFormFactories()
			-> std::span<IFormFactory*, std::to_underlying(ENUM_FORM_ID::kTotal)>
		{
			constexpr auto                                len = std::to_underlying(ENUM_FORM_ID::kTotal);
			static REL::Relocation<IFormFactory*(*)[len]> factories{ REL::ID(2689177) };
			return { *factories };
		}
	};
	static_assert(sizeof(IFormFactory) == 0x8);
}
