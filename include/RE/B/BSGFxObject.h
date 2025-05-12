#pragma once

namespace RE
{
	class BSGFxObject :
		public Scaleform::GFx::Value,    // 00
		public UsesBSGFXFunctionHandler  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGFxObject };

		BSGFxObject(const Scaleform::GFx::Value& a_flashObject) :
			Scaleform::GFx::Value(a_flashObject)
		{
		}

		BSGFxObject(const Scaleform::GFx::Value& a_flashObject, const char* a_relativePathToMember)
		{
			AcquireFlashObjectByMemberName(a_flashObject, a_relativePathToMember);
		}

		BSGFxObject(const Scaleform::GFx::Movie& a_parentMovie, const char* a_pathToObject)
		{
			AcquireFlashObjectByPath(a_parentMovie, a_pathToObject);
		}

		Scaleform::GFx::Value* AcquireFlashObjectByMemberName(const Scaleform::GFx::Value& a_flashObject, const char* a_relativePathToMember)
		{
			using func_t = decltype(&BSGFxObject::AcquireFlashObjectByMemberName);
			static REL::Relocation<func_t> func{ REL::ID(2287014) };
			return func(this, a_flashObject, a_relativePathToMember);
		}

		Scaleform::GFx::Value* AcquireFlashObjectByPath(const Scaleform::GFx::Movie& a_parentMovie, const char* a_absolutePathToMember)
		{
			using func_t = decltype(&BSGFxObject::AcquireFlashObjectByPath);
			static REL::Relocation<func_t> func{ REL::ID(2287015) };
			return func(this, a_parentMovie, a_absolutePathToMember);
		}
	};
	static_assert(sizeof(BSGFxObject) == 0x38);
}
