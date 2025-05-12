#pragma once

namespace RE
{
	namespace detail
	{
		template <class T>
		concept ExtraDataListConstraint =
			std::derived_from<T, BSExtraData> &&
			!std::is_pointer_v<T> &&
			!std::is_reference_v<T>;
	}

	namespace ComparisonQualifiers
	{
		static bool ContainerQualifier(const BSExtraData* a_extraData)
		{
			using func_t = decltype(ComparisonQualifiers::ContainerQualifier);
			REL::Relocation<func_t> func{ REL::ID(2190674) };
			return func(a_extraData);
		}

		static bool UIQualifier(const BSExtraData* a_extraData)
		{
			using func_t = decltype(ComparisonQualifiers::UIQualifier);
			REL::Relocation<func_t> func{ REL::ID(2190675) };
			return func(a_extraData);
		}
	};
}
