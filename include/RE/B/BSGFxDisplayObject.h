#pragma once

#include "RE/B/BSGFxObject.h"

namespace RE
{
	class BSGFxDisplayObject :
		public BSGFxObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGFxDisplayObject };
		static constexpr auto VTABLE{ VTABLE::BSGFxDisplayObject };

		struct InitialDisplayState
		{
		public:
			// members
			float originalWidth;   // 00
			float originalHeight;  // 04
		};
		static_assert(sizeof(InitialDisplayState) == 0x08);

		BSGFxDisplayObject(const Scaleform::GFx::Value& a_flashObject) :
			BSGFxObject(a_flashObject)
		{
			ctor_shared();
		}

		BSGFxDisplayObject(const Scaleform::GFx::Value& a_flashObject, const char* a_relativePathToMember) :
			BSGFxObject(a_flashObject, a_relativePathToMember)
		{
			ctor_shared();
		}

		BSGFxDisplayObject(const Scaleform::GFx::Movie& a_parentMovie, const char* a_pathToObject) :
			BSGFxObject(a_parentMovie, a_pathToObject)
		{
			ctor_shared();
		}

		virtual ~BSGFxDisplayObject()
		{
			if (parentDisplayObject) {
				parentDisplayObject->RemoveChild(*this);
			}
		}

		void RemoveChild(const BSGFxDisplayObject& a_child) const
		{
			using func_t = decltype(&BSGFxDisplayObject::RemoveChild);
			static REL::Relocation<func_t> func{ REL::ID(2287327) };
			return func(this, a_child);
		}

		// members
		const BSGFxDisplayObject* parentDisplayObject{ nullptr };  // 40
		InitialDisplayState       initialState;                    // 48

	private:
		void ctor_shared()
		{
			if (HasMember("height")) {
				Scaleform::GFx::Value height;
				if (GetMember("height", &height)) {
					if (height.IsNumber()) {
						initialState.originalHeight = static_cast<float>(height.GetNumber());
					}
				}
			}

			if (HasMember("width")) {
				Scaleform::GFx::Value width;
				if (GetMember("width", &width)) {
					if (width.IsNumber()) {
						initialState.originalWidth = static_cast<float>(width.GetNumber());
					}
				}
			}
		}
	};
	static_assert(sizeof(BSGFxDisplayObject) == 0x50);
}
